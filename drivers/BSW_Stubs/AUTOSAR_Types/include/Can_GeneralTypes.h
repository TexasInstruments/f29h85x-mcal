/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Can_GeneralTypes.h
 *  Generator:  None
 *
 *  Description:  This file contain all types and constants that are shared among the
 *                AUTOSAR CAN modules.                                                           
 *********************************************************************************************************************/

/*
 *Design: MCAL-22933, MCAL-22935, MCAL-22934
 */
#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/


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

/** \brief States that are used by the several ControllerMode functions.*/
typedef enum
{
   CAN_CS_UNINIT = 0U,  /* CAN controller state UNINIT.*/
   CAN_CS_STARTED,      /* CAN controller state STARTED. */
   CAN_CS_STOPPED,      /* CAN controller state STOPPED. */
   CAN_CS_SLEEP         /* CAN controller state SLEEP. */
} Can_ControllerStateType;

/** \brief Error states of a CAN controller.*/
typedef enum
{
   CAN_ERRORSTATE_ACTIVE = 0U,  /* The CAN controller takes fully part in communication. */
   CAN_ERRORSTATE_PASSIVE,      /* The CAN controller takes part in communication, but  */
                                /* does not send active error frames. */
   CAN_ERRORSTATE_BUSOFF        /* CAN controller state STOPPED. */
} Can_ErrorStateType;

/** \brief Represents the hardware object handles of a CAN hardware unit.*/

/* Requirements :  */
typedef uint16 Can_HwHandleType;

/** \brief Represents the Identifier of an L-PDU.*/
/* Requirements :  */
typedef uint32 Can_IdType;

/** \brief This type defines a data structure which clearly provides an Hardware Object Handle including
 its corresponding CAN Controller and therefore CanDrv as well as the specific CanId.*/

typedef struct
{
    Can_IdType       CanId;        /* Standard/Extended CAN ID of CAN L-PDU */
    Can_HwHandleType Hoh;          /* ID of the corresponding Hardware Object Range */
    uint8            ControllerId; /* Mailbox Corresponding Controller Id */
}Can_HwType;

/** \brief This type unites PduId (swPduHandle), SduLength (length), SduData (sdu), and CanId (id) for any CAN L-SDU.*/

/* Requirements : */
typedef struct 
{
    PduIdType  swPduHandle; /* private data for CanIf,just save and use for */
                            /* callback. */
    uint8      length;      /* Length, max 64 bytes. */
    uint32 id;          	/* the CAN ID, 29 or 11-bit. */
    uint8     *sdu;         /* data ptr. */
} Can_PduType;

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

#endif /* CAN_GENERAL_TYPES_H */
/*********************************************************************************************************************
 *  End of File: Can_GeneralTypes.h
 *********************************************************************************************************************/
