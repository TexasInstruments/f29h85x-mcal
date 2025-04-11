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
 *  File:       Cdd_Ecap_Priv.c
 *  Generator:  None
 *
 *  Description: This file contains private function definitions that are defined in Cdd_Ecap_Priv.h file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "Cdd_Ecap_Priv.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_Timestamp_ISRProcess(Cdd_Ecap_ChannelType Channel);
#endif

/**
 * \brief   This function enables capture loading.
 *
 * \param   baseAddr   It is the Memory address of the ECAP instance used.
 */
void Cdd_Ecap_captureLoadingEnable(uint32 baseAddr);

/**
 * \brief This function will reset the value of capture register cap1
 *
 * \param baseAddr  It is the Memory address of the ECAP instance used.
*/
void Cdd_Ecap_cap1Reset(uint32 baseAddr);

/**
 * \brief This function will reset the value of capture register cap2
 *
 * \param baseAddr  It is the Memory address of the ECAP instance used.
*/
void Cdd_Ecap_cap2Reset(uint32 baseAddr);

/**
 * \brief This function will reset the value of capture register cap3
 *
 * \param baseAddr  It is the Memory address of the ECAP instance used.
*/
void Cdd_Ecap_cap3Reset(uint32 baseAddr);

/**
 * \brief This function will reset the value of capture register cap4
 *
 * \param baseAddr  It is the Memory address of the ECAP instance used.
*/
void Cdd_Ecap_cap4Reset(uint32 baseAddr);

/**
 * \brief   This function configures prescale value.
 *
 * \param   baseAddr  It is the Memory address of the ECAP instance used.
 * \param   prescale  It is the value which is used to prescale the incoming
 *                    input.
 *
 *          Prescale can take any integer value between 0 to 31
 */
void Cdd_Ecap_prescaleConfig(uint32 baseAddr, uint32 prescale);

/**
 * \brief   This function configures ecapture module to operate in capture
 *          mode or in APWM mode.
 *
 * \param   baseAddr    It is the Memory address of the ECAP instance used.
 * \param   modeSelect  It is the value which determines whether ecapture
 *                      module to operate in capture mode or in APWM mode.\n
 *
 */
void Cdd_Ecap_operatingModeSelect(uint32 baseAddr, uint32 modeSelect);

/**
 * \brief   This function returns time-stamp for a given capture event.
 *
 * \param   baseAddr    It is the Memory address of the ECAP instance used.
 * \param   capEvtFlag  It is the value which determines for which capture event
 *                      time-stamp has to returned.
 *
 *
 * \return  Returns the time-stamp for given capure event.
 */
uint32 Cdd_Ecap_timeStampRead(uint32 baseAddr, uint32 capEvtFlag);

/**
 * \brief   This function configures Capture Event polarity.
 *
 * \param   baseAddr    It is the Memory address of the ECAP instance used.
 * \param   capEvt1pol  It determines whether Capture Event1 has to be generated
 *                      on rising edge or falling edge of pulse.
 *
 * \param   capEvt2pol  It determines whether Capture Event2 has to be generated
 *                      on rising edge or falling edge of pulse.
 *
 * \param   capEvt3pol  It determines whether Capture Event3 has to be generated
 *                      on rising edge or falling edge of pulse.
 *
 * \param   capEvt4pol  It determines whether Capture Event4 has to be generated
 *                      on rising edge or falling edge of pulse.
 *
 */
void Cdd_Ecap_captureEvtPolarityConfig(uint32 baseAddr, uint32 capEvt1pol,
                               uint32 capEvt2pol, uint32 capEvt3pol,
                               uint32 capEvt4pol);

/**
 * \brief   This function enables reset of the counters upon Capture Events.
 *
 * \param   baseAddr     It is the Memory address of the ECAP instance used.
 * \param   counterRst1  It determines whether counter has to be reset upon
 *                       Capture Event1.
 *
 * \param   counterRst2  It determines whether counter has to be reset upon
 *                       Capture Event2.
 *
 * \param   counterRst3  It determines whether counter has to be reset upon
 *                       Capture Event3.
 *
 * \param   counterRst4  It determines whether counter has to be reset upon
 *                       Capture Event4.
 *
 */
void Cdd_Ecap_captureEvtCntrRstConfig(uint32 baseAddr, uint32 counterRst1,
                                 uint32 counterRst2, uint32 counterRst3,
                                 uint32 counterRst4);

/**
 * \brief   This function configures ECAP to Continuous mode.
 *
 * This API is valid only if ECAP is configured to Capture Mode.It has
 * no significance when ECAP is configured in APWM mode.
 *
 * \param   baseAddr   It is the Memory address of the ECAP instance used.
 */
void Cdd_Ecap_continousModeConfig(uint32 baseAddr, uint16 event);

/**
 * \brief   This function configures counter to stop or free running
 *          based on its input argument flag.
 *
 * \param   baseAddr  It is the Memory address of the ECAP instance used.
 * \param   flag      It is the value which determine counter to be configured
 *                    to stop or free running.\n
 *
 */
void Cdd_Ecap_counterControl(uint32 baseAddr, uint32 flag);

/**
 * \brief   This function clears global interrupt and enables the generation of
 *          interrupts if any of the event interrupt are enabled and
 *          corresponding event interrupt flag is set.
 *
 * \param   baseAddr  It is the Memory address of the ECAP instance used.
 */
void Cdd_Ecap_globalIntrClear(uint32 baseAddr);

/**
 * \brief   This function enables the specified interrupts
 *
 * \param   baseAddr  It is the Memory address of the ECAP instance used.
 * \param   flag      It is the value which specifies the interrupts to
 *                    be enabled.\n
 *
 */
void Cdd_Ecap_intrEnable(uint32 baseAddr, uint16 flag);

/**
 * \brief   This function returns the status specified interrupts
 *
 * \param   baseAddr  It is the Memory address of the ECAP instance used.
 * \param   flag      It is the value which specifies the status of interrupts
 *                    to be returned.\n
 *
 *
 * \returns Status of the specified interrupts.
 *
 */
uint32 Cdd_Ecap_getIntrStatus(uint32 baseAddr, uint32 flag);

/**
 \param baseAddr is the base address of the ECAP module.
 \param srcSelect is the emulation mode.

 * \brief This function configures the eCAP counter, TSCTR,  to the desired emulation
 * mode when emulation suspension occurs. Valid inputs for mode are:
 * - CDD_ECAP_EMULATION_STOP  - Counter is stopped immediately.
 * - CDD_ECAP_EMULATION_RUN_TO_ZERO - Counter runs till it reaches 0.
 * - CDD_ECAP_EMULATION_FREE_RUN - Counter is not affected.
 */
void Cdd_Ecap_setEmulationMode(uint32 baseAddr, Cdd_Ecap_EmulationMode srcSelect);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_ECAP_START_SEC_CODE
#include "Cdd_Ecap_MemMap.h"

void Cdd_Ecap_reArm(uint32 baseAddr)
{
    HWREGH(baseAddr + ECAP_O_ECCTL2) |= ECAP_ECCTL2_REARM;
}
void Cdd_Ecap_captureLoadingEnable(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_ECCTL1) |= ECAP_ECCTL1_CAPLDEN;
}

void Cdd_Ecap_captureLoadingDisable(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_ECCTL1) &= ~ECAP_ECCTL1_CAPLDEN;
}

void Cdd_Ecap_cap1Reset(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_CAP1) |= (uint32)(0U);
}

void Cdd_Ecap_cap2Reset(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_CAP2) |= (uint32)(0U);
}

void Cdd_Ecap_cap3Reset(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_CAP3) |= (uint32)(0U);
}

void Cdd_Ecap_cap4Reset(uint32 baseAddr)
{
    HWREG(baseAddr + ECAP_O_CAP4) |= (uint32)(0U);
}

void Cdd_Ecap_prescaleConfig(uint32 baseAddr, uint32 prescale)
{
    uint32 temp_addr;

    if (prescale < CDD_ECAP_MAX_PRESCALER_VALUE)
    {
        temp_addr = baseAddr + ECAP_O_ECCTL1;
        /* Write to PRESCALE bit */
        HWREGH(temp_addr) = ((HWREGH(temp_addr) & (~ECAP_ECCTL1_PRESCALE_M)) |
                             (prescale << ECAP_ECCTL1_PRESCALE_S));
    }
}

void Cdd_Ecap_operatingModeSelect(uint32 baseAddr, uint32 modeSelect)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCTL2;

    if (modeSelect == CDD_ECAP_CAPTURE_MODE)
    {
        /* Capture mode */
        HWREGH(temp_addr) &= ~ECAP_ECCTL2_CAP_APWM;
    }
    else if (modeSelect == CDD_ECAP_APWM_MODE)
    {
        /* APWM mode */
        HWREGH(temp_addr) |= ECAP_ECCTL2_CAP_APWM;
    }
    else
    {
        /* Nothing */
    }
}

uint32 Cdd_Ecap_timeStampRead(uint32 baseAddr, uint32 capEvtFlag)
{
    uint32 count = 0U;

    switch(capEvtFlag)
    {
        case CDD_ECAP_EVENT_1:
            /* Read CAP1 register */
            count = HWREG(baseAddr + ECAP_O_CAP1);
        break;

        case CDD_ECAP_EVENT_2:
            /* Read CAP2 register */
            count = HWREG(baseAddr + ECAP_O_CAP2);
        break;

        case CDD_ECAP_EVENT_3:
            /* Read CAP3 register */
            count = HWREG(baseAddr + ECAP_O_CAP3);
        break;

        case CDD_ECAP_EVENT_4:
            /* Read CAP4 register */
            count = HWREG(baseAddr + ECAP_O_CAP4);
        break;

        default:
            /* Invalid event parameter */
            count = 0U;
        break;
    }

    return(count);
}

void Cdd_Ecap_captureEvtPolarityConfig(uint32 baseAddr, uint32 capEvt1pol,
                                       uint32 capEvt2pol, uint32 capEvt3pol,
                                       uint32 capEvt4pol)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCTL1;
    uint32 shiftCap1 = (uint32)(CDD_ECAP_EVENT_1) << 1U;
    uint32 shiftCap2 = (uint32)(CDD_ECAP_EVENT_2) << 1U;
    uint32 shiftCap3 = (uint32)(CDD_ECAP_EVENT_3) << 1U;
    uint32 shiftCap4 = (uint32)(CDD_ECAP_EVENT_4) << 1U;

    uint32 mask = (~((uint32)1U << shiftCap1) & ~((uint32)1U << shiftCap2) &
                   ~((uint32)1U << shiftCap3) & ~((uint32)1U << shiftCap4));

    uint32 value = (((uint32)(capEvt1pol) << shiftCap1) | ((uint32)(capEvt2pol) << shiftCap2) |
                    ((uint32)(capEvt3pol) << shiftCap3) | ((uint32)(capEvt4pol) << shiftCap4));

    /* Write to CAP1POL, CAP2POL, CAP3POL and CAP4POL */
    HWREGH(temp_addr) = ((HWREGH(temp_addr) & mask) | value);
}

void Cdd_Ecap_captureEvtCntrRstConfig(uint32 baseAddr, uint32 counterRst1,
                                      uint32 counterRst2, uint32 counterRst3,
                                      uint32 counterRst4)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCTL1;
    uint32 shiftCap1 = (uint32)(2U*CDD_ECAP_EVENT_1 + 1U);
    uint32 shiftCap2 = (uint32)(2U*CDD_ECAP_EVENT_2 + 1U);
    uint32 shiftCap3 = (uint32)(2U*CDD_ECAP_EVENT_3 + 1U);
    uint32 shiftCap4 = (uint32)(2U*CDD_ECAP_EVENT_4 + 1U);

    uint32 mask = (~((uint32)1U << shiftCap1) & ~((uint32)1U << shiftCap2) &
                   ~((uint32)1U << shiftCap3) & ~((uint32)1U << shiftCap4));
    uint32 value = (((uint32)(counterRst1) << shiftCap1) | ((uint32)(counterRst2) << shiftCap2) |
                    ((uint32)(counterRst3) << shiftCap3) | ((uint32)(counterRst4) << shiftCap4));

    /* Write to CTRRST1, CTRRST2, CTRRST3 and CTRRST4 */
    HWREGH(temp_addr) = ((HWREGH(temp_addr) & mask) | value);
}

void Cdd_Ecap_continousModeConfig(uint32 baseAddr, uint16 event)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCTL2;

    /* Write to CONT/ONESHT */
    HWREGH(temp_addr) =
               ((HWREGH(temp_addr) & (~ECAP_ECCTL2_CONT_ONESHT)) |
                (uint16)CDD_ECAP_CONTINUOUS_CAPTURE_MODE);

    /* Write to STOP_WRAP */
    HWREGH(temp_addr) =
               ((HWREGH(temp_addr) & (~ECAP_ECCTL2_STOP_WRAP_M)) |
                (((uint16)event) << ECAP_ECCTL2_STOP_WRAP_S));
}

void Cdd_Ecap_counterControl(uint32 baseAddr, uint32 flag)
{
    if (flag == CDD_ECAP_COUNTER_STOP)
    {
        HWREGH(baseAddr + ECAP_O_ECCTL2) &= ~ECAP_ECCTL2_TSCTRSTOP;
    }
    else
    {
        HWREGH(baseAddr + ECAP_O_ECCTL2) |= ECAP_ECCTL2_TSCTRSTOP;
    }
}

void Cdd_Ecap_globalIntrClear(uint32 baseAddr)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCLR;

    /* Write to INT bit */
    HWREGH(temp_addr) = ECAP_ECCLR_INT;
}

void Cdd_Ecap_intrEnable(uint32 baseAddr, uint16 flag)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECEINT;
    HWREGH(temp_addr) |= flag;
}

void Cdd_Ecap_intrDisable(uint32 baseAddr, uint32 flag)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECEINT;
    HWREGH(temp_addr) &= ~flag;
}

uint32 Cdd_Ecap_getIntrStatus(uint32 baseAddr, uint32 flag)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECFLG;
    uint32 value = HWREGH(temp_addr);
    return (value & flag);
}

void Cdd_Ecap_intrStatusClear(uint32 baseAddr, uint16 flag)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCLR;

    /* Write to ECCLR register */
    HWREGH(temp_addr) |= flag;
}

void Cdd_Ecap_setEmulationMode(uint32 baseAddr, Cdd_Ecap_EmulationMode mode)
{
    uint32 temp_addr = baseAddr + ECAP_O_ECCTL1;

    /* Write to FREE/SOFT bit */
    HWREGH(temp_addr) =
            ((HWREGH(temp_addr) & (~ECAP_ECCTL1_FREE_SOFT_M)) |
             ((uint16)mode << ECAP_ECCTL1_FREE_SOFT_S));
}

void Cdd_Ecap_selectECAPInput(uint32 base, Cdd_Ecap_InputSelect input)
{
    uint32 temp_addr = base + ECAP_O_ECCTL0;

    /* Write to ECCTL0 */
    HWREGH(temp_addr) =
                ((HWREGH(temp_addr) & ~ECAP_ECCTL0_INPUTSEL_M) |
                 (uint16)input);
}

void Cdd_Ecap_clearGlobalInterrupt(uint32 baseAddr)
{
    /* Write to INT bit */
    HWREGH(baseAddr + ECAP_O_ECCLR) = ECAP_ECCLR_INT;
}

void Cdd_Ecap_ResetChObj(Cdd_Ecap_ChObjType *chObj)
{
#if (CDD_ECAP_TIMESTAMP_API == STD_ON)
    chObj->NextTimeStampIndexPtr    = (Cdd_Ecap_ValueType *) NULL_PTR;
    chObj->NextTimeStampIndex       = 0U;
    chObj->TimeStampBufferSize      = 0U;
    chObj->NotifyInterval           = 0U;
    chObj->NotificationCounter      = 0U;
    chObj->IsActive                 = FALSE;
#endif
#if (CDD_ECAP_SIGNAL_MEASUREMENT_API == STD_ON)
    chObj->cap1                 = 0U;
    chObj->cap2                 = 0U;
    chObj->cap3                 = 0U;
    chObj->cap4                 = 0U;
    chObj->HighTime             = 0U;
    chObj->LowTime              = 0U;
    chObj->Period               = 0U;
    chObj->DutyCycle.ActiveTime = (Cdd_Ecap_ValueType) 0U;
    chObj->DutyCycle.PeriodTime = (Cdd_Ecap_ValueType) 0U;
    chObj->PeriodAcquired       = FALSE;
    chObj->DutyAcquired         = FALSE;
#endif
    chObj->InputState   = (Cdd_Ecap_InputStateType) CDD_ECAP_IDLE;
#if (CDD_ECAP_EDGE_COUNT_API == STD_ON)
    chObj->EdgeCounter  = (Cdd_Ecap_EdgeNumberType) 0U;
#endif
    chObj->activation_edge                  = CDD_ECAP_BOTH_EDGES;
    chObj->IsRunning                        = FALSE;
    chObj->NotificationEnabled              = FALSE;
    chObj->baseAddr                         = 0U;
    chObj->prescaler                        = 0U;
    chObj->chCfg.defaultStartEdge           = CDD_ECAP_BOTH_EDGES;
    chObj->chCfg.inputSelect                = CDD_ECAP_INPUT_INPUTXBAR1;
    chObj->chCfg.intrcapSelect              = CDD_ECAP_INT_ALL;
    chObj->chCfg.measurementMode            = CDD_ECAP_MODE_SIGNAL_MEASUREMENT;
    chObj->chCfg.signalMeasurementProperty  = CDD_ECAP_PERIOD_TIME;
    chObj->chCfg.notificationHandler        = (Cdd_Ecap_NotifyFuncType) NULL_PTR;
    chObj->chCfg.bufferType                 = CDD_ECAP_LINEAR_BUFFER;
    chObj->chCfg.instanceClkMHz             = 0U;
    chObj->chCfg.prescaler                  = 0U;
    chObj->chCfg.channelId                  = 0U;

    return;
}

void Cdd_Ecap_CopyConfig(Cdd_Ecap_ChObjType *chObj, const Cdd_Ecap_ChannelConfigType *chCfg)
{
    /* Copying the Config stucture to Channel Object */
    chObj->chCfg.base_addr                  = chCfg->base_addr;
    chObj->chCfg.channelId                  = chCfg->channelId;
    chObj->chCfg.defaultStartEdge           = chCfg->defaultStartEdge;
    chObj->chCfg.inputSelect                = chCfg->inputSelect;
    chObj->chCfg.intrcapSelect              = chCfg->intrcapSelect;
    chObj->chCfg.measurementMode            = chCfg->measurementMode;
    chObj->chCfg.signalMeasurementProperty  = chCfg->signalMeasurementProperty;
    chObj->chCfg.notificationHandler        = chCfg->notificationHandler;
    chObj->chCfg.bufferType                 = chCfg->bufferType;
    chObj->chCfg.instanceClkMHz             = chCfg->instanceClkMHz;
    chObj->chCfg.prescaler                  = chCfg->prescaler;

    /* Copying the pre-compile config structure to Channel Object */
    chObj->activation_edge = chCfg->defaultStartEdge;
    chObj->prescaler = (Cdd_Ecap_ChannelPrescalerType)chCfg->prescaler;
    /* Store base address of all the configured channels */
    chObj->baseAddr = chCfg->base_addr;

    return;
}

void Cdd_Ecap_HwUnitInit(Cdd_Ecap_ChObjType *chObj)
{
    uint32 baseAddr;

    baseAddr = chObj->baseAddr;
    /* Disable and Clear Interrupts */
    Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
    Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);

    /* Disable CAP1-CAP4 register loads */
    Cdd_Ecap_captureLoadingDisable(baseAddr);

    /* Configure eCAP
     *    Enable capture mode.
     *    Continous, stop capture at event 4.
     *    Set polarity based on default start edge configuration.
     *    Set capture in time difference mode.
     *    Enable eCAP module.
     */
    Cdd_Ecap_counterControl(baseAddr, CDD_ECAP_COUNTER_STOP);
    Cdd_Ecap_operatingModeSelect(baseAddr, CDD_ECAP_CAPTURE_MODE);
    /* Configure initial parameters */
    Cdd_Ecap_continousModeConfig(baseAddr, CDD_ECAP_EVENT_4);
    Cdd_Ecap_prescaleConfig(baseAddr, chObj->prescaler);

    if (chObj->activation_edge == CDD_ECAP_RISING_EDGE)
    {
        Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_RISING_EDGE, (uint32)CDD_ECAP_RISING_EDGE,
        (uint32)CDD_ECAP_RISING_EDGE, (uint32)CDD_ECAP_RISING_EDGE);
    }
    else if (chObj->activation_edge == CDD_ECAP_FALLING_EDGE)
    {
        Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_FALLING_EDGE,
        (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_FALLING_EDGE);
    }
    else if (chObj->activation_edge == CDD_ECAP_BOTH_EDGES)
    {
        Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_RISING_EDGE,
        (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_RISING_EDGE);
    }
    else
    {
        /* MISRA-C */
    }

    Cdd_Ecap_captureEvtCntrRstConfig(baseAddr, 1, 1, 1, 1); /*Delta Mode*/
    Cdd_Ecap_selectECAPInput(baseAddr,chObj->chCfg.inputSelect);

    Cdd_Ecap_counterControl(baseAddr, CDD_ECAP_COUNTER_FREE_RUNNING);
    Cdd_Ecap_captureLoadingEnable(baseAddr);

    return;
}

void Cdd_Ecap_ConfigEcap(uint32 baseAddr,
                         Cdd_Ecap_ActivationType activation,
                         Cdd_Ecap_CounterRstType cntRst,
                         boolean interruptEnable,
                         Cdd_Ecap_IntrCapSelect capture,
                         uint32 Channel)
{
    Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
    Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
    Cdd_Ecap_clearGlobalInterrupt(baseAddr);

    /* Disable CAP1-CAP4 register loads */
    Cdd_Ecap_captureLoadingDisable(baseAddr);
    Cdd_Ecap_cap1Reset(baseAddr);
    Cdd_Ecap_cap2Reset(baseAddr);
    Cdd_Ecap_cap3Reset(baseAddr);
    Cdd_Ecap_cap4Reset(baseAddr);
    Cdd_Ecap_reArm(baseAddr);

    Cdd_Ecap_counterControl(baseAddr, CDD_ECAP_COUNTER_STOP);
    Cdd_Ecap_operatingModeSelect(baseAddr, CDD_ECAP_CAPTURE_MODE);
    if (Cdd_Ecap_ChObj[Channel].chCfg.measurementMode == CDD_ECAP_MODE_SIGNAL_MEASUREMENT)
    {
        Cdd_Ecap_continousModeConfig(baseAddr, CDD_ECAP_EVENT_4);
    }
    else
    {
        if (activation == CDD_ECAP_RISING_EDGE || activation == CDD_ECAP_FALLING_EDGE)
        {
            Cdd_Ecap_continousModeConfig(baseAddr, CDD_ECAP_EVENT_1);
        }
        else
        {
            Cdd_Ecap_continousModeConfig(baseAddr, CDD_ECAP_EVENT_2);
        }
    }

    if (activation == CDD_ECAP_RISING_EDGE)
    {
         Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_RISING_EDGE, (uint32)CDD_ECAP_RISING_EDGE,
         (uint32)CDD_ECAP_RISING_EDGE, (uint32)CDD_ECAP_RISING_EDGE);
    }
    else if (activation == CDD_ECAP_FALLING_EDGE)
    {
         Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_FALLING_EDGE,
         (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_FALLING_EDGE);
    }
    else if (activation == CDD_ECAP_BOTH_EDGES)
    {
         Cdd_Ecap_captureEvtPolarityConfig(baseAddr, (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_RISING_EDGE,
         (uint32)CDD_ECAP_FALLING_EDGE, (uint32)CDD_ECAP_RISING_EDGE);
    }
    else
    {
        /* MISRA-C */
    }

    if (cntRst == CDD_ECAP_ABSOLUTE_MODE)
    {
        Cdd_Ecap_captureEvtCntrRstConfig(baseAddr, 0, 0, 0, 0); /* using absolute mode */
    }
    else if (cntRst == CDD_ECAP_DELTA_MODE)
    {
        Cdd_Ecap_captureEvtCntrRstConfig(baseAddr, 1, 1, 1, 1); /* using delta mode */
    }
    else
    {
        /* MISRA-C */
    }

    Cdd_Ecap_setEmulationMode(baseAddr,CDD_ECAP_EMULATION_STOP);
    Cdd_Ecap_counterControl(baseAddr, CDD_ECAP_COUNTER_FREE_RUNNING);

    /* Enable CAP1-CAP4 register loads */
    Cdd_Ecap_captureLoadingEnable(baseAddr);
    if (interruptEnable != (uint32)0U)
    {
        uint16 cap = (uint16)capture;
       Cdd_Ecap_intrEnable(baseAddr, cap);
    }

    return;
}

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
void Cdd_Ecap_TimeStamp_Init(Cdd_Ecap_ChannelType Channel, Cdd_Ecap_ValueType* StartPtr,
                             uint16 Size, uint16 NotifyInterval)
{
    Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr = StartPtr;
    Cdd_Ecap_ChObj[Channel].TimeStampBufferSize = Size;
    Cdd_Ecap_ChObj[Channel].NextTimeStampIndex = 0U;
    Cdd_Ecap_ChObj[Channel].NotifyInterval = NotifyInterval;
    Cdd_Ecap_ChObj[Channel].NotificationCounter = 0U;
}

void Cdd_Ecap_TimeStamp_Clear(Cdd_Ecap_ChannelType Channel)
{
    Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr = (Cdd_Ecap_ValueType *)NULL_PTR;
    Cdd_Ecap_ChObj[Channel].TimeStampBufferSize = 0U;
    Cdd_Ecap_ChObj[Channel].NextTimeStampIndex = 0U;
    Cdd_Ecap_ChObj[Channel].NotifyInterval = 0U;
    Cdd_Ecap_ChObj[Channel].NotificationCounter = 0U;
}
#endif /*CDD_ECAP_TIMESTAMP_API*/

#if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
/*Reset Signal measurement runtime struct*/
void Cdd_Ecap_SignalMeasurement_Init(Cdd_Ecap_ChannelType Channel)
{
    Cdd_Ecap_ChObj[Channel].cap1 = 0U;
    Cdd_Ecap_ChObj[Channel].cap2 = 0U;
    Cdd_Ecap_ChObj[Channel].cap3 = 0U;
    Cdd_Ecap_ChObj[Channel].cap4 = 0U;
    Cdd_Ecap_ChObj[Channel].HighTime = 0U;
    Cdd_Ecap_ChObj[Channel].LowTime = 0U;
    Cdd_Ecap_ChObj[Channel].Period = 0U;
    Cdd_Ecap_ChObj[Channel].DutyCycle.PeriodTime = 0U;
    Cdd_Ecap_ChObj[Channel].DutyCycle.ActiveTime = 0U;
    Cdd_Ecap_ChObj[Channel].DutyAcquired = FALSE;
    Cdd_Ecap_ChObj[Channel].PeriodAcquired = FALSE;
}
#endif

#define CDD_ECAP_STOP_SEC_CODE
#include "Cdd_Ecap_MemMap.h"

#define CDD_ECAP_START_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_Timestamp_ISR(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;
    baseAddr = Cdd_Ecap_ChObj[Channel].baseAddr;

    /* BufferPtr null check */
    if (Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr != NULL)
    {
        Cdd_Ecap_Timestamp_ISRProcess(Channel);
    }

    /* Enable all global interrupts*/
    //Cdd_Ecap_globalIntrClear(baseAddr);

    Cdd_Ecap_ChObj[Channel].NextTimeStampIndex++;

    /* Handling for end of buffer */
    if ((Cdd_Ecap_ChObj[Channel].NextTimeStampIndex >= Cdd_Ecap_ChObj[Channel].TimeStampBufferSize) &&
        (Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr != NULL_PTR))
    {
       switch (Cdd_Ecap_ChObj[Channel].chCfg.bufferType)
        {
            case CDD_ECAP_LINEAR_BUFFER:
                /* Stop capturing values and disable interrupts */

                /* Stop capturing timestamps, but take the NextTimeStampIndex value */
                Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
                Cdd_Ecap_ChObj[Channel].IsRunning = FALSE;
                break;
            case CDD_ECAP_CIRCULAR_BUFFER:
                /* Next timestamp writes over the first item, and continuous capturing timestamps */
                Cdd_Ecap_ChObj[Channel].NextTimeStampIndex = 0U;
                break;
            default:
                break;
        }
    }

    return;
}
#endif

#if (STD_ON == CDD_ECAP_TIMESTAMP_API)
static FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_Timestamp_ISRProcess(Cdd_Ecap_ChannelType Channel)
{
    uint32 baseAddr;
    uint32 timestampRead;
    uint32 avoidNesting_Flag = E_NOT_OK;

    baseAddr = Cdd_Ecap_ChObj[Channel].baseAddr;
    /* Check which capregister called the interrupt */
    if (Cdd_Ecap_getIntrStatus(baseAddr,CDD_ECAP_CEVT1_INT) != 0U)
    {
        /* interrupt occurred at CAP1, get the current timestamp from CAP1 */
        timestampRead = Cdd_Ecap_timeStampRead(baseAddr, (uint32)CDD_ECAP_EVENT_1);
        Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr[Cdd_Ecap_ChObj[Channel].NextTimeStampIndex] =
                                                                                                 (uint16)timestampRead;
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT1_INT);
        avoidNesting_Flag = E_OK;
    }
    if ((Cdd_Ecap_getIntrStatus(baseAddr,CDD_ECAP_CEVT2_INT) != 0U) && (avoidNesting_Flag != (uint32)E_OK))
    {
        /* interrupt occurred at CAP2, get the current timestamp from CAP2 */
        timestampRead = Cdd_Ecap_timeStampRead(baseAddr, (uint32)CDD_ECAP_EVENT_2);
        Cdd_Ecap_ChObj[Channel].NextTimeStampIndexPtr[Cdd_Ecap_ChObj[Channel].NextTimeStampIndex] =
                                                                                                 (uint16)timestampRead;
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT2_INT);
        avoidNesting_Flag = E_OK;
    }
    else
    {
        /* no other values possible*/
    }
}
#endif

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
/*******************************************************************************
 *   Function Name : Cdd_Ecap_ChannelISR
 ******************************************************************************/
/*! \Description: Interrupt Subroutine for Notification
 *
 *  \context    Function is called from interrupt level
 ******************************************************************************/
FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_ChannelISR(Cdd_Ecap_ChannelType Channel)
{
    uint8 chNum = 0U;

    for(chNum = 0U; chNum < CDD_ECAP_HW_CNT; chNum++)
    {
        if (Cdd_Ecap_ChObj[chNum].chCfg.channelId == Channel)
        {
            break;
        }
    }

    if(chNum < CDD_ECAP_HW_CNT)
    {
    #if (STD_ON == CDD_ECAP_TIMESTAMP_API)
        if (Cdd_Ecap_ChObj[chNum].chCfg.measurementMode == CDD_ECAP_MODE_TIMESTAMP)
        {
            uint32 baseAddr;
            baseAddr = Cdd_Ecap_ChObj[chNum].baseAddr;

            Cdd_Ecap_Timestamp_ISR(chNum);

            Cdd_Ecap_ChObj[chNum].NotificationCounter++;
            if ((Cdd_Ecap_ChObj[chNum].NotificationEnabled == TRUE) &&
                (Cdd_Ecap_ChObj[chNum].NotificationCounter >= Cdd_Ecap_ChObj[chNum].NotifyInterval))
            {
                /* Call configured notification function if defined */
                if (Cdd_Ecap_ChObj[chNum].chCfg.notificationHandler != NULL_PTR)
                {
                    Cdd_Ecap_ChObj[chNum].chCfg.notificationHandler();
                    /* Disable all global interrupts*/
                    Cdd_Ecap_globalIntrClear(baseAddr);
                }
            }
        }
    #endif
    #if (STD_ON == CDD_ECAP_EDGE_COUNT_API)
        if (Cdd_Ecap_ChObj[chNum].chCfg.measurementMode == CDD_ECAP_MODE_EDGE_COUNTER)
        {
            uint32 baseAddr;
            baseAddr = Cdd_Ecap_ChObj[chNum].baseAddr;

            Cdd_Ecap_ChObj[chNum].EdgeCounter++;

            /* Clear interrupt */
            Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT1_CEVT2_INT);
            Cdd_Ecap_globalIntrClear(baseAddr);
        }
    #endif
    #if (STD_ON == CDD_ECAP_EDGE_DETECT_API)
        if (Cdd_Ecap_ChObj[chNum].chCfg.measurementMode == CDD_ECAP_MODE_SIGNAL_EDGE_DETECT)
        {
            uint32 baseAddr;
            baseAddr = Cdd_Ecap_ChObj[chNum].baseAddr;

            Cdd_Ecap_ChObj[chNum].InputState = CDD_ECAP_ACTIVE;

            /* Clear interrupt */
            Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT1_CEVT2_INT);
            Cdd_Ecap_globalIntrClear(baseAddr);

            if ((Cdd_Ecap_ChObj[chNum].NotificationEnabled == TRUE) &&
                (Cdd_Ecap_ChObj[chNum].chCfg.notificationHandler != NULL_PTR))
            {
                Cdd_Ecap_ChObj[chNum].chCfg.notificationHandler();
            }
        }
    #endif
    #if (STD_ON == CDD_ECAP_SIGNAL_MEASUREMENT_API)
        if (Cdd_Ecap_ChObj[chNum].chCfg.measurementMode == CDD_ECAP_MODE_SIGNAL_MEASUREMENT)
        {
            uint32 baseAddr;
            Cdd_Ecap_ValueType highTime, lowTime, period;

            baseAddr = Cdd_Ecap_ChObj[chNum].baseAddr;

            Cdd_Ecap_ChObj[chNum].InputState = CDD_ECAP_ACTIVE;

            Cdd_Ecap_ChObj[chNum].cap1 = Cdd_Ecap_timeStampRead(baseAddr, CDD_ECAP_EVENT_1);
            Cdd_Ecap_ChObj[chNum].cap2 = Cdd_Ecap_timeStampRead(baseAddr, CDD_ECAP_EVENT_2);
            Cdd_Ecap_ChObj[chNum].cap3 = Cdd_Ecap_timeStampRead(baseAddr, CDD_ECAP_EVENT_3);
            Cdd_Ecap_ChObj[chNum].cap4 = Cdd_Ecap_timeStampRead(baseAddr, CDD_ECAP_EVENT_4);

            if (Cdd_Ecap_getIntrStatus(baseAddr,CDD_ECAP_CEVT1_INT) != 0U)
            {
                if ((Cdd_Ecap_ChObj[chNum].cap1 == 0U) ||
                    (Cdd_Ecap_ChObj[chNum].cap4 == 0U))
                {
                    Cdd_Ecap_ChObj[chNum].DutyAcquired = FALSE;
                    Cdd_Ecap_ChObj[chNum].PeriodAcquired = FALSE;
                }
                else
                {
                    /* Increment is done to take care of the cycle delay due to counter reset */
                    Cdd_Ecap_ChObj[chNum].cap1++;
                    Cdd_Ecap_ChObj[chNum].cap4++;
                    highTime = (Cdd_Ecap_ValueType)(Cdd_Ecap_ChObj[chNum].cap1);
                    lowTime  = (Cdd_Ecap_ValueType)(Cdd_Ecap_ChObj[chNum].cap4);
                    period = highTime + lowTime;
                    Cdd_Ecap_ChObj[chNum].HighTime = highTime;
                    Cdd_Ecap_ChObj[chNum].LowTime = lowTime;
                    Cdd_Ecap_ChObj[chNum].Period = period;
                    Cdd_Ecap_ChObj[chNum].DutyCycle.PeriodTime = period;
                    Cdd_Ecap_ChObj[chNum].DutyCycle.ActiveTime = highTime;
                    Cdd_Ecap_ChObj[chNum].DutyAcquired = TRUE;
                    Cdd_Ecap_ChObj[chNum].PeriodAcquired = TRUE;
                }
                Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT1_INT);
            }
            else if (Cdd_Ecap_getIntrStatus(baseAddr,CDD_ECAP_CEVT3_INT) != 0U)
            {
                if ((Cdd_Ecap_ChObj[chNum].cap2 == 0U) ||
                    (Cdd_Ecap_ChObj[chNum].cap3 == 0U))
                {
                    Cdd_Ecap_ChObj[chNum].DutyAcquired = FALSE;
                    Cdd_Ecap_ChObj[chNum].PeriodAcquired = FALSE;
                }
                else
                {
                    /* Increment is done to take care of the cycle delay due to counter reset */
                    Cdd_Ecap_ChObj[chNum].cap2++;
                    Cdd_Ecap_ChObj[chNum].cap3++;
                    highTime = (Cdd_Ecap_ValueType)(Cdd_Ecap_ChObj[chNum].cap3);
                    lowTime  = (Cdd_Ecap_ValueType)(Cdd_Ecap_ChObj[chNum].cap2);
                    period = highTime + lowTime;
                    Cdd_Ecap_ChObj[chNum].HighTime = highTime;
                    Cdd_Ecap_ChObj[chNum].LowTime = lowTime;
                    Cdd_Ecap_ChObj[chNum].Period = period;
                    Cdd_Ecap_ChObj[chNum].DutyCycle.PeriodTime = period;
                    Cdd_Ecap_ChObj[chNum].DutyCycle.ActiveTime = highTime;
                    Cdd_Ecap_ChObj[chNum].DutyAcquired = TRUE;
                    Cdd_Ecap_ChObj[chNum].PeriodAcquired = TRUE;
                }
                Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_CEVT3_INT);
            }
            else
            {
                /* Do Nothing */
            }
            /* Disable all global interrupts */
            Cdd_Ecap_globalIntrClear(baseAddr);
        }
    #endif
    }
    else
    {
        /* Do Nothing */
    }
}

#define CDD_ECAP_STOP_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Priv.c
 *********************************************************************************************************************/
