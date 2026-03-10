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
 *  File:       Lin_Example_Sleep_Wakeup_Interrupt.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  None
 *
 *  Description:  This file contains Lin Driver Demo implementation which will initialize the Lin
 *Module, Put the device to sleep mode, and when wakeup pulse is generated on LIN BUS, Wakeup
 *interrupt is expected and device should wakeup from sleep.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "string.h"
#include "Det.h"
#include "Std_Types.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h"
#include "EcuM.h"
#include "Port_Cfg.h"
#include "hw_types.h"
#include "Mcu.h"
#include "EcuM_Cbk.h"
#include "Lin.h"
#include "Lin_Priv.h"
#include "Port.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "LinIf_Cbk.h"

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
 * ExLined Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
Std_ReturnType Lin_CheckWakeUp_and_Sleep();
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
uint8*  Lin_Rx_Buff;
uint8** Lin_Rx_Data = &Lin_Rx_Buff;

int main(void)
{
    /* INITIALIZATIONS*/
    Std_ReturnType returnValue = E_NOT_OK;
    DeviceSupport_Init();
    /* EcuM_Init() will Initialize Port with the provided configuration. Below API will call
    Port_Init(&Port_Config) and will Initialize the Port and Mcu Driver */
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("LIN Driver Sample Application: Lin Sleep WakeUp Interrupt - Starts!!!\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

    /* Lin_Init */
#if (STD_ON == LIN_PRE_COMPILE_VARIANT)
    Lin_Init(NULL_PTR);
    Lin_WakeupInternal(LinConf_LinChannel_LinChannel_0);
#else
    const Lin_ConfigType* pCfgPtr = &Lin_Config;
    Lin_Init(pCfgPtr);
    returnValue = Lin_WakeupInternal(LinConf_LinChannel_LinChannel_0);
    if (returnValue == E_OK)
    {
        AppUtils_Printf("Initialization of LIN Module is Success !!!\n\n\r");
    }

#endif

    returnValue = Lin_CheckWakeUp_and_Sleep();
    if ((returnValue == E_OK) && (LIN_OPERATIONAL == Lin_GetStatus(LinConf_LinChannel_LinChannel_0, Lin_Rx_Data)))
    {
        AppUtils_Printf("---------------------------------------------------------------\n\r");
        AppUtils_Printf("LIN Example Application - Wake Up Interrupt PASSED !!!\n");
        AppUtils_Printf("---------------------------------------------------------------\n\r");
    }
    else
    {
        AppUtils_Printf("!!! Example Run Failed !!!\n\r");
    }
}

Std_ReturnType Lin_CheckWakeUp_and_Sleep()
{
    Std_ReturnType return_val = E_NOT_OK;

    AppUtils_Printf("LIN Module Going to Sleep. Sending Go to Sleep Command On Bus..\n\r");
    return_val = Lin_GoToSleep(LinConf_LinChannel_LinChannel_0);

    while (LIN_CH_SLEEP != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, Lin_Rx_Data))
        ;

    if (return_val == E_OK)
    {
        /* If Go to sleep is Success, Need to trigger wakeup pulse from PLIN */
        /* When WakeUp Pulse is triggered, Wakeup Interrupt will be triggered */
        AppUtils_Printf("LIN Module Successfully Went to Sleep Mode. \n\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Trigger WakeUp Pulse on Lin Bus to Wakeup Lin Module\n\r");
        AppUtils_Printf("Waiting for WAKE UP INTERRUPT on Bus...\n\r");

        while (LIN_OPERATIONAL != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, Lin_Rx_Data))
        {
            /* Do nothing */
        }
        AppUtils_Printf("Lin Module Wake Up from Sleep by WakeUp Interrupt is Success !!!\n\n\r");
    }
    else
    {
        AppUtils_Printf("Some Error Occurred while sending sleep signal to Lin Bus\n\r");
    }

    return return_val;
}

void Ecum_Lin_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    Std_ReturnType check_wakeup_status = E_NOT_OK;

    check_wakeup_status = LinIf_CheckWakeup(WakeupSource);

    if (check_wakeup_status == E_OK)
    {
        AppUtils_Printf("LinIf_CheckWakeup Detected WakeUp Pulse on Lin Bus !!!\n\r");
    }
    else
    {
        AppUtils_Printf("No WakeUp detected on Lin Bus\n\r");
    }
}
/*********************************************************************************************************************
 *  End of File: Lin_Example_Sleep_Wakeup_Interrupt.c
 *********************************************************************************************************************/
