/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
    DEVICE_F29H859TU8,
    DEVICE_F29H859TM8,
    DEVICE_F29H859DM6,
    DEVICE_F29H859DU6,
    DEVICE_F29P589DM5,
    DEVICE_F29P589DU5,
    DEVICE_F29P329SM2,
    DEVICE_F29P329SM1,
    DEVICE_F29P329SJ1
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
