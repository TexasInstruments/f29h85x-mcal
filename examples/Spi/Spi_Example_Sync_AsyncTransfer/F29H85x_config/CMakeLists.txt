add_library(Spi_Example_Sync_AsyncTransfer_Config INTERFACE)


target_include_directories(Spi_Example_Sync_AsyncTransfer_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Spi_Example_Sync_AsyncTransfer_Config INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Spi_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c
)