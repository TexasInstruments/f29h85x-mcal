set(CMAKE_SYSTEM_PROCESSOR c29)
set(CMAKE_SYSTEM_NAME Generic)

if(MINGW OR CYGWIN OR WIN32)
	set(EXECUTABLE_FILE_EXTESION .exe)
endif()

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM     NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY     NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE     NEVER)

# Optionally reduce compiler sanity check when cross-compiling.
set(CMAKE_TRY_COMPILE_TARGET_TYPE         STATIC_LIBRARY)

set(TOOLCHAIN_PREFIX c29)

# Find the compiler with the specified name. PATHS specify additional directories to search in, apart from the default locations.
# Add the compiler path to the PATH environment variable or specify the compiler path on the console.
# Example: cmake -S . --preset <preset_name> -D TCP=<Path/to/the/compiler>
find_program(target_tool NAMES c29clang PATHS ${TCP} ${TCP}/bin)

# Command to be used to mainpulate the paths.
cmake_path(GET target_tool PARENT_PATH bin_path) # Get the bin folder path
cmake_path(GET bin_path PARENT_PATH compiler_path) # Get the compiler path

set(compiler_flags "${cpu_flags}")

set(CMAKE_C_COMPILER ${target_tool} ${compiler_flags})  # Defining C compiler
set(CMAKE_CXX_COMPILER ${target_tool} ${compiler_flags})
set(CMAKE_ASM_COMPILER ${target_tool} ${compiler_flags})

#Adding this here because preset file doesn't support macro expansion
add_link_options(-I${compiler_path}/include/c -I${compiler_path}/include/c++ -I${compiler_path}/include/c29.c0-ti-none-eabi/c++/v1/ -I${compiler_path}/lib)

#Adding Linker options to treat warnings as errors and suppress expected warnings
add_link_options(-Wl,--emit_warnings_as_errors -Wl,--diag_suppress=10068 -Wl,--diag_suppress=10325 -Wl,--diag_suppress=10063)

set(CMAKE_EXECUTABLE_SUFFIX_ASM ".out")
set(CMAKE_EXECUTABLE_SUFFIX_C ".out")