add_library(SchM_Cdd_Dma INTERFACE)

target_include_directories(SchM_Cdd_Dma
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Cdd_Dma
               INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Cdd_Dma.c)
