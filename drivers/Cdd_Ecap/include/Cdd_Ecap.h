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
 *  File:       Cdd_Ecap.h
 *  Generator:  None
 *
 *  Description:  This file contains CDD ECAP driver public API function declarations .
 *********************************************************************************************************************/

#ifndef CDD_ECAP_H
#define CDD_ECAP_H

/**
 * \defgroup CDD_ECAP Cdd_Ecap public API GUIDE Header file
 * @{
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* CDD ECAP Driver ID Info */
/** \brief Texas Instruments Vendor ID */
#define CDD_ECAP_VENDOR_ID ((uint16)44U)
/** \brief CDD ECAP Driver Module ID */
#define CDD_ECAP_MODULE_ID ((uint16)255U)
/** \brief CDD ECAP Driver Instance ID */
#define CDD_ECAP_INSTANCE_ID ((uint8)0U)

/** \brief Driver Implementation Major Version */
#define CDD_ECAP_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_ECAP_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_ECAP_SW_PATCH_VERSION (1U)

/** \brief AUTOSAR Major version specification implemented by CDD_ECAP Driver */
#define CDD_ECAP_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor  version specification implemented by CDD_ECAP Driver */
#define CDD_ECAP_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_ECAP Driver */
#define CDD_ECAP_AR_RELEASE_REVISION_VERSION (1U)

/**
 *  \name CDD_ECAP Service IDs
 *
 *  The Service Id is one of the argument to Det_ReportError function and
 *  is used to identify the source of the error
 *  @{
 */
/** \brief Cdd_Ecap_Init() API Service ID */
#define CDD_ECAP_INIT_ID ((uint8)0x00U)
/** \brief Cdd_Ecap_DeInit() API Service ID */
#define CDD_ECAP_DEINIT_ID ((uint8)0x01U)
/** \brief Cdd_Ecap_SetMode() API Service ID */
#define CDD_ECAP_SETMODE_ID ((uint8)0x02U)
/** \brief Cdd_Ecap_SetActivationCondition() API Service ID */
#define CDD_ECAP_SETACTIVATIONCONDITION_ID ((uint8)0x05U)
/** \brief Cdd_Ecap_DisableNotification() API Service ID */
#define CDD_ECAP_DISABLENOTIFICATION_ID ((uint8)0x06U)
/** \brief Cdd_Ecap_EnableNotification() API Service ID */
#define CDD_ECAP_ENABLENOTIFICATION_ID ((uint8)0x07U)
/** \brief Cdd_Ecap_GetInputState() API Service ID */
#define CDD_ECAP_GETINPUTSTATE_ID ((uint8)0x08U)
/** \brief Cdd_Ecap_StartTimestamp() API Service ID */
#define CDD_ECAP_STARTTIMESTAMP_ID ((uint8)0x09U)
/** \brief Cdd_Ecap_StopTimestamp() API Service ID */
#define CDD_ECAP_STOPTIMESTAMP_ID ((uint8)0x0AU)
/** \brief Cdd_Ecap_GetTimeStampIndex() API Service ID */
#define CDD_ECAP_GETTIMESTAMPINDEX_ID ((uint8)0x0BU)
/** \brief Cdd_Ecap_ResetEdgeCount() API Service ID */
#define CDD_ECAP_RESETEDGECOUNT_ID ((uint8)0x0CU)
/** \brief Cdd_Ecap_EnableEdgeCount() API Service ID */
#define CDD_ECAP_ENABLEEDGECOUNT_ID ((uint8)0x0DU)
/** \brief Cdd_Ecap_DisableEdgeCount() API Service ID */
#define CDD_ECAP_DISABLEEDGECOUNT_ID ((uint8)0x0EU)
/** \brief Cdd_Ecap_GetEdgeNumbers() API Service ID */
#define CDD_ECAP_GETEDGENUMBERS_ID ((uint8)0x0FU)
/** \brief Cdd_Ecap_GetTimeElapsed() API Service ID */
#define CDD_ECAP_GETTIMEELAPSED_ID ((uint8)0x10U)
/** \brief Cdd_Ecap_GetDutyCycleValues() API Service ID */
#define CDD_ECAP_GETDUTYCYCLEVALUES_ID ((uint8)0x11U)
/** \brief Cdd_Ecap_GetVersionInfo() API Service ID */
#define CDD_ECAP_GETVERSIONINFO_ID ((uint8)0x12U)
/** \brief Cdd_Ecap_StartSignalMeasurement() API Service ID */
#define CDD_ECAP_STARTSIGNALMEASUREMENT_ID ((uint8)0x13U)
/** \brief Cdd_Ecap_StopSignalMeasurement() API Service ID */
#define CDD_ECAP_STOPSIGNALMEASUREMENT_ID ((uint8)0x14U)
/** \brief Cdd_Ecap_EnableEdgeDetection() API Service ID */
#define CDD_ECAP_ENABLEEDGEDETECTION_ID ((uint8)0x16U)
/** \brief Cdd_Ecap_DisableEdgeDetection() API Service ID */
#define CDD_ECAP_DISABLEEDGEDETECTION_ID ((uint8)0x17U)
/** \brief Cdd_Ecap_SetStartLevelCondition() API Service ID */
#define CDD_ECAP_SETSTARTLEVELCONDITION_ID ((uint8)0x18U)
/** @} */

/**
 *  \name CDD_ECAP Error Codes
 *
 *  Error codes returned by CDD_ECAP functions
 *  @{
 */
/** \brief API service called with invalid pointer */
#define CDD_ECAP_E_PARAM_POINTER ((uint8)0x0AU)
/**
 *  \brief API service called with invalid channel identifier
 *  or channel not configured
 */
#define CDD_ECAP_E_PARAM_CHANNEL ((uint8)0x0BU)
/** \brief API service called with an invalid or not feasible activation */
#define CDD_ECAP_E_PARAM_ACTIVATION ((uint8)0x0CU)
/** \brief Init Function Failed */
#define CDD_ECAP_E_INIT_FAILED ((uint8)0x0DU)
/** \brief API service used with invalid Buffer size */
#define CDD_ECAP_E_PARAM_BUFFER_SIZE ((uint8)0x0EU)
/** \brief API service called with invalid mode */
#define CDD_ECAP_E_PARAM_MODE ((uint8)0x0FU)
/** \brief API service called without module initialisation */
#define CDD_ECAP_E_UNINIT ((uint8)0x14U)
/** \brief Cdd_Ecap_StopTimestamp called on channel not started or already stopped */
#define CDD_ECAP_E_NOT_STARTED ((uint8)0x15U)
/** \brief API service called while a running operation */
#define CDD_ECAP_E_BUSY_OPERATION ((uint8)0x16U)
/** \brief API service Cdd_Ecap_Init called when module already initialized */
#define CDD_ECAP_E_ALREADY_INITIALIZED ((uint8)0x17U)
/** \brief API service called when notify interval is invalid */
#define CDD_ECAP_E_PARAM_NOTIFY_INTERVAL ((uint8)0x18U)
/** \brief API service Cdd_Ecap_GetVersionInfo called and parameter is invalid */
#define CDD_ECAP_E_PARAM_VINFO ((uint8)0x19U)
/** \brief API service called with an invalid or not feasible start level */
#define CDD_ECAP_E_PARAM_START_LEVEL ((uint8)0x1AU)
/** @} */

/**
 *  \name CDD_ECAP Driver State Values
 *
 *  The CDD_ECAP Driver State Values
 *  @{
 */
/** \brief CDD_ECAP driver Status uninitialized */
#define CDD_ECAP_STATUS_UNINIT ((uint8)(0U))
/** \brief CDD_ECAP driver Status Initialized */
#define CDD_ECAP_STATUS_INIT ((uint8)(1U))
/** @} */

/**
 *  \name CDD_ECAP bit field masks
 *
 *  The CDD_ECAP bit field masks
 *  @{
 */
/** \brief Capture Event 1 Interrupt Enable */
#define CDD_ECAP_ECEINT_CEVT1 (0x2U)
/** \brief Capture Event 2 Interrupt Enable */
#define CDD_ECAP_ECEINT_CEVT2 (0x4U)
/** \brief Capture Event 3 Interrupt Enable */
#define CDD_ECAP_ECEINT_CEVT3 (0x8U)
/** \brief Capture Event 4 Interrupt Enable */
#define CDD_ECAP_ECEINT_CEVT4 (0x10U)
/** @} */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/**
 *  \brief This type defines Value type
 */
typedef uint32 Cdd_Ecap_ValueType;
/**
 *  \brief This type defines return value Cdd_Ecap_GetTimeStampIndex
 */
typedef uint32 Cdd_Ecap_IndexType;
/**
 *  \brief This type defines return value of Cdd_Ecap_GetEdgeNumbers
 */
typedef uint32 Cdd_Ecap_EdgeNumberType;
/**
 *  \brief This type defines Channel type
 */
typedef uint8  Cdd_Ecap_ChannelType;
/**
 *  \brief This type defines Prescaler type
 */
typedef uint8  Cdd_Ecap_ChannelPrescalerType;

/**
 *  \brief This type defines a range of mode type
 */
typedef enum
{
    /** \brief Normal Mode */
    CDD_ECAP_MODE_NORMAL,
    /** \brief Sleep Mode */
    CDD_ECAP_MODE_SLEEP
} Cdd_Ecap_ModeType;

/**
 *  \brief This type defines a input state of CDD_ECAP driver
 */
typedef enum
{
    /** \brief Module is in active state */
    CDD_ECAP_ACTIVE,
    /** \brief Module is in idle state */
    CDD_ECAP_IDLE
} Cdd_Ecap_InputStateType;

/**
 *  \brief This type defines Activation range
 */
typedef enum
{
    /** \brief Rising Edge Activation type */
    CDD_ECAP_RISING_EDGE,
    /** \brief Falling Edge Activation type */
    CDD_ECAP_FALLING_EDGE,
    /** \brief Both Edge Activation type */
    CDD_ECAP_BOTH_EDGES
} Cdd_Ecap_ActivationType;

/**
 *  \brief This type defines the source of interrupt
 */
typedef enum
{
    CDD_ECAP_CEVT1_INT             = CDD_ECAP_ECEINT_CEVT1,
    CDD_ECAP_CEVT2_INT             = CDD_ECAP_ECEINT_CEVT2,
    CDD_ECAP_CEVT3_INT             = CDD_ECAP_ECEINT_CEVT3,
    CDD_ECAP_CEVT4_INT             = CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT1_CEVT2_INT       = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT2,
    CDD_ECAP_CEVT1_CEVT3_INT       = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT3,
    CDD_ECAP_CEVT1_CEVT4_INT       = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT2_CEVT3_INT       = CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT3,
    CDD_ECAP_CEVT2_CEVT4_INT       = CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT3_CEVT4_INT       = CDD_ECAP_ECEINT_CEVT3 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT1_CEVT2_CEVT3_INT = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT3,
    CDD_ECAP_CEVT1_CEVT2_CEVT4_INT = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT1_CEVT3_CEVT4_INT = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT3 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_CEVT2_CEVT3_CEVT4_INT = CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT3 | CDD_ECAP_ECEINT_CEVT4,
    CDD_ECAP_INT_ALL = CDD_ECAP_ECEINT_CEVT1 | CDD_ECAP_ECEINT_CEVT2 | CDD_ECAP_ECEINT_CEVT3 | CDD_ECAP_ECEINT_CEVT4
} Cdd_Ecap_IntrCapSelect;

/**
 *  \brief This type defines available measurement modes
 */
typedef enum
{
    /** \brief Signal Edge Detect Mode */
    CDD_ECAP_MODE_SIGNAL_EDGE_DETECT,
    /** \brief Signal measurement Mode */
    CDD_ECAP_MODE_SIGNAL_MEASUREMENT,
    /** \brief Signal Timestamp Mode */
    CDD_ECAP_MODE_TIMESTAMP,
    /** \brief Signal Edge counter Mode */
    CDD_ECAP_MODE_EDGE_COUNTER
} Cdd_Ecap_MeasurementModeType;

/**
 *  \brief This type defines Signal Measurement Property range
 */
typedef enum
{
    /** \brief Signal Low time */
    CDD_ECAP_LOW_TIME,
    /** \brief Signal High time */
    CDD_ECAP_HIGH_TIME,
    /** \brief Signal Period time */
    CDD_ECAP_PERIOD_TIME,
    /** \brief Signal Duty Cycle time */
    CDD_ECAP_DUTY_CYCLE
} Cdd_Ecap_SignalMeasurementPropertyType;

/**
 *  \brief This type defines TimeStamp Property range
 */
typedef enum
{
    /** \brief Linear Buffer to be used in Timestamp */
    CDD_ECAP_LINEAR_BUFFER,
    /** \brief Circular Buffer to be used in Timestamp */
    CDD_ECAP_CIRCULAR_BUFFER
} Cdd_Ecap_TimestampBufferType;

/**
 *  \brief This type defines the edge to start the edge capturing
 */
typedef enum
{
    /** \brief Rising Edge Activation type */
    CDD_ECAP_START_LEVEL_RISING_EDGE,
    /** \brief Falling Edge Activation type */
    CDD_ECAP_START_LEVEL_FALLING_EDGE
} Cdd_Ecap_StartLevelType;

/** \brief  Notification callback function pointer  */
typedef void (*Cdd_Ecap_NotifyFuncType)(void);

/**
 *  \brief This type defines Duty Cycle struct
 */
typedef struct
{
    /** \brief Active time of Signal */
    Cdd_Ecap_ValueType ActiveTime;
    /** \brief Period time of Signal */
    Cdd_Ecap_ValueType PeriodTime;
} Cdd_Ecap_DutyCycleType;

/**
 *  \brief CDD_ECAP Channel Config Structure
 */
typedef struct
{
    /** \brief Base address of CDD_ECAP Channel in use */
    uint32                                 base_addr;
    /** \brief Channel ID of CDD_ECAP Channel in use */
    Cdd_Ecap_ChannelType                   channelId;
    /** \brief Default activation edge to be used by CDD_ECAP module */
    Cdd_Ecap_ActivationType                defaultStartEdge;
    /** \brief xbar to used for input */
    Cdd_Ecap_InputSelect                   inputSelect;
    /** \brief Measurement Mode to be used */
    Cdd_Ecap_MeasurementModeType           measurementMode;
    /** \brief Signal Measurement property to be used if mode choosen */
    Cdd_Ecap_SignalMeasurementPropertyType signalMeasurementProperty;
    /** \brief Notification handler for notifications */
    Cdd_Ecap_NotifyFuncType                notificationHandler;
    /** \brief Buffer Type for Timestamp API mode */
    Cdd_Ecap_TimestampBufferType           bufferType;
    /** \brief Clk src for CDD_ECAP module in MHz */
    uint32                                 instanceClkMHz;
    /** \brief Prescaler value to be used for CDD_ECAP  module */
    Cdd_Ecap_ChannelPrescalerType          prescaler;
} Cdd_Ecap_ChannelConfigType;

/**
 *  \brief CDD_ECAP Config Structure
 */
typedef struct Cdd_Ecap_ConfigTag
{
    /** \brief Channel configurations */
    Cdd_Ecap_ChannelConfigType chCfg[CDD_ECAP_HW_CNT];
} Cdd_Ecap_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Service to initialize Cdd Ecap driver.
 *
 *  This service initializes all the ECAP HW units.
 *
 * \param[in] ConfigPtr Pointer to configuration set (Varaint PC requires a NULL_PTR)
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_Init(P2CONST(Cdd_Ecap_ConfigType, AUTOMATIC, CDD_ECAP_CFG) ConfigPtr);

#if (STD_ON == CDD_ECAP_DE_INIT_API)
/** \brief Service to De-initialize Cdd Ecap driver.
 *
 *  This service De-initializes all the ECAP HW units.
 *
 * \param[in] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DeInit(void);
#endif

/** \brief Service for setting the activation condition.
 *
 *  This service sets the activation condition of a channel(Rising, Falling or Both Edges).
 *
 * \param[in] Channel        CDD_ECAP Channel in use
 * \param[in] Activation     Activation condition or Edge to be selected
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_SetActivationCondition(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ActivationType Activation);

/** \brief Service for setting the start level condition.
 *
 *  This service sets the start level condition of a channel (Rising or Falling).
 *  In case of both edge detection, this parameter selects the start edge from which to start
 *counting the edges.
 *
 * \param[in] Channel        CDD_ECAP Channel in use
 * \param[in] Activation     Activation condition or Edge to be selected
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_SetStartLevelCondition(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_StartLevelType StartLevel);

/** \brief Service for disabling the notification.
 *
 *  This service disables the notification function of a channel.
 *
 * \param[in] Channel        CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableNotification(Cdd_Ecap_ChannelType Channel);

/** \brief Service for enabling the notification.
 *
 *  This service enables the notification function of a channel.
 *
 * \param[in] Channel        CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableNotification(Cdd_Ecap_ChannelType Channel);

#if (CDD_ECAP_GET_INPUT_STATE_API == STD_ON)
/** \brief Service for getting the input state of CDD_ECAP channel.
 *
 *  This service gets the input state of CDD_ECAP channel.
 *
 * \param[in] Channel        CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_InputStateType, CDD_ECAP_CODE) Cdd_Ecap_GetInputState(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_TIMESTAMP_API == STD_ON)
/** \brief Service for starting the timestamp measurement.
 *
 *  This service starts the timestamp measurement on the edges of a given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \param[in] BufferPtr        Pointer which points to timestamp buffer
 * \param[in] BufferSize       Size of the timestamp buffer
 * \param[in] NotifyInterval   Notify Interval
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_StartTimestamp(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType* BufferPtr, uint16 BufferSize,
                        uint16 NotifyInterval);

/** \brief Service for stopping the timestamp measurement.
 *
 *  This service stops the timestamp measurement on the edges of a given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StopTimestamp(Cdd_Ecap_ChannelType Channel);

/** \brief Service for reading the index of the timestamp measurement.
 *
 *  This service reads the index of the timestamp measurement.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_IndexType, CDD_ECAP_CODE) Cdd_Ecap_GetTimestampIndex(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_EDGE_COUNT_API == STD_ON)
/** \brief Service resets the edge count value to 0.
 *
 *  This service resets the edge count value to 0.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_ResetEdgeCount(Cdd_Ecap_ChannelType Channel);

/** \brief Service for enabling the counting of edges of the given channel.
 *
 *  This service enables the counting of edges of the given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeCount(Cdd_Ecap_ChannelType Channel);

/** \brief Service for disabling the counting of edges of the given channel.
 *
 *  This service disables the counting of edges of the given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableEdgeCount(Cdd_Ecap_ChannelType Channel);

/** \brief Service for getting the count of edges of the given channel.
 *
 *  This service counts the edges of the given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_EdgeNumberType, CDD_ECAP_CODE) Cdd_Ecap_GetEdgeNumbers(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_EDGE_DETECT_API == STD_ON)
/** \brief Service for enabling the detection of edges of the given channel.
 *
 *  This service enables the edge detection of given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_EnableEdgeDetection(Cdd_Ecap_ChannelType Channel);

/** \brief Service for disabling the detection of edges of the given channel.
 *
 *  This service disables the edge detection of given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_DisableEdgeDetection(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_SIGNAL_MEASUREMENT_API == STD_ON)
/** \brief Service for starting the measurement of signals for a given channel.
 *
 *  This service starts the signal measurement of a given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StartSignalMeasurement(Cdd_Ecap_ChannelType Channel);

/** \brief Service for stopping the measurement of signals for a given channel.
 *
 *  This service stops the signal measurement of a given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_StopSignalMeasurement(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_GET_TIME_ELAPSED_API == STD_ON)
/** \brief Service for reading the time elapsed between the edges of a channel.
 *
 *  This service reads the time elapsed between the edges of a channel(High time, low time, period
 *and duty).
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Cdd_Ecap_ValueType, CDD_ECAP_CODE) Cdd_Ecap_GetTimeElapsed(Cdd_Ecap_ChannelType Channel);
#endif

#if (CDD_ECAP_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/** \brief Service for reading the active time and period.
 *
 *  This service reads the active time and period of a given channel.
 *
 * \param[in] Channel          CDD_ECAP Channel in use
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_GetDutyCycleValues(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_DutyCycleType* DutyCycleValues);
#endif

#if (CDD_ECAP_GET_VERSION_INFO_API)
/** \brief service that returns the version information of the module.
 *
 * This service returns the version information of the Cdd Ecap module.
 *
 * \param[in] VersionInfoPtr    Pointer to where to store the version information of this module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ECAP_CODE)
Cdd_Ecap_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_ECAP_APPL_DATA) VersionInfoPtr);
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

#endif /* CDD_ECAP_H_ */

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap.h
 *********************************************************************************************************************/
