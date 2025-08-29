cmake_minimum_required(VERSION 3.26)
project(Spi_Example_SyncTransfer LANGUAGES C ASM)

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

if(NOT TARGET Spi)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Spi/
                     ${CMAKE_BINARY_DIR}/Spi)
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

if(NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port
                     ${CMAKE_BINARY_DIR}/Port)
endif()

if(NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu
                     ${CMAKE_BINARY_DIR}/Mcu)
endif()

if(NOT TARGET SchM_Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/
                     ${CMAKE_BINARY_DIR}/Port/SchM_Port)
endif()

if(NOT TARGET SchM_Spi)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Spi/
                     ${CMAKE_BINARY_DIR}/Spi/SchM_Spi)
endif()

if(NOT TARGET Spi_Example_SyncTransfer_Config)
    add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/Spi_Example_SyncTransfer_Config/
        ${CMAKE_BINARY_DIR}/Spi_Example_SyncTransfer/Spi_Example_SyncTransfer_Config
    )
endif()

if(NOT TARGET AppUtils)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../AppUtils
                     ${CMAKE_BINARY_DIR}/AppUtils)
endif()

if(NOT TARGET DeviceSupport)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport
                     ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

include_directories("${CMAKE_CURRENT_LIST_DIR}/drivers/hw_include/f29h85x/"
                    "${CMAKE_CURRENT_SOURCE_DIR}/")

add_link_options(-Wl,--stack_size=0x1000)
add_link_options(
    -Wl,--xml_link_info=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml
)
add_link_options(-Wl,-m=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map)

if(BUILD_CONFIGURATION MATCHES "RAM")
    add_link_options(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_ram_lnk_cpu1.cmd
    )
else()
    add_link_options(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../DeviceSupport/LinkerCMD/f29h85x_flash_lnk_cpu1.cmd
    )
endif()

# This command is used to move the .out file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)

add_executable(${PROJECT_NAME} Spi_Example_SyncTransfer.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Spi_Example_SyncTransfer_Config
            Spi
            SchM_Spi
            hw_include
            AUTOSAR_Types
            Det
            Dem
            Mcal_Lib
            MemMap
            EcuM
            Os
            Mcu
            AppUtils
            DeviceSupport
            Port
            SchM_Port)

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
