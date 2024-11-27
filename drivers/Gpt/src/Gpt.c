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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:         Gpt.c
 *  Generator:    None
 *
 *  Description:  This file contains GPT MCAL driver API definitions
 *********************************************************************************************************************/


/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* 
 *Design: MCAL-21953, MCAL-21955, MCAL-22034, MCAL-22035
 */
#include "Gpt.h"
#include "Gpt_Priv.h"
#include "Det.h"
#include "Dem.h"

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
/** \brief GPT Driver initialization variable */
/* 
 *Design: MCAL-23357
 */
#define GPT_START_SEC_VAR_INIT_BOOLEAN
#include "Gpt_MemMap.h"
static VAR(boolean, GPT_VAR_INIT) Gpt_DriverInitialized = FALSE;
#define GPT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Gpt_MemMap.h"

/** \brief GPT Driver gloabal variable to save configs & states of timers and its counters */
/* 
 *Design: MCAL-23358
 */
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
static VAR(Gpt_DriverObjType, VAR_INIT_UNSPECIFIED) Gpt_DrvObj = {0};
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
/*
 *Design: MCAL-21971
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#if (STD_ON == GPT_CFG_VERSION_INFO_API)
FUNC(void, GPT_CODE) Gpt_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "GPT_E_PARAM_POINTER" error */
    if (NULL_PTR == VersionInfoPtr)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_VERSION_INFO, GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16) GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16) GPT_MODULE_ID;
        VersionInfoPtr->instanceID       = (uint8) GPT_INSTANCE_ID;
        VersionInfoPtr->sw_major_version = (uint8) GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8) GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8) GPT_SW_PATCH_VERSION;
    }

    return;
}
#endif


/*
 *Design: MCAL-21972, MCAL-21976, MCAL-21980, MCAL-21979, MCAL-21974, MCAL-21975, MCAL-21977, 
 *Design: MCAL-21973, MCAL-21978, MCAL-21981
 */
FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_CONST) ConfigPtr)
{
    VAR(Gpt_ValueType, AUTOMATIC) loop = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) return_value = E_OK;
    const Gpt_ConfigType *CfgPtr = NULL_PTR;


#if (STD_ON == GPT_PRE_COMPILE_VARIANT)
        /* If the input pointer(CfgPtr) is NULL, use the default pre compile configuration */
        if (NULL_PTR == ConfigPtr)
        {
            CfgPtr = &Gpt_ConfigSetptr;
        }
#else
        if (NULL_PTR != ConfigPtr)
        {
            /* Assigning passed module configuration to Config pointer incase of Post Build variant */
            CfgPtr = ConfigPtr;
        }
#endif /*GPT_PRE_COMPILE_VARIANT*/

    /* Gpt module must not be initialized. Otherwise call the Det with GPT_E_ALREADY_INITIALIZED */
    if (TRUE == Gpt_DriverInitialized)
    {
        #if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_ALREADY_INITIALIZED);
        #endif
    }
    else if (NULL_PTR == CfgPtr)
    {
        #if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_PARAM_POINTER);
        #endif 
    }
    else
    {
        /*
         * When the Gpt_Init is called for the first time then, setting the state of
         * all the GPTs to GPT_CH_UNINITIALIZED
         */
        for(loop = ((Gpt_ValueType)0U); loop<((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); loop++)
        {
            Gpt_DrvObj.Gpt_ChannelState[loop] = GPT_CH_UNINITIALIZED;
        }

        /* Set the index value of all channels to MAX value */
        for(loop = ((Gpt_ValueType)0U); loop<((Gpt_ValueType)GPT_CFG_MAX_CHANNELS); loop++)
        {
            Gpt_DrvObj.Gpt_Lut_Channel_Index[loop] = GPT_MAX_32BIT_VAL;
        }
        /* Copy Config Pointer */
        Gpt_DrvObj.Gpt_CfgPtr = CfgPtr;

        for(loop = ((Gpt_ValueType)0U); ((loop<((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS)) && (return_value == E_OK)); loop++)        {
            /* If the channel is invalid, report to DET with "GPT_E_PARAM_CHANNEL" error. */
            if (Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop].Gpt_ChannelId >= ((Gpt_ChannelType)GPT_CFG_MAX_CHANNELS))
            {
                (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_PARAM_CHANNEL);
                return_value = E_NOT_OK;
            }
        }

        if(E_OK == return_value)
        {
                for(loop = ((Gpt_ValueType)0U); loop<((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); loop++)
                {
                /* Initialize the GPT channel. */
                (void) Gpt_InitPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop]));

                /* Disable the interrupts */
                (void) Gpt_DisableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop]));

                /* Set the channel State to "Initialized". */
                Gpt_DrvObj.Gpt_ChannelState[loop] = GPT_CH_INITIALIZED;

                /* Set the channel notification State to "Disabled". */
                Gpt_DrvObj.Gpt_NotificationState[loop] = GPT_NOTIF_DISABLED;

                /* Set the period counter at stop state to 0 */
                Gpt_DrvObj.Gpt_StopStatePrdCounter[loop] = ((Gpt_ValueType)0U);

                /* Set the current counter at stop state to 0 */
                Gpt_DrvObj.Gpt_StopStateCurCounter[loop] = ((Gpt_ValueType)0U);

                /* Set the index(loop) value to the current channel */
                Gpt_DrvObj.Gpt_Lut_Channel_Index[Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop].Gpt_ChannelId] = loop;
                }
            /* Save the Gpt_DrvObj address into a pointer in Gpt_Priv.c */
            Gpt_SetDriverObjPtr(&Gpt_DrvObj);

            /* Save the GPT driver as initialized. */
            Gpt_DriverInitialized = TRUE;
        }
    }
    return;
}

/*
 *Design: MCAL-21988, MCAL-21983, MCAL-21985, MCAL-21982, MCAL-21984, MCAL-21989, MCAL-21987, MCAL-21986
 */
#if (STD_ON == GPT_CFG_DEINIT_API)
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    VAR(Gpt_ValueType, AUTOMATIC) loop = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) return_value = E_OK;
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, the function shall raise the error GPT_E_UNINIT */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,  GPT_SID_DEINIT, GPT_E_UNINIT);
    }
    else
#endif
    {
        /* Iterate through the configured list. */
        for (loop = ((Gpt_ValueType)0U); ((loop<((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS)) && (return_value == E_OK)); loop++)        {
            /* If any timer channel is in state "running", report to DET with "GPT_E_BUSY" error. */
            if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[loop])
            {
                (void) Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DEINIT, GPT_E_BUSY);

                return_value = E_NOT_OK;
            }
        }

        if(E_OK == return_value)
        {
            /* Iterate through the configured list. */
            for (loop = ((Gpt_ValueType)0U); loop<((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); loop++)
            {
                /* GPT can be deinitialized only in states other than GPT_CH_RUNNING and GPT_CH_UNINITIALIZED */
                if (GPT_CH_UNINITIALIZED != Gpt_DrvObj.Gpt_ChannelState[loop])
                {

                    /* Deinitialize the hardware used by the GPT driver to the power on reset state. */
                    Gpt_DeInitPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop]));

                    /* Disable the interrupts */
                    Gpt_DisableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[loop]));

                    /* Set the channel State to 'Uninitialized'. */
                    Gpt_DrvObj.Gpt_ChannelState[loop] = GPT_CH_UNINITIALIZED;

                    /* Set the channel notification state to 'Disabled'. */
                    Gpt_DrvObj.Gpt_NotificationState[loop] = GPT_NOTIF_DISABLED;

                }
                else{
                    /* Do Nothing */
                }
            }
            Gpt_DriverInitialized = FALSE;
        }
    }
    return;
}
#endif

/*
 *Design: MCAL-21993, MCAL-21996, MCAL-21994, MCAL-21992, MCAL-21990, MCAL-21991, MCAL-21997, MCAL-21995, 
 *Design: MCAL-21998, MCAL-21956
 */
#if (STD_ON == GPT_CFG_TIME_ELAPSED_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ret_val = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if(FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_ELAPSED, GPT_E_UNINIT);
    }
    /* If channel is not a valid configured channel, the function shall raise the error GPT_E_PARAM_CHANNEL. */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_ELAPSED, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Check for channel state */
        switch(Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            case GPT_CH_INITIALIZED:
            {
                /* Return the time elapsed as 0 as per AUTOSAR when timer channel is in INIT state */
                ret_val = ((Gpt_ValueType)0U);
                break;
            }
            case GPT_CH_RUNNING:
            {
                /* Return the time difference between period register and current counter register of the channel. */
                ret_val = Gpt_GetPrdCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index])) - \
                Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
                break;
            }
            case GPT_CH_STOPPED:
            {
               /* Return the time diff between period and counter register which are saved when timer is topped */
                if(Gpt_DrvObj.Gpt_StopStatePrdCounter[ch_index]>=Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index]){
                    ret_val = Gpt_DrvObj.Gpt_StopStatePrdCounter[ch_index] - Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index];
                }
                else{
                    ret_val = ((Gpt_ValueType)0U);
                }
                break;
            }
            case GPT_CH_EXPIRED: 
            {
                /* Read & return the period register of the channel. */
                ret_val = Gpt_GetPrdCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret_val;
}
#endif


/*
 *Design: MCAL-22006, MCAL-22000, MCAL-22005, MCAL-22002, MCAL-22004, MCAL-22003, MCAL-22001, MCAL-21999
 */
#if (STD_ON == GPT_CFG_TIME_REMAINING_API)

FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ret_val = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if(FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_REMAINING, GPT_E_UNINIT);
    }
    /* If channel is not a valid configured channel, report to DET with GPT_E_PARAM_CHANNEL" error. */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_REMAINING, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Check for channel state */
        switch(Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            case GPT_CH_INITIALIZED:
            {
                /* Return the time remaining as 0 as per AUTOSAR when timer channel is in INIT state */
                ret_val = ((Gpt_ValueType)0U);
                break;
            }
            case GPT_CH_RUNNING:
            {
                /* Read & return the counter register of the channel. */
                ret_val = Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
                break;
            }
            case GPT_CH_STOPPED:
            {
                /* Return the counter value which is saved when timer timer is stopped. */
                ret_val = Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index];
                break;
            }
            case GPT_CH_EXPIRED:
            {
                /* Return the time remaining as 0 as per AUTOSAR when timer channel is in EXPIRED state */
                ret_val = ((Gpt_ValueType)0U);
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret_val;
}
#endif

/*
 *Design: MCAL-22009, MCAL-22012, MCAL-22010, MCAL-22007, MCAL-22013, MCAL-22011, MCAL-22008, MCAL-22014 
 */
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_UNINIT);
    }
    /* If channel is not a valid configured channel, report to DET with GPT_E_PARAM_CHANNEL" error. */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_PARAM_CHANNEL);
    }
    /* If count value is 0, report to DET with GPT_E_PARAM_VALUE" error. */
    else if ((Gpt_ValueType)0U == Value)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_PARAM_VALUE);
    }
    else
#endif
    {
        /* If the channel is already in running state, report DET with "GPT_E_BUSY" error. */
        if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            (void) Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_BUSY);
        }
        else
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Start counting.  */
            Gpt_StartTimerPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]), Value);

            /* Set the channel state to "Running". */
            Gpt_DrvObj.Gpt_ChannelState[ch_index] = GPT_CH_RUNNING;

            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return;
}


/*
 *Design: MCAL-22017, MCAL-22015, MCAL-22020, MCAL-22018, MCAL-22016, MCAL-22019, MCAL-22021
 */
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_STOP_TIMER, GPT_E_UNINIT);
    }
    /* If the requested channel is not a valid configured channel, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_STOP_TIMER, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Check whether timer channel is in RUNNING state or not */
        if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();
            
            /* Stop the timer. */
            Gpt_StopTimerPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            /*  Save the counter & period values when the timer is stopped */
            Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index] = \
                    Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
            Gpt_DrvObj.Gpt_StopStatePrdCounter[ch_index] = \
                    Gpt_GetPrdCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            /* Set the channel state to "Stopped". */
            Gpt_DrvObj.Gpt_ChannelState[ch_index] = GPT_CH_STOPPED;

            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }

    return;
}

/*
 *Design: MCAL-22024, MCAL-22022, MCAL-22027, MCAL-22023, MCAL-22025, MCAL-22026 
 */
#if (STD_ON == GPT_CFG_NOTIFICATION_API)
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_ENABLE_NOTIFY, GPT_E_UNINIT);
    }
    /* If the requested channel is not a valid configured channel, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    /* OR */
    /* If the notification call pointer is NULL, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    else if ((GPT_MAX_32BIT_VAL == ch_index) || (NULL_PTR == Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction))
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_ENABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        if(GPT_CH_UNINITIALIZED != Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Enable the interrupt */
            Gpt_EnableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            /* Set the channel notification state to "Enable". */
            Gpt_DrvObj.Gpt_NotificationState[ch_index] = GPT_NOTIF_ENABLED;

            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }

    return;
}
#endif


/*
 *Design: MCAL-22033, MCAL-22032, MCAL-22031, MCAL-22029, MCAL-22030, MCAL-22028     
 */
#if (STD_ON == GPT_CFG_NOTIFICATION_API)
FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void) Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DISABLE_NOTIFY, GPT_E_UNINIT);
    }
    /* If the requested channel is not a valid configured channel, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    /* OR */
    /* If the notification call pointer is NULL, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    else if ((GPT_MAX_32BIT_VAL == ch_index) || (NULL_PTR == Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction))
    {
        (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DISABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        if(GPT_CH_UNINITIALIZED != Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Disable the timer interrupt */
            Gpt_DisableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            /* Set the channel notification state to "Disable". */
            Gpt_DrvObj.Gpt_NotificationState[ch_index] = GPT_NOTIF_DISABLED;

            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }

    return;
}
#endif



#if (STD_ON == GPT_CFG_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{
    (void) Mode;

    return;
}

FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    (void) Channel;

    return;
}

FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    (void) Channel;

    return;
}

FUNC(void, GPT_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    (void) WakeupSource;

    return;
}
#endif

FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType) E_NOT_OK;
    (void) PredefTimer;
    (void) *TimeValuePtr;

    return retVal;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Gpt.c
 *********************************************************************************************************************/
