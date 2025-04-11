add_library(SchM_Fls INTERFACE)

target_include_directories(SchM_Fls INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(SchM_Fls INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Fls.c
)
