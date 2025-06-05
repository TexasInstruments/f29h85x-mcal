/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Ecap_Capture_Signal.c
 *  Generator:  Code generation tool (if any)
 *
 * Description: This example configures 4 ECAP channels in different modes and captures a PWM
 * signal. Channel0 -> Signal Measurement Mode. Channel1 -> Time Stamp Mode. Channel2 -> Edge
 * Counter Mode. Channel3 -> Signal Edge Detect. Channel1, 2 and 3 are configured in rising edge
 * mode. Input Xbar 7 is being used for all the ECAP channels and PWM signal is on the GPIO40.
 * Notification function is also being used for Channel1 and 3.
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

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_EXAMPLE_DELAY_TIME    (100000U)
#define CDD_ECAP_TIMESTAMP_BUFFER_SIZE (20U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
Cdd_Ecap_ValueType     buffer[CDD_ECAP_TIMESTAMP_BUFFER_SIZE];
Cdd_Ecap_ValueType*    bufferPtr = buffer;
uint32                 highTime, periodTime, SignalActive;
Cdd_Ecap_DutyCycleType dutyValue;
uint32                 GCddEcapTimeCnt, GCddEcapSignalCnt;
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

void Cdd_Ecap_TimeStampNotify();
void Cdd_Ecap_SignalNotify();

void CddEcap_DemoSignalMeasurementMode();
void CddEcap_DemoTimestampingMode();
void CddEcap_DemoEdgeCountingMode();
void CddEcap_DemoEdgeDetectionMode();

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

    AppUtils_Printf("Cdd_Ecap_Capture_Signal Example Application - STARTS!\r\n");

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
    CddEcap_DemoSignalMeasurementMode();

    /* Timestamping */
    CddEcap_DemoTimestampingMode();

    /* Edge Counting */
    CddEcap_DemoEdgeCountingMode();

    /* Edge Detection */
    CddEcap_DemoEdgeDetectionMode();

    Cdd_Ecap_DeInit();

    AppUtils_Printf("Cdd_Ecap_Capture_Signal Example Application - ENDS!\r\n");

    return 0;
}

/**
 * \brief This function demonstrates the signal measurement mode of Cdd_Ecap
 *
 * The function measures the signal on channel 0 and prints the high time and
 * period of the signal.
 *
 * \return None
 */
void CddEcap_DemoSignalMeasurementMode()
{
    uint32 i = 0;  // loop counter

    AppUtils_Printf(" Signal Measurement Start on Channel %d ...\r\n", CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    Cdd_Ecap_StartSignalMeasurement(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    // Loop to measure the signal for 1000 iterations
    while (i <= 1000)
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
        }

        ++i;  // Increment the loop counter
    }

    // Print the high time and period
    AppUtils_Printf("High time of the signal is: %d\r\n", highTime);
    AppUtils_Printf("Period of the signal is: %d\r\n", periodTime);
    AppUtils_Printf(" \r\n");

    return;
}

/**
 * @brief This function demonstrates the timestamping feature of Cdd_Ecap
 *
 * This function measures the signal on channel 1 and stores the timestamps in a
 * buffer. The timestamps are then printed.
 *
 * @return None
 */
void CddEcap_DemoTimestampingMode()
{
    uint32 i = 0;

    /* Print the start of the demo */
    AppUtils_Printf(" Timestamping Start on Channel %d...\r\n", CddEcapConf_CddEcapChannel_CddEcapChannel_1);

    /* Start the timestamping on channel 1 */
    Cdd_Ecap_StartTimestamp(CddEcapConf_CddEcapChannel_CddEcapChannel_1, bufferPtr, CDD_ECAP_TIMESTAMP_BUFFER_SIZE, 0);

    /* Enable notification for channel 1 */
    Cdd_Ecap_EnableNotification(CddEcapConf_CddEcapChannel_CddEcapChannel_1);

    /* Delay for the example */
    McalLib_Delay(CDD_ECAP_EXAMPLE_DELAY_TIME);

    /* Stop timestamping on channel 1 */
    Cdd_Ecap_StopTimestamp(CddEcapConf_CddEcapChannel_CddEcapChannel_1);

    /* Print the timestamps in the buffer */
    AppUtils_Printf("Timestamps in Buffer \r\n");
    for (i = 0; i < CDD_ECAP_TIMESTAMP_BUFFER_SIZE; i++)
    {
        /* Print the timestamps in hex and decimal */
        AppUtils_Printf("buffer[%d]: 0x%04x (%u) \r\n", i, (uint16)bufferPtr[i], (uint16)bufferPtr[i]);
    }
    AppUtils_Printf(" \r\n");

    return;
}

/**
 * \brief This function demonstrates the edge counting mode of Cdd_Ecap.
 *
 * The function enables edge counting on channel 2, delays for the demo,
 * disables edge counting, and prints the edge count.
 *
 * \return None
 */
void CddEcap_DemoEdgeCountingMode()
{
    AppUtils_Printf(" Edge Counting Start on Channel %d...\r\n", CddEcapConf_CddEcapChannel_CddEcapChannel_2);

    // Initialize edge count
    Cdd_Ecap_EdgeNumberType edgeCount = 0;

    // Enable edge counting on channel 2
    Cdd_Ecap_EnableEdgeCount(CddEcapConf_CddEcapChannel_CddEcapChannel_2);

    // Delay for the demo
    McalLib_Delay(CDD_ECAP_EXAMPLE_DELAY_TIME);

    // Disable edge counting on channel 2
    Cdd_Ecap_DisableEdgeCount(CddEcapConf_CddEcapChannel_CddEcapChannel_2);

    // Get the edge count
    edgeCount = Cdd_Ecap_GetEdgeNumbers(CddEcapConf_CddEcapChannel_CddEcapChannel_2);
    AppUtils_Printf("Edge count is: %d\r\n", edgeCount);
    AppUtils_Printf(" \r\n");

    return;
}

/**
 * \brief This function demonstrates the edge detection mode of Cdd_Ecap.
 *
 * The function enables edge detection on channel 3, delays for the demo,
 * disables edge detection, and prints the number of edges detected.
 *
 * \return None
 */
void CddEcap_DemoEdgeDetectionMode()
{
    // Print the starting message
    AppUtils_Printf(" Edge Detection Start on Channel %d...\r\n", CddEcapConf_CddEcapChannel_CddEcapChannel_3);

    // Initialize the counter to store the number of edges detected
    GCddEcapSignalCnt = 0U;

    // Enable edge detection on channel 3
    Cdd_Ecap_EnableEdgeDetection(CddEcapConf_CddEcapChannel_CddEcapChannel_3);

    // Enable the notification function for channel 3
    Cdd_Ecap_EnableNotification(CddEcapConf_CddEcapChannel_CddEcapChannel_3);

    // Delay for the demo
    McalLib_Delay(CDD_ECAP_EXAMPLE_DELAY_TIME);

    // Disable edge detection on channel 3
    Cdd_Ecap_DisableEdgeDetection(CddEcapConf_CddEcapChannel_CddEcapChannel_3);

    // Print the number of edges detected
    AppUtils_Printf("Number of edges detected is: %d\r\n", GCddEcapSignalCnt);

    // Print a newline
    AppUtils_Printf(" \r\n");

    return;
}

void Cdd_Ecap_TimeStampNotify()
{
    GCddEcapTimeCnt++;
}

void Cdd_Ecap_SignalNotify()
{
    GCddEcapSignalCnt++;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Capture_Signal.c
 *********************************************************************************************************************/
