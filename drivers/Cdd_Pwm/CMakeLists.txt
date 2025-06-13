add_library(Cdd_Pwm INTERFACE)

target_include_directories(Cdd_Pwm INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(
    Cdd_Pwm INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Pwm.c ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Pwm_Priv.c
                      ${CMAKE_CURRENT_LIST_DIR}/src/Cdd_Pwm_Irq.c)
