

# Macro implementation
macro(SUBDIRLIST subdirlist curdir)
    file(GLOB subdirectories LIST_DIRECTORIES true RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(subdir ${subdirectories})
        if(IS_DIRECTORY ${curdir}/${subdir})
            add_subdirectory(${curdir}/${subdir} ${CMAKE_BINARY_DIR}/${subdir})
            list(APPEND dirlist ${subdir})
        endif()
    endforeach()
    set(${subdirlist} ${dirlist})
endmacro()

#Add the module name to the module_list. Don't edit anything else.
set(module_list "Mcu" "Gpt" "Dio" "Port" "Can" "Wdg" "Cdd_Xbar" "Lin" "Spi" "Cdd_Sent" "Cdd_Uart" "Cdd_Adc" "Cdd_Ecap" "Cdd_Pwm" "Cdd_Ipc" "Fls")
set(example_list "")

foreach(example ${module_list})

    message("Adding ${example} subdirectory")
    SUBDIRLIST(subdir_${example} ${CMAKE_CURRENT_SOURCE_DIR}/${example})

    list(APPEND example_list ${subdir_${example}})

    # Add custom target to build all the examples of a module.
    # Example: To run all the examples of the Mcu module give the below command:
    # cmake --build <path/to/the/artefacts> -t Mcu_Examples
    # Use --clean-first after the path, to clean before building another target.
    add_custom_target(${example}_Examples DEPENDS ${subdir_${example}})

endforeach()

#Add custom target examples to build all the examples.
# Run cmake --build <path/to/the/artefacts> -t examples to build all the examples.
add_custom_target(examples DEPENDS ${example_list})

# Save the example_list to a file
file(WRITE ${CMAKE_BINARY_DIR}/example_list.txt "${example_list}")