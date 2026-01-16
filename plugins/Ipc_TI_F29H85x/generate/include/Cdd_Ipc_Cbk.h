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
 *  File:       Cdd_Ipc_Cbk.h.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_IPC_CBK_H
#define CDD_IPC_CBK_H
/** \addtogroup CDD_IPC
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

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Exported function prototypes for User callback*/

/** \brief Exported function prototypes for User callback.
 *
 * \param[in] PduInfoPtr Pointer to PDU Information.
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
[!VAR "CddIpcUserCallbackFunctionList" = "' '"!][!//
[!LOOP "as:modconf('Cdd_Ipc/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ipc/Cdd']/CddIpcConfig/CddIpcRemoteCoreConfig/*/CddIpcRxInstanceConfig/*/CddIpcRxChannelConfig/*"!][!//
[!IF "(node:exists(CddIpcUserCallbackFunction))"!][!//
[!IF "CddIpcUserCallbackFunction !='NULL_PTR'"!][!//
[!IF "not(node:containsValue(text:split($CddIpcUserCallbackFunctionList),CddIpcUserCallbackFunction))"!][!//
[!"concat('extern void ',node:value(CddIpcUserCallbackFunction),'(const PduInfoType *PduInfoPtr);')"!]
[!VAR "CddIpcUserCallbackFunctionList" = "concat($CddIpcUserCallbackFunctionList,' ',CddIpcUserCallbackFunction)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
 #endif /* CDD_IPC_CBK_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Cbk.h.h
 *********************************************************************************************************************/
