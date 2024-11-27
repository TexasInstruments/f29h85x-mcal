add_library(SchM_Gpt INTERFACE)

target_include_directories(SchM_Gpt INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(SchM_Gpt INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/SchM_Gpt.c
)
