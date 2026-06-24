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
 *  File:       Cdd_Dma_Example_Adc_Data_Binning.c
 *  Generator:  None
 *
 *  Description:  This example demonstrates DMA-based data binning with the CDD ADC driver. Data binning is a
 *                technique where multiple ADC conversion results for each channel are stored in separate memory
 *                locations (bins) for later processing.
 *
 *                The example uses software-triggered ADC conversions with DMA configured to automatically
 *                transfer results into a binned memory structure. Each ADC trigger generates one burst that
 *                fills one bin for all channels. The DMA uses burst and transfer stepping to organize data
 *                in an interleaved format optimized for per-channel processing.
 *
 *  Setup required for the example:
 *  - ADCA is configured for 2.5V internal reference voltage mode
 *  - Connect desired analog voltages to ADCAIN0, ADCAIN1, ADCAIN6, ADCAIN7, ADCAIN28 pins
 *    (corresponding to channels CH0-CH4)
 *
 *
 *  Steps followed in the example:
 *  EcuM_Init()
 *  - Initialize clock to 200 MHz using Mcu_Init()
 *  - Initialize pins using Port_Init() to see the print statements on the console
 *  - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 *  - Initialize Cdd_Dma driver using Cdd_Dma_Init()
 *
 *  Execution Flow:
 *  1. EcuM_Init() - Initialize system (MCU clock to 200 MHz, Port pins, ADC driver)
 *  2. AppUtils_Init() - Initialize UART for console output
 *  3. Configure_Cdd_Dma() - Set up DMA for data binning with burst/transfer stepping
 *  4. Cdd_Dma_StartChannelTransfer() - Start DMA channel (waits for ADC triggers)
 *  5. Cdd_Adc_StartGroupConversion() - Trigger first ADC conversion
 *  6. Loop for 3 conversions:
 *     - Wait for DMA burst completion (one bin filled)
 *     - Update ADC status and re-trigger for next bin
 *  7. Wait for DMA transfer interrupt (all bins filled)
 *  8. Display binned results organized by channel and bin
 *
 *  Expected Results:
 *  - 3 ADC conversions are triggered by software
 *  - DMA automatically transfers results into 3 bins per channel
 *  - Memory layout: [CH0_Bin0, CH0_Bin1, CH0_Bin2, CH1_Bin0, CH1_Bin1, CH1_Bin2, ...]
 *  - Console displays binned conversion results for all 5 channels
 *  - DMA transfer interrupt confirms all bins are filled
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Adc.h"
#include "Port.h"
#include "Mcu.h"
#include "Cdd_Dma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* Application Configuration */
#define CDD_ADC_NUM_CHANNELS (5U) /**< Number of ADC channels: CH0, CH1, CH2, CH3, CH4 */
#define CDD_ADC_NUM_BINS     (3U) /**< Number of bins per channel for data binning */

/* DMA Transfer Configuration */
#define BURST_SIZE         10U    /**< Burst size: 10 bytes (5 channels × 2 bytes/channel) */
#define TRANSFER_SIZE      3U     /**< Transfer size: 3 bursts (one per bin) */
#define MAX_WRAP_SIZE      65535U /**< Maximum wrap size (no wrapping) */
#define WRAP_STEP_DISABLED 0U     /**< Wrap step disabled */

/* Source (ADC Result Register) Step Configuration */
#define SRC_BURST_STEP    2    /**< Burst step: +2 bytes to move to next ADC result register */
#define SRC_TRANSFER_STEP (-8) /**< Transfer step: -8 bytes to wrap back to first ADC result */

/* Destination (Memory Buffer) Step Configuration */
#define DEST_BURST_STEP    6     /**< Burst step: +6 bytes to skip 2 bins and move to next channel */
#define DEST_TRANSFER_STEP (-22) /**< Transfer step: -22 bytes to wrap back to start and advance to next bin */

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

/** Buffer to store ADC conversion results in an interleaved binning format */
VAR(Cdd_Adc_ValueGroupType, AUTOMATIC) Cdd_Adc_BinnedBuffer[CDD_ADC_NUM_CHANNELS * CDD_ADC_NUM_BINS] = {0U};
/** Counter for DMA transfer complete interrupts */
volatile VAR(uint32, AUTOMATIC) Cdd_Adc_DmaIsrCount = 0U;
VAR(Cdd_Dma_ChannelStatus, AUTOMATIC) dmaStatus;
VAR(boolean, AUTOMATIC) testResult = TRUE;
#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
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

FUNC(void, AUTOMATIC) Cdd_Adc_Dma_notification(uint8 Channel_Index)
{
    /* Increment counter to indicate DMA transfer complete - all bins filled */
    Cdd_Adc_DmaIsrCount++;
}

/** Configures the DMA channel to perform data binning for ADC conversions. */
FUNC(void, AUTOMATIC) Configure_Cdd_Dma(void)
{
    VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) channelParams;
    VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) transferParams;

    /* Configure DMA channel properties */
    channelParams.DataSize                 = CDD_DMA_CHANNEL_DATASIZE_MODE_16;    /* 16-bit ADC results */
    channelParams.WrDataSize               = CDD_DMA_CHANNEL_WR_DATASIZE_MODE_16; /* 16-bit memory writes */
    channelParams.OneShotMode              = CDD_DMA_ONESHOT_MODE_DISABLED;       /* Continuous operation */
    channelParams.ContinuousMode           = CDD_DMA_CONTINUOUS_MODE_ENABLED;     /* Auto-restart after transfer */
    channelParams.ChannelIntEnable         = CDD_DMA_CHANNEL_INTERRUPT_ENABLED; /* Enable transfer complete interrupt */
    channelParams.ChIntMode                = CDD_DMA_INT_END_OF_TRANSFER;       /* Interrupt after all 3 bursts */
    channelParams.OverflowIntEnable        = CDD_DMA_OVERFLOW_INTERRUPT_DISABLED; /* No overflow interrupt needed */
    channelParams.PeripheralEvntTrigEnable = CDD_DMA_PERI_EVT_TRIG_ENABLED;       /* ADC triggers DMA */
    channelParams.PeripheralEventTrigSrc   = CDD_DMA_TRIGGER_ADCA1;               /* ADCA INT1 as trigger source */

    Cdd_Dma_SetChannelProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, channelParams);

    /* Configure transfer parameters */
    /* Transfer size: 10 bytes per burst (5 channels), 3 bursts total (3 bins) */
    transferParams.TransferSizeProperties.BurstSize    = BURST_SIZE;
    transferParams.TransferSizeProperties.TransferSize = TRANSFER_SIZE;

    /* Source step sizes: +2 bytes per burst (next ADC result), -8 bytes per transfer (wrap back) */
    transferParams.SrcStepSize.SrcBurstStep    = SRC_BURST_STEP;
    transferParams.SrcStepSize.SrcTransferStep = SRC_TRANSFER_STEP;

    /* Destination step sizes: +6 bytes per burst (skip bins), -22 bytes per transfer (wrap and advance) */
    transferParams.DestStepSize.DestBurstStep    = DEST_BURST_STEP;
    transferParams.DestStepSize.DestTransferStep = DEST_TRANSFER_STEP;

    /* Source and destination addresses */
    transferParams.SrcAddress  = (uint32)ADCARESULT_BASE;
    transferParams.DestAddress = (uint32)(&Cdd_Adc_BinnedBuffer[0U]);

    /* Wrap properties (no wrapping) */
    transferParams.SrcWrapProperties.SrcWrapSize     = MAX_WRAP_SIZE;
    transferParams.SrcWrapProperties.SrcWrapStep     = WRAP_STEP_DISABLED;
    transferParams.SrcWrapProperties.SrcBegAddress   = (uint32)ADCARESULT_BASE;
    transferParams.DestWrapProperties.DestWrapSize   = MAX_WRAP_SIZE;
    transferParams.DestWrapProperties.DestWrapStep   = WRAP_STEP_DISABLED;
    transferParams.DestWrapProperties.DestBegAddress = (uint32)(&Cdd_Adc_BinnedBuffer[0U]);

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
    EcuM_Init();
    DeviceSupport_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("Executing Cdd_Dma_Example_Adc_Data_Binning example\n");

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
    Cdd_Adc_GetVersionInfo(&Cdd_Adc_VersionInfo);
    AppUtils_Printf("CDD ADC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Adc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Adc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Adc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Adc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Adc_VersionInfo.sw_patch_version);
#endif

    /* Configure DMA for data binning */
    Configure_Cdd_Dma();

    /* Start DMA channel - it will wait for ADC triggers */
    Cdd_Dma_StartChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    /* Trigger first ADC conversion (starts DMA burst 1) */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_0);

    /* Loop to fill all 3 bins (3 conversions = 3 bursts) */
    for (uint32 conversion = 0; conversion < TRANSFER_SIZE; conversion++)
    {
        /* Wait for current DMA burst to complete (one bin filled for all channels) */
        do
        {
            Cdd_Dma_GetChannelStatus(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, &dmaStatus);
            McalLib_Delay(10U);
        } while (dmaStatus.BurstStatus == CDD_DMA_BURST_ACTIVITY_ONGOING);

        /* Update ADC status and re-trigger next conversion if needed */
        if (conversion < (TRANSFER_SIZE - 1))
        {
            /* This API updates ADC group status and re-triggers the ADC for next conversion */
            Cdd_Adc_UpdateStatusThroughDma(CDD_ADCA, CDD_ADC_INT1);
        }
    }

    /* Wait for DMA transfer complete interrupt (confirms all 3 bursts/bins complete) */
    while (Cdd_Adc_DmaIsrCount < 1)
    {
        McalLib_Delay(50U);
    }

    /* Stop DMA channel */
    Cdd_Dma_StopChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    AppUtils_Printf("ADC conversion results with DMA data binning:\n");

    for (uint8 ch = 0; ch < CDD_ADC_NUM_CHANNELS; ch++)
    {
        AppUtils_Printf("Channel %d:\n", ch);
        for (uint8 bin = 0; bin < CDD_ADC_NUM_BINS; bin++)
        {
            /* Calculate buffer index: channel offset + bin offset */
            uint8 index = (ch * CDD_ADC_NUM_BINS) + bin;
            AppUtils_Printf("  Bin %d: %d\n", bin, Cdd_Adc_BinnedBuffer[index]);
        }
    }

    for (uint8 ch = 0U; ch < CDD_ADC_NUM_CHANNELS; ch++)
    {
        for (uint8 bin = 0U; bin < CDD_ADC_NUM_BINS; bin++)
        {
            uint8 index = (ch * CDD_ADC_NUM_BINS) + bin;
            if (Cdd_Adc_BinnedBuffer[index] == 0U)
            {
                AppUtils_Printf("  FAIL: BinnedBuffer[ch=%d][bin=%d] is 0 - DMA did not transfer data\n", ch, bin);
                testResult = FALSE;
            }
        }
    }

    Cdd_Dma_DeInit();
    Cdd_Adc_DeInit();

    AppUtils_Printf("\n\r===============================================\n\r");

    if (testResult == TRUE)
    {
        AppUtils_Printf("\nCdd_Dma_Example_Adc_Data_Binning Example executed successfully\n");
    }
    else
    {
        AppUtils_Printf("\nCdd_Dma_Example_Adc_Data_Binning Example failed\n");
    }

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Example_Adc_Data_Binning.c
 *********************************************************************************************************************/
