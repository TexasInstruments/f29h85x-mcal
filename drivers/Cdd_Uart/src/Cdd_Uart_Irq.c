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

#if defined(CDD_UART0_ENABLE)
#if defined(CDD_UART0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_0_ISR)
#elif defined(CDD_UART0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_0_ISR)
#else
ISR(Cdd_Uart_0_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART0);
}
#endif

#if defined(CDD_UART1_ENABLE)
#if defined(CDD_UART1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_1_ISR)
#elif defined(CDD_UART1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_1_ISR)
#else
ISR(Cdd_Uart_1_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART1);
}
#endif

#if defined(CDD_UART2_ENABLE)
#if defined(CDD_UART2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_2_ISR)
#elif defined(CDD_UART2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_2_ISR)
#else
ISR(Cdd_Uart_2_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART2);
}
#endif

#if defined(CDD_UART3_ENABLE)
#if defined(CDD_UART3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_3_ISR)
#elif defined(CDD_UART3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_3_ISR)
#else
ISR(Cdd_Uart_3_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART3);
}
#endif

#if defined(CDD_UART4_ENABLE)
#if defined(CDD_UART4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_4_ISR)
#elif defined(CDD_UART4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_4_ISR)
#else
ISR(Cdd_Uart_4_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART4);
}
#endif

#if defined(CDD_UART5_ENABLE)
#if defined(CDD_UART5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Uart_5_ISR)
#elif defined(CDD_UART5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Uart_5_ISR)
#else
ISR(Cdd_Uart_5_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Uart_ProcessISR(CDD_UART_INSTANCE_UART5);
}
#endif

#define CDD_UART_STOP_SEC_ISR_CODE
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Irq.c
 *********************************************************************************************************************/
