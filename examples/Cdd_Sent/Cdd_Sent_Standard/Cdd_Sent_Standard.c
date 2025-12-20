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
 *  File:       Cdd_Sent_Standard.c
 *  Generator:  None
 *
 *  Description:  This file contains Cdd_Sent standard example to read the data from the standard
 *sent sensor .
 *
 * This program will receive sensor data from a magnetic angle sensor using the SENT communication
 *protocol. This data can be further utilized to convert and get the sensed information.
 *
 * The sensor sends out a signal that is made up of a string of pulses with data encoded as falling
 *to falling edge periods. It happens independently of any receiver module activity, which occurs
 *without the receiver module sending a sync signal. The modulated signal with a constant amplitude
 *voltage and an evaluation of the time interval between two falling edges (a single edge) is
 *delivered in units of 4 bits (1 nibble), which can represent values ranging from 0 to 15.
 *
 * This example configures SENT module to receive 6 Data-nibble per frame for fast channel.
 *
 * \b External \b Connections \n
 *    - Connect GPIO18 to sensor's SENT channel 4 pin
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_Sent.h"
#include "Platform_Types.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "EcuM.h"
#include "Cdd_Sent_Cbk.h"
#include "Mcal_Lib.h"
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

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#if (STD_ON == CDD_SENT_CFG_GET_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Cdd_Sent_VersionInfo;
#endif
volatile uint32 data_received_count = 0;
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_SENT_TIME_DELAY_PER_SECOND (50000000U) /* 1 second Mcal delay*/
/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
int main(void)
{
    Std_ReturnType return_value = E_NOT_OK;
    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("Cdd_Sent Driver Sample Application - Starts!!!\n\r");
    /*  get version Info */
#if (STD_ON == CDD_SENT_CFG_GET_VERSION_INFO_API)
    Cdd_Sent_GetVersionInfo(&Cdd_Sent_VersionInfo);
    AppUtils_Printf("Cdd_Sent MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Sent_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Sent_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Sent_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Sent_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Sent_VersionInfo.sw_patch_version);
#endif

    AppUtils_Printf("Initilizing Cdd_Sent Driver\n");
    Cdd_Sent_Init(NULL_PTR);
    AppUtils_Printf("Cdd Sent Drive initilized\n");

    /* Wait for 1 seconds*/
    McalLib_Delay(CDD_SENT_TIME_DELAY_PER_SECOND * 1);

    if (data_received_count >= 2)
    {
        return_value = E_OK;
        AppUtils_Printf("Cdd_Sent_Standard: Sample Application - Completes successfully !!!\n");
    }
    else
    {
        return_value = E_NOT_OK;
        AppUtils_Printf("Cdd_Sent_Standard: Sample Application - FAILED !!!\n");
    }

    AppUtils_Printf("De-Initilizing Cdd_Sent Driver\n");
    (void)Cdd_Sent_Deinit();

    return return_value;
}

void CddSent_Callback(PduIdType id, const PduInfoType *PduInfoPtr)
{
    uint32 *data = (uint32 *)PduInfoPtr->SduDataPtr;
    if (PduInfoPtr->SduLength > 2)
    {
        AppUtils_Printf("Id received  from Fast channel : %d\n", id);
        AppUtils_Printf("Timestamp received  from Fast channel : %d\n", *data);
        AppUtils_Printf("Data received  from Fast channel : %d\n", *(data + 1));
    }
    else
    {
        AppUtils_Printf("Id received  from Slow channel : %d\n", id);
        AppUtils_Printf("Data received  from Slow channel : %d\n", *data);
    }
    data_received_count++;
}

void CddSent_Error_Callback()
{
    AppUtils_Printf("Error data received \n");
}
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Standard.c
 *********************************************************************************************************************/
