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
 *  File:       Cdd_Pwm_Example_XCmp_MultipleEdges.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates multiple edges generation in a single period
 *                  using XCMP feature.
 *
 * Setup required for the example:
 * Connect the GPIO pins configured for EPWM to the logic analyzer to observe the PWM channel output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 * - Initialize clock to 100 MHz using Mcu_Init()
 * - Initialize pins in EPWM mode with Port_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw() as follows
 *  - EPWM1A is allocated all XCMP1-8 registers. EPWM1B has no output.
 *      - No Shadow registers used
 *  - EPWM2A is allocated XCMP1-4 and EPWM2B is allocated XCMP5-8 registers.
 *      - Configured in LOAD ONCE mode and the XCMP values are updated every period with a new shadow buffer set
 *      - Shadow level is set to 3
 *  - EPWM3A is allocated XCMP1-4 and EPWM2B is allocated XCMP5-8 registers.
 *      - Configured in LOAD MULTIPLE mode. Repeat count is configured for SHD buffer set 3 & 2.
 *        The SHDBUF ptr is set to 3 again after 16 periods.
 *      - Shadow level is set to 3
 *
 * EnableXLoad trigger the XCMP mode
 * Print the notification count for each EPWM instance
 * Track the changes in the waveform with a logic analyzer
 *
 * EPWM waveform can be observed on the respective pins configured in EPWM mode
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
#include "Cdd_Pwm_Cfg.h"
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Pwm.h"
#include "Port.h"
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_EVENT_COUNT ((uint8)1U)
#define CDD_PWM_SHD_LEVEL   ((uint8)3U)

#define CDD_PWM_NOTIFICATION_COUNT (2000U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* Array to store the notification of the PWM instances */
uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0};

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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_HwUnit0Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_HwUnit1Notification()
{
    /* Reapeat the shadow level */
    if (0U == (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] % CDD_PWM_SHD_LEVEL))
    {
        Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_TWO);
        /* Enable Start Load */
        Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    }
    else if (1U == (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] % CDD_PWM_SHD_LEVEL))
    {
        Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_ONE);
        /* Enable Start Load */
        Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    }
    else if (2U == (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] % CDD_PWM_SHD_LEVEL))
    {
        Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE);
        /* Enable Start Load */
        Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    }
    else
    {
        /* No action */
    }

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;

    if (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] == CDD_PWM_NOTIFICATION_COUNT)
    {
        Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
        Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, FALSE);
    }
}

void Cdd_Pwm_HwUnit2Notification()
{
    /* Reapeat the shadow level */
    /* Enable start load */

    if (0U == Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2] % 16U)
    {
        Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
    }

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;

    if (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2] == CDD_PWM_NOTIFICATION_COUNT)
    {
        Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
        Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, FALSE);
    }
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM1 instance in LOAD ONCE XCMP mode with split disabled */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 2249U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_ConfigureSyncOutPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                        CDD_PWM_SYNC_OUT_PULSE_ON_ALL, TRUE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_ConfigureXCmpMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    Cdd_Pwm_AllocAXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_8_CMPA);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP1_ACTIVE, 250U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP2_ACTIVE, 500U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP3_ACTIVE, 750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP4_ACTIVE, 1000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP5_ACTIVE, 1250U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP6_ACTIVE, 1500U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP7_ACTIVE, 1750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP8_ACTIVE, 2000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XTBPRD_ACTIVE, 2249U);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    /* Configure EPWM2 instance in LOAD MULTIPLE XCMP mode with split and shadow level enabled(repeat buffer) */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 2249U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_ConfigureXCmpMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_ConfigureSplitXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_SetXCmpLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_LOADONCE);
    Cdd_Pwm_SetXCmpShadowLevel(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOWLEVEL_3);
    Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                        CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE);

    Cdd_Pwm_AllocAXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_4_CMPA);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP1_ACTIVE, 450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP2_ACTIVE, 900U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP3_ACTIVE, 1350U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP4_ACTIVE, 1800U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP1_SHADOW3, 550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP2_SHADOW3, 1000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP3_SHADOW3, 1450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP4_SHADOW3, 1900U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP1_SHADOW2, 650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP2_SHADOW2, 1100U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP3_SHADOW2, 1550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP4_SHADOW2, 2000U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP1_SHADOW1, 750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP2_SHADOW1, 1200U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP3_SHADOW1, 1650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP4_SHADOW1, 2100U);

    /* Configure CMP B COMPARE  */
    Cdd_Pwm_AllocBXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_8_CMPB);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP5_ACTIVE, 750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP6_ACTIVE, 1200U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP7_ACTIVE, 1650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP8_ACTIVE, 2100U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP5_SHADOW3, 650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP6_SHADOW3, 1100U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP7_SHADOW3, 1550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP8_SHADOW3, 2000U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP5_SHADOW2, 550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP6_SHADOW2, 1000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP7_SHADOW2, 1450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP8_SHADOW2, 1900U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP5_SHADOW1, 450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP6_SHADOW1, 900U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP7_SHADOW1, 1350U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP8_SHADOW1, 1800U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XTBPRD_ACTIVE, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XTBPRD_SHADOW1, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XTBPRD_SHADOW2, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XTBPRD_SHADOW3, 2249U);

    /* XCMP Action Qualifier actions for COMPARE A */
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    /* XCMP Action Qualifier actions for COMPARE B */

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    /* Action qualifier action for COMPARE A & B */
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_INT_TBCTR_ZERO);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_EVENT_COUNT);

    /* Configure EPWM3 instance in LOAD MULTIPLE XCMP mode with split and shadow level enabled(repeat buffer) */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 2249U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 0U);
    Cdd_Pwm_SetSyncInPulseSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_A, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_B, 100U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_ConfigureXCmpMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);
    Cdd_Pwm_ConfigureSplitXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);
    Cdd_Pwm_SetXCmpLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_LOADMULTIPLE);
    Cdd_Pwm_SetXCmpShadowLevel(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOWLEVEL_3);

    Cdd_Pwm_SetXCmpShadowRepeatBufxCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2, 5U);
    Cdd_Pwm_SetXCmpShadowRepeatBufxCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3, 7U);

    Cdd_Pwm_AllocAXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_4_CMPA);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP1_ACTIVE, 450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP2_ACTIVE, 900U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP3_ACTIVE, 1350U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP4_ACTIVE, 1800U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP1_SHADOW3, 550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP2_SHADOW3, 1000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP3_SHADOW3, 1450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP4_SHADOW3, 1900U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP1_SHADOW2, 650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP2_SHADOW2, 1100U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP3_SHADOW2, 1550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP4_SHADOW2, 2000U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP1_SHADOW1, 750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP2_SHADOW1, 1200U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP3_SHADOW1, 1650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP4_SHADOW1, 2100U);

    /* Configure CMP B COMPARE  */
    Cdd_Pwm_AllocBXCmp(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_8_CMPB);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP5_ACTIVE, 750U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP6_ACTIVE, 1200U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP7_ACTIVE, 1650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP8_ACTIVE, 2100U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP5_SHADOW3, 650U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP6_SHADOW3, 1100U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP7_SHADOW3, 1550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP8_SHADOW3, 2000U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP5_SHADOW2, 550U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP6_SHADOW2, 1000U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP7_SHADOW2, 1450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP8_SHADOW2, 1900U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP5_SHADOW1, 450U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP6_SHADOW1, 900U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP7_SHADOW1, 1350U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP8_SHADOW1, 1800U);

    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XTBPRD_ACTIVE, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XTBPRD_SHADOW1, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XTBPRD_SHADOW2, 2249U);
    Cdd_Pwm_SetXCmpRegValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XTBPRD_SHADOW3, 2249U);

    /* XCMP Action Qualifier actions for COMPARE A */

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4);

    /* XCMP Action Qualifier actions for COMPARE B */
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_ACTIVE,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW1,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW2,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7);
    Cdd_Pwm_SetXCmpActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_XCMP_SHADOW3,
                                         CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8);

    /* Action qualifier action for COMPARE A & B */
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);
    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_INT_TBCTR_ZERO);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_EVENT_COUNT);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_XCmp_MultipleEdges example\r\n");

    Cdd_Pwm_ConfigureHw();

    AppUtils_Printf("EPWM1 has split XCMP disabled; therefore Channel B will not generate any waveform \r\n");
    AppUtils_Printf("EPWM2 is set to LOAD ONCE XCMP mode \r\n");
    AppUtils_Printf("EPWM3 is set to LOAD MULTIPLE XCMP mode\r\n");

    AppUtils_Printf("Enable XCMP load for all EPWM instances\r\n");

    Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    Cdd_Pwm_EnableXLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);

    while (!(
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2] == CDD_PWM_NOTIFICATION_COUNT) &&
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] == CDD_PWM_NOTIFICATION_COUNT)))
    {
        McalLib_Delay(10U);
    }

    AppUtils_Printf("Number of interrupts detected for EPWM2 are %d\r\n",
                    (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]));
    AppUtils_Printf("Number of interrupts detected for EPWM3 are %d\r\n",
                    (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]));

    AppUtils_Printf("Waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_XCmp_MultipleEdges example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_XCmp_MultipleEdges.c
 *********************************************************************************************************************/
