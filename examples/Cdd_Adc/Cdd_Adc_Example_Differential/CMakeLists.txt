project(Cdd_Adc_Example_Differential LANGUAGES C ASM)

if(NOT TARGET hw_include)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/hw_include/ ${CMAKE_BINARY_DIR}/hw_include)
endif()

if(NOT TARGET MemMap)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/MemMap/ ${CMAKE_BINARY_DIR}/MemMap)
endif()

if(NOT TARGET Mcal_Lib)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcal_Lib/ ${CMAKE_BINARY_DIR}/Mcal_Lib)
endif()

if(NOT TARGET AUTOSAR_Types)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/AUTOSAR_Types/
                     ${CMAKE_BINARY_DIR}/AUTOSAR_Types)
endif()

if(NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu/ ${CMAKE_BINARY_DIR}/Mcu)
endif()

if(NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port ${CMAKE_BINARY_DIR}/Port)
endif()

if(NOT TARGET Gpt)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Gpt ${CMAKE_BINARY_DIR}/Gpt)
endif()

if(NOT TARGET Cdd_Adc)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Cdd_Adc/ ${CMAKE_BINARY_DIR}/Cdd_Adc)
endif()

if(NOT TARGET Det)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Det/ ${CMAKE_BINARY_DIR}/Det)
endif()

if(NOT TARGET Dem)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dem/ ${CMAKE_BINARY_DIR}/Dem)
endif()

if(NOT TARGET EcuM)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/EcuM/ ${CMAKE_BINARY_DIR}/EcuM)
endif()

if(NOT TARGET Os)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Os/ ${CMAKE_BINARY_DIR}/Os)
endif()

if(NOT TARGET SchM_Cdd_Adc)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Cdd_Adc/
                     ${CMAKE_BINARY_DIR}/Cdd_Adc/Cdd_Adc_Example_Differential/SchM_Cdd_Adc)
endif()

if(NOT TARGET SchM_Gpt)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Gpt/
                     ${CMAKE_BINARY_DIR}/Cdd_Adc/Cdd_Adc_Example_Differential/SchM_Gpt)
endif()

if(NOT TARGET SchM_Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/
                     ${CMAKE_BINARY_DIR}/Cdd_Adc/Cdd_Adc_Example_Differential/SchM_Port)
endif()

if(NOT TARGET Cdd_Adc_Example_Differential_Config)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Cdd_Adc_Example_Differential_Config/)
endif()

if(NOT TARGET DeviceSupport)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

if(NOT TARGET AppUtils)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../AppUtils ${CMAKE_BINARY_DIR}/AppUtils)
endif()

add_link_options(-Wl,--stack_size=0x1000)
add_link_options(-Wl,--xml_link_info=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml)
add_link_options(-Wl,-m=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map)

if(BUILD_CONFIGURATION MATCHES "RAM")
    add_link_options(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_ram_lnk_cpu1.cmd)
else()
    add_link_options(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_flash_lnk_cpu1.cmd)
endif()

# This command is used to move the .out file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)

add_executable(${PROJECT_NAME} Cdd_Adc_Example_Differential.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Cdd_Adc_Example_Differential_Config
            DeviceSupport
            AppUtils
            Mcu
            Port
            Gpt
            SchM_Gpt
            SchM_Port
            Cdd_Adc
            hw_include
            AUTOSAR_Types
            Det
            Dem
            Mcal_Lib
            MemMap
            EcuM
            Os
            SchM_Cdd_Adc)

# This command is used to move the .xml and .map files
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
        ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)

if(BUILD_CONFIGURATION MATCHES "FLASH")
    signing(${PROJECT_NAME} ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME})
endif()
