# AGENTS.md

This file provides guidance to AI assistants helping users of the TI F29x MCAL product. The focus is on user workflows: installation, configuration, building examples, and integration with AUTOSAR projects.

## Product Overview

The F29x MCAL (Microcontroller Abstraction Layer) is a software package for TI F29H85x, F29P32x, and F29P58x devices that provides AUTOSAR 4.3.1 compliant drivers.

**Package Structure:**

- `drivers/` - MCAL driver implementations
- `plugins/` - EB Tresos configuration plugins
- `examples/` - Bare-metal example applications
- `docs/User_Guide/index.html` - **Primary documentation** (refer here for supported modules, version info, and detailed guides)

## MCAL and CDD Module Reference

This section provides a quick reference for all MCAL and CDD modules available in the `drivers/` directory.

### MCAL Modules (AUTOSAR Standard)

| Module | Description | When to Use |
|--------|-------------|-------------|
| **Can** | Provides services for basic transmission and reception of CAN frames in both interrupt and polling mode. Supports CAN 2.0 A/B, ISO 11898-1:2015, and full CAN FD (up to 64 data bytes, 5 Mbps data rate). | Use for vehicle network communication, diagnostics, and inter-ECU messaging requiring robust, high-speed serial communication. |
| **Dio** | Abstracts access to microcontroller's hardware pins for digital input/output operations. Provides services for reading/writing to DIO channels, ports, and channel groups. | Use for controlling LEDs, reading switches/buttons, interfacing with simple digital sensors, or any GPIO-based I/O operations. |
| **Fls** | Provides services for reading, writing, erasing, and protecting internal data flash memory. Supports asynchronous operations with blank check and compare functions. | Use for non-volatile data storage, calibration data, configuration parameters, or any application requiring persistent storage. |
| **Gpt** | Initializes and controls internal General Purpose Timers (CPU-Timer0, CPU-Timer1, CPU-Timer2). Supports one-shot and continuous modes with configurable notifications. | Use for time-based scheduling, periodic task triggering, timeout monitoring, or any application requiring precise timing intervals. |
| **Lin** | Communication driver for Local Interconnect Network (LIN) protocol. Supports LIN 1.3, 2.0, and 2.1 protocols with configurable baud rates up to 20 kbps. | Use for low-cost, low-speed communication with sensors, actuators, and sub-systems where CAN bandwidth is not required (e.g., seat controls, mirrors, rain sensors). |
| **Mcu** | Provides services for microcontroller initialization including clock configuration, PLL setup, RAM initialization, reset control, and power mode management. | Use as the foundation module - must be initialized first before any other MCAL driver. Required for clock setup and system initialization. |
| **Port** | Initializes and configures the entire PORT structure of the microcontroller. Assigns pins to various functionalities (GPIO, CAN, SPI, ADC, LIN, etc.). | Use to configure pin multiplexing, direction, and characteristics. Must be initialized after Mcu and before peripheral drivers that use GPIO pins. |
| **Spi** | Provides channel-based read, write, and transfer access to SPI devices. Supports 1-16 bit data words, multiple clocking schemes, and 16-level FIFO. | Use for high-speed communication with external devices like EEPROMs, sensors, displays, or any SPI-compatible peripherals. |
| **Wdg** | Provides services for watchdog timer initialization, mode changes, and trigger condition setting. Supports reset mode, interrupt mode, and windowed watchdog operation. | Use for system safety monitoring to detect software hangs or runaway conditions and trigger recovery actions. |

### CDD Modules (Complex Device Drivers - TI Specific)

| Module | Description | When to Use |
|--------|-------------|-------------|
| **Cdd_Adc** | Analog-to-Digital Converter driver supporting 12/16-bit resolution, up to 80 single-ended channels, 32 SOCs, hardware oversampling, post-processing blocks (PPB), and safety checkers. | Use for reading analog sensor values (temperature, pressure, voltage, current), motor control feedback, or any analog signal acquisition. |
| **Cdd_Ecap** | Enhanced Capture driver for measuring timing of external events. Supports period/duty cycle measurement, edge detection/notification, edge counting, and timestamping. | Use for speed measurement of rotating machinery, pulse width/period measurement, position sensing, or decoding duty-cycle encoded signals. |
| **Cdd_I2c** | Inter-Integrated Circuit (I2C) driver providing communication interface for I2C bus devices. Supports controller mode, 7/10-bit addressing, and configurable baud rates. | Use for communication with I2C sensors, EEPROMs, RTCs, or other I2C-compatible devices on the bus. |
| **Cdd_Ipc** | Inter-Processor Communication driver enabling communication between the AUTOSAR core and other cores running SDK-based applications. Supports up to 12 bytes per message with 255 logical channels. | Use for multi-core applications where the AUTOSAR stack needs to exchange data with SDK-based software running on other CPU cores. |
| **Cdd_Pwm** | Enhanced Pulse Width Modulation driver for generating PWM signals. Supports simple mode (basic PWM) and advanced mode (trip zones, dead-band, chopper, digital compare). | Use for motor control, power conversion, LED dimming, or any application requiring precise PWM waveform generation. |
| **Cdd_Sent** | Single Edge Nibble Transmission driver for receiving data from SENT sensors. Supports standard SENT and MTP (Master Trigger Pulse) modes with up to 4 sensors per instance. | Use for interfacing with SENT-compatible sensors (common in automotive for position, pressure, and temperature sensing). |
| **Cdd_Uart** | Universal Asynchronous Receiver/Transmitter driver for serial communication. Supports up to 25 Mbps, 16-deep FIFOs, and configurable data formats (5-8 bits, parity, stop bits). | Use for debug console output, communication with external devices, or any asynchronous serial communication needs. |
| **Cdd_Xbar** | Crossbar driver for routing signals between device inputs, outputs, and internal resources. Supports Input, Output, CLB, ePWM, MINDB, and ICL crossbars. | Use for flexible signal routing, connecting GPIO to peripherals, routing internal signals to outputs, or configuring complex signal paths. |

### Utility Modules

| Module | Description | When to Use |
|--------|-------------|-------------|
| **Mcal_Lib** | Utility library providing common functions used by MCAL drivers, including `McalLib_Delay()` for timing delays. | Use `McalLib_Delay()` for timing delays instead of inline NOP instructions or busy-wait loops. |

> **Note:** All modules support AUTOSAR 4.3.1 specification. Vendor ID: 44 (Texas Instruments).

## Folder Structure

### Top-Level Directory Structure

``` text
f29h85x_mcal/
├── CMakeLists.txt              # Root CMake build configuration
├── CMakePresets.json           # CMake presets for different build configurations
├── mcal_release_notes.pdf      # Release notes with version info
├── license.txt                 # License information
├── drivers/                    # MCAL driver source code
├── plugins/                    # EB Tresos configuration plugins
├── examples/                   # Example applications
└── docs/                       # Documentation
```

### Drivers Directory Structure

The `drivers/` directory contains all MCAL driver implementations.

Each driver module follows a consistent internal structure:

``` text
drivers/<Module>/
├── CMakeLists.txt              # Driver build configuration
├── include/                    # Header files
│   ├── <Module>.h              # Public API header
│   ├── <Module>_Priv.h         # Private/internal header
│   └── <Module>_Utils.h        # Utility functions header (if applicable)
└── src/                        # Source files
    ├── <Module>.c              # Main driver implementation
    ├── <Module>_Priv.c         # Private implementation
    ├── <Module>_Irq.c          # Interrupt handlers (if applicable)
    └── <Module>_Utils.c        # Utility functions (if applicable)
```

**BSW_Stubs Directory:**

Contains stub implementations for AUTOSAR BSW modules used only in bare-metal examples:

``` text
drivers/BSW_Stubs/
├── AUTOSAR_Types/          # Standard AUTOSAR type definitions
├── Dem/                    # Diagnostic Event Manager stubs
├── Det/                    # Default Error Tracer stubs
├── EcuM/                   # ECU Manager stubs
├── Os/                     # OS stubs
├── SchM/                   # Schedule Manager stubs
├── CanIf/                  # CAN Interface stubs
├── LinIf/                  # LIN Interface stubs
├── PduR/                   # PDU Router stubs
├── Fee/                    # Flash EEPROM Emulation stubs
└── MemMap/                 # Memory mapping stubs
```

> ⚠️ **Warning:** Never use BSW_Stubs in production AUTOSAR applications - use your BSW vendor's implementations instead.

### Plugins Directory Structure

The `plugins/` directory contains EB Tresos configuration plugins.

Each plugin follows this internal structure:

``` text
plugins/<Module>_TI_F29H85x/
├── plugin.xml                  # Plugin descriptor for EB Tresos
├── META-INF/                   # Plugin metadata
│   ├── MANIFEST.MF             # OSGi manifest
│   ├── CRYPTOMANIFEST.MF       # Cryptographic manifest
│   └── CRYPTOMANIFESTSIG.MF    # Cryptographic signature
├── config/                     # Module configuration definitions
│   ├── <Module>.xdm            # XDM configuration schema
│   └── <Module>.arxml          # AUTOSAR module definition
├── generate/                   # Code generation templates
│   ├── include/
│   │   └── <Module>_Cfg.h      # Configuration header template
│   └── src/
│       ├── <Module>_Cfg.c      # Configuration source template
│       ├── <Module>_Lcfg.c     # Link-time config template
│       └── <Module>_PBcfg.c    # Post-build config template
└── generate_swcd/              # BSWMD generation templates
    └── swcd/
        └── <Module>_BSWMD.arxml  # BSW Module Description template
```

### Examples Directory Structure

The `examples/` directory contains example applications organized by module:

``` text
examples/
├── CMakeLists.txt              # Main examples build file
├── AppUtils/                   # Shared utilities (Printf, debug)
├── DeviceSupport/              # Device startup code and linker files
├── <Module>/                   # <Module> examples

```

**AppUtils Directory:**

``` text
examples/AppUtils/
├── AppUtils.c                  # Printf and debug utility implementations
├── AppUtils.h                  # Utility function declarations
└── CMakeLists.txt              # Build configuration
```

**DeviceSupport Directory:**

``` text
examples/DeviceSupport/
├── CMakeLists.txt              # Build configuration
├── makefile.defs               # Makefile definitions
├── include/                    # Device header files
├── src/                        # Startup and initialization code
├── LinkerCMD/                  # Linker command files for each variant
├── targetconfigs/              # CCS target configuration files
├── DeviceSupport_Example_Emulate_f29p32x/  # F29P32x emulation example
└── DeviceSupport_Example_Emulate_f29p58x/  # F29P58x emulation example
```

### Example Structure Patterns

Examples follow two organizational patterns depending on device variant support:

#### Pattern 1: Single-Variant Examples (F29H85x only)

For examples that only support F29H85x:

``` text
examples/<Module>/<ExampleName>/
├── CMakeLists.txt                    # Example build configuration
├── <ExampleName>.c                   # Main example source code
├── <ExampleName>.h                   # Example header (if needed)
├── CCS/                              # Code Composer Studio project
│   └── <ExampleName>.projectspec     # CCS project specification
└── <ExampleName>_Config/             # EB Tresos configuration project
    ├── .project                      # EB Tresos project file
    ├── CMakeLists.txt                # Config build integration
    ├── config/                       # Configuration source files (.xdm)
    │   ├── Mcu.xdm                   # MCU configuration
    │   ├── Port.xdm                  # Port configuration
    │   ├── <Module>.xdm              # Module-specific configuration
    │   ├── ResourceAllocator.xdm     # Resource allocation
    │   ├── Dem.xdm                   # Diagnostic Event Manager
    │   ├── EcuM.xdm                  # ECU Manager
    │   └── Os.xdm                    # OS configuration
    └── output/                       # Generated configuration files
        ├── include/                  # Generated headers (*_Cfg.h)
        ├── src/                      # Generated source (*_PBcfg.c)
        └── swcd/                     # Generated BSWMD (*_BSWMD.arxml)
```

**Example - Dio_Example_Read_Write_All:**

``` text
examples/Dio/Dio_Example_Read_Write_All/
├── CMakeLists.txt
├── Dio_Example_Read_Write_All.c
├── CCS/
│   └── Dio_Example_Read_Write_All.projectspec
└── Dio_Example_Read_Write_Config/
    ├── config/
    │   ├── Dio.xdm
    │   ├── Mcu.xdm
    │   ├── Port.xdm
    │   └── ...
    └── output/
        ├── include/
        ├── src/
        └── swcd/
```

#### Pattern 2: Multi-Variant Examples (F29H85x, F29P32x, F29P58x)

For examples supporting multiple device variants, common configuration is shared while device-specific configuration is separated:

``` text
examples/<Module>/<ExampleName>/
├── CMakeLists.txt                    # Example build configuration
├── <ExampleName>.c                   # Main example source (shared)
├── <ExampleName>.h                   # Example header (shared)
├── Common/                           # Shared configuration
│   └── tresos/
│       └── config/                   # Device-independent configs
│           ├── Mcu.xdm               # MCU config (shared)
│           ├── <Module>.xdm          # Module config (shared)
│           ├── Dem.xdm
│           ├── EcuM.xdm
│           └── Os.xdm
├── F29H85x/                          # F29H85x-specific files
│   ├── CCS/
│   │   └── <ExampleName>.projectspec
│   └── <ExampleName>_Config/
│       ├── config/                   # Device-specific configs
│       │   ├── Port.xdm              # Pin assignments for F29H85x
│       │   └── ResourceAllocator.xdm
│       └── output/                   # Generated files for F29H85x
├── F29P32x/                          # F29P32x-specific files
│   ├── CCS/
│   │   └── <ExampleName>.projectspec
│   └── <ExampleName>_Config/
│       ├── config/
│       │   ├── Port.xdm              # Pin assignments for F29P32x
│       │   └── ResourceAllocator.xdm
│       └── output/
└── F29P58x/                          # F29P58x-specific files
    ├── CCS/
    │   └── <ExampleName>.projectspec
    └── <ExampleName>_Config/
        ├── config/
        │   ├── Port.xdm              # Pin assignments for F29P58x
        │   └── ResourceAllocator.xdm
        └── output/
```

### Docs Directory Structure

``` text
docs/
├── User_Guide/                 # HTML User Guide (start with index.html)
├── Static_Analysis/            # Static analysis reports
└── Test_Report/                # Test reports
```

### What to Find Where

| Directory | Purpose | When to Use |
| --------- | ------- | ----------- |
| `drivers/<Module>/include/` | Public API headers | Include in your application |
| `drivers/<Module>/src/` | Driver implementation | Reference for understanding behavior |
| `drivers/BSW_Stubs/` | Stub BSW modules | **Bare-metal examples only** - never for production |
| `plugins/<Module>_TI_F29H85x/` | EB Tresos plugins | Copy to EB Tresos installation |
| `examples/<Module>/` | Example applications | Starting point for your application |
| `examples/AppUtils/` | Debug utilities | Use `AppUtils_Printf()` for debugging |
| `examples/DeviceSupport/` | Startup code & linkers | Reference implementation (customize for production) |
| `docs/User_Guide/` | HTML documentation | Primary reference for all modules |

## Getting Started

### Prerequisites

1. **TI CGT C29 Clang Compiler** (`c29clang`) - See release notes for version
2. **Code Composer Studio (CCS)** - For debugging and project import
3. **EB Tresos Studio** - For driver configuration (request from [MCAL-EB-TRESOS](https://www.ti.com/drr/opn/PROCESSOR-SDK-MCAL-EB-TRESOS))
4. **CMake** - For command-line builds

### Installation

1. Download the MCAL package from [ti.com](https://www.ti.com/tool/F29-SDK)
2. Run the installer and follow the wizard
3. Copy `{MCAL_INSTALL_PATH}/plugins/*` to `{EB_INSTALLATION_PATH}/tresos/plugins/`

### EB Tresos License Setup

1. Install **EB Client License Administrator** and activate with the provided key
2. Install **EB Tresos Studio** (version specified in release notes)

## Configuration Workflow

> 🤖 **IMPORTANT: AI Agent Rule for XDM and Auto-Generated Files**
>
> **AI assistants must NEVER directly edit `.xdm` files or auto-generated configuration files.** These files require the EB Tresos GUI for proper modification.
>
> **Files that must NOT be edited directly:**
>
> 1. **`.xdm` files** - EB Tresos configuration source files
> 2. **Auto-generated `.c` and `.h` files** - Generated by EB Tresos from `.xdm` configurations:
>    - Typically named: `<ModuleName>_Cfg.h`, `<ModuleName>_Cfg.c`, `<ModuleName>_Lcfg.c`, `<ModuleName>_PBcfg.c`
>    - Located in the `output/` folder inside `*_Config/` directories (e.g., `<Example>_Config/output/include/` and `<Example>_Config/output/src/`)
>    - Any manual changes to these files will be **overwritten** when the configuration is regenerated
>
> When configuration changes are needed, AI assistants should:
>
> 1. **Provide a summary** of the required configuration changes
> 2. **Specify which module and parameters** need to be modified
> 3. **Indicate the values** that should be set
> 4. **Ask the user** to make the changes in EB Tresos
> 5. **Provide step by step guide** in case any changes are required in XDM file. The parameter names for particular module can be found under `plugins\{ModuleName}_TI_F29H85x\config\[In case of Cdd add Cdd_]{ModuleName}.xdm`
>
> Example response format:
>
> ``` text
> To enable the SPI interrupt, please make the following changes in EB Tresos:
> 1. Open EB Tresos and load your project
> 2. Navigate to the Spi module in the project explorer
> 3. Expand SpiGeneral container
> 4. Locate the SpiInterruptMode parameter
> 5. Change the value from current setting to LEVEL
> 6. Save the configuration and regenerate
>
> Reference: Parameter definitions can be found in plugins\Spi_TI_F29H85x\config\Spi.xdm
> ```

### AI Agent Additional Guidelines

> 🤖 **Additional Rules for AI Assistants**
>
> 1. **Don't use SysCfg for MCAL projects** - SysCfg is not compatible with MCAL. Use EB Tresos for all configuration needs.
>
> 2. **For delays, use McalLib instead of adding NOPs** - Use delay functions from [`drivers/Mcal_Lib/src/Mcal_Lib.c`](drivers/Mcal_Lib/src/Mcal_Lib.c) instead of inline NOP instructions or busy-wait loops. Choose the appropriate function based on the time unit:
>    - `McalLib_DelayMsec(delayMsec)` - For delays in **milliseconds**
>    - `McalLib_DelayUsec(delayUsec)` - For delays in **microseconds**
>    - `McalLib_Delay(loopcnt)` - For delays in **CPU cycles** (low-level, each loop iteration takes 4 cycles)
>
> 3. **Use AppUtils for debug UART prints** - Use `AppUtils_Printf()` from `examples/AppUtils/` for debug output instead of implementing custom UART print functions.
>
> 4. **Symbolic Names for MCAL/CDD APIs** - The symbolic names passed to MCAL/CDD APIs are constructed following AUTOSAR TPS_ECUC_02108 rule:
>    - Format: `{Mip}Conf_{ContainerDef}_{ContainerValue}`
>    - Where:
>      - `{Mip}` = Module implementation prefix (e.g., `Spi`, `Can`, `Dio`) or `apiServicePrefix` for CDDs
>      - `Conf_` = Literal string "Conf_"
>      - `{ContainerDef}` = shortName of the EcucParamConfContainerDef
>      - `{ContainerValue}` = shortName of the EcucContainerValue container holding the symbolicNameValue
>    - Example: `DemConf_DemEventParameter_CORTSI_E_CORE_FAILURE_1`
>    - **Important:** When suggesting container names in EB Tresos, ensure the shortName matches what will be used in the API calls.
>
> 5. **Don't use AUTOSAR modules other than those in drivers/** - Only use AUTOSAR modules provided under the `drivers/` directory. Do not introduce external AUTOSAR BSW modules or third-party implementations.
>
> 6. **Scan examples directory for reference** - Before implementing or modifying code, scan the `examples/` directory to find a similar example for the user's request. Use it as a reference to maintain consistency in coding patterns, configuration structure, and best practices.
>
> 7. **Device properties from ResourceAllocator** - To determine device-specific properties (available peripherals, pin counts, etc.):
>    - Read the Device, Variant, and Package from `config/ResourceAllocator.xdm` in the example
>    - Use the corresponding properties files under `plugins/ResourceAllocator_TI_F29H85x/resources/`
>    - Path pattern: `plugins/ResourceAllocator_TI_F29H85x/resources/{Device}/{Variant}/ResourceAllocator_{Package}.properties`
>    - Example: For `Device=F29H859TU_Q1`, `Variant=F29H859TU8_Q`, `Package=F29H859TU8_Q_256ZEX`:
>      - `plugins/ResourceAllocator_TI_F29H85x/resources/F29H859TU_Q1/ResourceAllocator_F29H859TU_Q1.properties`
>      - `plugins/ResourceAllocator_TI_F29H85x/resources/F29H859TU_Q1/F29H859TU8_Q/ResourceAllocator_F29H859TU8_Q.properties`
>      - `plugins/ResourceAllocator_TI_F29H85x/resources/F29H859TU_Q1/F29H859TU8_Q/ResourceAllocator_F29H859TU8_Q_256ZEX.properties`
>    - For pin mux modes, refer to `drivers/Port/include/Port_Pin_Map.h`
>
> 8. **Ask user for pin selection based on board design** - Pin assignments depend on the user's hardware design. Always ask the user which pins to use for a specific function unless they are using a known evaluation board.
>    - **F29H85X-SOM-EVM default pins:**
>
>      | Function | GPIO Pin | Notes |
>      | -------- | -------- | ----- |
>      | User LED3 (Green) | GPIO23 | Active low |
>      | User LED4 (Green) | GPIO9 | Active low |
>
>    - For custom boards, ask the user to provide the pin mapping from their schematic.
>
> 9. **Verify driver init requirement before EcuM configuration** - Before asking users to configure a driver's initialization in the EcuM module via EB Tresos, first verify that the driver actually requires initialization by checking the `<ModuleName>.c` file in `drivers/<ModuleName>/src/`. Look for a `<ModuleName>_Init()` function to confirm the driver needs EcuM configuration.
>
> 10. **Adding missing modules to project** - If a build fails in CCS due to unavailability of any module or driver, those files can be added to the project by modifying the `.project` file present in the CCS project directory.
>
> 11. **Wait Bootloader / Program Crash Detection** - While debugging, if the program counter reaches any of the following ROM addresses, it indicates the program has crashed or an exception occurred (bootrom entered wait boot mode):
>     - `0x0001535C` (PG1.0/1.1) or `0x0001549C` (PG2.0) - Triggered when: wait boot (0x04) bootmode is selected via BMSP, FLASH mode is selected but erased, or boot fails in Link0 due to NMI/SSU Configuration/APR configuration errors.
>     - `0x00014EB0` (PG1.0/1.1) or `0x00015040` (PG2.0) - Triggered when boot fails in Link1.
>

### Creating a New EB Tresos Project

1. Launch EB Tresos → File → New → Configuration Project
2. Select **F29H85x** as the Target (always use F29H85x, even for F29P32x/F29P58x variants)
3. Add required modules (typically: Mcu, Port, and your peripheral drivers)
4. Select "Default Recommended Configuration" when available

### Configuring and Generating

1. Configure parameters in the module GUI
2. Click **Settings → AutoCalc** to calculate derived values (required before generate)
3. Right-click project → **Verify Project** to check for errors
4. Right-click project → **Generate Project** to create configuration files

Generated files appear in `output/` subdirectory:

- `output/include/*_Cfg.h` - Configuration headers
- `output/src/*_PBcfg.c` - Post-build configuration
- `output/swcd/*_BSWMD.arxml` - BSW Module Description

### Loading Example Configurations

1. Launch EB Tresos → File → Import
2. Browse to the example's configuration folder (e.g., `examples/Can/Can_Example_Classic_FD/F29H85x/Can_Example_Classic_FD_Config`)
3. Select the configuration project to import
4. The example configuration will be loaded and ready for use

## Building Examples

### Using CMake

**Configure:**

```shell
# Replace <version> with the compiler version from mcal_release_notes.pdf (e.g., 1.0.0LTS)
cmake -S . --preset mingw-c2000-f29h85x -DCMAKE_BUILD_TYPE=Debug -DBUILD_CONFIGURATION=FLASH -DTCP="C:\ti\ti-cgt-c29_<version>"
```

**Build:**

```shell
cmake --build build/artefacts -t <ExampleName>
```

### CMake Options

| Option | Values | Description |
| ------ | ------ | ----------- |
| `TCP` | Path | Compiler path (required if not in system PATH) |
| `CMAKE_BUILD_TYPE` | Debug, Release | Debug includes symbols; Release enables optimization |
| `BUILD_CONFIGURATION` | RAM, FLASH | RAM for debugging; FLASH for production (requires signing) |

### Using Code Composer Studio

1. File → Import → CCS Projects
2. Browse to `examples/<Module>/<Example>/CCS/`
3. Select the `.projectspec` file
4. Build and debug from CCS

## AUTOSAR Integration

### Integrating with Third-Party BSW Stacks

TI MCAL modules can be imported into other AUTOSAR tools (Vector DaVinci, ETAS ISOLAR-AB, etc.):

**Required files:**

1. **MCAL Export (ARXML)** - Export from EB Tresos via Im- and Exporters
2. **Vendor-Specific Module Definition** - In `plugins/<Module>_TI_F29H85x/config/<Module>.arxml`
3. **BSWMD File** - Generate via Build Project → Generate_SWC-T

**Note:** MCAL configuration should always be done in EB Tresos. Import into other tools is for reference only.

### BSW Stubs Warning

The `drivers/BSW_Stubs/` folder contains stub implementations for bare-metal examples only. **Never use these in production AUTOSAR applications** - use your BSW vendor's implementations instead.

## Important Gotchas

### Configuration Gotchas

- **Never manually edit generated files** - Changes will be overwritten on regenerate
- **Never directly edit `.xdm` files** - These must be modified through EB Tresos GUI only (see AI Agent Rule above)
- **Always use F29H85x as target** in EB Tresos, even for F29P32x/F29P58x devices
- **Run AutoCalc before Generate** - Many parameters have dependencies that must be calculated
- **ResourceAllocator module** - Required for pin/peripheral allocation

### Build Gotchas

- **FLASH builds require signing** - Handled automatically by the build system
- **Linker files are for superset variants** - Modify for your specific device's memory sizes
- **DeviceSupport code is reference only** - Replace with your own startup code for production

### Integration Gotchas

- **Driver initialization order matters:** Mcu → Port → Other peripherals
- **MCAL runs on CPU1 only** - CPU2/CPU3 support not included in current release

## Troubleshooting

### EB Tresos Issues

| Problem | Solution |
| ------- | -------- |
| Plugins not appearing | Verify plugins copied to `{EB_INSTALLATION_PATH}/tresos/plugins/` |
| Validation errors | Run Settings → AutoCalc before generating |

### Build Issues

| Problem | Solution |
| ------- | -------- |
| Compiler not found | Set `-DTCP=<path>` or add compiler to system PATH |
| Version mismatch errors | Regenerate configuration files |
| Signing fails (FLASH) | Check Python is installed |

### Runtime Issues

| Problem | Solution |
| ------- | -------- |
| Driver init fails | Verify Mcu_Init() called first; check clock configuration |
| Peripheral not responding | Verify Port configuration for the peripheral pins |
| Program enters wait mode | Emulation API detected unavailable resource; check device variant |

### Debugging Tips

1. **Enable DET:** Set `<MODULE>_DEV_ERROR_DETECT = STD_ON` for runtime checks
2. **Use AppUtils:** `AppUtils_Printf()` outputs to UART for debugging
3. **Check linker map:** Verify section placement in `build/assets/<example>.map`

## Device Variant Emulation

For F29P32x/F29P58x variants, use the Emulation API before ECU initialization:

```c
DeviceSupport_EmulateDevice(DEVICE_F29P329SM2);
```

See `docs/User_Guide/index.html` for available device macros.

## Documentation Resources

| Resource | Location |
| -------- | -------- |
| **User Guide** | `docs/User_Guide/index.html` |
| Release Notes | `mcal_release_notes.pdf` |
| EB Tresos Guide | `{EB_INSTALLATION_PATH}/tresos/doc/` |
| Online Documentation | <https://software-dl.ti.com/C2000/docs/mcal/F29H85x/latest/index.html> |

## Quick Reference

### Driver Initialization Pattern

```c
// 1. Initialize MCU (clocks, reset)
Mcu_Init(&Mcu_Config);
Mcu_InitClock(McuClockSettingConfig_0);
while (Mcu_GetPllStatus() != MCU_PLL_LOCKED) {}
Mcu_DistributePllClock();

// 2. Initialize Port (GPIO configuration)
Port_Init(&Port_Config);

// 3. Initialize peripheral drivers
Spi_Init(&Spi_Config);
```

### AUTOSAR API Pattern

All MCAL drivers follow consistent naming:

- `<Module>_Init(ConfigPtr)` - Initialize driver
- `<Module>_DeInit()` - De-initialize driver  
- `<Module>_GetVersionInfo(versioninfo)` - Get version
- `<Module>_GetStatus()` - Get current status

### File Naming Conventions

| File Pattern | Description |
| ------------ | ----------- |
| `*.xdm` | EB Tresos configuration source |
| `*_Cfg.h` | Generated compile-time configuration |
| `*_PBcfg.c` | Generated post-build configuration |
| `*_BSWMD.arxml` | BSW Module Description |

## IMPORTANT: Default UART Settings

**ALWAYS use these UART settings by default unless user specifies otherwise:**

- **Baud Rate**: 115200 (NEVER use 9600 unless explicitly requested)
- **Data Bits**: 8
- **Parity**: None
- **Stop Bits**: 1
