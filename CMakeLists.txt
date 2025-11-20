cmake_minimum_required(VERSION 3.30.2)

project(F29x_MCAL LANGUAGES C ASM)

set(PROJECT_ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find the Python executable
find_program(python_tool NAMES python python3)

# Path to the signing script folder
set(SIGNING_DIRECTORY ${PROJECT_ROOT_DIRECTORY}/build/toolchain/signing)

# Set FLASH as the default BUILD_CONFIGURATION. The selected build configuration
# applies to all the modules.
set(BUILD_CONFIGURATION
    "FLASH"
    CACHE STRING "User-option to select RAM/FLASH build configuration.\n")

# Abort CMake build when an invalid BUILD_CONFIGURATION is passed on the
# terminal/console
if(BUILD_CONFIGURATION MATCHES "RAM" OR BUILD_CONFIGURATION MATCHES "FLASH")
    message(
        STATUS
            "\nSelected ${BUILD_CONFIGURATION} build configuration for all the modules\n"
    )
else()
    message(
        FATAL_ERROR
            "Only RAM & FLASH build configurations are supported. Select either RAM or FLASH.\n"
    )
endif()

# Set FALSE as the BUILD_EMULATE. The selected build configuration for emulation
# Set BUILD_EMULATE as TRUE along with BUILD_DEVICE to emulate F29P32X and
# F29P58X
set(BUILD_EMULATE
    "FALSE"
    CACHE STRING "User-option to select TRUE/FALSE BUILD_EMULATE.\n")

# Set F29H85X as the default Variant. The selected build configuration
set(BUILD_DEVICE
    "F29H85X"
    CACHE STRING
          "User-option to select F29H85X/F29P32X/F29P58X build configuration.\n"
)

# Abort CMake build when an invalid BUILD_DEVICE is passed on the
# terminal/console
if(BUILD_DEVICE MATCHES "F29H85X"
   OR BUILD_DEVICE MATCHES "F29P32X"
   OR BUILD_DEVICE MATCHES "F29P58X")
    message(
        STATUS
            "\nSelected ${BUILD_DEVICE} build configuration for all the modules\n"
    )
else()
    message(
        FATAL_ERROR
            "Only F29H85X, F29P32X & F29P58X build variants are supported. Select either one of them.\n"
    )
endif()

# Define BUILD_DEVICE_F29xx macro and only for C and CXX files
if(BUILD_EMULATE MATCHES "TRUE")
    add_compile_options(
        $<$<COMPILE_LANGUAGE:C,CXX>:-DBUILD_DEVICE_${BUILD_DEVICE}>)
endif()

# Macro to select the appropriate linker file based on
# BUILD_DEVICE,BUILD_CONFIGURATION , LINKER_FILE_TYPE and CORE Usage:
# select_linker_file([LINKER_FILE_TYPE] [CORE]) LINKER_FILE_TYPE values :
# DEFAULT , ALL

macro(select_linker_file LINKER_FILE_TYPE CORE)

    # Base path for linker files
    set(LINKER_BASE_PATH
        "${PROJECT_ROOT_DIRECTORY}/examples/DeviceSupport/LinkerCMD")

    # Convert BUILD_DEVICE to lowercase for filename
    string(TOLOWER ${BUILD_DEVICE} VARIANT_LOWER)
    string(TOLOWER ${BUILD_CONFIGURATION} CONFIG_TYPE)

    # Check if we need the "_all" suffix based on LINKER_FILE_TYPE and
    # BUILD_DEVICE
    if(LINKER_FILE_TYPE MATCHES "ALL")
        set(SUFFIX "_all")
    else()
        set(SUFFIX "")
    endif()

    # Construct the linker file path using the naming convention
    set(LINKER_FILE
        "${LINKER_BASE_PATH}/${VARIANT_LOWER}_${CONFIG_TYPE}_lnk_${CORE}${SUFFIX}.cmd"
    )

    # Add link options for the linker file
    add_link_options(${LINKER_FILE})
endmacro()

# Macro to merge CPU3 image into CPU1 image
macro(CPU3MERGE PROJECT_NAME PROJECT_BIN_PATH CPU3_PROJECT_NAME CPU3_OUT_PATH)
    # Convert CPU3.out to binary format
    execute_process(
        COMMAND
            ${CMAKE_OBJCOPY} -O binary
            ${CPU3_OUT_PATH}/${CPU3_PROJECT_NAME}.out
            ${CMAKE_CURRENT_BINARY_DIR}/${CPU3_PROJECT_NAME}.bin)

    # Get the size of CPU3 section
    file(SIZE ${CMAKE_CURRENT_BINARY_DIR}/${CPU3_PROJECT_NAME}.bin CPU3_APPSIZE)

    # Define CPU3_APPSIZE macro and assign the calculated size to it only for C
    # and CXX files
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE $<$<COMPILE_LANGUAGE:C,CXX>:-DCPU3_APPSIZE=${CPU3_APPSIZE}>)

    # Merge CPU3 image into CPU1 image by updating cpu3app section
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND
            ${CMAKE_OBJCOPY} --update-section
            cpu3app=${CMAKE_CURRENT_BINARY_DIR}/${CPU3_PROJECT_NAME}.bin
            ${PROJECT_BIN_PATH}/${PROJECT_NAME}.out
            ${PROJECT_BIN_PATH}/${PROJECT_NAME}_merged.out)

endmacro()

# Settings specific for FLASH build configuration
if(BUILD_CONFIGURATION MATCHES "FLASH")

    # Define "_FLASH" compiler option only for C and CXX files
    add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-D_FLASH>)

    # Macro to sign(add certificate) the generated .out files
    macro(SIGNING PROJECT_NAME PROJECT_BIN_PATH)
        add_custom_command(
            TARGET ${PROJECT_NAME}
            POST_BUILD
            COMMAND
                ${CMAKE_OBJCOPY} --remove-section=cert
                --remove-section=.TI.bound:CPU1_Cfg
                --remove-section=.TI.bound:CPU2_Cfg
                --remove-section=.TI.bound:CPU3_Cfg -O binary
                ${PROJECT_BIN_PATH}/${PROJECT_NAME}.out
                ${PROJECT_BIN_PATH}/${PROJECT_NAME}.bin
            COMMAND
                ${python_tool} ${SIGNING_DIRECTORY}/sign_non_secure.py --b
                "${PROJECT_BIN_PATH}/${PROJECT_NAME}.bin" --c C29 --k
                ${SIGNING_DIRECTORY}/keys/key.pem --o 60 --l 0x10001000
            COMMAND
                ${CMAKE_OBJCOPY} --update-section
                cert=${PROJECT_BIN_PATH}/C29-cert.bin
                ${PROJECT_BIN_PATH}/${PROJECT_NAME}.out
                ${PROJECT_BIN_PATH}/${PROJECT_NAME}_cert.out
            COMMAND ${CMAKE_COMMAND} -E remove -f
                    "${PROJECT_BIN_PATH}/${PROJECT_NAME}.out"
            COMMAND
                ${CMAKE_COMMAND} -E rename
                "${PROJECT_BIN_PATH}/${PROJECT_NAME}_cert.out"
                "${PROJECT_BIN_PATH}/${PROJECT_NAME}.out"
            COMMAND ${CMAKE_COMMAND} -E remove -f
                    "${PROJECT_BIN_PATH}/x509-temp.cfg"
            COMMAND ${CMAKE_COMMAND} -E remove -f
                    "${PROJECT_BIN_PATH}/${PROJECT_NAME}.bin"
            COMMAND ${CMAKE_COMMAND} -E remove -f
                    "${PROJECT_BIN_PATH}/C29-cert.bin")
    endmacro()
endif()

# Build driver examples
message(STATUS "Configuring CMake to build examples\n")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)

