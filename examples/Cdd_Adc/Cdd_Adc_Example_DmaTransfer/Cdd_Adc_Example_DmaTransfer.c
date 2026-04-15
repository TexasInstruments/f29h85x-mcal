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
 *  File:       Cdd_Adc_Example_DmaTransfer.c
 *  Generator:  None
 *
 *  Description:  This example demonstrates the DMA integration with CDD ADC driver.
 *
 * Setup required for the example:
 * ADCA is configured for 2.5V internal reference voltage mode.
 * Connect desired voltage to ADCAIN0,ADCAIN1,ADCAIN6,ADCAIN7,ADCAIN28,ADCAIN29,ADCAIN30 & ADCAIN31 pins.
 *
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins using Port_Init() to see the print statements on the console
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * AppUtils_Init() to initailize App Utils
 * Cdd_Dma_Init() to initialize DMA
 * Cdd_Pwm_ConfigureHardware() to initialize PWM and generate 64KHz frequency waveform
 * Call EnableHardwareTrigger API to start the group conversion
 * For every 15.625us a trigger is generated to ADC for conversion.
 * The result buffer is updated by DMA after the group is done and the interrupt is generated.
 *
 * Continue this for 1second and observe the behaviour.
 *
 * Call DisableHardwareTrigger to stop further triggers from PWM to ADC.
 *
 * Wait until group status is IDLE
 *
 * Print the success statement after the example is executed successfully.
 * Observe the ADC conversion results in the buffer.
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
#include "Cdd_Pwm.h"
#include "Cdd_Dma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_EVENT_COUNT (1U)

#define CDD_DMA1CH1_SRC_BURSTSTEP  2U
#define CDD_DMA1CH1_DEST_BURSTSTEP 2U
#define CDD_DMA1CH1_BURSTSIZE      16U

#define CDD_DMA1CH1_SRC_TRANSFERSTEP  2U
#define CDD_DMA1CH1_DEST_TRANSFERSTEP 2U
#define CDD_DMA1CH1_TRANSFERSIZE      1U

#define CDD_ADC_STREAMING_SAMPLE_COUNT (32U)

#define CDD_ADC_PWM_FREQUENCY (64000U)

#define CDD_ADC_SECONDS (5U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

Os_TickType value = 0U, elapsed_value = 0U;

uint8 Cdd_Adc_DmaSampleCount = 0U;

Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[32U][8U] = {0U};

uint32 Cdd_Adc_DmaIsrCount = 0U; /* */

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

void Cdd_Pwm_ConfigureHardware();
void Configure_Cdd_Dma();

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* DMA notification callback */
void Cdd_Adc_Dma_notification(uint8 Channel_Index)
{
    /* DMA notification */
    Cdd_Adc_DmaSampleCount++;
    Cdd_Adc_DmaIsrCount++;

    if (Cdd_Adc_DmaSampleCount == CDD_ADC_STREAMING_SAMPLE_COUNT)
    {
        /* Set Dma Isr count to 0 to count the next sampling */
        Cdd_Adc_DmaSampleCount = 0U;
    }

    /* Update the destination address of the DMA channel for next transfer */
    Cdd_Dma_SetTransferDestAddress(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0,
                                   (uint32)(&Cdd_Adc_Buffer[Cdd_Adc_DmaSampleCount][0U]));
}

void Configure_Cdd_Dma()
{
    Cdd_Dma_ChannelParamsType channelParams;

    /* Configure channel properties */
    channelParams.DataSize                 = CDD_DMA_CHANNEL_DATASIZE_MODE_16;
    channelParams.WrDataSize               = CDD_DMA_CHANNEL_WR_DATASIZE_MODE_16;
    channelParams.OneShotMode              = CDD_DMA_ONESHOT_MODE_DISABLED;
    channelParams.ContinuousMode           = CDD_DMA_CONTINUOUS_MODE_ENABLED;
    channelParams.ChannelIntEnable         = CDD_DMA_CHANNEL_INTERRUPT_ENABLED;
    channelParams.ChIntMode                = CDD_DMA_INT_END_OF_TRANSFER;
    channelParams.OverflowIntEnable        = CDD_DMA_OVERFLOW_INTERRUPT_DISABLED;
    channelParams.PeripheralEvntTrigEnable = CDD_DMA_PERI_EVT_TRIG_ENABLED;
    channelParams.PeripheralEventTrigSrc   = CDD_DMA_TRIGGER_ADCA1;

    Cdd_Dma_SetChannelProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, channelParams);

    /* Configure transfer size: burst size and transfer size */
    Cdd_Dma_SetTransferSize(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, CDD_DMA1CH1_BURSTSIZE, CDD_DMA1CH1_TRANSFERSIZE);

    /* Configure source properties: burst step and transfer step */
    Cdd_Dma_SetTransferSrcProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, CDD_DMA1CH1_SRC_BURSTSTEP,
                                     CDD_DMA1CH1_SRC_TRANSFERSTEP);

    /* Configure destination properties: burst step and transfer step */
    Cdd_Dma_SetTransferDestProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, CDD_DMA1CH1_DEST_BURSTSTEP,
                                      CDD_DMA1CH1_DEST_TRANSFERSTEP);

    /* Set source address (ADCA result register - fixed) */
    Cdd_Dma_SetTransferSrcAddress(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, (uint32)ADCARESULT_BASE);

    /* Set initial destination address (first buffer location) */
    Cdd_Dma_SetTransferDestAddress(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, (uint32)(&Cdd_Adc_Buffer[0U][0U]));
}

void Cdd_Pwm_ConfigureHardware()
{
    /* Configure PWM instance to generate 64KHz with 20% duty cycle and it triggers ADC conversion */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_1);
    /* Set the time base counter mode to UP-COUNT mode */
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP);

    /* Configure the period as per required frequency */
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 3124U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    /* Set the counter compare value */
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, 625U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    /* Configure PWM output based on compare actions */
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    /* Configure PWM to generate trigger to ADC */
    Cdd_Pwm_ConfigureAdcTrigger(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_SOC_A, TRUE);
    Cdd_Pwm_SetAdcTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_SOC_A,
                                CDD_PWM_SOC_TBCTR_U_CMPA);
    Cdd_Pwm_SetAdcTriggerEventPrescale(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_SOC_A,
                                       CDD_PWM_EVENT_COUNT);
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

int main()
{
    EcuM_Init();
    DeviceSupport_Init();
    /* To print the statements */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Executing Cdd_Adc_Example_DmaTransfer example\n");

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

    Configure_Cdd_Dma();

    /* Configure PWM instance */
    Cdd_Pwm_ConfigureHardware();

    /* Start DMA channel */
    Cdd_Dma_StartChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    /* Start the hardware group conversion.
     * Cdd_Adc_SetupResultBuffer is not required because DMA mode is enabled for the group.
     */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);

    /* Continue the data transfer for 5 seconds */
    while (Cdd_Adc_DmaIsrCount < (CDD_ADC_PWM_FREQUENCY * CDD_ADC_SECONDS))
    {
        McalLib_Delay(100U);
    }

    /* Disable hardware trigger after 1second */
    Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);

    /* Stop DMA channel */
    Cdd_Dma_StopChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    AppUtils_Printf("Total DMA interrupts generated are %d\n", Cdd_Adc_DmaIsrCount);
    AppUtils_Printf("All ADC conversion results have been transferred to the destination through DMA\n");
    AppUtils_Printf("For example,Cdd_Adc_Buffer[31] channel results are: \n");

    /* DeInitialize ADC */
    Cdd_Adc_DeInit();

    for (uint8 i = 0; i < 8; i++)
    {
        AppUtils_Printf("   Channel%d result stored in the buffer is %d\n", i, Cdd_Adc_Buffer[31U][i]);
    }

    AppUtils_Printf("Cdd_Adc_Example_DmaTransfer Example executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_DmaTransfer.c
 *********************************************************************************************************************/
