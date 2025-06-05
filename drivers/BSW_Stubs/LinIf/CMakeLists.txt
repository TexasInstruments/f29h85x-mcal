add_library(LinIf INTERFACE)

target_include_directories(LinIf INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(LinIf INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/LinIf_Cbk.c)
