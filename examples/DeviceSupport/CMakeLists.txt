add_library(DeviceSupport INTERFACE)

target_include_directories(DeviceSupport INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(DeviceSupport INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/src/DeviceSupport.c
    ${CMAKE_CURRENT_LIST_DIR}/src/codestartbranch.asm
)