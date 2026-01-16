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
 *  File:       Can_Irq.c
 *  Generator:  None
 *
 *  Description:  This file contains controller dependent local functions and private functions
 *                to be used in Can.c.
 *********************************************************************************************************************/
/*
 *Design: MCAL-22825, MCAL-22842, MCAL-22827, MCAL-22880, MCAL-23013, MCAL-23010
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Can.h"
#include "Can_Priv.h"
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
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define CAN_START_SEC_ISR_CODE
#include "Can_MemMap.h"

#if defined(CAN_MCANA_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCANA_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_A_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANA_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_A_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANA_ISR_CAT2)
ISR(Can_A_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCANA, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCANA_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_A_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANA_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_A_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANA_ISR_CAT2)
ISR(Can_A_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCANA, MCAN_INT_LINE_1);
}

#if defined(CAN_MCANA_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_A_WakeUpISR)
#elif defined(CAN_MCANA_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_A_WakeUpISR)
#elif defined(CAN_MCANA_ISR_CAT2)
ISR(Can_A_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCANA);
}
#endif

#if defined(CAN_MCANB_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCANB_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_B_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANB_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_B_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANB_ISR_CAT2)
ISR(Can_B_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCANB, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCANB_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_B_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANB_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_B_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANB_ISR_CAT2)
ISR(Can_B_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCANB, MCAN_INT_LINE_1);
}

#if defined(CAN_MCANB_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_B_WakeUpISR)
#elif defined(CAN_MCANB_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_B_WakeUpISR)
#elif defined(CAN_MCANB_ISR_CAT2)
ISR(Can_B_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCANB);
}
#endif

#if defined(CAN_MCANC_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCANC_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_C_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANC_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_C_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANC_ISR_CAT2)
ISR(Can_C_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCANC, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCANC_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_C_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANC_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_C_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANC_ISR_CAT2)
ISR(Can_C_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCANC, MCAN_INT_LINE_1);
}

#if defined(CAN_MCANC_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_C_WakeUpISR)
#elif defined(CAN_MCANC_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_C_WakeUpISR)
#elif defined(CAN_MCANC_ISR_CAT2)
ISR(Can_C_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCANC);
}
#endif

#if defined(CAN_MCAND_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAND_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_D_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAND_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_D_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAND_ISR_CAT2)
ISR(Can_D_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAND, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAND_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_D_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAND_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_D_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAND_ISR_CAT2)
ISR(Can_D_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAND, MCAN_INT_LINE_1);
}

#if defined(CAN_MCAND_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_D_WakeUpISR)
#elif defined(CAN_MCAND_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_D_WakeUpISR)
#elif defined(CAN_MCAND_ISR_CAT2)
ISR(Can_D_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAND);
}
#endif

#if defined(CAN_MCANE_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCANE_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_E_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANE_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_E_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANE_ISR_CAT2)
ISR(Can_E_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCANE, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCANE_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_E_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANE_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_E_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANE_ISR_CAT2)
ISR(Can_E_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCANE, MCAN_INT_LINE_1);
}

#if defined(CAN_MCANE_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_E_WakeUpISR)
#elif defined(CAN_MCANE_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_E_WakeUpISR)
#elif defined(CAN_MCANE_ISR_CAT2)
ISR(Can_E_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCANE);
}
#endif

#if defined(CAN_MCANF_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCANF_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_F_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANF_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_F_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANF_ISR_CAT2)
ISR(Can_F_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCANF, MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCANF_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_F_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCANF_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_F_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCANF_ISR_CAT2)
ISR(Can_F_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCANF, MCAN_INT_LINE_1);
}

#if defined(CAN_MCANF_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_F_WakeUpISR)
#elif defined(CAN_MCANF_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_F_WakeUpISR)
#elif defined(CAN_MCANF_ISR_CAT2)
ISR(Can_F_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCANF);
}
#endif

#define CAN_STOP_SEC_ISR_CODE
#include "Can_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Can_Irq.c
 *********************************************************************************************************************/
