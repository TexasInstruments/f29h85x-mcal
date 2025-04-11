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
 *  File:       Lin_Priv.h
 *
 *  Description:  This file contains interface header for LIN private functions
 *********************************************************************************************************************/

#ifndef LIN_PRIV_H
#define LIN_PRIV_H

/**
 * \addtogroup LIN
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_types.h"
#include "Mcal_Lib_Cpu.h"
#include "hw_lin.h"
#include "Lin.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* 
 *Design: MCAL-25541, MCAL-25542, MCAL-25543
 */
/** \brief Lin Interrupt Wakeup Flag*/
#define LIN_INT_WAKEUP                      (0x00000002U)
/** \brief Time out */
#define LIN_INT_TO                          (0x00000010U) 
/** \brief Time out after wakeup signal */
#define LIN_INT_TOAWUS                      (0x00000040U) 
/** \brief Time out after 3 wakeup signals */
#define LIN_INT_TOA3WUS                     (0x00000080U) 
/** \brief Transmit buffer ready */
#define LIN_INT_TX                          (0x00000100U) 
/** \brief Receive buffer ready */
#define LIN_INT_RX                          (0x00000200U) 
/** \brief Received matching identifier */
#define LIN_INT_ID                          (0x00002000U) 
/** \brief Parity error */
#define LIN_INT_PE                          (0x01000000U) 
/** \brief Overrun error */
#define LIN_INT_OE                          (0x02000000U) 
/** \brief Framing error */
#define LIN_INT_FE                          (0x04000000U) 
/** \brief No response error */
#define LIN_INT_NRE                         (0x08000000U) 
/** \brief Inconsistent sync field error */
#define LIN_INT_ISFE                        (0x10000000U) 
/** \brief Checksum error */
#define LIN_INT_CE                          (0x20000000U) 
/** \brief Physical bus error */
#define LIN_INT_PBE                         (0x40000000U) 
/** \brief Bit error */
#define LIN_INT_BE                          (0x80000000U) 
/** \brief All interrupts */
#define LIN_INT_ALL                         (0xFF0023D2U) 

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/* 
 *Design: MCAL-25688
 */
/** \brief Enum of Channel Activity Status */
typedef enum Lin_ChannelActivityStatusTag
{   
    /** \brief Idle state. */
    LIN_CHANNEL_IDLE,
    /** \brief Transmission started. */
    LIN_CHANNEL_TX_STARTED,
    /** \brief Reception started. */
    LIN_CHANNEL_RX_STARTED,
} Lin_ChannelActivityStatusType;

/* 
 *Design: MCAL-25689
 */
/** \brief Enum of Channel Network Status */
typedef enum Lin_ChannelNetworkStatusTag
{ 
    /** \brief Channel is operational. */
    LIN_CHANNEL_OPERATIONAL,
    /** \brief Sleep state pending. */
    LIN_CHANNEL_SLEEP_PENDING,
    /** \brief Sleep state. */
    LIN_CHANNEL_SLEEP
} Lin_ChannelNetworkStatusType;

/* 
 *Design: MCAL-25690
 */
/** \brief Channel Status type structure */
typedef struct Lin_ChannelStatusTag
{   
    /** \brief Enum of Channel Activity Status. */
    Lin_ChannelActivityStatusType linChannelActivityStatus;

    /** \brief Enum of Channel Network Status. */
    Lin_ChannelNetworkStatusType linChannelNetworkStatus;
} Lin_ChannelStatusType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Lin_InitInternal - Initializes the LIN module.
 *
 * \param[in] Lin_ConfigPtr Pointer to LIN driver configuration set.
 * \param[out] None
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK: No error has occurred during execution of the API 
 * \retval E_NOT_OK: An error has occurred during execution of the API
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_InitInternal(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Lin_ConfigPtr);


/** \brief Lin_CheckWakeupInternal - This function checks if a wakeup has occurred on the addressed LIN channel.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[out] None
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK: No error has occurred during execution of the API 
 * \retval E_NOT_OK: An error has occurred during execution of the API
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeupInternal(uint8 Channel);


/** \brief Lin_WakeupProcess - Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 * 
 * \param[in] Channel LIN channel to be addressed.
 * \param[out] None
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Wake-up request has been accepted
 * \retval E_NOT_OK: Wake-up request has not been accepted, development or production error occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupProcess(uint8 Channel);


/** \brief Lin_WakeupInternalProcess - Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL 
 *         without generating a wake up pulse.
 * 
 * \param[in] Channel LIN channel to be addressed.
 * \param[out] None
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Wake-up request has been accepted
 * \retval E_NOT_OK: Wake-up request has not been accepted, development or production error occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternalProcess(uint8 Channel);


/** \brief Lin_GetStatusInternal - Gets the status of the LIN driver.
 * 
 * \param[in] Channel LIN channel to be addressed.
 * \param[in] lin_cnt_base_addr Base address of the lin
 * \param[out] Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the 
 *                       current SDU is stored.
 * \pre None
 * \post None
 * \return return_value
 * \retval LIN_NOT_OK: Development or production error occurred 
 * \retval LIN_TX_OK: Successful transmission 
 * \retval LIN_TX_BUSY: Ongoing transmission (Header or Response) 
 * \retval LIN_TX_HEADER_ERROR: Erroneous header transmission such as: 
 *                      - Mismatch between sent and read back data 
 *                      - Identifier parity error or Physical bus error 
 * \retval LIN_TX_ERROR: Erroneous response transmission such as: 
 *                      - Mismatch between sent and read back data 
 *                      - Physical bus error 
 * \retval LIN_RX_OK: Reception of correct response 
 * \retval LIN_RX_BUSY: Ongoing reception: at least one response byte has been received, 
 *                      but the checksum byte has not been received 
 * \retval LIN_RX_ERROR: Erroneous response reception such as: 
 *                      - Framing error 
 *                      - Overrun error 
 *                      - Checksum error or Short response 
 * \retval LIN_RX_NO_RESPONSE: No response byte has been received so far 
 * \retval LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up from the LIN_CH_SLEEP 
 *                      and no data has been sent. 
 * \retval LIN_CH_SLEEP: Sleep state operation; in this state wake-up detection from slave nodes is enabled.
 *
 *********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatusInternal(uint8 Channel,\
                            P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr, 
                           P2CONST(uint32, AUTOMATIC, LIN_CONFIG_DATA) lin_cnt_base_addr);


/** \brief Lin_HwUnitConfig - This API will configure Lin IP instance.
 * 
 * \param[in] linChannel      LIN channel to be addressed.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_HwUnitConfig(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel);


/** \brief Lin_SendData - This API will copy data into LIN_TDx registers and start transmission.
 * 
 * \param[in] linChannel      LIN channel to be addressed.
 * \param[in] linChannelActivityStatus      Pointer to current activity staus of the channel.
 * \param[in] pduInfoPtr     Pointer to PDU to be sent.
 * \param[out] None
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK : Transmission command has been accepted
 * \retval E_NOT_OK : Transmission command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_SendData(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel, \
P2VAR(Lin_ChannelActivityStatusType, AUTOMATIC, LIN_APPL_DATA) linChannelActivityStatus, \
P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pduInfoPtr);


/** \brief Lin_GetData - This API will copy the received data into sduPtr.
 * 
 * \param[in] linChannel      LIN channel to be addressed.
 * \param[in] base           Base address of Lin Instance.
 * \param[in] sduPtr         Pointer to Pointer to SDU to be received.
 * \param[out] None
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK : Copying of received data command has been accepted
 * \retval E_NOT_OK : Copying of received data command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_GetData(uint32 channelID, uint32 base, P2VAR(uint8*, AUTOMATIC, LIN_APPL_CONST) sduPtr);


/** \brief Lin_FetchTxStatus - This API will fetch transmit status.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK : Fetching the transmit status command has been accepted
 * \retval E_NOT_OK : Fetching the transmit status command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE) Lin_FetchTxStatus(uint32 base);


/** \brief Lin_FetchRxStatus - This API will fetch receive status.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK : Fetching the receive status command has been accepted
 * \retval E_NOT_OK : Fetching the receive status command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE) Lin_FetchRxStatus(uint32 base);


/** \brief Lin_SendWakeupSignal - This API will send wakeup signal on Lin bus.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK : Wakeup request  has been accepted
 * \retval E_NOT_OK : Wakeup request has not been accepted
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_SendWakeupSignal(uint32 base);

/** \brief Lin_SendGoToSleepSignal - This API will send go to sleep signal on Lin bus.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK : Sleep command has been sent
 * \retval E_NOT_OK : Sleep command has not been sent/Timeout error occurred
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_SendGoToSleepSignal(uint32 base);


/** \brief Lin_EnterLowPowerMode - This API will enter local low power mode for Lin instance.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[in] enable    If TRUE low power will be entered; if FALSE Lin comes out of low power mode.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_EnterLowPowerMode(uint32 base, boolean enable);


/** \brief Lin_CheckWakeupStatus - This API will check if Lin in woken up.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(boolean, LIN_CODE) Lin_CheckWakeupStatus(uint32 base);


/** \brief Lin_AbortTransmission - This API will abort ongoing transmission.
 * 
 * \param[in] base      Base address of Lin Instance.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_AbortTransmission(uint32 base);


/** \brief Lin_EnableWakeupDetection - This API will enable wakeup detection.
 * 
 * \param[in] linChannel      LIN channel to be addressed.
 * \param[in] enable    If TRUE wakeup detection will be enabled; if FALSE wakeup detection will be disabled.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_EnableWakeupDetection(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_CONST) linChannel, \
boolean enable);


/** \brief Lin_ProcessISR - This API will process ISR for given channel.
 * 
 * \param[in] channelID      LIN channel to be addressed.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_ProcessISR(uint32 channelID);


/** \brief This function writes a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 32-bit register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegWriteRaw32(uint32 addr, uint32 value);


/** \brief This function writes a 8 bit register value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write 8 bits to the 32-bit register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegWriteRaw8(uint32 addr, uint8 value);


/** \brief This function writes a 32 bit register masking specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \param[in] value Value to write in the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegMFWriteRaw32(uint32 addr,
                                      uint32 mask,
                                      uint32 shift,
                                      uint32 value);


/** \brief This function reads a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint32, LIN_CODE) Lin_RegReadRaw32(uint32 addr);


/** \brief This function reads a 8 bits of 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint8, LIN_CODE) Lin_RegReadRaw8(uint32 addr);



LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegWriteRaw32(uint32 addr, uint32 value)
{
    *(volatile uint32 *) addr = value;
}


LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegWriteRaw8(uint32 addr, uint8 value)
{
    *(volatile uint8 *) addr = value;
}


LOCAL_INLINE FUNC(void, LIN_CODE) Lin_RegMFWriteRaw32(uint32 addr,
                                      uint32 mask,
                                      uint32 shift,
                                      uint32 value)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32 *)addr = regVal;
}


LOCAL_INLINE FUNC(uint32, LIN_CODE) Lin_RegReadRaw32(uint32 addr)
{
    uint32 regVal = *(volatile uint32 *)addr;
    return (regVal);
}


LOCAL_INLINE FUNC(uint8, LIN_CODE) Lin_RegReadRaw8(uint32 addr)
{
    uint8 regVal = *(volatile uint8 *)addr;
    return (regVal);
}

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* LIN_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Lin_Priv.h
 *********************************************************************************************************************/
