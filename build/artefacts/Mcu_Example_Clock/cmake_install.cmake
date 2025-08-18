# Install script for directory: C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/examples/Mcu/Mcu_Example_Clock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/F29x_MCAL")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/ti/ti-cgt-c29_1.0.0LTS/bin/c29objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/hw_include/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Port/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcal_Lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/AUTOSAR_Types/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Det/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Dem/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/EcuM/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Os/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/MemMap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/SchM_Port/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Clock/Mcu_Clock_Config/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Clock/AppUtils/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/DeviceSupport/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Clock/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
