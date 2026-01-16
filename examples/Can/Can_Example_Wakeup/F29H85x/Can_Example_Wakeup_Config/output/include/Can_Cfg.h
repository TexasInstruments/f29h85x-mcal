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
 *  File:       Can_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                          
 *********************************************************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

/**
 * \addtogroup CAN
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 #include "hw_memmap.h"
 
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
#define CAN_CFG_MAJOR_VERSION    (3U) 
/** \brief Can configuration Minor Version. */
#define CAN_CFG_MINOR_VERSION    (1U)
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
#define CAN_CFG_PRE_COMPILE_VARIANT          (STD_OFF)


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
#define CAN_CFG_ICOM_SUPPORT             (STD_OFF)



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
#define CAN_CFG_GET_VERSION_INFO_API         (STD_ON)

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
 * \brief Enable/Disable ECC configuration.
 *
 *****************************************************************************/
#define CAN_CFG_ECC         (STD_OFF)


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
 * \brief CAN timeout - used in CAN Cancel wait and Start/Stop busy wait.
 *  Specifies the maximum time for blocking function until a timeout is detected.
 *  Unit is milli seconds.
 *
 *****************************************************************************/
/*
 *Design: MCAL-22755
 */


#define CAN_CFG_TIMEOUT_DURATION    ((McalLib_TickType)(20000000U))

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
 * \brief Enable/Disable Can Trigger Transmit.
 *
 *****************************************************************************/
#define CAN_TRIGGER_TRANSMIT_ENABLE          (STD_OFF)

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
#define MAX_ICOM_CONFIGURATION               (0U)



/*****************************************************************************
 *
 * \brief Max number of Icom messages defined 
 *
 *****************************************************************************/
#define MAX_ICOM_MESSAGES (0U)
/*****************************************************************************
 *
 * \brief Max number of Icom RX message signals defined 
 *
 *****************************************************************************/
#define MAX_ICOM_RX_SIGNAL_COUNT (0U)




/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM for Hardware failure.
 *********************************************************************************************************************/
#define CAN_CFG_DEM_ENABLE    (STD_OFF)



/*********************************************************************************************************************
 * \brief Enable/Disable DEM for ECC BEU error.
 *********************************************************************************************************************/
#define CAN_CFG_DEM_BEU_ENABLE    (STD_OFF)



/*****************************************************************************
 *
 * \brief Max number of receive dedicated mailboxes per controller 
 *
 *****************************************************************************/
#define KMAX_RX_MB_PER_CONTROLLER               (64U)

/*****************************************************************************
 *
 * \brief Max number of transmit dedicated mailboxes per controller 
 *
 *****************************************************************************/
#define KMAX_TX_MB_PER_CONTROLLER               (32U)

/*****************************************************************************
 *
 * \brief Max number of standard filters per controller 
 *
 *****************************************************************************/
#define KMAX_STD_FILTERS_PER_CONTROLLER         (128U)

/*****************************************************************************
 *
 * \brief Max number of standard filters per controller 
 *
 *****************************************************************************/
#define KMAX_EXTD_FILTERS_PER_CONTROLLER         (64U)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief   Enum for the event pin. */
typedef enum
{
    /** \brief  EVENT PIN0 */
    CAN_EVENT_PIN_0 = 0x0U,
    /** \brief EVENT PIN1 */
    CAN_EVENT_PIN_1 = 0x1U,
    /** \brief EVENT NONE */
    CAN_EVENT_PIN_NONE = 0x2U,
} Can_EventPin;

/** \brief   Enum for the Can standard filter selection. */
typedef enum
{
    /** \brief  Range filter from SFID1 to SFID2 (SFID2 ≥ SFID1) */
    CAN_RANGE_FILTER = 0x0U,
    /** \brief  Dual ID filter for SFID1 or SFID2 */
    CAN_DUAL_ID_FILTER = 0x1U,
    /** \brief  Classic filter: SFID1 = filter; SFID2 = mask */
    CAN_CLASSIC_FILTER = 0x2U,
    /** \brief  Filter element disabled */
    CAN_FILTER_DISABLED = 0x03,
} Can_StandardFilterType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief CAN Configuration struct declaration */
extern const struct Can_ConfigType_s Can_Config;



/* Baud Rate Structure for all configsets */
extern CONST(struct Can_BaudConfigType_s, CAN_CONFIG_DATA) CanConfigSet_CanController_0_CanControllerBaudrateConfig_0;


/*List of the Baudrate structures */

extern CONST(struct Can_BaudConfigType_s*, CAN_CONFIG_DATA) CanConfigSet_CanController_0_BaudRateConfigList[1];

/* Controller structure for CanConfigSet_CanController_0*/
extern CONST(struct Can_ControllerType_s, CAN_CONFIG_DATA) CanConfigSet_CanController_0;



#if (CAN_CFG_ICOM_SUPPORT == STD_ON)

extern CONST(struct Can_IcomConfigType_s*, CAN_CONFIG_DATA) Can_IcomConfigurationList[0];
#endif



/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CAN_CFG_H */
/*********************************************************************************************************************
 *  End of File: Can_Cfg.h
 *********************************************************************************************************************/
