add_library(SchM_Spi INTERFACE)

target_include_directories(SchM_Spi INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(SchM_Spi INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Spi.c
)
