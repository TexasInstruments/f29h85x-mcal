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
 *  File:       Cdd_Ecap.c
 *  Generator:  None
 *
 *  Description: This file contains CDD ECAP driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "SchM_Cdd_Ecap.h"
#include "Cdd_Ecap.h"
#include "Cdd_Ecap_Priv.h"
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief AUTOSAR version information check has to match definition in header file */
#if ((CDD_ECAP_AR_RELEASE_MAJOR_VERSION != (4U)) || (CDD_ECAP_AR_RELEASE_MINOR_VERSION != (3U)) || \
     (CDD_ECAP_AR_RELEASE_REVISION_VERSION != (1U)))
#error "Cdd_Ecap: AUTOSAR Version Numbers of Cdd Ecap are different!!"
#endif

/** \brief AUTOSAR version information check has to match definition in header file */
#if ((CDD_ECAP_SW_MAJOR_VERSION != (1U)) || (CDD_ECAP_SW_MINOR_VERSION != (0U)))
#error "Cdd_Ecap: Software Version Numbers are inconsistent!!"
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

static void Cdd_Ecap_CheckInit_Internal(uint32 chNum, const Cdd_Ecap_ConfigType *ConfigPtr);

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_Ecap_checkInitErrors(const Cdd_Ecap_ConfigType *Cdd_Ecap_ConfigPtr);
static Std_ReturnType Cdd_Ecap_checkSetActivationConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                                 Cdd_Ecap_ActivationType Activation);
static Std_ReturnType Cdd_Ecap_checkStartLevelConditionErrors(Cdd_Ecap_ChannelType    Channel,
                                                              Cdd_Ecap_StartLevelType StartLevel);
#if (STD_ON == CDD_ECAP_GET_INPUT_STATE_API)
static Std_ReturnType Cdd_Ecap_checkGetInputStateErrors(Cdd_Ecap_ChannelType Channel);
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
VAR(Cdd_Ecap_ChObjType, CDD_ECAP_VAR_NO_INIT) Cdd_Ecap_ChObj[CDD_ECAP_HW_CNT];
#define CDD_ECAP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
    Std_ReturnType             retVal             = E_OK;
    uint32                     chNum              = 0U;
    const Cdd_Ecap_ConfigType *Cdd_Ecap_ConfigPtr = ConfigPtr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    retVal = Cdd_Ecap_checkInitErrors(Cdd_Ecap_ConfigPtr);
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    if (((Std_ReturnType)E_OK) == retVal)
    {
        Cdd_Ecap_ConfigPtr = &CDD_ECAP_INIT_CONFIG_PC;
        for (chNum = 0U; chNum < CDD_ECAP_HW_CNT; chNum++)
        {
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
            if (((Cdd_Ecap_ConfigPtr)->chCfg[chNum].channelId) > (uint32)CDD_ECAP_HW_CNT)
            {
                /* Invalid channel */
                (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_INIT_ID,
                                      CDD_ECAP_E_PARAM_CHANNEL);
            }
            else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
            {
                Cdd_Ecap_CheckInit_Internal(chNum, Cdd_Ecap_ConfigPtr);
            }
        }
        Cdd_Ecap_DrvStatus = CDD_ECAP_STATUS_INIT;
    }

    return;
}

#if (STD_ON == CDD_ECAP_DE_INIT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DeInit(void)
{
    uint32 chIdx;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DEINIT_ID, CDD_ECAP_E_UNINIT);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj;

        Cdd_Ecap_DrvStatus = CDD_ECAP_STATUS_UNINIT;
        for (chIdx = 0U; chIdx < CDD_ECAP_HW_CNT; chIdx++)
        {
            chObj = &Cdd_Ecap_ChObj[chIdx];
            /* Check if any channel is running. If yes, cannot call Deinit */
            if (FALSE == chObj->IsRunning)
            {
                /* Disable and Clear Interrupts */
                Cdd_Ecap_intrDisable(chObj->baseAddr, CDD_ECAP_INT_ALL);
                Cdd_Ecap_intrStatusClear(chObj->baseAddr, CDD_ECAP_INT_ALL);
                /* Disable CAP1-CAP4 register loads */
                Cdd_Ecap_captureLoadingDisable(chObj->baseAddr);

                Cdd_Ecap_ResetChObj(chObj);
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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLENOTIFICATION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        /* Disable the notification on the given channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        chObj->NotificationEnabled = FALSE;
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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLENOTIFICATION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        /* Enables the notification on the given channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        chObj->NotificationEnabled = TRUE;
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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        chObj->activation_edge = Activation;
#if ((CDD_ECAP_EDGE_DETECT_API == STD_ON) || (CDD_ECAP_SIGNAL_MEASUREMENT_API == STD_ON))
        chObj->InputState = CDD_ECAP_IDLE;
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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        chObj->StartLevel = StartLevel;
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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        /* Return the current input status for the channel */
        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        retState = chObj->InputState;
        if (retState == CDD_ECAP_ACTIVE)
        {
            chObj->InputState = CDD_ECAP_IDLE;
        }
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return retState;
}
#endif /* (STD_ON == CDD_ECAP_GET_INPUT_STATE_API) */

#if (STD_ON == CDD_ECAP_EDGE_DETECT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeDetection(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        chObj->IsRunning = TRUE;
        if ((chObj->activation_edge == CDD_ECAP_RISING_EDGE) || (chObj->activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_DELTA_MODE, TRUE, CDD_ECAP_CEVT1_INT,
                                Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_DELTA_MODE, TRUE, CDD_ECAP_CEVT1_CEVT2_INT,
                                Channel);
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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGEDETECTION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        chObj->IsRunning = FALSE;

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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        Cdd_Ecap_TimeStamp_Init(Channel, BufferPtr, BufferSize, NotifyInterval);
        chObj->IsRunning = TRUE;
        chObj->IsActive  = TRUE;
        if ((chObj->activation_edge == CDD_ECAP_RISING_EDGE) || (chObj->activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_ABSOLUTE_MODE, TRUE, CDD_ECAP_CEVT1_INT,
                                Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_ABSOLUTE_MODE, TRUE,
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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        if ((FALSE == chObj->IsActive) && (FALSE == chObj->IsRunning))
        {
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID,
                                         CDD_ECAP_E_NOT_STARTED);
#endif
        }
        else
        {
            baseAddr = chObj->baseAddr;

            SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

            /* Disable and Clear Interrupts */
            Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
            Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
            /* Disable CAP1-CAP4 register loads */
            Cdd_Ecap_captureLoadingDisable(baseAddr);
            Cdd_Ecap_TimeStamp_Clear(Channel);

            chObj->IsRunning = FALSE;
            chObj->IsActive  = FALSE;

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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if ((chObj->IsActive) != (uint32)0U)
        {
            index = chObj->NextTimeStampIndex;
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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_RESETEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_RESETEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        chObj->EdgeCounter = 0U;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }
}

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeCount(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID, CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_ENABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        chObj->IsRunning = TRUE;
        if ((chObj->activation_edge == CDD_ECAP_RISING_EDGE) || (chObj->activation_edge == CDD_ECAP_FALLING_EDGE))
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_DELTA_MODE, TRUE, CDD_ECAP_CEVT1_INT,
                                Channel);
        }
        else
        {
            Cdd_Ecap_ConfigEcap(baseAddr, chObj->activation_edge, CDD_ECAP_DELTA_MODE, TRUE, CDD_ECAP_CEVT1_CEVT2_INT,
                                Channel);
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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_DISABLEEDGECOUNT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        chObj->IsRunning = FALSE;

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
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETEDGENUMBERS_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_EDGE_COUNTER != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETEDGENUMBERS_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
        edgecount = chObj->EdgeCounter;
        SchM_Exit_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();
    }

    return edgecount;
}
#endif /* (STD_ON == CDD_ECAP_EDGE_COUNT_API) */

#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StartSignalMeasurement(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;

#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    if (CDD_ECAP_STATUS_UNINIT == Cdd_Ecap_DrvStatus)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_UNINIT);
    }
    else if (CDD_ECAP_MAX_NUM_CHANNELS <= Channel)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode)
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        chObj->IsRunning  = TRUE;
        chObj->InputState = CDD_ECAP_IDLE;
        Cdd_Ecap_SignalMeasurement_Init(Channel);
        Cdd_Ecap_ConfigEcap(baseAddr, CDD_ECAP_BOTH_EDGES, CDD_ECAP_DELTA_MODE, TRUE, CDD_ECAP_CEVT1_CEVT3_INT,
                            Channel);

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
    else if ((CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else if ((CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPSIGNALMEASUREMENT_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
    }
    else
#endif /* (STD_ON == CDD_ECAP_DEV_ERROR_DETECT) */
    {
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        baseAddr = chObj->baseAddr;

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        /* Disable and Clear Interrupts */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
        /* Disable CAP1-CAP4 register loads */
        Cdd_Ecap_captureLoadingDisable(baseAddr);
        chObj->IsRunning = FALSE;

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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if (chObj->PeriodAcquired == TRUE)
        {
            switch (chObj->chCfg.signalMeasurementProperty)
            {
                case CDD_ECAP_DUTY_CYCLE:
                    elapsedTime = (uint32)(((uint64)chObj->HighTime * 100U) / (uint64)chObj->Period);
                    break;
                case CDD_ECAP_PERIOD_TIME:
                    elapsedTime = chObj->Period;
                    break;
                case CDD_ECAP_HIGH_TIME:
                    elapsedTime = chObj->HighTime;
                    break;
                case CDD_ECAP_LOW_TIME:
                    elapsedTime = chObj->LowTime;
                    break;
                default:
                    elapsedTime = 0U;
                    break;
            }
            chObj->PeriodAcquired = FALSE;
        }
        else
        {
            elapsedTime = 0U;
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
        Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[Channel];

        SchM_Enter_Cdd_Ecap_CDD_ECAP_EXCLUSIVE_AREA_0();

        if (chObj->DutyAcquired == TRUE)
        {
            DutyCycleValues->PeriodTime = chObj->DutyCycle.PeriodTime;
            DutyCycleValues->ActiveTime = chObj->DutyCycle.ActiveTime;

            chObj->DutyAcquired = FALSE;
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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
static void Cdd_Ecap_CheckInit_Internal(uint32 chNum, const Cdd_Ecap_ConfigType *Cdd_Ecap_ConfigPtr)
{
    Cdd_Ecap_ChObjType *chObj = &Cdd_Ecap_ChObj[chNum];

    /* Reset Channel object */
    Cdd_Ecap_ResetChObj(chObj);
    /* Copy the configuration */
    Cdd_Ecap_CopyConfig(chObj, &Cdd_Ecap_ConfigPtr->chCfg[chNum]);
    /* HW Channel Init */
    Cdd_Ecap_HwUnitInit(chObj);

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
    chObj->IsActive = FALSE;
#endif

    return;
}

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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_SETACTIVATIONCONDITION_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT == Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETINPUTSTATE_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_EDGE_DETECT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETINPUTSTATE_ID,
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STARTTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
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
    if ((retVal == (Std_ReturnType)E_OK) && (Cdd_Ecap_ChObj[Channel].NotificationEnabled == TRUE) &&
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_STOPTIMESTAMP_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMESTAMPINDEX_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MODE_TIMESTAMP != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETDUTYCYCLEVALUES_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
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

    if ((retVal == (Std_ReturnType)E_OK) && (CDD_ECAP_MAX_NUM_CHANNELS <= Channel))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMEELAPSED_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
        retVal = E_NOT_OK;
    }

    if ((retVal == (Std_ReturnType)E_OK) &&
        (CDD_ECAP_MODE_SIGNAL_MEASUREMENT != Cdd_Ecap_ChObj[Channel].chCfg.measurementMode))
    {
        (void)Det_ReportError(CDD_ECAP_MODULE_ID, CDD_ECAP_INSTANCE_ID, CDD_ECAP_GETTIMEELAPSED_ID,
                              CDD_ECAP_E_PARAM_CHANNEL);
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
