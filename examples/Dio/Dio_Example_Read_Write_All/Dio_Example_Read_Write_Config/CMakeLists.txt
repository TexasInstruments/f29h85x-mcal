add_library(Dio_Example_Read_Write_Config INTERFACE)


target_include_directories(Dio_Example_Read_Write_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Dio_Example_Read_Write_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Dio_Lcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
)