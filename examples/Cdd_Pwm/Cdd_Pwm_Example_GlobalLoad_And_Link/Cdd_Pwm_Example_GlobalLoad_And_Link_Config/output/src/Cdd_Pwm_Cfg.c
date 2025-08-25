
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
#if ((CDD_PWM_SW_MAJOR_VERSION != (2U)) || CDD_PWM_SW_MINOR_VERSION != (0U))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm.h are inconsistent!"
#endif

#if ( (CDD_PWM_CFG_MAJOR_VERSION != (2U)) \
    ||(CDD_PWM_CFG_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Pwm_Cfg.c and Cdd_Pwm_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_BASEADDR_STEP             (EPWM2_BASE - EPWM1_BASE)


#define CDD_PWM_XLINK_BASEADDR_STEP       (EPWM2XLINK_BASE - EPWM1XLINK_BASE)


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
    
    .xlink_hwmask = 
    {
                        
        [0] = (uint32)(15U)
    },
    .hwunitcfg = 
    {        
        [0] =
        {
            /* HwunitId: EPWM1 */
            .instance_id = (uint8)(1U),
            .base_addr = (EPWM1_BASE + (CDD_PWM_BASEADDR_STEP*0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit0Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [1] =
        {
            /* HwunitId: EPWM2 */
            .instance_id = (uint8)(2U),
            .base_addr = (EPWM1_BASE + (CDD_PWM_BASEADDR_STEP*1U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit1Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [2] =
        {
            /* HwunitId: EPWM3 */
            .instance_id = (uint8)(3U),
            .base_addr = (EPWM1_BASE + (CDD_PWM_BASEADDR_STEP*2U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit2Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },
        [3] =
        {
            /* HwunitId: EPWM4 */
            .instance_id = (uint8)(4U),
            .base_addr = (EPWM1_BASE + (CDD_PWM_BASEADDR_STEP*3U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = (Cdd_Pwm_NotificationType)(Cdd_Pwm_HwUnit3Notification),
            .tripzone_notification = (Cdd_Pwm_TripZoneNotificationType)(NULL_PTR)
            #endif
        },        
        [4] =
        {
            /* XLINK HwunitId: EPWM1 */
            .instance_id = (uint8)(1U),
            .base_addr = (EPWM1XLINK_BASE + (CDD_PWM_XLINK_BASEADDR_STEP*0U)),
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            .notification = NULL_PTR,
            .tripzone_notification = NULL_PTR
            #endif
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
