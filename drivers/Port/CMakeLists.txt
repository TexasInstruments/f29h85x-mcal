add_library(Port INTERFACE)

target_include_directories(Port INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Port INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Port.c ${CMAKE_CURRENT_LIST_DIR}/src/Port_Priv.c)
