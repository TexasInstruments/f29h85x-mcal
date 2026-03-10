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
 *  File:       File name
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  Description of file's purpose                                                           
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "hw_memmap.h"
#ifdef __cplusplus

extern "C" {
#endif

[!AUTOSPACING!]

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
  #if ((CDD_ECAP_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||(CDD_ECAP_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap.h are inconsistent!"
#endif

 #if ((CDD_ECAP_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||(CDD_ECAP_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_BASEADDR_STEP             (uint32)(ECAP2_BASE - ECAP1_BASE)
#define CDD_ECAP_HR_BASEADDR_STEP          (uint32)(HRCAP6_BASE - HRCAP5_BASE)
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Ecap Driver configuration */

#define CDD_ECAP_START_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

[!SELECT "as:modconf('Cdd_Ecap/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ecap/Cdd']"!]
[!VAR "NumChannels" = "num:i(count(CddEcapConfigSet/CddEcapChannel/*))"!]

[!AUTOSPACING!]

[!VAR "Index" = "0"!]
[!VAR "Index1" = "0"!]
[!VAR "Ticks" = "0"!]
[!VAR "DeviceName" = "node:value(node:ref('ASPathDataOfSchema:/TI_F29H85x/ResourceAllocator/ResourceAllocatorGeneral/Device'))"!]

[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile')"!]
[!VAR "Index" = "0"!]
[!VAR "Index1" = "0"!]
[!VAR "Ticks" = "0"!]

/* Cdd_Ecap Channel Configuration parameters */
 CONST(struct Cdd_Ecap_ConfigTag, CDD_ECAP_CONFIG_DATA)
    Cdd_Ecap_Config =
{
    .chCfg =
    {
    [!LOOP "CddEcapConfigSet/CddEcapChannel/*"!][!/*Channel Loop */!]
        [[!"num:i($Index1)"!]] =
        {
            .channelId = CDD_ECAP_CHANNEL[!"num:i(CddEcapChannelId)"!], /* Channel ID */
            .emulationMode = [!"CddEcapEmulationMode"!], /* Emulation Mode */
            .defaultStartEdge = [!"CddEcapDefaultStartEdge"!],/* Default start edge*/
            .inputSelect = [!"CddEcapInputSelect"!],/* Input source select */
            .measurementMode = [!"CddEcapMeasurementMode"!],/* Measurement Mode*/
            [!IF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_SIGNAL_MEASUREMENT'"!]
            .signalMeasurementProperty = [!"CddEcapSignalMeasurement/CddEcapSignalMeasurementProperty"!],
              [!IF "node:empty(CddEcapSignalMeasurement/CddEcapSignalMeasurementProperty) = 'true'"!][!ERROR "Signal Measurement Property is not configured"!][!ENDIF!][!//
            [!ELSEIF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_TIMESTAMP'"!]
            [!IF "node:exists(CddEcapTimestampMeasurement/CddEcapTimestampNotification)"!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)[!IF "node:empty(CddEcapTimestampMeasurement/CddEcapTimestampNotification)"!] NULL_PTR [!ELSE!] [!"CddEcapTimestampMeasurement/CddEcapTimestampNotification"!] [!ENDIF!],
            [!ELSE!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)NULL_PTR,
            [!ENDIF!]
            .bufferType =  [!"CddEcapTimestampMeasurement/CddEcapTimestampMeasurementProperty"!],
            [!IF "node:empty(CddEcapTimestampMeasurement/CddEcapTimestampMeasurementProperty) = 'true'"!][!ERROR "Buffer Type is not configured"!][!ENDIF!][!//
            [!ELSEIF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_SIGNAL_EDGE_DETECT'"!]
            [!IF "node:exists(CddEcapSignalEdgeDetection/CddEcapSignalNotification)"!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)[!IF "node:empty(CddEcapSignalEdgeDetection/CddEcapSignalNotification)"!] NULL_PTR [!ELSE!] [!"CddEcapSignalEdgeDetection/CddEcapSignalNotification"!] [!ENDIF!],
            [!ELSE!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)NULL_PTR,
            [!ENDIF!]
            [!ENDIF!]
            .instanceClkMHz = [!"num:i(num:div(num:i(CddEcapClkFrequency), 1000000))"!]U,
            .prescaler = (uint8)[!"num:i(num:div(substring-after(CddEcapPrescaler,'CDD_ECAP_PRESCALAR_'), 2))"!]U, /* prescale */
            .base_addr = (uint32)[!"node:value(node:ref(CddEcapChannelRef)/BaseAddr)"!], /* Base address of the channel */
            [!IF "CddEcapHREnable = 'true'"!]
            [!IF "ecu:get('ResourceAllocator_F29H85x.Cdd_Ecap_HrEnable') = 'FALSE'"!][!ERROR "HR mode is not enabled for this device."!]
            [!ELSEIF "not(text:contains(concat(',', ecu:get('ResourceAllocator_F29H85x.Cdd_Ecap_HrSupportId'), ','), concat(',', CddEcapChannelId, ',')))"!][!ERROR!]HR mode is not supported for ECAP [!"num:i(CddEcapChannelId + 1)"!][!ENDERROR!]
            [!ELSE!]
            .hr_enable = (boolean)TRUE,
            [!VAR "baseAddr" = "node:value(node:ref(CddEcapChannelRef)/BaseAddr)"!]
            .hr_base_addr = (uint32)[!"concat('HR', substring-after($baseAddr, 'E'))"!] /* Base address of the high resolution channel */
            [!ENDIF!]
            [!ENDIF!]
        }[!VAR "Index1" = "$Index1+1"!][!IF "not(node:islast())"!],[!ENDIF!][!CR!][!ENDLOOP!]
    }[!IF "not(node:islast())"!],[!ENDIF!][!CR!]
};
[!VAR "Index" = "$Index+1"!][!/*End of CddEcapConfigSet */!]
[!ENDIF!][!//

[!/*
    Duplicate channel ID check
*/!]
[!LOOP "CddEcapConfigSet/CddEcapChannel/*"!]
[!VAR "chanId" = "CddEcapChannelId"!]
[!VAR "chName" = "@name"!]
[!VAR "Repeated" = "0"!]
[!LOOP "CddEcapConfigSet/CddEcapChannel/*"!]
[!IF "CddEcapChannelId = num:i($chanId)"!]
    [!IF "'1' = num:i($Repeated)"!]
        [!ERROR!] Cdd_Ecap ChannelId should be unique!!!. Please check channel [!"$chName"!] and [!"@name"!], both have same channel ID as [!"num:i($chanId)"!]." [!ENDERROR!]
    [!ELSE!]
        [!VAR "Repeated" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
#ifdef __cplusplus
}
#endif

/*</CDD_ECAP_CONFIGURATION>*/
#define CDD_ECAP_STOP_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Cfg.c
 *********************************************************************************************************************/
