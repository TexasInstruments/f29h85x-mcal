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
 *  File:         Cdd_Ecap_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Ecap Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "Cdd_Ecap_Priv.h"
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
#define CDD_ECAP_START_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

#if defined(CDD_ECAP_CHANNEL0_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch0Notify)
#elif defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch0Notify)
#elif defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch0Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL0"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL0);
}
#endif

#if defined(CDD_ECAP_CHANNEL1_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch1Notify)
#elif defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch1Notify)
#elif defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch1Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL1"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL1);
}
#endif

#if defined(CDD_ECAP_CHANNEL2_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch2Notify)
#elif defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch2Notify)
#elif defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch2Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL2"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL2);
}
#endif

#if defined(CDD_ECAP_CHANNEL3_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch3Notify)
#elif defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch3Notify)
#elif defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch3Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL3"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL3);
}
#endif

#if defined(CDD_ECAP_CHANNEL4_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch4Notify)
#elif defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch4Notify)
#elif defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch4Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL4);
}
#endif

#if defined(CDD_ECAP_CHANNEL5_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch5Notify)
#elif defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch5Notify)
#elif defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch5Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL5"
#endif
{
    Cdd_Ecap_ChannelISR(CDD_ECAP_CHANNEL5);
}
#endif

#if defined(CDD_ECAP_HR_CHANNEL4_INT_ENABLE)
#if defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_HR_ch4Notify)
#elif defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_HR_ch4Notify)
#elif defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_HR_ch4Notify)
#else
#error "Invalid interrupt category for HR mode CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_HR_ISR(CDD_ECAP_CHANNEL4);
}
#endif

#if defined(CDD_ECAP_HR_CHANNEL5_INT_ENABLE)
#if defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_HR_ch5Notify)
#elif defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_HR_ch5Notify)
#elif defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_HR_ch5Notify)
#else
#error "Invalid interrupt category for HR mode CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_HR_ISR(CDD_ECAP_CHANNEL5);
}
#endif
#define CDD_ECAP_STOP_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Irq.c
 *********************************************************************************************************************/
