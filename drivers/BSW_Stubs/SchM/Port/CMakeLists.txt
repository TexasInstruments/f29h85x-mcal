add_library(SchM_Port INTERFACE)

target_include_directories(SchM_Port INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Port INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Port.c)
