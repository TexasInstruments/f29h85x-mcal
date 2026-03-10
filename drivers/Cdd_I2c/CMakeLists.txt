add_library(Cdd_I2c INTERFACE)

target_include_directories(Cdd_I2c INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_I2c
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c_Hw.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c_Irq.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c_Priv.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c_Target.c
              ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_I2c_Utils.c)
