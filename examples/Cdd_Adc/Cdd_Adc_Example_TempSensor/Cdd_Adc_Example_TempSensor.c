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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Adc_Example_TempSensor.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc example source file. Channel ID 20 on ADCA and ADCC are both connected to
 *  the temperature sensor internally. The ADC conversion results can be passed to GetTemperatureC
 *  & GetTemperatureC APIs to get the temperature value in Celsius and Kelvin respectively.
 *
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins using Port_Init() to see the print statements on the console
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * Verification of Cdd_Adc temperature sensor values
 * Channel ID 20 on ADCA and ADCC are both connected to the temperature sensor internally.
 * The ADC conversion results can be passed to GetTemperatureC & GetTemperatureC APIs to get the
 * temperature value in Celsius and Kelvin respectively.
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
#include "Gpt.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define TIMER_CLK_FREQ_HZ (20000000U) /* Timer clock frequency in Hz */
#define GPT_TIME_US_1     (10000U)    /* 10 ms */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

#define GPT_COUNT_VALUE_1MS (TIMER_CLK_FREQ_HZ / 100000U) * GPT_TIME_US_1

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

uint16                 Gpt_IntCount = 0U;
Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[CDD_ADC_GROUP_CNT][10U], Cdd_Adc_ResultBuffer[CDD_ADC_GROUP_CNT][10U];
sint16                 Cdd_Adc_ADCA_TempC, Cdd_Adc_ADCC_TempC, Cdd_Adc_ADCA_TempK, Cdd_Adc_ADCC_TempK;

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* GPT timer channel 0 notification function */
void Gpt_Notify_Func_0(void)
{
    Gpt_IntCount++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Adc_Group1Notification()
{
    /* When the group status is IDLE the read the temperature sensor value in temperature */
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        /* Read group results */
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                          &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
        Cdd_Adc_ADCA_TempC = Cdd_Adc_GetTemperatureC(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
        Cdd_Adc_ADCA_TempK = Cdd_Adc_GetTemperatureK(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
    }
}

void Cdd_Adc_Group2Notification()
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        /* Read group results */
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                          &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
        Cdd_Adc_ADCC_TempC = Cdd_Adc_GetTemperatureC(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
        Cdd_Adc_ADCC_TempK = Cdd_Adc_GetTemperatureK(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
    }
}

int main()
{
    DeviceSupport_Init();
    EcuM_Init();
    /* To print the statements */
    AppUtils_Init(200000000U);
    AppUtils_Printf(" Executing Cdd_Adc_Example_TempSensor example\n");

    /* Set group result buffer */
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0,
                              &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0,
                              &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);

    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);

    /* Enable timer interrupt which is the trigger source for the hardware trigger group conversion
     */
    Gpt_EnableNotification(0U);
    /* Configure the timer in the continuous mode with 1millisecond as the time period */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Start the software group conversion */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    /* Start the hardware group conversion */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);

    /* Wait until both the group conversions are done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Print the temperature values that were calculated in the notification function */
    AppUtils_Printf("Temperature in Celsius converted by ADCA is %d\n", Cdd_Adc_ADCA_TempC);
    AppUtils_Printf("Temperature in Kelvin converted by ADCA is %d\n", Cdd_Adc_ADCA_TempK);
    AppUtils_Printf("Temperature in Celsius converted by ADCC is %d\n", Cdd_Adc_ADCC_TempC);
    AppUtils_Printf("Temperature in Kelvin converted by ADCC is %d\n", Cdd_Adc_ADCC_TempK);

    /* Stop the timer */
    Gpt_StopTimer(0U);
    /* Deinitialize GPT */
    Gpt_DeInit();

    /* DeInitialize ADC */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_TempSensor Example executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_TempSensor.c
 *********************************************************************************************************************/
