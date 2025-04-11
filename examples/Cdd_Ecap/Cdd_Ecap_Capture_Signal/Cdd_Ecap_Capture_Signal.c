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
 *  File:       Cdd_Ecap_Capture_Signal.c
 *  Generator:  Code generation tool (if any)
 *
 *  Description: This example configures 4 ECAP channels in different modes and captures a PWM signal.
                 Channel0 -> Signal Measurement Mode.
                 Channel1 -> Time Stamp Mode.
                 Channel2 -> Edge Counter Mode.
                 Channel3 -> Signal Edge Detect.
                 Channel1, 2 and 3 are configured in rising edge mode. 
                 Input Xbar 7 is being used for all the ECAP channels and PWM signal is on the GPIO40.
                 Notification funtion is also being used for Channel1 and 3.
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

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
Cdd_Ecap_ValueType buffer[20];
Cdd_Ecap_ValueType* bufferPtr = buffer;
uint32 highTime, periodTime, SignalActive;
Cdd_Ecap_DutyCycleType dutyValue;
uint32 TimeCnt, SignalCnt;
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

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
void Cdd_Ecap_TimeStampNotify();
void Cdd_Ecap_SignalNotify();

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
    AppUtils_Printf("Executing Cdd_Ecap_Capture_Signal example\n");

    //Configuration for ECAP0
    Cdd_Ecap_StartSignalMeasurement(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

    //Configuration for ECAP1
    Cdd_Ecap_StartTimestamp(CddEcapConf_CddEcapChannel_CddEcapChannel_1, bufferPtr, 20, 0);
    Cdd_Ecap_EnableNotification(CddEcapConf_CddEcapChannel_CddEcapChannel_1);

    //Configuration for ECAP2
    Cdd_Ecap_EnableEdgeCount(CddEcapConf_CddEcapChannel_CddEcapChannel_2);
    
    //Configuration for ECAP3
    Cdd_Ecap_EnableEdgeDetection(CddEcapConf_CddEcapChannel_CddEcapChannel_3);
    Cdd_Ecap_EnableNotification(CddEcapConf_CddEcapChannel_CddEcapChannel_3);
    uint32 i = 0;

    while(i <= 1000)
    {
        if(CDD_ECAP_ACTIVE == Cdd_Ecap_GetInputState(CddEcapConf_CddEcapChannel_CddEcapChannel_0))
        {
            Cdd_Ecap_GetDutyCycleValues(CddEcapConf_CddEcapChannel_CddEcapChannel_0, &dutyValue);
            Cdd_Ecap_GetTimeElapsed(CddEcapConf_CddEcapChannel_CddEcapChannel_0);

            highTime = dutyValue.ActiveTime;
            periodTime = dutyValue.PeriodTime;   

        }

        if(CDD_ECAP_ACTIVE == Cdd_Ecap_GetInputState(CddEcapConf_CddEcapChannel_CddEcapChannel_3))
        {
            SignalActive++;
        }
        ++i;
    }
    AppUtils_Printf("High time of the signal is: %d\n", highTime);
    AppUtils_Printf("Period of the signal is: %d\n", periodTime);

    Cdd_Ecap_DeInit();

    while(1)
    {

    }

    return 0;
}

void Cdd_Ecap_TimeStampNotify()
{
    TimeCnt++;
}

void Cdd_Ecap_SignalNotify()
{
    SignalCnt++;
}
 
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Capture_Signal.c
 *********************************************************************************************************************/
