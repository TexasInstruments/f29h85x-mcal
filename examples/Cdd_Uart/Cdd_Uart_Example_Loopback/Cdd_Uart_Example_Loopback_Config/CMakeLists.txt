add_library(Cdd_Uart_Example_Loopback_Config INTERFACE)


target_include_directories(Cdd_Uart_Example_Loopback_Config INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Cdd_Uart_Example_Loopback_Config INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Uart_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
)