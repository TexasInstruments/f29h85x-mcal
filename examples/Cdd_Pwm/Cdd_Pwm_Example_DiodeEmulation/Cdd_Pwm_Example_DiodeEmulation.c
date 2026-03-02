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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Pwm_Example_DiodeEmulation.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates independent waveform
 *  generation on two output channels of a PWM instance using Cdd_Pwm driver.50Hz PWM waveforms
 *  with different duty cycles can be observed on the PWM1 channel output waveforms. 1KHz
 *  waveforms can be observed with the PWM2 channel output waveforms.
 *
 * Setup required for the example:
 * Connect the GPIO pins to the logic analyzer to observe the output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 * - Initialize clock to 100 MHz using Mcu_Init()
 * - Initialize pins in EPWM mode with Port_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * - Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw() to configure EPWM instances as follows
 *
 * Diode Emulation configuration:
 *  - For EPWM1 A & B outputs the AQ actions are configured to LOW & HIGH respectively.
 *      During DE(diode emulation) mode, EPWM outputs are set to opposite of the configured polarities.
 *      EPWM1A's output is set to HIGH and EPWM1B's set to LOW during DE mode
 *
 *  - For EPWM2 A & B outputs the AQ actions are configured to HIGH & LOW respectively.
 *      During DE(diode emulation) mode, EPWM outputs are set to opposite of the configured polarities.
 *      EPWM2A's output is set to LOW and EPWM2B's set to HIGH during DE mode
 *
 *  - EPWM1 & EPWM2 are configured in one-shot diode emulation mode.
 *  - EPWM3 is configured same as EPWM1 but in CBC(cycle-by-cycle) DE mode
 *     In the Cycle-by-cycle clear mode, trip condition is evaluated on every EPWMxSYNCPER and if the trip
 *     condition is not present, then DEACTIVE flag is cleared (exiting of DE mode).
 *
 * Force diode emulation active flag for both EPWM1 & EPWM2 and wait until EPWM1 & EPWM2 outputs are changed to the
 * configured state (EPWM1A to HIGH, EPWM1B to LOW, EPWM2A to LOW & EPWM2B to HIGH).
 * Wait until the configured output states are achieved.
 * Clear active diode emulation flags for both EPWM1 & EPWM2 instances to exit DE mode.
 * Force diode emulation active flag for EPWM1
 * Wait until EPWM1 enters the DE mode.
 * The execution will stay in the loop if the expected condition is not achieved(Only EPWM1 should enter DE mode).
 * Clear active diode emulation flags for EPWM1 to exit DE mode.
 * Force diode emulation active flag for EPWM3
 * Wait until EPWM3 outputs are changed to the configured state (EPWM3A to HIGH & EPWM3B to LOW).
 * Wait until the CBC clear the active flag and the EPWM instance exits the DE mode.
 *
 *  EPWM waveform and DE intput trip signals can be monitored on the respective pins configured
 * \b External \b Connections \n
 * - GPIO0 EPWM1A
 * - GPIO1 EPWM1B
 * - GPIO2 EPWM2A
 * - GPIO3 EPWM2B
 * - GPIO4 EPWM3A
 * - GPIO5 EPWM3B
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
#include "Cdd_Pwm.h"
#include "Port.h"
#include "Mcu.h"
#include "Dio.h"

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

/* Array to store the notification of the PWM instances */
uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0U};

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
#endif

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

/* Function to configure EPWM hardware */
void Cdd_Pwm_ConfigureHw(void);

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_HwUnit0Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_HwUnit1Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;
}

void Cdd_Pwm_HwUnit2Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;
}

void Cdd_Pwm_ConfigureHw()
{
    /* EPWM1 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_128,
                              CDD_PWM_HSCLOCK_DIVIDER_14);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 65535U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_ConfigureSyncOutPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                        CDD_PWM_SYNC_OUT_PULSE_ON_ALL, TRUE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_ConfigureDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);
    Cdd_Pwm_NoBypassDiodeEmulationLogic(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_SetDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_DIODE_EMULATION_OST);
    Cdd_Pwm_SetDiodeEmulationReentryDelay(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                  CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT1);
    Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                   CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT3);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                           CDD_PWM_DE_SRC_TRIPL);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                          CDD_PWM_DE_HIGH);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                           CDD_PWM_DE_SRC_TRIPH);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                          CDD_PWM_DE_LOW);

    /* EPWM2 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_128,
                              CDD_PWM_HSCLOCK_DIVIDER_14);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 65535U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_ConfigureDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_NoBypassDiodeEmulationLogic(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    Cdd_Pwm_SetDiodeEmulationReentryDelay(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 255U);
    Cdd_Pwm_SetDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_DIODE_EMULATION_OST);
    Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                                  CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT1);
    Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                                   CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT3);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                           CDD_PWM_DE_SRC_TRIPL);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                          CDD_PWM_DE_LOW);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                           CDD_PWM_DE_SRC_TRIPH);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                          CDD_PWM_DE_HIGH);

    /* EPWM3 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_CLOCK_DIVIDER_128,
                              CDD_PWM_HSCLOCK_DIVIDER_14);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 65535U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_ConfigureSyncOutPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                        CDD_PWM_SYNC_OUT_PULSE_ON_ALL, TRUE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_A,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_B,
                                   30000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_ConfigureDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);
    Cdd_Pwm_NoBypassDiodeEmulationLogic(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
    Cdd_Pwm_SetDiodeEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_DIODE_EMULATION_CBC);
    Cdd_Pwm_SetDiodeEmulationReentryDelay(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 0U);
    Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                                  CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT2);
    Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                                   CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT3);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                           CDD_PWM_DE_SRC_TRIPL);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                          CDD_PWM_DE_HIGH);
    Cdd_Pwm_SelectDiodeEmulationTripSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                           CDD_PWM_DE_SRC_TRIPH);
    Cdd_Pwm_SelectDiodeEmulationPwmSignal(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                          CDD_PWM_DE_LOW);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_DiodeEmulation example\r\n");

    /* Get version Info */
#if (STD_ON == CDD_ADC_VERSION_INFO_API)
    Cdd_Adc_GetVersionInfo(&Cdd_Adc_VersionInfo);
    AppUtils_Printf("CDD_ADC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Adc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Adc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Adc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Adc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Adc_VersionInfo.sw_patch_version);
#endif

    /* Configure EPWM hardware instances */
    Cdd_Pwm_ConfigureHw();

    McalLib_Delay(50000000U);

    AppUtils_Printf("Force diode emulation active flags for EPWM1 & EPWM2 instances\r\n");

    /* Now force the active flag to high and the EPWM instances should enter DE mode */
    Cdd_Pwm_ForceDiodeEmulationActive(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_ForceDiodeEmulationActive(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);

    /* Check if the states are changing */
    while (!((STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_DioChannel_0)) &&
             (STD_LOW == Dio_ReadChannel(DioConf_DioChannel_DioChannel_1))))
    {
    }

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;

    AppUtils_Printf("EPWM1A output is HIGH\r\n");
    AppUtils_Printf("EPWM2A output is LOW\r\n");

    /* Clear diode emulation active flags */
    Cdd_Pwm_ClearDiodeEmulationActiveFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_ClearDiodeEmulationActiveFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);

    AppUtils_Printf("Cleared diode emulation active flags for EPWM1 & EPWM2 instances\r\n");

    AppUtils_Printf("Force diode emulation active flags for EPWM1 instance\r\n");

    /* Force the active flag for EPWM1 and only EPWM1 instances should enter DE mode */
    Cdd_Pwm_ForceDiodeEmulationActive(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);

    /* Read the Dio channel levels/states */
    while (!((STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_DioChannel_1)) &&
             (STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_DioChannel_0))))
    {
    }

    AppUtils_Printf("EPWM1A output is HIGH\r\n");
    AppUtils_Printf("EPWM2A output is HIGH\r\n");

    /* Clear diode emulation active flag */
    Cdd_Pwm_ClearDiodeEmulationActiveFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);

    AppUtils_Printf("Cleared diode emulation active flags for EPWM1 instance\r\n");

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;

    AppUtils_Printf("Force diode emulation active flags for EPWM3 instance\r\n");
    /* Force the active flag for EPWM3 and only EPWM3 instances should enter DE mode */
    Cdd_Pwm_ForceDiodeEmulationActive(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);

    McalLib_Delay(500U);

    while (STD_LOW == Dio_ReadChannel(DioConf_DioChannel_DioChannel_2))
    {
    }

    AppUtils_Printf("EPWM3A output is HIGH\r\n");

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;

    while (STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_DioChannel_2))
    {
    }

    AppUtils_Printf("Diode emulation active flag has been cleared by hardware\r\n");

    McalLib_Delay(50000000);

    AppUtils_Printf("Generated waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_DiodeEmulation example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_DiodeEmulation.c
 *********************************************************************************************************************/
