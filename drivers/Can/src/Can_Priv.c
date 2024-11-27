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
 #include "Os.h"
 #if (CAN_CFG_DEM_ENABLE == STD_ON)
 #include "Dem.h"
 #endif
 #include "CanIf_Cbk.h"
 #include "Mcal_Lib.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CAN_INVALID_BASE_ADDR                                     (0x00000000U)

/**
 * \brief  Mask and shift for Tx Buffers elements.
 */
#define MCANSS_TX_BUFFER_ELEM_ID_SHIFT                            (0U)
#define MCANSS_TX_BUFFER_ELEM_ID_MASK                             (0x1FFFFFFFU)
#define MCANSS_TX_BUFFER_ELEM_RTR_SHIFT                           (29U)
#define MCANSS_TX_BUFFER_ELEM_RTR_MASK                            (0x20000000U)
#define MCANSS_TX_BUFFER_ELEM_XTD_SHIFT                           (30U)
#define MCANSS_TX_BUFFER_ELEM_XTD_MASK                            (0x40000000U)
#define MCANSS_TX_BUFFER_ELEM_ESI_SHIFT                           (31U)
#define MCANSS_TX_BUFFER_ELEM_ESI_MASK                            (0x80000000U)
#define MCANSS_TX_BUFFER_ELEM_DLC_SHIFT                           (16U)
#define MCANSS_TX_BUFFER_ELEM_DLC_MASK                            (0x000F0000U)
#define MCANSS_TX_BUFFER_ELEM_BRS_SHIFT                           (20U)
#define MCANSS_TX_BUFFER_ELEM_BRS_MASK                            (0x00100000U)
#define MCANSS_TX_BUFFER_ELEM_FDF_SHIFT                           (21U)
#define MCANSS_TX_BUFFER_ELEM_FDF_MASK                            (0x00200000U)
#define MCANSS_TX_BUFFER_ELEM_EFC_SHIFT                           (23U)
#define MCANSS_TX_BUFFER_ELEM_EFC_MASK                            (0x00800000U)
#define MCANSS_TX_BUFFER_ELEM_MM_SHIFT                            (24U)
#define MCANSS_TX_BUFFER_ELEM_MM_MASK                             (0xFF000000U)

/**
 * \brief  Mask and shift for Rx Buffers elements.
 */
#define MCANSS_RX_BUFFER_ELEM_ID_SHIFT                           (0U)
#define MCANSS_RX_BUFFER_ELEM_ID_MASK                            (0x1FFFFFFFU)
#define MCANSS_RX_BUFFER_ELEM_RTR_SHIFT                          (29U)
#define MCANSS_RX_BUFFER_ELEM_RTR_MASK                           (0x20000000U)
#define MCANSS_RX_BUFFER_ELEM_XTD_SHIFT                          (30U)
#define MCANSS_RX_BUFFER_ELEM_XTD_MASK                           (0x40000000U)
#define MCANSS_RX_BUFFER_ELEM_ESI_SHIFT                          (31U)
#define MCANSS_RX_BUFFER_ELEM_ESI_MASK                           (0x80000000U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT                         (0U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_MASK                          (0x0000FFFFU)
#define MCANSS_RX_BUFFER_ELEM_DLC_SHIFT                          (16U)
#define MCANSS_RX_BUFFER_ELEM_DLC_MASK                           (0x000F0000U)
#define MCANSS_RX_BUFFER_ELEM_BRS_SHIFT                          (20U)
#define MCANSS_RX_BUFFER_ELEM_BRS_MASK                           (0x00100000U)
#define MCANSS_RX_BUFFER_ELEM_FDF_SHIFT                          (21U)
#define MCANSS_RX_BUFFER_ELEM_FDF_MASK                           (0x00200000U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT                         (24U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_MASK                          (0x7F000000U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT                         (31U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_MASK                          (0x80000000U)

/**
 * \brief  Macro for Interrupt Line enable mask.
 */
#define MCANSS_INTR_LINE_EN_MASK   ((MCAN_ILE_EINT0_MASK | MCAN_ILE_EINT1_MASK))


/**
 * \brief  Macro for Interrupt Line select mask for 0.
 */
#define MCANSS_INTR_LINE_0_MASK   (( MCAN_ILS_ARAL_MASK | \
                                     MCAN_ILS_PEDL_MASK | \
                                     MCAN_ILS_PEAL_MASK | \
                                     MCAN_ILS_WDIL_MASK | \
                                     MCAN_ILS_BOL_MASK))


/**
 * \brief  Macro for Interrupt Line select mask for 1.
 */
#define MCANSS_INTR_LINE_1_MASK   (( MCAN_ILS_EWL_MASK | \
                                     MCAN_ILS_EPL_MASK | \
                                     MCAN_ILS_ELOL_MASK | \
                                     MCAN_ILS_BEUL_MASK | \
                                     MCAN_ILS_BECL_MASK | \
                                     MCAN_ILS_DRXL_MASK | \
                                     MCAN_ILS_TOOL_MASK | \
                                     MCAN_ILS_MRAFL_MASK | \
                                     MCAN_ILS_TSWL_MASK | \
                                     MCAN_ILS_TEFLL_MASK | \
                                     MCAN_ILS_TEFFL_MASK | \
                                     MCAN_ILS_TEFWL_MASK | \
                                     MCAN_ILS_TEFNL_MASK | \
                                     MCAN_ILS_TFEL_MASK | \
                                     MCAN_ILS_TCFL_MASK | \
                                     MCAN_ILS_TCL_MASK | \
                                     MCAN_ILS_HPML_MASK | \
                                     MCAN_ILS_RF1LL_MASK | \
                                     MCAN_ILS_RF1FL_MASK | \
                                     MCAN_ILS_RF1WL_MASK | \
                                     MCAN_ILS_RF1NL_MASK | \
                                     MCAN_ILS_RF0LL_MASK | \
                                     MCAN_ILS_RF0FL_MASK | \
                                     MCAN_ILS_RF0WL_MASK | \
                                     MCAN_ILS_RF0NL_MASK))

/**
 * \brief  Macro for standard Message ID filter.
 */
#define MCANSS_STD_ID_FILTER_SIZE_WORDS                          (1U)

/**
 * \brief  Macro for extended Message ID filter.
 */
#define MCANSS_EXT_ID_FILTER_SIZE_WORDS                          (2U)

/**
 * \brief  Mask and shift for Standard Message ID Filter Elements.
 */
#define MCANSS_STD_ID_FILTER_SFID2_SHIFT                         (0U)
#define MCANSS_STD_ID_FILTER_SFID2_MASK                          (0x000003FFU)
#define MCANSS_STD_ID_FILTER_SFID1_SHIFT                         (16U)
#define MCANSS_STD_ID_FILTER_SFID1_MASK                          (0x03FF0000U)
#define MCANSS_STD_ID_FILTER_SFEC_SHIFT                          (27U)
#define MCANSS_STD_ID_FILTER_SFEC_MASK                           (0x38000000U)
#define MCANSS_STD_ID_FILTER_SFT_SHIFT                           (30U)
#define MCANSS_STD_ID_FILTER_SFT_MASK                            (0xC0000000U)

/**
 * \brief  Extended Message ID Filter Element.
 */
#define MCANSS_EXT_ID_FILTER_EFID2_SHIFT                        (0U)
#define MCANSS_EXT_ID_FILTER_EFID2_MASK                         (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFID1_SHIFT                        (0U)
#define MCANSS_EXT_ID_FILTER_EFID1_MASK                         (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFEC_SHIFT                         (29U)
#define MCANSS_EXT_ID_FILTER_EFEC_MASK                          (0xE0000000U)
#define MCANSS_EXT_ID_FILTER_EFT_SHIFT                          (30U)
#define MCANSS_EXT_ID_FILTER_EFT_MASK                           (0xC0000000U)

/**
 * \brief  Macro for Message RAM config.
 */
#define MCAN_MSGRAM_RX_FIFO_0                                   (0x1U)
#define MCAN_MSGRAM_CLASSIC_FILTER                              (0x2U)



#define MAX_UINT32   (0xFFFFFFFFU)
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
static CONST(uint8, CAN_CONST) Can_DataSize[16] = {0U, 1U, 2U, 3U,
                                                   4U, 5U, 6U, 7U,
                                                   8U, 12U, 16U, 20U,
                                                   24U, 32U, 48U, 64U};
/** \brief Can hardware object size lookup table. */
static CONST(uint8, CAN_CONST) Can_ObjSize[8] = {4U, 5U, 6U, 7U,
                                                 8U, 10U, 14U, 18U};
#define CAN_STOP_SEC_CONST_8
#include "Can_MemMap.h"


/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief This function will enable MCAN interrupts as per config.
 * 
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_EnableInterruptPriv(uint32 baseAddr, uint32 interruptMask, boolean enable);

/** \brief This function will select MCAN interrupt lines as per config.
 * 
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_SelectInterruptLinePriv(uint32 baseAddr, uint32 interruptMask);


/** \brief This function will enable MCAN interrupt lines as per config.
 * 
 * \param[in] configParam Pointer to CAN Controller config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_EnableInterruptLinePriv(uint32 baseAddr, boolean enable);

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
static Std_ReturnType Can_CheckControllerConfigPriv(const Can_ConfigType *ConfigPtr);
#endif

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
static Std_ReturnType Can_CheckMbConfigPriv(const Can_ConfigType *ConfigPtr);
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
static void Can_WaitForMemoryInitPriv(uint32 baseAddr);

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
static Can_ControllerOperationMode Can_GetOpModePriv(uint32 baseAddr);

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
static void Can_SetOpModePriv(uint32 baseAddr, Can_ControllerOperationMode cntrMode);

/** \brief This function will get Clock Stop Acknowledgment for Can module.
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return Clock Stop Acknowledgment of Can Hw Unit.
 * \retval CAN_CLOCK_STOP_NO_ACK - No clock stop acknowledged
 * \retval CAN_CLOCK_STOP_ACK -    MCAN may be set in power down 
 *
*****************************************************************************/
static Can_ClockStopAckMode Can_GetClkStopAckPriv(uint32 baseAddr);


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
static void Can_InitHwPriv(uint32 baseAddr, const Can_ControllerType *configParam);

/** \brief This API will unblock write access to write protected registers.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_WriteProtectedRegUnlockPriv(uint32 baseAddr);

/** \brief This API will block write access to write protected registers.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_WriteProtectedRegLockPriv(uint32 baseAddr);

/** \brief This API will configure Different sections of Message RAM.
 *
 * \param[in] canController Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] maxMbCnt Maximum number of Mailbox to be configured.
 * \param[in] canHtrhMbMap Pointer to Htrh to mailbox mapping.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_SetupMsgRamPriv(Can_ControllerObjType* canController, \
                        const Can_MailboxObjType* canMailbox, uint8 maxMbCnt, uint8* canHtrhMbMap);

/** \brief This API will initialize Message RAM.
 *
 * \param[in] msgRamConfig Message RAM Configuration parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_MsgRamConfigInitPriv(Can_FdMsgRAMConfigObjType *msgRamConfig);

/** \brief This API will configure setup Message RAM as per config.
 *
 * \param[in] msgRamConfig Message RAM Configuration parameters.
 * \param[in] mailboxCfg Mailbox Configuration parameters.
 * \param[in] htrh Handle ID of HTH.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_SetupRxMailboxPriv(Can_FdMsgRAMConfigObjType* msgRamConfig, const Can_MailboxType* mailboxCfg);

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
static void Can_SetupTxMailboxPriv(Can_FdMsgRAMConfigObjType* msgRamConfig, \
                               const Can_MailboxType* mailboxCfg, \
                               const Can_ControllerType* canControllerCfg, \
                               uint8 htrh, \
                               uint32 baseAddr);

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
static void Can_MsgRamConfigPriv(uint32 baseAddr, \
                             Can_FdMsgRAMConfigObjType *canFDMsgRamConfig);

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
static void Can_HwMsgRamConfigPriv(uint32 baseAddr, \
                               const Can_MsgRAMConfigParams *msgRAMConfigParams);

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
static void Can_AddStdMsgIDFilterPriv(uint32 baseAddr, \
                                  uint32 filtNum, \
                                  const Can_StdMsgIDFilterElement *elem);

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
static void Can_AddExtMsgIDFilterPriv(uint32 baseAddr, \
                                  uint32 filtNum, \
                                  const Can_ExtMsgIDFilterElement *elem);

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
static void Can_LoopbackModePriv(uint32 baseAddr, boolean loopbackMode);

/** \brief This function will get appropriate interrpt mask based on config.
 *
 * \param[in] configParam Pointer to CAN Controller config parameters. 
 * \pre None
 * \post None
 * \return Interrupt Mask to be used.
 * \retval returns the value of the type uint32.
 *
****************************************************************************/
static uint32 Can_GetInterruptMaskPriv(const Can_ControllerType *configParam);

/** \brief This API is used to add Clock Stop Request.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] enable Clock Stop requested if it is TRUE, No Clock Stop is requested if it is FALSE.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_AddClkStopRequestPriv(uint32 baseAddr, boolean enable);

/** \brief This API will cancel all pending transmit messages.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_CancelPendingMsgPriv(uint32 baseAddr);

/** \brief This API will read status of Transmit Buffers.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return Value of Transmit Buffer status register MCAN_TXBRP.
 * \retval returns the value of the type uint32.
 *
*****************************************************************************/
static uint32 Can_GetTxBufReqPendPriv(uint32 baseAddr);

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
static void Can_TxBufCancelReqPriv(uint32 baseAddr, uint32 buffNum);

/** \brief This API will read status of Transmit Buffers Cancel request.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return Value of Transmit Cancellation status register MCAN_TXBCF.
 * \retval returns the value of the type uint32.
 *
 *****************************************************************************/
static uint32 Can_TxBufCancelStatusPriv(uint32 baseAddr);

/** \brief This API will read Transmission status of Transmit Buffers.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \pre None
 * \post None
 * \return Value of Transmit status for Tx buffers register MCAN_TXBTO.
 * \retval returns the value of the type uint32.
 *
 *****************************************************************************/
static uint32 Can_GetTxBufTransStatusPriv(uint32 baseAddr);

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
static void Can_TxBufAddReqPriv(uint32 baseAddr, uint32 buffNum);

/** \brief This API will update data in the Message RAM.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \param[in] buffNum Transmit Buffer number.
 * \param[in] elem Pointer to the data to be written in Message RAM.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_WriteMsgRamPriv(uint32 baseAddr, uint32 bufNum, const Can_TxBufElementType *elem);

/** \brief This API will read data from Rx Buffer of CAN Hw Unit.
 *
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] maxMbCnt Maximum number of Mailbox to be configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_ReadRxBuffPriv(Can_ControllerObjType *controllerObj, \
                               const Can_MailboxObjType *canMailbox, \
                               uint8 maxMbCnt);

/** \brief This API will read data from Rx FIFO of CAN Hw Unit.
 *
 * \param[in] controllerObj Pointer to Can controller config parameters.
 * \param[in] canMailbox Message RAM Configuration parameters.
 * \param[in] maxMbCnt Maximum number of Mailbox to be configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_ReadRxFIFOPriv(Can_ControllerObjType *controllerObj, \
                               const Can_MailboxObjType *canMailbox, \
                               uint8 maxMbCnt);

/** \brief This API will configure Tx and Rx FIFOs, Buffers
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] msgRAMConfigParams Populated structure for MCAN Message RAM Configuration parameters
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_HwMsgRamConfigPriv(uint32 baseAddr, \
                               const Can_MsgRAMConfigParams *msgRAMConfigParams);

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
static void Can_ReadMsgRamPriv(uint32 baseAddr, \
                           uint32 memType, \
                           uint32 bufNum, \
                           Can_RxBufElementType *elem);

/** \brief This API will return the status of the current interrupts
 *
 * \param[in] baseAddr Base Address of controller.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static uint32 Can_GetIntrStatus(uint32 baseAddr);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/** \brief This function will validate the icom configuration critiria based on rx message configs.
 * 
 * \param[in] can_identifier Identifier to validate.
 * \param[in] sduptr Pointer to received data.
 * \param[in] icom_config_id current icom configuration id.
 * \pre None
 * \post None
 * \return The status of whether the icom configuration critiria matched or not
 * \retval E_OK - If icom configuration matched.
 * \retval E_NOT_OK - If icom configuration not matched.
 *
 *****************************************************************************/
static Std_ReturnType Can_ValidateIcomConfigCriteriaPriv(uint32 can_identifier,const uint8* sduptr, uint8 icom_config_id, \
                                        P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_COST) canController);
#endif

/** \brief This function will clear pending CAN interrupts.
 * 
 * \param[in] baseAddr Base Address of the MCAN Registers.
 * \param[in] intrMask Mask for interrupts to be cleared.
 * \pre Can module must be initialized
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_ClearIntrStatusPriv(uint32 baseAddr, uint32 intrMask, uint32 lineSelect);


/** \brief This API will clear new Rx data status for Can Hw Unit.
 *
 * \param[in] baseAddr Base Address of controller. 
 * \param[in] newDataStatus Bits to be cleared.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_ClearNewDataStatusPriv(uint32 baseAddr, \
                            Can_RxNewDataStatusType newDataStatus);


/** \brief This API will read status of Rx FIFO.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] fifoStatus Pointer to location to store value read.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_GetRxFIFOStatusPriv(uint32 baseAddr, \
                         Can_RxFIFOStatusType *fifoStatus);


/** \brief This API will write acknowledgment for read of Rx FIFO.
 *
 * \param[in] baseAddr Base Address of controller.
 * \param[in] idx FIFO element ID.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static void Can_WriteRxFIFOAckPriv(uint32 baseAddr, \
                        uint32 idx);


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
static void Can_GetNewDataStatusPriv(uint32 baseAddr, \
                          Can_RxNewDataStatusType *newDataStatus);




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
Can_CheckInitDetPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC)returnStatus = E_NOT_OK;

    if(NULL_PTR != ConfigPtr)
    {
        returnStatus = Can_CheckControllerConfigPriv(ConfigPtr);

        if ((Std_ReturnType) E_OK == returnStatus)
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
    VAR(uint32, AUTOMATIC)controllerIndx;
    VAR(uint32, AUTOMATIC)mbIndx;
    VAR(uint32, AUTOMATIC)loopIndx;

    for (controllerIndx = ((uint32)0U); controllerIndx < (uint32)KMAX_CONTROLLER;
            controllerIndx++)
    {
        drvObj->canController[controllerIndx].canState = CAN_CS_UNINIT;
        drvObj->canController[controllerIndx].canBaud = ((uint16)0U);
        drvObj->canController[controllerIndx].canBusOffRecoveryStatus = FALSE;
        drvObj->canController[controllerIndx].canInterruptCounter = ((uint8)0U);

        for (mbIndx = ((uint32)0U); mbIndx < (uint32)KMAX_MB_PER_CONTROLLER; mbIndx++)
        {
            drvObj->canController[controllerIndx].canTxStatus[mbIndx] =
                ((uint8)0U);
        }

        for (mbIndx = ((uint32)0U); mbIndx < (uint32)CAN_FD_PAYLOAD_MAX_BYTES; mbIndx++)
        {
            drvObj->canController[controllerIndx].canSduPtr[mbIndx] = ((uint8)0U);
        }
    }

    for (mbIndx = ((uint32)0U); mbIndx < (uint32)KMAX_MAILBOXES; mbIndx++)
    {
        for (loopIndx = ((uint32)0U);
            loopIndx < (uint32)KMAX_MB_PER_CONTROLLER;
            loopIndx++)
        {
            drvObj->canMailbox[mbIndx].canTxRxPduId[loopIndx] =
                ((PduIdType)0U);
        }
    }
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    for (loopIndx = ((uint32)0U); loopIndx < (uint32)MAX_ICOM_CONFIGURATION;
            loopIndx++)
    {
        drvObj->Can_IcomActivation[loopIndx] = FALSE;
    }
#endif
}

/*
 *Design: MCAL-23023
 */
FUNC(void, CAN_CODE) 
Can_InitDrvObjPriv(P2VAR(Can_DriverObjType, AUTOMATIC, CAN_APPL_DATA) drvObj,
                    P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC)controllerIndx;
    VAR(uint32, AUTOMATIC)mbIndx;
    VAR(uint32, AUTOMATIC)controller;
    #if (CAN_CFG_ICOM_SUPPORT == STD_ON)
        VAR(uint32, AUTOMATIC)IcomIndex;
    #endif

    for (controllerIndx = ((uint32)0U); controllerIndx < (uint32)KMAX_CONTROLLER;
            controllerIndx++)
    {
        drvObj->canController[controllerIndx].canControllerConfig = *ConfigPtr->CanControllerList[controllerIndx];

        drvObj->canController[controllerIndx].MaxBaudConfigID =
            ConfigPtr->MaxBaudConfigID[controllerIndx];

        drvObj->controllerIDMap[ConfigPtr->CanControllerList[controllerIndx]
                                    ->CanControllerInstance] = controllerIndx;
    }
    drvObj->maxTxMbCnt = 0U;
    drvObj->maxRxMbCnt = 0U;
    for (mbIndx = ((uint32)0U); mbIndx < (uint32)KMAX_MAILBOXES; mbIndx++)
    {
        drvObj->canMailbox[mbIndx].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
        controller = ConfigPtr->MailBoxList[mbIndx]->CanControllerRef->CanControllerId;
        /* Poll only for Active Controllers */
        if (TRUE == drvObj->canController[controller].canControllerConfig.CanControllerActivation)
        {

            /* Poll only for Tx Mailbox */
            if(TRANSMIT == ConfigPtr->MailBoxList[mbIndx]->CanObjectType)
            {
             
                if ((Can_ProcessingType) POLLING == 
                drvObj->canController[controller].canControllerConfig.CanTxProcessing)
                {
                    drvObj->canTxMailbox[drvObj->maxTxMbCnt].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
                    drvObj->maxTxMbCnt = drvObj->maxTxMbCnt + 1U;
                }
                else if ((Can_ProcessingType) MIXED == 
                drvObj->canController[controller].canControllerConfig.CanTxProcessing)
                {
                    
                    if (TRUE == ConfigPtr->MailBoxList[mbIndx]->CanHardwareObjectUsesPolling)
                    {
                        drvObj->canTxMailbox[drvObj->maxTxMbCnt].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
                        drvObj->maxTxMbCnt = drvObj->maxTxMbCnt + 1U;
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
            else
            {
                if ((Can_ProcessingType) POLLING == 
                drvObj->canController[controller].canControllerConfig.CanRxProcessing)
                {
                    drvObj->canRxMailbox[drvObj->maxRxMbCnt].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
                    drvObj->maxRxMbCnt = drvObj->maxRxMbCnt + 1U;
                }
                else if ((Can_ProcessingType) MIXED == 
                drvObj->canController[controller].canControllerConfig.CanRxProcessing)
                {
                    
                    if (TRUE == ConfigPtr->MailBoxList[mbIndx]->CanHardwareObjectUsesPolling)
                    {
                        drvObj->canRxMailbox[drvObj->maxRxMbCnt].mailBoxConfig = *ConfigPtr->MailBoxList[mbIndx];
                        drvObj->maxRxMbCnt = drvObj->maxRxMbCnt + 1U;
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
        }
        else
        {
            /* Do Nothing */
        }
    }
    drvObj->canMaxControllerCount = ConfigPtr->CanMaxControllerCount;
    drvObj->maxMbCnt = ConfigPtr->MaxMbCnt;
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
    for (IcomIndex = ((uint32)0U); IcomIndex < (uint32)MAX_ICOM_CONFIGURATION;
            IcomIndex++)
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
Can_HwUnitConfigPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController ,
                      P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox ,
                      uint8 maxMbCnt,
                      P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) canHtrhMbMap)
{
    VAR(uint32, AUTOMATIC)canCntBaseAddr = canController->canControllerConfig.CanControllerBaseAddress;

    /* Wait for Memory Initialization to happen */
    Can_WaitForMemoryInitPriv(canCntBaseAddr);
    
    /* Put MCAN in SW initialization mode */
    Can_SetOpModePriv(canCntBaseAddr, (Can_ControllerOperationMode) CAN_CONTROLLER_OPERATION_MODE_SW_INIT);

    Can_WriteProtectedRegUnlockPriv(canCntBaseAddr);

    /* Initialize MCAN HW Module */
    Can_InitHwPriv(canCntBaseAddr, &(canController->canControllerConfig));  

    /* Configure Message RAM sections */
    Can_SetupMsgRamPriv(canController, canMailbox, maxMbCnt, canHtrhMbMap);

    /* Configure Loopback mode */
    Can_LoopbackModePriv(canCntBaseAddr, canController->canControllerConfig.CanConfigParam.CanLoopbackMode);
    
    Can_WriteProtectedRegLockPriv(canCntBaseAddr);

    /* Configure Bit Timings */
    (void)Can_HWSetBaudRatePriv(canCntBaseAddr, canController->canControllerConfig.CanControllerDefaultBaudrate);

    /* Configure MCAN interrupts enabled in config */
    Can_EnableInterruptsPriv(&canController->canControllerConfig);
}
 
/*
 *Design: MCAL-23024
 */
FUNC(Std_ReturnType, CAN_CODE) 
Can_HWSetBaudRatePriv(uint32 baseAddr, 
                P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_COST) baudConfig )
{
    VAR(uint16, AUTOMATIC)brp = (uint16)0U;
    VAR(uint8, AUTOMATIC)seg1 = (uint8)0U;
    VAR(uint8, AUTOMATIC)seg2 = (uint8)0U;
    VAR(uint8, AUTOMATIC)sjw = (uint8)0U;

    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;

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

    if ((((uint8)MCAN_NBTP_NSJW_MAX) >= sjw) &&
        (((uint8)MCAN_NBTP_NTSEG2_MAX) >= seg2) &&
        (((uint8)MCAN_NBTP_NTSEG1_MAX) >= seg1) &&
        (((uint16)MCAN_NBTP_NBRP_MAX) >= brp))
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_NBTP,
                            MCAN_NBTP_NSJW,
                            sjw);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_NBTP,
                            MCAN_NBTP_NTSEG2,
                            seg2);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_NBTP,
                            MCAN_NBTP_NTSEG1,
                            seg1);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_NBTP,
                            MCAN_NBTP_NBRP,
                            brp);

        returnValue = E_OK;
    }
    else
    {
        returnValue = E_NOT_OK;
    }

    if((E_OK == returnValue) && (TRUE == baudConfig->BaudFdEnable))
    {
        if (baudConfig->BaudFdRateConfig.BrpValue > 0U)
        {
            brp = baudConfig->BaudFdRateConfig.BrpValue - (uint16)1U;
        }
        else
        {
            /* Do nothing */
        }
        if ((((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg
                       + baudConfig->BaudFdRateConfig.CanControllerSeg1)) > 0U) && 
                       (((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg
                       + baudConfig->BaudFdRateConfig.CanControllerSeg1)) < 255U))
        {
            seg1 = ((uint8)(baudConfig->BaudFdRateConfig.CanControllerPropSeg + 
                   baudConfig->BaudFdRateConfig.CanControllerSeg1)) - ((uint8)1U);
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

        if ((((uint8)MCAN_DBTP_DSJW_MAX) >= sjw) &&
            (((uint8)MCAN_DBTP_DTSEG2_MAX) >= seg2) &&
            (((uint8)MCAN_DBTP_DTSEG1_MAX) >= seg1) &&
            (((uint16)MCAN_DBTP_DBRP_MAX) >= brp))
        {
            CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                            MCAN_DBTP_DSJW,
                            sjw);
            CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                            MCAN_DBTP_DTSEG2,
                            seg2);
            CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                            MCAN_DBTP_DTSEG1,
                            seg1);
            CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                            MCAN_DBTP_DBRP,
                            brp);

            returnValue = E_OK;
        }
        else
        {
            returnValue = E_NOT_OK;
        }
        if((((boolean )TRUE) == baudConfig->BaudFdRateConfig.TxDelayCompEnable) && (E_OK == returnValue))
        {
            if((((uint8)CAN_TDCR_TDCF_MAX) >= baudConfig->BaudFdRateConfig.TxDelayCompFilter) &&
                (((uint8)CAN_TDCR_TDCO_MAX) >= baudConfig->BaudFdRateConfig.CanControllerTrcvDelayCompensationOffset))
            {
                /* Configure Transceiver Delay Compensation */
                CAN_REG_MF_WRITE32(baseAddr + MCAN_TDCR,
                                    MCAN_TDCR_TDCF,
                                    baudConfig->BaudFdRateConfig.TxDelayCompFilter);

                CAN_REG_MF_WRITE32(baseAddr + MCAN_TDCR,
                                    MCAN_TDCR_TDCO,
                                    baudConfig->BaudFdRateConfig.CanControllerTrcvDelayCompensationOffset);

                CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                                    MCAN_DBTP_TDC,
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
    else
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_DBTP,
                    MCAN_DBTP_TDC,
                    baudConfig->BaudFdRateConfig.TxDelayCompEnable);
    }
    
    
    Can_WriteProtectedRegLockPriv(baseAddr);

    return returnValue;
}

/*
 *Design: MCAL-24213
 */
FUNC(void, CAN_CODE) 
Can_DisableInterruptsPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam)
{
    VAR(uint32, AUTOMATIC)interruptMask = (uint32)0U;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;


    baseAddr = configParam->CanControllerBaseAddress;
    interruptMask = Can_GetInterruptMaskPriv(configParam);

    if(((uint32)0U != interruptMask) && (TRUE == configParam->CanControllerActivation))
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
Can_EnableInterruptsPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam)
{
    VAR(uint32, AUTOMATIC)interruptMask = (uint32)0U;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;

    baseAddr = configParam->CanControllerBaseAddress;
    interruptMask = Can_GetInterruptMaskPriv(configParam);

    if(((uint32)0U != interruptMask) && (TRUE == configParam->CanControllerActivation))
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
Can_HwDeInitPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;

    baseAddr = configParam->CanControllerBaseAddress;

    /* Disable all Interrupts */
    Can_DisableInterruptsPriv(configParam);

    /* Clear Interrupt Status */
    Can_ClearIntrStatusPriv(baseAddr, (uint32)CAN_INTR_MASK_ALL, MCAN_INT_LINE_0);
    Can_ClearIntrStatusPriv(baseAddr, (uint32)CAN_INTR_MASK_ALL, MCAN_INT_LINE_1);
}


/*
 *Design: MCAL-23027
 */
FUNC(Can_ErrorStateType, CAN_CODE) 
Can_GetProtocolStatusPriv(P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_COST) canController)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC)returnValue = CAN_ERRORSTATE_ACTIVE;

    baseAddr = canController->canControllerConfig.CanControllerBaseAddress;
    regVal = CAN_REG_READ32(baseAddr + MCAN_PSR);

    if((uint32)1U == CAN_FIELD_GET(regVal, MCAN_PSR_BO))
    {
        returnValue = CAN_ERRORSTATE_BUSOFF;
    }
    else if((uint32)1U == CAN_FIELD_GET(regVal, MCAN_PSR_EP))
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
Can_HWCheckWakeupPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam )
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(Can_ControllerOperationMode, AUTOMATIC)initStatus;
    VAR(Can_ClockStopAckMode, AUTOMATIC)csa;

    initStatus = Can_GetOpModePriv(configParam->CanControllerBaseAddress);
    csa = Can_GetClkStopAckPriv(configParam->CanControllerBaseAddress);

    if((CAN_CONTROLLER_OPERATION_MODE_SW_INIT == initStatus) && 
        (CAN_CLOCK_STOP_ACK == csa))
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
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) Can_CanIfIndication )
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC)protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Put Can in operational mode */
    Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode) CAN_CONTROLLER_OPERATION_MODE_NORMAL);

    /* Can is started, report to CanIf */
    controllerObj->canState = CAN_CS_STARTED;
    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STARTED);

    /* Check if there is a bus off */
    protStatus = Can_GetProtocolStatusPriv(controllerObj);
    if(CAN_ERRORSTATE_BUSOFF == protStatus)
    {
        controllerObj->canBusOffRecoveryStatus = TRUE;
    }
    else
    {
        /* Do Nothing */
    }

    returnValue = E_OK;
    Can_CanIfIndication->stopIndication = TRUE;

    return returnValue;
}

/*
 *Design: MCAL-23030
 */
FUNC(void, CAN_CODE) 
Can_HwUnitStopPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) Can_CanIfIndication )
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Put Can in SW initilization mode */
    Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode) CAN_CONTROLLER_OPERATION_MODE_SW_INIT);

    /* Wait for Can to reach correct operational mode */
    
    /* Cancel pending messages */
    Can_CancelPendingMsgPriv(baseAddr);

    /* Can is stopped, report to CanIf */
    controllerObj->canState = CAN_CS_STOPPED;
    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
    Can_CanIfIndication->stopIndication = TRUE;
}

/*
 *Design: MCAL-23031
 */
FUNC(Std_ReturnType, CAN_CODE) 
Can_HwUnitSleepPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) Can_CanIfIndication )
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(Os_TickType, AUTOMATIC)startCount = (Os_TickType)0U;
    VAR(Os_TickType, AUTOMATIC)elapsedCount = (Os_TickType)0U;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(boolean, AUTOMATIC)timeout = FALSE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Put Can in Power Down mode */
    Can_AddClkStopRequestPriv(baseAddr, TRUE);

    (void)Os_GetCounterValue(CAN_CFG_OS_COUNTER_ID, &startCount);
    /* Wait for Can to reach correct operational mode */
    do
    {
        (void)Os_GetElapsedValue(CAN_CFG_OS_COUNTER_ID,
                                &startCount,
                                &elapsedCount);

        if (CAN_CFG_TIMEOUT_DURATION <= elapsedCount)
        {
            timeout = TRUE;
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    } while (CAN_CLOCK_STOP_ACK != Can_GetClkStopAckPriv(baseAddr));

    if(FALSE == timeout)
    {
        /* Can is in sleep, report to CanIf */
        controllerObj->canState = CAN_CS_SLEEP;
        CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_SLEEP);
        controllerObj->canBusOffRecoveryStatus = FALSE;
        returnValue = E_OK;
        Can_CanIfIndication->sleepIndication = TRUE;
    }
    else
    {
        /*  Timeout */
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
        Can_CanIfIndication->sleepIndication = FALSE;
    }

    return returnValue;
}

/*
 *Design: MCAL-23032
 */
FUNC(Std_ReturnType, CAN_CODE) 
Can_HwUnitWakeupPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) Can_CanIfIndication)
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(Os_TickType, AUTOMATIC)startCount = (Os_TickType)0U;
    VAR(Os_TickType, AUTOMATIC)elapsedCount = (Os_TickType)0U;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(boolean, AUTOMATIC)timeout = FALSE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Deactivate Local Power Down */
    Can_AddClkStopRequestPriv(baseAddr, FALSE);

    (void)Os_GetCounterValue(CAN_CFG_OS_COUNTER_ID, &startCount);

    do
    {
        (void)Os_GetElapsedValue(CAN_CFG_OS_COUNTER_ID,
                                &startCount,
                                &elapsedCount);

        if (CAN_CFG_TIMEOUT_DURATION <= elapsedCount)
        {
            timeout = TRUE;
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    } while (CAN_CLOCK_STOP_NO_ACK != Can_GetClkStopAckPriv(baseAddr));

    if(FALSE == timeout)
    {
        /* Can is stopped, report to CanIf */
        controllerObj->canState = CAN_CS_STOPPED;
        CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
        returnValue = E_OK;
        Can_CanIfIndication->stopIndication = TRUE;
    }
    else
    {
        /*  Timeout */
        Can_CanIfIndication->stopIndication = FALSE; 
#if (CAN_CFG_DEM_ENABLE == STD_ON)
        (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
    }

    return returnValue;
}

/*
 *Design: MCAL-24217
 */
FUNC(Std_ReturnType, CAN_CODE) 
Can_GetFreeTxMsgObjPriv(P2CONST(Can_MailboxType, AUTOMATIC, CAN_COST) mailboxCfg,
                       P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_COST) canController,
                       P2VAR(Can_HwHandleType, AUTOMATIC, CAN_APPL_DATA) msgObj,
                       uint8 htrh)
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;
    VAR(uint8, AUTOMATIC)canTxStatus = (uint8)0U;
    VAR(uint32, AUTOMATIC)bitIndex = (uint32)0U;
    
    baseAddr = mailboxCfg->CanControllerRef->CanControllerBaseAddress;

    if(((uint16)1U) < mailboxCfg->CanHwObjectCount)
    {
        loopCnt = ((uint8)canController->canFDMsgRamConfig.txBuffNum);

        for(; ((loopCnt < (uint8)(canController->canFDMsgRamConfig.txFIFONum + 
            canController->canFDMsgRamConfig.txBuffNum)) && (loopCnt < KMAX_MB_PER_CONTROLLER)); loopCnt++)
        {
            canTxStatus = canController->canTxStatus[loopCnt];
            bitIndex = ((uint32)1U << loopCnt);
            /*- Check for pending message:
            *     - pending message, return CAN_BUSY
            *     - no pending message, start new transmission
            */
            if(bitIndex == (Can_GetTxBufReqPendPriv(baseAddr) & bitIndex))
            {
                returnValue = (Std_ReturnType)CAN_BUSY;
            }
            else if(((uint8)1U == canTxStatus) &&
                    (FALSE == canController->canControllerConfig.CanConfigParam.CanDisableAutomaticRetransmission))
            {
                returnValue = (Std_ReturnType)CAN_BUSY;
            }
            else
            {
                *msgObj = (Can_HwHandleType )loopCnt;
                returnValue = E_OK;
                break;
            }
        }

    }
    else
    {
        for(loopCnt = ((uint8)0U); ((loopCnt < ((uint8)(canController->canFDMsgRamConfig.txBuffNum))) 
            && (loopCnt < (uint8)64U)); loopCnt++)
        {
            if(htrh == canController->canFDMsgRamConfig.txMbMapping[0U][loopCnt])
            {
                break;
            }
            else
            {
                /* Do Nothing */
            }
        }

        if((loopCnt < (uint8)(canController->canFDMsgRamConfig.txBuffNum)) && (loopCnt < KMAX_MB_PER_CONTROLLER))
        {
            canTxStatus = canController->canTxStatus[loopCnt];
            bitIndex = ((uint32)1U << loopCnt);
            /*- Check for pending message:
            *     - pending message, return CAN_BUSY
            *     - no pending message, start new transmission
            */
            if(bitIndex == (Can_GetTxBufReqPendPriv(baseAddr) & bitIndex))
            {
                returnValue = (Std_ReturnType)CAN_BUSY;
            }
            else if((((uint8)1U) == canTxStatus) &&
                    (FALSE == canController->canControllerConfig.CanConfigParam.CanDisableAutomaticRetransmission))
            {
                returnValue = (Std_ReturnType)CAN_BUSY;
            }
            else
            {
                *msgObj = (Can_HwHandleType )loopCnt;
                returnValue = E_OK;
            }
        }
        else
        {
            returnValue = E_NOT_OK;
        }
    }

    return returnValue;
}

/*
 *Design: MCAL-24218
 */
FUNC(void, CAN_CODE) 
Can_WriteTxMailboxPriv(P2CONST(Can_MailboxType, AUTOMATIC, CAN_COST) mailboxCfg,
                    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                    uint8 hth,
                    uint32 messageBox,
                    P2CONST(Can_PduType, AUTOMATIC, CAN_COST) pduInfo)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;
    VAR(Can_TxBufElementType, AUTOMATIC)elem = {0U};

    baseAddr = mailboxCfg->CanControllerRef->CanControllerBaseAddress;

    if(CAN_MSG_TYPE_CLASSIC_CAN == ((pduInfo->id) & (CAN_MSG_TYPE_MASK)))
    {
        /* Classic CAN */
        elem.brs = ((boolean )0U);
        elem.fdf = ((boolean )0U);
    }
    else
    {
        /* CAN FD */
        elem.brs = ((boolean )1U);
        elem.fdf = ((boolean )1U);
    }

    if(CAN_ID_MIXED == mailboxCfg->CanIdType)
    {
        /* Mixed ID */
        if(CAN_MSG_ID_TYPE_EXT == (pduInfo->id & CAN_MSG_ID_TYPE_EXT))
        
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

    if(((uint8)CAN_ID_XTD) == elem.xtd)
    {
        /* Extended ID */
        elem.id = pduInfo->id & CAN_XTD_MSGID_MASK;
    }
    else
    {
        /* Standard ID */
        elem.id = (pduInfo->id & CAN_STD_MSGID_MASK) << CAN_STD_MSGID_SHIFT;
    }

    /* Copy payload into message element */
    for (loopCnt = ((uint8)0U); loopCnt < pduInfo->length; loopCnt++)
    {
        elem.data[loopCnt] = pduInfo->sdu[loopCnt];
    }

    /* Add padding value to unused to data in payload */
    for (loopCnt = pduInfo->length; loopCnt < ((uint8)CAN_FD_PAYLOAD_MAX_BYTES); loopCnt++)
    {
        elem.data[loopCnt] = mailboxCfg->CanFdPaddingValue;
    }

    /* Find standard data length */
    for (loopCnt = ((uint8)0U); loopCnt < ((uint8)16U); loopCnt++)
    {
        if(pduInfo->length <= Can_DataSize[loopCnt])
        {
            elem.dataLength = ((uint32)loopCnt);
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
    
    if(((uint16)1U) < mailboxCfg->CanHwObjectCount)
    {
        elem.memType = CAN_MEM_TYPE_FIFO;
    }
    else
    {
        elem.memType = CAN_MEM_TYPE_BUF;
    }

    controllerObj->canFDMsgRamConfig.hthToMbMapping[messageBox] = hth;

    Can_WriteMsgRamPriv(baseAddr, messageBox, &elem);
    
    Can_TxBufAddReqPriv(baseAddr, messageBox);

}

/*
 *Design: MCAL-24219
 */
FUNC(void, CAN_CODE) 
Can_HwUnitTxDonePollingPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                         P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox,
                         uint8 htrh)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)buffNum = (uint32)0U;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)bitPos = (uint32)0U;
    VAR(uint32, AUTOMATIC)txStatus = (uint32)0U;

    baseAddr = canController->canControllerConfig.CanControllerBaseAddress;

    if(((uint16)1U) < canMailbox->mailBoxConfig.CanHwObjectCount)
    {
        loopCnt = (uint32)(canController->canFDMsgRamConfig.txBuffNum);
        buffNum = ((uint32)(((uint32)canController->canFDMsgRamConfig.txBuffNum) + 
            ((uint32)canController->canFDMsgRamConfig.txFIFONum)));

        for (; loopCnt < buffNum; loopCnt++)
        {
            if(htrh == canController->canFDMsgRamConfig.hthToMbMapping[loopCnt])
            {
                bitPos = ((uint32)1U << loopCnt);
                txStatus = Can_GetTxBufTransStatusPriv(baseAddr);

                if((((uint8)1U) == canController->canTxStatus[loopCnt]) &&
                (bitPos == (txStatus & bitPos)))
                {
                    /* Call Tx Confirmation */
                    CanIf_TxConfirmation(canMailbox->canTxRxPduId[loopCnt]);
                    /* Clear the status as data is already sent */
                    canController->canTxStatus[loopCnt] = ((uint8)0U);
                }
                else
                {
                /*  Do Nothing */
                }
            }
            else
            {
                /*  Do Nothing */
            }
        }
        
    }
    else
    {
        loopCnt = ((uint32)canMailbox->mailBoxConfig.HwHandle);
        bitPos = ((uint32)1U << loopCnt);
        txStatus = Can_GetTxBufTransStatusPriv(baseAddr);

        if ((((uint8)1U) == canController->canTxStatus[loopCnt]) &&
            (bitPos == (txStatus & bitPos)))
        {
            /* Call Tx Confirmation */
            CanIf_TxConfirmation(canMailbox->canTxRxPduId[loopCnt]);
            /* Clear the status as data is already sent */
            canController->canTxStatus[loopCnt] = ((uint8)0U);
        }
        else
        {
            /*  Do Nothing */
        }
    }
}

/*
 *Design: MCAL-24220
 */
FUNC(void, CAN_CODE) 
Can_ReadRxMailboxPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                   P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox,
                   uint8 maxMbCnt)
{
    /* Read Messages stored in buffers */
    Can_ReadRxBuffPriv(controllerObj, canMailbox,maxMbCnt);

    /* Read messages stored in Rx FIFO */
    Can_ReadRxFIFOPriv(controllerObj,canMailbox,maxMbCnt);
}

/*
 *Design: MCAL-23033
 */
FUNC(void, CAN_CODE) 
Can_BusOffProcessPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(Can_ControllerOperationMode, AUTOMATIC)initStatus;
    VAR(Can_ErrorStateType, AUTOMATIC)protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;
    initStatus = Can_GetOpModePriv(baseAddr);
    protStatus = Can_GetProtocolStatusPriv(controllerObj);

    if((CAN_ERRORSTATE_BUSOFF == protStatus) &&
        (CAN_CONTROLLER_OPERATION_MODE_SW_INIT == initStatus))
    {
        /* Check if recovery has already started */
        if(TRUE != controllerObj->canBusOffRecoveryStatus)
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
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(Can_ControllerOperationMode, AUTOMATIC)initStatus;
    VAR(Can_ClockStopAckMode, AUTOMATIC)csa;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;
    initStatus = Can_GetOpModePriv(baseAddr);
    csa = Can_GetClkStopAckPriv(baseAddr);

    if((CAN_CONTROLLER_OPERATION_MODE_SW_INIT == initStatus) &&
        (CAN_CLOCK_STOP_ACK == csa))
    {
        /* Still Sleeping */
    }
    else
    {
        /* Call the Wakeup indicationtoCanIf function */
        if(CAN_CS_SLEEP == controllerObj->canState)
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
                    P2VAR(Can_CanIfIndicationType, AUTOMATIC, CAN_APPL_DATA) indication )
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(Can_ErrorStateType, AUTOMATIC)protStatus = CAN_ERRORSTATE_ACTIVE;

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;
    
    switch (controllerObj->canState)
    {
        case CAN_CS_STARTED:
            /* If BusOff recovery sequence has started, check if CAN controller is started.
            * If not restart CAN controller */
            if (TRUE == controllerObj->canBusOffRecoveryStatus)
            {
                /* Restart CAN controller */
                Can_SetOpModePriv(baseAddr, (Can_ControllerOperationMode) CAN_CONTROLLER_OPERATION_MODE_NORMAL);
                protStatus = Can_GetProtocolStatusPriv(controllerObj);

                if(CAN_ERRORSTATE_BUSOFF == protStatus)
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
            if(CAN_CONTROLLER_OPERATION_MODE_SW_INIT == Can_GetOpModePriv(baseAddr))
            {
                if (FALSE == indication->stopIndication)
                {
                    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_STOPPED);
                    indication->stopIndication = TRUE;
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
            break;

        case CAN_CS_SLEEP:
            if(CAN_CLOCK_STOP_ACK == Can_GetClkStopAckPriv(baseAddr))
            {
                if (FALSE == indication->sleepIndication)
                {
                    CanIf_ControllerModeIndication(controllerObj->canControllerConfig.CanControllerId, CAN_CS_SLEEP);
                    indication->sleepIndication = TRUE;
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
            break;

        default:
            break;
    }
}

/*
 *Design: MCAL-24221, MCAL-22876, MCAL-22878, MCAL-22874, MCAL-22912, MCAL-22850, MCAL-22879
 */
FUNC(void, CAN_CODE) 
Can_ProcessISR(Can_ControllerInstance canInstance,uint32 lineSelect)
{
    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController = NULL_PTR;
    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox = NULL_PTR;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)intrStatus = (uint32)0U;
    VAR(uint32, AUTOMATIC)txStatus = (uint32)0U;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)bitPos = (uint32)0U;
    VAR(uint8, AUTOMATIC)hth = (uint8)0U;

    if(NULL_PTR != Can_DriverObjPtr)
    {
        canController = &(Can_DriverObjPtr->canController[Can_DriverObjPtr->controllerIDMap[canInstance]]);
        canMailbox = &(Can_DriverObjPtr->canMailbox[0U]);
        baseAddr = canController->canControllerConfig.CanControllerBaseAddress;
        intrStatus = Can_GetIntrStatus(baseAddr);
        Can_ClearIntrStatusPriv(baseAddr, intrStatus, lineSelect);
        
        /* Process bus off interrupts*/
        if(MCAN_IR_BO_MASK == (intrStatus & MCAN_IR_BO_MASK))
        {
            Can_CancelPendingMsgPriv(baseAddr);
            /* BusOff Recovery sequence has not started */
            canController->canState = CAN_CS_STOPPED;
            /*Call the bus off indicationtoCanIf function*/
            CanIf_ControllerBusOff(canController->canControllerConfig.CanControllerId);
        }
        else
        {
            /* Do Nothing */
        }
#ifdef CAN_DEV_ERROR_DETECT
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        if ((uint32)MCAN_IR_RF0L_MASK ==
            (intrStatus & (uint32)MCAN_IR_RF0L_MASK))
        {
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                                CAN_SID_PROCESSISR,
                                CAN_E_DATALOST);
        }
#endif
#endif

        /* Process Tx interrupts*/
        if(MCAN_IR_TC_MASK == (intrStatus & MCAN_IR_TC_MASK))
        {
                txStatus = Can_GetTxBufTransStatusPriv(baseAddr);

            /* Check only Tx buffers */
            for (loopCnt = ((uint32)0U); loopCnt < MCAN_TX_MB_MAX_NUM; loopCnt++)
            {
                bitPos = ((uint32)1U << bitPos);

                if(bitPos == (txStatus & bitPos))
                {
                    hth = canController->canFDMsgRamConfig.hthToMbMapping[loopCnt];

                    if ((TRANSMIT == canMailbox[hth].mailBoxConfig.CanObjectType) &&
                        (((uint8)1U) == canController->canTxStatus[loopCnt]))
                    {
                        /* Call Tx Confirmation */
                        CanIf_TxConfirmation(canMailbox->canTxRxPduId[loopCnt]);
                        /* Clear the status as data is already sent */
                        canController->canTxStatus[loopCnt] = ((uint8)0U);
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
            
        }
        else
        {
            /* Do Nothing */
        }

        /* Process Rx interrupts*/
        if (((uint32)MCAN_IR_RF0N_MASK ==
            (intrStatus & (uint32)MCAN_IR_RF0N_MASK)) ||
            ((uint32)MCAN_IR_DRX_MASK ==
            (intrStatus & (uint32)MCAN_IR_DRX_MASK)))
        {
            Can_ReadRxBuffPriv(canController, canMailbox, Can_DriverObjPtr->maxMbCnt);

            Can_ReadRxFIFOPriv(canController, canMailbox, Can_DriverObjPtr->maxMbCnt);
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


/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*
 *Design: MCAL-24238
 */
static FUNC(void, CAN_CODE) 
Can_ReadMsgRamPriv(uint32 baseAddr,
               uint32 memType,
               uint32 bufNum,
               P2VAR(Can_RxBufElementType, AUTOMATIC, CAN_APPL_DATA) elem)
{
    VAR(uint32, AUTOMATIC)startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemSize = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)idx = (uint32)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;

    if(((uint32)CAN_MEM_TYPE_BUF) == memType)
    {
        startAddr = CAN_REG_MF_READ32((baseAddr + MCAN_RXBC), MCAN_RXBC_RBSA);
        elemSize = CAN_REG_MF_READ32((baseAddr + MCAN_RXESC), MCAN_RXESC_RBDS);
        idx = bufNum;
    } 
    else
    {
        startAddr = CAN_REG_MF_READ32((baseAddr + MCAN_RXF0C), MCAN_RXF0C_F0SA);
        elemSize = CAN_REG_MF_READ32((baseAddr + MCAN_RXESC), MCAN_RXESC_F0DS);
        idx = CAN_REG_MF_READ32((baseAddr + MCAN_RXF0S), MCAN_RXF0S_F0GI);
    }

    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemSize = ((uint32)Can_ObjSize[elemSize]);
    elemSize *= ((uint32)4U);
    elemAddr = startAddr + (elemSize * idx);

    regVal = CAN_REG_READ32(baseAddr + elemAddr);
    elem->id = (uint32)CAN_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_ID);
    elem->xtd = (uint8)CAN_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_XTD);

    elemAddr += ((uint32)4U);
    regVal = CAN_REG_READ32(baseAddr + elemAddr);
    elem->brs = (boolean)CAN_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_BRS);
    elem->dataLength = (uint32)CAN_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_DLC);
    elem->fdf = (boolean)CAN_FIELD_GET(regVal, MCANSS_RX_BUFFER_ELEM_FDF);

    elemAddr += ((uint32)4U);
    loopCnt = ((uint32)0U);
    /* Reading words from message RAM and forming payload bytes out of it */
    while ((4U <= (((uint32)Can_DataSize[elem->dataLength]) - loopCnt)) &&
            (0U != (((uint32)Can_DataSize[elem->dataLength]) - loopCnt)))
    {
        if((loopCnt + (uint8)3U) < (uint8)64U)
        {
            regVal = CAN_REG_READ32(baseAddr + elemAddr);
            elem->data[(loopCnt + ((uint32)0U))] = (uint8)(regVal & ((uint32)0x000000FFU));
            elem->data[(loopCnt + ((uint32)1U))] = (uint8)((regVal & ((uint32)0x0000FF00U)) >> 8U);
            elem->data[(loopCnt + ((uint32)2U))] = (uint8)((regVal & ((uint32)0x00FF0000U)) >> 16U);
            elem->data[(loopCnt + ((uint32)3U))] = (uint8)((regVal & ((uint32)0xFF000000U)) >> 24U);
            elemAddr += ((uint32)4U);
            loopCnt += ((uint32)4U);
        }
    }
    
    /* Reading remaining bytes from message RAM */
    if(0U < (((uint32)Can_DataSize[elem->dataLength]) - loopCnt))
    {
        regVal = CAN_REG_READ32(baseAddr + elemAddr);
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
static FUNC(Std_ReturnType, CAN_CODE)
Can_CheckControllerConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC)returnStatus = E_OK;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)cnt = (uint32)0U;

    for (loopCnt = 0U; loopCnt < KMAX_CONTROLLER; loopCnt++)
    {
        if (NULL_PTR == ConfigPtr->CanControllerList[loopCnt])
        {
            returnStatus = (Std_ReturnType) E_NOT_OK;
        }
        else if (NULL_PTR == ConfigPtr->CanControllerList[loopCnt]->CanControllerDefaultBaudrate)
        {
            returnStatus = (Std_ReturnType) E_NOT_OK;
        }
        else if (CAN_INVALID_BASE_ADDR ==
                ConfigPtr->CanControllerList[loopCnt]->CanControllerBaseAddress)
        {
            returnStatus = (Std_ReturnType) E_NOT_OK;
        }
        else
        {
            for (cnt = 0U; cnt <= ConfigPtr->MaxBaudConfigID[loopCnt]; cnt++)
            {
                if (NULL_PTR ==
                    ConfigPtr->CanControllerList[loopCnt]->BaudRateConfigList[cnt])
                {
                returnStatus = (Std_ReturnType) E_NOT_OK;
                }
            }
        }

        if (returnStatus == (Std_ReturnType) E_NOT_OK)
        {
            break;
        }
    }

    return returnStatus;
}
#endif

#if (CAN_CFG_DEV_ERROR_DETECT == STD_ON)

/*
 *Design: MCAL-23037
 */
static FUNC(Std_ReturnType, CAN_CODE) 
Can_CheckMbConfigPriv(P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC)returnStatus = E_OK;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;

    for (loopCnt = 0U; loopCnt < KMAX_MAILBOXES; loopCnt++)
    {
        if (NULL_PTR == ConfigPtr->MailBoxList[loopCnt])
        {
            returnStatus = (Std_ReturnType) E_NOT_OK;
        }
        else if (NULL_PTR == ConfigPtr->MailBoxList[loopCnt]->CanControllerRef)
        {
            returnStatus = (Std_ReturnType) E_NOT_OK;
        }
        else
        {
            /*Do Nothing*/
        }

        if (returnStatus == (Std_ReturnType) E_NOT_OK)
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
static FUNC(void, CAN_CODE) 
Can_WaitForMemoryInitPriv(uint32 baseAddr)
{
    VAR(uint32, AUTOMATIC)elapsedCount = (uint32 )0;
    
    do
    {
        McalLib_Delay(1);
        elapsedCount += (uint32)15U; 

        if(CAN_CFG_TIMEOUT_DURATION_CYCLES <= elapsedCount)
        {
#if (CAN_CFG_DEM_ENABLE == STD_ON)
            (void)Dem_SetEventStatus(
                    CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
            break;
        }
        else
        {
            /* Do Nothing */
        }
    } while ((uint32)1U != CAN_REG_MF_READ32((baseAddr + MCAN_MCANSS_STAT), MCAN_MCANSS_STAT_MEM_INIT_DONE));
}

/*
 *Design: MCAL-23038
 */
static FUNC(Can_ControllerOperationMode, CAN_CODE) 
Can_GetOpModePriv(uint32 baseAddr)
{
    VAR(Can_ControllerOperationMode, AUTOMATIC)controllerMode;
    
    if((uint32)1U == (CAN_REG_MF_READ32((baseAddr + MCAN_CCCR),MCAN_CCCR_INIT)))
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
static FUNC(void, CAN_CODE) 
Can_SetOpModePriv(uint32 baseAddr, 
            Can_ControllerOperationMode cntrMode)
{
    CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_INIT, cntrMode);
}

/*
 *Design: MCAL-23040
 */
static FUNC(Can_ClockStopAckMode, CAN_CODE) 
Can_GetClkStopAckPriv(uint32 baseAddr)
{
        VAR(Can_ClockStopAckMode, AUTOMATIC)clockStopAck;
    
    if((uint32)1U == (CAN_REG_MF_READ32((baseAddr + MCAN_CCCR),MCAN_CCCR_CSA)))
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
Can_InitHwPriv(uint32 baseAddr, 
        P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam)
{
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    /* Configure MCAN wakeup */
    regVal = CAN_REG_READ32(baseAddr + MCAN_MCANSS_CTRL);

    CAN_FIELD_SET32(regVal,
                    MCAN_MCANSS_CTRL_WAKEUPREQEN,
                    configParam->CanWakeupSupport);
    CAN_FIELD_SET32(regVal,
                    MCAN_MCANSS_CTRL_AUTOWAKEUP,
                    configParam->CanWakeupSupport);

    CAN_REG_WRITE32(baseAddr + MCAN_MCANSS_CTRL, regVal);

    

    /* Configure MCAN mode(FD vs Classic CAN operation) and controls */
    regVal = CAN_REG_READ32(baseAddr + MCAN_CCCR);

    CAN_FIELD_SET32(regVal,
                    MCAN_CCCR_FDOE,
                    configParam->CanConfigParam.CanFDMode);
    CAN_FIELD_SET32(regVal,
                    MCAN_CCCR_BRSE,
                    configParam->CanControllerDefaultBaudrate->BaudFdRateConfig.CanControllerTxBitRateSwitch);
    CAN_FIELD_SET32(regVal,
                    MCAN_CCCR_TXP,
                    configParam->CanConfigParam.CanTransmitPause);
    CAN_FIELD_SET32(regVal,
                    MCAN_CCCR_PXHD,   /* Protocol Exception Handling Disable */
                    (uint32)0U);
    CAN_FIELD_SET32(regVal,
                    MCAN_CCCR_DAR,
                    configParam->CanConfigParam.CanDisableAutomaticRetransmission);

    CAN_REG_WRITE32(baseAddr + MCAN_CCCR, regVal);

    /* Configure Global Filter */
        CAN_REG_MF_WRITE32(baseAddr + MCAN_GFC,
                        MCAN_GFC_RRFE,
                        (uint32)1U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_GFC,
                        MCAN_GFC_RRFS,
                        (uint32)1U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_GFC,
                        MCAN_GFC_ANFE,
                        (uint32)2U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_GFC,
                        MCAN_GFC_ANFS,
                        (uint32)2U);
}

/*
 *Design: MCAL-24224
 */
static FUNC(void, CAN_CODE) 
Can_WriteProtectedRegUnlockPriv(uint32 baseAddr)
{
    CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_CCE, 0x1U);
}

/*
 *Design: MCAL-24225
 */
static FUNC(void, CAN_CODE) 
Can_WriteProtectedRegLockPriv(uint32 baseAddr)
{
    CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR, MCAN_CCCR_CCE, 0x0U);
}

/*
 *Design: MCAL-23042
 */
static FUNC(void, CAN_CODE) 
Can_SetupMsgRamPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) canController,
                    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox,
                    uint8 maxMbCnt,
                    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) canHtrhMbMap)
{
    VAR(uint8, AUTOMATIC)htrh = (uint8)0U;
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint8, AUTOMATIC)controller = (uint8)0U;
    P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) canControllerCfg = NULL_PTR;
    P2CONST(Can_MailboxType, AUTOMATIC, CAN_COST) mailboxCfg = NULL_PTR;
    P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) mailboxCfgList = NULL_PTR;
    P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig = NULL_PTR;


    controller = canController->canControllerConfig.CanControllerId;
    canControllerCfg = &canController->canControllerConfig;
    mailboxCfgList = &canMailbox[0U];
    baseAddr = canControllerCfg->CanControllerBaseAddress;
    msgRamConfig = &canController->canFDMsgRamConfig;

    Can_MsgRamConfigInitPriv(msgRamConfig);

    /* Initialize Message RAM parameters according to configured mailboxes */
    for (htrh = ((uint8)0U); htrh < maxMbCnt; htrh++)
    {
        mailboxCfg = &mailboxCfgList[htrh].mailBoxConfig;

        if(controller == mailboxCfg->CanControllerRef->CanControllerId)
        {
            if(RECEIVE == mailboxCfg->CanObjectType)
            {
                Can_SetupRxMailboxPriv(msgRamConfig,
                                mailboxCfg);
            }
            else
            {
                Can_SetupTxMailboxPriv(msgRamConfig,
                                mailboxCfg,
                                canControllerCfg,
                                htrh,
                                baseAddr);

                canHtrhMbMap[mailboxCfg->CanObjectId] = htrh;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }

    msgRamConfig->configParams.lss = (uint32)msgRamConfig->stdFilterNum;
    msgRamConfig->configParams.lse = (uint32)msgRamConfig->extFilterNum;

    /* Configure Message RAM Sections :
    *  STD/EXT filters, Tx Buffers/FIFO and Rx Buffers/FIFO */
    Can_MsgRamConfigPriv(baseAddr, msgRamConfig);
}

/*
 *Design: MCAL-23043
 */
static FUNC(void, CAN_CODE) 
Can_MsgRamConfigInitPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig)
{
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;

    msgRamConfig->stdFilterNum = ((uint8)0U);
    msgRamConfig->extFilterNum = ((uint8)0U);

    /* Initialize Message RAM configuration parameters */
    msgRamConfig->configParams.flssa = ((uint32)0U);
    msgRamConfig->configParams.lss = ((uint32)0U);
    msgRamConfig->configParams.flesa = ((uint32)0U);
    msgRamConfig->configParams.lse = ((uint32)0U);
    msgRamConfig->configParams.txStartAddr = ((uint32)0U);
    msgRamConfig->configParams.txBufNum = ((uint32)0U);
    msgRamConfig->configParams.txFIFOSize = ((uint32)0U);
    msgRamConfig->configParams.txBufMode = ((uint32)1U);
    msgRamConfig->configParams.txBufElemSize = (uint32)CAN_ELEM_SIZE_64BYTES;
    msgRamConfig->configParams.txEventFIFOStartAddr = ((uint32)0U);
    msgRamConfig->configParams.txEventFIFOSize = ((uint32)0U);
    msgRamConfig->configParams.txEventFIFOWaterMark = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0startAddr = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0size = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0waterMark = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO0OpMode = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1startAddr = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1size = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1waterMark = ((uint32)0U);
    msgRamConfig->configParams.rxFIFO1OpMode = ((uint32)0U);
    msgRamConfig->configParams.rxBufStartAddr = ((uint32)0U);
    msgRamConfig->configParams.rxBufElemSize = (uint32)CAN_ELEM_SIZE_64BYTES;
    msgRamConfig->configParams.rxFIFO0ElemSize = (uint32)CAN_ELEM_SIZE_64BYTES;
    msgRamConfig->configParams.rxFIFO1ElemSize = ((uint32)0U);

    msgRamConfig->txBuffNum = ((uint16)0U);
    msgRamConfig->txFIFONum = ((uint16)0U);
    msgRamConfig->rxBuffNum = ((uint16)0U);
    msgRamConfig->rxFIFONum = ((uint16)0U);

    for (loopCnt = ((uint32)0U); loopCnt < KMAX_MB_PER_CONTROLLER; loopCnt++)
    {
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfid1 = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfid2 = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sfec = ((uint32)0U);
        msgRamConfig->stdMsgIDFilterList[loopCnt].sft = ((uint32)0x3U);
        msgRamConfig->extMsgIDFilterList[loopCnt].efid1 = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].efid2 = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].efec = ((uint32)0U);
        msgRamConfig->extMsgIDFilterList[loopCnt].eft = ((uint32)0x3U);
        msgRamConfig->txMbMapping[0U][loopCnt] = ((uint8)0xFFU);
        msgRamConfig->txMbMapping[1U][loopCnt] = ((uint8)0xFFU);
        msgRamConfig->hthToMbMapping[loopCnt] = ((uint8)0xFFU);
    }
}


/*
 *Design: MCAL-23044
 */
static FUNC(void, CAN_CODE) 
Can_SetupRxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                    P2CONST(Can_MailboxType, AUTOMATIC, CAN_COST) mailboxCfg)
{
    VAR(uint8, AUTOMATIC)idx = (uint8)0U;

    if(((uint16)1U) < mailboxCfg->CanHwObjectCount)
    {
        /* Get Filter Mask for HRH - STD */
        if((uint32)CAN_ID_STD == mailboxCfg->CanIdType)
        {
            idx = msgRamConfig->stdFilterNum;

            msgRamConfig->stdMsgIDFilterList[idx].sfid1 = (mailboxCfg->CanHwFilterCode & CAN_STD_MSGID_MASK);
            msgRamConfig->stdMsgIDFilterList[idx].sfid2 = (mailboxCfg->CanHwFilterMask.MaskValue & CAN_STD_MSGID_MASK);

            /* Store the message in Rx FIFO 0 */
            msgRamConfig->stdMsgIDFilterList[idx].sfec = MCAN_MSGRAM_RX_FIFO_0;

            /* Classic Filter - Bit Mask */
            msgRamConfig->stdMsgIDFilterList[idx].sft = MCAN_MSGRAM_CLASSIC_FILTER;

            msgRamConfig->stdFilterNum++;
        }
        /* Get Filter Mask for HRH - EXT */
        else
        {
            idx = msgRamConfig->extFilterNum;

            msgRamConfig->extMsgIDFilterList[idx].efid1 = (mailboxCfg->CanHwFilterCode & CAN_XTD_MSGID_MASK);
            msgRamConfig->extMsgIDFilterList[idx].efid2 = (mailboxCfg->CanHwFilterMask.MaskValue & CAN_XTD_MSGID_MASK);

            /* Store the message in Rx FIFO 0 */
            msgRamConfig->extMsgIDFilterList[idx].efec = MCAN_MSGRAM_RX_FIFO_0;

            /* Classic Filter - Bit Mask */
            msgRamConfig->extMsgIDFilterList[idx].eft = MCAN_MSGRAM_CLASSIC_FILTER;

            msgRamConfig->extFilterNum++;
        }

        /* Set Mailbox Entry */
        msgRamConfig->rxFIFONum += ((uint16)1U);
        msgRamConfig->configParams.rxFIFO0size += (uint32)mailboxCfg->CanHwObjectCount;
    }
    else
    {
        /* Get Filter Mask for HRH - STD */
        if((uint32)CAN_ID_STD == mailboxCfg->CanIdType)
        {
            idx = msgRamConfig->stdFilterNum;

            msgRamConfig->stdMsgIDFilterList[idx].sfid1 = (mailboxCfg->CanHwFilterCode & CAN_STD_MSGID_MASK);
            msgRamConfig->stdMsgIDFilterList[idx].sfid2 = (uint32)msgRamConfig->rxBuffNum;

            /* Store the message in Rx Buffer */
            msgRamConfig->stdMsgIDFilterList[idx].sfec = ((uint32)0x7U);

            /* No filter can be set for Rx Buffer */
            msgRamConfig->stdMsgIDFilterList[idx].sft = ((uint32)0x0U);

            msgRamConfig->stdFilterNum++;
        }
        /* Get Filter Mask for HRH - EXT */
        else
        {
            idx = msgRamConfig->extFilterNum;

            msgRamConfig->extMsgIDFilterList[idx].efid1 = (mailboxCfg->CanHwFilterCode & CAN_XTD_MSGID_MASK);
            msgRamConfig->extMsgIDFilterList[idx].efid2 = (uint32)msgRamConfig->rxBuffNum;

            /* Store the message in Rx FIFO 0 */
            msgRamConfig->extMsgIDFilterList[idx].efec = ((uint32)0x7U);

            /* No filter can be set for Rx Buffer */
            msgRamConfig->extMsgIDFilterList[idx].eft = ((uint32)0x0U);

            msgRamConfig->extFilterNum++;
        }

        /* Set Mailbox Entry */
        msgRamConfig->rxBuffNum += ((uint16)1U);
    }
}

/*
 *Design: MCAL-24226
 */
static FUNC(void, CAN_CODE) 
Can_SetupTxMailboxPriv(P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) msgRamConfig,
                       P2CONST(Can_MailboxType, AUTOMATIC, CAN_COST) mailboxCfg ,
                       P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) canControllerCfg ,
                       uint8 htrh,
                       uint32 baseAddr)
{
    VAR(uint32, AUTOMATIC)intrCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    if(((uint16)1U) < mailboxCfg->CanHwObjectCount)
    {
        /* Set Mailbox Entry */
        msgRamConfig->txMbMapping[1U][mailboxCfg->HwHandle] = htrh;
        msgRamConfig->txFIFONum += mailboxCfg->CanHwObjectCount;
        msgRamConfig->configParams.txFIFOSize += (uint32)mailboxCfg->CanHwObjectCount;

        /* Prepare Transmission Interrupt Enable Mask */
        for (intrCnt = ((uint32)0U); intrCnt < ((uint32)mailboxCfg->CanHwObjectCount); intrCnt++)
        {
            if(INTERRUPT == canControllerCfg->CanTxProcessing)
            {
                regVal  = CAN_REG_READ32(baseAddr + MCAN_TXBTIE);
                regVal |= (((uint32) 1U) << (((uint32)mailboxCfg->HwHandle) + ((uint32)intrCnt)));
                CAN_REG_WRITE32(baseAddr + MCAN_TXBTIE, regVal);
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    else
    {
        /* Set Mailbox Entry */
        msgRamConfig->txMbMapping[0U][mailboxCfg->HwHandle] = htrh;
        msgRamConfig->txBuffNum += ((uint16)1U);
        msgRamConfig->configParams.txBufNum++;

        /* Prepare Transmission Interrupt Enable Mask */
        if(INTERRUPT == canControllerCfg->CanTxProcessing)
        {
            regVal = CAN_REG_READ32(baseAddr + MCAN_TXBTIE);
            regVal |= ((uint32)1U << (mailboxCfg->HwHandle));
            CAN_REG_WRITE32(baseAddr + MCAN_TXBTIE, regVal);
        }
        else
        {
            /* Do Nothing */
        }
    }
}

/*
 *Design: MCAL-24227
 */
static FUNC(void, CAN_CODE) 
Can_MsgRamConfigPriv(uint32 baseAddr,
                 P2VAR(Can_FdMsgRAMConfigObjType, AUTOMATIC, CAN_APPL_DATA) canFDMsgRamConfig)
{
    VAR(uint32, AUTOMATIC)startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)txMbNum = (uint32)0U;

    txMbNum = ((uint32)canFDMsgRamConfig->txBuffNum + (uint32)canFDMsgRamConfig->txFIFONum);

    if ((MCAN_TX_BUFFER_MAX_NUM >= txMbNum) &&
        (((uint16)MCAN_RX_FIFO_0_MAX_NUM) >= canFDMsgRamConfig->rxBuffNum) &&
        (((uint16)MCAN_RX_BUFFER_MAX_NUM) >= canFDMsgRamConfig->rxFIFONum))
    {
        /* Calculate Start Address for Message RAM sections */
        canFDMsgRamConfig->configParams.flssa = ((uint32)0U);

        startAddr += (uint32)(((uint32)canFDMsgRamConfig->stdFilterNum +
                                (uint32)1U) *
                                (uint32)MCAN_MSG_RAM_STD_ELEM_SIZE * 4U);
        canFDMsgRamConfig->configParams.flesa = startAddr;

        startAddr += (uint32)(((uint32)canFDMsgRamConfig->extFilterNum +
                                (uint32)1U) *
                                (uint32)MCAN_MSG_RAM_EXT_ELEM_SIZE * 4U);
        canFDMsgRamConfig->configParams.txStartAddr = startAddr;
        
        startAddr += (uint32)(((uint32)canFDMsgRamConfig->configParams.txBufNum +
                                (uint32)1U) *
                                (uint32)MCAN_MSG_RAM_TX_RX_ELEM_SIZE * 4U);
        startAddr += (uint32)(((uint32)canFDMsgRamConfig->configParams.txFIFOSize +
                                (uint32)1U) *
                                (uint32)MCAN_MSG_RAM_TX_RX_ELEM_SIZE * 4U);
        canFDMsgRamConfig->configParams.rxFIFO0startAddr = startAddr;

        startAddr += (uint32)((canFDMsgRamConfig->configParams.rxFIFO0size + ((uint32)1U))
            * MCAN_MSG_RAM_TX_RX_ELEM_SIZE * 4U);
        canFDMsgRamConfig->configParams.rxBufStartAddr = startAddr;

        /* Configure Message RAM */
        Can_HwMsgRamConfigPriv(baseAddr, &canFDMsgRamConfig->configParams);

        /* Configure Standard ID Filters */
        for (loopCnt = ((uint32)0U); loopCnt < (uint32)canFDMsgRamConfig->stdFilterNum; loopCnt++)
        {
            Can_AddStdMsgIDFilterPriv(baseAddr, loopCnt, &canFDMsgRamConfig->stdMsgIDFilterList[loopCnt]);
        }

        /* Configure Extended ID Filters */
        for (loopCnt = ((uint32)0U); loopCnt < (uint32)canFDMsgRamConfig->extFilterNum; loopCnt++)
        {
            Can_AddExtMsgIDFilterPriv(baseAddr, loopCnt, &canFDMsgRamConfig->extMsgIDFilterList[loopCnt]);
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-24228
 */
static FUNC(void, CAN_CODE) 
Can_HwMsgRamConfigPriv(uint32 baseAddr,
                   P2CONST(Can_MsgRAMConfigParams, AUTOMATIC, CAN_COST) msgRAMConfigParams)
{
    VAR(uint32, AUTOMATIC)elemNum = 0U;

    /* Configure Message Filters section */
    if (((uint32)0U) != msgRAMConfigParams->lss)
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_SIDFC,
                        MCAN_SIDFC_FLSSA,
                        (msgRAMConfigParams->flssa >> ((uint32)2U)));
        CAN_REG_MF_WRITE32(baseAddr + MCAN_SIDFC,
                        MCAN_SIDFC_LSS,
                        msgRAMConfigParams->lss);
    }

    if (((uint32)0U) != msgRAMConfigParams->lse)
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_XIDFC,
                        MCAN_XIDFC_FLESA,
                        (msgRAMConfigParams->flesa >> ((uint32)2U)));
        CAN_REG_MF_WRITE32(baseAddr + MCAN_XIDFC,
                        MCAN_XIDFC_LSE,
                        msgRAMConfigParams->lse);
    }

    /* Configure Rx FIFO 0 section */
    if (((uint32)0U) != msgRAMConfigParams->rxFIFO0size)
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_RXF0C,
                        MCAN_RXF0C_F0SA,
                        (msgRAMConfigParams->rxFIFO0startAddr >> ((uint32)2U)));
        CAN_REG_MF_WRITE32(baseAddr + MCAN_RXF0C,
                        MCAN_RXF0C_F0S,
                        msgRAMConfigParams->rxFIFO0size);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_RXF0C,
                        MCAN_RXF0C_F0WM,
                        msgRAMConfigParams->rxFIFO0waterMark);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_RXF0C,
                        MCAN_RXF0C_F0OM,
                        msgRAMConfigParams->rxFIFO0OpMode);
        /* Configure Rx FIFO0 elements size */
        CAN_REG_MF_WRITE32(baseAddr + MCAN_RXESC,
                        MCAN_RXESC_F0DS,
                        msgRAMConfigParams->rxFIFO0ElemSize);
    }

    /* Configure Rx FIFO 1 section */
    if (((uint32)0U) != msgRAMConfigParams->rxFIFO1size)
    {
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C,
                        MCAN_RXF1C_F1SA,
                        (msgRAMConfigParams->rxFIFO1startAddr >> ((uint32)2U)));
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C,
                        MCAN_RXF1C_F1S,
                        msgRAMConfigParams->rxFIFO1size);
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C,
                        MCAN_RXF1C_F1WM,
                        msgRAMConfigParams->rxFIFO1waterMark);
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_RXF1C,
                        MCAN_RXF1C_F1OM,
                        msgRAMConfigParams->rxFIFO1OpMode);
        /* Configure Rx FIFO1 elements size */
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_RXESC,
                        MCAN_RXESC_F1DS,
                        msgRAMConfigParams->rxFIFO1ElemSize);
    }

    /* Configure Rx Buffer Start Address */
    CAN_REG_MF_WRITE32(baseAddr + MCAN_RXBC,
                    MCAN_RXBC_RBSA,
                    (msgRAMConfigParams->rxBufStartAddr >> ((uint32)2U)));
    /* Configure Rx Buffer elements size */
    CAN_REG_MF_WRITE32(baseAddr + MCAN_RXESC,
                    MCAN_RXESC_RBDS,
                    msgRAMConfigParams->rxBufElemSize);

    /* Configure Tx Event FIFO section */
    if (((uint32)0U) != msgRAMConfigParams->txEventFIFOSize)
    {
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_TXEFC,
                        MCAN_TXEFC_EFSA,
                        (msgRAMConfigParams->txEventFIFOStartAddr >> ((uint32)2U)));
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_TXEFC,
                        MCAN_TXEFC_EFS,
                        msgRAMConfigParams->txEventFIFOSize);
        CAN_REG_MF_WRITE32((baseAddr) + MCAN_TXEFC,
                        MCAN_TXEFC_EFWM,
                        msgRAMConfigParams->txEventFIFOWaterMark);
    }
    
    /* Configure Tx Buffer and FIFO/Q section */
    elemNum = (uint32)((uint32)msgRAMConfigParams->txBufNum + (uint32)msgRAMConfigParams->txFIFOSize);
    
    if ((MCAN_TX_MB_MAX_NUM >= elemNum) &&
        ((((uint32)0U) != msgRAMConfigParams->txBufNum) ||
            (((uint32)0U) != msgRAMConfigParams->txFIFOSize)))
    {
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TXBC,
                        MCAN_TXBC_TBSA,
                        (msgRAMConfigParams->txStartAddr >> ((uint32)2U)));
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TXBC,
                        MCAN_TXBC_NDTB,
                        msgRAMConfigParams->txBufNum);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TXBC,
                        MCAN_TXBC_TFQS,
                        msgRAMConfigParams->txFIFOSize);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TXBC,
                        MCAN_TXBC_TFQM,
                        msgRAMConfigParams->txBufMode);
        /* Configure Tx Buffer/FIFO0/FIFO1 elements size */
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TXESC,
                        MCAN_TXESC_TBDS,
                        msgRAMConfigParams->txBufElemSize);
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-24229
 */
static FUNC(void, CAN_CODE) 
Can_AddStdMsgIDFilterPriv(uint32 baseAddr,
                      uint32 filtNum,
                      P2CONST(Can_StdMsgIDFilterElement, AUTOMATIC, CAN_COST) elem)
{
    VAR(uint32, AUTOMATIC)startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    startAddr = CAN_REG_MF_READ32(baseAddr + MCAN_SIDFC, MCAN_SIDFC_FLSSA);
    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemAddr = startAddr + (filtNum * MCANSS_STD_ID_FILTER_SIZE_WORDS * 4U);

    regVal = ((uint32)0U);
    regVal |= ((uint32)elem->sfid2 << MCANSS_STD_ID_FILTER_SFID2_SHIFT);
    regVal |= ((uint32)elem->sfid1 << MCANSS_STD_ID_FILTER_SFID1_SHIFT);
    regVal |= ((uint32)elem->sfec << MCANSS_STD_ID_FILTER_SFEC_SHIFT);
    regVal |= ((uint32)elem->sft << MCANSS_STD_ID_FILTER_SFT_SHIFT);
    CAN_REG_WRITE32(baseAddr + elemAddr, regVal);
}

/*
 *Design: MCAL-24230
 */
static FUNC(void, CAN_CODE) 
Can_AddExtMsgIDFilterPriv(uint32 baseAddr,
                      uint32 filtNum,
                      P2CONST(Can_ExtMsgIDFilterElement, AUTOMATIC, CAN_COST) elem)
{
    VAR(uint32, AUTOMATIC)startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    startAddr = CAN_REG_MF_READ32(baseAddr + MCAN_XIDFC, MCAN_XIDFC_FLESA);
    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemAddr = startAddr + (filtNum * MCANSS_EXT_ID_FILTER_SIZE_WORDS * 4U);

    regVal = ((uint32)0U);
    regVal |= ((uint32)elem->efid1 << MCANSS_EXT_ID_FILTER_EFID1_SHIFT);
    regVal |= ((uint32)elem->efec << MCANSS_EXT_ID_FILTER_EFEC_SHIFT);
    CAN_REG_WRITE32(baseAddr + elemAddr, regVal);

    elemAddr += ((uint32)4U);
    regVal = ((uint32)0U);
    regVal |= ((uint32)elem->efid2 << MCANSS_EXT_ID_FILTER_EFID2_SHIFT);
    regVal |= ((uint32)elem->eft << MCANSS_EXT_ID_FILTER_EFT_SHIFT);
    CAN_REG_WRITE32(baseAddr + elemAddr, regVal);
}

/*
 *Design: MCAL-23045
 */
static FUNC(void, CAN_CODE) 
Can_LoopbackModePriv(uint32 baseAddr, 
                    boolean loopbackMode)
{

    if((boolean) TRUE == loopbackMode)
    {
        /*  Enable internal loopback mode */
        CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR, 
                            MCAN_CCCR_TEST,
                            0x1U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TEST,
                            MCAN_TEST_LBCK,
                            0x1U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR,
                            MCAN_CCCR_MON,
                            0x0U);
    }
    else
    {
        /*  Disable loopback mode */
        CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR, 
                            MCAN_CCCR_TEST,
                            0x0U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_TEST,
                            MCAN_TEST_LBCK,
                            0x0U);
        CAN_REG_MF_WRITE32(baseAddr + MCAN_CCCR,
                            MCAN_CCCR_MON,
                            0x0U);
    }

}

/*
 *Design: MCAL-23046
 */
static FUNC(uint32, CAN_CODE) 
Can_GetInterruptMaskPriv(P2CONST(Can_ControllerType, AUTOMATIC, CAN_COST) configParam)
{
    VAR(uint32, AUTOMATIC)interruptMask = (uint32)0U;

    if(INTERRUPT == configParam->CanBusoffProcessing)
    {
        interruptMask |= ((uint32)MCAN_IR_BO_MASK);
    }
    else
    {
        /* Do Nothing */
    }

    if(INTERRUPT == configParam->CanRxProcessing)
    {
        interruptMask |= ((uint32) MCAN_IR_RF0N_MASK |\
                            (uint32) MCAN_IR_RF0W_MASK |\
                            (uint32) MCAN_IR_RF0F_MASK |\
                            (uint32) MCAN_IR_RF0L_MASK |\
                            (uint32) MCAN_IR_RF1N_MASK |\
                            (uint32) MCAN_IR_RF1W_MASK |\
                            (uint32) MCAN_IR_RF1F_MASK |\
                            (uint32) MCAN_IR_RF1L_MASK |\
                            (uint32) MCAN_IR_HPM_MASK);
    }
    else
    {
        /* Do Nothing */
    }

    if(INTERRUPT == configParam->CanTxProcessing)
    {
        interruptMask |= ((uint32) MCAN_IR_TFE_MASK |\
                            (uint32) MCAN_IR_TEFN_MASK |\
                            (uint32) MCAN_IR_TEFW_MASK |\
                            (uint32) MCAN_IR_TEFF_MASK |\
                            (uint32) MCAN_IR_TEFL_MASK |\
                            (uint32) MCAN_IR_TC_MASK);
    }
    else
    {
        /* Do Nothing */
    }

    if(INTERRUPT == configParam->CanWakeupProcessing)
    {
        /*  Do Nothing */
    }
    else
    {
        /* Do Nothing */
    }

    return interruptMask;
}

/*
 *Design: MCAL-23047
 */
static FUNC(void, CAN_CODE) 
Can_EnableInterruptPriv(uint32 baseAddr, 
                        uint32 interruptMask, 
                        boolean enable)
{
    VAR(uint32, AUTOMATIC)regVal;
    
    regVal = CAN_REG_READ32(baseAddr + MCAN_IE);
    if (TRUE == enable)
    {
        regVal |= interruptMask;
    }
    else
    {
        regVal &= ~interruptMask;
    }
    CAN_REG_WRITE32(baseAddr + MCAN_IE, regVal);
}

/*
 *Design: MCAL-23048
 */
static FUNC(void, CAN_CODE) 
Can_SelectInterruptLinePriv(uint32 baseAddr, 
                            uint32 interruptMask)
{
    VAR(uint32, AUTOMATIC)regVal;
    
    regVal  = CAN_REG_READ32(baseAddr + MCAN_ILS);
    regVal &= ~(MCANSS_INTR_LINE_0_MASK | interruptMask);
    regVal |= (MCANSS_INTR_LINE_1_MASK | interruptMask);
    CAN_REG_WRITE32(baseAddr + MCAN_ILS, regVal);
}


/*
 *Design: MCAL-23049
 */
static FUNC(void, CAN_CODE) 
Can_EnableInterruptLinePriv(uint32 baseAddr, 
                            boolean enable)
{
    VAR(uint32, AUTOMATIC)regVal;
    
    regVal   = CAN_REG_READ32(baseAddr + MCAN_ILE);
    
    if(enable == TRUE)
    {
        regVal  |=  ((uint32)0x2U);
    }
    else
    {
        regVal  &= ~((uint32) 0x2U);
    }
    CAN_REG_WRITE32(baseAddr + MCAN_ILE, regVal);
}   

/*
 *Design: MCAL-23050
 */
static FUNC(void, CAN_CODE) 
Can_AddClkStopRequestPriv(uint32 baseAddr, 
                        boolean enable)
{
    CAN_REG_MF_WRITE32((baseAddr + MCAN_CCCR), MCAN_CCCR_CSR, enable);
}

/*
 *Design: MCAL-23051
 */
static FUNC(void, CAN_CODE) 
Can_CancelPendingMsgPriv(uint32 baseAddr)
{
    VAR(Os_TickType, AUTOMATIC)startCount = (Os_TickType)0U;
    VAR(Os_TickType, AUTOMATIC)elapsedCount = (Os_TickType)0U;
    VAR(uint32, AUTOMATIC)txBufPendStatus = (uint32)0U;
    VAR(uint32, AUTOMATIC)bitIndex = (uint32)0U;
    VAR(uint32, AUTOMATIC)bitPos = (uint32)0U;

    /* Get Tx Buffers with pending message requests */
    txBufPendStatus = Can_GetTxBufReqPendPriv(baseAddr);

    for (bitIndex = ((uint32)0U); bitIndex < ((uint32)32U); bitIndex++)
    {
        /* For each bit set call cancel request */
        bitPos = (uint32)1U << bitIndex;
        
        if(bitPos == (txBufPendStatus & bitPos))
        {
            /* Clear pending Tx request */
            Can_TxBufCancelReqPriv(baseAddr, bitIndex);

            (void)Os_GetCounterValue(CAN_CFG_OS_COUNTER_ID, &startCount);
            do
            {
                (void)Os_GetElapsedValue(CAN_CFG_OS_COUNTER_ID,
                                    &startCount,
                                    &elapsedCount);

                if (CAN_CFG_TIMEOUT_DURATION <= elapsedCount)
                {
                    /*  Timeout */
#if (CAN_CFG_DEM_ENABLE == STD_ON)
                    (void)Dem_SetEventStatus(CAN_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED); 
#endif
                    break;
                }
                else
                {
                    /*  Do Nothing */
                }
            } while ((uint32)bitPos != ((Can_TxBufCancelStatusPriv(baseAddr)) & bitPos));
        }
    }
}

/*
 *Design: MCAL-23052
 */
static FUNC(uint32, CAN_CODE) 
Can_GetTxBufReqPendPriv(uint32 baseAddr)
{
    return (CAN_REG_READ32(baseAddr + MCAN_TXBRP));
}

/*
 *Design: MCAL-24231
 */
static FUNC(void, CAN_CODE) 
Can_TxBufCancelReqPriv(uint32 baseAddr, 
                    uint32 buffNum)
{
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    regVal = CAN_REG_READ32(baseAddr + MCAN_TXBCR);
    regVal |= ((uint32)1U << buffNum);
    CAN_REG_WRITE32((baseAddr + MCAN_TXBCR), regVal);
}

/*
 *Design: MCAL-24232
 */
static FUNC(uint32, CAN_CODE) 
Can_TxBufCancelStatusPriv(uint32 baseAddr)
{
    return (CAN_REG_READ32(baseAddr + MCAN_TXBCF));
}

/*
 *Design: MCAL-23053
 */
static FUNC(uint32, CAN_CODE) 
Can_GetTxBufTransStatusPriv(uint32 baseAddr)
{
    return (CAN_REG_READ32(baseAddr + MCAN_TXBTO));
}

/*
 *Design: MCAL-23054
 */
static FUNC(void, CAN_CODE) 
Can_TxBufAddReqPriv(uint32 baseAddr, 
                    uint32 buffNum)
{
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    regVal = CAN_REG_READ32(baseAddr + MCAN_TXBAR);
    regVal |= ((uint32)1U << buffNum);
    CAN_REG_WRITE32((baseAddr + MCAN_TXBAR), regVal);

}

/*
 *Design: MCAL-23055
 */
static FUNC(void, CAN_CODE) 
Can_WriteMsgRamPriv(uint32 baseAddr, 
                uint32 bufNum,
                P2CONST(Can_TxBufElementType, AUTOMATIC, CAN_COST) elem)
{
    VAR(uint32, AUTOMATIC)startAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)elemSize = (uint32)0U;
    VAR(uint32, AUTOMATIC)idx = (uint32)0U;
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;


    if(CAN_MEM_TYPE_BUF == elem->memType)
    {
        idx = bufNum;
    }
    else
    {
        idx = CAN_REG_MF_READ32((baseAddr + MCAN_TXFQS), MCAN_TXFQS_TFQPI);
    }

    startAddr = CAN_REG_MF_READ32((baseAddr + MCAN_TXBC), MCAN_TXBC_TBSA);
    elemSize = CAN_REG_MF_READ32((baseAddr + MCAN_TXESC), MCAN_TXESC_TBDS);

    startAddr = (uint32)(startAddr << ((uint32)2U));
    elemSize = ((uint32)Can_ObjSize[elemSize]);
    elemSize *= ((uint32)4U);
    elemAddr = startAddr + (elemSize * idx);

    regVal = ((uint32)0U);
    regVal |= ((((uint32)elem->id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT)) |
                (((uint32)elem->xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT)));
    CAN_REG_WRITE32((baseAddr + elemAddr), regVal);
    elemAddr += ((uint32)4U);

    regVal = ((uint32)0U);
    regVal |= ((((uint32)elem->dataLength << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT)) |
                (((uint32)elem->brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT)) |
                (((uint32)elem->fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT)));
    CAN_REG_WRITE32((baseAddr + elemAddr), regVal);
    elemAddr += ((uint32)4U);

    /* Framing words out of the payload bytes and writing it to message RAM */
    while ((4U <= (Can_DataSize[elem->dataLength] - loopCnt)) &&
            (0U != (Can_DataSize[elem->dataLength] - loopCnt)))
    {
        regVal = ((uint32)0U);
        if((loopCnt+(uint8)3U) < 64U)
        {
            regVal |= (((uint32)elem->data[loopCnt]) |
                        ((uint32)elem->data[(loopCnt + ((uint8)1U))] << ((uint32)8U)) |
                        ((uint32)elem->data[(loopCnt + ((uint8)2U))] << ((uint32)16U)) |
                        ((uint32)elem->data[(loopCnt + ((uint8)3U))] << ((uint32)24U)));
            CAN_REG_WRITE32((baseAddr + elemAddr), regVal);
            elemAddr += ((uint32)4U);
            loopCnt += ((uint8)4U);
        }
    }

    /* Framing a word out of remaining payload bytes and writing it to message RAM */
    if (0U < (Can_DataSize[elem->dataLength] - loopCnt))
    {
        regVal = ((uint32)0U);
        if((loopCnt+(uint8)3U) < 64U)
        {
            regVal |= (((uint32)elem->data[loopCnt]) |
                        ((uint32)elem->data[(loopCnt + ((uint8)1U))] << ((uint32)8U)) |
                        ((uint32)elem->data[(loopCnt + ((uint8)2U))] << ((uint32)16U)) |
                        ((uint32)elem->data[(loopCnt + ((uint8)3U))] << ((uint32)24U)));
        }
        CAN_REG_WRITE32((baseAddr + elemAddr), regVal);
    }
}


/*
 *Design: MCAL-24234
 */
static FUNC(void, CAN_CODE) 
Can_ReadRxBuffPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                   P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox,
                   uint8 maxMbCnt)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)buffNum = (uint32)0U;
    VAR(uint32, AUTOMATIC)status = (uint32)0U;
    VAR(uint32, AUTOMATIC)bitPos = (uint32)0U;
    VAR(uint8, AUTOMATIC)canDataLength = (uint8)0U;
    VAR(uint32, AUTOMATIC)canIdentifier = (uint32)0U;
    VAR(uint8, AUTOMATIC)htrh = (uint8)0U;
    VAR(uint32, AUTOMATIC)byteCnt = (uint32)0U;
    VAR(Can_RxNewDataStatusType, AUTOMATIC)newDataStatus = {0U};
    VAR(Can_RxBufElementType, AUTOMATIC)elem = {0U};
    VAR(boolean, AUTOMATIC)RxIndicationStatus = (boolean) FALSE;
    VAR(boolean, AUTOMATIC)lpduCalloutStatus = (boolean) TRUE;
    #if (CAN_CFG_ICOM_SUPPORT == STD_ON)
                VAR(Std_ReturnType, AUTOMATIC)IcomStatus;
    #endif

    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;

    /* Get NewData Status */
    Can_GetNewDataStatusPriv(baseAddr, &newDataStatus);

    /* Clear NewData Status */
    Can_ClearNewDataStatusPriv(baseAddr, newDataStatus);

    /* Scan newData Register (32 bits x 2 Registers) and
        * read appropriate mailbox if any message is received */
    for (buffNum = ((uint32)0U); buffNum < MCAN_RX_BUFFER_MAX_NUM; buffNum++)
    {
        if(buffNum < ((uint32)32U))
        {
            status = newDataStatus.statusLow;
            bitPos = (((uint32)1U) << buffNum);
        }
        else
        {
            status = newDataStatus.statusHigh;
            bitPos = (((uint32)1U) << (buffNum - (uint32)32U));
        }

        if(bitPos == (status & bitPos))
        {
            if(buffNum < (uint32)controllerObj->canFDMsgRamConfig.rxBuffNum)
            {
                Can_ReadMsgRamPriv(baseAddr,
                            ((uint32)CAN_MEM_TYPE_BUF),
                            buffNum,
                            &elem);

                canDataLength = Can_DataSize[elem.dataLength];

                if((uint8)CAN_ID_XTD == elem.xtd)
                {
                    /* Received frame with Extended ID - set MSB to '1' */
                    canIdentifier = ((uint32)elem.id | CAN_MSG_ID_TYPE_EXT);
                }
                else
                {
                    /* Received frame with Standard ID */
                    canIdentifier = (((uint32)elem.id >> CAN_STD_MSGID_SHIFT) & CAN_STD_MSGID_MASK);
                }

                /* Set CAN-FD bit (30th bit) to '1' if CAN-FD frame is
                received */
                canIdentifier = (canIdentifier | ((uint32)elem.fdf << ((uint32)30U)));

                for (htrh = ((uint8)0U); htrh < maxMbCnt; htrh++)
                {
                    /* Check for Controller type and Active state as well
                        * as MailBox Direction */
                    if((RECEIVE == canMailbox[htrh].mailBoxConfig.CanObjectType) && 
                        (TRUE == controllerObj->canControllerConfig.CanControllerActivation) && 
                        (canMailbox[htrh].mailBoxConfig.CanControllerRef->CanControllerId == 
                        controllerObj->canControllerConfig.CanControllerId) &&
                        (((uint32)elem.xtd) == canMailbox[htrh].mailBoxConfig.CanIdType) && 
                        ((canIdentifier & CAN_XTD_MSGID_MASK) == 
                        (canMailbox[htrh].mailBoxConfig.CanHwFilterCode & CAN_XTD_MSGID_MASK)))
                    {
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }

                if(htrh < maxMbCnt)
                {
                    /* Copying payload into SDU */
                    for (byteCnt = ((uint32)0U); byteCnt < ((uint32)canDataLength); byteCnt++)
                    {
                        controllerObj->canSduPtr[byteCnt] = (uint8)elem.data[byteCnt];
                    }

                    /* Copy CanId, HOH and CanControllerId */
                    controllerObj->mailboxCfg.CanId = canIdentifier;
                    controllerObj->mailboxCfg.Hoh = (uint8) canMailbox[htrh].mailBoxConfig.CanObjectId;
                    controllerObj->mailboxCfg.ControllerId = controllerObj->canControllerConfig.CanControllerId;

                    /* Copy SDU data */
                    controllerObj->pduInfo.SduDataPtr = controllerObj->canSduPtr;
                    controllerObj->pduInfo.SduLength = ((PduLengthType)canDataLength);
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)       
                    /* check for Icom configuration */
                    if (Can_DriverObjPtr->Can_IcomActivation[controllerObj->canControllerConfig.CanControllerId] == TRUE)
                    {
                        IcomStatus = 
                        Can_ValidateIcomConfigCriteriaPriv(canIdentifier, controllerObj->pduInfo.SduDataPtr,
                        Can_DriverObjPtr->Can_IcomConfigurationId[controllerObj->canControllerConfig.CanControllerId],
                        controllerObj);
                        if( E_OK == IcomStatus )
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
        else
        {
            /* Do Nothing */
        }
    }
    if (RxIndicationStatus == TRUE)
    {
#ifdef  CAN_LPDU_RECEIVE_CALLOUT_FUNCTION
        lpduCalloutStatus = CAN_LPDU_RECEIVE_CALLOUT_FUNCTION(htrh, canIdentifier, canDataLength,
                                                    controllerObj->canSduPtr);
#endif
        
        if(lpduCalloutStatus == TRUE)
        {
            /* Call Receive Indication */
            CanIf_RxIndication(&controllerObj->mailboxCfg, &controllerObj->pduInfo);
        }
    }
}

/*
 *Design: MCAL-24235
 */
static FUNC(void, CAN_CODE) 
Can_ReadRxFIFOPriv(P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_APPL_DATA) controllerObj,
                   P2CONST(Can_MailboxObjType, AUTOMATIC, CAN_COST) canMailbox,
                   uint8 maxMbCnt)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(uint32, AUTOMATIC)fillLvl = (uint32)0U;
    VAR(uint32, AUTOMATIC)loopCnt = (uint32)0U;
    VAR(uint32, AUTOMATIC)mask = (uint32)0U;
    VAR(uint8, AUTOMATIC)canDataLength = (uint8)0U;
    VAR(uint32, AUTOMATIC)canIdentifier = (uint32)0U;
    VAR(uint8, AUTOMATIC)htrh = (uint8)0U;
    VAR(uint32, AUTOMATIC)byteCnt = (uint32)0U;
    VAR(Can_RxFIFOStatusType, AUTOMATIC)fifoStatus = ((Can_RxFIFOStatusType ){0U});
    VAR(Can_RxBufElementType, AUTOMATIC)elem = {0U};
    VAR(boolean, AUTOMATIC)RxIndicationStatus = (boolean) FALSE;
    VAR(boolean, AUTOMATIC)lpduCalloutStatus = (boolean) TRUE;
    #if (CAN_CFG_ICOM_SUPPORT == STD_ON)
        VAR(Std_ReturnType, AUTOMATIC)icom_status;
    #endif
    
    
    baseAddr = controllerObj->canControllerConfig.CanControllerBaseAddress;
    fifoStatus.num = CAN_RX_FIFO_NUM_0;

    /* Get Rx FIFO status */
    Can_GetRxFIFOStatusPriv(baseAddr, &fifoStatus);
    fillLvl = fifoStatus.fillLvl;

    for (loopCnt = ((uint32)0U); loopCnt < fillLvl; loopCnt++)
    {
        Can_GetRxFIFOStatusPriv(baseAddr, &fifoStatus);
        Can_ReadMsgRamPriv(baseAddr,
                        (uint32 )CAN_MEM_TYPE_FIFO,
                        fifoStatus.getIdx,
                        &elem);
        Can_WriteRxFIFOAckPriv(baseAddr, fifoStatus.getIdx);

        canDataLength = Can_DataSize[elem.dataLength];

        if ((uint8)CAN_ID_XTD == elem.xtd)
        {
            /* Received frame with Extended ID - set MSB to '1' */
            canIdentifier = ((uint32)elem.id | CAN_MSG_ID_TYPE_EXT);
            mask = CAN_XTD_MSGID_MASK;
        }
        else
        {
            /* Received frame with Standard ID */
            canIdentifier = (((uint32)elem.id >> CAN_STD_MSGID_SHIFT) & CAN_STD_MSGID_MASK);
            mask = CAN_STD_MSGID_MASK;
        }

        /* Set CAN-FD bit (30th bit) to '1' if CAN-FD frame is
        received */
        canIdentifier = (canIdentifier | ((uint32)elem.fdf << ((uint32)30U)));

        for (htrh = ((uint8)0U); htrh < maxMbCnt; htrh++)
        {
            /* Check for Controller type and Active state as well
                * as MailBox Direction */
            if((RECEIVE == canMailbox[htrh].mailBoxConfig.CanObjectType) && 
                (TRUE == controllerObj->canControllerConfig.CanControllerActivation) && 
                (canMailbox[htrh].mailBoxConfig.CanControllerRef->CanControllerId == 
                controllerObj->canControllerConfig.CanControllerId) &&
                (((uint32 )elem.xtd) == canMailbox[htrh].mailBoxConfig.CanIdType))
            {
                /* Get exact mask value */
                mask = mask & canMailbox[htrh].mailBoxConfig.CanHwFilterMask.MaskValue;
                if((canIdentifier & mask) ==
                (canMailbox[htrh].mailBoxConfig.CanHwFilterCode & mask))
                {
                break;
                }
            }
            else
            {
                /* Do Nothing */
            }
        }

        if(htrh < maxMbCnt)
        {
            /* Copying payload into SDU */
            for (byteCnt = ((uint32)0U); byteCnt < ((uint32)canDataLength); byteCnt++)
            {
                controllerObj->canSduPtr[byteCnt] = (uint8)elem.data[byteCnt];
            }

            /* Copy CanId, HOH and CanControllerId */
            controllerObj->mailboxCfg.CanId = canIdentifier;
            controllerObj->mailboxCfg.Hoh = (uint8) canMailbox[htrh].mailBoxConfig.CanObjectId;
            controllerObj->mailboxCfg.ControllerId = controllerObj->canControllerConfig.CanControllerId;

            /* Copy SDU data */
            controllerObj->pduInfo.SduDataPtr = controllerObj->canSduPtr;
            controllerObj->pduInfo.SduLength = ((PduLengthType)canDataLength);

#if (CAN_CFG_ICOM_SUPPORT == STD_ON) 
            /* check for Icom configuration */
            if (Can_DriverObjPtr->Can_IcomActivation[controllerObj->canControllerConfig.CanControllerId] == TRUE)
            {
                icom_status = Can_ValidateIcomConfigCriteriaPriv(canIdentifier, controllerObj->pduInfo.SduDataPtr
                    ,Can_DriverObjPtr->Can_IcomConfigurationId[controllerObj->canControllerConfig.CanControllerId],
                    controllerObj);
                if( E_OK == icom_status )
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
        }
        else
        {
            /* Do Nothing */
        }
    }
    if (RxIndicationStatus == TRUE)
    {
#ifdef  CAN_LPDU_RECEIVE_CALLOUT_FUNCTION
        lpduCalloutStatus = CAN_LPDU_RECEIVE_CALLOUT_FUNCTION(htrh, canIdentifier, canDataLength,
                                                    controllerObj->canSduPtr);
#endif
        
        if(lpduCalloutStatus == TRUE)
        {
            /* Call Receive Indication */
            CanIf_RxIndication(&controllerObj->mailboxCfg, &controllerObj->pduInfo);
        }
    }    
}

/*
 *Design: MCAL-24215
 */
static FUNC(uint32, CAN_CODE) 
Can_GetIntrStatus(uint32 baseAddr)
{
    return(CAN_REG_READ32(baseAddr + MCAN_IR));
}

#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
/*
 *Design: MCAL-24233
 */
static FUNC(Std_ReturnType, CAN_CODE)
Can_ValidateIcomConfigCriteriaPriv(uint32 can_identifier,
                            P2CONST(uint8, AUTOMATIC, CAN_COST) sduptr,
                            uint8 IcomConfigId,
                            P2CONST(Can_ControllerObjType, AUTOMATIC, CAN_COST) canController)
{
    VAR(Std_ReturnType, AUTOMATIC)status = E_NOT_OK;
    VAR(uint16, AUTOMATIC)LoopCount = 0U;
    VAR(uint16, AUTOMATIC)RxMessageConfigId;
    P2CONST(Can_IcomConfigType, AUTOMATIC, CAN_COST) IcomConfigPtr = &Can_DriverObjPtr->IcomConfigurationList[IcomConfigId-(uint8)1U];
    P2CONST(Can_IcomRxMessageType, AUTOMATIC, CAN_COST) RxMessage;
    P2CONST(Can_IcomSignalConfigType, AUTOMATIC, CAN_COST) signalData;
    VAR(uint64, AUTOMATIC)sdudata = 0U;
    VAR(uint64, AUTOMATIC)sdudataSingle = 0U;
    

    for(LoopCount = (uint16)0U; LoopCount < (uint16)8U; LoopCount++)
    {
        sdudataSingle = sduptr[LoopCount];
        sdudata |= (sdudataSingle << (8U*((uint16)7U - LoopCount)));
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
        if(LoopCount < IcomConfigPtr->RxMessageCount)
        {
            RxMessage = &IcomConfigPtr->CanIcomRxMessage[RxMessageConfigId];
            if(((uint16)0U) == RxMessage->SignalCount)
            {
                status = E_OK;
            }
            else
            {
                for (LoopCount = ((uint16)0U); LoopCount < RxMessage->SignalCount; LoopCount++)
                {
                    signalData = &RxMessage->CanIcomRxMessageSignalConfig[LoopCount];
                    switch(signalData->CanIcomSignalOperation)
                    {
                        case AND:
                            if (signalData->CanIcomSignalValue == ( (uint64)sdudata & signalData->CanIcomSignalMask))
                            {
                                status = E_OK;
                            }
                        break;
                        case EQUAL:
                            
                            if (sdudata == (uint64)signalData->CanIcomSignalValue)
                            {
                                status = E_OK;
                            }
                        break;
                        case GREATER:
                            if ((uint64)sdudata > signalData->CanIcomSignalValue)
                            {
                                status = E_OK;
                            }
                        break;
                        case SMALLER:
                            if ((uint64)sdudata < signalData->CanIcomSignalValue)
                            {
                                status = E_OK;
                            }
                        break;
                        case XOR:
                            if (signalData->CanIcomSignalValue == ( (uint64)sdudata ^ signalData->CanIcomSignalMask))
                            {
                                status = E_OK;
                            }
                        break;
                        default:
                        
                        break;
                    } 
                }
            }
        }
    }
    if (E_OK == status)
    {
        Can_DriverObjPtr->Can_IcomCounterValue[canController->canControllerConfig.CanControllerId]++;
        if (Can_DriverObjPtr->Can_IcomCounterValue[canController->canControllerConfig.CanControllerId] < 
                IcomConfigPtr->CanIcomCounterValue)
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
static FUNC(void, CAN_CODE) 
Can_ClearIntrStatusPriv(uint32 baseAddr, 
                        uint32 intrMask,
                        uint32 lineSelect)
{
    CAN_REG_WRITE32((baseAddr + MCAN_IR), intrMask);
    CAN_REG_WRITE32((baseAddr + MCAN_MCANSS_EOI), lineSelect);
}



/*
 *Design: MCAL-24236
 */
static FUNC(void, CAN_CODE) 
Can_GetNewDataStatusPriv(uint32 baseAddr,
                      P2VAR(Can_RxNewDataStatusType, AUTOMATIC, CAN_APPL_DATA) newDataStatus)
{
    newDataStatus->statusLow  = CAN_REG_READ32(baseAddr + MCAN_NDAT1);
    newDataStatus->statusHigh = CAN_REG_READ32(baseAddr + MCAN_NDAT2);
}



/*
 *Design: MCAL-24237
 */
FUNC(void, CAN_CODE) 
static Can_ClearNewDataStatusPriv(uint32 baseAddr,
                        Can_RxNewDataStatusType newDataStatus)
{
    CAN_REG_WRITE32((baseAddr + MCAN_NDAT1), newDataStatus.statusLow);
    CAN_REG_WRITE32((baseAddr + MCAN_NDAT2), newDataStatus.statusHigh);
}



/*
 *Design: MCAL-24239
 */
static FUNC(void, CAN_CODE) 
Can_GetRxFIFOStatusPriv(uint32 baseAddr,
                    P2VAR(Can_RxFIFOStatusType, AUTOMATIC, CAN_APPL_DATA) fifoStatus)
{
    VAR(uint32, AUTOMATIC)regVal = (uint32)0U;

    regVal = CAN_REG_READ32(baseAddr + MCAN_RXF0S);
    fifoStatus->fifoFull = ((boolean)CAN_FIELD_GET(regVal, MCAN_RXF0S_F0F));
    fifoStatus->fillLvl = CAN_FIELD_GET(regVal, MCAN_RXF0S_F0FL);
    fifoStatus->getIdx = CAN_FIELD_GET(regVal, MCAN_RXF0S_F0GI);
    fifoStatus->msgLost = CAN_FIELD_GET(regVal, MCAN_RXF0S_RF0L);
    fifoStatus->putIdx = CAN_FIELD_GET(regVal, MCAN_RXF0S_F0PI);
}


/*
 *Design: MCAL-24240
 */
static FUNC(void, CAN_CODE) 
Can_WriteRxFIFOAckPriv(uint32 baseAddr,
                    uint32 idx)
{
    VAR(uint32, AUTOMATIC)size = (uint32)0U;

    size = CAN_REG_MF_READ32((baseAddr + MCAN_RXF0C), MCAN_RXF0C_F0S);

    if(size >= idx)
    {
        CAN_REG_MF_WRITE32((baseAddr + MCAN_RXF0A),
                            MCAN_RXF0A_F0AI,
                            idx);
    }
    else
    {
        /* Do Nothing */
    }
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Can_Priv.c
 *********************************************************************************************************************/
