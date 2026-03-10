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
 *  File:       None
 *  Generator:  None
 *
 *  Description:  EcuM source file                                                    
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "EcuM.h"
#include "hw_types.h"
#include "hw_pipe.h"
#include "hw_memmap.h"
#include "hw_cputimer.h"
#include "hw_ints.h"
#include "hw_sysctl.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h" 

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/* AUTOSAR version information check has to match definition in header file */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
     (ECUM_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (ECUM_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "EcuM: AUTOSAR Version Numbers of EcuM are different"
#endif

/* Vendor specific version information is BCD coded */
#if ((ECUM_SW_MAJOR_VERSION != (1U)) || (ECUM_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of EcuM.c and EcuM.h are inconsistent!"
#endif

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
#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    uint8 i;
    for(i=0;i<ECUM_CFG_WAKEUP_EVENT_COUNT;i++)
    {
        if(EcuM_EventRecord[i].source_id & WakeupSource)
        {
            /* Clear the wakeup source bit corresponding to each wakeup source. */
            EcuM_WakeupBitSet &= ~(EcuM_EventRecord[i].source_id);
            /* Call source specific CheckWakeup function */
            (EcuM_EventRecord[i].wakeup_funcptr)(WakeupSource); 
        }
    } 
}

FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType Sources)
{
    /* Set the wakeup source bits corresponding to each wakeup source.  */
    EcuM_WakeupBitSet |= Sources;
}

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

/* Initializes EcuM stub */
FUNC(void, ECUM_CODE) EcuM_Init(void)
{
    EcuM_InitList(); /* Initializes all modules*/
    Os_StartOS(); /* Initializes Os stub */
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: EcuM.c
 *********************************************************************************************************************/
