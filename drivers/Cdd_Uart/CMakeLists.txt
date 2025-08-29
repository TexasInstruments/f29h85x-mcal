add_library(Cdd_Uart INTERFACE)

target_include_directories(Cdd_Uart INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Uart
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Uart.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Uart_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Uart_Irq.c)
