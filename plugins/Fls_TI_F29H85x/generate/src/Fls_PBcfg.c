[!SKIPFILE "node:value(as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPostBuild'"!]
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
 *  File:         Fls_PBcfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration file for FLS MCAL driver
 *********************************************************************************************************************/

/********************************************************************************************************************
 * Header Files
 ********************************************************************************************************************/
#include "Fls.h"
#include "Fls_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
 #if ((FLS_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||\
    (FLS_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Fls_PBcfg.c and Fls.h are inconsistent!"
#endif

 #if ((FLS_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||\
    (FLS_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Fls_PBcfg.c and Fls_Cfg.h are inconsistent!"
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
/* generation of runtime configuration       */

#ifdef __cplusplus
extern "C" {
#endif
[!AUTOSPACING!]
/* generation of configuration data */
[!SELECT "as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']"!]
[!LOOP "FlsConfigSet"!][!//
CONST(struct Fls_ConfigType_s, FLS_CONFIG_DATA) Fls_Config =
{
[!WS "4"!].Fls_JobEndNotification = [!IF "(node:exists(FlsJobEndNotification))"!][!IF "node:value(FlsJobEndNotification) = 'NULL_PTR' or node:empty(FlsJobEndNotification)"!] NULL_PTR[!ELSE!](Fls_JobEndNotifyType)[!"(node:value(FlsJobEndNotification))"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
[!WS "4"!].Fls_JobErrorNotification = [!IF "(node:exists(FlsJobErrorNotification))"!][!IF "node:value(FlsJobErrorNotification) = 'NULL_PTR' or node:empty(FlsJobErrorNotification)"!] NULL_PTR[!ELSE!](Fls_JobErrorNotifyType)[!"(node:value(FlsJobErrorNotification))"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
[!WS "4"!].FlsMaxReadNormalMode = [!"FlsMaxReadNormalMode"!]U,
[!WS "4"!].FlsMaxWriteNormalMode = [!"FlsMaxWriteNormalMode"!]U, /* 8 byts or 16 bytes */
[!WS "4"!].sectorList =
[!WS "4"!]{
[!WS "4"!][!LOOP "FlsSectorList/FlsSector/*"!]
[!WS "4"!][!WS "4"!][[!"@index"!]] =
[!WS "4"!][!WS "4"!][!WS "4"!]{
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].numberOfSectors = [!"FlsNumberOfSectors"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].sectorSize = [!"FlsSectorSize"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].sectorStartAddress = [!"num:i(num:i(as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']/FlsGeneral/FlsBaseAddress) + num:i(FlsSectorStartaddress))"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!]},
[!WS "4"!][!ENDLOOP!]},
};
[!ENDLOOP!][!//
[!ENDSELECT!][!//

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
 *  END OF FILE: Fls_PBCfg.c
 *********************************************************************************************************************/