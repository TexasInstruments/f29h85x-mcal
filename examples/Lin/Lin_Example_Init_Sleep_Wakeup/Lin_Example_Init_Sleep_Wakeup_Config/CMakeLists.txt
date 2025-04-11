add_library(Lin_Example_Init_Sleep_Wakeup_Config INTERFACE)


target_include_directories(Lin_Example_Init_Sleep_Wakeup_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Lin_Example_Init_Sleep_Wakeup_Config INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/Lin_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c

)