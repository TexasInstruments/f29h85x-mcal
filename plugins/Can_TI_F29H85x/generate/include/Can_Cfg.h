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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Can_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                          
 *********************************************************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

/**
 * \defgroup CAN Can API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*****************************************************************************
 *
 * \brief Can Driver Configuration SW Version Info.
 *
 *****************************************************************************/
 /** \brief Can configuration Major Version. */
#define CAN_CFG_MAJOR_VERSION    ([!"substring-before($moduleSoftwareVer,'.')"!]U) 
/** \brief Can configuration Minor Version. */
#define CAN_CFG_MINOR_VERSION    ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief Can configuration Patch Version. */
#define CAN_CFG_PATCH_VERSION    ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)


/*****************************************************************************
 *
 * \brief Can Build Variant.
 *  Build variants.(i.e Pre-compile,Post-build)
 *
 *****************************************************************************/
/*
 *Design: MCAL-24204
 */
#define CAN_CFG_PRE_COMPILE_VARIANT          [!IF "as:modconf('Can')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/*****************************************************************************
 *
 * \brief Enable/Disable development error detection.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22746,MCAL-22745
 */
#define CAN_CFG_DEV_ERROR_DETECT             [!IF "as:modconf('Can')[1]/CanGeneral/CanDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]



/*****************************************************************************
 *
 * \brief Enable/Disable Public Icom Support.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22753,MCAL-22745
 */
#define CAN_CFG_ICOM_SUPPORT             [!IF "as:modconf('Can')[1]/CanGeneral/CanPublicIcomSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "as:modconf('Can')[1]/CanGeneral/CanPublicIcomSupport = 'true'"!][!//
[!IF "node:exists(as:modconf('Can')[1]/CanGeneral/CanIcomGeneral/*) = 'true'"!][!//
/*****************************************************************************
 *
 * \brief CAN ICOM variant. (i.e SW, HW, HW/SW)
 *
 *****************************************************************************/
/*
 *Design: MCAL-22810,MCAL-22745
 */

[!LOOP "as:modconf('Can')[1]/CanGeneral"!][!//
#define CAN_ICOM_VARIANT	[!"CanIcomGeneral/CanIcomVariant"!]

[!IF "node:exists(as:modconf('Can')[1]/CanGeneral/CanIcomGeneral/CanIcomLevel) = 'true'"!][!//
/*****************************************************************************
 *
 * \brief CAN ICOM level, this value is always one.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22809
 */
#define CAN_ICOM_LEVEL  [!"CanIcomGeneral/CanIcomLevel"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/*****************************************************************************
 *
 * \brief This parameter defines the existence and the name of a callout function that is called 
 *  after a successful reception of a received CAN Rx L-PDU. If this parameter is omitted no callout shall take place.
 *
 *****************************************************************************/

/*
 *Design: MCAL-22748,MCAL-22745
 */
[!IF "node:exists(as:modconf('Can')[1]/CanGeneral/CanLPduReceiveCalloutFunction) = 'true'"!]
[!IF "as:modconf('Can')[1]/CanGeneral/CanLPduReceiveCalloutFunction/* = ''"!]
[!ERROR "CanLPduReceiveCalloutFunction should not be NULL"!][!//
[!ENDIF!]

#define CAN_LPDU_RECEIVE_CALLOUT_FUNCTION            [!"as:modconf('Can')[1]/CanGeneral/CanLPduReceiveCalloutFunction"!]
extern boolean [!"as:modconf('Can')[1]/CanGeneral/CanLPduReceiveCalloutFunction"!](uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth,const uint8* CanSduPtr);
[!ENDIF!]


/*****************************************************************************
 *
 * \brief Enable/Disable CanMultiplexedTransmission.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22752,MCAL-22745
 */
#define CAN_CFG_MULTIPLEXED_TX     [!IF "as:modconf('Can')[1]/CanGeneral/CanMultiplexedTransmission = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/*****************************************************************************
 *
 * \brief Enable/Disable Can_GetVersionInfo().
 *
 *****************************************************************************/
/*
 *Design: MCAL-22756
 */
#define CAN_CFG_GET_VERSION_INFO_API         [!IF "as:modconf('Can')[1]/CanGeneral/CanVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Enable/Disable Can_SetBuadrate().
 *
 *****************************************************************************/
/*
 *Design: MCAL-22754
 */
#define CAN_CFG_SET_BAUDRATE_API         [!IF "as:modconf('Can')[1]/CanGeneral/CanSetBaudrateApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/*****************************************************************************
 *
 * \brief Different periods for the main function read and write.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22802
 */
/*<CAN_CFG_MAINFUNCTIONREADWRITE_LIST>*/
[!LOOP "as:modconf('Can')[1]/CanGeneral"!][!LOOP "CanMainFunctionRWPeriods/*"!][!//
/* Symbolic name of the RW period [!"@index"!]*/
#define [!"@name"!]    [!"@index"!] /*~ASR~*/

/* main function write for the period */
#define Can_MainFunction_Write_[!"@name"!]() Can_MainFunction_Write([!"@name"!])  /*~ASR~*/

/* main function read for the period */
#define Can_MainFunction_Read_[!"@name"!]() Can_MainFunction_Read([!"@name"!])  /*~ASR~*/

[!ENDLOOP!][!ENDLOOP!][!//
/*<CAN_CFG_MAINFUNCTIONREADWRITE_LIST>*/

/*****************************************************************************
 *
 * \brief Counter ID for counter used to count wait ticks
 *
 *****************************************************************************/
/*
 *Design: MCAL-22757
 */
#define CAN_CFG_OS_COUNTER_ID               ((Os_CounterIdType)[!"num:i(node:ref(as:modconf('Can')[1]/CanGeneral/CanOsCounterRef)/OsCounterId)"!]U)


/*****************************************************************************
 *
 * \brief CAN timeout - used in CAN Cancel wait and Start/Stop busy wait.
 *  Specifies the maximum time for blocking function until a timeout is detected.
 *  Unit is milli seconds.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22755
 */
[!VAR "ostickpersec"="node:ref(as:modconf('Can')[1]/CanGeneral/CanOsCounterRef)/OsSecondsPerTick"!]
#define CAN_CFG_TIMEOUT_DURATION            ((uint32)[!"num:i(num:div(as:modconf('Can')[1]/CanGeneral/CanTimeoutDuration,$ostickpersec))"!]U)

/*****************************************************************************
 *
 * \brief CAN timeout in cycles - used in CAN memory initialization wait.
 *  Specifies the maximum time for blocking function until a timeout is detected.
 *  Unit is cycles.
 *
 *****************************************************************************/
#define CAN_CFG_TIMEOUT_DURATION_CYCLES	    ((uint32)[!"num:i(num:mul(as:modconf('Can')[1]/CanGeneral/CanTimeoutDuration,10000000))"!]U)
[!//
[!VAR "wakeupfunc"="0"!][!//
[!VAR "txpoll"="0"!][!//
[!VAR "rxpoll"="0"!][!//
[!VAR "busoffpoll"="0"!][!//
[!VAR "wakeuppoll"="0"!][!//
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanController/*"!][!//
[!IF "CanWakeupFunctionalityAPI = 'true'"!][!//
    [!VAR "wakeupfunc" = "$wakeupfunc + 1"!][!//
[!ENDIF!][!//
[!IF "CanTxProcessing = 'POLLING'"!][!//
    [!VAR "txpoll" = "$txpoll + 1"!][!//
[!ENDIF!][!//
[!IF "CanRxProcessing = 'POLLING'"!][!//
    [!VAR "rxpoll" = "$rxpoll + 1"!][!//
[!ENDIF!][!//
[!IF "CanBusoffProcessing = 'POLLING'"!][!//
    [!VAR "busoffpoll" = "$busoffpoll + 1"!][!//
[!ENDIF!][!//
[!IF "CanWakeupProcessing = 'POLLING'"!][!//
    [!VAR "wakeuppoll" = "$wakeuppoll + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//


/*****************************************************************************
 *
 * \brief Enable/Disable Can_CheckWakeup() 
 *
 *****************************************************************************/
#define CAN_CFG_WAKEUP_FUNCTIONALITY_API     [!IF "$wakeupfunc = 0"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt 
 *   No mixed mode is allowed. Enable/Disable Can_MainFunction_Write. 
 *
 *****************************************************************************/
#define CAN_TX_POLLING                       [!IF "$txpoll = 0"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_Read. 
 *
 *****************************************************************************/
#define CAN_RX_POLLING                       [!IF "$rxpoll = 0"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_BusOff. 
 *
 *****************************************************************************/
#define CAN_BUSOFF_POLLING                   [!IF "$busoffpoll = 0"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_Wakeup.
 *
 *****************************************************************************/
#define CAN_WAKEUP_POLLING                   [!IF "$wakeuppoll = 0"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Defines for symbolic names for the CanHardwareObjectIds 
 *
 *****************************************************************************/
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanHardwareObject/*"!][!//
#define CanConf_CanHardwareObject_[!"@name"!] ([!"CanObjectId"!]U)  /*~ASR~*/
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Defines for symbolic names for the Can controller ID's (CanControllerId) 
 *
 *****************************************************************************/
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanController/*"!][!//
#define CanConf_CanController_[!"@name"!] ([!"CanControllerId"!]U)  /*~ASR~*/
[!ENDLOOP!][!//

/*
 *Design: MCAL-24206
 */
/*****************************************************************************
 *
 * \brief Can Controller Instance interrupt definition 
 *
 *****************************************************************************/
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanController/*"!][!//
[!IF "CanRxProcessing ='INTERRUPT' or CanRxProcessing ='INTERRUPT' or CanBusoffProcessing ='INTERRUPT' or CanWakeupProcessing ='INTERRUPT'"!]
#define CAN_[!"CanControllerInstance"!]_ENABLE
[!IF "CanInteruptType = 'CAN_ISR_CAT1_RTINT'"!][!//
#define CAN_[!"CanControllerInstance"!]_ISR_CAT1_RTINT
[!ELSEIF "CanInteruptType = 'CAN_ISR_CAT1_INT'"!][!//
#define CAN_[!"CanControllerInstance"!]_ISR_CAT1_INT
[!ELSE!][!//
#define CAN_[!"CanControllerInstance"!]_ISR_CAT2
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//


/*****************************************************************************
 *
 * \brief Max number of controllers defined
 *
 *****************************************************************************/
/*
 *Design: MCAL-23019
 */
#define KMAX_CONTROLLER                      ([!"num:i(count(as:modconf('Can')[1]/CanConfigSet/CanController/*))"!]U)

/*****************************************************************************
 *
 * \brief Max number of mailboxes defined 
 *
 *****************************************************************************/
#define KMAX_MAILBOXES                       ([!"num:i(count(as:modconf('Can')[1]/CanConfigSet/CanHardwareObject/*))"!]U)

/*****************************************************************************
 *
 * \brief Max number of Icom configurations defined 
 *
 *****************************************************************************/
#define MAX_ICOM_CONFIGURATION               ([!"num:i(count(as:modconf('Can')[1]/CanConfigSet/CanIcom/CanIcomConfig/*))"!]U)

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CAN_CFG_DEM_ENABLE    [!IF "node:refexists(as:modconf('Can')[1]/CanGeneral/CanDemEventParameterRefs/CAN_E_HARDWARE_ERROR)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:refexists(as:modconf('Can')[1]/CanGeneral/CanDemEventParameterRefs/CAN_E_HARDWARE_ERROR)"!]

#define CAN_E_HARDWARE_ERROR  (DemConf_DemEventParameter_[!"node:name(node:ref(as:modconf('Can')[1]/CanGeneral/CanDemEventParameterRefs/CAN_E_HARDWARE_ERROR))"!])
[!ENDIF!]

/*****************************************************************************
 *
 * \brief Max number of mailboxes per controller 
 *
 *****************************************************************************/
#define KMAX_MB_PER_CONTROLLER               (64U)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!//
/** \brief CAN Configuration struct declaration */
extern const struct Can_ConfigType_s Can_[!"@name"!];
[!ENDLOOP!][!//

[!IF "as:modconf('Can')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!]
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//
[!LOOP "CanControllerBaudrateConfig/*"!][!//

/* Baud Rate Structure for all configsets */
extern CONST(struct Can_BaudConfigType_s, CAN_CONFIG_DATA) [!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!];

[!ENDLOOP!][!ENDLOOP!][!ENDLOOP!][!//

/*List of the Baudrate structures */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//

extern CONST(struct Can_BaudConfigType_s*, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!]_BaudRateConfigList[[!"num:i(count(CanControllerBaudrateConfig/*))"!]];
[!ENDLOOP!][!ENDLOOP!][!//

[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//
/* Controller structure for [!"../../@name"!]_[!"@name"!]*/
extern CONST(struct Can_ControllerType_s, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!];

[!ENDLOOP!][!ENDLOOP!][!//

[!ENDIF!]


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 
#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H */
/*********************************************************************************************************************
 *  End of File: Can_Cfg.h
 *********************************************************************************************************************/
