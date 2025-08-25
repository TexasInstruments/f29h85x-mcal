add_library(Cdd_Sent_Mtp_ExternalTrigger_Source_Config INTERFACE)

target_include_directories(Cdd_Sent_Mtp_ExternalTrigger_Source_Config
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/include/)

target_sources(
    Cdd_Sent_Mtp_ExternalTrigger_Source_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/output/src/Cdd_Sent_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Dem_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Mcu_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Port_PBcfg.c
              ${CMAKE_CURRENT_LIST_DIR}/output/src/Gpt_PBcfg.c)
