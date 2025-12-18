
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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
#if ((CDD_PWM_SW_MAJOR_VERSION != (3U)) \
    || (CDD_PWM_SW_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm.h are inconsistent!"
#endif

#if ( (CDD_PWM_CFG_MAJOR_VERSION != (3U)) \
    ||(CDD_PWM_CFG_MINOR_VERSION != (0U)))
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



/** \brief Cdd Pwm Driver configuration */
#define CDD_PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"

/* Driver configuration structure in simple mode */
CONST(Cdd_Pwm_ConfigType, CDD_PWM_CONFIG_DATA) Cdd_Pwm_Config =
{
    .hwunitcfg = 
    {        
        [0] =
        {

            /* HwunitId: EPWM1 */
            .instance_id = (uint8)(1U),
            .channelclass = (Cdd_Pwm_ChannelClassType)CDD_PWM_FIXED_PERIOD,
            .symmetry = CDD_PWM_ASYMMETRIC_WAVEFORM,
            .period = (Cdd_Pwm_PeriodType)500U,
            .enable_interrupt = (boolean)(0U),
            .clockdivider = (Cdd_Pwm_ClockDividerType)CDD_PWM_CLOCK_DIVIDER_1,
            .highspeed_clkdiv = (Cdd_Pwm_HighSpeedClkDivType)CDD_PWM_HSCLOCK_DIVIDER_1,
            .base_addr = (uint32)(EPWM1_BASE_FRAME(0U)),
            .startchannel = (Cdd_Pwm_ChannelType)(0U),
            .lastchannel = (Cdd_Pwm_ChannelType)(0U),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(NULL_PTR),
            #endif
            .emulation_mode = (Cdd_Pwm_EmulationModeType)(CDD_PWM_EMULATION_STOP_AFTER_NEXT_TB)
        }
    },
    .channelcfg  =
    {        
        [0] =
        {
            /* HwunitId: EPWM1 */
            .hw_index = (Cdd_Pwm_InstanceType)0U,
            .outputchannel = (Cdd_Pwm_OutputChannelType)CDD_PWM_OUTPUT_A,
            .idlestate = (Cdd_Pwm_OutputStateType)CDD_PWM_LOW,
            .polarity = (Cdd_Pwm_OutputStateType)CDD_PWM_HIGH,
            .dutycycle = (Cdd_Pwm_DutyCycleType)8192U
        }
    }
};





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
