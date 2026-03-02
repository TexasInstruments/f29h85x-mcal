project(Empty_Project LANGUAGES C ASM)

if(NOT TARGET hw_include)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/hw_include/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/hw_include)
endif()

if(NOT TARGET Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcu/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Mcu)
endif()

if(NOT TARGET Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Port/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Port)
endif()

if(NOT TARGET SchM_Mcu)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Mcu/
                     ${CMAKE_BINARY_DIR}/SchM_Mcu)
endif()

if(NOT TARGET SchM_Port)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/SchM/Port/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/SchM_Port)
endif()

if(NOT TARGET Mcal_Lib)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/Mcal_Lib/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Mcal_Lib)
endif()

if(NOT TARGET AUTOSAR_Types)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/AUTOSAR_Types/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/AUTOSAR_Types)
endif()

if(NOT TARGET Det)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Det/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Det)
endif()

if(NOT TARGET Dem)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Dem/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Dem)
endif()

if(NOT TARGET MemMap)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/MemMap/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/MemMap)
endif()

if(NOT TARGET EcuM)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/EcuM/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/EcuM)
endif()

if(NOT TARGET Os)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/drivers/BSW_Stubs/Os/
                     ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Os)
endif()

if(NOT TARGET AppUtils)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/examples/AppUtils/
                     ${CMAKE_BINARY_DIR}/AppUtils)
endif()

if(NOT TARGET Empty_Project_Config)
    add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DEVICE}/Empty_Project_Config/
        ${CMAKE_CURRENT_BINARY_DIR}/Empty_Project/Empty_Project_Config)
endif()

if(NOT TARGET DeviceSupport)
    add_subdirectory(${PROJECT_ROOT_DIRECTORY}/examples/DeviceSupport/
                     ${CMAKE_BINARY_DIR}/DeviceSupport)
endif()

add_link_options(-Wl,--stack_size=0x1000)
add_link_options(-Wl,--heap_size=0x1000)
add_link_options(
    -Wl,--xml_link_info=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_linkInfo.xml
)
add_link_options(-Wl,-m=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map)

select_linker_file("DEFAULT" "cpu1")

# This command is used to move the .out file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_ROOT_DIRECTORY}/build/assets/examples/${PROJECT_NAME}/)
add_executable(${PROJECT_NAME} Empty_Project.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Empty_Project_Config
            AppUtils
            Port
            SchM_Port
            Mcu
            SchM_Mcu
            hw_include
            AUTOSAR_Types
            Det
            Dem
            Mcal_Lib
            MemMap
            EcuM
            Os
            DeviceSupport)
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
