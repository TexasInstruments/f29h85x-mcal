add_library(Wdg INTERFACE)

target_include_directories(Wdg INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Wdg INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Wdg.c ${CMAKE_CURRENT_LIST_DIR}/src/Wdg_Priv.c)
