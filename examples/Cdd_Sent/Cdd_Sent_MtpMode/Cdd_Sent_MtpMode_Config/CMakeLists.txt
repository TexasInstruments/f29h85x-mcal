add_library(Cdd_Sent_MtpMode_Config INTERFACE)

target_include_directories(Cdd_Sent_MtpMode_Config INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Sent_MtpMode_Config
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Sent_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Os_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Dem_Cfg.c ${CMAKE_CURRENT_LIST_DIR}/src/EcuM_Cfg.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_PBcfg.c ${CMAKE_CURRENT_LIST_DIR}/src/Port_PBcfg.c)
