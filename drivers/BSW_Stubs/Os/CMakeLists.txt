add_library(Os INTERFACE)

target_include_directories(Os INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Os INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Os.c)
