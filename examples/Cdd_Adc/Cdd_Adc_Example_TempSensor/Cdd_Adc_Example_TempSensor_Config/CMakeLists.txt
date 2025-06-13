add_library(Cdd_Adc_Example_TempSensor_Config INTERFACE)

target_include_directories(Cdd_Adc_Example_TempSensor_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include/)

target_sources(
    Cdd_Adc_Example_TempSensor_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Adc_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Port_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Gpt_Cfg.c)
