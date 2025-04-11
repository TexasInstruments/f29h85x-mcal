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
#include "Os.h"
#include "Can.h"
#include "Can_Priv.h"
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

#define CAN_START_SEC_ISR_CODE
#include "Can_MemMap.h"

#if defined(CAN_MCAN1_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_1_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_1_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN1_ISR_CAT2)
ISR(Can_1_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN1,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_1_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_1_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN1_ISR_CAT2)
ISR(Can_1_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN1,MCAN_INT_LINE_1);

}

#if defined(CAN_MCAN1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_1_WakeUpISR)
#elif defined(CAN_MCAN1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_1_WakeUpISR)
#elif defined(CAN_MCAN1_ISR_CAT2)
ISR(Can_1_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN1);
}
#endif

#if defined(CAN_MCAN2_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_2_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_2_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN2_ISR_CAT2)
ISR(Can_2_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN2,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_2_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_2_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN2_ISR_CAT2)
ISR(Can_2_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN2,MCAN_INT_LINE_1);
}

#if defined(CAN_MCAN2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_2_WakeUpISR)
#elif defined(CAN_MCAN2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_2_WakeUpISR)
#elif defined(CAN_MCAN2_ISR_CAT2)
ISR(Can_2_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN2);
}
#endif


#if defined(CAN_MCAN3_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_3_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_3_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN3_ISR_CAT2)
ISR(Can_3_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN3,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_3_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_3_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN3_ISR_CAT2)
ISR(Can_3_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN3,MCAN_INT_LINE_1);
}

#if defined(CAN_MCAN3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_3_WakeUpISR)
#elif defined(CAN_MCAN3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_3_WakeUpISR)
#elif defined(CAN_MCAN3_ISR_CAT2)
ISR(Can_3_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN3);
}
#endif


#if defined(CAN_MCAN4_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_4_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_4_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN4_ISR_CAT2)
ISR(Can_4_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN4,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_4_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_4_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN4_ISR_CAT2)
ISR(Can_4_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN4,MCAN_INT_LINE_1);
}

#if defined(CAN_MCAN4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_4_WakeUpISR)
#elif defined(CAN_MCAN4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_4_WakeUpISR)
#elif defined(CAN_MCAN4_ISR_CAT2)
ISR(Can_4_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN4);
}
#endif


#if defined(CAN_MCAN5_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_5_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_5_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN5_ISR_CAT2)
ISR(Can_5_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN5,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_5_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_5_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN5_ISR_CAT2)
ISR(Can_5_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN5,MCAN_INT_LINE_1);
}

#if defined(CAN_MCAN5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_5_WakeUpISR)
#elif defined(CAN_MCAN5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_5_WakeUpISR)
#elif defined(CAN_MCAN5_ISR_CAT2)
ISR(Can_5_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN5);
}
#endif


#if defined(CAN_MCAN6_ENABLE)
/*Design: MCAL-22839 */
#if defined(CAN_MCAN6_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_6_Int0ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN6_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_6_Int0ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN6_ISR_CAT2)
ISR(Can_6_Int0ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine0ISR(CAN_CONTROLLER_INSTANCE_MCAN6,MCAN_INT_LINE_0);
}

/*Design: MCAL-22839 */
#if defined(CAN_MCAN6_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_6_Int1ISR)
/*Design: MCAL-22839 */
#elif defined(CAN_MCAN6_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_6_Int1ISR)
/*Design: MCAL-22841 */
#elif defined(CAN_MCAN6_ISR_CAT2)
ISR(Can_6_Int1ISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessLine1ISR(CAN_CONTROLLER_INSTANCE_MCAN6,MCAN_INT_LINE_1);
}

#if defined(CAN_MCAN6_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Can_6_WakeUpISR)
#elif defined(CAN_MCAN6_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Can_6_WakeUpISR)
#elif defined(CAN_MCAN6_ISR_CAT2)
ISR(Can_6_WakeUpISR)
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Can_ProcessWakeUpISR(CAN_CONTROLLER_INSTANCE_MCAN6);
}
#endif



#define CAN_STOP_SEC_ISR_CODE
#include "Can_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Can_Irq.c
 *********************************************************************************************************************/
