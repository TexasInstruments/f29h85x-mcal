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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Mcu_Example_Clock.c
 *  Generator:  None
 *
 *  Description:  This file contains example application for Mcu Driver module
 *
 *  This example demonstrates how to configure the clocks using Mcu module; XCLKOUT pin is used
 *  for observing internal clocks through an external pin, for debugging and testing purposes.
 *
 *  On reset, by default XCLKOUT clock source is set to PLLSYSCLK (CPU clock)
 *  and the XCLKOUT divider is set to 8.
 *  Expected frequency of XCLKOUT = (PLLSYSCLK freq)/8 = 200/8 = 25MHz.
 *
 *  View the XCLKOUT on GPIO73 using an oscilloscope.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu.h"
#include "EcuM.h"
#include "Platform_Types.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/
/* Default internal oscillator frequency, 10 MHz */

#define SYSCTL_DEFAULT_OSC_FREQ (10000000U)

/* Defines related to clock configuration */

#define DEVICE_SYSCLK_FREQ (200000000U)
#define DEVICE_OSCSRC_FREQ (20000000U)
/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
uint32 Mcu_ApplGetClock(uint32 clockInHz)
{
    uint32 temp;
    uint32 oscSource;
    uint32 clockOut;
    uint32 imult, refDiv, oDiv, sysDiv;

    /* If one of the internal oscillators is being used, start from the
    /known default frequency.  Otherwise, use clockInHz parameter.*/

    oscSource = HWREG(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

    if ((oscSource == (uint32)MCU_CLKSRC_OSC2) || (oscSource == (uint32)MCU_CLKSRC_OSC1))
    {
        clockOut = SYSCTL_DEFAULT_OSC_FREQ;
    }
    else
    {
        clockOut = clockInHz;
    }

    /* If the PLL is enabled calculate its effect on the clock */
    if ((HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) & (SYSCTL_SYSPLLCTL1_PLLEN | SYSCTL_SYSPLLCTL1_PLLCLKEN)) == 3U)
    {
        imult = (HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & SYSCTL_SYSPLLMULT_IMULT_M) >> SYSCTL_SYSPLLMULT_IMULT_S;

        refDiv = (HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & SYSCTL_SYSPLLMULT_REFDIV_M) >> SYSCTL_SYSPLLMULT_REFDIV_S;

        oDiv = (HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & SYSCTL_SYSPLLMULT_ODIV_M) >> SYSCTL_SYSPLLMULT_ODIV_S;

        /* Calculate integer multiplier */
        clockOut = clockOut * imult;

        /* Calculate PLL divider */
        temp = (refDiv + 1U) * (oDiv + 1U);

        /* Divide dividers */
        if (temp != 0U)
        {
            clockOut /= temp;
        }
    }

    sysDiv = HWREG(DEVCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) & SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M;

    clockOut /= (sysDiv + 1U);

    return (clockOut);
}

int main(void)
{
    Std_ReturnType return_value = E_OK;
    uint32         sys_clock_out, loop_cnt;

    DeviceSupport_Init();
    EcuM_Init(); /* PORT & MCU Initilization to get configuration settings */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Sample Application - STARTS !!!\r\n");

    /*  get version Info */
#if (STD_ON == MCU_CFG_GET_VERSION_INFO_API)
    Std_VersionInfoType Mcu_VersionInfo;

    Mcu_GetVersionInfo(&Mcu_VersionInfo);
    AppUtils_Printf("MCU MCAL Version Info\r\n");
    AppUtils_Printf("---------------------\r\n");
    AppUtils_Printf("Vendor ID           : %d\r\n", Mcu_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\r\n", Mcu_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\r\n", Mcu_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\r\n", Mcu_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\r\n", Mcu_VersionInfo.sw_patch_version);
#endif

    sys_clock_out = Mcu_ApplGetClock(DEVICE_OSCSRC_FREQ);

    AppUtils_Printf("Generated System clock value : %d \r\n", sys_clock_out);

    /* Wait for few seconds so that user can probe the Clock on the configured GPIO pin */
    loop_cnt = 0U;
    while (loop_cnt < 30U)
    {
        AppUtils_Printf("Waiting for user to probe the clock on the configured GPIO pin ...  %d\r\n", loop_cnt);
        McalLib_DelayMsec(1000U, DEVICE_SYSCLK_FREQ);
        loop_cnt++;
    }

    AppUtils_Printf("Mcu_Example_Clock: Sample Application - Completes successfully !!!\r\n");

    return return_value;
}

/*********************************************************************************************************************
 *  End of File: Mcu_Example_Clock.c
 *********************************************************************************************************************/
