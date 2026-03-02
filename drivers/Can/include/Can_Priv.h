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
 *  File:       Can_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for CAN private functions
 *********************************************************************************************************************/
/*
 *Design: MCAL-22825, MCAL-22842, MCAL-22827, MCAL-22880, MCAL-23013, MCAL-23010
 */
#ifndef CAN_PRIV_H
#define CAN_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_mcanss.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief  Can classic payload max bytes */
#define CAN_CLASSIC_PAYLOAD_MAX_BYTES ((uint8)8U)

/** \brief   Can FD payload max bytes */
#define CAN_FD_PAYLOAD_MAX_BYTES ((uint8)64U)

/** \brief Can TDCR and TDCF max   */
#define CAN_TDCR_TDCF_MAX ((uint8)0x7FU)

/** \brief Can TDCR and TDCO max   */
#define CAN_TDCR_TDCO_MAX (0x7FU)

/** \brief Can id STD   */
#define CAN_ID_STD (0x0U)

/** \brief Can id XTD   */
#define CAN_ID_XTD (0x1U)

/** \brief Can id MIXED   */
#define CAN_ID_MIXED (0x2U)

/** \brief Can XID MSGID mask    */
#define CAN_XTD_MSGID_MASK ((uint32)0x1fffffffU)

/** \brief Can STD MSGID mask    */
#define CAN_STD_MSGID_MASK ((uint32)0x7ffU)

/** \brief Can STD MSGID shift    */
#define CAN_STD_MSGID_SHIFT ((uint32)18U)

/** \brief Can id can controller type mask    */
#define CAN_ID_CAN_CONTROLLER_TYPE_MASK ((uint32)0x40000000U)

/** \brief Can msg type mask   */
#define CAN_MSG_TYPE_MASK ((uint32)0x40000000U)

/** \brief Can msg type mask   */
#define CAN_MSG_ID_TYPE_EXT ((uint32)0x80000000U)

/** \brief Can msg type classic can   */
#define CAN_MSG_TYPE_CLASSIC_CAN ((uint32)0x0U)

/** \brief Can msg type can id   */
#define CAN_MSG_TYPE_CAN_FD ((uint32)0x40000000U)

/** \brief  Standard ID Filter Element Size */
#define MCAN_MSG_RAM_STD_ELEM_SIZE (1U)
/** \brief  Extended ID Filter Element Size */
#define MCAN_MSG_RAM_EXT_ELEM_SIZE (2U)
/** \brief  Tx/Rx Mailbox Size in case of FD CAN */
#define MCAN_MSG_RAM_TX_RX_FD_ELEM_SIZE (18U)
/** \brief  Tx/Rx Mailbox Size in case of classic CAN */
#define MCAN_MSG_RAM_TX_RX_CLASSIC_ELEM_SIZE (4U)

/** \brief MCAN IP TX buffer max number */
#define MCAN_TX_BUFFER_MAX_NUM ((uint8)32U)
/** \brief MCAN IP RX buffer max number */
#define MCAN_RX_BUFFER_MAX_NUM ((uint8)64U)
/** \brief MCAN rx FIFO_0 max number */
#define MCAN_RX_FIFO_0_MAX_NUM ((uint8)64U)
/** \brief MCAN rx FIFO_1 max number */
#define MCAN_RX_FIFO_1_MAX_NUM ((uint8)64U)
/** \brief MCAN rx FIFO_1 max number */
#define MCAN_RX_MAX_FIFO_NUM ((uint8)2U)

/** \brief MCAN number of Tx Buffers in status register */
#define MCAN_TX_MB_MAX_NUM ((uint8)32U)
/** \brief MCAN number of Rx buffers in NDAT status register */
#define MCAN_RX_MB_NDAT_NUM ((uint8)32U)

/** \brief Macro defines mask for all the interrupts status for MCAN. */
#define CAN_INTR_MASK_ALL                                                                                            \
    ((uint32)MCAN_IR_RF0N_MASK | (uint32)MCAN_IR_RF0W_MASK | (uint32)MCAN_IR_RF0F_MASK | (uint32)MCAN_IR_RF0L_MASK | \
     (uint32)MCAN_IR_RF1N_MASK | (uint32)MCAN_IR_RF1W_MASK | (uint32)MCAN_IR_RF1F_MASK | (uint32)MCAN_IR_RF1L_MASK | \
     (uint32)MCAN_IR_HPM_MASK | (uint32)MCAN_IR_TC_MASK | (uint32)MCAN_IR_TCF_MASK | (uint32)MCAN_IR_TFE_MASK |      \
     (uint32)MCAN_IR_TEFN_MASK | (uint32)MCAN_IR_TEFW_MASK | (uint32)MCAN_IR_TEFF_MASK | (uint32)MCAN_IR_TEFL_MASK | \
     (uint32)MCAN_IR_TSW_MASK | (uint32)MCAN_IR_MRAF_MASK | (uint32)MCAN_IR_TOO_MASK | (uint32)MCAN_IR_DRX_MASK |    \
     (uint32)MCAN_IR_BEC_MASK | (uint32)MCAN_IR_BEU_MASK | (uint32)MCAN_IR_ELO_MASK | (uint32)MCAN_IR_EP_MASK |      \
     (uint32)MCAN_IR_EW_MASK | (uint32)MCAN_IR_BO_MASK | (uint32)MCAN_IR_WDI_MASK | (uint32)MCAN_IR_PEA_MASK |       \
     (uint32)MCAN_IR_PED_MASK | (uint32)MCAN_IR_ARA_MASK)

/** \brief MCAN Interrupt line 0 */
#define MCAN_INT_LINE_0 (1U)

/** \brief MCAN Interrupt line 0 */
#define MCAN_INT_LINE_1 (2U)

/** \brief  MCAN ECC Control */
#define MCAN_O_ERR_CTRL (MCAN_ECC_AGGR_CONTROL - MCAN_ERROR_REGS)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/*
 *Design: MCAL-25936
 */
/** \brief   Enum to represent the MCAN mode of operation */
typedef enum
{
    /** \brief CAN normal mode */
    CAN_CONTROLLER_OPERATION_MODE_NORMAL = 0U,
    /** \brief CAN SW initialization mode */
    CAN_CONTROLLER_OPERATION_MODE_SW_INIT = 1U
} Can_ControllerOperationMode;

/*
 *Design: MCAL-25937
 */
/** \brief   Enum to represent the MCAN mode of operation */
typedef enum
{
    /** \brief No clock stop acknowledged */
    CAN_CLOCK_STOP_NO_ACK = 0U,
    /** \brief MCAN may be set in power down  */
    CAN_CLOCK_STOP_ACK = 1U
} Can_ClockStopAckMode;

/*
 *Design: MCAL-25938
 */
/** \brief   Can State Transition indication done to CanIf module */
typedef struct Can_CanIfIndication_s
{
    /** \brief Uninit Indication */
    boolean uninitIndication;
    /** \brief Start Indication */
    boolean startIndication;
    /** \brief Stop Indication*/
    boolean stopIndication;
    /** \brief Sleep Indication */
    boolean sleepIndication;
} Can_CanIfIndicationType;

/*
 *Design: MCAL-25939
 */
/** \brief   Enum to represent FIFO/Buffer element Size */
typedef enum
{
    /** \brief  8 byte data field */
    CAN_ELEM_SIZE_8BYTES = 0U,
    /** \brief  12 byte data field */
    CAN_ELEM_SIZE_12BYTES = 1U,
    /** \brief  16 byte data field */
    CAN_ELEM_SIZE_16BYTES = 2U,
    /** \brief  20 byte data field */
    CAN_ELEM_SIZE_20BYTES = 3U,
    /** \brief  24 byte data field */
    CAN_ELEM_SIZE_24BYTES = 4U,
    /** \brief  32 byte data field */
    CAN_ELEM_SIZE_32BYTES = 5U,
    /** \brief  48 byte data field */
    CAN_ELEM_SIZE_48BYTES = 6U,
    /** \brief  64 byte data field */
    CAN_ELEM_SIZE_64BYTES = 7U
} Can_MailboxElemSizeType;

/*
 *Design: MCAL-25940
 */
/** \brief Structure for MCAN Message RAM Configuration Parameters
 *  Message RAM can contain following sections:
 *  Standard ID filters, Extended ID filters, TX FIFO(or TX Q),
 *  TX Buffers, TX EventFIFO, RX FIFO0, RX FIFO1, RX Buffer.
 *  Note: If particular section in the RAM is not used then it's size
 *  should be initialized to '0'
 *  (Number of buffers in case of Tx/Rx buffer).
 */
typedef struct Can_MsgRAMConfigParams_s
{
    /** \brief  Standard ID Filter List Start Address */
    uint32 flssa;
    /** \brief List Size: Standard ID
                0 = No standard Message ID filter
                1-127 = Number of standard Message ID filter elements
                others = Values greater than 128 are interpreted as 128 */
    uint8  lss;
    /** \brief Extended ID Filter List Start Address */
    uint32 flesa;
    /** \brief List Size: Extended ID
                0 = No standard Message ID filter
                1-64 = Number of standard Message ID filter elements
                others = Values greater than 64 are interpreted as 64 */
    uint8  lse;
    /** \brief Tx Buffers Start Address */
    uint32 txStartAddr;
    /** \brief Number of Dedicated Transmit Buffers
                0 = No Dedicated Tx Buffers
                1-32 = Number of Dedicated Tx Buffers
                others = Values greater than 32 are interpreted as 32 */
    uint8  txBufNum;
    /** \brief Transmit FIFO/Queue Size
                0 = No Tx FIFO/Queue
                1-32 = Number of Tx Buffers used for Tx FIFO/Queue
                others = Values greater than 32 are interpreted as 32 */
    uint8  txFIFOSize;
    /** \brief Tx FIFO/Queue Mode
                0 = Tx FIFO operation
                1 = Tx Queue operation */
    uint32 txBufMode;
    /** \brief Tx Event FIFO Start Address */
    uint32 txEventFIFOStartAddr;
    /** \brief Event FIFO Size
                0 = Tx Event FIFO disabled
                1-32 = Number of Tx Event FIFO elements
                others = Values greater than 32 are interpreted as 32 */
    uint32 txEventFIFOSize;
    /** \brief Tx Event FIFO Watermark
                0 = Watermark interrupt disabled
                1-32 = Level for Tx Event FIFO watermark interrupt
                others = Watermark interrupt disabled */
    uint32 txEventFIFOWaterMark;
    /** \brief Rx FIFO0 Start Address */
    uint32 rxFIFO0startAddr;
    /** \brief Rx FIFO0 Size
                0 = No Rx FIFO
                1-64 = Number of Rx FIFO elements
                others = Values greater than 64 are interpreted as 64 */
    uint8  rxFIFO0size;
    /** \brief Rx FIFO0 Watermark
                0 = Watermark interrupt disabled
                1-63 = Level for Rx FIFO 0 watermark interrupt
                others = Watermark interrupt disabled */
    uint32 rxFIFO0waterMark;
    /** \brief Rx FIFO0 Operation Mode
                0 = FIFO blocking mode
                1 = FIFO overwrite mode */
    uint32 rxFIFO0OpMode;
    /** \brief Rx FIFO1 Start Address */
    uint32 rxFIFO1startAddr;
    /** \brief Rx FIFO1 Size
                0 = No Rx FIFO
                1-64 = Number of Rx FIFO elements
                others = Values greater than 64 are interpreted as 64 */
    uint8  rxFIFO1size;
    /** \brief Rx FIFO1 Watermark
                0 = Watermark interrupt disabled
                1-63 = Level for Rx FIFO 1 watermark interrupt
                others = Watermark interrupt disabled */
    uint32 rxFIFO1waterMark;
    /** \brief Rx FIFO1 Operation Mode
                0 = FIFO blocking mode
                1 = FIFO overwrite mode */
    uint32 rxFIFO1OpMode;
    /** \brief Rx Buffer Start Address */
    uint32 rxBufStartAddr;
    /** \brief Size of Rx/Tx Buffer Element in words */
    uint32 bufferElemSize;
} Can_MsgRAMConfigParams;

/*
 *Design: MCAL-25941
 */
/** \brief   Structure for MCAN Standard Message ID Filter Element. */
typedef struct Can_StdMsgIDFilterElement_s
{
    /** \brief Standard Filter ID 2 */
    uint32 sfid2;
    /** \brief Standard Filter ID 1 */
    uint32 sfid1;
    /** \brief Standard Filter Element Configuration
                000 = Disable filter element
                001 = Store in Rx FIFO 0 if filter matches
                010 = Store in Rx FIFO 1 if filter matches
                011 = Reject ID if filter matches
                100 = Set priority if filter matches
                101 = Set priority and store in FIFO 0 if filter matches
                110 = Set priority and store in FIFO 1 if filter matches
                111 = Store into Rx Buffer or as debug message,
                configuration of SFT[1:0] ignored.
                If SFEC = “100”, “101”, or “110” a match sets
                high priority message event is generated. */
    uint32 sfec;
    /** \brief Standard Filter Type
                00 = Range filter from SFID1 to SFID2 (SFID2 ≥ SFID1)
                01 = Dual ID filter for SFID1 or SFID2
                10 = Classic filter: SFID1 = filter, SFID2 = mask
                11 = Filter element disabled */
    uint32 sft;
} Can_StdMsgIDFilterElement;

/*
 *Design: MCAL-25942
 */
/** \brief   Structure for MCAN Extended Message ID Filter Element. */
typedef struct Can_ExtMsgIDFilterElement_s
{
    /** \brief Extended Filter ID 1 */
    uint32 efid1;
    /** \brief Extended Filter Element Configuration
                000 = Disable filter element
                001 = Store in Rx FIFO 0 if filter matches
                010 = Store in Rx FIFO 1 if filter matches
                011 = Reject ID if filter matches
                100 = Set priority if filter matches
                101 = Set priority and store in FIFO 0 if filter matches
                110 = Set priority and store in FIFO 1 if filter matches
                111 = Store into Rx Buffer or as debug message,
                configuration of SFT[1:0] ignored.
                If EFEC = “100”, “101”, or “110” a match sets
                high priority message event is generated. */
    uint32 efec;
    /** \brief Extended Filter ID 2 */
    uint32 efid2;
    /** \brief Extended Filter Type
                00 = Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1)
                01 = Dual ID filter for EFID1 or EFID2
                10 = Classic filter: EFID1 = filter, EFID2 = mask
                11 = Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1),
                XIDAM mask not applied */
    uint32 eft;
} Can_ExtMsgIDFilterElement;

/*
 *Design: MCAL-25943
 */
/** \brief   Can FD controller Message RAM Configuration object structure. */
typedef struct Can_FdMsgRAMConfigObjType_s
{
    /** \brief MCAN Message RAM Configuration parameters */
    Can_MsgRAMConfigParams    configParams;
    /** \brief Standard ID filter elements */
    Can_StdMsgIDFilterElement stdMsgIDFilterList[KMAX_STD_FILTERS_PER_CONTROLLER];
    /** \brief Extended ID filter elements */
    Can_ExtMsgIDFilterElement extMsgIDFilterList[KMAX_EXTD_FILTERS_PER_CONTROLLER];
    /** \brief Standard ID filter element number */
    uint8                     stdFilterNum;
    /** \brief Extended ID filter element number */
    uint8                     extFilterNum;
    /** \brief Mapping of transmit buffer to HOH */
    Can_HwHandleType          canTxBufToHohMapping[KMAX_TX_MB_PER_CONTROLLER];
    /** \brief Mapping of receive buffer to HOH */
    Can_HwHandleType          canRxBufToHohMapping[KMAX_RX_MB_PER_CONTROLLER];
    /** \brief Mapping of receive Fifo to HOH */
    Can_HwHandleType          canRxFifoToHohMapping[MCAN_RX_MAX_FIFO_NUM];
    /** \brief Tx number of Buffer elements */
    uint8                     txBuffNum;
    /** \brief Tx number of FIFO elements */
    uint8                     txFIFONum;
    /** \brief Rx number of Buffer elements */
    uint8                     rxBuffNum;
    /** \brief Rx number of FIFO elements */
    uint8                     rxFIFONum;
} Can_FdMsgRAMConfigObjType;

/*
 *Design: MCAL-25944
 */
/** \brief   Can controller object structure */
typedef struct Can_ControllerObjType_s
{
    /** \brief Bus off recovery status */
    boolean                   canBusOffRecoveryStatus;
    /** \brief Tx/Rx Pdu ID Info for Message RAM buffer*/
    PduIdType                 canTxRxPduId[KMAX_TX_MB_PER_CONTROLLER];
    /** \brief Total number of interrupts for this controller */
    uint8                     canInterruptCounter;
    /** \brief Set BRP value */
    uint16                    canBaud;
    /** \brief SDU pointer */
    uint8                     canSduPtr[CAN_FD_PAYLOAD_MAX_BYTES];
    /** \brief Can Controller */
    Can_ControllerType        canControllerConfig;
    /** \brief Max Baud Config Index in BaudRateConfigList */
    uint16                    MaxBaudConfigID;
    /** \brief State of Can */
    Can_ControllerStateType   canState;
    /** \brief Structure which includes HOH, CAN Controller ID and specific CanId */
    Can_HwType                mailboxCfg;
    /** \brief Structure which includes pointer to the SDU and it's length */
    PduInfoType               pduInfo;
    /** \brief MCAN Message RAM configuration parameters */
    Can_FdMsgRAMConfigObjType canFDMsgRamConfig;
} Can_ControllerObjType;

/*
 *Design: MCAL-25945
 */
/** \brief   Can Mailbox type strucuture */
typedef struct Can_MailboxObjType_s
{
    /** \brief Mailbox Config Info */
    Can_MailboxType mailBoxConfig;
} Can_MailboxObjType;

/*
 *Design: MCAL-25946
 */
/** \brief   Can Driver object type structure */
typedef struct Can_DriverObjType_s
{
    /** \brief List of enabled Controllers */
    Can_ControllerObjType canController[KMAX_CONTROLLER];
    /** \brief MB array for all controllers */
    Can_MailboxObjType    canMailbox[KMAX_MAILBOXES];
    /** \brief MaxCount of Controller in Controller List */
    uint8                 canMaxControllerCount;
    /** \brief MaxMbCount in MB list in all controller */
    uint16                maxMbCnt;
    /** \brief CAN Controller ID mapping */
    uint32                controllerIDMap[KMAX_CONTROLLER];
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    /** \brief Icom Configuration List */
    Can_IcomConfigType IcomConfigurationList[MAX_ICOM_CONFIGURATION];
#endif
    /** \brief Icom Activation */
    boolean Can_IcomActivation[KMAX_CONTROLLER];
    /** \brief Icom Configuration Id */
    uint8   Can_IcomConfigurationId[KMAX_CONTROLLER];
    /** \brief Icom Counter Value */
    uint8   Can_IcomCounterValue[KMAX_CONTROLLER];
} Can_DriverObjType;

/*
 *Design: MCAL-25947
 */
/** \brief   Enum to represent the CAN Message RAM type. */
typedef enum
{
    /** \brief MCAN Msg RAM buffersss */
    CAN_MEM_TYPE_BUF = 0U,
    /** \brief MCAN Msg RAM FIFO/Queue */
    CAN_MEM_TYPE_FIFO0 = 1U,
    /** \brief MCAN Msg RAM FIFO/Queue */
    CAN_MEM_TYPE_FIFO1 = 2U
} Can_MemType;

/*
 *Design: MCAL-25948
 */
/** \brief   Structure for CAN Tx Buffer element. */
typedef struct Can_TxBufElementType_s
{
    /** \brief Identifier */
    uint32      id;
    /** \brief Extended Identifier
                0 = 11-bit standard identifier
                1 = 29-bit extended identifier */
    uint8       xtd;
    /** \brief Data Length Code
                0-8  = CAN  CAN FD transmit frame has 0-8 data bytes
                9-15 = CAN FD transmit frame has 12/16/20/24/32/48/64 data bytes */
    uint32      dataLength;
    /** \brief Bit Rate Switching
                0 = CAN FD frames transmitted without bit rate switching
                1 = CAN FD frames transmitted with bit rate switching */
    boolean     brs;
    /** \brief FD Format
                0 = Frame transmitted in Classic CAN format
                1 = Frame transmitted in CAN FD format */
    boolean     fdf;
    /** \brief Can Message Ram Type */
    Can_MemType memType;
    /** \brief Data bytes.
                Only first dlc number of bytes are valid. */
    uint8       data[CAN_FD_PAYLOAD_MAX_BYTES];
} Can_TxBufElementType;

/*
 *Design: MCAL-25949
 */
/** \brief   Structure for CAN Rx Buffer element. */
typedef struct Can_RxBufElementType_s
{
    /** \brief Identifier */
    uint32  id;
    /** \brief Extended Identifier
                0 = 11-bit standard identifier
                1 = 29-bit extended identifier */
    uint8   xtd;
    /** \brief Data Length Code
                0-8  = CAN  CAN FD transmit frame has 0-8 data bytes
                9-15 = CAN FD transmit frame has 12/16/20/24/32/48/64 data bytes */
    uint32  dataLength;
    /** \brief Bit Rate Switching
                0 = CAN FD frames transmitted without bit rate switching
                1 = CAN FD frames transmitted with bit rate switching */
    boolean brs;
    /** \brief FD Format
                0 = Frame transmitted in Classic CAN format
                1 = Frame transmitted in CAN FD format */
    boolean fdf;
    /** \brief Data bytes.
                Only first dlc number of bytes are valid. */
    uint8   data[CAN_FD_PAYLOAD_MAX_BYTES];
} Can_RxBufElementType;

/*
 *Design: MCAL-25950
 */
/** \brief   Enum to represent the MCAN Rx FIFO number. */
typedef enum
{
    /** \brief MCAN Rx FIFO 0 */
    CAN_RX_FIFO_NUM_0 = 0U,
    /** \brief MCAN Rx FIFO 1 */
    CAN_RX_FIFO_NUM_1 = 1U
} Can_RxFifoNumType;

/*
 *Design: MCAL-25951
 */
/** \brief   Structure for CAN Rx FIFO Status. */
typedef struct Can_RxFIFOStatusType_s
{
    /** \brief Rx FIFO number */
    Can_RxFifoNumType num;
    /** \brief Rx FIFO Fill Level  */
    uint8             fillLvl;
    /** \brief Rx FIFO Get Index  */
    uint8             getIdx;
    /** \brief Rx FIFO Put Index  */
    uint8             putIdx;
    /** \brief Rx FIFO Full
        0 = Rx FIFO not full
        1 = Rx FIFO full */
    boolean           fifoFull;
    /** \brief Rx FIFO Message Lost
        0 = No Rx FIFO Message Lost
        1 = Rx FIFO Message Lost */
    boolean           msgLost;
} Can_RxFIFOStatusType;

/*
 *Design: MCAL-25951
 */
/** \brief   Structure for CAN Rx FIFO Status. */
typedef struct Can_TxFIFOStatusType_s
{
    /** \brief Rx FIFO Put Index  */
    uint8   putIdx;
    /** \brief Rx FIFO Full
        0 = Rx FIFO not full
        1 = Rx FIFO full */
    boolean fifoFull;
} Can_TxFIFOStatusType;

/*
 *Design: MCAL-25952
 */
/** \brief   Structure for Can new data flag for Rx buffer. */
typedef struct Can_RxNewDataStatusType_s
{
    /** \brief New data flag for Rx buffer no. 0 to 31 */
    uint32 statusLow;
    /** \brief New data flag for Rx buffer no. 32 to 63 */
    uint32 statusHigh;
} Can_RxNewDataStatusType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/** \brief This function will check for NULL pointers for Config structure.
 *
 * \param[in] ConfigPtr Pointer to post-build configuration data.
 * \pre None
 * \post None
 * \return The status of whether NULL pointers present in the ConfigPtr passed.
 * \retval E_OK - If all pointers are initialized properly.
 * \retval E_NOT_OK - If there are NULL pointers present.
 *
 *****************************************************************************/
Std_ReturnType Can_CheckInitDetPriv(const Can_ConfigType *ConfigPtr);
#endif

/** \brief This function will reset default  Config structure.
 *
 * \param[in] drvObj Pointer to post-build configuration data.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_ResetDrvObjPriv(Can_DriverObjType *drvObj);

/** \brief This function will initialize Driver Config structure.
 *
 * \param[in] drvObj Pointer to post-build configuration data.
 * \param[in] ConfigPtr Pointer to Can controllers Config structure.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_InitDrvObjPriv(Can_DriverObjType *drvObj, const Can_ConfigType *ConfigPtr);

/** \brief This function will initialize Can HW Unit.
 *
 * \param[in] canController Pointer to Can controller Config structure.
 * \param[in] canMailbox Pointer to Mailbox structure.
 * \param[in] maxMbCnt Maximum number of mailbox configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitConfigPriv(Can_ControllerObjType *canController, const Can_MailboxObjType *canMailbox, uint16 maxMbCnt);

/** \brief This API will configure the Message RAM.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] canFDMsgRamConfig Message RAM Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_MsgRamConfigPriv(uint32 baseAddr, P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) canFDMsgRamConfig);

/** \brief This API will configure a bit timings for MCAN module.
 *
 * \param[in] baseAddr Base Address of the MCAN Registers.
 * \param[in] baudConfig Configuration parameters for MCAN bit timing.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HWSetBaudRatePriv(uint32 baseAddr, const Can_BaudConfigType *baudConfig);

/** \brief This function will disable MCAN interrupts as per config.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_DisableInterruptsPriv(const Can_ControllerType *configParam);

/** \brief This function will enable MCAN interrupts as per config.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_EnableInterruptsPriv(const Can_ControllerType *configParam);

/** \brief This function will de-initialize Can HW Unit.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HwDeInitPriv(const Can_ControllerType *configParam);

/** \brief This function will fetch Protocol Errors detected by CAN HW Unit.
 *
 * \param[in] canController Pointer to Can controller Config structure.
 * \pre None
 * \post None
 * \return The Can error state when controller is ACTIVE/PASSIVE/BUS-OFF
 * \retval CAN_ERRORSTATE_ACTIVE - If no protocol errors are present.
 * \retval CAN_ERRORSTATE_PASSIVE - If CAN controller is in passive state due
 *                                   to protocol errors.
 * \retval CAN_ERRORSTATE_BUSOFF - If bus off error is detected.
 *
 *****************************************************************************/
Can_ErrorStateType Can_GetProtocolStatusPriv(const Can_ControllerObjType *canController);

/** \brief This function will fetch Wakeup Status for CAN HW Unit.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether CAN HW Unit is Wakeup/Sleeping
 * \retval TRUE - If CAN HW Unit is in Wakeup.
 * \retval FALSE - If CAN HW Unit is still sleeping.
 *
 *****************************************************************************/
Std_ReturnType Can_HWCheckWakeupPriv(const Can_ControllerType *configParam);

/** \brief This function will start Can HW Unit.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[inout] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller
 *status to update, CanIf module indication done information / Updates, Start successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether starting of Can HW Unit is successful
 * \retval E_OK - If startup is successful.
 * \retval E_NOT_OK - If startup is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitStartPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType *canIfIndication);

/** \brief This function will stop Can HW Unit.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[inout] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller
 *status to update, CanIf module indication done information / Updates, Stop successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether stopping of Can HW Unit is successful
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitStopPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType *canIfIndication);

/** \brief This function will sleep Can HW Unit.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[inout] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller
 *status to update, CanIf module indication done information / Updates, Sleep successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether sleep of Can HW Unit is successful
 * \retval E_OK - If sleep is successful.
 * \retval E_NOT_OK - If sleep is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitSleepPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType *canIfIndication);

/** \brief This function will wakeup Can HW Unit.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[inout] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller
 *status to update, CanIf module indication done information / Updates, Wakeup successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether wakeup of Can HW Unit is successful
 * \retval E_OK - If wakeup is successful.
 * \retval E_NOT_OK - If wakeup is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitWakeupPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType *canIfIndication);

/** \brief This function will check if desired Tx mailbox is free.
 *
 * \param[in] mailboxCfg Pointer to Mailbox structure.
 * \param[in] msgObj HW object in the controller.
 * \pre Can module must be initialized
 * \post None
 * \return The status of Tx mailbox free/busy/not-found
 * \retval E_OK - If free message object is found.
 * \retval E_NOT_OK - If free message object is not found.
 * \retval CAN_BUSY - If message is already pending.
 *
 *****************************************************************************/
Std_ReturnType Can_GetFreeTxMsgObjPriv(const Can_MailboxType *mailboxCfg, uint8 *msgObj);

/** \brief This function will write into the Transmit Mailbox.
 *
 * \param[in] mailboxCfg Pointer to Mailbox structure.
 * \param[in] messageBox HW object in the controller.
 * \param[in] pduInfo Pointer to SDU user memory, DLC and Identifier.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_WriteTxMailboxPriv(const Can_MailboxType *mailboxCfg, uint8 messageBox, const Can_PduType *pduInfo);

/** \brief This function will poll for Tx confirmation.
 *
 * \param[in] canController Pointer to Can controller Config structure.
 * \param[in] canMailbox Pointer to Mailbox structure.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitTxDonePollingPriv(Can_ControllerObjType *canController, const Can_MailboxObjType *canMailbox);

/** \brief This function will read Rx messages from Mailbox.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canMailbox Pointer to Mailbox structure.
 * \param[in] htrh HW object in the configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
void Can_ReadRxMailboxPriv(Can_ControllerObjType *controllerObj, const Can_MailboxObjType *canMailbox,
                           Can_HwHandleType htrh);

/** \brief This function will inform CanIf if bus off is detected.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_BusOffProcessPriv(Can_ControllerObjType *controllerObj);

/** \brief This function will inform EcuM if Wakeup is detected.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_WakeupProcessPriv(Can_ControllerObjType *controllerObj);

/** \brief This function will inform CanIf if any mode changes are detected.
 *
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] indication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status
 *indication done to CanIf module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_ModeProcessPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType *indication);

/*********************************************************************************************************************
 ** \brief Can_ProcessLine0ISR: Invoked by the respective CAN controller ISR.
 *
 * This Interrupt function is invoked when CAN Tx/Bus-Off interrupts occur for a controller, inside
 *the respective Controller ISR, when the interrupts for the controller are enabled.
 *
 *
 * \param[in] canInstance the Can Controller Instance ID
 * \param[in] lineSelect the interrupt line for Can Controller Instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Can_ProcessLine0ISR(Can_ControllerInstance canInstance, uint32 lineSelect);

/*********************************************************************************************************************
 ** \brief Can_ProcessLine1ISR: Invoked by the respective CAN controller ISR.
 *
 * This Interrupt function is invoked when CAN Rx interrupts occur for a controller, inside the
 * respective Controller ISR, when the interrupts for the controller are enabled.
 *
 *
 * \param[in] canInstance the Can Controller Instance ID
 * \param[in] lineSelect the interrupt line for Can Controller Instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Can_ProcessLine1ISR(Can_ControllerInstance canInstance, uint32 lineSelect);

/** \brief Can_ProcessWakeUpISR: Invoked by the respective CAN controller ISR.
 *
 * This Interrupt function is invoked when CAN wakeup event occur for a controller, inside the
 * respective Controller ISR, when the interrupts for the controller are enabled.
 *
 * \param[in] instance the Can Controller Instance ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE) Can_ProcessWakeUpISR(Can_ControllerInstance instance);

/** \brief This service disables all interrupts.
 *
 * This function checks if there is a DET Error and then disables all the
 * interrupts for the controller.
 * \param[in] drvObj Pointer to Can controller Config structure.
 * \param[in] Controller CAN controller for which interrupts shall be re-enabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_PollingCheck(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj, uint8 Controller);

/** \brief This service enables all allowed interrupts.
 *
 * This function checks the total number of interrupts and enables all the
 * interrupts allowed for the controller.
 * \param[in] drvObj Pointer to Can controller Config structure.
 * \param[in] Controller CAN controller for which interrupts shall be re-enabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_InterruptCounterCheckPriv(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj, uint8 Controller);

/** \brief This API will configure the Message RAM.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] msgRAMConfigParams Message RAM Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_HwMsgRamConfigPriv(uint32 baseAddr, P2CONST(Can_MsgRAMConfigParams, AUTOMATIC, CAN_CONST) msgRAMConfigParams);

/** \brief This function will add padding value to unused to data in payload and find standard data
 *length .
 *
 * \param[in] pduInfo Base Address of controller.
 * \param[in] elemPtr Pointer to location to store value read.
 * \param[in] mailboxCfg Mailbox Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_AddPdgValFindStdDtlen(P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pduInfo,
                          P2VAR(Can_TxBufElementType, AUTOMATIC, CAN_APPL_DATA) elemPtr,
                          P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg);

/** \brief This function will Call Receive Indication  .
 *
 * \param[in] RxIndicationStatus Receive indication status.
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canIdentifier Holds Can Identifier value.
 * \param[in] htrh Handle ID of HTH.
 * \param[in] canDataLength Frame length of msg.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_CallRxIndication(CONST(boolean, AUTOMATIC) RxIndicationStatus, CONST(Can_HwHandleType, AUTOMATIC) htrh,
                     CONST(uint32, AUTOMATIC) canIdentifier, CONST(uint8, AUTOMATIC) canDataLength,
                     P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj);

/** \brief This function will configure a bit timings for MCAN module.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] baudConfig Configuration parameters for MCAN bit timing.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_CanSetBaudRatePriv(uint32 baseAddr, P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_CONST) baudConfig);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/** \brief This function will validate the icom configuration critiria based on rx message configs.
 *
 * \param[in] loopCnt Signal Count.
 * \param[in] icomConfigPtr Pointer to Icom data structure containing the overall ICOM configuration
 *data.
 * \param[in] sduData Hold sdu data.
 * \param[in] rxMessageConfigId Indidicates Receive Message Id.
 * \pre None
 * \post None
 * \return The status of whether the icom configuration critiria matched or not
 * \retval E_OK - If icom configuration matched.
 * \retval E_NOT_OK - If icom configuration not matched.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_ValidateIcomConfigPriv(uint16 loopCnt, P2CONST(Can_IcomConfigType, AUTOMATIC, CAN_CONST) icomConfigPtr,
                           uint64 sduData, uint16 rxMessageConfigId);
#endif

/** \brief This function will Configure Transceiver Delay Compensation.
 *
 * \param[in] baseAddress Base Address of controller.
 * \param[in] baudConfig Configuration parameters for MCAN bit timing.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_CheckTxDelayCompEnablePriv(uint32 baseAddress, P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_CONST) baudConfig);

/** \brief This API will write acknowledgment for read of Rx FIFO0/FIFO1.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] idx FIFO element ID.
 * \param[in] hwHandle of FIFO. 0 value represents FIFO0 and 1 represents FIFO1
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE) Can_WriteRxFIFOAckPriv(uint32 baseAddr, uint8 idx, uint8 hwHandle);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/** \brief This function will validate the icom configuration critiria based on rx message configs.
 *
 * \param[in] signalData Hold Icom signal config data
 * \param[in] sduData Hold sdu data.
 * \pre None
 * \post None
 * \return The status of whether the icom configuration critiria matched or not
 * \retval E_OK - If icom Signal Operation configuration matched.
 * \retval E_NOT_OK - If icom Signal Operation configuration not matched.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_IcomSignalOp(P2CONST(Can_IcomSignalConfigType, AUTOMATIC, CAN_CONST) signalData, uint64 sduData);
#endif

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/** \brief This function will check for NULL pointers for Controller Config structure.
 *
 * \param[in] ConfigPtr Pointer to post-build configuration data.
 * \pre None
 * \post None
 * \return The status whether Controller config pointers are properly initialized.
 * \retval E_OK - If all pointers are initialized properly.
 * \retval E_NOT_OK - If there are NULL pointers present.
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_CheckControllerConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr);
#endif

/** \brief This API will Call Tx Confirmation.
 *
 * \param[in] loopCnt Tx number of buffer elements.
 * \param[in] buffNum Tx number of buffer and FIFO elements.
 * \param[in] canController Pointer to Can controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_HwUnitTxConfirmationPriv(uint8 loopCnt, uint8 buffNum,
                             P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController);

/** \brief This API will update data in the Message RAM.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] bufNum Transmit Buffer number.
 * \param[in] elem Pointer to the data to be written in Message RAM.
 * \param[in] pdu_Info Pointer to the Pdu to be transmitted.
 * \param[in] mailBoxConfig Pointer to the Hoh configuration data.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_WriteMsgRamPriv(uint32 baseAddr, uint8 bufNum, P2CONST(Can_TxBufElementType, AUTOMATIC, CAN_CONST) elem,
                    P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pdu_Info,
                    P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailBoxConfig);

/** \brief This API will read data from Message Ram of Can Hw Unit.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] memType Base Address of controller.
 * \param[in] bufNum Transmit Buffer number.
 * \param[in] elem Pointer to location to store value read.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_ReadMsgRamPriv(uint32 baseAddr, uint32 memType, uint8 bufNum,
                   P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem);

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
Can_PeriodicReadbackPrv(uint8 Controller,
                        P2VAR(Can_PeriodicReadBackDataType, AUTOMATIC, CAN_APPL_DATA) ReadBackRegisterdata);

/** \brief This service shall load the specific ECC register based on the parameters.
 *
 * \param[in] baseAddr CAN controller base address.
 * \param[in] regOffset regOffset for the register to load.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE) Can_EccLoadRegister(uint32 baseAddr, uint32 regOffset);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
#endif /* CAN_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Can_Priv.h
 *********************************************************************************************************************/
