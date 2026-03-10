/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
