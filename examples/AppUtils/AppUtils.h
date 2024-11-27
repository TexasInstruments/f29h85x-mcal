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
 *  File:       AppUtils.h
 *  Generator:  None
 *
 *  Description:  AppUtils header file
 *********************************************************************************************************************/
#ifndef APPUTILS_H
#define APPUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"
#include "string.h"
#include "hw_memmap.h"
#include "hw_uart.h"
#include "hw_types.h"

#if defined(DEBUG)
#include "assert.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#define APPUTILS_ASSERT(y) (AppUtils_AssertFunc((uint32)(y),(char *) #y,(char *) __FILE__,(uint32) __LINE__))

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Function to check if the condition is true.
 *
 * This function  to check if the condition passed as a paramter is true.
 *
 * \param[in] Condition Condition to be checked
 * \param[in] Str       String to be printed
 * \param[in] FileName  Name of the file
 * \param[in] LineNum   Line number
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void AppUtils_AssertFunc(uint32 Condition,char *Str,char *FileName,uint32 LineNum);

/** \brief Function to initialiaze UART.
 *
 * This function initializes UART for AppUtils.
 *
 * \param[in] UartClk Clock frequency configured
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void AppUtils_Init(uint32 UartClk);

/** \brief Function to deinitialiaze UART.
 *
 * This function deinitializes UART for AppUtils.
 *
 * \param[in] None
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void AppUtils_DeInit(void);

/** \brief Function to print the string on the console.
 *
 * This function prints the given string on the console.
 *
 * \param[in] Message Pointer to meesage(String)
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void AppUtils_Printf(const char *Message, ...);

/** \brief Function to get the character passed via console.
 *
 * This function reads the character passed via console.
 *
 * \param[in] None 
 * \param[out] None
 * \post None
 * \return Returns the character read that is passed via console.
 * \retval char
 *
 *********************************************************************************************************************/
sint8 AppUtils_GetChar(void);

/** \brief Function to get the number passed via console.
 *
 * This function reads the number passed via console.
 *
 * \param[in] None
 * \param[out] None
 * \post None
 * \return Returns the number read that is passed via console.
 * \retval sint32
 *
 *********************************************************************************************************************/
sint32 AppUtils_GetNum(void);

/** \brief Function to get the number passed via console.
 *
 * This function reads the number passed via console.
 *
 * \param[in] None
 * \param[out] None
 * \post None
 * \return Returns the number read that is passed via console.
 * \retval sint32
 *
 *********************************************************************************************************************/
sint8 Uart_ReadChar();

/** \brief Function to get the number passed via console.
 *
 * This function reads the number passed via console.
 *
 * \param[in] data
 * \param[out] None
 * \post None
 * \return Returns the number read that is passed via console.
 * \retval sint32
 *
 *********************************************************************************************************************/
void Uart_WriteChar(uint8 data);

/** \brief Function to enable UART module.
 *
 * This function to enable UART module.
 *
 * \param[in] None
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Uart_EnableModule();

/** \brief Function to disable UART module.
 *
 * This function to disable UART module.
 *
 * \param[in] None
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Uart_DisableModule();

/** \brief Function to configure UART instance usd for printing on the console.
 *
 * This function to configure UART instance usd for printing on the console.
 *
 * \param[in] UartClk Uart clock
 * \param[in] Baudrate Baudrate
 * \param[in] Config Uart configuration
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Uart_SetConfig(uint32 UartClk,uint32 Baudrate, uint32 Config);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* APPUTILS_H */
/*********************************************************************************************************************
 *  End of File: AppUtils.h
 *********************************************************************************************************************/
