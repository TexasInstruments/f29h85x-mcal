add_library(Cdd_Adc INTERFACE)

target_include_directories(Cdd_Adc INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Adc
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Adc.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Adc_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Adc_Irq.c)
