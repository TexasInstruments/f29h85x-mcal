[!SKIPFILE "node:value(as:modconf('Cdd_I2c/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_I2c/Cdd']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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

[!AUTOSPACING!]

[!SELECT "as:modconf('Cdd_I2c/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_I2c/Cdd']"!][!//
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Version checking - cfg.c and .h */
#if ((CDD_I2C_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_I2C_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_I2c_Cfg.c and Cdd_I2c.h are inconsistent!"
#endif

/** \brief Version checking - cfg.c and cfg.h */
#if ((CDD_I2C_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_I2C_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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

[!VAR "var_max_ch_per_seq" = "0"!][!//
[!LOOP "CddI2cSeqConfig/*"!][!//
[!VAR "temp" = "num:i(count(CddI2cSeqChList/*))"!][!//
[!IF "$var_max_ch_per_seq < $temp"!][!//
[!VAR "var_max_ch_per_seq" = "$temp"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
CONST(struct Cdd_I2c_ConfigTag, CDD_I2C_CONFIG_DATA) Cdd_I2c_Config =
{
    .hwUnitCfg =
    {
[!LOOP "CddI2cHwConfig/*"!][!//
        [[!"num:i(@index)"!]U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_[!"node:value(node:ref(CddI2cHwUnitRef)/InstanceName)"!],
            .baudRate = [!"CddI2cHwBaudrate"!]U,
            .hwUnitFrequency = [!"CddI2cHwUnitFrequency"!]U,
            .sysClk = [!"num:i(node:value(concat(node:path(node:ref(CddI2cHwFunctionalClock)), '/McuClockReferencePointFrequency')))"!]U,
            .ownAddress = [!"CddI2cHwOwnAddress"!]U,
        },
[!ENDLOOP!][!CR!][!//
    },
    .seqCfg =
    {
[!LOOP "CddI2cSeqConfig/*"!][!//
        [[!"num:i(@index)"!]U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_[!"node:value(node:ref(node:ref(node:current()/CddI2cSeqHwUnitAssignment)/CddI2cHwUnitRef)/InstanceName)"!],
            .completeNotify = [!"CddI2cSeqCompleteNotify"!],
            .errorNotify = [!"CddI2cSeqErrorNotify"!],
            .restartMode = CDD_I2C_[!"CddI2cSeqRestartModeType"!],
            .chPerSeq = [!"num:i(count(CddI2cSeqChList/*))"!]U,
            .chList =
            {
                [!FOR "x" = "1" TO "num:i(count(CddI2cSeqChList/*))"!]
                [!"node:pos(node:ref(./CddI2cSeqChList/*[num:i($x)]/CddI2cSeqChAssignment))"!]U,
                [!ENDFOR!][!//
                [!FOR "x" = "num:i(count(CddI2cSeqChList/*))+num:i(1)" TO "num:i($var_max_ch_per_seq)"!]
                0U,
                [!ENDFOR!][!//
            },
        },
[!ENDLOOP!][!CR!][!//
    },
    .chCfg =
    {
[!LOOP "CddI2cChConfig/*"!][!//
        [[!"num:i(@index)"!]U] =
        {
            .deviceAddress = [!"CddI2cChTargetAddress"!]U,
            .direction = CDD_I2C_[!"CddI2cChDirection"!],
            .addressScheme = CDD_I2C_[!"CddI2cChTargetAddressScheme"!],
        },
[!ENDLOOP!][!CR!][!//
    },
};
#define CDD_I2C_STOP_SEC_CONFIG_DATA
#include "Cdd_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CONFIG_CONST_32
#include "Cdd_I2c_MemMap.h"
[!VAR "I2CAInstanceConfigured" = "0"!][!VAR "I2CBInstanceConfigured" = "0"!][!//
CONST(uint32, CDD_I2C_CONST) Cdd_I2c_HwUnitBaseAddr[CDD_I2C_HW_UNIT_MAX] = {
[!LOOP "CddI2cHwConfig/*"!][!//
[!IF "node:value(node:ref(CddI2cHwUnitRef)/InstanceName) = 'I2CA'"!][!//
    [!"node:value(node:ref(CddI2cHwUnitRef)/BaseAddr)"!], /* I2CA_BASE_ADDR */
[!VAR "I2CAInstanceConfigured" = "$I2CAInstanceConfigured+num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($I2CAInstanceConfigured) = 0"!][!//
    I2CA_BASE_FRAME(0U), /* I2CA_BASE_ADDR */
[!ENDIF!][!//
[!LOOP "CddI2cHwConfig/*"!][!//
[!IF "node:value(node:ref(CddI2cHwUnitRef)/InstanceName) = 'I2CB'"!][!//
    [!"node:value(node:ref(CddI2cHwUnitRef)/BaseAddr)"!], /* I2CB_BASE_ADDR */
[!VAR "I2CBInstanceConfigured" = "$I2CBInstanceConfigured+num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($I2CBInstanceConfigured) = 0"!][!//
    I2CB_BASE_FRAME(0U), /* I2CB_BASE_ADDR */
[!ENDIF!][!//
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
[!ENDSELECT!][!//

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Cfg.c
 *********************************************************************************************************************/
