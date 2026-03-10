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
 *  File:         Lin_GeneralTypes.h
 *  Generator:    None
 *
 *  Description:  This file contains the LIN MCAL driver private API's definitions specific to device
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-25591, MCAL-25592
 */
#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

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
/*
 * Design: MCAL-25538
 */
/** \brief Lin Frame PID type */
typedef uint8 Lin_FramePidType;

/*
 * Design: MCAL-25538,MCAL-25547
 */
/** \brief Lin Frame Checksum type */
typedef enum Lin_FrameCsModelTag
{
   /** \brief Enhanced CheckSum */
   LIN_ENHANCED_CS,
   /** \brief Classic CheckSum */
   LIN_CLASSIC_CS
} Lin_FrameCsModelType;

/*
 * Design: MCAL-25538
 */
/** \brief Lin Frame response type */
typedef enum Lin_FrameResponseTag
{
   /** \brief Send data - Master Response */
   LIN_MASTER_RESPONSE,
   /** \brief Send data - Slave Response */
   LIN_SLAVE_RESPONSE,
   /** \brief Send data - Slave to Slave */
   LIN_SLAVE_TO_SLAVE
} Lin_FrameResponseType;

/*
 * Design: MCAL-25538,MCAL-25548
 */
/** \brief Lin Frame Data Length */
typedef uint8 Lin_FrameDlType;

/*
 * Design: MCAL-25538,MCAL-25547,MCAL-25548
 */
/** \brief Lin Pdu Type */
typedef struct Lin_PduTag
{
   /** \brief Lin Pid/Message ID */
   Lin_FramePidType Pid;
   /** \brief Lin CheckSum Type */
   Lin_FrameCsModelType Cs;
   /** \brief Lin Frame response type */
   Lin_FrameResponseType Drc;
   /** \brief Data Length */
   Lin_FrameDlType Dl;
   /** \brief Sdu Pointer buffer to hold data */
   uint8* SduPtr;
} Lin_PduType;

/*
 * Design: MCAL-25538
 */
/** \brief Lin Module Status Type */
typedef enum Lin_StatusTag
{
   /** \brief Lin Status - Development or production error occurred */
   LIN_NOT_OK,
   /** \brief Lin Status - Successful transmission. */
   LIN_TX_OK,
   /** \brief Lin Status - Ongoing transmission (Header or Response) */
   LIN_TX_BUSY,
   /** \brief Lin Status - Error in Header Transmission */
   LIN_TX_HEADER_ERROR,
   /** \brief Lin Status - Error in data Transmission */
   LIN_TX_ERROR,
   /** \brief Lin Status - Reception of correct response. */
   LIN_RX_OK,
   /** \brief Lin Status - Ongoing reception */
   LIN_RX_BUSY,
   /** \brief Lin Status - Error in Response reception */
   LIN_RX_ERROR,
   /** \brief Lin Status - No response byte has been received so far. */
   LIN_RX_NO_RESPONSE,
   /** \brief Lin Status - LIN channel is ready to transmit next header. */
   LIN_OPERATIONAL,
   /** \brief Lin Status - Sleep state operation. */
   LIN_CH_SLEEP
} Lin_StatusType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* LIN_GENERALTYPES_H */
/*********************************************************************************************************************
 *  End of File: Lin_GeneralTypes.h
 *********************************************************************************************************************/
