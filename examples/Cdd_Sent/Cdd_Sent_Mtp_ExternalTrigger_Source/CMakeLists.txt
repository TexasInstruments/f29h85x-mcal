project(Cdd_Sent_Mtp_ExternalTrigger_Source LANGUAGES C ASM)

if(NOT TARGET hw_include)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/hw_include/ ${CMAKE_BINARY_DIR}/hw_include)
endif()

if(NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu/ ${CMAKE_BINARY_DIR}/Mcu)
endif()

if(NOT TARGET Mcal_Lib)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcal_Lib/ ${CMAKE_BINARY_DIR}/Mcal_Lib)
endif()

if(NOT TARGET AUTOSAR_Types)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/AUTOSAR_Types/
                     ${CMAKE_BINARY_DIR}/AUTOSAR_Types)
endif()

if(NOT TARGET Det)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Det/ ${CMAKE_BINARY_DIR}/Det)
endif()

if(NOT TARGET Dem)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dem/ ${CMAKE_BINARY_DIR}/Dem)
endif()

if(NOT TARGET PduR)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/PduR/ ${CMAKE_BINARY_DIR}/PduR)
endif()

if(NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port ${CMAKE_BINARY_DIR}/Port)
endif()

if(NOT TARGET Gpt)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Gpt ${CMAKE_BINARY_DIR}/Gpt)
endif()

if(NOT TARGET Cdd_Sent)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Cdd_Sent ${CMAKE_BINARY_DIR}/Cdd_Sent)
endif()

if(NOT TARGET MemMap)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/MemMap/ ${CMAKE_BINARY_DIR}/MemMap)
endif()

if(NOT TARGET Os)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Os/ ${CMAKE_BINARY_DIR}/Os)
endif()

if(NOT TARGET SchM_Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/ ${CMAKE_BINARY_DIR}/SchM_Port)
endif()

if(NOT TARGET SchM_Gpt)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Gpt/
                     ${CMAKE_BINARY_DIR}/Cdd_Adc/Cdd_Adc_Example_Differential/SchM_Gpt)
endif()

if(NOT TARGET EcuM)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/EcuM/ ${CMAKE_BINARY_DIR}/EcuM)
endif()

if(NOT TARGET Cdd_Sent_Mtp_ExternalTrigger_Source_Config)
    add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/Cdd_Sent_Mtp_ExternalTrigger_Source_Config/
        ${CMAKE_BINARY_DIR}/Cdd_Sent/Cdd_Sent_Mtp_ExternalTrigger_Source/Cdd_Sent_Mtp_ExternalTrigger_Source_Config
    )
endif()

if(NOT TARGET AppUtils)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/examples/AppUtils/ ${CMAKE_BINARY_DIR}/AppUtils)
endif()

if(NOT TARGET DeviceSupport)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/")

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

add_executable(${PROJECT_NAME} Cdd_Sent_Mtp_ExternalTrigger_Source.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Cdd_Sent_Mtp_ExternalTrigger_Source_Config
            Cdd_Sent
            Mcu
            hw_include
            AUTOSAR_Types
            Det
            Dem
            PduR
            Port
            Gpt
            SchM_Gpt
            Mcal_Lib
            MemMap
            Os
            SchM_Port
            EcuM
            AppUtils
            DeviceSupport)

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
