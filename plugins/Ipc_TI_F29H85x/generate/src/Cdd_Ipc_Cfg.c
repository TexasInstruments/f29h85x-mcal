[!SKIPFILE "as:modconf('Cdd_Ipc/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ipc/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
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
#if ((CDD_IPC_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_IPC_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Ipc.c and Cdd_Ipc.h are inconsistent!"
#endif

#if ((CDD_IPC_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_IPC_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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

[!AUTOSPACING!][!//

#define CDD_IPC_START_SEC_CONFIG_DATA
#include "Cdd_Ipc_MemMap.h"

[!SELECT "as:modconf('Cdd_Ipc/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ipc/Cdd']"!]
/** \brief CDD Ipc Configuration */
CONST(struct Cdd_Ipc_ConfigTag, CDD_IPC_CONFIG_DATA) Cdd_Ipc_Config =
{
    .Cdd_Ipc_LocalCore = [!"node:value(CddIpcGeneral/CddIpcLocalCore)"!],

[!IF "num:i(count(CddIpcConfig/CddIpcRemoteCoreConfig/*/CddIpcTxInstanceConfig/*))>0"!]
    .Cdd_Ipc_TxInstanceConfig = 
     {
[!LOOP "CddIpcConfig/CddIpcRemoteCoreConfig/*/CddIpcTxInstanceConfig/*"!]
        {
            .Cdd_Ipc_TxInstance = [!"node:value(CddIpcTxInstance)"!],
            .Cdd_Ipc_TxChannelCount = [!"num:i(count(CddIpcTxChannelConfig/*))"!]U,
            .Cdd_Ipc_TxChannelConfig = 
                {
[!LOOP "CddIpcTxChannelConfig/*"!]
                    {
                        .Cdd_Ipc_ChannelID = [!"node:value(CddIpcTxChannelId)"!]U,
                        .Cdd_Ipc_TxProcessing = [!"node:value(CddIpcTxProcessing)"!],
[!IF "as:modconf('Cdd_Ipc/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ipc/Cdd']/CddIpcGeneral/CddIpcIntegrationWithAsrComStackEnable  = 'true'"!]
[!VAR "PduID"="substring-after(node:value(CddIpcTxPduID), '/CddPduRLowerLayerContribution/')"!]
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddPduRLowerLayerTxPdu_[!"$PduID"!],
[!ELSE!][!//
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddIpcTxChannelConfig_[!"@name"!],
[!ENDIF!]
                    },
[!ENDLOOP!]
                }
        },
[!ENDLOOP!]
     },
[!ENDIF!]

[!IF "num:i(count(CddIpcConfig/CddIpcRemoteCoreConfig/*/CddIpcRxInstanceConfig/*))>0"!]
    .Cdd_Ipc_RxInstanceConfig = 
    {
[!LOOP "CddIpcConfig/CddIpcRemoteCoreConfig/*/CddIpcRxInstanceConfig/*"!]
        {
            .Cdd_Ipc_RxInstance = [!"node:value(CddIpcRxInstance)"!],
            .Cdd_Ipc_RxChannelCount = [!"num:i(count(CddIpcRxChannelConfig/*))"!]U,
            .Cdd_Ipc_RxChannelConfig = 
                 {
[!LOOP "CddIpcRxChannelConfig/*"!]
                    {
                        .Cdd_Ipc_ChannelID = [!"node:value(CddIpcRxChannelId)"!]U,
                        .Cdd_Ipc_UserCallbackFunction = [!IF "(node:exists(CddIpcUserCallbackFunction))"!][!IF "node:value(CddIpcUserCallbackFunction) = 'NULL_PTR'"!] NULL_PTR[!ELSE!](Cdd_Ipc_NotifyType)[!"(node:value(CddIpcUserCallbackFunction))"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
[!IF "as:modconf('Cdd_Ipc/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ipc/Cdd']/CddIpcGeneral/CddIpcIntegrationWithAsrComStackEnable  = 'true'"!]
[!VAR "PduID"="substring-after(node:value(CddIpcRxPduID), '/CddPduRLowerLayerContribution/')"!]
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddPduRLowerLayerRxPdu_[!"$PduID"!],
[!VAR "PduID"="node:value(node:ref(CddIpcRxPduID)/CddIpcPduRHandle)"!]
                        .Cdd_Ipc_PduID = [!"$PduID"!],
[!ELSE!][!//
                        .Cdd_Ipc_HandleID = Cdd_IpcConf_CddIpcRxChannelConfig_[!"@name"!],
[!ENDIF!]
                    },
[!ENDLOOP!]
                }
        },
[!ENDLOOP!]
    },
[!ENDIF!]
};
[!ENDSELECT!]

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
