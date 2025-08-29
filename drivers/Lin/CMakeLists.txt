add_library(Lin INTERFACE)

target_include_directories(Lin INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Lin
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Lin.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Lin_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Lin_Irq.c)
