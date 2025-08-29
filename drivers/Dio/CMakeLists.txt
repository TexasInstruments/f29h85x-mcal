add_library(Dio INTERFACE)

target_include_directories(Dio INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Dio INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Dio.c
                             ${CMAKE_CURRENT_LIST_DIR}/src/Dio_Priv.c)
