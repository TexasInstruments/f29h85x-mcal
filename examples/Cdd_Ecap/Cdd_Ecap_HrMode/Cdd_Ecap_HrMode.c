/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Ecap_HrMode.c
 *  Generator:  Code generation tool (if any)
 *
 * Description: This example configures ECAP in HR mode and measures the high time and period time. This example
 * demonstratesthe HR mode for precise signal measurement. ECAP is configured on GPIO1 and PWM signals are coming on
 * GPIO0. InputXbar 7 is used for ECAP. ECAP is configured in signal measurement mode. This example calculates the
 * high time and period of the given signal. A PWM signal of fixed duty and time period is used for this purpose.
 *
 * Configuration:
 * PWM period configuration - 500 SYSCLK cycles
 * PWM high time configuration - 125 SYSCLK cycles(25% duty)
 * ECAP is configured in signal measurement mode
 * scaleFactor is the conversion factor
 *
 * External connections:
 * Connect GPIO0 and GPIO1 using a jumper wire to see the results
 *
 * Additional Note:
 * For deviation in HRCAP measurement refer to the datasheet of F29H85x. Link is also attached below
 * (https://www.ti.com/lit/ds/symlink/f29h859tu-q1.pdf). The "CDD_ECAP_PWM_MARGIN" is chosen according to that.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Ecap.h"
#include "Port.h"
#include "Mcu.h"
#include "Cdd_Pwm.h"
#include <math.h>

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_NUMBER_OF_ITERATIONS (5000000U)
#define CDD_ECAP_EXAMPLE_DELAY_TIME   (12000U)

#define CDD_ECAP_PWM_PERIOD_CONFIGURED (500.0)  // PWM period configued in the config tool in sysclk cycles
#define CDD_ECAP_PWM_PERIOD_TIME       ((CDD_ECAP_PWM_PERIOD_CONFIGURED + 1) * 2)
#define CDD_ECAP_PWM_HIGH_TIME         (CDD_ECAP_PWM_PERIOD_CONFIGURED / 4)  // Duty value configured in the example
#define CDD_ECAP_PWM_MARGIN            (0.540 + 0.3 * 4.7)  // Margin of error in nanoseconds ((0.540 + (0.3*4.7) ns))

#define CDD_ECAP_SYSCLK_TICK (5U)  // Corrosponds to 5ns for 200MHz SYSCLK
/*******************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
Cdd_Ecap_ValueType          highTime, periodTime;
Cdd_Ecap_DutyCycleType      dutyValue;
Cdd_Ecap_ChannelHrScaleType highTimeHr, periodTimeHr, scaleFactor;
Cdd_Ecap_ChannelHrScaleType highTimeHrActual, periodTimeHrActual;
/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
/** \brief Brief variable description */

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief Brief function description
 *
 * Extended function description
 *
 * \param[in] input_parameter_name Input Parameter description
 * \param[out] output_parameter_name Output Parameter description
 * \pre Preconditions
 * \post Postconditions
 * \return Return general description
 * \retval Description of specific return values (for example enum values)
 *
 *********************************************************************************************************************/

void CddEcap_DemoSignalMeasurementModeHighResolution();

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
int main(void)
{
    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U);  // Init App utils to enable prints

    AppUtils_Printf("Cdd_Ecap_HrMode Example Application - STARTS!\r\n");

    /*  Get version Info */
#if (CDD_ECAP_GET_VERSION_INFO_API == STD_ON)
    Std_VersionInfoType versioninfo;

    /* Get and print version */
    Cdd_Ecap_GetVersionInfo(&versioninfo);
    AppUtils_Printf(" \r\n");
    AppUtils_Printf(" Cdd Ecap MCAL Version Info\r\n");
    AppUtils_Printf(" --------------------------\r\n");
    AppUtils_Printf(" Vendor ID           : %d\r\n", versioninfo.vendorID);
    AppUtils_Printf(" Module ID           : %d\r\n", versioninfo.moduleID);
    AppUtils_Printf(" SW Major Version    : %d\r\n", versioninfo.sw_major_version);
    AppUtils_Printf(" SW Minor Version    : %d\r\n", versioninfo.sw_minor_version);
    AppUtils_Printf(" SW Patch Version    : %d\r\n", versioninfo.sw_patch_version);
    AppUtils_Printf(" \r\n");
#endif /* #if (CddEcap_VERSION_INFO_API == STD_ON) */

    /* Signal Measurement */
    CddEcap_DemoSignalMeasurementModeHighResolution();

    AppUtils_Printf("Cdd_Ecap_HrMode Example Application - ENDS!\r\n");

    Cdd_Ecap_DeInit();

    return 0;
}

/**
 * \brief This function demonstrates the signal measurement mode of Cdd_Ecap in HR mode
 *
 * The function measures the signal on channel 0 and prints the high time and
 * period of the signal.
 *
 * \return None
 */
void CddEcap_DemoSignalMeasurementModeHighResolution()
{
    uint32 i = 0;  // loop counter

    AppUtils_Printf("Signal Measurement Start on Channel %d ...\r\n", CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    Cdd_Ecap_StartSignalMeasurement(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    // Checking if the scalefactor calibration is done(Initial calibration)
    while (Cdd_Ecap_GetHrScaleFactor(CddEcapConf_CddEcapChannel_CddEcapChannel_0) == CDD_ECAP_SF_NOTREADY)
        ;

    // Loop to measure the signal for 5000000 iterations
    while (i < CDD_ECAP_NUMBER_OF_ITERATIONS)
    {
        // Check if the signal is active
        if (CDD_ECAP_ACTIVE == Cdd_Ecap_GetInputState(CddEcapConf_CddEcapChannel_CddEcapChannel_0))
        {
            // Get the duty cycle values
            Cdd_Ecap_GetDutyCycleValues(CddEcapConf_CddEcapChannel_CddEcapChannel_0, &dutyValue);
            // Get the time elapsed
            Cdd_Ecap_GetTimeElapsed(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

            highTime   = dutyValue.ActiveTime;  // Store the high time
            periodTime = dutyValue.PeriodTime;  // Store the period

            scaleFactor = Cdd_Ecap_GetHrScaleFactor(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

            highTimeHr =
                Cdd_Ecap_ConvertHrTimeStampToEcapTimeStamp(CddEcapConf_CddEcapChannel_CddEcapChannel_0, highTime);
            periodTimeHr =
                Cdd_Ecap_ConvertHrTimeStampToEcapTimeStamp(CddEcapConf_CddEcapChannel_CddEcapChannel_0, periodTime);
        }

        ++i;  // Increment the loop counter
    }

    Cdd_Ecap_StopSignalMeasurement(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    // Actual time in nano-seconds
    highTimeHrActual   = (highTimeHr)*CDD_ECAP_SYSCLK_TICK;
    periodTimeHrActual = (periodTimeHr)*CDD_ECAP_SYSCLK_TICK;

    if ((fabs(periodTimeHrActual - (CDD_ECAP_PWM_PERIOD_TIME * CDD_ECAP_SYSCLK_TICK)) > CDD_ECAP_PWM_MARGIN))
    {
        AppUtils_Printf("Example failed!!!\r\n");
    }
    else
    {
        AppUtils_Printf("Example passed!!!\r\n");
    }

    // Print the high time and period
    AppUtils_Printf("High time of the signal in nano-secs is: %f\r\n", highTimeHrActual);
    AppUtils_Printf("Period of the signal in nano-secs is: %f\r\n", periodTimeHrActual);
    AppUtils_Printf(" \r\n");

    return;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_HrMode.c
 *********************************************************************************************************************/
