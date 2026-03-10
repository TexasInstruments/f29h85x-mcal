
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


/* Driver configuration structure in advanced mode */
CONST(Cdd_Pwm_ConfigType, CDD_PWM_CONFIG_DATA) Cdd_Pwm_Config =
{
    
    
    .hwunitcfg = 
    {        
        [0] =
        {
            /* HwunitId: EPWM1 */
            .instance_id = (uint8)(1U),
            .base_addr = (uint32)(EPWM1_BASE_FRAME(0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit0Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [1] =
        {
            /* HwunitId: EPWM2 */
            .instance_id = (uint8)(2U),
            .base_addr = (uint32)(EPWM2_BASE_FRAME(0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit1Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [2] =
        {
            /* HwunitId: EPWM3 */
            .instance_id = (uint8)(3U),
            .base_addr = (uint32)(EPWM3_BASE_FRAME(0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit2Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [3] =
        {
            /* HwunitId: EPWM7 */
            .instance_id = (uint8)(7U),
            .base_addr = (uint32)(EPWM7_BASE_FRAME(0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit3Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },        
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
