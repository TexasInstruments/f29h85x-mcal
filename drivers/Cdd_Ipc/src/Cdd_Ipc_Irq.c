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
 *  File:         Cdd_Ipc_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Ipc Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Os.h"
#include "Cdd_Ipc.h"
#include "Cdd_Ipc_Priv.h"
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
 * External Functions Definition
 *********************************************************************************************************************/
#define CDD_IPC_START_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST0_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST0_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU2_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST1_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST1_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU2_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST2_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST2_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU2_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU2_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST3_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST3_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU2_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU2_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU2_R_INST3);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST0_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST0_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU3_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST1_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST1_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU3_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST2_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST2_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU3_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU1_L_CPU3_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST3_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST3_ISR)
#elif defined(CDD_IPC_CPU1_L_CPU3_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU1_L_CPU3_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU1_L_CPU3_R_INST3);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST0_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST0_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU1_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST1_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST1_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU1_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST2_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST2_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU1_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU1_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST3_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST3_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU1_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU1_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU1_R_INST3);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST0_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST0_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU3_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST1_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST1_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU3_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST2_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST2_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU3_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU2_L_CPU3_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST3_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST3_ISR)
#elif defined(CDD_IPC_CPU2_L_CPU3_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU2_L_CPU3_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU2_L_CPU3_R_INST3);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST0_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST0_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU1_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST1_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST1_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU1_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST2_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST2_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU1_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU1_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST3_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST3_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU1_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU1_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU1_R_INST3);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST0_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST0_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST0_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST0_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST0_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST0_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST0_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU2_R_INST0);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST1_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST1_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST1_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST1_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST1_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU2_R_INST1);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST2_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST2_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST2_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST2_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST2_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU2_R_INST2);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST3_ENABLE)
#if defined(CDD_IPC_CPU3_L_CPU2_R_INST3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST3_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST3_ISR)
#elif defined(CDD_IPC_CPU3_L_CPU2_R_INST3_ISR_CAT2_INT)
ISR(Cdd_Ipc_CPU3_L_CPU2_R_INST3_ISR)
#else
    #error "Invalid Ipc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Ipc_ProcessIsr(CDD_IPC_CPU3_L_CPU2_R_INST3);
}
#endif


#define CDD_IPC_STOP_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Irq.c
 *********************************************************************************************************************/
