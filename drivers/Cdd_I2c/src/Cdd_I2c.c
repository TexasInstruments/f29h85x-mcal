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
 *  File:       Cdd_I2c.c
 *  Generator:  None
 *
 *  Description:  The I2C driver provides APIs to configure the I2C module
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c_Priv.h"
#include "Cdd_I2c_Hw.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_I2C_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version of I2C is incorrect"
#endif

/* vendor specific version information check */
#if ((CDD_I2C_SW_MAJOR_VERSION != (1U)) || (CDD_I2C_SW_MINOR_VERSION != (2U)))
#error "Version numbers of Cdd_I2c.c and Cdd_I2c.h are not matching!"
#endif
#if ((CDD_I2C_CFG_MAJOR_VERSION != (1U)) || (CDD_I2C_CFG_MINOR_VERSION != (2U)))
#error "Version numbers of Cdd_I2c.c and Cdd_I2c_Cfg.h are not matching!"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_SetupEBParamCheck(uint8 apiId, Cdd_I2c_ChannelType chId,
                                                Cdd_I2c_DataConstPtrType txDataBufferPtr,
                                                Cdd_I2c_DataPtrType rxDataBufferPtr, Cdd_I2c_DataLengthType length);
#endif
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

/* ========================================================================== */
/*                        Local Object Definitions                            */
/* ========================================================================== */

#define CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_I2c_MemMap.h"
/* Driver Status */
Cdd_I2c_ComponentStatusType Cdd_I2c_DrvState = CDD_I2C_UNINIT;
#define CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_I2c_MemMap.h"

#define CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_I2c_MemMap.h"
/* Driver Object */
Cdd_I2c_DriverObjType Cdd_I2c_DrvObj;
#define CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_I2c_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

FUNC(void, CDD_I2C_CODE) Cdd_I2c_Init(const Cdd_I2c_ConfigType *configPtr)
{
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    Std_ReturnType retVal = E_OK;
    if (NULL_PTR != configPtr)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT, CDD_I2C_E_PARAM_CONFIG);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (CDD_I2C_UNINIT != Cdd_I2c_DrvState))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT, CDD_I2C_E_ALREADY_INITIALIZED);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        /* Only pre-compile variant supported */
        const Cdd_I2c_ConfigType *localConfigPtr = &CDD_I2C_CONFIG_PC;

        /* Suppress unused parameter MISRAC warning */
        (void)configPtr;
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
        retVal = Cdd_I2c_CheckConfig(localConfigPtr);
        if (retVal == (Std_ReturnType)E_OK)
#endif
        {
            Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

            Cdd_I2c_InitDrvObj(drvObj);
            Cdd_I2c_CopyConfig(drvObj, localConfigPtr);

            /* Init HW once all config is copied */
            for (uint32 hwIdx = 0U; hwIdx < CDD_I2C_MAX_HW_UNIT; hwIdx++)
            {
                Cdd_I2c_HwUnitObjType          *hwUnitObj = &drvObj->hwUnitObj[hwIdx];
                const Cdd_I2c_HwUnitConfigType *hwUnitCfg = hwUnitObj->hwUnitCfg;
                Cdd_I2c_HwInit(hwUnitObj->baseAddr, hwUnitCfg->baudRate, hwUnitCfg->hwUnitFrequency, hwUnitCfg->sysClk,
                               hwUnitCfg->ownAddress, hwUnitCfg->mode);
            }
            Cdd_I2c_DrvState = CDD_I2C_IDLE;
        }
    }

    return;
}

FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_DeInit(void)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_DEINIT, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    else
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

        for (uint32 hwIdx = 0U; hwIdx < CDD_I2C_MAX_HW_UNIT; hwIdx++)
        {
            Cdd_I2c_HwUnitObjType *hwUnitObj = &drvObj->hwUnitObj[hwIdx];
            Cdd_I2c_HwDeInit(hwUnitObj->baseAddr);
        }
        Cdd_I2c_DeInitDrvObj(drvObj);
        Cdd_I2c_DrvState = CDD_I2C_UNINIT;
    }

    return retVal;
}

#if (STD_ON == CDD_I2C_VERSION_INFO_API)
FUNC(void, CDD_I2C_CODE) Cdd_I2c_GetVersionInfo(Std_VersionInfoType *versionInfo)
{
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (NULL_PTR == versionInfo)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_GET_VERSION_INFO,
                              CDD_I2C_E_PARAM_VINFO_PTR);
    }
    else
#endif
    {
        versionInfo->vendorID         = CDD_I2C_VENDOR_ID;
        versionInfo->moduleID         = CDD_I2C_MODULE_ID;
        versionInfo->sw_major_version = (uint8)CDD_I2C_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)CDD_I2C_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)CDD_I2C_SW_PATCH_VERSION;
    }

    return;
}
#endif

FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_ResetHwUnit(Cdd_I2c_HwUnitType hwUnitId)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
    Cdd_I2c_HwUnitObjType *hwUnitObj;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_RESET_HW_UNIT, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR == hwUnitObj)
        {
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_RESET_HW_UNIT,
                                  CDD_I2C_E_PARAM_HWUNIT);
#endif
            retVal = E_NOT_OK;
        }
        else
        {
            SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

            retVal = Cdd_I2c_ResetHwUnitPriv(drvObj, hwUnitObj);

            SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
        }
    }

    return retVal;
}

#if (STD_ON == CDD_I2C_GET_STATUS_API)
FUNC(Cdd_I2c_ComponentStatusType, CDD_I2C_CODE) Cdd_I2c_GetStatus(void)
{
    return Cdd_I2c_DrvState;
}
#endif

/*
 * Controller only APIs
 */
#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEB(Cdd_I2c_ChannelType chId, Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                Cdd_I2c_DataLengthType length)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_SETUP_EB, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
    {
        if (chId >= CDD_I2C_MAX_CH)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_SETUP_EB,
                                  CDD_I2C_E_PARAM_CHANNEL);
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = Cdd_I2c_SetupEBParamCheck(CDD_I2C_SID_SETUP_EB, chId, txDataBufferPtr, rxDataBufferPtr, length);
        }
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_ChObjType     *chObj  = &drvObj->chObj[chId];

        SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

        chObj->txBufPtr = txDataBufferPtr;
        chObj->rxBufPtr = rxDataBufferPtr;
        chObj->length   = length;
        /* Restore device address from user configuration */
        chObj->deviceAddress = chObj->chCfg->deviceAddress;
        chObj->addressScheme = chObj->chCfg->addressScheme;

        SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
    }

    return retVal;
}

FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEBDynamic(Cdd_I2c_ChannelType chId, Cdd_I2c_AddressType deviceAddress,
                       Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                       Cdd_I2c_DataLengthType length)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_SETUP_EB_DYNAMIC, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
    {
        if (chId >= CDD_I2C_MAX_CH)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_SETUP_EB_DYNAMIC,
                                  CDD_I2C_E_PARAM_CHANNEL);
            retVal = E_NOT_OK;
        }
        else
        {
            retVal =
                Cdd_I2c_SetupEBParamCheck(CDD_I2C_SID_SETUP_EB_DYNAMIC, chId, txDataBufferPtr, rxDataBufferPtr, length);
        }
    }
    if ((retVal == (Std_ReturnType)E_OK) && (deviceAddress > CDD_I2C_ADDRESS_10_BIT_MAX))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_SETUP_EB_DYNAMIC,
                              CDD_I2C_E_PARAM_ADDRESS);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_ChObjType     *chObj  = &drvObj->chObj[chId];

        SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

        chObj->txBufPtr      = txDataBufferPtr;
        chObj->rxBufPtr      = rxDataBufferPtr;
        chObj->length        = length;
        chObj->deviceAddress = deviceAddress;
        /* The API doesn't provide parameter for addressing mode, so derive based on address */
        if (deviceAddress > CDD_I2C_ADDRESS_7_BIT_MAX)
        {
            chObj->addressScheme = CDD_I2C_ADDRESS_10_BIT;
        }
        else
        {
            chObj->addressScheme = CDD_I2C_ADDRESS_7_BIT;
        }

        SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
    }

    return retVal;
}

FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_AsyncTransmit(Cdd_I2c_SequenceType sequenceId)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_ASYNC_TRANSMIT, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (sequenceId >= CDD_I2C_MAX_SEQ))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_ASYNC_TRANSMIT,
                              CDD_I2C_E_PARAM_SEQUENCE);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_SeqObjType    *seqObj = &drvObj->seqObj[sequenceId];

        SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

        /* Pending sequence cannot be queued again */
        if (CDD_I2C_SEQ_PENDING == seqObj->seqResult)
        {
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_ASYNC_TRANSMIT,
                                  CDD_I2C_E_SEQ_BUSY);
#endif
            retVal = E_NOT_OK;
        }
        else
        {
            /* Call the start sequence API */
            retVal = Cdd_I2c_StartSeqAsync(drvObj, seqObj);
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
            if (E_OK != retVal)
            {
                (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_ASYNC_TRANSMIT,
                                      CDD_I2C_E_SEQ_BUSY);
            }
#endif
        }

        SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
    }

    return retVal;
}

#if (STD_ON == CDD_I2C_CANCEL_API)
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_Cancel(Cdd_I2c_SequenceType sequenceId)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_CANCEL, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (sequenceId >= CDD_I2C_MAX_SEQ))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_CANCEL, CDD_I2C_E_PARAM_SEQUENCE);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_SeqObjType    *seqObj = &drvObj->seqObj[sequenceId];

        SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

        if (CDD_I2C_SEQ_PENDING == seqObj->seqResult)
        {
            retVal = Cdd_I2c_CancelSeq(drvObj, seqObj);
        }

        SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
    }

    return retVal;
}
#endif

FUNC(void, CDD_I2C_CODE) Cdd_I2c_MainFunction(void)
{
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_MAIN_FUNCTION, CDD_I2C_E_UNINIT);
    }
    else
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();

        /* Check all hardware units for any pending sequence */
        for (uint32 hwUnitIdx = 0U; hwUnitIdx < drvObj->maxHwUnit; hwUnitIdx++)
        {
            hwUnitObj = &drvObj->hwUnitObj[hwUnitIdx];
            /* Only poll HW units that are not using interrupts */
            if ((FALSE == hwUnitObj->hwUnitCfg->isIntrMode) && (NULL_PTR != hwUnitObj->curChObj))
            {
                Cdd_I2c_ProcessEvents(drvObj, hwUnitObj);
            }
        }

        SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_I2C_CODE) Cdd_I2c_PollingModeProcessing(void)
{
    /* This API is deprecated and provide only for backward compatibility.
     * Call main handling fxn which does the job */
    Cdd_I2c_MainFunction();
    return;
}

FUNC(Cdd_I2c_SequenceResultType, CDD_I2C_CODE) Cdd_I2c_GetSequenceResult(Cdd_I2c_SequenceType sequenceId)
{
    Cdd_I2c_SequenceResultType seqResult = CDD_I2C_SEQ_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_GET_SEQUENCE_RESULT,
                              CDD_I2C_E_UNINIT);
        seqResult = CDD_I2C_SEQ_NOT_OK;
    }
    if ((seqResult == CDD_I2C_SEQ_OK) && (sequenceId >= CDD_I2C_MAX_SEQ))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_GET_SEQUENCE_RESULT,
                              CDD_I2C_E_PARAM_SEQUENCE);
        seqResult = CDD_I2C_SEQ_NOT_OK;
    }
    if (CDD_I2C_SEQ_OK == seqResult)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_SeqObjType    *seqObj = &drvObj->seqObj[sequenceId];

        seqResult = seqObj->seqResult;
    }

    return seqResult;
}

FUNC(Cdd_I2c_ChannelResultType, CDD_I2C_CODE) Cdd_I2c_GetResult(Cdd_I2c_ChannelType chId)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_OK;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_GET_RESULT, CDD_I2C_E_UNINIT);
        chResult = CDD_I2C_CH_RESULT_NOT_OK;
    }
    if ((chResult == CDD_I2C_CH_RESULT_OK) && (chId >= CDD_I2C_MAX_CH))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_GET_RESULT, CDD_I2C_E_PARAM_CHANNEL);
        chResult = CDD_I2C_CH_RESULT_NOT_OK;
    }
    if (CDD_I2C_CH_RESULT_OK == chResult)
#endif
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_ChObjType     *chObj  = &drvObj->chObj[chId];

        chResult = chObj->chResult;
    }

    return chResult;
}
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_SetupEBParamCheck(uint8 apiId, Cdd_I2c_ChannelType chId,
                                                Cdd_I2c_DataConstPtrType txDataBufferPtr,
                                                Cdd_I2c_DataPtrType rxDataBufferPtr, Cdd_I2c_DataLengthType length)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

    if (CDD_I2C_WRITE == drvObj->chObj[chId].chCfg->direction)
    {
        if (NULL_PTR == txDataBufferPtr)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_TRANS_BUFFER);
            retVal = E_NOT_OK;
        }

        if ((retVal == (Std_ReturnType)E_OK) && (NULL_PTR != rxDataBufferPtr))
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_DIRECTION);
            retVal = E_NOT_OK;
        }
    }

    if ((retVal == (Std_ReturnType)E_OK) && (drvObj->chObj[chId].chCfg->direction == CDD_I2C_READ))
    {
        if (NULL_PTR == rxDataBufferPtr)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_TRANS_BUFFER);
            retVal = E_NOT_OK;
        }

        if ((retVal == (Std_ReturnType)E_OK) && (NULL_PTR != txDataBufferPtr))
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_DIRECTION);
            retVal = E_NOT_OK;
        }
    }

    if ((retVal == (Std_ReturnType)E_OK) && (length == 0U))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_LENGTH);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_I2c.c
 *********************************************************************************************************************/
