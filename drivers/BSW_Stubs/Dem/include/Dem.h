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
 *  File:       Dem.h
 *  Generator:  None
 *
 *  Description:  Diagnostic Event Manager header file.                                                           
 *********************************************************************************************************************/
#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dem_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define DEM_SW_MAJOR_VERSION            (1U) /* Driver Implementation Major Version. */
#define DEM_SW_MINOR_VERSION            (0U) /* Driver Implementation Minor Version. */
#define DEM_SW_PATCH_VERSION            (0U) /* Driver Implementation Patch Version. */

#define DEM_AR_RELEASE_MAJOR_VERSION    (4U) /*  AUTOSAR Major version specification implemented by DEM Driver. */
#define DEM_AR_RELEASE_MINOR_VERSION    (3U) /*  AUTOSAR Minor  version specification implemented by DEM Driver. */
#define DEM_AR_RELEASE_REVISION_VERSION (1U) /*  AUTOSAR Patch version specification implemented by DEM Driver. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* Identification of an event by assigned EventId. The EventId is assigned by the Dem. Remark: 0 is not a valid value*/
typedef uint16 Dem_EventIdType; 

/* This type contains all monitor test result values, which can be reported via Dem_SetEventStatus(). */
typedef enum Dem_EventStatusTag
{
    /* Monitor reports qualified test result passed. */ 
    DEM_EVENT_STATUS_PASSED = 0x00U,
    /* Monitor reports qualified test result failed. */
    DEM_EVENT_STATUS_FAILED = 0x01U,          
    /* Monitor reports non-qualified test result pre-passed (debounced Dem-internally). */      
    DEM_EVENT_STATUS_PREPASSED = 0x02U,             
    /* Monitor reports non-qualified test result pre-failed (debounced Dem-internally). */
    DEM_EVENT_STATUS_PREFAILED = 0x03U,       
    /* Monitor triggers the storage of ExtendedDataRecords and FreezeFrames ON_FDC_THRESHOLD. */      
    DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED = 0x04U,
} Dem_EventStatusType;

/* This type shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() function. */
typedef struct  Dem_EventReportTag     
{
    Dem_EventIdType          event_id;           
    Dem_EventStatusType      event_status;
} Dem_EventReportType;   

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
extern volatile Dem_EventReportType Dem_ReportRecord[DEM_CFG_EVENT_COUNT];

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service to set diagostic events
 *
 * Called by SW-Cs or BSW modules to report monitor status information to the Dem. 
 * BSW modules calling Dem_SetEventStatus can safely ignore the return value.
 *
 * \param[in] EventId      Identification of an event by assigned EventId.
 * \param[in] EventStatus  Monitor test result 
 * \pre None
 * \post None
 * \return Returns status of set event operation.
 * \retval  E_OK: set of event status was successful. 
 *          E_NOT_OK: Event status setting or processing failed or could not be accepted.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, DEM_DATA) EventId, \
VAR(Dem_EventStatusType, DEM_DATA) EventStatus);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* DEM_H */
/*********************************************************************************************************************
 *  End of File: Dem.h
 *********************************************************************************************************************/
