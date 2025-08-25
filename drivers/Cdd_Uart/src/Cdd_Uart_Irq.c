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
