[!SKIPFILE "as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
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
 *  File:       Cdd_Xbar_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
#include "Cdd_Xbar.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_XBAR_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_XBAR_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_XBAR_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif


/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

[!AUTOSPACING!][!//

#define CDD_XBAR_START_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

[!SELECT "as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/CddXbarConfiguration"!]
/** \brief CDD Crossbar Configuration */
VAR(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = 
{
[!IF "num:i(count(CddXbarInputXbarConfig/CddXbarInputXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25701 */
    .Cdd_Xbar_InputCfg = 
    {
[!LOOP "CddXbarInputXbarConfig/CddXbarInputXbarInstanceConfig/*"!]
        {
            .inputSelect = [!"node:value(CddXbarInputXbarInput)"!],   /* Design: MCAL-25720 */
[!IF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_GPIO_AIO'"!]
            .inputLine = [!"node:value(node:ref(text:concat(node:path(node:ref(CddXbarInputXbarInputSource)),'/PortPinId')))"!]U,    /* [!"node:value(node:ref(text:concat(node:path(node:ref(CddXbarInputXbarInputSource)),'/PortPinPeripheralInstance')))"!] */  /* Design: MCAL-25721 */
[!ELSEIF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_LOGIC_HIGH'"!][!//
            .inputLine = 0xFFFEU,   /* LOGIC HIGH */
[!ELSEIF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_LOGIC_LOW'"!][!//
            .inputLine = 0xFFFFU,  /* LOGIC LOW  */  /* Design: MCAL-25721 */
[!ENDIF!]
[!/* Validate that if CddXbarInputXbarInput is not in external interrupt list, CddXbarExternalInterruptEdge must be CDD_XBAR_INT_TYPE_DISABLED */!][!//
[!IF "not(text:contains(ecu:list('ResourceAllocator_F29H85x.Cdd_Xbar_External_Interrupt_Input_Xbar'), node:value(CddXbarInputXbarInput)))"!][!//
[!IF "CddXbarExternalInterruptEdge != 'CDD_XBAR_INT_TYPE_DISABLED'"!][!//
[!ERROR!]CddXbarExternalInterruptEdge must be CDD_XBAR_INT_TYPE_DISABLED for [!"node:value(CddXbarInputXbarInput)"!] as it is not connected to an external interrupt (XINT). Only INPUT_XBAR4 (XINT1), INPUT_XBAR5 (XINT2), INPUT_XBAR6 (XINT3), INPUT_XBAR13 (XINT4), and INPUT_XBAR14 (XINT5) support external interrupts.[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
            .externalIntEnable = [!IF "CddXbarExternalInterruptEdge != 'CDD_XBAR_INT_TYPE_DISABLED'"!] TRUE[!ELSE!][!WS "1"!]FALSE[!ENDIF!],
            .externalIntNum = CDD_XBAR_[!IF "text:contains(ecu:list('ResourceAllocator_F29H85x.Cdd_Xbar_External_Interrupt_Input_Xbar'), CddXbarInputXbarInput)"!][!"ecu:get(concat('ResourceAllocator_F29H85x.Cdd_Xbar_External_Interrupt.', node:value(CddXbarInputXbarInput)))"!][!ELSE!]XINT_DISABLED[!ENDIF!],
            .externalIntrEdge = [!"node:value(CddXbarExternalInterruptEdge)"!],
            .selectConfigLock = [!"text:toupper(CddXbarInputXbarInputSelectConfigurationLock)"!],   /* Design: MCAL-25707 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25708 */
    .outConfigLock = [!"text:toupper(CddXbarOutputXbarConfig/CddXbarOutputXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarOutputXbarConfig/CddXbarOutputXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_OutputCfg =
    {
[!LOOP "CddXbarOutputXbarConfig/CddXbarOutputXbarInstanceConfig/*/CddXbarOutputXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarOutputXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarOutputXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!] 
            .outputLine = [!"../CddXbarOutputXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputStretchPulse = [!"../CddXbarOutputXbarOutputPulseStretch"!],    /* Design: MCAL-25719 */
            .outputInversion = [!"text:toupper(../CddXbarOutputXbarOutputInversion)"!],    /* Design: MCAL-25713 */
            .outputLatch = [!"text:toupper(../CddXbarOutputXbarOutputLatch)"!],    /* Design: MCAL-25718 */
            .outputInversionBeforeLatch = [!"text:toupper(../CddXbarOutputXbarOutputFlagConfig/CddXbarOutputXbarInversionBeforeLatch)"!],    /* Design: MCAL-25814 */
            .outputFlag = [!"../CddXbarOutputXbarOutputFlagConfig/CddXbarOutputXbarOutputLatchInitSts"!],    /* Design: MCAL-25813 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25709 */
    .epwmConfigLock = [!"text:toupper(CddXbarEpwmXbarConfig/CddXbarEpwmXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarEpwmXbarConfig/CddXbarEpwmXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_EpwmCfg =
    {
[!LOOP "CddXbarEpwmXbarConfig/CddXbarEpwmXbarInstanceConfig/*/CddXbarEpwmXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarEpwmXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarEpwmXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarEpwmXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarEpwmXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
    /* Design: MCAL-25710 */
    .clbConfigLock = [!"text:toupper(CddXbarClbXbarConfig/CddXbarClbXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarClbXbarConfig/CddXbarClbXbarInstanceConfig/*))>0"!]
    /* Design: MCAL-25702 */
    .Cdd_Xbar_ClbCfg =
    {
[!LOOP "CddXbarClbXbarConfig/CddXbarClbXbarInstanceConfig/*/CddXbarClbXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarClbXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarClbXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarClbXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarClbXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
    /* Design: MCAL-25711 */
    .mindbConfigLock = [!"text:toupper(CddXbarMindbXbarConfig/CddXbarMindbXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarMindbXbarConfig/CddXbarMindbXbarInstanceConfig/*))>0"!]
    /* Design: MCAL-25702 */
    .Cdd_Xbar_MindbCfg =
    {
[!LOOP "CddXbarMindbXbarConfig/CddXbarMindbXbarInstanceConfig/*/CddXbarMindbXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarMindbXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarMindbXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarMindbXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarMindbXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25712 */
    .iclConfigLock = [!"text:toupper(CddXbarIclXbarConfig/CddXbarIclXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarIclXbarConfig/CddXbarIclXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_IclCfg =
    {
[!LOOP "CddXbarIclXbarConfig/CddXbarIclXbarInstanceConfig/*/CddXbarIclXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarIclXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarIclXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarIclXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarIclXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
[!IF "num:i(count(CddXbarOutputXbarConfig/CddXbarOutputXbarInstanceConfig/*))>0"!]
    .outputXbarFlagBaseAddress = (uint32)[!"node:ref(as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/CddXbarGeneral/CddXbarOutputXbarFlag)/BaseAddr"!],
[!ENDIF!]
[!IF "as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/CddXbarGeneral/CddXbarInputFlagApi = 'true'"!]
    .inputFlagBaseAddress = (uint32)[!"node:ref(as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/CddXbarGeneral/CddXbarInputFlag)/BaseAddr"!],
[!ENDIF!]
};
[!ENDSELECT!]

#define CDD_XBAR_STOP_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Cfg.c
 *********************************************************************************************************************/
