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
 *  File:         Lin_GeneralTypes.h
 *  Generator:    None
 *
 *  Description:  This file contains the LIN MCAL driver private API's definitions specific to device
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
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
