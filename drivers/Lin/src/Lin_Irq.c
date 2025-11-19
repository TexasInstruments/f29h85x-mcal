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
 *  File:       Lin_Irq.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  None
 *
 *  Description:  This file contains Interrupt Service Routines for Lin.c
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Os.h"
#include "Lin.h"
#include "Lin_Priv.h"
#include "EcuM_Cbk.h"
#include "Mcal_Lib_Cpu.h"

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
 *  External Functions Definition
 *********************************************************************************************************************/
#define LIN_START_SEC_ISR_CODE
#include "Lin_MemMap.h"

#if defined(LIN_INSTANCE_LINA_LINE_NUM_0)
#if (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Lin_A_Int0ISR)
#elif (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Lin_A_Int0ISR)
#elif (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT2)
ISR(Lin_A_Int0ISR)
#else
#error "Invalid interrupt category for Lin Instance A"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Lin_ProcessISR(LIN_INSTANCE_LINA);
}
#endif

#if defined(LIN_INSTANCE_LINA_LINE_NUM_1)
#if (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Lin_A_Int1ISR)
#elif (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Lin_A_Int1ISR)
#elif (LIN_INSTANCE_LINA_ISR_TYPE == LIN_ISR_CAT2)
ISR(Lin_A_Int1ISR)
#else
#error "Invalid interrupt category for Lin Instance A"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Lin_ProcessISR(LIN_INSTANCE_LINA);
}
#endif

#if defined(LIN_INSTANCE_LINB_LINE_NUM_0)
#if (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Lin_B_Int0ISR)
#elif (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Lin_B_Int0ISR)
#elif (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT2)
ISR(Lin_B_Int0ISR)
#else
#error "Invalid interrupt category for Lin Instance B"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Lin_ProcessISR(LIN_INSTANCE_LINB);
}
#endif

#if defined(LIN_INSTANCE_LINB_LINE_NUM_1)
#if (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Lin_B_Int1ISR)
#elif (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Lin_B_Int1ISR)
#elif (LIN_INSTANCE_LINB_ISR_TYPE == LIN_ISR_CAT2)
ISR(Lin_B_Int1ISR)
#else
#error "Invalid interrupt category for Lin Instance B"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Lin_ProcessISR(LIN_INSTANCE_LINB);
}
#endif

#define LIN_STOP_SEC_ISR_CODE
#include "Lin_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Lin_Irq.c
 *********************************************************************************************************************/
