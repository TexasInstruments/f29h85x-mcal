
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
#if ((CDD_PWM_SW_MAJOR_VERSION != (3U)) \
    || (CDD_PWM_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm.h are inconsistent!"
#endif

#if ( (CDD_PWM_CFG_MAJOR_VERSION != (3U)) \
    ||(CDD_PWM_CFG_MINOR_VERSION != (1U)))
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
            .channelclass = (Cdd_Pwm_ChannelClassType)CDD_PWM_VARIABLE_PERIOD,
            .symmetry = CDD_PWM_ASYMMETRIC_WAVEFORM,
            .period = (Cdd_Pwm_PeriodType)62499U,
            .enable_interrupt = (boolean)(1U),
            .clockdivider = (Cdd_Pwm_ClockDividerType)CDD_PWM_CLOCK_DIVIDER_16,
            .highspeed_clkdiv = (Cdd_Pwm_HighSpeedClkDivType)CDD_PWM_HSCLOCK_DIVIDER_2,
            .base_addr = (uint32)(EPWM1_BASE_FRAME(0U)),
            .startchannel = (Cdd_Pwm_ChannelType)(0U),
            .lastchannel = (Cdd_Pwm_ChannelType)(1U),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_AsymmetricNotification),
            #endif
            .emulation_mode = (Cdd_Pwm_EmulationModeType)(CDD_PWM_EMULATION_STOP_AFTER_NEXT_TB)
        },

        [1] =
        {

            /* HwunitId: EPWM2 */
            .instance_id = (uint8)(2U),
            .channelclass = (Cdd_Pwm_ChannelClassType)CDD_PWM_FIXED_PERIOD,
            .symmetry = CDD_PWM_SYMMETRIC_WAVEFORM,
            .period = (Cdd_Pwm_PeriodType)12500U,
            .enable_interrupt = (boolean)(1U),
            .clockdivider = (Cdd_Pwm_ClockDividerType)CDD_PWM_CLOCK_DIVIDER_2,
            .highspeed_clkdiv = (Cdd_Pwm_HighSpeedClkDivType)CDD_PWM_HSCLOCK_DIVIDER_2,
            .base_addr = (uint32)(EPWM2_BASE_FRAME(0U)),
            .startchannel = (Cdd_Pwm_ChannelType)(2U),
            .lastchannel = (Cdd_Pwm_ChannelType)(3U),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_SymmetricNotification),
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
            .dutycycle = (Cdd_Pwm_DutyCycleType)16384U
        },

        [1] =
        {
            /* HwunitId: EPWM1 */
            .hw_index = (Cdd_Pwm_InstanceType)0U,
            .outputchannel = (Cdd_Pwm_OutputChannelType)CDD_PWM_OUTPUT_B,
            .idlestate = (Cdd_Pwm_OutputStateType)CDD_PWM_HIGH,
            .polarity = (Cdd_Pwm_OutputStateType)CDD_PWM_LOW,
            .dutycycle = (Cdd_Pwm_DutyCycleType)8192U
        },

        [2] =
        {
            /* HwunitId: EPWM2 */
            .hw_index = (Cdd_Pwm_InstanceType)1U,
            .outputchannel = (Cdd_Pwm_OutputChannelType)CDD_PWM_OUTPUT_A,
            .idlestate = (Cdd_Pwm_OutputStateType)CDD_PWM_LOW,
            .polarity = (Cdd_Pwm_OutputStateType)CDD_PWM_HIGH,
            .dutycycle = (Cdd_Pwm_DutyCycleType)8192U
        },

        [3] =
        {
            /* HwunitId: EPWM2 */
            .hw_index = (Cdd_Pwm_InstanceType)1U,
            .outputchannel = (Cdd_Pwm_OutputChannelType)CDD_PWM_OUTPUT_B,
            .idlestate = (Cdd_Pwm_OutputStateType)CDD_PWM_HIGH,
            .polarity = (Cdd_Pwm_OutputStateType)CDD_PWM_LOW,
            .dutycycle = (Cdd_Pwm_DutyCycleType)24576U
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
