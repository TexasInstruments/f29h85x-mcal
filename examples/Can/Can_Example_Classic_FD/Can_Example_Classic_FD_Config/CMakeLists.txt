add_library(Can_Example_Classic_FD_Config INTERFACE)

target_include_directories(Can_Example_Classic_FD_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Can_Example_Classic_FD_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Can_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Can_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c)
