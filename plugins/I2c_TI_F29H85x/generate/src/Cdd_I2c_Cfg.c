[!SKIPFILE "node:value(as:modconf('Cdd_I2c/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_I2c/Cdd']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
[!IF "CddI2cHwUnitMode = 'CDD_I2C_MODE_TARGET'"!][!//
            .baudRate = 0U,
[!ELSE!][!//
            .baudRate = [!"CddI2cHwBaudrate"!]U,
[!ENDIF!][!//
            .hwUnitFrequency = [!"CddI2cHwUnitFrequency"!]U,
            .sysClk = [!"num:i(node:value(concat(node:path(node:ref(CddI2cHwFunctionalClock)), '/McuClockReferencePointFrequency')))"!]U,
            .ownAddress = [!"CddI2cHwOwnAddress"!]U,
            .addressScheme = [!"CddI2cHwAddressScheme"!],
            .mode = [!"CddI2cHwUnitMode"!],
            .isIntrMode = [!IF "CddI2cHwUnitMode = 'CDD_I2C_MODE_TARGET' or CddI2cHwUseInterrupts = 'true'"!] TRUE[!ELSE!] FALSE[!ENDIF!],
[!IF "CddI2cHwUnitMode = 'CDD_I2C_MODE_TARGET' and node:exists(CddI2cTargetCallbacks)"!][!//
            .targetTxStartNotification = [!IF "node:exists(CddI2cTargetCallbacks/CddI2cTargetTxStartNotification)"!] [!"CddI2cTargetCallbacks/CddI2cTargetTxStartNotification"!][!ELSE!] NULL_PTR[!ENDIF!],
            .targetRxStartNotification = [!IF "node:exists(CddI2cTargetCallbacks/CddI2cTargetRxStartNotification)"!] [!"CddI2cTargetCallbacks/CddI2cTargetRxStartNotification"!][!ELSE!] NULL_PTR[!ENDIF!],
            .targetTxCompleteNotification = [!IF "node:exists(CddI2cTargetCallbacks/CddI2cTargetTxCompleteNotification)"!] [!"CddI2cTargetCallbacks/CddI2cTargetTxCompleteNotification"!][!ELSE!] NULL_PTR[!ENDIF!],
            .targetRxCompleteNotification = [!IF "node:exists(CddI2cTargetCallbacks/CddI2cTargetRxCompleteNotification)"!] [!"CddI2cTargetCallbacks/CddI2cTargetRxCompleteNotification"!][!ELSE!] NULL_PTR[!ENDIF!],
            .targetErrorNotification = [!IF "node:exists(CddI2cTargetCallbacks/CddI2cTargetErrorNotification)"!] [!"CddI2cTargetCallbacks/CddI2cTargetErrorNotification"!][!ELSE!] NULL_PTR[!ENDIF!],
[!ELSE!][!//
            .targetTxStartNotification = NULL_PTR,
            .targetRxStartNotification = NULL_PTR,
            .targetTxCompleteNotification = NULL_PTR,
            .targetRxCompleteNotification = NULL_PTR,
            .targetErrorNotification = NULL_PTR,
[!ENDIF!][!//
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
