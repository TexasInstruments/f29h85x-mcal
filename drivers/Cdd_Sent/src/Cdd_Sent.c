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
 *  File:       Cdd_Sent.c
 *  Generator:  None
 *
 *  Description:  This file contains CDD SENT MCAL driver API function definitions
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-xxxxx */
#include "Cdd_Sent.h"
#include "Cdd_Sent_Priv.h"

/* Design: MCAL-xxxxx */
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
#if ((CDD_SENT_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
     (CDD_SENT_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_SENT_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version Numbers of CDD_SENT are different"
#endif

#if ((CDD_SENT_SW_MAJOR_VERSION != (1U)) || (CDD_SENT_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Sent.c and Cdd_Sent.h are inconsistent!"
#endif

#if ((CDD_SENT_CFG_MAJOR_VERSION != (1U)) || (CDD_SENT_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Sent.c and Cdd_Sent_Cfg.h are inconsistent!"
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
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Sent_MemMap.h"
static VAR(boolean, CDD_SENT_VAR_INIT) Cdd_Sent_DriverInitialized = FALSE;
#define CDD_SENT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Sent_MemMap.h"

#define CDD_SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"
/* Global configuration structure object */
static P2CONST(Cdd_Sent_ConfigType, CDD_SENT_VAR_INIT, CDD_SENT_VAR_INIT) Cdd_Sent_DrvObj;
#define CDD_SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_CODE
#include "Cdd_Sent_MemMap.h"

/* Design : MCAL-xxxxx */
#if (STD_ON == CDD_SENT_CFG_GET_VERSION_INFO_API)
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_SENT_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "CDD_SENT_E_PARAM_POINTER" error */
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(
            CDD_SENT_MODULE_ID,
            CDD_SENT_INSTANCE_ID,
            CDD_SENT_SID_GET_VERSION_INFO,
            CDD_SENT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID = (uint16)CDD_SENT_VENDOR_ID;
        VersionInfoPtr->moduleID = (uint16)CDD_SENT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_SENT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_SENT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_SENT_SW_PATCH_VERSION;
    }
}
#endif


/* Design : MCAL-xxxxx */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Init(P2CONST(Cdd_Sent_ConfigType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{

    VAR(uint32, AUTOMATIC) loop_count;
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) return_value = E_NOT_OK;
#endif
    P2CONST(Cdd_Sent_ConfigType, AUTOMATIC, CDD_SENT_CONST) config_ptr = NULL_PTR;  /* Config pointer initialised with NULL_PTR */

#if (STD_ON == CDD_SENT_CFG_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        config_ptr = &CddSentConfig_Cdd_SentController_List;
    }
    else
    {
    #if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, CDD_SENT_SID_INIT, CDD_SENT_E_PARAM_POINTER);
    #endif 
    }
#endif

    /* Cdd_Sent module must not be initialized. Otherwise call the Det with CDD_SENT_E_ALREADY_INITIALIZED */
    if (TRUE == Cdd_Sent_DriverInitialized)
    {
        #if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, CDD_SENT_SID_INIT, CDD_SENT_E_ALREADY_INITIALIZED);
        #endif
    }
    else if (NULL_PTR == config_ptr)
    {
        #if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, CDD_SENT_SID_INIT, CDD_SENT_E_PARAM_POINTER);
        #endif 
    }
    else
    {

        /* Save the pointer to configuration */
        Cdd_Sent_DrvObj = config_ptr;

        /*
         * Only initialize configured resources, that means, only HW units listed
         * in the configuration structure.
         */
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
        for (loop_count = ((uint32)0U); loop_count < ((uint32) SENT_CFG_NO_OF_HW_UNITS); loop_count++)
        {
            /* If the channel is invalid, report to DET with "CDD_SENT_E_PARAM_CHANNEL" error. */
            if (Cdd_Sent_DrvObj->Cdd_Sent_HWUnit[loop_count]->Cdd_SentHWUnitId >=
                ((uint8)SENT_MAX_HW_UNITS))
            {
                return_value = E_NOT_OK;
                (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, CDD_SENT_SID_INIT,CDD_SENT_E_PARAM_CHANNEL);
                break;
            }
            else
            {
                return_value = E_OK;
            }
        }

        if(E_OK == return_value)
#endif
        {
            for (loop_count = ((uint32)0U); loop_count < ((uint32) SENT_CFG_NO_OF_HW_UNITS); loop_count++)
            {
                /* Initialize the CDD_SENT channel. */
                (void)Cdd_Sent_HwInitPrv(Cdd_Sent_DrvObj->Cdd_Sent_HWUnit[loop_count]);

            }

            /* Save the Cdd_Sent_DrvObj address into a pointer in Cdd_Sent_Priv.c */
            Cdd_Sent_SetDriverObjPtr((Cdd_Sent_ConfigType*)Cdd_Sent_DrvObj);
            Cdd_Sent_DriverInitialized = TRUE;

            /* Enable Sent Receiver*/
            for (loop_count = ((uint32)0U); loop_count < ((uint32) SENT_CFG_NO_OF_HW_UNITS); loop_count++)

            {
                /* Initialize the CDD_SENT channel. */
                Cdd_Sent_EnableSentReceiver(Cdd_Sent_DrvObj->Cdd_Sent_HWUnit[loop_count]->Cdd_SentBaseAddress);
            }

        }
    }
}

/* Design : MCAL-xxxxx */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Deinit(void)
{
    VAR(uint32, AUTOMATIC) loop_count;
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) return_value = E_NOT_OK;
#endif

#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    /* CDD_Sent module must  be initialized. Otherwise call the Det with CDD_SENT_E_UNINIT */
    if (FALSE == Cdd_Sent_DriverInitialized)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                               CDD_SENT_INSTANCE_ID,
                               CDD_SENT_SID_DEINIT,
                               CDD_SENT_E_UNINIT);
    }
    else
#endif
    {

        /*
         * Only initialize configured resources, that means, only channels listed
         * in the channel configuration structure.
         */
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
        for(loop_count = ((uint32)0U); loop_count<((uint32 )SENT_CFG_NO_OF_HW_UNITS); loop_count++)
        {
            /* If the channel is invalid, report to DET with "CDD_SENT_E_PARAM_CHANNEL" error. */
            if (Cdd_Sent_DrvObj->Cdd_Sent_HWUnit[loop_count]->Cdd_SentHWUnitId >=
                        ((uint8 )SENT_MAX_HW_UNITS))
            {
                return_value = E_NOT_OK;
                (void) Det_ReportError(CDD_SENT_MODULE_ID,
                                       CDD_SENT_INSTANCE_ID,
                                       CDD_SENT_SID_INIT,
                                       CDD_SENT_E_PARAM_CHANNEL);
                break;
            }
            else
            {
                 return_value = E_OK;
            }
        }
        if(E_OK == return_value)
#endif
        {
            for(loop_count = ((uint32)0U); loop_count<((uint32 )SENT_CFG_NO_OF_HW_UNITS); loop_count++)
            {
                /* De-Initialize the CDD_SENT channel. */
                (void) Cdd_Sent_HwDenitPrv(Cdd_Sent_DrvObj->Cdd_Sent_HWUnit[loop_count]);
            }
            Cdd_Sent_DriverInitialized = FALSE;
        }
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define CDD_SENT_STOP_SEC_CODE
#include "Cdd_Sent_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Cdd_Sent.c
 *********************************************************************************************************************/
