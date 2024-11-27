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
 *  File:       EcuM.h
 *  Generator:  None
 *
 *  Description:  EcuM header file                                                   
 *********************************************************************************************************************/
#ifndef ECUM_H
#define ECUM_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Os.h" 
#include "EcuM_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define ECUM_SW_MAJOR_VERSION             (1U) /* Implementation Major Version. */
#define ECUM_SW_MINOR_VERSION             (0U) /* Implementation Minor Version. */
#define ECUM_SW_PATCH_VERSION             (0U) /* Implementation Patch Version. */

#define ECUM_AR_RELEASE_MAJOR_VERSION     (4U) /*  AUTOSAR Major version specification implemented by EcuM. */
#define ECUM_AR_RELEASE_MINOR_VERSION     (3U) /*  AUTOSAR Minor  version specification implemented by EcuM. */
#define ECUM_AR_RELEASE_REVISION_VERSION  (1U) /*  AUTOSAR Patch version specification implemented by EcuM. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
typedef uint32 EcuM_WakeupSourceType;

typedef P2FUNC(void,ECUM_CODE,EcuM_WakeupFuncPtrType)(EcuM_WakeupSourceType WakeupSource);

typedef struct EcuM_WakeupEventSource
{
    EcuM_WakeupSourceType source_id;
    EcuM_WakeupFuncPtrType wakeup_funcptr;
}EcuM_WakeupEventSourceType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/* 32-bit bitset corresponding to all wakeup event sources. */
extern volatile uint32 EcuM_WakeupBitSet;

/* EcuM wakeup event record */
extern volatile EcuM_WakeupEventSourceType EcuM_EventRecord[ECUM_CFG_WAKEUP_EVENT_COUNT];

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Initialize EcuM stub.
 *
 * This function initializes EcuM stub.
 *
 * \param[in] None 
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Init(void);

/** \brief Initialize all modules.
 *
 * This function initializes all modules.
 *
 * \param[in] None 
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_InitList(void);

/** \brief Set wakeup event.
 *
 * This function sets the wakeup event.
 *
 * \param[in] Sources Sources of the wakeup event
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType Sources);

/** \brief Poll a wakeup source
 *
 * This callout is called by the EcuM to poll a wakeup source. 
 *
 * \param[in] WakeupSource Sources of the wakeup event
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ECUM_H */
/*********************************************************************************************************************
 *  End of File: EcuM.h
 *********************************************************************************************************************/
