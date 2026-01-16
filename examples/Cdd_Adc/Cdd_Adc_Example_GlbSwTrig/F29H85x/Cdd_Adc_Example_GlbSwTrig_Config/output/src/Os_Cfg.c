
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
            .int_id = (Os_IntIdType)87U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int1Isr,
        },

        [1] =
        {
            .int_id = (Os_IntIdType)88U,
            .int_priority = (Os_IntPriorityType)1U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int2Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_Int2Isr,
        },

        [2] =
        {
            .int_id = (Os_IntIdType)92U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCB_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCB_Int1Isr,
        },

        [3] =
        {
            .int_id = (Os_IntIdType)93U,
            .int_priority = (Os_IntPriorityType)2U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCB_Int2Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCB_Int2Isr,
        },

        [4] =
        {
            .int_id = (Os_IntIdType)97U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCC_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCC_Int1Isr,
        },

        [5] =
        {
            .int_id = (Os_IntIdType)98U,
            .int_priority = (Os_IntPriorityType)3U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCC_Int2Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCC_Int2Isr,
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
            .int_id = (Os_IntIdType)107U,
            .int_priority = (Os_IntPriorityType)255U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCE_Int1Isr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCE_Int1Isr,
        },

        [8] =
        {
            .int_id = (Os_IntIdType)86U,
            .int_priority = (Os_IntPriorityType)12U,
            .int_category = (Os_IntCategoryType)CATEGORY_1,
            .int_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_PpbEvtIntIsr,
            .isr_funcptr = (Os_IsrFuncPtrType)Cdd_Adc_ADCA_PpbEvtIntIsr,
        }
    },

    .threshold = (Os_ThresholdType)25U,
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
