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
 *  File:       Cdd_Dma_Example_Gpt_Ping_Pong_Buffer.c
 *  Generator:  None
 *
 *  Description:  This example demonstrates DMA-based ping-pong buffering using a software-incremented counter as the
 *DMA source and GPT timer as the trigger source. Ping-pong buffering is a technique where two buffers alternate between
 *data collection and processing, allowing continuous data capture without gaps.
 *
 *                The example uses GPT timer(CPUTIMER0) trigger source with DMA configured to automatically transfer
 *                results into alternating ping and pong buffers. When one buffer is being filled by DMA, the other
 *                buffer can be processed by the CPU. The DMA destination address is switched in the ISR to implement
 *                the ping-pong mechanism.
 *
 *  Execution Flow:
 *  1. EcuM_Init() - Initialize system (MCU clock to 200 MHz, Port pins, Gpt driver)
 *  2. AppUtils_Init() - Initialize UART for console output
 *  3. Configure_Cdd_Dma()  - Set up DMA channel for ping-pong buffering from SourceCounter
 *  4. Cdd_Dma_StartChannelTransfer() - Start DMA channel (waits for Gpt triggers)
 *  5. GPT notification fires at 1 ms intervals:
 *     - TINT0 hardware event triggers the DMA burst automatically
 *     - Increments SourceCounter so each DMA capture holds a unique value
 *     - DMA ISR switches destination to the alternate buffer when a buffer is full
 *  6. Display captured values from both ping and pong buffers
 *
 *  Expected Results:
 *  - 20 snapshots of SourceCounter are captured by DMA into alternating ping and pong buffers (10 samples each)
 *  - Console displays the captured values from both buffers *
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
#include "Gpt.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/** Number of samples stored in each ping / pong buffer. */
#define PING_PONG_BUFFER_SIZE 10U

/** Number of data elements transferred per DMA burst (1 byte per burst). */
#define DMA_BURST_SIZE 1U

/** Number of bursts per buffer fill (equals PING_PONG_BUFFER_SIZE). */
#define DMA_TRANSFER_SIZE 10U

/** Destination address step between consecutive bursts (1 byte). */
#define DMA_DEST_BURST_STEP 1U

/** Source address step between bursts (0 = always read from the same address). */
#define DMA_SRC_STEP_DISABLED 0U

/** Wrap size value that effectively disables wrapping (maximum field value). */
#define DMA_WRAP_DISABLED 65535U

/** MCU clock = 200 MHz; 1 ms period → 200 000 000 Hz × 0.001 s = 200 000 ticks. */
#define GPT_PERIOD_1MS_TICKS 200000U

/** Total number of GPT-triggered DMA captures to perform (2 full buffer fills). */
#define GPT_DMA_TRIGGER_COUNT 20U

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

VAR(uint8, AUTOMATIC) PingBuffer[PING_PONG_BUFFER_SIZE] = {0U};

VAR(uint8, AUTOMATIC) PongBuffer[PING_PONG_BUFFER_SIZE] = {0U};

/** DMA source */
volatile VAR(uint8, AUTOMATIC) SourceCounter = 0U;

/** Points to the buffer currently being filled by the DMA channel. */
volatile VAR(uint8*, AUTOMATIC) ActiveDmaBuffer = PingBuffer;

/** Incremented by the DMA transfer-complete ISR each time a buffer is fully filled. */
volatile VAR(uint8, AUTOMATIC) DmaBufferFillCount = 0U;

/** Incremented by the GPT notification on every timer period expiry. */
volatile VAR(uint8, AUTOMATIC) GptTriggerCount = 0U;

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Dma_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

FUNC(void, AUTOMATIC) Configure_Cdd_Dma(void);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* GPT channel 0 notification callback.*/
FUNC(void, AUTOMATIC) Gpt_Notify_Func_0(void)
{
    GptTriggerCount++;
    SourceCounter++;

    if (GptTriggerCount >= GPT_DMA_TRIGGER_COUNT)
    {
        Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
    }
}

FUNC(void, AUTOMATIC) Cdd_Dma_transfer_complete_notification(uint8 Channel_Index)
{
    DmaBufferFillCount++;

    /* Toggle destination between ping and pong buffers. */
    if (ActiveDmaBuffer == PingBuffer)
    {
        ActiveDmaBuffer = PongBuffer;
    }
    else
    {
        ActiveDmaBuffer = PingBuffer;
    }

    Cdd_Dma_SetTransferDestAddress(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, (uint32)ActiveDmaBuffer);
}

FUNC(void, AUTOMATIC) Cdd_Dma_overflow_notification(uint8 Channel_Index)
{
    AppUtils_Printf("DMA overflow detected on channel %d\n", Channel_Index);
    while (1)
        ;
}

FUNC(void, AUTOMATIC) Configure_Cdd_Dma(void)
{
    VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) channelParams;
    VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) transferParams;

    /* --- Channel properties --- */
    channelParams.DataSize                 = CDD_DMA_CHANNEL_DATASIZE_MODE_8;
    channelParams.WrDataSize               = CDD_DMA_CHANNEL_WR_DATASIZE_MODE_8;
    channelParams.OneShotMode              = CDD_DMA_ONESHOT_MODE_DISABLED;
    channelParams.ContinuousMode           = CDD_DMA_CONTINUOUS_MODE_ENABLED;
    channelParams.ChannelIntEnable         = CDD_DMA_CHANNEL_INTERRUPT_ENABLED;
    channelParams.ChIntMode                = CDD_DMA_INT_END_OF_TRANSFER;
    channelParams.OverflowIntEnable        = CDD_DMA_OVERFLOW_INTERRUPT_ENABLED;
    channelParams.PeripheralEvntTrigEnable = CDD_DMA_PERI_EVT_TRIG_ENABLED;
    channelParams.PeripheralEventTrigSrc   = CDD_DMA_TRIGGER_TINT0;

    Cdd_Dma_SetChannelProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, channelParams);

    /* --- Transfer size --- */
    transferParams.TransferSizeProperties.BurstSize    = DMA_BURST_SIZE;
    transferParams.TransferSizeProperties.TransferSize = DMA_TRANSFER_SIZE;

    /* --- Source address and step --- */
    /* Source is fixed: always read from the same SourceCounter address. */
    transferParams.SrcAddress                      = (uint32)(&SourceCounter);
    transferParams.SrcStepSize.SrcBurstStep        = DMA_SRC_STEP_DISABLED;
    transferParams.SrcStepSize.SrcTransferStep     = DMA_SRC_STEP_DISABLED;
    transferParams.SrcWrapProperties.SrcWrapSize   = DMA_WRAP_DISABLED;
    transferParams.SrcWrapProperties.SrcWrapStep   = DMA_SRC_STEP_DISABLED;
    transferParams.SrcWrapProperties.SrcBegAddress = (uint32)(&SourceCounter);

    /* --- Destination address and step --- */
    /* Destination advances by 1 byte per burst to fill the buffer sequentially. */
    transferParams.DestAddress                       = (uint32)PingBuffer;
    transferParams.DestStepSize.DestBurstStep        = DMA_SRC_STEP_DISABLED;
    transferParams.DestStepSize.DestTransferStep     = DMA_DEST_BURST_STEP;
    transferParams.DestWrapProperties.DestWrapSize   = DMA_WRAP_DISABLED;
    transferParams.DestWrapProperties.DestWrapStep   = DMA_SRC_STEP_DISABLED;
    transferParams.DestWrapProperties.DestBegAddress = (uint32)PingBuffer;

    Cdd_Dma_SetTransferProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, transferParams);
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

FUNC(int, AUTOMATIC) main(void)
{
    VAR(uint8, AUTOMATIC) sampleIndex;
    VAR(boolean, AUTOMATIC) testPassed = TRUE;

    EcuM_Init();
    DeviceSupport_Init();
    AppUtils_Init(200000000U);

    AppUtils_Printf("Executing Cdd_Dma_Example_Gpt_Ping_Pong_Buffer example\n");

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
    Cdd_Dma_GetVersionInfo(&Cdd_Dma_VersionInfo);
    AppUtils_Printf("CDD DMA MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Dma_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Dma_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Dma_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Dma_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Dma_VersionInfo.sw_patch_version);
#endif

    /* Configure DMA channel for ping-pong buffering. */
    Configure_Cdd_Dma();

    /* Arm the DMA channel; it will wait for the first TINT0 peripheral trigger. */
    Cdd_Dma_StartChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    AppUtils_Printf("\nStarting ping-pong buffer capture via GPT-triggered DMA...\n");

    /* Enable the GPT notification so Gpt_Notify_Func_0 is called on each timer expiry. */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, GPT_PERIOD_1MS_TICKS);

    /* Wait until all GPT-triggered DMA captures have been issued and both ping and pong buffers have been filled. */
    while ((GptTriggerCount < GPT_DMA_TRIGGER_COUNT) || (DmaBufferFillCount < 2U))
    {
        McalLib_Delay(100U);
    }

    AppUtils_Printf("Ping and Pong buffers filled!\n\n");

    /* Stop the DMA channel before reading the buffers. */
    Cdd_Dma_StopChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    /* Display captured samples from both buffers. */
    AppUtils_Printf("DMA ping-pong buffer capture results:\n");

    AppUtils_Printf("Ping Buffer (expected 0..%d):\n", PING_PONG_BUFFER_SIZE - 1U);
    for (sampleIndex = 0U; sampleIndex < PING_PONG_BUFFER_SIZE; sampleIndex++)
    {
        AppUtils_Printf("  Sample[%d]: %d\n", sampleIndex, PingBuffer[sampleIndex]);
    }

    AppUtils_Printf("\nPong Buffer (expected %d..%d):\n", PING_PONG_BUFFER_SIZE, (2U * PING_PONG_BUFFER_SIZE) - 1U);
    for (sampleIndex = 0U; sampleIndex < PING_PONG_BUFFER_SIZE; sampleIndex++)
    {
        AppUtils_Printf("  Sample[%d]: %d\n", sampleIndex, PongBuffer[sampleIndex]);
    }

    for (sampleIndex = 0U; sampleIndex < PING_PONG_BUFFER_SIZE; sampleIndex++)
    {
        if (PingBuffer[sampleIndex] != sampleIndex)
        {
            AppUtils_Printf("  FAIL: PingBuffer[%d] = %d, expected %d\n", sampleIndex, PingBuffer[sampleIndex],
                            sampleIndex);
            testPassed = FALSE;
        }

        if (PongBuffer[sampleIndex] != (sampleIndex + PING_PONG_BUFFER_SIZE))
        {
            AppUtils_Printf("  FAIL: PongBuffer[%d] = %d, expected %d\n", sampleIndex, PongBuffer[sampleIndex],
                            sampleIndex + PING_PONG_BUFFER_SIZE);
            testPassed = FALSE;
        }
    }

    Cdd_Dma_DeInit();

    AppUtils_Printf("\n\r==================================================================\n\r");

    if (testPassed == TRUE)
    {
        AppUtils_Printf("\nCdd_Dma_Example_Gpt_Ping_Pong_Buffer Example PASSED\n");
    }
    else
    {
        AppUtils_Printf("\nCdd_Dma_Example_Gpt_Ping_Pong_Buffer Example FAILED\n");
    }

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Example_Gpt_Ping_Pong_Buffer.c
 *********************************************************************************************************************/
