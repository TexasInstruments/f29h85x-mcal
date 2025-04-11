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
 *  File:       Cdd_Sent_Cbk.h.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_SENT_CBK_H
#define CDD_SENT_CBK_H
/** \addtogroup CDD_SENT
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/** \brief Decalation of PduInfoType and PduIdType in ComStack_Types.h */
/*
 *Design: MCAL-28683
 */
#include "ComStack_Types.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/*
 *Design: MCAL-28703, MCAL-28702
*/

/** \brief Exported function prototypes for User callback and Error callback
 *
 * \param[in] PduInfoPtr Pointer to PDU Information.
 * \param[in] id  : When Cdd Sent is integrated with Autosar Com stack, this id parameter
 * is a Pdu identifier used  to address the respective sensor.
 * When Cdd Sent is not integrated with Autosar Com stack, this id parameter
 * is a device identifier used  to address the respective sensor.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/

extern void CddSent_Callback(PduIdType id, const PduInfoType *PduInfoPtr);
extern void CddSent_Error_Callback(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
 #endif /* CDD_SENT_CBK_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Cbk.h.h
 *********************************************************************************************************************/
