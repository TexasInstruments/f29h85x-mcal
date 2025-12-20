add_library(Cmpss INTERFACE)

target_include_directories(Cmpss INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Cmpss INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/cmpss.c)
target_sources(Cmpss INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/asysctl.c)
