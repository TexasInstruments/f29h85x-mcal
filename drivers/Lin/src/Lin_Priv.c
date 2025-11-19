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
 *  File:         Lin_Priv.c
 *  Generator:    None
 *
 *  Description:  This file contains the LIN MCAL driver private API's definitions specific to
 *device
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Lin_Priv.h"
#include "EcuM_Cbk.h"
#include "LinIf_Cbk.h"
#include "Mcal_Lib.h"
#include "Mcal_Lib_RegAccess.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*
 * Design : MCAL-25695, MCAL-25698, MCAL-25699
 */
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief  LIN IO DFT Key which when written in IODFTENA
 *          enables the User and Previledge mode Writes */
#define LIN_IO_DFT_KEY (0xAU)

/** \brief  LIN/SCI Wakeup signal is sent by sending an
 *          byte with value 0xF0 */
#define LIN_WAKEUP_KEY (0xF0U)

/** \brief  LIN/SCI Go To Sleep signal is sent by sending
 * commander request frame with identifier 0x3C (60),
 * with the first data field as 0x00 */
#define LIN_GOTOSLEEP_TD0KEY (0x00FFFFFFU)
#define LIN_GOTOSLEEP_TD1KEY (0xFFFFFFFFU)

/** \brief  Max data length of the LIN SDU */
#define LIN_MAX_DATA_LENGTH (8U)

/* SHIFT VALUES FOR LIN REGISTERS */

/* SCIGCR0 */

#define SCIGCR0_RESET_SHIFT (0U)

/* SCIGCR1 */
#define SCIGCR1_TXENA_SHIFT        (25U)
#define SCIGCR1_RXENA_SHIFT        (24U)
#define SCIGCR1_SWRESET_SHIFT      (7U)
#define SCIGCR1_CLKCOMMANDER_SHIFT (5U)
#define SCIGCR1_TIMINGMODE_SHIFT   (1U)
#define SCIGCR1_LINMODE_SHIFT      (6U)
#define SCIGCR1_ADAPT_SHIFT        (9U)
#define SCIGCR1_COMMMODE_SHIFT     (0U)
#define SCIGCR1_CONT_SHIFT         (17U)
#define SCIGCR1_HGENCTRL_SHIFT     (12U)
#define SCIGCR1_MBUF_SHIFT         (10U)
#define SCIGCR1_PARITYENA_SHIFT    (10U)
#define SCIGCR1_CTYPE_SHIFT        (11U)
#define SCIGCR1_LOOPBACK_SHIFT     (16U)

/* SCIGCR2 */
#define SCIGCR2_GENWU_SHIFT     (8U)
#define SCIGCR2_POWERDOWN_SHIFT (0U)
#define SCIGCR2_CC_SHIFT        (17U)

/* SCIFLR */
#define SCIFLR_WAKEUP_SHIFT (1U)

/* SCIPIO0 */
#define SCIPIO0_TXFUNC_SHIFT (2U)
#define SCIPIO0_RXFUNC_SHIFT (1U)

/* IODFTCTRL */
#define IODFTCTRL_LPBENA_SHIFT (1U)
#define IODFTCTRL_RXPENA_SHIFT (0U)

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
extern Lin_ChannelStatusType Lin_Channel_Status[LIN_MAX_CHANNEL];

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
/*
 *Design:
 */
#define LIN_START_SEC_VAR_INIT_PTR
#include "Lin_MemMap.h"
static P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) Lin_Drv_Config_Ptr = NULL_PTR;
#define LIN_STOP_SEC_VAR_INIT_PTR
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT_8
#include "Lin_MemMap.h"
static VAR(uint8, LIN_VAR) Lin_RxShadowBuffer[LIN_MAX_CHANNEL][LIN_MAX_DATA_LENGTH];
#define LIN_STOP_SEC_VAR_NO_INIT_8
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/** \brief Lin_DisableHWUnit - This API will disable Lin HW Unit.
 *
 * \param[in] base Base address of Lin Instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_DisableHWUnit(uint32 base);

/** \brief Lin_EnableHWUnit - This API will enable Lin HW Unit.
 *
 * \param[in] base Base address of Lin Instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnableHWUnit(uint32 base);

/** \brief Lin_EnterSoftwareReset - This API will make Lin enter software reset mode.
 *
 * \param[in] base Base address of Lin Instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnterSoftwareReset(uint32 base);

/** \brief Lin_ExitSoftwareReset - This API will make Lin exit software reset mode.
 *
 * \param[in] base Base address of Lin Instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ExitSoftwareReset(uint32 base);

/** \brief Lin_SetLinMode - This API will configure the HW unit to run in Lin mode.
 *
 * \param[in] base Base address of Lin Instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetLinMode(uint32 base);

/** \brief Lin_SetSyncFields - This API will configure Sync Field values.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] syncBreak Value of Sync Break to be configured
 * \param[in] delimiter Value of delimiter to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetSyncFields(uint32 base, uint16 syncBreak, uint16 delimiter);

/** \brief Lin_SetTxMask - This API will configure Tx mask for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] mask Mask value to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetTxMask(uint32 base, uint16 mask);

/** \brief Lin_SetRxMask - This API will configure Rx mask for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] mask Mask value to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetRxMask(uint32 base, uint16 mask);

/** \brief Lin_SetBaudrateConfig - This API will configure baudrate for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] baudrateconfig Pointer to baudrate config
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE)
    Lin_SetBaudrateConfig(uint32 base, P2CONST(Lin_BaudRateConfigType, AUTOMATIC, LIN_APPL_CONST) baudrateconfig);

/** \brief Lin_SetFrameLength - This API will set framelength for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] length Length of frame
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetFrameLength(uint32 base, uint16 length);

/** \brief Lin_SetChecksumType - This API will set checksum type for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] type Type of checksum to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetChecksumType(uint32 base, Lin_FrameCsModelType type);

/** \brief Lin_SetIDByte - This API will set ID byte type for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] identifier ID Type to be configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetIDByte(uint32 base, Lin_FramePidType identifier);

/** \brief Lin_EnableInterrupt - This API will enable interrupts for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] intrLineNum Interrupt line to be selected
 * \param[in] intFlags Interrupts to be selected
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnableInterrupt(uint32 base, Lin_InterruptLineNum intrLineNum, uint32 intFlags);

/** \brief Lin_DisableInterrupt - This API will disable interrupts for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] intFlags Interrupts to be selected
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_DisableInterrupt(uint32 base, uint32 intFlags);

/** \brief Lin_ServiceInterrupts - This API will Service Lin interrupts for selected Interrupt line
 *and will clear the interrupt flags.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] int_line Interrupt line
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ServiceInterrupts(uint32 base, Lin_InterruptLineNum int_line);

/** \brief Lin_SetLoopbackMode - This API will set loopback mode for Lin instance.
 *
 * \param[in] base Base address of Lin Instance.
 * \param[in] loopbackMode Loopback mode to be selected
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, LIN_CODE) Lin_SetLoopbackMode(uint32 base, Lin_LoopbackModeType loopbackMode);

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*
 * Design: MCAL-25669
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_InitInternal(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) Lin_ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) failcountflag         = 0U;

    for (uint8 channel_idx = (uint8)0U; channel_idx < (uint8)LIN_MAX_CHANNEL; channel_idx++)
    {
        /* Updating pointer of Driver Configuration to be used for ISR processing*/
        Lin_Drv_Config_Ptr = Lin_ConfigPtr;

        /* Init individual controller */
        return_value = Lin_HwUnitConfig(&Lin_ConfigPtr->linChannelCfg[channel_idx]);
        if (return_value == E_NOT_OK)
        {
            failcountflag = 1U;
        }
        else
        {
            Lin_Channel_Status[channel_idx].linChannelNetworkStatus = LIN_CHANNEL_SLEEP;
            Lin_EnterLowPowerMode(Lin_ConfigPtr->linChannelCfg[channel_idx].linControllerConfig.CntrAddr, TRUE);

            if (TRUE == Lin_ConfigPtr->linChannelCfg[channel_idx].linChannelWakeupSupport)
            {
                Lin_EnableWakeupDetection(&Lin_ConfigPtr->linChannelCfg[channel_idx], TRUE);
            }
            else
            {
                Lin_EnableWakeupDetection(&Lin_ConfigPtr->linChannelCfg[channel_idx], FALSE);
            }

            Lin_Channel_Status[channel_idx].linChannelActivityStatus = LIN_CHANNEL_IDLE;
        }
    }

    if (failcountflag == (uint32)1U)
    {
        return_value = E_NOT_OK;
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

/*
 * Design: MCAL-25670
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeupInternal(uint8 Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC)
    base = Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr;
    if ((uint8)LIN_CHANNEL_SLEEP == (uint8)Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        if ((boolean)TRUE == (boolean)Lin_CheckWakeupStatus(base))
        {
            /* Clear Wakeup Flag*/
            McalLib_RegMFWriteRaw32((base + LIN_O_SCIFLR), LIN_SCIFLR_WAKEUP, SCIFLR_WAKEUP_SHIFT, (uint32)TRUE);

            /* Wakeup event sent to ECU Manager */
            EcuM_SetWakeupEvent(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linWakeupSource);
            Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_OPERATIONAL;

            return_value = E_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }
    return return_value;
}

/*
 * Design: MCAL-25671
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupProcess(uint8 Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

    if ((uint8)LIN_CHANNEL_SLEEP == (uint8)Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        Lin_EnterLowPowerMode(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, FALSE);
        Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_OPERATIONAL;

        /* Enable transmit and receive bits. */
        McalLib_RegWriteRaw32(
            (Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr +
                                         LIN_O_SCIGCR1) |
                (uint32)LIN_SCIGCR1_TXENA | (uint32)LIN_SCIGCR1_RXENA);

        /* Set Mask ID for TX to not Send any message*/
        Lin_SetTxMask(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, 0x00U);

        /* Set Mask ID for RX */
        Lin_SetRxMask(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, 0x00U);

        /*
         * Set the message ID to initiate a header transmission.
         * This causes the ID to be written to the bus followed by the
         * data in the transmit buffers.
         */
        Lin_SetIDByte(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, LIN_WAKEUP_ID);

        return_value = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return (return_value);
}

/*
 * Design: MCAL-25672
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternalProcess(uint8 Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    if ((uint8)LIN_CHANNEL_SLEEP == (uint8)Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        Lin_EnterLowPowerMode(Lin_Drv_Config_Ptr->linChannelCfg[Channel].linControllerConfig.CntrAddr, FALSE);
        Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_OPERATIONAL;

        return_value = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return (return_value);
}

/*
 * Design : MCAL-25553,MCAL-25564,MCAL-25573,MCAL-25582
 */
FUNC(Lin_StatusType, LIN_CODE)
Lin_GetStatusInternalProcess(uint8 Channel, P2VAR(uint8 *, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr,
                             P2CONST(uint32, AUTOMATIC, LIN_CONFIG_DATA) lin_cnt_base_addr)
{
    VAR(Lin_StatusType, AUTOMATIC) return_value = LIN_NOT_OK;

    if (LIN_CHANNEL_OPERATIONAL == Lin_Channel_Status[Channel].linChannelNetworkStatus)
    {
        return_value = Lin_GetStatusInternal(Channel, Lin_SduPtr, lin_cnt_base_addr);
    }
    else if ((LIN_CHANNEL_SLEEP == Lin_Channel_Status[Channel].linChannelNetworkStatus))
    {
        return_value = LIN_CH_SLEEP;
    }
    else if ((LIN_CHANNEL_SLEEP_PENDING == Lin_Channel_Status[Channel].linChannelNetworkStatus))
    {
        Lin_Channel_Status[Channel].linChannelNetworkStatus = LIN_CHANNEL_SLEEP;
        return_value                                        = LIN_CH_SLEEP;
    }
    else
    {
        /* Do Nothing */
    }

    return return_value;
}

/*
 * Design : MCAL-25673
 */
FUNC(Lin_StatusType, LIN_CODE)
Lin_GetStatusInternal(uint8 Channel, P2VAR(uint8 *, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr,
                      P2CONST(uint32, AUTOMATIC, LIN_CONFIG_DATA) lin_cnt_base_addr)
{
    VAR(Lin_StatusType, AUTOMATIC) return_value = LIN_NOT_OK;
    switch (Lin_Channel_Status[Channel].linChannelActivityStatus)
    {
        case LIN_CHANNEL_IDLE:
            return_value = LIN_OPERATIONAL;
            break;

        case LIN_CHANNEL_TX_STARTED:

            return_value = Lin_FetchTxStatus(*lin_cnt_base_addr);

            if (LIN_TX_OK == return_value)
            {
                Lin_Channel_Status[Channel].linChannelActivityStatus = LIN_CHANNEL_IDLE;
            }
            else if ((LIN_TX_HEADER_ERROR == return_value) || (LIN_TX_ERROR == return_value))
            {
                Lin_Channel_Status[Channel].linChannelActivityStatus = LIN_CHANNEL_IDLE;
            }
            else
            {
                /* Do Nothing */
            }
            break;

        case LIN_CHANNEL_RX_STARTED:

            return_value = Lin_FetchRxStatus(*lin_cnt_base_addr);

            if (LIN_RX_OK == return_value)
            {
                Lin_GetData((uint32)Channel, *lin_cnt_base_addr, Lin_SduPtr);
                Lin_Channel_Status[Channel].linChannelActivityStatus = LIN_CHANNEL_IDLE;
            }
            else if ((LIN_RX_NO_RESPONSE == return_value) || (LIN_RX_ERROR == return_value))
            {
                Lin_Channel_Status[Channel].linChannelActivityStatus = LIN_CHANNEL_IDLE;
            }
            else
            {
                /* Do Nothing */
            }

            break;

        default:
            /* Do Nothing */
            break;
    }
    return return_value;
}

/*
 * Design: MCAL-25676
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_HwUnitConfig(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel)
{
    VAR(uint32, AUTOMATIC) lin_cnt_base_addr    = linChannel->linControllerConfig.CntrAddr;
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

    if ((linChannel->linBaudConfig.BaudRate >= (uint32)1000U) && (linChannel->linBaudConfig.BaudRate <= (uint32)20000U))
    {
        /* Reset LIN HW Unit */
        Lin_DisableHWUnit(lin_cnt_base_addr);
        Lin_EnableHWUnit(lin_cnt_base_addr);

        /* Enter Software Reset State */
        Lin_EnterSoftwareReset(lin_cnt_base_addr);

        /* Enable Lin Mode and configure as Master Node */
        Lin_SetLinMode(lin_cnt_base_addr);

        /* Set Loopback Mode */
        Lin_SetLoopbackMode(lin_cnt_base_addr, linChannel->linControllerConfig.LoopbackMode);

        /* Set Baudrate */
        Lin_SetBaudrateConfig(lin_cnt_base_addr, &linChannel->linBaudConfig);

        /*
         * Configure sync field
         * Sync break (13 + 5 = 18 Tbits)
         * Sync delimiter (1 + 3 = 4 Tbits)
         */
        Lin_SetSyncFields(lin_cnt_base_addr, 5U, 3U);

        /* Exit Software Reset State */
        Lin_ExitSoftwareReset(lin_cnt_base_addr);

        return_value = E_OK;
    }
    else
    {
        /* Do Nothing. Return E_NOT_OK */
    }

    return return_value;
}

/*
 * Design : MCAL-25677
 */
FUNC(Std_ReturnType, LIN_CODE)
Lin_SendData(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_DATA) linChannel,
             P2VAR(Lin_ChannelActivityStatusType, AUTOMATIC, LIN_APPL_DATA) linChannelActivityStatus,
             P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pduInfoPtr)
{
    VAR(uint32, AUTOMATIC) lin_cnt_base_addr    = linChannel->linControllerConfig.CntrAddr;
    uint8 *p_data                               = NULL_PTR;
    VAR(uint8, AUTOMATIC) length                = pduInfoPtr->Dl;
    VAR(uint8, AUTOMATIC) data_length           = 0U;
    VAR(sint8, AUTOMATIC) i                     = 0;
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

    if (LIN_CHANNEL_IDLE != *linChannelActivityStatus)
    {
        Lin_AbortTransmission(lin_cnt_base_addr);
        *linChannelActivityStatus = LIN_CHANNEL_IDLE;
    }
    else
    {
        /* Do Nothing */
    }

    /* Set Checksum Type*/
    Lin_SetChecksumType(lin_cnt_base_addr, pduInfoPtr->Cs);

    if ((LIN_MASTER_RESPONSE == pduInfoPtr->Drc) && (length != 0U))
    {
        /* Enable transmit bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_TXENA);

        /* Enable receive bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_RXENA);

        /* Set Mask ID for TX */
        Lin_SetTxMask(lin_cnt_base_addr, (uint16)pduInfoPtr->Pid);

        /* Set Mask ID for RX to not accept any message as we don't need to read the message */
        Lin_SetRxMask(lin_cnt_base_addr, 0x00U);

        /*
         * Set the frame length (number of bytes to be transmitted)
         */
        Lin_SetFrameLength(lin_cnt_base_addr, (uint16)length);

        /*
         * Set the message ID to initiate a header transmission.
         * This causes the ID to be written to the bus followed by the
         * data in the transmit buffers.
         */
        Lin_SetIDByte(lin_cnt_base_addr, pduInfoPtr->Pid);

        data_length = (length - (uint8)1U);
        p_data      = ((uint8 *)pduInfoPtr->SduPtr + data_length);

        /* Shift each 8-bit piece of data into the correct register. */
        for (i = (sint8)data_length; i >= 0; i--)
        {
            McalLib_RegWriteRaw8(lin_cnt_base_addr + (uint8)LIN_O_TD0 + ((uint8)i ^ (uint8)3U), *p_data);
            p_data--;
        }

        *linChannelActivityStatus = LIN_CHANNEL_TX_STARTED;
        return_value              = E_OK;
    }
    else if ((LIN_SLAVE_RESPONSE == pduInfoPtr->Drc) && (length != 0U))
    {
        /* Enable transmit bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_TXENA);

        /* Enable receive bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_RXENA);

        /*
         * Set the frame length (number of bytes to be received)
         */
        Lin_SetFrameLength(lin_cnt_base_addr, (uint16)length);

        /* Set Mask ID for TX to not Send any message*/
        Lin_SetTxMask(lin_cnt_base_addr, 0x00U);

        /* Set Mask ID for RX */
        Lin_SetRxMask(lin_cnt_base_addr, (uint16)pduInfoPtr->Pid);

        /*
         * Set the message ID to initiate a header transmission.
         * This causes the ID to be written to the bus followed by the
         * data in the transmit buffers.
         */
        Lin_SetIDByte(lin_cnt_base_addr, pduInfoPtr->Pid);

        *linChannelActivityStatus = LIN_CHANNEL_RX_STARTED;
        return_value              = E_OK;
    }
    else if (LIN_SLAVE_TO_SLAVE == pduInfoPtr->Drc)
    {
        /* Enable transmit bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_TXENA);

        /* Enable receive bit. */
        McalLib_RegWriteRaw32(
            (lin_cnt_base_addr + LIN_O_SCIGCR1),
            (uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_RXENA);

        /* Set Mask ID for RX to not accept any message as we don't need to read the message */
        Lin_SetRxMask(lin_cnt_base_addr, 0x00U);

        /*
         * Set the message ID to initiate a header transmission.
         * This causes the ID to be written to the bus followed by the
         * data in the transmit buffers.
         */
        Lin_SetIDByte(lin_cnt_base_addr, pduInfoPtr->Pid);

        return_value = E_OK;
    }
    else
    {
        /* Do Nothing */
    }

    return return_value;
}

/*
 * Design: MCAL-25678
 */
FUNC(void, LIN_CODE)
Lin_GetData(uint32 channelID, uint32 base, P2VAR(uint8 *, AUTOMATIC, LIN_APPL_CONST) sduPtr)
{
    VAR(uint32, AUTOMATIC) length = 0U;

    /* Set Sdu pointer to the address of corresponding shadow buffer */
    *sduPtr = Lin_RxShadowBuffer[channelID];

    /* Get the length from the SCIFORMAT register. */
    length = ((uint32)((uint32)McalLib_RegReadRaw32(base + LIN_O_SCIFORMAT) & (uint32)LIN_SCIFORMAT_LENGTH_M) >>
              (uint32)LIN_SCIFORMAT_LENGTH_S);

    /* Read each data Byte by Byte. */
    for (uint8 i = (uint8)0U; i <= (uint8)length; i++)
    {
        Lin_RxShadowBuffer[channelID][i] = McalLib_RegReadRaw8(base + LIN_O_RD0 + ((uint32)i ^ 3U));
    }
}

/*
 * Design: MCAL-25674
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_FetchTxStatus(uint32 base)
{
    VAR(Lin_StatusType, AUTOMATIC) return_value = LIN_TX_BUSY;
    VAR(uint32, AUTOMATIC) reg_val              = McalLib_RegReadRaw32(base + LIN_O_SCIFLR);

    if (((reg_val & LIN_SCIFLR_PBE) == LIN_SCIFLR_PBE))
    {
        return_value = LIN_TX_HEADER_ERROR;
    }
    else if ((reg_val & LIN_SCIFLR_BE) == LIN_SCIFLR_BE)
    {
        return_value = LIN_TX_ERROR;
    }
    else if ((reg_val & LIN_SCIFLR_TXEMPTY) == LIN_SCIFLR_TXEMPTY)
    {
        return_value = LIN_TX_OK;
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear status bits after read */
    McalLib_RegWriteRaw32((base + LIN_O_SCIFLR), reg_val);
    return return_value;
}

/*
 * Design: MCAL-25675
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_FetchRxStatus(uint32 base)
{
    VAR(Lin_StatusType, AUTOMATIC) return_value = LIN_RX_BUSY;
    VAR(uint32, AUTOMATIC) reg_val              = McalLib_RegReadRaw32(base + LIN_O_SCIFLR);

    if ((reg_val & LIN_SCIFLR_NRE) == LIN_SCIFLR_NRE)
    {
        return_value = LIN_RX_NO_RESPONSE;
    }
    /* TI_COVERAGE_GAP_START [MC/DC Gap] in RX status, Overrun, Parity, and Frame error can't be
     * reproduced by S/W*/
    else if (((reg_val & LIN_SCIFLR_CE) == LIN_SCIFLR_CE) || ((reg_val & LIN_SCIFLR_OE) == LIN_SCIFLR_OE) ||
             ((reg_val & LIN_SCIFLR_PE) == LIN_SCIFLR_PE) || ((reg_val & LIN_SCIFLR_FE) == LIN_SCIFLR_FE))
    /* TI_COVERAGE_GAP_STOP*/
    {
        return_value = LIN_RX_ERROR;
    }
    else if ((reg_val & LIN_SCIFLR_RXRDY) == LIN_SCIFLR_RXRDY)
    {
        return_value = LIN_RX_OK;
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear status bits after read */
    McalLib_RegWriteRaw32((base + LIN_O_SCIFLR), reg_val);

    return return_value;
}

/*
 * Design : MCAL-25679
 */
FUNC(void, LIN_CODE) Lin_SendWakeupSignal(uint32 base)
{
    /* Set key in Byte 0 (MSB) of transmit buffer 0 register */
    McalLib_RegMFWriteRaw32((base + LIN_O_TD0), LIN_TD0_TD0_M, LIN_TD0_TD0_S, (uint16)LIN_WAKEUP_KEY);

    /* Transmit TDO for wakeup */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR2), LIN_SCIGCR2_GENWU, SCIGCR2_GENWU_SHIFT, (uint32)TRUE);
}

/*
 * Design : MCAL-25680
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_SendGoToSleepSignal(uint32 base)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = E_NOT_OK;
    VAR(uint32, AUTOMATIC) reg_val              = 0U;
#ifdef LIN_TIMEOUT_DURATION
    VAR(uint32, AUTOMATIC) timeout_duration = LIN_TIMEOUT_DURATION;
#endif

    /* Enable transmit bit. */
    McalLib_RegWriteRaw32((base + LIN_O_SCIGCR1),
                          (uint32)McalLib_RegReadRaw32(base + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_TXENA);

    /* Enable receive bit. */
    McalLib_RegWriteRaw32((base + LIN_O_SCIGCR1),
                          (uint32)McalLib_RegReadRaw32(base + LIN_O_SCIGCR1) | (uint32)LIN_SCIGCR1_RXENA);

    /* Set Mask ID for TX for GoToSleep Command*/
    Lin_SetTxMask(base, 0x3CU);

    /* Set Mask ID for RX to not accept any message as we don't need to read the message */
    Lin_SetRxMask(base, 0x00U);

    /*
     * Set the frame length (number of bytes to be transmitted)
     */
    Lin_SetFrameLength(base, 0x8U);

    /* Set key in Byte 0 (MSB) of transmit buffer 0 register
     * For Go to Sleep Command, the first Byte should be 0 and remaining byte Should be 0xFF
     */
    McalLib_RegWriteRaw32((base + LIN_O_TD1), (uint32)LIN_GOTOSLEEP_TD1KEY);
    McalLib_RegWriteRaw32((base + LIN_O_TD0), (uint32)LIN_GOTOSLEEP_TD0KEY);
    /*
     * Set the message ID as 60 OR 0x3C to initiate a header transmission.
     * This causes the ID to be written to the bus followed by the
     * data in the transmit buffers.
     */
    Lin_SetIDByte(base, 0x3CU);

#ifdef LIN_TIMEOUT_DURATION
    while (timeout_duration > 0U)
    {
        reg_val = McalLib_RegReadRaw32(base + LIN_O_SCIFLR);
        if ((reg_val & LIN_SCIFLR_TXEMPTY) == LIN_SCIFLR_TXEMPTY)
        {
            return_value = E_OK;
            break;
        }
        else
        {
            McalLib_Delay(LIN_MCAL_LIB_DELAY);
            timeout_duration--;
            /* Wait for TX Ready flag */
        }
    }
#else
    return_value = E_OK;
#endif

    return return_value;
}

/*
 * Design : MCAL-25681
 */
FUNC(void, LIN_CODE) Lin_EnterLowPowerMode(uint32 base, boolean enable)
{
    /* Entering Powerdown */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR2), LIN_SCIGCR2_POWERDOWN, SCIGCR2_POWERDOWN_SHIFT, (uint32)enable);
}

/*
 * Design : MCAL-25682
 */
FUNC(boolean, LIN_CODE) Lin_CheckWakeupStatus(uint32 base)
{
    return (((uint32)McalLib_RegReadRaw32(base + LIN_O_SCIGCR2) & (uint32)LIN_SCIGCR2_POWERDOWN) !=
            (uint32)LIN_SCIGCR2_POWERDOWN);
}

/*
 * Design : MCAL-25683
 */
FUNC(void, LIN_CODE) Lin_AbortTransmission(uint32 base)
{
    /* NOTE: Current Lin IP doesn't support aborting communication once message
        transmission / reception is started. */

    /* Disable transmit bit. */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_TXENA, SCIGCR1_TXENA_SHIFT, (uint32)FALSE);

    /* Disable receive bit. */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_RXENA, SCIGCR1_RXENA_SHIFT, (uint32)FALSE);
}

/*
 * Design : MCAL-25684
 */
FUNC(void, LIN_CODE)
Lin_EnableWakeupDetection(P2CONST(Lin_ChannelType, AUTOMATIC, LIN_APPL_CONST) linChannel, boolean enable)
{
    if (TRUE == enable)
    {
        Lin_EnableInterrupt(linChannel->linControllerConfig.CntrAddr, linChannel->linControllerConfig.IntrLineNum,
                            LIN_INT_WAKEUP);
    }
    else
    {
        Lin_DisableInterrupt(linChannel->linControllerConfig.CntrAddr, LIN_INT_WAKEUP);
    }
}

/*
 * Design : MCAL-25541 ,MCAL-25685
 */
FUNC(void, LIN_CODE) Lin_ProcessISR(uint32 channelID)
{
    VAR(uint32, AUTOMATIC)
    lin_cnt_base_addr             = Lin_Drv_Config_Ptr->linChannelCfg[channelID].linControllerConfig.CntrAddr;
    Lin_InterruptLineNum int_line = Lin_Drv_Config_Ptr->linChannelCfg[channelID].linControllerConfig.IntrLineNum;

    if ((TRUE == Lin_Drv_Config_Ptr->linChannelCfg[channelID].linChannelWakeupSupport) &&
        ((((uint32)McalLib_RegReadRaw32(lin_cnt_base_addr + LIN_O_SCIFLR) & (uint32)LIN_SCIFLR_WAKEUP) ==
          (uint32)LIN_SCIFLR_WAKEUP)))
    {
        /* Come out of low power mode */
        Lin_EnterLowPowerMode(lin_cnt_base_addr, FALSE);

        /* Service Interrupt */
        Lin_ServiceInterrupts(lin_cnt_base_addr, int_line);

        /* Notify EcuM */
        EcuM_CheckWakeup(Lin_Drv_Config_Ptr->linChannelCfg[channelID].linWakeupSource);
        /* Send WakeUp Confirmation to LinIf */
        LinIf_WakeupConfirmation(Lin_Drv_Config_Ptr->linChannelCfg[channelID].linWakeupSource);
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
 * Design : MCAL-28463
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_DisableHWUnit(uint32 base)
{
    /* Disable TX and RX pin control functionality. */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIPIO0), LIN_SCIPIO0_RXFUNC, SCIPIO0_RXFUNC_SHIFT, (uint32)FALSE);
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIPIO0), LIN_SCIPIO0_TXFUNC, SCIPIO0_TXFUNC_SHIFT, (uint32)FALSE);

    /* Reset reset bit. SCIGCR0 Register Offset = 0x0U */
    McalLib_RegMFWriteRaw32(base, LIN_SCIGCR0_RESET, SCIGCR0_RESET_SHIFT, (uint32)FALSE);
}

/*
 * Design : MCAL-28464
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnableHWUnit(uint32 base)
{
    /* Set reset bit. SCIGCR0 Register Offset = 0x0U*/
    McalLib_RegMFWriteRaw32((base), LIN_SCIGCR0_RESET, SCIGCR0_RESET_SHIFT, (uint32)TRUE);

    /* Disable TX and RX pin control functionality. */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIPIO0), LIN_SCIPIO0_RXFUNC, SCIPIO0_RXFUNC_SHIFT, (uint32)TRUE);
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIPIO0), LIN_SCIPIO0_TXFUNC, SCIPIO0_TXFUNC_SHIFT, (uint32)TRUE);
}

/*
 * Design : MCAL-28465
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnterSoftwareReset(uint32 base)
{
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_SWNRST, SCIGCR1_SWRESET_SHIFT, (uint32)FALSE);
}

/*
 * Design : MCAL-28466
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ExitSoftwareReset(uint32 base)
{
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_SWNRST, SCIGCR1_SWRESET_SHIFT, (uint32)TRUE);
}

/*
 * Design : MCAL-25686
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetLinMode(uint32 base)
{
    /* Program Timing Mode bit */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_TIMINGMODE, SCIGCR1_TIMINGMODE_SHIFT, (uint32)FALSE);

    /* Set Mode as LIN */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_LINMODE, SCIGCR1_LINMODE_SHIFT, (uint32)TRUE);

    /* Program LIN Mode to Master */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_CLK_COMMANDER, SCIGCR1_CLKCOMMANDER_SHIFT,
                            (uint32)TRUE);

    /* Disable Automatic Baudrate Adjustment */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_ADAPT, SCIGCR1_ADAPT_SHIFT, (uint32)FALSE);

    /* Write communication mode selection to the appropriate bit - will use the length set during
     * Lin_SendFrame */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_COMMMODE, SCIGCR1_COMMMODE_SHIFT, (uint32)FALSE);

    /* Set Debug Suspend mode - Complete Tx/Rx before Freezing*/
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_CONT, SCIGCR1_CONT_SHIFT, (uint32)TRUE);

    /* Sets the message filtering type - Filtering uses LIN message ID Byte */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_HGENCTRL, SCIGCR1_HGENCTRL_SHIFT, (uint32)FALSE);

    /* Enable Multi-buffer Mode */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_MBUFMODE, SCIGCR1_MBUF_SHIFT, (uint32)TRUE);

    /* Enable the parity mode */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_PARITYENA, SCIGCR1_PARITYENA_SHIFT, (uint32)TRUE);

    /* Comparing the Check Sum */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR2), LIN_SCIGCR2_CC, SCIGCR2_CC_SHIFT, (uint32)TRUE);

    /* Set LIN interrupts to disabled */
    Lin_DisableInterrupt(base, LIN_INT_ALL);
}

/*
 * Design : MCAL-28467
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetSyncFields(uint32 base, uint16 syncBreak, uint16 delimiter)
{
    /* Clear sync values and set new values */
    McalLib_RegMFWriteRaw32((base + LIN_O_COMP), (LIN_COMP_SDEL_M | LIN_COMP_SBREAK_M), LIN_COMP_SDEL_S,
                            ((uint32)syncBreak | ((uint32)delimiter - 1U)));

    McalLib_RegWriteRaw32((base + LIN_O_COMP), ((uint32)syncBreak | (((uint32)delimiter - 1U) << LIN_COMP_SDEL_S)));
}

/*
 * Design : MCAL-28468
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetTxMask(uint32 base, uint16 mask)
{
    /* Clear previous mask value and set new mask */
    McalLib_RegMFWriteRaw32((base + LIN_O_MASK), LIN_MASK_TXIDMASK_M, LIN_MASK_TXIDMASK_S, (uint32)mask);
}

/*
 * Design : MCAL-28469
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetRxMask(uint32 base, uint16 mask)
{
    /* Clear previous mask value and set new mask */
    McalLib_RegMFWriteRaw32((base + LIN_O_MASK), LIN_MASK_RXIDMASK_M, LIN_MASK_RXIDMASK_S, (uint32)mask);
}

/*
 * Design : MCAL-28470
 */
LOCAL_INLINE FUNC(void, LIN_CODE)
    Lin_SetBaudrateConfig(uint32 base, P2CONST(Lin_BaudRateConfigType, AUTOMATIC, LIN_APPL_CONST) baudrateconfig)
{
    /* Set baud rate prescaler and divider. */
    McalLib_RegWriteRaw32((base + LIN_O_BRSR),
                          (baudrateconfig->Prescalar | (baudrateconfig->FractionalDivider << LIN_BRSR_M_S)));
}

/*
 * Design : MCAL-28471
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetFrameLength(uint32 base, uint16 length)
{
    /* Clear and set frame length value */
    McalLib_RegMFWriteRaw32((base + LIN_O_SCIFORMAT), LIN_SCIFORMAT_LENGTH_M, LIN_SCIFORMAT_LENGTH_S,
                            ((uint32)length - (uint32)1U));
}

/*
 * Design : MCAL-28472
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetChecksumType(uint32 base, Lin_FrameCsModelType type)
{
    /* Set checksum type. */
    if (LIN_ENHANCED_CS == type)
    {
        McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_CTYPE, SCIGCR1_CTYPE_SHIFT, (uint32)1);
    }
    else
    {
        McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_CTYPE, SCIGCR1_CTYPE_SHIFT, (uint32)0);
    }
}

/*
 * Design : MCAL-28473
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetIDByte(uint32 base, Lin_FramePidType identifier)
{
    McalLib_RegMFWriteRaw32((base + LIN_O_ID), LIN_ID_IDBYTE_M, LIN_ID_IDBYTE_S, (uint32)identifier);
}

/*
 * Design : MCAL-28474
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_EnableInterrupt(uint32 base, Lin_InterruptLineNum intrLineNum, uint32 intFlags)
{
    /* Set Interrupt Flags */
    McalLib_RegWriteRaw32((base + LIN_O_SCISETINT),
                          (uint32)McalLib_RegReadRaw32(base + LIN_O_SCISETINT) | (uint32)intFlags);

    if (LIN_INTERRUPT_LINE_NUM_1 == intrLineNum)
    {
        /* Set interrupt levels to 1 */
        McalLib_RegWriteRaw32((base + LIN_O_SCISETINTLVL),
                              (uint32)McalLib_RegReadRaw32(base + LIN_O_SCISETINTLVL) | (uint32)intFlags);

        HWREGB(base + LIN_O_GLB_INT_EN) |= (uint8)(LIN_GLB_INT_EN_GLBINT0_EN << (uint8)intrLineNum);
    }
    else
    {
        /* Set interrupt levels to 0 */
        McalLib_RegWriteRaw32((base + LIN_O_SCICLEARINTLVL), intFlags);
        HWREGB(base + LIN_O_GLB_INT_EN) |= (uint8)(LIN_GLB_INT_EN_GLBINT0_EN << (uint8)intrLineNum);
    }
}

/*
 * Design : MCAL-28476
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_DisableInterrupt(uint32 base, uint32 intFlags)
{
    /* Clear Interrupt Flags */
    McalLib_RegWriteRaw32((base + LIN_O_SCICLEARINT), intFlags);
}

/*
 * Design : MCAL-28477
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ServiceInterrupts(uint32 base, Lin_InterruptLineNum int_line)
{
    /* Clear All the Interrupt Flags in SCIFLR */
    HWREG(base + LIN_O_SCIFLR) = LIN_INT_ALL;

    /* Read Interrupt Status Flag */
    HWREGH(base + LIN_O_SCIINTVECT0);

    /* Clear Global Interrupt Flag Bit */
    HWREGB(base + LIN_O_GLB_INT_CLR) = (uint8)LIN_GLB_INT_CLR_INT0_FLG_CLR << (uint8)(int_line);
}

/*
 * Design: MCAL-25687
 */
static FUNC(void, LIN_CODE) Lin_SetLoopbackMode(uint32 base, Lin_LoopbackModeType loopbackMode)
{
    switch (loopbackMode)
    {
        case LIN_LOOPBACK_DISABLED:

            /* Disable Internal Loopback */
            McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_LOOPBACK, SCIGCR1_LOOPBACK_SHIFT,
                                    (uint32)FALSE);

            /* Disable External Loopback */
            McalLib_RegMFWriteRaw32((base + LIN_O_IODFTCTRL), LIN_IODFTCTRL_LPBENA, IODFTCTRL_LPBENA_SHIFT,
                                    (uint32)FALSE);

            /* Set Analog Loopback Path */
            McalLib_RegMFWriteRaw32((base + LIN_O_IODFTCTRL), LIN_IODFTCTRL_RXPENA, IODFTCTRL_RXPENA_SHIFT,
                                    (uint32)FALSE);

            break;

        case LIN_LOOPBACK_INTERNAL:

            /* Enable Internal Loopback */
            McalLib_RegMFWriteRaw32((base + LIN_O_SCIGCR1), LIN_SCIGCR1_LOOPBACK, SCIGCR1_LOOPBACK_SHIFT, (uint32)TRUE);

            break;

        case LIN_LOOPBACK_EXTERNAL:

            /* Clear the IO DFT Enable Key */
            McalLib_RegMFWriteRaw32((base + LIN_O_IODFTCTRL), LIN_IODFTCTRL_IODFTENA_M, LIN_IODFTCTRL_IODFTENA_S,
                                    LIN_IO_DFT_KEY);

            /* Enable Digital External Loopback */
            McalLib_RegMFWriteRaw32((base + LIN_O_IODFTCTRL), LIN_IODFTCTRL_LPBENA, IODFTCTRL_LPBENA_SHIFT,
                                    (uint32)FALSE);

            /* Set Analog Loopback Path */
            McalLib_RegMFWriteRaw32((base + LIN_O_IODFTCTRL), LIN_IODFTCTRL_RXPENA, IODFTCTRL_RXPENA_SHIFT,
                                    (uint32)FALSE);

            break;

        default:
            break;
    }
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Lin_Priv.c
 *********************************************************************************************************************/
