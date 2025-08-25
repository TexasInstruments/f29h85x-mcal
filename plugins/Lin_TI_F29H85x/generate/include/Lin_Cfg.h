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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Lin_Cfg.h
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-25544,MCAL-25545,MCAL-25546
 */
#ifndef LIN_CFG_H
#define LIN_CFG_H
/**
 * \addtogroup LIN
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif
 
 #ifndef DOXYGEN_SHOULD_SKIP_THIS 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "EcuM_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * \brief Lin Driver Configuration SW Version Info.
 *
 *****************************************************************************/
/** \brief Lin configuration Major Version. */
#define LIN_CFG_MAJOR_VERSION    ([!"substring-before($moduleSoftwareVer,'.')"!]U)
/** \brief Lin configuration Minor Version. */
#define LIN_CFG_MINOR_VERSION    ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief Lin configuration Patch Version. */
#define LIN_CFG_PATCH_VERSION    ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)

[!SELECT "as:modconf('Lin')[as:path(node:dtos(.))='/TI_F29H85x/Lin']"!]
/*****************************************************************************
 *
 * \brief LIN Build Variant. 
 *  Build variants.(i.e Pre-compile,Post-build or Link time)
 * 
 *****************************************************************************/
#define LIN_PRE_COMPILE_VARIANT          [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*****************************************************************************
 *
 * \brief Pointer to Lin Config Set to be used during Pre-Compile
 *
 *****************************************************************************/
#define LIN_INIT_CONFIG_PC                   Lin_Config
[!ENDIF!]

/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
/*
 * Design: MCAL-25661, MCAL-25662
 */
#define LIN_DEM_ENABLE    [!IF "node:refexists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "node:refexists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!]
/*
 * Design: MCAL-25586, MCAL-25588, MCAL-25589
 */
/** \brief LIN DEM Event Configuration: LIN Timeout */
#define LIN_E_TIMEOUT  					(DemConf_DemEventParameter_[!"node:name(node:ref(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!])

[!ENDIF!]

/** \brief LIN DEM Event Configuration: LIN Timeout Duration*/
#define LIN_TIMEOUT_DURATION            [!"LinGeneral/LinTimeoutDuration"!]U

[!VAR "SysClock"="num:i(node:ref(LinGeneral/SysClockRef)/McuClockReferencePointFrequency)"!][!//
[!VAR "SysClock"="num:i(num:div((num:div(1,65535)), num:div(15,$SysClock)))"!][!//
/** \brief LIN Delay to Mcal Lib */
#define LIN_MCAL_LIB_DELAY              [!"num:i($SysClock)"!]U

/*****************************************************************************
 *
 * \brief Enable/Disable development error detection.
 *
 *****************************************************************************/
#define LIN_DEV_ERROR_DETECT             [!IF "LinGeneral/LinDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Enable/Disable Lin_GetVersionInfo().
 *
 *****************************************************************************/
#define LIN_GET_VERSION_INFO_API         [!IF "LinGeneral/LinVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Lin Instance to Channel ID mapping.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25663
 */
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define [!"LinInstance"!]                    [!"LinChannelId"!]
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel Symbolic Names.
 *
 *****************************************************************************/
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define LinConf_LinChannel_[!"@name"!]       [!"LinChannelId"!]      /*~ASR~*/
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel Interrupt Line Selection.
 *
 *****************************************************************************/
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define [!"LinInstance"!]_[!"substring-after(LinInterruptLineSelect, 'LIN_INTERRUPT_')"!]                  
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel ISR Type Selection.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25665
 */
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define [!"LinInstance"!]_ISR_TYPE           [!"LinISRType"!]
[!ENDLOOP!][!//


/*****************************************************************************
 *
 * \brief Max number of channels defined
 *
 *****************************************************************************/
#define LIN_MAX_CHANNEL                      ([!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Enum of Lin Interrupt line number, 0 or 1. */
/* 
*Design: MCAL-25666, MCAL-25691  
*/
typedef enum
{
   /** \brief Use Interrupt Line 0 */
   LIN_INTERRUPT_LINE_NUM_0 = 0x0U,
   /** \brief Use Interrupt Line 1 */
   LIN_INTERRUPT_LINE_NUM_1 = 0x1U
} Lin_InterruptLineNum;

/** \brief Enum of Lin Loopbackmode, Internal/External/Disabled Type selection. */
/* 
*Design: MCAL-25692, MCAL-25664
*/
typedef enum Lin_LoopbackModeTag
{
   /** \brief Loopback disabled */
   LIN_LOOPBACK_DISABLED,
   /** \brief Loopback internal */
   LIN_LOOPBACK_INTERNAL,
   /** \brief Loopback external */
   LIN_LOOPBACK_EXTERNAL
} Lin_LoopbackModeType;

/** \brief Lin Controller Configuration structure.*/
/* 
 *Design: MCAL-25693   
 */
typedef struct Lin_ControllerTag
{
   /** \brief Pointer to LinReg structure */
   uint32 CntrAddr;

   /** \brief Loopback Mode for this controller */
   Lin_LoopbackModeType LoopbackMode;

   /** \brief Interrupt Line to be selected */
   Lin_InterruptLineNum IntrLineNum;
   
} Lin_ControllerType;


/** \brief Lin Controller BaudRate Configuration.*/
/* 
 *Design: MCAL-25659,MCAL-25667,MCAL-25668,MCAL-25694
 */
typedef struct Lin_BaudrateConfigTag
{ 
   /** \brief Baud rate value */
   uint32 BaudRate;

   /** \brief Prescalar value */
   uint32 Prescalar;

   /** \brief Fractional Divider value */
   uint32 FractionalDivider;
} Lin_BaudRateConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief LIN Configuration struct declaration */
/* 
 *Design: MCAL-25660
 */
extern const struct Lin_ConfigTag Lin_Config;
[!ENDSELECT!]
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
#endif /* LIN_CFG_H */
/*********************************************************************************************************************
 *  End of File: Lin_Cfg.h
 *********************************************************************************************************************/
