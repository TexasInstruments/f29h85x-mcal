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
 *  File:       Cdd_Xbar_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
#include "Cdd_Xbar.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_XBAR_SW_MAJOR_VERSION != (3U)) || (CDD_XBAR_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != (3U)) || (CDD_XBAR_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif


/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/


#define CDD_XBAR_START_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/** \brief CDD Crossbar Configuration */
VAR(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = 
{
  /* Design: MCAL-25701 */
    .Cdd_Xbar_InputCfg = 
    {
        {
            .inputSelect = CDD_XBAR_INPUT1,   /* Design: MCAL-25720 */
            .inputLine = 12U,    /* GPIO12 */  /* Design: MCAL-25721 */
            .selectConfigLock = FALSE,   /* Design: MCAL-25707 */
        },
        {
            .inputSelect = CDD_XBAR_INPUT2,   /* Design: MCAL-25720 */
            .inputLine = 13U,    /* GPIO13 */  /* Design: MCAL-25721 */
            .selectConfigLock = FALSE,   /* Design: MCAL-25707 */
        },
        {
            .inputSelect = CDD_XBAR_INPUT3,   /* Design: MCAL-25720 */
            .inputLine = 17U,    /* GPIO17 */  /* Design: MCAL-25721 */
            .selectConfigLock = FALSE,   /* Design: MCAL-25707 */
        },
    },
  /* Design: MCAL-25708 */
    .outConfigLock = FALSE,
  /* Design: MCAL-25709 */
    .epwmConfigLock = FALSE,
    /* Design: MCAL-25710 */
    .clbConfigLock = FALSE,
    /* Design: MCAL-25711 */
    .mindbConfigLock = FALSE,
  /* Design: MCAL-25712 */
    .iclConfigLock = FALSE,
    .inputFlagBaseAddress = (uint32)XBAR_BASE_FRAME(0U),
};

#define CDD_XBAR_STOP_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Cfg.c
 *********************************************************************************************************************/
