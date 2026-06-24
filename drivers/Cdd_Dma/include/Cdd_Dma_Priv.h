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
 *  File:       Cdd_Dma_Priv.h
 *  Generator:  None
 *
 *  Description:   This file contains data structures and private function declarations of private
 *API's.
 *********************************************************************************************************************/
#ifndef CDD_DMA_PRIV_H
#define CDD_DMA_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_rtdma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* Design: MCAL-39309 */
/** \brief DMA Driver Object Structure */
typedef struct Cdd_Dma_DriverObjTag
{
    /** \brief 2D lookup table: [instance][channel] -> configuration array index
     *
     * - First dimension: DMA instance (0=RTDMA1, 1=RTDMA2)
     * - Second dimension: DMA channel (0=CH1, 1=CH2, ... 9=CH10)
     * - Value: Index into Cdd_Dma_ConfigPtr->chcfg[] array
     * - 0xFF indicates channel is not configured
     */
    uint8 channelindex[CDD_DMA_HW_INSTANCE_MAX][CDD_DMA_CHANNEL_MAX];
} Cdd_Dma_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *  Design: MCAL-39317
 *********************************************************************************************************************/
/** \brief Initialize the driver object with channel lookup table and set configuration pointer
 *
 * \param[in]  CfgPtr Configuration pointer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_DrvObjInit(P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONST) CfgPtr);

/** \brief Initializes the DMA HW instances
 * \pre None
 * \post None
 * \return None
 * \retval None
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_HwUnitInit(void);

/** \brief Deinitialize the DMA HW instances
 * \pre None
 * \post None
 * \return None
 * \retval None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_HwUnitDeinit(void);

/** \brief Initializes the MPU Region
 *
 * \param[in]  MpuBaseAddress MPU base address
 * \param[in]  MpuRegionCfg  MPU Region configurations
 * \pre None
 * \post None
 * \return None
 * \retval None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuRegionInit(uint32 MpuBaseAddress, Cdd_Dma_MpuRegionCfgType MpuRegionCfg);

/** \brief Sets the data size for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  DataSize Read data size
 * \param[in]  WrDataSize Write data size
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetDataSize(uint32 Base, Cdd_Dma_ChannelDataSizeType DataSize, Cdd_Dma_ChannelWrDataSizeType WrDataSize);

/** \brief Sets the modes for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  OneShotMode One-shot mode enable/disable
 * \param[in]  ContinuousMode Continuous mode enable/disable
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetMode(uint32 Base, Cdd_Dma_OneshotModeEnableType OneShotMode,
                Cdd_Dma_ContinuousModeEnableType ContinuousMode);

/** \brief Sets the interrupt mode for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  IntMode Interrupt mode (beginning or end of transfer)
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetInterruptMode(uint32 Base, Cdd_Dma_ChIntModeType IntMode);

/** \brief Enables the interrupt for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  IntEnable Interrupt enable/disable
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetInterruptEnable(uint32 Base, Cdd_Dma_ChIntEnableType IntEnable);

/** \brief Sets the overflow interrupt mode for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  OvrflowIntEnable Overflow interrupt enable/disable
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetOverflowInterruptEnable(uint32 Base, Cdd_Dma_OvrflowIntEnableType OvrflowIntEnable);

/** \brief Sets peripheral event trigger enable/disable for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  PeripheralEvntTrigEnable Enable/disable peripheral event trigger
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerEnable_Priv(uint32 Base, Cdd_Dma_PeriEvtTrigEnableType PeripheralEvntTrigEnable);

/** \brief Sets the peripheral event trigger source for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  PeripheralEventTrigSrc Peripheral event trigger source
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerSource_Priv(uint32 Base, Cdd_Dma_PeriEvtTriggerSrcType PeripheralEventTrigSrc);

/** \brief Sets the transfer sizes for DMA channel : Burst size and Transfer size
 *
 * \param[in]  Base Channel base address
 * \param[in]  BurstSize Burst size
 * \param[in]  TransferSize Transfer size
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSize_Priv(uint32 Base, uint16 BurstSize, uint32 TransferSize);

/** \brief Sets the transfer source step for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  SrcBurstStep Source burst step
 * \param[in]  SrcTransferStep Source transfer step
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSrcStep_Priv(uint32 Base, sint16 SrcBurstStep, sint16 SrcTransferStep);

/** \brief Sets the transfer destination step for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  DestBurstStep Destination burst step
 * \param[in]  DestTransferStep Destination transfer step
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferDestStep_Priv(uint32 Base, sint16 DestBurstStep, sint16 DestTransferStep);

/** \brief Sets the transfer source address for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  SrcAddress Source address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSrcAddress_Priv(uint32 Base, uint32 SrcAddress);

/** \brief Sets the transfer destination address for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  DestAddress Destination address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferDestAddress_Priv(uint32 Base, uint32 DestAddress);

/** \brief Sets the transfer source wrap properties for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  SrcWrapSize Source wrap size
 * \param[in]  SrcWrapStep Source wrap step
 * \param[in]  SrcBegAddress Source beginning address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapSrc(uint32 Base, uint32 SrcWrapSize, sint16 SrcWrapStep, uint32 SrcBegAddress);

/** \brief Sets the transfer destination wrap properties for DMA channel
 *
 * \param[in]  Base Channel base address
 * \param[in]  DestWrapSize Destination wrap size
 * \param[in]  DestWrapStep Destination wrap step
 * \param[in]  DestBegAddress Destination beginning address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapDest(uint32 Base, uint32 DestWrapSize, sint16 DestWrapStep, uint32 DestBegAddress);

/** \brief Starts a DMA channel transfer
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_StartChannelTransfer_Priv(uint32 Base);

/** \brief Stops a DMA channel transfer
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_StopChannelTransfer_Priv(uint32 Base);

/** \brief Forces peripheral event trigger for DMA channel
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ForcePeripheralEventTrigger_Priv(uint32 Base);

/** \brief Clears peripheral event trigger flag for DMA channel
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ClearPeripheralEventTrigger_Priv(uint32 Base);

/** \brief Triggers soft reset for DMA channel
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_TriggerSoftReset_Priv(uint32 Base);

/** \brief Checks if peripheral event trigger is enabled
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return boolean TRUE if peripheral event trigger is enabled, FALSE otherwise
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_IsPeripheralEventTriggerEnabled(uint32 Base);

/** \brief Gets peripheral event trigger flag status
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return Cdd_Dma_PeriEvtTrigStatusType Peripheral event trigger flag status
 *********************************************************************************************************************/
FUNC(Cdd_Dma_PeriEvtTrigStatusType, CDD_DMA_CODE) Cdd_Dma_GetPeripheralEventTriggerFlag(uint32 Base);

/** \brief Gets transfer status flag
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return Cdd_Dma_TransferStatusType Transfer status flag
 *********************************************************************************************************************/
FUNC(Cdd_Dma_TransferStatusType, CDD_DMA_CODE) Cdd_Dma_GetTransferStatusFlag(uint32 Base);

/** \brief Gets burst status flag
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return Cdd_Dma_BurstStatusType Burst status flag
 *********************************************************************************************************************/
FUNC(Cdd_Dma_BurstStatusType, CDD_DMA_CODE) Cdd_Dma_GetBurstStatusFlag(uint32 Base);

/** \brief Gets run status flag
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return Cdd_Dma_RunStatusType Run status flag
 *********************************************************************************************************************/
FUNC(Cdd_Dma_RunStatusType, CDD_DMA_CODE) Cdd_Dma_GetRunStatusFlag(uint32 Base);

/** \brief Gets overflow status flag
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return Cdd_Dma_OverflowStatusType Overflow status flag
 *********************************************************************************************************************/
FUNC(Cdd_Dma_OverflowStatusType, CDD_DMA_CODE) Cdd_Dma_GetOverflowStatusFlag(uint32 Base);

/** \brief Sets error clear to clear error conditions
 *
 * \param[in]  Base Channel base address
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ClearErrorFlag_Priv(uint32 Base);

/** \brief Updates channel priority by writing to SWPRI1 or SWPRI2 register
 *
 * This function updates the priority for a specific DMA channel by performing a read-modify-write operation on the
 *appropriate SWPRI register.
 * - Channels 1-8 use SWPRI1 register (4 bits per channel)
 * - Channels 9-10 use SWPRI2 register (4 bits per channel)
 *
 * \param[in]  ChannelId Symbolic name of the channel for which priority shall be set
 * \param[in]  HwInstIdx Hardware instance index in the configuration structure
 * \param[in]  Priority  Priority value to set
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_UpdateChannelPriority(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) HwInstIdx,
                              Cdd_Dma_ChannelPriority Priority);

/** \brief Reads channel priority from SWPRI1 or SWPRI2 register
 *
 * This function reads the priority for a specific DMA channel from the appropriate SWPRI register.
 * - Channels 1-8 use SWPRI1 register (4 bits per channel)
 * - Channels 9-10 use SWPRI2 register (4 bits per channel)
 *
 * \param[in]  ChannelId Symbolic name of the channel for which priority shall be read
 * \param[in]  HwInstIdx Hardware instance index in the configuration structure
 * \param[out] Priority  Pointer to memory location where the channel priority will be stored
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_ReadChannelPriority(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) HwInstIdx,
                            P2VAR(Cdd_Dma_ChannelPriority, AUTOMATIC, CDD_DMA_APPL_DATA) Priority);

/** \brief Finds the hardware instance index for a given DMA instance
 *
 * \param[in]  Instance   DMA instance type
 * \param[out] IndexPtr   Pointer to variable where the hardware instance index will be stored
 * \pre None
 * \post None
 * \return Status of finding hardware instance index
 * \retval E_OK: Successfully found hardware instance index
 * \retval E_NOT_OK: Hardware instance not found
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_GetHwInstanceIndex(VAR(Cdd_Dma_InstanceType, AUTOMATIC) Instance,
                           P2VAR(uint8, AUTOMATIC, CDD_DMA_APPL_DATA) IndexPtr);

/** \brief Checks if DMA hardware instance configuration is committed for a given channel
 *
 * \param[in]  ChannelId Channel identifier
 * \pre None
 * \post None
 * \return Status of DMA hardware instance configuration commit
 * \retval TRUE: DMA hardware instance configuration is committed
 * \retval FALSE: DMA hardware instance configuration is not committed
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_IsHwInstanceCommittedForChannel(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Sets DMA configuration commit (permanent lock) for a specific DMA instance
 *
 * \param[in] HwInstanceId Hardware instance index
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetDmaCfgCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId);

/** \brief Sets channel configuration commit (permanent lock) for a specific channel
 *
 * \param[in] ChannelId Channel configuration index
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetChannelCommit_Priv(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Sets MPU configuration commit (permanent lock) for a specific DMA instance
 *
 * \param[in] HwInstanceId Hardware instance index
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetMpuCfgCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId);

/** \brief Sets MPU region configuration commit (permanent lock) for a specific DMA MPU region
 *
 * \param[in] HwInstanceId Hardware instance index
 * \param[in] MpuRegionIdx MPU region index within the instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetMpuRegionCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId, VAR(uint8, AUTOMATIC) MpuRegionIdx);

/** \brief Periodic readback of DMA channel registers
 *
 * \param[in] ChannelId Channel identifier
 * \param[out] ReadBackRegisterdata Pointer to the read back registers structure
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_PeriodicReadbackPrv(VAR(uint8, AUTOMATIC) ChannelId,
                            P2VAR(Cdd_Dma_PeriodicReadBackDataType, AUTOMATIC, CDD_DMA_APPL_DATA) ReadBackRegisterdata);

/** \brief ISR function called by a specific interrupt
 *
 * This ISR call the notification function if enabled for the channel
 *
 * \param[in]  InstanceId DMA instance
 * \param[in]  ChannelId DMA channel
 * \pre Cdd_Dma_Init must be called before this function
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ProcessIsr(Cdd_Dma_InstanceType InstanceId, Cdd_Dma_ChannelType ChannelId);

#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
/** \brief Locks DMA instance configurations
 *
 * \param[in]  Base Base address of the DMA instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgLockConfiguration(uint32 Base);

/** \brief Unlocks DMA instance configurations
 *
 * \param[in]  Base Base address of the DMA instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgUnlockConfiguration(uint32 Base);
/** \brief Locks DMA Channel configurations
 *
 * \param[in]  Base Base address of the DMA Channel
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigLockConfiguration(uint32 Base);

/** \brief Unlocks DMA Channel configurations
 *
 * \param[in]  Base Base address of the DMA Channel
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigUnlockConfiguration(uint32 Base);

/** \brief Locks all DMA Channel configurations
 *
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigLockConfigurationAll(void);
#endif

/** \brief Checks whether channel configurations are committed for a DMA channel
 *
 * \param[in] Base : Base address of the DMA channel
 * \pre None
 * \post None
 * \return Status of DMA channel configurations commit
 * \retval TRUE: DMA channel configurations committed
 * \retval FALSE: DMA channel configurations not committed
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckChannelConfigCommit(uint32 Base);

/** \brief Checks whether DMA configurations are committed for a hardware instance
 *
 * \param[in] Base : Base address of the hardware instance
 * \pre None
 * \post None
 * \return Status of DMA instance configurations commit
 * \retval TRUE: DMA instance configurations committed
 * \retval FALSE: DMA instance configurations not committed
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckConfigurationCommit(uint32 Base);

/** \brief Checks whether MPU instance configurations are committed for a DMA MPU instance
 *
 * \param[in] Base : Base address of the DMA MPU instance
 * \pre None
 * \post None
 * \return Status of DMA MPU instance configurations commit
 * \retval TRUE: DMA MPU instance configurations committed
 * \retval FALSE: DMA MPU instance configurations not committed
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckMpuConfigCommit(uint32 Base);

/** \brief Checks whether MPU region configurations are committed for a DMA MPU region
 *
 * \param[in] Base : Base address of the DMA MPU
 * \param[in] MpuRegion : DMA MPU Region
 * \pre None
 * \post None
 * \return Status of DMA MPU region configurations commit
 * \retval TRUE: DMA MPU region configurations committed
 * \retval FALSE: DMA MPU region configurations not committed
 *********************************************************************************************************************/
FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckMpuRegionCommit(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion);
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CDD_DMA_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Priv.h
 *********************************************************************************************************************/
