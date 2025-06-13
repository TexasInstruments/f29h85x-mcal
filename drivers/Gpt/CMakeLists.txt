add_library(Gpt INTERFACE)

target_include_directories(Gpt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Gpt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Gpt.c ${CMAKE_CURRENT_LIST_DIR}/src/Gpt_Irq.c
                             ${CMAKE_CURRENT_LIST_DIR}/src/Gpt_Priv.c)
