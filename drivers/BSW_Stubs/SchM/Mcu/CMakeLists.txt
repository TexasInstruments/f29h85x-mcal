add_library(SchM_Mcu INTERFACE)

target_include_directories(SchM_Mcu INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Mcu INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Mcu.c)
