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
 *  File:       Os.c
 *  Generator:  None
 *
 *  Description:  Os stub source file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_types.h"
#include "hw_pipe.h"
#include "hw_memmap.h"
#include "hw_cputimer.h"
#include "hw_ints.h"
#include "hw_sysctl.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/* AUTOSAR version information check has to match definition in header file */
#if ((OS_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
     (OS_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (OS_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "OS: AUTOSAR Version Numbers of OS are different"
#endif

/* Vendor specific version information is BCD coded */
#if ((OS_SW_MAJOR_VERSION != (1U)) || (OS_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Os.c and Os.h are inconsistent!"
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
 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

const Os_CfgType *Os_CfgPtr = &OS_INIT_CONFIG_PC;

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Initialize the PIPE control registers by setting them to a known state.
 *
 * This function initializes the PIPE control registers. After globally disabling interrupts and enabling the PIPE, it
 * clears all of the PIE interrupt enable bits and interrupt flags.
 *
 * \param[in] CfgPtr Os config structure
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,OS_CODE) OS_ISRInit(const Os_CfgType *CfgPtr);

#if(STD_ON == OS_COUNTER_ENABLE)
/** \brief Initialize the  OS counter.
 *
 * This function initializes the OS counter by configuring the CPU2 timer.
 *
 * \param[in] CounterCfg Counter config structure
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,OS_CODE) OS_CounterInit(const Os_CounterCfgType *CounterCfg);
#endif

/** \brief Initialize the PIPE control registers by setting them to a known state.
 *
 * This function initializes the PIPE control registers. After globally disabling interrupts and enabling the PIPE, it
 * clears all of the PIE interrupt enable bits and interrupt flags.
 *
 * \param[in] None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,OS_CODE) Interrupt_InitModule(void);

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
static inline void Interrupt_setINTSP(SSU_StackType Stack);

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
static inline void Interrupt_SetLinkOwner(uint32 IntNum, SSU_LinkType LinkOwner);

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
static inline void Interrupt_GlobalEnable(void);

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
static inline void Interrupt_DisableGlobal(void);

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
static inline void Interrupt_EnableInterrupt(uint8 IntNum);

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
static inline void Interrupt_SetIntPriority(uint8 IntNum, uint8 Priority);

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
static inline void Interrupt_SetGroupMask(uint8 GroupMask);

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
static inline void Interrupt_SetThreshold(uint8 Threshold);

#if(STD_ON == OS_COUNTER_ENABLE)
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
static inline void OS_TimerPrescaler(Os_PrescalerType Prescaler);

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
static inline void OS_StartTimer(void);

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
static inline void OS_ReloadTimer(void);

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
static inline void OS_TimerDisableInterrupt(void);

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
static inline void OS_TimerSetPeriod(uint32 PeriodCount);

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
static inline void OS_TimerClearOverflowFlag(void);

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
static inline void OS_SetTimerDivideDown(uint16 DivideDown);

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
static inline uint32 OS_GetTimerCount(void);

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
static inline uint32 OS_GetPeriodCount(void);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* CAT2 ISR common function implementation */
void Os_IsrCat2(Os_IntIdType InterruptId)
{
    uint8 i=0;
    for(i=0;i<OS_CFG_MAX_ISR;i++)
    {
        if((Os_CfgPtr->isr_cfg[i].int_id == InterruptId) && (Os_CfgPtr->isr_cfg[i].int_category == CATEGORY_2))
        {
            /* Call the ISR corresponding to the InterruptId. */
            (Os_CfgPtr->isr_cfg[i].isr_funcptr)();
            break;
        }
    }
}

FUNC(void,OS_CODE) Os_StartOS(void)
{
    /* Initialize the interrupt vector table and configure the interrupts */
    OS_ISRInit(Os_CfgPtr); 
    /* Timer2 Counter initialization */
#if(STD_ON == OS_COUNTER_ENABLE)
    OS_CounterInit(&(Os_CfgPtr->counter_cfg[0])); /* Initializing OS counter */
#endif

}

#if(STD_ON == OS_COUNTER_ENABLE)

FUNC(StatusType,OS_CODE) GetCounterValue(Os_CounterIdType CounterId, Os_TickRefType Value)
{
    *Value = OS_GetPeriodCount() - OS_GetTimerCount();
    return (StatusType)E_OK;
}

FUNC(StatusType,OS_CODE) GetElapsedValue(Os_CounterIdType CounterId,Os_TickRefType Value,Os_TickRefType ElapsedValue)
{
    Os_TickType cur_val ;
    cur_val =  OS_GetPeriodCount() - OS_GetTimerCount();
    if (cur_val < *Value)
    {
        /* Counter overflow occurred */
        cur_val       = OS_GetPeriodCount() + (cur_val - *Value) + 1U ;
        *ElapsedValue = cur_val;
    }
    else
    {
        /* No overflow */
        *ElapsedValue = (cur_val - *Value);
    }
    return (StatusType)E_OK;
}

#endif

/**********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if(STD_ON == OS_COUNTER_ENABLE)
static FUNC(void,OS_CODE) OS_CounterInit(const Os_CounterCfgType *CounterCfg)
{
    OS_TimerDisableInterrupt(); /* Interrupt is disabled */
    OS_TimerClearOverflowFlag(); /* Clear the overflow flag */
    OS_TimerPrescaler(OS_TIMER2CLK_DIV_1);
    /* Setting 1TICK = 1US (micro-second) with SYSCLK as the timer clock source */
    OS_SetTimerDivideDown(TIMERDIVIDEDOWN_PERTICK); 
    OS_TimerSetPeriod(CounterCfg->max_timercount); /* Set the counter value in period register */
    OS_ReloadTimer(); /* Reloads the timer which loads the values in TIM,TPR and TPRH registers.*/
    OS_StartTimer(); /* Start the timer */
}
#endif

static FUNC(void,OS_CODE) Interrupt_InitModule(void)
{
    /* Initialize the MMR registers */
    HWREG(PIPE_BASE + PIPE_O_MMR_CLR) = 0x3U;

    /* Initialize the memory and wait for completion */
    HWREG(PIPE_BASE + PIPE_O_MEM_INIT) = PIPE_MEM_INIT_KEY | 0x3U;
    while(HWREG(PIPE_BASE + PIPE_O_MEM_INIT_STS) != 0x2U);

    /*Set INTSP to STACK2 */
    Interrupt_setINTSP(SSU_STACK2);

    MCAL_LIB_EINT;
    /* Enables global interrupt. */
    Interrupt_GlobalEnable();

}

static FUNC(void,OS_CODE) OS_ISRInit(const Os_CfgType *CfgPtr)
{  
    if(CfgPtr != NULL_PTR)
    {
        uint8 i=0;
        
        /* Disable INT and RTINT by disabling global enable key.*/
        Interrupt_DisableGlobal();

        /* Initialize the PIPE control registers.*/
        Interrupt_InitModule();

        /* Configure RTINT threshold */
        Interrupt_SetThreshold(CfgPtr->threshold);

        /* Configure the group mask */
        Interrupt_SetGroupMask(DISABLE_GROUP_MASK); /* Disable interrupt nesting.*/

        /* Configure the interrupts */
        for(i=0;i< OS_CFG_MAX_ISR;i++)
        {
            /* Set all link owner of all interrupts to LINK2 */
            Interrupt_SetLinkOwner((CfgPtr->isr_cfg[i].int_id),SSU_LINK2);

            /* ISR to be called when an interrupt occurs. */
            HWREG(PIPE_BASE + PIPE_O_INT_VECT_ADDR(CfgPtr->isr_cfg[i].int_id)) = (uint32)(CfgPtr->isr_cfg[i].int_funcptr);

            /* Assign the priority level and enable the interrupt.*/         
            Interrupt_SetIntPriority(CfgPtr->isr_cfg[i].int_id,CfgPtr->isr_cfg[i].int_priority);
            Interrupt_EnableInterrupt(CfgPtr->isr_cfg[i].int_id);
        }
    }
}

static inline void
Interrupt_setINTSP(SSU_StackType Stack)
{
    HWREG(PIPE_BASE + PIPE_O_INTSP) = Stack;
}

static inline void
Interrupt_SetLinkOwner(uint32 IntNum, SSU_LinkType LinkOwner)
{
    uint32 base = PIPE_BASE + PIPE_O_INT_LINK_OWNER(IntNum);
    HWREG(base) = (HWREG(base) & 0xF0U) | (uint8)LinkOwner;
}

static inline void Interrupt_GlobalEnable(void)
{
    HWREG(PIPE_BASE + PIPE_O_GLOBAL_EN) = (0x3U | PIPE_GLOBAL_EN_KEY);
}

static inline void Interrupt_DisableGlobal(void)
{
    HWREG(PIPE_BASE + PIPE_O_GLOBAL_EN) = PIPE_GLOBAL_EN_KEY;
}

static inline void Interrupt_EnableInterrupt(uint8 IntNum)
{
    HWREG(PIPE_BASE + PIPE_O_INT_CTL_L(IntNum)) = PIPE_INT_CTL_L_EN;
}

static inline void Interrupt_SetIntPriority(uint8 IntNum, uint8 Priority)
{
    uint32 base = PIPE_BASE + PIPE_O_INT_CONFIG(IntNum);
    HWREG(base) = (HWREG(base) & ~PIPE_INT_CONFIG_PRI_LEVEL_M) | Priority;
}

static inline void Interrupt_SetGroupMask(uint8 GroupMask)
{
    HWREG(PIPE_BASE + PIPE_O_INT_GRP_MASK) = GroupMask;
}

static inline void Interrupt_SetThreshold(uint8 Threshold)
{
    HWREG(PIPE_BASE + PIPE_O_RTINT_THRESHOLD) = Threshold;
}

#if(STD_ON == OS_COUNTER_ENABLE)
static inline void OS_TimerPrescaler(Os_PrescalerType Prescaler)
{
    /* Clear TSS bit of register TCR */
    HWREG(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) = \
    (HWREG(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) & \
        ~(SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M)) | \
        ((uint8)Prescaler << SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S);
}

static inline void OS_StartTimer(void)
{
    /* Clear TSS bit of register TCR */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) &= ~CPUTIMER_TCR_TSS;
}

static inline void OS_ReloadTimer(void)
{
    /* Reload the timer counter. */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) |= CPUTIMER_TCR_TRB;
}

static inline void OS_TimerDisableInterrupt(void)
{
    /* Clear TIE bit of TCR register */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) &= ~CPUTIMER_TCR_TIE;
}

static inline void OS_TimerSetPeriod(uint32 PeriodCount)
{
    /* Load the period Count in the PRD register. */
    HWREG(CPUTIMER2_BASE + CPUTIMER_O_PRD) = PeriodCount;
}

static inline void OS_TimerClearOverflowFlag(void)
{
    /* Set TIF bit of TCR register */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TCR) |= CPUTIMER_TCR_TIF;
}

static inline void OS_SetTimerDivideDown(uint16 DivideDown)
{
    /* Sets the CPU Timer divide down value */
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TPRH) = DivideDown >> 8U;
    HWREGH(CPUTIMER2_BASE + CPUTIMER_O_TPR) = (DivideDown & CPUTIMER_TPR_TDDR_M) ;
}

static inline uint32 OS_GetTimerCount(void)
{
    /* Get the TIMH:TIM registers value */
    return(HWREG(CPUTIMER2_BASE + CPUTIMER_O_TIM));
}

static inline uint32 OS_GetPeriodCount(void)
{
    /* Get the PRDH:PRD registers value */
    return (HWREG(CPUTIMER2_BASE + CPUTIMER_O_PRD));
}
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Os.c
 *********************************************************************************************************************/
