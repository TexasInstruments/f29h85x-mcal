[!SKIPFILE "as:modconf('Cdd_Dma/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Dma/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
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
#if ((CDD_DMA_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_DMA_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Dma.c and Cdd_Dma.h are inconsistent!"
#endif

#if ((CDD_DMA_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_DMA_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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

[!AUTOSPACING!][!//

#define CDD_DMA_START_SEC_CONFIG_DATA
#include "Cdd_Dma_MemMap.h"

[!SELECT "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']"!][!//
/** \brief Cdd Dma Configuration */
CONST(struct Cdd_Dma_ConfigTag, CDD_DMA_CONFIG_DATA) Cdd_Dma_Config =
{
[!IF "num:i(count(as:modconf('ResourceAllocator')/ResourceAllocatorGeneral/Cdd_Dma/*/CddDmaHwInstance/*))>0"!]
    .hwinstcfg =
    {
[!VAR "INDEX"= "0"!]
[!LOOP "ResourceAllocatorGeneral/Cdd_Dma/*/CddDmaHwInstance/*"!]
        [[!"num:i($INDEX)"!]] =
        {
            .instance = [!"concat('CDD_DMA',substring-after(node:value(InstanceName),'RTDMA'))"!],
            .baseaddress = (uint32)([!"concat(node:value(InstanceName),'_BASE')"!]),
            .priorityscheme = [!"node:value(CddDmaPriorityScheme  )"!],
            .emulationmode = [!"node:value(CddDmaEmulationMode    )"!],
            .swpri1 = [!//
[!VAR "SWPRI1" = "286331153"!][!// Default priority 1 for all 8 channels (0x11111111)
[!LOOP "CddDmaChannel/*"!][!//
[!VAR "CHANNEL_NAME" = "node:value(ChannelName)"!][!//
[!VAR "CHANNEL_NUM" = "num:i(substring-after($CHANNEL_NAME,'CH'))"!][!//
[!IF "$CHANNEL_NUM >= 1 and $CHANNEL_NUM <= 8"!][!//
[!VAR "PRIORITY" = "num:i(node:value(CddDmaChannelPriority))"!][!//
[!VAR "SHIFT" = "($CHANNEL_NUM - 1) * 4"!][!//
[!VAR "SWPRI1" = "$SWPRI1 - bit:shl(1,$SHIFT) + bit:shl($PRIORITY,$SHIFT)"!][!// Remove default 1, add configured priority
[!ENDIF!][!//
[!ENDLOOP!][!//
[!"num:inttohex($SWPRI1,8)"!]U,
            .swpri2 = [!//
[!VAR "SWPRI2" = "286331153"!][!// Default priority 1 for channels 9-10 only (0x11111111)
[!LOOP "CddDmaChannel/*"!][!//
[!VAR "CHANNEL_NAME" = "node:value(ChannelName)"!][!//
[!VAR "CHANNEL_NUM" = "num:i(substring-after($CHANNEL_NAME,'CH'))"!][!//
[!IF "$CHANNEL_NUM >= 9 and $CHANNEL_NUM <= 10"!][!//
[!VAR "PRIORITY" = "num:i(node:value(CddDmaChannelPriority))"!][!//
[!VAR "SHIFT" = "($CHANNEL_NUM - 9) * 4"!][!//
[!VAR "SWPRI2" = "$SWPRI2 - bit:shl(1,$SHIFT) + bit:shl($PRIORITY,$SHIFT)"!][!// Remove default 1, add configured priority
[!ENDIF!][!//
[!ENDLOOP!][!//
[!"num:inttohex($SWPRI2,8)"!]U,
            .mpuenable = [!IF "node:value(CddDmaMpuEnable)='true'"!]TRUE[!ELSE!][!WS "1"!]FALSE[!ENDIF!],
            .mpubaseaddress = (uint32)([!"concat(node:value(InstanceName),'_MPU_BASE')"!]),
            [!IF "node:value(CddDmaMpuEnable) = 'true'"!]
            .mpuregioncount = (uint8)[!"num:i(count(CddDmaMpuRegion/*))"!]U,
            .mpucfg =
            {
                [!VAR "MPUINDEX"= "0"!]
                [!LOOP "CddDmaMpuRegion/*"!]
                [[!"num:i($MPUINDEX)"!]] =
                {
                    .mpuregion = [!"node:value(CddDmaMpuRegionId)"!],
                    .mpustartaddr = [!"num:inttohex(node:value(CddDmaMpuStartAddress))"!]U,
                    .mpuendaddr = [!"num:inttohex(node:value(CddDmaMpuEndAddress))"!]U,
                    .access = [!"node:value(CddDmaMpuAccessPermission)"!],
                    .chmask = ([!VAR "sep" = "0"!][!LOOP "CddDmaMpuChannelEnable/*"!]
                    [!IF "$sep = 1"!]|[!ENDIF!](1U << (uint8)CDD_DMA_[!"node:value(node:ref(text:concat(node:path(node:ref(.)),'/ChannelName  ')))"!])
                    [!VAR "sep" = "1"!][!"'                              '"!][!ENDLOOP!]),
                },
                [!VAR "MPUINDEX" = "$MPUINDEX + 1"!]
                [!ENDLOOP!]
            },
            [!ELSE!]
            .mpuregioncount = 0U,
            .mpucfg = {},
            [!ENDIF!]
        },
[!VAR "INDEX" = "$INDEX + 1"!]
[!ENDLOOP!][!ENDIF!][!ENDSELECT!]
    },
[!SELECT "as:modconf('Cdd_Dma/Cdd')/CddDmaConfig"!]
[!IF "num:i(count(as:modconf('Cdd_Dma/Cdd')[1]/CddDmaConfig/CddDmaChannel/*))>0"!]
    .chcfg = 
    {
[!LOOP "as:modconf('Cdd_Dma/Cdd')[1]/CddDmaConfig/CddDmaChannel/*"!]
        [[!"@index"!]] = 
        {
            .instance = [!"concat('CDD_DMA',substring-after(node:value(CddDmaInstance),'RTDMA'))"!],
            .channel = [!"concat('CDD_DMA_',node:value(CddDmaChannel))"!],
            .baseaddress = (uint32)[!"node:value(node:ref(node:ref(CddDmaChannelRef)/ChannelRef)/BaseAddr)"!],
            .chintnotification = [!IF "(node:exists(CddDmaChIntNotification))"!][!IF "node:value(CddDmaChIntNotification) = 'NULL_PTR'"!] NULL_PTR[!ELSE!][!WS "1"!](Cdd_Dma_NotifyType)[!"(node:value(CddDmaChIntNotification))"!][!ENDIF!][!ELSE!][!WS "1"!]NULL_PTR[!ENDIF!],
            .overflowintnotification = [!IF "(node:exists(CddDmaOverflowIntNotification))"!][!IF "node:value(CddDmaOverflowIntNotification) = 'NULL_PTR'"!] NULL_PTR[!ELSE!][!WS "1"!](Cdd_Dma_NotifyType)[!"(node:value(CddDmaOverflowIntNotification))"!][!ENDIF!][!ELSE!][!WS "1"!]NULL_PTR[!ENDIF!],
        },
[!ENDLOOP!]
    },
[!ENDIF!]
};
[!ENDSELECT!]

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
