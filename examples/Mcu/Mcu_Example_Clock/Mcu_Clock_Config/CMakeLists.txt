add_library(Mcu_Clock_Config INTERFACE)

target_include_directories(Mcu_Clock_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Mcu_Clock_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c)
