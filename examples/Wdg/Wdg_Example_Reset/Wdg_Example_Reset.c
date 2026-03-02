/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Wdg_Example_Reset.c
 *  Generator:  None
 *
 *  Description:  Watchdog Reset Demonstration Example
 *
 *  This example demonstrates the watchdog timer reset functionality when the watchdog
 *  is intentionally not serviced. Expected reset reason after watchdog expiry: MCU_WATCHDOG_RESET (3)
 *  This demonstrate watchdog timeout behavior and system reset mechanism
 *      - Show how to detect and identify watchdog reset as the reset source
 *      - Illustrate persistent data storage across watchdog resets using USER registers
 *
 *  1. Initialization Phase:
 *     - Reads the reset reason using Mcu_GetResetReason() API
 *     - Detects non-watchdog reset (typically MCU_POWER_ON_RESET = 0)
 *     - Initializes the watchdog in SLOW mode with a configurable timeout period but intentionally does
 *       NOT call Wdg_SetTriggerCondition()
 *     - Waits for the watchdog to expire and trigger a system reset
 *
 *  2. Subsequent Executions (After Watchdog Reset):
 *     - Detects MCU_WATCHDOG_RESET (value = 3) as the reset reason
 *     - Increments a persistent counter stored in USER_REG1_PORESETN register
 *     - This register persists across watchdog resets but clears on power-on reset
 *     - Repeats the watchdog timeout cycle up to MAX_WDG_RESET (20) times
 *
 *  3. Completion:
 *     - After 20 watchdog resets, disables the watchdog using Wdg_SetMode(WDGIF_OFF_MODE)
 *     - Clears the persistent counter register
 *     - Reports successful completion of the test
 *
 *  NOTE: This example intentionally does NOT service the watchdog to demonstrate
 *  the reset behavior. In production applications, Wdg_SetTriggerCondition() must
 *  be called periodically within the configured timeout to prevent unintended resets.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Wdg.h"
#include "Os.h"
#include "Platform_Types.h"
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "Mcu.h"
#include "Port.h"
#include "AppUtils.h"
#include "DeviceSupport.h"

/* Hardware register access for persistent USER registers */
#include "hw_sysctl.h"
#include "hw_types.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
/* Use USER_REG1_PORESETN register which persists across watchdog resets
 * CPUSYS_BASE is the base address for CPU system control registers */
#define PERSISTENT_COUNTER_REG (HWREG(CPUSYS_BASE + SYSCTL_O_USER_REG1_PORESETN))

/* Magic number to validate the register has been initialized */
#define COUNTER_MAGIC_MASK 0xDEAD0000U
#define COUNTER_VALUE_MASK 0x0000FFFFU

#define MAX_WDG_RESET 20U

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

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
static uint32  ReadPersistentCounter(void);
static void    WritePersistentCounter(uint32 counter);
static boolean IsPersistentCounterValid(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/** \brief Check if persistent counter register has valid data */
static boolean IsPersistentCounterValid(void)
{
    uint32 reg_value = PERSISTENT_COUNTER_REG;
    return ((reg_value & 0xFFFF0000U) == COUNTER_MAGIC_MASK);
}

/** \brief Read counter from persistent register */
static uint32 ReadPersistentCounter(void)
{
    uint32 counter = 0U;

    if (IsPersistentCounterValid())
    {
        uint32 reg_value = PERSISTENT_COUNTER_REG;
        counter          = (reg_value & COUNTER_VALUE_MASK);
    }
    return counter;
}

/** \brief Write counter to persistent register */
static void WritePersistentCounter(uint32 counter)
{
    /* Combine magic number with counter value */
    uint32 reg_value = COUNTER_MAGIC_MASK | (counter & COUNTER_VALUE_MASK);

    /* Write to persistent register */
    PERSISTENT_COUNTER_REG = reg_value;
}

int main(void)
{
    Std_ReturnType return_value  = E_NOT_OK;
    uint16         Wdg_Timeout   = 0U;
    uint32         reset_counter = 0U;
    WdgIf_ModeType Wdg_Mode      = WDGIF_OFF_MODE;
    /* Store reset reason.*/
    Mcu_ResetType  mcu_reset_reason = MCU_RESET_UNDEFINED;

    DeviceSupport_Init();
    EcuM_Init();               /* PORT & MCU Initialization to get configuration settings */
    AppUtils_Init(200000000U); /* 200 MHZ system clock*/

    if (Wdg_Config.Wdg_DefaultMode == WDGIF_SLOW_MODE)
    {
        Wdg_Timeout = Wdg_Config.Wdg_SlowModeCfg.Timeout;
    }
    else
    {
        Wdg_Timeout = Wdg_Config.Wdg_FastModeCfg.Timeout;
    }

    /* Note: During the first execution(Power on reset),
     * the reset reason will not be WATCHDOG Reset.*/
    mcu_reset_reason = Mcu_GetResetReason();

    /* The watchdog is initialized and intentionally not serviced.
     * watchdog expires and triggers a wdg reset.
     * After the reset occurs, the reset reason is expected to be MCU_WATCHDOG_RESET=3.
     */
    AppUtils_Printf("------------------------------- \n");
    AppUtils_Printf("Wdg Reset Test Example !!!\n");
    AppUtils_Printf("------------------------------- \n");

    AppUtils_Printf("Detected Reset Reason: %d\n", mcu_reset_reason);
    AppUtils_Printf("Reset Reasons: 0=POWER_ON, 1=EXTERNAL, 2=ESM_NMI_WD, 3=WATCHDOG, 4=SW, 5=ESM, 6=UNDEFINED\n");
    AppUtils_Printf("----------------------------------------------------- \n");

    /* Read counter from persistent register */
    reset_counter = ReadPersistentCounter();

    Wdg_Init(&Wdg_Config); /* Slow mode configuration settings 3342 msec */

    if (mcu_reset_reason != MCU_WATCHDOG_RESET)
    {
        reset_counter = 0U;
        /* Non-watchdog reset: Demonstrate watchdog reset */
        AppUtils_Printf("Sample Application to test Wdg Reset - STARTS !!!\n");
        AppUtils_Printf("WDG is Initialized in Slow mode\n");
        AppUtils_Printf("Watchdog will NOT be serviced intentionally !!!\n");
        AppUtils_Printf("Watchdog reset will occur in %dms\n", Wdg_Timeout);
        AppUtils_Printf("----------------------------------------------------- \n");
        AppUtils_Printf("----------------------------------------------------- \n");

        /*
         * IMPORTANT:
         * No call to Wdg_SetTriggerCondition is made here intentionally.
         * This allows the watchdog to expire and trigger reset.
         */
    }
    else
    {
        /* Watchdog reset detected: Increment counter and check limit */
        AppUtils_Printf("Restarted after a Watchdog Reset !!!\n");

        /* Increment counter and save to persistent register */
        reset_counter++;
        WritePersistentCounter(reset_counter);

        AppUtils_Printf("Wdg Example Reset: Sample Application - Watchdog Reset #%d\n", reset_counter);
        AppUtils_Printf("----------------------------------------------------- \n");

        if (reset_counter >= MAX_WDG_RESET)
        {
            return_value = E_OK;

            /* Disable Wdg by calling WDGIF_OFF_MODE*/
            Wdg_SetMode(Wdg_Mode);

            AppUtils_Printf("----------------------------------------------------- \n");
            AppUtils_Printf("Total watchdog resets performed: %d\n", reset_counter);
            AppUtils_Printf("Sample Application to test Wdg Reset  - COMPLETED !!!\n");

            /* Clear the persistent register for next run */
            PERSISTENT_COUNTER_REG = 0U;
        }
    }

    /* Wait for the watchdog to reset */
    if ((mcu_reset_reason != MCU_WATCHDOG_RESET) || (reset_counter < MAX_WDG_RESET))
    {
        AppUtils_Printf("Waiting for watchdog to expire and trigger reset...\n");
        McalLib_DelayMsec(Wdg_Timeout + 500U);
    }

    return return_value;
}

/*********************************************************************************************************************
 *  End of File: Wdg_Example_Reset.c
 *********************************************************************************************************************/
