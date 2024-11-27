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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Std_Types.h
 *  Generator:  None
 *
 *  Description:  Template file to define Standard Types used in AUTOSAR.                                                           
 *********************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
    #define E_OK    ((uint8)0x00U)      /* Return OK     */
    typedef unsigned char StatusType;
#endif
#define E_NOT_OK    ((uint8)0x01U)      /* Return Not OK */

#define STD_HIGH    0x01U               /* Physical state 5V or 3.3V */
#define STD_LOW     0x00U               /* Physical state 0v         */

#define STD_ACTIVE 0x01U                /* Logical state active */
#define STD_IDLE   0x00U                /* Logical state idle   */

#define STD_ON     0x01U                /* Turn ON */
#define STD_OFF    0x00U                /* Turn OFF */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* This type can be used as standard API return type which is shared between the RTE and the BSW modules.*/
typedef uint8       Std_ReturnType;     
                                        
/* This type shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() function. */
typedef struct  Std_VersionInfoTag      
{
    uint16          vendorID;           
    uint16          moduleID;
    uint8           instanceID;
    uint8           sw_major_version;
    uint8           sw_minor_version;
    uint8           sw_patch_version;
} Std_VersionInfoType;                  

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* STD_TYPES_H */
/*********************************************************************************************************************
 *  End of File: Std_Types.h
 *********************************************************************************************************************/
