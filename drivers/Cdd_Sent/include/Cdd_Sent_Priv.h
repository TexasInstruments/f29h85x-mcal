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
 *  File:       Cdd_Sent_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to Cdd_Sent
 *
 *********************************************************************************************************************/
#ifndef CDD_SENT_PRIV_H
#define CDD_SENT_PRIV_H

/** \addtogroup CDD_SENT
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

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
 * This function Set the Cdd_Sent driver object into global pointer which can be used in ISR notification API.
 *
 * \param[in] Set_DrvObj Set_DrvObj is the Cdd_Sent driver object defined in Cdd_Sent.c
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE) Cdd_Sent_SetDriverObjPtr( Cdd_Sent_ConfigType* Set_DrvObj);

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
FUNC(void, CDD_SENT_CODE) \
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
FUNC(void, CDD_SENT_CODE) \
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
FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_HwDenitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief Trigger particular Sent instance.
 *
 * This function trigger particular Sent instance using the configuration parameters.
 *
 * \param[in] Instance_Id is the sent instance id.
 * \param[in] Channel_Id is the sent Channel id.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_TriggerPrv(uint8 Instance_Id,uint8 Channel_Id);

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

/** \brief Get Frame data.
 *
 * This function Enable MTP Channel using the configuration parameters.
 *
 * \param[in] membase is the base address of the SENT module.
 * \param[in] SENTWord is the sentWord.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getFrameData(uint32 memBase, uint16 SENTWord);

/** \brief Get message data.
 *
 * This function get the message id of slow data.
 *
 * \param[in] SentInstance is the base instance of the SENT module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getMessageID(Cdd_SentInstance SentInstance);

/** \brief Get slow data.
 *
 * This function fetches slow data.
 *
 * \param[in] SentInstance is the instance of the SENT module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getSlowData(Cdd_SentInstance SentInstance);

/** \brief Enable MTP Channel.
 *
 * This function Enable MTP Channel using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] channel is the sent Channel type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_enableMTPChannel(uint32 mtpBase, Cdd_SentChannelType channel);

/** \brief Set MTP Period.
 *
 * This function Set MTP Period using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] channel is the sent Channel type.
 * \param[in] period is the Time period.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setMTPPeriod(uint32 mtpBase, Cdd_SentChannelType channel, uint32 period);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_clearInterruptFlag(uint32 base, uint32 intFlags);

/** \brief Set Broadcast Channel MTP Toggle Time.
 *
 * This function Set Broadcast Channel MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setBroadcastChMTPToggleTime(uint32 mtpBase, \
                            uint32 compareNum, uint32 toggleTime);

/** \brief Set Sensor-1 MTP Toggle Time.
 *
 * This function Set Sensor-1 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor1MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime);

/** \brief Set Sensor-2 MTP Toggle Time.
 *
 * This function Set Sensor-2 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor2MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime);

/** \brief Set Sensor-3 MTP Toggle Time.
 *
 * This function Set Sensor-3 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor3MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime);

/** \brief Set Sensor-4 MTP Toggle Time.
 *
 * This function Set Sensor-4 MTP Toggle Time using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] compareNum is the sent Compare number.
 * \param[in] toggleTime is the Toggle Time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor4MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime);

/** \brief Disable MTP Channel.
 *
 * This function Disable MTP Channel using the configuration parameters.
 *
 * \param[in] mtpbase is the base address of the SENT module.
 * \param[in] channel is the sent Channel Type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_disableMTPChannel(uint32 mtpBase, Cdd_SentChannelType channel);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) 
Cdd_Sent_disableSentReceiver(uint32 base);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) 
Cdd_Sent_EnableSentReceiver(uint32 base);

/** \brief Set Tick Time.
 *
 * This function set tick time using the configuration parameters.
 *
 * \param[in] base is the base address of the SENT module.
 * \param[in] ttClock is the tick time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setTTClock(uint32 base, uint32 ttClock);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setGFILTClockCycle(uint32 base, uint32 gFiltClock);

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
LOCAL_INLINE void
Sent_ConfigureFifoMode(uint32 base, Cdd_SentFIFOMode fifoMode);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_configureTimeout(uint32 base, uint32 timeOut);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setDataNibble(uint32 base, Cdd_SentDataNibblesCount dataNibble);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setRFIFOTriggerLevel(uint32 base, Cdd_SentTriggerLevel triggerLevel);

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
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
Cdd_Sent_getFIFO(uint32 base);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
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
LOCAL_INLINE void
Cdd_Sent_setDataSortingFormat(uint32 base, Cdd_Sent_DataNumber dataNumber,
                        Cdd_SentNibbleNumber nibbleNum, Cdd_SentNibble nibble);

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
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_enableMTPSoftwareTrigger(uint32 SentBase, Cdd_SentChannelType channel);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getFrameData(uint32 memBase, uint16 SENTWord)
{
    /* Return the received work from SENT Fast channel data when FIFO is */
    /* not enabled and it is memory mapped. */
    uint32 data= HWREG(memBase + SENT_O_MDATA(SENTWord));
    return data;
}

LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getMessageID(Cdd_SentInstance SentInstance)
{
    uint32 Sent_Base = (((uint32)SENT1CSENT_BASE) + (((uint32)SentInstance) +0x1000U));
    uint32 Slow_Data_Base = HWREG(Sent_Base+0x28U);
    uint32 mask = 0xFF000000U;
    uint32 MessageID= Slow_Data_Base & mask;
    return MessageID;
}

LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) \
Cdd_Sent_getSlowData(Cdd_SentInstance SentInstance)
{
    uint32 Sent_Base = (((uint32)SENT1CSENT_BASE) + (((uint32)SentInstance) + 0x1000U));
    uint32 Slow_Data_Base = HWREG(Sent_Base+0x28U);
    uint32 mask = 0xFFFF00U;
    uint32 Slow_Data= Slow_Data_Base & mask;
    return Slow_Data;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_enableMTPChannel(uint32 mtpBase, Cdd_SentChannelType channel)
{
    VAR(uint32, AUTOMATIC) channelOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_CHANNEL_STEP = 0x100U;

	channelOffset = (((uint32)SENT_MTP_CHANNEL_STEP*(uint32)channel) +
				SENT_O_BC_MTP_EN);

    /* Enable the channel to generate trigger pulses. */

    HWREG(mtpBase + channelOffset) |= SENT_BC_MTP_EN_MTP_EN;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setMTPPeriod(uint32 mtpBase, Cdd_SentChannelType channel, uint32 period)
{
    VAR(uint32, AUTOMATIC) periodOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_PERIOD_STEP = 0x100U;

    periodOffset = (SENT_MTP_PERIOD_STEP * (uint32)channel) +
                    SENT_O_BC_MTP_PERIOD;

    /* Set the period that the master trigger pulse output waveform is active. */

    HWREG(mtpBase + periodOffset) = (HWREG(mtpBase + periodOffset) &
                                        ~SENT_BC_MTP_PERIOD_PERIOD_M) | period;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_clearInterruptFlag(uint32 base, uint32 intFlags)
{
    /* Clear the specified interrupt. */

    HWREG(base + SENT_O_RCLRINT) |= intFlags;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setBroadcastChMTPToggleTime(uint32 mtpBase, \
                            uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) +
                    SENT_O_BC_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) &
                                 ~SENT_BC_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor1MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) +
                    SENT_O_S1_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) &
                                 ~SENT_S1_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor2MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;


    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) +
                    SENT_O_S2_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) &
                                 ~SENT_S2_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor3MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) +
                    SENT_O_S3_MTP_CMP1;

    /* Set the toggle time for MTPG output of Sensor 3 channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) &
                                 ~SENT_S3_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_setSensor4MTPToggleTime(uint32 mtpBase, uint32 compareNum, \
                            uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) +
                    SENT_O_S4_MTP_CMP1;

    /*  Set the toggle time for MTPG output of Sensor 4 channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) &
                                 ~SENT_S4_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_disableMTPChannel(uint32 mtpBase, Cdd_SentChannelType channel)
{
    VAR(uint32, AUTOMATIC) channelOffset;
	VAR(uint32, AUTOMATIC) SENT_MTP_CHANNEL_STEP = 0x100U;

    channelOffset = (SENT_MTP_CHANNEL_STEP * (uint32)channel) +
                    SENT_O_BC_MTP_EN;

    /* Disable the channel to generate trigger pulses. */

    HWREG(mtpBase + channelOffset) &= ~SENT_BC_MTP_EN_MTP_EN;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) 
Cdd_Sent_disableSentReceiver(uint32 base)
{
    /* Disable SENT receiver. */

    HWREG(base + SENT_O_RCFG) &= ~SENT_RCFG_RX_ENB;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) 
Cdd_Sent_EnableSentReceiver(uint32 base)
{
    /* Enable SENT reveiver to monitor the SENT bus. */
    HWREG(base + SENT_O_RCFG) |= SENT_RCFG_RX_ENB;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setTTClock(uint32 base, uint32 ttClock)
{
    /* Set the number of clock cycle per tick time. */

    HWREG(base + SENT_O_RCFG) = (HWREG(base + SENT_O_RCFG) &
                                ~SENT_RCFG_TTCLK_M) |
                                ((uint32)ttClock << SENT_RCFG_TTCLK_S);
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setGFILTClockCycle(uint32 base, uint32 gFiltClock)
{
    /* Set the number of clock cycle to be filtered out. */

    HWREG(base + SENT_O_RCFG2) = (HWREG(base + SENT_O_RCFG2) &
                                ~SENT_RCFG2_GFILT_M) |
                                ((uint32)gFiltClock << SENT_RCFG2_GFILT_S);
}

LOCAL_INLINE void
Sent_ConfigureFifoMode(uint32 base, Cdd_SentFIFOMode fifoMode)
{
    /* Configure FIFO Mode. */

    HWREG(base + SENT_O_RCFG2) = (HWREG(base + SENT_O_RCFG2) &
                                 ~SENT_RCFG2_FIFO_MODE) | (uint32)fifoMode;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_configureTimeout(uint32 base, uint32 timeOut)
{
    /* Configure the timeout for SENT module. */

    HWREG(base + SENT_O_CSENT_TO) = timeOut;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_enableInterrupt(uint32 base, uint32 intFlags)
{
    /* Enable the specified interrupt. */

    HWREG(base + SENT_O_REINT) |= intFlags;
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setDataNibble(uint32 base, Cdd_SentDataNibblesCount dataNibble)
{
    /* Set the number of data nibbles for standard SENT. */
    HWREG(base + SENT_O_RCFG) =
                            (HWREG(base + SENT_O_RCFG) & ~SENT_RCFG_RX_DNIB_M) |
                            (((uint32)dataNibble) << SENT_RCFG_RX_DNIB_S);
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_setRFIFOTriggerLevel(uint32 base, Cdd_SentTriggerLevel triggerLevel)
{
    /* Configure the trigger level for the receiver FIFO trigger interrupt and */
    /* DMA trigger. */

    HWREG(base + SENT_O_RCFG2) = (HWREG(base + SENT_O_RCFG2) &
                        ~SENT_RCFG2_RFIFO_TRIGLEV_M) |
                        ((uint32)triggerLevel << SENT_RCFG2_RFIFO_TRIGLEV_S);
}

LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
Cdd_Sent_getFIFO(uint32 base)
{
    /* Return the received SENT fast channel data located at the */
    /* top of the receive FIFO. */

    return(HWREG(base + SENT_O_RFDATA));
}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
Cdd_Sent_disableInterrupt(uint32 base, uint32 intFlags)
{
    /* Disable the specified interrupt. */

    HWREG(base + SENT_O_REINT) &= ~intFlags;
}

LOCAL_INLINE void
Cdd_Sent_setDataSortingFormat(uint32 base, Cdd_Sent_DataNumber dataNumber,
                        Cdd_SentNibbleNumber nibbleNum, Cdd_SentNibble nibble)
{
    uint32 dataOffset;
    uint32 shiftVal;

    dataOffset = ((uint32)SENT_DATAXMAP_STEP * (uint32)dataNumber) + (uint32)SENT_O_DATA0_MAP;
    shiftVal = (uint32)nibbleNum * (uint32)4;

    HWREG(base + dataOffset) = (HWREG(base + dataOffset) &
                        ~((uint32)SENT_DATA0_MAP_D0_NIB0_M << shiftVal)) |
                        ((uint32)nibble << shiftVal);

}

LOCAL_INLINE FUNC(void, CDD_SENT_CODE) \
Cdd_Sent_enableMTPSoftwareTrigger(uint32 SentBase, Cdd_SentChannelType channel)
{
    VAR(uint32, AUTOMATIC) triggerOffset;

    triggerOffset = (SENT_MTP_SWTR_STEP + (uint32)channel) +
                     SENT_O_BC_MTP_SWTR;

    /* Enable broadcast channel's software trigger. */

     HWREG(SentBase + triggerOffset) |= SENT_BC_MTP_SWTR_SWTR;
}
/*********************************************************************************************************************
 *
 *  Mark the end of the C bindings section for C++ compilers.
 *
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_SENT_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Priv.h
 *********************************************************************************************************************/
