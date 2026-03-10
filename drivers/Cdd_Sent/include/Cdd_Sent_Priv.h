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
 *  File:       Cdd_Sent_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to Cdd_Sent
 *
 *********************************************************************************************************************/
#ifndef CDD_SENT_PRIV_H
#define CDD_SENT_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Design: MCAL-28616
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent.h"
#include "hw_sent.h"
#include "hw_memmap.h"
#include "hw_types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief Max 32 bit value. */
#define CDD_SENT_MAX_32BIT_VAL (0xFFFFFFFFU)

/** \brief Max 16 bit value. */
#define CDD_SENT_MAX_16BIT_VAL (0xFFFFU)

/** \brief Sent CRC nibble position 1 */
#define CDD_SENT_CRC_NIBBLE_PS_0 ((uint32)0U)
/** \brief Sent CRC nibble position 2 */
#define CDD_SENT_CRC_NIBBLE_PS_1 ((uint32)1U)
/** \brief Sent CRC Status nibble position */
#define CDD_SENT_CRC_NIBBLE_PS_2 ((uint32)2U)

/** \brief Sent CRC nibble 1 */
#define CDD_SENT_CRC_NIBBLE_1 ((uint32)10U)
/** \brief Sent CRC nibble 2 */
#define CDD_SENT_CRC_NIBBLE_2 ((uint32)11U)
/** \brief Sent CRC Status nibble */
#define CDD_SENT_CRC_STATUS_NIBBLE ((uint32)15U)
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Set the Cdd_Sent driver object into global pointer.
 *
 * This function Set the Cdd_Sent driver object into global pointer which can be used in ISR
 *notification API.
 *
 * \param[in] Set_DrvObj Set_DrvObj is the Cdd_Sent driver object defined in Cdd_Sent.c
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE) Cdd_Sent_SetDriverObjPtr(Cdd_Sent_DriverObjType* Set_DrvObj);

/** \brief Initialize the Sent instance.
 *
 * This function initializes the Sent using the configuration parameters.
 *
 * \param[in] ConfigPtr is the structure containing Sent HW unit configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwInitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief Initialize MTP mode.
 *
 * This function initializes the MTP mode using the configuration parameters.
 *
 * \param[in] ConfigPtr is the structure containing Sent HW unit configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_MTPInitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief DeInitialize the Sent instance.
 *
 * This function Deinitialize the Sent using the configuration parameters.
 *
 * \param[in] ConfigPtr is the structure containing Sent HW unit configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwDenitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief Get the array index of a channel from configuration array/vector
 *
 *  This function populates the 'ChannelIndex' pointer with the array index of the
 *  'Channel' present in configuration array
 *
 * \param[in] CddSentDrvObj is a structure containing multiple timer configurations.
 * \param[in] SentInstance Numeric identifier of the Sent instance.
 * \param[out] InstanceIndex Pointer to populate the index of channel present in config
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_GetChIdxPriv(const Cdd_Sent_DriverObjType* CddSentDrvObj, Cdd_SentInstance SentInstance,
                      uint32* InstanceIndex);

/** \brief Trigger particular Sent instance.
 *
 * This function trigger particular Sent instance using the configuration parameters.
 *
 * \param[in] Instance_Id is the sent instance id.
 * \param[in] Channel_Id is the sent Channel id.
 * \param[in] Trigger_Source is the type of trigger source.
 * \param[in] PduInfoPtr is the PDU Information Type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/

FUNC(void, CDD_SENT_CODE)
Cdd_Sent_TriggerPrv(uint8 Instance_Id, Cdd_SentTriggerSource Trigger_Source, uint8 Channel_Id,
                    P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr);

/** \brief Cdd_Sent_ProcessISR: Invoked by the respective Sent channel ISR.
 *
 * This Interrupt notification call function is called when interrupt
 * notification is enabled for the  sent channel
 *
 * \param[in] SentInstance Numeric identifier of the Sent channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Cdd_Sent_ProcessISR(Cdd_SentInstance SentInstance);

/** \brief Get message data.
 *
 * This function get the message id of slow data.
 *
 * \param[in] Sent_Instance_Object Configuration pointer to Sent HW Unit.
 * \pre None
 * \post None
 * \return uint32
 * \retval returns message data
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
    Cdd_Sent_getMessageID(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object);

/** \brief Get slow data.
 *
 * This function fetches slow data.
 *
 * \param[in] Sent_Instance_Object Configuration pointer to Sent HW Unit.
 * \pre None
 * \post None
 * \return uint32
 * \retval returns slow data
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
    Cdd_Sent_getSlowData(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object);

/** \brief Enable MTP Channel.
 *
 * This function Enable MTP Channel using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] channel is the sent Channel type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_enableMTPChannel(uint32 mtpBase, Cdd_SentSensorType channel);

/** \brief Set MTP Timeout.
 *
 * This function Set MTP Timeout using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] sensorNum is the sent Channel type.
 * \param[in] sensorTimeout is the Time period.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_configureMTPTimeout(uint32 mtpBase, Cdd_SentSensorType sensorNum, uint32 sensorTimeout);

/** \brief Set MTP WaitTime.
 *
 * This function Set MTP waittime using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] waitTime is the Time period.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setMTPWaitTime(uint32 mtpBase, uint32 waitTime);

/** \brief Set MTP Period.
 *
 * This function Set MTP Period using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] channel is the sent Channel type.
 * \param[in] period is the Time period.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setMTPPeriod(uint32 mtpBase, Cdd_SentSensorType channel, uint32 period);

/** \brief Clear Interrupt Flag.
 *
 * This function clear Interrupt flag.
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] intFlags is the interrupt flag.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_clearInterruptFlag(uint32 base, uint32 intFlags);

/** \brief Set Broadcast Channel MTP Toggle Time.
 *
 * This function Set Broadcast Channel MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setBroadcastChMTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime);

/** \brief Set Sensor-1 MTP Toggle Time.
 *
 * This function Set Sensor-1 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor1MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime);

/** \brief Set Sensor-2 MTP Toggle Time.
 *
 * This function Set Sensor-2 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor2MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime);

/** \brief Set Sensor-3 MTP Toggle Time.
 *
 * This function Set Sensor-3 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor3MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime);

/** \brief Set Sensor-4 MTP Toggle Time.
 *
 * This function Set Sensor-4 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor4MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime);

/** \brief Disable MTP Channel.
 *
 * This function Disable MTP Channel using the configuration parameters.
 *
 * \param[in] mtpBase is the base address of the SENT module.
 * \param[in] channel is the sent Channel Type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_disableMTPChannel(uint32 mtpBase, Cdd_SentSensorType channel);

/** \brief Disable Sent receiver.
 *
 * This function Disable Sent receiver using the configuration parameters.
 *
 * \param[in] base is the base address of the SENT module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_disableSentReceiver(uint32 base);

/** \brief Enable Sent receiver.
 *
 * This function Enable Sent receiver using the configuration parameters.
 *
 * \param[in] base is the base address of the SENT module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_EnableSentReceiver(uint32 base);

/** \brief Set GFlit clock cycle.
 *
 * This function set GFlit clock cycle using the configuration parameters.
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] gFiltClock is the gFlitClock.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setGFILTClockCycle(uint32 base, uint32 gFiltClock);

/** \brief Configure the FIFO Mode.
 *
 * The \e fifoMode specifies whether the Timestamp, data0 and data1 data
 *  will be mapped directly to a memory or in FIFO. Valid values
 * can be referred from the enum \e SENT_FIFOMode..
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] fifoMode is the FIFO mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Sent_ConfigureFifoMode(uint32 base, Cdd_SentFIFOMode fifoMode);

/** \brief Configure timeout.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] timeOut is the timeout value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_configureTimeout(uint32 base, uint32 timeOut);

/** \brief Enable the interrupt for channel.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] intFlags interrupt value for sensor channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_enableInterrupt(uint32 base, uint32 intFlags);

/** \brief Set data nibbles count.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] dataNibble data nibbles count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setDataNibble(uint32 base, Cdd_SentDataNibblesCount dataNibble);

/** \brief Set the trigger level for receiver FIFO triggerinterrupt.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] triggerLevel is the trigger level..
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setRFIFOTriggerLevel(uint32 base, Cdd_SentTriggerLevel triggerLevel);

/** \brief Get SENT FIFO data.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) Cdd_Sent_getFIFO(uint32 base);

/** \brief Disable the interrupt for channel.
 *
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] intFlags interrupt value for sensor channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_disableInterrupt(uint32 base, uint32 intFlags);

/** \brief Configure the receiver data sorting format.
 *
 * This function configures where the received nibbles are stored in data0/1 map.
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] dataNumber indicates the number of data where the nibbles will be stored.
 * \param[in] nibbleNum is the number of nibble which will be stored.
 * \param[in]  nibble is the type of nibble.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setDataSortingFormat(uint32 base, Cdd_Sent_DataNumber dataNumber, Cdd_SentNibbleNumber nibbleNum,
                                  Cdd_SentNibble nibble);

/** \brief Trigger software trigger request.
 *
 * This function triggers software trigger request.
 *
 * \param[in] SentBase is the base address of the SENT module.
 * \param[in] channel is the sent Channel Type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_enableMTPSoftwareTrigger(uint32 SentBase, Cdd_SentSensorType channel);

/** \brief Cdd_Sent_InitPriv : Initializes the CDD_SENT Channels and Enables Sent Receiver.
 *
 * This service initializes the configured HW units.
 * \param[in] Cdd_Sent_DriverObj Cdd_Sent_DrvObj is the Cdd_Sent driver object defined in Cdd_Sent.c
 * \param[in] Cdd_Sent_DrvInitialized Cdd_Sent_DriverInitialized is the boolean variable
 *                                       defined in Cdd_Sent.c
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_InitPriv(P2VAR(Cdd_Sent_DriverObjType, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DriverObj,
                  P2VAR(boolean, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DrvInitialized);

/** \brief Cdd_Sent_TransmitPriv : Triggers the MTP.
 *
 * This service will trigger the MTP in case of MTP enabled.
 *
 * \param[in] PduInfoPtr Pointer to PDU Information.
 * \param[in] TxPduId ID of the Tx PDU
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_SENT_CODE)
Cdd_Sent_TransmitPriv(P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr, PduIdType TxPduId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *
 *  Mark the end of the C bindings section for C++ compilers.
 *
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* CDD_SENT_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Priv.h
 *********************************************************************************************************************/
