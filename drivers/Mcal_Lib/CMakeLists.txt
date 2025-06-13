add_library(Mcal_Lib INTERFACE)

target_include_directories(Mcal_Lib INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_sources(Mcal_Lib INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/Mcal_Lib.c
                                  ${CMAKE_CURRENT_LIST_DIR}/src/Mcal_Lib_BootRom.c)
