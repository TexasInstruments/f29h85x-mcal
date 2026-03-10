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


/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Version checking - cfg.c and .h */
#if ((CDD_I2C_SW_MAJOR_VERSION != (1U)) || (CDD_I2C_SW_MINOR_VERSION != (2U)))
  #error "Version numbers of Cdd_I2c_Cfg.c and Cdd_I2c.h are inconsistent!"
#endif

/** \brief Version checking - cfg.c and cfg.h */
#if ((CDD_I2C_CFG_MAJOR_VERSION != (1U)) || (CDD_I2C_CFG_MINOR_VERSION != (2U)))
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
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
            .mode = CDD_I2C_MODE_CONTROLLER,
            .isIntrMode = TRUE,
            .targetTxStartNotification = NULL_PTR,
            .targetRxStartNotification = NULL_PTR,
            .targetTxCompleteNotification = NULL_PTR,
            .targetRxCompleteNotification = NULL_PTR,
            .targetErrorNotification = NULL_PTR,
        },
        [1U] =
        {
            .hwUnitId = CDD_I2C_HW_UNIT_I2CB,
            .baudRate = 400000U,
            .hwUnitFrequency = 10000000U,
            .sysClk = 200000000U,
            .ownAddress = 127U,
            .addressScheme = CDD_I2C_ADDRESS_7_BIT,
            .mode = CDD_I2C_MODE_CONTROLLER,
            .isIntrMode = TRUE,
            .targetTxStartNotification = NULL_PTR,
            .targetRxStartNotification = NULL_PTR,
            .targetTxCompleteNotification = NULL_PTR,
            .targetRxCompleteNotification = NULL_PTR,
            .targetErrorNotification = NULL_PTR,
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
