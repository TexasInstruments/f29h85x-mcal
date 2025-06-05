add_library(CanIf INTERFACE)

target_include_directories(CanIf INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(CanIf INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/CanIf_Cbk.c)
