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
 *  \file       Fls_Cbk.h
 *  Generator:  None
 *
 *  \brief Description:  call back functions for job done and job error
 *********************************************************************************************************************/

#ifndef FLS_CBK_H_
#define FLS_CBK_H_

#ifdef __cplusplus
extern "C"
{
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

/** \brief Typedef for job end notification function pointer */
/** Requirements : SWS_FLS_00192 */
/*
 *  Design: MCAL-31039
 */
typedef P2FUNC (void, FLS_APPL_CODE, Fls_JobEndNotifyType)(void);

/** \brief Typedef for job error notification function pointer */
/** Requirements : SWS_FLS_00193 */
typedef P2FUNC (void, FLS_APPL_CODE, Fls_JobErrorNotifyType)(void);

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
[!SELECT "as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']"!]
[!AUTOSPACING!]
[!VAR "notifyFxnList" = "' '"!][!//
[!LOOP "FlsConfigSet"!][!//
[!IF "(node:exists(FlsJobEndNotification))"!][!//
[!IF "FlsJobEndNotification !='NULL_PTR' and FlsJobEndNotification !=''"!][!//
[!IF "not(node:containsValue(text:split($notifyFxnList),FlsJobEndNotification))"!][!//
[!"concat('extern void ',node:value(FlsJobEndNotification),'(void);')"!]
[!VAR "notifyFxnList" = "concat($notifyFxnList,' ',notifyFxnList)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "notifyFxnList" = "' '"!][!//
[!LOOP "FlsConfigSet"!][!//
[!IF "(node:exists(FlsJobErrorNotification))"!][!//
[!IF "FlsJobErrorNotification !='NULL_PTR' and FlsJobErrorNotification !=''"!][!//
[!IF "not(node:containsValue(text:split($notifyFxnList),FlsJobErrorNotification))"!][!//
[!"concat('extern void ',node:value(FlsJobErrorNotification),'(void);')"!]
[!VAR "notifyFxnList" = "concat($notifyFxnList,' ',notifyFxnList)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!]

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  /** #ifndef FLS_CBK_H_ */

/*********************************************************************************************************************
 *  End of File: FLS_CBK_H_
 *********************************************************************************************************************/
