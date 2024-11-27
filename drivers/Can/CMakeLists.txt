add_library(Can INTERFACE)


target_include_directories(Can INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(Can INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Can.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Can_Irq.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Can_Priv.c
)