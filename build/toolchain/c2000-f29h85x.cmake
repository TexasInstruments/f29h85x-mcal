set(PROCESSOR_VARIANT "-mcpu=c29.c0")
set(FLOATING_POINT_HARDWARE "-mfpu=f32")

set(cpu_flags "${PROCESSOR_VARIANT} ${FLOATING_POINT_HARDWARE}")

include(${CMAKE_CURRENT_LIST_DIR}/ti-cgt-c29-clang.cmake)