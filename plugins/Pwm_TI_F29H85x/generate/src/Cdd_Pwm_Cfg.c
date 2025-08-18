[!SKIPFILE "node:value(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
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
#if ((CDD_PWM_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_PWM_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm.h are inconsistent!"
#endif

#if ( (CDD_PWM_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    ||(CDD_PWM_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_BASEADDR_STEP             (EPWM2_BASE - EPWM1_BASE)

[!MACRO "GetLog2", "Value"!]
    [!NOCODE!]
    [!VAR "Log2" = "0"!][!//
    [!FOR "i" = "0" TO "7"!]
        [!IF "num:i($Value) != num:i(1)"!]
            [!VAR "Value"="bit:shr($Value,1)"!]
        [!ELSE!]
            [!VAR "Log2"="num:i($i)"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!"num:i($Log2)"!][!ENDCODE!]
    [!ENDNOCODE!]
[!ENDMACRO!]

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
[!SELECT "as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']"!]
[!VAR "ChannelCount" = "num:i(0)"!]

/** \brief Cdd Pwm Driver configuration */
#define CDD_PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"[!//

CONST(Cdd_Pwm_ConfigType, CDD_PWM_CONFIG_DATA) Cdd_Pwm_ConfigSet =
{
    .hwunitcfg = 
    {[!//
        [!LOOP "CddPwmConfigSet/CddPwmHwUnitConfig/*"!]
        [[!"@index"!]] =
        {
            /* HwunitId: EPWM[!"node:value(CddPwmInstanceId)"!] */
            .instance_id = (uint8)([!"CddPwmInstanceId"!]U),
            .channelclass = (Cdd_Pwm_ChannelClassType)[!"CddPwmOutputClass"!],
            .symmetry = [!"CddPwmSymmetry"!],[!//
            [!VAR "CddPwmClkDiv"!][!CALL "GetLog2", "Value" = "num:i(substring-after(node:value(CddPwmClockDivider),'CDD_PWM_CLK_DIVIDER_'))"!][!ENDVAR!]
            .clockdivider = (uint8)(([!"num:i($CddPwmClkDiv)"!]U << 3U) | [!"num:i(num:i(substring-after(node:value(CddPwmHighSpeedClockDivider),'CDD_PWM_HSCLK_DIVIDER_')) div num:i(2))"!]U),
            .period = (Cdd_Pwm_PeriodType)[!"CddPwmPeriod"!]U,
            .base_addr = (EPWM1_BASE + (CDD_PWM_BASEADDR_STEP*[!"num:i(num:i(CddPwmInstanceId)-num:i(1))"!]U)),
            .enable_interrupt = (boolean)([!"num:i(node:when((CddPwmInterruptEnable = 'false'),0,1))"!]U),
            .startchannel = (Cdd_Pwm_ChannelType)([!"num:i($ChannelCount)"!]U),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)([!IF "node:exists(CddPwmNotification)"!][!"CddPwmNotification"!][!ELSE!]NULL_PTR[!ENDIF!]),
            #endif
            .lastchannel = (Cdd_Pwm_ChannelType)([!"num:i($ChannelCount + num:i(count(CddPwmOutputChannel/*))-1)"!]U)
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!VAR "ChannelCount" = "num:i($ChannelCount + num:i(count(CddPwmOutputChannel/*)))"!][!ENDLOOP!]
    },
    .channelcfg  =
    {[!//
        [!VAR "CddPwmChannelCount"="num:i(0)"!][!LOOP "CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmOutputChannel/*"!]
        [[!"num:i($CddPwmChannelCount)"!]]=
        {
            /* HwunitId: EPWM[!"node:value(../../CddPwmInstanceId)"!] */
            .hw_index = (Cdd_Pwm_InstanceType)[!"num:i(node:pos(../../.))"!]U,
            .outputchannel = (Cdd_Pwm_OuputChannelType)[!"CddPwmChannel"!],
            .idlestate = (Cdd_Pwm_OutputStateType)[!"CddPwmIdleState"!],
            .polarity = (Cdd_Pwm_OutputStateType)[!"CddPwmPolarity"!],
            .dutycycle = (Cdd_Pwm_DutyCycleType)[!"CddPwmDutyCycle"!]U
        }[!VAR "CddPwmChannelCount"="num:i($CddPwmChannelCount+1)"!][!IF "$CddPwmChannelCount < num:i(count(as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']/CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmOutputChannel/*))"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    }
};[!//
[!ENDSELECT!]
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
