project(Can_Example_Icom LANGUAGES C ASM)

if (NOT TARGET hw_include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/hw_include/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/hw_include)
endif ()

if (NOT TARGET Can)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/Can/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Can)
endif ()

if (NOT TARGET Port)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/Port/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Port)
endif ()

if (NOT TARGET Mcu)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/Mcu/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Mcu)
endif ()

if (NOT TARGET SchM_Port)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/SchM/Port/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/SchM_Port)
endif ()

if (NOT TARGET Mcal_Lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/Mcal_Lib/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Mcal_Lib)
endif ()

if (NOT TARGET AUTOSAR_Types)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/AUTOSAR_Types/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/AUTOSAR_Types)
endif ()

if (NOT TARGET Det)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/Det/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Det)
endif ()

if (NOT TARGET Dem)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/Dem/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Dem)
endif ()

if (NOT TARGET MemMap)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/MemMap/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/MemMap)
endif ()

if (NOT TARGET SchM_Can)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/SchM/Can/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/SchM_Can)
endif ()

if (NOT TARGET EcuM)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/EcuM/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/EcuM)
endif ()

if (NOT TARGET Os)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/Os/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/Os)
endif ()

if (NOT TARGET CanIf)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/BSW_Stubs/CanIf/ ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/CanIf)
endif ()

if (NOT TARGET f29h85x_config)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/f29h85x_config/  ${CMAKE_CURRENT_BINARY_DIR}/Can_Example_Icom/f29h85x_config) 
endif ()

if (NOT TARGET AppUtils)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../AppUtils ${CMAKE_BINARY_DIR}/AppUtils)
endif ()


if (NOT TARGET DeviceSupport)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

add_link_options(-Wl,--stack_size=0x1000)
add_link_options(-Wl,--xml_link_info=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml)
add_link_options(-Wl,-m=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map)

if(BUILD_CONFIGURATION MATCHES "RAM")
    add_link_options(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_ram_lnk.cmd)
else()
    add_link_options(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_flash_lnk.cmd)
endif()

# This command is used to move the .out file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)
add_executable(${PROJECT_NAME}
    Can_Example_Icom.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE  Can_Example_Icom_Config CanIf Can hw_include AppUtils AUTOSAR_Types Port SchM_Port Mcu Det  Dem  Mcal_Lib  MemMap  SchM_Can EcuM Os DeviceSupport)
# This command is used to move the .xml and .map files
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/
)

if(BUILD_CONFIGURATION MATCHES "FLASH")
SIGNING(${PROJECT_NAME} ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME})
endif()


