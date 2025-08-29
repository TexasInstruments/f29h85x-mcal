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
 *  File:       Cdd_Ecap_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains CDD ECAP driver private API function declarations .
 *********************************************************************************************************************/
#ifndef CDD_ECAP_PRIV_H
#define CDD_ECAP_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_ecap.h"
#include "hw_types.h"
#include "Mcal_Lib.h"
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_ECAPTIMER_MAX_RESOLUTION (0xFFFFFFFFU) /** \brief CDD ECAP Timer Max Resolution */
#define CDD_ECAPTICKMAXVALUE         (0xF0000000U) /** \brief CDD ECAP Tick Max Value */

#define CDD_ECAP_EVENT_1 ((uint16)(0U)) /** \brief eCAP event 1 */
#define CDD_ECAP_EVENT_2 ((uint16)(1U)) /** \brief eCAP event 2 */
#define CDD_ECAP_EVENT_3 ((uint16)(2U)) /** \brief eCAP event 3 */
#define CDD_ECAP_EVENT_4 ((uint16)(3U)) /** \brief eCAP event 4 */

#define CDD_ECAP_CONTINUOUS_CAPTURE_MODE ((uint16)(0U)) /** \brief eCAP operates in continuous capture mode */
#define CDD_ECAP_ONE_SHOT_CAPTURE_MODE   ((uint16)(1U)) /** \brief eCAP operates in one shot capture mode */
#define CDD_ECAP_COUNTER_STOP            ((uint16)(0U)) /** \brief Counter Mode Stop  */
#define CDD_ECAP_COUNTER_FREE_RUNNING    ((uint16)(1U)) /** \brief Counter Mode Start  */

#define CDD_ECAP_CAPTURE_MODE ((uint16)(0U)) /** \brief Capture Mode  */
#define CDD_ECAP_APWM_MODE    ((uint16)(1U)) /** \brief APWM Mode     */

#define CDD_ECAP_MAX_PRESCALER_VALUE (32U) /** \brief Max Prescalar of CDD_ECAP  */

#define CDD_ECAP_SYSCLK (200000000U) /** \brief  SYSCLK value  */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Channel object structure */
typedef struct Cdd_Ecap_ChannelObjTag
{
#if (CDD_ECAP_TIMESTAMP_API == STD_ON)
    Cdd_Ecap_ValueType *NextTimeStampIndexPtr;
    /** \brief Next time stamp index Pointer for timestamp API */
    uint16              NextTimeStampIndex;
    /** \brief Next time stamp index for timestamp API */
    uint16              TimeStampBufferSize;
    /** \brief Time Stamp buffer size as input from user */
    uint16              NotifyInterval;
    /** \brief Notify Interval number as input from user */
    uint16              NotificationCounter;
    /** \brief Notification counter to compare with NotifyInterval */
    boolean             IsActive;
    /** \brief Set to true when timestamp API is executing */
#endif
#if (CDD_ECAP_SIGNAL_MEASUREMENT_API == STD_ON)
    uint32                 cap1;
    /** \brief Value from capture register 1 */
    uint32                 cap2;
    /** \brief Value from capture register 2 */
    uint32                 cap3;
    /** \brief Value from capture register 3 */
    uint32                 cap4;
    /** \brief Value from capture register 4 */
    uint32                 intrCount;
    /** \brief Interrupt count */
    Cdd_Ecap_DutyCycleType DutyCycle;
    /** \brief Duty Cycle */
    Cdd_Ecap_ValueType     HighTime;
    /** \brief Signal High Time */
    Cdd_Ecap_ValueType     LowTime;
    /** \brief Signal Low Time */
    Cdd_Ecap_ValueType     Period;
    /** \brief Signal period */
    boolean                DutyAcquired;
    /** \brief Set to true when Duty cycle values have been acquired */
    boolean                PeriodAcquired;
    /** \brief Set to true when Period values have been acquired */
    boolean                HighTimeAcquired;
    /** \brief Set to true when high time values have been acquired */
    boolean                LowTimeAcquired;
    /** \brief Set to true when low time values have been acquired */
#endif
    Cdd_Ecap_InputStateType InputState;
    /** \brief Variable for input state of module */
#if (CDD_ECAP_EDGE_COUNT_API == STD_ON)
    Cdd_Ecap_EdgeNumberType EdgeCounter;
    /** \brief Counter for edge count */
#endif
    Cdd_Ecap_ActivationType       activation_edge;
    /** \brief Activation edge type for module */
    Cdd_Ecap_StartLevelType       StartLevel;
    /** \brief Start edge type for module */
    boolean                       IsRunning;
    /** \brief Set to true when operation in in progress */
    boolean                       NotificationEnabled;
    /** \brief Set to true when notification are enabled */
    Cdd_Ecap_ChannelPrescalerType prescaler;
/** \brief Prescaler value */
/** \brief Channel configurations */
#if (STD_ON == CDD_ECAP_HR_API)
    /** \brief Interrupt count for HR mode */
    uint32  intHr;
    /** \brief sysclkcount for HR mode */
    uint32  sysclkCount;
    /** \brief hrclkcount for HR mode */
    uint32  hrclkCount;
    /** \brief To check if the calibration is done or not in HR mode */
    boolean calDone;
    /** \brief Scale factor value */
    float32 scaleFactor;
#endif
} Cdd_Ecap_DrvObjType;

/** \brief CDD ECAP configuration structure internal to driver */
typedef struct
{
    /** \brief ECAP channel object */
    Cdd_Ecap_DrvObjType chObj[CDD_ECAP_HW_CNT];
    /** \brief ECAP channel Index */
    uint8               channelIdx[CDD_ECAP_MAX_NUM_CHANNELS];
} Cdd_Ecap_ChObjType;

/**
 *  \brief This type defines Counter Reset Mode
 */
typedef enum
{
    CDD_ECAP_ABSOLUTE_MODE,
    /** \brief Don't Reset counter upon counter event*/
    CDD_ECAP_DELTA_MODE
    /** \brief Reset upon counter capture event */
} Cdd_Ecap_CounterRstType;

extern volatile uint8 Cdd_Ecap_DrvStatus;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/**
 * \brief   This API will reset CDD ECAP s/w channel object.
 *
 * \return  None.
 *
 **/
void Cdd_Ecap_ResetChObj(void);

/**
 * \brief   This API will copy all channel configuration into local ECAP Object
 *
 * \param[in]  chObj      Pointer to driver object.
 * \param[in]  chCfg      Pointer to configuration object sent by application.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_CopyConfig(Cdd_Ecap_ChObjType *chObj, const Cdd_Ecap_ConfigType *chCfg);

/**
 * \brief   This API will initialize ECAP channel object associated with logical
 *          channel.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_HwUnitInit(void);

#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
/**
 * \brief   This API will Clears the Signal Measurment API Structure
 *
 * \param[in]   Channel      CDD ECAP Channel in Use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_SignalMeasurement_Init(Cdd_Ecap_ChannelType Channel);
#endif

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
/**
 * \brief   This API will Init the Timestamp API Structure
 *
 * \param[in]   Channel         CDD ECAP Channel in Use
 * \param[in]   StartPtr        Start of the Buffer ptr
 * \param[in]   Size            Size of the Buffer to use
 * \param[in]   NotifyInterval  Notify Inerval
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_TimeStamp_Init(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType *StartPtr, uint16 Size,
                             uint16 NotifyInterval);
/**
 * \brief   This API will be called by ISR for timestamp API
 *
 * \param[in]   Channel         ECAP Channel in Use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_Timestamp_ISR(Cdd_Ecap_ChannelType Channel);
/**
 * \brief   This API will clear the timestamp structure
 *
 * \param[in]   Channel         ECAP Channel in Use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_TimeStamp_Clear(Cdd_Ecap_ChannelType Channel);
#endif

/**
 * \brief   This API will configure the ECAP module
 *
 * \param[in]   baseAddr      Baseaddress of channel
 * \param[in]   activation    Activation Edge type
 * \param[in]   cntRst        Counter Reset Mode
 * \param[in]   interruptEnable  Interrupt Enable
 * \param[in]   capture       Capture Mode
 * \param[in]   Channel       Channel number
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_ConfigEcap(uint32 baseAddr, Cdd_Ecap_ActivationType activation, Cdd_Ecap_CounterRstType cntRst,
                         boolean interruptEnable, Cdd_Ecap_IntrCapSelect capture, uint32 Channel);

/**
 * \brief   This is the Channel ISR
 *
 * \param[in]   Channel       Channel number
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_ChannelISR(Cdd_Ecap_ChannelType Channel);
/**
 * \brief   This is the Channel ISR for HR mode
 *
 * \param[in]   Channel     Channel number
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HR_ISR(Cdd_Ecap_ChannelType Channel);
/**
 * \brief   This will select ECAP Input.
 *
 * \param[in]        input               Cdd Ecap Input
 * \param[in]       base                Baseaddress of channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_selectECAPInput(uint32 base, Cdd_Ecap_InputSelect input);
/**
 * \brief   This function disables capture loading
 *
 * \param[in]   baseAddr   It is the Memory address of the ECAP instance used.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_captureLoadingDisable(uint32 baseAddr);
/**
 * \brief   This function disables the specified interrupts
 *
 * \param[in]   baseAddr  It is the Memory address of the ECAP instance used.
 * \param[in]   flag      It is the value which specifies the interrupts to be disabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_intrDisable(uint32 baseAddr, uint32 flag);
/**
 * \brief   This function clears of the status specified interrupts
 *
 * \param[in]   baseAddr  It is the Memory address of the ECAP instance used.
 * \param[in]   flag      It is the value which specifies the status of interrupts to be cleared.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_intrStatusClear(uint32 baseAddr, uint16 flag);
/**
 * \brief   This function resets the MOD counter of the given channel.
 *
 * \param[in]   baseAddr  It is the Memory address of the ECAP instance used.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_reArm(uint32 baseAddr);

#if (STD_ON == CDD_ECAP_HR_API)
/** \brief Service to enable high resolution capability for the given HRCAP channel.
 *
 * This service enables high resolution capability for the given HRCAP channel.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_enableHighResolution(uint32 baseAddr);

/** \brief Service to disable high resolution capability for the given HRCAP channel.
 *
 * This service disables high resolution capability for the given HRCAP channel.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_disableHighResolution(uint32 baseAddr);

/** \brief Service to enable the high resolution clock for the given HRCAP channel.
 *
 * This service enables the high resolution clock for the given HRCAP channel.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_enableHighResolutionClock(uint32 baseAddr);

/** \brief Service to disable the high resolution clock for the given HRCAP channel.
 *
 * This service disables the high resolution clock for the given HRCAP channel.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_disableHighResolutionClock(uint32 baseAddr);

/** \brief Service to start the calibration process for high resolution capability.
 *
 * This service starts the calibration process for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_startCalibration(uint32 baseAddr);

/** \brief Service to set the calibration mode for high resolution capability.
 *
 * This service sets the calibration mode for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_setCalibrationMode(uint32 baseAddr);

/** \brief Service to enable the calibration interrupt for high resolution capability.
 *
 * This service enables the calibration interrupt for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] intFlags   The interrupt flags to be enabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_enableCalibrationInterrupt(uint32 baseAddr, uint16 intFlags);

/** \brief Service to disable the calibration interrupt for high resolution capability.
 *
 * This service disables the calibration interrupt for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] intFlags   The interrupt flags to be disabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_disableCalibrationInterrupt(uint32 baseAddr, uint16 intFlags);

/** \brief Service to retrieve the calibration flags for high resolution capability.
 *
 * This service retrieves the calibration flags for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_ChannelHrInterruptType, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_getCalibrationFlags(uint32 baseAddr);

/** \brief Service to clear the calibration flags for high resolution capability.
 *
 * This service clears the calibration flags for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] flags      The flags to be cleared.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_clearCalibrationFlags(uint32 baseAddr, uint16 flags);

/** \brief Service to check if the calibration process is busy for high resolution capability.
 *
 * This service checks if the calibration process is busy for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_isCalibrationBusy(uint32 baseAddr);

/** \brief Service to force the calibration flags for high resolution capability.
 *
 * This service forces the calibration flags for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] flags      The flags to be forced.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_forceCalibrationFlags(uint32 baseAddr, uint16 flags);

/** \brief Service to set the calibration period for high resolution capability.
 *
 * This service sets the calibration period for high resolution capability, it sets that to 1.6 ms.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] sysclkHz   The system clock frequency in Hz
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_setCalibrationPeriod(uint32 baseAddr, uint32 sysclkHz);

/** \brief Service to configure the calibration period for high resolution capability.
 *
 * This service configures the calibration period for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] sysclkHz   The system clock frequency in Hz
 * \param[in] periodInMs  The calibration period in milliseconds
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_HRCAP_configCalibrationPeriod(uint32 baseAddr, uint32 sysclkHz, float32 periodInMs);

/** \brief Service to retrieve the calibration clock period for high resolution capability.
 *
 * This service retrieves the calibration clock period for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] ClockSource  The clock source for calibration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_ValueType, CDD_ECAP_CODE)
Cdd_Ecap_HRCAP_getCalibrationClockPeriod(uint32 baseAddr, Cdd_Ecap_HrCap_CalibrationClockSource ClockSource);

/** \brief Service to retrieve the scale factor for high resolution capability.
 *
 * This service retrieves the scale factor for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] Channel  The channel for which the scale factor is to be retrieved.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_ChannelHrScaleType, CDD_ECAP_CODE)
Cdd_Ecap_HRCAP_getScaleFactor(uint32 baseAddr, Cdd_Ecap_ChannelType Channel);

/** \brief Service to convert the event timestamp to nanoseconds for high resolution capability.
 *
 * This service converts the event timestamp to nanoseconds for high resolution capability.
 *
 * \param[in] baseAddr   The base address of the HRCAP channel.
 * \param[in] scaleFactor  The scale factor for conversion.
 * \param[in] timestamp   Event timestamp
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_ChannelHrScaleType, CDD_ECAP_CODE)
Cdd_Ecap_HRCAP_convertEventTimeStamp(uint32 baseAddr, uint32 timestamp, float32 scaleFactor);
#endif
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CDD_ECAP_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Priv.h
 *********************************************************************************************************************/
