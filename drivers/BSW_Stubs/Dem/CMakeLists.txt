add_library(Dem INTERFACE)

target_include_directories(Dem INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Dem INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Dem.c
)