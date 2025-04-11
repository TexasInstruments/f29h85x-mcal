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
 *  File:       Cdd_Ipc
 *  Generator:  None
 *
 *  Description: This file contains CDD IPC driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ipc.h"
#include "Cdd_Ipc_Priv.h"
#include "SchM_Cdd_Ipc.h"
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_IPC_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_IPC_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_IPC_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version of CDD_IPC is incorrect"
#endif

/* vendor specific version information check */

#if ((CDD_IPC_SW_MAJOR_VERSION != (1U)) || (CDD_IPC_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Ipc.c and Cdd_Ipc.h are not matching!"
#endif

#if ((CDD_IPC_CFG_MAJOR_VERSION != (1U)) || (CDD_IPC_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Ipc.c and Cdd_Ipc_Cfg.h are not matching!"
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
#define CDD_IPC_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Ipc_MemMap.h"
/* Cdd_Ipc Driver initialization variable */
VAR(boolean,CDD_IPC_VAR_INIT) Cdd_Ipc_IsInitialized = FALSE;
#define CDD_IPC_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"
/* Cdd_Ipc configuration pointer to access driver configuration. */
P2CONST(Cdd_Ipc_ConfigType,AUTOMATIC,CDD_IPC_CONST) Cdd_Ipc_CfgPtr = NULL_PTR;
#define CDD_IPC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
/** \brief Checks and reports DET errors for Cdd_Ipc_Transmit API
 *
 * \param[in] PduInfoPtr is the pointer to a struct of type PduInfoType containing the complete data to be transmitted.
 * \pre None
 * \post None
 * \return DET errors detection status.
 * \retval E_OK: DET errors not reported.
 * \retval E_NOT_OK: DET errors reported.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_TransmitPduDetCheck
(P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);
#endif
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#if (STD_ON == CDD_IPC_GET_VERSION_INFO_API)
/*
 * Design: MCAL-
 */
FUNC(void,CDD_IPC_CODE) Cdd_Ipc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_IPC_APPL_DATA) VersionInfo)
{
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    /* If VersionInfo is NULL */
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_IPC_MODULE_ID,CDD_IPC_INSTANCE_ID,CDD_IPC_SID_GET_VERSION_INFO,\
                                                                         CDD_IPC_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = (uint16)CDD_IPC_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)CDD_IPC_MODULE_ID ;
        VersionInfo->instanceID       = (uint8)CDD_IPC_INSTANCE_ID ;
        VersionInfo->sw_major_version = (uint8)CDD_IPC_SW_MAJOR_VERSION ;
        VersionInfo->sw_minor_version = (uint8)CDD_IPC_SW_MINOR_VERSION ;
        VersionInfo->sw_patch_version = (uint8)CDD_IPC_SW_PATCH_VERSION ;
    }
    return;
}
#endif

/*
 * Design: MCAL-
 */
FUNC(void, CDD_IPC_CODE) Cdd_Ipc_Init(P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONFIG_DATA) ConfigPtr)
{
    /* Config pointer initialised with NULL_PTR */
    P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONFIG_DATA) config_ptr = NULL_PTR;
#if (STD_ON == CDD_IPC_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        config_ptr = &CDD_IPC_PRE_COMPILE_VARIANT_CONFIG;
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        config_ptr = ConfigPtr;
    }
#endif /*CDD_IPC_PRE_COMPILE_VARIANT*/

    /* Cdd_Ipc module must not be initialized. Otherwise call the Det with CDD_IPC_E_ALREADY_INITIALIZED */
    if (TRUE == Cdd_Ipc_IsInitialized)
    {
        #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, 
        CDD_IPC_SID_INIT, CDD_IPC_E_ALREADY_INITIALIZED);
        #endif /* STD_ON == CDD_IPC_DEV_ERROR_DETECT */ 
    }
    else if (NULL_PTR == config_ptr)
    {
        #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)      
        /* API is being called with invalid config param */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, 
            CDD_IPC_SID_INIT, CDD_IPC_E_PARAM_POINTER);   
        #endif /* STD_ON == CDD_IPC_DEV_ERROR_DETECT */    
    }
    else
    {
        /* Save the pointer to configuration */
        Cdd_Ipc_CfgPtr = config_ptr;
        Cdd_Ipc_SetCfgObj(Cdd_Ipc_CfgPtr);
        /* Set Init Done flag */
        Cdd_Ipc_IsInitialized = TRUE;
    }
}

/*
 * Design: MCAL-
 */
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_Sync(VAR(Cdd_Ipc_RemoteCoreType, AUTOMATIC) RemoteCore)
{
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_NOT_OK;

#if(CDD_IPC_DEV_ERROR_DETECT == STD_ON)
    if(Cdd_Ipc_IsInitialized == FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_SYNC, CDD_IPC_E_UNINIT);
    }
    else if ((RemoteCore == Cdd_Ipc_CfgPtr->Cdd_Ipc_LocalCore) || (RemoteCore > CDD_IPC_CORE_COUNT))
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_SYNC, CDD_IPC_E_PARAM_VALUE);
    }
    else
#endif
    {
        return_val = Cdd_Ipc_Sync_Process(RemoteCore);
    }

    return return_val;
}

/*
 * Design: MCAL-
 */
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_Transmit
(VAR(PduIdType , AUTOMATIC) ChannelId, P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_NOT_OK;

#if(CDD_IPC_DEV_ERROR_DETECT == STD_ON)
    if(Cdd_Ipc_IsInitialized == FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_TRANSMIT, CDD_IPC_E_UNINIT);
    }
    else if(FALSE == Cdd_Ipc_IsChannelIdValid(ChannelId))
    {
        /* Report Det error if ChannelId is not configured */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_TRANSMIT, CDD_IPC_E_PARAM_VALUE);
    }
    else if(E_NOT_OK == Cdd_Ipc_TransmitPduDetCheck(PduInfoPtr))
    {
        /* Cdd_Ipc_TransmitPduDetCheck() reports Det error if PduInfoPtr is invalid */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Ipc_CDD_IPC_EXCLUSIVE_AREA_0();
        return_val = Cdd_Ipc_Transmit_Priv(ChannelId, PduInfoPtr);
        SchM_Exit_Cdd_Ipc_CDD_IPC_EXCLUSIVE_AREA_0();
    }

    return return_val;
}

FUNC(void, CDD_IPC_CODE) Cdd_Ipc_MainFunction_Read(void)
{
    VAR(uint8, AUTOMATIC) channel_index = (uint8)0U;
    VAR(PduInfoType, AUTOMATIC) pduinfo;
    VAR(uint8, AUTOMATIC) databuffer[CDD_IPC_MAX_SIZE] = {0U};
    pduinfo.SduDataPtr = databuffer;

    for (uint8 instance_index = 0U; instance_index < CDD_IPC_RX_INSTANCE_COUNT; instance_index++)
    {
        if(TRUE == Cdd_Ipc_GetChannelPollingStatus(instance_index, &channel_index))
        {
            SchM_Enter_Cdd_Ipc_CDD_IPC_EXCLUSIVE_AREA_1();
            Cdd_Ipc_ReadChannelPriv(instance_index, &pduinfo);
            Cdd_Ipc_Acknowledge(Cdd_Ipc_CfgPtr->Cdd_Ipc_RxInstanceConfig[instance_index].Cdd_Ipc_RxInstance);
            SchM_Exit_Cdd_Ipc_CDD_IPC_EXCLUSIVE_AREA_1();
            Cdd_Ipc_RxIndication(instance_index, channel_index, &pduinfo);
        }
    }
}

FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_IsTxInstanceFree(VAR(PduIdType , AUTOMATIC) ChannelId)
{
    VAR(boolean, AUTOMATIC) return_val = FALSE;

#if(CDD_IPC_DEV_ERROR_DETECT == STD_ON)
    if(Cdd_Ipc_IsInitialized == FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, 
             CDD_IPC_IS_TX_INSTANCE_FREE, CDD_IPC_E_UNINIT);
    }
    else if(FALSE == Cdd_Ipc_IsChannelIdValid(ChannelId))
    {
        /* Report Det error if ChannelId is not configured */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, 
            CDD_IPC_IS_TX_INSTANCE_FREE, CDD_IPC_E_PARAM_VALUE);
    }
    else
#endif
    {
        return_val = Cdd_Ipc_InstanceStatus(ChannelId);
    }
    
    return return_val;
}

FUNC(uint64 , CDD_IPC_CODE) Cdd_Ipc_GetCounter(void)
{
    VAR(uint64, AUTOMATIC) return_val;

     return_val = Cdd_Ipc_ReadCounter();
    
    return return_val;
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_TransmitPduDetCheck
(P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_OK;

    if((NULL_PTR == PduInfoPtr) || ((PduInfoPtr->SduLength != 0U) && (NULL_PTR == PduInfoPtr->SduDataPtr)))
    {
        /* Report Det error if PduInfoPtr is NULL */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_TRANSMIT, CDD_IPC_E_PARAM_POINTER);
        return_value = E_NOT_OK;
    }
    else if (PduInfoPtr->SduLength > CDD_IPC_MAX_SIZE)
    {
        /* Report Det error if Pdu length is greater than 12 bytes */
        (void)Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID, CDD_IPC_SID_TRANSMIT, CDD_IPC_E_INVALID_LENGTH);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return return_value;
}
#endif
/*********************************************************************************************************************
 *  End of File: Cdd_Ipc.c
 *********************************************************************************************************************/
