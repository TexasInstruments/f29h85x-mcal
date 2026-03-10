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
 *  File:       Cdd_Pwm_Example_DC_EventFilter.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates how digital compare event filter uses
 *                blanking window functionality to filter noise or unwanted pulses from the DC event signals.
 *                This example shows how digital compare can be configured with Cdd_Pwm driver APIs.
 *
 * Setup required for the example:
 * Connect the GPIO pins configured for EPWM to the logic analyzer to observe the PWM channel output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 *  - Initialize clock to 100 MHz using Mcu_Init()
 *  - Initialize pins in EPWM mode with Port_Init()
 *  - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw() to configure EPWM1 as follows
 *  - EPWM1 has DCAEVT1 as digital compare event and it forces the EPWM output to LOW
 *  - GPIO12 is used as the input to the INPUT XBAR INPUT2
 *  - INPUT2 (from INPUT XBAR) is used as the source for DCAEVT1
 *  - GPIO12's PULL-UP resistor is enabled. In order to test the trip, PULL this pin to GND using Dio_WriteChanel API
 *  - Because DCAEVT1 is filtered version of DCAEVT1, DCFILT signal uses the blanking window to ignore
 *    DCAEVT1 for the duration of DC Blanking window
 *
 *  - EPWM1 has DCBEVT1 as digital compare event and it forces the EPWM output to LOW
 *  - GPIO12 is used as the input to the INPUT XBAR INPUT2
 *  - INPUT2 (from INPUT XBAR) is used as the source for DCBEVT1
 *  - GPIO12's PULL-UP resistor is enabled. in order to test the trip, PULL this pin to GND using Dio_WriteChanel API
 *
 * DCAEVT1 & DCBEVT1 events are configured to force the outputs to LOW when the trip occurs on the TRIP2 input.
 * DCAEVT1 event is configured to trigger trip-zone interrupt and the notification count is incremented
 * inside the notification function.
 *
 * Trip input is pulled LOW which triggers LOW state on both the EPWM outputs and notifications are expected.
 * Disable trip-zone interrupts and notifications when the notification count reaches 3.
 * Set the trip input to HIGH
 * Clear all flags and disable DCBEVT1 as a trip source to test the blanking window functionality.
 * Blanking window is increased to test event filtering on output A.
 * Set DCAEVT1 as trip interrupt source and enable notification. Set the notification count to zero.
 * Trip input is pulled to LOW during the blanking window. Only EPWMB's waveform should be affected by this and
 * 0 notifications are expected.
 * Disable blanking window.
 * Trip input is again pulled to LOW, now both output waveforms should be affected by this and
 * notifications are expected.
 * Print notification counts in sequence to track the events.
 *
 *  EPWM waveform can be observed on the respective pins configured in EPWM mode
 * \b External \b Connections \n
 * - GPIO0 EPWM1A
 * - GPIO1 EPWM1B
 * - GPIO12 --> TRIPIN2. This pin is pulled LOW using DIO to trip the EPWM.
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

#define CDD_PWM_EVENT_COUNT ((uint8)1U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* Array to store the notification of the PWM instances */
uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0};

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

void Cdd_Pwm_ConfigureHw(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_Hw0TzNotification(uint16 TripZoneFlag)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;

    if (3U == Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0])
    {
        /* Disable notification & interrupt when the notification count reaches 3 */
        Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                           (CDD_PWM_TZ_INTERRUPT_DCAEVT1), FALSE);
        Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, FALSE);
    }
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM1 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_4,
                              CDD_PWM_HSCLOCK_DIVIDER_4);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 65535U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                   2000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, 0U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    /* Set action qualifier actions */
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    /* Set trip zone actions */
    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_ACTION_EVENT_DCAEVT1,
                              CDD_PWM_TZ_ACTION_LOW);
    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_ACTION_EVENT_DCBEVT1,
                              CDD_PWM_TZ_ACTION_LOW);

    /* Configure digital compare inputs */
    Cdd_Pwm_SelectDigitalCompareTripInput(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_DC_TRIP_TRIPIN2,
                                          CDD_PWM_DC_TYPE_DCAH);
    Cdd_Pwm_SelectDigitalCompareTripInput(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_DC_TRIP_TRIPIN2,
                                          CDD_PWM_DC_TYPE_DCAL);

    Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                    CDD_PWM_TZ_DC_OUTPUT_A1, CDD_PWM_TZ_EVENT_DCXH_LOW);
    Cdd_Pwm_SetDigitalCompareEventSyncMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                           CDD_PWM_DC_EVENT_1, CDD_PWM_DC_EVENT_INPUT_SYNCED);
    Cdd_Pwm_SetDigitalCompareEventSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                         CDD_PWM_DC_EVENT_1, CDD_PWM_DC_EVENT_SOURCE_FILT_SIGNAL);

    Cdd_Pwm_SelectDigitalCompareTripInput(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_DC_TRIP_TRIPIN2,
                                          CDD_PWM_DC_TYPE_DCBH);
    Cdd_Pwm_SelectDigitalCompareTripInput(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_DC_TRIP_TRIPIN2,
                                          CDD_PWM_DC_TYPE_DCBL);
    Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                    CDD_PWM_TZ_DC_OUTPUT_B1, CDD_PWM_TZ_EVENT_DCXH_LOW);
    Cdd_Pwm_SetDigitalCompareEventSyncMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                           CDD_PWM_DC_EVENT_1, CDD_PWM_DC_EVENT_INPUT_SYNCED);

    /* Configure balking window */
    Cdd_Pwm_SetDigitalCompareBlankingEvent(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                           CDD_PWM_DC_WINDOW_START_TBCTR_ZERO);
    Cdd_Pwm_SetDigitalCompareWindowLength(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 6000U);
    Cdd_Pwm_ConfigureDigitalCompareBlankingWindow(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    /* Configure trip-zone interrupt */
    Cdd_Pwm_ConfigureTripZoneSignals(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                     (CDD_PWM_TZ_SIGNAL_DCAEVT1 | CDD_PWM_TZ_SIGNAL_DCBEVT1), TRUE);
    Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                       (CDD_PWM_TZ_INTERRUPT_DCAEVT1), TRUE);
    Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_DC_EventFilter example\r\n");

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

    /* Wait for 1second to check the ideal operation of the EPWM */
    McalLib_Delay(50000000U);

    /* Pull the trip input to LOW */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);

    /* Wait until the notification is reached */
    while (3U != Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0])
    {
        McalLib_Delay(50U);
    }

    AppUtils_Printf("Notification count is %d\r\n",
                    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]);

    /* Set the channel state to HIGH */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);

    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_DCAEVT1);
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_DCBEVT1);
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_OST);

    /* Disable DCBEVT1 signal as the trip signal source */
    Cdd_Pwm_ConfigureTripZoneSignals(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_SIGNAL_DCBEVT1,
                                     FALSE);

    McalLib_Delay(50000U);

    /* Increase the blanking window */
    Cdd_Pwm_SetDigitalCompareWindowLength(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 65534U);

    /* Configure trip zone interrupt source because it is disabled in the notification function */
    Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                       (CDD_PWM_TZ_INTERRUPT_DCAEVT1), TRUE);
    Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] = 0U;

    /* Wait until the new period starts */
    while (Cdd_Pwm_GetTimeBaseCounterValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0) != 0U)
    {
    }

    /* Pull the trip input to LOW */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);

    McalLib_Delay(25U);

    /* Pull back the trip input to HIGH after leaving the trip for atleast 3*TBCLK cycles */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);

    /* Wait for 1second to check for notification */
    McalLib_Delay(50000000U);

    AppUtils_Printf("Notification count after increasing the blanking window is %d\r\n",
                    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]);

    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] = 0U;

    /* Now disable compare banking window */
    Cdd_Pwm_ConfigureDigitalCompareBlankingWindow(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, FALSE);

    while (Cdd_Pwm_GetTimeBaseCounterValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0) != 0U)
    {
    }

    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);

    McalLib_Delay(25U);

    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);

    McalLib_Delay(50000000U); /* Wait for 1sec */

    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_DCAEVT1);
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_DCBEVT1);
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_FLAG_OST);

    AppUtils_Printf("Notification count after disabling the blanking window is %d\r\n",
                    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]);

    /* Resume normal operation for 1 second */
    McalLib_Delay(5000000U);

    AppUtils_Printf("Generated waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_DC_EventFilter example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_DC_EventFilter.c
 *********************************************************************************************************************/
