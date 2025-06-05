add_library(SchM_Lin INTERFACE)

target_include_directories(SchM_Lin INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Lin INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Lin.c)
