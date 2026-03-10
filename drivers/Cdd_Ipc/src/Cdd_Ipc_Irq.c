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
 *  File:         Cdd_Ipc_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Ipc Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ipc.h"
#include "Cdd_Ipc_Priv.h"
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
#define CDD_IPC_START_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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

/* Design: MCAL-30596 */
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
