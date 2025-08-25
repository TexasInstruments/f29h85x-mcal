add_library(Cdd_Pwm_Example_GlobalLoad_And_Link_Config INTERFACE)

target_include_directories(Cdd_Pwm_Example_GlobalLoad_And_Link_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Pwm_Example_GlobalLoad_And_Link_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Pwm_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_Cfg.c)