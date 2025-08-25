add_library(Rtdma_Example_Mem_Transfer_Config INTERFACE)

target_include_directories(Rtdma_Example_Mem_Transfer_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Rtdma_Example_Mem_Transfer_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c)
