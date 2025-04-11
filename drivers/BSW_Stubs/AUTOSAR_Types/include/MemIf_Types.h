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