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
