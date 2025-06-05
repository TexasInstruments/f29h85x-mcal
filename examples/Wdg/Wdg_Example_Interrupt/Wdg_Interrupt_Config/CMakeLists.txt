add_library(Wdg_Interrupt_Config INTERFACE)

target_include_directories(Wdg_Interrupt_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Wdg_Interrupt_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Wdg_PBcfg.c)
