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
 *  File:       Cdd_I2c_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Cdd_I2c configuration source file
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c.h"
#include "hw_memmap.h"


/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Version checking - cfg.c and .h */
#if ((CDD_I2C_SW_MAJOR_VERSION != (1U)) || (CDD_I2C_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Cdd_I2c_Cfg.c and Cdd_I2c.h are inconsistent!"
#endif

/** \brief Version checking - cfg.c and cfg.h */
#if ((CDD_I2C_CFG_MAJOR_VERSION != (1U)) || (CDD_I2C_CFG_MINOR_VERSION != (1U)))
    #error "Version numbers of Cdd_I2c_Cfg.c and Cdd_I2c_Cfg.h are inconsistent!"
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
 * Exported Object Definitions
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CONFIG_DATA
#include "Cdd_I2c_MemMap.h"

CONST(struct Cdd_I2c_ConfigTag, CDD_I2C_CONFIG_DATA) Cdd_I2c_Config =
{
    .hwUnitCfg =
    {
        [0U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CA,
            .baudRate = 400000U,
            .hwUnitFrequency = 10000000U,
            .sysClk = 200000000U,
            .ownAddress = 127U,
        },
        [1U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .baudRate = 400000U,
            .hwUnitFrequency = 10000000U,
            .sysClk = 200000000U,
            .ownAddress = 127U,
        },

    },
    .seqCfg =
    {
        [0U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CA,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 1U,
            .chList =
            {
                0U,
                0U,
            },
        },
        [1U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CA,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 1U,
            .chList =
            {
                1U,
                0U,
            },
        },
        [2U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CA,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 2U,
            .chList =
            {
                2U,
                3U,
            },
        },
        [3U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CA,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_NOSTOP,
            .chPerSeq = 2U,
            .chList =
            {
                4U,
                5U,
            },
        },
        [4U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 1U,
            .chList =
            {
                6U,
                0U,
            },
        },
        [5U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 1U,
            .chList =
            {
                7U,
                0U,
            },
        },
        [6U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_STOP,
            .chPerSeq = 2U,
            .chList =
            {
                8U,
                9U,
            },
        },
        [7U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .completeNotify = I2c_appSeqComplete,
            .errorNotify = I2c_appSeqFail,
            .restartMode = CDD_I2C_RESTART_MODE_NOSTOP,
            .chPerSeq = 2U,
            .chList =
            {
                10U,
                11U,
            },
        },

    },
    .chCfg =
    {
        [0U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [1U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [2U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [3U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [4U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [5U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [6U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [7U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [8U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [9U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [10U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_WRITE,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },
        [11U] =
        {
            .deviceAddress = 127U,
            .direction = CDD_I2C_READ,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
        },

    },
};
#define CDD_I2C_STOP_SEC_CONFIG_DATA
#include "Cdd_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CONFIG_CONST_32
#include "Cdd_I2c_MemMap.h"
CONST(uint32, CDD_I2C_CONST) Cdd_I2c_HwUnitBaseAddr[CDD_I2C_HW_UNIT_MAX] = {
    I2CA_BASE_FRAME(0U), /* I2CA_BASE_ADDR */
    I2CB_BASE_FRAME(0U), /* I2CB_BASE_ADDR */
};
#define CDD_I2C_STOP_SEC_CONFIG_CONST_32
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Cfg.c
 *********************************************************************************************************************/
