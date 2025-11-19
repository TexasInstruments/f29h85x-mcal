add_library(Adc_Rtdma INTERFACE)

target_include_directories(Adc_Rtdma
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Adc_Rtdma INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Rtdma.c)
