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
 *  File:         Cdd_Ipc_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data        
 *********************************************************************************************************************/
#ifndef CDD_IPC_CFG_H
#define CDD_IPC_CFG_H

/** \addtogroup CDD_IPC
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "hw_memmap.h"
#include "hw_ipc.h"
#include "Cdd_Ipc_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS 
/** \brief CDD Ipc configuration Major Version */
#define CDD_IPC_CFG_MAJOR_VERSION                (2U)

/** \brief CDD Ipc configuration Minor Version */
#define CDD_IPC_CFG_MINOR_VERSION                (1U)

/** \brief CDD Ipc configuration Patch Version */
#define CDD_IPC_CFG_PATCH_VERSION                (0U)

/** \brief Switches the pre compile variant ON or OFF */
#define CDD_IPC_PRE_COMPILE_VARIANT              STD_ON

/** \brief Pre compile variant configuration */
#define CDD_IPC_PRE_COMPILE_VARIANT_CONFIG       Cdd_Ipc_Config

/** \brief CDD Ipc developement error detection */
#define CDD_IPC_DEV_ERROR_DETECT                 STD_ON

/** \brief Switches the Cdd_Ipc_GetVersionInfo function ON or OFF */
#define CDD_IPC_GET_VERSION_INFO_API             STD_ON

/** \brief Enables or disables the integration of Cdd_Ipc with AUTOSAR communication stack */
#define CDD_IPC_INTEGRATION_WITH_ASR_COM_STACK_ENABLE    (STD_OFF)

/** \brief Macro to define the number of core */
#define CDD_IPC_CORE_COUNT                        3U

/** \brief Macro to define the number of remote cores configured */
#define CDD_IPC_REMOTE_CORE_COUNT                 1U

/** \brief Macro to define the max no of bytes that can be transmitted or received */
#define CDD_IPC_MAX_SIZE                          12U

/** \brief Macro to define the number of Tx instances configured */
#define CDD_IPC_TX_INSTANCE_COUNT                   (1U)

/** \brief Macro to define the number of Rx instances configured */
#define CDD_IPC_RX_INSTANCE_COUNT                   (1U)

 /** \brief Macro to define the maximum number of Tx channels configured per instance */
#define CDD_IPC_TX_CHANNEL_COUNT         1U

 /** \brief Macro to define the maximum number of Rx channels configured per instance */
#define CDD_IPC_RX_CHANNEL_COUNT         1U

/** \brief Cdd Ipc Sync timeout, units is clock cycles. */
#define CDD_IPC_CFG_TIMEOUT_CLOCK_CYCLES    ((uint64)(2000000000U))

/* Design: MCAL-30536 */
/*****************************************************************************
 * \brief Symbolic names for the remote cores
 *****************************************************************************/ 
/** \brief Remore core CDD_IPC_CPU3 symbolic name */
#define CddIpcConf_CddIpcRemoteCoreConfig_CddIpcRemoteCoreConfig_0    CDD_IPC_CPU3  /*~ASR~*/


/* Design: MCAL-30603 */
/*****************************************************************************
 * \brief Symbolic names for the Tx channels
 ***************************************************************************/
#define Cdd_IpcConf_CddIpcTxChannelConfig_CddIpcTxChannelConfig_0 1U	         /*~ASR~*/

/* Design: MCAL-30602 */
/*****************************************************************************
 * \brief Symbolic names for the Rx channels
 ***************************************************************************/
#define Cdd_IpcConf_CddIpcRxChannelConfig_CddIpcRxChannelConfig_0 1U	         /*~ASR~*/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief Cdd Ipc Instance interrupt definition */
#define CDD_IPC_CPU1_L_CPU3_R_INST0_ENABLE
#define CDD_IPC_CPU1_L_CPU3_R_INST0_ISR_CAT2_INT

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* Design: MCAL-30527 */
/** \brief CPU cores type */
typedef enum
{
    CDD_IPC_CPU1 = 0U,              /*!< \brief  CPU1 */
    CDD_IPC_CPU2 = 1U,              /*!< \brief  CPU2 */
    CDD_IPC_CPU3 = 2U,              /*!< \brief  CPU3*/
}Cdd_Ipc_CoreType;

/* Design: MCAL-30526 */
/** \brief IPC Tx processing */
typedef enum
{
    CDD_IPC_POLLING = 1U,              /*!< \brief  Polling mode*/
    CDD_IPC_INTERRUPT  = 2U            /*!< \brief  Interrupt mode*/
}Cdd_Ipc_TxProcessingType;

/* Design: MCAL-30525 */
/** \brief IPC Instance type */
typedef enum
{
    /** \brief CPU1 - Local core, CPU2 - Remote core, Instance 1 */
    CDD_IPC_CPU1_L_CPU2_R_INST0 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU2INTIPCSET(0U),
    /** \brief CPU1 - Local core, CPU2 - Remote core, Instance 2 */
    CDD_IPC_CPU1_L_CPU2_R_INST1 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU2INTIPCSET(1U),
    /** \brief CPU1 - Local core, CPU2 - Remote core, Instance 3 */
    CDD_IPC_CPU1_L_CPU2_R_INST2 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU2INTIPCSET(2U),
    /** \brief CPU1 - Local core, CPU2 - Remote core, Instance 4 */
    CDD_IPC_CPU1_L_CPU2_R_INST3 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU2INTIPCSET(3U),

    /** \brief CPU1 - Local core, CPU3 - Remote core, Instance 1 */
    CDD_IPC_CPU1_L_CPU3_R_INST0 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU3INTIPCSET(0U),
    /** \brief CPU1 - Local core, CPU3 - Remote core, Instance 2 */
    CDD_IPC_CPU1_L_CPU3_R_INST1 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU3INTIPCSET(1U),
    /** \brief CPU1 - Local core, CPU3 - Remote core, Instance 3 */
    CDD_IPC_CPU1_L_CPU3_R_INST2 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU3INTIPCSET(2U),
    /** \brief CPU1 - Local core, CPU3 - Remote core, Instance 4 */
    CDD_IPC_CPU1_L_CPU3_R_INST3 = CPU1IPCSEND_BASE + IPC_O_CPU1TOCPU3INTIPCSET(3U),

    /** \brief CPU2 - Local core, CPU1 - Remote core, Instance 1 */
    CDD_IPC_CPU2_L_CPU1_R_INST0 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU1INTIPCSET(0U),
    /** \brief CPU2 - Local core, CPU1 - Remote core, Instance 2 */
    CDD_IPC_CPU2_L_CPU1_R_INST1 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU1INTIPCSET(1U),
    /** \brief CPU2 - Local core, CPU1 - Remote core, Instance 3 */
    CDD_IPC_CPU2_L_CPU1_R_INST2 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU1INTIPCSET(2U),
    /** \brief CPU2 - Local core, CPU1 - Remote core, Instance 4 */
    CDD_IPC_CPU2_L_CPU1_R_INST3 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU1INTIPCSET(3U),

    /** \brief CPU2 - Local core, CPU3 - Remote core, Instance 1 */
    CDD_IPC_CPU2_L_CPU3_R_INST0 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU3INTIPCSET(0U),
    /** \brief CPU2 - Local core, CPU3 - Remote core, Instance 2 */
    CDD_IPC_CPU2_L_CPU3_R_INST1 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU3INTIPCSET(1U),
    /** \brief CPU2 - Local core, CPU3 - Remote core, Instance 3 */
    CDD_IPC_CPU2_L_CPU3_R_INST2 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU3INTIPCSET(2U),
    /** \brief CPU2 - Local core, CPU3 - Remote core, Instance 4 */
    CDD_IPC_CPU2_L_CPU3_R_INST3 = CPU2IPCSEND_BASE + IPC_O_CPU2TOCPU3INTIPCSET(3U),

    /** \brief CPU3 - Local core, CPU1 - Remote core, Instance 1 */
    CDD_IPC_CPU3_L_CPU1_R_INST0 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU1INTIPCSET(0U),
    /** \brief CPU3 - Local core, CPU1 - Remote core, Instance 2 */
    CDD_IPC_CPU3_L_CPU1_R_INST1 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU1INTIPCSET(1U),
    /** \brief CPU3 - Local core, CPU1 - Remote core, Instance 3 */
    CDD_IPC_CPU3_L_CPU1_R_INST2 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU1INTIPCSET(2U),
    /** \brief CPU3 - Local core, CPU1 - Remote core, Instance 4 */
    CDD_IPC_CPU3_L_CPU1_R_INST3 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU1INTIPCSET(3U),

    /** \brief CPU3 - Local core, CPU2 - Remote core, Instance 1 */
    CDD_IPC_CP3_L_CPU2_R_INST0 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU2INTIPCSET(0U),
    /** \brief CPU3 - Local core, CPU2 - Remote core, Instance 2 */
    CDD_IPC_CP3_L_CPU2_R_INST1 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU2INTIPCSET(1U),
    /** \brief CPU3 - Local core, CPU2 - Remote core, Instance 3 */
    CDD_IPC_CP3_L_CPU2_R_INST2 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU2INTIPCSET(2U),
    /** \brief CPU3 - Local core, CPU2 - Remote core, Instance 4 */
    CDD_IPC_CP3_L_CPU2_R_INST3 = CPU3IPCSEND_BASE + IPC_O_CPU3TOCPU2INTIPCSET(3U),
}Cdd_Ipc_InstanceType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/* Cdd Ipc Configuration struct extern declaration */
extern const struct Cdd_Ipc_ConfigTag Cdd_Ipc_Config;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_IPC_CFG_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Cfg.h
 *********************************************************************************************************************/
