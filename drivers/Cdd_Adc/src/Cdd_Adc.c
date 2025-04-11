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
 *  File:       Cdd_Adc
 *  Generator:  None
 *
 *  Description: This file contains CDD ADC driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Priv.h"
#include "SchM_Cdd_Adc.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_ADC_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_ADC_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_ADC_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version of CDD_ADC is incorrect"
#endif

/* vendor specific version information check */

#if ((CDD_ADC_SW_MAJOR_VERSION != (2U)) || (CDD_ADC_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Adc.c and Cdd_Adc.h are not matching!"
#endif

#if ((CDD_ADC_CFG_MAJOR_VERSION != (2U)) || (CDD_ADC_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Adc.c and Cdd_Adc_Cfg.h are not matching!"
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

/* Cdd_Adc Driver initialization variable */
#define CDD_ADC_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Adc_MemMap.h"
static VAR(boolean,CDD_ADC_VAR_INIT) Cdd_Adc_IsInitialized = FALSE;
#define CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Adc_MemMap.h"

/* Cdd_Adc driver object to store hardware unit status. */
#define CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"
static VAR(Cdd_Adc_DriverObjType,CDD_ADC_VAR_FAST_INIT) Cdd_Adc_DrvObj;
#define CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"

/* Cdd_Adc configuration pointer to access driver configuration. */
#define CDD_ADC_START_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"
P2CONST(Cdd_Adc_ConfigType,AUTOMATIC,CDD_ADC_CONST) Cdd_Adc_CfgPtr = NULL_PTR;
#define CDD_ADC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_ADC_START_SEC_CODE
#include "Cdd_Adc_MemMap.h"
/*
 * Design: MCAL-
 */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_Init(P2CONST(Cdd_Adc_ConfigType,AUTOMATIC, CDD_ADC_CFG) CfgPtr)
{
#if(CDD_ADC_DEV_ERROR_DETECT == STD_ON)
    if(Cdd_Adc_IsInitialized != FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_INIT,CDD_ADC_E_ALREADY_INITIALIZED);
    }
    else if (CfgPtr != NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_INIT,CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        Cdd_Adc_CfgPtr = &CDD_ADC_CONFIG_PC;
        Cdd_Adc_SetDrvObj(&Cdd_Adc_DrvObj,Cdd_Adc_CfgPtr);
        /* Initialize the driver object */
        Cdd_Adc_DrvObjInit();
        /* Initialize the ADC HW Unit */
        Cdd_Adc_HwUnitInit();
        Cdd_Adc_IsInitialized = TRUE;   /* Update the initialized flag to true */
    }
    return;
}

FUNC(Std_ReturnType,CDD_ADC_CODE) Cdd_Adc_SetupResultBuffer(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group,\
    P2CONST(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr)
{
    Std_ReturnType return_val = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SETUP_RESULT_BUFFER,CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SETUP_RESULT_BUFFER,\
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if (NULL_PTR == DataBufferPtr)
    {
        /* Report DET error if data buffer pointer is NULL */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SETUP_RESULT_BUFFER,\
                                CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Report runtime error if the group status not IDLE */
        if (CDD_ADC_IDLE != Cdd_Adc_DrvObj.group_obj[Group].grp_status)
        {
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SETUP_RESULT_BUFFER,\
                                        CDD_ADC_E_BUSY);
        }
        else
        {
            /* Set the result buffer pointer */
            Cdd_Adc_DrvObj.group_obj[Group].resbuffer = DataBufferPtr;
            Cdd_Adc_DrvObj.group_obj[Group].cur_resultptr = \
                        (Cdd_Adc_ValueGroupType*)(Cdd_Adc_DrvObj.group_obj[Group].resbuffer);
            return_val = E_OK;
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;
}

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_ADC_DATA) VersionInfo)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    /* If VersionInfo is NULL */
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_VERSION_INFO,\
                                CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = CDD_ADC_VENDOR_ID;
        VersionInfo->moduleID         = CDD_ADC_MODULE_ID ;
        VersionInfo->instanceID       = CDD_ADC_INSTANCE_ID ;
        VersionInfo->sw_major_version = (uint8)CDD_ADC_SW_MAJOR_VERSION ;
        VersionInfo->sw_minor_version = (uint8)CDD_ADC_SW_MINOR_VERSION ;
        VersionInfo->sw_patch_version = (uint8)CDD_ADC_SW_PATCH_VERSION ;
    }
    return;
}
#endif

/*
 * Design: MCAL- 
 */
#if (STD_ON == CDD_ADC_DEINIT_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_DeInit(void)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DEINIT,CDD_ADC_E_UNINIT);
    }
    else
#endif
    {
        /* Deinitialize the ADC HW Unit */
        Cdd_Adc_HwUnitDeinit();
        Cdd_Adc_IsInitialized = FALSE;
    }
    return;
}
#endif  

#if (STD_ON == CDD_ADC_ENABLE_START_STOP_GROUP_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_StartGroupConversion(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_StartGroupConversion */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GROUP_CONVERSION,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GROUP_CONVERSION,\
                                CDD_ADC_E_PARAM_GROUP); 
    }
    else if (Cdd_Adc_DrvObj.group_obj[Group].resbuffer == NULL_PTR)
    {
        /* Report DET error if result buffer is NULL when Cdd_Adc_StartGroupConversion is called*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GROUP_CONVERSION,\
                                CDD_ADC_E_BUFFER_UNINIT);
    }
    else if (CDD_ADC_TRIGG_SRC_HW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET when Cdd_Adc_StartGroupConversion is called on a group with hardware trigger source */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GROUP_CONVERSION,\
                                CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if((Cdd_Adc_DrvObj.group_obj[Group].triggersrc == CDD_ADC_GRP_TRIGG_SRC_SW) && \
            ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE) || \
            ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED) && \
            (Cdd_Adc_DrvObj.group_obj[Group].implicit_stop == TRUE))))
        {
            /* Call the start group API only when the trigger source is software */
            Cdd_Adc_StartGroup(Group);
        }
        else
        {
            /* Report DET error if the ADC is busy or the group is not stopped by global software trigger after use */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GROUP_CONVERSION,\
                                            CDD_ADC_E_BUSY);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ;
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopGroupConversion(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_StopGroupConversion */
       (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GROUP_CONVERSION,CDD_ADC_E_UNINIT);
    }
    else if(Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GROUP_CONVERSION,\
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if (CDD_ADC_TRIGG_SRC_HW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET error if trigger source is wrong */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GROUP_CONVERSION,\
                                CDD_ADC_E_WRONG_TRIGG_SRC);  
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if(Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE)
        {
            /* Report DET error if the group is IDLE or is called for the group started by Cdd_Adc_StartGlobalSwTrig */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GROUP_CONVERSION,\
                                            CDD_ADC_E_IDLE);
        }
        else if(Cdd_Adc_DrvObj.group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_SW)
        {
            /* Report DET error if the group is started by global software trigger but stopped using 
                Cdd_Adc_StopGroupConversion API */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GROUP_CONVERSION,\
                                            CDD_ADC_E_BUSY);
        }
        else
        {
            /* Call the stop group API */
            Cdd_Adc_StopGroup(Group);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;
}
#endif  

#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
/* This API configures the Global software Trigger */
FUNC(Std_ReturnType,CDD_ADC_CODE) Cdd_Adc_StartGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType,AUTOMATIC) GlbSwTrig)
{
    Std_ReturnType return_val = E_OK;
    Cdd_Adc_GlbSwCfgType glbsw;
    Cdd_Adc_GroupType group_id;
    uint16 groupmask;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GLBSW_TRIG,CDD_ADC_E_UNINIT);
        return_val = E_NOT_OK;
    }
    else if(GlbSwTrig >= CDD_ADC_GLBSW_TRIG_CNT)
    {
        /* Report DET error if the global software trigger symbolic ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GLBSW_TRIG,CDD_ADC_E_INVALID_ID);
        return_val = E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        glbsw = Cdd_Adc_CfgPtr->glbtrigcfg[GlbSwTrig];
        group_id = 0U;
        for(groupmask = glbsw.group_mask;((groupmask > 0U)&&(group_id<CDD_ADC_GROUP_CNT));(groupmask = groupmask>>1U))
        {
            if((groupmask & 1U) != 0U)
            {
                if(((Cdd_Adc_DrvObj.group_obj[group_id].grp_status != CDD_ADC_COMPLETED) && \
                        (Cdd_Adc_DrvObj.glbsw_obj[GlbSwTrig].status == TRUE)) || \
                    ((Cdd_Adc_DrvObj.group_obj[group_id].grp_status != CDD_ADC_IDLE) && \
                        (Cdd_Adc_DrvObj.glbsw_obj[GlbSwTrig].status == FALSE)))
                {
                    /* Report runtime error if the group conversion is not done for the previous API call or when the 
                        group is not in IDLE state and the API is called after StopGlobalSwTrig API */
                    (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,\
                    CDD_ADC_SID_START_GLBSW_TRIG,CDD_ADC_E_BUSY);
                    return_val = E_NOT_OK;
                    break;
                }
            #if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
                else if((Cdd_Adc_DrvObj.glbsw_obj[GlbSwTrig].status != TRUE) && \
                        (Cdd_Adc_DrvObj.group_obj[group_id].resbuffer == NULL_PTR))
                {
                    /* Report DET error if the result buffer is NULL for any one of the groups and this check
                        * is not when the API is called more than once without calling StopGlobalSwTrig API.
                        */
                    (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_GLBSW_TRIG,\
                                            CDD_ADC_E_BUFFER_UNINIT);
                    return_val = E_NOT_OK;
                    break;
                }
            #endif
                else
                {
                    /* Move to the next group if all the checks are passed */
                }
            }
            else
            {
                /* Skip the group if not configured for the specified global software trigger */
            }
            group_id++;
        }

        if(return_val == E_OK)
        {
            /* Trigger the global software trigger for the configured hardware units if no errors are reported. */
            Cdd_Adc_StartGlbTrig(GlbSwTrig);
        }
        else
        {
            /* Return E_NOT_OK in all other cases */
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType,AUTOMATIC) GlbSwTrig)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GLBSW_TRIG,CDD_ADC_E_UNINIT);
    }
    else if(GlbSwTrig >= CDD_ADC_GLBSW_TRIG_CNT)
    {
        /* Report DET error if the global software trigger symbolic ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GLBSW_TRIG,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if(Cdd_Adc_DrvObj.glbsw_obj[GlbSwTrig].status == FALSE)
        {
            /* Report runtime error when this API is called without calling Cdd_Adc_StartGlobalSwTrig API */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_GLBSW_TRIG,\
                                        CDD_ADC_E_IDLE);
        }
        else
        {
            Cdd_Adc_StopGlbTrig(GlbSwTrig);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}
#endif


#if (CDD_ADC_HW_TRIGGER_API == STD_ON)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_EnableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_EnableHardwareTrigger */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if (Cdd_Adc_DrvObj.group_obj[Group].resbuffer == NULL_PTR)
    {
        /* Report DET error if result buffer is NULL when Cdd_Adc_EnableHardwareTrigger is called*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_BUFFER_UNINIT); 
    }
    else if (CDD_ADC_TRIGG_SRC_SW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else if (CDD_ADC_CONV_MODE_CONTINUOUS == Cdd_Adc_CfgPtr->groupcfg[Group].conversion_mode)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_WRONG_CONV_MODE);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE) || \
            ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED) && \
                (Cdd_Adc_DrvObj.group_obj[Group].implicit_stop == TRUE)))
        {
            /* Call the start group API */
            Cdd_Adc_StartGroup(Group);
        }
        else
        {
            /* Report DET error if Adc is BUSY */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,\
                                            CDD_ADC_E_BUSY);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return; 
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_DisableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_DisableHardwareTrigger */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if (CDD_ADC_TRIGG_SRC_SW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else if (CDD_ADC_CONV_MODE_CONTINUOUS == Cdd_Adc_CfgPtr->groupcfg[Group].conversion_mode)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,\
                                CDD_ADC_E_WRONG_CONV_MODE);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if(Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE)
        {
            /* The group is not enabled with a previous call of Cdd_Adc_EnableHardwareTrigger */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,\
                                            CDD_ADC_E_IDLE);
        }
        else
        {
            /* Call the stop group private function. */
            Cdd_Adc_StopGroup(Group);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;     
}
#endif

/* Service to get the status of the group. */
FUNC(Cdd_Adc_StatusType,CDD_ADC_CODE) Cdd_Adc_GetGroupStatus(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group)
{
    Cdd_Adc_StatusType group_status = CDD_ADC_IDLE;
#if(STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_GRP_STATUS,CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_GRP_STATUS,CDD_ADC_E_PARAM_GROUP);
    }
    else 
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Return the status of the requested group */
        group_status = Cdd_Adc_DrvObj.group_obj[Group].grp_status;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return group_status;
}


#if (STD_ON == CDD_ADC_READ_GROUP_API)

FUNC(Std_ReturnType,CDD_ADC_CODE) Cdd_Adc_ReadGroup(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group,\
                            P2VAR(Cdd_Adc_ValueGroupType,AUTOMATIC,CDD_ADC_DATA) DataBufferPtr)
{
    Std_ReturnType return_val = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_ReadGroup */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_GROUP,CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_GROUP,CDD_ADC_E_PARAM_GROUP);
    }
    else if (NULL_PTR == DataBufferPtr)
    {
        /* Report DET error if data buffer pointer is NULL */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_GROUP,CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {  
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if(((CDD_ADC_IDLE == Cdd_Adc_DrvObj.group_obj[Group].grp_status) && \
            (Cdd_Adc_DrvObj.group_obj[Group].valid_samples == 0U)))
        {
            /*Report DET error if required group to read is IDLE */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_GROUP,CDD_ADC_E_IDLE);
        }
        else if((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_COMPLETED) || \
                    (Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED))
        {
            /* If the group is not in COMPLETED or STREAM_COMPLETED state then read the group result */
            Cdd_Adc_ReadGroupResult(Group,DataBufferPtr);
            return_val = E_OK;
        }
        else
        {
            /* If no conversion results are available return E_NOT_OK when group is in IDLE & BUSY state */
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;     
}
#endif

#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_EnableGroupNotification(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling CDD_Adc_EnableGroupNotification */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,\
                                        CDD_ADC_E_PARAM_GROUP);
    }
    else if ((Cdd_Adc_GroupEndNotifyType)NULL_PTR == Cdd_Adc_CfgPtr->groupcfg[Group].groupend_notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,\
                                CDD_ADC_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        Cdd_Adc_DrvObj.group_obj[Group].grp_notification =  TRUE;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_DisableGroupNotification(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_DisableGroupNotification */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,\
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if ((Cdd_Adc_GroupEndNotifyType)NULL_PTR == Cdd_Adc_CfgPtr->groupcfg[Group].groupend_notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,\
                                            CDD_ADC_E_NOTIF_CAPABILITY);
    }    
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Disable group notification capability. */
        Cdd_Adc_DrvObj.group_obj[Group].grp_notification = FALSE;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;
}
#endif 

FUNC(Cdd_Adc_StreamNumSampleType,CDD_ADC_CODE) Cdd_Adc_GetStreamLastPointer(VAR(Cdd_Adc_GroupType,AUTOMATIC) Group,\
                                                P2VAR(Cdd_Adc_ValueGroupType,AUTOMATIC,CDD_ADC_DATA) *PtrToSamplePtr)
{
    Cdd_Adc_StreamNumSampleType num_samples = 0U;
    Cdd_Adc_StatusType grp_status;
#if(STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        *PtrToSamplePtr = (Cdd_Adc_ValueGroupType*)NULL_PTR;
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_STREAM_LAST_POINTER,\
                                CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        *PtrToSamplePtr = (Cdd_Adc_ValueGroupType*)NULL_PTR;
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_STREAM_LAST_POINTER,\
                                CDD_ADC_E_PARAM_GROUP);
    }
    else if(PtrToSamplePtr == NULL_PTR)
    {
        /* Report DET error if the PtrToSamplePtr is NULL_PTR */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_STREAM_LAST_POINTER,\
                                CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        grp_status = Cdd_Adc_DrvObj.group_obj[Group].grp_status;
        if((grp_status == CDD_ADC_COMPLETED) || (grp_status == CDD_ADC_STREAM_COMPLETED) || \
                ((Cdd_Adc_CfgPtr->groupcfg[Group].access_mode == CDD_ADC_ACCESS_MODE_SINGLE) && \
                    (Cdd_Adc_DrvObj.group_obj[Group].valid_samples != 0U)))
        {
            /* Get valid samples count only when the group is in COMPLETED or STREAM_COMPLETED state or for single 
                access groups if the valid samples are stored in the result buffer */
            num_samples = Cdd_Adc_GetValidSampleCnt(Group,PtrToSamplePtr);
        }
        else if((grp_status == CDD_ADC_IDLE) && (Cdd_Adc_DrvObj.group_obj[Group].valid_samples == 0U))
        {
            *PtrToSamplePtr = (Cdd_Adc_ValueGroupType*)NULL_PTR;
            /* Report DET error if the ADC is IDLE and no results are available from previous conversions */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_STREAM_LAST_POINTER,\
                                            CDD_ADC_E_IDLE);
        }
        else
        {
            /* If group status id IDLE or BUSY then return 0(valid samples) and set the PtrToSamplePtr to NULL_PTR */
            *PtrToSamplePtr = (Cdd_Adc_ValueGroupType*)NULL_PTR;
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return (num_samples);
}

#if(STD_ON == CDD_ADC_SET_RESOLUTION_API) 
/*
 * API to set the resolution 
 */
FUNC(Std_ReturnType,CDD_ADC_CODE) 
Cdd_Adc_SetResolution(VAR(Cdd_Adc_HwUnitInstanceType,AUTOMATIC)HwUnit,VAR(Cdd_Adc_ResolutionType,AUTOMATIC) Resolution)
{
    Std_ReturnType return_value = E_NOT_OK;
    uint32 baseaddr;
    Cdd_Adc_GroupType group;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
       (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SET_RESOLUTION,CDD_ADC_E_UNINIT);
    }
    else if(HwUnit >= CDD_ADC_HW_CNT)
    {
        /* Report DET error if the specified hardware unit ID doesn't exist */
       (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SET_RESOLUTION,CDD_ADC_E_INVALID_ID);
    }
    else if(((Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].hwunit_id == CDD_ADCC) || \
        (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].hwunit_id == CDD_ADCD) || \
        (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].hwunit_id == CDD_ADCE) || \
        ((Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltrefmode == CDD_ADC_REFERENCE_INTERNAL) && \
        (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltref == CDD_ADC_REFERENCE_3_3V)))\
                 && (Resolution == CDD_ADC_RESOLUTION_16BIT))
    {
        /* Report DET error if resolution requested is not supported by the specified ADC and 
            internal 3.3V reference mode is not supported in 16-bit resolution mode */
       (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SET_RESOLUTION,\
                                CDD_ADC_E_WRONG_RESOLUTION_MODE);
    }
    else
#endif
    {
        if(Cdd_Adc_DrvObj.hwunit_obj[HwUnit].cur_resolution == Resolution)
        {
            /* Report DET error if the Adc was already configured with the requested resolution. */
            (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SET_RESOLUTION,\
                                            CDD_ADC_E_ALREADY_SET);
        }
        else
        {
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            /* Report Det runtime error if any of the group is in IDLE state */
            for(group = Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].startgroupnum;\
                ((group <= Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].lastgroupnum) && (group < CDD_ADC_GROUP_CNT));group++)
            {
                if(Cdd_Adc_DrvObj.group_obj[group].grp_status != CDD_ADC_IDLE)
                {
                    /* Check if the group is in IDLE state, else report det runtime error */
                    (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_SET_RESOLUTION,\
                                                    CDD_ADC_E_BUSY);
                    break;
                }
                else
                {
                    /* Skip to the next group if the group is in IDLE state */
                }
            }

            /* When all the groups are IDLE, the group ID exceeds the last group number of the hardware unit */
            if(group > Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].lastgroupnum)
            {
                /* Set the resolution of the specified hardware unit. */
                baseaddr = Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].base_addr;
                Cdd_Adc_SetMode(baseaddr,Resolution,Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].signal_mode);
                Cdd_Adc_DrvObj.hwunit_obj[HwUnit].cur_resolution = Resolution;
                return_value = E_OK; /* Return E_OK if the resolution configuration is successful */
            }
            else
            {
                /* If any of the groups is BUSY then return the function without any action */
            }
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
    }
    return return_value;    
}
#endif 

#if(STD_ON == CDD_ADC_SAFETY_CHECK_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_StartResultChecker(VAR(Cdd_Adc_CheckerType,AUTOMATIC) CheckerId)
{
    uint32 base_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_RESULT_CHECKER,CDD_ADC_E_UNINIT);
    }
    else if (CheckerId >= CDD_ADC_CHECKER_CNT)
    {
        /* Report DET error if the checker ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_RESULT_CHECKER,\
                                CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        /* Base address of the safety checker unit */
        base_addr = Cdd_Adc_CfgPtr->checkercfg.checkerunitcfg[CheckerId].base_addr;
        if(Cdd_Adc_GetCheckerStatus(base_addr) == TRUE)
        {
            /* Report DET error if safety checker is already ENABLED */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_START_RESULT_CHECKER,\
                                            CDD_ADC_E_CHECKER_BUSY);
        }
        else
        {
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            /* Enable the specified result safety checker tile */                        
            Cdd_Adc_ConfigureCheckerTile(base_addr,TRUE);
            /* Force Software sync */
            Cdd_Adc_ForceSafetyCheckerSync(base_addr);
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
    }
    return;    
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopResultChecker(VAR(Cdd_Adc_CheckerType,AUTOMATIC) CheckerId)
{
    uint32 base_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_RESULT_CHECKER,CDD_ADC_E_UNINIT);
    }
    else if (CheckerId >= CDD_ADC_CHECKER_CNT)
    {
        /* Report DET error if the checker ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_RESULT_CHECKER,\
                                CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        /*Base address of the safety checker unit*/
        base_addr = Cdd_Adc_CfgPtr->checkercfg.checkerunitcfg[CheckerId].base_addr;
        if(Cdd_Adc_GetCheckerStatus(base_addr) == TRUE)
        {
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            Cdd_Adc_StopChecker(CheckerId);
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Report DET error if checker is not enabled */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_STOP_RESULT_CHECKER,\
                                            CDD_ADC_E_CHECKER_IDLE);
        }
    }
    return;    
}

/* This function will point to the structure which stores the flag status of all the safety checker units */
FUNC(void,CDD_ADC_CODE) 
Cdd_Adc_ReadCheckerStatus(VAR(Cdd_Adc_CheckerIntEvtType,AUTOMATIC) IntEvt,\
        P2VAR(Cdd_Adc_CheckFlagStatusType,AUTOMATIC,CDD_ADC_DATA) CheckerFlag)
{
    uint16 status;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_RESULT_CHECKER,CDD_ADC_E_UNINIT);
    }
    else if (IntEvt >= CDD_ADC_CHECKER_INTEVT_CNT)
    {
        /* Report DET error if interrupt event ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_RESULT_CHECKER,\
                                CDD_ADC_E_INVALID_ID);
    }
    else if ((CheckerFlag == NULL_PTR) || ((CheckerFlag + CDD_ADC_CHECKER_CNT) == NULL_PTR))
    {
        /* Report DET error if the passed pointer is NULL and the buffer doesn't have enough space */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_RESULT_CHECKER,\
                                CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        status = Cdd_Adc_GetSafetyCheckIntStatus(Cdd_Adc_CfgPtr->checkercfg.checkerintevtcfg[IntEvt].base_addr);
        /* Check if the interrupt flag is set */
        if(TRUE == ((uint8)status))
        {
            /* This functions returns the interrupt source event flag for each safety checker */
            Cdd_Adc_CheckerIsr(IntEvt,CheckerFlag);
        }
        else
        {
            /* Don't perform any action if the interrupt flag is not set */
        }
    }
    return;    
}

/* This function will point to the structure which stores the flag status of all the safety checker units */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearCheckerEvt(VAR(Cdd_Adc_CheckerIntEvtType,AUTOMATIC) IntEvt,\
                VAR(Cdd_Adc_CheckerEventType,AUTOMATIC) Event_Id)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_CLEAR_CHECKER_EVT,CDD_ADC_E_UNINIT);
    }
    else if (IntEvt >= CDD_ADC_CHECKER_INTEVT_CNT)
    {
        /* Report DET error if interrupt event ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_CLEAR_CHECKER_EVT,\
                                CDD_ADC_E_INVALID_ID);
    }
    else if((uint8)Event_Id >= CDD_ADC_CHECKER_EVT_CNT)
    {
         /* Report DET error if the event ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_CLEAR_CHECKER_EVT,\
                                CDD_ADC_E_PARAM_CONFIG);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Clear flags that generated the event */
        Cdd_Adc_ClearCheckerStatus(IntEvt,Event_Id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;    
}
#endif

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
FUNC(Cdd_Adc_PpbValType,CDD_ADC_CODE) Cdd_Adc_ReadPartialPpbValue(VAR(Cdd_Adc_PpbType,AUTOMATIC) PpbId)
{
    Cdd_Adc_PpbValType ppbval = {((sint32)0),((sint32)0),((sint32)0),((uint16)0U),((uint16)0U),((uint16)0U)};
    uint32 result_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PARTIAL_PPB_VALUE,\
                                CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PARTIAL_PPB_VALUE,\
                                CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        result_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].base_addr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppbval.ppbmin   = Cdd_Adc_ReadPpbPMin(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmax   = Cdd_Adc_ReadPpbPMax(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbsum   = Cdd_Adc_ReadPpbPSum(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbcount = Cdd_Adc_ReadPpbPCount(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmaxindex = Cdd_Adc_ReadPpbPMaxIndex(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbminindex = Cdd_Adc_ReadPpbPMinIndex(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ppbval;
}

FUNC(Cdd_Adc_PpbValType,CDD_ADC_CODE) Cdd_Adc_ReadPpbValue(VAR(Cdd_Adc_PpbType,AUTOMATIC) PpbId)
{
    Cdd_Adc_PpbValType ppbval = {((sint32)0),((sint32)0),((sint32)0),((uint16)0U),((uint16)0U),((uint16)0U)};
    uint32 result_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PPB_VALUE,CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PPB_VALUE,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        result_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].result_baseaddr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppbval.ppbmin   = Cdd_Adc_ReadPpbMin(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmax   = Cdd_Adc_ReadPpbMax(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbsum   = Cdd_Adc_ReadPpbSum(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbcount = Cdd_Adc_ReadPpbCount(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmaxindex = Cdd_Adc_ReadPpbMaxIndex(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbminindex = Cdd_Adc_ReadPpbMinIndex(result_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
   return ppbval;    
}

FUNC(sint32,CDD_ADC_CODE) Cdd_Adc_ReadPpb(VAR(Cdd_Adc_PpbType,AUTOMATIC) PpbId)
{
    sint32 ppb_result = (sint32)0;
    uint32 resultbaseaddr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PPB,CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_READ_PPB,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        resultbaseaddr = Cdd_Adc_CfgPtr->hwunitcfg[(Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex)].result_baseaddr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppb_result = Cdd_Adc_ReadPpbResult(resultbaseaddr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ppb_result;
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearPpbEvt(VAR(Cdd_Adc_PpbType,AUTOMATIC) PpbId)
{
    uint32 base_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_CLEAR_PPB_EVT,CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_CLEAR_PPB_EVT,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        base_addr = Cdd_Adc_CfgPtr->hwunitcfg[(Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex)].base_addr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        Cdd_Adc_ClearPpbEvtStatus(base_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id,\
                                    Cdd_Adc_CfgPtr->ppbcfg[PpbId].tripevtsel);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return;
}

FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_GetDelayStamp(VAR(Cdd_Adc_PpbType,AUTOMATIC) PpbId)
{
    uint16 delay_stamp = 0U;
    uint32 base_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_DELAY_STAMP,CDD_ADC_E_UNINIT);
    }
    else if(PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_DELAY_STAMP,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        base_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].base_addr;
        if(Cdd_Adc_ReadSocTrigSrc(base_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].soc_num) == CDD_ADC_TRIGGER_SW_ONLY)
        {
            /* This function should be called only for the SOCs configured for the hardware trigger source. */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_DELAY_STAMP,\
                                            CDD_ADC_E_WRONG_TRIGG_SRC);
        }
        else
        {
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            delay_stamp = Cdd_Adc_GetPpbDelayTimeStamp(base_addr,Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
    }
    return delay_stamp;    
}
#endif

#if(STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE) 
FUNC(sint16,CDD_ADC_CODE) Cdd_Adc_GetTemperatureC(VAR(Cdd_Adc_HwUnitInstanceType,AUTOMATIC) HwUnit,\
        VAR(Cdd_Adc_ValueGroupType,AUTOMATIC) TempResult)
{
    sint16 temp_value = 0;
    float32 vref = 0.0f,temp = 0.0f;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_TEMPERATURE_C,CDD_ADC_E_UNINIT);
    }
    else if(HwUnit >= CDD_ADC_HW_CNT)
    {
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_TEMPERATURE_C,\
                                CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        vref = (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltref == CDD_ADC_REFERENCE_3_3V)?(3.3F):(2.5F);
        /* Read temp sensor slope and offset locations from OTP and convert */ 
        temp = ((float32)TempResult * ((float32)vref/2.5F));
        if(Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltrefmode == CDD_ADC_REFERENCE_INTERNAL)
        {
            temp_value = (sint16)((((sint32)temp - CDD_ADC_INT_REF_TSOFFSET)*4096)/CDD_ADC_INT_REF_TSSLOPE);
        }
        else
        {
            temp_value = (sint16)((((sint32)temp - CDD_ADC_EXT_REF_TSOFFSET)*4096)/CDD_ADC_EXT_REF_TSSLOPE);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return temp_value;
}

FUNC(sint16,CDD_ADC_CODE) Cdd_Adc_GetTemperatureK(VAR(Cdd_Adc_HwUnitInstanceType,AUTOMATIC) HwUnit,\
        VAR(Cdd_Adc_ValueGroupType,AUTOMATIC) TempResult)
{
    sint16 temp_value = 0;
    float32 vref = 0.0f,temp = 0.0f;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_TEMPERATURE_K,CDD_ADC_E_UNINIT);
    }
    else if(HwUnit >= CDD_ADC_HW_CNT)
    {
       (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_GET_TEMPERATURE_K,CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        vref = (float32)((Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltref == CDD_ADC_REFERENCE_3_3V)?(3.3F):(2.5F));
        /*  Read temp sensor slope and offset locations from OTP and convert */
        temp = ((float32)TempResult * ((float32)vref/2.5F));
        if(Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltrefmode == CDD_ADC_REFERENCE_INTERNAL)
        {
            temp_value = (sint16)(((((sint32)temp - CDD_ADC_INT_REF_TSOFFSET)*4096)/CDD_ADC_INT_REF_TSSLOPE) + 273);
        }
        else
        {
            temp_value = (sint16)(((((sint32)temp - CDD_ADC_EXT_REF_TSOFFSET)*4096)/CDD_ADC_EXT_REF_TSSLOPE) + 273);
        } 
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();    
    }
    return temp_value;
}
#endif

FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetInternalTestNode(VAR(Cdd_Adc_InternalTestNodeType,AUTOMATIC) TestNode)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_INTERNAL_TEST_NODE,CDD_ADC_E_UNINIT);
    }
    else if(TestNode >= CDD_ADC_TEST_NODE_MAX)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID,CDD_ADC_INSTANCE_ID,CDD_ADC_SID_INTERNAL_TEST_NODE,\
                                CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        Cdd_Adc_SelectInternalTestNode(TestNode);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}

#define CDD_ADC_STOP_SEC_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  End of File: Cdd_Adc.c
 *********************************************************************************************************************/
