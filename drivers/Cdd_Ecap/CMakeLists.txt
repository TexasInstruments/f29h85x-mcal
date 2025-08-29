add_library(Cdd_Ecap INTERFACE)

target_include_directories(Cdd_Ecap INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Ecap
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ecap.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ecap_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Ecap_Irq.c)
