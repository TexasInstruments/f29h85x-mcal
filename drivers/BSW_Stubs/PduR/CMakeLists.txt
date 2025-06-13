add_library(PduR INTERFACE)

target_include_directories(PduR INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(PduR INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/PduR.c)
