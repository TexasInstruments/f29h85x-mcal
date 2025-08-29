add_library(Fls INTERFACE)

target_include_directories(Fls INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Fls
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Fls.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Fls_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Fls_Ac.c)
