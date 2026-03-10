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
 *  File:       DeviceSupport.h
 *  Generator:  None
 *
 *  Description:  DeviceSupport header file
 *********************************************************************************************************************/
#ifndef DEVICESUPPORT_H
#define DEVICESUPPORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "hw_memmap.h"
#include "hw_fri.h"
#include "hw_types.h"
#include "hw_asysctl.h"
#include "hw_ssu.h"
#include "hw_sysctl.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
//*****************************************************************************
//
//! Macros for FRI options to use with the Flash_ConfigFRI() function.
//! Includes macros for enabling and disabling prefetch, data cache, code cache
//! and data preread.
//
//*****************************************************************************
#define FLASH_PREFETCH_ENABLE     0x1U
#define FLASH_PREFETCH_DISABLE    0x0U
#define FLASH_DATACACHE_ENABLE    0x2U
#define FLASH_DATACACHE_DISABLE   0x0U
#define FLASH_CODECACHE_ENABLE    0x4U
#define FLASH_CODECACHE_DISABLE   0x0U
#define FLASH_DATAPREREAD_ENABLE  0x8U
#define FLASH_DATAPREREAD_DISABLE 0x0U

//
// Internal macros used for committing trim registers.
// Not intended for application use.
//
#define ASYSCTL_O_FLASHTRIMCOMMIT                   0x90U
#define ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITREAD  0x1U
#define ASYSCTL_FLASHTRIMCOMMIT_FLC0TRIMCOMMITOTHER 0x2U
#define ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITREAD  0x4U
#define ASYSCTL_FLASHTRIMCOMMIT_FLC1TRIMCOMMITOTHER 0x8U
#define ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITREAD  0x10
#define ASYSCTL_FLASHTRIMCOMMIT_FLC2TRIMCOMMITOTHER 0x20

//*****************************************************************************
//
//! Macro to define the offset between options for different FRIs.
//! For example, FRI_O_2_INTF_CTRL - FRI_O_1_INTF_CTRL = 0x10U.
//
//*****************************************************************************
#define FRI_REG_STEP 0x10U

//*****************************************************************************
//
// Defines related to Flash Support
//
//*****************************************************************************
#define DEVICE_FLASH_WAITSTATES ((uint8)3)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
//*****************************************************************************
//
//! Enumeration of FRI register addresses for use with Flash_ConfigFRI()
//
//*****************************************************************************
typedef enum
{
    FLASH_FRI1 = 0,
    FLASH_FRI2 = 1,
    FLASH_FRI3 = 2,
    FLASH_FRI4 = 3
} Flash_FRI;

//*****************************************************************************
//
//! Enumeration of devices to be used with Emulation API
//
//*****************************************************************************
typedef enum
{
    DEVICE_F29H859TU8Q,
    DEVICE_F29H859TM8Q,
    DEVICE_F29H859DU6Q,
    DEVICE_F29P589DU5Q,
    DEVICE_F29P589DM5Q,
    DEVICE_F29P329SJ1Q,
    DEVICE_F29P329SM1Q,
    DEVICE_F29P329SM2Q
} Device_PartNumber;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
extern uint32 CPU3_RESET_VECTOR;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Initialize the Device specific support.
 *
 * This function initializes the Flash wait states if required.
 *
 * \pre None
 * \post None
 *
 *********************************************************************************************************************/
void DeviceSupport_Init();
void DeviceSupport_EmulateDevice(Device_PartNumber partNumber);
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* DEVICESUPPORT_H */
/*********************************************************************************************************************
 *  End of File: DeviceSupport.h
 *********************************************************************************************************************/
