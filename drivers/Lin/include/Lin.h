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
 *  File:       Lin.h
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Lin Driver functions
 *********************************************************************************************************************/
/*
 *Design: MCAL-25531
 */
#ifndef LIN_H
#define LIN_H
/**
 * \defgroup LIN Lin API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-25531, MCAL-25532, MCAL-25533, MCAL-25534
 */
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Lin_Cfg.h"
#include "EcuM_Cbk.h"
#include "Std_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*****************************************************************************
 *
 * Defines for LIN Driver version used for compatibility checks.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25697
 */
/** \brief Driver Implementation Major Version. */
#define LIN_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version. */
#define LIN_SW_MINOR_VERSION (1U)
/**  \brief Driver Implementation Patch Version. */
#define LIN_SW_PATCH_VERSION (0U)

/*****************************************************************************
 *
 * Defines for LIN Driver AUTOSAR version used for compatibility checks.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25697
 */
/** \brief AUTOSAR Major version specification implemented by LIN Driver. */
#define LIN_AR_RELEASE_MAJOR_VERSION (4U)

/** \brief AUTOSAR Minor version specification implemented by LIN Driver. */
#define LIN_AR_RELEASE_MINOR_VERSION (3U)

/** \brief AUTOSAR Patch version specification implemented by LIN Driver. */
#define LIN_AR_RELEASE_REVISION_VERSION (1U)

/*****************************************************************************
 *
 * LIN Driver ID Info.
 *
 *****************************************************************************/
/** \brief Texas Instruments Vendor ID. */
#define LIN_VENDOR_ID ((uint16)44U)
/** \brief LIN Driver Module ID. */
#define LIN_MODULE_ID ((uint16)82U)
/** \brief LIN Driver Instance ID. */
#define LIN_INSTANCE_ID ((uint8)0U)
/*****************************************************************************
 * LIN Error Codes returned by Driver functions.
 *****************************************************************************/
/*
 *Design: MCAL-25580
 */

/** \brief  API service used without module initialization. */
#ifndef LIN_E_UNINIT
#define LIN_E_UNINIT ((uint8)0x00U)
#endif

/** \brief  API service used with an invalid or inactive channel parameter. */
#ifndef LIN_E_INVALID_CHANNEL
#define LIN_E_INVALID_CHANNEL ((uint8)0x02U)
#endif

/** \brief API service called with invalid configuration pointer. */
#ifndef LIN_E_INVALID_POINTER
#define LIN_E_INVALID_POINTER ((uint8)0x03U)
#endif

/** \brief  Invalid state transition for the current state. */
#ifndef LIN_E_STATE_TRANSITION
#define LIN_E_STATE_TRANSITION ((uint8)0x04U)
#endif

/** \brief API service called with a NULL pointer. */
#ifndef LIN_E_PARAM_POINTER
#define LIN_E_PARAM_POINTER ((uint8)0x05U)
#endif

/*****************************************************************************
 * LIN Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 *
 *****************************************************************************/
/*
 *Design: MCAL-25587, MCAL-25696
 */
/** \brief Service ID - Lin_Init(). */
#define LIN_SID_INIT ((uint8)0x00U)
/** \brief Service ID - Lin_GetVersionInfo(). */
#define LIN_SID_GET_VERSION_INFO ((uint8)0x01U)
/** \brief Service ID - Lin_SendFrame(). */
#define LIN_SID_SEND_FRAME ((uint8)0x04U)
/** \brief Service ID - Lin_GoToSleep(). */
#define LIN_SID_GOTO_SLEEP ((uint8)0x06U)
/** \brief Service ID - Lin_Wakeup(). */
#define LIN_SID_WAKEUP ((uint8)0x07U)
/** \brief Service ID - Lin_GetStatus(). */
#define LIN_SID_GET_STATUS ((uint8)0x08U)
/** \brief Service ID -  Lin_GoToSleepInternal(). */
#define LIN_SID_GOTO_SLEEP_INTERNAL ((uint8)0x09U)
/** \brief Service ID - Lin_CheckWakeup(). */
#define LIN_SID_CHECK_WAKEUP ((uint8)0x0AU)
/** \brief Service ID - Lin_WakeupInternal(). */
#define LIN_SID_WAKEUP_INTERNAL ((uint8)0x0BU)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * LIN Driver ISR category level
 * Defines for LIN Driver ISR ISR category level
 *********************************************************************************************************************/
/** \brief Category 1 RT ISR type */
#define LIN_ISR_CAT1_RTINT (0x00U)
/** \brief Category 1 ISR type */
#define LIN_ISR_CAT1_INT (0x01U)
/** \brief Category 2 ISR type */
#define LIN_ISR_CAT2 (0x02U)

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*
 *Design: MCAL-25544,MCAL-25545,MCAL-25546,MCAL-25536,MCAL-25658
 */
/** \brief  Lin Channel type structure */
typedef struct Lin_ChannelTag
{
    /** \brief Lin Channel Wakeup Support */
    boolean linChannelWakeupSupport;

    /** \brief Lin Controller Config */
    Lin_ControllerType linControllerConfig;

    /** \brief Lin Baud Rate Config */
    Lin_BaudRateConfigType linBaudConfig;

    /** \brief Wakeup source to be set */
    EcuM_WakeupSourceType linWakeupSource;
} Lin_ChannelType;

/*
 * Design:   MCAL-25593
 */
/** \brief LIN Channel Configuration structure */
typedef struct Lin_ConfigTag
{
    /** \brief LIN Channel Configuration structure */
    Lin_ChannelType linChannelCfg[LIN_MAX_CHANNEL];
} Lin_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == LIN_GET_VERSION_INFO_API)
/** \brief Service to get the version information of the module.
 *
 * This service writes the version information of this module into the data
 * structure referenced by the parameter. If this parameter references
 * NULL_PTR, a development error is reported to Det. This service is only
 * available if the pre-compile configuration parameter LIN_GET_VERSION_INFO_API
 * is enabled.
 *
 * \param[out] versioninfo structure that contains the version information parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE)
Lin_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_DATA) versioninfo);
#endif

/** \brief Lin_Init - Initializes the LIN module.
 *
 * \param[in] Config Pointer to LIN driver configuration set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, LIN_CODE) Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_CONFIG_DATA) Config);

/** \brief Lin_CheckWakeup - This function checks if a wakeup has occurred on the addressed LIN
 *channel.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: No error has occurred during execution of the API
 * \retval E_NOT_OK: An error has occurred during execution of the API
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel);

/** \brief Lin_SendFrame - Sends a LIN header and a LIN response, if necessary. The direction of the
 *frame response (master response, slave response, slave-to-slave communication) is provided by the
 *PduInfoPtr.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \param[in] PduInfoPtr Pointer to PDU containing the PID, checksum model, response type, Dl and
 *SDU data pointer
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Send command has been accepted.
 * \retval E_NOT_OK: Send command has not been accepted, development or production error occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE)
Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);

/** \brief Lin_GoToSleep - The service instructs the driver to transmit a go-to-sleep-command on the
 *addressed LIN channel.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Sleep command has been accepted.
 * \retval E_NOT_OK: Sleep command has not been accepted, development or production error occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel);

/** \brief Lin_GoToSleepInternal - Sets the channel state to LIN_CH_SLEEP, enables the wake-up
 *detection and optionally sets the LIN hardware unit to reduced power operation mode.
 *
 * \param[in] Channel LIN channel to be addressed.
 * \pre None
 * \post None
 * \return return_value
 * \retval E_OK: Command has been accepted.
 * \retval E_NOT_OK: Command has not been accepted, development or production error occurred.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel);

/** \brief Lin_Wakeup - Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
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
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel);

/** \brief Lin_WakeupInternal - Generates a wake up pulse and sets the channel state to
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
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal(VAR(uint8, AUTOMATIC) Channel);

/** \brief Lin_GetStatus - Gets the status of the LIN driver.
 *
 * \param[in] Channel LIN channel to be addressed.
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
Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, P2VAR(uint8*, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* LIN_H */
/*********************************************************************************************************************
 *  End of File: Lin.h
 *********************************************************************************************************************/
