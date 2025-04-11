add_library(Spi INTERFACE)


target_include_directories(Spi INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)


target_sources(Spi INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Spi.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Spi_Priv.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Spi_Utils.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Spi_Irq.c
)