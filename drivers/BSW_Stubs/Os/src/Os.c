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

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Os.c
 *********************************************************************************************************************/
