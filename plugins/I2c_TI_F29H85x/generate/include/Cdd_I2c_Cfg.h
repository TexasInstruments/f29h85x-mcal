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
 *  File:       Cdd_I2c_Cfg.h
 *  Generator:  None
 *
 *  Description:  Cdd_I2c configuration header file
 *********************************************************************************************************************/
/**
 *  \addtogroup CDD_I2C
 *
 *  This files defines I2C configuration structures
 *  @{
 */

#ifndef CDD_I2C_CFG_H_
#define CDD_I2C_CFG_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

[!SELECT "as:modconf('Cdd_I2c/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_I2c/Cdd']"!][!//
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/**
 *  \name I2C Driver Configuration SW Version Info
 *
 *  Defines for I2C Driver configuration version
 *  @{
 */
/** \brief I2C configuration Major Version */
#define CDD_I2C_CFG_MAJOR_VERSION       ([!"substring-before($moduleSoftwareVer,'.')"!]U)
/** \brief I2C configuration Minor Version */
#define CDD_I2C_CFG_MINOR_VERSION       ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief I2C configuration Patch Version */
#define CDD_I2C_CFG_PATCH_VERSION       ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** @} */
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/**
 *  \brief I2C Build Variant.
 *   Build variants.(i.e Pre Compile and Post Build)
 */
#define CDD_I2C_PRE_COMPILE_VARIANT     (STD_ON)[!//

/** \brief Precompile variant macro */
#define CDD_I2C_CONFIG_PC               Cdd_I2c_Config

[!ENDIF!]
/** \brief Enable/disable Interrupts */
#define CDD_I2C_POLLING_MODE            [!IF "CddI2cGeneral/CddI2cUseInterrupts = 'true'"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/** \brief Enable/Disable I2C dev detect error */
#define CDD_I2C_DEV_ERROR_DETECT        [!IF "CddI2cGeneral/CddI2cDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Version info API macro */
#define CDD_I2C_VERSION_INFO_API        [!IF "CddI2cGeneral/CddI2cVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Check to enable cancel API */
#define CDD_I2C_CANCEL_API              [!IF "CddI2cGeneral/CddI2cCancelApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Check to enable get driver status API */
#define CDD_I2C_GET_STATUS_API          [!IF "CddI2cGeneral/CddI2cStatusApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
 *  \name I2C HW Unit ID
 *
 *  Specifies the HW identification (ID) for I2C
 *  @{
 */
/** \brief HW unit 0 */
#define CDD_I2C_HW_UNIT_I2CA            ((Cdd_I2c_HwUnitType)0U)
/** \brief HW unit 1 */
#define CDD_I2C_HW_UNIT_I2CB            ((Cdd_I2c_HwUnitType)1U)
/** @} */
/** \brief Maximum supported HW units for the SOC */
#define CDD_I2C_HW_UNIT_MAX             ([!"num:i(count(ecu:list('ResourceAllocator_F29H85x.Cdd_I2cInstanceName')))"!]U)

[!VAR "varmax" = "0"!][!//
[!LOOP "CddI2cSeqConfig/*"!][!//
[!VAR "temp" = "num:i(count(CddI2cSeqChList/*))"!][!//
[!IF "$varmax < $temp"!][!//
[!VAR "varmax" = "$temp"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
/*
 * All below macros are used for static memory allocation and can be changed to
 * match the usecase requirements.
 */
/** \brief Maximum channels allowed per sequence */
#define CDD_I2C_MAX_CH_PER_SEQ          ([!"num:i($varmax)"!]U)

[!VAR "varmax" = "0"!][!//
[!LOOP "CddI2cChConfig/*"!][!//
[!VAR "varmax" = "$varmax+1"!][!//
[!ENDLOOP!][!//
/** \brief Maximum channels across all sequence/hwunit */
#define CDD_I2C_MAX_CH                  ([!"num:i($varmax)"!]U)

[!VAR "varmax" = "0"!][!//
[!LOOP "CddI2cSeqConfig/*"!][!//
[!VAR "varmax" = "$varmax+1"!][!//
[!ENDLOOP!][!//
/** \brief Maximum sequence across all hwunit */
#define CDD_I2C_MAX_SEQ                 ([!"num:i($varmax)"!]U)

/** \brief Maximum HW unit */
#define CDD_I2C_MAX_HW_UNIT             ([!"num:i(count(CddI2cHwConfig/*))"!]U)

/*
 * All below macros are used for enabling a particular hardware.
 */
[!LOOP "CddI2cHwConfig/*"!][!//
#define CDD_I2C_HW_UNIT_[!"node:value(node:ref(CddI2cHwUnitRef)/InstanceName)"!]_ACTIVE
[!ENDLOOP!][!//

[!IF "CddI2cGeneral/CddI2cUseInterrupts = 'true' "!]
[!LOOP "CddI2cHwConfig/*"!][!//
#define CDD_I2C_HW_UNIT_[!"node:value(node:ref(CddI2cHwUnitRef)/InstanceName)"!]_[!"CddI2cHwIrqType"!]
[!ENDLOOP!][!//
[!ENDIF!]

[!SELECT "CddI2cSeqConfig/*"!][!//
/** \brief Symbolic Name for I2c Sequence [!"node:pos(.)"!] */
#define CddI2cConf_CddI2cSeqConfig_[!"@name"!]    ([!"node:pos(.)"!]U)
[!ENDSELECT!][!//

[!SELECT "CddI2cChConfig/*"!][!//
/** \brief Symbolic Name for I2c Channel [!"node:pos(.)"!] */
#define CddI2cConf_CddI2cChConfig_[!"@name"!]      ([!"node:pos(.)"!]U)
[!ENDSELECT!][!//

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern CONST(struct Cdd_I2c_ConfigTag, CDD_I2C_CONFIG_DATA) Cdd_I2c_Config;
extern CONST(uint32, CDD_I2C_CONST) Cdd_I2c_HwUnitBaseAddr[CDD_I2C_HW_UNIT_MAX];

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

[!VAR "CddI2cSeqCompleteNotifyList" = "' '"!][!//
[!LOOP "CddI2cSeqConfig/*"!][!//
[!IF "not(node:empty(CddI2cSeqCompleteNotify)) and not((text:match(CddI2cSeqCompleteNotify,'NULL_PTR')))"!][!//
[!IF "not(node:containsValue(text:split($CddI2cSeqCompleteNotifyList),CddI2cSeqCompleteNotify))"!][!//
[!"concat('extern void ',node:value(CddI2cSeqCompleteNotify),'(void);')"!]
[!VAR "CddI2cSeqCompleteNotifyList" = "concat($CddI2cSeqCompleteNotifyList,' ',CddI2cSeqCompleteNotify)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "CddI2cSeqErrorNotifyList" = "' '"!][!//
[!LOOP "CddI2cSeqConfig/*"!][!//
[!IF "not(node:empty(CddI2cSeqErrorNotify)) and not((text:match(CddI2cSeqErrorNotify,'NULL_PTR')))"!][!//
[!IF "not(node:containsValue(text:split($CddI2cSeqErrorNotifyList),CddI2cSeqErrorNotify))"!][!//
[!"concat('extern void ',node:value(CddI2cSeqErrorNotify),'(uint8 errorCode);')"!]
[!VAR "CddI2cSeqErrorNotifyList" = "concat($CddI2cSeqErrorNotifyList,' ',CddI2cSeqErrorNotify)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

[!ENDSELECT!][!//
#ifdef __cplusplus
}
#endif

#endif  /* #ifndef I2C_CFG_H_ */

/** @} */
/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Cfg.h
 *********************************************************************************************************************/
