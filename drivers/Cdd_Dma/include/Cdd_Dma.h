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

#ifndef CDD_DMA_H
#define CDD_DMA_H

/**
 * \defgroup CDD_DMA Cdd_Dma API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Cdd_Dma_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * CDD DMA Software version
 *********************************************************************************************************************/

/* Defines for CDD_DMA Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_DMA_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_DMA_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_DMA_SW_PATCH_VERSION (0U)

/*********************************************************************************************************************
 * AUTOSAR release version for CDD DMA
 *********************************************************************************************************************/

/*  Defines for CDD_DMA Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_DMA Driver*/
#define CDD_DMA_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_DMA Driver*/
#define CDD_DMA_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_DMA Driver*/
#define CDD_DMA_AR_RELEASE_REVISION_VERSION (1U)

/*********************************************************************************************************************
 * CDD DMA Vendor specific information
 *********************************************************************************************************************/

/* CDD DMA Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_DMA_VENDOR_ID ((uint16)44U)
/** \brief CDD DMA Driver Module ID */
#define CDD_DMA_MODULE_ID ((uint16)255U)
/** \brief CDD DMA Instance ID */
#define CDD_DMA_INSTANCE_ID ((uint8)0U)

/*********************************************************************************************************************
 * Error codes returned by CDD DMA driver
 *********************************************************************************************************************/

/** \brief API service used without module initialization */
#define CDD_DMA_E_UNINIT ((uint8)0x0AU)

/** \brief API called for reinitialization of already initialized DMA driver */
#define CDD_DMA_E_ALREADY_INITIALIZED ((uint8)0x0BU)

/** \brief Initialization API failed */
#define CDD_DMA_E_INIT_FAILED ((uint8)0x0CU)

/** \brief API service called with invalid parameter pointer */
#define CDD_DMA_E_PARAM_POINTER ((uint8)0x0DU)

/** \brief API service called with invalid parameter pointer */
#define CDD_DMA_E_PARAM_VALUE ((uint8)0x0EU)

/** \brief API service called during ongoing process */
#define CDD_DMA_E_BUSY ((uint8)0x0FU)

/** \brief API service called to force or clear peripheral event trigger when peripheral event trigger is disabled */
#define CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_DISABLED ((uint8)0x10U)

/** \brief API service called to enable peripheral event trigger when peripheral event trigger is already enabled */
#define CDD_DMA_E_PERIPHERAL_EVENT_TRIGGER_ENABLED ((uint8)0x11U)

/** \brief API service called to start a channel when the channel is already running */
#define CDD_DMA_E_ALREADY_RUNNING ((uint8)0x12U)

/** \brief API service called to halt a channel when the channel already halted */
#define CDD_DMA_E_ALREADY_HALTED ((uint8)0x13U)

/** \brief API service called to modify DMA configurable properties when DMA configurable properties are committed */
#define CDD_DMA_E_DMACFG_COMMITTED ((uint8)0x14U)

/** \brief API service called to modify DMA channel properties when DMA channel properties are committed */
#define CDD_DMA_E_CHCFG_COMMITTED ((uint8)0x15U)

/** \brief API service called to modify DMA MPU region properties when DMA MPU region properties are committed */
#define CDD_DMA_E_MPUR_COMMITTED ((uint8)0x16U)

/** \brief API service called to enable or disable MPU when DMA MPU configuration are committed */
#define CDD_DMA_E_MPUCFG_COMMITTED ((uint8)0x17U)

/** \brief API service called to clear error flag when no overflow is detected */
#define CDD_DMA_E_NO_OVERFLOW ((uint8)0x18U)

/** \brief API service called to clear peripheral event trigger when no event trigger exists */
#define CDD_DMA_E_NO_TRIGGER ((uint8)0x19U)

/*********************************************************************************************************************
 * Service Ids of CDD DMA APIs to report DET error
 *********************************************************************************************************************/
/** \brief Cdd_Dma_GetVersionInfo() API Service ID */
#define CDD_DMA_SID_GET_VERSION_INFO ((uint8)0x00U)
/** \brief Cdd_Dma_Init() API Service ID */
#define CDD_DMA_SID_INIT ((uint8)0x01U)
/** \brief Cdd_Dma_DeInit() API Service ID */
#define CDD_DMA_SID_DEINIT ((uint8)0x02U)
/** \brief Cdd_Dma_SetChannelProperties() API Service ID */
#define CDD_DMA_SID_SET_CHANNEL_PROPERTIES ((uint8)0x03U)
/** \brief Cdd_Dma_SetTransferProperties() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_PROPERTIES ((uint8)0x04U)
/** \brief Cdd_Dma_SetTransferSize() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_SIZE ((uint8)0x05U)
/** \brief Cdd_Dma_SetTransferSrcProperties() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_SRC_PROPERTIES ((uint8)0x06U)
/** \brief Cdd_Dma_SetTransferDestProperties() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_DEST_PROPERTIES ((uint8)0x07U)
/** \brief Cdd_Dma_SetTransferSrcAddress() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_SRC_ADDRESS ((uint8)0x08U)
/** \brief Cdd_Dma_SetTransferDestAddress() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_DEST_ADDRESS ((uint8)0x09U)
/** \brief Cdd_Dma_SetTransferWrapSrcProperties() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_WRAP_SRC_PROPERTIES ((uint8)0x0AU)
/** \brief Cdd_Dma_SetTransferWrapDestProperties() API Service ID */
#define CDD_DMA_SID_SET_TRANSFER_WRAP_DEST_PROPERTIES ((uint8)0x0BU)
/** \brief Cdd_Dma_EnablePeripheralEventTrigger() API Service ID */
#define CDD_DMA_SID_ENABLE_PERIPHERAL_EVENT_TRIGGER ((uint8)0x0CU)
/** \brief Cdd_Dma_DisablePeripheralEventTrigger() API Service ID */
#define CDD_DMA_SID_DISABLE_PERIPHERAL_EVENT_TRIGGER ((uint8)0x0DU)
/** \brief Cdd_Dma_SetPeripheralEventTriggerSource() API Service ID */
#define CDD_DMA_SID_SET_PERIPHERAL_EVENT_TRIGGER_SOURCE ((uint8)0x0EU)
/** \brief Cdd_Dma_StartChannelTransfer() API Service ID */
#define CDD_DMA_SID_START_CHANNEL_TRANSFER ((uint8)0x0FU)
/** \brief Cdd_Dma_StopChannelTransfer() API Service ID */
#define CDD_DMA_SID_STOP_CHANNEL_TRANSFER ((uint8)0x10U)
/** \brief Cdd_Dma_ForcePeripheralEventTrigger() API Service ID */
#define CDD_DMA_SID_FORCE_PERIPHERAL_EVENT_TRIGGER ((uint8)0x11U)
/** \brief Cdd_Dma_ClearPeripheralEventTrigger() API Service ID */
#define CDD_DMA_SID_CLEAR_PERIPHERAL_EVENT_TRIGGER ((uint8)0x12U)
/** \brief Cdd_Dma_TriggerSoftReset() API Service ID */
#define CDD_DMA_SID_TRIGGER_SOFT_RESET ((uint8)0x13U)
/** \brief Cdd_Dma_SetChannelPriority() API Service ID */
#define CDD_DMA_SID_SET_CHANNEL_PRIORITY ((uint8)0x14U)
/** \brief Cdd_Dma_GetChannelStatus() API Service ID */
#define CDD_DMA_SID_GET_CHANNEL_STATUS ((uint8)0x15U)
/** \brief Cdd_Dma_ClearErrorFlag() API Service ID */
#define CDD_DMA_SID_CLEAR_ERROR_FLAG ((uint8)0x16U)
/** \brief Cdd_Dma_SetChannelCommit() API Service ID */
#define CDD_DMA_SID_SET_CHANNEL_COMMIT ((uint8)0x17U)
/** \brief Cdd_Dma_SetDmaCfgCommit() API Service ID */
#define CDD_DMA_SID_SET_DMACFG_COMMIT ((uint8)0x18U)
/** \brief Cdd_Dma_SetMpuRegionCommit() API Service ID */
#define CDD_DMA_SID_SET_MPUR_COMMIT ((uint8)0x19U)
/** \brief Cdd_Dma_SetMpuCfgCommit() API Service ID */
#define CDD_DMA_SID_SET_MPUCFG_COMMIT ((uint8)0x1AU)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/* None */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief  Channel notification callback function pointer. */
typedef void (*Cdd_Dma_NotifyType)(uint8 Channel_Index);

/** \brief Emulation control type */
typedef enum
{
    CDD_DMA_EMULATION_STOP,    /*!< \brief  The DMA completes the current read-write operation, then halts */
    CDD_DMA_EMULATION_FREE_RUN /*!< \brief  The DMA continues running during an emulation halt */
} Cdd_Dma_EmulationModeType;

/** \brief Channel priority selection type */
typedef enum
{
    CDD_DMA_PRIORITY_ROUND_ROBIN,    /*!< \brief  The round-robin priority scheme */
    CDD_DMA_PRIORITY_SOFTWARE_CONFIG /*!< \brief  Software configurable priority for channels */
} Cdd_Dma_PriorityType;

/** \brief DMA instance type */
typedef enum
{
    CDD_DMA1 = 0,
    CDD_DMA2 = 1,
} Cdd_Dma_InstanceType;

/** \brief DMA Channel type */
typedef enum
{
    CDD_DMA_CH1  = 0,
    CDD_DMA_CH2  = 1,
    CDD_DMA_CH3  = 2,
    CDD_DMA_CH4  = 3,
    CDD_DMA_CH5  = 4,
    CDD_DMA_CH6  = 5,
    CDD_DMA_CH7  = 6,
    CDD_DMA_CH8  = 7,
    CDD_DMA_CH9  = 8,
    CDD_DMA_CH10 = 9,
} Cdd_Dma_ChannelType;

/** \brief DMA MPU Region type */
typedef enum
{
    CDD_DMA_MPUR1  = 0,  /*!< \brief  RTDMA MPU Region 1 */
    CDD_DMA_MPUR2  = 1,  /*!< \brief  RTDMA MPU Region 2 */
    CDD_DMA_MPUR3  = 2,  /*!< \brief  RTDMA MPU Region 3 */
    CDD_DMA_MPUR4  = 3,  /*!< \brief  RTDMA MPU Region 4 */
    CDD_DMA_MPUR5  = 4,  /*!< \brief  RTDMA MPU Region 5 */
    CDD_DMA_MPUR6  = 5,  /*!< \brief  RTDMA MPU Region 6 */
    CDD_DMA_MPUR7  = 6,  /*!< \brief  RTDMA MPU Region 7 */
    CDD_DMA_MPUR8  = 7,  /*!< \brief  RTDMA MPU Region 8 */
    CDD_DMA_MPUR9  = 8,  /*!< \brief  RTDMA MPU Region 9 */
    CDD_DMA_MPUR10 = 9,  /*!< \brief  RTDMA MPU Region 10 */
    CDD_DMA_MPUR11 = 10, /*!< \brief  RTDMA MPU Region 11 */
    CDD_DMA_MPUR12 = 11, /*!< \brief  RTDMA MPU Region 12 */
    CDD_DMA_MPUR13 = 12, /*!< \brief  RTDMA MPU Region 13 */
    CDD_DMA_MPUR14 = 13, /*!< \brief  RTDMA MPU Region 14 */
    CDD_DMA_MPUR15 = 14, /*!< \brief  RTDMA MPU Region 15 */
    CDD_DMA_MPUR16 = 15  /*!< \brief  RTDMA MPU Region 16 */
} Cdd_Dma_MpuRegionType;

/** \brief Write data size mode bit type */
typedef enum
{
    CDD_DMA_CHANNEL_WR_DATASIZE_MODE_8 =
        0x0U, /*!< \brief  DMA channel transfers 8 bits of data on write port per read/write operation */
    CDD_DMA_CHANNEL_WR_DATASIZE_MODE_16 =
        0x100000U, /*!< \brief  DMA channel transfers 16 bits of data on write port per read/write operation */
    CDD_DMA_CHANNEL_WR_DATASIZE_MODE_32 =
        0x200000U, /*!< \brief  DMA channel transfers 32 bits of data on write port per read/write operation */
    CDD_DMA_CHANNEL_WR_DATASIZE_MODE_64 =
        0x300000U, /*!< \brief  DMA channel transfers 64 bits of data on write port per read/write operation */

} Cdd_Dma_ChannelWrDataSizeType;

/** \brief Data size mode bit type */
typedef enum
{
    CDD_DMA_CHANNEL_DATASIZE_MODE_8 =
        0x0U, /*!< \brief  DMA channel transfers 8 bits of data per read/write operation */
    CDD_DMA_CHANNEL_DATASIZE_MODE_16 =
        0x20000U, /*!< \brief  DMA channel transfers 16 bits of data per read/write operation */
    CDD_DMA_CHANNEL_DATASIZE_MODE_32 =
        0x40000U, /*!< \brief  DMA channel transfers 32 bits of data per read/write operation */
    CDD_DMA_CHANNEL_DATASIZE_MODE_64 =
        0x60000U, /*!< \brief  DMA channel transfers 64 bits of data per read/write operation */

} Cdd_Dma_ChannelDataSizeType;

/** \brief Continuous mode type */
typedef enum
{
    CDD_DMA_CONTINUOUS_MODE_DISABLED, /*!< \brief  Continuous mode disabled */
    CDD_DMA_CONTINUOUS_MODE_ENABLED   /*!< \brief  Continuous mode enabled */
} Cdd_Dma_ContinuousModeEnableType;

/** \brief Oneshot mode type */
typedef enum
{
    CDD_DMA_ONESHOT_MODE_DISABLED, /*!< \brief  Oneshot mode disabled */
    CDD_DMA_ONESHOT_MODE_ENABLED   /*!< \brief  Oneshot mode enabled */
} Cdd_Dma_OneshotModeEnableType;

/** \brief Channel interrupt generation enable type */
typedef enum
{
    CDD_DMA_CHANNEL_INTERRUPT_DISABLED, /*!< \brief  Channel interrupt generation mode disabled */
    CDD_DMA_CHANNEL_INTERRUPT_ENABLED   /*!< \brief  Channel interrupt generation mode enabled */
} Cdd_Dma_ChIntEnableType;

/** \brief Channel interrupt generation mode type */
typedef enum
{
    CDD_DMA_INT_BEG_OF_TRANSFER, /*!< \brief  Generate interrupt at beginning of new transfer */
    CDD_DMA_INT_END_OF_TRANSFER  /*!< \brief  Generate interrupt at end of transfer */
} Cdd_Dma_ChIntModeType;

/** \brief Overflow interrupt type */
typedef enum
{
    CDD_DMA_OVERFLOW_INTERRUPT_DISABLED, /*!< \brief  Overflow interrupt disabled */
    CDD_DMA_OVERFLOW_INTERRUPT_ENABLED   /*!< \brief  Overflow interrupt enabled */
} Cdd_Dma_OvrflowIntEnableType;

/** \brief  Peripheral event trigger enable type */
typedef enum
{
    CDD_DMA_PERI_EVT_TRIG_DISABLED, /*!< \brief  Peripheral event trigger disabled */
    CDD_DMA_PERI_EVT_TRIG_ENABLED   /*!< \brief  Peripheral event trigger enabled */
} Cdd_Dma_PeriEvtTrigEnableType;

/** \brief Overflow status type */
typedef enum
{
    CDD_DMA_OVERFLOW_NOT_DETECTED, /*!< \brief  No overflow detected */
    CDD_DMA_OVERFLOW_DETECTED /*!< \brief  Overflow detected i.e. peripheral event trigger was received while PERINTFLG
                                 was already set */
} Cdd_Dma_OverflowStatusType;

/** \brief Run status type */
typedef enum
{
    CDD_DMA_CHANNEL_NOT_RUNNING, /*!< \brief  DMA channel is ready to respond to peripheral event triggers - no ongoing
                                    transfer */
    CDD_DMA_CHANNEL_RUNNING      /*!< \brief  DMA channel is busy */
} Cdd_Dma_RunStatusType;

/** \brief Burst status type */
typedef enum
{
    CDD_DMA_NO_BURST_ACTIVITY_ONGOING, /*!< \brief  Burst is completed i.e. BURST_COUNT has reached zero*/
    CDD_DMA_BURST_ACTIVITY_ONGOING     /*!< \brief  Burst is in progress */
} Cdd_Dma_BurstStatusType;

/** \brief Transfer status type */
typedef enum
{
    CDD_DMA_NO_TRANSFER_ACTIVITY_ONGOING, /*!< \brief  Transfer is completed i.e. TRANSFER_COUNT has reached zero*/
    CDD_DMA_TRANSFER_ACTIVITY_ONGOING     /*!< \brief  Transfer is in progress */
} Cdd_Dma_TransferStatusType;

/** \brief Peripheral event trigger status type */
typedef enum
{
    CDD_DMA_WAITING_FOR_EVT_TRIG, /*!< \brief  Wating for peripheral event trigger*/
    CDD_DMA_PENDING_EVT_TRIG      /*!< \brief  Peripheral event trigger has arrived */
} Cdd_Dma_PeriEvtTrigStatusType;

/** \brief MPU region access type */
typedef enum
{
    CDD_DMA_NO_ACCESS,        /*!< \brief  No access to the region */
    CDD_DMA_READ_ACCESS,      /*!< \brief  Only read access */
    CDD_DMA_READ_WRITE_ACCESS /*!< \brief  Both read and write access */
} Cdd_Dma_MpuRegionAccessType;

typedef enum
{
    CDD_DMA_CHPRIORITY0, /*!< \brief    Priority 0. */
    CDD_DMA_CHPRIORITY1, /*!< \brief    Priority 1. */
    CDD_DMA_CHPRIORITY2, /*!< \brief    Priority 2. */
    CDD_DMA_CHPRIORITY3  /*!< \brief    Priority 3. */
} Cdd_Dma_ChannelPriority;

/** \brief DMA Channel status structure */
typedef struct
{
    /** \brief  Peripheral event trigger flag status */
    Cdd_Dma_PeriEvtTrigStatusType PeripheralEventTriggerFlag;
    /** \brief  Transfer status flag */
    Cdd_Dma_TransferStatusType    TransferStatus;
    /** \brief  Burst status flag */
    Cdd_Dma_BurstStatusType       BurstStatus;
    /** \brief  Run status flag */
    Cdd_Dma_RunStatusType         RunStatus;
    /** \brief  Overflow status flag */
    Cdd_Dma_OverflowStatusType    OverflowStatus;
} Cdd_Dma_ChannelStatus;

/** \brief DMA Channel properties */
typedef struct Cdd_Dma_ChannelParamsTag
{
    /** \brief  DMA channel data size mode */
    Cdd_Dma_ChannelDataSizeType      DataSize;
    /** \brief  DMA channel write data size mode */
    Cdd_Dma_ChannelWrDataSizeType    WrDataSize;
    /** \brief  DMA channel one shot mode */
    Cdd_Dma_OneshotModeEnableType    OneShotMode;
    /** \brief  DMA channel continuous mode */
    Cdd_Dma_ContinuousModeEnableType ContinuousMode;
    /** \brief  DMA channel interrupt */
    Cdd_Dma_ChIntEnableType          ChannelIntEnable;
    /** \brief  DMA channel interrupt generation mode */
    Cdd_Dma_ChIntModeType            ChIntMode;
    /** \brief  DMA channel overflow interrupt */
    Cdd_Dma_OvrflowIntEnableType     OverflowIntEnable;
    /** \brief  DMA channel peripheral event trigger */
    Cdd_Dma_PeriEvtTrigEnableType    PeripheralEvntTrigEnable;
    /** \brief  DMA channel peripheral event source */
    Cdd_Dma_PeriEvtTriggerSrcType    PeripheralEventTrigSrc;
} Cdd_Dma_ChannelParamsType;

/** \brief Burst and Transfer size parameter */
typedef struct Cdd_Dma_TransferSizeTag
{
    /** \brief  DMA channel burst size */
    uint8  BurstSize;
    /** \brief  DMA channel transfer size */
    uint16 TransferSize;
} Cdd_Dma_TransferSizeType;

/** \brief Source burst step and transfer step parameter */
typedef struct Cdd_Dma_TransferSrcStepTag
{
    /** \brief  DMA channel source burst step */
    sint16 SrcBurstStep;
    /** \brief  DMA channel source transfer step */
    sint16 SrcTransferStep;
} Cdd_Dma_TransferSrcStepType;

/** \brief Destination burst step and transfer step parameter */
typedef struct Cdd_Dma_TransferDestStepTag
{
    /** \brief  DMA channel destination burst step */
    sint16 DestBurstStep;
    /** \brief  DMA channel destination transfer step */
    sint16 DestTransferStep;
} Cdd_Dma_TransferDestStepType;

/** \brief MPU Region channel mask parameter */
typedef uint16 Cdd_Dma_MpuChmaskType;

/** \brief Source wrap size, wrap step and beginning address parameter*/
typedef struct Cdd_Dma_TransferSrcWrapTag
{
    /** \brief  DMA channel source wrap size */
    uint16 SrcWrapSize;
    /** \brief  DMA channel source wrap step */
    sint16 SrcWrapStep;
    /** \brief  DMA channel source beginning  address */
    uint32 SrcBegAddress;
} Cdd_Dma_TransferSrcWrapType;

/** \brief Destination wrap size, wrap step and beginning address parameter */
typedef struct Cdd_Dma_TransferDestWrapTag
{
    /** \brief  DMA channel destination wrap size */
    uint16 DestWrapSize;
    /** \brief  DMA channel destination wrap step */
    sint16 DestWrapStep;
    /** \brief  DMA channel destination beginning  address */
    uint32 DestBegAddress;
} Cdd_Dma_TransferDestWrapType;

/** \brief DMA transfer properties */
typedef struct Cdd_Dma_TransferParamsTag
{
    /** \brief  DMA channel burst and transfer size */
    Cdd_Dma_TransferSizeType     TransferSizeProperties;
    /** \brief  DMA channel source burst and transfer step */
    Cdd_Dma_TransferSrcStepType  SrcStepSize;
    /** \brief  DMA channel destination burst and transfer step */
    Cdd_Dma_TransferDestStepType DestStepSize;
    /** \brief  DMA channel source address */
    uint32                       SrcAddress;
    /** \brief  DMA channel destination address */
    uint32                       DestAddress;
    /** \brief  DMA channel source wrap size, wrap step and begin address */
    Cdd_Dma_TransferSrcWrapType  SrcWrapProperties;
    /** \brief  DMA channel destination wrap size, wrap step and begin address */
    Cdd_Dma_TransferDestWrapType DestWrapProperties;
} Cdd_Dma_TransferParamsType;

/** \brief DMA Channel configuration structure */
typedef struct Cdd_Dma_MpuRegionCfgTag
{
    /** \brief  Dma Mpu Region */
    Cdd_Dma_MpuRegionType       mpuregion;
    /** \brief  DMA Start Address */
    uint32                      mpustartaddr;
    /** \brief  DMA End Address */
    uint32                      mpuendaddr;
    /** \brief  DMA MPU Region Access Type */
    Cdd_Dma_MpuRegionAccessType access;
    /** \brief  DMA MPU Region Channel Mask */
    Cdd_Dma_MpuChmaskType       chmask;
} Cdd_Dma_MpuRegionCfgType;

/** \brief CDD DMA config type */
typedef struct Cdd_Dma_HwInstanceCfgTag
{
    /** \brief Cdd_Dma Instance */
    Cdd_Dma_InstanceType      instance;
    /** \brief Cdd_Dma Instance Base address */
    uint32                    baseaddress;
    /** \brief Priority scheme */
    Cdd_Dma_PriorityType      priorityscheme;
    /** \brief Emulation mode type */
    Cdd_Dma_EmulationModeType emulationmode;
    //** \brief  Software Priority Configuration for channel 1 to channel 8 */
    uint32                    swpri1;
    /** \brief  Software Priority Configuration for channel 9 to channel 10 */
    uint32                    swpri2;
    /** \brief Mpu enable */
    boolean                   mpuenable;
    /** \brief Cdd_Dma Mpu Base address */
    uint32                    mpubaseaddress;
    /** \brief Cdd_Dma Mpu region count */
    uint8                     mpuregioncount;
    /** \brief Cdd_Dma Mpu Region Type */
    Cdd_Dma_MpuRegionCfgType  mpucfg[CDD_DMA_MPU_REGION_COUNT];
} Cdd_Dma_HwInstanceCfgType;

/** \brief CDD DMA channel config type */
typedef struct Cdd_Dma_ChannelCfgTag
{
    /** \brief Cdd_Dma Instance*/
    Cdd_Dma_InstanceType instance;
    /** \brief Cdd_Dma Channel */
    Cdd_Dma_ChannelType  channel;
    /** \brief Cdd_Dma Channel Base address */
    uint32               baseaddress;
    /** \brief Cdd_Dma Channel Interrupt Notification Type */
    Cdd_Dma_NotifyType   chintnotification;
    /** \brief Cdd_Dma Overflow Interrupt Notification Type */
    Cdd_Dma_NotifyType   overflowintnotification;
} Cdd_Dma_ChannelCfgType;

/** \brief CDD DMA config type */
typedef struct Cdd_Dma_ConfigTag
{
    /** \brief Cdd_Dma Instance Cfg Type */
    Cdd_Dma_HwInstanceCfgType hwinstcfg[CDD_DMA_HW_INSTANCE_COUNT];
    /** \brief Cdd_Dma Channel Cfg Type */
    Cdd_Dma_ChannelCfgType    chcfg[CDD_DMA_CHANNEL_COUNT];
} Cdd_Dma_ConfigType;
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
/** \brief Service to provide the version information of Cdd Dma module
 *
 * \param[out] VersionInfoPtr is the pointer to CDD DMA driver version information.
 * \pre This API is available only if CDD_DMA_GET_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_DMA_APPL_DATA) VersionInfoPtr);
#endif /* CDD_DMA_GET_VERSION_INFO_API */

/** \brief Service to initialize CDD DMA driver
 *
 * \param[in] ConfigPtr is the NULL pointer for pre compile variant
 *from plugin
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_Init(P2CONST(Cdd_Dma_ConfigType, AUTOMATIC, CDD_DMA_CONFIG_DATA) ConfigPtr);

/** \brief Service to deinitialize CDD DMA driver
 *
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE) Cdd_Dma_DeInit(void);

/** \brief Service to set the channel properties of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the channel properties are configured
 * \param[in] ChannelProperties: Structure of type Cdd_Dma_ChannelParamsType which contains the channel properties
 * to be set.
 * \pre None
 * \post None
 * \return Status of setting channel properties
 * \retval E_OK: Successfully set channel properties
 * \retval E_NOT_OK: Failed to set channel properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetChannelProperties(VAR(uint8, AUTOMATIC) ChannelId,
                             VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) ChannelProperties);

/** \brief Service to set the transfer properties of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the transfer properties are configured
 * \param[in] TransferProperties: Structure of type Cdd_Dma_TransferParamsType which contains the transfer properties to
 *be set
 * \pre None
 * \post None
 * \return Status of setting transfer properties
 * \retval E_OK: Successfully set transfer properties
 * \retval E_NOT_OK: Failed to set transfer properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferProperties(VAR(uint8, AUTOMATIC) ChannelId,
                              VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) TransferProperties);

/** \brief Service to set the burst size and transfer size of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the transfer size properties are configured
 * \param[in] BurstSize: Number of words transferred per burst
 * \param[in] TransferSize: Total number of bursts in the transfer
 * \pre None
 * \post None
 * \return Status of setting burst size and transfer size
 * \retval E_OK: Successfully set burst size and transfer size
 * \retval E_NOT_OK: Failed to set burst size and transfer size
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSize(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint8, AUTOMATIC) BurstSize,
                        VAR(uint16, AUTOMATIC) TransferSize);

/** \brief Service to set the transfer source properties : source burst step, source transfer step of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the source burst step and source transfer step
 *properties are configured
 * \param[in] SrcBurstStep: Source burst step
 * \param[in] SrcTransferStep: Source transfer step
 * \pre None
 * \post None
 * \return Status of setting transfer source properties : source burst step, source transfer step
 * \retval E_OK: Successfully set transfer source properties
 * \retval E_NOT_OK: Failed to set transfer source properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSrcProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(sint16, AUTOMATIC) SrcBurstStep,
                                 VAR(sint16, AUTOMATIC) SrcTransferStep);

/** \brief Service to set the transfer destination properties : destination burst step, destination transfer step of a
 *DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the destination burst step and destination transfer
 *step properties are configured
 * \param[in] DestBurstStep: Destination burst step
 * \param[in] DestTransferStep: Destination transfer step
 * \pre None
 * \post None
 * \return Status of setting transfer destination properties : destination burst step, destination transfer step
 * \retval E_OK: Successfully set transfer destination properties
 * \retval E_NOT_OK: Failed to set transfer destination properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferDestProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(sint16, AUTOMATIC) DestBurstStep,
                                  VAR(sint16, AUTOMATIC) DestTransferStep);

/** \brief Service to set the transfer source address of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the source address is configured
 * \param[in] SrcAddress: Transfer source address
 * \pre None
 * \post None
 * \return Status of setting transfer source address
 * \retval E_OK: Successfully set transfer source address.
 * \retval E_NOT_OK: Failed to set source address.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferSrcAddress(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint32, AUTOMATIC) SrcAddress);

/** \brief Service to set the transfer destination address of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the destination address is configured
 * \param[in] DestAddress: Transfer destination address
 * \pre None
 * \post None
 * \return Status of setting transfer destination address
 * \retval E_OK: Successfully set transfer destination address
 * \retval E_NOT_OK: Failed to set destination address
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferDestAddress(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint32, AUTOMATIC) DestAddress);

/** \brief Service to set the transfer source wrap properties of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the source wrap properties are configured
 * \param[in] SrcWrapSize: Source wrap size
 * \param[in] SrcWrapStep: Source wrap step
 * \param[in] SrcBegAddress: Source beginning address
 * \pre None
 * \post None
 * \return Status of setting source wrap properties
 * \retval E_OK: Successfully set source wrap properties
 * \retval E_NOT_OK: Failed to set source wrap properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapSrcProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint16, AUTOMATIC) SrcWrapSize,
                                     VAR(sint16, AUTOMATIC) SrcWrapStep, VAR(uint32, AUTOMATIC) SrcBegAddress);

/** \brief Service to set the transfer destination wrap properties of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the destination wrap properties are configured
 * \param[in] DestWrapSize: Destination wrap size
 * \param[in] DestWrapStep: Destination wrap step
 * \param[in] DestBegAddress: Destination beginning address
 * \pre None
 * \post None
 * \return Status of setting destination wrap properties
 * \retval E_OK: Successfully set destination wrap properties
 * \retval E_NOT_OK: Failed to set destination wrap properties
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetTransferWrapDestProperties(VAR(uint8, AUTOMATIC) ChannelId, VAR(uint16, AUTOMATIC) DestWrapSize,
                                      VAR(sint16, AUTOMATIC) DestWrapStep, VAR(uint32, AUTOMATIC) DestBegAddress);

/** \brief Service to enable peripheral event triggers of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which trigger shall be enabled
 * \pre None
 * \post None
 * \return Status of peripheral event trigger enabling
 * \retval E_OK: Successfully enabled peripheral event trigger
 * \retval E_NOT_OK: Failed to enable peripheral event trigger
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_EnablePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to disable peripheral event triggers of a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which trigger shall be disabled
 * \pre None
 * \post None
 * \return Status of peripheral event trigger disabling
 * \retval E_OK: Successfully disabled peripheral event trigger
 * \retval E_NOT_OK: Failed to disabled peripheral event trigger
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_DisablePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to set the peripheral event trigger source for a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel for which trigger source shall be set
 * \param[in] PeripheralEventTrigSrc : Peripheral event trigger source value
 * \pre None
 * \post None
 * \return Status of setting peripheral event trigger source
 * \retval E_OK: Successfully set peripheral event trigger source
 * \retval E_NOT_OK: Failed to set peripheral event trigger source
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetPeripheralEventTriggerSource(VAR(uint8, AUTOMATIC) ChannelId,
                                        VAR(Cdd_Dma_PeriEvtTriggerSrcType, AUTOMATIC) PeripheralEventTrigSrc);

/** \brief Service to start or enable a DMA channel
 *
 * \param[in] ChannelId : Symbolic name of the channel which shall be enabled
 * \pre None
 * \post None
 * \return Status of enabling the DMA channel
 * \retval E_OK: Successfully enabled the DMA channel
 * \retval E_NOT_OK: Failed to enable the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_StartChannelTransfer(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to stop or disable a DMA channel.
 *
 * \param[in] ChannelId : Symbolic name of the channel for which transfer shall be stopped
 * \pre None
 * \post None
 * \return Status of stoping the DMA channel
 * \retval E_OK: Successfully disabled the DMA channel
 * \retval E_NOT_OK: Failed to disable the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_StopChannelTransfer(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to force the peripheral event trigger for the channel.
 *
 * \param[in] ChannelId : Symbolic name of the DMA channel for which trigger shall be forced
 * \pre None
 * \post None
 * \return Status of forcing DMA channel trigger
 * \retval E_OK: Successfully forced trigger for the DMA channel
 * \retval E_NOT_OK: Failed to force trigger for the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ForcePeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to clear the peripheral event trigger for the channel.
 *
 * \param[in] ChannelId : Symbolic name of the channel for which trigger shall be cleared
 * \pre None
 * \post None
 * \return Status of clearing DMA channel trigger
 * \retval E_OK: Successfully cleared trigger for the DMA channel
 * \retval E_NOT_OK: Failed to clear trigger for the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ClearPeripheralEventTrigger(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to trigger a soft reset for the channel.
 *
 * \param[in] ChannelId : Symbolic name of the channel for which for which soft trigger shall be triggered
 * \pre None
 * \post None
 * \return Status of trigerring soft reset
 * \retval E_OK: Successfully triggered soft reset for the DMA channel
 * \retval E_NOT_OK: Failed to trigger soft reset for the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_TriggerSoftReset(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to set channel priority.
 *
 * \param[in] ChannelId : Symbolic name of the channel for which priority shall be set
 * \param[in] Priority : Channel priority to be assigned
 * \pre None
 * \post None
 * \return Status of setting channel priority
 * \retval E_OK: Successfully set channel priority for the DMA channel
 * \retval E_NOT_OK: Failed to set channel priority for the DMA channel
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE)
Cdd_Dma_SetChannelPriority(VAR(uint8, AUTOMATIC) ChannelId, Cdd_Dma_ChannelPriority Priority);

/** \brief Service to get the channel status : peripheral event trigger status, transfer status, burst status, run
 *status and overflow status
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the status shall be read
 * \param[out] ChannelStatus : Pointer to the structure of type Cdd_Dma_ChannelStatus where the channel status will be
 *copied
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_DMA_CODE)
Cdd_Dma_GetChannelStatus(VAR(uint8, AUTOMATIC) ChannelId,
                         P2VAR(Cdd_Dma_ChannelStatus, AUTOMATIC, CDD_DMA_APPL_DATA) ChannelStatus);

/** \brief Service to clear the overflow error flag for a DMA channel.
 *
 * \param[in] ChannelId : Symbolic name of the channel for which the overflow error needs to be cleared
 * \pre None
 * \post None
 * \return Status of clearing the overflow error flag
 * \retval E_OK: Successfully cleared overflow error flag
 * \retval E_NOT_OK: Failed to clear overflow error flag
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_ClearErrorFlag(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to commit DMA configurable properties such as priority scheme, channel priority and emulation mode
 *for a specific instance.
 *
 * \param[in] HwInstanceId Symbolic name of the DMA hardware instance
 * \pre None
 * \post None
 * \return Status of commiting DMA configurations
 * \retval E_OK: Successfully commited DMA configurations
 * \retval E_NOT_OK: Failed to commit DMA configurations
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetDmaCfgCommit(VAR(uint8, AUTOMATIC) HwInstanceId);

/** \brief Service to commit DMA channel configurations for a specific channel.
 *
 * \param[in] ChannelId Symbolic name of the DMA channel
 * \pre None
 * \post None
 * \return Status of commiting DMA channel configurations
 * \retval E_OK: Successfully commited DMA channel configurations
 * \retval E_NOT_OK: Failed to commit DMA channel configurations
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetChannelCommit(VAR(uint8, AUTOMATIC) ChannelId);

/** \brief Service to commit Mpu configuration: MPUEN for a specific instance.
 *
 * \param[in] HwInstanceId Symbolic name of the DMA hardware instance
 * \pre None
 * \post None
 * \return Status of commiting Mpu configuration
 * \retval E_OK: Successfully commited Mpu configuration
 * \retval E_NOT_OK: Failed to commit Mpu configuration
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetMpuCfgCommit(VAR(uint8, AUTOMATIC) HwInstanceId);

/** \brief Service to commit Mpu Region configurations for a specific MPU region.
 *
 * \param[in] MpuRegionId Symbolic name of the DMA MPU region
 * \pre None
 * \post None
 * \return Status of commiting Mpu Region configuration
 * \retval E_OK: Successfully commited Mpu Region configuration
 * \retval E_NOT_OK: Failed to commit Mpu Region configuration
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_DMA_CODE) Cdd_Dma_SetMpuRegionCommit(VAR(uint16, AUTOMATIC) MpuRegionId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*None*/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_DMA_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Dma.h
 *********************************************************************************************************************/
