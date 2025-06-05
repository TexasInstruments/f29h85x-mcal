add_library(Can_Example_loopback_Config INTERFACE)

target_include_directories(Can_Example_loopback_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Can_Example_loopback_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Can_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c)
