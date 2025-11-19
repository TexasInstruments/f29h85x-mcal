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
 *  \addtogroup CDD_I2C I2C Configuration Header file
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
#define CDD_I2C_CFG_MAJOR_VERSION       (1U)
/** \brief I2C configuration Minor Version */
#define CDD_I2C_CFG_MINOR_VERSION       (0U)
/** \brief I2C configuration Patch Version */
#define CDD_I2C_CFG_PATCH_VERSION       (0U)
/** @} */

/**
 *  \brief I2C Build Variant.
 *   Build variants.(i.e Pre Compile and Post Build)
 */
#define CDD_I2C_PRE_COMPILE_VARIANT     (STD_ON)
/** \brief Precompile variant macro */
#define CDD_I2C_CONFIG_PC               Cdd_I2c_Config


/** \brief Enable/disable Interrupts */
#define CDD_I2C_POLLING_MODE            (STD_ON)

/** \brief Enable/Disable I2C dev detect error */
#define CDD_I2C_DEV_ERROR_DETECT        (STD_ON)

/** \brief Version info API macro */
#define CDD_I2C_VERSION_INFO_API        (STD_ON)

/** \brief Check to enable cancel API */
#define CDD_I2C_CANCEL_API              (STD_ON)

/** \brief Check to enable get driver status API */
#define CDD_I2C_GET_STATUS_API          (STD_ON)

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
#define CDD_I2C_HW_UNIT_MAX             (2U)

/*
 * All below macros are used for static memory allocation and can be changed to
 * match the usecase requirements.
 */
/** \brief Maximum channels allowed per sequence */
#define CDD_I2C_MAX_CH_PER_SEQ          (2U)

/** \brief Maximum channels across all sequence/hwunit */
#define CDD_I2C_MAX_CH                  (12U)

/** \brief Maximum sequence across all hwunit */
#define CDD_I2C_MAX_SEQ                 (8U)

/** \brief Maximum HW unit */
#define CDD_I2C_MAX_HW_UNIT             (2U)

/*
 * All below macros are used for enabling a particular hardware.
 */
#define CDD_I2C_HW_UNIT_I2CA_ACTIVE
#define CDD_I2C_HW_UNIT_I2CB_ACTIVE



/** \brief Symbolic Name for I2c Sequence 0 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_0    (0U)
/** \brief Symbolic Name for I2c Sequence 1 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_1    (1U)
/** \brief Symbolic Name for I2c Sequence 2 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_2    (2U)
/** \brief Symbolic Name for I2c Sequence 3 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_3    (3U)
/** \brief Symbolic Name for I2c Sequence 4 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_4    (4U)
/** \brief Symbolic Name for I2c Sequence 5 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_5    (5U)
/** \brief Symbolic Name for I2c Sequence 6 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_6    (6U)
/** \brief Symbolic Name for I2c Sequence 7 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_7    (7U)

/** \brief Symbolic Name for I2c Channel 0 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_0      (0U)
/** \brief Symbolic Name for I2c Channel 1 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_1      (1U)
/** \brief Symbolic Name for I2c Channel 2 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_2      (2U)
/** \brief Symbolic Name for I2c Channel 3 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_3      (3U)
/** \brief Symbolic Name for I2c Channel 4 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_4      (4U)
/** \brief Symbolic Name for I2c Channel 5 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_5      (5U)
/** \brief Symbolic Name for I2c Channel 6 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_6      (6U)
/** \brief Symbolic Name for I2c Channel 7 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_7      (7U)
/** \brief Symbolic Name for I2c Channel 8 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_8      (8U)
/** \brief Symbolic Name for I2c Channel 9 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_9      (9U)
/** \brief Symbolic Name for I2c Channel 10 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_10      (10U)
/** \brief Symbolic Name for I2c Channel 11 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_11      (11U)

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

extern void I2c_appSeqComplete(void);

extern void I2c_appSeqFail(uint8 errorCode);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef I2C_CFG_H_ */

/** @} */
/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Cfg.h
 *********************************************************************************************************************/
