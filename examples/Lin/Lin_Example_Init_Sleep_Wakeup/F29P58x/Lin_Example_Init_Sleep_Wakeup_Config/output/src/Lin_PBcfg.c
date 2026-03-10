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
 *  File:       Lin_PBcfg.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-25649,MCAL-25650,MCAL-25651,MCAL-25652,MCAL-25653,MCAL-25654,MCAL-25655,MCAL-25656,MCAL-25657,
          MCAL-25658,MCAL-25659,MCAL-25660,MCAL-25661,MCAL-25662,MCAL-25663,MCAL-25664,MCAL-25665,MCAL-25666,
          MCAL-25667,MCAL-25668,MCAL-25544,MCAL-25545,MCAL-25546
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Lin.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((LIN_SW_MAJOR_VERSION != (3U)) || (LIN_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Lin_PBcfg.c and Lin.h are inconsistent!"
#endif

#if ((LIN_CFG_MAJOR_VERSION != (3U)) || (LIN_CFG_MINOR_VERSION != (1U)))
  #error "Version numbers of Lin_PBcfg.c and Lin_Cfg.h are inconsistent!"
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
#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

CONST(Lin_ConfigType, LIN_CFG) Lin_Config =
{
    .linChannelCfg[0] =
    {
	    .linControllerConfig =
	    {
		    .CntrAddr = (uint32)LINB_BASE_FRAME(0U),
		    .IntrLineNum = LIN_INTERRUPT_LINE_NUM_0,
		    .LoopbackMode = LIN_LOOPBACK_DISABLED
	    },
	    .linBaudConfig = 
	    {
		    .BaudRate = (uint32)9600,
			.Prescalar = (uint32)650,
		    .FractionalDivider = (uint32)0
	    },
	    .linChannelWakeupSupport =FALSE,
        .linWakeupSource = (EcuM_WakeupSourceType )(0U)
		
    }   
};
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
#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Lin_PBcfg.c
 *********************************************************************************************************************/
