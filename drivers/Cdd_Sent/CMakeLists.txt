add_library(Cdd_Sent INTERFACE)

target_include_directories(Cdd_Sent INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Sent INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Sent.c ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Sent_Irq.c
                       ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Sent_Priv.c)
