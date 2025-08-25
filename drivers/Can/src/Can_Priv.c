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
 *  File:       Can_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains controller dependent local functions and private functions
 *                to be used in Can.c.
 *********************************************************************************************************************/
/*
 *Design: MCAL-22825, MCAL-22842, MCAL-22827, MCAL-22880, MCAL-23013, MCAL-23010
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Can.h"
#include "Can_Priv.h"
#include "Can_Cfg.h"
#include "EcuM_Cbk.h"
#include "hw_sysctl.h"
#include "Os.h"
#if (CAN_CFG_DEM_ENABLE == STD_ON)
#include "Dem.h"
#endif
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "CanIf_Cbk.h"
#include "Mcal_Lib.h"
#include "Mcal_Lib_RegAccess.h"
#include "SchM_Can.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CAN_INVALID_BASE_ADDR (0x00000000U)

/**
 * \brief  Mask and shift for Tx Buffers elements.
 */
#define MCANSS_TX_BUFFER_ELEM_ID_SHIFT  (0U)
#define MCANSS_TX_BUFFER_ELEM_ID_MASK   (0x1FFFFFFFU)
#define MCANSS_TX_BUFFER_ELEM_RTR_SHIFT (29U)
#define MCANSS_TX_BUFFER_ELEM_RTR_MASK  (0x20000000U)
#define MCANSS_TX_BUFFER_ELEM_XTD_SHIFT (30U)
#define MCANSS_TX_BUFFER_ELEM_XTD_MASK  (0x40000000U)
#define MCANSS_TX_BUFFER_ELEM_ESI_SHIFT (31U)
#define MCANSS_TX_BUFFER_ELEM_ESI_MASK  (0x80000000U)
#define MCANSS_TX_BUFFER_ELEM_DLC_SHIFT (16U)
#define MCANSS_TX_BUFFER_ELEM_DLC_MASK  (0x000F0000U)
#define MCANSS_TX_BUFFER_ELEM_BRS_SHIFT (20U)
#define MCANSS_TX_BUFFER_ELEM_BRS_MASK  (0x00100000U)
#define MCANSS_TX_BUFFER_ELEM_FDF_SHIFT (21U)
#define MCANSS_TX_BUFFER_ELEM_FDF_MASK  (0x00200000U)
#define MCANSS_TX_BUFFER_ELEM_EFC_SHIFT (23U)
#define MCANSS_TX_BUFFER_ELEM_EFC_MASK  (0x00800000U)
#define MCANSS_TX_BUFFER_ELEM_MM_SHIFT  (24U)
#define MCANSS_TX_BUFFER_ELEM_MM_MASK   (0xFF000000U)

/**
 * \brief  Mask and shift for Rx Buffers elements.
 */
#define MCANSS_RX_BUFFER_ELEM_ID_SHIFT   (0U)
#define MCANSS_RX_BUFFER_ELEM_ID_MASK    (0x1FFFFFFFU)
#define MCANSS_RX_BUFFER_ELEM_RTR_SHIFT  (29U)
#define MCANSS_RX_BUFFER_ELEM_RTR_MASK   (0x20000000U)
#define MCANSS_RX_BUFFER_ELEM_XTD_SHIFT  (30U)
#define MCANSS_RX_BUFFER_ELEM_XTD_MASK   (0x40000000U)
#define MCANSS_RX_BUFFER_ELEM_ESI_SHIFT  (31U)
#define MCANSS_RX_BUFFER_ELEM_ESI_MASK   (0x80000000U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT (0U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_MASK  (0x0000FFFFU)
#define MCANSS_RX_BUFFER_ELEM_DLC_SHIFT  (16U)
#define MCANSS_RX_BUFFER_ELEM_DLC_MASK   (0x000F0000U)
#define MCANSS_RX_BUFFER_ELEM_BRS_SHIFT  (20U)
#define MCANSS_RX_BUFFER_ELEM_BRS_MASK   (0x00100000U)
#define MCANSS_RX_BUFFER_ELEM_FDF_SHIFT  (21U)
#define MCANSS_RX_BUFFER_ELEM_FDF_MASK   (0x00200000U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT (24U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_MASK  (0x7F000000U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT (31U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_MASK  (0x80000000U)

/**
 * \brief  Macro for Interrupt Line enable mask.
 */
#define MCANSS_INTR_LINE_EN_MASK ((MCAN_ILE_EINT0_MASK | MCAN_ILE_EINT1_MASK))

/**
 * \brief  Macro for Interrupt Line select mask for 0.
 */
#define MCANSS_INTR_LINE_0_MASK                                                                                   \
    ((MCAN_ILS_ARAL_MASK | MCAN_ILS_PEDL_MASK | MCAN_ILS_PEAL_MASK | MCAN_ILS_WDIL_MASK | MCAN_ILS_BOL_MASK |     \
      MCAN_ILS_EWL_MASK | MCAN_ILS_EPL_MASK | MCAN_ILS_ELOL_MASK | MCAN_ILS_BEUL_MASK | MCAN_ILS_BECL_MASK |      \
      MCAN_ILS_TOOL_MASK | MCAN_ILS_MRAFL_MASK | MCAN_ILS_TSWL_MASK | MCAN_ILS_TEFLL_MASK | MCAN_ILS_TEFFL_MASK | \
      MCAN_ILS_TEFWL_MASK | MCAN_ILS_TEFNL_MASK | MCAN_ILS_TFEL_MASK | MCAN_ILS_TCFL_MASK | MCAN_ILS_TCL_MASK |   \
      MCAN_ILS_HPML_MASK))

/**
 * \brief  Macro for Interrupt Line select mask for 1.
 */
#define MCANSS_INTR_LINE_1_MASK                                                                                     \
    ((MCAN_ILS_RF1LL_MASK | MCAN_ILS_RF1FL_MASK | MCAN_ILS_RF1WL_MASK | MCAN_ILS_RF1NL_MASK | MCAN_ILS_RF0LL_MASK | \
      MCAN_ILS_RF0FL_MASK | MCAN_ILS_RF0WL_MASK | MCAN_IR_DRX_MASK | MCAN_ILS_RF0NL_MASK))

/**
 * \brief  Macro for standard Message ID filter.
 */
#define MCANSS_STD_ID_FILTER_SIZE_WORDS (1U)

/**
 * \brief  Macro for extended Message ID filter.
 */
#define MCANSS_EXT_ID_FILTER_SIZE_WORDS (2U)

/**
 * \brief  Mask and shift for Standard Message ID Filter Elements.
 */
#define MCANSS_STD_ID_FILTER_SFID2_SHIFT           (0U)
#define MCANSS_STD_ID_FILTER_SFID2_MASK            (0x000003FFU)
#define MCANSS_STD_ID_FILTER_SFID1_SHIFT           (16U)
#define MCANSS_STD_ID_FILTER_SFID1_MASK            (0x03FF0000U)
#define MCANSS_STD_ID_FILTER_SFEC_SHIFT            (27U)
#define MCANSS_STD_ID_FILTER_SFEC_MASK             (0x38000000U)
#define MCANSS_STD_ID_FILTER_SFT_SHIFT             (30U)
#define MCANSS_STD_ID_FILTER_SFT_MASK              (0xC0000000U)
#define MCANSS_STD_ID_FILTER_SFID2_EVENT_PIN_SHIFT (6U)
/**
 * \brief  Extended Message ID Filter Element.
 */
#define MCANSS_EXT_ID_FILTER_EFID2_SHIFT           (0U)
#define MCANSS_EXT_ID_FILTER_EFID2_MASK            (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFID1_SHIFT           (0U)
#define MCANSS_EXT_ID_FILTER_EFID1_MASK            (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFEC_SHIFT            (29U)
#define MCANSS_EXT_ID_FILTER_EFEC_MASK             (0xE0000000U)
#define MCANSS_EXT_ID_FILTER_EFT_SHIFT             (30U)
#define MCANSS_EXT_ID_FILTER_EFT_MASK              (0xC0000000U)
#define MCANSS_EXT_ID_FILTER_SFID2_EVENT_PIN_SHIFT (6U)
/**
 * \brief  Macro for Message RAM config.
 */
#define MCAN_MSGRAM_RX_FIFO_0      (0x1U)
#define MCAN_MSGRAM_RX_FIFO_1      (0x2U)
#define MCAN_MSGRAM_RX_BUFFER      (0x7U)
#define MCAN_MSGRAM_CLASSIC_FILTER (0x2U)

/**
 * \brief  MCAN MSG RAM BANK number for ECC AGGR.
 */
#define MCANSS_MSG_RAM_NUM (0U)

#define MAX_UINT32 (0xFFFFFFFFU)
#define MAX_UINT8  (0xFFU)

#define KEY_VALUE          (0x56340000U)
#define MCAN_CLOCK_STOP    (uint32)(0x100U)
#define MCAN_WAKEUP_STATUS (uint32)(0x1U)
#define MCAN_WAKEUP        (uint32)(0x0U)
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"
/** \brief Pointer for the Can global object. */
P2VAR(Can_DriverObjType, CAN_VAR_NO_INIT, CAN_DATA) Can_DriverObjPtr;
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONST_8
#include "Can_MemMap.h"
/** \brief Can data length lookup table. */
static CONST(uint8, CAN_CONST) Can_DataSize[16] = {0U, 1U,  2U,  3U,  4U,  5U,  6U,  7U,
                                                   8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
/** \brief Can hardware object size lookup table. */
static CONST(uint8, CAN_CONST) Can_ObjSize[8] = {4U, 5U, 6U, 7U, 8U, 10U, 14U, 18U};
#define CAN_STOP_SEC_CONST_8
#include "Can_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief This function will enable MCAN interrupts as per config.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] interruptMask Mask for interrupts to be enabled/disabled.
 * \param[in] enable TRUE to enable interrupts, FALSE to disable.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_EnableInterruptPriv(uint32 baseAddr, uint32 interruptMask, boolean enable);

/** \brief This function will select MCAN interrupt lines as per config.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] interruptMask Mask for interrupts to be selected.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_SelectInterruptLinePriv(uint32 baseAddr, uint32 interruptMask);

/** \brief This function will enable MCAN interrupt lines as per config.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] enable TRUE to enable interrupt lines, FALSE to disable.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_EnableInterruptLinePriv(uint32 baseAddr, boolean enable);

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/** \brief This function will check for NULL pointers for Mailbox Config structure.
 *
 * \param[in] ConfigPtr Pointer to post-build configuration data.
 * \pre None
 * \post None
 * \return The status whether Mailbox config pointers are properly initialized.
 * \retval E_OK - If all pointers are initialized properly.
 * \retval E_NOT_OK - If there are NULL pointers present.
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CAN_CODE) Can_CheckMbConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr);
#endif

/** \brief Waits for the intialization of Message RAM to be done.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_WaitForMemoryInitPriv(uint32 baseAddr);

/** \brief This function will get Can module mode of operation.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return Operation Mode of Can Hw Unit.
 * \retval CAN_CONTROLLER_OPERATION_MODE_NORMAL -  CAN normal mode
 * \retval CAN_CONTROLLER_OPERATION_MODE_SW_INIT - CAN SW initialization mode
 *
 *****************************************************************************************/
static FUNC(Can_ControllerOperationMode, CAN_CODE) Can_GetOpModePriv(uint32 baseAddr);

/** \brief This function will set Can module mode of operation.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] cntrMode Mode of operation.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_SetOpModePriv(uint32 baseAddr, Can_ControllerOperationMode cntrMode);

/** \brief This function will get Clock Stop Acknowledgment for Can module.
 *
 * \param[in] instance the Can Controller Instance ID
 * \pre None
 * \post None
 * \return Clock Stop Acknowledgment of Can Hw Unit.
 * \retval CAN_CLOCK_STOP_NO_ACK - No clock stop acknowledged
 * \retval CAN_CLOCK_STOP_ACK -    MCAN may be set in power down
 *
 *****************************************************************************/
static Can_ClockStopAckMode Can_GetClkStopAckPriv(Can_ControllerInstance instance);

/** \brief This function will initialize MCAN registers as per user config.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_InitHwPriv(uint32 baseAddr, P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam);

/** \brief This API will unblock write access to write protected registers.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_WriteProtectedRegUnlockPriv(uint32 baseAddr);

/** \brief This API will block write access to write protected registers.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_WriteProtectedRegLockPriv(uint32 baseAddr);

/** \brief This API will configure Different sections of Message RAM.
 *
 * \param[in] canController Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] maxMbCnt Maximum number of Mailbox to be configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_SetupMsgRamPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                        P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, uint16 maxMbCnt);

/** \brief This API will initialize Message RAM.
 *
 * \param[in] msgRamConfig Message RAM Configuration parameters.
 * \param[in] canControllerCfg Pointer to Can controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_MsgRamConfigInitPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                             P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) canControllerCfg);

/** \brief This API will configure setup Message RAM as per config.
 *
 * \param[in] msgRamConfig Message RAM Configuration parameters.
 * \param[in] mailboxCfg Mailbox Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_SetupRxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                           P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg);

/** \brief This API will configure Different sections of Message RAM.
 *
 * \param[in] msgRamConfig Message RAM Configuration parameters.
 * \param[in] mailboxCfg Mailbox Configuration parameters.
 * \param[in] canControllerCfg Pointer to Can controller config parameters.
 * \param[in] htrh Handle ID of HTH.
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_SetupTxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                           P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg,
                           P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) canControllerCfg, Can_HwHandleType htrh,
                           uint32 baseAddr);

/** \brief This API will add standard filter.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] filtNum Filter number.
 * \param[in] elem Filter Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_AddStdMsgIDFilterPriv(uint32 baseAddr, uint8 filtNum,
                                                      P2CONST(Can_StdMsgIDFilterElement, AUTOMATIC, CAN_CONST) elem);

/** \brief This API will add extended filter.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] filtNum Filter number.
 * \param[in] elem Filter Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_AddExtMsgIDFilterPriv(uint32 baseAddr, uint8 filtNum,
                                                      P2CONST(Can_ExtMsgIDFilterElement, AUTOMATIC, CAN_CONST) elem);

/** \brief This API will enable/disable Loop Back Test Mode for MCAN module.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] loopbackMode Loop Back Mode is enabled if it is TRUE.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_LoopbackModePriv(uint32 baseAddr, boolean loopbackMode);

/** \brief This function will get appropriate interrpt mask based on config.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return Interrupt Mask to be used.
 * \retval returns the value of the type uint32.
 *
 ****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_GetInterruptMaskPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam);

/** \brief This API is used to add Clock Stop Request.
 *
 * \param[in] instance the Can Controller Instance ID
 * \param[in] enable Clock Stop requested if it is TRUE, No Clock Stop is requested if it is FALSE.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_AddClkStopRequestPriv(Can_ControllerInstance instance, boolean enable);

/** \brief This API will cancel all pending transmit messages.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_CancelPendingMsgPriv(uint32 baseAddr);

/** \brief This API will read status of Transmit Buffers.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return Value of Transmit Buffer status register MCAN_TXBRP.
 * \retval returns the value of the type uint32.
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_GetTxBufReqPendPriv(uint32 baseAddr);

/** \brief This API will cancel transmit of particular Tx buffer.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] buffNum Transmit Buffer number.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_TxBufCancelReqPriv(uint32 baseAddr, uint32 buffNum);

/** \brief This API will read status of Transmit Buffers Cancel request.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return Value of Transmit Cancellation status register MCAN_TXBCF.
 * \retval returns the value of the type uint32.
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_TxBufCancelStatusPriv(uint32 baseAddr);

/** \brief This API will read Transmission status of Transmit Buffers.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return Value of Transmit status for Tx buffers register MCAN_TXBTO.
 * \retval returns the value of the type uint32.
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_GetTxBufTransStatusPriv(uint32 baseAddr);

/** \brief This API will add transmit request on particular Tx buffer.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] buffNum Transmit Buffer number.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_TxBufAddReqPriv(uint32 baseAddr, uint8 buffNum);

/** \brief This API will read data from Rx Buffer of CAN Hw Unit.
 *
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] htrh Handle ID of HTH.
 * \param[inout] newDataStatus Pointer to variable to store New Data Status.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_ReadRxBuffPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                       P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, Can_HwHandleType htrh,
                       P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus);

/** \brief This API will read data from Rx FIFO of CAN Hw Unit.
 *
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] htrh Handle ID of HTH.
 * \param[inout] fifoStatus Pointer to FIFO status information.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_ReadRxFIFOPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                       P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, Can_HwHandleType htrh,
                       P2VAR(Can_RxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus);

/** \brief This API will return the status of the current interrupts
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_GetIntrStatus(uint32 baseAddr);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/** \brief This function will validate the icom configuration critiria based on rx message configs.
 *
 * \param[in] can_identifier Identifier to validate.
 * \param[in] sduptr Pointer to received data.
 * \param[in] IcomConfigId current icom configuration id
 * \param[in] canController Pointer to Can controller config parameters.
 * \pre None
 * \post None
 * \return The status of whether the icom configuration critiria matched or not
 * \retval E_OK - If icom configuration matched.
 * \retval E_NOT_OK - If icom configuration not matched.
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CAN_CODE)
    Can_ValidateIcomConfigCriteriaPriv(uint32 can_identifier, P2CONST(uint8, AUTOMATIC, CAN_CONST) sduptr,
                                       uint8  IcomConfigId,
                                       P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController);
#endif

/** \brief This function will clear pending CAN interrupts.
 *
 * \param[in] baseAddr Base Address of the MCAN Registers.
 * \param[in] intrMask Mask for interrupts to be cleared.
 * \param[in] lineSelect Interrupt line select value.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_ClearIntrStatusPriv(uint32 baseAddr, uint32 intrMask, uint32 lineSelect);

/** \brief This API will clear new Rx data status for Can Hw Unit.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] newDataStatus Bits to be cleared.
 * \param[in] buffNum Buffer number.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_ClearNewDataStatusPriv(uint32 baseAddr, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus,
                               uint8  buffNum);

/** \brief This API will read status of Rx FIFO0/FIFO1.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] fifoStatus Pointer to location to store value read.
 * \param[in] hwHandle Hardware handle indicating FIFO0 or FIFO1.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_GetRxFIFOStatusPriv(uint32 baseAddr, P2VAR(Can_RxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus,
                            uint8  hwHandle);

/** \brief This API will read status of Tx FIFO.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] fifoStatus Pointer to location to store value read.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_GetTxFIFOStatusPriv(uint32 baseAddr, P2VAR(Can_TxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus);

/** \brief This API will read new Rx data status for Can Hw Unit.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] newDataStatus Pointer to variable to store New Data Status.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_GetNewDataStatusPriv(uint32 baseAddr, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus);

/** \brief This API will process bus off interrupts.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] intrStatus Status of the current interrupts.
 * \param[in] canControllerObj Pointer to Can controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_CheckBusOffPriv(uint32 intrStatus, uint32 baseAddr,
                        P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canControllerObj);

/** \brief This API will reads the elapsed value with respect to a particular instance of the
 *counter.
 *
 * \param[in] bitPos Indicates the bit position.
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_WaitForTxBufCancelReqPriv(uint32 bitPos, uint32 baseAddr);

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/** \brief This function will check for NULL pointers for Controller Config structure.
 *
 * \param[in] loopCount Count of controller.
 * \param[in] ConfigPtr Pointer to Can controllers Config structure.
 * \pre None
 * \post None
 * \return The status whether Controller config pointers are properly initialized.
 * \retval E_OK - If all pointers are initialized properly.
 * \retval E_NOT_OK - If there are NULL pointers present.
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CAN_CODE)
    Can_CheckBaudRateConfigList(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr, uint32 loopCount);
#endif

/** \brief This function will check only Tx buffers.
 *
 * \param[in] txStat Count of controller.
 * \param[in] canCntrlObj Pointer to Can controller config parameters.
 * \param[in] canMailObj Message RAM Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE)
    Can_CheckAllTxBuffers(uint32 txStat, P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canCntrlObj,
                          P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailObj);

/** \brief This function will check for pending message.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] canController Pointer to Can controller config parameters.
 * \param[in] msgObj Handles the Can HW unit.
 * \param[in] loopCnt count of Tx Buffer
 * \pre None
 * \post None
 * \return returns CAN_BUSY and E_OK
 * \retval CAN_BUSY - pending message
 * \retval E_OK - no pending message.
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CAN_CODE)
    Can_CheckPendingMsgPriv(P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController,
                            VAR(uint8, AUTOMATIC) loopCnt, VAR(uint32, AUTOMATIC) baseAddr,
                            P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) msgObj);

/** \brief This function will check for Icom configuration.
 *
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canIdentifier Holds Can Identifier value
 * \pre None
 * \post None
 * \return returns the receive indication status
 * \retval returns the value of type boolean
 *
 *****************************************************************************/
static FUNC(boolean, CAN_CODE)
    Can_RxIndicationStatusPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                               VAR(uint32, AUTOMATIC) canIdentifier);

/** \brief This function returns Id of Can Frame.
 *
 * \param[in] elem Pointer to location to store value read.
 * \pre None
 * \post None
 * \return returns Id of Can Frame.
 * \retval returns uint32 type data.
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE) Can_GetCanIdentifier(P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem);

/** \brief This API will check for bit position.
 *
 * \param[in] buffNum Transmit Buffer number.
 * \param[in] newDataStatus Pointer to variable to store New Data Status.
 * \pre None
 * \post None
 * \return The status of appropriate mailbox if any message is received
 * \retval E_OK - If any message is received.
 * \retval E_NOT_OK - If any message is not received.
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CAN_CODE)
    Can_BitPos(VAR(uint8, AUTOMATIC) buffNum, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus);

/** \brief This function will Copying payload into SDU.
 *
 * \param[in] canDataLength Frame length of msg.
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] elem Pointer to location to store value read.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_CopyPayloadToSdu(VAR(uint8, AUTOMATIC) canDataLength,
                                                 P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                                                 P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem);

/** \brief This service shall configure the ECC module based on the configuration.
 *
 * \param[in] baseAddr CAN controller base address.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_EccConfigPriv(uint32 baseAddr);

/** \brief This service shall copy data from pdu info to regval.
 *
 * \param[in] loopCnt Current loopcount of the data
 * \param[in] pdu_Info Pdu info from the can_write API.
 * \param[in] Paddingvalue Padding value from mailbox
 * \pre None
 * \post None
 * \return Register value to write in message ram.
 * \retval Register value to write in message ram.
 *
 *****************************************************************************/
static FUNC(uint32, CAN_CODE)
    Can_CopyodddataPrv(P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) loopCnt,
                       P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pdu_Info, uint8 Paddingvalue);

/** \brief This service shall process the wakeup events and send to EcuM.
 *
 * \param[in] instance CAN controller instance.
 * \param[in] canController CAN controller object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CAN_CODE)
Can_ProcessWakeUpPrv(Can_ControllerInstance instance,
                     P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/** \brief This service shall check the rx message for Icom.
 *
 * \param[in] RxMessage Rx message object from Icom data.
 * \param[in] sduData Received Sdu data.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK if the received data matched to any configured data
 * \retval E_NOT_OK if the received data doesn't match to any configured data
 *
 *****************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
Can_IcomCheckRxmsgPriv(P2CONST(Can_IcomRxMessageType, AUTOMATIC, CAN_CONST) RxMessage, uint64 sduData);
#endif

/** \brief This service shall increase passing parameter by 4 after check .
 *
 * \param[in] loopCnt loop count to increase.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CAN_CODE) Can_Loopcountincreaseby4Prv(P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) loopCnt);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/*
 *Design: MCAL-24211
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_CheckInitDetPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) returnStatus = E_NOT_OK;

    if (NULL_PTR != ConfigPtr)
    {
        returnStatus = Can_CheckControllerConfigPriv(ConfigPtr);

        if ((Std_ReturnType)E_OK == returnStatus)
        {
            returnStatus = Can_CheckMbConfigPriv(ConfigPtr);
        }
        else
        {
            /*  Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return returnStatus;
}
#endif

/*
 *Design: MCAL-24212
 */
FUNC(void, CAN_CODE)
Can_ResetDrvObjPriv(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj)
{
    VAR(uint8, AUTOMATIC) controllerIndx;
    VAR(uint8, AUTOMATIC) mbIndx;

    for (controllerIndx = ((uint8)0U); controllerIndx < (uint8)KMAX_CONTROLLER; controllerIndx++)
    {
        drvObj->canController[controllerIndx].canBaud                 = ((uint16)0U);
        drvObj->canController[controllerIndx].canBusOffRecoveryStatus = FALSE;
        drvObj->canController[controllerIndx].canInterruptCounter     = ((uint8)0U);
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
        drvObj->Can_IcomActivation[controllerIndx] = FALSE;
#endif
        for (mbIndx = ((uint8)0U); mbIndx < (uint8)KMAX_TX_MB_PER_CONTROLLER; mbIndx++)
        {
            drvObj->canController[controllerIndx].canTxStatus[mbIndx]  = ((uint8)0U);
            drvObj->canController[controllerIndx].canTxRxPduId[mbIndx] = ((PduIdType)0U);
        }

        for (mbIndx = ((uint8)0U); mbIndx < (uint8)CAN_FD_PAYLOAD_MAX_BYTES; mbIndx++)
        {
            drvObj->canController[controllerIndx].canSduPtr[mbIndx] = ((uint8)0U);
        }
    }
}

/*
 *Design: MCAL-23023
 */
FUNC(void, CAN_CODE)
Can_InitDrvObjPriv(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj,
                   P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr)
{
    VAR(uint8, AUTOMATIC) controllerIndx;
    VAR(Can_HwHandleType, AUTOMATIC) mbIndx;
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) IcomIndex;
#endif

    for (controllerIndx = ((uint8)0U); controllerIndx < (uint8)KMAX_CONTROLLER; controllerIndx++)
    {
        drvObj->canController[controllerIndx].canControllerConfig = *ConfigPtr->CanControllerList[controllerIndx];

        drvObj->canController[controllerIndx].MaxBaudConfigID = ConfigPtr->MaxBaudConfigID[controllerIndx];

        drvObj->controllerIDMap[ConfigPtr->CanControllerList[controllerIndx]->CanControllerInstance] = controllerIndx;
    }
    drvObj->canMaxControllerCount = ConfigPtr->CanMaxControllerCount;
    drvObj->maxMbCnt              = ConfigPtr->MaxMbCnt;
    /* Copy all mailboxes */
    for (mbIndx = ((Can_HwHandleType)0U); mbIndx < (Can_HwHandleType)KMAX_MAILBOXES; mbIndx++)
    {
        drvObj->canMailbox[mbIndx].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
    }
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    for (IcomIndex = ((uint32)0U); IcomIndex < (uint32)MAX_ICOM_CONFIGURATION; IcomIndex++)
    {
        drvObj->IcomConfigurationList[IcomIndex] = *ConfigPtr->IcomConfigurationList[IcomIndex];
    }
#endif
    Can_DriverObjPtr = drvObj;
}

/*
 *Design: MCAL-23025
 */
FUNC(void, CAN_CODE)
Can_HwUnitConfigPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                     P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, uint16 maxMbCnt)
{
    VAR(uint32, AUTOMATIC)
    canCntBaseAddr                = canController->canControllerConfig.CanControllerBaseAddress;
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    /*Change Can controller from reset to normal state*/
    regVal  = MCAL_LIB_REG_READ32(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10);
    regVal &= ~((uint32)1U << ((uint32)canController->canControllerConfig.CanControllerInstance + (uint32)4U));
    MCAL_LIB_REG_WRITE32((CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10), regVal);

    /* Wait for Memory Initialization to happen */
    Can_WaitForMemoryInitPriv(canCntBaseAddr);

    /* Put MCAN in SW initialization mode */
    Can_SetOpModePriv(canCntBaseAddr, (Can_ControllerOperationMode)CAN_CONTROLLER_OPERATION_MODE_SW_INIT);

    /* Unlock Protected Registers */
    Can_WriteProtectedRegUnlockPriv(canCntBaseAddr);

    /* Initialize MCAN HW Module */
    Can_InitHwPriv(canCntBaseAddr, &(canController->canControllerConfig));

    /* Configure Message RAM sections */
    Can_SetupMsgRamPriv(canController, canMailbox, maxMbCnt);

    /* Configure Loopback mode */
    Can_LoopbackModePriv(canCntBaseAddr, canController->canControllerConfig.CanConfigParam.CanLoopbackMode);

    /* Configure MCAN interrupts enabled in config */
    Can_EnableInterruptsPriv(&canController->canControllerConfig);

    /* Configure ECC Registers */
    Can_EccConfigPriv(canCntBaseAddr);

    /* Lock Protected Registers */
    Can_WriteProtectedRegLockPriv(canCntBaseAddr);

    /* Configure Bit Timings */
    Can_HWSetBaudRatePriv(canCntBaseAddr, canController->canControllerConfig.CanControllerDefaultBaudrate);
}

/*
 *Design: MCAL-29472
 */
static FUNC(void, CAN_CODE) Can_EccConfigPriv(uint32 baseAddr)
{
    Can_EccLoadRegister(baseAddr, MCAN_O_ERR_CTRL);
#if (CAN_CFG_ECC == STD_ON)
    VAR(uint32, AUTOMATIC) regVal  = 0U;
    regVal                        |= MCAN_ERR_CTRL_ECC_ENABLE;
    regVal                        |= MCAN_ERR_CTRL_ECC_CHECK;
    regVal                        |= MCAN_ERR_CTRL_CHECK_SVBUS_TIMEOUT;
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_ECC_AGGR_CONTROL), regVal);
#else
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_ECC_AGGR_CONTROL), 0U);
#endif
}

/*
 *Design: MCAL-29473
 */
FUNC(void, CAN_CODE) Can_EccLoadRegister(uint32 baseAddr, uint32 regOffset)
{
    VAR(uint32, AUTOMATIC) regVal                 = 0U;
    VAR(McalLib_TickType, AUTOMATIC) elapsedCount = (McalLib_TickType)0U;

    regVal |= ((uint32)MCANSS_MSG_RAM_NUM << MCAN_ECC_AGGR_VECTOR_SHIFT);
    regVal |= (regOffset << MCAN_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_SHIFT);
    regVal |= ((uint32)1U << MCAN_ECC_AGGR_VECTOR_RD_SVBUS_SHIFT);
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_ECC_AGGR_VECTOR), regVal);

    do
    {
        McalLib_Delay(1);
        elapsedCount += (uint32)15U;
        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION_CYCLES <= elapsedCount)
        {
#if (CAN_CFG_DEM_ENABLE == STD_ON)
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /* Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC_DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while ((uint32)1U !=
             (uint32)MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_ECC_AGGR_VECTOR), MCAN_ECC_AGGR_VECTOR_RD_SVBUS_DONE));
    /* TI_COVERAGE_GAP_STOP */
}

/*
 *Design: MCAL-23024
 */
FUNC(void, CAN_CODE)
Can_HWSetBaudRatePriv(uint32 baseAddr, P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_CONST) baudConfig)
{
    VAR(uint16, AUTOMATIC) brp = (uint16)0U;
    VAR(uint8, AUTOMATIC) seg1 = (uint8)0U;
    VAR(uint8, AUTOMATIC) seg2 = (uint8)0U;
    VAR(uint8, AUTOMATIC) sjw  = (uint8)0U;

    /* The actual interpretation by the hardware for BTP filed is such that,
    one more than the value programmed. Hence deduct 1 from configured value. */

    Can_WriteProtectedRegUnlockPriv(baseAddr);

    if (baudConfig->BrpValue > 0U)
    {
        brp = baudConfig->BrpValue - (uint16)1U;
    }
    else
    {
        /* Do nothing */
    }

    if ((((uint8)(baudConfig->CanControllerPropSeg + baudConfig->CanControllerSeg1)) > 0U) &&
        (((uint8)(baudConfig->CanControllerPropSeg + baudConfig->CanControllerSeg1)) < 255U))
    {
        seg1 = ((uint8)(baudConfig->CanControllerPropSeg + baudConfig->CanControllerSeg1)) - ((uint8)1U);
    }
    else
    {
        /* Do nothing */
    }

    if (baudConfig->CanControllerSeg2 > 0U)
    {
        seg2 = baudConfig->CanControllerSeg2 - (uint8)1U;
    }
    else
    {
        /* Do nothing */
    }

    if (baudConfig->CanControllerSyncJumpWidth > 0U)
    {
        sjw = baudConfig->CanControllerSyncJumpWidth - (uint8)1U;
    }
    else
    {
        /* Do nothing */
    }

    /* Update the nominal bit timing and Prescaler register*/
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_NBTP, MCAN_NBTP_NSJW, sjw);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_NBTP, MCAN_NBTP_NTSEG2, seg2);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_NBTP, MCAN_NBTP_NTSEG1, seg1);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_NBTP, MCAN_NBTP_NBRP, brp);

    if (TRUE == baudConfig->BaudFdEnable)
    {
        /* Update the Data bit timing and Prescaler register*/
        Can_CanSetBaudRatePriv(baseAddr, baudConfig);
        Can_CheckTxDelayCompEnablePriv(baseAddr, baudConfig);
    }
    else
    {
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_DBTP, MCAN_DBTP_TDC, baudConfig->BaudFdRateConfig.TxDelayCompEnable);
    }
    Can_WriteProtectedRegLockPriv(baseAddr);
}

/*
 *Design: MCAL-24213
 */
FUNC(void, CAN_CODE)
Can_DisableInterruptsPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(uint32, AUTOMATIC) interruptMask = (uint32)0U;
    VAR(uint32, AUTOMATIC) baseAddr      = (uint32)0U;

    baseAddr      = configParam->CanControllerBaseAddress;
    interruptMask = Can_GetInterruptMaskPriv(configParam);

    if ((TRUE == configParam->CanControllerActivation) && ((uint32)0U != interruptMask))
    {
        /* Interrupt Disable */
        Can_EnableInterruptPriv(baseAddr, interruptMask, FALSE);

        /* Interrupt Line Disable */
        Can_EnableInterruptLinePriv(baseAddr, FALSE);
    }
    else
    {
        /* No interrupts to be configured */
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-24214
 */
FUNC(void, CAN_CODE)
Can_EnableInterruptsPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(uint32, AUTOMATIC) interruptMask = (uint32)0U;
    VAR(uint32, AUTOMATIC) baseAddr      = (uint32)0U;

    baseAddr      = configParam->CanControllerBaseAddress;
    interruptMask = Can_GetInterruptMaskPriv(configParam);

    if ((uint32)0U != interruptMask)
    {
        /* Interrupt Enable */
        Can_EnableInterruptPriv(baseAddr, interruptMask, TRUE);

        /* Interrupt Line Select */
        Can_SelectInterruptLinePriv(baseAddr, interruptMask);

        /* Interrupt Line Enable */
        Can_EnableInterruptLinePriv(baseAddr, TRUE);
    }
    else
    {
        /* No interrupts to be configured */
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-23026
 */
FUNC(void, CAN_CODE)
Can_HwDeInitPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    /*Change Can controller to reset*/
    regVal  = MCAL_LIB_REG_READ32(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10);
    regVal |= ((uint32)1U << ((uint32)configParam->CanControllerInstance + (uint32)4U));
    MCAL_LIB_REG_WRITE32((CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10), regVal);
}

/*
 *Design: MCAL-23027
 */
FUNC(Can_ErrorStateType, CAN_CODE)
Can_GetProtocolStatusPriv(P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController)
{
    VAR(uint32, AUTOMATIC) baseAddr                = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal                  = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC) returnValue = CAN_ERRORSTATE_ACTIVE;

    baseAddr = canController->canControllerConfig.CanControllerBaseAddress;
    regVal   = MCAL_LIB_REG_READ32(baseAddr + MCAN_PSR);

    if ((uint32)1U == MCAL_LIB_REG_FIELD_GET(regVal, MCAN_PSR_BO))
    {
        returnValue = CAN_ERRORSTATE_BUSOFF;
    }
    else if ((uint32)1U == MCAL_LIB_REG_FIELD_GET(regVal, MCAN_PSR_EP))
    {
        returnValue = CAN_ERRORSTATE_PASSIVE;
    }
    else
    {
        /* Do Nothing  */
    }

    return returnValue;
}

/*
 *Design: MCAL-23028
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_HWCheckWakeupPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue = E_NOT_OK;
    VAR(Can_ClockStopAckMode, AUTOMATIC) csa;

    csa = Can_GetClkStopAckPriv(configParam->CanControllerInstance);

    if (CAN_CLOCK_STOP_ACK == csa)
    {
        /* Sleeping */
        returnValue = E_NOT_OK;
    }
    else
    {
        /* Wakeup */
        returnValue = E_OK;
    }

    return returnValue;
}

/*
 *Design: MCAL-23029
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_HwUnitStartPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) canIfIndication)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue    = E_NOT_OK;
    VAR(uint32, AUTOMATIC) baseAddr               = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC) protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Put Can in operational mode */
    Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode)CAN_CONTROLLER_OPERATION_MODE_NORMAL);

    /* Can is started, report to CanIf */
    controllerObj->canState = CAN_CS_STARTED;
    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STARTED);

    /* Check if there is a bus off */
    protStatus = Can_GetProtocolStatusPriv(controllerObj);
    if (CAN_ERRORSTATE_BUSOFF == protStatus)
    {
        controllerObj->canBusOffRecoveryStatus = TRUE;
    }
    else
    {
        /* Do Nothing */
    }

    returnValue                     = E_OK;
    canIfIndication->stopIndication = TRUE;

    return returnValue;
}

/*
 *Design: MCAL-23030
 */
FUNC(void, CAN_CODE)
Can_HwUnitStopPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                   P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) CanIfIndication)
{
    VAR(uint32, AUTOMATIC) baseAddr = (uint32)0U;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Put Can in SW initilization mode */
    Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode)CAN_CONTROLLER_OPERATION_MODE_SW_INIT);

    /* Wait for Can to reach correct operational mode */

    /* Cancel pending messages */
    Can_CancelPendingMsgPriv(baseAddr);

    /* Can is stopped, report to CanIf */
    controllerObj->canState = CAN_CS_STOPPED;
    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
    CanIfIndication->stopIndication = TRUE;
}

/*
 *Design: MCAL-23031
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_HwUnitSleepPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) Can_CanIfIndication)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue         = E_NOT_OK;
    VAR(McalLib_TickType, AUTOMATIC) startCount        = (McalLib_TickType)0U;
    VAR(McalLib_TickType, AUTOMATIC) elapsedCount      = (McalLib_TickType)0U;
    VAR(Can_ControllerInstance, AUTOMATIC) canInstance = (uint8)0U;
    VAR(boolean, AUTOMATIC) timeout                    = FALSE;

    canInstance = controllerObj->canControllerConfig.CanControllerInstance;

    /* Put Can in Power Down mode */
    Can_AddClkStopRequestPriv(canInstance, TRUE);

    (void)McalLib_GetCounterValue(&startCount);
    /* Wait for Can to reach correct operational mode */
    do
    {
        (void)McalLib_GetElapsedValue(&startCount, &elapsedCount);

        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION <= elapsedCount)
        {
            timeout = TRUE;
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /*  Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while (CAN_CLOCK_STOP_ACK != Can_GetClkStopAckPriv(canInstance));
    /* TI_COVERAGE_GAP_STOP */

    if (FALSE == timeout)
    {
        /* Can is in sleep, report to CanIf */
        controllerObj->canState = CAN_CS_SLEEP;
        CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_SLEEP);
        controllerObj->canBusOffRecoveryStatus = FALSE;
        returnValue                            = E_OK;
        Can_CanIfIndication->sleepIndication   = TRUE;
    }
    /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
     * Hardware IP Errors */
    else
    {
        /*  Timeout */
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
        Can_CanIfIndication->sleepIndication = FALSE;
    }
    /* TI_COVERAGE_GAP_STOP */

    return returnValue;
}

/*
 *Design: MCAL-23032
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_HwUnitWakeupPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                     P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) canIfIndication)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue         = E_NOT_OK;
    VAR(McalLib_TickType, AUTOMATIC) startCount        = (McalLib_TickType)0U;
    VAR(McalLib_TickType, AUTOMATIC) elapsedCount      = (McalLib_TickType)0U;
    VAR(Can_ControllerInstance, AUTOMATIC) canInstance = (uint8)0U;
    VAR(boolean, AUTOMATIC) timeout                    = FALSE;

    canInstance = controllerObj->canControllerConfig.CanControllerInstance;
    /* Deactivate Local Power Down */
    Can_AddClkStopRequestPriv(canInstance, FALSE);
    (void)McalLib_GetCounterValue(&startCount);

    do
    {
        (void)McalLib_GetElapsedValue(&startCount, &elapsedCount);
        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION <= elapsedCount)
        {
            timeout = TRUE;
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /*  Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while (CAN_CLOCK_STOP_NO_ACK != Can_GetClkStopAckPriv(canInstance));
    /* TI_COVERAGE_GAP_STOP */

    if (FALSE == timeout)
    {
        /* Can is stopped, report to CanIf */
        controllerObj->canState = CAN_CS_STOPPED;
        CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
        returnValue                     = E_OK;
        canIfIndication->stopIndication = TRUE;
    }
    /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
     * Hardware IP Errors*/
    else
    {
        /*  Timeout */
        canIfIndication->stopIndication = FALSE;
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
    }
    /* TI_COVERAGE_GAP_STOP */

    return returnValue;
}

/*
 *Design: MCAL-24217
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_GetFreeTxMsgObjPriv(P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg,
                        P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController,
                        P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) msgObj)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue      = E_NOT_OK;
    VAR(uint32, AUTOMATIC) baseAddr                 = (uint32)0U;
    VAR(uint8, AUTOMATIC) buffNum                   = (uint8)0U;
    VAR(Can_TxFIFOStatusType, AUTOMATIC) fifoStatus = ((Can_TxFIFOStatusType){0U});

    baseAddr = mailboxCfg->CanControllerRef->CanControllerBaseAddress;

    if (CAN_BASIC == mailboxCfg->CanHandleType)
    {
        /* Get the status of Tx FIFO*/
        Can_GetTxFIFOStatusPriv(baseAddr, &fifoStatus);

        /* If Tx FIFO is full, new message can't be written to FIFO*/
        if (fifoStatus.fifoFull == TRUE)
        {
            returnValue = (Std_ReturnType)CAN_BUSY;
        }
        /* Maintaining the canTxStatus is necessary, as BRP may get cleared upon lost arbitration,
        error during transmission etc.*/
        else if ((((uint8)1U) == canController->canTxStatus[fifoStatus.putIdx]) &&
                 (FALSE == canController->canControllerConfig.CanConfigParam.CanDisableAutomaticRetransmission))
        {
            returnValue = (Std_ReturnType)CAN_BUSY;
        }
        else
        {
            *msgObj     = fifoStatus.putIdx;
            returnValue = E_OK;
        }
    }
    else
    {
        buffNum     = mailboxCfg->HwHandle;
        returnValue = Can_CheckPendingMsgPriv(canController, buffNum, baseAddr, msgObj);
    }
    return returnValue;
}

/*
 *Design: MCAL-24218
 */
FUNC(void, CAN_CODE)
Can_WriteTxMailboxPriv(P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg,
                       P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj, uint8 messageBox,
                       P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pduInfo)
{
    VAR(uint32, AUTOMATIC) baseAddr           = (uint32)0U;
    VAR(Can_TxBufElementType, AUTOMATIC) elem = {0U};

    baseAddr = mailboxCfg->CanControllerRef->CanControllerBaseAddress;

    if (CAN_MSG_TYPE_CLASSIC_CAN == ((pduInfo->id) & (CAN_MSG_TYPE_MASK)))
    {
        /* Classic CAN */
        elem.brs = ((boolean)0U);
        elem.fdf = ((boolean)0U);
    }
    else
    {
        /* CAN FD */
        elem.brs = ((boolean)1U);
        elem.fdf = ((boolean)1U);
    }

    if (CAN_ID_MIXED == mailboxCfg->CanIdType)
    {
        /* Mixed ID */
        if (CAN_MSG_ID_TYPE_EXT == (pduInfo->id & CAN_MSG_ID_TYPE_EXT))

        {
            /* Extended ID */
            elem.xtd = CAN_ID_XTD;
        }
        else
        {
            /* Standard ID */
            elem.xtd = CAN_ID_STD;
        }
    }
    else
    {
        elem.xtd = ((uint8)mailboxCfg->CanIdType);
    }

    if (((uint8)CAN_ID_XTD) == elem.xtd)
    {
        /* Extended ID */
        elem.id = pduInfo->id & CAN_XTD_MSGID_MASK;
    }
    else
    {
        /* Standard ID */
        elem.id = (pduInfo->id & CAN_STD_MSGID_MASK) << CAN_STD_MSGID_SHIFT;
    }

    Can_AddPdgValFindStdDtlen(pduInfo, &elem, mailboxCfg);

    Can_WriteMsgRamPriv(baseAddr, messageBox, &elem, pduInfo, mailboxCfg);

    Can_TxBufAddReqPriv(baseAddr, messageBox);
}

/*
 *Design: MCAL-24219
 */
FUNC(void, CAN_CODE)
Can_HwUnitTxDonePollingPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                            P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox)
{
    VAR(uint32, AUTOMATIC) baseAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC) buffNum   = (uint32)0U;
    VAR(uint8, AUTOMATIC) loopCnt   = (uint32)0U;
    VAR(uint32, AUTOMATIC) bitPos   = (uint32)0U;
    VAR(uint32, AUTOMATIC) txStatus = (uint32)0U;

    baseAddr = canController->canControllerConfig.CanControllerBaseAddress;

    if (CAN_BASIC == canMailbox->mailBoxConfig.CanHandleType)
    {
        loopCnt = canController->canFDMsgRamConfig.txBuffNum;
        buffNum = (canController->canFDMsgRamConfig.txBuffNum + canController->canFDMsgRamConfig.txFIFONum);

        /* Check if transmission is completed from FIFO*/
        Can_HwUnitTxConfirmationPriv(loopCnt, buffNum, canController, canMailbox);
    }
    else
    {
        loopCnt = (canMailbox->mailBoxConfig.HwHandle);
        bitPos  = ((uint32)1U << loopCnt);
        /* Get the transmission status of dedicated buffers */
        txStatus = Can_GetTxBufTransStatusPriv(baseAddr);
        /* Check if transmission is completed for respective dedicated buffer */
        if ((((uint8)1U) == canController->canTxStatus[loopCnt]) && (bitPos == (txStatus & bitPos)))
        {
            /* Clear the status as data is already sent. Status must be cleared before calling Tx confirmation */
            canController->canTxStatus[loopCnt] = ((uint8)0U);
            /* Call Tx Confirmation */
            CanIf_TxConfirmation(canController->canTxRxPduId[loopCnt]);
        }
    }
}

/*
 *Design: MCAL-24220
 */
FUNC(void, CAN_CODE)
Can_ReadRxMailboxPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                      P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, Can_HwHandleType htrh)
{
    VAR(Std_ReturnType, AUTOMATIC) retval                 = E_NOT_OK;
    VAR(Can_RxNewDataStatusType, AUTOMATIC) newDataStatus = {0U};
    VAR(uint32, AUTOMATIC) baseAddr                       = (uint32)0U;
    VAR(Can_RxFIFOStatusType, AUTOMATIC) fifoStatus       = ((Can_RxFIFOStatusType){0U});

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    if (CAN_BASIC == canMailbox->mailBoxConfig.CanHandleType)
    {
        /* Read the status of Fifo mapped to Hoh */
        Can_GetRxFIFOStatusPriv(baseAddr, &fifoStatus, canMailbox->mailBoxConfig.HwHandle);
        /* Read messages stored in Rx FIFO0/FIFO1 */
        Can_ReadRxFIFOPriv(controllerObj, canMailbox, htrh, &fifoStatus);
    }
    else
    {
        /* Scan NDAT status register to chcek if new message is received in respective dedicated buffers */
        Can_GetNewDataStatusPriv(baseAddr, &newDataStatus);
        retval = Can_BitPos(canMailbox->mailBoxConfig.HwHandle, &newDataStatus);
        if (retval == E_OK)
        {
            /* Read message from dedicated receive buffer */
            Can_ReadRxBuffPriv(controllerObj, canMailbox, htrh, &newDataStatus);
        }
    }
}

/*
 *Design: MCAL-23033
 */
FUNC(void, CAN_CODE)
Can_BusOffProcessPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj)
{
    VAR(uint32, AUTOMATIC) baseAddr = (uint32)0U;
    VAR(Can_ControllerOperationMode, AUTOMATIC) initStatus;
    VAR(Can_ErrorStateType, AUTOMATIC) protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr   = controllerObj->canControllerConfig.CanControllerBaseAddress;
    initStatus = Can_GetOpModePriv(baseAddr);
    protStatus = Can_GetProtocolStatusPriv(controllerObj);

    if ((CAN_ERRORSTATE_BUSOFF == protStatus) && (CAN_CONTROLLER_OPERATION_MODE_SW_INIT == initStatus))
    {
        /* Check if recovery has already started */
        if (TRUE != controllerObj->canBusOffRecoveryStatus)
        {
            Can_CancelPendingMsgPriv(baseAddr);
            /* BusOff Recovery sequence has not started */
            controllerObj->canState = CAN_CS_STOPPED;
            /*Call the bus off indicationtoCanIf function*/
            CanIf_ControllerBusOff(controllerObj->canControllerConfig.CanControllerId);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-23034
 */
FUNC(void, CAN_CODE)
Can_WakeupProcessPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj)
{
    VAR(Can_ClockStopAckMode, AUTOMATIC) csa;

    csa = Can_GetClkStopAckPriv(controllerObj->canControllerConfig.CanControllerInstance);

    if (CAN_CLOCK_STOP_ACK == csa)
    {
        /* Still Sleeping */
    }
    else
    {
        /* Call the Wakeup indication to CanIf function */
        if (CAN_CS_SLEEP == controllerObj->canState)
        {
            EcuM_CheckWakeup(controllerObj->canControllerConfig.CanWakeupSourceRef);
        }
        else
        {
            /* Do Nothing */
        }

        controllerObj->canState = CAN_CS_STOPPED;
    }
}

/*
 *Design: MCAL-23035
 */
FUNC(void, CAN_CODE)
Can_ModeProcessPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) indication)
{
    VAR(uint32, AUTOMATIC) baseAddr               = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC) protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    switch (controllerObj->canState)
    {
        case CAN_CS_STARTED:
            /* If BusOff recovery sequence has started, check if CAN controller is started.
             * If not restart CAN controller */
            if (TRUE == controllerObj->canBusOffRecoveryStatus)
            {
                /* Restart CAN controller */
                Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode)CAN_CONTROLLER_OPERATION_MODE_NORMAL);
                protStatus = Can_GetProtocolStatusPriv(controllerObj);

                if (CAN_ERRORSTATE_BUSOFF == protStatus)
                {
                    /* Busoff recovery has completed */
                    controllerObj->canBusOffRecoveryStatus = FALSE;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                /* Do Nothing */
            }
            if (FALSE == indication->startIndication)
            {
                CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STARTED);
                indication->startIndication = TRUE;
            }
            else
            {
                /* Do Nothing */
            }
            break;

        case CAN_CS_STOPPED:
            if ((CAN_CONTROLLER_OPERATION_MODE_SW_INIT == Can_GetOpModePriv(baseAddr)) &&
                (FALSE == indication->stopIndication))
            {
                CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
                indication->stopIndication = TRUE;
            }
            else
            {
                /* Do Nothing */
            }
            break;

        case CAN_CS_SLEEP:
            if ((CAN_CLOCK_STOP_ACK ==
                 Can_GetClkStopAckPriv(controllerObj->canControllerConfig.CanControllerInstance)) &&
                (FALSE == indication->sleepIndication))
            {
                CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_SLEEP);
                indication->sleepIndication = TRUE;
            }
            else
            {
                /* Do Nothing */
            }
            break;

        default:
            break;
    }
}

/*
 *Design: MCAL-24221, MCAL-22876, MCAL-22878, MCAL-22874, MCAL-22912, MCAL-22850, MCAL-22879
 */
FUNC(void, CAN_CODE)
Can_ProcessLine0ISR(Can_ControllerInstance canInstance, uint32 lineSelect)
{
    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController = NULL_PTR;
    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox         = NULL_PTR;
    VAR(uint32, AUTOMATIC) baseAddr                                      = (uint32)0U;
    VAR(uint32, AUTOMATIC) intrStatus                                    = (uint32)0U;
    VAR(uint32, AUTOMATIC) txStatus                                      = (uint32)0U;

    if (NULL_PTR != Can_DriverObjPtr)
    {
        canController = &(Can_DriverObjPtr->canController[Can_DriverObjPtr->controllerIDMap[canInstance]]);
        canMailbox    = &(Can_DriverObjPtr->canMailbox[0U]);
        baseAddr      = canController->canControllerConfig.CanControllerBaseAddress;
        /* Get Interrupt status */
        intrStatus = Can_GetIntrStatus(baseAddr);
        /* Take a snap of all required status registers to process further*/
        txStatus = Can_GetTxBufTransStatusPriv(baseAddr);
        /* Clear Interrupt status, next interrupt can register in MCAN_IR but can't be served until
        current execution is completed as nesting is not allowed */
        Can_ClearIntrStatusPriv(baseAddr, intrStatus & MCANSS_INTR_LINE_0_MASK, lineSelect);
        /* Check bus off*/
        Can_CheckBusOffPriv(intrStatus, baseAddr, canController);

        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
#if (CAN_CFG_DEM_BEU_ENABLE == STD_ON)
        /* Process Bit Error Uncorrecetd interrupt*/
        if (MCAN_IR_BEU_MASK == (intrStatus & MCAN_IR_BEU_MASK))
        {
            (void)Dem_SetEventStatus(CAN_E_SAFTEY_BEU_ERROR, DEM_EVENT_STATUS_PREFAILED);
        }
#endif
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        if ((MCAN_IR_ARA_MASK == (intrStatus & MCAN_IR_ARA_MASK)) ||
            (MCAN_IR_PED_MASK == (intrStatus & MCAN_IR_PED_MASK)) ||
            (MCAN_IR_PEA_MASK == (intrStatus & MCAN_IR_PEA_MASK)) ||
            (MCAN_IR_WDI_MASK == (intrStatus & MCAN_IR_WDI_MASK)) ||
            (MCAN_IR_EP_MASK == (intrStatus & MCAN_IR_EP_MASK)) ||
            (MCAN_IR_ELO_MASK == (intrStatus & MCAN_IR_ELO_MASK)) ||
            (MCAN_IR_MRAF_MASK == (intrStatus & MCAN_IR_MRAF_MASK)) ||
            (MCAN_IR_TOO_MASK == (intrStatus & MCAN_IR_TOO_MASK)))
        {
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
        }
#endif
        /* TI_COVERAGE_GAP_STOP */
        /* Process Transmission ocurred interrupt*/
        if (MCAN_IR_TC_MASK == (intrStatus & MCAN_IR_TC_MASK))
        {
            /* Check only Tx buffers */
            Can_CheckAllTxBuffers(txStatus, canController, canMailbox);
        }
    }
    else
    {
        /* Do Nothing */
    }
}

FUNC(void, CAN_CODE)
Can_ProcessLine1ISR(Can_ControllerInstance canInstance, uint32 lineSelect)
{
    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController = NULL_PTR;
    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox         = NULL_PTR;
    VAR(uint32, AUTOMATIC) baseAddr                                      = (uint32)0U;
    VAR(uint32, AUTOMATIC) intrStatus                                    = (uint32)0U;
    VAR(Can_HwHandleType, AUTOMATIC) hrh                                 = (Can_HwHandleType)0U;
    VAR(Can_HwHandleType, AUTOMATIC) loopIdx                             = (Can_HwHandleType)0U;
    VAR(uint8, AUTOMATIC) buffIdx                                        = (uint8)0U;
    VAR(Can_RxNewDataStatusType, AUTOMATIC) newDataStatus                = {0U};
    VAR(Std_ReturnType, AUTOMATIC) retval                                = E_NOT_OK;
    VAR(Can_RxFIFOStatusType, AUTOMATIC) fifo0Status                     = ((Can_RxFIFOStatusType){0U});
    VAR(Can_RxFIFOStatusType, AUTOMATIC) fifo1Status                     = ((Can_RxFIFOStatusType){0U});

    if (NULL_PTR != Can_DriverObjPtr)
    {
        canController = &(Can_DriverObjPtr->canController[Can_DriverObjPtr->controllerIDMap[canInstance]]);
        canMailbox    = &(Can_DriverObjPtr->canMailbox[0U]);
        baseAddr      = canController->canControllerConfig.CanControllerBaseAddress;
        /* Get Interrupt status */
        intrStatus = Can_GetIntrStatus(baseAddr);
        /* Take a snap of all required status registers to process further */
        Can_GetNewDataStatusPriv(baseAddr, &newDataStatus);
        Can_GetRxFIFOStatusPriv(baseAddr, &fifo0Status, (uint8)0U);
        Can_GetRxFIFOStatusPriv(baseAddr, &fifo1Status, (uint8)1U);
        /* Clear Interrupt status, next interrupt can register in MCAN_IR but can't be served until
        current execution is completed as nesting is not allowed */
        Can_ClearIntrStatusPriv(baseAddr, intrStatus & MCANSS_INTR_LINE_1_MASK, lineSelect);

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
        if (((uint32)MCAN_IR_RF0L_MASK == (intrStatus & (uint32)MCAN_IR_RF0L_MASK)) ||
            ((uint32)MCAN_IR_RF1L_MASK == (intrStatus & (uint32)MCAN_IR_RF1L_MASK)))
        {
            /* data lost error*/
            (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_PROCESSISR, CAN_E_DATALOST);
        }
#endif
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        /* Process FIFO0 and FIFO1 full interrupt*/
        if ((uint32)MCAN_IR_RF0F_MASK == (intrStatus & (uint32)MCAN_IR_RF0F_MASK) ||
            (uint32)MCAN_IR_RF1F_MASK == (intrStatus & (uint32)MCAN_IR_RF1F_MASK))
        {
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
        }
#endif
        /* Process dedicated Rx buffer interrupt */
        if ((uint32)MCAN_IR_RF0N_MASK == (intrStatus & (uint32)MCAN_IR_RF0N_MASK))
        {
            /* Identify the Hoh associated with Fifo 0 */
            loopIdx    = canController->canFDMsgRamConfig.canRxFifoToHohMapping[0];
            canMailbox = &(Can_DriverObjPtr->canMailbox[loopIdx]);
            if ((canController->canControllerConfig.CanTxProcessing == CAN_INTERRUPT) ||
                ((canController->canControllerConfig.CanTxProcessing == CAN_MIXED) &&
                 (canMailbox->mailBoxConfig.CanHardwareObjectUsesPolling == FALSE)))
            {
                Can_ReadRxFIFOPriv(canController, canMailbox, loopIdx, &fifo0Status);
            }
        }
        /* Process FIFO1 Rx interrupt*/
        if ((uint32)MCAN_IR_RF1N_MASK == (intrStatus & (uint32)MCAN_IR_RF1N_MASK))
        {
            /* Identify the Hoh associated with Fifo 1 */
            loopIdx    = canController->canFDMsgRamConfig.canRxFifoToHohMapping[1];
            canMailbox = &(Can_DriverObjPtr->canMailbox[loopIdx]);
            if ((canController->canControllerConfig.CanTxProcessing == CAN_INTERRUPT) ||
                ((canController->canControllerConfig.CanTxProcessing == CAN_MIXED) &&
                 (canMailbox->mailBoxConfig.CanHardwareObjectUsesPolling == FALSE)))
            {
                Can_ReadRxFIFOPriv(canController, canMailbox, loopIdx, &fifo1Status);
            }
        }
        /* Process FIFO0 Rx interrupt*/
        if ((uint32)MCAN_IR_DRX_MASK == (intrStatus & (uint32)MCAN_IR_DRX_MASK))
        {
            for (buffIdx = 0; buffIdx < (uint8)KMAX_RX_MB_PER_CONTROLLER; buffIdx++)
            {
                retval = Can_BitPos(buffIdx, &newDataStatus);
                if ((retval == E_OK) && (buffIdx < (uint32)canController->canFDMsgRamConfig.rxBuffNum))
                {
                    /* Identify Hoh associated with dedicated buffer*/
                    hrh        = canController->canFDMsgRamConfig.canRxBufToHohMapping[buffIdx];
                    canMailbox = &(Can_DriverObjPtr->canMailbox[hrh]);
                    /* Chcek if Hoh is valid */
                    if (CAN_RECEIVE == canMailbox->mailBoxConfig.CanObjectType)
                    {
                        /* Chcek if Hoh is expected to be read in interrupt */
                        if ((canController->canControllerConfig.CanTxProcessing == CAN_INTERRUPT) ||
                            ((canController->canControllerConfig.CanTxProcessing == CAN_MIXED) &&
                             (canMailbox->mailBoxConfig.CanHardwareObjectUsesPolling == FALSE)))
                        {
                            /* Read dedicated message buffer */
                            Can_ReadRxBuffPriv(canController, canMailbox, hrh, &newDataStatus);
                        }
                    }
                }
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
}

FUNC(void, CAN_CODE) Can_ProcessWakeUpISR(Can_ControllerInstance instance)
{
    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController = NULL_PTR;

    if (NULL_PTR != Can_DriverObjPtr)
    {
        canController = &(Can_DriverObjPtr->canController[Can_DriverObjPtr->controllerIDMap[instance]]);

        if (canController->canControllerConfig.CanWakeupProcessing == (Can_ProcessingType)CAN_INTERRUPT)
        {
            Can_ProcessWakeUpPrv(instance, canController);
        }
    }
}

FUNC(void, CAN_CODE)
Can_ProcessWakeUpPrv(Can_ControllerInstance instance,
                     P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController)
{
    VAR(uint32, AUTOMATIC) wakeStatus  = (uint32)0U;
    VAR(uint32, AUTOMATIC) clearStatus = (uint32)0U;
    wakeStatus                         = (MCAN_WAKEUP_STATUS << (uint32)instance);
    clearStatus                        = (uint32)(MCAN_WAKEUP_STATUS << (uint32)instance);

    if (wakeStatus == (MCAL_LIB_REG_READ32(CPUSYS_BASE + SYSCTL_O_MCANWAKESTATUS) & wakeStatus))
    {
        /* Call the EcuM function to check the wakeup events */
        EcuM_CheckWakeup(canController->canControllerConfig.CanWakeupSourceRef);
        /* Clear the wake status */
        MCAL_LIB_REG_WRITE32(CPUSYS_BASE + SYSCTL_O_MCANWAKESTATUSCLR, clearStatus);
        /* Clear the wake status if not cleared*/
        if (MCAN_WAKEUP != (MCAL_LIB_REG_READ32(CPUSYS_BASE + SYSCTL_O_MCANWAKESTATUS) & wakeStatus))
        {
            MCAL_LIB_REG_WRITE32(CPUSYS_BASE + SYSCTL_O_MCANWAKESTATUSCLR, clearStatus);
        }
    }
    else
    {
#if (CAN_CFG_DEM_ENABLE == STD_ON)

        (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
    }
}

/*
 *Design: MCAL-24227
 */
FUNC(void, CAN_CODE)
Can_MsgRamConfigPriv(uint32 baseAddr, P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) canFDMsgRamConfig)
{
    VAR(uint32, AUTOMATIC) startAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC) loopCnt    = (uint32)0U;
    VAR(uint8, AUTOMATIC) txMbNum    = (uint32)0U;

    txMbNum = (canFDMsgRamConfig->txBuffNum + canFDMsgRamConfig->txFIFONum);

    if (((uint8)MCAN_TX_BUFFER_MAX_NUM >= txMbNum) &&
        (((uint8)MCAN_RX_BUFFER_MAX_NUM) >= canFDMsgRamConfig->rxBuffNum) &&
        (((uint8)MCAN_RX_FIFO_0_MAX_NUM) >= canFDMsgRamConfig->configParams.rxFIFO0size) &&
        (((uint8)MCAN_RX_FIFO_1_MAX_NUM) >= canFDMsgRamConfig->configParams.rxFIFO1size))
    {
        /* Calculate Start Address for Message RAM sections */
        /* Start address of standard filters*/
        if ((uint8)0U < canFDMsgRamConfig->stdFilterNum)
        {
            canFDMsgRamConfig->configParams.flssa = ((uint32)0U);
            startAddr += (uint32)(((uint32)canFDMsgRamConfig->stdFilterNum) * (uint32)MCAN_MSG_RAM_STD_ELEM_SIZE * 4U);
        }

        /* Start address of extended filters*/
        if ((uint8)0U < canFDMsgRamConfig->extFilterNum)
        {
            canFDMsgRamConfig->configParams.flesa = startAddr;
            startAddr += (uint32)(((uint32)canFDMsgRamConfig->extFilterNum) * (uint32)MCAN_MSG_RAM_EXT_ELEM_SIZE * 4U);
        }

        /* Start address of Rx FIFO0 */
        if ((uint8)0U < canFDMsgRamConfig->configParams.rxFIFO0size)
        {
            canFDMsgRamConfig->configParams.rxFIFO0startAddr = startAddr;
            startAddr += (uint32)(((uint32)canFDMsgRamConfig->configParams.rxFIFO0size) *
                                  (uint32)canFDMsgRamConfig->configParams.bufferElemSize * 4U);
        }

        /* Start address of Rx FIFO1 */
        if ((uint8)0U < canFDMsgRamConfig->configParams.rxFIFO1size)
        {
            canFDMsgRamConfig->configParams.rxFIFO1startAddr = startAddr;
            startAddr += (uint32)(((uint32)canFDMsgRamConfig->configParams.rxFIFO1size) *
                                  (uint32)canFDMsgRamConfig->configParams.bufferElemSize * 4U);
        }

        /* Start address of Rx Buffers */
        if ((uint8)0U < canFDMsgRamConfig->rxBuffNum)
        {
            canFDMsgRamConfig->configParams.rxBufStartAddr  = startAddr;
            startAddr                                      += (uint32)(((uint32)canFDMsgRamConfig->rxBuffNum) *
                                  (uint32)canFDMsgRamConfig->configParams.bufferElemSize * 4U);
        }

        /* Start address of Tx Buffers */
        if ((uint8)0U < (canFDMsgRamConfig->txBuffNum + canFDMsgRamConfig->configParams.txFIFOSize))
        {
            canFDMsgRamConfig->configParams.txStartAddr = startAddr;
        }

        /* Configure Message RAM */
        Can_HwMsgRamConfigPriv(baseAddr, &canFDMsgRamConfig->configParams);

        /* Configure Standard ID Filters */
        for (loopCnt = ((uint8)0U); loopCnt < canFDMsgRamConfig->stdFilterNum; loopCnt++)
        {
            Can_AddStdMsgIDFilterPriv(baseAddr, loopCnt, &canFDMsgRamConfig->stdMsgIDFilterList[loopCnt]);
        }

        /* Configure Extended ID Filters */
        for (loopCnt = ((uint8)0U); loopCnt < canFDMsgRamConfig->extFilterNum; loopCnt++)
        {
            Can_AddExtMsgIDFilterPriv(baseAddr, loopCnt, &canFDMsgRamConfig->extMsgIDFilterList[loopCnt]);
        }
    }
}

/*
 *Design: MCAL-24238
 */
FUNC(void, CAN_CODE)
Can_ReadMsgRamPriv(uint32 baseAddr, Can_MemType memType, uint8 bufNum,
                   P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem)
{
    VAR(uint32, AUTOMATIC) startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemSize  = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemAddr  = (uint32)0U;
    VAR(uint8, AUTOMATIC) idx        = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal    = (uint32)0U;
    VAR(uint32, AUTOMATIC) loopCnt   = (uint32)0U;

    if (((Can_MemType)CAN_MEM_TYPE_BUF) == memType)
    {
        /* To read RX dedicated buffer */
        startAddr = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXBC), MCAN_RXBC_RBSA);
        elemSize  = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXESC), MCAN_RXESC_RBDS);
        idx       = bufNum;
    }
    else if (((Can_MemType)CAN_MEM_TYPE_FIFO0) == memType)
    {
        /* To read RX FIFO0*/
        startAddr = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF0C), MCAN_RXF0C_F0SA);
        elemSize  = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXESC), MCAN_RXESC_F0DS);
        idx       = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF0S), MCAN_RXF0S_F0GI);
    }
    else
    {
        /* To read RX FIFO1*/
        startAddr = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF1C), MCAN_RXF1C_F1SA);
        elemSize  = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXESC), MCAN_RXESC_F1DS);
        idx       = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF1S), MCAN_RXF1S_F1GI);
    }

    startAddr  = (uint32)(startAddr << ((uint32)2U));
    elemSize   = ((uint32)Can_ObjSize[elemSize]);
    elemSize  *= ((uint32)4U);
    elemAddr   = startAddr + (elemSize * idx);

    regVal    = MCAL_LIB_REG_READ32(baseAddr + elemAddr);
    elem->id  = (uint32)MCAL_LIB_REG_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_ID);
    elem->xtd = (uint8)MCAL_LIB_REG_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_XTD);

    elemAddr         += ((uint32)4U);
    regVal            = MCAL_LIB_REG_READ32(baseAddr + elemAddr);
    elem->brs         = (boolean)MCAL_LIB_REG_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_BRS);
    elem->dataLength  = (uint32)MCAL_LIB_REG_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_DLC);
    elem->fdf         = (boolean)MCAL_LIB_REG_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_FDF);

    elemAddr += ((uint32)4U);
    loopCnt   = ((uint32)0U);
    /* Reading words from message RAM and forming payload bytes out of it */
    while ((4U <= (((uint32)Can_DataSize[elem->dataLength]) - loopCnt)) &&
           (0U != (((uint32)Can_DataSize[elem->dataLength]) - loopCnt)))
    {
        if ((loopCnt + (uint8)3U) < (uint8)64U)
        {
            regVal                                = MCAL_LIB_REG_READ32(baseAddr + elemAddr);
            elem->data[(loopCnt + ((uint32)0U))]  = (uint8)(regVal & ((uint32)0x000000FFU));
            elem->data[(loopCnt + ((uint32)1U))]  = (uint8)((regVal & ((uint32)0x0000FF00U)) >> 8U);
            elem->data[(loopCnt + ((uint32)2U))]  = (uint8)((regVal & ((uint32)0x00FF0000U)) >> 16U);
            elem->data[(loopCnt + ((uint32)3U))]  = (uint8)((regVal & ((uint32)0xFF000000U)) >> 24U);
            elemAddr                             += ((uint32)4U);
            loopCnt                              += ((uint32)4U);
        }
    }

    /* Reading remaining bytes from message RAM */
    if (0U < (((uint32)Can_DataSize[elem->dataLength]) - loopCnt))
    {
        regVal                               = MCAL_LIB_REG_READ32(baseAddr + elemAddr);
        elem->data[(loopCnt + ((uint32)0U))] = (uint8)(regVal & ((uint32)0x000000FFU));
        elem->data[(loopCnt + ((uint32)1U))] = (uint8)((regVal & ((uint32)0x0000FF00U)) >> 8U);
        elem->data[(loopCnt + ((uint32)2U))] = (uint8)((regVal & ((uint32)0x00FF0000U)) >> 16U);
    }
    else
    {
        /* Do Nothing */
    }
}

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)

/*
 *Design: MCAL-23036
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_CheckControllerConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) returnStatus = E_OK;
    VAR(uint32, AUTOMATIC) loopCnt              = (uint32)0U;

    for (loopCnt = 0U; loopCnt < KMAX_CONTROLLER; loopCnt++)
    {
        if ((NULL_PTR == ConfigPtr->CanControllerList[loopCnt]) ||
            (NULL_PTR == ConfigPtr->CanControllerList[loopCnt]->CanControllerDefaultBaudrate) ||
            (CAN_INVALID_BASE_ADDR == ConfigPtr->CanControllerList[loopCnt]->CanControllerBaseAddress))
        {
            returnStatus = (Std_ReturnType)E_NOT_OK;
            break;
        }
        else
        {
            returnStatus = Can_CheckBaudRateConfigList(ConfigPtr, loopCnt);
        }
    }

    return returnStatus;
}
#endif

/*
 *Design: MCAL-24228
 */
FUNC(void, CAN_CODE)
Can_HwMsgRamConfigPriv(uint32 baseAddr, P2CONST(Can_MsgRAMConfigParams, AUTOMATIC, CAN_CONST) msgRAMConfigParams)
{
    VAR(uint8, AUTOMATIC) elemNum      = 0U;
    VAR(uint32, AUTOMATIC) elementSize = 0U;
    /* Buffer data size for tx and rx elements */
    if (msgRAMConfigParams->bufferElemSize == MCAN_MSG_RAM_TX_RX_FD_ELEM_SIZE)
    {
        elementSize = CAN_ELEM_SIZE_64BYTES;
    }
    else
    {
        elementSize = CAN_ELEM_SIZE_8BYTES;
    }

    /* Configure Message Filters section */
    if (((uint8)0U) != msgRAMConfigParams->lss)
    {
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_SIDFC, MCAN_SIDFC_FLSSA, (msgRAMConfigParams->flssa >> ((uint32)2U)));
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_SIDFC, MCAN_SIDFC_LSS, msgRAMConfigParams->lss);
    }

    if (((uint8)0U) != msgRAMConfigParams->lse)
    {
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_XIDFC, MCAN_XIDFC_FLESA, (msgRAMConfigParams->flesa >> ((uint32)2U)));
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_XIDFC, MCAN_XIDFC_LSE, msgRAMConfigParams->lse);
    }

    /* Configure Rx FIFO 0 section */
    if (((uint8)0U) != msgRAMConfigParams->rxFIFO0size)
    {
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXF0C, MCAN_RXF0C_F0SA,
                                (msgRAMConfigParams->rxFIFO0startAddr >> ((uint32)2U)));
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXF0C, MCAN_RXF0C_F0S, msgRAMConfigParams->rxFIFO0size);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXF0C, MCAN_RXF0C_F0WM, msgRAMConfigParams->rxFIFO0waterMark);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXF0C, MCAN_RXF0C_F0OM, msgRAMConfigParams->rxFIFO0OpMode);
        /* Configure Rx FIFO0 elements size */
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXESC, MCAN_RXESC_F0DS, elementSize);
    }

    /* Configure Rx FIFO 1 section */
    if (((uint8)0U) != msgRAMConfigParams->rxFIFO1size)
    {
        MCAL_LIB_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C, MCAN_RXF1C_F1SA,
                                (msgRAMConfigParams->rxFIFO1startAddr >> ((uint32)2U)));
        MCAL_LIB_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C, MCAN_RXF1C_F1S, msgRAMConfigParams->rxFIFO1size);
        MCAL_LIB_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C, MCAN_RXF1C_F1WM, msgRAMConfigParams->rxFIFO1waterMark);
        MCAL_LIB_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C, MCAN_RXF1C_F1OM, msgRAMConfigParams->rxFIFO1OpMode);
        /* Configure Rx FIFO1 elements size */
        MCAL_LIB_REG_MF_WRITE32((baseAddr) + MCAN_RXESC, MCAN_RXESC_F1DS, elementSize);
    }

    /* Configure Rx Buffer Start Address */
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXBC, MCAN_RXBC_RBSA, (msgRAMConfigParams->rxBufStartAddr >> ((uint32)2U)));
    /* Configure Rx Buffer elements size */
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_RXESC, MCAN_RXESC_RBDS, elementSize);

    /* Configure Tx Buffer and FIFO/Q section */
    elemNum = msgRAMConfigParams->txBufNum + msgRAMConfigParams->txFIFOSize;

    if ((MCAN_TX_MB_MAX_NUM >= elemNum) &&
        ((((uint8)0U) != msgRAMConfigParams->txBufNum) || (((uint8)0U) != msgRAMConfigParams->txFIFOSize)))
    {
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TXBC, MCAN_TXBC_TBSA,
                                (msgRAMConfigParams->txStartAddr >> ((uint32)2U)));
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TXBC, MCAN_TXBC_NDTB, msgRAMConfigParams->txBufNum);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TXBC, MCAN_TXBC_TFQS, msgRAMConfigParams->txFIFOSize);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TXBC, MCAN_TXBC_TFQM, msgRAMConfigParams->txBufMode);
        /* Configure Tx Buffer/FIFO0/FIFO1 elements size */
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TXESC, MCAN_TXESC_TBDS, elementSize);
    }
}

/*
 *Design: MCAL-23055
 */
FUNC(void, CAN_CODE)
Can_WriteMsgRamPriv(uint32 baseAddr, uint8 bufNum, P2CONST(Can_TxBufElementType, AUTOMATIC, CAN_CONST) elem,
                    P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pdu_Info,
                    P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailBoxConfig)
{
    VAR(uint32, AUTOMATIC) startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemAddr  = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemSize  = (uint32)0U;
    VAR(uint8, AUTOMATIC) idx        = (uint32)0U;
    VAR(uint8, AUTOMATIC) loopCnt    = (uint8)0U;
    VAR(uint32, AUTOMATIC) regVal    = (uint32)0U;

    if (CAN_MEM_TYPE_BUF == elem->memType)
    {
        idx = bufNum;
    }
    else
    {
        idx = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_TXFQS), MCAN_TXFQS_TFQPI);
    }

    startAddr = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_TXBC), MCAN_TXBC_TBSA);
    elemSize  = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_TXESC), MCAN_TXESC_TBDS);

    startAddr  = (uint32)(startAddr << ((uint32)2U));
    elemSize   = ((uint32)Can_ObjSize[elemSize]);
    elemSize  *= ((uint32)4U);
    elemAddr   = startAddr + (elemSize * idx);

    regVal  = ((uint32)0U);
    regVal |= ((((uint32)elem->id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT)) |
               (((uint32)elem->xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT)));
    MCAL_LIB_REG_WRITE32((baseAddr + elemAddr), regVal);
    elemAddr += ((uint32)4U);

    regVal  = ((uint32)0U);
    regVal |= ((((uint32)elem->dataLength << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT)) |
               (((uint32)elem->brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT)) |
               (((uint32)elem->fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT)));
    MCAL_LIB_REG_WRITE32((baseAddr + elemAddr), regVal);
    elemAddr += ((uint32)4U);

    /* Framing words out of the payload bytes and writing it to message RAM */
    while (Can_DataSize[elem->dataLength] > loopCnt)
    {
        regVal = ((uint32)0U);
        if ((loopCnt + (uint8)3U) < pdu_Info->length)
        {
            regVal |=
                (((uint32)pdu_Info->sdu[loopCnt]) | ((uint32)pdu_Info->sdu[(loopCnt + ((uint8)1U))] << ((uint32)8U)) |
                 ((uint32)pdu_Info->sdu[(loopCnt + ((uint8)2U))] << ((uint32)16U)) |
                 ((uint32)pdu_Info->sdu[(loopCnt + ((uint8)3U))] << ((uint32)24U)));
            MCAL_LIB_REG_WRITE32((baseAddr + elemAddr), regVal);
            elemAddr += ((uint32)4U);
            Can_Loopcountincreaseby4Prv(&loopCnt);
        }
        else if (loopCnt < pdu_Info->length)
        {
            regVal = Can_CopyodddataPrv(&loopCnt, pdu_Info, mailBoxConfig->CanFdPaddingValue);
            MCAL_LIB_REG_WRITE32((baseAddr + elemAddr), regVal);
            elemAddr += ((uint32)4U);
        }
        else
        {
            regVal |= (((uint32)mailBoxConfig->CanFdPaddingValue) |
                       ((uint32)mailBoxConfig->CanFdPaddingValue << ((uint32)8U)) |
                       ((uint32)mailBoxConfig->CanFdPaddingValue << ((uint32)16U)) |
                       ((uint32)mailBoxConfig->CanFdPaddingValue << ((uint32)24U)));
            MCAL_LIB_REG_WRITE32((baseAddr + elemAddr), regVal);
            elemAddr += ((uint32)4U);
            Can_Loopcountincreaseby4Prv(&loopCnt);
        }
    }
}

static FUNC(void, CAN_CODE) Can_Loopcountincreaseby4Prv(P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) loopCnt)
{
    /* TI_COVERAGE_GAP_START [Branch Coverage] This cannot be covered. Added to resolve MISRA */
    if ((*loopCnt + ((uint8)4U)) < MAX_UINT8)
    {
        *loopCnt += ((uint8)4U);
    }
    /* TI_COVERAGE_GAP_STOP */
}

static FUNC(uint32, CAN_CODE)
    Can_CopyodddataPrv(P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) loopCnt,
                       P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pdu_Info, uint8 Paddingvalue)
{
    VAR(uint32, AUTOMATIC) innerLoopCount = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal         = (uint32)0U;
    for (innerLoopCount = (uint32)0U; innerLoopCount < (uint32)4U; innerLoopCount++)
    {
        if (*loopCnt < pdu_Info->length)
        {
            regVal |= (((uint32)pdu_Info->sdu[*loopCnt]) << ((uint32)innerLoopCount * 8U));
        }
        else
        {
            regVal |= ((uint32)Paddingvalue << ((uint32)innerLoopCount * 8U));
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] This cannot be covered. Added to resolve MISRA */
        if (*loopCnt < MAX_UINT8)
        {
            *loopCnt = *loopCnt + (uint8)1U;
        }
        /* TI_COVERAGE_GAP_STOP */
    }
    return regVal;
}

/*
 *Design: MCAL-24240
 */
FUNC(void, CAN_CODE) Can_WriteRxFIFOAckPriv(uint32 baseAddr, uint8 idx, uint8 hwHandle)
{
    VAR(uint8, AUTOMATIC) size = (uint32)0U;

    if (hwHandle == (uint8)0U)
    {
        size = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF0C), MCAN_RXF0C_F0S);
        if (size >= idx)
        {
            MCAL_LIB_REG_MF_WRITE32((baseAddr + MCAN_RXF0A), MCAN_RXF0A_F0AI, idx);
        }
    }
    else if (hwHandle == (uint8)1U)
    {
        size = MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_RXF1C), MCAN_RXF1C_F1S);
        if (size >= idx)
        {
            MCAL_LIB_REG_MF_WRITE32((baseAddr + MCAN_RXF1A), MCAN_RXF1A_F1AI, idx);
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-28416
 */
FUNC(void, CAN_CODE)
Can_PollingCheck(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj, uint8 Controller)
{
    if ((CAN_POLLING != drvObj->canController[Controller].canControllerConfig.CanRxProcessing) ||
        (CAN_POLLING != drvObj->canController[Controller].canControllerConfig.CanTxProcessing) ||
        (CAN_POLLING != drvObj->canController[Controller].canControllerConfig.CanBusoffProcessing) ||
        (CAN_POLLING != drvObj->canController[Controller].canControllerConfig.CanWakeupProcessing))
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        if ((uint8)0U == drvObj->canController[Controller].canInterruptCounter)
        {
            Can_DisableInterruptsPriv(&drvObj->canController[Controller].canControllerConfig);
        }
        else
        {
            /* Do Nothing */
        }
        drvObj->canController[Controller].canInterruptCounter++;
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-28417
 */
FUNC(void, CAN_CODE)
Can_InterruptCounterCheckPriv(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj, uint8 Controller)
{
    if ((uint8)0U < drvObj->canController[Controller].canInterruptCounter)
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        drvObj->canController[Controller].canInterruptCounter--;

        if ((uint8)0U == drvObj->canController[Controller].canInterruptCounter)
        {
            Can_EnableInterruptsPriv(&drvObj->canController[Controller].canControllerConfig);
        }
        else
        {
            /* Do Nothing */
        }
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-28426
 */
FUNC(void, CAN_CODE)
Can_HwUnitTxConfirmationPriv(uint8 loopCnt, uint8 buffNum,
                             P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                             P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox)
{
    VAR(uint32, AUTOMATIC) bitPos   = (uint32)0U;
    VAR(uint32, AUTOMATIC) txStatus = (uint32)0U;
    VAR(uint32, AUTOMATIC) baseAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC) loop_Cnt  = loopCnt;

    baseAddr = canController->canControllerConfig.CanControllerBaseAddress;

    for (; loop_Cnt < buffNum; loop_Cnt++)
    {
        bitPos = ((uint32)1U << loop_Cnt);
        /* Get the status of transmission occurred bit*/
        txStatus = Can_GetTxBufTransStatusPriv(baseAddr);

        if ((((uint8)1U) == canController->canTxStatus[loop_Cnt]) && (bitPos == (txStatus & bitPos)))
        {
            /* Clear the status as data is already sent */
            canController->canTxStatus[loop_Cnt] = ((uint8)0U);
            /* Call Tx Confirmation */
            CanIf_TxConfirmation(canController->canTxRxPduId[loop_Cnt]);
        }
    }
}

/*
 *Design: MCAL-28433
 */
FUNC(void, CAN_CODE)
Can_CheckTxDelayCompEnablePriv(uint32 baseAddress, P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_CONST) baudConfig)
{
    if (((boolean)TRUE) == baudConfig->BaudFdRateConfig.TxDelayCompEnable)
    {
        if (((CAN_TDCR_TDCF_MAX) >= baudConfig->BaudFdRateConfig.TxDelayCompFilter) &&
            ((CAN_TDCR_TDCO_MAX) >= baudConfig->BaudFdRateConfig.CanControllerTrcvDelayCompensationOffset))
        {
            /* Configure Transceiver Delay Compensation */
            MCAL_LIB_REG_MF_WRITE32(baseAddress + MCAN_TDCR, MCAN_TDCR_TDCF,
                                    baudConfig->BaudFdRateConfig.TxDelayCompFilter);

            MCAL_LIB_REG_MF_WRITE32(baseAddress + MCAN_TDCR, MCAN_TDCR_TDCO,
                                    baudConfig->BaudFdRateConfig.CanControllerTrcvDelayCompensationOffset);

            MCAL_LIB_REG_MF_WRITE32(baseAddress + MCAN_DBTP, MCAN_DBTP_TDC,
                                    baudConfig->BaudFdRateConfig.TxDelayCompEnable);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
}

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/*
 *Design: MCAL-28435
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_ValidateIcomConfigPriv(uint16 loopCnt, P2CONST(Can_IcomConfigType, AUTOMATIC, CAN_CONST) icomConfigPtr,
                           uint64 sduData, uint16 rxMessageConfigId)
{
    VAR(Std_ReturnType, AUTOMATIC) returnVal = E_NOT_OK;
    P2CONST(Can_IcomRxMessageType, AUTOMATIC, CAN_CONST) RxMessage;

    if (loopCnt < icomConfigPtr->RxMessageCount)
    {
        RxMessage = &icomConfigPtr->CanIcomRxMessage[rxMessageConfigId];
        if (((uint16)0U) == RxMessage->SignalCount)
        {
            returnVal = E_OK;
        }
        else
        {
            returnVal = Can_IcomCheckRxmsgPriv(RxMessage, sduData);
        }
    }

    return returnVal;
}

FUNC(Std_ReturnType, CAN_CODE)
Can_IcomCheckRxmsgPriv(P2CONST(Can_IcomRxMessageType, AUTOMATIC, CAN_CONST) RxMessage, uint64 sduData)
{
    VAR(uint16, AUTOMATIC) loopCount = (uint16)0U;
    P2CONST(Can_IcomSignalConfigType, AUTOMATIC, CAN_CONST) signalData;
    VAR(Std_ReturnType, AUTOMATIC) returnVal = E_NOT_OK;
    for (loopCount = ((uint16)0U); loopCount < RxMessage->SignalCount; loopCount++)
    {
        signalData = &RxMessage->CanIcomRxMessageSignalConfig[loopCount];
        returnVal  = Can_IcomSignalOp(signalData, sduData);
        if (returnVal == E_OK)
        {
            break;
        }
    }
    return returnVal;
}

#endif

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/*
 *Design: MCAL-28440
 */
FUNC(Std_ReturnType, CAN_CODE)
Can_IcomSignalOp(P2CONST(Can_IcomSignalConfigType, AUTOMATIC, CAN_CONST) signalData, uint64 sduData)
{
    VAR(Std_ReturnType, AUTOMATIC) returnVal = E_NOT_OK;
    /* TI_COVERAGE_GAP_START [Branch/MC-DC] All the Conditions are verified. This is False Positive
     */
    if (((signalData->CanIcomSignalOperation == AND) &&
         (signalData->CanIcomSignalValue == ((uint64)sduData & signalData->CanIcomSignalMask))) ||
        ((signalData->CanIcomSignalOperation == EQUAL) && (sduData == (uint64)signalData->CanIcomSignalValue)) ||
        ((signalData->CanIcomSignalOperation == GREATER) && ((uint64)sduData > signalData->CanIcomSignalValue)) ||
        ((signalData->CanIcomSignalOperation == SMALLER) && ((uint64)sduData < signalData->CanIcomSignalValue)) ||
        ((signalData->CanIcomSignalOperation == XOR) &&
         (signalData->CanIcomSignalValue == ((uint64)sduData ^ signalData->CanIcomSignalMask))))
    {
        /* TI_COVERAGE_GAP_STOP */
        returnVal = E_OK;
    }

    else
    {
        /* Do Nothing */;
    }

    return returnVal;
}
#endif

/*
 *Design: MCAL-28441
 */
FUNC(void, CAN_CODE)
Can_CanSetBaudRatePriv(uint32 baseAddr, P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_CONST) baudConfig)
{
    VAR(uint16, AUTOMATIC) brp = (uint16)0U;
    VAR(uint8, AUTOMATIC) seg1 = (uint8)0U;
    VAR(uint8, AUTOMATIC) seg2 = (uint8)0U;
    VAR(uint8, AUTOMATIC) sjw  = (uint8)0U;

    if (baudConfig->BaudFdRateConfig.BrpValue > 0U)
    {
        brp = baudConfig->BaudFdRateConfig.BrpValue - (uint16)1U;
    }
    else
    {
        /* Do nothing */
    }

    if ((((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg + baudConfig->BaudFdRateConfig.CanControllerSeg1)) >
         0U) &&
        (((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg + baudConfig->BaudFdRateConfig.CanControllerSeg1)) <
         255U))
    {
        seg1 = ((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg +
                        baudConfig->BaudFdRateConfig.CanControllerSeg1)) -
               ((uint8)1U);
    }
    else
    {
        /* Do nothing */
    }

    if (baudConfig->BaudFdRateConfig.CanControllerSeg2 > 0U)
    {
        seg2 = baudConfig->BaudFdRateConfig.CanControllerSeg2 - (uint8)1U;
    }
    else
    {
        /* Do nothing */
    }

    if (baudConfig->BaudFdRateConfig.CanControllerSyncJumpWidth > 0U)
    {
        sjw = baudConfig->BaudFdRateConfig.CanControllerSyncJumpWidth - (uint8)1U;
    }
    else
    {
        /* Do nothing */
    }

    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_DBTP, MCAN_DBTP_DSJW, sjw);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_DBTP, MCAN_DBTP_DTSEG2, seg2);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_DBTP, MCAN_DBTP_DTSEG1, seg1);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_DBTP, MCAN_DBTP_DBRP, brp);
}

/*
 *Design: MCAL-28442
 */
FUNC(void, CAN_CODE)
Can_AddPdgValFindStdDtlen(P2CONST(Can_PduType, AUTOMATIC, CAN_CONST) pduInfo,
                          P2VAR(Can_TxBufElementType, AUTOMATIC, CAN_APPL_DATA) elemPtr,
                          P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg)
{
    VAR(uint8, AUTOMATIC) loopCnt = (uint8)0U;

    /* Find standard data length */
    for (loopCnt = ((uint8)0U); loopCnt < ((uint8)16U); loopCnt++)
    {
        if (pduInfo->length <= Can_DataSize[loopCnt])
        {
            elemPtr->dataLength = ((uint32)loopCnt);
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }

    if (CAN_BASIC == mailboxCfg->CanHandleType)
    {
        elemPtr->memType = CAN_MEM_TYPE_FIFO0;
    }
    else
    {
        elemPtr->memType = CAN_MEM_TYPE_BUF;
    }
}

/*
 *Design: MCAL-28443
 */
FUNC(void, CAN_CODE)
Can_CallRxIndication(CONST(boolean, AUTOMATIC) RxIndicationStatus, CONST(Can_HwHandleType, AUTOMATIC) htrh,
                     CONST(uint32, AUTOMATIC) canIdentifier, CONST(uint8, AUTOMATIC) canDataLength,
                     P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj)
{
    VAR(boolean, AUTOMATIC) lpduCalloutStatus = (boolean)TRUE;

    if (RxIndicationStatus == TRUE)
    {
#ifdef CAN_LPDU_RECEIVE_CALLOUT_FUNCTION
        lpduCalloutStatus =
            CAN_LPDU_RECEIVE_CALLOUT_FUNCTION(htrh, canIdentifier, canDataLength, controllerObj->canSduPtr);
#endif

        if (lpduCalloutStatus == TRUE)
        {
            /* Call Receive Indication */
            CanIf_RxIndication(&controllerObj->mailboxCfg, &controllerObj->pduInfo);
        }
    }
}

/*
 *Design: MCAL-29471
 */
FUNC(void, CAN_CODE)
Can_PeriodicReadbackPrv(uint8 Controller,
                        P2VAR(Can_PeriodicReadBackDataType, AUTOMATIC, CAN_APPL_DATA) ReadBackRegisterdata)
{
    VAR(uint32, AUTOMATIC) baseAddr;
    baseAddr = (uint32)Can_DriverObjPtr->canController[Controller].canControllerConfig.CanControllerBaseAddress;
    ReadBackRegisterdata->CanMcanSSCtrl           = MCAL_LIB_REG_READ32(baseAddr + MCAN_MCANSS_CTRL);
    ReadBackRegisterdata->CanMcanCccr             = MCAL_LIB_REG_READ32(baseAddr + MCAN_CCCR);
    ReadBackRegisterdata->CanMcanDBTP             = MCAL_LIB_REG_READ32(baseAddr + MCAN_DBTP);
    ReadBackRegisterdata->CanMcanErrCtrl          = MCAL_LIB_REG_READ32(baseAddr + MCAN_ECC_AGGR_CONTROL);
    ReadBackRegisterdata->CanMcanGfc              = MCAL_LIB_REG_READ32(baseAddr + MCAN_GFC);
    ReadBackRegisterdata->CanMcanIe               = MCAL_LIB_REG_READ32(baseAddr + MCAN_IE);
    ReadBackRegisterdata->CanMcanIle              = MCAL_LIB_REG_READ32(baseAddr + MCAN_ILE);
    ReadBackRegisterdata->CanMcanIls              = MCAL_LIB_REG_READ32(baseAddr + MCAN_ILS);
    ReadBackRegisterdata->CanMcanIr               = MCAL_LIB_REG_READ32(baseAddr + MCAN_IR);
    ReadBackRegisterdata->CanMcanNBTP             = MCAL_LIB_REG_READ32(baseAddr + MCAN_NBTP);
    ReadBackRegisterdata->CanMcanPsr              = MCAL_LIB_REG_READ32(baseAddr + MCAN_PSR);
    ReadBackRegisterdata->CanMcanSidfc            = MCAL_LIB_REG_READ32(baseAddr + MCAN_SIDFC);
    ReadBackRegisterdata->CanMcanTdcr             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TDCR);
    ReadBackRegisterdata->CanMcanTest             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TEST);
    ReadBackRegisterdata->CanMcanXidfc            = MCAL_LIB_REG_READ32(baseAddr + MCAN_XIDFC);
    ReadBackRegisterdata->CanMcanSSIe             = MCAL_LIB_REG_READ32(baseAddr + MCAN_MCANSS_IE);
    ReadBackRegisterdata->CanMcanSSExtTSPrescaler = MCAL_LIB_REG_READ32(baseAddr + MCAN_MCANSS_EXT_TS_PRESCALER);
    ReadBackRegisterdata->CanMcanRwd              = MCAL_LIB_REG_READ32(baseAddr + MCAN_RWD);
    ReadBackRegisterdata->CanMcanTscc             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TSCC);
    ReadBackRegisterdata->CanMcanTscv             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TSCV);
    ReadBackRegisterdata->CanMcanTocc             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TOCC);
    ReadBackRegisterdata->CanMcanTocv             = MCAL_LIB_REG_READ32(baseAddr + MCAN_TOCV);
    ReadBackRegisterdata->CanMcanEcr              = MCAL_LIB_REG_READ32(baseAddr + MCAN_ECR);
    ReadBackRegisterdata->CanMcanXidam            = MCAL_LIB_REG_READ32(baseAddr + MCAN_XIDAM);
    ReadBackRegisterdata->CanMcanHpms             = MCAL_LIB_REG_READ32(baseAddr + MCAN_HPMS);
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*
 *Design: MCAL-28432
 */
static FUNC(void, CAN_CODE)
    Can_CheckAllTxBuffers(uint32 txStat, P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canCntrlObj,
                          P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailObj)
{
    VAR(uint8, AUTOMATIC) loopCnt        = (uint8)0U;
    VAR(uint32, AUTOMATIC) bitPos        = (uint32)0U;
    VAR(Can_HwHandleType, AUTOMATIC) hth = (Can_HwHandleType)0U;

    /* Loop through all transmit buffers*/
    for (loopCnt = ((uint8)0U); loopCnt < MCAN_TX_MB_MAX_NUM; loopCnt++)
    {
        bitPos = ((uint32)1U << loopCnt);
        if (bitPos == (txStat & bitPos))
        {
            hth = canCntrlObj->canFDMsgRamConfig.canTxBufToHohMapping[loopCnt];
            if ((canCntrlObj->canControllerConfig.CanTxProcessing == CAN_INTERRUPT) ||
                ((canCntrlObj->canControllerConfig.CanTxProcessing == CAN_MIXED) &&
                 (canMailObj[hth].mailBoxConfig.CanHardwareObjectUsesPolling == FALSE)))
            {
                if ((CAN_TRANSMIT == canMailObj[hth].mailBoxConfig.CanObjectType) &&
                    (((uint8)1U) == canCntrlObj->canTxStatus[loopCnt]))
                {
                    /* Clear the status as data is already sent */
                    canCntrlObj->canTxStatus[loopCnt] = ((uint8)0U);
                    /* Call Tx Confirmation */
                    CanIf_TxConfirmation(canCntrlObj->canTxRxPduId[loopCnt]);
                }
            }
        }
    }
}

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)

/*
 *Design: MCAL-23037
 */
static FUNC(Std_ReturnType, CAN_CODE) Can_CheckMbConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) returnStatus = E_OK;
    VAR(uint32, AUTOMATIC) loopCnt              = (uint32)0U;

    for (loopCnt = 0U; loopCnt < KMAX_MAILBOXES; loopCnt++)
    {
        if (NULL_PTR == ConfigPtr->MailBoxList[loopCnt])
        {
            returnStatus = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == ConfigPtr->MailBoxList[loopCnt]->CanControllerRef)
        {
            returnStatus = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /*Do Nothing*/
        }

        if (returnStatus == (Std_ReturnType)E_NOT_OK)
        {
            break;
        }
    }
    return returnStatus;
}
#endif

/*
 *Design: MCAL-24222
 */
static FUNC(void, CAN_CODE) Can_WaitForMemoryInitPriv(uint32 baseAddr)
{
    VAR(uint32, AUTOMATIC) elapsedCount = (uint32)0;

    do
    {
        McalLib_Delay(1);
        elapsedCount += (uint32)15U;
        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION_CYCLES <= elapsedCount)
        {
#if (CAN_CFG_DEM_ENABLE == STD_ON)
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /* Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while ((uint32)1U !=
             (uint32)MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_MCANSS_STAT), MCAN_MCANSS_STAT_MEM_INIT_DONE));
    /* TI_COVERAGE_GAP_STOP */
}

/*
 *Design: MCAL-23038
 */
static FUNC(Can_ControllerOperationMode, CAN_CODE) Can_GetOpModePriv(uint32 baseAddr)
{
    VAR(Can_ControllerOperationMode, AUTOMATIC) controllerMode;

    if ((uint32)1U == ((uint32)MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_CCCR), MCAN_CCCR_INIT)))
    {
        controllerMode = CAN_CONTROLLER_OPERATION_MODE_SW_INIT;
    }
    else
    {
        controllerMode = CAN_CONTROLLER_OPERATION_MODE_NORMAL;
    }

    return controllerMode;
}

/*
 *Design: MCAL-23039
 */
static FUNC(void, CAN_CODE) Can_SetOpModePriv(uint32 baseAddr, Can_ControllerOperationMode cntrMode)
{
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_INIT, cntrMode);
    VAR(uint32, AUTOMATIC) elapsedCount = (uint32)0;
    do
    {
        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION_CYCLES <= elapsedCount)
        {
#if (CAN_CFG_DEM_ENABLE == STD_ON)
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /* Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while ((Can_ControllerOperationMode)cntrMode !=
             (Can_ControllerOperationMode)MCAL_LIB_REG_MF_READ32((baseAddr + MCAN_CCCR), MCAN_CCCR_INIT));
    /* TI_COVERAGE_GAP_STOP */
}

/*
 *Design: MCAL-23040
 */
static FUNC(Can_ClockStopAckMode, CAN_CODE) Can_GetClkStopAckPriv(Can_ControllerInstance instance)
{
    VAR(Can_ClockStopAckMode, AUTOMATIC) clockStopAck = (uint8)0U;
    VAR(uint32, AUTOMATIC) canStopClkAck              = 0U;
    canStopClkAck                                     = (MCAN_CLOCK_STOP << (uint32)instance);

    if (canStopClkAck == (MCAL_LIB_REG_READ32(CPUSYS_BASE + SYSCTL_O_CLKSTOPACK) & canStopClkAck))
    {
        clockStopAck = CAN_CLOCK_STOP_ACK;
    }
    else
    {
        clockStopAck = CAN_CLOCK_STOP_NO_ACK;
    }

    return clockStopAck;
}

/*
 *Design: MCAL-23041
 */
static FUNC(void, CAN_CODE)
    Can_InitHwPriv(uint32 baseAddr, P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    /* Configure MCAN wakeup */
    regVal = MCAL_LIB_REG_READ32(baseAddr + MCAN_MCANSS_CTRL);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_MCANSS_CTRL_WAKEUPREQEN, configParam->CanWakeupSupport);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_MCANSS_CTRL_AUTOWAKEUP, configParam->CanWakeupSupport);
    MCAL_LIB_REG_WRITE32(baseAddr + MCAN_MCANSS_CTRL, regVal);

    /* Configure MCAN mode(FD vs Classic CAN operation) and controls */
    regVal = MCAL_LIB_REG_READ32(baseAddr + MCAN_CCCR);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_CCCR_FDOE, configParam->CanConfigParam.CanFDMode);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_CCCR_BRSE,
                             configParam->CanControllerDefaultBaudrate->BaudFdRateConfig.CanControllerTxBitRateSwitch);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_CCCR_TXP, configParam->CanConfigParam.CanTransmitPause);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_CCCR_PXHD, /* Protocol Exception Handling Disable */
                             (uint32)0U);
    MCAL_LIB_REG_FIELD_SET32(regVal, MCAN_CCCR_DAR, configParam->CanConfigParam.CanDisableAutomaticRetransmission);
    MCAL_LIB_REG_WRITE32(baseAddr + MCAN_CCCR, regVal);

    /* Configure Global Filter */
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_GFC, MCAN_GFC_RRFE, (uint32)1U);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_GFC, MCAN_GFC_RRFS, (uint32)1U);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_GFC, MCAN_GFC_ANFE, (uint32)2U);
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_GFC, MCAN_GFC_ANFS, (uint32)2U);
}

/*
 *Design: MCAL-24224
 */
static FUNC(void, CAN_CODE) Can_WriteProtectedRegUnlockPriv(uint32 baseAddr)
{
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_CCE, 0x1U);
}

/*
 *Design: MCAL-24225
 */
static FUNC(void, CAN_CODE) Can_WriteProtectedRegLockPriv(uint32 baseAddr)
{
    MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_CCE, 0x0U);
}

/*
 *Design: MCAL-23042
 */
static FUNC(void, CAN_CODE)
    Can_SetupMsgRamPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                        P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, uint16 maxMbCnt)
{
    VAR(Can_HwHandleType, AUTOMATIC) htrh                                   = (Can_HwHandleType)0U;
    VAR(uint32, AUTOMATIC) baseAddr                                         = (uint32)0U;
    VAR(uint8, AUTOMATIC) controller                                        = (uint8)0U;
    P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) canControllerCfg      = NULL_PTR;
    P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg               = NULL_PTR;
    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) mailboxCfgList        = NULL_PTR;
    P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig = NULL_PTR;

    controller       = canController->canControllerConfig.CanControllerId;
    canControllerCfg = &canController->canControllerConfig;
    mailboxCfgList   = &canMailbox[0U];
    baseAddr         = canControllerCfg->CanControllerBaseAddress;
    msgRamConfig     = &canController->canFDMsgRamConfig;

    Can_MsgRamConfigInitPriv(msgRamConfig, canControllerCfg);

    /* Initialize Message RAM parameters according to configured mailboxes */
    for (htrh = ((Can_HwHandleType)0U); htrh < (Can_HwHandleType)maxMbCnt; htrh++)
    {
        mailboxCfg = &mailboxCfgList[htrh].mailBoxConfig;

        if (controller == mailboxCfg->CanControllerRef->CanControllerId)
        {
            if (CAN_RECEIVE == mailboxCfg->CanObjectType)
            {
                Can_SetupRxMailboxPriv(msgRamConfig, mailboxCfg);
            }
            else
            {
                Can_SetupTxMailboxPriv(msgRamConfig, mailboxCfg, canControllerCfg, htrh, baseAddr);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }

    msgRamConfig->configParams.lss = msgRamConfig->stdFilterNum;
    msgRamConfig->configParams.lse = msgRamConfig->extFilterNum;

    /* Configure Message RAM Sections :
     *  STD/EXT filters, Tx Buffers/FIFO and Rx Buffers/FIFO */
    Can_MsgRamConfigPriv(baseAddr, msgRamConfig);
}

/*
 *Design: MCAL-23043
 */
static FUNC(void, CAN_CODE)
    Can_MsgRamConfigInitPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                             P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) canControllerCfg)
{
    VAR(uint8, AUTOMATIC) loopCnt                                   = (uint32)0U;
    P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) controllerCfg = canControllerCfg;

    msgRamConfig->stdFilterNum = ((uint8)0U);
    msgRamConfig->extFilterNum = ((uint8)0U);

    /* Initialize Message RAM configuration parameters */
    msgRamConfig->configParams.flssa                = ((uint32)0U);
    msgRamConfig->configParams.lss                  = ((uint8)0U);
    msgRamConfig->configParams.flesa                = ((uint32)0U);
    msgRamConfig->configParams.lse                  = ((uint8)0U);
    msgRamConfig->configParams.txStartAddr          = ((uint32)0U);
    msgRamConfig->configParams.txBufNum             = ((uint8)0U);
    msgRamConfig->configParams.txFIFOSize           = ((uint8)0U);
    msgRamConfig->configParams.txBufMode            = ((uint32)1U);
    msgRamConfig->configParams.txEventFIFOStartAddr = ((uint32)0U);
    msgRamConfig->configParams.txEventFIFOSize      = ((uint32)0U);
    msgRamConfig->configParams.txEventFIFOWaterMark = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0startAddr     = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0size          = ((uint8)0U);
    msgRamConfig->configParams.rxFIFO0waterMark     = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0OpMode        = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1startAddr     = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1size          = ((uint8)0U);
    msgRamConfig->configParams.rxFIFO1waterMark     = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1OpMode        = ((uint32)0U);
    msgRamConfig->configParams.rxBufStartAddr       = ((uint32)0U);

    /* Message buffer element size is set to 8 bytes or 64 bytes based on FD mode support*/
    if (controllerCfg->CanConfigParam.CanFDMode == TRUE)
    {
        msgRamConfig->configParams.bufferElemSize = (uint32)MCAN_MSG_RAM_TX_RX_FD_ELEM_SIZE;
    }
    else
    {
        msgRamConfig->configParams.bufferElemSize = (uint32)MCAN_MSG_RAM_TX_RX_CLASSIC_ELEM_SIZE;
    }

    msgRamConfig->txBuffNum = ((uint8)0U);
    msgRamConfig->txFIFONum = ((uint8)0U);
    msgRamConfig->rxBuffNum = ((uint8)0U);
    msgRamConfig->rxFIFONum = ((uint8)0U);

    for (loopCnt = ((uint8)0U); loopCnt < (uint8)KMAX_TX_MB_PER_CONTROLLER; loopCnt++)
    {
        msgRamConfig->canTxBufToHohMapping[loopCnt] = ((Can_HwHandleType)0xFFU);
    }
    for (loopCnt = ((uint8)0U); loopCnt < KMAX_RX_MB_PER_CONTROLLER; loopCnt++)
    {
        msgRamConfig->canRxBufToHohMapping[loopCnt] = ((Can_HwHandleType)0xFFU);
    }
    for (loopCnt = ((uint8)0U); loopCnt < KMAX_STD_FILTERS_PER_CONTROLLER; loopCnt++)
    {
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfid1 = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfid2 = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfec  = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sft   = ((uint32)0x3U);
    }
    for (loopCnt = ((uint8)0U); loopCnt < KMAX_EXTD_FILTERS_PER_CONTROLLER; loopCnt++)
    {
        msgRamConfig->extMsgIDFilterList[loopCnt].efid1 = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].efid2 = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].efec  = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].eft   = ((uint32)0x3U);
    }
}

/*
 *Design: MCAL-23044
 */
static FUNC(void, CAN_CODE)
    Can_SetupRxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                           P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg)
{
    VAR(uint8, AUTOMATIC) idx        = (uint8)0U;
    VAR(uint8, AUTOMATIC) filterList = (uint8)0U;

    if (mailboxCfg->CanHandleType == CAN_BASIC)
    {
        if (((Can_IdType)CAN_ID_STD == mailboxCfg->CanIdType) || ((Can_IdType)CAN_ID_MIXED == mailboxCfg->CanIdType))
        {
            for (filterList = (uint8)0U; filterList < mailboxCfg->CanFilterListCount; filterList++)
            {
                /* Index of Standard filter*/
                idx = msgRamConfig->stdFilterNum;

                /* Standard filter ids*/
                msgRamConfig->stdMsgIDFilterList[idx].sfid1 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterCode & CAN_STD_MSGID_MASK);
                msgRamConfig->stdMsgIDFilterList[idx].sfid2 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterMask.MaskValue & CAN_STD_MSGID_MASK);

                if (mailboxCfg->HwHandle == ((uint8)0U))
                {
                    /* Store the message in Rx FIFO 0 */
                    msgRamConfig->stdMsgIDFilterList[idx].sfec = MCAN_MSGRAM_RX_FIFO_0;
                    msgRamConfig->configParams.rxFIFO0size     = mailboxCfg->CanHwObjectCount;
                }
                else
                {
                    /* Store the message in Rx FIFO 1 */
                    msgRamConfig->stdMsgIDFilterList[idx].sfec = MCAN_MSGRAM_RX_FIFO_1;
                    msgRamConfig->configParams.rxFIFO1size     = mailboxCfg->CanHwObjectCount;
                }
                /* Filter type configuration */
                msgRamConfig->stdMsgIDFilterList[idx].sft =
                    mailboxCfg->CanHwFilterList[filterList]->CanStandardFilterType;

                msgRamConfig->stdFilterNum++;
            }
        }
        if (((Can_IdType)CAN_ID_XTD == mailboxCfg->CanIdType) || ((Can_IdType)CAN_ID_MIXED == mailboxCfg->CanIdType))
        {
            for (filterList = (uint8)0U; filterList < mailboxCfg->CanFilterListCount; filterList++)
            {
                /* Index of Standard filter*/
                idx = msgRamConfig->extFilterNum;

                msgRamConfig->extMsgIDFilterList[idx].efid1 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterCode & CAN_XTD_MSGID_MASK);
                msgRamConfig->extMsgIDFilterList[idx].efid2 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterMask.MaskValue & CAN_XTD_MSGID_MASK);

                if (mailboxCfg->HwHandle == ((uint8)0U))
                {
                    /* Store the message in Rx FIFO 0 */
                    msgRamConfig->extMsgIDFilterList[idx].efec = MCAN_MSGRAM_RX_FIFO_0;
                    msgRamConfig->configParams.rxFIFO0size     = mailboxCfg->CanHwObjectCount;
                }
                else
                {
                    /* Store the message in Rx FIFO 1 */
                    msgRamConfig->extMsgIDFilterList[idx].efec = MCAN_MSGRAM_RX_FIFO_1;
                    msgRamConfig->configParams.rxFIFO1size     = mailboxCfg->CanHwObjectCount;
                }

                /* Filter type configuration */
                msgRamConfig->extMsgIDFilterList[idx].eft =
                    mailboxCfg->CanHwFilterList[filterList]->CanStandardFilterType;

                msgRamConfig->extFilterNum++;
            }
        }
        msgRamConfig->rxFIFONum++;
        msgRamConfig->canRxFifoToHohMapping[mailboxCfg->HwHandle] = mailboxCfg->CanObjectId;
    }
    else
    {
        if (((Can_IdType)CAN_ID_STD == mailboxCfg->CanIdType) || ((Can_IdType)CAN_ID_MIXED == mailboxCfg->CanIdType))
        {
            for (filterList = (uint8)0U; filterList < mailboxCfg->CanFilterListCount; filterList++)
            {
                /* Index of Standard filter*/
                idx = msgRamConfig->stdFilterNum;

                /* Standard filter ids*/
                msgRamConfig->stdMsgIDFilterList[idx].sfid1 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterCode & CAN_STD_MSGID_MASK);
                msgRamConfig->stdMsgIDFilterList[idx].sfid2 = (uint32)msgRamConfig->rxBuffNum;
                msgRamConfig->stdMsgIDFilterList[idx].sfid2 |=
                    ((uint32)((uint32)mailboxCfg->CanHwFilterList[filterList]->CanEventPin
                              << (uint32)MCANSS_STD_ID_FILTER_SFID2_EVENT_PIN_SHIFT));

                /* Store the message in dedicated buffer */
                msgRamConfig->stdMsgIDFilterList[idx].sfec = MCAN_MSGRAM_RX_BUFFER;

                /* Standard filter type ignored for dedicated buffer */
                msgRamConfig->stdMsgIDFilterList[idx].sft = ((uint32)0x0U);

                msgRamConfig->stdFilterNum++;
            }
        }
        if (((Can_IdType)CAN_ID_XTD == mailboxCfg->CanIdType) || ((Can_IdType)CAN_ID_MIXED == mailboxCfg->CanIdType))
        {
            for (filterList = (uint8)0U; filterList < mailboxCfg->CanFilterListCount; filterList++)
            {
                /* Index of Standard filter*/
                idx = msgRamConfig->extFilterNum;

                msgRamConfig->extMsgIDFilterList[idx].efid1 =
                    (mailboxCfg->CanHwFilterList[filterList]->CanHwFilterCode & CAN_XTD_MSGID_MASK);
                msgRamConfig->extMsgIDFilterList[idx].efid2 = (uint32)msgRamConfig->rxBuffNum;
                msgRamConfig->extMsgIDFilterList[idx].efid2 |=
                    ((uint32)((uint32)mailboxCfg->CanHwFilterList[filterList]->CanEventPin
                              << (uint32)MCANSS_EXT_ID_FILTER_SFID2_EVENT_PIN_SHIFT));

                /* Store the message in dedicated buffer */
                msgRamConfig->extMsgIDFilterList[idx].efec = MCAN_MSGRAM_RX_BUFFER;

                /* Extended filter type ignored for dedicated buffer */
                msgRamConfig->extMsgIDFilterList[idx].eft = ((uint32)0x0U);

                msgRamConfig->extFilterNum++;
            }
        }
        /* Set Mailbox Entry */
        msgRamConfig->rxBuffNum++;
        msgRamConfig->canRxBufToHohMapping[mailboxCfg->HwHandle] = mailboxCfg->CanObjectId;
    }
}

/*
 *Design: MCAL-24226
 */
static FUNC(void, CAN_CODE)
    Can_SetupTxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                           P2CONST(Can_MailboxType, AUTOMATIC, CAN_CONST) mailboxCfg,
                           P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) canControllerCfg, Can_HwHandleType htrh,
                           uint32 baseAddr)
{
    VAR(uint8, AUTOMATIC) intrCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    if (CAN_BASIC == mailboxCfg->CanHandleType)
    {
        /* Set Mailbox Entry */
        msgRamConfig->txFIFONum               += ((uint8)1U);
        msgRamConfig->configParams.txFIFOSize += mailboxCfg->CanHwObjectCount;

        /* Prepare Transmission Interrupt Enable Mask */

        if ((CAN_INTERRUPT == canControllerCfg->CanTxProcessing) ||
            ((CAN_MIXED == canControllerCfg->CanTxProcessing) && (FALSE == mailboxCfg->CanHardwareObjectUsesPolling)))
        {
            regVal = MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBTIE);
            for (intrCnt = ((uint8)0U); intrCnt < mailboxCfg->CanHwObjectCount; intrCnt++)
            {
                regVal |= (((uint32)1U) << (msgRamConfig->txBuffNum + intrCnt));
                msgRamConfig->canTxBufToHohMapping[(msgRamConfig->txBuffNum + intrCnt)] = htrh;
            }
            MCAL_LIB_REG_WRITE32(baseAddr + MCAN_TXBTIE, regVal);
        }
    }
    else
    {
        /* Set Mailbox Entry */
        msgRamConfig->canTxBufToHohMapping[mailboxCfg->HwHandle]  = htrh;
        msgRamConfig->txBuffNum                                  += ((uint8)1U);
        msgRamConfig->configParams.txBufNum++;

        /* Prepare Transmission Interrupt Enable Mask */
        if ((CAN_INTERRUPT == canControllerCfg->CanTxProcessing) ||
            ((CAN_MIXED == canControllerCfg->CanTxProcessing) && (FALSE == mailboxCfg->CanHardwareObjectUsesPolling)))
        {
            regVal  = MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBTIE);
            regVal |= ((uint32)1U << (mailboxCfg->HwHandle));
            MCAL_LIB_REG_WRITE32(baseAddr + MCAN_TXBTIE, regVal);
        }
    }
}

/*
 *Design: MCAL-24229
 */
static FUNC(void, CAN_CODE) Can_AddStdMsgIDFilterPriv(uint32 baseAddr, uint8 filtNum,
                                                      P2CONST(Can_StdMsgIDFilterElement, AUTOMATIC, CAN_CONST) elem)
{
    VAR(uint32, AUTOMATIC) startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemAddr  = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal    = (uint32)0U;

    startAddr = MCAL_LIB_REG_MF_READ32(baseAddr + MCAN_SIDFC, MCAN_SIDFC_FLSSA);
    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemAddr  = startAddr + ((uint32)filtNum * MCANSS_STD_ID_FILTER_SIZE_WORDS * 4U);

    regVal  = ((uint32)0U);
    regVal |= (elem->sfid2 << MCANSS_STD_ID_FILTER_SFID2_SHIFT);
    regVal |= (elem->sfid1 << MCANSS_STD_ID_FILTER_SFID1_SHIFT);
    regVal |= (elem->sfec << MCANSS_STD_ID_FILTER_SFEC_SHIFT);
    regVal |= (elem->sft << MCANSS_STD_ID_FILTER_SFT_SHIFT);
    MCAL_LIB_REG_WRITE32(baseAddr + elemAddr, regVal);
}

/*
 *Design: MCAL-24230
 */
static FUNC(void, CAN_CODE) Can_AddExtMsgIDFilterPriv(uint32 baseAddr, uint8 filtNum,
                                                      P2CONST(Can_ExtMsgIDFilterElement, AUTOMATIC, CAN_CONST) elem)
{
    VAR(uint32, AUTOMATIC) startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC) elemAddr  = (uint32)0U;
    VAR(uint32, AUTOMATIC) regVal    = (uint32)0U;

    startAddr = MCAL_LIB_REG_MF_READ32(baseAddr + MCAN_XIDFC, MCAN_XIDFC_FLESA);
    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemAddr  = startAddr + ((uint32)filtNum * MCANSS_EXT_ID_FILTER_SIZE_WORDS * 4U);

    regVal  = ((uint32)0U);
    regVal |= (elem->efid1 << MCANSS_EXT_ID_FILTER_EFID1_SHIFT);
    regVal |= (elem->efec << MCANSS_EXT_ID_FILTER_EFEC_SHIFT);
    MCAL_LIB_REG_WRITE32(baseAddr + elemAddr, regVal);

    elemAddr += ((uint32)4U);
    regVal    = ((uint32)0U);
    regVal   |= (elem->efid2 << MCANSS_EXT_ID_FILTER_EFID2_SHIFT);
    regVal   |= (elem->eft << MCANSS_EXT_ID_FILTER_EFT_SHIFT);
    MCAL_LIB_REG_WRITE32(baseAddr + elemAddr, regVal);
}

/*
 *Design: MCAL-23045
 */
static FUNC(void, CAN_CODE) Can_LoopbackModePriv(uint32 baseAddr, boolean loopbackMode)
{
    if ((boolean)TRUE == loopbackMode)
    {
        /*  Enable internal loopback mode */
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_TEST, 0x1U);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TEST, MCAN_TEST_LBCK, 0x1U);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_MON, 0x0U);
    }
    else
    {
        /*  Disable loopback mode */
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_TEST, 0x0U);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_TEST, MCAN_TEST_LBCK, 0x0U);
        MCAL_LIB_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_MON, 0x0U);
    }
}

/*
 *Design: MCAL-23046
 */
static FUNC(uint32, CAN_CODE) Can_GetInterruptMaskPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_CONST) configParam)
{
    VAR(uint32, AUTOMATIC) interruptMask = (uint32)0U;

    /* Enable BusOff Interrupt*/
    if (CAN_INTERRUPT == configParam->CanBusoffProcessing)
    {
        interruptMask |= ((uint32)MCAN_IR_BO_MASK);
    }

    /* Enable Receive Interrupt*/
    if (CAN_POLLING != configParam->CanRxProcessing)
    {
        interruptMask |= ((uint32)MCAN_IR_RF0N_MASK | (uint32)MCAN_IR_RF1N_MASK | (uint32)MCAN_IR_RF0L_MASK |
                          (uint32)MCAN_IR_RF1L_MASK | (uint32)MCAN_IR_DRX_MASK);
    }

    /* Enable Transmit Interrupt*/
    if (CAN_POLLING != configParam->CanTxProcessing)
    {
        interruptMask |= ((uint32)MCAN_IR_TFE_MASK | (uint32)MCAN_IR_TC_MASK);
    }

#if (CAN_CFG_DEM_ENABLE == STD_ON)
    /* Enable Hardware Error Interrupt*/
    interruptMask |=
        ((uint32)MCAN_IR_RF0F_MASK | (uint32)MCAN_IR_RF1F_MASK | (uint32)MCAN_IR_ARA_MASK | (uint32)MCAN_IR_PED_MASK |
         (uint32)MCAN_IR_PEA_MASK | (uint32)MCAN_IR_WDI_MASK | (uint32)MCAN_IR_EW_MASK | (uint32)MCAN_IR_EP_MASK |
         (uint32)MCAN_IR_ELO_MASK | (uint32)MCAN_IR_TOO_MASK | (uint32)MCAN_IR_MRAF_MASK);
#endif

#if (CAN_CFG_DEM_BEU_ENABLE == STD_ON)
    /* Enable Bit Error Uncorrected Interrupt*/
    interruptMask |= ((uint32)MCAN_IR_BEU_MASK);
#endif

    return interruptMask;
}

/*
 *Design: MCAL-23047
 */
static FUNC(void, CAN_CODE) Can_EnableInterruptPriv(uint32 baseAddr, uint32 interruptMask, boolean enable)
{
    VAR(uint32, AUTOMATIC) regVal;

    regVal = MCAL_LIB_REG_READ32(baseAddr + MCAN_IE);
    if (TRUE == enable)
    {
        regVal |= interruptMask;
    }
    else
    {
        regVal &= ~interruptMask;
    }
    MCAL_LIB_REG_WRITE32(baseAddr + MCAN_IE, regVal);
}

/*
 *Design: MCAL-23048
 */
static FUNC(void, CAN_CODE) Can_SelectInterruptLinePriv(uint32 baseAddr, uint32 interruptMask)
{
    VAR(uint32, AUTOMATIC) regVal;

    regVal  = MCAL_LIB_REG_READ32(baseAddr + MCAN_ILS);
    regVal &= ~(MCANSS_INTR_LINE_0_MASK & interruptMask);
    regVal |= (MCANSS_INTR_LINE_1_MASK & interruptMask);
    MCAL_LIB_REG_WRITE32(baseAddr + MCAN_ILS, regVal);
}

/*
 *Design: MCAL-23049
 */
static FUNC(void, CAN_CODE) Can_EnableInterruptLinePriv(uint32 baseAddr, boolean enable)
{
    VAR(uint32, AUTOMATIC) regVal;

    regVal = MCAL_LIB_REG_READ32(baseAddr + MCAN_ILE);

    if (enable == TRUE)
    {
        regVal |= ((uint32)0x3U);
    }
    else
    {
        regVal &= ~((uint32)0x3U);
    }
    MCAL_LIB_REG_WRITE32(baseAddr + MCAN_ILE, regVal);
}

/*
 *Design: MCAL-23050
 */
static FUNC(void, CAN_CODE) Can_AddClkStopRequestPriv(Can_ControllerInstance instance, boolean enable)
{
    VAR(uint32, AUTOMATIC) clkStop = 0U;
    if (TRUE == enable)
    {
        clkStop = (KEY_VALUE | (MCAN_CLOCK_STOP << (uint32)instance));
    }
    else
    {
        clkStop = (KEY_VALUE | (enable << (uint32)instance));
    }

    MCAL_LIB_REG_WRITE32(CPUSYS_BASE + SYSCTL_O_CLKSTOPREQ, clkStop);
}

/*
 *Design: MCAL-23051
 */
static FUNC(void, CAN_CODE) Can_CancelPendingMsgPriv(uint32 baseAddr)
{
    VAR(uint32, AUTOMATIC) txBufPendStatus = (uint32)0U;
    VAR(uint32, AUTOMATIC) bitIndex        = (uint32)0U;
    VAR(uint32, AUTOMATIC) bitPos          = (uint32)0U;

    /* Get Tx Buffers with pending message requests */
    txBufPendStatus = Can_GetTxBufReqPendPriv(baseAddr);

    for (bitIndex = ((uint32)0U); bitIndex < ((uint32)32U); bitIndex++)
    {
        /* For each bit set call cancel request */
        bitPos = (uint32)1U << bitIndex;

        if (bitPos == (txBufPendStatus & bitPos))
        {
            /* Clear pending Tx request */
            Can_TxBufCancelReqPriv(baseAddr, bitIndex);

            /* Wait till cancellation request is accepted */
            Can_WaitForTxBufCancelReqPriv(bitPos, baseAddr);
        }
    }
}

/*
 *Design: MCAL-28428
 */
static FUNC(void, CAN_CODE) Can_WaitForTxBufCancelReqPriv(uint32 bitPos, uint32 baseAddr)
{
    VAR(McalLib_TickType, AUTOMATIC) elapsedCnt = 0U;
    VAR(McalLib_TickType, AUTOMATIC) startCount = (McalLib_TickType)0U;

    /* Fetch the start time */
    (void)McalLib_GetCounterValue(&startCount);
    do
    {
        (void)McalLib_GetElapsedValue(&startCount, &elapsedCnt);
        /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
        if (CAN_CFG_TIMEOUT_DURATION <= elapsedCnt)
        {
            /*  Timeout */
#if (CAN_CFG_DEM_ENABLE == STD_ON)
            (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PREFAILED);
#endif
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            /*  Do Nothing */
        }
        /* TI_COVERAGE_GAP_START [Branch/MC-DC Coverage] This cannot be covered can't simulate
         * Hardware IP Errors */
    } while ((uint32)bitPos != ((Can_TxBufCancelStatusPriv(baseAddr))&bitPos));
    /* TI_COVERAGE_GAP_STOP */

    return;
}

/*
 *Design: MCAL-23052
 */
static FUNC(uint32, CAN_CODE) Can_GetTxBufReqPendPriv(uint32 baseAddr)
{
    return (MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBRP));
}

/*
 *Design: MCAL-24231
 */
static FUNC(void, CAN_CODE) Can_TxBufCancelReqPriv(uint32 baseAddr, uint32 buffNum)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    regVal  = MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBCR);
    regVal |= ((uint32)1U << buffNum);
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_TXBCR), regVal);
}

/*
 *Design: MCAL-24232
 */
static FUNC(uint32, CAN_CODE) Can_TxBufCancelStatusPriv(uint32 baseAddr)
{
    return (MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBCF));
}

/*
 *Design: MCAL-23053
 */
static FUNC(uint32, CAN_CODE) Can_GetTxBufTransStatusPriv(uint32 baseAddr)
{
    return (MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBTO));
}

/*
 *Design: MCAL-23054
 */
static FUNC(void, CAN_CODE) Can_TxBufAddReqPriv(uint32 baseAddr, uint8 buffNum)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;

    regVal  = MCAL_LIB_REG_READ32(baseAddr + MCAN_TXBAR);
    regVal |= ((uint32)1U << buffNum);
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_TXBAR), regVal);
}

/*
 *Design: MCAL-24234
 */
static FUNC(void, CAN_CODE)
    Can_ReadRxBuffPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                       P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, Can_HwHandleType htrh,
                       P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus)
{
    VAR(uint32, AUTOMATIC) baseAddr            = (uint32)0U;
    VAR(uint8, AUTOMATIC) buffNum              = (uint32)0U;
    VAR(uint8, AUTOMATIC) canDataLength        = (uint8)0U;
    VAR(uint32, AUTOMATIC) canIdentifier       = (uint32)0U;
    VAR(Can_RxBufElementType, AUTOMATIC) elem  = {0U};
    VAR(boolean, AUTOMATIC) RxIndicationStatus = (boolean)FALSE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;
    buffNum  = canMailbox->mailBoxConfig.HwHandle;

    /* Read message RAM area*/
    Can_ReadMsgRamPriv(baseAddr, ((uint32)CAN_MEM_TYPE_BUF), buffNum, &elem);

    /* Clear NewData Status after reading*/
    Can_ClearNewDataStatusPriv(baseAddr, newDataStatus, buffNum);

    canDataLength = Can_DataSize[elem.dataLength];
    canIdentifier = Can_GetCanIdentifier(&elem);

    /* Copying payload into SDU */
    Can_CopyPayloadToSdu(canDataLength, controllerObj, &elem);

    /* Copy CanId, HOH and CanControllerId */
    controllerObj->mailboxCfg.CanId        = canIdentifier;
    controllerObj->mailboxCfg.Hoh          = canMailbox->mailBoxConfig.CanObjectId;
    controllerObj->mailboxCfg.ControllerId = controllerObj->canControllerConfig.CanControllerId;

    /* Copy SDU data */
    controllerObj->pduInfo.SduDataPtr = controllerObj->canSduPtr;
    controllerObj->pduInfo.SduLength  = ((PduLengthType)canDataLength);

    RxIndicationStatus = Can_RxIndicationStatusPriv(controllerObj, canIdentifier);
    Can_CallRxIndication(RxIndicationStatus, htrh, canIdentifier, canDataLength, controllerObj);
}

/*
 *Design: MCAL-24235
 */
static FUNC(void, CAN_CODE)
    Can_ReadRxFIFOPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                       P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_CONST) canMailbox, Can_HwHandleType htrh,
                       P2VAR(Can_RxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus)
{
    VAR(uint32, AUTOMATIC) baseAddr            = (uint32)0U;
    VAR(uint8, AUTOMATIC) fill_Lvl             = (uint32)0U;
    VAR(uint8, AUTOMATIC) loop_Cnt             = (uint32)0U;
    VAR(uint8, AUTOMATIC) canDataLength        = (uint8)0U;
    VAR(uint32, AUTOMATIC) canIdentifier       = (uint32)0U;
    VAR(Can_RxBufElementType, AUTOMATIC) elem  = {0U};
    VAR(boolean, AUTOMATIC) RxIndicationStatus = (boolean)FALSE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    if ((canMailbox->mailBoxConfig.HwHandle == (uint8)0) || (canMailbox->mailBoxConfig.HwHandle == (uint8)1))
    {
#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
        if (fifoStatus->msgLost == TRUE)
        {
            /* data lost error*/
            (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_MAINFUNC_READ, CAN_E_DATALOST);
        }
#endif
        fill_Lvl = fifoStatus->fillLvl;
        /* Loop through all received messages in FIFO0*/
        for (loop_Cnt = ((uint8)0U); loop_Cnt < fill_Lvl; loop_Cnt++)
        {
            if (canMailbox->mailBoxConfig.HwHandle == (uint8)0)
            {
                /* Read the message RAM area */
                Can_ReadMsgRamPriv(baseAddr, (Can_MemType)CAN_MEM_TYPE_FIFO0, fifoStatus->getIdx, &elem);
            }
            else
            {
                /* Read the message RAM area */
                Can_ReadMsgRamPriv(baseAddr, (Can_MemType)CAN_MEM_TYPE_FIFO1, fifoStatus->getIdx, &elem);
            }
            /* Acknowledge the message reception, the Fifo status will be updated after ack in hardware */
            Can_WriteRxFIFOAckPriv(baseAddr, fifoStatus->getIdx, canMailbox->mailBoxConfig.HwHandle);
            fifoStatus->getIdx++;
            canDataLength = Can_DataSize[elem.dataLength];
            canIdentifier = Can_GetCanIdentifier(&elem);
            /* Copy CanId, HOH and CanControllerId */
            controllerObj->mailboxCfg.CanId        = canIdentifier;
            controllerObj->mailboxCfg.Hoh          = canMailbox->mailBoxConfig.CanObjectId;
            controllerObj->mailboxCfg.ControllerId = controllerObj->canControllerConfig.CanControllerId;

            /* Copying payload into SDU */
            Can_CopyPayloadToSdu(canDataLength, controllerObj, &elem);

            /* Copy SDU data */
            controllerObj->pduInfo.SduDataPtr = controllerObj->canSduPtr;
            controllerObj->pduInfo.SduLength  = ((PduLengthType)canDataLength);

            /* Chcek whether Rx indication shall be called based on Icom */
            RxIndicationStatus = Can_RxIndicationStatusPriv(controllerObj, canIdentifier);

            /* Lpdu callout and Rx Indication */
            Can_CallRxIndication(RxIndicationStatus, htrh, canIdentifier, canDataLength, controllerObj);
        }
    }
}

/*
 *Design: MCAL-24215
 */
static FUNC(uint32, CAN_CODE) Can_GetIntrStatus(uint32 baseAddr)
{
    return (MCAL_LIB_REG_READ32(baseAddr + MCAN_IR));
}

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/*
 *Design: MCAL-28425
 */
static FUNC(Std_ReturnType, CAN_CODE)
    Can_ValidateIcomConfigCriteriaPriv(uint32 can_identifier, P2CONST(uint8, AUTOMATIC, CAN_CONST) sduptr,
                                       uint8  IcomConfigId,
                                       P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController)
{
    VAR(Std_ReturnType, AUTOMATIC) status    = E_NOT_OK;
    VAR(uint16, AUTOMATIC) LoopCount         = 0U;
    VAR(uint16, AUTOMATIC) RxMessageConfigId = 0U;
    P2CONST(Can_IcomConfigType, AUTOMATIC, CAN_CONST)
    IcomConfigPtr                        = &Can_DriverObjPtr->IcomConfigurationList[IcomConfigId - (uint8)1U];
    VAR(uint64, AUTOMATIC) sdudata       = 0U;
    VAR(uint64, AUTOMATIC) sdudataSingle = 0U;

    for (LoopCount = (uint16)0U; LoopCount < (uint16)8U; LoopCount++)
    {
        sdudataSingle  = sduptr[LoopCount];
        sdudata       |= (sdudataSingle << (8U * ((uint16)7U - LoopCount)));
    }

    if ((TRUE == IcomConfigPtr->CanIcomWakeOnBusOff) ||
        ((FALSE == IcomConfigPtr->CanIcomWakeOnBusOff) &&
         (CAN_ERRORSTATE_BUSOFF != Can_GetProtocolStatusPriv(canController))))
    {
        for (LoopCount = ((uint16)0U); LoopCount < IcomConfigPtr->RxMessageCount; LoopCount++)
        {
            if (can_identifier == ((uint32)IcomConfigPtr->CanIcomRxMessage[LoopCount].CanIcomMessageId))
            {
                RxMessageConfigId = LoopCount;
                break;
            }
        }

        status = Can_ValidateIcomConfigPriv(LoopCount, IcomConfigPtr, sdudata, RxMessageConfigId);
    }
    if (E_OK == status)
    {
        Can_DriverObjPtr->Can_IcomCounterValue[canController->canControllerConfig.CanControllerId]++;
        if (Can_DriverObjPtr->Can_IcomCounterValue[canController->canControllerConfig.CanControllerId] <
            IcomConfigPtr->CanIcomRxMessage[RxMessageConfigId].CanIcomCounterValue)
        {
            status = E_NOT_OK;
        }
        else
        {
            Can_DriverObjPtr->Can_IcomCounterValue[canController->canControllerConfig.CanControllerId] = 0U;
        }
    }
    return status;
}
#endif

/*
 *Design: MCAL-24216
 */
static FUNC(void, CAN_CODE) Can_ClearIntrStatusPriv(uint32 baseAddr, uint32 intrMask, uint32 lineSelect)
{
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_IR), intrMask);
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_MCANSS_EOI), lineSelect);
}

/*
 *Design: MCAL-24236
 */
static FUNC(void, CAN_CODE)
    Can_GetNewDataStatusPriv(uint32 baseAddr, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus)
{
    newDataStatus->statusLow  = MCAL_LIB_REG_READ32(baseAddr + MCAN_NDAT1);
    newDataStatus->statusHigh = MCAL_LIB_REG_READ32(baseAddr + MCAN_NDAT2);
}

/*
 *Design: MCAL-24237
 */
static FUNC(void, CAN_CODE)
    Can_ClearNewDataStatusPriv(uint32 baseAddr, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus,
                               uint8  buffNum)
{
    VAR(uint32, AUTOMATIC) lowerNdatStatus  = (uint32)0U;
    VAR(uint32, AUTOMATIC) higherNdatStatus = (uint32)0U;
    if (((uint8)32U) > buffNum)
    {
        lowerNdatStatus          = newDataStatus->statusLow & (((uint32)1U) << buffNum);
        newDataStatus->statusLow = newDataStatus->statusLow & (~lowerNdatStatus);
    }
    else
    {
        higherNdatStatus = newDataStatus->statusHigh & (((uint32)1U) << (buffNum - (uint8)32U));
        newDataStatus->statusHigh = newDataStatus->statusHigh & (~higherNdatStatus);
    }
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_NDAT1), lowerNdatStatus);
    MCAL_LIB_REG_WRITE32((baseAddr + MCAN_NDAT2), higherNdatStatus);
}

/*
 *Design: MCAL-24239
 */
static FUNC(void, CAN_CODE)
    Can_GetRxFIFOStatusPriv(uint32 baseAddr, P2VAR(Can_RxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus,
                            uint8  hwHandle)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;
    if (hwHandle == (uint8)0U)
    {
        /* hWHandle 0 represents RX FIFO0, read status of RX FIFO0 */
        regVal               = MCAL_LIB_REG_READ32(baseAddr + MCAN_RXF0S);
        fifoStatus->fifoFull = ((boolean)MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF0S_F0F));
        fifoStatus->fillLvl  = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF0S_F0FL);
        fifoStatus->getIdx   = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF0S_F0GI);
        fifoStatus->msgLost  = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF0S_RF0L);
        fifoStatus->putIdx   = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF0S_F0PI);
    }
    else if (hwHandle == (uint8)1U)
    {
        /* hWHandle 1 represents RX FIFO1, read status of RX FIFO1 */
        regVal               = MCAL_LIB_REG_READ32(baseAddr + MCAN_RXF1S);
        fifoStatus->fifoFull = ((boolean)MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF1S_F1F));
        fifoStatus->fillLvl  = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF1S_F1FL);
        fifoStatus->getIdx   = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF1S_F1GI);
        fifoStatus->msgLost  = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF1S_RF1L);
        fifoStatus->putIdx   = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_RXF1S_F1PI);
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-24239
 */
static FUNC(void, CAN_CODE)
    Can_GetTxFIFOStatusPriv(uint32 baseAddr, P2VAR(Can_TxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus)
{
    VAR(uint32, AUTOMATIC) regVal = (uint32)0U;
    /* Read the status of Tx FIFO */
    regVal               = MCAL_LIB_REG_READ32(baseAddr + MCAN_TXFQS);
    fifoStatus->fifoFull = ((boolean)MCAL_LIB_REG_FIELD_GET(regVal, MCAN_TXFQS_TFQF));
    fifoStatus->putIdx   = MCAL_LIB_REG_FIELD_GET(regVal, MCAN_TXFQS_TFQPI);
}

/*
 *Design: MCAL-28427
 */
static FUNC(void, CAN_CODE) Can_CheckBusOffPriv(uint32 intrStatus, uint32 baseAddr,
                                                P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canControllerObj)
{
    /* Process bus off interrupts*/
    if (MCAN_IR_BO_MASK == (intrStatus & MCAN_IR_BO_MASK))
    {
        if (canControllerObj->canControllerConfig.CanBusoffProcessing == CAN_INTERRUPT)
        {
            Can_CancelPendingMsgPriv(baseAddr);
            /* BusOff Recovery sequence has not started */
            canControllerObj->canState = CAN_CS_STOPPED;
            /*Call the bus off indicationtoCanIf function*/
            CanIf_ControllerBusOff(canControllerObj->canControllerConfig.CanControllerId);
        }
    }
    else
    {
        /* Do Nothing */
    }
}

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)
/*
 *Design: MCAL-28431
 */
static FUNC(Std_ReturnType, CAN_CODE)
    Can_CheckBaudRateConfigList(P2CONST(Can_ConfigType, AUTOMATIC, CAN_CONST) ConfigPtr, uint32 loopCount)
{
    VAR(Std_ReturnType, AUTOMATIC) returnStat = E_OK;
    VAR(uint32, AUTOMATIC) cnt                = (uint32)0U;
    for (cnt = 0U; cnt <= ConfigPtr->MaxBaudConfigID[loopCount]; cnt++)
    {
        if (NULL_PTR == ConfigPtr->CanControllerList[loopCount]->BaudRateConfigList[cnt])
        {
            returnStat = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    return returnStat;
}
#endif

/*
 *Design: MCAL-28437
 */
static FUNC(Std_ReturnType, CAN_CODE)
    Can_CheckPendingMsgPriv(P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_CONST) canController,
                            VAR(uint8, AUTOMATIC) loopCnt, VAR(uint32, AUTOMATIC) baseAddr,
                            P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) msgObj)
{
    VAR(uint8, AUTOMATIC) canTxStatus          = (uint8)0U;
    VAR(uint32, AUTOMATIC) bitIndex            = (uint32)0U;
    VAR(Std_ReturnType, AUTOMATIC) returnValue = E_NOT_OK;

    canTxStatus = canController->canTxStatus[loopCnt];
    bitIndex    = ((uint32)1U << loopCnt);

    /*- Check for pending message:
     *     - pending message, return CAN_BUSY
     *     - no pending message, start new transmission
     */
    /* Check BRP for requested buffer*/
    if (bitIndex == (Can_GetTxBufReqPendPriv(baseAddr) & bitIndex))
    {
        returnValue = (Std_ReturnType)CAN_BUSY;
    }
    /* Maintaining the canTxStatus is necessary, as BRP may get cleared upon lost arbitration,
        error during transmission etc.*/
    else if ((((uint8)1U) == canTxStatus) &&
             (FALSE == canController->canControllerConfig.CanConfigParam.CanDisableAutomaticRetransmission))
    {
        returnValue = (Std_ReturnType)CAN_BUSY;
    }
    else
    {
        *msgObj     = loopCnt;
        returnValue = E_OK;
    }
    return returnValue;
}

/*
 *Design: MCAL-28439
 */
static FUNC(boolean, CAN_CODE)
    Can_RxIndicationStatusPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                               VAR(uint32, AUTOMATIC) canIdentifier)
{
    VAR(boolean, AUTOMATIC) RxIndicationStatus = (boolean)FALSE;

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) icom_status;
    /* check for Icom configuration */
    if (Can_DriverObjPtr->Can_IcomActivation[controllerObj->canControllerConfig.CanControllerId] == TRUE)
    {
        icom_status = Can_ValidateIcomConfigCriteriaPriv(
            canIdentifier, controllerObj->pduInfo.SduDataPtr,
            Can_DriverObjPtr->Can_IcomConfigurationId[controllerObj->canControllerConfig.CanControllerId],
            controllerObj);
        if (E_OK == icom_status)
        {
            /* Call Receive Indication */
            RxIndicationStatus = TRUE;
        }
    }
    else
#endif
    {
        /* Call Receive Indication */
        RxIndicationStatus = TRUE;
    }

    return RxIndicationStatus;
}

/*
 *Design: MCAL-28444
 */
static FUNC(uint32, CAN_CODE) Can_GetCanIdentifier(P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem)
{
    VAR(uint32, AUTOMATIC) canIdentifier = (uint32)0U;

    if ((uint8)CAN_ID_XTD == elem->xtd)
    {
        /* Received frame with Extended ID - set MSB to '1' */
        canIdentifier = ((uint32)elem->id | CAN_MSG_ID_TYPE_EXT);
    }
    else
    {
        /* Received frame with Standard ID */
        canIdentifier = (((uint32)elem->id >> CAN_STD_MSGID_SHIFT) & CAN_STD_MSGID_MASK);
    }
    /* Set CAN-FD bit (30th bit) to '1' if CAN-FD frame is
    received */
    canIdentifier = (canIdentifier | ((uint32)elem->fdf << ((uint32)30U)));

    return canIdentifier;
}

/*
 *Design: MCAL-28445
 */
static FUNC(Std_ReturnType, CAN_CODE)
    Can_BitPos(VAR(uint8, AUTOMATIC) buffNum, P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;
    VAR(uint32, AUTOMATIC) status         = (uint32)0U;
    VAR(uint32, AUTOMATIC) bitPos         = (uint32)0U;

    if (buffNum < (MCAN_RX_MB_NDAT_NUM))
    {
        status = newDataStatus->statusLow;
        bitPos = (((uint32)1U) << buffNum);
    }
    else
    {
        status = newDataStatus->statusHigh;
        bitPos = (((uint32)1U) << (buffNum - MCAN_RX_MB_NDAT_NUM));
    }

    if (bitPos == (status & bitPos))
    {
        retval = E_OK;
    }
    else
    {
        /*Do Nothing*/
    }

    return retval;
}

/*
 *Design: MCAL-28446
 */
static FUNC(void, CAN_CODE) Can_CopyPayloadToSdu(VAR(uint8, AUTOMATIC) canDataLength,
                                                 P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                                                 P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem)
{
    VAR(uint32, AUTOMATIC) byteCnt = (uint32)0U;

    for (byteCnt = ((uint32)0U); byteCnt < ((uint32)canDataLength); byteCnt++)
    {
        controllerObj->canSduPtr[byteCnt] = (uint8)elem->data[byteCnt];
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Can_Priv.c
 *********************************************************************************************************************/
