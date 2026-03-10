/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
#define LIN_INT_WAKEUP (0x00000002U)
/** \brief Time out */
#define LIN_INT_TO (0x00000010U)
/** \brief Time out after wakeup signal */
#define LIN_INT_TOAWUS (0x00000040U)
/** \brief Time out after 3 wakeup signals */
#define LIN_INT_TOA3WUS (0x00000080U)
/** \brief Transmit buffer ready */
#define LIN_INT_TX (0x00000100U)
/** \brief Receive buffer ready */
#define LIN_INT_RX (0x00000200U)
/** \brief Received matching identifier */
#define LIN_INT_ID (0x00002000U)
/** \brief Parity error */
#define LIN_INT_PE (0x01000000U)
/** \brief Overrun error */
#define LIN_INT_OE (0x02000000U)
/** \brief Framing error */
#define LIN_INT_FE (0x04000000U)
/** \brief No response error */
#define LIN_INT_NRE (0x08000000U)
/** \brief Inconsistent sync field error */
#define LIN_INT_ISFE (0x10000000U)
/** \brief Checksum error */
#define LIN_INT_CE (0x20000000U)
/** \brief Physical bus error */
#define LIN_INT_PBE (0x40000000U)
/** \brief Bit error */
#define LIN_INT_BE (0x80000000U)
/** \brief All interrupts */
#define LIN_INT_ALL (0xFF0023D2U)

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
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK: No error has occurred during execution of the API
 * \retval E_NOT_OK: An error has occurred during execution of the API
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE)
Lin_InitInternal(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Lin_ConfigPtr);

/** \brief Lin_CheckWakeupInternal - This function checks if a wakeup has occurred on the addressed
 *LIN channel.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK: No error has occurred during execution of the API
 * \retval E_NOT_OK: An error has occurred during execution of the API
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeupInternal(uint8 Channel);

/** \brief Lin_WakeupProcess - Generates a wake up pulse and sets the channel state to
 *LIN_CH_OPERATIONAL.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Wake-up request has been accepted
 * \retval E_NOT_OK: Wake-up request has not been accepted, development or production error
 *occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupProcess(uint8 Channel);

/** \brief Lin_WakeupInternalProcess - Generates a wake up pulse and sets the channel state to
 *LIN_CH_OPERATIONAL without generating a wake up pulse.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Wake-up request has been accepted
 * \retval E_NOT_OK: Wake-up request has not been accepted, development or production error
 *occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternalProcess(uint8 Channel);

/** \brief Lin_GetStatusInternalProcess - Gets the status of the LIN driver.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[in] lin_cnt_base_addr Base address of the lin
 * \param[out] Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *receive buffer where the current SDU is stored.
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
 * \retval LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up from the
 *LIN_CH_SLEEP and no data has been sent.
 * \retval LIN_CH_SLEEP: Sleep state operation; in this state wake-up detection from slave nodes is
 *enabled.
 *
 *********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE)
Lin_GetStatusInternalProcess(uint8 Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr,
                             P2CONST(uint32, AUTOMATIC, LIN_CONFIG_DATA) lin_cnt_base_addr);

/** \brief Lin_GetStatusInternal - Gets the status of the LIN driver.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[in] lin_cnt_base_addr Base address of the lin
 * \param[out] Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *receive buffer where the current SDU is stored.
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
 * \retval LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up from the
 *LIN_CH_SLEEP and no data has been sent.
 * \retval LIN_CH_SLEEP: Sleep state operation; in this state wake-up detection from slave nodes is
 *enabled.
 *
 *********************************************************************************************************************/
FUNC(Lin_StatusType, LIN_CODE)
Lin_GetStatusInternal(uint8 Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr,
                      P2CONST(uint32, AUTOMATIC, LIN_CONFIG_DATA) lin_cnt_base_addr);

/** \brief Lin_HwUnitConfig - This API will configure Lin IP instance.
 *
 * \param[in] linChannel      LIN channel to be addressed.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE)
Lin_HwUnitConfig(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel);

/** \brief Lin_SendData - This API will copy data into LIN_TDx registers and start transmission.
 *
 * \param[in] linChannel      LIN channel to be addressed.
 * \param[in] linChannelActivityStatus      Pointer to current activity staus of the channel.
 * \param[in] pduInfoPtr     Pointer to PDU to be sent.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK : Transmission command has been accepted
 * \retval E_NOT_OK : Transmission command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE)
Lin_SendData(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel,
             P2VAR(Lin_ChannelActivityStatusType, AUTOMATIC, LIN_APPL_DATA) linChannelActivityStatus,
             P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pduInfoPtr);

/** \brief Lin_GetData - This API will copy the received data into sduPtr.
 *
 * \param[in] channelID      LIN channel to be addressed.
 * \param[in] base           Base address of Lin Instance.
 * \param[in] sduPtr         Pointer to Pointer to SDU to be received.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK : Copying of received data command has been accepted
 * \retval E_NOT_OK : Copying of received data command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE)
Lin_GetData(uint32 channelID, uint32 base, P2VAR(uint8*, AUTOMATIC, LIN_APPL_CONST) sduPtr);

/** \brief Lin_FetchTxStatus - This API will fetch transmit status.
 *
 * \param[in] base      Base address of Lin Instance.
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
 * \param[in] enable    If TRUE wakeup detection will be enabled; if FALSE wakeup detection will be
 *disabled.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE)
Lin_EnableWakeupDetection(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_CONST) linChannel, boolean enable);

/** \brief Lin_ProcessISR - This API will process ISR for given channel.
 *
 * \param[in] channelID      LIN channel to be addressed.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_ProcessISR(uint32 channelID);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* LIN_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Lin_Priv.h
 *********************************************************************************************************************/
