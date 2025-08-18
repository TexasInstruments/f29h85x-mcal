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
 *  File:       Can_cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/
#include "Can.h"

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CAN_SW_MAJOR_VERSION != (2U)) || (CAN_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_cfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (2U)) || (CAN_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_cfg.c and Can_Cfg.h are inconsistent!"
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
 * Local Object Definitions
 *********************************************************************************************************************/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* Controller structure defined here for all config sets */

/*
 * Design: MCAL-22759,MCAL-22760,MCAL-22761,MCAL-22762,MCAL-22763,MCAL-22764,MCAL-22765,
 * Design: MCAL-22766,MCAL-22767,MCAL-22768,MCAL-22769,MCAL-22801,MCAL-24210,MCAL-24209,MCAL-24208,
 * Design: MCAL-24207,MCAL-24206
 */
/* Controller structure for CanConfigSet_CanController_0*/
CONST(Can_ControllerType, CAN_CONFIG_DATA) CanConfigSet_CanController_0 =
{
    .CanControllerId = (uint8 )0U,
    .CanControllerActivation = (boolean )TRUE,
    .CanControllerInstance = (Can_ControllerInstance )CAN_CONTROLLER_INSTANCE_MCAN1,
    .CanControllerBaseAddress = (uint32 )0x60020000U,
    .CanBusoffProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanRxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanTxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupFunctionalityAPI = (boolean )FALSE,
    .CanWakeupProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupSupport = (boolean )FALSE,
    .CanWakeupSourceRef = (EcuM_WakeupSourceType )(0U),
    .CanControllerDefaultBaudrate = (const Can_BaudConfigType* )&CanConfigSet_CanController_0_CanControllerBaudrateConfig_0,
    .BaudRateConfigList = (const Can_BaudConfigType** )CanConfigSet_CanController_0_BaudRateConfigList,
    .CanConfigParam = {
        .CanFDMode = (boolean )TRUE,
        .CanLoopbackMode = (boolean )FALSE,
        .CanTransmitPause = (boolean )FALSE,
        .CanDisableAutomaticRetransmission = (boolean )FALSE,
    }
};


/* List of Icom configuration */

/*
 * Design: MCAL-22804,MCAL-22805,MCAL-22806,MCAL-22807,MCAL-22808,MCAL-22811,MCAL-22812,MCAL-22813,MCAL-22814,
 * Design: MCAL-22815,MCAL-22816,MCAL-22817,MCAL-22818,MCAL-22819,MCAL-22820,MCAL-22801,MCAL-22822
 */

/* Overall list of Icom configurations */
CONST(Can_IcomConfigType*, CAN_CONFIG_DATA) Can_IcomConfigurationList[] =
{
};




/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
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
 
/*********************************************************************************************************************
 *  End of File: Can_cfg.c
 *********************************************************************************************************************/
