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
 *  File:       None
 *  Generator:  None
 *
 *  Description:  EcuM source file                                                    
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "EcuM.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/* AUTOSAR version information check has to match definition in header file */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
     (ECUM_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (ECUM_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "EcuM: AUTOSAR Version Numbers of EcuM are different"
#endif

/* Vendor specific version information is BCD coded */
#if ((ECUM_SW_MAJOR_VERSION != (1U)) || (ECUM_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of EcuM.c and EcuM.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    uint8 i;
    for(i=0;i<ECUM_CFG_WAKEUP_EVENT_COUNT;i++)
    {
        if(EcuM_EventRecord[i].source_id & WakeupSource)
        {
            /* Clear the wakeup source bit corresponding to each wakeup source. */
            EcuM_WakeupBitSet &= ~(EcuM_EventRecord[i].source_id);
            /* Call source specific CheckWakeup function */
            (EcuM_EventRecord[i].wakeup_funcptr)(WakeupSource); 
        }
    } 
}

FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType Sources)
{
    /* Set the wakeup source bits corresponding to each wakeup source.  */
    EcuM_WakeupBitSet |= Sources;
}

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* Initializes EcuM stub */
FUNC(void, ECUM_CODE) EcuM_Init(void)
{
    EcuM_InitList(); /* Initializes all modules*/
    Os_StartOS(); /* Initializes Os stub */
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: EcuM.c
 *********************************************************************************************************************/
