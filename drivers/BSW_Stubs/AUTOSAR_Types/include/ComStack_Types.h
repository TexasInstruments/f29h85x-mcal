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
 *  File:       ComStack_Types.h
 *  Generator:  None
 *
 *  Description:  This file contain all types and constants that are shared among the
 *                AUTOSAR COM stack modules.                                                           
 *********************************************************************************************************************/
#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"

/*********************************************************************************************************************
 * Other Header Files
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

/** \brief The size of this global type depends on the maximum number of PDUs used within one software module. */
 
typedef uint16 PduIdType; /*~ASR~*/

/** \brief The size of this global type depends on the maximum length of PDUs to be sent by an ECU. */

typedef uint16 PduLengthType; /*~ASR~*/

/** \brief Structure defining the PDU Information Type.*/

typedef struct
{
   uint8 *SduDataPtr; /* Payload.*/
   uint8 *MetaDataPtr; /* Meta Data */
   PduLengthType SduLength; /* Length of SDU.*/
} PduInfoType; /*~ASR~*/

/** \brief IcomConfigIdType defines the configuration ID. An ID of 0 is the default 
 configuration. An ID greater than 0 shall identify a configuration for 
 Pretended Networking. There is more than 1 configuration possible.*/

typedef uint8 IcomConfigIdType; /*~ASR~*/


/** \brief IcomSwitch_ErrorType defines the errors which can occur when activating or deactivating 
Pretended Networking.*/
 
typedef enum
{
   ICOM_SWITCH_E_OK = 0U, /* The activation of Pretended Networking was successful. */
   ICOM_SWITCH_E_FAILED   /*  The activation of Pretended Networking was not successful. */
} IcomSwitch_ErrorType;

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

#endif /* COMSTACK_TYPES_H */
/*********************************************************************************************************************
 *  End of File: ComStack_Types.h
 *********************************************************************************************************************/
