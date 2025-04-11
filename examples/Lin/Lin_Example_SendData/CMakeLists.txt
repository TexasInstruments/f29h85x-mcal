project(Lin_Example_SendData LANGUAGES C ASM)

if (NOT TARGET hw_include)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/hw_include/ ${CMAKE_BINARY_DIR}/hw_include)
endif ()

if (NOT TARGET Lin)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Lin/ ${CMAKE_BINARY_DIR}/Lin)
endif ()

if (NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port/ ${CMAKE_BINARY_DIR}/Port)
endif ()

if (NOT TARGET Mcal_Lib)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcal_Lib/ ${CMAKE_BINARY_DIR}/Mcal_Lib)
endif ()

if (NOT TARGET AUTOSAR_Types)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/AUTOSAR_Types/ ${CMAKE_BINARY_DIR}/AUTOSAR_Types)
endif ()

if (NOT TARGET Det)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Det/ ${CMAKE_BINARY_DIR}/Det)
endif ()

if (NOT TARGET Dem)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dem/ ${CMAKE_BINARY_DIR}/Dem)
endif ()

if (NOT TARGET MemMap)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/MemMap/ ${CMAKE_BINARY_DIR}/MemMap)
endif ()

if (NOT TARGET SchM_Lin)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Lin/ ${CMAKE_BINARY_DIR}/SchM_Lin)
endif ()

if (NOT TARGET SchM_Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/ ${CMAKE_BINARY_DIR}/SchM_Port)
endif ()

if (NOT TARGET Os)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Os/ ${CMAKE_BINARY_DIR}/Os)
endif ()

if (NOT TARGET LinIf)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/LinIf/ ${CMAKE_BINARY_DIR}/LinIf)
endif ()

if (NOT TARGET EcuM)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/EcuM/ ${CMAKE_BINARY_DIR}/EcuM)
endif ()

if (NOT TARGET Lin_Example_SendData_Config)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Lin_Example_SendData_Config/  ${CMAKE_BINARY_DIR}/Lin_Example_SendData/Lin_Example_SendData_Config) 
endif ()

if (NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu ${CMAKE_BINARY_DIR}/Mcu)
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
    Lin_Example_SendData.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Lin_Example_SendData_Config
    Lin
    hw_include
    AUTOSAR_Types
    Det
    Os
    LinIf
    Mcal_Lib
    MemMap
    SchM_Lin
    SchM_Port
    EcuM
    Port
    Mcu
    Dem
    AppUtils
    DeviceSupport
    )

# This command is used to move the .xml and .map files
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/
)

if(BUILD_CONFIGURATION MATCHES "FLASH")
SIGNING(${PROJECT_NAME} ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME})
endif()