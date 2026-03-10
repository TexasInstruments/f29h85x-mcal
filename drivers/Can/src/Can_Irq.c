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
