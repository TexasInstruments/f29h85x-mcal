add_library(EcuM INTERFACE)

target_include_directories(EcuM INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(EcuM INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/EcuM.c
)