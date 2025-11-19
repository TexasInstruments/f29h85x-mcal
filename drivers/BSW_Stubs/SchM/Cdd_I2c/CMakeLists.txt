add_library(SchM_Cdd_I2c INTERFACE)

target_include_directories(SchM_Cdd_I2c
                           INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(SchM_Cdd_I2c
               INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Cdd_I2c.c)
