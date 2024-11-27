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
 *  File:         Gpt_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains GPT interrupt service routine definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 /* 
 *Design: MCAL-21954
 */
#include "Gpt_Priv.h"
#include "Mcal_Lib_Cpu.h"
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
#define GPT_START_SEC_ISR_CODE
#include "Gpt_MemMap.h"
/*
 *Design: MCAL-22040
 */
#if defined(GPT_CHANNEL0_ENABLE)
#if defined(GPT_ISR_CAT1_RTINT_CHANNEL0)
MCAL_LIB_RTINT_ISR(Gpt_Ch0Isr)
#elif defined(GPT_ISR_CAT1_INT_CHANNEL0)
MCAL_LIB_INT_ISR(Gpt_Ch0Isr)
#elif defined(GPT_ISR_CAT2_CHANNEL0)
ISR(Gpt_Ch0Isr)
#else
    #error "Invalid interrupt category for timer channel 0"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Gpt_IsrNotifyFunction(0U);
}
#endif

/*
 *Design: MCAL-22040
 */
#if defined(GPT_CHANNEL1_ENABLE)
#if defined(GPT_ISR_CAT1_RTINT_CHANNEL1)
MCAL_LIB_RTINT_ISR(Gpt_Ch1Isr)
#elif defined(GPT_ISR_CAT1_INT_CHANNEL1)
MCAL_LIB_INT_ISR(Gpt_Ch1Isr)
#elif defined(GPT_ISR_CAT2_CHANNEL1)
ISR(Gpt_Ch1Isr)
#else
    #error "Invalid interrupt category for timer channel 1"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Gpt_IsrNotifyFunction(1U);
}
#endif

/*
 *Design: MCAL-22040
 */
#if defined(GPT_CHANNEL2_ENABLE)
#if defined(GPT_ISR_CAT1_RTINT_CHANNEL2)
MCAL_LIB_RTINT_ISR(Gpt_Ch2Isr)
#elif defined(GPT_ISR_CAT1_INT_CHANNEL2)
MCAL_LIB_INT_ISR(Gpt_Ch2Isr)
#elif defined(GPT_ISR_CAT2_CHANNEL2)
ISR(Gpt_Ch2Isr)
#else
    #error "Invalid interrupt category for timer channel 2"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Gpt_IsrNotifyFunction(2U);
}
#endif

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define GPT_STOP_SEC_ISR_CODE
#include "Gpt_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Gpt_Irq.c
 *********************************************************************************************************************/
