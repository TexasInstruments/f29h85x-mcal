add_library(SchM_Cdd_Ipc INTERFACE)

target_include_directories(SchM_Cdd_Ipc
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Cdd_Ipc
               INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Cdd_Ipc.c)
