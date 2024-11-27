add_library(SchM_Can INTERFACE)

target_include_directories(SchM_Can INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(SchM_Can INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Can.c
)
