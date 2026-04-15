/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2026 Texas Instruments Incorporated
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
 *  File:       Cdd_Dma
 *  Generator:  None
 *
 *  Description: This file contains CDD DMA driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Dma.h"
#include "Cdd_Dma_Priv.h"
#include "SchM_Cdd_Dma.h"
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_DMA_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_DMA_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_DMA_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version of CDD_DMA is incorrect"
#endif

/* vendor specific version information check */

#if ((CDD_DMA_SW_MAJOR_VERSION != (1U)) || (CDD_DMA_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Dma.c and Cdd_Dma.h are not matching!"
#endif

#if ((CDD_DMA_CFG_MAJOR_VERSION != (1U)) || (CDD_DMA_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Dma.c and Cdd_Dma_Cfg.h are not matching!"
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

/* Cdd_Dma Driver initialization variable */
#define CDD_DMA_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Dma_MemMap.h"
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
static VAR(boolean, CDD_DMA_VAR_INIT) Cdd_Dma_IsInitialized = FALSE;
#endif
#define CDD_DMA_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Dma_MemMap.h"

/* Cdd_Dma configuration pointer to access driver configuration. */
#define CDD_DMA_START_SEC_VAR_INIT_PTR
#include "Cdd_Dma_MemMap.h"
P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONST) Cdd_Dma_CfgPtr = NULL_PTR;
#define CDD_DMA_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Dma_MemMap.h"
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
/** \brief Validates that WR_DATASIZE is an integral multiple of DATASIZE
 *
 * \param DataSize Source data size (read port)
 * \param WrDataSize Destination data size (write port)
 * \pre None
 * \post None
 * \return Status of validation check
 * \retval TRUE if configuration is valid
 * \retval FALSE if configuration is not valid
 *********************************************************************************************************************/
static FUNC(boolean, CDD_DMA_CODE)
    Cdd_Dma_IsDataSizeConfigValid(VAR(Cdd_Dma_ChannelDataSizeType, AUTOMATIC) DataSize,
                                  VAR(Cdd_Dma_ChannelWrDataSizeType, AUTOMATIC) WrDataSize);

/** \brief Validates common channel parameters (initialization and channel ID)
 *
 * \param ChannelId Channel identifier
 * \param ServiceId Service ID of the calling API
 * \pre None
 * \post Reports DET error if validation fails
 * \return Status of validation check
 * \retval E_OK if all validations pass
 * \retval E_NOT_OK if any validation fails
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ValidateInitAndChannelId(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) ServiceId);

/** \brief Validates channel state (not committed and not busy)
 *
 * \param ChannelId Channel identifier
 * \param ServiceId Service ID of the calling API
 * \pre Driver must be initialized and channel ID must be valid
 * \post Reports DET error if validation fails
 * \return Status of validation check
 * \retval E_OK if channel is not committed and not busy
 * \retval E_NOT_OK if channel is committed or busy
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ValidateChannelState(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) ServiceId);

/** \brief Validates peripheral event trigger state for forcing peripheral event trigger
 *
 * \param ChannelId Channel identifier
 * \pre Driver must be initialized and channel ID must be valid
 * \post Reports DET error if validation fails
 * \return Status of validation check
 * \retval E_OK if peripheral event trigger is enabled and no trigger is pending
 * \retval E_NOT_OK if peripheral event trigger is disabled or trigger already pending
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ValidateForcePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Validates peripheral event trigger state for clearing peripheral event trigger
 *
 * \param ChannelId Channel identifier
 * \pre Driver must be initialized and channel ID must be valid
 * \post Reports DET error if validation fails
 * \return Status of validation check
 * \retval E_OK if peripheral event trigger is enabled and trigger is pending
 * \retval E_NOT_OK if peripheral event trigger is disabled or no trigger to clear
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ValidateClearPeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);
#endif

/** \brief Configures peripheral event trigger
 *
 * \param BaseAddress Channel base address
 * \param PeripheralEventTrigSrc Peripheral event trigger source
 * \param PeripheralEvntTrigEnable Enable/disable peripheral event trigger
 * \pre Channel must be unlocked
 * \post Peripheral event trigger is configured
 * \return None
 *********************************************************************************************************************/
static FUNC(void, CDD_DMA_CODE)
    Cdd_Dma_ConfigurePeripheralEventTrigger(VAR(uint32, AUTOMATIC) BaseAddress,
                                            VAR(Cdd_Dma_PeriEvtTriggerSrcType, AUTOMATIC) PeripheralEventTrigSrc,
                                            VAR(Cdd_Dma_PeriEvtTrigEnableType, AUTOMATIC) PeripheralEvntTrigEnable);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_DMA_START_SEC_CODE
#include "Cdd_Dma_MemMap.h"

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_DMA_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* If VersionInfoPtr is NULL */
    if ((Std_VersionInfoType *)NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_GET_VERSION_INFO,
                              CDD_DMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = CDD_DMA_VENDOR_ID;
        VersionInfoPtr->moduleID         = CDD_DMA_MODULE_ID;
        VersionInfoPtr->instanceID       = CDD_DMA_INSTANCE_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_DMA_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_DMA_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_DMA_SW_PATCH_VERSION;
    }
}
#endif

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_Init(P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONFIG_DATA) ConfigPtr)
{
    /* Config pointer initialised with NULL_PTR */
    P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONFIG_DATA) config_ptr = NULL_PTR;
#if (STD_ON == CDD_DMA_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        config_ptr = &CDD_DMA_PRE_COMPILE_VARIANT_CONFIG;
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        config_ptr = ConfigPtr;
    }
#endif /*CDD_DMA_PRE_COMPILE_VARIANT*/

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Cdd_Dma module must not be initialized. Otherwise call the Det with CDD_DMA_E_ALREADY_INITIALIZED */
    if (TRUE == Cdd_Dma_IsInitialized)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_INIT, CDD_DMA_E_ALREADY_INITIALIZED);
    }
    else if (NULL_PTR == config_ptr)
    {
        /* API is being called with invalid config param */
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_INIT, CDD_DMA_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CDD_DMA_DEV_ERROR_DETECT */
    {
        /* Save the pointer to configuration */
        Cdd_Dma_CfgPtr = config_ptr;

        /* Initialize the driver object with channel lookup table and set configuration pointers */
        Cdd_Dma_DrvObjInit(Cdd_Dma_CfgPtr);

        /* Initialize the DMA instances */
        if (Cdd_Dma_HwUnitInit() == E_OK)
        {
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
            /* Lock channel configuration for all configured channels */
            Cdd_Dma_ChConfigLockConfigurationAll();
#endif
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
            Cdd_Dma_IsInitialized = TRUE; /* Update the initialized flag to true */
#endif                                    /* STD_ON == CDD_DMA_DEV_ERROR_DETECT */
        }
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
        else
        {
            /* DMA configurations are already committed, cannot initialize */
            (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_INIT, CDD_DMA_E_INIT_FAILED);
        }
#endif /* STD_ON == CDD_DMA_DEV_ERROR_DETECT */
    }
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_DeInit(void)
{
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_DEINIT, CDD_DMA_E_UNINIT);
    }
    else
#endif
    {
        /* Deinitialize the DMA HW Units */
        Cdd_Dma_HwUnitDeinit();
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
        Cdd_Dma_IsInitialized = FALSE;
#endif
    }
    return;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetChannelProperties(VAR(uint8, AUTOMATIC) ChannelId,
                             VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) ChannelProperties)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_CHANNEL_PROPERTIES) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateInitAndChannelId*/
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_CHANNEL_PROPERTIES) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateChannelState*/
    }
    /* Check if DATASIZE >= WR_DATASIZE (DST size is integral multiple of SRC) */
    else if (Cdd_Dma_IsDataSizeConfigValid(ChannelProperties.DataSize, ChannelProperties.WrDataSize) == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_PROPERTIES,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set data size and write data size */
        Cdd_Dma_SetDataSize(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, ChannelProperties.DataSize,
                            ChannelProperties.WrDataSize);

        /* Set mode: One-shot and Continuous */
        Cdd_Dma_SetMode(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, ChannelProperties.OneShotMode,
                        ChannelProperties.ContinuousMode);

        /* Set interrupt mode*/
        Cdd_Dma_SetInterruptMode(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, ChannelProperties.ChIntMode);

        /* Configure peripheral event trigger */
        Cdd_Dma_ConfigurePeripheralEventTrigger(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                                ChannelProperties.PeripheralEventTrigSrc,
                                                ChannelProperties.PeripheralEvntTrigEnable);

        /* Set interrupt enable */
        Cdd_Dma_SetInterruptEnable(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, ChannelProperties.ChannelIntEnable);

        /* Set overflow interrupt enable */
        Cdd_Dma_SetOverflowInterruptEnable(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                           ChannelProperties.OverflowIntEnable);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferProperties(VAR(uint8, AUTOMATIC) ChannelId,
                              VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) TransferProperties)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_PROPERTIES) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateInitAndChannelId */
    }
    /* Check if BurstSize, TransferSize, or WrapSize is zero (would cause underflow) */
    else if ((TransferProperties.TransferSizeProperties.BurstSize == 0U) ||
             (TransferProperties.TransferSizeProperties.TransferSize == 0U) ||
             (TransferProperties.SrcWrapProperties.SrcWrapSize == 0U) ||
             (TransferProperties.DestWrapProperties.DestWrapSize == 0U))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_TRANSFER_PROPERTIES,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_PROPERTIES) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateChannelState */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer size properties: Burst size and Transfer size */
        Cdd_Dma_SetTransferSize_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                     TransferProperties.TransferSizeProperties.BurstSize,
                                     TransferProperties.TransferSizeProperties.TransferSize);

        /* Set transfer source properties: Burst step and Transfer step */
        Cdd_Dma_SetTransferSrcStep_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                        TransferProperties.SrcStepSize.SrcBurstStep,
                                        TransferProperties.SrcStepSize.SrcTransferStep);

        /* Set transfer destination properties: Burst step and Transfer step */
        Cdd_Dma_SetTransferDestStep_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                         TransferProperties.DestStepSize.DestBurstStep,
                                         TransferProperties.DestStepSize.DestTransferStep);

        /* Set transfer source address */
        Cdd_Dma_SetTransferSrcAddress_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, TransferProperties.SrcAddress);

        /* Set transfer destination address */
        Cdd_Dma_SetTransferDestAddress_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                            TransferProperties.DestAddress);

        /* Set transfer source wrap properties: Wrap size, Wrap step, Begin address */
        Cdd_Dma_SetTransferWrapSrc(
            Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, TransferProperties.SrcWrapProperties.SrcWrapSize,
            TransferProperties.SrcWrapProperties.SrcWrapStep, TransferProperties.SrcWrapProperties.SrcBegAddress);

        /* Set transfer destination wrap properties: Wrap size, Wrap step, Begin address */
        Cdd_Dma_SetTransferWrapDest(
            Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, TransferProperties.DestWrapProperties.DestWrapSize,
            TransferProperties.DestWrapProperties.DestWrapStep, TransferProperties.DestWrapProperties.DestBegAddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSize(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) BurstSize,
                        VAR(uint16, AUTOMATIC) TransferSize)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_SIZE) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateInitAndChannelId */
    }
    /* Check if BurstSize or TransferSize is zero (would cause underflow) */
    else if ((BurstSize == 0U) || (TransferSize == 0U))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_TRANSFER_SIZE,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_SIZE) != E_OK)
    {
        /* DET is already raised by Cdd_Dma_ValidateChannelState */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer size properties: Burst size and Transfer size */
        Cdd_Dma_SetTransferSize_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, BurstSize, TransferSize);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSrcProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(sint16, AUTOMATIC) SrcBurstStep,
                                 VAR(sint16, AUTOMATIC) SrcTransferStep)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_SRC_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_SRC_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer source properties: Burst step and Transfer step */
        Cdd_Dma_SetTransferSrcStep_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, SrcBurstStep, SrcTransferStep);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferDestProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(sint16, AUTOMATIC) DestBurstStep,
                                  VAR(sint16, AUTOMATIC) DestTransferStep)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_DEST_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_DEST_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer destination properties: Burst step and Transfer step */
        Cdd_Dma_SetTransferDestStep_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, DestBurstStep, DestTransferStep);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSrcAddress(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint32, AUTOMATIC) SrcAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_SRC_ADDRESS) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_SRC_ADDRESS) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer source address */
        Cdd_Dma_SetTransferSrcAddress_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, SrcAddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferDestAddress(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint32, AUTOMATIC) DestAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_DEST_ADDRESS) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_DEST_ADDRESS) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer destination address */
        Cdd_Dma_SetTransferDestAddress_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, DestAddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapSrcProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint16, AUTOMATIC) SrcWrapSize,
                                     VAR(sint16, AUTOMATIC) SrcWrapStep, VAR(uint32, AUTOMATIC) SrcBegAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_WRAP_SRC_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Check if SrcWrapSize is zero (would cause underflow) */
    else if (SrcWrapSize == 0U)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_TRANSFER_WRAP_SRC_PROPERTIES,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_WRAP_SRC_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer source wrap properties: Wrap size, Wrap step, Begin address */
        Cdd_Dma_SetTransferWrapSrc(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, SrcWrapSize, SrcWrapStep,
                                   SrcBegAddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapDestProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint16, AUTOMATIC) DestWrapSize,
                                      VAR(sint16, AUTOMATIC) DestWrapStep, VAR(uint32, AUTOMATIC) DestBegAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_TRANSFER_WRAP_DEST_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Check if DestWrapSize is zero (would cause underflow) */
    else if (DestWrapSize == 0U)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_TRANSFER_WRAP_DEST_PROPERTIES,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_TRANSFER_WRAP_DEST_PROPERTIES) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set transfer destination wrap properties: Wrap size, Wrap step, Begin address */
        Cdd_Dma_SetTransferWrapDest(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress, DestWrapSize, DestWrapStep,
                                    DestBegAddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_EnablePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_ENABLE_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_ENABLE_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Check if peripheral event trigger is already enabled */
    else if (Cdd_Dma_IsPeripheralEventTriggerEnabled(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_ENABLE_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_ENABLED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Enable peripheral event trigger */
        Cdd_Dma_SetPeripheralEventTriggerEnable_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                                     CDD_DMA_PERI_EVT_TRIG_ENABLED);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_DisablePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_DISABLE_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_DISABLE_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Check if peripheral event trigger is already disabled */
    else if (Cdd_Dma_IsPeripheralEventTriggerEnabled(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_DISABLE_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_DISABLED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Disable peripheral event trigger */
        Cdd_Dma_SetPeripheralEventTriggerEnable_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                                     CDD_DMA_PERI_EVT_TRIG_DISABLED);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerSource(VAR(uint8, AUTOMATIC) ChannelId,
                                        VAR(Cdd_Dma_PeriEvtTriggerSrcType, AUTOMATIC) PeripheralEventTrigSrc)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_SET_PERIPHERAL_EVENT_TRIGGER_SOURCE) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate channel state (not committed and not busy) */
    else if (Cdd_Dma_ValidateChannelState(ChannelId, CDD_DMA_SID_SET_PERIPHERAL_EVENT_TRIGGER_SOURCE) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Unlock channel configuration */
        Cdd_Dma_ChConfigUnlockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        /* Set peripheral event trigger source */
        Cdd_Dma_SetPeripheralEventTriggerSource_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress,
                                                     PeripheralEventTrigSrc);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        /* Lock channel configuration */
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
#endif
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_StartChannelTransfer(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_START_CHANNEL_TRANSFER,
                              CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_START_CHANNEL_TRANSFER,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (CDD_DMA_CHANNEL_RUNNING == Cdd_Dma_GetRunStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_START_CHANNEL_TRANSFER,
                              CDD_DMA_E_ALREADY_RUNNING);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Start the DMA channel */
        Cdd_Dma_StartChannelTransfer_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_StopChannelTransfer(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_STOP_CHANNEL_TRANSFER,
                              CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_STOP_CHANNEL_TRANSFER,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (CDD_DMA_CHANNEL_NOT_RUNNING == Cdd_Dma_GetRunStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_STOP_CHANNEL_TRANSFER,
                              CDD_DMA_E_ALREADY_HALTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Stop the DMA channel */
        Cdd_Dma_StopChannelTransfer_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_ForcePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_FORCE_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate peripheral event trigger state */
    else if (Cdd_Dma_ValidateForcePeripheralEventTrigger(ChannelId) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Force peripheral event trigger */
        Cdd_Dma_ForcePeripheralEventTrigger_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_ClearPeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Validate initialization and channel ID */
    if (Cdd_Dma_ValidateInitAndChannelId(ChannelId, CDD_DMA_SID_CLEAR_PERIPHERAL_EVENT_TRIGGER) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    /* Validate peripheral event trigger state */
    else if (Cdd_Dma_ValidateClearPeripheralEventTrigger(ChannelId) != E_OK)
    {
        /* Validation failed, error already reported */
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Clear peripheral event trigger flag */
        Cdd_Dma_ClearPeripheralEventTrigger_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_TriggerSoftReset(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_TRIGGER_SOFT_RESET, CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_TRIGGER_SOFT_RESET,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Trigger soft reset */
        Cdd_Dma_TriggerSoftReset_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_GetChannelStatus(VAR(uint8, AUTOMATIC) ChannelId,
                         P2VAR(Cdd_Dma_ChannelStatus, AUTOMATIC, CDD_DMA_APPL_DATA) ChannelStatus)
{
#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_GET_CHANNEL_STATUS, CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_GET_CHANNEL_STATUS,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Check if ChannelStatus pointer is NULL */
    else if (ChannelStatus == NULL_PTR)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_GET_CHANNEL_STATUS,
                              CDD_DMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        /* Get peripheral event trigger flag status */
        ChannelStatus->PeripheralEventTriggerFlag =
            Cdd_Dma_GetPeripheralEventTriggerFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);

        /* Get transfer status flag */
        ChannelStatus->TransferStatus = Cdd_Dma_GetTransferStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);

        /* Get burst status flag */
        ChannelStatus->BurstStatus = Cdd_Dma_GetBurstStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);

        /* Get run status flag */
        ChannelStatus->RunStatus = Cdd_Dma_GetRunStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);

        /* Get overflow status flag */
        ChannelStatus->OverflowStatus = Cdd_Dma_GetOverflowStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
    }
}

FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_ClearErrorFlag(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_CLEAR_ERROR_FLAG, CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_CLEAR_ERROR_FLAG,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Check if overflow flag is set before clearing */
    else if (Cdd_Dma_GetOverflowStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) ==
             CDD_DMA_OVERFLOW_NOT_DETECTED)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_CLEAR_ERROR_FLAG,
                              CDD_DMA_E_NO_OVERFLOW);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Set error clear to clear error conditions */
        Cdd_Dma_ClearErrorFlag_Priv(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetChannelPriority(VAR(uint8, AUTOMATIC) ChannelId, Cdd_Dma_ChannelPriority Priority)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_PRIORITY,
                              CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_PRIORITY,
                              CDD_DMA_E_PARAM_VALUE);
    }
    /* Check if Dma hardware instance configurations are committed */
    else if (Cdd_Dma_IsHwInstanceCommittedForChannel(ChannelId) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_PRIORITY,
                              CDD_DMA_E_DMACFG_COMMITTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Update the channel priority*/
        Cdd_Dma_UpdateChannelPriority(ChannelId, Priority);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetDmaCfgCommit(VAR(uint8, AUTOMATIC) HwInstanceId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_DMACFG_COMMIT, CDD_DMA_E_UNINIT);
    }
    /* Validate HwInstanceId */
    else if (HwInstanceId >= CDD_DMA_HW_INSTANCE_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_DMACFG_COMMIT,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (Cdd_Dma_CheckConfigurationCommit(Cdd_Dma_CfgPtr->hwinstcfg[HwInstanceId].baseaddress) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_DMACFG_COMMIT,
                              CDD_DMA_E_DMACFG_COMMITTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Set DMA configuration commit (permanent lock) for the specified HW instance */
        Cdd_Dma_SetDmaCfgCommit_Priv(HwInstanceId);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetChannelCommit(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_COMMIT, CDD_DMA_E_UNINIT);
    }
    /* Validate ChannelId */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_COMMIT,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (Cdd_Dma_CheckChannelConfigCommit(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_CHANNEL_COMMIT,
                              CDD_DMA_E_CHCFG_COMMITTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Set channel configuration commit (permanent lock) for the specified channel */
        Cdd_Dma_SetChannelCommit_Priv(ChannelId);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetMpuCfgCommit(VAR(uint8, AUTOMATIC) HwInstanceId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUCFG_COMMIT, CDD_DMA_E_UNINIT);
    }
    /* Validate HwInstanceId */
    else if (HwInstanceId >= CDD_DMA_HW_INSTANCE_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUCFG_COMMIT,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (Cdd_Dma_CheckMpuConfigCommit(Cdd_Dma_CfgPtr->hwinstcfg[HwInstanceId].mpubaseaddress) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUCFG_COMMIT,
                              CDD_DMA_E_MPUCFG_COMMITTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Set MPU configuration commit for the specified HW instance */
        Cdd_Dma_SetMpuCfgCommit_Priv(HwInstanceId);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetMpuRegionCommit(VAR(uint16, AUTOMATIC) MpuRegionId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;
    VAR(uint8, AUTOMATIC) hw_inst_idx;
    VAR(uint8, AUTOMATIC) mpu_region_idx;

    hw_inst_idx    = (uint8)((MpuRegionId >> 8U) & 0xFFU);
    mpu_region_idx = (uint8)(MpuRegionId & 0xFFU);

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUR_COMMIT, CDD_DMA_E_UNINIT);
    }
    else if ((hw_inst_idx >= CDD_DMA_HW_INSTANCE_COUNT) ||
             (mpu_region_idx >= Cdd_Dma_CfgPtr->hwinstcfg[hw_inst_idx].mpuregioncount))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUR_COMMIT,
                              CDD_DMA_E_PARAM_VALUE);
    }
    else if (Cdd_Dma_CheckMpuRegionCommit(Cdd_Dma_CfgPtr->hwinstcfg[hw_inst_idx].mpubaseaddress,
                                          Cdd_Dma_CfgPtr->hwinstcfg[hw_inst_idx].mpucfg[mpu_region_idx].mpuregion) ==
             TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_SET_MPUR_COMMIT,
                              CDD_DMA_E_MPUR_COMMITTED);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        /* Set MPU region configuration commit for the specified MPU region */
        Cdd_Dma_SetMpuRegionCommit_Priv(hw_inst_idx, mpu_region_idx);
        SchM_Exit_Cdd_Dma_CDD_DMA_EXCLUSIVE_AREA_0();
        ret_val = E_OK;
    }

    return ret_val;
}

#define CDD_DMA_STOP_SEC_CODE
#include "Cdd_Dma_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define CDD_DMA_START_SEC_CODE
#include "Cdd_Dma_MemMap.h"

#if (STD_ON == CDD_DMA_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ValidateInitAndChannelId(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) ServiceId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    /* Check if driver is initialized */
    if (Cdd_Dma_IsInitialized == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, ServiceId, CDD_DMA_E_UNINIT);
    }
    /* Check if ChannelId is valid */
    else if (ChannelId >= CDD_DMA_CHANNEL_COUNT)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, ServiceId, CDD_DMA_E_PARAM_VALUE);
    }
    else
    {
        /* All validations passed */
        ret_val = E_OK;
    }

    return ret_val;
}

static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ValidateChannelState(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) ServiceId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    /* Check if Channel is committed */
    if (Cdd_Dma_CheckChannelConfigCommit(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == TRUE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, ServiceId, CDD_DMA_E_CHCFG_COMMITTED);
    }
    /* Check if Channel is busy */
    else if ((Cdd_Dma_GetTransferStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) ==
              CDD_DMA_TRANSFER_ACTIVITY_ONGOING) ||
             (Cdd_Dma_GetBurstStatusFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) ==
              CDD_DMA_BURST_ACTIVITY_ONGOING))
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, ServiceId, CDD_DMA_E_BUSY);
    }
    else
    {
        /* All validations passed */
        ret_val = E_OK;
    }

    return ret_val;
}

static FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ValidateForcePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    /* Check if peripheral event trigger is enabled */
    if (Cdd_Dma_IsPeripheralEventTriggerEnabled(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_FORCE_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_DISABLED);
    }
    /* Check if trigger is already pending */
    else if (Cdd_Dma_GetPeripheralEventTriggerFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) ==
             CDD_DMA_PENDING_EVT_TRIG)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_FORCE_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_BUSY);
    }
    else
    {
        /* All validations passed */
        ret_val = E_OK;
    }

    return ret_val;
}

static FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ValidateClearPeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    /* Check if peripheral event trigger is enabled */
    if (Cdd_Dma_IsPeripheralEventTriggerEnabled(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) == FALSE)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_CLEAR_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_DISABLED);
    }
    /* Check if no trigger exists*/
    else if (Cdd_Dma_GetPeripheralEventTriggerFlag(Cdd_Dma_CfgPtr->chcfg[ChannelId].baseaddress) ==
             CDD_DMA_WAITING_FOR_EVT_TRIG)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, CDD_DMA_INSTANCE_ID, CDD_DMA_SID_CLEAR_PERIPHERAL_EVENT_TRIGGER,
                              CDD_DMA_E_NO_TRIGGER);
    }
    else
    {
        /* All validations passed */
        ret_val = E_OK;
    }

    return ret_val;
}

static FUNC(boolean, CDD_DMA_CODE)
    Cdd_Dma_IsDataSizeConfigValid(VAR(Cdd_Dma_ChannelDataSizeType, AUTOMATIC) DataSize,
                                  VAR(Cdd_Dma_ChannelWrDataSizeType, AUTOMATIC) WrDataSize)
{
    VAR(boolean, AUTOMATIC) is_valid = FALSE;
    VAR(uint8, AUTOMATIC) data_size_bits;
    VAR(uint8, AUTOMATIC) wr_data_size_bits;

    /* Extract bit size from DataSize enum value
     * Formula: bits = 8 << (DataSize >> 17) */
    data_size_bits = (uint8)(8U << ((uint32)DataSize >> 17U));

    /* Extract bit size from WrDataSize enum value
     * Formula: bits = 8 << (WrDataSize >> 20)*/
    wr_data_size_bits = (uint8)(8U << ((uint32)WrDataSize >> 20U));

    /* Validation: WR_DATASIZE must be less than or equal to DATASIZE */
    if (wr_data_size_bits <= data_size_bits)
    {
        is_valid = TRUE;
    }

    return is_valid;
}
#endif /* STD_ON == CDD_DMA_DEV_ERROR_DETECT */

static FUNC(void, CDD_DMA_CODE)
    Cdd_Dma_ConfigurePeripheralEventTrigger(VAR(uint32, AUTOMATIC) BaseAddress,
                                            VAR(Cdd_Dma_PeriEvtTriggerSrcType, AUTOMATIC) PeripheralEventTrigSrc,
                                            VAR(Cdd_Dma_PeriEvtTrigEnableType, AUTOMATIC) PeripheralEvntTrigEnable)
{
    /* Configure peripheral event trigger source first */
    Cdd_Dma_SetPeripheralEventTriggerSource_Priv(BaseAddress, PeripheralEventTrigSrc);

    /* Enable or disable peripheral event trigger */
    Cdd_Dma_SetPeripheralEventTriggerEnable_Priv(BaseAddress, PeripheralEvntTrigEnable);
}

#define CDD_DMA_STOP_SEC_CODE
#include "Cdd_Dma_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Dma.c
 *********************************************************************************************************************/
