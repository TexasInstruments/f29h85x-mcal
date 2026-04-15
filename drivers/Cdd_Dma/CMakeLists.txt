add_library(Cdd_Dma INTERFACE)

target_include_directories(Cdd_Dma INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Dma
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Dma.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Dma_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Dma_Irq.c)
