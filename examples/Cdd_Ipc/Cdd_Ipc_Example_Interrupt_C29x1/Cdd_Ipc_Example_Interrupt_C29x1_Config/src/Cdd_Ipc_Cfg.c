/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited. This product is protected under copyright law and
 *                 trade secret law as an unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
#if ((CDD_IPC_SW_MAJOR_VERSION != (1U)) || (CDD_IPC_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Ipc.c and Cdd_Ipc.h are inconsistent!"
#endif

#if ((CDD_IPC_CFG_MAJOR_VERSION != (1U)) || (CDD_IPC_CFG_MINOR_VERSION != (0U)))
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
CONST(struct Cdd_Ipc_ConfigTag, CDD_IPC_CONFIG_DATA) Cdd_Ipc_Configuration =
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
                        .Cdd_Ipc_TxProcessing = CDD_IPC_INTERRUPT,
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
                        .Cdd_Ipc_UserCallbackFunction =(Cdd_Ipc_NotifyType)CddIpcRxChannelConfig_2_Rxindication,
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
