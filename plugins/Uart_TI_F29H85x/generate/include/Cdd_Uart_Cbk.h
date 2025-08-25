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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Uart_Cbk.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_UART_CBK_H
#define CDD_UART_CBK_H
/** \addtogroup CDD_UART
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
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

 /*********************************************************************************************************************/
[!VAR "CddUartUserCallbackFunctionList" = "' '"!]
[!LOOP "as:modconf('Cdd_Uart/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Uart/Cdd']/CddUartConfigSet/CddUartConfig/*"!][!//
[!IF "not(node:empty(CddUartWriteConfig/CddUartWriteNotificationHandler)) and (node:value(CddUartWriteConfig/CddUartWriteNotificationHandler) !='NULL_PTR')"!][!//
[!IF "not(node:containsValue(text:split($CddUartUserCallbackFunctionList),CddUartWriteConfig/CddUartWriteNotificationHandler))"!][!//
[!"concat('extern void ',node:value(CddUartWriteConfig/CddUartWriteNotificationHandler),'(void);')"!]
[!VAR "CddUartUserCallbackFunctionList" = "concat($CddUartUserCallbackFunctionList,' ',CddUartWriteConfig/CddUartWriteNotificationHandler)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "not(node:empty(CddUartReadConfig/CddUartReadNotificationHandler)) and (node:value(CddUartReadConfig/CddUartReadNotificationHandler) !='NULL_PTR')"!][!//
[!IF "not(node:containsValue(text:split($CddUartUserCallbackFunctionList),CddUartReadConfig/CddUartReadNotificationHandler))"!][!//
[!"concat('extern void ',node:value(CddUartReadConfig/CddUartReadNotificationHandler),'(void);')"!]
[!VAR "CddUartUserCallbackFunctionList" = "concat($CddUartUserCallbackFunctionList,' ',CddUartReadConfig/CddUartReadNotificationHandler)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "not(node:empty(CddUartReadConfig/CddUartErrorNotificationHandler)) and (node:value(CddUartReadConfig/CddUartErrorNotificationHandler) !='NULL_PTR')"!][!//
[!IF "not(node:containsValue(text:split($CddUartUserCallbackFunctionList),CddUartReadConfig/CddUartErrorNotificationHandler))"!][!//
[!"concat('extern void ',node:value(CddUartReadConfig/CddUartErrorNotificationHandler),'(void);')"!]
[!VAR "CddUartUserCallbackFunctionList" = "concat($CddUartUserCallbackFunctionList,' ',CddUartReadConfig/CddUartErrorNotificationHandler)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
 #endif /* CDD_UART_CBK_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Cbk.h
 *********************************************************************************************************************/
