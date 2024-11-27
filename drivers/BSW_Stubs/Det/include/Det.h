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
 *  File:       Det.h
 *  Generator:  Code generation tool (if any)
 *
 *  Description: Development Error Tracer header file.                                                      
 *********************************************************************************************************************/
#ifndef DET_H
#define DET_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define DET_SW_MAJOR_VERSION            (1U) /* Driver Implementation Major Version. */
#define DET_SW_MINOR_VERSION            (0U) /* Driver Implementation Minor Version. */
#define DET_SW_PATCH_VERSION            (0U) /* Driver Implementation Patch Version. */

#define DET_AR_RELEASE_MAJOR_VERSION    (4U) /*  AUTOSAR Major version specification implemented by DET Driver. */
#define DET_AR_RELEASE_MINOR_VERSION    (3U) /*  AUTOSAR Minor  version specification implemented by DET Driver. */
#define DET_AR_RELEASE_REVISION_VERSION (1U) /*  AUTOSAR Patch version specification implemented by DET Driver. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service to report development errors
 *
 * The function logs the error and never returns.
 *
 * \param[in] ModuleId      Module ID of calling module
 * \param[in] InstanceId    The identifier of the index based instance of a module, starting from 0, 
 *                          If the module is a single instance module it shall pass 0 as the InstanceId.
 * \param[in] ApiId         ID of API service in which error is detected (defined in SWS of calling module)
 * \param[in] ErrorId       ID of detected development error (defined in SWS of calling module).
 * \pre None
 * \post None
 * \return Never returns a value, but has a return type for compatibility with services and hooks
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) ErrorId);

/** \brief Service to report runtime errors.
 *
 * \param[in] ModuleId      Module ID of calling module
 * \param[in] InstanceId    The identifier of the index based instance of a module, starting from 0, 
 *                          If the module is a single instance module it shall pass 0 as the InstanceId.
 * \param[in] ApiId         ID of API service in which error is detected (defined in SWS of calling module)
 * \param[in] ErrorId       ID of detected development error (defined in SWS of calling module).
 * \pre None
 * \post None
 * \return Returns always E_OK (is required for services)
 * \retval E_OK: Service executed as expected.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) ErrorId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* DET_H */
/*********************************************************************************************************************
 *  End of File: Det.h
 *********************************************************************************************************************/
