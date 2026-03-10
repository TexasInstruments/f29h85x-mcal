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
 *  File:       File name
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  Description of file's purpose                                                           
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "hw_memmap.h"
#ifdef __cplusplus

extern "C" {
#endif


/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
  #if ((CDD_ECAP_SW_MAJOR_VERSION != (3U)) ||(CDD_ECAP_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap.h are inconsistent!"
#endif

 #if ((CDD_ECAP_CFG_MAJOR_VERSION != (3U)) ||(CDD_ECAP_CFG_MINOR_VERSION != (1U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_BASEADDR_STEP             (uint32)(ECAP2_BASE - ECAP1_BASE)
#define CDD_ECAP_HR_BASEADDR_STEP          (uint32)(HRCAP6_BASE - HRCAP5_BASE)
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Ecap Driver configuration */

#define CDD_ECAP_START_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"





/* Cdd_Ecap Channel Configuration parameters */
 CONST(struct Cdd_Ecap_ConfigTag, CDD_ECAP_CONFIG_DATA)
    Cdd_Ecap_Config =
{
    .chCfg =
    {
        [0] =
        {
            .channelId = CDD_ECAP_CHANNEL4, /* Channel ID */
            .emulationMode = CDD_ECAP_EMULATION_FREE_RUN, /* Emulation Mode */
            .defaultStartEdge = CDD_ECAP_BOTH_EDGES,/* Default start edge*/
            .inputSelect = CDD_ECAP_INPUT_INPUTXBAR7,/* Input source select */
            .measurementMode = CDD_ECAP_MODE_SIGNAL_MEASUREMENT,/* Measurement Mode*/
            .signalMeasurementProperty = CDD_ECAP_HIGH_TIME,
            .instanceClkMHz = 200U,
            .prescaler = (uint8)0U, /* prescale */
            .base_addr = (uint32)ECAP5_BASE_FRAME(0U), /* Base address of the channel */
            .hr_enable = (boolean)TRUE,
            .hr_base_addr = (uint32)HRCAP5_BASE_FRAME(0U) /* Base address of the high resolution channel */
        }
    }
};


#ifdef __cplusplus
}
#endif

/*</CDD_ECAP_CONFIGURATION>*/
#define CDD_ECAP_STOP_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

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
 
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Cfg.c
 *********************************************************************************************************************/
