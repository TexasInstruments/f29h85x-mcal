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
 *  File:       Lin.c
 *
 *  Description:  This file contains Interface and services for Lin Driver
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-25530, MCAL-25537, MCAL-25539, MCAL-25540, MCAL-25535, MCAL-25590, MCAL-25648
 */
#include "Lin.h"
#include "Lin_Priv.h"
#include "SchM_Lin.h"
#if (STD_ON == LIN_DEM_ENABLE)
#include "Dem.h"
#endif

#if (STD_ON == LIN_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*
 * AUTOSAR version information check has to match definition in header file
 */
#if ((LIN_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (LIN_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (LIN_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "LIN: AUTOSAR Version Numbers of LIN are different"
#endif

/*
 * Vendor specific version information is BCD coded
 */
#if ((LIN_SW_MAJOR_VERSION != (3U)) || (LIN_SW_MINOR_VERSION != (1U)))
#error "Version numbers of Lin.c and Lin.h are inconsistent!"
#endif

#if ((LIN_CFG_MAJOR_VERSION != (3U)) || (LIN_CFG_MINOR_VERSION != (1U)))
#error "Version numbers of Lin.c and Lin_Cfg.h are inconsistent!"
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
#if (STD_ON == LIN_DEV_ERROR_DETECT)
/** \brief  Lin Module State */
typedef enum Lin_ModuleStateTag
{
    /** \brief  Lin Module State UnInitialized */
    LIN_UNINIT,
    /** \brief  Lin Module State Initialized */
    LIN_INIT
} Lin_ModuleStateType;
#endif

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Internal Function Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#define LIN_START_SEC_VAR_INIT_PTR
#include "Lin_MemMap.h"
/* Global configuration structure object */
static P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) Lin_Config_Ptr;
#define LIN_STOP_SEC_VAR_INIT_PTR
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

#if (STD_ON == LIN_DEV_ERROR_DETECT)
/*
 * Global Init Done flag
 */
static VAR(Lin_ModuleStateType, LIN_VAR_INIT) Lin_Module_State = LIN_UNINIT;
#endif
VAR(Lin_ChannelStatusType, LIN_VAR) Lin_Channel_Status[LIN_MAX_CHANNEL];

#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (STD_ON == LIN_DEV_ERROR_DETECT)
/** \brief Lin_SendFrameDetCheck - This API will check for DET errors in Lin_SendFrame() API.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[in] PduInfoPtr Pointer to PDU containing the PID, checksum model, response type, Dl and
 *SDU data pointer
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, LIN_CODE)
    Lin_SendFrameDetCheck(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);

/** \brief Lin_GetStatusDetCheck - This API will check for DET errors in Lin_GetStatus() API.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[out] Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *receive buffer where the current SDU is stored.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, LIN_CODE)
    Lin_GetStatusDetCheck(VAR(uint8, AUTOMATIC) Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#if (STD_ON == LIN_GET_VERSION_INFO_API)
/*
 * Design: MCAL-25585, MCAL-25604, MCAL-25605
 */
FUNC(void, LIN_CODE)
Lin_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_DATA) versioninfo)
{
#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GET_VERSION_INFO, LIN_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->vendorID         = (LIN_VENDOR_ID);
        versioninfo->moduleID         = (LIN_MODULE_ID);
        versioninfo->sw_major_version = (uint8)(LIN_SW_MAJOR_VERSION);
        versioninfo->sw_minor_version = (uint8)(LIN_SW_MINOR_VERSION);
        versioninfo->sw_patch_version = (uint8)(LIN_SW_PATCH_VERSION);
    }
}
#endif

/*
 * Design:
 * MCAL-25526,MCAL-25527,MCAL-25528,MCAL-25529,MCAL-25549,MCAL-25550,MCAL-25551,MCAL-25581,MCAL-25584,
 * Design:
 * MCAL-25587,MCAL-25594,MCAL-25595,MCAL-25596,MCAL-25597,MCAL-25598,MCAL-25599,MCAL-25600,MCAL-25645,
 * Design: MCAL-25646,MCAL-25647
 */
FUNC(void, LIN_CODE)
Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) Config)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    /* Local Config pointer initialised with NULL_PTR */
    P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) config_ptr = NULL_PTR;

#if (STD_ON == LIN_PRE_COMPILE_VARIANT)
    if (NULL_PTR == Config)
    {
        /* Assigning passed module configuration to local Config pointer incase of Pre Compile
         * variant */
        config_ptr = &LIN_INIT_CONFIG_PC;
    }
    else
    {
#if (STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_INIT, LIN_E_PARAM_POINTER);
#endif
    }
#else  /* If Post Build Variant is selected */
    if (NULL_PTR != Config)
    {
        /* Assigning passed module configuration to local Config pointer incase of Post Build
         * variant */
        config_ptr = Config;
    }
#endif /*LIN_PRE_COMPILE_VARIANT*/

    if (NULL_PTR == config_ptr)
    {
#if (STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_INIT, LIN_E_PARAM_POINTER);
#endif
    }
#if (STD_ON == LIN_DEV_ERROR_DETECT)
    else if (LIN_UNINIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_INIT, LIN_E_STATE_TRANSITION);
    }
#endif
    else
    {
        /* Save the Local Config Pointer to Global Configuration Structure Pointer*/
        Lin_Config_Ptr = config_ptr;
        return_value   = Lin_InitInternal(Lin_Config_Ptr);

        if (return_value == E_OK)
        {
#if (STD_ON == LIN_DEV_ERROR_DETECT)
            /*
             * Set Init Done flag
             */
            Lin_Module_State = LIN_INIT;
#endif
        }
        /* TI_COVERAGE_GAP_START [Line Gap] in LIN_E_INVALID_POINTER, False Positive */
        else
        {
#if (STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_INIT, LIN_E_INVALID_POINTER);
#endif
        }
        /* TI_COVERAGE_GAP_STOP*/
    }
}

/*
 * Design:
 * MCAL-25577,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25601,MCAL-25602,MCAL-25603,MCAL-25642,MCAL-25643,
 * Design: MCAL-25644
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_CHECK_WAKEUP, LIN_E_UNINIT);
    }
    else if ((uint8)LIN_MAX_CHANNEL < (uint8)Channel)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_CHECK_WAKEUP, LIN_E_INVALID_CHANNEL);
    }
    else
#endif
    {
        return_value = Lin_CheckWakeupInternal(Channel);
    }
    return return_value;
}

/*
 * Design:
 * MCAL-25559,MCAL-25560,MCAL-25561,MCAL-25562,MCAL-25563,MCAL-25565,MCAL-25566,MCAL-25567,MCAL-25568,
 * Design:
 * MCAL-25569,MCAL-25570,MCAL-25571,MCAL-25572,MCAL-25574,MCAL-25581,MCAL-25582,MCAL-25583,MCAL-25587,
 * Design:
 * MCAL-25606,MCAL-25607,MCAL-25608,MCAL-25609,MCAL-25610,MCAL-25611,MCAL-25612,MCAL-25613,MCAL-25614
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_SEND_FRAME, LIN_E_UNINIT);
    }
    else
    {
        return_value = Lin_SendFrameDetCheck(Channel, PduInfoPtr);
    }

    if (((Std_ReturnType)E_OK) == return_value)
#endif
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();

        return_value = Lin_SendData(&Lin_Config_Ptr->linChannelCfg[Channel],
                                    &Lin_Channel_Status[Channel].linChannelActivityStatus, PduInfoPtr);

        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();
    }
    return (return_value);
}

/*
 * Design:
 * MCAL-25552,MCAL-25575,MCAL-25576,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25615,MCAL-25616,MCAL-25617,
 * Design: MCAL-25618,MCAL-25619,MCAL-25620,MCAL-25621,MCAL-25622,MCAL-25642,MCAL-25558
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GOTO_SLEEP, LIN_E_UNINIT);
    }
    else if ((uint8)LIN_MAX_CHANNEL <= (uint8)Channel)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GOTO_SLEEP, LIN_E_INVALID_CHANNEL);
    }
    else
#endif
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();

        if (TRUE == Lin_Config_Ptr->linChannelCfg[Channel].linChannelWakeupSupport)
        {
            Lin_EnableWakeupDetection(&Lin_Config_Ptr->linChannelCfg[Channel], TRUE);
        }
        else
        {
            Lin_EnableWakeupDetection(&Lin_Config_Ptr->linChannelCfg[Channel], FALSE);
        }

        /* Send goto-sleep command on bus */
        return_value = Lin_SendGoToSleepSignal(Lin_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr);
        if (return_value == E_NOT_OK)
        {
#if (STD_ON == LIN_DEM_ENABLE)
#ifdef LIN_E_TIMEOUT
            Dem_SetEventStatus(LIN_E_TIMEOUT, DEM_EVENT_STATUS_PREFAILED);
#endif
#endif
        }
        else
        {
            Lin_EnterLowPowerMode(Lin_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, TRUE);
            Lin_AbortTransmission(Lin_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr);
            Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_SLEEP_PENDING;
            return_value                                        = E_OK;
        }

        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();
    }

    return return_value;
}

/*
 * Design:
 * MCAL-25554,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25623,MCAL-25624,MCAL-25625,MCAL-25626,MCAL-25627
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GOTO_SLEEP_INTERNAL, LIN_E_UNINIT);
    }
    else if ((uint8)LIN_MAX_CHANNEL <= (uint8)Channel)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GOTO_SLEEP_INTERNAL, LIN_E_INVALID_CHANNEL);
    }
    else
#endif
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();

        if (TRUE == Lin_Config_Ptr->linChannelCfg[Channel].linChannelWakeupSupport)
        {
            Lin_EnableWakeupDetection(&Lin_Config_Ptr->linChannelCfg[Channel], TRUE);
        }
        else
        {
            Lin_EnableWakeupDetection(&Lin_Config_Ptr->linChannelCfg[Channel], FALSE);
        }

        Lin_EnterLowPowerMode(Lin_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, TRUE);

        Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_SLEEP;

        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();

        return_value = E_OK;
    }

    return return_value;
}

/*
 * Design:
 * MCAL-25555,MCAL-25557,MCAL-25578,MCAL-25581,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25628,MCAL-25629,
 * Design: MCAL-25630
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP, LIN_E_UNINIT);
    }
    else if ((uint8)LIN_MAX_CHANNEL <= (uint8)Channel)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP, LIN_E_INVALID_CHANNEL);
    }
    else if (LIN_CHANNEL_SLEEP != Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP, LIN_E_STATE_TRANSITION);
    }
    else
#endif
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();
        return_value = Lin_WakeupProcess(Channel);
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();
    }

    return return_value;
}

/*
 * Design:
 * MCAL-25556,MCAL-25579,MCAL-25581,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25631,MCAL-25632,MCAL-25633,
 * Design: MCAL-25634
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_WakeupInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP_INTERNAL, LIN_E_UNINIT);
    }
    else if ((uint8)LIN_MAX_CHANNEL <= (uint8)Channel)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP_INTERNAL, LIN_E_INVALID_CHANNEL);
    }
    else if (LIN_CHANNEL_SLEEP != Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_WAKEUP_INTERNAL, LIN_E_STATE_TRANSITION);
    }
    else
#endif
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();
        return_value = Lin_WakeupInternalProcess(Channel);
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();
    }

    return return_value;
}

/*
 * Design:
 * MCAL-25553,MCAL-25564,MCAL-25573,MCAL-25582,MCAL-25583,MCAL-25587,MCAL-25635,MCAL-25636,MCAL-25637,
 * Design: MCAL-25638,MCAL-25639,MCAL-25640,MCAL-25641
 */
FUNC(Lin_StatusType, LIN_CODE)
Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
{
    VAR(Lin_StatusType, AUTOMATIC) return_value = LIN_NOT_OK;
    VAR(uint32, AUTOMATIC) lin_cnt_base_addr    = (uint32)0U;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    VAR(Std_ReturnType, AUTOMATIC) det_return_value = (Std_ReturnType)E_NOT_OK;

    det_return_value = Lin_GetStatusDetCheck(Channel, Lin_SduPtr);

    if (((Std_ReturnType)E_OK) == det_return_value)
#endif
    {
        lin_cnt_base_addr = Lin_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr;

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_0();

        return_value = Lin_GetStatusInternalProcess(Channel, Lin_SduPtr, &lin_cnt_base_addr);

        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_0();
    }
    return return_value;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 * Design : MCAL-28462, MCAL-28461
 */
#if (STD_ON == LIN_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, LIN_CODE)
    Lin_SendFrameDetCheck(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_OK;

    if ((LIN_MAX_CHANNEL <= Channel))
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_SEND_FRAME, LIN_E_INVALID_CHANNEL);
        return_value = E_NOT_OK;
    }
    else if ((NULL_PTR == PduInfoPtr))
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_SEND_FRAME, LIN_E_PARAM_POINTER);
        return_value = E_NOT_OK;
    }
    else if ((LIN_CHANNEL_OPERATIONAL != Lin_Channel_Status[Channel].linChannelNetworkStatus))
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_SEND_FRAME, LIN_E_STATE_TRANSITION);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Do Nothing. Return E_OK with No det Errors*/
    }

    return return_value;
}

/*
 * Design : MCAL-28462
 */
static FUNC(Std_ReturnType, LIN_CODE)
    Lin_GetStatusDetCheck(VAR(uint8, AUTOMATIC) Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_OK;

    if (LIN_INIT != Lin_Module_State)
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GET_STATUS, LIN_E_UNINIT);
        return_value = E_NOT_OK;
    }
    else if ((LIN_MAX_CHANNEL < Channel))
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GET_STATUS, LIN_E_INVALID_CHANNEL);
        return_value = E_NOT_OK;
    }
    else if ((NULL_PTR == Lin_SduPtr))
    {
        (void)Det_ReportError(LIN_MODULE_ID, LIN_INSTANCE_ID, LIN_SID_GET_STATUS, LIN_E_PARAM_POINTER);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Do Nothing. Return E_OK with No det Errors*/
    }
    return return_value;
}
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Lin.c
 *********************************************************************************************************************/
