add_library(Cdd_Xbar INTERFACE)

target_include_directories(Cdd_Xbar INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Cdd_Xbar INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Xbar.c
                                  ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Xbar_Priv.c)
