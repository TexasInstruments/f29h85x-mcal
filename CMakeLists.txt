cmake_minimum_required(VERSION 3.30.2)

project(F29x_MCAL LANGUAGES C ASM)

set(PROJECT_ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Path to the signing script folder
set(SIGNING_DIRECTORY ${PROJECT_ROOT_DIRECTORY}/build/toolchain/signing)

# Set FLASH as the default BUILD_CONFIGURATION. The selected build configuration applies to all the modules.
set(BUILD_CONFIGURATION "FLASH" CACHE STRING "User-option to select RAM/FLASH build configuration.\n")

# Abort CMake build when an invalid BUILD_CONFIGURATION is passed on the terminal/console
if(BUILD_CONFIGURATION MATCHES "RAM" OR BUILD_CONFIGURATION MATCHES "FLASH")
message("\nSelected ${BUILD_CONFIGURATION} build configuration for all the modules\n")
else()
message(FATAL_ERROR "Only RAM & FLASH build configurations are supported. Select either RAM or FLASH.\n")
endif()

# Settings specific for FLASH build configuration
if(BUILD_CONFIGURATION MATCHES "FLASH")

    # Define "_FLASH" compiler option
    add_compile_options(-D_FLASH)

    # Macro to sign(add certificate) the generated .out files
    macro(SIGNING PROJECT_NAME PROJECT_BIN_PATH)
      find_program(python_tool NAMES python python3)
      add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} --remove-section=cert --remove-section=.TI.bound:CPU1_Cfg --remove-section=.TI.bound:CPU2_Cfg --remove-section=.TI.bound:CPU3_Cfg -O binary ${PROJECT_BIN_PATH}/${PROJECT_NAME}.out ${PROJECT_BIN_PATH}/${PROJECT_NAME}.bin
      COMMAND ${python_tool} ${SIGNING_DIRECTORY}/sign_non_secure.py --b "${PROJECT_BIN_PATH}/${PROJECT_NAME}.bin" --c C29 --k ${SIGNING_DIRECTORY}/keys/key.pem --o 60 --l 0x10001000 
      COMMAND ${CMAKE_OBJCOPY} --update-section cert=${PROJECT_BIN_PATH}/C29-cert.bin ${PROJECT_BIN_PATH}/${PROJECT_NAME}.out ${PROJECT_BIN_PATH}/${PROJECT_NAME}_cert.out
      COMMAND ${CMAKE_COMMAND} -E remove -f "${PROJECT_BIN_PATH}/${PROJECT_NAME}.out"
      COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_BIN_PATH}/${PROJECT_NAME}_cert.out" "${PROJECT_BIN_PATH}/${PROJECT_NAME}.out")
    endmacro()
endif()

# Build driver examples
message("Configuring CMake to build examples\n")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)