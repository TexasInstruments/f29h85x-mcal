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
 *  File:       Cdd_Sent.c
 *  Generator:  None
 *
 *  Description:  This file contains CDD SENT MCAL driver API function definitions
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* 
* Design: MCAL-28618
*/
#include "Cdd_Sent.h"
#include "Cdd_Sent_Priv.h"

/* Design: MCAL-29150 */
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

#if ((CDD_SENT_SW_MAJOR_VERSION != (2U)) || (CDD_SENT_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Sent.c and Cdd_Sent.h are inconsistent!"
#endif

#if ((CDD_SENT_CFG_MAJOR_VERSION != (2U)) || (CDD_SENT_CFG_MINOR_VERSION != (0U)))
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
/*
 *Design: MCAL-28678
 */
VAR(boolean, CDD_SENT_VAR_INIT) Cdd_Sent_DriverInitialized = FALSE;
#define CDD_SENT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Sent_MemMap.h"

#define CDD_SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"
/* Global configuration structure object */
/*
 *Design: MCAL-28679
 */
static VAR(Cdd_Sent_DriverObjType, CDD_SENT_VAR_INIT) Cdd_Sent_DrvObj = {0};
#define CDD_SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief Cdd_Sent_ConfigInitPriv : Configure the Cdd_Sent Driver object when it is unintialised.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE) Cdd_Sent_ConfigInitPriv(void);
/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_CODE
#include "Cdd_Sent_MemMap.h"

/*
 *Design: MCAL-28654, MCAL-28655
 */
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


/*
 *Design: MCAL-28650, MCAL-28651, MCAL-28652, MCAL-28653, MCAL-28626, MCAL-28680
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Init(P2CONST(Cdd_Sent_ConfigType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
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
        (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, CDD_SENT_SID_INIT, \
        CDD_SENT_E_ALREADY_INITIALIZED);
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
        Cdd_Sent_DrvObj.CddSent_CfgPtr = config_ptr;

        /* Set the index value of all channels to MAX value */
        Cdd_Sent_ConfigInitPriv();
    }
}

/*
 *Design: MCAL-28656, MCAL-28658, MCAL-28657, MCAL-28625
 */
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
            if (Cdd_Sent_DrvObj.CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentHWUnitId >=
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
                (void) Cdd_Sent_HwDenitPrv(Cdd_Sent_DrvObj.CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]);
            }
            Cdd_Sent_DriverInitialized = FALSE;
        }
    }
}

/*
 *Design: MCAL-28659, MCAL-28660
 */
#if (STD_ON == CDD_SENT_ENABLE_MTP_MODE)
FUNC(Std_ReturnType, CDD_SENT_CODE)
Cdd_Sent_Transmit(P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr,
                    PduIdType TxPduId)
{
    VAR(Std_ReturnType, AUTOMATIC) Status = E_NOT_OK;

#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    /* CDD_Sent module must  be initialized. Otherwise call the Det with CDD_SENT_E_UNINIT */
    if (FALSE == Cdd_Sent_DriverInitialized)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                               CDD_SENT_INSTANCE_ID,
                               CDD_SENT_SID_TRANSMIT,
                               CDD_SENT_E_UNINIT);
    }
    else if (NULL_PTR == PduInfoPtr)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                               CDD_SENT_INSTANCE_ID,
                               CDD_SENT_SID_TRANSMIT,
                               CDD_SENT_E_PARAM_POINTER);
    }
    else
#endif
    {
        Status = Cdd_Sent_TransmitPriv(PduInfoPtr, TxPduId);
    }
	return Status;
}
#endif

/*
 *Design: MCAL-29238, MCAL-29239, MCAL-29240
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Enable_Interrupts(Cdd_SentInstance SentInstance)
{
    VAR(CddSent_ValueType, AUTOMATIC) instance_index = CDD_SENT_MAX_32BIT_VAL;
    (void)Cdd_Sent_GetChIdxPriv(&Cdd_Sent_DrvObj, SentInstance, &instance_index);

#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    /* CDD_Sent module must  be initialized. Otherwise call the Det with CDD_SENT_E_UNINIT */
    if (FALSE == Cdd_Sent_DriverInitialized)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                               CDD_SENT_INSTANCE_ID,
                               CDD_SENT_SID_ENABLE_INTERRUPT,
                               CDD_SENT_E_UNINIT);
    }
    else if (SENT_MAX_HW_UNITS < instance_index)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                        CDD_SENT_INSTANCE_ID,
                        CDD_SENT_SID_ENABLE_INTERRUPT,
                        CDD_SENT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
            uint32 Sent_Instance_BaseAdress= Cdd_Sent_DrvObj.CddSent_CfgPtr-> \
            Cdd_Sent_HWUnit[instance_index]->CddSentBaseAddress;
            
            /* Enable interrupt sources*/
            Cdd_Sent_enableInterrupt(Sent_Instance_BaseAdress, SENT_ENABLE_INTERRUPT_SOURCES);
    }

}

/*
 *Design: MCAL-29241, MCAL-29242, MCAL-29243
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Disable_Interrupts(Cdd_SentInstance SentInstance)
{
    VAR(CddSent_ValueType, AUTOMATIC) instance_index = CDD_SENT_MAX_32BIT_VAL;
    (void)Cdd_Sent_GetChIdxPriv(&Cdd_Sent_DrvObj, SentInstance, &instance_index);

#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    /* CDD_Sent module must  be initialized. Otherwise call the Det with CDD_SENT_E_UNINIT */
    if (FALSE == Cdd_Sent_DriverInitialized)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                               CDD_SENT_INSTANCE_ID,
                               CDD_SENT_SID_DISABLE_INTERRUPT,
                               CDD_SENT_E_UNINIT);
    }
    else if (SENT_MAX_HW_UNITS < instance_index)
    {
        (void) Det_ReportError(CDD_SENT_MODULE_ID,
                        CDD_SENT_INSTANCE_ID,
                        CDD_SENT_SID_DISABLE_INTERRUPT,
                        CDD_SENT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        uint32 Sent_Instance_BaseAdress= Cdd_Sent_DrvObj.CddSent_CfgPtr->Cdd_Sent_HWUnit[instance_index]->CddSentBaseAddress;
        
        /* Disable interrupt sources*/
        Cdd_Sent_disableInterrupt(Sent_Instance_BaseAdress, (0xFFFFFFFFU));
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 *Design: MCAL-28838
 */
static FUNC(void, CDD_SENT_CODE) Cdd_Sent_ConfigInitPriv(void)
{
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) return_value = E_NOT_OK;
#endif
    for (uint32 loop_count = ((uint32)0U); loop_count < ((uint32) SENT_MAX_HW_UNITS); loop_count++)
    {
        Cdd_Sent_DrvObj.CddSent_Lut_Channel_Index[loop_count]=CDD_SENT_MAX_32BIT_VAL;
        for(uint32 Channel_count = 0U; Channel_count < (uint32)MAXIMUM_NUMBER_OF_SENSORS; Channel_count++)
        {
            Cdd_Sent_DrvObj.CddSent_Fast_Channel_PduID[loop_count][Channel_count] = CDD_SENT_MAX_16BIT_VAL;
        }
    }
    /*
        * Only initialize configured resources, that means, only HW units listed
        * in the configuration structure.
        */
#if (STD_ON == CDD_SENT_CFG_DEV_ERROR_DETECT)
    for (uint32 loop_count = ((uint32)0U); loop_count < ((uint32) SENT_CFG_NO_OF_HW_UNITS); loop_count++)
    {
        /* If the channel is invalid, report to DET with "CDD_SENT_E_PARAM_CHANNEL" error. */
        if (Cdd_Sent_DrvObj.CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentHWUnitId >=
        ((uint8)SENT_MAX_HW_UNITS))
        {
            return_value = E_NOT_OK;
            (void)Det_ReportError(CDD_SENT_MODULE_ID, CDD_SENT_INSTANCE_ID, \
            CDD_SENT_SID_INIT,CDD_SENT_E_PARAM_CHANNEL);
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
        Cdd_Sent_InitPriv(&Cdd_Sent_DrvObj, &Cdd_Sent_DriverInitialized);
    }
}
#define CDD_SENT_STOP_SEC_CODE
#include "Cdd_Sent_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Cdd_Sent.c
 *********************************************************************************************************************/
