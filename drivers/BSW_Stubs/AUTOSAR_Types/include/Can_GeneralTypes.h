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
