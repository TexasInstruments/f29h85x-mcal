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
 *  File:         Fls_Cfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated pre compile configuration file for FLS MCAL driver
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls.h"
#include "Fls_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
 #if ((FLS_SW_MAJOR_VERSION != (3U)) ||\
    (FLS_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Fls_Cfg.c and Fls.h are inconsistent!"
#endif

 #if ((FLS_CFG_MAJOR_VERSION != (3U)) ||\
    (FLS_CFG_MINOR_VERSION != (1U)))
    #error "Version numbers of Fls_Cfg.c and Fls_Cfg.h are inconsistent!"
#endif

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
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Object Definitions
 *********************************************************************************************************************/
#define  FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
/* generation of runtime configuration */

#ifdef __cplusplus
extern "C" {
#endif
/* generation of configuration data */
/*
 * Design: MCAL-31044, MCAL-31045, MCAL-31046, MCAL-31047, MCAL-31048, MCAL-31049, MCAL-31066,
 * Design: MCAL-31067, MCAL-31068, MCAL-31069, MCAL-31070, MCAL-31071, MCAL-31072, MCAL-31073,
 * Design: MCAL-31074, MCAL-31075, MCAL-31076,
 */
CONST(struct Fls_ConfigType_s, FLS_CONFIG_DATA) Fls_Config =
{
    .Fls_JobEndNotification = (Fls_JobEndNotifyType)Fee_JobEndNotification,
    .Fls_JobErrorNotification = (Fls_JobErrorNotifyType)Fee_JobErrorNotification,
    .FlsMaxReadNormalMode = 16U,
    .FlsMaxWriteNormalMode = 16U, /* 8 byts or 16 bytes */
    .sectorList =
    {
            [0] =
            {
                .numberOfSectors = 1U,
                .sectorSize = 2048U,
                .sectorStartAddress = 281018368U,
            },
            [1] =
            {
                .numberOfSectors = 1U,
                .sectorSize = 2048U,
                .sectorStartAddress = 281020416U,
            },
            [2] =
            {
                .numberOfSectors = 1U,
                .sectorSize = 2048U,
                .sectorStartAddress = 281022464U,
            },
            [3] =
            {
                .numberOfSectors = 1U,
                .sectorSize = 2048U,
                .sectorStartAddress = 281024512U,
            },
            [4] =
            {
                .numberOfSectors = 1U,
                .sectorSize = 2048U,
                .sectorStartAddress = 281026560U,
            },
    },
};

#ifdef __cplusplus
}
#endif

#define  FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * END OF FILE: Fls_Cfg.c
 *********************************************************************************************************************/
