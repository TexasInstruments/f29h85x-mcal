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
 *  File:       MemIf_Types.h
 *  Project:    C29x MCAL
 *  Generator:  None
 *
 *  Description:  MemIf Types
 *                                                                   
 *********************************************************************************************************************/
 #ifndef MEMIF_TYPES_H
 #define MEMIF_TYPES_H

 #ifdef __cplusplus
 extern "C"{
 #endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/**<
 *  @brief  MemIf Module Status Types.
 */
 /*SWS_MemIf_00064*/
typedef enum MemIf_StatusType {
    MEMIF_UNINIT = 0U,
    /**< Module/Device Driver has not been initialized yet */
    MEMIF_IDLE,
    /**< Module/Device Driver is currently IDLE */
    MEMIF_BUSY,
    /**< Module/Device Driver is currently BUSY */
    MEMIF_BUSY_INTERNAL,
    /**< Module/Device Driver is busy with Internal management operations */
} MemIf_StatusType;

/**<
 *  @brief  MemIf Mode Types.
 */
 /*SWS_MemIf_00066*/
typedef enum MemIf_ModeType {
    MEMIF_MODE_SLOW = 0U,
    /**< Module/Device Driver are working in slow mode */
    MEMIF_MODE_FAST,
    /**< Module/Device Driver are working in fast mode */
} MemIf_ModeType;

/**<
 *  @brief  MemIf Job Results Types.
 */
 /*SWS_MemIf_00065*/
typedef enum MemIf_JobResultType {
    MEMIF_JOB_OK = 0U,
    /**< The job has been finished successfully */
    MEMIF_JOB_FAILED,
    /**< The job has not finished successfully */
    MEMIF_JOB_PENDING,
    /**< The job has not yet been finished */
    MEMIF_JOB_CANCELED,
    /**< The job has been canceled */
    MEMIF_BLOCK_INCONSISTENT,
    /**< The requested block is inconsistent or BLOCK not found*/
    MEMIF_BLOCK_INVALID,
    /**< The requested block has been marked invalid, operation cannot be performed */
} MemIf_JobResultType;

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

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MEMIF_TYPES_H */

/*********************************************************************************************************************
 *  End of File: MEMIf_Type.h
 *********************************************************************************************************************/