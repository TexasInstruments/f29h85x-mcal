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
 *  File:       Can.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Can Driver functions
 *********************************************************************************************************************/
/*
 *Design: MCAL-22825, MCAL-22842, MCAL-22827, MCAL-22880, MCAL-23013, MCAL-23010
 */
#ifndef CAN_H
#define CAN_H

/**
 * \defgroup CAN Can API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*Design: MCAL-22834 */
#include "ComStack_Types.h"

/*Design: MCAL-22833, MCAL-22832 */
#include "Can_GeneralTypes.h"
#include "CanIf_Cbk.h"
#include "Can_Cfg.h"

#include "EcuM_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/**
 * Defines for CAN Driver version used for compatibility checks.
 */
/** \brief  Driver Implementation Major Version. */
#define CAN_SW_MAJOR_VERSION (2U)
/** \brief  Driver Implementation Minor Version. */
#define CAN_SW_MINOR_VERSION (0U)
/** \brief  Driver Implementation Patch Version. */
#define CAN_SW_PATCH_VERSION (0U)

/**
 * Defines for CAN Driver AUTOSAR version used for compatibility checks.
 */
/** \brief  AUTOSAR Major version specification implemented by CAN Driver */
#define CAN_AR_RELEASE_MAJOR_VERSION (4U)

/** \brief AUTOSAR Minor version specification implemented by CAN Driver */
#define CAN_AR_RELEASE_MINOR_VERSION (3U)

/** \brief AUTOSAR Patch version specification implemented by CAN Driver.*/
#define CAN_AR_RELEASE_REVISION_VERSION (1U)

/**
 * \brief CAN Driver ID Info.
 */
/** \brief  Texas Instruments Vendor ID. */
#define CAN_VENDOR_ID ((uint16)44U)
/** \brief  CAN Driver Module ID. */
#define CAN_MODULE_ID ((uint16)80U)
/** \brief  CAN Instance ID. */
#define CAN_INSTANCE_ID ((uint16)0U)

/**
 * \brief The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error.
 */

/** \brief Service ID - Can_Init(). */
#define CAN_SID_INIT 0x00U
/** \brief Service ID - Can_MainFunction_Write(). */
#define CAN_SID_MAINFUNC_WRITE 0x01U
/** \brief Service ID - Can_SetControllerMode(). */
#define CAN_SID_SETCTR 0x03U
/** \brief Service ID - Can_DisableControllerInterrupts(). */
#define CAN_SID_DIINT 0x04U
/** \brief Service ID - Can_EnableControllerInterrupts(). */
#define CAN_SID_ENINT 0x05U
/** \brief Service ID - Can_Write(). */
#define CAN_SID_WRITE 0x06U
/** \brief Service ID - Can_GetVersionInfo(). */
#define CAN_SID_GET_VERSION_INFO 0x07U
/** \brief Service ID - Can_MainFunction_Read(). */
#define CAN_SID_MAINFUNC_READ 0x08U
/** \brief Service ID - Can_MainFunction_BusOff(). */
#define CAN_SID_MAINFUNC_BO 0x09U
/** \brief Service ID - Can_MainFunction_Wakeup(). */
#define CAN_SID_MAINFUNC_WU 0x0AU
/** \brief Service ID - Can_CheckWakeup(). */
#define CAN_SID_CKWAKEUP 0x0BU
/** \brief Service ID - Can_MainFunction_Mode(). */
#define CAN_SID_MAINFUNC_MODE 0x0CU
/** \brief Service ID - Can_ChangeBaudrate(). */
#define CAN_SID_CHNGBAUDRATE 0x0DU
/** \brief Service ID - Can_CheckBaudrate(). */
#define CAN_SID_CHKBAUDRATE 0x0EU
/** \brief Service ID - Can_SetBaudRate(). */
#define CAN_SID_SETBAUDRATE 0x0FU
/** \brief Service ID - Can_DeInit(). */
#define CAN_SID_DEINIT 0x10U
/** \brief Service ID - Can_GetControllerErrorState(). */
#define CAN_SID_GETCNTRERRSTATE 0x11U
/** \brief Service ID - Can_GetControllerMode(). */
#define CAN_SID_GETCNTRMODE 0x12U
/** \brief Service ID - Can_ProcessISR(). */
#define CAN_SID_PROCESSISR 0x13U
/** \brief Service ID - Can_SetIcomConfiguration(). */
#define CAN_SID_ICOMCONFIG 0x21U
/** \brief Service ID - Can_PeriodicReadback(). */
#define CAN_SID_READBACK 0x22U

/*
 *Design: MCAL-22929
 */
/** \brief Error codes returned by Can functions - Development Errors. */

/** \brief NULL_PTR passed as parameter. */
#ifndef CAN_E_PARAM_POINTER
#define CAN_E_PARAM_POINTER 0x01U
#endif

/** \brief Invalid Controller Handle. */
#ifndef CAN_E_PARAM_HANDLE
#define CAN_E_PARAM_HANDLE 0x02U
#endif

/** \brief Invalid length of msg. */
#ifndef CAN_E_PARAM_DATA_LENGTH
#define CAN_E_PARAM_DATA_LENGTH 0x03U
#endif

/** \brief Invalid controller id. */
#ifndef CAN_E_PARAM_CONTROLLER
#define CAN_E_PARAM_CONTROLLER 0x04U
#endif

/** \brief Error due to API invoked without performing Can_Init(). */
#ifndef CAN_E_UNINIT
#define CAN_E_UNINIT 0x05U
#endif

/** \brief Error during Controller state transition. */
#ifndef CAN_E_TRANSITION
#define CAN_E_TRANSITION 0x06U
#endif

/** \brief Invalid Baudrate configuration. */
#ifndef CAN_E_PARAM_BAUDRATE
#define CAN_E_PARAM_BAUDRATE 0x07U
#endif

/** \brief Invalid ICOM configuration Id */
#ifndef CAN_E_ICOM_CONFIG_INVALID
#define CAN_E_ICOM_CONFIG_INVALID 0x08U
#endif

/** \brief Error codes returned by Can functions - Run Time Errors. */
/** \brief Data lost/dropped. */
#ifndef CAN_E_DATALOST
#define CAN_E_DATALOST 0x01U
#endif

/** \brief Icom config disable. */
#define CAN_ICOM_CONFIG_DISABLE (0U)

/** \brief Extended id. */
#define CAN_EXTENDED_ID (1U)
/** \brief Standard id. */
#define CAN_STANDARD_ID (0U)
/** \brief Mixed id. */
#define CAN_MIXED_ID (2U)
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/*
 *Design: MCAL-24241
 */
/** \brief  Can Tx/Rx Processing */
typedef enum
{
    /** \brief Interrupt */
    CAN_INTERRUPT = 0x0U,
    /** \brief Mixed  */
    CAN_MIXED = 0x1U,
    /** \brief Polling */
    CAN_POLLING = 0x2U
} Can_ProcessingType;

/*
 *Design: MCAL-25953
 */
/** \brief Values that can be returned by CAN Driver APIs. */
typedef enum
{
    /** \brief  Transmit request could not be processed because no
                       transmit object was available. */
    CAN_BUSY = 2U
} Can_ReturnType;

/*
 *Design: MCAL-24242
 */
/** \brief  Can Handle Type FULL/BASIC */
typedef enum
{
    /** \brief Full  */
    CAN_FULL = 0x0U,
    /** \brief Basic  */
    CAN_BASIC
} Can_HandleType;

/*
 *Design: MCAL-24243
 */
/** \brief  Can Controller Instance ID */
typedef enum
{
    /** \brief MCANA Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN1 = 0x0U,
    /** \brief MCANB Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN2 = 0x1U,
    /** \brief MCANC Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN3 = 0x2U,
    /** \brief MCAND Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN4 = 0x3U,
    /** \brief MCANE Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN5 = 0x4U,
    /** \brief MCANF Controller Instance */
    CAN_CONTROLLER_INSTANCE_MCAN6 = 0x5U,

} Can_ControllerInstance;

/*
 *Design: MCAL-24244
 */
/** \brief Can Main Function RW Period Ref Type Identifier */
typedef struct
{
    /** \brief ID */
    uint16 ID;
} Can_MainFunctionRWPeriodRefType;

/*
 *Design: MCAL-24245
 */
/** \brief  Structure defining the filter mask to be used */
typedef struct Can_MaskType_s
{
    /** \brief  Filter mask value. */
    uint32 MaskValue;
} Can_MaskType;

/*
 *Design: MCAL-24246
 */
/** \brief  Can Mailbox direction enum */
typedef enum
{
    /** \brief Mailbox is for receive */
    CAN_RECEIVE = 0x0U,
    /** \brief Mailbox is for transmit */
    CAN_TRANSMIT
} Can_MailboxDirectionType;

/*
 *Design: MCAL-24247
 */
/** \brief  MCan Controller Specific Configuration */
typedef struct Can_CanConfigType_s
{
    /** \brief TRUE = Enable Flexible datarate operation */
    boolean CanFDMode;
    /** \brief TRUE = Enable Loopback mode */
    boolean CanLoopbackMode;
    /** \brief TRUE = Enable Transmit Pause */
    boolean CanTransmitPause;
    /** \brief TRUE = Disable Auto Retransmission */
    boolean CanDisableAutomaticRetransmission;
} Can_CanConfigType;

/*
 *Design: MCAL-22786, MCAL-22785, MCAL-22784, MCAL-22783, MCAL-22782, MCAL-22781, MCAL-22780,
 *MCAL-24248
 */
/** \brief  Structure defining the CAN FD data phase baud rate configuration */
typedef struct Can_FdBaudConfigType_s
{
    /** \brief Transceiver Delay Compensation offset */
    uint16  CanControllerTrcvDelayCompensationOffset;
    /** \brief In KB */
    uint16  CanControllerFdBaudRate;
    /** \brief Controller BRP value for Baud */
    uint16  BrpValue;
    /** \brief Prop Segement value */
    uint8   CanControllerPropSeg;
    /** \brief Phase Segment 1 */
    uint8   CanControllerSeg1;
    /** \brief Phase Segment 2 */
    uint8   CanControllerSeg2;
    /** \brief Sync jump width */
    uint8   CanControllerSyncJumpWidth;
    /** \brief Specifies if the bit rate switching shall be used for transmissions */
    boolean CanControllerTxBitRateSwitch;
    /** \brief TRUE = Enable Transmitter Delay Compensation */
    boolean TxDelayCompEnable;
    /** \brief Transmitter Delay Compensation Filter windown length (CAN module CLK cycles) */
    uint8   TxDelayCompFilter;
} Can_FdBaudConfigType;

/*
 *Design: MCAL-22773, MCAL-22774, MCAL-22772, MCAL-22778, MCAL-22777, MCAL-22776, MCAL-22775,
 *MCAL-24249
 */
/** \brief  Can Controller Baud Rate Configuration definition */
typedef struct Can_BaudConfigType_s
{
    /** \brief List of available Data phase Baud rates for CAN FD */
    Can_FdBaudConfigType BaudFdRateConfig;
    /** \brief Controller BRP value for Baud */
    uint16               BrpValue;
    /** \brief In KB */
    uint16               CanControllerBaudRate;
    /** \brief Config ID */
    uint8                CanControllerBaudRateConfigID;
    /** \brief Prop Segement value */
    uint8                CanControllerPropSeg;
    /** \brief Phase Segment 1 */
    uint8                CanControllerSeg1;
    /** \brief Phase Segment 2 */
    uint8                CanControllerSeg2;
    /** \brief Sync jump width */
    uint8                CanControllerSyncJumpWidth;
    /** \brief Baud Fd Enable */
    boolean              BaudFdEnable;

} Can_BaudConfigType;

/*
 *Design: MCAL-22760, MCAL-22761, MCAL-22763, MCAL-22764, MCAL-22765, MCAL-22766, MCAL-22767,
 *MCAL-22768, Design: MCAL-22769, MCAL-22771, MCAL-24250
 */
/** \brief  Can Controller Configuration definition */
typedef struct Can_ControllerType_s
{
    /** \brief Id as provided by GUI */
    uint8                      CanControllerId;
    /** \brief Contoller is used=1 or not_used=0 */
    boolean                    CanControllerActivation;
    /** \brief Can Controller Instance */
    Can_ControllerInstance     CanControllerInstance;
    /** \brief Pointer to CanReg structure */
    uint32                     CanControllerBaseAddress;
    /** \brief TRUE = Interrupt FALSE = Polling */
    Can_ProcessingType         CanBusoffProcessing;
    /** \brief TRUE = Interrupt FALSE = Polling */
    Can_ProcessingType         CanRxProcessing;
    /** \brief TRUE = Interrupt FALSE = Polling */
    Can_ProcessingType         CanTxProcessing;
    /** \brief TRUE = Enable Can_CheckWakeup API */
    boolean                    CanWakeupFunctionalityAPI;
    /** \brief TRUE = Interrupt FALSE = Polling */
    Can_ProcessingType         CanWakeupProcessing;
    /** \brief Automatic wakeup via bus activity */
    boolean                    CanWakeupSupport;
    /** \brief Wakeup source to be set */
    EcuM_WakeupSourceType      CanWakeupSourceRef;
    /** \brief pointer to default Baud structure */
    const Can_BaudConfigType*  CanControllerDefaultBaudrate;
    /** \brief List of available Baud rates */
    const Can_BaudConfigType** BaudRateConfigList;
    /** \brief HW specific config parameters */
    Can_CanConfigType          CanConfigParam;

} Can_ControllerType;

/**
 * \brief Structure defining the HW filter to be used
 */
typedef struct Can_HwFilterType_s
{
    /** \brief  ID value extended will have MSB set */
    uint32                 CanHwFilterCode;
    /** \brief  ptr to Mask for the RX filtering */
    Can_MaskType           CanHwFilterMask;
    /** \brief  filter event pin at extension interface */
    Can_EventPin           CanEventPin;
    /** \brief  filter type classic, dual, range */
    Can_StandardFilterType CanStandardFilterType;
} Can_HwFilterType;

/*
 *Design: MCAL-22799, MCAL-22796, MCAL-22800, MCAL-22795, MCAL-22794, MCAL-22793, MCAL-22792,
 *MCAL-22791, MCAL-22790, Design: MCAL-22794, MCAL-22789, MCAL-22788
 */
/** \brief  Can mailbox configuration definition */
typedef struct Can_MailboxType_s
{
    /** \brief  CanHandleType 0=Full, 1=Basic */
    Can_HandleType                  CanHandleType;
    /** \brief  CanIdType 0=standard 1=Extended */
    Can_IdType                      CanIdType;
    /** \brief  CanObjectId - Holds handle Id */
    Can_HwHandleType                CanObjectId;
    /** \brief  Mailbox - Hw object in the controller */
    uint8                           HwHandle;
    /** \brief  Number of hardware objects used to implement one HOH */
    uint8                           CanHwObjectCount;
    /** \brief  CanObjectType - Direction of Mailbox */
    Can_MailboxDirectionType        CanObjectType;
    /** \brief  Controller */
    const Can_ControllerType*       CanControllerRef;
    /** \brief  Reference to list of hardware filters HOH is associated to. */
    const Can_HwFilterType**        CanHwFilterList;
    /** \brief  Reference to list of hardware filters HOH is associated to. */
    uint8                           CanFilterListCount;
    /** \brief  If PduInfo->SduLength does not match possible DLC values CanDrv will use the next
       higher valid DLC for transmission with initialization of unused bytes to the value of the
       corresponding CanFdPaddingValue. */
    uint8                           CanFdPaddingValue;
    /** \brief  Trigger Transmit Enable/Disable */
    boolean                         CanTriggerTransmitEnable;
    /** \brief  Whether HW Object uses polling */
    boolean                         CanHardwareObjectUsesPolling;
    /** \brief Main Function Read/Write Period*/
    Can_MainFunctionRWPeriodRefType CanMainFunctionRWPeriodRef;

} Can_MailboxType;

/*
 *Design: MCAL-24252
 */
/** \brief Icom signal operation type. */
typedef enum
{
    /** \brief AND */
    AND = 0U,
    /** \brief EQUAL */
    EQUAL = 1U,
    /** \brief GREATER */
    GREATER = 2U,
    /** \brief SMALLER */
    SMALLER = 3U,
    /** \brief XOR */
    XOR = 4U,
} Can_Icom_signal_operation_type;

/*
 *Design: MCAL-24254
 */
/** \brief Icom signal config data structure */
typedef struct Can_IcomSignalConfigType_s
{
    /** \brief Icom Signal Mask */
    uint64                         CanIcomSignalMask;
    /** \brief Icom Signal Operation */
    Can_Icom_signal_operation_type CanIcomSignalOperation;
    /** \brief Icom Signal value*/
    uint64                         CanIcomSignalValue;
} Can_IcomSignalConfigType;

/*
 *Design: MCAL-24255
 */
/** \brief Icom Rx message data structure */
typedef struct Can_IcomRxMessageType_s
{
    /** \brief Icom Meassage Id */
    uint32                   CanIcomMessageId;
    /** \brief Icom Payload Length Error */
    boolean                  CanIcomPayloadLengthError;
    /** \brief Icom Counter value */
    uint16                   CanIcomCounterValue;
    /** \brief Icom Message Id Mask */
    uint32                   CanIcomMessageIdMask;
    /** \brief Icom Missing Message Timer value */
    uint32                   CanIcomMissingMessageTimerValue;
    /** \brief Signal Count */
    uint16                   SignalCount;
    /** \brief Icom Rx Message Signal Config */
    Can_IcomSignalConfigType CanIcomRxMessageSignalConfig[MAX_ICOM_RX_SIGNAL_COUNT];

} Can_IcomRxMessageType;

/*
 *Design: MCAL-24256
 */
/** \brief Icom data structure containing the overall
 *  ICOM configuration data
 */
typedef struct Can_IcomConfigType_s
{
    /** \brief List of enabled Controllers */
    IcomConfigIdType      CanIcomConfigId;
    /** \brief Icom Wake ON Busoff */
    boolean               CanIcomWakeOnBusOff;
    /** \brief Rx Message Count */
    uint16                RxMessageCount;
    /** \brief Icom Rx Message */
    Can_IcomRxMessageType CanIcomRxMessage[MAX_ICOM_MESSAGES];
    /** \brief Icom Counter value */
    uint32                CanIcomCounterValue;
} Can_IcomConfigType;

/*
 *Design: MCAL-25954, MCAL-25955, MCAL-25956, MCAL-25957, MCAL-25958
 */
/** \brief External data structure containing the overall
 *  initialization data for the CAN driver and SFR settings affecting all
 *  controllers.
 */
typedef struct Can_ConfigType_s
{
    /** \brief List of enabled Controllers */
    const Can_ControllerType** CanControllerList;
    /** \brief MaxCount of Controller in Controller List */
    uint8                      CanMaxControllerCount;
    /** \brief MB array for all controllers */
    const Can_MailboxType**    MailBoxList;
    /** \brief MaxMbCount in MB list in all controller */
    uint16                     MaxMbCnt;
    /** \brief Max Baud Config Index in BaudRateConfigList in all controller */
    uint32                     MaxBaudConfigID[KMAX_CONTROLLER];
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    /** \brief Icom Configuration List */
    const Can_IcomConfigType** IcomConfigurationList;
#endif
} Can_ConfigType;

/** \brief  Can periodic readback register definition */
typedef struct Can_PeriodicReadBackDataType_s
{
    /** \brief Register data for MCANSS_CTRL register */
    uint32 CanMcanSSCtrl;
    /** \brief Register data for MCAN_DBTP register */
    uint32 CanMcanDBTP;
    /** \brief Register data for MCAN_TEST register */
    uint32 CanMcanTest;
    /** \brief Register data for MCAN_CCCR register */
    uint32 CanMcanCccr;
    /** \brief Register data for MCAN_NBTP register */
    uint32 CanMcanNBTP;
    /** \brief Register data for MCAN_PSR register */
    uint32 CanMcanPsr;
    /** \brief Register data for MCAN_TDCR register */
    uint32 CanMcanTdcr;
    /** \brief Register data for MCAN_IR register */
    uint32 CanMcanIr;
    /** \brief Register data for MCAN_IE register */
    uint32 CanMcanIe;
    /** \brief Register data for MCAN_ILS register */
    uint32 CanMcanIls;
    /** \brief Register data for MCAN_ILE register */
    uint32 CanMcanIle;
    /** \brief Register data for MCAN_GFC register */
    uint32 CanMcanGfc;
    /** \brief Register data for MCAN_SIDFC register */
    uint32 CanMcanSidfc;
    /** \brief Register data for MCAN_XIDFC register */
    uint32 CanMcanXidfc;
    /** \brief Register data for MCANERR_CTRL register */
    uint32 CanMcanErrCtrl;
    /** \brief Register data for MCANSS_IE register */
    uint32 CanMcanSSIe;
    /** \brief Register data for MCANSS_EXT_TS_PRESCALER register */
    uint32 CanMcanSSExtTSPrescaler;
    /** \brief Register data for MCAN_RWD register */
    uint32 CanMcanRwd;
    /** \brief Register data for MCAN_TSCC register */
    uint32 CanMcanTscc;
    /** \brief Register data for MCAN_TSCV register */
    uint32 CanMcanTscv;
    /** \brief Register data for MCAN_TOCC register */
    uint32 CanMcanTocc;
    /** \brief Register data for MCAN_TOCV register */
    uint32 CanMcanTocv;
    /** \brief Register data for MCAN_ECR register */
    uint32 CanMcanEcr;
    /** \brief Register data for MCAN_XIDAM register */
    uint32 CanMcanXidam;
    /** \brief Register data for MCAN_HPMS register */
    uint32 CanMcanHpms;

} Can_PeriodicReadBackDataType;

/*
 *Design: MCAL-24253
 */
/** \brief Can Driver state */
typedef enum
{
    /** \brief Can module state when reset/power-up */
    CAN_UNINIT = 0U,
    /** \brief Can module state after initialization */
    CAN_READY = 1U
} Can_DrvState;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CAN_CFG_GET_VERSION_INFO_API)
/** \brief Function returns the version information of this module.
 *
 *
 * This service writes the version information of this module into the data
 * structure referenced by the parameter. If this parameter references
 * NULL_PTR, a development error is reported.
 *
 * \param[out] versioninfo Pointer to where to store the version information of
 * this module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo);
#endif

/** \brief This function initializes the configuration.
 *
 * This function initializes the message RAM, which also clears all the
 * message objects, and places the CAN controller in an init state. Write
 * access to the configuration registers is available as a result, allowing
 * the bit timing and message objects to be setup.
 *
 * \param[in] ConfigPtr Pointer to post-build configuration data.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE) Can_Init(P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config_Ptr);

/** \brief This function deinitializes the module.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_DeInit(void);

#if (STD_ON == CAN_CFG_SET_BAUDRATE_API)
/** \brief This service shall set the baud rate configuration of the CAN
 * Controller.
 *
 * This function sets the baud rate configuration of the CAN controller.
 * Depending on necessary baud rate modifications the controller might have
 * to reset.
 *
 * \param[in] Controller CAN controller, whose baud rate shall be set.
 * \param[in] BaudRateConfigID references a baud rate configuration by ID.
 * \pre None
 * \post None
 * \return Setting the Baudrate successful or failure.
 * \retval E_OK - Service request accepted, setting of (new) baud rate
 *                started.
 * \retval E_NOT_OK - Service request not accepted.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_SetBaudrate(uint8 Controller, const uint16 BaudRateConfigID);
#endif

/** \brief This service performs software triggered state transitions of the
 * CAN controller State machine.
 *
 * The function perfroms the transition of the CAN controller state machine
 * which is software triggered.
 *
 * \param[in] Controller CAN controller for which the status shall be changed.
 * \param[in] Transition Transition value to request new CAN controller state.
 * \pre None
 * \post None
 * \return Setting the controller mode successful/failure.
 * \retval E_OK: Request accepted.
 * \retval E_NOT_OK: Request not accepted i.e. an error occured while
 *                     requesting an incorrect from one state to other or an
 *                     incorrect transition.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

/** \brief This service disables all interrupts.
 *
 * This function checks if there is a DET Error and then disables all the
 * interrupts for the controller.
 *
 * \param[in] Controller CAN controller for which interrupts shall be re-enabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_DisableControllerInterrupts(uint8 Controller);

/** \brief This service enables all allowed interrupts.
 *
 * This function checks the total number of interrupts and enables all the
 * interrupts allowed for the controller.
 *
 * \param[in] Controller CAN controller for which interrupts shall be re-enabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_EnableControllerInterrupts(uint8 Controller);

#if (STD_ON == CAN_CFG_WAKEUP_FUNCTIONALITY_API)
/** \brief This service checks if a wakeup has occurred for the given
 * controller.
 *
 * This function checks if the Init is done and checks if wakeup has occured
 * and returns value accordingly for the given controller.
 *
 * \param[in] Controller to be checked for a wakeup.
 * \pre None
 * \post None
 * \return Wakeup occurred or not for a controller
 * \retval E_OK: API call has been accepted.
 * \retval E_NOT_OK: API call has not been accepted.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_CheckWakeup(uint8 Controller);
#endif

/** \brief This service obtains the error state of the CAN controller.
 *
 * This function gets the error state of the CAN controller.
 *
 * \param[in] Controller CAN controller, which is requested for ErrorState.
 * \param[in] ErrorStatePtr Pointer to a memory location, where the error state of the CAN
 *                      controller will be stored.
 * \pre None
 * \post None
 * \return Error state obtained successfully/failed to obtain error state.
 * \retval E_OK - Error state request has been accepted.
 * \retval E_NOT_OK - Error state request has not been accepted..
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_GetControllerErrorState(uint8 Controller, P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr);

/** \brief This service reports about the current status of the requested CAN controller.
 *
 * This function gets the current status of the CAN controller.
 *
 * \param[in] Controller CAN controller, which is requested for ErrorState.
 * \param[in] ControllerModePtr Pointer to a memory location, where the current
 *                          mode of the CAN controller will be stored.
 * \pre None
 * \post None
 * \return Able/unable to fetch current status of the controller.
 * \retval E_OK - Controller mode request has been accepted.
 * \retval E_NOT_OK - Controller mode request has not been accepted.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_GetControllerMode(uint8 Controller, P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr);

/** \brief This service is called by CanIf to pass a CAN message to CanDrv
 * for transmission.
 *
 * The function Can_Write first checks if the hardware transmit object is
 * identified and is free. It passes the CAN message to CanDrv for
 * transmission.
 *
 * \param[in] Hth information which HW-transmit handle shall be used for transmit.
 *        Implicitly this is also the information about the controller to use
 *        because the Hth numbers are unique inside one hardware unit.
 * \param[in] PduInfo Pointer to SDU user memory, DLC and Identifier.
 * \pre None
 * \post None
 * \return Can write command is accepted (or) resulted in an error (or) Controller is busy
 * \retval E_OK: Write command has been accepted.
 * \retval E_NOT_OK: Development error occurred.
 * \retval CAN_BUSY: No TX hardware buffer available or pre-emptive call of
 *                   Can_Write that can't be implemented re-entrant
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_Write(Can_HwHandleType Hth, P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);

/** \brief This service performs the polling of TX confirmation when
 *        CAN_TX_PROCESSING is set to POLLING.
 *
 * This function checks if Can Initialisation is done to check for error if DET
 * error detect is enabled. For a TX Mailbox if the controller is active
 * polling of TX confirmation is done.
 *
 * \param[in] RWFuncID Read/Write period ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MainFunction_Write(uint16 RWFuncID);

/** \brief This service performs the polling of RX indications when
 *        CAN_RX_PROCESSING is set to POLLING.
 *
 * This function checks if Can Initialisation is done to check for error if DET
 * error detect is enabled. For a Rx Mailbox if the controller is active
 * polling of Rx indications is done.
 *
 * \param[in] RWFuncID Read/Write period ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MainFunction_Read(uint16 RWFuncID);

/** \brief This service performs the polling of bus-off events that are
 *        configured statically as 'to be polled'.
 *
 * This function checks if Can Initialisation is done to check for error if DET
 * error detect is enabled. If the controller is active the polling of bus-off
 * events that are configured statically as 'to be polled'.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MainFunction_BusOff(void);

/** \brief This function performs the polling of wake-up events that are
 *        configured statically as 'to be polled'.
 *
 * This function checks if Can Initialisation is done to check for error if DET
 * error detect is enabled. The polling of wake-up events is done.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MainFunction_Wakeup(void);

/** \brief This function performs the polling of CAN controller mode
 *        transitions.
 *
 * This function checks if Can Initialisation is done to check for error if DET
 * error detect is enabled. The polling of CAN controller mode transitions is
 * done.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MainFunction_Mode(void);

/** \brief This service shall change the Icom Configuration of a CAN controller to the
 * requested one.
 *
 * \param[in] Controller CAN controller for which the status shall be changed
 * \param[in] ConfigurationId Requested Configuration
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: CAN driver succeeded in setting a configuration with a
 *               valid Configuration id.
 * \retval E_NOT_OK: CAN driver failed to set a configuration with a valid
 *                   Configuration id.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId);

/** \brief This service shall read all the statically configured registers
 *
 * \param[in] Controller CAN controller for which the configured registers shall be read
 * \param[out] ReadBackRegisterdata pointer for the read back registers
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_PeriodicReadback(uint8 Controller,
                     P2VAR(Can_PeriodicReadBackDataType, AUTOMATIC, CAN_APPL_DATA) ReadBackRegisterdata);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CAN_H */
/*********************************************************************************************************************
 *  End of File: Can.h
 *********************************************************************************************************************/
