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
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins using Port_Init() to see the print statements on the console
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * AppUtils_Init() to initailize App Utils
 * Configure_Rtdma() to initialize DMA
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
#include "Rtdma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_EVENT_COUNT (1U)

#define RTDMA1CH1_SRC_BURSTSTEP  2U
#define RTDMA1CH1_DEST_BURSTSTEP 2U
#define RTDMA1CH1_BURSTSIZE      16U

#define RTDMA1CH1_SRC_TRANSFERSTEP  2U
#define RTDMA1CH1_DEST_TRANSFERSTEP 2U
#define RTDMA1CH1_TRANSFERSIZE      1U

#define RTDMA1CH1_SRC_WRAPSTEP  (0U)
#define RTDMA1CH1_DEST_WRAPSTEP (2U)

#define RTDMA1CH1_SRC_WRAPSIZE  (1U)
#define RTDMA1CH1_DEST_WRAPSIZE (1U)

#define DATASIZE 16U

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
void Configure_Rtdma();

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* Rtdma 1 channel ISR */
MCAL_LIB_INT_ISR(Rtdma1_Isr)
{
    /* DMA ISR */
    Cdd_Adc_DmaSampleCount++;
    Cdd_Adc_DmaIsrCount++;

    if (Cdd_Adc_DmaSampleCount == CDD_ADC_STREAMING_SAMPLE_COUNT)
    {
        /* Set Dma Isr count to 0 to count the next sampling */
        Cdd_Adc_DmaSampleCount = 0U;
    }

    /* Update the source and destination address of the RTDMA channel */
    DMA_configAddresses(RTDMA1CH1_BASE, (Cdd_Adc_ValueGroupType *)(&Cdd_Adc_Buffer[Cdd_Adc_DmaSampleCount][0U]),
                        (Cdd_Adc_ValueGroupType *)ADCARESULT_BASE);
}

void Configure_Rtdma()
{
    /* Perform a hard reset on DMA */
    DMA_initController(RTDMA1_BASE);

    /* Allow DMA to run free on emulation suspend */
    DMA_setEmulationMode(RTDMA1_BASE, DMA_EMULATION_FREE_RUN);

    DMA_setPriorityMode(RTDMA1_BASE, DMA_PRIORITY_SOFTWARE_CONFIG);

    /* Disabling MPU region */
    DMA_disableMPU(RTDMA1_MPU_BASE);

    /* Set channel priority */
    DMA_setChannelPriority(RTDMA1_BASE, DMA_CH1, DMA_CHPRIORITY1);

    /* DMA channel 1 set up for ADCA */
    DMA_configAddresses(RTDMA1CH1_BASE, (Cdd_Adc_ValueGroupType *)&Cdd_Adc_Buffer[0U][0U],
                        (Cdd_Adc_ValueGroupType *)ADCARESULT_BASE);

    /* Perform enough bursts(16 bytes) to fill the results buffer.
     * Data will be transferred 16 bits at a time.
     */
    DMA_configBurst(RTDMA1CH1_BASE, RTDMA1CH1_BURSTSIZE, RTDMA1CH1_SRC_BURSTSTEP, RTDMA1CH1_DEST_BURSTSTEP);

    /* Configure transfer step */
    DMA_configTransfer(RTDMA1CH1_BASE, RTDMA1CH1_TRANSFERSIZE, RTDMA1CH1_SRC_TRANSFERSTEP, RTDMA1CH1_DEST_TRANSFERSTEP);

    /* When one-shot is disabled and continuous mode is enabled:
     * Transfer one burst upon one trigger and keep the channel enabled, when next trigger comes,
     * next burst will be transferred
     */
    DMA_configMode(RTDMA1CH1_BASE, DMA_TRIGGER_ADCA1,
                   (DMA_CFG_ONESHOT_DISABLE | DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT));

    /* Enable the trigger to DMA */
    DMA_enableTrigger(RTDMA1CH1_BASE);
    DMA_disableOverrunInterrupt(RTDMA1CH1_BASE);
    DMA_setInterruptMode(RTDMA1CH1_BASE, DMA_INT_AT_END);
    DMA_enableInterrupt(RTDMA1CH1_BASE);
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
    DeviceSupport_Init();
    EcuM_Init();
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

    /* Configure DMA */
    Configure_Rtdma();

    /* Configure PWM instance */
    Cdd_Pwm_ConfigureHardware();

    /* Start DMA channel */
    DMA_startChannel(RTDMA1CH1_BASE);

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
    DMA_stopChannel(RTDMA1CH1_BASE);

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
