/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       DeviceSupport.c
 *  Generator:  None
 *
 *  Description:  DeviceSupport source file
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "DeviceSupport.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#ifdef MULTICORE_ENABLE_CPU3
#ifdef _FLASH
#define CPU3_RESET_VECTOR 0x10401000U
#else
#define CPU3_RESET_VECTOR 0x20118000U
#endif
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
//**************************************************************************************************
//
//! Values that can be passed as parameter \e cpu in all the functions
//
//**************************************************************************************************
typedef enum
{
    SSU_CPU1 = 0,
    SSU_CPU2 = 1,
    SSU_CPU3 = 2
} DEVICESUPPORT_SSU_CPUID;

//**************************************************************************************************
//
//! SSU Links
//
//**************************************************************************************************
typedef enum
{
    SSU_LINK0  = 0,
    SSU_LINK1  = 1,
    SSU_LINK2  = 2,
    SSU_LINK3  = 3,
    SSU_LINK4  = 4,
    SSU_LINK5  = 5,
    SSU_LINK6  = 6,
    SSU_LINK7  = 7,
    SSU_LINK8  = 8,
    SSU_LINK9  = 9,
    SSU_LINK10 = 10,
    SSU_LINK11 = 11,
    SSU_LINK12 = 12,
    SSU_LINK13 = 13,
    SSU_LINK14 = 14,
    SSU_LINK15 = 15,
} DEVICESUPPORT_SSU_Link;

//**************************************************************************************************
//
//! Values that can be passed as parameter \e reset in SSU_controlCPUReset()
//! functions
//
//**************************************************************************************************
typedef enum
{
    SSU_CORE_RESET_ACTIVE   = 0xC9,  //! CPU is held in reset
    SSU_CORE_RESET_DEACTIVE = 0x36   //! CPU reset is released (if no HSM) or
                                     //! determined by HSM input
} DEVICESUPPORT_SSU_CoreReset;

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
#ifdef _FLASH
#if !defined(__CPU2__) && !defined(__CPU3__)
//
//  Dummy certificate section which is updated when actual certificate is generated
//  as part of the post build steps
//
__attribute__((retain, section("cert"))) const uint8 certificate[4096U] = {0U};
#endif
#endif

#if !defined(__CPU2__) && !defined(__CPU3__)
#ifdef MULTICORE_ENABLE_CPU3
#ifndef CPU3_APPSIZE
#ifdef _FLASH
#define CPU3_APPSIZE 0x100000
#else
#define CPU3_APPSIZE 0x8000
#endif /* _FLASH */
#endif /* CPU3_APPSIZE */
__attribute__((retain, section("cpu3app"))) const uint8 cpu3App[CPU3_APPSIZE] = {0U};
#endif /* MULTICORE_ENABLE_CPU3 */
#endif /* !defined(__CPU2__) && !defined(__CPU3__) */

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#ifdef _FLASH
static void Flash_InitModule(uint16 waitstates);
#endif

#ifdef MULTICORE_ENABLE_CPU3

void DeviceSupport_ConfigBootAddress(DEVICESUPPORT_SSU_CPUID cpu, uint32 addr, DEVICESUPPORT_SSU_Link link);

void DeviceSupport_ControlCPUReset(DEVICESUPPORT_SSU_CPUID cpu, DEVICESUPPORT_SSU_CoreReset control);

static inline boolean DeviceSupport_IsCPU3Reset();

#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
//*****************************************************************************
//
// Delay instruction that allows for register configuration to complete.
//
//*****************************************************************************
#define FLASH_DELAY_CONFIG \
    __asm(" NOP #8");      \
    __asm(" NOP #8");      \
    __asm(" NOP #4");

#ifdef _FLASH
//*****************************************************************************
//
//! Configures FRI
//!
//! \param friID is the Flash_FRI enum associated with the FRI desired for
//! for configuration
//!
//! \param configFlags is the value to be written and should be built with values
//! from the FRI option macros
//!
//!
//! This function allows the user to configure FRI prefetch, data cache,
//! code cache, and data preread flags.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".TI.ramfunc.link2"))) static inline void Flash_ConfigFRI(Flash_FRI friID, uint32 configFlags)
{
    //
    // Set the FRI options.
    //
    HWREG(FRI1_BASE + FRI_O_1_INTF_CTRL + (friID * FRI_REG_STEP)) = configFlags;
}

//*****************************************************************************
//
//! Sets the random read wait state amount.
//!
//!
//! \param waitstates is the wait-state value.
//!
//! This function sets the number of wait states for a flash read access. The
//! \e waitstates parameter is a number between 1 and 15. It is \b important
//! to look at your device's datasheet for information about what the required
//! minimum flash wait-state is for your selected SYSCLK frequency.
//!
//! By default the wait state amount is configured to the maximum 15.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".TI.ramfunc.link2"))) static inline void Flash_SetWaitstates(uint16 waitstates)
{
    //
    // waitstates is 4 bits wide.
    //
    if ((waitstates <= 0xFU) && (waitstates >= 0x1U))
    {
        //
        // Write flash read wait-state amount to appropriate register.
        //
        HWREG(FRI1_BASE + FRI_O_FRDCNTL) = (HWREG(FRI1_BASE + FRI_O_FRDCNTL) & ~(uint32)FRI_FRDCNTL_RWAIT_M) |
                                           ((uint32)waitstates << FRI_FRDCNTL_RWAIT_S);
    }
}

//*****************************************************************************
//
//! Initializes the flash config 1 trim registers.
//!
//! \return None.
//!
//!
//*****************************************************************************
static inline void Flash_WriteTrims(uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{
    //
    // Set the requested bits to the value.
    //
    HWREG(ANALOGSUBSYS_BASE + reg_offset) &= ~(uint32)mask;

    HWREG(ANALOGSUBSYS_BASE + reg_offset) |= ((uint32)value << shift);
}
#endif
/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
void DeviceSupport_Init()
{
    /*Emulate selected device*/
#ifdef BUILD_DEVICE_F29P32X
    DeviceSupport_EmulateDevice(DEVICE_F29P329SM2Q);
#endif
#ifdef BUILD_DEVICE_F29P58X
    DeviceSupport_EmulateDevice(DEVICE_F29P589DU5Q);
#endif
#ifdef _FLASH
    //
    // Call Flash Initialization to setup flash waitstates. This function must
    // reside in RAM.
    //
    Flash_InitModule(DEVICE_FLASH_WAITSTATES);
#endif

#ifdef MULTICORE_ENABLE_CPU3
    //
    // Boot CPU3
    //
    DeviceSupport_ConfigBootAddress(SSU_CPU3, (uint32)CPU3_RESET_VECTOR, SSU_LINK2);
    //
    // Bring CPU3 out of reset. Wait for CPU3 to go out of reset.
    //
    DeviceSupport_ControlCPUReset(SSU_CPU3, SSU_CORE_RESET_DEACTIVE);
    while (DeviceSupport_IsCPU3Reset() == 0x1U)
        ;
#endif
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#ifdef _FLASH
__attribute__((section(".TI.ramfunc.link2"))) static void Flash_InitModule(uint16 waitstates)
{
    if ((waitstates <= 0xFU) && (waitstates >= 0x1U))
    {
        //
        // Disable data cache, code cache, prefetch, and data preread before changing wait states
        //
        Flash_ConfigFRI(FLASH_FRI1, FLASH_DATAPREREAD_DISABLE | FLASH_CODECACHE_DISABLE | FLASH_DATACACHE_DISABLE |
                                        FLASH_PREFETCH_DISABLE);
        Flash_ConfigFRI(FLASH_FRI2, FLASH_DATAPREREAD_DISABLE | FLASH_CODECACHE_DISABLE | FLASH_DATACACHE_DISABLE |
                                        FLASH_PREFETCH_DISABLE);
        Flash_ConfigFRI(FLASH_FRI3, FLASH_DATAPREREAD_DISABLE | FLASH_CODECACHE_DISABLE | FLASH_DATACACHE_DISABLE |
                                        FLASH_PREFETCH_DISABLE);
        Flash_ConfigFRI(FLASH_FRI4, FLASH_DATAPREREAD_DISABLE | FLASH_CODECACHE_DISABLE | FLASH_DATACACHE_DISABLE |
                                        FLASH_PREFETCH_DISABLE);

        //
        // Set waitstates according to frequency.
        //
        Flash_SetWaitstates(waitstates);

        //
        // Configure TRIMCOMMITREAD and TRIMCOMMITOTHER in TRIMCOMMIT register
        //
        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITREAD, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITREAD);
        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITOTHER, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITOTHER);

        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITREAD, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITREAD);
        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITOTHER, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITOTHER);

        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITREAD, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITREAD);
        Flash_WriteTrims(ASYSCTL_O_FLASHTRIMCOMMIT, ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITOTHER, 0,
                         ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITOTHER);

        //
        // Enable data cache, code cache, prefetch, and data preread to improve performance of code
        // executed from flash.
        //
        Flash_ConfigFRI(FLASH_FRI1, FLASH_DATAPREREAD_ENABLE | FLASH_CODECACHE_ENABLE | FLASH_DATACACHE_ENABLE |
                                        FLASH_PREFETCH_ENABLE);
        Flash_ConfigFRI(FLASH_FRI2, FLASH_DATAPREREAD_ENABLE | FLASH_CODECACHE_ENABLE | FLASH_DATACACHE_ENABLE |
                                        FLASH_PREFETCH_ENABLE);
        Flash_ConfigFRI(FLASH_FRI3, FLASH_DATAPREREAD_ENABLE | FLASH_CODECACHE_ENABLE | FLASH_DATACACHE_ENABLE |
                                        FLASH_PREFETCH_ENABLE);
        Flash_ConfigFRI(FLASH_FRI4, FLASH_DATAPREREAD_ENABLE | FLASH_CODECACHE_ENABLE | FLASH_DATACACHE_ENABLE |
                                        FLASH_PREFETCH_ENABLE);

        //
        // Force a pipeline flush to ensure that the write to the last register
        // configured occurs before returning.
        //

        FLASH_DELAY_CONFIG;
    }
}
#endif

#ifdef MULTICORE_ENABLE_CPU3

void DeviceSupport_ConfigBootAddress(DEVICESUPPORT_SSU_CPUID cpu, uint32 addr, DEVICESUPPORT_SSU_Link link)
{
    if (cpu == SSU_CPU2)
    {
        HWREG(SSUCPU2CFG_BASE + SSU_O_RST_VECT) = addr;
        HWREG(SSUCPU2CFG_BASE + SSU_O_RST_LINK) = link;
    }
    else if (cpu == SSU_CPU3)
    {
        HWREG(SSUCPU3CFG_BASE + SSU_O_RST_VECT) = (uint32)addr;
        HWREG(SSUCPU3CFG_BASE + SSU_O_RST_LINK) = link;
    }
    else
    {
        //
        // Invalid option
        //
    }
}

void DeviceSupport_ControlCPUReset(DEVICESUPPORT_SSU_CPUID cpu, DEVICESUPPORT_SSU_CoreReset control)
{
    if (cpu == SSU_CPU2)
    {
        HWREG(SSUCPU2CFG_BASE + SSU_O_CPU_RST_CTRL) = control;
    }
    else if (cpu == SSU_CPU3)
    {
        HWREG(SSUCPU3CFG_BASE + SSU_O_CPU_RST_CTRL) = control;
    }
    else
    {
        //
        // Invalid option
        //
    }
}

static inline boolean DeviceSupport_IsCPU3Reset()
{
    return ((HWREGH(DEVCFG_BASE + SYSCTL_O_RSTSTAT) & SYSCTL_RSTSTAT_CPU3) == 0U);
}

#endif

void DeviceSupport_EmulateDevice(Device_PartNumber partNumber)
{
    //
    // Update the MCUCNF registers value for different GPNs
    //

    switch (partNumber)
    {
        case DEVICE_F29H859TU8Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x3F0000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x3F0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x1FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0xF000FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x18U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFFFFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0xFFFFU;
            break;
        case DEVICE_F29H859TM8Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x3F0000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x3F0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x1FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0xF000FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x18U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFFFFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0xFFU;
            break;
        case DEVICE_F29H859DU6Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x3F0000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x3F0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x1FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x3FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0xF000FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x10U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFFFFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0xFFFFU;
            break;
        case DEVICE_F29P589DU5Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0xF0000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0xF0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x1FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0x70007U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x8U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0xFFFFU;
            break;
        case DEVICE_F29P589DM5Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0xF0000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0xF0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x1FU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0x70007U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x8U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0x0U;
            break;
        case DEVICE_F29P329SJ1Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x1DFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x70U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x7U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0x1U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0x30003U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x8U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0x0U;
            break;
        case DEVICE_F29P329SM1Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x1DFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x70U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0x7U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0x1U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0x30003U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x8U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0x0U;
            break;
        case DEVICE_F29P329SM2Q:
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF1)  = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF2)  = 0x1DFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF4)  = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF7)  = 0x30000U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF10) = 0x70U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF13) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF14) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF16) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF17) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF18) = 0x30003U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF19) = 0x3U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF23) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF26) = 0xFFFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF31) = 0x3FFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF64) = 0x8U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF65) = 0xFF33U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF74) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF76) = 0xFFFFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF78) = 0xFU;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF79) = 0x0U;
            HWREG(DEVCFG_BASE + SYSCTL_O_MCUCNF81) = 0x0U;
            break;
        default:
            break;
    }
}

/*********************************************************************************************************************
 *  End of File: DeviceSupport.c
 *********************************************************************************************************************/
