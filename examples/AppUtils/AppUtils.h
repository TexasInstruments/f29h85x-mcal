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
#define APPUTILS_ASSERT(y) (AppUtils_AssertFunc((uint32)(y), (char *)#y, (char *)__FILE__, (uint32)__LINE__))

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
void AppUtils_AssertFunc(uint32 Condition, char *Str, char *FileName, uint32 LineNum);

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

/** \brief Function to write a character to the console.
 *
 * This function writes the given character to the console.
 *
 * \param[in] Data Character to be written
 * \param[out] None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
void Uart_WriteChar(uint8 Data);

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
void Uart_SetConfig(uint32 UartClk, uint32 Baudrate, uint32 Config);

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
