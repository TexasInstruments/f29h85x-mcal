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
 *  File:       Wdg.c
 *  Generator:  None
 *
 *  Description:  This file contains interface for Wdg Drv functions                                                  
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Wdg.h"
#include "Wdg_Priv.h"
#include "Wdg_Cbk.h"
#include "SchM_Wdg.h"

#if (STD_ON == WDG_DEV_ERROR_DETECT)
    #include "Det.h"
#endif /*WDG_DEV_ERROR_DETECT*/

#if (STD_ON == WDG_DEM_ENABLE)
    #include "Dem.h"
#endif /*WDG_DEM_ENABLE*/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((WDG_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
    (WDG_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
    (WDG_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "WDG: AUTOSAR Version Numbers of WDG are different"
#endif

/* vendor specific version information */
#if ((WDG_SW_MAJOR_VERSION != (1U)) || (WDG_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Wdg.c and Wdg.h are inconsistent!"
#endif

#if ((WDG_CFG_MAJOR_VERSION != (1U)) || (WDG_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Wdg.c and Wdg_Cfg.h are inconsistent!"
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

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

VAR(Wdg_DriverObjType, WDG_VAR_NO_INIT) Wdg_DrvObj;

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"


#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (STD_ON == WDG_DEV_ERROR_DETECT)
    volatile VAR(Wdg_StatusType, WDG_VAR_INIT) Wdg_DrvStatus = WDG_UNINIT;
#endif
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief Wdg_CheckAndSetRequestedMode - This API will check requested mode configuration settings and set the mode
 * 
 * \param[in] Mode The requested mode type off,slow,fast mode
 * \param[out] None
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted.
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, WDG_CODE) Wdg_CheckAndSetRequestedMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

 /*
 * Design: MCAL-25270, MCAL-25271
 */
#if (STD_ON == WDG_GET_VERSION_INFO_API)
FUNC(void, WDG_CODE) Wdg_GetVersionInfo(P2VAR (Std_VersionInfoType, AUTOMATIC,WDG_APPL_DATA) Versioninfo)
{
#if (STD_ON == WDG_DEV_ERROR_DETECT)
    if (NULL_PTR == Versioninfo)
    {
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                            WDG_SID_GET_VERSION_INFO, WDG_E_PARAM_POINTER);
    }
    else
#endif /* WDG_DEV_ERROR_DETECT */
    {
        Versioninfo->vendorID         = (WDG_VENDOR_ID);
        Versioninfo->moduleID         = (WDG_MODULE_ID);
        Versioninfo->sw_major_version = (uint8) (WDG_SW_MAJOR_VERSION);
        Versioninfo->sw_minor_version = (uint8) (WDG_SW_MINOR_VERSION);
        Versioninfo->sw_patch_version = (uint8) (WDG_SW_PATCH_VERSION);
    }

    return;
}
#endif  /* WDG_GET_VERSION_INFO_API */


 /*
 * Design: MCAL-25220, MCAL-25221, MCAL-25223, MCAL-25227, MCAL-25228, MCAL-25230, 
 * Design: MCAL-25231, MCAL-25247, MCAL-25248, MCAL-25249, MCAL-25250, MCAL-25251,
 * Design: MCAL-25252, MCAL-25253, MCAL-25254, MCAL-25245, MCAL-25271, MCAL-25272
 */
FUNC(void, WDG_CODE) Wdg_Init(P2CONST(Wdg_ConfigType, WDG_CONFIG_DATA, WDG_CONFIG_DATA) CfgPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = (Std_ReturnType) E_NOT_OK;
    /* Config pointer initialised with NULL_PTR */
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_CONFIG_DATA) config_ptr = NULL_PTR;

#if (STD_ON == WDG_DEV_ERROR_DETECT)
    /* Set to uninit state, After successful initialization only, it sets to IDLE state*/
    Wdg_DrvStatus = WDG_UNINIT;
#endif


#if ((STD_ON == WDG_VARIANT_PRE_COMPILE) || (STD_ON == WDG_VARIANT_LINK_TIME))
    if (NULL_PTR == CfgPtr)
    {
        config_ptr = &WDG_INIT_CONFIG_PC;
    }
#endif  /* (STD_ON == WDG_VARIANT_PRE_COMPILE) or  (STD_ON == WDG_VARIANT_LINK_TIME) */

#if (STD_ON == WDG_VARIANT_POST_BUILD)  
    if (NULL_PTR != CfgPtr)
    {
        config_ptr = CfgPtr;
    }
#endif  /* (STD_ON == WDG_VARIANT_POST_BUILD) */

    if (NULL_PTR == config_ptr)
    {
#if (STD_ON == WDG_DEV_ERROR_DETECT)
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                            WDG_SID_INIT, WDG_E_PARAM_POINTER);
#endif
    }
    else
    {
        /* If Disable allowed feature is OFF and default mode is Off mode from configuration, 
           Report DEM error to indicate that wdg disable feature is rejected */
#if (WDG_DISABLE_ALLOWED == STD_OFF) 
        if (WDGIF_OFF_MODE == config_ptr->Wdg_DefaultMode)
        {
        #ifdef WDG_E_DISABLE_REJECTED
            (void)Dem_SetEventStatus(WDG_E_DISABLE_REJECTED, DEM_EVENT_STATUS_FAILED);
        #endif
        }
#else
        /* If Disable allowed feature is ON and default mode is Off mode from configuration, 
           disable the wdg */
        if (WDGIF_OFF_MODE == config_ptr->Wdg_DefaultMode)
        {
            ret_val = (Std_ReturnType) E_OK;
            /* Disable the Watchdog */
            Wdg_DisableWatchdog();
        }
#endif
        else
        {
            #ifdef WDG_E_DISABLE_REJECTED
                (void)Dem_SetEventStatus(WDG_E_DISABLE_REJECTED, DEM_EVENT_STATUS_PASSED);
            #endif

            ret_val = Wdg_PlatformInit(config_ptr);

            if (((Std_ReturnType) E_OK) != ret_val)
            {
            #ifdef WDG_E_MODE_FAILED
                /* Mode not supported */
                (void)Dem_SetEventStatus(WDG_E_MODE_FAILED, DEM_EVENT_STATUS_FAILED);
            #endif

            #if (STD_ON == WDG_DEV_ERROR_DETECT)
                (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                                WDG_SID_INIT, WDG_E_PARAM_CONFIG);        
            #endif
            }
            else
            {
                #ifdef WDG_E_MODE_FAILED
                    (void)Dem_SetEventStatus(WDG_E_MODE_FAILED, DEM_EVENT_STATUS_PASSED);
                #endif

                /* Save the configured Mode type & Mode configuration settings to global object*/
                Wdg_DrvObj.Wdg_PreviousMode  = config_ptr->Wdg_DefaultMode;
                Wdg_DrvObj.Wdg_SlowModeCfg   = config_ptr->Wdg_SlowModeCfg;
                Wdg_DrvObj.Wdg_FastModeCfg   = config_ptr->Wdg_FastModeCfg;

                /* Enable the Watchdog Counter */
                Wdg_EnableWatchdog();
            }
        }
#if (STD_ON == WDG_DEV_ERROR_DETECT)
        if(ret_val == (Std_ReturnType) E_OK)
        {
            Wdg_DrvStatus = WDG_IDLE;
        }
        else
        {
            /* Do Nothing */
        }
#endif
    }
    return;
}


 /*
 * Design: MCAL-25227, MCAL-25228, MCAL-25230, MCAL-25231, MCAL-25247, MCAL-25255,
 * Design: MCAL-25256, MCAL-25257, MCAL-25258, MCAL-25259, MCAL-25260, MCAL-25261,
 * Design: MCAL-25262, MCAL-25263, MCAL-25264, MCAL-25244, MCAL-25245, MCAL-25271, 
 * Design: MCAL-25272, MCAL-25301
 */
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType) E_NOT_OK;

#if (STD_ON == WDG_DEV_ERROR_DETECT)
    if (WDG_IDLE != Wdg_DrvStatus)
    {
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                    WDG_SID_SET_MODE, WDG_E_DRIVER_STATE);
     
    }
    else if (WDGIF_MODE_MAX <= Mode)
    {
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                    WDG_SID_SET_MODE, WDG_E_PARAM_MODE);
    }
    else
#endif
    {
        /* If Disable allowed feature is OFF and default mode is Off mode from configuration, 
           Report DEM error to indicate that wdg disable feature is rejected */
#if (WDG_DISABLE_ALLOWED == STD_OFF) 
        if (WDGIF_OFF_MODE == Mode)
        {
        #ifdef WDG_E_DISABLE_REJECTED
            (void)Dem_SetEventStatus(WDG_E_DISABLE_REJECTED, DEM_EVENT_STATUS_FAILED);
        #endif
        }
#else
        /* If Disable allowed feature is ON and default mode is Off mode from configuration, 
           disable the wdg */
        if (WDGIF_OFF_MODE == Mode)
        {
            return_value = (Std_ReturnType) E_OK;
            /* Disable the Watchdog */
            Wdg_DisableWatchdog();
        }

#endif
        else
        {
            #ifdef WDG_E_DISABLE_REJECTED
                (void)Dem_SetEventStatus(WDG_E_DISABLE_REJECTED, DEM_EVENT_STATUS_PASSED);
            #endif

            /* local function to check requested mode configuration settings and set mode */
            return_value = Wdg_CheckAndSetRequestedMode(Mode);          
        }
#if (STD_ON == WDG_DEV_ERROR_DETECT)
        if(return_value == (Std_ReturnType) E_OK)
        {
            Wdg_DrvStatus = WDG_IDLE;
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    return (return_value);
}


 /*
 * Design: MCAL-25244, MCAL-25265, MCAL-25266, MCAL-25267, MCAL-25268, MCAL-25269
 * Design: MCAL-25271, MCAL-25238, MCAL-25239, MCAL-25240, MCAL-25241, MCAL-25242
 * Design: MCAL-25243, MCAL-25236, MCAL-25237
 */
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(VAR(uint16, AUTOMATIC) Timeout)
{
#if (STD_ON == WDG_DEV_ERROR_DETECT)
    VAR(uint16, AUTOMATIC) Max_Timeout = 0U;

    Max_Timeout = Wdg_GetMaxTimeout(&Wdg_DrvObj);

    /* Check if driver already initialized */
    if (WDG_IDLE != Wdg_DrvStatus)
    {
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                        WDG_SID_SET_TRIGGER_CONDITION, WDG_E_DRIVER_STATE);    
    }
    else if (Timeout > Max_Timeout)
    {
        /* API is being called with an invalid timeout value */
        (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                        WDG_SID_SET_TRIGGER_CONDITION, WDG_E_PARAM_TIMEOUT); 

    }
    else
#endif 
    {
        Wdg_SetTriggerConditionPriv(Timeout);
    }

    return;
}


/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

 /*
 * Design: MCAL-28572
 */
static FUNC(Std_ReturnType, WDG_CODE) Wdg_CheckAndSetRequestedMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType) E_NOT_OK;
    P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_CONST) mode_cfg_ptr = NULL_PTR;

    /* Check if requested mode type is other than configured mode type */
    if (Mode != Wdg_DrvObj.Wdg_PreviousMode)
    {
        /* Get Requested mode type settings from configuration settings */
        if(Mode == WDGIF_FAST_MODE)
        {
            mode_cfg_ptr = &Wdg_DrvObj.Wdg_FastModeCfg;
        }
        else
        {
            mode_cfg_ptr = &Wdg_DrvObj.Wdg_SlowModeCfg;
        }
#if (STD_ON == WDG_DEV_ERROR_DETECT)
        /* Set driver status as busy */
        Wdg_DrvStatus = WDG_BUSY;
#endif

        /* Disable the Watchdog */
        Wdg_DisableWatchdog();

        /* Reset the Watchdog Counter */
        Wdg_ServiceWatchdog();

        /* Set requested mode configuration settings */
        return_value = Wdg_SetModeConfig(mode_cfg_ptr);


        if (((Std_ReturnType) E_NOT_OK) == return_value)
        {

            #ifdef WDG_E_MODE_FAILED
            /* Mode not supported */
                (void)Dem_SetEventStatus(WDG_E_MODE_FAILED, DEM_EVENT_STATUS_FAILED);
            #endif
            #if (STD_ON == WDG_DEV_ERROR_DETECT)
                (void) Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, 
                            WDG_SID_SET_MODE, WDG_E_PARAM_CONFIG);  
            #endif  
        }
        else
        {
            #ifdef WDG_E_MODE_FAILED
                (void)Dem_SetEventStatus(WDG_E_MODE_FAILED, DEM_EVENT_STATUS_PASSED);
            #endif

            /* Save the configured Mode type value */
            Wdg_DrvObj.Wdg_PreviousMode = Mode;

            /* Enable the Watchdog */
            Wdg_EnableWatchdog();
        }

    }
    else
    {
        return_value = (Std_ReturnType) E_OK;
    }
    return return_value;
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Wdg.c
 *********************************************************************************************************************/
