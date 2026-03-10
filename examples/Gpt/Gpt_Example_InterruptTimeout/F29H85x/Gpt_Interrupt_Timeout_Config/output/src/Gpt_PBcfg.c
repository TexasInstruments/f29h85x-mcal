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
 *  File:         Gpt_PBcfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data for GPT MCAL driver
 *********************************************************************************************************************/
/*
 *Design: MCAL-22043
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-22063
 */
#include "Gpt.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Check module software version information */
#if ((GPT_SW_MAJOR_VERSION != (2U)) ||\
     (GPT_SW_MINOR_VERSION != (0U)))
    #error "Module software version numbers of Gpt_PBcfg.c and Gpt.h are inconsistent!"
#endif

#if ((GPT_CFG_MAJOR_VERSION != (2U)) || \
    (GPT_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Gpt_PBcfg.c and Gpt_Cfg.h are inconsistent!"
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
 * Exported Function Prototypes
 *********************************************************************************************************************/
/*
 *Design: MCAL-22036, MCAL-22037
 */
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
extern void Gpt_Notify_Func_0(void);
extern void Gpt_Notify_Func_1(void);


/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
/*
 *Design: MCAL-22085, MCAL-22086, MCAL-22050, MCAL-22051, MCAL-22052, MCAL-22053, MCAL-22054, 
 * MCAL-22055, MCAL-22056, MCAL-22036, MCAL-22037, MCAL-22041
 */
/** \brief Gpt Channels Configuration parameters. */
static CONST(Gpt_ChannelConfigType, GPT_CONFIG_DATA) Gpt_ChannelConfiguration[2] =
{
    [0] =
    {
        .Gpt_ChannelId         = ((Gpt_ChannelType) 0U),  /* Gpt Channel ID. */
        .Gpt_ChannelMode       = ((Gpt_ChannelModeType) GPT_CH_MODE_ONESHOT),  /* Gpt Channel Mode. */
        .Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER0_BASE),  /* Gpt Channel Base Address. */
        .Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) 0U),  /* Gpt Channel Prescale Value. */
        .Gpt_PtrNotifyFunction = ((Gpt_NotifyType) Gpt_Notify_Func_0),  /* Notification Call Back function. */
        .Gpt_SimStatus         = ((Gpt_SimStatusType) GPT_SIM_DISABLE),  /* Gpt Channel Simulation State */
        .Gpt_SimMode           = ((Gpt_SimModeType) GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC),  /* Gpt Channel Simulation Mode */
    },
    [1] =
    {
        .Gpt_ChannelId         = ((Gpt_ChannelType) 1U),  /* Gpt Channel ID. */
        .Gpt_ChannelMode       = ((Gpt_ChannelModeType) GPT_CH_MODE_CONTINUOUS),  /* Gpt Channel Mode. */
        .Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER1_BASE),  /* Gpt Channel Base Address. */
        .Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) 0U),  /* Gpt Channel Prescale Value. */
        .Gpt_PtrNotifyFunction = ((Gpt_NotifyType) Gpt_Notify_Func_1),  /* Notification Call Back function. */
        .Gpt_SimStatus         = ((Gpt_SimStatusType) GPT_SIM_DISABLE),  /* Gpt Channel Simulation State */
        .Gpt_SimMode           = ((Gpt_SimModeType) GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC),  /* Gpt Channel Simulation Mode */
    }

};

/** \brief Config variable to be passed to Gpt_Init API. */
/*
 *Design: MCAL-22049
 */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_Config =
{
    .ChannelCfgPtr = ((const Gpt_ChannelConfigType *) &Gpt_ChannelConfiguration[0]), /* Pointer to Channel Configuration. */
};

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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Gpt_PBcfg.c
 *********************************************************************************************************************/
