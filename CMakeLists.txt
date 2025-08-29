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

    # Define CPU3_APPSIZE macro and assign the calculated size to it
    target_compile_options(${PROJECT_NAME}
                           PRIVATE -DCPU3_APPSIZE=${CPU3_APPSIZE})

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

# Option to enable Code Coverage Instrumentation
option(CODE_COVERAGE "Determines whether to enable Code Coverage" OFF)

# Enable / Disable Code Coverage for all the modules
if(${CODE_COVERAGE})
    message(STATUS "\nConfiguring CMake to enable Code Coverage\n")

    add_compile_options(-fprofile-instr-generate)

    add_compile_options(-fcoverage-mapping)

    add_compile_options(-fmcdc)

endif(${CODE_COVERAGE})

# Settings specific for FLASH build configuration
if(BUILD_CONFIGURATION MATCHES "FLASH")

    # Define "_FLASH" compiler option
    add_compile_options(-D_FLASH)

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

# Option to enable the build for tests
option(BUILD_TESTS "Determines whether to build tests" OFF)

# Build tests for all the modules when enabled
if(${BUILD_TESTS})
    message(
        STATUS "\nConfiguring CMake to build tests when BUILD_TESTS is ON\n")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif(${BUILD_TESTS})
