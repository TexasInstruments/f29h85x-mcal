add_library(Det INTERFACE)

target_include_directories(Det INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Det INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Det.c)
