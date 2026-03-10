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
 *  File:       Cdd_Ecap.c
 *  Generator:  None
 *
 *  Description: This file contains CDD ECAP driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "Cdd_Ecap_Priv.h"
#include "SchM_Cdd_Ecap.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief AUTOSAR version information check has to match definition in header file */
#if ((CDD_ECAP_AR_RELEASE_MAJOR_VERSION != (4U)) || (CDD_ECAP_AR_RELEASE_MINOR_VERSION != (3U)) || \
     (CDD_ECAP_AR_RELEASE_REVISION_VERSION != (1U)))
#error "Cdd_Ecap: AUTOSAR Version Numbers of Cdd Ecap are different!!"
#endif

/* vendor specific version information check */

#if ((CDD_ECAP_SW_MAJOR_VERSION != (3U)) || (CDD_ECAP_SW_MINOR_VERSION != (1U)))
#error "Cdd_Ecap: Cdd_Ecap.c and Cdd_Ecap.h are not matching!!"
#endif

#if ((CDD_ECAP_CFG_MAJOR_VERSION != (3U)) || (CDD_ECAP_CFG_MINOR_VERSION != (1U)))
#error "Cdd_Ecap: Cdd_Ecap.c and Cdd_Ecap_Cfg.h are not matching!!"
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

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_Ecap_checkInitErrors(const Cdd_Ecap_ConfigType *Cdd_Ecap_ConfigPtr);
static Std_ReturnType Cdd_Ecap_checkSetActivationConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                                 Cdd_Ecap_ActivationType Activation);
static Std_ReturnType Cdd_Ecap_checkStartLevelConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                              Cdd_Ecap_StartLevelType StartLevel);
#if (STD_ON == CDD_ECAP_GET_INPUT_STATE_API)
static Std_ReturnType Cdd_Ecap_checkGetInputStateErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_EDGE_DETECT_API)
static Std_ReturnType Cdd_Ecap_checkEnableEdgeDetectionErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_EDGE_COUNT_API)
static Std_ReturnType Cdd_Ecap_checkEnableEdgeCountErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
static Std_ReturnType Cdd_Ecap_checkStartSignalMeasurementErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkStartTimestampErrors(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType *BufferPtr,
                                                         uint16 BufferSize, uint16 NotifyInterval);
#endif
#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkStopTimestampErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkGetTimestampIndexErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_GET_TIME_ELAPSED_API)
static Std_ReturnType Cdd_Ecap_checkGetTimeElapsedErrors(Cdd_Ecap_ChannelType Channel);
#endif
#if (STD_ON == CDD_ECAP_GET_DUTY_CYCLE_VALUES_API)
static Std_ReturnType Cdd_Ecap_checkGetDutyCycleValuesErrors(Cdd_Ecap_ChannelType    Channel,
                                                             Cdd_Ecap_DutyCycleType *DutyCycleValues);
#endif
#if (STD_ON == CDD_ECAP_HR_API)
static Std_ReturnType Cdd_Ecap_checkHighResolutionScaleFactorErrors(Cdd_Ecap_ChannelType Channel);
static Std_ReturnType Cdd_Ecap_checkHighResolutionTimeStampErrors(Cdd_Ecap_ChannelType Channel);
#endif
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */

#define CDD_ECAP_START_SEC_VAR_INIT_8
#include "Cdd_Ecap_MemMap.h"
/** \brief CDD ECAP driver init status */
volatile VAR(uint8, CDD_ECAP_VAR_INIT) Cdd_Ecap_DrvStatus = CDD_ECAP_STATUS_UNINIT;
#define CDD_ECAP_STOP_SEC_VAR_INIT_8
#include "Cdd_Ecap_MemMap.h"

#define CDD_ECAP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ecap_MemMap.h"
/** \brief CDD ECAP driver object.
 *  Cdd_Ecap_ChObj is not static storage class, as this requires to be accessed by
 *  debug interface provided.
 */
VAR(Cdd_Ecap_ChObjType, CDD_ECAP_VAR_NO_INIT) Cdd_Ecap_ChObj;
#define CDD_ECAP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ecap_MemMap.h"

/* Cdd_Ecap configuration pointer to access driver configuration. */
#define CDD_ECAP_START_SEC_VAR_INIT_PTR
#include "Cdd_Ecap_MemMap.h"
P2CONST(Cdd_Ecap_ConfigType, AUTOMATIC, CDD_ECAP_CONST) Cdd_Ecap_ConfigPtr = NULL_PTR;
#define CDD_ECAP_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CDD_ECAP_START_SEC_CODE
#include "Cdd_Ecap_MemMap.h"

FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_Init(P2CONST(Cdd_Ecap_ConfigType, AUTOMATIC, CDD_ECAP_CFG) ConfigPtr)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkInitErrors(ConfigPtr);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        Cdd_Ecap_ConfigPtr = &CDD_ECAP_INIT_CONFIG_PC;
        /* Set driver object the configuration */
        Cdd_Ecap_CopyConfig(&Cdd_Ecap_ChObj, Cdd_Ecap_ConfigPtr);
        /* Reset(Initialize) Channel object */
        Cdd_Ecap_ResetChObj();
        /* HW Channel Init */
        Cdd_Ecap_HwUnitInit();

        Cdd_Ecap_DrvStatus = CDD_ECAP_STATUS_INIT;
    }

    return;
}

#if (STD_ON == CDD_ECAP_DE_INIT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DeInit(void)
{
    uint8 chIdx;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DEINIT_ID, CDD_ECAP_E_UNINIT);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_DrvStatus = CDD_ECAP_STATUS_UNINIT;
        for (chIdx = 0U; chIdx < CDD_ECAP_HW_CNT; chIdx++)
        {
            /* Check if any channel is running. If yes, cannot call Deinit */
            if (FALSE == Cdd_Ecap_ChObj.chObj[chIdx].IsRunning)
            {
                /* Disable and Clear Interrupts */
                Cdd_Ecap_intrDisable(Cdd_Ecap_ConfigPtr->chCfg[chIdx].base_addr, CDD_ECAP_INT_ALL);
                Cdd_Ecap_intrStatusClear(Cdd_Ecap_ConfigPtr->chCfg[chIdx].base_addr, CDD_ECAP_INT_ALL);
                /* Disable CAP1-CAP4 register loads */
                Cdd_Ecap_captureLoadingDisable(Cdd_Ecap_ConfigPtr->chCfg[chIdx].base_addr);

                Cdd_Ecap_ResetChObj();
            }
            else
            {
                (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DEINIT_ID,
                                      CDD_ECAP_DEINIT_RUNNING_CHANNEL_ID);
            }
        }
    }

    return;
}
#endif /* (STD_ON == CDD_ECAP_DE_INIT_API) */

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableNotification(Cdd_Ecap_ChannelType Channel)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLENOTIFICATION_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLENOTIFICATION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        /* Disable the notification on the given channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        Cdd_Ecap_ChObj.chObj[Channel].NotificationEnabled = FALSE;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableNotification(Cdd_Ecap_ChannelType Channel)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLENOTIFICATION_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLENOTIFICATION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        /* Enables the notification on the given channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        Cdd_Ecap_ChObj.chObj[Channel].NotificationEnabled = TRUE;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_SetActivationCondition(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ActivationType Activation)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkSetActivationConditionErrors(Channel, Activation);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        Cdd_Ecap_ChObj.chObj[Channel].activation_edge = Activation;
#if ((STD_ON == CDD_ECAP_GET_INPUT_STATE_API))
        if (Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode == CDD_ECAP_MODE_SIGNAL_EDGE_DETECT)
        {
            Cdd_Ecap_ChObj.chObj[Channel].InputState = CDD_ECAP_IDLE;
        }
#endif
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_SetStartLevelCondition(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_StartLevelType StartLevel)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkStartLevelConditionErrors(Channel, StartLevel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        Cdd_Ecap_ChObj.chObj[Channel].StartLevel = StartLevel;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

#if (STD_ON == CDD_ECAP_GET_INPUT_STATE_API)
FUNC(Cdd_Ecap_InputStateType, CDD_ECAP_CODE) Cdd_Ecap_GetInputState(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType          retVal   = E_OK;
    Cdd_Ecap_InputStateType retState = CDD_ECAP_IDLE;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkGetInputStateErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        /* Return the current input status for the channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        retState = Cdd_Ecap_ChObj.chObj[Channel].InputState;
        if (retState == CDD_ECAP_ACTIVE)
        {
            Cdd_Ecap_ChObj.chObj[Channel].InputState = CDD_ECAP_IDLE;
        }
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return retState;
}
#endif /* (STD_ON == CDD_ECAP_GET_INPUT_STATE_API) */

#if (STD_ON == CDD_ECAP_EDGE_DETECT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeDetection(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;
    uint32         baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkEnableEdgeDetectionErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        Cdd_Ecap_ChObj.chObj[Channel].IsRunning  = TRUE;
        Cdd_Ecap_ChObj.chObj[Channel].InputState = CDD_ECAP_IDLE;
        if ((Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_RISING_EDGE) ||
            (Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_DELTA_MODE,
                                CDD_ECAP_CEVT1_INT, Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_DELTA_MODE,
                                CDD_ECAP_CEVT1_CEVT2_INT, Channel);
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableEdgeDetection(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        Cdd_Ecap_ChObj.chObj[Channel].IsRunning = FALSE;

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}
#endif /* (STD_ON == CDD_ECAP_EDGE_DETECT_API) */

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_StartTimestamp(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType *BufferPtr, uint16 BufferSize,
                        uint16 NotifyInterval)
{
    Std_ReturnType retVal = E_OK;
    uint32         baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkStartTimestampErrors(Channel, BufferPtr, BufferSize, NotifyInterval);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        Cdd_Ecap_TimeStamp_Init(Channel, BufferPtr, BufferSize, NotifyInterval);
        Cdd_Ecap_ChObj.chObj[Channel].IsRunning = TRUE;
        Cdd_Ecap_ChObj.chObj[Channel].IsActive  = TRUE;
        if ((Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_RISING_EDGE) ||
            (Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_ABSOLUTE_MODE,
                                CDD_ECAP_CEVT1_INT, Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_ABSOLUTE_MODE,
                                CDD_ECAP_CEVT1_CEVT2_INT, Channel);
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StopTimestamp(Cdd_Ecap_ChannelType Channel)
{
    uint32         baseAddr;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkStopTimestampErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        if ((FALSE == Cdd_Ecap_ChObj.chObj[Channel].IsActive) && (FALSE == Cdd_Ecap_ChObj.chObj[Channel].IsRunning))
        {
            (void)Det_ReportRuntimeError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID,
                                         CDD_ECAP_E_NOT_STARTED);
        }
        else
        {
            baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

            SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

            /* Disable and Clear Interrupts */
            Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
            Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
            /* Disable CAP1-CAP4 register loads */
            Cdd_Ecap_captureLoadingDisable(baseAddr);
            Cdd_Ecap_TimeStamp_Clear(Channel);

            Cdd_Ecap_ChObj.chObj[Channel].IsRunning = FALSE;
            Cdd_Ecap_ChObj.chObj[Channel].IsActive  = FALSE;

            SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        }
    }

    return;
}

FUNC(Cdd_Ecap_IndexType, CDD_ECAP_CODE) Cdd_Ecap_GetTimestampIndex(Cdd_Ecap_ChannelType Channel)
{
    Cdd_Ecap_IndexType index  = 0U;
    Std_ReturnType     retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkGetTimestampIndexErrors(Channel);
#endif
    if (((Std_ReturnType)E_OK) == retVal)
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if ((Cdd_Ecap_ChObj.chObj[Channel].IsActive) != (uint32)0U)
        {
            index = Cdd_Ecap_ChObj.chObj[Channel].NextTimeStampIndex;
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return index;
}
#endif /* (STD_ON == CDD_ECAP_TIMESTAMP_API) */

#if (STD_ON == CDD_ECAP_EDGE_COUNT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_ResetEdgeCount(Cdd_Ecap_ChannelType Channel)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_RESETEDGECOUNT_ID, CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_RESETEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_RESETEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        Cdd_Ecap_ChObj.chObj[Channel].EdgeCounter = 0U;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeCount(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;
    uint32         baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkEnableEdgeCountErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        Cdd_Ecap_ChObj.chObj[Channel].IsRunning = TRUE;
        if ((Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_RISING_EDGE) ||
            (Cdd_Ecap_ChObj.chObj[Channel].activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_DELTA_MODE,
                                CDD_ECAP_CEVT1_INT, Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, Cdd_Ecap_ChObj.chObj[Channel].activation_edge, CDD_ECAP_DELTA_MODE,
                                CDD_ECAP_CEVT1_CEVT2_INT, Channel);
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableEdgeCount(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGECOUNT_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        Cdd_Ecap_ChObj.chObj[Channel].IsRunning = FALSE;

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }
}

FUNC(Cdd_Ecap_EdgeNumberType, CDD_ECAP_CODE) Cdd_Ecap_GetEdgeNumbers(Cdd_Ecap_ChannelType Channel)
{
    Cdd_Ecap_EdgeNumberType edgecount = 0U;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETEDGENUMBERS_ID, CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_HW_CNT <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETEDGENUMBERS_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETEDGENUMBERS_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        edgecount = Cdd_Ecap_ChObj.chObj[Channel].EdgeCounter;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return edgecount;
}
#endif /* (STD_ON == CDD_ECAP_EDGE_COUNT_API) */

#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StartSignalMeasurement(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;
    uint32         baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkStartSignalMeasurementErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        Cdd_Ecap_ChObj.chObj[Channel].IsRunning  = TRUE;
        Cdd_Ecap_ChObj.chObj[Channel].InputState = CDD_ECAP_IDLE;
        Cdd_Ecap_SignalMeasurement_Init(Channel);
#if (STD_ON == CDD_ECAP_HR_API)
        if (Cdd_Ecap_ConfigPtr->chCfg[Channel].hr_enable == TRUE)
        {
            /* If HR mode is enabled then the counter should be absolute Mode */
            Cdd_Ecap_ConfigEcap(baseAddr, CDD_ECAP_BOTH_EDGES, CDD_ECAP_ABSOLUTE_MODE, CDD_ECAP_INT_ALL, Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, CDD_ECAP_BOTH_EDGES, CDD_ECAP_DELTA_MODE, CDD_ECAP_INT_ALL, Channel);
        }
#else
        Cdd_Ecap_ConfigEcap(baseAddr, CDD_ECAP_BOTH_EDGES, CDD_ECAP_DELTA_MODE, CDD_ECAP_INT_ALL, Channel);
#endif

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StopSignalMeasurement(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if ((CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if ((CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        baseAddr = Cdd_Ecap_ConfigPtr->chCfg[Channel].base_addr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        Cdd_Ecap_ChObj.chObj[Channel].IsRunning = FALSE;

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return;
}
#endif /* (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API) */

#if (STD_ON == CDD_ECAP_GET_TIME_ELAPSED_API)
FUNC(Cdd_Ecap_ValueType, CDD_ECAP_CODE) Cdd_Ecap_GetTimeElapsed(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType     retVal      = E_OK;
    Cdd_Ecap_ValueType elapsedTime = 0U;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkGetTimeElapsedErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if ((Cdd_Ecap_ConfigPtr->chCfg[Channel].signalMeasurementProperty == CDD_ECAP_PERIOD_TIME) &&
            (Cdd_Ecap_ChObj.chObj[Channel].PeriodAcquired == TRUE))
        {
            elapsedTime                                  = Cdd_Ecap_ChObj.chObj[Channel].Period;
            Cdd_Ecap_ChObj.chObj[Channel].PeriodAcquired = FALSE;
        }

        if ((Cdd_Ecap_ConfigPtr->chCfg[Channel].signalMeasurementProperty == CDD_ECAP_HIGH_TIME) &&
            (Cdd_Ecap_ChObj.chObj[Channel].HighTimeAcquired == TRUE))
        {
            elapsedTime                                    = Cdd_Ecap_ChObj.chObj[Channel].HighTime;
            Cdd_Ecap_ChObj.chObj[Channel].HighTimeAcquired = FALSE;
        }

        if ((Cdd_Ecap_ConfigPtr->chCfg[Channel].signalMeasurementProperty == CDD_ECAP_LOW_TIME) &&
            (Cdd_Ecap_ChObj.chObj[Channel].LowTimeAcquired == TRUE))
        {
            elapsedTime                                   = Cdd_Ecap_ChObj.chObj[Channel].LowTime;
            Cdd_Ecap_ChObj.chObj[Channel].LowTimeAcquired = FALSE;
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return elapsedTime;
}
#endif

#if (STD_ON == CDD_ECAP_GET_DUTY_CYCLE_VALUES_API)
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_GetDutyCycleValues(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_DutyCycleType *DutyCycleValues)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkGetDutyCycleValuesErrors(Channel, DutyCycleValues);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if (Cdd_Ecap_ChObj.chObj[Channel].DutyAcquired == TRUE)
        {
            DutyCycleValues->PeriodTime = Cdd_Ecap_ChObj.chObj[Channel].DutyCycle.PeriodTime;
            DutyCycleValues->ActiveTime = Cdd_Ecap_ChObj.chObj[Channel].DutyCycle.ActiveTime;

            Cdd_Ecap_ChObj.chObj[Channel].DutyAcquired = FALSE;
        }
        else
        {
            DutyCycleValues->PeriodTime = 0U;
            DutyCycleValues->ActiveTime = 0U;
        }

        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (STD_ON == CDD_ECAP_GET_VERSION_INFO_API)
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_ECAP_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
        Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETVERSIONINFO_ID, CDD_ECAP_E_PARAM_VINFO);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = CDD_ECAP_VENDOR_ID;
        VersionInfoPtr->moduleID         = CDD_ECAP_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_ECAP_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_ECAP_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_ECAP_SW_PATCH_VERSION;
    }

    return;
}
#endif /* CDD_ECAP_GET_VERSION_INFO_API*/

/*Periodic register readback API for CDD ECAP*/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_PeriodicReadback(Cdd_Ecap_ChannelType Channel,
                          P2VAR(Cdd_Ecap_PeriodicReadBackDataType, AUTOMATIC, CDD_ECAP_APPL_DATA) ReadBackRegisterdata)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)

    /* Check if the CDD ECAP driver is not initialized and report a DET error. */
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_READBACK_ID, CDD_ECAP_E_UNINIT);
    }
    if ((CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_READBACK_ID, CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        Cdd_Ecap_PeriodicReadbackPrv(Channel, ReadBackRegisterdata);
    }
}

#if (STD_ON == CDD_ECAP_HR_API)
FUNC(Cdd_Ecap_ChannelHrScaleType, CDD_ECAP_CODE) Cdd_Ecap_GetHrScaleFactor(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType              retVal      = E_OK;
    Cdd_Ecap_ChannelHrScaleType scaleFactor = 0;
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkHighResolutionScaleFactorErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        scaleFactor = Cdd_Ecap_ChObj.chObj[Channel].scaleFactor;
    }
    else
    {
        scaleFactor = 0;
    }

    return scaleFactor;
}
FUNC(Cdd_Ecap_ChannelHrScaleType, CDD_ECAP_CODE)
Cdd_Ecap_ConvertHrTimeStampToEcapTimeStamp(Cdd_Ecap_ChannelType Channel, uint32 timeStamp)
{
    uint32                      baseAddr;
    float32                     scaleFactor;
    Cdd_Ecap_ChannelHrScaleType hrTimeStamp = 0.0f;
    Std_ReturnType              retVal      = E_OK;
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkHighResolutionTimeStampErrors(Channel);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        baseAddr    = Cdd_Ecap_ConfigPtr->chCfg[Channel].hr_base_addr;
        scaleFactor = Cdd_Ecap_HRCAP_getScaleFactor(baseAddr, Channel);
        hrTimeStamp = Cdd_Ecap_HRCAP_convertEventTimeStamp(timeStamp, scaleFactor);
    }
    return (Cdd_Ecap_ChannelHrScaleType)hrTimeStamp;
}
#endif
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_Ecap_checkInitErrors(const Cdd_Ecap_ConfigType *Cdd_Ecap_ConfigPtr)
{
    Std_ReturnType retVal = E_OK;

    if (NULL != Cdd_Ecap_ConfigPtr)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_INIT_ID, CDD_ECAP_E_PARAM_POINTER);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_STATUS_INIT == Cdd_Ecap_DrvStatus))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_INIT_ID,
                              CDD_ECAP_E_ALREADY_INITIALIZED);
        retVal = E_NOT_OK;
    }

    return retVal;
}

static Std_ReturnType Cdd_Ecap_checkSetActivationConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                                 Cdd_Ecap_ActivationType Activation)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETACTIVATIONCONDITION_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETACTIVATIONCONDITION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT == Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETACTIVATIONCONDITION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (Activation != CDD_ECAP_RISING_EDGE) &&
        (Activation != CDD_ECAP_FALLING_EDGE) && (Activation != CDD_ECAP_BOTH_EDGES))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETACTIVATIONCONDITION_ID,
                              CDD_ECAP_E_PARAM_ACTIVATION);
        retVal = E_NOT_OK;
    }

    return retVal;
}

static Std_ReturnType Cdd_Ecap_checkStartLevelConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                              Cdd_Ecap_StartLevelType StartLevel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETSTARTLEVELCONDITION_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETSTARTLEVELCONDITION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (StartLevel != CDD_ECAP_START_LEVEL_RISING_EDGE) &&
        (StartLevel != CDD_ECAP_START_LEVEL_FALLING_EDGE))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETSTARTLEVELCONDITION_ID,
                              CDD_ECAP_E_PARAM_START_LEVEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}

#if (STD_ON == CDD_ECAP_GET_INPUT_STATE_API)
static Std_ReturnType Cdd_Ecap_checkGetInputStateErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETINPUTSTATE_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETINPUTSTATE_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETINPUTSTATE_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_EDGE_DETECT_API)
static Std_ReturnType Cdd_Ecap_checkEnableEdgeDetectionErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_EDGE_COUNT_API)
static Std_ReturnType Cdd_Ecap_checkEnableEdgeCountErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
static Std_ReturnType Cdd_Ecap_checkStartSignalMeasurementErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkStartTimestampErrors(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType *BufferPtr,
                                                         uint16 BufferSize, uint16 NotifyInterval)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (NULL_PTR == BufferPtr))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_POINTER);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (0U == BufferSize))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_BUFFER_SIZE);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (Cdd_Ecap_ChObj.chObj[Channel].NotificationEnabled == TRUE) &&
        (0U == NotifyInterval))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_NOTIFY_INTERVAL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkStopTimestampErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static Std_ReturnType Cdd_Ecap_checkGetTimestampIndexErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMESTAMPINDEX_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMESTAMPINDEX_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMESTAMPINDEX_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_GET_DUTY_CYCLE_VALUES_API)
static Std_ReturnType Cdd_Ecap_checkGetDutyCycleValuesErrors(Cdd_Ecap_ChannelType    Channel,
                                                             Cdd_Ecap_DutyCycleType *DutyCycleValues)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETDUTYCYCLEVALUES_ID,
                              CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETDUTYCYCLEVALUES_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETDUTYCYCLEVALUES_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (NULL_PTR == DutyCycleValues))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETDUTYCYCLEVALUES_ID,
                              CDD_ECAP_E_PARAM_POINTER);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_GET_TIME_ELAPSED_API)
static Std_ReturnType Cdd_Ecap_checkGetTimeElapsedErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;

    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMEELAPSED_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMEELAPSED_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ConfigPtr->chCfg[Channel].measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMEELAPSED_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#if (STD_ON == CDD_ECAP_HR_API)
static Std_ReturnType Cdd_Ecap_checkHighResolutionScaleFactorErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRSCALEFACTOR_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRSCALEFACTOR_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (Cdd_Ecap_ConfigPtr->chCfg[Channel].channelId < 4U))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRSCALEFACTOR_ID,
                              CDD_ECAP_E_HR_CHANNEL);

        retVal = E_NOT_OK;
    }

    return retVal;
}

static Std_ReturnType Cdd_Ecap_checkHighResolutionTimeStampErrors(Cdd_Ecap_ChannelType Channel)
{
    Std_ReturnType retVal = E_OK;
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRTIMESTAMP_ID, CDD_ECAP_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_HW_CNT <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (Cdd_Ecap_ConfigPtr->chCfg[Channel].channelId < 4U))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_HRTIMESTAMP_ID, CDD_ECAP_E_HR_CHANNEL);

        retVal = E_NOT_OK;
    }

    return retVal;
}
#endif

#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */

#define CDD_ECAP_STOP_SEC_CODE
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap.c
 *********************************************************************************************************************/
