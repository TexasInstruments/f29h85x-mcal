
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
 *  File:       Os_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Os configuration source file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
#if ((OS_SW_MAJOR_VERSION != (1U)) || (OS_SW_MINOR_VERSION != (0U)))
  #error "Version numbers of Os_Cfg.c and Os.h are inconsistent!"
#endif

#if ( (OS_CFG_MAJOR_VERSION != (1U)) \
    ||(OS_CFG_MINOR_VERSION != (0U)))
  #error "Version numbers of Os_Cfg.c and Os_Cfg.h are inconsistent!"
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
#define OS_START_SEC_CONFIG_DATA
#include "Os_MemMap.h"


/* Os configuration structure */
CONST(struct Os_ConfigType_s, OS_CONFIG_DATA) Os_Config =
{
    .isr_cfg =
    {
        
        [0] =
        {
            .int_id = (Os_IntIdType)78U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch0Notify,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch0Notify,
        },

        [1] =
        {
            .int_id = (Os_IntIdType)79U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch1Notify,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch1Notify,
        },

        [2] =
        {
            .int_id = (Os_IntIdType)80U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch2Notify,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch2Notify,
        },

        [3] =
        {
            .int_id = (Os_IntIdType)81U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch3Notify,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Ecap_ch3Notify,
        }
    },

    .threshold = (Os_ThresholdType)0U,
};   

#define OS_STOP_SEC_CONFIG_DATA
#include "Os_MemMap.h"
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
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Os_Cfg.c
 *********************************************************************************************************************/
