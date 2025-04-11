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
#include "Os_Cfg.h"
#include "hw_types.h"
#include "hw_pipe.h"
#include "hw_memmap.h"
#include "hw_cputimer.h"
#include "hw_ints.h"
#include "hw_sysctl.h"

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

typedef enum{
    SSU_LINK0   = 0,
    SSU_LINK1   = 1,
    SSU_LINK2   = 2,
    SSU_LINK3   = 3,
    SSU_LINK4   = 4,
    SSU_LINK5   = 5,
    SSU_LINK6   = 6,
    SSU_LINK7   = 7,
    SSU_LINK8   = 8,
    SSU_LINK9   = 9,
    SSU_LINK10  = 10,
    SSU_LINK11  = 11,
    SSU_LINK12  = 12,
    SSU_LINK13  = 13,
    SSU_LINK14  = 14,
    SSU_LINK15  = 15,
} SSU_LinkType;

typedef enum
{
    OS_TIMER2CLK_DIV_1  = 0,  /* Cputimer2 clock =  Cputimer2 clock / 1 */  
    OS_TIMER2CLK_DIV_2  = 1,  /* Cputimer2 clock =  Cputimer2 clock / 2 */  
    OS_TIMER2CLK_DIV_4  = 2,  /* Cputimer2 clock =  Cputimer2 clock / 4 */  
    OS_TIMER2CLK_DIV_8  = 3,  /* Cputimer2 clock =  Cputimer2 clock / 8 */  
    OS_TIMER2CLK_DIV_16 = 4   /* Cputimer2 clock =  Cputimer2 clock / 16 */  
}Os_PrescalerType;

typedef enum
{
    SSU_STACK1 = 1,
    SSU_STACK2 = 2,
    SSU_STACK3 = 3,
    SSU_STACK4 = 4,
    SSU_STACK5 = 5,
    SSU_STACK6 = 6,
    SSU_STACK7 = 7
} SSU_StackType;

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

/** \brief Sets the INT Stack Pointer.
 *
 * CPU will acknowledge the INT only when its current execution stack matched with INTSP
 *
 * \param[in] Stack is the INT stack.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static inline void
Interrupt_setINTSP(SSU_StackType Stack)
{
    HWREG(PIPE_BASE + PIPE_O_INTSP) = Stack;
}

/** \brief Set the Interrupt Link Owner.
 *
 * This function sets the interrupt link owner.
 *
 * \param[in] IntNum specifies the interrupt in question.
 * \param[in] LinkOwner LinkOwner to be set for the interrupt (SSU_LINK0..15)
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static inline void
Interrupt_SetLinkOwner(uint32 IntNum, SSU_LinkType LinkOwner)
{
    uint32 base = PIPE_BASE + PIPE_O_INT_LINK_OWNER(IntNum);
    HWREG(base) = (HWREG(base) & 0xF0U) | (uint8)LinkOwner;
}

/** \brief Global enable for INT and RTINT
 *
 * The function enables the global enable bit to forward INT and RTINT  interrupts  to CPU.
 *
 * \param[in] None
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_GlobalEnable(void)
{
    HWREG(PIPE_BASE + PIPE_O_GLOBAL_EN) = (0x3U | PIPE_GLOBAL_EN_KEY);
}

/** \brief Global disable for INT and RTINT.
 *
 * The function disables the global enable bit to not forward INT and RTINT
 * interrupts  to CPU.
 *
 * \param[in] None
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_DisableGlobal(void)
{
    HWREG(PIPE_BASE + PIPE_O_GLOBAL_EN) = PIPE_GLOBAL_EN_KEY;
}

/** \brief Enables the specified interrupt.
 *
 * The function enables the interrupt which allows the interrupt to participate 
 * in priority arbitration.
 *
 * \param[in] IntNum Numeric ID of the interrupt.
 *                         It should be unique & in between 0 and 255 including.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_EnableInterrupt(uint8 IntNum)
{
    HWREG(PIPE_BASE + PIPE_O_INT_CTL_L(IntNum)) = PIPE_INT_CTL_L_EN;
}

/** \brief Set the Interrupt Priority Level
 *
 * The function sets the priority to the specified interrupt.
 *
 * \param[in] IntNum Numeric ID of the interrupt.
 *                         It should be unique & in between 0 and 255 including.
 * \param[in] Priority Priority level of the interrupt.
 *                     It should be in between 0 and 255 including them.
 *                     Two interrupts can have same priority level.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_SetIntPriority(uint8 IntNum, uint8 Priority)
{
    uint32 base = PIPE_BASE + PIPE_O_INT_CONFIG(IntNum);
    HWREG(base) = (HWREG(base) & ~PIPE_INT_CONFIG_PRI_LEVEL_M) | Priority;
}

/** \brief Set the Interrupt Group Mask
 *
 * The function sets the group mask for the interrupts.Interrupts in a given 
 * group do not preempt or nest within other interrupts in the group. Any other 
 * group mask chosen for INT_GRP_MASK that is not listed results in using 
 * the default group mask of 0xFF (all interrupts can nest).
 *
 * \param[in] GroupMask Group mask (0-255).
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_SetGroupMask(uint8 GroupMask)
{
    HWREG(PIPE_BASE + PIPE_O_INT_GRP_MASK) = GroupMask;
}

/** \brief Set the threshold for RTINT
 *
 * This function sets the interrupt threshold value to group incoming interrupt 
 * as RTINT or INT interrupt.
 *
 * \param[in] Threshold Threshold value (0-256)
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void Interrupt_SetThreshold(uint8 Threshold)
{
    HWREG(PIPE_BASE + PIPE_O_RTINT_THRESHOLD) = Threshold;
}

/** \brief Select clock source prescaler
 *
 * The function selects the prescaler for the timer clock source.
 *
 * \param[in] Prescaler Value for the timer 2 clock source prescaler.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_TimerPrescaler(Os_PrescalerType Prescaler)
{
    /* Clear TSS bit of register TCR */
    HWREG(DEVCFG_BASE + SYSCTL_O_TMR2CLKCTL) = \
    (HWREG(DEVCFG_BASE + SYSCTL_O_TMR2CLKCTL) & \
        ~(SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M)) | \
        ((uint8)Prescaler << SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S);
}

/** \brief Starts/restarts CPU timer2.
 *
 * The function starts/restarts the CPU timer2.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_StartTimer(void)
{
    /* Clear TSS bit of register TCR */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) &= ~CPUTIMER_TCR_TSS;
}

/** \brief Reloads CPU timer2.
 *
 * The function reloads the CPU timer2.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_ReloadTimer(void)
{
    /* Reload the timer counter. */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) |= CPUTIMER_TCR_TRB;
}

/** \brief Disables CPU timer interrupt.
 *
 * This function disables the CPU timer interrupt.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_TimerDisableInterrupt(void)
{
    /* Clear TIE bit of TCR register */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) &= ~CPUTIMER_TCR_TIE;
}

/** \brief Enables CPU timer interrupt.
 *
 * This function enables the CPU timer interrupt.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_TimerEnableInterrupt(void)
{
    /* Set TIE bit of TCR register */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) |= CPUTIMER_TCR_TIE;
}

/** \brief Sets CPU timer period.
 *
 * This function sets the CPU timer period count in the register PRD. When the 
 * timer register(TIM) decrements to zero, the TIM register is reloaded with the 
 * period value contained in the PRD registers, at the start of the next timer 
 * input clock cycle (the output of the prescaler).The PRD contents are also 
 * loaded into the TIM when you set the timer reload bit (TRB) in TCR.
 *
 * \param[in] PeriodCount is the CPU timer period count.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_TimerSetPeriod(uint32 PeriodCount)
{
    /* Load the period Count in the PRD register. */ 
    HWREG(CPUTIMER2_BASE + CPUTIMER_O_PRD) = PeriodCount;
}

/** \brief Clears CPU timer overflow flag.
 *
 * This function clears the CPU timer overflow flag.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_TimerClearOverflowFlag(void)
{
    /* Set TIF bit of TCR register */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) |= CPUTIMER_TCR_TIF;
}

/** \brief Set CPU timer divide down value.
 *
 * This function sets the TDDRH:TDDR value.
 *
 * \param[in] DivideDown is the count for 1 TICK
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
******************************************************************************/
static inline void OS_SetTimerDivideDown(uint16 DivideDown)
{
    /* Sets the CPU Timer divide down value */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TPRH) = DivideDown >> 8U;
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TPR) = (DivideDown & CPUTIMER_TPR_TDDR_M) ;
}

/** \brief Returns the current CPU timer counter value.
 *
 * This function returns the current CPU timer counter value.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return Returns the current CPU timer count value.
 * \retval uint32
 *
******************************************************************************/
static inline uint32 OS_GetTimerCount(void)
{
    /* Get the TIMH:TIM registers value */ 
    return(HWREG(CPUTIMER2_BASE + CPUTIMER_O_TIM));
}

/** \brief Returns CPU timer period register value.
 *
 * This function returns the CPU timer period register value.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return Returns CPU timer period register value.
 * \retval uint32
 *
******************************************************************************/
static inline uint32 OS_GetPeriodCount(void)
{
    /* Get the PRDH:PRD registers value */ 
    return (HWREG(CPUTIMER2_BASE + CPUTIMER_O_PRD));
}

#ifdef __cplusplus
}
#endif

#endif /* OS_H */
/*********************************************************************************************************************
 *  End of File: Os.h
 *********************************************************************************************************************/
