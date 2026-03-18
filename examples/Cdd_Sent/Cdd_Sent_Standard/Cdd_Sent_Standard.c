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

void CddSent_Error_Callback(void)
{
    AppUtils_Printf("Error data received \n");
}
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Standard.c
 *********************************************************************************************************************/
