add_library(Cdd_Dma_Example_Gpt_Ping_Pong_Buffer_Config INTERFACE)

target_include_directories(Cdd_Dma_Example_Gpt_Ping_Pong_Buffer_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Dma_Example_Gpt_Ping_Pong_Buffer_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Gpt_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Dma_Cfg.c)
