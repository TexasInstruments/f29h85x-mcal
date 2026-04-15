/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Cdd_Dma_Example_Mem_Transfer.c
 *  Generator:  None
 *
 *  Description: This example demonstrates how to use the Cdd_Dma driver for memory-to-memory transfer.
 *               This example uses one DMA channel to transfer data from a buffer to another buffer in RAM.
 *               The example triggers the DMA channel repeatedly until the transfer of 16 bursts (where each
 *               burst is 4 32-bit words) has been completed. When the whole transfer is complete it will
 *               trigger the DMA interrupt.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Port.h"
#include "Mcu.h"
#include "Cdd_Dma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define DATASIZE           16U
#define BURST_SIZE         4U
#define TRANSFER_SIZE      16U
#define WORD_SIZE_BYTES    4U
#define MAX_WRAP_SIZE      65535U
#define WRAP_STEP_DISABLED 0U

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
VAR(uint32, AUTOMATIC) TxData[DATASIZE]; /* Send data buffer */
VAR(uint32, AUTOMATIC) RxData[DATASIZE]; /* Receive data buffer */
volatile VAR(uint8, AUTOMATIC) done = 0;
#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Dma_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

FUNC(int, AUTOMATIC) main(void)
{
    VAR(uint16, AUTOMATIC) idx;
    VAR(uint16, AUTOMATIC) burstCount   = 0U;
    VAR(boolean, AUTOMATIC) burstResult = TRUE;
    VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) channelParams;
    VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) transferParams;
    VAR(Cdd_Dma_ChannelStatus, AUTOMATIC) channelStatus;

    /* EcuM_Init() will Initialize Port and Mcu with the provided configuration */
    EcuM_Init();

    DeviceSupport_Init();

    AppUtils_Init(200000000U); /* Init App utils to enable prints */
    AppUtils_Printf("Executing Cdd_Dma_Example_Mem_Transfer example\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\r");

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
    Cdd_Dma_GetVersionInfo(&Cdd_Dma_VersionInfo);
    AppUtils_Printf("CDD DMA MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Dma_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Dma_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Dma_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Dma_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Dma_VersionInfo.sw_patch_version);
    AppUtils_Printf("---------------------------------------------------------------\n\r");
#endif

    /* Initialize Cdd_Dma driver with configuration from EB Tresos */
    Cdd_Dma_Init(NULL_PTR);

    /* Initialize test data */
    for (idx = 0; idx < DATASIZE; idx++)
    {
        TxData[idx] = idx;
        RxData[idx] = 0;
    }

    AppUtils_Printf("Data at source before transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", TxData[idx]);
    }
    AppUtils_Printf("\n\rData at destination before transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", RxData[idx]);
    }

    /* Configure DMA channel properties */
    channelParams.PeripheralEventTrigSrc   = CDD_DMA_TRIGGER_SOFTWARE;
    channelParams.ContinuousMode           = CDD_DMA_CONTINUOUS_MODE_ENABLED;
    channelParams.OneShotMode              = CDD_DMA_ONESHOT_MODE_DISABLED;
    channelParams.DataSize                 = CDD_DMA_CHANNEL_DATASIZE_MODE_32;
    channelParams.WrDataSize               = CDD_DMA_CHANNEL_WR_DATASIZE_MODE_32;
    channelParams.ChannelIntEnable         = CDD_DMA_CHANNEL_INTERRUPT_ENABLED;
    channelParams.ChIntMode                = CDD_DMA_INT_END_OF_TRANSFER;
    channelParams.OverflowIntEnable        = CDD_DMA_OVERFLOW_INTERRUPT_DISABLED;
    channelParams.PeripheralEvntTrigEnable = CDD_DMA_PERI_EVT_TRIG_ENABLED;

    Cdd_Dma_SetChannelProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, channelParams);

    /* Configure transfer parameters */
    /* Transfer size: 4 words per burst, 16 bursts total */
    transferParams.TransferSizeProperties.BurstSize    = BURST_SIZE;
    transferParams.TransferSizeProperties.TransferSize = TRANSFER_SIZE;

    /* Source and destination step sizes (4 bytes per 32-bit word) */
    transferParams.SrcStepSize.SrcBurstStep      = WORD_SIZE_BYTES;
    transferParams.SrcStepSize.SrcTransferStep   = WORD_SIZE_BYTES;
    transferParams.DestStepSize.DestBurstStep    = WORD_SIZE_BYTES;
    transferParams.DestStepSize.DestTransferStep = WORD_SIZE_BYTES;

    /* Source and destination addresses */
    transferParams.SrcAddress  = (uint32)TxData;
    transferParams.DestAddress = (uint32)RxData;

    /* Wrap properties (no wrapping) */
    transferParams.SrcWrapProperties.SrcWrapSize     = MAX_WRAP_SIZE;
    transferParams.SrcWrapProperties.SrcWrapStep     = WRAP_STEP_DISABLED;
    transferParams.SrcWrapProperties.SrcBegAddress   = (uint32)TxData;
    transferParams.DestWrapProperties.DestWrapSize   = MAX_WRAP_SIZE;
    transferParams.DestWrapProperties.DestWrapStep   = WRAP_STEP_DISABLED;
    transferParams.DestWrapProperties.DestBegAddress = (uint32)RxData;

    Cdd_Dma_SetTransferProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, transferParams);

    Cdd_Dma_SetPeripheralEventTriggerSource(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, CDD_DMA_TRIGGER_SOFTWARE);

    /* Start DMA channel */
    Cdd_Dma_StartChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    done       = 0U; /* Test is not done yet */
    burstCount = 0U; /* Initialize burst counter */

    /* Process all 16 bursts */
    while (burstCount < TRANSFER_SIZE)
    {
        /* Trigger the DMA channel */
        Cdd_Dma_ForcePeripheralEventTrigger(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

        /* Wait until this burst completes */
        do
        {
            Cdd_Dma_GetChannelStatus(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, &channelStatus);
        } while (channelStatus.BurstStatus == CDD_DMA_BURST_ACTIVITY_ONGOING);

        /* Check data integrity for this burst */
        if (RxData[burstCount] != TxData[burstCount])
        {
            burstResult = FALSE;
            AppUtils_Printf("Burst %d failed at index %d (expected: %d, actual: %d) ", burstCount, burstCount,
                            TxData[burstCount], RxData[burstCount]);
        }

        /* Move to next burst */
        burstCount++;
    }

    /* Wait for interrupt to confirm completion */
    while (done == 0U)
    {
    }

    /* Stop DMA channel */
    Cdd_Dma_StopChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    AppUtils_Printf("\n\rData at source after transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", TxData[idx]);
    }
    AppUtils_Printf("\n\rData at destination after transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", RxData[idx]);
    }
    AppUtils_Printf("\n\r===============================================\n\r");

    if (burstResult == TRUE)
    {
        AppUtils_Printf("\n\rTransfer successful\n\r");
    }
    else
    {
        AppUtils_Printf("\n\rTransfer failed\n\r");
    }

    return 0;
}

FUNC(void, AUTOMATIC) Cdd_Dma_Channel1_notification(uint8 Channel_Index)
{
    /* Verify the channel index matches the expected symbolic name */
    if (Channel_Index == Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0)
    {
        done = 1U; /* Test done */
    }
    return;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Example_Mem_Transfer.c
 *********************************************************************************************************************/
