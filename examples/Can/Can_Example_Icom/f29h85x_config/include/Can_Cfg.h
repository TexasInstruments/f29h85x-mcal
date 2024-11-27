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
#define CAN_CFG_MAJOR_VERSION    (1U) 
/** \brief Can configuration Minor Version. */
#define CAN_CFG_MINOR_VERSION    (0U)
/** \brief Can configuration Patch Version. */
#define CAN_CFG_PATCH_VERSION    (0U)


/*****************************************************************************
 *
 * \brief Can Build Variant.
 *  Build variants.(i.e Pre-compile,Post-build)
 *
 *****************************************************************************/
/*
 *Design: MCAL-24204
 */
#define CAN_CFG_PRE_COMPILE_VARIANT          (STD_ON)


/*****************************************************************************
 *
 * \brief Enable/Disable development error detection.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22746,MCAL-22745
 */
#define CAN_CFG_DEV_ERROR_DETECT             (STD_ON)



/*****************************************************************************
 *
 * \brief Enable/Disable Public Icom Support.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22753,MCAL-22745
 */
#define CAN_CFG_ICOM_SUPPORT             (STD_ON)

/*****************************************************************************
 *
 * \brief CAN ICOM variant. (i.e SW, HW, HW/SW)
 *
 *****************************************************************************/
/*
 *Design: MCAL-22810,MCAL-22745
 */

#define CAN_ICOM_VARIANT	CAN_ICOM_VARIANT_SW

/*****************************************************************************
 *
 * \brief CAN ICOM level, this value is always one.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22809
 */
#define CAN_ICOM_LEVEL  CAN_ICOM_LEVEL_ONE

/*****************************************************************************
 *
 * \brief This parameter defines the existence and the name of a callout function that is called 
 *  after a successful reception of a received CAN Rx L-PDU. If this parameter is omitted no callout shall take place.
 *
 *****************************************************************************/

/*
 *Design: MCAL-22748,MCAL-22745
 */



/*****************************************************************************
 *
 * \brief Enable/Disable CanMultiplexedTransmission.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22752,MCAL-22745
 */
#define CAN_CFG_MULTIPLEXED_TX     (STD_OFF)


/*****************************************************************************
 *
 * \brief Enable/Disable Can_GetVersionInfo().
 *
 *****************************************************************************/
/*
 *Design: MCAL-22756
 */
#define CAN_CFG_GET_VERSION_INFO_API         (STD_OFF)

/*****************************************************************************
 *
 * \brief Enable/Disable Can_SetBuadrate().
 *
 *****************************************************************************/
/*
 *Design: MCAL-22754
 */
#define CAN_CFG_SET_BAUDRATE_API         (STD_OFF)


/*****************************************************************************
 *
 * \brief Different periods for the main function read and write.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22802
 */
/*<CAN_CFG_MAINFUNCTIONREADWRITE_LIST>*/
/* Symbolic name of the RW period 0*/
#define CanMainFunctionRWPeriods_0    0 /*~ASR~*/

/* main function write for the period */
#define Can_MainFunction_Write_CanMainFunctionRWPeriods_0() Can_MainFunction_Write(CanMainFunctionRWPeriods_0)  /*~ASR~*/

/* main function read for the period */
#define Can_MainFunction_Read_CanMainFunctionRWPeriods_0() Can_MainFunction_Read(CanMainFunctionRWPeriods_0)  /*~ASR~*/

/* Symbolic name of the RW period 1*/
#define CanMainFunctionRWPeriods_1    1 /*~ASR~*/

/* main function write for the period */
#define Can_MainFunction_Write_CanMainFunctionRWPeriods_1() Can_MainFunction_Write(CanMainFunctionRWPeriods_1)  /*~ASR~*/

/* main function read for the period */
#define Can_MainFunction_Read_CanMainFunctionRWPeriods_1() Can_MainFunction_Read(CanMainFunctionRWPeriods_1)  /*~ASR~*/

/* Symbolic name of the RW period 2*/
#define CanMainFunctionRWPeriods_2    2 /*~ASR~*/

/* main function write for the period */
#define Can_MainFunction_Write_CanMainFunctionRWPeriods_2() Can_MainFunction_Write(CanMainFunctionRWPeriods_2)  /*~ASR~*/

/* main function read for the period */
#define Can_MainFunction_Read_CanMainFunctionRWPeriods_2() Can_MainFunction_Read(CanMainFunctionRWPeriods_2)  /*~ASR~*/

/*<CAN_CFG_MAINFUNCTIONREADWRITE_LIST>*/

/*****************************************************************************
 *
 * \brief Counter ID for counter used to count wait ticks
 *
 *****************************************************************************/
/*
 *Design: MCAL-22757
 */
#define CAN_CFG_OS_COUNTER_ID               ((Os_CounterIdType)0U)


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

#define CAN_CFG_TIMEOUT_DURATION            ((uint32)100000U)

/*****************************************************************************
 *
 * \brief CAN timeout in cycles - used in CAN memory initialization wait.
 *  Specifies the maximum time for blocking function until a timeout is detected.
 *  Unit is cycles.
 *
 *****************************************************************************/
#define CAN_CFG_TIMEOUT_DURATION_CYCLES	    ((uint32)1000000U)
                

/*****************************************************************************
 *
 * \brief Enable/Disable Can_CheckWakeup() 
 *
 *****************************************************************************/
#define CAN_CFG_WAKEUP_FUNCTIONALITY_API     (STD_OFF)

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt 
 *   No mixed mode is allowed. Enable/Disable Can_MainFunction_Write. 
 *
 *****************************************************************************/
#define CAN_TX_POLLING                       (STD_ON)

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_Read. 
 *
 *****************************************************************************/
#define CAN_RX_POLLING                       (STD_ON)

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_BusOff. 
 *
 *****************************************************************************/
#define CAN_BUSOFF_POLLING                   (STD_ON)

/*****************************************************************************
 *
 * \brief For all controllers setting needs to be same either polling or interrupt
 *  No mixed mode is allowed. Enable/Disable Can_MainFunction_Wakeup.
 *
 *****************************************************************************/
#define CAN_WAKEUP_POLLING                   (STD_ON)

/*****************************************************************************
 *
 * \brief Defines for symbolic names for the CanHardwareObjectIds 
 *
 *****************************************************************************/
#define CanConf_CanHardwareObject_CanHardwareObject_0 (0U)  /*~ASR~*/
#define CanConf_CanHardwareObject_CanHardwareObject_1 (1U)  /*~ASR~*/

/*****************************************************************************
 *
 * \brief Defines for symbolic names for the Can controller ID's (CanControllerId) 
 *
 *****************************************************************************/
#define CanConf_CanController_CanController_0 (0U)  /*~ASR~*/

/*
 *Design: MCAL-24206
 */
/*****************************************************************************
 *
 * \brief Can Controller Instance interrupt definition 
 *
 *****************************************************************************/


/*****************************************************************************
 *
 * \brief Max number of controllers defined
 *
 *****************************************************************************/
/*
 *Design: MCAL-23019
 */
#define KMAX_CONTROLLER                      (1U)

/*****************************************************************************
 *
 * \brief Max number of mailboxes defined 
 *
 *****************************************************************************/
#define KMAX_MAILBOXES                       (2U)

/*****************************************************************************
 *
 * \brief Max number of Icom configurations defined 
 *
 *****************************************************************************/
#define MAX_ICOM_CONFIGURATION               (1U)

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CAN_CFG_DEM_ENABLE    (STD_OFF)



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
/** \brief CAN Configuration struct declaration */
extern const struct Can_ConfigType_s Can_CanConfigSet;




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
