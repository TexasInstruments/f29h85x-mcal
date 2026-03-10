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
/*
 *  AUTOSAR version information check has to match definition in header file
 */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (GPT_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (GPT_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "GPT: AUTOSAR Version Numbers of GPT are different"
#endif

/* vendor specific version information is BCD coded */
#if ((GPT_SW_MAJOR_VERSION != (2U)) || (GPT_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Gpt.c and Gpt.h are inconsistent!"
#endif

#if ((GPT_CFG_MAJOR_VERSION != (2U)) || (GPT_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Gpt.c and Gpt_Cfg.h are inconsistent!"
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

#if (STD_ON == GPT_CFG_DEINIT_API)
/** \brief Gpt_DeinitChannelPriv : De-initializes the GPT module.
 *
 * This service deinitializes the Gpt driver to the power on reset state.
 * The Gpt driver state is changed to "Uninitialized" state".
 * All the configuration registers are cleared to stop the timer channels.
 * API will disable all interrupts.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, GPT_CODE) Gpt_DeinitChannelPriv(void);
#endif

/** \brief Gpt_SetChannelToRunningPriv : Starts a timer channel
 *
 * \param[in] TargetTimeValue Target time in number of ticks.
 * \param[in] Channel_Index Pointer to populate the index of channel present in config.
 * \pre Gpt Driver must be initialized.
 * \post Postconditions
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, GPT_CODE) Gpt_SetChannelToRunningPriv(Gpt_ValueType TargetTimeValue, Gpt_ValueType Channel_Index);

#if (STD_ON == GPT_CFG_TIME_ELAPSED_API)
/** \brief Returns the time elapsed for a given channel.
 *
 * \param[in] Channel_Index Pointer to populate the index of channel present in config.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return Returns the time already elapsed.
 * \retval Value of the type uint32
 *
 *********************************************************************************************************************/
static FUNC(uint32, GPT_CODE) Gpt_ChannelStateCheckPriv(Gpt_ValueType Channel_Index);
#endif

/** \brief  Initializes the Gpt module.
 *
 * This service initializes all the configured Gpt channels. This will set the
 * state of the each channel to "Initialized".
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, GPT_CODE) Gpt_ConfigureInitPriv(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/** \brief Gpt_InitDet : checks the configuration data of Gpt Module is valid to initialise or not.
 *
 *
 * \param[in] Cfg_Ptr Pointer to the configuration data
 * \pre None
 * \post None
 * \return returns if Gpt module is intialised or not
 * \retval E_Ok-If Gpt module is not initialized.
 * \retval E_NOT_Ok- If Gpt module is initialized.
 *
 *********************************************************************************************************************/
static inline FUNC(uint32, GPT_CODE) Gpt_InitDet(const Gpt_ConfigType* Cfg_Ptr);

/** \brief Gpt_SetChannelsToUnintializedPriv : Sets the state of all the GPTs to
 *GPT_CH_UNINITIALIZED.
 *
 *
 * \param[in] GptDrvObj Pointer to the GPT driver object
 * \param[in] Cfg_Ptr Pointer to the configuration data
 * \pre None
 * \post None
 * \return returns the channel is valid or invalid.
 * \retval E_Ok-If the channel is valid.
 * \retval E_NOT_Ok-If the channel is invalid.
 *
 *********************************************************************************************************************/
static inline FUNC(uint32, GPT_CODE)
    Gpt_SetChannelsToUnintializedPriv(Gpt_DriverObjType* GptDrvObj, const Gpt_ConfigType* Cfg_Ptr);

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
/*
 *Design: MCAL-21971
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#if (STD_ON == GPT_CFG_VERSION_INFO_API)
FUNC(void, GPT_CODE)
Gpt_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "GPT_E_PARAM_POINTER"
     * error */
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_VERSION_INFO, GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16)GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16)GPT_MODULE_ID;
        VersionInfoPtr->instanceID       = (uint8)GPT_INSTANCE_ID;
        VersionInfoPtr->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
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
    VAR(Gpt_ValueType, AUTOMATIC) return_value           = E_OK;
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_CONST) CfgPtr = NULL_PTR;

#if (STD_ON == GPT_PRE_COMPILE_VARIANT)
    /* If the input pointer(CfgPtr) is NULL, use the default pre compile configuration */
    if (NULL_PTR == ConfigPtr)
    {
        CfgPtr = &GPT_INIT_CONFIG_PC;
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        CfgPtr = ConfigPtr;
    }
#endif /*GPT_PRE_COMPILE_VARIANT*/

    if (E_OK == Gpt_InitDet(CfgPtr))
    {
        /*
         * When the Gpt_Init is called for the first time then, setting the state of
         * all the GPTs to GPT_CH_UNINITIALIZED
         */
        return_value = Gpt_SetChannelsToUnintializedPriv(&Gpt_DrvObj, CfgPtr);

        if (E_OK == return_value)
        {
            Gpt_ConfigureInitPriv();

            /* Save the Gpt_DrvObj address into a pointer in Gpt_Priv.c */
            Gpt_SetDriverObjPtr(&Gpt_DrvObj);

            /* Save the GPT driver as initialized. */
            Gpt_DriverInitialized = TRUE;
        }
    }
    return;
}

/*
 *Design: MCAL-21988, MCAL-21983, MCAL-21985, MCAL-21982, MCAL-21984, MCAL-21989, MCAL-21987,
 *MCAL-21986
 */
#if (STD_ON == GPT_CFG_DEINIT_API)
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    VAR(Gpt_ValueType, AUTOMATIC) loop         = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) return_value = E_OK;
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, the function shall raise the error GPT_E_UNINIT */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DEINIT, GPT_E_UNINIT);
    }
    else
#endif
    {
        /* Iterate through the configured list. */
        for (loop = ((Gpt_ValueType)0U); (loop < ((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS)); loop++)
        {
            /* If any timer channel is in state "running", report to DET with "GPT_E_BUSY" error. */
            if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[loop])
            {
                (void)Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DEINIT, GPT_E_BUSY);

                return_value = E_NOT_OK;
                break;
            }
        }

        if (E_OK == return_value)
        {
            Gpt_DeinitChannelPriv();

            Gpt_DriverInitialized = FALSE;
        }
    }
    return;
}
#endif

/*
 *Design: MCAL-21993, MCAL-21996, MCAL-21994, MCAL-21992, MCAL-21990, MCAL-21991, MCAL-21997,
 *MCAL-21995, Design: MCAL-21998, MCAL-21956
 */
#if (STD_ON == GPT_CFG_TIME_ELAPSED_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ret_val  = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_ELAPSED, GPT_E_UNINIT);
#endif
    }
    /* If channel is not a valid configured channel, the function shall raise the error
     * GPT_E_PARAM_CHANNEL. */
    else if (GPT_CFG_NO_OF_CHANNELS <= ch_index)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_ELAPSED, GPT_E_PARAM_CHANNEL);
#endif
    }
    else
    {
        ret_val = Gpt_ChannelStateCheckPriv(ch_index);
    }

    return ret_val;
}
#endif

/*
 *Design: MCAL-22006, MCAL-22000, MCAL-22005, MCAL-22002, MCAL-22004, MCAL-22003, MCAL-22001,
 *MCAL-21999
 */
#if (STD_ON == GPT_CFG_TIME_REMAINING_API)

FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ret_val  = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_REMAINING, GPT_E_UNINIT);
#endif
    }
    /* If channel is not a valid configured channel, report to DET with GPT_E_PARAM_CHANNEL" error.
     */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_GET_TIME_REMAINING, GPT_E_PARAM_CHANNEL);
#endif
    }
    else
    {
        /* Check for channel state */
        switch (Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            case GPT_CH_INITIALIZED:
                /* Return the time remaining as 0 as per AUTOSAR when timer channel is in INIT state
                 */
                ret_val = ((Gpt_ValueType)0U);
                break;
            case GPT_CH_RUNNING:
                /* Read & return the counter register of the channel. */
                ret_val = Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
                break;
            case GPT_CH_STOPPED:
                /* Return the counter value which is saved when timer timer is stopped. */
                ret_val = Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index];
                break;
            case GPT_CH_EXPIRED:
                /* Return the time remaining as 0 as per AUTOSAR when timer channel is in EXPIRED
                 * state */
                ret_val = ((Gpt_ValueType)0U);
                break;
            /* TI_COVERAGE_GAP_START [Branch/Line Gap] All the states of the channel are already
               added in Switch hence this default case can't be validated. */
            default:
                break;
                /* TI_COVERAGE_GAP_STOP*/
        }
    }

    return ret_val;
}
#endif

/*
 *Design: MCAL-22009, MCAL-22012, MCAL-22010, MCAL-22007, MCAL-22013, MCAL-22011, MCAL-22008,
 *MCAL-22014
 */
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_UNINIT);
    }
    /* If channel is not a valid configured channel, report to DET with GPT_E_PARAM_CHANNEL" error.
     */
    else if (GPT_CFG_MAX_CHANNELS <= ch_index)
    {
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_PARAM_CHANNEL);
    }
    /* If count value is 0, report to DET with GPT_E_PARAM_VALUE" error. */
    else if ((Gpt_ValueType)0U == Value)
    {
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_PARAM_VALUE);
    }
    else
#endif
    {
        Gpt_SetChannelToRunningPriv(Value, ch_index);
    }
    return;
}

/*
 *Design: MCAL-22017, MCAL-22015, MCAL-22020, MCAL-22018, MCAL-22016, MCAL-22019, MCAL-22021
 */
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) ch_index = GPT_MAX_32BIT_VAL;

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_STOP_TIMER, GPT_E_UNINIT);
#endif
    }
    /* If the requested channel is not a valid configured channel, report to DET with
     * "GPT_E_PARAM_CHANNEL" error. */
    else if (GPT_MAX_32BIT_VAL == ch_index)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_STOP_TIMER, GPT_E_PARAM_CHANNEL);
#endif
    }
    else
    {
        /* Check whether timer channel is in RUNNING state or not */
        if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[ch_index])
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Stop the timer. */
            Gpt_StopTimerPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));

            /*  Save the counter & period values when the timer is stopped */
            Gpt_DrvObj.Gpt_StopStateCurCounter[ch_index] =
                Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index]));
            Gpt_DrvObj.Gpt_StopStatePrdCounter[ch_index] =
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

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_ENABLE_NOTIFY, GPT_E_UNINIT);
#endif
    }
    /* If the requested channel is not a valid configured channel, report to DET with
     * "GPT_E_PARAM_CHANNEL" error. */
    /* OR */
    /* If the notification call pointer is NULL, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    else if ((GPT_MAX_32BIT_VAL == ch_index) ||
             (NULL_PTR == Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction))
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_ENABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
#endif
    }
    else
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

    (void)Gpt_GetChIdxPriv(&Gpt_DrvObj, Channel, &ch_index);
    /* If the driver is not initialized, report to DET with "GPT_E_UNINIT" error. */
    if (FALSE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DISABLE_NOTIFY, GPT_E_UNINIT);
#endif
    }
    /* If the requested channel is not a valid configured channel, report to DET with
     * "GPT_E_PARAM_CHANNEL" error. */
    /* OR */
    /* If the notification call pointer is NULL, report to DET with "GPT_E_PARAM_CHANNEL" error. */
    else if ((GPT_MAX_32BIT_VAL == ch_index) ||
             (NULL_PTR == Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[ch_index].Gpt_PtrNotifyFunction))
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_DISABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
#endif
    }
    else
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

    return;
}
#endif

#if (STD_ON == GPT_CFG_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{
    (void)Mode;

    return;
}

FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    (void)Channel;

    return;
}

FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    (void)Channel;

    return;
}

FUNC(void, GPT_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;

    return;
}
#endif

FUNC(Std_ReturnType, GPT_CODE)
Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    (void)PredefTimer;
    (void)*TimeValuePtr;

    return retVal;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#if (STD_ON == GPT_CFG_DEINIT_API)
/*
 *Design: MCAL-28453
 */
static FUNC(void, GPT_CODE) Gpt_DeinitChannelPriv(void)
{
    VAR(Gpt_ValueType, AUTOMATIC) LoopValue = 0;
    /* Iterate through the configured list. */
    for (LoopValue = ((Gpt_ValueType)0U); LoopValue < ((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); LoopValue++)
    {
        /* GPT can be deinitialized only in states other than GPT_CH_RUNNING and
         * GPT_CH_UNINITIALIZED */
        if (GPT_CH_UNINITIALIZED != Gpt_DrvObj.Gpt_ChannelState[LoopValue])
        {
            /* Deinitialize the hardware used by the GPT driver to the power on reset state. */
            Gpt_DeInitPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[LoopValue]));

            /* Disable the interrupts */
            Gpt_DisableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[LoopValue]));

            /* Set the channel State to 'Uninitialized'. */
            Gpt_DrvObj.Gpt_ChannelState[LoopValue] = GPT_CH_UNINITIALIZED;

            /* Set the channel notification state to 'Disabled'. */
            Gpt_DrvObj.Gpt_NotificationState[LoopValue] = GPT_NOTIF_DISABLED;
        }
        else
        {
            /* Do Nothing */
        }
    }
}
#endif

/*
 *Design: MCAL-28454
 */
static FUNC(void, GPT_CODE) Gpt_SetChannelToRunningPriv(Gpt_ValueType TargetTimeValue, Gpt_ValueType Channel_Index)
{
    /* If the channel is already in running state, report DET with "GPT_E_BUSY" error. */
    if (GPT_CFG_NO_OF_CHANNELS > Channel_Index)
    {
        if (GPT_CH_RUNNING == Gpt_DrvObj.Gpt_ChannelState[Channel_Index])
        {
            (void)Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_START_TIMER, GPT_E_BUSY);
        }
        else
        {
            /* Critical section, block the interrupts. */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Start counting.  */
            Gpt_StartTimerPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Channel_Index]), TargetTimeValue);

            /* Set the channel state to "Running". */
            Gpt_DrvObj.Gpt_ChannelState[Channel_Index] = GPT_CH_RUNNING;

            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    else
    {
        /*Do nothing*/
    }
}

#if (STD_ON == GPT_CFG_TIME_ELAPSED_API)
/*
 *Design: MCAL-28455
 */
static FUNC(uint32, GPT_CODE) Gpt_ChannelStateCheckPriv(Gpt_ValueType Channel_Index)
{
    VAR(Gpt_ValueType, AUTOMATIC) returnValue = 0U;
    VAR(uint32, AUTOMATIC) periodRegVal       = 0U;
    VAR(uint32, AUTOMATIC) countRegVal        = 0U;
    /* Check for channel state */
    switch (Gpt_DrvObj.Gpt_ChannelState[Channel_Index])
    {
        case GPT_CH_INITIALIZED:
            /* Return the time elapsed as 0 as per AUTOSAR when timer channel is in INIT state
             */
            returnValue = ((Gpt_ValueType)0U);
            break;
        case GPT_CH_RUNNING:
            /* Return the time difference between period register and current counter register
             * of the channel. */
            periodRegVal = Gpt_GetPrdCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Channel_Index]));
            countRegVal  = Gpt_GetCurCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Channel_Index]));
            /*TIM register is loaded with value in PRD register
             *before timer is started. In running mode TIM Register counter starts decrementing
             *till it reaches zero.
             *In RUNNING state periodRegVal is always greater than countRegVal*/
            returnValue = (uint32)(periodRegVal - countRegVal);
            break;
        case GPT_CH_STOPPED:
            /* Return the time diff between period and counter register which are saved when
             * timer is stopped */
            periodRegVal = Gpt_DrvObj.Gpt_StopStatePrdCounter[Channel_Index];
            countRegVal  = Gpt_DrvObj.Gpt_StopStateCurCounter[Channel_Index];
            if (periodRegVal > countRegVal)
            {
                returnValue = (uint32)(periodRegVal - countRegVal);
            }
            break;
        case GPT_CH_EXPIRED:
            /* Read & return the period register of the channel. */
            returnValue = Gpt_GetPrdCountPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Channel_Index]));
            break;
        /* TI_COVERAGE_GAP_START [Branch/Line Gap] All the states of the channel are already
               added in Switch hence this default case can't be validated. */
        default:
            break;
            /* TI_COVERAGE_GAP_STOP*/
    }

    return returnValue;
}
#endif

/*
 *Design: MCAL-28456
 */
static FUNC(void, GPT_CODE) Gpt_ConfigureInitPriv(void)
{
    VAR(Gpt_ValueType, AUTOMATIC) Loop = 0U;

    for (Loop = ((Gpt_ValueType)0U); Loop < ((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); Loop++)
    {
        /* Initialize the GPT channel. */
        (void)Gpt_InitPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Loop]));

        /* Disable the interrupts */
        (void)Gpt_DisableIntPriv(&(Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Loop]));

        /* Set the channel State to "Initialized". */
        Gpt_DrvObj.Gpt_ChannelState[Loop] = GPT_CH_INITIALIZED;

        /* Set the channel notification State to "Disabled". */
        Gpt_DrvObj.Gpt_NotificationState[Loop] = GPT_NOTIF_DISABLED;

        /* Set the period counter at stop state to 0 */
        Gpt_DrvObj.Gpt_StopStatePrdCounter[Loop] = ((Gpt_ValueType)0U);

        /* Set the current counter at stop state to 0 */
        Gpt_DrvObj.Gpt_StopStateCurCounter[Loop] = ((Gpt_ValueType)0U);

        /* Set the index(loop) value to the current channel */
        Gpt_DrvObj.Gpt_Lut_Channel_Index[Gpt_DrvObj.Gpt_CfgPtr->ChannelCfgPtr[Loop].Gpt_ChannelId] = Loop;
    }
}

/*
 *Design: MCAL-28457
 */
static inline FUNC(uint32, GPT_CODE) Gpt_InitDet(const Gpt_ConfigType* Cfg_Ptr)
{
    VAR(Gpt_ValueType, AUTOMATIC) retVal = E_NOT_OK;
    /* Gpt module must not be initialized. Otherwise call the Det with GPT_E_ALREADY_INITIALIZED */
    if (TRUE == Gpt_DriverInitialized)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_ALREADY_INITIALIZED);
#endif
    }
    else if (NULL_PTR == Cfg_Ptr)
    {
#if (STD_ON == GPT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_PARAM_POINTER);
#endif
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/*
 *Design: MCAL-28458
 */
static inline FUNC(uint32, GPT_CODE)
    Gpt_SetChannelsToUnintializedPriv(Gpt_DriverObjType* GptDrvObj, const Gpt_ConfigType* Cfg_Ptr)
{
    VAR(Gpt_ValueType, AUTOMATIC) LoopValue   = 0U;
    VAR(Gpt_ValueType, AUTOMATIC) returnValue = E_OK;
    for (LoopValue = ((Gpt_ValueType)0U); LoopValue < ((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS); LoopValue++)
    {
        GptDrvObj->Gpt_ChannelState[LoopValue] = GPT_CH_UNINITIALIZED;
    }

    /* Set the index value of all channels to MAX value */
    for (LoopValue = ((Gpt_ValueType)0U); LoopValue < ((Gpt_ValueType)GPT_CFG_MAX_CHANNELS); LoopValue++)
    {
        GptDrvObj->Gpt_Lut_Channel_Index[LoopValue] = GPT_MAX_32BIT_VAL;
    }
    /* Copy Config Pointer */
    GptDrvObj->Gpt_CfgPtr = Cfg_Ptr;

    for (LoopValue = ((Gpt_ValueType)0U); (LoopValue < ((Gpt_ValueType)GPT_CFG_NO_OF_CHANNELS)); LoopValue++)
    {
        /* If the channel is invalid, report to DET with "GPT_E_PARAM_CHANNEL" error. */
        if (GptDrvObj->Gpt_CfgPtr->ChannelCfgPtr[LoopValue].Gpt_ChannelId >= ((Gpt_ChannelType)GPT_CFG_MAX_CHANNELS))
        {
            (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SID_INIT, GPT_E_PARAM_CHANNEL);
            returnValue = E_NOT_OK;
            break;
        }
    }
    return returnValue;
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Gpt.c
 *********************************************************************************************************************/
