[!SKIPFILE "node:value(as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
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
#if ((OS_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (OS_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Os_Cfg.c and Os.h are inconsistent!"
#endif

#if ( (OS_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    ||(OS_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!SELECT "as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']"!]
[!LOOP "OsIsr/*"!][!//
[!IF "OsIsrCategory = 'CATEGORY_2'"!][!//
MCAL_LIB_INT_ISR(Os_Isr[!"InterruptId"!])
{
    Os_IsrCat2((Os_IntIdType)[!"InterruptId"!]);
}
[!ENDIF!][!//
[!ENDLOOP!][!//

/* Os configuration structure */
[!LOOP "Os_ConfigSet"!][!//
CONST(struct Os_ConfigType_s, OS_CONFIG_DATA) Os_Config =
{
    .isr_cfg =
    {
        [!LOOP "as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']/OsIsr/*"!]
        [[!"@index"!]] =
        {
            .int_id = (Os_IntIdType)[!"InterruptId"!]U,
            .int_priority = (Os_IntPriorityType)[!"InteruptPriority"!]U,
            .int_category = (Os_IntCategoryType)[!"OsIsrCategory"!],
            .int_funcptr = (Os_IsrFuncPtrType)[!IF "OsIsrCategory = 'CATEGORY_1'"!][!"ISRFunc"!][!ELSE!]Os_Isr[!"InterruptId"!][!ENDIF!],
            .isr_funcptr = (Os_IsrFuncPtrType)[!IF "OsIsrCategory = 'CATEGORY_1'"!][!"ISRFunc"!][!ELSE!]ISR_[!"ISRFunc"!][!ENDIF!],
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },
[!IF "as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']/OsCounter/*[1]/OsCounterEnable = 'true'"!]
    .counter_cfg =
    {
        [!LOOP "as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']/OsCounter/*"!]
        [[!"@index"!]] =
        {
            .max_timercount = (Os_CounterMaxValue)[!"OsCounterMaxAllowedValue"!]U,
            .counter_id = (Os_CounterIdType)[!"OsCounterId"!]U,
            .counter_type = (Os_CounterType)OS_HARDWARE_COUNTER,
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },    
[!ENDIF!]
    .threshold = (Os_ThresholdType)[!"OsRtIntThreshold"!]U,
};   
[!ENDLOOP!][!//
[!ENDSELECT!][!//

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
