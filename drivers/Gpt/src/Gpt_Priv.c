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
 *  File:         Gpt_Priv.c
 *  Generator:    None
 *
 *  Description:  This file contains the GPT MCAL driver private API's definitions specific to
 *device
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Gpt_Priv.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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
 * Local Object Definitions
 *********************************************************************************************************************/
/** \brief GPT Driver gloabal pointer to save address of Gpt_DrvObj defined in Gpt.c */
/*
 *Design: MCAL-23358
 */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
P2VAR(Gpt_DriverObjType, AUTOMATIC, VAR_NO_INIT_UNSPECIFIED) Gpt_DrvObjPtr;
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/*
 *Design: MCAL-28449
 */
FUNC(void, GPT_CODE) Gpt_SetDriverObjPtr(Gpt_DriverObjType *Set_DrvObj)
{
    Gpt_DrvObjPtr = Set_DrvObj;
}

/*
 *Design: MCAL-22077
 */
FUNC(void, GPT_CODE)
Gpt_GetChIdxPriv(const Gpt_DriverObjType *GptDrvObj, Gpt_ChannelType Channel, uint32 *ChannelIndex)
{
    if (Channel < GPT_CFG_MAX_CHANNELS)
    {
        *ChannelIndex = GptDrvObj->Gpt_Lut_Channel_Index[Channel];
    }

    return;
}

/*
 *Design: MCAL-22076
 */
FUNC(void, GPT_CODE) Gpt_DeInitPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Set TSS bit of TCR register to stop the timer. */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TSS);

    /* Set the period register to reset values. */
    HWREG(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_PRD)) = ((uint32)GPT_CFG_PERIOD_RESET_VAL);

    /* Set TRB bit of TCR register to reload the timer count. */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TRB);

    /* Set TPR.TDDR and TPRH.TDDRH registers to reset values */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TPRH)) =
        ((GPT_CFG_PRESCALE_RESET_VAL >> ((uint16)8U)) << CPUTIMER_TPRH_TDDRH_S) & CPUTIMER_TPRH_TDDRH_M;
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TPR)) =
        (GPT_CFG_PRESCALE_RESET_VAL << ((uint16)CPUTIMER_TPR_TDDR_S)) & CPUTIMER_TPR_TDDR_M;

    /* Set TIF bit of TCR register  */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TIF);

    /* Set Timer SW Emulation Behaviour to reset states */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_FREE);
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_SOFT);

    return;
}

/*
 *Design: MCAL-22075
 */
FUNC(void, GPT_CODE) Gpt_InitPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Load the MSB period Count */
    HWREG(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_PRD)) = GPT_CFG_MAX_TICK_VALUE;

    /* Writes to TPR.TDDR and TPRH.TDDRH bits */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TPRH)) =
        ((ChannelObj->Gpt_PrescaleValue >> (uint16)8U) << CPUTIMER_TPRH_TDDRH_S) & CPUTIMER_TPRH_TDDRH_M;

    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TPR)) =
        (ChannelObj->Gpt_PrescaleValue << ((uint16)CPUTIMER_TPR_TDDR_S)) & CPUTIMER_TPR_TDDR_M;

    /* Set TIF bit of TCR register */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TIF);

    /* Set TSS bit of register TCR to stop the timer */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TSS);

    /* Set TRB bit of register TCR to reload the tick value programmed into PRD register */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TRB);

    /* Setting SW Breakpoint Emulation Behaviour */
    if (GPT_SIM_ENABLE == ChannelObj->Gpt_SimStatus)
    {
        switch (ChannelObj->Gpt_SimMode)
        {
            case (GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC):
                HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_FREE);
                HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_SOFT);
                break;
            case (GPT_SIM_STOP_TIMER_AT_NEXT_TIMER_ELAPSE):
                HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_FREE);
                HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_SOFT);
                break;
            default:
                break;
        }
    }
    else
    {
        /* Set the FREE bit of TCR register to run the timer freely even in simulation mode */
        HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_FREE);
    }

    return;
}

/*
 *Design: MCAL-22078
 */
FUNC(uint32, GPT_CODE) Gpt_GetCurCountPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Read & return the counter register */
    return (HWREG(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TIM)));
}

/*
 *Design: MCAL-22079
 */
FUNC(uint32, GPT_CODE) Gpt_GetPrdCountPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Read & return the period register */
    return (HWREG(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_PRD)));
}

/*
 *Design: MCAL-22080
 */
FUNC(void, GPT_CODE) Gpt_StartTimerPriv(const Gpt_ChannelConfigType *ChannelObj, uint32 count)
{
    /* Set the counter value in period register */
    HWREG(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_PRD)) = count;

    /* Set TRB bit of TCR register to reload the TIM register from PRD register */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TRB);

    /* Clear the TSS bit of TCR register to restart/start the timer */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= ((uint16)~CPUTIMER_TCR_TSS);

    return;
}

/*
 *Design: MCAL-22081
 */
FUNC(void, GPT_CODE) Gpt_StopTimerPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Set the TSS bit of TCR register to stop the timer */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TSS);

    return;
}

/*
 *Design: MCAL-22084
 */
FUNC(void, GPT_CODE) Gpt_ClrOvfFlagPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Set the TIF bit of TCR register to clear the overflow flag */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TIF);

    return;
}

/*
 *Design: MCAL-22082
 */
FUNC(void, GPT_CODE) Gpt_EnableIntPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Set the TIE bit of TCR register to enable the interrupt */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) |= ((uint16)CPUTIMER_TCR_TIE);

    return;
}

/*
 *Design: MCAL-22083
 */
FUNC(void, GPT_CODE) Gpt_DisableIntPriv(const Gpt_ChannelConfigType *ChannelObj)
{
    /* Clear the TIE bit of TCR register to diable the interrupt */
    HWREGH(ChannelObj->Gpt_ChannelBaseAddr + ((uint32)CPUTIMER_O_TCR)) &= (uint16) ~(CPUTIMER_TCR_TIE);

    return;
}

/*
 *Design: MCAL-28452, 22040, MCAL-21957, MCAL-21958, MCAL-21960, MCAL-22038, MCAL-22039
 */
FUNC(void, GPT_CODE) Gpt_IsrNotifyFunction(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void)Gpt_GetChIdxPriv(Gpt_DrvObjPtr, Channel, &ch_index);
    if (GPT_MAX_32BIT_VAL != ch_index)
    {
        /* Mark the channel as inactive/expired. */
        if (GPT_CH_MODE_ONESHOT == Gpt_DrvObjPtr->Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_ChannelMode)
        {
            Gpt_StopTimerPriv(&(Gpt_DrvObjPtr->Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            Gpt_DrvObjPtr->Gpt_ChannelState[ch_index] = GPT_CH_EXPIRED;
        }

        /* Overflow flag is set on timer expiry, clear it here */
        Gpt_ClrOvfFlagPriv(&(Gpt_DrvObjPtr->Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

        /* Call notification callback. */
        if (NULL_PTR != Gpt_DrvObjPtr->Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction)
        {
            Gpt_DrvObjPtr->Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction();
        }
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Gpt_Priv.c
 *********************************************************************************************************************/
