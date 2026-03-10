[!SKIPFILE "node:value(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *  File:       Cdd_Pwm_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Cdd_Pwm configuration source file                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
#if ((CDD_PWM_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    || (CDD_PWM_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm.h are inconsistent!"
#endif

#if ( (CDD_PWM_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    ||(CDD_PWM_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm_Cfg.h are inconsistent!"
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
 * Exported Object Definitions
 *********************************************************************************************************************/

[!VAR "ChannelCount" = "num:i(0)"!]

/** \brief Cdd Pwm Driver configuration */
#define CDD_PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"[!//

[!LOOP "as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/CddPwmConfigSet"!][!//
[!IF "node:value(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/CddPwmConfigSet/CddPwmAdvancedMode) = 'false'"!]
/* Driver configuration structure in simple mode */
CONST(Cdd_Pwm_ConfigType, CDD_PWM_CONFIG_DATA) Cdd_Pwm_Config =
{
    .hwunitcfg = 
    {[!//
        [!LOOP "CddPwmHwUnitConfig/*"!]
        [[!"@index"!]] =
        {

            /* HwunitId: EPWM[!"node:value(CddPwmInstance)"!] */
            .instance_id = (uint8)([!"CddPwmInstance"!]U),
            .channelclass = (Cdd_Pwm_ChannelClassType)[!"CddPwmOutputClass"!],
            .symmetry = [!"CddPwmSymmetry"!],
            .period = (Cdd_Pwm_PeriodType)[!"CddPwmDefaultPeriod"!]U,
            .enable_interrupt = (boolean)([!"num:i(node:when((CddPwmInterruptEnable = 'false'),0,1))"!]U),
            .clockdivider = (Cdd_Pwm_ClockDividerType)[!"CddPwmClockDivider"!],
            .highspeed_clkdiv = (Cdd_Pwm_HighSpeedClkDivType)[!"CddPwmHighSpeedClockDivider"!],
            .base_addr = (uint32)([!"node:value(node:ref(CddPwmInstanceRef)/BaseAddr)"!]),
            .startchannel = (Cdd_Pwm_ChannelType)([!"num:i($ChannelCount)"!]U),
            .lastchannel = (Cdd_Pwm_ChannelType)([!"num:i($ChannelCount + num:i(count(CddPwmOutputChannel/*))-1)"!]U),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)([!IF "node:exists(CddPwmInterruptNotification)"!][!"CddPwmInterruptNotification"!][!ELSE!]NULL_PTR[!ENDIF!]),
            #endif
            .emulation_mode = (Cdd_Pwm_EmulationModeType)([!"node:value(CddPwmEmulationMode)"!])
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!VAR "ChannelCount" = "num:i($ChannelCount + num:i(count(CddPwmOutputChannel/*)))"!][!ENDLOOP!]
    },
    .channelcfg  =
    {[!//
        [!VAR "CddPwmChannelCount"="num:i(0)"!][!LOOP "CddPwmHwUnitConfig/*/CddPwmOutputChannel/*"!]
        [[!"num:i($CddPwmChannelCount)"!]] =
        {
            /* HwunitId: EPWM[!"node:value(../../CddPwmInstance)"!] */
            .hw_index = (Cdd_Pwm_InstanceType)[!"num:i(node:pos(../../.))"!]U,
            .outputchannel = (Cdd_Pwm_OutputChannelType)[!"CddPwmChannel"!],
            .idlestate = (Cdd_Pwm_OutputStateType)[!"CddPwmIdleState"!],
            .polarity = (Cdd_Pwm_OutputStateType)[!"CddPwmPolarity"!],
            .dutycycle = (Cdd_Pwm_DutyCycleType)[!"CddPwmDefaultDutyCycle"!]U
        }[!VAR "CddPwmChannelCount"="num:i($CddPwmChannelCount+1)"!][!IF "$CddPwmChannelCount < num:i(count(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmOutputChannel/*))"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    }
};[!//

[!ELSE!]
[!VAR "CddPwmHwUnitCount" = "num:i(count(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/CddPwmConfigSet/CddPwmHwUnitConfig/*))"!]
/* Driver configuration structure in advanced mode */
CONST(Cdd_Pwm_ConfigType, CDD_PWM_CONFIG_DATA) Cdd_Pwm_Config =
{
    [!IF "(num:i(count(CddPwmXlinkConfig/*)) > 0)"!]
    .xlink_hwmask = 
    {
        [!LOOP "CddPwmXlinkConfig/*"!][!//
        [!VAR "hw_mask" = "num:i(0)"!][!//
        [!LOOP "CddPwmLinkHwUnit/*"!][!VAR "hw_mask" = "bit:or(bit:bitset(0,num:i(node:pos(node:path(node:ref(CddPwmHwUnit))))),$hw_mask)"!][!ENDLOOP!]
        [[!"@index"!]] = (uint32)([!"num:i($hw_mask)"!]U)[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },[!ENDIF!]
    [!IF "(num:i(count(CddPwmHrpwmCalibrationConfig/*)) > 0)"!]
    .hrpwmcal_baseaddr = 
    {[!//
        [!LOOP "CddPwmHrpwmCalibrationConfig/*/CddPwmHrpwmCalConfig/*"!]
        [[!"@index"!]] = ((uint32)[!"node:value(node:ref(CddPwmHrpwmCalInstanceRef)/BaseAddr)"!])[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },[!ENDIF!]
    .hwunitcfg = 
    {[!//
        [!LOOP "CddPwmHwUnitConfig/*"!]
        [[!"@index"!]] =
        {
            /* HwunitId: EPWM[!"node:value(CddPwmInstance)"!] */
            .instance_id = (uint8)([!"CddPwmInstance"!]U),
            .base_addr = (uint32)([!"node:value(node:ref(CddPwmInstanceRef)/BaseAddr)"!]),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)([!IF "not(node:empty(CddPwmInterruptNotification))"!][!"CddPwmInterruptNotification"!][!ELSE!]NULL_PTR[!ENDIF!]),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)([!IF "not(node:empty(CddPwmTripZoneNotification))"!][!"CddPwmTripZoneNotification"!][!ELSE!]NULL_PTR[!ENDIF!])
            #endif
        },[!ENDLOOP!][!//
        [!LOOP "CddPwmXlinkConfig/*"!]
        [[!"num:i(num:i(@index) + num:i($CddPwmHwUnitCount))"!]] =
        {
            /* XLINK HwunitId: [!"node:value(node:ref(CddPwmXlinkInstanceRef)/InstanceName)"!]XLINK */
            .instance_id = (uint8)([!"num:i(substring-after(node:value(node:ref(CddPwmXlinkInstanceRef)/InstanceName),'EPWM'))"!]U),
            .base_addr = (uint32)([!"node:value(node:ref(CddPwmXlinkInstanceRef)/XlinkBaseAddr)"!]),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = NULL_PTR,
            .tripzone_notification = NULL_PTR
            #endif
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    }
};[!//

[!ENDIF!]

[!ENDLOOP!]


#define CDD_PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"

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
 *  End of File: Cdd_Pwm_Cfg.c
 *********************************************************************************************************************/
