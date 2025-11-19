add_library(Lin_Example_Init_Sleep_Wakeup_Config INTERFACE)

target_include_directories(Lin_Example_Init_Sleep_Wakeup_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Lin_Example_Init_Sleep_Wakeup_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Lin_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c)
