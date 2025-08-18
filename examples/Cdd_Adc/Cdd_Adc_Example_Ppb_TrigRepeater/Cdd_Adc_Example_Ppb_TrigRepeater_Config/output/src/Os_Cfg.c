
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

MCAL_LIB_INT_ISR(Os_Isr89)
{
    Os_IsrCat2((Os_IntIdType)89);
}

/* Os configuration structure */
CONST(struct Os_ConfigType_s, OS_CONFIG_DATA) Os_ConfigSet =
{
    .isr_cfg =
    {
        
        [0] =
        {
            .int_id = (Os_IntIdType)86U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_PpbEvtIntIsr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_PpbEvtIntIsr,
        },

        [1] =
        {
            .int_id = (Os_IntIdType)87U,
            .int_priority = (Os_IntPriorityType)15U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int1Isr,
        },

        [2] =
        {
            .int_id = (Os_IntIdType)88U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int2Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int2Isr,
        },

        [3] =
        {
            .int_id = (Os_IntIdType)89U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_2,
            .int_funcptr = (Os_IsrFuncPtrType)Os_Isr89,
            .isr_funcptr = (Os_IsrFuncPtrType)ISR_Cdd_Adc_ADCA_Int3Isr,
        },

        [4] =
        {
            .int_id = (Os_IntIdType)90U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int4Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int4Isr,
        },

        [5] =
        {
            .int_id = (Os_IntIdType)6U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Gpt_Ch0Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Gpt_Ch0Isr,
        },

        [6] =
        {
            .int_id = (Os_IntIdType)102U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCD_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCD_Int1Isr,
        },

        [7] =
        {
            .int_id = (Os_IntIdType)103U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCD_Int2Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCD_Int2Isr,
        }
    },

    .threshold = (Os_ThresholdType)20U,
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
