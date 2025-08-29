project(Cdd_Pwm_Example_DiodeEmulation LANGUAGES C ASM)

if(NOT TARGET hw_include)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/hw_include/
                     ${CMAKE_BINARY_DIR}/hw_include)
endif()

if(NOT TARGET MemMap)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/MemMap/
                     ${CMAKE_BINARY_DIR}/MemMap)
endif()

if(NOT TARGET Mcal_Lib)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcal_Lib/
                     ${CMAKE_BINARY_DIR}/Mcal_Lib)
endif()

if(NOT TARGET AUTOSAR_Types)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/AUTOSAR_Types/
                     ${CMAKE_BINARY_DIR}/AUTOSAR_Types)
endif()

if(NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu/
                     ${CMAKE_BINARY_DIR}/Mcu)
endif()

if(NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port
                     ${CMAKE_BINARY_DIR}/Port)
endif()

if(NOT TARGET Cdd_Pwm)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Cdd_Pwm
                     ${CMAKE_BINARY_DIR}/Cdd_Pwm)
endif()

if(NOT TARGET Det)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Det/
                     ${CMAKE_BINARY_DIR}/Det)
endif()

if(NOT TARGET Dem)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dem/
                     ${CMAKE_BINARY_DIR}/Dem)
endif()

if(NOT TARGET EcuM)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/EcuM/
                     ${CMAKE_BINARY_DIR}/EcuM)
endif()

if(NOT TARGET Os)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Os/
                     ${CMAKE_BINARY_DIR}/Os)
endif()

if(NOT TARGET Dio)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dio/
                     ${CMAKE_BINARY_DIR}/Dio)
endif()

if(NOT TARGET Cdd_Xbar)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Cdd_Xbar/
                     ${CMAKE_BINARY_DIR}/Cdd_Xbar)
endif()

if(NOT TARGET SchM_Cdd_Pwm)
    add_subdirectory(
        ${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Cdd_Pwm/
        ${CMAKE_BINARY_DIR}/Cdd_Pwm/Cdd_Pwm_Example_DiodeEmulation/SchM_Cdd_Pwm)
endif()

if(NOT TARGET SchM_Port)
    add_subdirectory(
        ${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/
        ${CMAKE_BINARY_DIR}/Cdd_Pwm/Cdd_Pwm_Example_DiodeEmulation/SchM_Port)
endif()

if(NOT TARGET Cdd_Pwm_Example_DiodeEmulation_Config)
    add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/Cdd_Pwm_Example_DiodeEmulation_Config/)
endif()

if(NOT TARGET DeviceSupport)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport
                     ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

if(NOT TARGET AppUtils)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../AppUtils
                     ${CMAKE_BINARY_DIR}/AppUtils)
endif()

add_link_options(-Wl,--stack_size=0x10000)
add_link_options(-Wl,--heap_size=0x1000)
add_link_options(
    -Wl,--xml_link_info=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml
)
add_link_options(-Wl,-m=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map)

if(BUILD_CONFIGURATION MATCHES "RAM")
    add_link_options(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_ram_lnk_cpu1_all.cmd
    )
else()
    add_link_options(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_flash_lnk_cpu1.cmd
    )
endif()

# This command is used to move the .out file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)

add_executable(${PROJECT_NAME} Cdd_Pwm_Example_DiodeEmulation.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Cdd_Pwm_Example_DiodeEmulation_Config
            DeviceSupport
            AppUtils
            Mcu
            Port
            SchM_Port
            Cdd_Pwm
            hw_include
            AUTOSAR_Types
            Det
            Dem
            Mcal_Lib
            MemMap
            EcuM
            Os
            SchM_Cdd_Pwm
            Dio
            Cdd_Xbar)

# This command is used to move the .xml and .map files
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
        ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)

if(BUILD_CONFIGURATION MATCHES "FLASH")
    signing(${PROJECT_NAME}
            ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME})
endif()
