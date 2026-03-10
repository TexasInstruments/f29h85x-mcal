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
 *  File:       Dio_Example_Read_Write_All.c
 *  Generator:  None
 *
 *  Description:  This file contains Dio examples with read/write of channel, read/write of port,
 *                read/write of channel group and fliping channel level.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Dio.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "Platform_Types.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"

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

/*  GPIO direction configuration */
#define DIO_A_DIR                 ((uint32)0x0F0F0F0F)
#define DIO_WRITE_PORT_LEVEL      ((uint32)0x55555555)
#define DIO_WRITE_PORT_GROUPLEVEL ((uint32)0xAA)

#if (STD_ON == DIO_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Dio_VersionInfo;
#endif
/* Dio channel level global variable */
Dio_LevelType        Dio_ChannelLevel = 0x0;
/* Dio port level global variable */
Dio_PortLevelType    Dio_PortLevel = 0x00000000;
/* Dio channel group */
Dio_ChannelGroupType Dio_ChannelGroup = {.port = DIO_PORT_A, .mask = 0xFF00, .offset = 8U};

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/* dio flip channel level */
Dio_LevelType Dio_FlipLevel = 0x0;
#endif

/* dio channel response */
Std_ReturnType Dio_ChannelResponse = E_OK;
/* dio port response */
Std_ReturnType Dio_PortResponse = E_OK;
/* dio channel group response */
Std_ReturnType Dio_ChnlGroupResponse = E_OK;

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
int main(void)
{
    Std_ReturnType return_value = E_NOT_OK;
    DeviceSupport_Init();
    /*  Configure the Port A pins direction and init MCU */
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    /*  get version Info */
#if (STD_ON == DIO_VERSION_INFO_API)
    Dio_GetVersionInfo(&Dio_VersionInfo);
    AppUtils_Printf("DIO MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Dio_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Dio_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Dio_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Dio_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Dio_VersionInfo.sw_patch_version);
#endif
    /*  Write and Read to an individual pin which configured as output */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);
    /*  The level of the pins configured as output should be changed */
    Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_DioChannel_0);
    if (Dio_ChannelLevel != STD_HIGH)
    {
        Dio_ChannelResponse = E_NOT_OK;
    }

    AppUtils_Printf("\nTest A. Write and Read Channel\n");
    AppUtils_Printf("-------------------------------\n");
    /*  DioConf_DioChannel_DioChannel_4 is configured as input, below wtite should not have any
     * impact */
    AppUtils_Printf("Reading channel 4\n");
    Dio_LevelType Dio_InptChannelLevel = Dio_ReadChannel(DioConf_DioChannel_DioChannel_4);
    /* write STD_HIGH to input channel */
    AppUtils_Printf("Writing High to channel 4\n");
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_4, STD_HIGH);
    /* The level of the pins configured as input should not be changed */
    AppUtils_Printf("Reading channel 4\n");
    Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_DioChannel_4);
    if (Dio_ChannelLevel != Dio_InptChannelLevel)
    {
        Dio_ChannelResponse = E_NOT_OK;
    }
    /* write STD_LOW to input channel */
    AppUtils_Printf("Writing Low to channel 4\n");
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_4, STD_LOW);
    AppUtils_Printf("Reading channel 4\n");
    Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_DioChannel_4);
    if (Dio_ChannelLevel != Dio_InptChannelLevel)
    {
        Dio_ChannelResponse = E_NOT_OK;
    }
    AppUtils_Printf("DIO Test A :Service API: Write/Read Channel completed\n");

    AppUtils_Printf("\nTest B. Write/Read Port\n");
    AppUtils_Printf("----------------------------\n");
    AppUtils_Printf("Writing on to Port 0\n");
    /*  Read and Write to a DIO port */
    Dio_WritePort(DioConf_DioPort_DioPort_0, DIO_WRITE_PORT_LEVEL);

    AppUtils_Printf("Reading from Port 0\n");
    /*  The level of the pins configured as input should not be changed */
    Dio_PortLevel = Dio_ReadPort(DioConf_DioPort_DioPort_0);
    if ((Dio_PortLevel & DIO_A_DIR) != (DIO_WRITE_PORT_LEVEL & DIO_A_DIR))
    {
        Dio_PortResponse = E_NOT_OK;
    }

    AppUtils_Printf("Test B. Write/Read Port completed\n");
    AppUtils_Printf("\nTest C. Write/Read Channel group\n");
    AppUtils_Printf("----------------------------\n");
    AppUtils_Printf("Writing on to channel group 0\n");
    /*  Read and Write to a DIO channel group */
    Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0, DIO_WRITE_PORT_GROUPLEVEL);

    AppUtils_Printf("Reding from channel group 0\n");
    /*  The level of the pins configured as input should not be changed */
    Dio_PortLevel = Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0);
    if ((Dio_PortLevel & DIO_A_DIR) != (DIO_WRITE_PORT_GROUPLEVEL & DIO_A_DIR))
    {
        Dio_ChnlGroupResponse = E_NOT_OK;
    }
    AppUtils_Printf("DIO Test C :Service API: Write/Read Channel group completed\n");
#if (STD_ON == DIO_FLIP_CHANNEL_API)
    AppUtils_Printf("\nTest D. Flip Channel\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Reading from channel 8\n");
    /* flip the level of the pin which configured as output */
    Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_DioChannel_8);
    AppUtils_Printf("Fliping channel 8 level\n");
    Dio_FlipLevel = Dio_FlipChannel(DioConf_DioChannel_DioChannel_8);
    /*  The level of the pins configured as output should be fliped */
    if (Dio_ChannelLevel == Dio_FlipLevel)
    {
        Dio_ChannelResponse = E_NOT_OK;
        AppUtils_Printf("FAIL: Failed to flip channel 8 level \n");
    }
    else
    {
        AppUtils_Printf("PASS: channel 8 level fliped\n");
    }
    AppUtils_Printf("DIO Test D :Service API: Flip Channel completed\n");
#endif
    AppUtils_Printf("\nDio_Example_Read_Write_All: Sample Application - Completes successfully !!!");

    return return_value;
}
/*********************************************************************************************************************
 *  End of File: Dio_Example_Read_Write_All.c
 *********************************************************************************************************************/
