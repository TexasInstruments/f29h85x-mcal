/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2026 Texas Instruments Incorporated
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
 *  File:       Cdd_Dma_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/

/*
 * Design: MCAL-39320, MCAL-39321, MCAL-39322, MCAL-39323, MCAL-39324, MCAL-39325, MCAL-39326, MCAL-39327, MCAL-39328
 * Design: MCAL-39329, MCAL-39330, MCAL-39331
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_memmap.h"
#include "Cdd_Dma.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_DMA_SW_MAJOR_VERSION != (1U)) || (CDD_DMA_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Cdd_Dma.c and Cdd_Dma.h are inconsistent!"
#endif

#if ((CDD_DMA_CFG_MAJOR_VERSION != (1U)) || (CDD_DMA_CFG_MINOR_VERSION != (1U)))
    #error "Version numbers of Cdd_Dma_Cfg.c and Cdd_Dma_Cfg.h are inconsistent!"
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


#define CDD_DMA_START_SEC_CONFIG_DATA
#include "Cdd_Dma_MemMap.h"

/** \brief Cdd Dma Configuration */
CONST(struct Cdd_Dma_ConfigTag, CDD_DMA_CONFIG_DATA) Cdd_Dma_Config =
{
    .hwinstcfg =
    {
        [0] =
        {
            .instance = CDD_DMA1,
            .baseaddress = (uint32)(RTDMA1_BASE),
            .priorityscheme = CDD_DMA_PRIORITY_SOFTWARE_CONFIG,
            .emulationmode = CDD_DMA_EMULATION_STOP,
            .swpri1 = 0x11111111U,
            .swpri2 = 0x11111111U,
            .mpuenable =TRUE,
            .mpubaseaddress = (uint32)(RTDMA1_MPU_BASE),
            .mpuregioncount = (uint8)1U,
            .mpucfg =
            {
                [0] =
                {
                    .mpuregion = CDD_DMA_MPUR1,
                    .mpustartaddr = 0x200e0000U,
                    .mpuendaddr = 0x200e0fffU,
                    .access = CDD_DMA_READ_WRITE_ACCESS,
                    .chmask = ((1U << (uint8)CDD_DMA_CH1)
                              ),
                },
            },
        },
    },
    .chcfg = 
    {
        [0] = 
        {
            .instance = CDD_DMA1,
            .channel = CDD_DMA_CH1,
            .baseaddress = (uint32)RTDMA1CH1_BASE_FRAME(0U),
            .chintnotification = NULL_PTR,
            .overflowintnotification = NULL_PTR,
        },
    },
};

#define CDD_DMA_STOP_SEC_CONFIG_DATA
#include "Cdd_Dma_MemMap.h"

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
 *  End of File: Cdd_Dma_Cfg.c
 *********************************************************************************************************************/
