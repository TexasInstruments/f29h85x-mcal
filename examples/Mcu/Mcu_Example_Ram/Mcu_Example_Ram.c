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
 *  File:       Mcu_Example_Ram.c
 *  Generator:  None
 *
 *  Description:  This file contains example application for Mcu Driver module
 *
 *  This example demonstrates how to do ram initialization of provided ram section and also to check
 *ram status
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu.h"
#include "EcuM.h"
#include "Platform_Types.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
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
#define DEVICE_SYSCLK_FREQ (200000000U)

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
volatile boolean          Mcu_CheckRamState = TRUE;
volatile Mcu_RamStateType Mcu_RamState      = MCU_RAMSTATE_INVALID;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static boolean Mcu_ApplCheckRamSection(Mcu_RamSectionConfigType ramConfig)
{
    uint32  i                 = 0U;
    boolean status            = (boolean)FALSE;
    uint32  section_size      = ramConfig.Mcu_RamSectionBytes;
    uint32  section_writeSize = ramConfig.Mcu_RamSectionWriteSize;
    uint32  num_iterations    = (section_size / section_writeSize);

    if (section_writeSize == 1U)
    {
        uint8 *addr = ramConfig.Mcu_RamSectionBaseAddress;
        for (i = 0U; i < num_iterations; i++)
        {
            if (*(addr + i) != ramConfig.Mcu_RamDefaultValue)
            {
                status = (boolean)FALSE;
                break;
            }
        }
    }
    else if (section_writeSize == 2U)
    {
        uint16 *addr = (uint16 *)ramConfig.Mcu_RamSectionBaseAddress;
        for (i = 0U; i < num_iterations; i++)
        {
            if (*(addr + i) != ramConfig.Mcu_RamDefaultValue)
            {
                status = (boolean)FALSE;
                break;
            }
        }
    }
    else if (section_writeSize == 4U)
    {
        uint32 *addr = (uint32 *)ramConfig.Mcu_RamSectionBaseAddress;
        for (i = 0U; i < num_iterations; i++)
        {
            if (*(addr + i) != ramConfig.Mcu_RamDefaultValue)
            {
                status = (boolean)FALSE;
                break;
            }
        }
    }
    else if (section_writeSize == 8U)
    {
        uint64 *addr = (uint64 *)ramConfig.Mcu_RamSectionBaseAddress;
        for (i = 0U; i < num_iterations; i++)
        {
            if (*(addr + i) != ramConfig.Mcu_RamDefaultValue)
            {
                status = (boolean)FALSE;
                break;
            }
        }
    }
    else
    {
        // Do Nothing
    }

    if (i == num_iterations)
    {
        status = (boolean)TRUE;
    }
    return status;
}

int main(void)
{
    Std_ReturnType init_ramsection_return = E_OK;
    boolean        status;
    uint32         loop_cnt;

    DeviceSupport_Init();
    EcuM_Init(); /* MCU Initilization to get configuration settings */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Sample Application - STARTS !!!\r\n");

    /*  get version Info */
#if (STD_ON == MCU_CFG_GET_VERSION_INFO_API)
    Std_VersionInfoType Mcu_VersionInfo;

    Mcu_GetVersionInfo(&Mcu_VersionInfo);
    AppUtils_Printf("MCU MCAL Version Info\r\n");
    AppUtils_Printf("---------------------\r\n");
    AppUtils_Printf("Vendor ID           : %d\r\n", Mcu_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\r\n", Mcu_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\r\n", Mcu_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\r\n", Mcu_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\r\n", Mcu_VersionInfo.sw_patch_version);
#endif

    status = Mcu_ApplCheckRamSection(Mcu_Config_Mcu_ModuleConfiguration_0.Mcu_ConfigRamSection[McuRamSectorSettingConf_0]);
    if (status != TRUE)
    {
        init_ramsection_return = E_NOT_OK;
    }

#if (STD_ON == MCU_CFG_GET_RAM_STATE_API)
    if (TRUE == Mcu_CheckRamState)
    {
        Mcu_RamState = Mcu_GetRamState(); /* Get ram state */
    }
#endif

    AppUtils_Printf("RAM section verified \r\n");
    AppUtils_Printf("RAM state verified \r\n");

    /* Wait for few seconds so that user can look at memory browser to check RAM initialization
     * before the app exits */
    loop_cnt = 0U;
    while (loop_cnt < 30U)
    {
        AppUtils_Printf("Halt and check the RAM init status from memory browser ...  %d\r\n", loop_cnt);
        McalLib_DelayMsec(1000U, DEVICE_SYSCLK_FREQ);
        loop_cnt++;
    }

    AppUtils_Printf("Mcu_Example_Ram: Sample Application - Completes successfully !!!\r\n");

    return init_ramsection_return;
}

/*********************************************************************************************************************
 *  End of File: Mcu_Example_Ram.c
 *********************************************************************************************************************/
