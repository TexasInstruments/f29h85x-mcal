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

/** \addtogroup CDD_ECAP
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_ecap.h"
#include "hw_types.h"
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

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief CDD ECAP configuration structure internal to driver */
typedef struct
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
    uint32                        baseAddr;
    /** \brief Base address of the ECAP Channel being used*/
    Cdd_Ecap_ChannelPrescalerType prescaler;
    /** \brief Prescaler value */
    Cdd_Ecap_ChannelConfigType    chCfg;
    /** \brief Channel configurations */
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

/**
 *  \brief This defines the available emulation modes
 */
typedef enum
{
    /** \brief TSCTR is stopped on emulation suspension */
    CDD_ECAP_EMULATION_STOP = 0x0U,
    /** \brief runs until 0 before stopping on emulation suspension */
    CDD_ECAP_EMULATION_RUN_TO_ZERO = 0x1U,
    /** \brief is not affected by emulation suspension */
    CDD_ECAP_EMULATION_FREE_RUN = 0x2U
} Cdd_Ecap_EmulationMode;

extern Cdd_Ecap_ChObjType Cdd_Ecap_ChObj[CDD_ECAP_HW_CNT];
/** \brief Cdd_Ecap_ChObj is not static storage class, as this requires to be accessed by
    debug interface provided. */

extern volatile uint8 Cdd_Ecap_DrvStatus;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/**
 * \brief   This API will reset CDD ECAP s/w channel object.
 *
 * \param[in]   chObj       Pointer to channel object.
 *
 * \return  None.
 *
 **/
void Cdd_Ecap_ResetChObj(Cdd_Ecap_ChObjType *chObj);

/**
 * \brief   This API will copy all channel configuration into local ECAP Object
 *
 * \param[in]  chObj      Pointer to driver object.
 * \param[in]  chCfg     Pointer to configuration object sent by application.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_CopyConfig(Cdd_Ecap_ChObjType *chObj, const Cdd_Ecap_ChannelConfigType *chCfg);

/**
 * \brief   This API will initialize ECAP channel object associated with logical
 *          channel.
 *
 * \param[in]   chObj      Pointer to channel object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **/
void Cdd_Ecap_HwUnitInit(Cdd_Ecap_ChObjType *chObj);

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
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_ChannelISR(Cdd_Ecap_ChannelType ChannelNumber);

/**
 * \brief   This will select ECAP Input.
 *
 * \param[in]        input               Cdd Ecap Input
 *  \param[in]       base                Baseaddress of channel
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
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* CDD_ECAP_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Priv.h
 *********************************************************************************************************************/
