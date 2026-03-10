/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
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
 *  File:         Uart_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains UART interrupt service routine definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-xxxxx
 */
#include "Cdd_Uart.h"
#include "Cdd_Uart_Priv.h"
#include "Mcal_Lib_Cpu.h"
#include "Cdd_Uart.h"
#include "Os.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define CDD_UART_START_SEC_ISR_CODE
#include "Cdd_Uart_MemMap.h"

#if defined(CDD_UARTA_ENABLE)
#if defined(CDD_UARTA_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_A_ISR)
#elif defined(CDD_UARTA_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_A_ISR)
#else
ISR(Cdd_Uart_A_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTA);
}
#endif

#if defined(CDD_UARTB_ENABLE)
#if defined(CDD_UARTB_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_B_ISR)
#elif defined(CDD_UARTB_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_B_ISR)
#else
ISR(Cdd_Uart_B_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTB);
}
#endif

#if defined(CDD_UARTC_ENABLE)
#if defined(CDD_UARTC_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_C_ISR)
#elif defined(CDD_UARTC_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_C_ISR)
#else
ISR(Cdd_Uart_C_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTC);
}
#endif

#if defined(CDD_UARTD_ENABLE)
#if defined(CDD_UARTD_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_D_ISR)
#elif defined(CDD_UARTD_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_D_ISR)
#else
ISR(Cdd_Uart_D_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTD);
}
#endif

#if defined(CDD_UARTE_ENABLE)
#if defined(CDD_UARTE_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_E_ISR)
#elif defined(CDD_UARTE_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_E_ISR)
#else
ISR(Cdd_Uart_E_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTE);
}
#endif

#if defined(CDD_UARTF_ENABLE)
#if defined(CDD_UARTF_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_F_ISR)
#elif defined(CDD_UARTF_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_F_ISR)
#else
ISR(Cdd_Uart_F_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UARTF);
}
#endif

#define CDD_UART_STOP_SEC_ISR_CODE
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Irq.c
 *********************************************************************************************************************/
