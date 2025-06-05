add_library(AppUtils INTERFACE)

target_include_directories(AppUtils INTERFACE ${CMAKE_CURRENT_LIST_DIR}/)

target_sources(AppUtils INTERFACE ${CMAKE_CURRENT_LIST_DIR}/AppUtils.c)
