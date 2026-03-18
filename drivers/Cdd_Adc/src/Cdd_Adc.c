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

#if ((CDD_ADC_SW_MAJOR_VERSION != (3U)) || (CDD_ADC_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Adc.c and Cdd_Adc.h are not matching!"
#endif

#if ((CDD_ADC_CFG_MAJOR_VERSION != (3U)) || (CDD_ADC_CFG_MINOR_VERSION != (0U)))
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
static VAR(boolean, CDD_ADC_VAR_INIT) Cdd_Adc_IsInitialized = FALSE;
#define CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Adc_MemMap.h"

/* Cdd_Adc driver object to store hardware unit status. */
#define CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"
static VAR(Cdd_Adc_DriverObjType, CDD_ADC_VAR_FAST_INIT) Cdd_Adc_DrvObj;
#define CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"

/* Cdd_Adc configuration pointer to access driver configuration. */
#define CDD_ADC_START_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"
P2CONST(Cdd_Adc_ConfigType, AUTOMATIC, CDD_ADC_CONST) Cdd_Adc_CfgPtr = NULL_PTR;
#define CDD_ADC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/* Design: MCAL-31314 */
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
/** \brief This function detects det errors in the Cdd_Adc_SetupResultBuffer & Cdd_Adc_ReadGroup APIs
 *
 * This function detects det errors in the Cdd_Adc_SetupResultBuffer & Cdd_Adc_ReadGroup APIs
 *
 * \param[in] Group Numeric ID of requested ADC Channel group
 * \param[in] DataBufferPtr Pointer to result data buffer
 * \param[in] ApiId API ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_BufferPtrDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                              P2CONST(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr,
                              VAR(uint8, AUTOMATIC) ApiId);

#if (STD_ON == CDD_ADC_ENABLE_START_STOP_GROUP_API)
/** \brief This function detects det errors in the Cdd_Adc_StartGroupConversion & Cdd_Adc_StopGroupConversion APIs
 *
 * This function detects det errors in the Cdd_Adc_StartGroupConversion & Cdd_Adc_StopGroupConversion APIs
 *
 * \param[in] Group Numeric ID of requested ADC Channel group
 * \param[in] ApiId API ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_SwGrpConvDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group, VAR(uint8, AUTOMATIC) ApiId);
#endif

#if (CDD_ADC_HW_TRIGGER_API == STD_ON)

/** \brief This function detects det errors for Cdd_Adc_EnableHardwareTrigger & Cdd_Adc_DisableHardwareTrigger APIs
 *
 * This function detects det errors for Cdd_Adc_EnableHardwareTrigger & Cdd_Adc_DisableHardwareTrigger APIs
 *
 * \param[in] Group Numeric ID of requested ADC Channel group
 * \param[in] ApiId API ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_HwGrpConvDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group, VAR(uint8, AUTOMATIC) ApiId);

/** \brief This function detects det errors in the Cdd_Adc_EnableHardwareTrigger API
 *
 * This function detects det errors in the Cdd_Adc_EnableHardwareTrigger API
 *
 * \param[in] Group Numeric ID of requested ADC Channel group
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_ADC_CODE) Cdd_Adc_HwGrpDetErrCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);
#endif

/** \brief This function detects det errors in the Cdd_Adc_GetStreamLastPointer API
 *
 * This function detects det errors in the Cdd_Adc_GetStreamLastPointer API
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \param[out] PtrToSamplePtr  Pointer to result buffer pointer.
 * \pre None
 * \post None
 * \return Returns if the result buffer setup is successful.
 * \retval  E_OK: result buffer pointer initialized correctly
 * \retval  E_NOT_OK: operation failed or development error occured
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_GetStreamPtrDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                                 P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) * PtrToSamplePtr);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_GetStreamPtrDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                                 P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) * PtrToSamplePtr)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        *PtrToSamplePtr = (Cdd_Adc_ValueGroupType *)NULL_PTR;
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_STREAM_LAST_POINTER,
                              CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        *PtrToSamplePtr = (Cdd_Adc_ValueGroupType *)NULL_PTR;
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_STREAM_LAST_POINTER,
                              CDD_ADC_E_PARAM_GROUP);
    }
    else if (PtrToSamplePtr == NULL_PTR)
    {
        /* Report DET error if the PtrToSamplePtr is NULL_PTR */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_STREAM_LAST_POINTER,
                              CDD_ADC_E_PARAM_POINTER);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_BufferPtrDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                              P2CONST(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr,
                              VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_PARAM_GROUP);
    }
    else if (NULL_PTR == DataBufferPtr)
    {
        /* Report DET error if data buffer pointer is NULL */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_PARAM_POINTER);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

#if (STD_ON == CDD_ADC_ENABLE_START_STOP_GROUP_API)
static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_SwGrpConvDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group, VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Adc_StartGroupConversion */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_PARAM_GROUP);
    }
    else if (CDD_ADC_TRIGG_SRC_HW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET when Cdd_Adc_StartGroupConversion is called on a group with hardware trigger source */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}
#endif

#if (CDD_ADC_HW_TRIGGER_API == STD_ON)

static FUNC(Std_ReturnType, CDD_ADC_CODE)
    Cdd_Adc_HwGrpConvDetCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group, VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_PARAM_GROUP);
    }
    else if (CDD_ADC_TRIGG_SRC_SW == Cdd_Adc_CfgPtr->groupcfg[Group].trigsrc_type)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, ApiId, CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_ADC_CODE) Cdd_Adc_HwGrpDetErrCheck(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_ADC_CONV_MODE_CONTINUOUS == Cdd_Adc_CfgPtr->groupcfg[Group].conversion_mode)
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,
                              CDD_ADC_E_WRONG_CONV_MODE);
    }
    else if ((Cdd_Adc_DrvObj.group_obj[Group].resbuffer == NULL_PTR) &&
             (FALSE == Cdd_Adc_CfgPtr->groupcfg[Group].dma_mode))
    {
        /* Report DET error if result buffer is NULL when Cdd_Adc_EnableHardwareTrigger is called*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,
                              CDD_ADC_E_BUFFER_UNINIT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

#endif
#endif

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_ADC_START_SEC_CODE
#include "Cdd_Adc_MemMap.h"

/* Design: MCAL-31166,MCAL-31165,MCAL-31164,MCAL-31163 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_Init(P2CONST(Cdd_Adc_ConfigType, AUTOMATIC, CDD_ADC_CFG) CfgPtr)
{
#if (CDD_ADC_DEV_ERROR_DETECT == STD_ON)
    if (Cdd_Adc_IsInitialized != FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_INIT, CDD_ADC_E_ALREADY_INITIALIZED);
    }
#if (STD_ON == CDD_ADC_PRE_COMPILE_VARIANT)
    else if (CfgPtr != NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_INIT, CDD_ADC_E_PARAM_POINTER);
    }
#else
    else if (CfgPtr == NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_INIT, CDD_ADC_E_PARAM_POINTER);
    }
#endif /* #if(STD_ON == CDD_ADC_PRE_COMPILE_VARIANT) */
    else
#endif
    {
#if (STD_ON == CDD_ADC_PRE_COMPILE_VARIANT)
        Cdd_Adc_CfgPtr = &CDD_ADC_CONFIG_PC;
#else
        Cdd_Adc_CfgPtr = CfgPtr;
#endif /* #if(STD_ON == CDD_ADC_PRE_COMPILE_VARIANT) */

        Cdd_Adc_SetDrvObj(&Cdd_Adc_DrvObj, Cdd_Adc_CfgPtr);
        /* Initialize the driver object */
        Cdd_Adc_DrvObjInit();
        /* Initialize the ADC HW Unit */
        Cdd_Adc_HwUnitInit();
        Cdd_Adc_IsInitialized = TRUE; /* Update the initialized flag to true */
    }
}

/* Design: MCAL-31171,MCAL-31170,MCAL-31169,MCAL-31168,MCAL-31167 */
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_SetupResultBuffer(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                          P2CONST(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr)
{
    Std_ReturnType return_val = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    /* Check the return values of DET error check function */
    Std_ReturnType det_returnval = Cdd_Adc_BufferPtrDetCheck(Group, DataBufferPtr, CDD_ADC_SID_SETUP_RESULT_BUFFER);

    if ((E_OK == det_returnval) && (TRUE == Cdd_Adc_CfgPtr->groupcfg[Group].dma_mode))
    {
        /* Report error if the group is configured for DMA */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SETUP_RESULT_BUFFER,
                              CDD_ADC_E_WRONG_PROCESSING_MODE);
        det_returnval = E_NOT_OK;
    }

    /* If no det error is reported then configure the result buffer pointer */
    if (det_returnval == E_OK)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Report runtime error if the group status not IDLE */
        if (CDD_ADC_IDLE != Cdd_Adc_DrvObj.group_obj[Group].grp_status)
        {
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SETUP_RESULT_BUFFER,
                                         CDD_ADC_E_BUSY);
        }
        else
        {
            /* Set the result buffer pointer */
            Cdd_Adc_DrvObj.group_obj[Group].resbuffer = DataBufferPtr;
            Cdd_Adc_DrvObj.group_obj[Group].cur_resultptr =
                (Cdd_Adc_ValueGroupType *)(Cdd_Adc_DrvObj.group_obj[Group].resbuffer);
            return_val = E_OK;
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;
}

#if (STD_ON == CDD_ADC_VERSION_INFO_API)

/* Design: MCAL-31315 */
/* Design: MCAL-31173,MCAL-31172,MCAL-31313 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_ADC_DATA) VersionInfo)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    /* If VersionInfo is NULL */
    if ((Std_VersionInfoType *)NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_VERSION_INFO,
                              CDD_ADC_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = CDD_ADC_VENDOR_ID;
        VersionInfo->moduleID         = CDD_ADC_MODULE_ID;
        VersionInfo->instanceID       = CDD_ADC_INSTANCE_ID;
        VersionInfo->sw_major_version = (uint8)CDD_ADC_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)CDD_ADC_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)CDD_ADC_SW_PATCH_VERSION;
    }
}
#endif

/*
 * Design: MCAL-31308
 */
#if (STD_ON == CDD_ADC_DEINIT_API)
/* Design: MCAL-31176,MCAL-31175,MCAL-31174 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DeInit(void)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DEINIT, CDD_ADC_E_UNINIT);
    }
    else
#endif
    {
        /* Deinitialize the ADC HW Unit */
        Cdd_Adc_HwUnitDeinit();
        Cdd_Adc_IsInitialized = FALSE;
    }
}
#endif

/* Design: MCAL-31316,MCAL-31309 */
#if (STD_ON == CDD_ADC_ENABLE_START_STOP_GROUP_API)
/*
 * Design: MCAL-31186,MCAL-31185,MCAL-31184,MCAL-31183,MCAL-31182,MCAL-31181,MCAL-31180,MCAL-31179,
 * MCAL-31178,MCAL-31177
 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGroupConversion(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Adc_SwGrpConvDetCheck(Group, CDD_ADC_SID_START_GROUP_CONVERSION);

    if ((E_OK == return_value) && (Cdd_Adc_DrvObj.group_obj[Group].resbuffer == ((Cdd_Adc_ValueGroupType *)NULL_PTR)) &&
        (FALSE == Cdd_Adc_CfgPtr->groupcfg[Group].dma_mode))
    {
        /* Report DET error if result buffer is NULL when Cdd_Adc_StartGroupConversion is called*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GROUP_CONVERSION,
                              CDD_ADC_E_BUFFER_UNINIT);
        /* Update the DET error check return value */
        return_value = E_NOT_OK;
    }

    /* When no DET errors are reported */
    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if (Cdd_Adc_DrvObj.group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_SW)
        {
            /* Report DET error if the group is start by global software trigger */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GROUP_CONVERSION,
                                         CDD_ADC_E_WRONG_TRIGG_TYPE);
        }
        else if ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE) ||
                 ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED) &&
                  (Cdd_Adc_DrvObj.group_obj[Group].implicit_stop == TRUE)))
        {
            /* Call the start group API only when the trigger source is software */
            Cdd_Adc_StartGroup(Group);
        }
        else
        {
            /* Report DET error if the ADC is busy */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GROUP_CONVERSION,
                                         CDD_ADC_E_BUSY);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}

/*
  Design: MCAL-31196,MCAL-31195,MCAL-31194,MCAL-31193,MCAL-31192,MCAL-31191,MCAL-31190,MCAL-31189,
  MCAL-31188,MCAL-31187
 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGroupConversion(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Adc_SwGrpConvDetCheck(Group, CDD_ADC_SID_STOP_GROUP_CONVERSION);

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if (Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE)
        {
            /* Report DET error if the group is IDLE or is called for the group started by
             * Cdd_Adc_StartGlobalSwTrig */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_GROUP_CONVERSION,
                                         CDD_ADC_E_IDLE);
        }
        else if (Cdd_Adc_DrvObj.group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_SW)
        {
            /* Report DET error if the group is started by global software trigger but stopped using
                Cdd_Adc_StopGroupConversion API */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_GROUP_CONVERSION,
                                         CDD_ADC_E_WRONG_TRIGG_TYPE);
        }
        else
        {
            /* Call the stop group API */
            Cdd_Adc_StopGroup(Group);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
/* This API configures the Global software Trigger */
/* Design: MCAL-31292,MCAL-31291,MCAL-31290,MCAL-31289,MCAL-31288 */
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_StartGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig)
{
    Std_ReturnType return_val = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GLBSW_TRIG, CDD_ADC_E_UNINIT);
    }
    else if (GlbSwTrig >= CDD_ADC_GLBSW_TRIG_CNT)
    {
        /* Report DET error if the global software trigger symbolic ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GLBSW_TRIG,
                              CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        return_val = Cdd_Adc_CheckGlbTrig(GlbSwTrig);

        /* Corresponding errors are reported in Cdd_Adc_CheckGlbTrig function in case of return_val =  E_NOT_OK */
        if (return_val == E_OK)
        {
            /* Trigger the global software trigger for the configured hardware units if no errors
             * are reported. */
            Cdd_Adc_StartGlbTrig(GlbSwTrig);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;
}

/* Design: MCAL-31296,MCAL-31295,MCAL-31294 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_val = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_GLBSW_TRIG, CDD_ADC_E_UNINIT);
    }
    else if (GlbSwTrig >= CDD_ADC_GLBSW_TRIG_CNT)
    {
        /* Design: MCAL-31293 */
        /* Report DET error if the global software trigger symbolic ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_GLBSW_TRIG,
                              CDD_ADC_E_INVALID_ID);
    }
    else
    {
        return_val = E_OK;
    }

    /* When no det errors are reported */
    if (E_OK == return_val)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if (Cdd_Adc_DrvObj.glbsw_obj[GlbSwTrig].status == FALSE)
        {
            /* Report runtime error when this API is called without calling
             * Cdd_Adc_StartGlobalSwTrig API */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_GLBSW_TRIG,
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

/* Design: MCAL-31317 */
#if (CDD_ADC_HW_TRIGGER_API == STD_ON)

/* Design: MCAL-31212,MCAL-31211,MCAL-31210,MCAL-31209,MCAL-31208,MCAL-31207,MCAL-31206,MCAL-31205 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Adc_HwGrpConvDetCheck(Group, CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER);

    if (E_OK == return_value)
    {
        return_value = Cdd_Adc_HwGrpDetErrCheck(Group);
    }

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE) ||
            ((Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED) &&
             (Cdd_Adc_DrvObj.group_obj[Group].implicit_stop == TRUE)))
        {
            /* Call the start group API */
            Cdd_Adc_StartGroup(Group);
        }
        else
        {
            /* Report DET error if Adc is BUSY */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER,
                                         CDD_ADC_E_BUSY);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}

/* Design: MCAL-31220,MCAL-31219,MCAL-31218,MCAL-31217,MCAL-31216,MCAL-31215,MCAL-31214,MCAL-31213 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DisableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    return_value                = Cdd_Adc_HwGrpConvDetCheck(Group, CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER);

    if ((E_OK == return_value) && (CDD_ADC_CONV_MODE_CONTINUOUS == Cdd_Adc_CfgPtr->groupcfg[Group].conversion_mode))
    {
        /* Report DET error if trigger source is wrong*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,
                              CDD_ADC_E_WRONG_CONV_MODE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if (Cdd_Adc_DrvObj.group_obj[Group].grp_status == CDD_ADC_IDLE)
        {
            /* The group is not enabled with a previous call of Cdd_Adc_EnableHardwareTrigger */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER,
                                         CDD_ADC_E_IDLE);
        }
        else
        {
            /* Call the stop group private function. */
            Cdd_Adc_StopGroup(Group);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}
#endif

/* Service to get the status of the group. */
/* Design: MCAL-31227,MCAL-31226,MCAL-31225,MCAL-31224,MCAL-31223,MCAL-31222,MCAL-31221 */
FUNC(Cdd_Adc_StatusType, CDD_ADC_CODE) Cdd_Adc_GetGroupStatus(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
    Cdd_Adc_StatusType group_status = CDD_ADC_IDLE;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_GRP_STATUS, CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_GRP_STATUS,
                              CDD_ADC_E_PARAM_GROUP);
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

/* Design: MCAL-31204,MCAL-31203,MCAL-31202,MCAL-31201,MCAL-31200,MCAL-31199,MCAL-31198,MCAL-31197 */
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_ReadGroup(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                  P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr)
{
    Std_ReturnType return_val = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType det_retval = Cdd_Adc_BufferPtrDetCheck(Group, DataBufferPtr, CDD_ADC_SID_READ_GROUP);

    if ((E_OK == det_retval) && (TRUE == Cdd_Adc_CfgPtr->groupcfg[Group].dma_mode))
    {
        /* Report error if the group is configured for DMA */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_GROUP,
                              CDD_ADC_E_WRONG_PROCESSING_MODE);
        det_retval = E_NOT_OK;
    }

    if (E_OK == det_retval)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        if (((CDD_ADC_IDLE == Cdd_Adc_DrvObj.group_obj[Group].grp_status) &&
             (Cdd_Adc_DrvObj.group_obj[Group].valid_samples == 0U)))
        {
            /* Report DET error if required group to read is in IDLE state and
             * the group conversion is not started (no results are available from previous conversions)
             */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_GROUP,
                                         CDD_ADC_E_IDLE);
        }
        else if (Cdd_Adc_DrvObj.group_obj[Group].grp_status != CDD_ADC_BUSY)
        {
            /* If the group is not in COMPLETED or STREAM_COMPLETED or IDLE state then read the group result
             */
            Cdd_Adc_ReadGroupResult(Group, DataBufferPtr);
            return_val = E_OK;
        }
        else
        {
            /* If no conversion results are available return E_NOT_OK when group is in BUSY state */
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_val;
}
#endif

/* Design: MCAL-31310 */
#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
/* Design: MCAL-31283,MCAL-31282,MCAL-31281,MCAL-31280 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableGroupNotification(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling
         * CDD_Adc_EnableGroupNotification */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,
                              CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,
                              CDD_ADC_E_PARAM_GROUP);
    }
    else if ((Cdd_Adc_GroupEndNotifyType)NULL_PTR == Cdd_Adc_CfgPtr->groupcfg[Group].groupend_notification)
    {
        /* Design: MCAL-31156 */
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION,
                              CDD_ADC_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Enable group notification */
        Cdd_Adc_DrvObj.group_obj[Group].grp_notification = TRUE;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}

/* Design: MCAL-31287,MCAL-31286,MCAL-31285,MCAL-31284 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DisableGroupNotification(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling
         * Cdd_Adc_DisableGroupNotification */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,
                              CDD_ADC_E_UNINIT);
    }
    else if (Group >= CDD_ADC_GROUP_CNT)
    {
        /* Report DET error if the group ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,
                              CDD_ADC_E_PARAM_GROUP);
    }
    else if ((Cdd_Adc_GroupEndNotifyType)NULL_PTR == Cdd_Adc_CfgPtr->groupcfg[Group].groupend_notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION,
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
}
#endif

/* Design: MCAL-31236,MCAL-31235,MCAL-31234,MCAL-31233,MCAL-31232,MCAL-31231,MCAL-31230,MCAL-31229,MCAL-31228 */
FUNC(Cdd_Adc_StreamNumSampleType, CDD_ADC_CODE)
Cdd_Adc_GetStreamLastPointer(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                             P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) * PtrToSamplePtr)
{
    Cdd_Adc_StreamNumSampleType num_samples = 0U;
    Cdd_Adc_StatusType          grp_status;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_val = Cdd_Adc_GetStreamPtrDetCheck(Group, PtrToSamplePtr);

    if ((E_OK == return_val) && (TRUE == Cdd_Adc_CfgPtr->groupcfg[Group].dma_mode))
    {
        /* Report error if the group is configured for DMA */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_STREAM_LAST_POINTER,
                              CDD_ADC_E_WRONG_PROCESSING_MODE);

        /* Set the PtrToSamplePtr to NULL_PTR */
        *PtrToSamplePtr = (Cdd_Adc_ValueGroupType *)NULL_PTR;
        return_val      = E_NOT_OK;
    }

    /* If no det error is reported */
    if (E_OK == return_val)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        grp_status = Cdd_Adc_DrvObj.group_obj[Group].grp_status;
        if ((grp_status == CDD_ADC_COMPLETED) || (grp_status == CDD_ADC_STREAM_COMPLETED))
        {
            /* Get valid samples count only when the group is in COMPLETED or STREAM_COMPLETED state
               or for single access groups if the valid samples are stored in the result buffer */
            num_samples = Cdd_Adc_GetValidSampleCnt(Group, PtrToSamplePtr);
        }
        else if ((grp_status == CDD_ADC_IDLE) && (Cdd_Adc_DrvObj.group_obj[Group].valid_samples == 0U))
        {
            *PtrToSamplePtr = (Cdd_Adc_ValueGroupType *)NULL_PTR;
            /* Report DET error if the ADC is IDLE and no results are available from previous
             * conversions */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_STREAM_LAST_POINTER,
                                         CDD_ADC_E_IDLE);
        }
        else
        {
            /* If group status id IDLE or BUSY then return 0(valid samples) and set the
             * PtrToSamplePtr to NULL_PTR */
            *PtrToSamplePtr = (Cdd_Adc_ValueGroupType *)NULL_PTR;
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return (num_samples);
}

#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
/*
 * API to set the resolution
 */

/* Design: MCAL-31318 */
/* Design: MCAL-31263,MCAL-31262,MCAL-31261,MCAL-31260,,MCAL-31259,MCAL-31258,MCAL-31257 */
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_SetResolution(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                      VAR(Cdd_Adc_ResolutionType, AUTOMATIC) Resolution)
{
    Std_ReturnType return_value = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is uninitialized */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION, CDD_ADC_E_UNINIT);
    }
    else if (HwUnit >= CDD_ADC_HW_CNT)
    {
        /* Report DET error if the specified hardware unit ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION, CDD_ADC_E_INVALID_ID);
    }
    else if (CDD_ADC_RESOLUTION_NONE <= Resolution)
    {
        /* Report DET error if the specified hardware unit ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION,
                              CDD_ADC_E_INVALID_RESOLUTION);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        return_value = Cdd_Adc_UpdateResolution(HwUnit, Resolution);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return return_value;
}
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

/* Design: MCAL-31244,MCAL-31243,MCAL-31242,MCAL-31246,MCAL-31245 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartResultChecker(VAR(Cdd_Adc_CheckerType, AUTOMATIC) CheckerId)
{
    uint32 base_addr = 0U;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver is not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_RESULT_CHECKER,
                              CDD_ADC_E_UNINIT);
    }
    else if (CheckerId >= CDD_ADC_CHECKER_CNT)
    {
        /* Report DET error if the checker ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_RESULT_CHECKER,
                              CDD_ADC_E_INVALID_ID);
    }
    else
    {
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        /* Base address of the safety checker unit */
        base_addr = Cdd_Adc_CfgPtr->checkercfg.checkerunitcfg[CheckerId].base_addr;
        if (Cdd_Adc_GetCheckerStatus(base_addr) == TRUE)
        {
            /* Report DET error if safety checker is already ENABLED */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_RESULT_CHECKER,
                                         CDD_ADC_E_CHECKER_BUSY);
        }
        else
        {
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            /* Force Software sync to clear any result safety checker event flags that are set */
            Cdd_Adc_ForceSafetyCheckerSync(base_addr);
            /* Enable the specified result safety checker tile */
            Cdd_Adc_ConfigureCheckerTile(base_addr, TRUE);
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
    }
}

/* Design: MCAL-31241,MCAL-31240,MCAL-31239,MCAL-31238,MCAL-31237  */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopResultChecker(VAR(Cdd_Adc_CheckerType, AUTOMATIC) CheckerId)
{
    uint32 base_addr = 0U;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_RESULT_CHECKER,
                              CDD_ADC_E_UNINIT);
    }
    else if (CheckerId >= CDD_ADC_CHECKER_CNT)
    {
        /* Report DET error if the checker ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_RESULT_CHECKER,
                              CDD_ADC_E_INVALID_ID);
    }
    else
    {
        /* Do nothing */
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        /*Base address of the safety checker unit*/
        base_addr = Cdd_Adc_CfgPtr->checkercfg.checkerunitcfg[CheckerId].base_addr;
        if (Cdd_Adc_GetCheckerStatus(base_addr) == TRUE)
        {
            SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
            Cdd_Adc_StopChecker(CheckerId);
            SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Report DET error if checker is not enabled */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_STOP_RESULT_CHECKER,
                                         CDD_ADC_E_CHECKER_IDLE);
        }
    }
}

/* This function will point to the structure which stores the flag status of all the safety checker
 * units */
/* Design: MCAL-31251,MCAL-31250,MCAL-31249,MCAL-31248,MCAL-31247 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ReadCheckerStatus(VAR(Cdd_Adc_CheckerIntEvtType, AUTOMATIC) IntEvt,
                          P2VAR(Cdd_Adc_CheckFlagStatusType, AUTOMATIC, CDD_ADC_DATA) CheckerFlag)
{
    uint16 status;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_RESULT_CHECKER,
                              CDD_ADC_E_UNINIT);
    }
    else if (IntEvt >= CDD_ADC_CHECKER_INTEVT_CNT)
    {
        /* Report DET error if interrupt event ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_RESULT_CHECKER,
                              CDD_ADC_E_INVALID_ID);
    }
    else if (CheckerFlag == (Cdd_Adc_CheckFlagStatusType *)NULL_PTR)
    {
        /* Report DET error if the passed pointer is NULL and the buffer doesn't have enough space
         */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_RESULT_CHECKER,
                              CDD_ADC_E_PARAM_POINTER);
    }
    else
    {
        /* Do nothing */
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        status = Cdd_Adc_GetSafetyCheckIntStatus(Cdd_Adc_CfgPtr->checkercfg.checkerintevtcfg[IntEvt].base_addr);
        /* Check if the interrupt flag is set */
        if (TRUE == ((uint8)status))
        {
            /* This functions returns the interrupt source event flag for each safety checker */
            Cdd_Adc_CheckerIsr(IntEvt, CheckerFlag);
        }
    }
}

/* This function will point to the structure which stores the flag status of all the safety checker
 * units */
/* Design: MCAL-31256,MCAL-31255,MCAL-31254,MCAL-31253,MCAL-31252 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearCheckerEvt(VAR(Cdd_Adc_CheckerIntEvtType, AUTOMATIC) IntEvt,
                        VAR(Cdd_Adc_CheckerEventType, AUTOMATIC) Event_Id)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CLEAR_CHECKER_EVT, CDD_ADC_E_UNINIT);
    }
    else if (IntEvt >= CDD_ADC_CHECKER_INTEVT_CNT)
    {
        /* Report DET error if interrupt event ID doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CLEAR_CHECKER_EVT,
                              CDD_ADC_E_INVALID_ID);
    }
    else if ((uint8)Event_Id >= CDD_ADC_CHECKER_EVT_CNT)
    {
        /* Report DET error if the event ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CLEAR_CHECKER_EVT,
                              CDD_ADC_E_PARAM_EVENT);
    }
    else
    {
        /* Do nothing */
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Clear flags that generated the event */
        Cdd_Adc_ClearCheckerStatus(IntEvt, Event_Id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}
#endif

/* Design: MCAL-31311 */
#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Design: MCAL-31266,MCAL-31265,MCAL-31264,MCAL-31263 */
FUNC(Cdd_Adc_PpbValType, CDD_ADC_CODE)
Cdd_Adc_ReadPartialPpbValue(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    Cdd_Adc_PpbValType ppbval = {((sint32)0), ((sint32)0), ((sint32)0), ((uint16)0U), ((uint16)0U), ((uint16)0U)};
    uint32             result_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PARTIAL_PPB_VALUE,
                              CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PARTIAL_PPB_VALUE,
                              CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        result_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].base_addr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppbval.ppbmin      = Cdd_Adc_ReadPpbPMin(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmax      = Cdd_Adc_ReadPpbPMax(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbsum      = Cdd_Adc_ReadPpbPSum(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbcount    = Cdd_Adc_ReadPpbPCount(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmaxindex = Cdd_Adc_ReadPpbPMaxIndex(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbminindex = Cdd_Adc_ReadPpbPMinIndex(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ppbval;
}

/* Design: MCAL-31269,MCAL-31268,MCAL-31267 */
FUNC(Cdd_Adc_PpbValType, CDD_ADC_CODE) Cdd_Adc_ReadPpbValue(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    Cdd_Adc_PpbValType ppbval = {((sint32)0), ((sint32)0), ((sint32)0), ((uint16)0U), ((uint16)0U), ((uint16)0U)};
    uint32             result_addr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PPB_VALUE, CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PPB_VALUE, CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        result_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].result_baseaddr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppbval.ppbmin      = Cdd_Adc_ReadPpbMin(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmax      = Cdd_Adc_ReadPpbMax(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbsum      = Cdd_Adc_ReadPpbSum(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbcount    = Cdd_Adc_ReadPpbCount(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbmaxindex = Cdd_Adc_ReadPpbMaxIndex(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        ppbval.ppbminindex = Cdd_Adc_ReadPpbMinIndex(result_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ppbval;
}

/* Design: MCAL-31272,MCAL-31271,MCAL-31270 */
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpb(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    sint32 ppb_result = (sint32)0;
    uint32 resultbaseaddr;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PPB, CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_READ_PPB, CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        resultbaseaddr = Cdd_Adc_CfgPtr->hwunitcfg[(Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex)].result_baseaddr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        ppb_result = Cdd_Adc_ReadPpbResult(resultbaseaddr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return ppb_result;
}

/* Design: MCAL-31279,MCAL-31278,MCAL-31277 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearPpbEvt(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    uint32 base_addr = 0U;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CLEAR_PPB_EVT, CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CLEAR_PPB_EVT, CDD_ADC_E_INVALID_ID);
    }
    else
#endif
    {
        base_addr = Cdd_Adc_CfgPtr->hwunitcfg[(Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex)].base_addr;
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        Cdd_Adc_ClearPpbEvtStatus(base_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id,
                                  Cdd_Adc_CfgPtr->ppbcfg[PpbId].tripevtsel);
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}

/* Design: MCAL-31276,MCAL-31275,MCAL-31274,MCAL-31273 */
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetDelayStamp(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    uint16 delay_stamp = 0U;
    uint32 base_addr   = 0U;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_DELAY_STAMP, CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_DELAY_STAMP,
                              CDD_ADC_E_INVALID_ID);
    }
    else if (CDD_ADC_TRIGG_SRC_HW != Cdd_Adc_PrivGetTrigSrc(PpbId))
    {
        /* This function should be called only for the SOCs configured for the hardware trigger source. */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_DELAY_STAMP,
                              CDD_ADC_E_WRONG_TRIGG_SRC);
    }
    else
#endif
    {
        base_addr = Cdd_Adc_CfgPtr->hwunitcfg[Cdd_Adc_CfgPtr->ppbcfg[PpbId].hwunitindex].base_addr;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        delay_stamp = Cdd_Adc_GetPpbDelayTimeStamp(base_addr, Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppb_id);
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return delay_stamp;
}

#if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
/* Design:MCAL-35280 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ConfigurePpbNotification(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId, VAR(boolean, AUTOMATIC) Mode)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Design: MCAL-35328 */
        /* Report DET error if the driver not initialised before calling
         * CDD_Adc_EnableGroupNotification */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CONFIGURE_PPB_NOTIFICATION,
                              CDD_ADC_E_UNINIT);
    }
    else if (PpbId >= CDD_ADC_PPB_CNT)
    {
        /* Design:MCAL-35329 */
        /* Report DET error if the PPB ID doesn't exist*/
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CONFIGURE_PPB_NOTIFICATION,
                              CDD_ADC_E_INVALID_ID);
    }
    else if ((Cdd_Adc_PpbNotifyType)NULL_PTR == Cdd_Adc_CfgPtr->ppbcfg[PpbId].ppbevtint_notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_CONFIGURE_PPB_NOTIFICATION,
                              CDD_ADC_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        /* Enable/disable PPB notification */
        Cdd_Adc_DrvObj.ppb_obj[PpbId] = Mode;
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
}
#endif

#endif

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
/* Design: MCAL-31300,MCAL-31329,MCAL-31328,MCAL-31327,MCAL-31299 */
FUNC(sint16, CDD_ADC_CODE)
Cdd_Adc_GetTemperatureC(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                        VAR(Cdd_Adc_ValueGroupType, AUTOMATIC) TempResult)
{
    sint16  temp_value = 0;
    float32 vref = 0.0f, temp = 0.0f;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Design: MCAL-31297 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_TEMPERATURE_C, CDD_ADC_E_UNINIT);
    }
    else if (HwUnit >= CDD_ADC_HW_CNT)
    {
        /* Design: MCAL-31298 */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_TEMPERATURE_C,
                              CDD_ADC_E_INVALID_ID);
    }
    else
    {
        /* Do nothing */
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        vref = (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltref == CDD_ADC_REFERENCE_3_3V) ? (3.3F) : (2.5F);
        /* Read temp sensor slope and offset locations from OTP and convert */
        temp = ((float32)TempResult * ((float32)vref / 2.5F));
        if (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltrefmode == CDD_ADC_REFERENCE_INTERNAL)
        {
            temp_value = (sint16)((((sint32)temp - CDD_ADC_INT_REF_TSOFFSET) * 4096) / CDD_ADC_INT_REF_TSSLOPE);
        }
        else
        {
            temp_value = (sint16)((((sint32)temp - CDD_ADC_EXT_REF_TSOFFSET) * 4096) / CDD_ADC_EXT_REF_TSSLOPE);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return temp_value;
}

/* Design: MCAL-31304,MCAL-31303,MCAL-31302,MCAL-31301 */
FUNC(sint16, CDD_ADC_CODE)
Cdd_Adc_GetTemperatureK(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                        VAR(Cdd_Adc_ValueGroupType, AUTOMATIC) TempResult)
{
    sint16  temp_value = 0;
    float32 vref = 0.0f, temp = 0.0f;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_TEMPERATURE_K, CDD_ADC_E_UNINIT);
    }
    else if (HwUnit >= CDD_ADC_HW_CNT)
    {
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_GET_TEMPERATURE_K,
                              CDD_ADC_E_INVALID_ID);
    }
    else
    {
        /* Do nothing */
        return_value = E_OK;
    }

    if (E_OK == return_value)
#endif
    {
        SchM_Enter_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
        vref = (float32)((Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltref == CDD_ADC_REFERENCE_3_3V) ? (3.3F) : (2.5F));
        /*  Read temp sensor slope and offset locations from OTP and convert */
        temp = ((float32)TempResult * ((float32)vref / 2.5F));
        if (Cdd_Adc_CfgPtr->hwunitcfg[HwUnit].voltrefmode == CDD_ADC_REFERENCE_INTERNAL)
        {
            temp_value = (sint16)(((((sint32)temp - CDD_ADC_INT_REF_TSOFFSET) * 4096) / CDD_ADC_INT_REF_TSSLOPE) + 273);
        }
        else
        {
            temp_value = (sint16)(((((sint32)temp - CDD_ADC_EXT_REF_TSOFFSET) * 4096) / CDD_ADC_EXT_REF_TSSLOPE) + 273);
        }
        SchM_Exit_Cdd_Adc_CDD_ADC_EXCLUSIVE_AREA_0();
    }
    return temp_value;
}
#endif

/* Design: MCAL-31307,MCAL-31306,MCAL-31305 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetInternalTestNode(VAR(Cdd_Adc_InternalTestNodeType, AUTOMATIC) TestNode)
{
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_INTERNAL_TEST_NODE, CDD_ADC_E_UNINIT);
    }
    else if (TestNode >= CDD_ADC_TEST_NODE_MAX)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_INTERNAL_TEST_NODE,
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

/* Design: MCAL-32672,MCAL-31128,MCAL-32668 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_UpdateStatusThroughDma(VAR(Cdd_Adc_HwUnitType, AUTOMATIC) HwUnitId, VAR(Cdd_Adc_IntNumType, AUTOMATIC) IntNum)
{
    /* Update the status of the group that is linked to the specified interrupt of the ADC instance */
    Cdd_Adc_PrivUpdateStatusThroughDma(IntNum, HwUnitId);
}

#define CDD_ADC_STOP_SEC_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Adc.c
 *********************************************************************************************************************/
