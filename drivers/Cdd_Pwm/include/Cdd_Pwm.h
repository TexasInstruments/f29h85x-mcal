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
 *  File:       Cdd_Pwm
 *  Generator:  None
 *
 *  Description:  This file contains CDD PWM driver public API function declarations.
 *********************************************************************************************************************/
#ifndef CDD_PWM_H
#define CDD_PWM_H

/**
 * \defgroup CDD_PWM Cdd_Pwm API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* Defines for CDD_PWM Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_PWM_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_PWM_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_PWM_SW_PATCH_VERSION (0U)

/*  Defines for CDD_PWM Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_REVISION_VERSION (1U)

/* CDD PWM Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_PWM_VENDOR_ID ((uint16)44U)
/** \brief CDD PWM Driver Module ID */
#define CDD_PWM_MODULE_ID ((uint16)255U)
/** \brief CDD PWM Instance ID */
#define CDD_PWM_INSTANCE_ID ((uint8)0U)

/* Error codes returned by Cdd Pwm functions. */

/** \brief API service used without module initialization */
#define CDD_PWM_E_UNINIT ((uint8)0x0AU)
/** \brief API Cdd_Pwm_Init service called while the PWM driver has already been initialized */
#define CDD_PWM_E_ALREADY_INITIALIZED ((uint8)0x0BU)
/** \brief  API service called with invalid pointer */
#define CDD_PWM_E_PARAM_POINTER ((uint8)0x0CU)
/** \brief  API service called with invalid parameter ID */
#define CDD_PWM_E_INVALID_ID ((uint8)0x0DU)
/** \brief Enable/disable notification function for a PWM instance whose configuration set has no
 * notification available */
#define CDD_PWM_E_NOTIF_CAPABILITY ((uint8)0x0EU)
/** \brief  API service called for the instance whose channel class is not variable period */
#define CDD_PWM_E_CHANNEL_CLASS ((uint8)0x0FU)
/** \brief API service called when the notification is already enabled */
#define CDD_PWM_E_NOTIF_ALREADY_ENABLED ((uint8)0x10U)
/** \brief API service called when the channel configured for the notification is invalid */
#define CDD_PWM_E_INVALID_CHANNEL_NOTIFICATION ((uint8)0x11U)
/** \brief API service called when the edge notification type is not valid */
#define CDD_PWM_E_INVALID_NOTIFICATION ((uint8)0x12U)
/** \brief API service called when the event count is invalid/out-of-range */
#define CDD_PWM_E_INVALID_EVENT_COUNT ((uint8)0x13U)
/** \brief API service called with the invalid duty cycle value */
#define CDD_PWM_E_INVALID_DUTY_CYCLE ((uint8)0x14U)

/* The Service Id is one of the argument to Det_ReportError function and is used to identify the
 * source of the error */
/** \brief Cdd_Pwm_Init() API Service ID */
#define CDD_PWM_SID_INIT ((uint8)0x00U)
/** \brief Cdd_Pwm_DeInit() API Service ID */
#define CDD_PWM_SID_DEINIT ((uint8)0x01U)
/** \brief Cdd_Pwm_SetDutyCycle() API Service ID */
#define CDD_PWM_SID_SET_DUTY_CYCLE ((uint8)0x02U)
/** \brief Cdd_Pwm_SetPeriod() API Service ID */
#define CDD_PWM_SID_SET_PERIOD ((uint8)0x03U)
/** \brief Cdd_Pwm_SetOutputToIdle() API Service ID */
#define CDD_PWM_SID_SET_OUTPUT_TO_IDLE ((uint8)0x04U)
/** \brief Cdd_Pwm_EnableNotification() API Service ID */
#define CDD_PWM_SID_ENABLE_NOTIFICATION ((uint8)0x05U)
/** \brief Cdd_Pwm_DisableNotification() API Service ID */
#define CDD_PWM_SID_DISABLE_NOTIFICATION ((uint8)0x06U)
/** \brief Cdd_Pwm_GetVersionInfo() API Service ID */
#define CDD_PWM_SID_GET_VERSION_INFO ((uint8)0x07U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Numeric Identifier of a PWM channel */
typedef uint8 Cdd_Pwm_ChannelType;

/** \brief Numeric Identifier of a PWM instance */
typedef uint8 Cdd_Pwm_InstanceType;

/** \brief Period of the PWM instance */
typedef uint16 Cdd_Pwm_PeriodType;

/** \brief Duty cycle of the PWM channel */
typedef uint16 Cdd_Pwm_DutyCycleType;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Notification function pointer */
typedef P2FUNC(void, CDD_PWM_CODE, Cdd_Pwm_NotificationType)(void);
#endif

/** \brief Output Status type */
typedef enum
{
    CDD_PWM_HIGH, /*!< \brief  The PWM channel is in high state. */
    CDD_PWM_LOW   /*!< \brief  The PWM channel is in low state. */
} Cdd_Pwm_OutputStateType;

/** \brief Edge notification type */
typedef enum
{
    CDD_PWM_RISING_EDGE,  /*!< \brief Notification will be called when a rising edge occurs on the
                             PWM output signal */
    CDD_PWM_FALLING_EDGE, /*!< \brief Notification will be called when a falling edge occurs on the
                             PWM output signal*/
    /*!< \brief Notification will be called when either a rising edge or falling edge occur on the
       PWM output signal */
    CDD_PWM_BOTH_EDGES,
    CDD_PWM_EDGE_NONE /*!< \brief No notification will be called */
} Cdd_Pwm_EdgeNotificationType;

/** \brief Channel class type */
typedef enum
{
    /** \brief The PWM channel has a variable period. The duty cycle and the period can be changed.
     */
    CDD_PWM_VARIABLE_PERIOD,
    /** \brief The PWM channel has a fixed period. Only the duty cycle can be changed */
    CDD_PWM_FIXED_PERIOD
} Cdd_Pwm_ChannelClassType;

/** \brief Enumeration to define the output channel type for the notification */
typedef enum
{
    CDD_PWM_CHANNEL_A,    /** \brief Up - count mode */
    CDD_PWM_CHANNEL_B,    /** \brief Down - count mode */
    CDD_PWM_BOTH_A_AND_B, /** \brief Up - down - count mode */
    CDD_PWM_NONE          /** \brief Stop - Freeze counter */
} Cdd_Pwm_NotificationChannelType;

/* Pwm channel configation */
typedef struct Cdd_Pwm_ChannelCfgTag
{
    /* PMW instance index*/
    uint8                    hw_index;
    /* Output type of the channel */
    Cdd_Pwm_OuputChannelType outputchannel;
    /* Default duty cycle */
    Cdd_Pwm_DutyCycleType    dutycycle;
    /* Idle state of the PWM channel */
    Cdd_Pwm_OutputStateType  idlestate;
    /* Polarity of the PWM channel (Active Low or Active High) */
    Cdd_Pwm_OutputStateType  polarity;
} Cdd_Pwm_ChannelCfgType;

/* PWM Hardware unit configuration */
typedef struct Cdd_Pwm_HwUnitCfgTag
{
    /* PWM instance ID */
    uint8                     instance_id;
    /* Class type of the PWM channel */
    Cdd_Pwm_ChannelClassType  channelclass;
    /* Clock divider is time base clock divider multiplied with high speed clock
     * divider(CLKDIV*HSPCLKDIV) */
    uint8                     clockdivider;
    /* Phase shift of the PWM channel */
    uint16                    phaseshift;
    /* Default period */
    Cdd_Pwm_PeriodType        period;
    /* Base address of the PWM channel */
    uint32                    base_addr;
    /* Symmetry of the waveform */
    Cdd_Pwm_OuputSymmetryType symmetry;
    /* Interrupt enable/disable */
    boolean                   enable_interrupt;
    /* Starting channel ID  */
    uint8                     startchannel;
    /* Last channel ID */
    uint8                     lastchannel;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Idle state of the PWM channel */
    Cdd_Pwm_NotificationType notification;
#endif
} Cdd_Pwm_HwUnitCfgType;

/** \brief PWM driver configuration */
typedef struct Cdd_Pwm_ConfigTag
{
    /** \brief  PWM hardware instance configurations */
    Cdd_Pwm_HwUnitCfgType  hwunitcfg[CDD_PWM_COUNT];
    /** \brief  Channel configurations */
    Cdd_Pwm_ChannelCfgType channelcfg[CDD_PWM_CHANNEL_COUNT];
} Cdd_Pwm_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service to initialize Cdd Pwm driver.
 *
 * This service initializes all the PWM channels with the configured values.
 *
 * \param[in] CfgPtr Pointer to configuration set (Variant PC requires a NULL_PTR)
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr);

#if (STD_ON == CDD_PWM_DEINIT_API)
/** \brief Service to deinitialize Cdd Pwm driver.
 *
 * This service de-initializes the PWM driver.
 *
 * \param[in] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DeInit(void);
#endif

#if (STD_ON == CDD_PWM_SET_DUTY_CYCLE_API)
/** \brief Service to set the duty cycle
 *
 * This service sets the duty cycle for the requested PWM Channel.
 *
 * \param[in] ChannelNumber     Numeric ID of the requested PWM Channel.
 * \param[in] DutyCycle         Duty cycles for the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelNumber,
                     VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle);
#endif

#if (STD_ON == CDD_PWM_SET_PERIOD_API)
/** \brief Service to set the period and duty cycle for a PWM channel
 *
 * This service sets period and duty cycle for the requested PWM Channel.
 *
 * \param[in] ChannelNumber     Numeric ID of the requested PWM Channel.
 * \param[in] Period            Period for the requested PWM Channel.
 * \param[in] DutyCycle         Duty cycles for the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_PeriodType, AUTOMATIC) Period);
#endif

#if (STD_ON == CDD_PWM_SET_OUTPUT_TO_IDLE_API)
/** \brief Service to set the output to IDLE for a PWM channel
 *
 * This service sets the output to IDLE for the requested PWM Channel.
 *
 * \param[in] ChannelNumber     Numeric ID of the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetOutputToIdle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelNumber);
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Service to enable the PWM signal edge notification according to notification parameter
 *
 * This service enables the PWM signal edge notification according to notification parameter
 *
 * \param[in] ChannelNumber     Numeric ID of the requested PWM Channel.
 * \param[in] Notification      Type of notification
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_NotificationChannelType, AUTOMATIC) Channel,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) Notification,
                           VAR(uint8, AUTOMATIC) IntEvtCount);

/** \brief Service to disable the PWM signal edge notification
 *
 * This service disables signal edge notification for the requested PWM Channels.
 *
 * \param[in] ChannelNumber     Numeric ID of the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_NotificationChannelType, AUTOMATIC) Channel);
#endif

#if (STD_ON == CDD_PWM_VERSION_INFO_API)
/** \brief service that returns the version information of the module.
 *
 * This service returns the version information of the Pwm module.
 *
 * \param[in] VersionInfo    Pointer to where to store the version information of this module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_PWM_DATA) VersionInfo);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_PWM_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm.h
 *********************************************************************************************************************/
