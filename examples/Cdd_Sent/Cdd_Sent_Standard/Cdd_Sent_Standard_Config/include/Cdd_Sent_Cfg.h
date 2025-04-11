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
#define CDD_SENT_CFG_MAJOR_VERSION    (1U) //!< CDDSENT configuration Major Version.
#define CDD_SENT_CFG_MINOR_VERSION    (0U) //!< CDDSENT configuration Minor Version.
#define CDD_SENT_CFG_PATCH_VERSION    (0U) //!< CDDSENT configuration Patch Version.


/** \brief CDDSENT Build Variant. Build Variants.(i.e Pre-compile,Post-Build or Link time)*/
#define CDD_SENT_CFG_PRE_COMPILE_VARIANT          (STD_ON)

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CDD_SENT_CFG_DEM_ENABLE    (STD_ON)


#define CDD_E_HARDWARE_ERROR  (DemConf_DemEventParameter_CDD_E_HARDWARE_ERROR)



/** \brief Enable/Disable DEV error detection.*/
/*
 *Design: MCAL-xxxxx
 */
#define CDD_SENT_CFG_DEV_ERROR_DETECT             (STD_ON)


/** \brief Enable/Disable CddSent_GetVersionInfo().*/

/*
 *Design: MCAL-22756
 */
#define CDD_SENT_CFG_GET_VERSION_INFO_API         (STD_ON)

/** \brief Defines for symbolic names for the CddSent HW uint ID's (CddSentHWUnitId) */
#define Cdd_SentConf_Cdd_SentController_CddSentController_0 (0U) /*~ASR~*/

                        
#define ENABLE_TIMESTAMP (0x1U)

/** \brief CddSent Controller Instance interrupt definition */
#define CDD_SENT1_ENABLE
#define CDD_SENT1_ISR_CAT1_INT

/** \brief Max number of HW units defined defined */
#define SENT_MAX_HW_UNITS                      (6U)

/** \brief No. of HW units defined in CddSent Driver */
#define SENT_CFG_NO_OF_HW_UNITS            (1U)

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
