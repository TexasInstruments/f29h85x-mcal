/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Mcu_Example_Ram.c
 *  Generator:  None
 *
 *  Description:  This file contains example application for Mcu Driver module
 *
 *  This example demonstrates how to do ram initialization of provided ram section and also to check
 *  ram status.
 *
 *  Verify that RAM is initialized with Mcu_RamSectionCfgSet0 (16 consecutive bytes starting from
 *  address 0x200e0000 are set to 0xCD)
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

    status =
        Mcu_ApplCheckRamSection(Mcu_Config_Mcu_ModuleConfiguration_0.Mcu_ConfigRamSection[McuRamSectorSettingConf_0]);
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
        McalLib_DelayMsec(1000U);
        loop_cnt++;
    }

    AppUtils_Printf("Mcu_Example_Ram: Sample Application - Completes successfully !!!\r\n");

    return init_ramsection_return;
}

/*********************************************************************************************************************
 *  End of File: Mcu_Example_Ram.c
 *********************************************************************************************************************/
