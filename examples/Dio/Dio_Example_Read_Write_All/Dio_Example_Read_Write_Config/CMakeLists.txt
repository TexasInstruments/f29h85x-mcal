add_library(Dio_Example_Read_Write_Config INTERFACE)

target_include_directories(Dio_Example_Read_Write_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Dio_Example_Read_Write_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Dio_Lcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c)
