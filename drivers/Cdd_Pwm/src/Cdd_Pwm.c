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
 *  File:       Cdd_Pwm
 *  Generator:  None
 *
 *  Description: This file contains CDD PWM driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Priv.h"
#include "SchM_Cdd_Pwm.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_PWM_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_PWM_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_PWM_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version of CDD_PWM is incorrect"
#endif

/* vendor specific version information check */
#if ((CDD_PWM_SW_MAJOR_VERSION != (1U)) || (CDD_PWM_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Pwm.c and Cdd_Pwm.h are not matching!"
#endif

#if ((CDD_PWM_CFG_MAJOR_VERSION != (1U)) || (CDD_PWM_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Pwm.c and Cdd_Pwm_Cfg.h are not matching!"
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

/* Cdd_Pwm Driver initialization variable */
#define CDD_PWM_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Pwm_MemMap.h"
static VAR(boolean,CDD_PWM_VAR_INIT) Cdd_Pwm_IsInitialized = FALSE;
#define CDD_PWM_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm driver object to store status of PWM instances and channels */
#define CDD_PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"
static VAR(Cdd_Pwm_DriverObjType,CDD_PWM_VAR_FAST_INIT) Cdd_Pwm_DrvObj;
#define CDD_PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm configuration pointer to access driver configuration. */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2CONST(Cdd_Pwm_ConfigType,AUTOMATIC,CDD_PWM_CONST) Cdd_Pwm_CfgPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED) && (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
/** \brief Cdd_Pwm_Notification_DetCheck - This API will report DET error for the notification related APIs
 * 
 * \param[in] InstanceId    Numeric ID of the PWM instance
 * \param[out] ApiId        Service ID of the API
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_PWM_CODE) \
    Cdd_Pwm_Notification_DetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId, VAR(uint8,AUTOMATIC) ApiId);

/** \brief Cdd_Pwm_EnableNotification_DetChecks - This API will report DET error for the notification related APIs
 * 
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[out] Channel  Channel notification type
 * \param[in] Notification Notification type of the instance
 * \param[out] IntEvtCount  Count of number of events to be generated before generating an interrupt 
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) \
    Cdd_Pwm_EnableNotification_DetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
    VAR(Cdd_Pwm_NotificationChannelType,AUTOMATIC) Channel, VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) Notification,\
                    VAR(uint8,AUTOMATIC) IntEvtCount);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType,AUTOMATIC, CDD_PWM_CFG) CfgPtr)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if(Cdd_Pwm_IsInitialized != FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INIT,CDD_PWM_E_ALREADY_INITIALIZED);
    }
    #if(STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
    else if (CfgPtr != NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR for pre-compile build variant */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INIT,CDD_PWM_E_PARAM_POINTER);
    }
    #else
    else if (CfgPtr == NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is NULL_PTR for non pre-compile build variant*/
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INIT,CDD_PWM_E_PARAM_POINTER);
    }
    #endif
    else
#endif
    {
        Cdd_Pwm_CfgPtr = &CDD_PWM_CONFIG_PC;
        Cdd_Pwm_SetDrvObj(&Cdd_Pwm_DrvObj,Cdd_Pwm_CfgPtr);
        /* Initialize the driver object */
        Cdd_Pwm_DrvObjInit();
        /* Initialize the PWM HW Unit */
        Cdd_Pwm_HwUnitInit();
        /* Update the initialized flag to true */
        Cdd_Pwm_IsInitialized = TRUE;
    }
}

#if (STD_ON == CDD_PWM_VERSION_INFO_API)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_PWM_DATA) VersionInfo)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* If VersionInfo is NULL */
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VERSION_INFO,\
                                CDD_PWM_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = CDD_PWM_VENDOR_ID;
        VersionInfo->moduleID         = CDD_PWM_MODULE_ID ;
        VersionInfo->instanceID       = CDD_PWM_INSTANCE_ID ;
        VersionInfo->sw_major_version = (uint8)CDD_PWM_SW_MAJOR_VERSION ;
        VersionInfo->sw_minor_version = (uint8)CDD_PWM_SW_MINOR_VERSION ;
        VersionInfo->sw_patch_version = (uint8)CDD_PWM_SW_PATCH_VERSION ;
    }
}
#endif

#if (STD_ON == CDD_PWM_DEINIT_API)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DeInit(void)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DEINIT,CDD_PWM_E_UNINIT);
    }
    else
#endif
    {
        /* Deinitialize the PWM HW Unit */
        Cdd_Pwm_HwUnitDeinit();
        Cdd_Pwm_IsInitialized = FALSE;
    }
    return;
}
#endif  

#if (STD_ON == CDD_PWM_SET_DUTY_CYCLE_API)
/* Service to set the duty cycle of the PWM channel */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDutyCycle(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                    VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_Init */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,\
                                CDD_PWM_E_UNINIT);
    }
    else if (ChannelNumber >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,\
                                CDD_PWM_E_INVALID_ID); 
    }
    else if (DutyCycle > CDD_PWM_MAX_DUTY_CYCLE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,\
                                CDD_PWM_E_INVALID_DUTY_CYCLE); 
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_UpdateDutyCycle(ChannelNumber,DutyCycle);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (CDD_PWM_SET_PERIOD_API == STD_ON)
/* Service to set the period of the PWM hardware unit/instance */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetPeriod(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                            VAR(Cdd_Pwm_PeriodType,AUTOMATIC) Period)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PERIOD,CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PERIOD,CDD_PWM_E_INVALID_ID);
    }
    else if (Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].channelclass != CDD_PWM_VARIABLE_PERIOD)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PERIOD,CDD_PWM_E_CHANNEL_CLASS);
    }
    else 
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        /* Update the period of the PWM instance */
        Cdd_Pwm_UpdatePeriod(InstanceId,Period);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (CDD_PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/* Service to get the set the PWM channel output to IDLE */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetOutputToIdle(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_OUTPUT_TO_IDLE,CDD_PWM_E_UNINIT);
    }
    else if (ChannelNumber >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,\
                                                        CDD_PWM_SID_SET_OUTPUT_TO_IDLE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_SetIdleOutput(ChannelNumber);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
/* Function to check for the development errors in the notification APIs */
static FUNC(Std_ReturnType, CDD_PWM_CODE) \
    Cdd_Pwm_Notification_DetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId, VAR(uint8,AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_ID);
    }
    else if((Cdd_Pwm_NotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].notification)
    {
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_NOTIF_CAPABILITY);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

/* Function to check for the development errors in the notification APIs */
static FUNC(Std_ReturnType,CDD_PWM_CODE) \
    Cdd_Pwm_EnableNotification_DetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
    VAR(Cdd_Pwm_NotificationChannelType,AUTOMATIC) Channel, VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) Notification,\
                    VAR(uint8,AUTOMATIC) IntEvtCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    uint8 channel_id = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].startchannel;
    if (Notification >= CDD_PWM_EDGE_NONE)
    {
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,\
                                                                        CDD_PWM_E_INVALID_NOTIFICATION);
    }
    else if ((IntEvtCount > CDD_PWM_INTEVT_COUNT) || (0U == IntEvtCount))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,\
                                                                        CDD_PWM_E_INVALID_EVENT_COUNT);
    }
    else if((CDD_PWM_NONE <= Channel) || (((Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].lastchannel - channel_id) == 0U) && \
            ((CDD_PWM_BOTH_A_AND_B == Channel) || ((CDD_PWM_CHANNEL_A == Channel) && \
            (CDD_PWM_OUTPUT_B == Cdd_Pwm_CfgPtr->channelcfg[channel_id].outputchannel)) || \
            ((CDD_PWM_CHANNEL_B == Channel) && \
                    (CDD_PWM_OUTPUT_A == Cdd_Pwm_CfgPtr->channelcfg[channel_id].outputchannel)))))
    {
        /* Report DET error when
         *  1) Requested notification channel type is CDD_PWM_NONE or greater than ID of the CDD_PWM_NONE enum value
         *  2) Requested notification channel type is CDD_PWM_BOTH_A_AND_B but only one channel is 
         *      configured for the PWM instance.
         *  3) Requested notification channel type is CDD_PWM_CHANNEL_A but only channel B is 
         *      configured for the PWM instance.
         *  4) Requested notification channel type is CDD_PWM_CHANNEL_B but only channel A is 
         *      configured for the PWM instance.
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,\
                                                                    CDD_PWM_E_INVALID_CHANNEL_NOTIFICATION);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

#endif

/* Service to enable the notification of the channel */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                VAR(Cdd_Pwm_NotificationChannelType,AUTOMATIC) Channel,\
                            VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) Notification,VAR(uint8,AUTOMATIC) IntEvtCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_Notification_DetCheck(InstanceId,CDD_PWM_SID_ENABLE_NOTIFICATION);

    if(E_OK == return_value)
    {
        return_value = Cdd_Pwm_EnableNotification_DetCheck(InstanceId,Channel,Notification,IntEvtCount);
    }
    else
    {
        /* Do nothing */
    }

    if(return_value == E_OK)
#endif
    {
        if(Cdd_Pwm_DrvObj.hwunitobj[InstanceId].channel_notification == CDD_PWM_NONE)
        {
            SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
            /* Enable notification for the channel output */
            Cdd_Pwm_NotificationEnable(InstanceId,Channel,Notification,IntEvtCount);
            SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Notification is already enabled disable it first before requesting it again for another channel */
            Det_ReportRuntimeError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,\
                                                                                CDD_PWM_E_NOTIF_ALREADY_ENABLED);
        }
    }
}

/* Service to disable the notification of the channel */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                                    VAR(Cdd_Pwm_NotificationChannelType,AUTOMATIC) Channel)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_Notification_DetCheck(InstanceId,CDD_PWM_SID_DISABLE_NOTIFICATION);
    if((return_value == E_OK) && ((CDD_PWM_NONE <= Channel)))
    {
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_NOTIFICATION,\
                                            CDD_PWM_E_INVALID_CHANNEL_NOTIFICATION);
        return_value = E_NOT_OK;
    }
    else
    {
        /* This means either a det error is reported in the Cdd_Pwm_Notification_DetCheck function or
         * no det error is reported
         */
    }

    if(return_value == E_OK)
#endif
    {
        if(Cdd_Pwm_DrvObj.hwunitobj[InstanceId].channel_notification == Channel)
        {
            /* Notification should be disabled for the instance before enabling again for another channel type */
            SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
            Cdd_Pwm_NotificationDisable(InstanceId);
            SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Report Det runtime error that the notification for the channel should be disabled for the channel 
             * which was enabled with EnableNotification API 
             */
            Det_ReportRuntimeError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_NOTIFICATION,\
                                                                                CDD_PWM_E_NOTIF_ALREADY_ENABLED);
        }
    }
}
#endif 


#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm.c
 *********************************************************************************************************************/
