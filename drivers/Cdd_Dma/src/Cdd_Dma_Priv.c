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
 *  File:       Cdd_Dma_Priv.c
 *  Generator:  None
 *
 *  Description: This file contains private function definitions that are defined in Cdd_Dma_Priv.h
 *file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Dma.h"
#include "Cdd_Dma_Priv.h"
#include "Mcal_Lib_Cpu.h"
#include "Mcal_Lib.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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

#define CDD_DMA_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Dma_MemMap.h"
static VAR(Cdd_Dma_DriverObjType, CDD_DMA_VAR_NO_INIT) Cdd_Dma_DrvObj;
#define CDD_DMA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Dma_MemMap.h"

#define CDD_DMA_START_SEC_VAR_INIT_PTR
#include "Cdd_Dma_MemMap.h"
/* Cdd_Dma configuration pointer to access driver configuration. */
P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONST) Cdd_Dma_ConfigPtr = NULL_PTR;
#define CDD_DMA_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Dma_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Initializes MPU regions for a DMA hardware instance
 *
 * \param[in]  hwunitcfg Pointer to hardware instance configuration
 * \pre None
 * \post None
 * \return Status of MPU region initialization
 * \retval E_OK: MPU regions initialized successfully
 * \retval E_NOT_OK: MPU region initialization failed
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_InitMpuRegions(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg);

/** \brief Configures MPU enable/disable for a DMA hardware instance
 *
 * \param[in]  hwunitcfg Pointer to hardware instance configuration
 * \pre None
 * \post None
 * \return Status of MPU configuration
 * \retval E_OK: MPU configured successfully
 * \retval E_NOT_OK: MPU configuration failed
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ConfigureMpu(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg);

/** \brief Initializes DMA instance basic configurations
 *
 * \param[in]  hwunitcfg Pointer to hardware instance configurations
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
static FUNC(void, CDD_DMA_CODE)
    Cdd_Dma_InitHwInstanceConfig(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg);

/** \brief Processes initialization of a single DMA hardware unit
 *
 * \param[in]  hwunitcfg Pointer to hardware instance configuration
 * \pre None
 * \post None
 * \return Status of hardware unit initialization
 * \retval E_OK: Hardware unit initialized successfully
 * \retval E_NOT_OK: Hardware unit initialization failed
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ProcessHwUnitInit(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_DMA_START_SEC_CODE
#include "Cdd_Dma_MemMap.h"

/** \brief Performs hard reset of the hardware instance
 *
 * \param[in]  Base Base address of the DMA hardware instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_HardReset(uint32 Base);

/** \brief Writes priority value to SWPRIO1, i.e, priorities of CH1-CH8
 *
 * \param[in]  Base Base address of the DMA hardware instance
 * \param[in]  SwPriority Priority values (4 bits per channel starting from LSB)
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPriority1(uint32 Base, uint32 SwPriority);

/** \brief Writes priority value to SWPRIO2, i.e, priorities of CH9, CH10
 *
 * \param[in]  Base Base address of the DMA hardware instance
 * \param[in]  SwPriority Priority values (4 bits per channel starting from LSB)
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPriority2(uint32 Base, uint32 SwPriority);

/** \brief Enables MPU instance
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnable(uint32 Base);

/** \brief Enables MPU instance
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuDisable(uint32 Base);

#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
/** \brief Locks DMA instance configurations
 *
 * \param[in]  Base Base address of the DMA instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgLockConfiguration(uint32 Base);

/** \brief Unlocks DMA instance configurations
 *
 * \param[in]  Base Base address of the DMA instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgUnlockConfiguration(uint32 Base);

/** \brief Locks DMA MPU instance configurations
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnableLockConfiguration(uint32 Base);

/** \brief Unocks DMA MPU instance configurations
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnableUnlockConfiguration(uint32 Base);

/** \brief Locks MPU Region configurations
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \param[in]  MpuRegion MpuRegion that needs to be locked
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuRegionLockConfiguration(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion);

/** \brief Unlocks MPU Region configurations
 *
 * \param[in]  Base Base address of the DMA MPU instance
 * \param[in]  MpuRegion MpuRegion that needs to be unlocked
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE)
    Cdd_Dma_MpuRegionUnlockConfiguration(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion);
#endif

/** \brief Configures the priority scheme of the DMA hardware instance
 *
 * \param[in]  Base Base address of the DMA instance
 * \param[in]  PrioritySelection Round robin or software configurable priority
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPrioritySelection(uint32 Base, Cdd_Dma_PriorityType PrioritySelection);

/** \brief Configures the emulation mode of the DMA hardware instance
 *
 * \param[in]  Base Base address of the DMA instance
 * \param[in]  EmulationMode Free running or halt
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetEmulationMode(uint32 Base, Cdd_Dma_EmulationModeType EmulationMode);

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_DrvObjInit(P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONST) CfgPtr)
{
    uint8                ch_idx;
    uint8                inst_idx;
    Cdd_Dma_InstanceType instance;
    Cdd_Dma_ChannelType  channel;

    /* Set the configuration pointer */
    Cdd_Dma_ConfigPtr = CfgPtr;

    /* Initialize all lookup table entries to invalid index (0xFF) */
    for (inst_idx = 0U; inst_idx < CDD_DMA_HW_INSTANCE_MAX; inst_idx++)
    {
        for (ch_idx = 0U; ch_idx < CDD_DMA_CHANNEL_MAX; ch_idx++)
        {
            Cdd_Dma_DrvObj.channelindex[inst_idx][ch_idx] = 0xFFU;
        }
    }

    /* Build lookup table from configuration */
    for (ch_idx = 0U; ch_idx < CDD_DMA_CHANNEL_COUNT; ch_idx++)
    {
        instance = Cdd_Dma_ConfigPtr->chcfg[ch_idx].instance;
        channel  = Cdd_Dma_ConfigPtr->chcfg[ch_idx].channel;

        /* Store configuration array index in lookup table */
        Cdd_Dma_DrvObj.channelindex[instance][channel] = ch_idx;
    }
}

static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ProcessHwUnitInit(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Check if DMACFG_COMMIT is already set */
    if (Cdd_Dma_CheckConfigurationCommit(hwunitcfg->baseaddress) == TRUE)
    {
        ret_val = E_NOT_OK;
    }
    else
    {
        /* Initialize basic DMA configuration */
        Cdd_Dma_InitHwInstanceConfig(hwunitcfg);

        /* Configure MPU */
        ret_val = Cdd_Dma_ConfigureMpu(hwunitcfg);
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_HwUnitInit(void)
{
    VAR(uint8, AUTOMATIC) hwunit_idx;
    P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg;
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Initialize each hw units from the configuration */
    for (hwunit_idx = 0U; hwunit_idx < CDD_DMA_HW_INSTANCE_COUNT; hwunit_idx++)
    {
        /* Get pointer to current hardware unit configuration */
        hwunitcfg = &(Cdd_Dma_ConfigPtr->hwinstcfg[hwunit_idx]);

        /* Process hardware unit initialization */
        ret_val = Cdd_Dma_ProcessHwUnitInit(hwunitcfg);

        if (ret_val != E_OK)
        {
            break;
        }
    }

    return ret_val;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_HwUnitDeinit(void)
{
    VAR(uint8, AUTOMATIC) hwunit_idx;
    VAR(uint8, AUTOMATIC) ch_idx;

    /* Disable interrupts for all configured channels before resetting hardware */
    for (ch_idx = 0U; ch_idx < CDD_DMA_CHANNEL_COUNT; ch_idx++)
    {
        /* Disable channel interrupt */
        Cdd_Dma_SetInterruptEnable(Cdd_Dma_ConfigPtr->chcfg[ch_idx].baseaddress, CDD_DMA_CHANNEL_INTERRUPT_DISABLED);

        /* Disable overflow interrupt */
        Cdd_Dma_SetOverflowInterruptEnable(Cdd_Dma_ConfigPtr->chcfg[ch_idx].baseaddress,
                                           CDD_DMA_OVERFLOW_INTERRUPT_DISABLED);
    }

    /* Perform hard reset of the hardware instances */
    for (hwunit_idx = 0U; hwunit_idx < CDD_DMA_HW_INSTANCE_COUNT; hwunit_idx++)
    {
        Cdd_Dma_HardReset(Cdd_Dma_ConfigPtr->hwinstcfg[hwunit_idx].baseaddress);
    }
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuRegionInit(uint32 MpuBaseAddress, Cdd_Dma_MpuRegionCfgType MpuRegionCfg)
{
    HWREG(MpuBaseAddress + RTDMA_O_MPUR_START((uint32)MpuRegionCfg.mpuregion)) = MpuRegionCfg.mpustartaddr;

    HWREG(MpuBaseAddress + RTDMA_O_MPUR_END((uint32)MpuRegionCfg.mpuregion)) = MpuRegionCfg.mpuendaddr;

    HWREGH(MpuBaseAddress + RTDMA_O_MPUR_CHMASK((uint32)MpuRegionCfg.mpuregion)) = MpuRegionCfg.chmask;

    HWREG(MpuBaseAddress + RTDMA_O_MPUR_ACCESS((uint32)MpuRegionCfg.mpuregion)) = (uint32)MpuRegionCfg.access;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetDataSize(uint32 Base, Cdd_Dma_ChannelDataSizeType DataSize, Cdd_Dma_ChannelWrDataSizeType WrDataSize)
{
    VAR(uint32, AUTOMATIC) config_value = 0U;

    config_value = (uint32)DataSize | (uint32)WrDataSize;

    /* Configure data size in MODE register */
    HWREG(Base + RTDMA_O_MODE) =
        (HWREG(Base + RTDMA_O_MODE) & ~(RTDMA_MODE_DATASIZE_M | RTDMA_MODE_WRT_DATASIZE_M)) | config_value;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetMode(uint32 Base, Cdd_Dma_OneshotModeEnableType OneShotMode, Cdd_Dma_ContinuousModeEnableType ContinuousMode)
{
    VAR(uint32, AUTOMATIC) mode_value = 0U;

    /* Configure One-shot mode */
    if (OneShotMode == CDD_DMA_ONESHOT_MODE_ENABLED)
    {
        mode_value |= RTDMA_MODE_ONESHOT; /* Enable one-shot mode */
    }

    /* Configure Continuous mode */
    if (ContinuousMode == CDD_DMA_CONTINUOUS_MODE_ENABLED)
    {
        mode_value |= RTDMA_MODE_CONTINUOUS; /* Enable continuous mode */
    }

    HWREG(Base + RTDMA_O_MODE) =
        (HWREG(Base + RTDMA_O_MODE) & ~(RTDMA_MODE_ONESHOT | RTDMA_MODE_CONTINUOUS)) | mode_value;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetInterruptMode(uint32 Base, Cdd_Dma_ChIntModeType IntMode)
{
    VAR(uint32, AUTOMATIC) mode_value = 0U;

    /* Configure interrupt mode (beginning or end of transfer) */
    if (IntMode == CDD_DMA_INT_END_OF_TRANSFER)
    {
        mode_value |= (uint32)RTDMA_MODE_CHINTMODE; /* Interrupt at end of transfer */
    }

    HWREG(Base + RTDMA_O_MODE) = (HWREG(Base + RTDMA_O_MODE) & ~((uint32)RTDMA_MODE_CHINTMODE)) | mode_value;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetInterruptEnable(uint32 Base, Cdd_Dma_ChIntEnableType IntEnable)
{
    VAR(uint32, AUTOMATIC) mode_reg = 0U;

    /* Configure interrupt enable */
    if (IntEnable == CDD_DMA_CHANNEL_INTERRUPT_ENABLED)
    {
        mode_reg |= RTDMA_MODE_CHINTE; /* Enable channel interrupt */
    }

    HWREG(Base + RTDMA_O_MODE) = (HWREG(Base + RTDMA_O_MODE) & ~(RTDMA_MODE_CHINTE)) | mode_reg;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetOverflowInterruptEnable(uint32 Base, Cdd_Dma_OvrflowIntEnableType OvrflowIntEnable)
{
    VAR(uint32, AUTOMATIC) mode_reg = 0U;

    /* Configure overflow interrupt enable */
    if (OvrflowIntEnable == CDD_DMA_OVERFLOW_INTERRUPT_ENABLED)
    {
        mode_reg |= RTDMA_MODE_OVRINTE; /* Enable overflow interrupt */
    }
    HWREG(Base + RTDMA_O_MODE) = (HWREG(Base + RTDMA_O_MODE) & ~(RTDMA_MODE_OVRINTE)) | mode_reg;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerEnable_Priv(uint32 Base, Cdd_Dma_PeriEvtTrigEnableType PeripheralEvntTrigEnable)
{
    if (PeripheralEvntTrigEnable == CDD_DMA_PERI_EVT_TRIG_ENABLED)
    {
        /* Set the peripheral interrupt trigger enable bit */
        HWREG(Base + RTDMA_O_MODE) |= RTDMA_MODE_PERINTE;
    }
    else
    {
        /* Clear the peripheral interrupt trigger enable bit */
        HWREG(Base + RTDMA_O_MODE) &= ~(RTDMA_MODE_PERINTE);
    }
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerSource_Priv(uint32 Base, Cdd_Dma_PeriEvtTriggerSrcType PeripheralEventTrigSrc)
{
    /* Configure peripheral event trigger source in MODE register */
    HWREG(Base + RTDMA_O_MODE) = (HWREG(Base + RTDMA_O_MODE) & ~RTDMA_MODE_PERINTSEL_M) |
                                 ((uint32)PeripheralEventTrigSrc & RTDMA_MODE_PERINTSEL_M);
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSize_Priv(uint32 Base, uint8 BurstSize, uint16 TransferSize)
{
    /* Set burst size (size - 1 as per hardware requirement) */
    HWREGB(Base + RTDMA_O_BURST_SIZE) = (uint8)(BurstSize - 1U);

    /* Set transfer size (size - 1 as per hardware requirement) */
    HWREGH(Base + RTDMA_O_TRANSFER_SIZE) = (uint16)(TransferSize - 1U);
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSrcStep_Priv(uint32 Base, sint16 SrcBurstStep, sint16 SrcTransferStep)
{
    /* Set source burst step */
    HWREGH(Base + RTDMA_O_SRC_BURST_STEP) = (uint16)SrcBurstStep;

    /* Set source transfer step */
    HWREGH(Base + RTDMA_O_SRC_TRANSFER_STEP) = (uint16)SrcTransferStep;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferDestStep_Priv(uint32 Base, sint16 DestBurstStep, sint16 DestTransferStep)
{
    /* Set destination burst step */
    HWREGH(Base + RTDMA_O_DST_BURST_STEP) = (uint16)DestBurstStep;

    /* Set destination transfer step */
    HWREGH(Base + RTDMA_O_DST_TRANSFER_STEP) = (uint16)DestTransferStep;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferSrcAddress_Priv(uint32 Base, uint32 SrcAddress)
{
    /* Set source address */
    HWREG(Base + RTDMA_O_SRC_ADDR_SHADOW) = SrcAddress;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetTransferDestAddress_Priv(uint32 Base, uint32 DestAddress)
{
    /* Set destination address */
    HWREG(Base + RTDMA_O_DST_ADDR_SHADOW) = DestAddress;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapSrc(uint32 Base, uint16 SrcWrapSize, sint16 SrcWrapStep, uint32 SrcBegAddress)
{
    /* Set source wrap size (size - 1 as per hardware requirement) */
    HWREGH(Base + RTDMA_O_SRC_WRAP_SIZE) = (uint16)(SrcWrapSize - 1U);

    /* Set source wrap step */
    HWREGH(Base + RTDMA_O_SRC_WRAP_STEP) = (uint16)SrcWrapStep;

    /* Set source beginning address */
    HWREG(Base + RTDMA_O_SRC_BEG_ADDR_SHADOW) = SrcBegAddress;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapDest(uint32 Base, uint16 DestWrapSize, sint16 DestWrapStep, uint32 DestBegAddress)
{
    /* Set destination wrap size (size - 1 as per hardware requirement) */
    HWREGH(Base + RTDMA_O_DST_WRAP_SIZE) = (uint16)(DestWrapSize - 1U);

    /* Set destination wrap step */
    HWREGH(Base + RTDMA_O_DST_WRAP_STEP) = (uint16)DestWrapStep;

    /* Set destination beginning address */
    HWREG(Base + RTDMA_O_DST_BEG_ADDR_SHADOW) = DestBegAddress;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_StartChannelTransfer_Priv(uint32 Base)
{
    /* Set the run bit to start the DMA channel */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_RUN;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_StopChannelTransfer_Priv(uint32 Base)
{
    /* Set the halt bit to stop the DMA channel */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_HALT;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_ForcePeripheralEventTrigger_Priv(uint32 Base)
{
    /* Set the peripheral interrupt trigger force bit */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_PERINTFRC;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_ClearPeripheralEventTrigger_Priv(uint32 Base)
{
    /* Write a one to the clear bit to clear the peripheral trigger flag */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_PERINTCLR;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_TriggerSoftReset_Priv(uint32 Base)
{
    /* Set the soft reset bit. One NOP is required after SOFTRESET */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_SOFTRESET;
    MCAL_LIB_NOP;
}
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigLockConfiguration(uint32 Base)
{
    /* Lock the DMA channel configuration */
    HWREG(Base + RTDMA_O_CHCFG_LOCK) |= RTDMA_CHCFG_LOCK_LOCK;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigUnlockConfiguration(uint32 Base)
{
    /* Unlock the DMA channel configuration */
    HWREG(Base + RTDMA_O_CHCFG_LOCK) &= ~(RTDMA_CHCFG_LOCK_LOCK);
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_ChConfigLockConfigurationAll(void)
{
    VAR(uint8, AUTOMATIC) channel_idx;

    /* Lock configuration for all configured channels */
    for (channel_idx = 0U; channel_idx < CDD_DMA_CHANNEL_COUNT; channel_idx++)
    {
        Cdd_Dma_ChConfigLockConfiguration(Cdd_Dma_ConfigPtr->chcfg[channel_idx].baseaddress);
    }
}
#endif

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_IsPeripheralEventTriggerEnabled(uint32 Base)
{
    VAR(boolean, AUTOMATIC) enabled = FALSE;

    /* Check if peripheral event trigger enable bit is set in MODE register */
    if ((HWREG(Base + RTDMA_O_MODE) & RTDMA_MODE_PERINTE) != 0U)
    {
        enabled = TRUE;
    }

    return enabled;
}

FUNC(uint8, CDD_DMA_CODE) Cdd_Dma_GetHwInstanceIndex(VAR(Cdd_Dma_InstanceType, AUTOMATIC) instance)
{
    VAR(uint8, AUTOMATIC) hwunit_idx;
    VAR(uint8, AUTOMATIC) result = 0U;

    /* Find the hardware instance configuration by matching the instance field */
    for (hwunit_idx = 0U; hwunit_idx < CDD_DMA_HW_INSTANCE_COUNT; hwunit_idx++)
    {
        if (Cdd_Dma_ConfigPtr->hwinstcfg[hwunit_idx].instance == instance)
        {
            result = hwunit_idx;
            break;
        }
    }

    return result;
}

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_IsHwInstanceCommittedForChannel(VAR(uint8, AUTOMATIC) ChannelId)
{
    VAR(Cdd_Dma_InstanceType, AUTOMATIC) instance;
    VAR(uint8, AUTOMATIC) hwunit_idx;
    VAR(boolean, AUTOMATIC) is_committed = FALSE;

    /* Get instance from channel configuration */
    instance = Cdd_Dma_ConfigPtr->chcfg[ChannelId].instance;

    /* Find the hardware instance index */
    hwunit_idx = Cdd_Dma_GetHwInstanceIndex(instance);

    /* Check if Dma hardware instance configurations are committed */
    is_committed = Cdd_Dma_CheckConfigurationCommit(Cdd_Dma_ConfigPtr->hwinstcfg[hwunit_idx].baseaddress);

    return is_committed;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_UpdateChannelPriority(VAR(uint8, AUTOMATIC) ChannelId, Cdd_Dma_ChannelPriority Priority)
{
    VAR(Cdd_Dma_InstanceType, AUTOMATIC) instance;
    VAR(Cdd_Dma_ChannelType, AUTOMATIC) channel;
    VAR(uint32, AUTOMATIC) base_address;
    VAR(uint8, AUTOMATIC) hwunit_idx;
    VAR(uint32, AUTOMATIC) swpri_reg_value;
    VAR(uint8, AUTOMATIC) priority_shift;
    VAR(uint32, AUTOMATIC) priority_mask;

    /* Get instance and channel from configuration */
    instance = Cdd_Dma_ConfigPtr->chcfg[ChannelId].instance;
    channel  = Cdd_Dma_ConfigPtr->chcfg[ChannelId].channel;

    /* Find the hardware instance index */
    hwunit_idx = Cdd_Dma_GetHwInstanceIndex(instance);

    /* Get the DMA instance base address */
    base_address = Cdd_Dma_ConfigPtr->hwinstcfg[hwunit_idx].baseaddress;

    /* Update priority based on channel number */
    if (channel <= CDD_DMA_CH8)
    {
        /* Channels 1-8: Update SWPRI1 register */
        /* Each channel uses 4 bits, CDD_DMA_CH1 (0) starts at bit 0 */
        priority_shift = ((uint8)channel) * 4U;
        priority_mask  = (uint32)0x0FU << priority_shift;

        /* Read current SWPRI1 value */
        swpri_reg_value = HWREG(base_address + RTDMA_O_SWPRI1);

        /* Clear old priority bits and set new priority */
        swpri_reg_value = (swpri_reg_value & ~priority_mask) | ((uint32)Priority << priority_shift);

        /* Write back to SWPRI1 register */
        Cdd_Dma_SetPriority1(base_address, swpri_reg_value);
    }
    else
    {
        /* Channels 9-10: Update SWPRI2 register */
        /* CDD_DMA_CH9 (8) starts at bit 0, CDD_DMA_CH10 (9) at bit 4 */
        priority_shift = ((uint8)channel - 8U) * 4U;
        priority_mask  = (uint32)0x0FU << priority_shift;

        /* Read current SWPRI2 value */
        swpri_reg_value = HWREG(base_address + RTDMA_O_SWPRI2);

        /* Clear old priority bits and set new priority */
        swpri_reg_value = (swpri_reg_value & ~priority_mask) | ((uint32)Priority << priority_shift);

        /* Write back to SWPRI2 register */
        Cdd_Dma_SetPriority2(base_address, swpri_reg_value);
    }
}

FUNC(Cdd_Dma_PeriEvtTrigStatusType, CDD_DMA_CODE) Cdd_Dma_GetPeripheralEventTriggerFlag(uint32 Base)
{
    VAR(Cdd_Dma_PeriEvtTrigStatusType, AUTOMATIC) status;

    /* Read the peripheral event trigger flag from CONTROL register */
    if ((HWREG(Base + RTDMA_O_CONTROL) & RTDMA_CONTROL_PERINTFLG) != 0U)
    {
        status = CDD_DMA_PENDING_EVT_TRIG;
    }
    else
    {
        status = CDD_DMA_WAITING_FOR_EVT_TRIG;
    }

    return status;
}

FUNC(Cdd_Dma_TransferStatusType, CDD_DMA_CODE) Cdd_Dma_GetTransferStatusFlag(uint32 Base)
{
    VAR(Cdd_Dma_TransferStatusType, AUTOMATIC) status;

    /* Read the transfer status flag from CONTROL register */
    if ((HWREG(Base + RTDMA_O_CONTROL) & RTDMA_CONTROL_TRANSFERSTS) != 0U)
    {
        status = CDD_DMA_TRANSFER_ACTIVITY_ONGOING;
    }
    else
    {
        status = CDD_DMA_NO_TRANSFER_ACTIVITY_ONGOING;
    }

    return status;
}

FUNC(Cdd_Dma_BurstStatusType, CDD_DMA_CODE) Cdd_Dma_GetBurstStatusFlag(uint32 Base)
{
    VAR(Cdd_Dma_BurstStatusType, AUTOMATIC) status;

    /* Read the burst status flag from CONTROL register */
    if ((HWREG(Base + RTDMA_O_CONTROL) & RTDMA_CONTROL_BURSTSTS) != 0U)
    {
        status = CDD_DMA_BURST_ACTIVITY_ONGOING;
    }
    else
    {
        status = CDD_DMA_NO_BURST_ACTIVITY_ONGOING;
    }

    return status;
}

FUNC(Cdd_Dma_RunStatusType, CDD_DMA_CODE) Cdd_Dma_GetRunStatusFlag(uint32 Base)
{
    VAR(Cdd_Dma_RunStatusType, AUTOMATIC) status;

    /* Read the run status flag from CONTROL register */
    if ((HWREG(Base + RTDMA_O_CONTROL) & RTDMA_CONTROL_RUNSTS) != 0U)
    {
        status = CDD_DMA_CHANNEL_RUNNING;
    }
    else
    {
        status = CDD_DMA_CHANNEL_NOT_RUNNING;
    }

    return status;
}

FUNC(Cdd_Dma_OverflowStatusType, CDD_DMA_CODE) Cdd_Dma_GetOverflowStatusFlag(uint32 Base)
{
    VAR(Cdd_Dma_OverflowStatusType, AUTOMATIC) status;

    /* Read the overflow flag from CONTROL register */
    if ((HWREG(Base + RTDMA_O_CONTROL) & RTDMA_CONTROL_OVRFLG) != 0U)
    {
        status = CDD_DMA_OVERFLOW_DETECTED;
    }
    else
    {
        status = CDD_DMA_OVERFLOW_NOT_DETECTED;
    }

    return status;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_ClearErrorFlag_Priv(uint32 Base)
{
    /* Set the error clear bit to clear error conditions */
    HWREG(Base + RTDMA_O_CONTROL) |= RTDMA_CONTROL_ERRCLR;
}

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckChannelConfigCommit(uint32 Base)
{
    VAR(boolean, AUTOMATIC) commit_status = FALSE;

    /* Read CHCFG_COMMIT register and check if bit 0 is set */
    if ((HWREG(Base + RTDMA_O_CHCFG_COMMIT) & RTDMA_CHCFG_COMMIT_COMMIT) != 0U)
    {
        commit_status = TRUE;
    }
    return commit_status;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetChannelCommit_Priv(VAR(uint8, AUTOMATIC) ChannelId)
{
    /* Set the channel configuration commit bit for permanent lock */
    HWREG(Cdd_Dma_ConfigPtr->chcfg[ChannelId].baseaddress + RTDMA_O_CHCFG_COMMIT) = RTDMA_CHCFG_COMMIT_COMMIT;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetDmaCfgCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId)
{
    /* Set the DMA configuration commit bit for permanent lock */
    HWREG(Cdd_Dma_ConfigPtr->hwinstcfg[HwInstanceId].baseaddress + RTDMA_O_DMACFG_COMMIT) = RTDMA_DMACFG_COMMIT_COMMIT;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_SetMpuRegionCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId, VAR(uint8, AUTOMATIC) MpuRegionIdx)
{
    /* Set MPU region configuration commit bit for permanent lock for the specific region */
    HWREG(Cdd_Dma_ConfigPtr->hwinstcfg[HwInstanceId].mpubaseaddress +
          RTDMA_O_MPUR_COMMIT((uint32)Cdd_Dma_ConfigPtr->hwinstcfg[HwInstanceId].mpucfg[MpuRegionIdx].mpuregion)) |=
        RTDMA_MPUR_COMMIT_COMMIT;
}

FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetMpuCfgCommit_Priv(VAR(uint8, AUTOMATIC) HwInstanceId)
{
    /* Set MPU configuration commit bit for permanent lock */
    HWREG(Cdd_Dma_ConfigPtr->hwinstcfg[HwInstanceId].mpubaseaddress + RTDMA_O_MPUCFG_COMMIT) |=
        RTDMA_MPUCFG_COMMIT_COMMIT;
}

FUNC(void, CDD_DMA_CODE)
Cdd_Dma_ProcessIsr(Cdd_Dma_InstanceType InstanceId, Cdd_Dma_ChannelType ChannelId)
{
    uint8                      ch_idx;
    Cdd_Dma_OverflowStatusType overflow_status;

    ch_idx = Cdd_Dma_DrvObj.channelindex[InstanceId][ChannelId];

    /* Check if this channel is configured (not 0xFF) */
    if (ch_idx < CDD_DMA_CHANNEL_COUNT)
    {
        /* Check if overflow flag is set */
        overflow_status = Cdd_Dma_GetOverflowStatusFlag(Cdd_Dma_ConfigPtr->chcfg[ch_idx].baseaddress);

        if (CDD_DMA_OVERFLOW_DETECTED == overflow_status)
        {
            /* Call the overflow interrupt notification callback if configured */
            if (NULL_PTR != Cdd_Dma_ConfigPtr->chcfg[ch_idx].overflowintnotification)
            {
                Cdd_Dma_ConfigPtr->chcfg[ch_idx].overflowintnotification(ch_idx);
            }
        }
        else
        {
            /* Call the channel interrupt notification callback if configured */
            if (NULL_PTR != Cdd_Dma_ConfigPtr->chcfg[ch_idx].chintnotification)
            {
                Cdd_Dma_ConfigPtr->chcfg[ch_idx].chintnotification(ch_idx);
            }
        }
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static FUNC(void, CDD_DMA_CODE)
    Cdd_Dma_InitHwInstanceConfig(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg)
{
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
    Cdd_Dma_DmaCfgUnlockConfiguration(hwunitcfg->baseaddress);
#endif

    Cdd_Dma_HardReset(hwunitcfg->baseaddress);
    /* Configure the priority scheme*/
    Cdd_Dma_SetPrioritySelection(hwunitcfg->baseaddress, hwunitcfg->priorityscheme);

    Cdd_Dma_SetEmulationMode(hwunitcfg->baseaddress, hwunitcfg->emulationmode);

    Cdd_Dma_SetPriority1(hwunitcfg->baseaddress, hwunitcfg->swpri1);

    Cdd_Dma_SetPriority2(hwunitcfg->baseaddress, hwunitcfg->swpri2);

#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
    Cdd_Dma_DmaCfgLockConfiguration(hwunitcfg->baseaddress);
#endif
}

static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_InitMpuRegions(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg)
{
    VAR(uint8, AUTOMATIC) mpu_idx;
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    for (mpu_idx = 0U; mpu_idx < hwunitcfg->mpuregioncount; mpu_idx++)
    {
        /* Check if MPUR_COMMIT is already set for this MPU region */
        if (Cdd_Dma_CheckMpuRegionCommit(hwunitcfg->mpubaseaddress, hwunitcfg->mpucfg[mpu_idx].mpuregion) == FALSE)
        {
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
            Cdd_Dma_MpuRegionUnlockConfiguration(hwunitcfg->mpubaseaddress, hwunitcfg->mpucfg[mpu_idx].mpuregion);
#endif
            Cdd_Dma_MpuRegionInit(hwunitcfg->mpubaseaddress, hwunitcfg->mpucfg[mpu_idx]);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
            Cdd_Dma_MpuRegionLockConfiguration(hwunitcfg->mpubaseaddress, hwunitcfg->mpucfg[mpu_idx].mpuregion);
#endif
        }
        else
        {
            ret_val = E_NOT_OK;
            break;
        }
    }

    return ret_val;
}

static FUNC(Std_ReturnType, CDD_DMA_CODE)
    Cdd_Dma_ConfigureMpu(P2CONST(Cdd_Dma_HwInstanceCfgType, AUTOMATIC, CDD_DMA_CONST) hwunitcfg)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    if (hwunitcfg->mpuenable == TRUE)
    {
        /* Initialize MPU regions */
        if (Cdd_Dma_InitMpuRegions(hwunitcfg) == E_OK)
        {
            /* Check if MPUCFG_COMMIT is already set */
            if (Cdd_Dma_CheckMpuConfigCommit(hwunitcfg->mpubaseaddress) == FALSE)
            {
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
                Cdd_Dma_MpuEnableUnlockConfiguration(hwunitcfg->mpubaseaddress);
#endif
                Cdd_Dma_MpuEnable(hwunitcfg->mpubaseaddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
                Cdd_Dma_MpuEnableLockConfiguration(hwunitcfg->mpubaseaddress);
#endif
                ret_val = E_OK;
            }
        }
    }
    else
    {
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        Cdd_Dma_MpuEnableUnlockConfiguration(hwunitcfg->mpubaseaddress);
#endif
        Cdd_Dma_MpuDisable(hwunitcfg->mpubaseaddress);
#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
        Cdd_Dma_MpuEnableLockConfiguration(hwunitcfg->mpubaseaddress);
#endif
        ret_val = E_OK;
    }

    return ret_val;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPrioritySelection(uint32 Base, Cdd_Dma_PriorityType PrioritySelection)
{
    if (PrioritySelection == CDD_DMA_PRIORITY_SOFTWARE_CONFIG)
    {
        /* Set bit 16 for software configurable priority */
        HWREG(Base + RTDMA_O_DMACTRL) |= RTDMA_DMACTRL_PRIORITYSEL;
    }
    else
    {
        /* Clear bit 16 for round-robin priority */
        HWREG(Base + RTDMA_O_DMACTRL) &= ~(RTDMA_DMACTRL_PRIORITYSEL);
    }
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetEmulationMode(uint32 Base, Cdd_Dma_EmulationModeType EmulationMode)
{
    if (EmulationMode == CDD_DMA_EMULATION_FREE_RUN)
    {
        /* Set bit 15 for emulation free run */
        HWREG(Base + RTDMA_O_DEBUGCTRL) |= RTDMA_DEBUGCTRL_FREE;
    }
    else
    {
        /* Clear bit 15 for emulation stop */
        HWREG(Base + RTDMA_O_DEBUGCTRL) &= ~(RTDMA_DEBUGCTRL_FREE);
    }
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPriority1(uint32 Base, uint32 SwPriority)
{
    HWREG(Base + RTDMA_O_SWPRI1) = SwPriority;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_SetPriority2(uint32 Base, uint32 SwPriority)
{
    HWREG(Base + RTDMA_O_SWPRI2) = SwPriority;
}

#if (STD_ON == CDD_DMA_LOCK_CONFIGURATION)
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgLockConfiguration(uint32 Base)
{
    HWREG(Base + RTDMA_O_DMACFG_LOCK) |= RTDMA_DMACFG_LOCK_LOCK;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_DmaCfgUnlockConfiguration(uint32 Base)
{
    HWREG(Base + RTDMA_O_DMACFG_LOCK) &= ~(RTDMA_DMACFG_LOCK_LOCK);
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuRegionLockConfiguration(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion)
{
    HWREG(Base + RTDMA_O_MPUR_LOCK((uint32)MpuRegion)) |= RTDMA_MPUR_LOCK_LOCK;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuRegionUnlockConfiguration(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion)
{
    HWREG(Base + RTDMA_O_MPUR_LOCK((uint32)MpuRegion)) &= ~(RTDMA_MPUR_LOCK_LOCK);
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnableLockConfiguration(uint32 Base)
{
    HWREG(Base + RTDMA_O_MPUCFG_LOCK) |= RTDMA_MPUCFG_LOCK_LOCK;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnableUnlockConfiguration(uint32 Base)
{
    HWREG(Base + RTDMA_O_MPUCFG_LOCK) &= ~(RTDMA_MPUCFG_LOCK_LOCK);
}
#endif
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuEnable(uint32 Base)
{
    HWREG(Base + RTDMA_O_MPUCTRL) |= RTDMA_MPUCTRL_MPUEN;
}

LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_MpuDisable(uint32 Base)
{
    HWREG(Base + RTDMA_O_MPUCTRL) &= ~RTDMA_MPUCTRL_MPUEN;
}
LOCAL_INLINE FUNC(void, CDD_DMA_CODE) Cdd_Dma_HardReset(uint32 Base)
{
    HWREG(Base + RTDMA_O_DMACTRL) |= RTDMA_DMACTRL_HARDRESET;
    MCAL_LIB_NOP;
}

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckConfigurationCommit(uint32 Base)
{
    VAR(boolean, AUTOMATIC) commit_status = FALSE;

    /* Read DMACFG_COMMIT register and check if bit 0 is set */
    if ((HWREG(Base + RTDMA_O_DMACFG_COMMIT) & RTDMA_DMACFG_COMMIT_COMMIT) != 0U)
    {
        commit_status = TRUE;
    }
    return commit_status;
}

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckMpuConfigCommit(uint32 Base)
{
    VAR(boolean, AUTOMATIC) commit_status = FALSE;

    /* Read MPUCFG_COMMIT register and check if bit 0 is set */
    if ((HWREG(Base + RTDMA_O_MPUCFG_COMMIT) & RTDMA_MPUCFG_COMMIT_COMMIT) != 0U)
    {
        commit_status = TRUE;
    }
    return commit_status;
}

FUNC(boolean, CDD_DMA_CODE) Cdd_Dma_CheckMpuRegionCommit(uint32 Base, Cdd_Dma_MpuRegionType MpuRegion)
{
    VAR(boolean, AUTOMATIC) commit_status = FALSE;

    /* Read MPUR_COMMIT register for the specified MPU region and check if bit 0 is set */
    if ((HWREG(Base + RTDMA_O_MPUR_COMMIT((uint32)MpuRegion)) & RTDMA_MPUR_COMMIT_COMMIT) != 0U)
    {
        commit_status = TRUE;
    }
    return commit_status;
}

#define CDD_DMA_STOP_SEC_CODE
#include "Cdd_Dma_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Priv.c
 *********************************************************************************************************************/
