add_library(Cdd_Ipc_Example_Polling_C29x1_Config INTERFACE)

target_include_directories(Cdd_Ipc_Example_Polling_C29x1_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Ipc_Example_Polling_C29x1_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Ipc_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c)
