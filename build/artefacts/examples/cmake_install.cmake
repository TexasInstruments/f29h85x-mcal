# Install script for directory: C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/examples

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
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Clock/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_PowerMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Ram/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Mcu_Example_Reset/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Gpt_Example_ContinuousMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Gpt_Example_InterruptTimeout/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Gpt_Example_MixedMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Gpt_Example_OneShotMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Gpt_Example_Timers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Dio_Example_Read_Write_All/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Port_Example_Init/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Can_Example_Classic_FD/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Can_Example_Icom/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Can_Example_Loopback/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Can_Example_Wakeup/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Wdg_Example_Interrupt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Wdg_Example_Service/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Xbar_GpioToGpio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Lin_Example_Init_Sleep_Wakeup/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Lin_Example_SendData/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Lin_Example_Sleep_Wakeup_Interrupt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Spi_Example_AsyncTransfer_Interrupt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Spi_Example_External_Loopback/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Spi_Example_SyncTransfer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Spi_Example_Sync_AsyncTransfer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Sent_MtpMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Sent_Mtp_ExternalTrigger_Source/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Sent_Standard/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Uart_Example_Loopback/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Uart_Example_Read_Interrupt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Uart_Example_Write_Interrupt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Uart_Example_Write_Polling/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Adc_Example_Differential/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Adc_Example_GlbSwTrig/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Adc_Example_Ppb_TrigRepeater/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Adc_Example_TempSensor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Ecap_Capture_Signal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Ecap_HrMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Pwm_Example_UpCountMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Ipc_Example_Interrupt_C29x1/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Cdd_Ipc_Example_Polling_C29x1/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Fls_App_Example/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/Rtdma_Example_Mem_Transfer/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/work/source/mcal/mcal_scripts/jenkins/windows/release_area/c29x_mcal/build/artefacts/examples/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
