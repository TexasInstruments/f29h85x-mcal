add_library(Cdd_Ipc INTERFACE)

target_include_directories(Cdd_Ipc INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Ipc INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ipc.c ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ipc_Priv.c
                      ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ipc_Irq.c)
