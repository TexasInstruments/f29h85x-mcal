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
 *  File:       Lin_Example_Init_Sleep_Wakeup.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  None
 *
 *  Description:  This file contains Lin Driver Demo implementation which will Initialize the Lin
 *Module, Move the channel state to internal sleep and wakeup from Internal Sleep, Move the channel
 *state to deep sleep and wakeup from sleep mode.
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
#include "EcuM_Cfg.h"

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
#if (STD_ON == LIN_GET_VERSION_INFO_API)
Std_VersionInfoType Lin_VersionInfo;
#endif

Std_ReturnType returnValue = E_NOT_OK;
uint8*         rxBuff;
uint8**        rxData = &rxBuff;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
Std_ReturnType Lin_CheckWakeUp_and_Sleep();
Std_ReturnType Lin_CheckWakeUp_and_Sleep_Internal();
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
    /* INITIALIZATIONS*/
    DeviceSupport_Init();
    /* EcuM_Init() will Initialize Port with the provided configuration. Below API will call
    Port_Init(&Port_Config) and will Initialize the Port and Mcu Driver */
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("LIN Driver Sample Application: Lin Init Sleep WakeUp - Starts!!!\n\n\r");

    /* Lin_GetVersionInfo */
#if (LIN_GET_VERSION_INFO_API == STD_ON)
    Lin_GetVersionInfo(&Lin_VersionInfo);
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    AppUtils_Printf("Test 1: Get Version info for Lin\n\r");
    AppUtils_Printf("API Lin_GetVersionInfo executed successfully\n\r");
    AppUtils_Printf(" LIN MCAL Version Info\n\r");
    AppUtils_Printf(" ---------------------\n\r");
    AppUtils_Printf(" Vendor ID           : %d\n\r", Lin_VersionInfo.vendorID);
    AppUtils_Printf(" Module ID           : %d\n\r", Lin_VersionInfo.moduleID);
    AppUtils_Printf(" SW Major Version    : %d\n\r", Lin_VersionInfo.sw_major_version);
    AppUtils_Printf(" SW Minor Version    : %d\n\r", Lin_VersionInfo.sw_minor_version);
    AppUtils_Printf(" SW Patch Version    : %d\n\r", Lin_VersionInfo.sw_patch_version);
    AppUtils_Printf(" \n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
#endif

    /* Lin_Init */
    AppUtils_Printf("Test 2: Initialization of Lin Module\n\r");
#if (STD_ON == LIN_PRE_COMPILE_VARIANT)
    Lin_Init(NULL_PTR);
#else
    const Lin_ConfigType* pCfgPtr = &Lin_Config;
    Lin_Init(pCfgPtr);
    AppUtils_Printf("Initialization of LIN Module is Success !!!\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

#endif

    returnValue = Lin_CheckWakeUp_and_Sleep_Internal();
    if ((returnValue == E_OK) && (LIN_OPERATIONAL == Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData)))
    {
        AppUtils_Printf("Lin Waking up from Internal Sleep by LinWakeupInternal API is Success !!!\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    }

    returnValue = E_NOT_OK;

    returnValue = Lin_CheckWakeUp_and_Sleep();
    if ((returnValue == E_OK) && (LIN_OPERATIONAL == Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData)))
    {
        AppUtils_Printf("Lin Waking up from Sleep by LinWakeup API is Success !!!\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\r");
        AppUtils_Printf("LIN Example Init Sleep WakeUp Run FINISHED \n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\r");
    }
    else
    {
        AppUtils_Printf("---------------------------------------------------------------\n\r");
        AppUtils_Printf("!!!LIN Example Init Sleep WakeUp Run FAILED to run!!! \n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\r");
    }
}

Std_ReturnType Lin_CheckWakeUp_and_Sleep_Internal()
{
    Std_ReturnType return_val = E_NOT_OK;

    AppUtils_Printf("Test 3: Lin Module : Internal Sleep\n\r");
    return_val = Lin_GoToSleepInternal(LinConf_LinChannel_LinChannel_0);

    while (LIN_CH_SLEEP != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData))
        ;

    if (return_val == E_OK)
    {
        AppUtils_Printf("Lin going to internal Sleep is Success !!!\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 4: Lin Module : Wakeup from Internal Sleep - Wakeup Internal\n\r");
        return_val |= Lin_WakeupInternal(LinConf_LinChannel_LinChannel_0);
    }

    return return_val;
}

Std_ReturnType Lin_CheckWakeUp_and_Sleep()
{
    Std_ReturnType return_val = E_NOT_OK;

    AppUtils_Printf("Test 5: Lin Module : Sleep\n\r");
    AppUtils_Printf("Sending Go To Sleep Command on Lin Bus...\n\r");
    return_val = Lin_GoToSleep(LinConf_LinChannel_LinChannel_0);

    if (return_val == E_OK)
    {
        while (LIN_CH_SLEEP != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData))
            ;

        AppUtils_Printf("Lin Go to Sleep Command is sent on Lin Bus !!!\n\r");
        AppUtils_Printf("Lin going to Sleep is Success !!!\n\r");
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 6: Lin Module : Wakeup from Sleep - Lin Wakeup\n\r");
        return_val |= Lin_Wakeup(LinConf_LinChannel_LinChannel_0);
        AppUtils_Printf("Lin WakeUp Command is sent on Lin Bus !!!\n\r");
    }
    else
    {
        AppUtils_Printf("Failed to Send Sleep Command on Lin Bus !!!\n\r");
    }

    return return_val;
}

/*********************************************************************************************************************
 *  End of File: Lin_Example_Init_Sleep_Wakeup.c
 *********************************************************************************************************************/
