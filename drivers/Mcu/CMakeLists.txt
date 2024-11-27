add_library(Mcu INTERFACE)


target_include_directories(Mcu INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)


target_sources(Mcu INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu.c
    ${CMAKE_CURRENT_LIST_DIR}/src/Mcu_Priv.c
)