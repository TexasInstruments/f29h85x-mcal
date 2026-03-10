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
 *  File:       Dio_Lcfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated link time configuration data
 *********************************************************************************************************************/
[!SKIPFILE "node:value(as:modconf('Dio')[as:path(node:dtos(.))='/TI_F29H85x/Dio']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantLinkTime'"!]
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 /* Design: MCAL-22532 */
#include "Dio.h"

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
#if ((DIO_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    || (DIO_SW_MINOR_VERSION !=([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Dio_Lcfg.c and Dio.h are inconsistent!"
#endif

 #if ((DIO_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||\
    (DIO_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Dio_Lcfg.c and Dio_Cfg.h are inconsistent!"
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
[!SELECT "as:modconf('Dio')[as:path(node:dtos(.))='/TI_F29H85x/Dio']"!][!//
[!IF "num:i(count(DioConfig/DioPort/*/DioChannelGroup/*)) > 0"!][!//
#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
/* Global Data */
[!LOOP "DioConfig/DioPort/*"!]
[!LOOP "DioChannelGroup/*"!][!//
 /* Design : MCAL-22510, MCAL-22511 */
CONST(Dio_ChannelGroupType, DIO_CONFIG_DATA) [!"DioChannelGroupIdentification"!] =
{
    .port =   ((Dio_PortType) [!"concat('DIO_PORT_', translate(../../DioPortId, '01234567', 'ABCDEFGH'))"!]),
    .mask =   ((Dio_PortLevelType) [!"num:inttohex(DioPortMask,8)"!]U),
    .offset = ((uint8) [!"num:i(DioPortOffset)"!]U),
};
[!ENDLOOP!][!ENDLOOP!]


[!VAR "var1" = "0"!][!//
P2CONST(struct Dio_ChannelGroupType_s, DIO_CONFIG_DATA, DIO_CONFIG_DATA) Dio_ChannelGroupRef[DIO_MAX_NO_OF_CHANNEL_GROUPS] =
{[!LOOP "DioConfig/DioPort/*"!][!LOOP "DioChannelGroup/*"!]
    [[!"num:i($var1)"!]] = ((P2CONST(Dio_ChannelGroupType, DIO_CONFIG_DATA, DIO_CONFIG_DATA)) (&[!"DioChannelGroupIdentification"!])),
[!VAR "var1" = "$var1+1"!][!//
[!ENDLOOP!][!ENDLOOP!]};

#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
[!ENDIF!][!ENDSELECT!][!//
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
 * End of File: Dio_Lcfg.c
 *********************************************************************************************************************/
