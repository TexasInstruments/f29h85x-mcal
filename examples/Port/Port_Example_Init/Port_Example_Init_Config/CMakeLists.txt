add_library(Port_Example_Init_Config INTERFACE)

target_include_directories(Port_Example_Init_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Port_Example_Init_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c)
