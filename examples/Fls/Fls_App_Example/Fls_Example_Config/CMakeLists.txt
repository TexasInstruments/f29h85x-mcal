add_library(Fls_Example_Config INTERFACE)


target_include_directories(Fls_Example_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Fls_Example_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Fls_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
)