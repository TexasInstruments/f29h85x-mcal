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
 *  File:       Cdd_Ipc_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_Ipc.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_IPC_SW_MAJOR_VERSION != (2U)) || (CDD_IPC_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Cdd_Ipc.c and Cdd_Ipc.h are inconsistent!"
#endif

#if ((CDD_IPC_CFG_MAJOR_VERSION != (2U)) || (CDD_IPC_CFG_MINOR_VERSION != (1U)))
    #error "Version numbers of Cdd_Ipc_Cfg.c and Cdd_Ipc_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
#define CDD_IPC_START_SEC_CONST_32
#include "Cdd_Ipc_MemMap.h"
/* Design: MCAL-30535 */
/** \brief Cdd Ipc sync instance lookup table. */
CONST(Cdd_Ipc_InstanceType, CDD_IPC__CONST) Cdd_Ipc_Sync_Instances[CDD_IPC_CORE_COUNT][CDD_IPC_CORE_COUNT] = {
                                                     {0, CDD_IPC_CPU1_L_CPU2_R_INST0, CDD_IPC_CPU1_L_CPU3_R_INST0},
                                                     {CDD_IPC_CPU2_L_CPU1_R_INST0, 0, CDD_IPC_CPU2_L_CPU3_R_INST0},
                                                     {CDD_IPC_CPU3_L_CPU1_R_INST0, CDD_IPC_CP3_L_CPU2_R_INST0, 0}};
#define CDD_IPC_STOP_SEC_CONST_32
#include "Cdd_Ipc_MemMap.h"
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/


#define CDD_IPC_START_SEC_CONFIG_DATA
#include "Cdd_Ipc_MemMap.h"

/** \brief CDD Ipc Configuration */
CONST(struct Cdd_Ipc_ConfigTag, CDD_IPC_CONFIG_DATA) Cdd_Ipc_Config =
{
    .Cdd_Ipc_LocalCore = CDD_IPC_CPU1,

    .Cdd_Ipc_TxInstanceConfig = 
     {
        {
            .Cdd_Ipc_TxInstance = CDD_IPC_CPU1_L_CPU3_R_INST0,
            .Cdd_Ipc_TxChannelCount = 1U,
            .Cdd_Ipc_TxChannelConfig = 
                {
                    {
                        .Cdd_Ipc_ChannelID = 1U,
                        .Cdd_Ipc_TxProcessing = CDD_IPC_POLLING,
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddIpcTxChannelConfig_CddIpcTxChannelConfig_0,
                    },
                }
        },
     },

    .Cdd_Ipc_RxInstanceConfig = 
    {
        {
            .Cdd_Ipc_RxInstance = CDD_IPC_CPU1_L_CPU3_R_INST0,
            .Cdd_Ipc_RxChannelCount = 1U,
            .Cdd_Ipc_RxChannelConfig = 
                 {
                    {
                        .Cdd_Ipc_ChannelID = 1U,
                        .Cdd_Ipc_UserCallbackFunction =(Cdd_Ipc_NotifyType)CddIpcRxChannelConfig_1_Rxindication,
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddIpcRxChannelConfig_CddIpcRxChannelConfig_0,
                    },
                }
        },
    },
};

#define CDD_IPC_STOP_SEC_CONFIG_DATA
#include "Cdd_Ipc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Cfg.c
 *********************************************************************************************************************/
