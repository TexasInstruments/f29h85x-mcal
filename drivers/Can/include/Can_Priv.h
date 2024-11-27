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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
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

/** \addtogroup CAN Can API GUIDE Header file Can_Priv.h
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_mcanss.h"
#include "Can_Reg_Access.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief  Can classic payload max bytes */
#define CAN_CLASSIC_PAYLOAD_MAX_BYTES     (8U)

/** \brief   Can FD payload max bytes */
#define CAN_FD_PAYLOAD_MAX_BYTES          (64U)

/** \brief   Can max controller supported */
#define CAN_MAX_CONTROLLER_SUPPORTED      (1U)

/** \brief Can TDCR and TDCF max   */
#define CAN_TDCR_TDCF_MAX                 (0x7FU)

/** \brief Can TDCR and TDCO max   */
#define CAN_TDCR_TDCO_MAX                 (0x7FU)

/** \brief Can id STD   */
#define CAN_ID_STD                        (0x0U)

/** \brief Can id XTD   */
#define CAN_ID_XTD                        (0x1U)

/** \brief Can id MIXED   */
#define CAN_ID_MIXED                      (0x2U)

/** \brief Can XID MSGID mask    */
#define CAN_XTD_MSGID_MASK                ((uint32)0x1fffffffU)

/** \brief Can STD MSGID mask    */
#define CAN_STD_MSGID_MASK                ((uint32)0x7ffU)

/** \brief Can STD MSGID shift    */
#define CAN_STD_MSGID_SHIFT               ((uint32)18U)

/** \brief Can id can controller type mask    */
#define CAN_ID_CAN_CONTROLLER_TYPE_MASK   ((uint32)0x40000000U)

/** \brief Can msg type mask   */
#define CAN_MSG_TYPE_MASK                 ((uint32)0x40000000U)

/** \brief Can msg type mask   */
#define CAN_MSG_ID_TYPE_EXT               ((uint32)0x80000000U)

/** \brief Can msg type classic can   */
#define CAN_MSG_TYPE_CLASSIC_CAN          ((uint32)0x0U)

/** \brief Can msg type can id   */
#define CAN_MSG_TYPE_CAN_FD               ((uint32)0x40000000U)


/** \brief  Standard ID Filter Element Size */
#define MCAN_MSG_RAM_STD_ELEM_SIZE          (1U)
/** \brief  Extended ID Filter Element Size */
#define MCAN_MSG_RAM_EXT_ELEM_SIZE          (2U)
/** \brief  Tx/Rx Mailbox Size */
#define MCAN_MSG_RAM_TX_RX_ELEM_SIZE        (18U)

/** \brief MCAN IP TX buffer max number */
#define MCAN_TX_BUFFER_MAX_NUM                             (32U)
/** \brief MCAN IP RX buffer max number */
#define MCAN_RX_BUFFER_MAX_NUM                             (64U)
/** \brief MCAN rx FIFO_0 max number */
#define MCAN_RX_FIFO_0_MAX_NUM                             (64U)
/** \brief MCAN rx FIFO_1 max number */
#define MCAN_RX_FIFO_1_MAX_NUM                             (64U)

/** \brief MCAN TX_MB max number */
#define MCAN_TX_MB_MAX_NUM                                 (32U)
/** \brief MCAN RX_MB max number */
#define MCAN_RX_MB_MAX_NUM                                 (32U)

/** \brief Macro defines mask for all the interrupts status for MCAN. */
#define CAN_INTR_MASK_ALL                 ((uint32)MCAN_IR_RF0N_MASK | \
                                           (uint32)MCAN_IR_RF0W_MASK | \
                                           (uint32)MCAN_IR_RF0F_MASK | \
                                           (uint32)MCAN_IR_RF0L_MASK | \
                                           (uint32)MCAN_IR_RF1N_MASK | \
                                           (uint32)MCAN_IR_RF1W_MASK | \
                                           (uint32)MCAN_IR_RF1F_MASK | \
                                           (uint32)MCAN_IR_RF1L_MASK | \
                                           (uint32)MCAN_IR_HPM_MASK |  \
                                           (uint32)MCAN_IR_TC_MASK |   \
                                           (uint32)MCAN_IR_TCF_MASK |  \
                                           (uint32)MCAN_IR_TFE_MASK |  \
                                           (uint32)MCAN_IR_TEFN_MASK | \
                                           (uint32)MCAN_IR_TEFW_MASK | \
                                           (uint32)MCAN_IR_TEFF_MASK | \
                                           (uint32)MCAN_IR_TEFL_MASK | \
                                           (uint32)MCAN_IR_TSW_MASK |  \
                                           (uint32)MCAN_IR_MRAF_MASK | \
                                           (uint32)MCAN_IR_TOO_MASK |  \
                                           (uint32)MCAN_IR_DRX_MASK |  \
                                           (uint32)MCAN_IR_BEC_MASK |  \
                                           (uint32)MCAN_IR_BEU_MASK |  \
                                           (uint32)MCAN_IR_ELO_MASK |  \
                                           (uint32)MCAN_IR_EP_MASK |   \
                                           (uint32)MCAN_IR_EW_MASK |   \
                                           (uint32)MCAN_IR_BO_MASK |   \
                                           (uint32)MCAN_IR_WDI_MASK |  \
                                           (uint32)MCAN_IR_PEA_MASK |  \
                                           (uint32)MCAN_IR_PED_MASK |  \
                                           (uint32)MCAN_IR_ARA_MASK)

/** \brief MCAN Interrupt line 0 */
#define MCAN_INT_LINE_0                                     (1U)

/** \brief MCAN Interrupt line 0 */
#define MCAN_INT_LINE_1                                     (2U)

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
    uint32 lss;
    /** \brief Extended ID Filter List Start Address */
    uint32 flesa;
    /** \brief List Size: Extended ID
                0 = No standard Message ID filter
                1-64 = Number of standard Message ID filter elements
                others = Values greater than 64 are interpreted as 64 */
    uint32 lse;
    /** \brief Tx Buffers Start Address */
    uint32 txStartAddr;
    /** \brief Number of Dedicated Transmit Buffers
                0 = No Dedicated Tx Buffers
                1-32 = Number of Dedicated Tx Buffers
                others = Values greater than 32 are interpreted as 32 */
    uint8 txBufNum;
    /** \brief Transmit FIFO/Queue Size
                0 = No Tx FIFO/Queue
                1-32 = Number of Tx Buffers used for Tx FIFO/Queue
                others = Values greater than 32 are interpreted as 32 */
    uint8 txFIFOSize;
    /** \brief Tx FIFO/Queue Mode
                0 = Tx FIFO operation
                1 = Tx Queue operation */
    uint32 txBufMode;
    /** \brief Tx Buffer Element Size */
    uint32 txBufElemSize;
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
    uint32 rxFIFO0size;
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
    uint32 rxFIFO1size;
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
    /** \brief Rx Buffer Element Size */
    uint32 rxBufElemSize;
    /** \brief Rx FIFO0 Element Size */
    uint32 rxFIFO0ElemSize;
    /** \brief Rx FIFO1 Element Size */
    uint32 rxFIFO1ElemSize;
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
    Can_MsgRAMConfigParams configParams;
    /** \brief Standard ID filter elements */
    Can_StdMsgIDFilterElement stdMsgIDFilterList[KMAX_MB_PER_CONTROLLER];
    /** \brief Extended ID filter elements */
    Can_ExtMsgIDFilterElement extMsgIDFilterList[KMAX_MB_PER_CONTROLLER];
    /** \brief Standard ID filter element number */
    uint8 stdFilterNum;
    /** \brief Extended ID filter element number */
    uint8 extFilterNum;
    /** \brief Mapping of HTRH
                txMbMapping[0U][0-KMAX_MB_PER_CONTROLLER]: HTH to be stored into Buffer
                txMbMapping[1U][0-KMAX_MB_PER_CONTROLLER]: HTH to be stored into FIFO
                txMbMapping[m][n] = 0xFF : Initialization value */
    uint8 txMbMapping[2U][KMAX_MB_PER_CONTROLLER];
    /** \brief Mapping of HTH to HW mailboxes */
    uint8 hthToMbMapping[KMAX_MB_PER_CONTROLLER];
    /** \brief Tx number of Buffer elements */
    uint16 txBuffNum;
    /** \brief Tx number of FIFO elements */
    uint16 txFIFONum;
    /** \brief Rx number of Buffer elements */
    uint16 rxBuffNum;
    /** \brief Rx number of FIFO elements */
    uint16 rxFIFONum;
} Can_FdMsgRAMConfigObjType;

/*
 *Design: MCAL-25944
 */
/** \brief   Can controller object structure */
typedef struct Can_ControllerObjType_s
{
    /** \brief Bus off recovery status */
    boolean canBusOffRecoveryStatus;
    /** \brief TxRXx Status of Mailbox */
    uint8 canTxStatus[KMAX_MB_PER_CONTROLLER];
    /** \brief Total number of interrupts for this controller */
    uint8 canInterruptCounter;
    /** \brief Set BRP value */
    uint16 canBaud;
    /** \brief SDU pointer */
    uint8 canSduPtr[CAN_FD_PAYLOAD_MAX_BYTES];
    /** \brief Can Controller */
    Can_ControllerType canControllerConfig;
    /** \brief Max Baud Config Index in BaudRateConfigList */
    uint32 MaxBaudConfigID;
    /** \brief State of Can */
    Can_ControllerStateType canState;
    /** \brief Structure which includes HOH, CAN Controller ID and specific CanId */
    Can_HwType mailboxCfg;
    /** \brief Structure which includes pointer to the SDU and it's length */
    PduInfoType pduInfo;
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
    /** \brief Tx/Rx Pdu ID Info */
    PduIdType canTxRxPduId[KMAX_MB_PER_CONTROLLER];
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
    Can_MailboxObjType canMailbox[KMAX_MAILBOXES];
    /** \brief MB array for all controllers */
    Can_MailboxObjType canTxMailbox[KMAX_MAILBOXES];
    /** \brief MB array for all controllers */
    Can_MailboxObjType canRxMailbox[KMAX_MAILBOXES];
    /** \brief MaxCount of Controller in Controller List */
    uint8 canMaxControllerCount;
    /** \brief MaxMbCount in MB list in all controller */
    uint8 maxMbCnt;
    /** \brief MaxMbCount in MB list in all controller */
    uint8 maxTxMbCnt;
    /** \brief MaxMbCount in MB list in all controller */
    uint8 maxRxMbCnt;
    /** \brief CAN Controller ID mapping */
    uint32 controllerIDMap[KMAX_CONTROLLER];
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    /** \brief Icom Configuration List */
    Can_IcomConfigType      IcomConfigurationList[MAX_ICOM_CONFIGURATION];
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
    CAN_MEM_TYPE_FIFO = 1U
} Can_MemType;

/*
 *Design: MCAL-25948
 */
/** \brief   Structure for CAN Tx Buffer element. */
typedef struct Can_TxBufElementType_s
{
    /** \brief Identifier */
    uint32 id;
    /** \brief Extended Identifier
                0 = 11-bit standard identifier
                1 = 29-bit extended identifier */
    uint8 xtd;
    /** \brief Data Length Code
                0-8  = CAN  CAN FD transmit frame has 0-8 data bytes
                9-15 = CAN FD transmit frame has 12/16/20/24/32/48/64 data bytes */
    uint32 dataLength;
    /** \brief Bit Rate Switching
                0 = CAN FD frames transmitted without bit rate switching
                1 = CAN FD frames transmitted with bit rate switching */
    boolean brs;
    /** \brief FD Format
                0 = Frame transmitted in Classic CAN format
                1 = Frame transmitted in CAN FD format */
    boolean fdf;
    /** \brief Can Message Ram Type */
    Can_MemType memType;
    /** \brief Data bytes.
                Only first dlc number of bytes are valid. */
    uint8  data[CAN_FD_PAYLOAD_MAX_BYTES];
}Can_TxBufElementType;

/*
 *Design: MCAL-25949
 */
/** \brief   Structure for CAN Rx Buffer element. */
typedef struct Can_RxBufElementType_s
{
    /** \brief Identifier */
    uint32 id;
    /** \brief Extended Identifier
                0 = 11-bit standard identifier
                1 = 29-bit extended identifier */
    uint8 xtd;
    /** \brief Data Length Code
                0-8  = CAN  CAN FD transmit frame has 0-8 data bytes
                9-15 = CAN FD transmit frame has 12/16/20/24/32/48/64 data bytes */
    uint32 dataLength;
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
    uint8  data[CAN_FD_PAYLOAD_MAX_BYTES];
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
    uint32 fillLvl;
    /** \brief Rx FIFO Get Index  */
    uint32 getIdx;
    /** \brief Rx FIFO Put Index  */
    uint32 putIdx;
    /** \brief Rx FIFO Full
        0 = Rx FIFO not full
        1 = Rx FIFO full */
    boolean fifoFull;
    /** \brief Rx FIFO Message Lost */
    uint32 msgLost;
} Can_RxFIFOStatusType;

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
 * \param[in] canHtrhMbMap Pointer to Htrh to mailbox mapping.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitConfigPriv(Can_ControllerObjType *canController, \
                      const Can_MailboxObjType *canMailbox, \
                      uint8 maxMbCnt, \
                      uint8* canHtrhMbMap);

/** \brief This API will configure a bit timings for MCAN module.
 * 
 * \param[in] baseAddr Base Address of the MCAN Registers.
 * \param[in] baudConfig Configuration parameters for MCAN bit timing.
 * \pre None
 * \post None
 * \return The status of whether the Baud Rate configuration is successful
 * \retval E_OK - If baud rate config is successful.
 * \retval E_NOT_OK - If baud rate config is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HWSetBaudRatePriv(uint32 baseAddr, const Can_BaudConfigType* baudConfig);

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
Can_ErrorStateType Can_GetProtocolStatusPriv(const Can_ControllerObjType* canController);

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
Std_ReturnType Can_HWCheckWakeupPriv(const Can_ControllerType* configParam);

/** \brief This function will start Can HW Unit.
 * 
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status 
 *                              to update, CanIf module indication done information
 * \param[out] canIfIndication Updates, Start successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether starting of Can HW Unit is successful
 * \retval E_OK - If startup is successful.
 * \retval E_NOT_OK - If startup is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitStartPriv(Can_ControllerObjType* controllerObj, Can_CanIfIndicationType* canIfIndication);


/** \brief This function will stop Can HW Unit.
 * 
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status 
 *                              to update, CanIf module indication done information
 * \param[out] canIfIndication Updates, Stop successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether stopping of Can HW Unit is successful
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitStopPriv(Can_ControllerObjType* controllerObj, Can_CanIfIndicationType* canIfIndication);

/** \brief This function will sleep Can HW Unit.
 * 
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status 
 *                              to update, CanIf module indication done information
 * \param[out] canIfIndication Updates, Sleep successful status to the pointer
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether sleep of Can HW Unit is successful
 * \retval E_OK - If sleep is successful.
 * \retval E_NOT_OK - If sleep is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitSleepPriv(Can_ControllerObjType* controllerObj, Can_CanIfIndicationType* canIfIndication);

/** \brief This function will wakeup Can HW Unit.
 * 
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canIfIndication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status 
 *                              to update, CanIf module indication done information
 * \param[out] canIfIndication Updates, Wakeup successful status to the pointer 
 * \pre Can module must be initialized
 * \post None
 * \return The status of whether wakeup of Can HW Unit is successful
 * \retval E_OK - If wakeup is successful.
 * \retval E_NOT_OK - If wakeup is unsuccessful.
 *
 *****************************************************************************/
Std_ReturnType Can_HwUnitWakeupPriv(Can_ControllerObjType* controllerObj, Can_CanIfIndicationType* canIfIndication);

/** \brief This function will check if desired Tx mailbox is free.
 * 
 * \param[in] mailboxCfg Pointer to Mailbox structure.
 * \param[in] canController Pointer to Can controller Config structure.
 * \param[in] msgObj HW object in the controller.
 * \param[in] htrh HW object in the configuration.
 * \pre Can module must be initialized
 * \post None
 * \return The status of Tx mailbox free/busy/not-found
 * \retval E_OK - If free message object is found.
 * \retval E_NOT_OK - If free message object is not found.
 * \retval CAN_BUSY - If message is already pending.
 *
 *****************************************************************************/
Std_ReturnType Can_GetFreeTxMsgObjPriv(const Can_MailboxType *mailboxCfg, \
                                   const Can_ControllerObjType *canController, \
                                   Can_HwHandleType *msgObj, \
                                   uint8 htrh);

/** \brief This function will write into the Transmit Mailbox.
 * 
 * \param[in] mailboxCfg Pointer to Mailbox structure.
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] hth HW object in the configuration.
 * \param[in] messageBox HW object in the controller.
 * \param[in] pduInfo Pointer to SDU user memory, DLC and Identifier.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_WriteTxMailboxPriv(const Can_MailboxType *mailboxCfg, \
                        Can_ControllerObjType *controllerObj, \
                        uint8 hth, \
                        uint32 messageBox, \
                        const Can_PduType *pduInfo);

/** \brief This function will poll for Tx confirmation.
 * 
 * \param[in] canController Pointer to Can controller Config structure.
 * \param[in] mailboxCfg Pointer to Mailbox structure.
 * \param[in] htrh HW object in the configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_HwUnitTxDonePollingPriv(Can_ControllerObjType *canController, \
                             const Can_MailboxObjType *canMailbox, \
                             uint8 htrh);

/** \brief This function will read Rx messages from Mailbox.
 * 
 * \param[in] controllerObj Pointer to Can controller Config structure.
 * \param[in] canMailbox Pointer to Mailbox structure.
 * \param[in] maxMbCnt Maximum number of mailbox configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
void Can_ReadRxMailboxPriv(Can_ControllerObjType *controllerObj, \
                       const Can_MailboxObjType *canMailbox, \
                       uint8 maxMbCnt);

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
 * \param[in] indication Pointer to a struct containing Start/Stop/Sleep/Wakeup controller status indication done to 
 *                       CanIf module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
void Can_ModeProcessPriv(Can_ControllerObjType *controllerObj, Can_CanIfIndicationType* indication);


/*********************************************************************************************************************
 ** \brief Can_ProcessISR: Invoked by the respective CAN controller ISR.
 *
 * This Interrupt function is invoked when CAN Tx/Rx/Bus-Off interrupts occur for a controller, inside the 
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
void Can_ProcessISR(Can_ControllerInstance canInstance, uint32 lineSelect);                           

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
 #endif /* CAN_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Can_Priv.h
 *********************************************************************************************************************/
