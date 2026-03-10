/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:         Cdd_Adc_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Adc Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Priv.h"
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
#define CDD_ADC_START_SEC_ISR_CODE
#include "Cdd_Adc_MemMap.h"

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT1_ENABLE)
#if defined(CDD_ADCA_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int1Isr)
#elif defined(CDD_ADCA_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int1Isr)
#elif defined(CDD_ADCA_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int1Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1, CDD_ADCA);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCA_INT2_ENABLE)
#if defined(CDD_ADCA_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int2Isr)
#elif defined(CDD_ADCA_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int2Isr)
#elif defined(CDD_ADCA_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int2Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2, CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT3_ENABLE)
#if defined(CDD_ADCA_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int3Isr)
#elif defined(CDD_ADCA_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int3Isr)
#elif defined(CDD_ADCA_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int3Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3, CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT4_ENABLE)
#if defined(CDD_ADCA_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int4Isr)
#elif defined(CDD_ADCA_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int4Isr)
#elif defined(CDD_ADCA_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int4Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4, CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT1_ENABLE)
#if defined(CDD_ADCB_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int1Isr)
#elif defined(CDD_ADCB_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int1Isr)
#elif defined(CDD_ADCB_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int1Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1, CDD_ADCB);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCB_INT2_ENABLE)
#if defined(CDD_ADCB_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int2Isr)
#elif defined(CDD_ADCB_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int2Isr)
#elif defined(CDD_ADCB_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int2Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2, CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT3_ENABLE)
#if defined(CDD_ADCB_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int3Isr)
#elif defined(CDD_ADCB_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int3Isr)
#elif defined(CDD_ADCB_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int3Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3, CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT4_ENABLE)
#if defined(CDD_ADCB_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int4Isr)
#elif defined(CDD_ADCB_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int4Isr)
#elif defined(CDD_ADCB_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int4Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4, CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT1_ENABLE)
#if defined(CDD_ADCC_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int1Isr)
#elif defined(CDD_ADCC_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int1Isr)
#elif defined(CDD_ADCC_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int1Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1, CDD_ADCC);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCC_INT2_ENABLE)
#if defined(CDD_ADCC_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int2Isr)
#elif defined(CDD_ADCC_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int2Isr)
#elif defined(CDD_ADCC_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int2Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2, CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT3_ENABLE)
#if defined(CDD_ADCC_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int3Isr)
#elif defined(CDD_ADCC_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int3Isr)
#elif defined(CDD_ADCC_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int3Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3, CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT4_ENABLE)
#if defined(CDD_ADCC_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int4Isr)
#elif defined(CDD_ADCC_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int4Isr)
#elif defined(CDD_ADCC_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int4Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4, CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT1_ENABLE)
#if defined(CDD_ADCD_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int1Isr)
#elif defined(CDD_ADCD_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int1Isr)
#elif defined(CDD_ADCD_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int1Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1, CDD_ADCD);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCD_INT2_ENABLE)
#if defined(CDD_ADCD_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int2Isr)
#elif defined(CDD_ADCD_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int2Isr)
#elif defined(CDD_ADCD_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int2Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2, CDD_ADCD);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT3_ENABLE)
#if defined(CDD_ADCD_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int3Isr)
#elif defined(CDD_ADCD_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int3Isr)
#elif defined(CDD_ADCD_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int3Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3, CDD_ADCD);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT4_ENABLE)
#if defined(CDD_ADCD_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int4Isr)
#elif defined(CDD_ADCD_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int4Isr)
#elif defined(CDD_ADCD_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int4Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4, CDD_ADCD);
}
#endif

/*
 * Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT1_ENABLE)
#if defined(CDD_ADCE_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int1Isr)
#elif defined(CDD_ADCE_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int1Isr)
#elif defined(CDD_ADCE_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int1Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1, CDD_ADCE);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCE_INT2_ENABLE)
#if defined(CDD_ADCE_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int2Isr)
#elif defined(CDD_ADCE_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int2Isr)
#elif defined(CDD_ADCE_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int2Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2, CDD_ADCE);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT3_ENABLE)
#if defined(CDD_ADCE_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int3Isr)
#elif defined(CDD_ADCE_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int3Isr)
#elif defined(CDD_ADCE_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int3Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3, CDD_ADCE);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT4_ENABLE)
#if defined(CDD_ADCE_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int4Isr)
#elif defined(CDD_ADCE_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int4Isr)
#elif defined(CDD_ADCE_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int4Isr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4, CDD_ADCE);
}
#endif

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Enable the ISR functions only if Limit check API is enabled */

#if defined(CDD_ADCA_EVTINT_ENABLE)
#if defined(CDD_ADCA_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#elif defined(CDD_ADCA_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#elif defined(CDD_ADCA_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCA);
}
#endif

#if defined(CDD_ADCB_EVTINT_ENABLE)
#if defined(CDD_ADCB_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#elif defined(CDD_ADCB_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#elif defined(CDD_ADCB_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCB);
}
#endif

#if defined(CDD_ADCC_EVTINT_ENABLE)
#if defined(CDD_ADCC_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#elif defined(CDD_ADCC_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#elif defined(CDD_ADCC_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCC);
}
#endif

#if defined(CDD_ADCD_EVTINT_ENABLE)
#if defined(CDD_ADCD_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#elif defined(CDD_ADCD_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#elif defined(CDD_ADCD_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCD);
}
#endif

#if defined(CDD_ADCE_EVTINT_ENABLE)
#if defined(CDD_ADCE_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#elif defined(CDD_ADCE_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#elif defined(CDD_ADCE_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#else
#error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCE);
}
#endif

#endif

#define CDD_ADC_STOP_SEC_ISR_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Irq.c
 *********************************************************************************************************************/
