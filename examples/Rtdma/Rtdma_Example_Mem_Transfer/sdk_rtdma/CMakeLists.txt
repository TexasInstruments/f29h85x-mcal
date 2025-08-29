add_library(Rtdma INTERFACE)

target_include_directories(Rtdma INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Rtdma INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/rtdma.c)
