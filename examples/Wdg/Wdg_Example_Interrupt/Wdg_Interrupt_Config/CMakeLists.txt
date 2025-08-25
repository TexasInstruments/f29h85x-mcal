add_library(Wdg_Interrupt_Config INTERFACE)

target_include_directories(Wdg_Interrupt_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Wdg_Interrupt_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Wdg_PBcfg.c)
