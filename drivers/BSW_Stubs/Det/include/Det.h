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
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) FaultId);

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
