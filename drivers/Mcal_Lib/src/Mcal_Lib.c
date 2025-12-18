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
 *  File:       Mcal_Lib.c
 *  Generator:  None
 *
 *  Description:  Source file for library functions used by MCALs / CDDs
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/* Vendor specific version information is BCD coded */
#if ((MCAL_LIB_SW_MAJOR_VERSION != (1U)) || (MCAL_LIB_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Mcal_Lib.c and Mcal_lib.h are inconsistent!"
#endif
/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

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

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
__asm(
    "    .global McalLib_Delay        \n"
    "    .section .TI.ramfunc, \"ax\" \n"
    "McalLib_Delay:                   \n"
    "    MV A0,D0                     \n"
    "loop:                            \n"
    "    DECB A0, #1, loop            \n"
    "    RET                          \n");

#define MCAL_LIB_START_SEC_CODE
#include "Mcal_Lib_MemMap.h"

FUNC(void, MCAL_LIB_CODE) McalLib_DelayUsec(McalLib_TickType delayUsec)
{
    McalLib_TickType cycles, loopcnt;
    uint32           sysClkHz;

    sysClkHz = Mcu_GetSystemClock();
    if (sysClkHz == 0)
    {
        /* use a higher default sysclk so that the delays computed before Mcu initialization are safe.
         * Mcu_GetSystemClock return 0 if Mcu is not initialized */
        sysClkHz = MCAL_LIB_DEFAULT_SYSCLK_HZ;
    }

    cycles = (delayUsec * sysClkHz) / 1000000UL;
    if (cycles > 11U)
    {
        cycles -= 11U; /* each API call has 11 cycles of overhead*/
    }
    loopcnt = cycles >> 2U; /* each loop takes 4 cycles */
    McalLib_Delay(loopcnt);
}

FUNC(void, MCAL_LIB_CODE) McalLib_DelayMsec(McalLib_TickType delayMsec)
{
    McalLib_DelayUsec(delayMsec * 1000U);
}

void McalLib_GetCounterValue(P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) startTime)
{
    uint32 regValL;
    uint32 regValH;
    regValL    = *(volatile uint32 *)(IPCCOUNTER_BASE + IPC_O_COUNTERL);
    regValH    = *(volatile uint32 *)(IPCCOUNTER_BASE + IPC_O_COUNTERH);
    *startTime = (McalLib_TickType)(((McalLib_TickType)regValH << 32) | (McalLib_TickType)regValL);
    return;
}

FUNC(void, MCAL_LIB_CODE)
McalLib_GetElapsedValue(CONSTP2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) startTime,
                        P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) elapsedTime)
{
    McalLib_TickType cur_val;
    uint32           regValL;
    uint32           regValH;
    regValL      = *(volatile uint32 *)(IPCCOUNTER_BASE + IPC_O_COUNTERL);
    regValH      = *(volatile uint32 *)(IPCCOUNTER_BASE + IPC_O_COUNTERH);
    cur_val      = (McalLib_TickType)(((McalLib_TickType)regValH << 32) | (McalLib_TickType)regValL);
    *elapsedTime = (cur_val - *startTime);
    return;
}

FUNC(Std_ReturnType, MCAL_LIB_CODE)
McalLib_GetTimerTickFromUs(McalLib_TickType timeOutInUs, P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) tickCounter)
{
    Std_ReturnType   return_value = E_OK;
    uint32           sysClkHz;
    McalLib_TickType tickCounterValue;
    if (tickCounter == NULL_PTR)
    {
        return_value = E_NOT_OK;
    }
    else
    {
        sysClkHz = Mcu_GetSystemClock();
        if (sysClkHz == 0)
        {
            /* use a higher default sysclk so that the delays computed before Mcu initialization are safe.
             * Mcu_GetSystemClock return 0 if Mcu is not initialized */
            sysClkHz = MCAL_LIB_DEFAULT_SYSCLK_HZ;
        }
        /* Convert time in us to ticks : (tick = timeout in sec * freq in Hz)*/
        tickCounterValue = ((uint64)timeOutInUs * sysClkHz) / 1000000U;
        if (tickCounterValue >= MCAL_LIB_MAX_TICK_VALUE)
        {
            return_value = E_NOT_OK;
        }
        else
        {
            *tickCounter = (uint64)tickCounterValue;
        }
    }
    return return_value;
}

#define MCAL_LIB_STOP_SEC_CODE
#include "Mcal_Lib_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Mcal_Lib.c
 *********************************************************************************************************************/
