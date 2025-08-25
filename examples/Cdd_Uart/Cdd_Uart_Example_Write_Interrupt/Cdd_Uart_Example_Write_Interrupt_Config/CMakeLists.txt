add_library(Cdd_Uart_Example_Write_Interrupt_Config INTERFACE)

target_include_directories(Cdd_Uart_Example_Write_Interrupt_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Uart_Example_Write_Interrupt_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Uart_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c)
