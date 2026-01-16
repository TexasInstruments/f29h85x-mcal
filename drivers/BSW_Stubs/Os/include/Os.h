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
 *  File:       Os.h
 *  Generator:  None
 *
 *  Description: Os stub header file.
 *********************************************************************************************************************/
#ifndef OS_H
#define OS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Os_Cfg.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define MAX_NUMBER_OF_INTERRUPTS       (256U)  /* Maximum number of interrupts supported by the device.*/
#define DEFAULT_GROUP_MASK             (0xFFU) /* Default group mask on initialization of the PIPE control registers*/
#define DISABLE_GROUP_MASK             (0x00U) /* Disable interrupt nesting by selecting this group mask. */
#define TIMERDIVIDEDOWN_PERTICK        (0xC7U) /* This value in timer divide down register makes 1 TICK */

#define OS_SW_MAJOR_VERSION             (1U) /* Implementation Major Version. */
#define OS_SW_MINOR_VERSION             (0U) /* Implementation Minor Version. */
#define OS_SW_PATCH_VERSION             (0U) /* Implementation Patch Version. */

#define OS_AR_RELEASE_MAJOR_VERSION     (4U) /*  AUTOSAR Major version specification implemented by OS. */
#define OS_AR_RELEASE_MINOR_VERSION     (3U) /*  AUTOSAR Minor  version specification implemented by OS. */
#define OS_AR_RELEASE_REVISION_VERSION  (1U) /*  AUTOSAR Patch version specification implemented by OS. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#define ISR(Name)             void ISR_##Name(void)

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

typedef P2FUNC(void,OS_ISR_CODE,Os_IsrFuncPtrType)(void);

typedef uint8 Os_IntIdType;
typedef uint8 Os_IntPriorityType;

typedef uint8 Os_CounterIdType;
typedef uint32 Os_CounterMaxValue;

typedef uint8 Os_ThresholdType;

typedef uint32 Os_TickType;
typedef Os_TickType* Os_TickRefType;

typedef enum{
    OS_HARDWARE_COUNTER,
    OS_SOFTWARE_COUNTER
} Os_CounterType;

typedef enum{
    CATEGORY_1,
    CATEGORY_2
} Os_IntCategoryType;

typedef enum
{
    OS_TIMER2CLK_DIV_1  = 0,  /* Cputimer2 clock =  Cputimer2 clock / 1 */  
    OS_TIMER2CLK_DIV_2  = 1,  /* Cputimer2 clock =  Cputimer2 clock / 2 */  
    OS_TIMER2CLK_DIV_4  = 2,  /* Cputimer2 clock =  Cputimer2 clock / 4 */  
    OS_TIMER2CLK_DIV_8  = 3,  /* Cputimer2 clock =  Cputimer2 clock / 8 */  
    OS_TIMER2CLK_DIV_16 = 4   /* Cputimer2 clock =  Cputimer2 clock / 16 */  
}Os_PrescalerType;

typedef struct
{
    Os_CounterMaxValue max_timercount; /* Maximum allowed timer count */
    Os_CounterIdType counter_id; /* Numeric ID of the counter */
    Os_CounterType counter_type; /* Counter type (hardware or software) */
}Os_CounterCfgType;

typedef struct
{
    Os_IntIdType int_id; /* Interrupt ID */
    Os_IntPriorityType int_priority; /* Interrupt priority level */
    Os_IntCategoryType int_category; /* Interrupt category */
    Os_IsrFuncPtrType int_funcptr; /* Function pointer to the ISR */
    Os_IsrFuncPtrType isr_funcptr; /* Function pointer to the ISR */
}Os_IsrCfgType;

typedef struct Os_ConfigType_s
{
    /* 
     * Threshold to differentiate RTINT and INT. Interrupts with priority less than the threshold value are
     *   considered as RTINT else considered as INT.
     */
    Os_ThresholdType threshold;
    /* Os configuration structure */
    Os_IsrCfgType isr_cfg[OS_CFG_MAX_ISR];
    
#if(STD_ON == OS_COUNTER_ENABLE)
    Os_CounterCfgType counter_cfg[OS_CFG_MAX_COUNTER];
#endif
}Os_CfgType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
extern const Os_CfgType *Os_CfgPtr;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Configures the counter and interrupts.
 *
 * This function configures the interrupts and the counter used by RTOS.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void,OS_CODE) Os_StartOS(void);

/** \brief CAT2 ISR common function prototype
 *
 * This is a common function which is called when a CAT2 interrupt is generated. 
 * This function internally calls the ISR corresponding to the interrupt.
 *
 * \param[in] InterruptId Interrupt ID of the interrupt
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void,OS_CODE) Os_IsrCat2(Os_IntIdType InterruptId); 

#if(STD_ON == OS_COUNTER_ENABLE)
/** \brief  Reads the current count value of a counter.
 *
 * This function reads the current count value of a counter (returning hardware timer ticks).
 *
 * \param[in] CounterId The Counter which tick value should be read
 * \param[in] value  Current value of the counter is stored in this variable.
 * \param[out] None
 * \pre None
 * \post None
 * \return Return E_OK if there are no errors
 * \retval E_OK: No errors
 *
 *********************************************************************************************************************/
FUNC(StatusType,OS_CODE) GetCounterValue(Os_CounterIdType CounterId, Os_TickRefType Value);

/** \brief Reads the elapsed count value of a counter.
 *
 * This function reads the elapsed value with respect to a particular instance of the counter.
 *
 * \param[in] CounterId The Counter which tick value should be read
 * \param[in] value   The value corresponding to which the elapse value is calculated.
 * \param[in] ElapsedValue The elapsed value of the counter is stored in this variable.
 * \param[out] None
 * \pre None
 * \post None
 * \return Return E_OK if there are no errors
 * \retval E_OK: No errors
 *
 *********************************************************************************************************************/
FUNC(StatusType,OS_CODE) GetElapsedValue(Os_CounterIdType CounterId, Os_TickRefType Value,Os_TickRefType ElapsedValue);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OS_H */
/*********************************************************************************************************************
 *  End of File: Os.h
 *********************************************************************************************************************/
