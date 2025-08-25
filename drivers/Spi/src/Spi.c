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
 *  File:       Spi.c
 *  Generator:  None
 *
 *  Description:  This file contains Spi MCAL driver API function definitions
 *********************************************************************************************************************/
/*
 *Design: MCAL-24853, MCAL-24851, MCAL-24852
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-24856 */
#include "Spi.h"
#include "Spi_Priv.h"
#include "SchM_Spi.h"
/* Design: MCAL-25085 */
#include "Det.h"
/* Design: MCAL-24948, MCAL-25086 */
#if (SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
#include "Dem.h"
#endif
/* Design: MCAL-24855 */
#if (SPI_CS_VIA_GPIO == STD_ON)
#include "Dio.h"
#endif
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*
 * AUTOSAR version information check has to match definition in header file
 */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (SPI_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (SPI_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "SPI: AUTOSAR Version Numbers of SPI are different"
#endif

#if ((SPI_SW_MAJOR_VERSION != (2U)) || (SPI_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Spi.c and Spi.h are inconsistent!"
#endif

#if ((SPI_CFG_MAJOR_VERSION != (2U)) || (SPI_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Spi.c and Spi_Cfg.h are inconsistent!"
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
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/* Design : MCAL-24958 */
/** \brief SPI driver status */
volatile VAR(Spi_StatusType, SPI_VAR_INIT) Spi_DrvStatus = SPI_UNINIT;
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief SPI driver object */
/* Design : MCAL-25183 */
VAR(Spi_DriverObjType, SPI_VAR_NO_INIT) Spi_DrvObj;
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == SPI_DEV_ERROR_DETECT)

/** \brief private function for checking driver object
 *
 *  private function for checking driver object
 *
 * \param[in] cfgPtr: pointer to configuration parameters
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE) Spi_CheckConfig(const Spi_ConfigType *cfgPtr);

/** \brief private function for checking Det errors in AsyncTransmit function
 *
 *  private function for checking Det errors in AsyncTransmit function
 *
 * \param[in] Sequence: Sequence Id
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
#if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2))
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetCheckAsyncTransmit(Spi_SequenceType Sequence);
#endif /*#if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2))*/
#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
/** \brief private function for checking Det errors in SyncTransmit function
 *
 *  private function for checking Det errors in SyncTransmit function
 *
 * \param[in] Sequence: Sequence Id
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetCheckSyncTransmit(Spi_SequenceType Sequence);

#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY ==  SPI_LEVEL_2)) */
/** \brief private function for checking Det errors in Init function
 *
 *  private function for checking Det errors in Init function
 *
 * \param[in] ConfigPtr: pointer to configType
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE)
    Spi_DetCheckInitPtrObj(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) ConfigPtr);

/** \brief private function for checking Det errors in Init function
 *
 *  private function for checking Det errors in Init function
 *
 * \param[in] ConfigPtr: pointer to configType
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE)
    Spi_DetCheckInitJobCfg(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) ConfigPtr);
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
/** \brief private function for checking Det Run Time errors in syncTransmit function
 *
 *  private function for checking Det errors in SyncTransmit function
 *
 * \param[in] seqObj: Pointer to sequence object
 * \pre None
 * \post None
 * \return returns whether configuration params are correct or wrong
 * \retval E_OK: configuration parameters are valid
 * \retval E_NOT_OK: configuration parameters are in-valid
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetRTErrorCheckSyncTransmit(Spi_SeqObjType *seqObj);
#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY ==  SPI_LEVEL_2)) */
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
/*
 * Design : MCAL-24992, MCAL-24996, MCAL-24994, MCAL-24993, MCAL-24947
 * Design : MCAL-24995, MCAL-24991, MCAL-24887, MCAL-24937, MCAL-24938
 * Design : MCAL-24944
 */
FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) CfgPtr)
{
    P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) ConfigPtr = NULL_PTR;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    Std_ReturnType retVal = E_NOT_OK;
#endif
#if ((STD_ON == SPI_PRE_COMPILE_VARIANT) || (STD_ON == SPI_LINK_TIME_VARIANT))
    if (NULL_PTR == CfgPtr)
    {
        ConfigPtr = &SPI_INIT_CONFIG_PC;
    }
#else
    if (NULL_PTR != CfgPtr)
    {
        ConfigPtr = CfgPtr;
    }
#endif
    if (NULL_PTR == ConfigPtr)
    {
#if (STD_ON == SPI_DEV_ERROR_DETECT)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_POINTER);
#endif
    }
    else
    {
#if (STD_ON == SPI_DEV_ERROR_DETECT)
        if ((Spi_DetCheckInitPtrObj(ConfigPtr) == (Std_ReturnType)E_OK) &&
            (Spi_DetCheckInitJobCfg(ConfigPtr) == (Std_ReturnType)E_OK))
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
        {
#if (STD_ON == SPI_DEV_ERROR_DETECT)
            /* Check the configuration */
            retVal = Spi_CheckConfig(ConfigPtr);
            if (((Std_ReturnType)E_OK) == retVal)
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
            {
                Spi_PrivInit(&Spi_DrvObj, ConfigPtr);
            }
        }
    }
    return;
}
/*
 * Design : MCAL-24998, MCAL-24999, MCAL-25000, MCAL-25001,
 * Design : MCAL-25002, MCAL-25003, MCAL-25004,  MCAL-24997, MCAL-24946
 */

FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    VAR(uint8, AUTOMATIC) index;
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_DEINIT, SPI_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        if (SPI_BUSY == Spi_DrvStatus)
        {
            /* Do nothing */
        }
        else
        {
            Spi_DrvStatus = SPI_UNINIT;
            retVal        = ((Std_ReturnType)E_OK);
            /* Deinit the hardware modules */
            for (index = ((uint8)0U); index < Spi_DrvObj.maxHwUnit; index++)
            {
                Spi_HwUnitDeInit(&Spi_DrvObj.hwUnitObj[index]);
            }
            Spi_ResetDrvObj(&Spi_DrvObj);
        }
    }

    return (retVal);
}

/*
 * Design : MCAL-25047, MCAL-25048, MCAL-25049, MCAL-24960, MCAL-24956, MCAL-24961, MCAL-24959
 */
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    return (Spi_DrvStatus);
}

/*
 * Design : MCAL-25050, MCAL-25051, MCAL-25052, MCAL-25053, MCAL-24938, MCAL-24939, MCAL-24967
 * Design : MCAL-24946
 */

FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(VAR(Spi_JobType, AUTOMATIC) Job)
{
    VAR(Spi_JobResultType, AUTOMATIC) jobResult = SPI_JOB_FAILED;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_JOB_RESULT, SPI_E_UNINIT);
    }
    else if (Job >= Spi_DrvObj.maxJobs)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_JOB);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        jobResult = Spi_DrvObj.jobObj[Job].jobResult;
    }

    return (jobResult);
}

/*
 * Design : MCAL-25054, MCAL-25055, MCAL-25056, MCAL-24938, MCAL-24939, MCAL-24972
 * Design : MCAL-24946
 */

FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Spi_SeqResultType, AUTOMATIC) seqResult = SPI_SEQ_FAILED;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_SEQ_RESULT, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_SEQ_RESULT, SPI_E_PARAM_SEQ);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        seqResult = Spi_DrvObj.seqObj[Sequence].seqResult;
    }

    return (seqResult);
}

/*
 * Design : MCAL-25057
 */
#if (STD_ON == SPI_VERSION_INFO_API)
FUNC(void, SPI_CODE)
Spi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_VERSION_INFO, SPI_E_PARAM_POINTER);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        versioninfo->vendorID         = SPI_VENDOR_ID;
        versioninfo->moduleID         = SPI_MODULE_ID;
        versioninfo->sw_major_version = (uint8)SPI_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)SPI_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)SPI_SW_PATCH_VERSION;
    }

    return;
}
#endif /* #if (STD_ON == SPI_VERSION_INFO_API) */

/*
 * Design : MCAL-25067, MCAL-25068, MCAL-25069, MCAL-25070, MCAL-25071, MCAL-24962, MCAL-24963
 * Design : MCAL-24943, MCAL-24957, MCAL-24942
 */

#if (STD_ON == SPI_HW_STATUS_API)
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit)
{
    P2VAR(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj;
    VAR(Spi_StatusType, AUTOMATIC) hwUnitStatus = SPI_UNINIT;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_HW_UNIT_STATUS, SPI_E_UNINIT);
    }
    else if (0U == (SPI_CFG_ENABLED_HW_MASK & ((uint8)1U << HWUnit)))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_HW_UNIT_STATUS, SPI_E_PARAM_UNIT);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        /* HW unit ID may not be the index, so search for
                                                           matching HW unit */
        hwUnitObj    = Spi_GetHwUnitObj(HWUnit, &Spi_DrvObj);
        hwUnitStatus = Spi_PrivGetHWStatus(hwUnitObj);
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }
    return (hwUnitStatus);
}
#endif /* #if (STD_ON == SPI_HW_STATUS_API) */

/*
 * Design : MCAL-25006, MCAL-25007, MCAL-25008, MCAL-25009 ,MCAL-24937, MCAL-24880
 * Design : MCAL-25010, MCAL-25011, MCAL-25005, MCAL-25012, MCAL-24878, MCAL-24946
 */

#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))

FUNC(Std_ReturnType, SPI_CODE)
Spi_WriteIB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
            P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_WRITE_IB, SPI_E_UNINIT);
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) || (Spi_DrvObj.channelObj[Channel].chCfg->channelBufType != SPI_IB))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_WRITE_IB, SPI_E_PARAM_CHANNEL);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        chObj = &Spi_DrvObj.channelObj[Channel];
        if (SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            Spi_PrivIntlBufWrite8(chObj, DataBufferPtr);
            retVal = (Std_ReturnType)E_OK;
        }
        else
        {
            Spi_PrivIntlBufWrite16(chObj, DataBufferPtr);
            retVal = (Std_ReturnType)E_OK;
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}

/*
 * Design : MCAL-25031, MCAL-25032, MCAL-25033, MCAL-25034, MCAL-25035
 * Design : MCAL-25037, MCAL-24879, MCAL-24937, MCAL-24946, MCAL-25036, MCAL-25093
 */
FUNC(Std_ReturnType, SPI_CODE)
Spi_ReadIB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
           P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_UNINIT);
    }
    else if (NULL_PTR == DataBufferPointer)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_PARAM_POINTER);
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) || (Spi_DrvObj.channelObj[Channel].chCfg->channelBufType != SPI_IB))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        chObj = &Spi_DrvObj.channelObj[Channel];
        Spi_PrivReadIB(chObj, DataBufferPointer);
        retVal = E_OK;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}

#endif /* ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB)) */

/*
 * Design : MCAL-25038, MCAL-25039, MCAL-25040, MCAL-25041, MCAL-25042, MCAL-24940, MCAL-24884
 * Design : MCAL-25045, MCAL-25046, MCAL-24945, MCAL-25043, MCAL-25044, MCAL-24937, MCAL-24882
 * Design : MCAL-24941, MCAL-24946, MCAL-25098, MCAL-25101, MCAL-25100
 */
#if ((SPI_CHANNEL_BUFFERS == SPI_EB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
FUNC(Std_ReturnType, SPI_CODE)
Spi_SetupEB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
            P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
            P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
            VAR(Spi_NumberOfDataType, AUTOMATIC) Length)

{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_UNINIT);
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) || (Spi_DrvObj.channelObj[Channel].chCfg->channelBufType != SPI_EB))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_CHANNEL);
    }
    else if ((Length == 0U) || (Length > Spi_DrvObj.channelObj[Channel].chCfg->maxBufLength))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        chObj               = &Spi_DrvObj.channelObj[Channel];
        chObj->txBufPtr     = SrcDataBufferPtr;
        chObj->rxBufPtr     = DesDataBufferPtr;
        chObj->numWordsTxRx = Length;
        retVal              = ((Std_ReturnType)E_OK);

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}
#endif /* #if ((SPI_CHANNEL_BUFFERS == SPI_EB) || (SPI_CHANNEL_BUFFERS \ \
        * ==SPI_IB_EB)) */

/*
 * Design : MCAL-25014, MCAL-25015, MCAL-25016, MCAL-25017, MCAL-25018, MCAL-25028
 * Design : MCAL-25019, MCAL-25020, MCAL-25021, MCAL-25022, MCAL-25023, MCAL-24892
 * Design : MCAL-25024, MCAL-25025, MCAL-25027, MCAL-25029, MCAL-25026, MCAL-24938
 * Design : MCAL-25013, MCAL-24899, MCAL-24939, MCAL-25085, MCAL-24946, MCAL-25030
 */
#if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if ((Std_ReturnType)E_OK == Spi_DetCheckAsyncTransmit(Sequence))
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        if (Spi_GetSequenceResult(Sequence) == SPI_SEQ_PENDING)
        {
            (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
        }
        else
        {
            /* Call the start sequence API */
            retVal = Spi_StartSeqAsync(&Spi_DrvObj, &(Spi_DrvObj.seqObj[Sequence]));
            if (((Std_ReturnType)E_NOT_OK) == retVal)
            {
                (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
            }
        }
    }

    return (retVal);
}
#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_1) || \ \
        *(SPI_SCALABILITY == SPI_LEVEL_2)) */

/*
 * Design : MCAL-25072, MCAL-25073, MCAL-24938, MCAL-24939, MCAL-25076, MCAL-25074
 */

#if (STD_ON == SPI_CANCEL_API)
FUNC(void, SPI_CODE) Spi_Cancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_CANCEL, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        Spi_CancelSequence(&Spi_DrvObj, &Spi_DrvObj.seqObj[Sequence]);
    }

    return;
}
#endif

/*
 * Design : MCAL-25058, MCAL-25059, MCAL-25060, MCAL-25061, MCAL-25062, MCAL-25063, MCAL-24946
 * Design : MCAL-25064, MCAL-25065, MCAL-25066, MCAL-24885, MCAL-24888, MCAL-24938, MCAL-24939
 */

#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if ((Std_ReturnType)E_OK == Spi_DetCheckSyncTransmit(Sequence))
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        Spi_SeqObjType *seqObjTmp = &(Spi_DrvObj.seqObj[Sequence]);
        if ((Std_ReturnType)E_OK != Spi_DetRTErrorCheckSyncTransmit(seqObjTmp))
        {
            retVal = E_NOT_OK;
        }
        else
        {
            /* Call the start sequence API */
            retVal = Spi_StartSeqSync(&Spi_DrvObj, seqObjTmp);
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}
#endif /* ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY ==  SPI_LEVEL_2)) */

/*
 * Design : MCAL-25077, MCAL-25078, MCAL-25079, MCAL-25080, MCAL-25081, MCAL-25083, MCAL-25084,
 * Design : MCAL-24918, MCAL-25082, MCAL-24939, MCAL-24946
 */
#if (SPI_SCALABILITY == SPI_LEVEL_2)
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(VAR(Spi_AsyncModeType, AUTOMATIC) Mode)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Note: This error return is not mentioned in spec */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SET_ASYNC_MODE, SPI_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        if ((uint32)FALSE == Spi_DrvObj.isAsyncInProgress)
        {
            Spi_DrvObj.asyncMode = Mode;
            retVal               = E_OK;
        }
    }

    return (retVal);
}
#endif /* #if (SPI_SCALABILITY == SPI_LEVEL_2) */

/* Design: MCAL-24917 */
FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void)
{
    VAR(uint32, AUTOMATIC) hwUnitIdx;
    P2VAR(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj;
    VAR(Spi_HWUnitType, AUTOMATIC) hwUnitId;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Note: This error return is not mentioned in spec */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_MAINFUNCTION_HANDLING, SPI_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        /* Check all hardware units for any pending sequence */
        for (hwUnitIdx = ((uint32)0U); hwUnitIdx < Spi_DrvObj.maxHwUnit; hwUnitIdx++)
        {
            hwUnitObj = &Spi_DrvObj.hwUnitObj[hwUnitIdx];
            if ((SPI_POLLING_MODE == Spi_DrvObj.asyncMode) && (NULL_PTR != hwUnitObj->curJobObj))
            {
                hwUnitId = hwUnitObj->hwUnitCfg->hwUnitId;
                Spi_ProcessRxEvent(hwUnitId);
            }
        }
    }

    return;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == SPI_DEV_ERROR_DETECT)
/* Design: MCAL-28351 */
static FUNC(Std_ReturnType, SPI_CODE) Spi_CheckConfig(const Spi_ConfigType *cfgPtr)
{
    VAR(uint32, AUTOMATIC) index;
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    for (index = ((uint32)0U); index < cfgPtr->maxChannels; index++)
    {
        /* ID is used as index, can't exceed array size */
        if ((cfgPtr->channelCfg[index].channelId >= cfgPtr->maxChannels) || (cfgPtr->channelCfg[index].dataWidth < 1U))
        {
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_CHANNEL);
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    if (((Std_ReturnType)E_OK) == retVal)
    {
        for (index = ((uint32)0U); index < cfgPtr->maxJobs; index++)
        {
            /* ID is used as index, can't exceed array size */
            if ((cfgPtr->jobCfg[index].jobId >= cfgPtr->maxJobs) || (cfgPtr->jobCfg[index].channelPerJob == 0U) ||
                (cfgPtr->jobCfg[index].channelPerJob > SPI_MAX_CHANNELS_PER_JOB) ||
                (cfgPtr->jobCfg[index].externalDeviceCfgId >= cfgPtr->maxExtDevCfg))
            {
                (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_JOB);
                retVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    if (((Std_ReturnType)E_OK) == retVal)
    {
        for (index = ((uint32)0U); index < cfgPtr->maxSeq; index++)
        {
            /* ID is used as index, can't exceed array size */
            if ((cfgPtr->seqCfg[index].seqId >= cfgPtr->maxSeq) || (cfgPtr->seqCfg[index].jobPerSeq == 0U) ||
                (cfgPtr->seqCfg[index].jobPerSeq > SPI_MAX_JOBS_PER_SEQ))
            {
                (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_SEQ);
                retVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    return (retVal);
}
#if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2))
/* Design: MCAL-28352 */
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetCheckAsyncTransmit(Spi_SequenceType Sequence)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_SEQ);
    }
    else
    {
        retVal = E_OK;
    }
    return retVal;
}
#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2)) */
#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
/* Design: MCAL-28353 */
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetCheckSyncTransmit(Spi_SequenceType Sequence)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_SEQ);
    }
    else
    {
        retVal = E_OK;
    }
    return retVal;
}
#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY ==  SPI_LEVEL_2)) */
/* Design: MCAL-28354 */
static FUNC(Std_ReturnType, SPI_CODE)
    Spi_DetCheckInitPtrObj(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    if (SPI_UNINIT != Spi_DrvStatus)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
    }
    else if (ConfigPtr->maxChannels > SPI_MAX_CHANNELS)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_CHANNEL);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/* Design: MCAL-28355 */
static FUNC(Std_ReturnType, SPI_CODE)
    Spi_DetCheckInitJobCfg(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    if ((ConfigPtr->maxJobs > SPI_MAX_JOBS) || (ConfigPtr->maxExtDevCfg > SPI_MAX_EXT_DEV))
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_JOB);
    }
    else if (ConfigPtr->maxSeq > SPI_MAX_SEQ)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_SEQ);
    }
    else if (ConfigPtr->maxHwUnit > SPI_MAX_HW_UNIT)
    {
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_UNIT);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
/*
 * Design : MCAL-24931, MCAL-25085, MCAL-28356
 */
#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
static FUNC(Std_ReturnType, SPI_CODE) Spi_DetRTErrorCheckSyncTransmit(Spi_SeqObjType *seqObj)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal       = (Std_ReturnType)E_OK;
    VAR(Spi_SequenceType, AUTOMATIC) SequenceId = seqObj->seqCfg->seqId;
    VAR(uint32, AUTOMATIC) i;
#if (STD_ON == SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT)
    Spi_JobObjType    *jobObj;
    Spi_JobType        jobId;
    Spi_HwUnitObjType *hwUnitObj;
#endif
    if (Spi_GetSequenceResult(SequenceId) == SPI_SEQ_PENDING)
    {
        (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_PENDING);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (STD_OFF == SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT)
        for (i = ((Spi_SequenceType)0U); i < (Spi_SequenceType)Spi_DrvObj.maxSeq; i++)
        {
            if (Spi_GetSequenceResult(i) == SPI_SEQ_PENDING)
            {
                (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT,
                                             SPI_E_SEQ_IN_PROCESS);
                retVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
#else
        /* Check if the HW unit is free and job result is  not pending for all the jobs in this
         * sequence. If not reject the submission */
        for (i = 0U; i < seqObj->seqCfg->jobPerSeq; i++)
        {
            jobId     = seqObj->seqCfg->jobList[i];
            jobObj    = &Spi_DrvObj.jobObj[jobId];
            hwUnitObj = jobObj->hwUnitObj;
            if ((SPI_JOB_PENDING == jobObj->jobResult) || (SPI_HW_UNIT_OK != hwUnitObj->hwUnitResult))
            {
                (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT,
                                             SPI_E_SEQ_IN_PROCESS);
                /* the sequence is rejected due to common used jobs */
                retVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
#endif
    }

    return retVal;
}

#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY ==  SPI_LEVEL_2)) */
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Spi.c
 *********************************************************************************************************************/
