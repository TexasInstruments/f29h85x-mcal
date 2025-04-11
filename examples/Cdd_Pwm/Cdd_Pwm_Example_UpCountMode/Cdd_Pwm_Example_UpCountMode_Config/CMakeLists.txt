add_library(Cdd_Pwm_Example_UpCountMode_Config INTERFACE)

target_include_directories(Cdd_Pwm_Example_UpCountMode_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include/
)

target_sources(Cdd_Pwm_Example_UpCountMode_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Pwm_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_Cfg.c
)