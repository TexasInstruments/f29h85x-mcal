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
 *  File:       Cdd_Sent_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_SENT_CFG_H
#define CDD_SENT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent_Cbk.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief CDDSENT Driver Configuration SW Version Info.*/
#define CDD_SENT_CFG_MAJOR_VERSION    ([!"substring-before($moduleSoftwareVer,'.')"!]U) //!< CDDSENT configuration Major Version.
#define CDD_SENT_CFG_MINOR_VERSION    ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U) //!< CDDSENT configuration Minor Version.
#define CDD_SENT_CFG_PATCH_VERSION    ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U) //!< CDDSENT configuration Patch Version.


/** \brief CDDSENT Build Variant. Build Variants.(i.e Pre-compile,Post-Build or Link time)*/
#define CDD_SENT_CFG_PRE_COMPILE_VARIANT          [!IF "as:modconf('Cdd_Sent')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CDD_SENT_CFG_DEM_ENABLE    [!IF "node:refexists(as:modconf('Cdd_Sent')[1]/CddSentDemEventParameterRefs/CDD_E_HARDWARE_ERROR)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:refexists(as:modconf('Cdd_Sent')[1]/CddSentDemEventParameterRefs/CDD_E_HARDWARE_ERROR)"!]
#define CDD_E_HARDWARE_ERROR  (DemConf_DemEventParameter_[!"node:name(node:ref(as:modconf('Cdd_Sent')[1]/CddSentDemEventParameterRefs/CDD_E_HARDWARE_ERROR))"!])
[!ENDIF!]


/** \brief Enable/Disable DEV error detection.*/
/*
 *Design: MCAL-xxxxx
 */
#define CDD_SENT_CFG_DEV_ERROR_DETECT             [!IF "as:modconf('Cdd_Sent')[1]/CddSentGeneral/CddSentDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/** \brief Enable/Disable CddSent_GetVersionInfo().*/

/*
 *Design: MCAL-22756
 */
#define CDD_SENT_CFG_GET_VERSION_INFO_API         [!IF "as:modconf('Cdd_Sent')[1]/CddSentGeneral/CddSentVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Defines for symbolic names for the CddSent HW uint ID's (CddSentHWUnitId) */
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*"!][!//
#define Cdd_SentConf_Cdd_SentController_[!"@name"!] ([!"CddSentHWUnitId"!]U) /*~ASR~*/
[!ENDLOOP!][!//

[!VAR "Enable_Timestamp" = "0"!][!//
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*"!][!//
    [!LOOP "CddSentChannelObject/*"!][!//
    [!IF "CddSentEnableTimeStamp ='true'"!][!//
        [!VAR "Enable_Timestamp" = "1"!][!//
        [!BREAK!]
    [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDLOOP!][!//

#define ENABLE_TIMESTAMP [!IF "$Enable_Timestamp  ='1.0'"!](0x1U)[!ELSE!](0x0U)[!ENDIF!]

/** \brief CddSent Controller Instance interrupt definition */
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*"!][!//
#define CDD_[!"CddSentInstance"!]_ENABLE
[!IF "CddSentInteruptType = 'CDD_SENT_ISR_CAT1_RTINT'"!][!//
#define CDD_[!"CddSentInstance"!]_ISR_CAT1_RTINT
[!ELSEIF "CddSentInteruptType = 'CDD_SENT_ISR_CAT1_INT'"!][!//
#define CDD_[!"CddSentInstance"!]_ISR_CAT1_INT
[!ELSE!][!//
#define CDD_[!"CddSentInstance"!]_ISR_CAT2
[!ENDIF!][!//
[!ENDLOOP!][!//

/** \brief Max number of HW units defined defined */
#define SENT_MAX_HW_UNITS                      (6U)

/** \brief No. of HW units defined in CddSent Driver */
#define SENT_CFG_NO_OF_HW_UNITS            ([!"num:i(count(as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*))"!]U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
extern CONST(struct Cdd_Sent_DriverObjType_s, CDD_SENT_CONFIG_DATA) CddSentConfig_Cdd_SentController_List;
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
#endif /* CDD_SENT_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Cfg.h
 *********************************************************************************************************************/
