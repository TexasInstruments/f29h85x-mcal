add_library(Cdd_Adc_Example_GlbSwTrig_Config INTERFACE)

target_include_directories(Cdd_Adc_Example_GlbSwTrig_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Adc_Example_GlbSwTrig_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Adc_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c)
