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
 *  File:       Cdd_Sent_Irq.c
 *  Generator:  None
 *
 *  Description:  This file contains controller dependent local functions and private functions 
 *                to be used in Cdd_Sent_Irq.c.
 *********************************************************************************************************************/
/* 
* Design: MCAL-28620
*/
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Os.h"
#include "Cdd_Sent_Priv.h"
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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/* 
* Design: MCAL-28621
*/
#define CDD_SENT_START_SEC_ISR_CODE
#include "Cdd_Sent_MemMap.h"

#if defined(CDD_SENT1_ENABLE)
#if defined(CDD_SENT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_1_ISR)
#elif defined(CDD_SENT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_1_ISR)
#else
    ISR(Cdd_Sent_1_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT1);
}
#endif


#if defined(CDD_SENT2_ENABLE)
#if defined(CDD_SENT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_2_ISR)
#elif defined(CDD_SENT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_2_ISR)
#else
ISR(Cdd_Sent_2_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT2);
}
#endif

#if defined(CDD_SENT3_ENABLE)
#if defined(CDD_SENT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_3_ISR)
#elif defined(CDD_SENT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_3_ISR)
#else
ISR(Cdd_Sent_3_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT3);
}
#endif

#if defined(CDD_SENT4_ENABLE)
#if defined(CDD_SENT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_4_ISR)
#elif defined(CDD_SENT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_4_ISR)
#else
ISR(Cdd_Sent_4_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT4);
}
#endif

#if defined(CDD_SENT5_ENABLE)
#if defined(CDD_SENT5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_5_ISR)
#elif defined(CDD_SENT5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_5_ISR)
#else
ISR(Cdd_Sent_5_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT5);
}
#endif

#if defined(CDD_SENT6_ENABLE)
#if defined(CDD_SENT6_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Sent_6_ISR)
#elif defined(CDD_SENT6_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Sent_6_ISR)
#else
ISR(Cdd_Sent_6_ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Sent_ProcessISR(CDD_SENT_INSTANCE_SENT6);
}
#endif

#define CDD_SENT_STOP_SEC_ISR_CODE
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Irq.c
 *********************************************************************************************************************/
