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
 *  File:       Cdd_Adc_Priv.c
 *  Generator:  None
 *
 *  Description: This file contains private function definitions that are defined in Cdd_Adc_Priv.h
 *file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Priv.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define ADC_SOCXCTL_STEP (ADC_O_SOC1CTL - ADC_O_SOC0CTL)

#define ADC_REPXCTL_STEP    (ADC_O_REP2CTL - ADC_O_REP1CTL)
#define ADC_REPXN_STEP      (ADC_O_REP2N - ADC_O_REP1N)
#define ADC_REPXPHASE_STEP  (ADC_O_REP2PHASE - ADC_O_REP1PHASE)
#define ADC_REPXSPREAD_STEP (ADC_O_REP2SPREAD - ADC_O_REP1SPREAD)
#define ADC_INTSELXNY_STEP  (ADC_O_INTSEL3N4 - ADC_O_INTSEL1N2)

#define ADC_PPBXCONFIG_STEP  (ADC_O_PPB2CONFIG - ADC_O_PPB1CONFIG)
#define ADC_PPBXOFFCAL_STEP  (ADC_O_PPB2OFFCAL - ADC_O_PPB1OFFCAL)
#define ADC_PPBXOFFREF_STEP  (ADC_O_PPB2OFFREF - ADC_O_PPB1OFFREF)
#define ADC_PPBXTRIPHI_STEP  (ADC_O_PPB2TRIPHI - ADC_O_PPB1TRIPHI)
#define ADC_PPBXTRIPLO_STEP  (ADC_O_PPB2TRIPLO - ADC_O_PPB1TRIPLO)
#define ADC_PPBXTRIPLO2_STEP (ADC_O_PPB2TRIPLO2 - ADC_O_PPB1TRIPLO2)

#define ADC_PPBXSTAMP_STEP   (ADC_O_PPB2STAMP - ADC_O_PPB1STAMP)
#define ADC_PPBXLIMIT_STEP   (ADC_O_PPB2LIMIT - ADC_O_PPB1LIMIT)
#define ADC_PPBXCONFIG2_STEP (ADC_O_PPB2CONFIG2 - ADC_O_PPB1CONFIG2)
#define ADC_PPBXSUM_STEP     (ADC_O_PPB2SUM - ADC_O_PPB1SUM)
#define ADC_PPBXMAX_STEP     (ADC_O_PPB2MAX - ADC_O_PPB1MAX)
#define ADC_PPBXMAXI_STEP    (ADC_O_PPB2MAXI - ADC_O_PPB1MAXI)
#define ADC_PPBXMIN_STEP     (ADC_O_PPB2MIN - ADC_O_PPB1MIN)
#define ADC_PPBXMINI_STEP    (ADC_O_PPB2MINI - ADC_O_PPB1MINI)
#define ADC_PPBXRESULT_STEP  (ADC_O_PPB2RESULT - ADC_O_PPB1RESULT)
#define ADC_PPBXCOUNT_STEP   (ADC_O_PPB2COUNT - ADC_O_PPB1COUNT)

#define ADC_PPBXPSUM_STEP       (ADC_O_PPB2PSUM - ADC_O_PPB1PSUM)
#define ADC_PPBXPMAX_STEP       (ADC_O_PPB2PMAX - ADC_O_PPB1PMAX)
#define ADC_PPBXPMAXI_STEP      (ADC_O_PPB2PMAXI - ADC_O_PPB1PMAXI)
#define ADC_PPBXPMIN_STEP       (ADC_O_PPB2PMIN - ADC_O_PPB1PMIN)
#define ADC_PPBXPMINI_STEP      (ADC_O_PPB2PMINI - ADC_O_PPB1PMINI)
#define ADC_PPBXPCOUNT_STEP     (ADC_O_PPBP2PCOUNT - ADC_O_PPBP1PCOUNT)
#define ADC_PPBXTRIPFIL_STEP    (ADC_O_PPBTRIP2FILCTL - ADC_O_PPBTRIP1FILCTL)
#define ADC_PPBXTRIPFILCLK_STEP (ADC_O_PPBTRIP2FILCLKCTL - ADC_O_PPBTRIP1FILCLKCTL)
#define ADC_PPBEVTMASK          (ADC_EVTSEL_PPB1TRIPHI | ADC_EVTSEL_PPB1TRIPLO | ADC_EVTSEL_PPB1ZERO)

#define ADC_RESULT_STEP         (ADC_O_RESULT1 - ADC_O_RESULT0)
#define ADC_SAFECHECKRESEN_STEP (ADC_O_SAFECHECKRESEN2 - ADC_O_SAFECHECKRESEN)

#define ADC_CHECKERINTEVTBASE_STEP (ADCSAFETYCHECKINTEVT2_BASE - ADCSAFETYCHECKINTEVT1_BASE)

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
#define CDD_ADC_START_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"
P2VAR(Cdd_Adc_DriverObjType, AUTOMATIC, CDD_ADC_VAR_FAST_INIT) Cdd_Adc_DrvObjPtr = NULL_PTR;
#define CDD_ADC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"

#define CDD_ADC_START_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"
P2CONST(Cdd_Adc_ConfigType, AUTOMATIC, CDD_ADC_CONST) Cdd_Adc_ConfigPtr = NULL_PTR;
#define CDD_ADC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Select offset trim mode for the ADC hardware instance
 *
 * This function selects the offset trim mode for the ADC hardware instance
 *
 * \param[in]  Base   Base address of the ADC hardware instance
 * \param[in]  TrimMode   Tim mode for the ADC hardware instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelectOffsetTrimMode(uint32 Base, Cdd_Adc_OffsetTrimType TrimMode);

/** \brief Set ADC clock prescaler function
 *
 * This function sets the clock prescaler function for the ADC hardware unit
 *
 * \param[in]  Base   Base address of the ADC hardware instance
 * \param[in]  Prescale   Prescaler value for the ADC hardware instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPrescaler(uint32 Base, Cdd_Adc_PrescaleType Prescale);

/** \brief Set Interrupt pulse position function
 *
 * This function sets the interrupt pulse position for the ADC hardware unit
 *
 * \param[in]  Base   Base address of the ADC hardware unit
 * \param[in]  PulseMode   Interrupt pulse position selected for the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetIntPulseMode(uint32 Base, Cdd_Adc_EocPulseType PulseMode);

/** \brief Configure SOC(start-of-conversion) function
 *
 * This function configures the Sample window, Channel ID and Trigger for a SOC
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocNum   Numeric ID of the SOC
 * \param[in]  Trigger   The event for which that SOC is triggered
 * \param[in]  Channel   Channel ID configured for the SOC
 * \param[in]  SampleWindow   Sample window configured for the SOC
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetupSoc(uint32 Base, uint8 SocNum, Cdd_Adc_TriggerType Trigger, uint8 Channel, uint16 SampleWindow);

/** \brief Force Multiple SOC function
 *
 * This function triggers the software conversion for the SOCs configured in the SocMask where SOC
 *ID th bit is set in the SocMask
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocMask     SOC mask to trigger conversion for all the SOCs whose corresponding bit
 *is set in the mask
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceMultipleSoc(uint32 Base, uint32 SocMask);

/** \brief Set SOC priority function
 *
 * This function sets the SOC priority mode for the ADC hardware unit. The SOCs whose ID is below
 *this value will be considered as high priority and the rest will be considered in ROUND-ROBIN
 *mode.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PriorityMode     Priority mode for the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetSocPriority(uint32 Base, Cdd_Adc_SocPriorityType PriorityMode);

/** \brief Enable alternate DMA timing
 *
 * This function enables alternate DMA timing
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableAltDmaTiming(uint32 Base);

/** \brief Read SOC result function
 *
 * This reads the ADC conversion result for the specified SOC ID of an ADC hardware unit
 *
 * \param[in]  ResultBase     Result Base address of the ADC hardware unit
 * \param[in]  SocNumber     Numeric ID of the SOC
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadResult(uint32 ResultBase, uint8 SocNumber);

/** \brief Set interrupt as the SOC trigger function
 *
 * This function selects the specified interrupt as the SOC trigger in addition to the selected
 *trigger. This is applicable to only INT & INT2.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocNum     Numeric ID of the SOC
 * \param[in]  Trigger     oInterrupt trigger f the SOC
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetIntSocTrigger(uint32 Base, uint8 SocNum, Cdd_Adc_IntSocTriggerType Trigger);

/* ADC global registers */
#if (CDD_ADC_GLBSW_TRIG_API == STD_ON)
/** \brief Global software ADC select function
 *
 * This function enables the ADC hardware units for the global software trigger
 *
 * \param[in]  AdcMask   Mask to select the corresponding instances for the global software trigger
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_GlobalSwTrigger(uint8 AdcMask);

/** \brief Global software SOC select function
 *
 * This function enables triggers the software conversion for the specified SOC whose ADC hardware
 *unit is configured for the global software trigger
 *
 * \param[in]  SocMask   Mask to select the SOCs for the global software trigger. All the selected
 *SOCs in the selected hardware unit will be triggered for the ADC conversion.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SocGlobalSwTrigger(uint32 SocMask);
#endif

#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
/** \brief Select external channel for the SOC
 *
 * This function selects the external channel ID for the specified SOC of an ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocNum     Numeric ID of the SOC
 * \param[in]  ExtChannel     External channel ID to be selected for the SOC
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelSocExtChn(uint32 Base, uint8 SocNum, uint8 ExtChannel);

/** \brief Configure external mux preselect function
 *
 * This enables/disables the external mux preselect for the specified ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureExtMuxPreselect(uint32 Base);
#endif

#if (CDD_ADC_TRIG_REP_ENABLE == STD_ON)

/** \brief Set trigger repeater mode function
 *
 * This function sets the trigger repeater mode for an ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \param[in]  RepMode     Trigger repeater mode to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepMode(uint32 Base, Cdd_Adc_RepeaterType RepInstance, Cdd_Adc_RepeaterModeType RepMode);

/** \brief Select trigger for the trigger repeater function
 *
 * This function selects the trigger for the trigger repeater of an ADC hardware unit whose trigger
 *will be generated repeatedly for a configured count limit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \param[in]  Trigger     Trigger source which triggers the repeater to repeat the triggers
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SelTrigRepTrigger(uint32 Base, Cdd_Adc_RepeaterType RepInstance, Cdd_Adc_TriggerType Trigger);

/** \brief Trigger repeater sync function
 *
 * This function resets the trigger repeater flags except for the count, phase and spread delay
 *values.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceRepeaterTriggerSync(uint32 Base, Cdd_Adc_RepeaterType RepInstance);

/** \brief Set trigger repeater count function
 *
 * This function configures the trigger count for the repeater of an ADC hardware unit. The
 *configured count number of triggers will be generated once the trigger is received by the repeater
 *instance.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \param[in]  RepCount     Count value to be configured for the repeater
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepCount(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint8 RepCount);

/** \brief Set trigger repeater phase delay function
 *
 * This function configures the phase delay for the repeater of an ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \param[in]  RepPhase     Phase delay to be configured for the repeater
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepPhase(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint16 RepPhase);

/** \brief Set trigger repeater spread delay function
 *
 * This function configures the spread delay for the repeater of an ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \param[in]  RepSpread     Repeater spread to be configured for the repeater
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepSpread(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint16 RepSpread);

/** \brief Clear phase overflow function
 *
 * This function clears the phase overflow flow for the specified trigger repeater of an ADC HW unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearPhaseOvf(uint32 Base, Cdd_Adc_RepeaterType RepInstance);

/** \brief Clear trigger overflow function
 *
 * This function clears the trigger overflow flow for the specified trigger repeater of an ADC HW
 *unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearTriggerOvf(uint32 Base, Cdd_Adc_RepeaterType RepInstance);
#endif

/** \brief Enable/Disable interrupt function
 *
 * This function enables/disables the interrupt of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \param[in]  Mode     Enable/Disable to enable/disable the interrupt
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureInterrupt(uint32 Base, Cdd_Adc_IntNumType IntNum, boolean Mode);

/** \brief Enable/Disable continue to interrupt function
 *
 * This function enables/disables the continue to interrupt of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \param[in]  Mode     Enable/Disable to enable/disable the continue to interrupt mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureContinueToIntMode(uint32 Base, Cdd_Adc_IntNumType IntNum, boolean Mode);

/** \brief Set interrupt source function
 *
 * This function sets the interrupt source
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \param[in]  IntTrigger     Interrupt trigger type
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetIntSource(uint32 Base, Cdd_Adc_IntNumType IntNum, Cdd_Adc_IntTriggerType IntTrigger);

/** \brief Clear interrupt flag function
 *
 * This function clears the interrupt flag
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearInterruptFlag(uint32 Base, Cdd_Adc_IntNumType IntNum);

/** \brief Returns the interrupt overflow status
 *
 * This function returns the interrupt overflow status of the specified interrupt
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \pre None
 * \post None
 * \return Returns the interrupt overflow status
 * \retval boolean : TRUE - Interrupt overflow occurred
 *                   FALSE - Interrupt overflow not occurred
 *
 *********************************************************************************************************************/
static FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetIntOvfStatus(uint32 Base, Cdd_Adc_IntNumType IntNum);

/** \brief Clears the interrupt overflow status
 *
 * This function clears the interrupt overflow status of the specified interrupt
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  IntNum     Interrupt ID of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearIntOvfStatus(uint32 Base, Cdd_Adc_IntNumType IntNum);

/** \brief Set interrupt cycle offset function
 *
 * This functions sets the interrupt cycle offset for the ADC hardware unit. Used when the interrupt
 *pulse mode is configured as END_OF_ACQ_WIN. This allows the time to delay the interrupt after the
 *SOC acquisition.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  CycleOffset     Number of SYSCLK cycles to be waited before generating the interrupt
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetInterruptCycleOffset(uint32 Base, uint16 CycleOffset);

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

/** \brief Set Ppb calibration offset function
 *
 * This function sets the PPB calibration offset of the PPB of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  OffCal     Calibration offset configured for the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_PpbOffsetCorrection(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 OffCal);

/** \brief Set Ppb reference offset function
 *
 * This function sets the PPB reference offset of the PPB of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  Offset     Reference offset configured for the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPpbRefOffset(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 Offset);

/** \brief Set Ppb configuration function
 *
 * This function configures PPB of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  ResConfig     Configuration of the PPB (Like Delta enable, absolute enable & two's
 *complement)
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigurePpbResult(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 ResConfig);

/** \brief Set Ppb trip high limit function
 *
 * This function configures trip high limit of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  LimitHigh     Trip high limit of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigurePpbHighLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, sint32 LimitHigh);

/** \brief Enable Ppb extended low limit function
 *
 * This function enables the ppb extended low limit of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnablePpbExtendedLowLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Set Ppb extended trip low limit function
 *
 * This function configures extended trip low limit of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  TripLowLimit     Extended trip low limit of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetPpbExtendedLowLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, sint32 TripLowLimit);
/** \brief Enable/Disable Ppb trip filter function
 *
 * This function enable/disable Ppb trip filter of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  TripFilCfg     Trip filter configuration of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureTripFilter(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 TripFilCfg);

/** \brief Initialize Ppb trip filter function
 *
 * This function Initialize Ppb trip filter of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_TripFilterInit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Initialize Ppb trip filter prescale function
 *
 * This function initializes Ppb trip filter prescale of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  ClkPrescale     Trip filter clock prescale of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTripFilPrescale(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 ClkPrescale);

/** \brief Reads PPB event status function
 *
 * This function reads PPB event status of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetPpbEvtStatus(uint32 Base);

/** \brief Configure PPB event function
 *
 * This function configure PPB events of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  EvtFlags     Event flags of the PPB
 * \param[in]  Mode     Enable/disable Event flags for the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigPpbEvent(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 EvtFlags, boolean Mode);

/** \brief Configure PPB interrupt function
 *
 * This function configures PPB interrupt of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  IntFlags     Interrupt source flags of the PPB
 * \param[in]  Mode     Enable/disable interrupt source flags for the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigPpbEventInterrupt(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 IntFlags, boolean Mode);

/** \brief Configure PPB count limit function
 *
 * This function configures PPB count limit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  Limit     Count limit of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPpbCountLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 Limit);

/** \brief Configure PPB result comparisons
 *
 * This function configures PPB result comparison
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  PpbCfg2     PPB result comparison configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigPpb2(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 PpbCfg2);

/** \brief Force PPB sync function
 *
 * This function forces PPB sync for the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForcePpbSync(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Configure PPB function
 *
 * This function configures PPB
 *
 * \param[in]  PpbId     Numeric ID of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigPpbUnit(Cdd_Adc_PpbType PpbId);

#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

/** \brief Sets the safety checker input for the SOC
 *
 * This function sets the safety checker input for the SOC, this selects whether SOC result, PPB
 *result or PPBSUM result is passed to the safety checker
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocNum     Numeric ID of the SOC
 * \param[in]  ScInput     Safety checker input type for the SOC
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureSafetyCheckerInput(uint32 Base, uint8 SocNum, Cdd_Adc_CheckerInputType ScInput);

/** \brief Configures the safety checker result
 *
 * This function configures the safety checker result
 *
 * \param[in]  ScBase     Safety checker base address
 * \param[in]  CheckerResNum     ID for the result number to the checker
 * \param[in]  Instance     ADC hardware unit instance ID
 * \param[in]  ResultNum    SOC result numbers
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureSafetyChecker(uint32 ScBase, uint8 CheckerResNum, Cdd_Adc_HwUnitType Instance, uint8 ResultNum);

/** \brief Configures the safety checker tolerance
 *
 * This function configures the safety checker tolerance
 *
 * \param[in]  ScBase     Safety checker base address
 * \param[in]  Tolerance     Tolerance configured for the comparison
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetSafetyCheckerTolerance(uint32 ScBase, uint32 Tolerance);

/** \brief Returns the safety checker flag status
 *
 * This function returns the flag status of the safety checker unit
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \param[in]  CheckerNumber     Numeric ID of the safety checker
 * \param[in]  CheckerFlag     Safety checker flag type
 * \pre None
 * \post None
 * \return Returns the safety checker status for the specified flag for a safety checker unit
 * \retval boolean: TRUE - Event/interrupt flag set for the specified safety checker
 *                  FALSE -  Event/interrupt flag not set for the specified safety checker
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckStatus(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,
                                                                    Cdd_Adc_SafetyCheckFlagType CheckerFlag);

/** \brief Clears the safety checker flag status for the specified flag
 *
 * This function clears the safety checker flag status for the safety checker unit for the specified
 *flag
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \param[in]  CheckerNumber     Numeric ID of the safety checker
 * \param[in]  CheckerFlag     Safety checker flag type
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ClearCheckEvtFlag(uint32 Base, Cdd_Adc_CheckerType CheckerNumber, Cdd_Adc_SafetyCheckFlagType CheckerFlag);

/** \brief Clears the safety checker flags for multiple safety checker units for a specified flag
 *
 * This function clears the safety checker flag for multiple safety checker units for a specified
 *flag
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \param[in]  CheckerFlag     Safety checker flag type
 * \param[in]  EvtMask     Mask to be cleared
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ClearCheckEvtStatus(uint32 Base, Cdd_Adc_SafetyCheckFlagType CheckerFlag, uint16 EvtMask);

/** \brief Configures interrupt for a specified flag function for a safety checker interrupt event
 *instance
 *
 * This function configures safety checker interrupt source flags for the
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \param[in]  CheckerFlag     Safety checker flag type
 * \param[in]  IntFlagMask     interrupt flag sask to be configured
 * \param[in]  Mode         Enable/disable interrupt flag mask to be configured
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureCheckIntSrc(uint32 Base, Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag, uint16 IntFlagMask,
                                 boolean Mode);

/** \brief Clear safety checker interrupt status
 *
 * This function clears the safety checker interrupt
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearSafetyCheckIntStatus(uint32 Base);

/** \brief Configures a specified event for a specified interrupt event instance
 *
 * This function configures a specified event for a specified interrupt event instance
 *
 * \param[in]  Base     Safety checker interrupt event base address
 * \param[in]  CheckerFlag     Safety checker event flag type
 * \param[in]  CheckEvt     Event ID
 * \param[in]  EvtFlagMask    Event flag mask
 * \param[in]  Mode         Enable/disable event flags
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureCheckEvtSrc(uint32 Base, Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag, uint8 CheckEvt,
                                 uint16 EvtFlagMask, boolean Mode);
#endif

#if (STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
/** \brief Open/shorts detection mode function
 *
 * This function configures Open/shorts detection mode for an ADC hardware unit
 *
 * \param[in]  Base   Base address of the ADC hardware unit
 * \param[in]  Mode   Base address of the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigOSDetectMode(uint32 Base, Cdd_Adc_OsDetectModeType Mode);
#endif

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
/** \brief Enable/disable temperature sensor
 *
 * This function enable/disable temperature sensor
 *
 * \param[in]  Mode   Enable/Disable temperature sensor
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureTempSensor(boolean Mode);

/** \brief Returns lock temperature sensor function
 *
 * This function returns the temperature sensor lock status
 *
 * \pre None
 * \post None
 * \return Returns the temperature sensor lock status
 * \retval boolean - TRUE if the temperature sensor is locked
 *                  FALSE if the temperature sensor is not locked
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetTempSensorLockStatus(void);
#endif

#if (STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)
/** \brief Lock temperature sensor function
 *
 * This function locks temperature sensor
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_LockTempSensor(void);
#endif

/** \brief Enable/Disable ADC converter
 *
 * This function enables/disables the ADC converter
 *
 * \param[in]  Base     ADC hardware unit base address
 * \param[in]  Mode     Enable/Disable the converter
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureConverter(uint32 Base, boolean Mode);

/** \brief Update group function
 *
 * This function updates the group status
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_UpdateGroupStatus(Cdd_Adc_GroupType Group);

/** \brief Stop hardware trigger function
 *
 * This function stops the hardware trigger for the group to stop further conversion of the group
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopHwGrpTrigger(Cdd_Adc_GroupType Group);

/** \brief Set group function
 *
 * This function configures the group for conversion
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetGroup(Cdd_Adc_GroupType Group);

/** \brief Process group conversion after one complete conversion round
 *
 * This function manages the group conversion and status update after every complete conversion
 *round
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_ProcessGroup(Cdd_Adc_GroupType Group);

/** \brief Set group trigger function
 *
 * This function enables the group trigger to enable the group conversion
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetGrpTrigger(Cdd_Adc_GroupType Group);

/** \brief Set offset TRIM values for the ADC HW Unit function
 *
 * This function sets offset TRIM values for the ADC HW Unit
 *
 * \param[in]  Base     ADC hardware unit base address
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetOffsetTrim(uint32 Base);

/** \brief Set INL TRIM values for the ADC HW Unit function
 *
 * This function sets INL TRIM values for the ADC HW Unit
 *
 * \param[in]  HwUnitId     Numeric ID of the ADC instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetINLTrim(Cdd_Adc_HwUnitInstanceType HwUnitId);

/** \brief Set voltage reference for the ADC HW Unit function
 *
 * This function sets the voltage reference for the ADC HW Unit
 *
 * \param[in]  HwUnitId     Numeric ID of the ADC instance
 * \param[in]  RefMode     voltage reference mode
 * \param[in]  RefVoltage     reference voltage configured for the ADC HW Unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetVREF(Cdd_Adc_HwUnitInstanceType HwUnitId, Cdd_Adc_RefModeType RefMode, Cdd_Adc_RefVoltType RefVoltage);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_ADC_START_SEC_CODE
#include "Cdd_Adc_MemMap.h"

/* Design: MCAL-31355 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelectOffsetTrimMode(uint32 Base, Cdd_Adc_OffsetTrimType TrimMode)
{
    /* Select offset trim mode for the ADC hardware instance */
    HWREGH(Base + ADC_O_CTL2) = (HWREGH(Base + ADC_O_CTL2) & (uint16)(~ADC_CTL2_OFFTRIMMODE)) | (uint16)TrimMode;
}

/* Design: MCAL-31356 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPrescaler(uint32 Base, Cdd_Adc_PrescaleType Prescale)
{
    HWREGH(Base + ADC_O_CTL2) = (HWREGH(Base + ADC_O_CTL2) & (uint16)(~ADC_CTL2_PRESCALE_M)) | (uint16)Prescale;
}

/* Design: MCAL-31358,MCAL-31134 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetIntPulseMode(uint32 Base, Cdd_Adc_EocPulseType PulseMode)
{
    /* Set the position of the pulse */
    HWREGH(Base + ADC_O_CTL1) = (HWREGH(Base + ADC_O_CTL1) & (uint16)(~ADC_CTL1_INTPULSEPOS)) | ((uint16)PulseMode);
}

/* Design: MCAL-31357 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetupSoc(uint32 Base, uint8 SocNum, Cdd_Adc_TriggerType Trigger, uint8 Channel, uint16 SampleWindow)
{
    /* Calculate address for the SOC control register */
    uint32 ctrlreg_addr = Base + ADC_O_SOC0CTL + ((uint32)SocNum * ADC_SOCXCTL_STEP);

    /* Set the configuration of the specified SOC */
    HWREG(ctrlreg_addr) = (HWREG(ctrlreg_addr) & ~(ADC_SOC0CTL_CHSEL_M | ADC_SOC0CTL_ACQPS_M | ADC_SOC0CTL_TRIGSEL_M)) |
                          ((uint32)Channel << ADC_SOC0CTL_CHSEL_S) | ((uint32)Trigger << ADC_SOC0CTL_TRIGSEL_S) |
                          ((uint32)SampleWindow);
}

/* Design: MCAL-31359 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceMultipleSoc(uint32 Base, uint32 SocMask)
{
    /* Write to the register that will force a 1 to desired SOCs */
    HWREG(Base + ADC_O_SOCFRC1) |= SocMask;
}

/* Design: MCAL-31360 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetSocPriority(uint32 Base, Cdd_Adc_SocPriorityType PriorityMode)
{
    HWREGH(Base + ADC_O_SOCPRICTL) =
        (HWREGH(Base + ADC_O_SOCPRICTL) & (uint16)(~ADC_SOCPRICTL_SOCPRIORITY_M)) | ((uint16)PriorityMode);
}

LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableAltDmaTiming(uint32 Base)
{
    /* DMA is always triggered at tDMA regardless or whether the ADC is in early interrupt mode */
    HWREGH(Base + ADC_O_CTL1) |= (uint16)ADC_CTL1_TDMAEN;
}

/* Design: MCAL-31361 */
static FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadResult(uint32 ResultBase, uint8 SocNumber)
{
    /*  Return the ADC result for the selected SOC */
    return (uint16)(HWREGH(ResultBase + ADC_O_RESULT0 + ((uint32)SocNumber * ADC_RESULT_STEP)));
}

/* Design: MCAL-31362 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetIntSocTrigger(uint32 Base, uint8 SocNum, Cdd_Adc_IntSocTriggerType Trigger)
{
    /* Each SOC has a 2-bit field in this register */
    uint16 shift_val = (((uint16)SocNum % (uint16)16U) << (uint8)1U);
    /* Get the offset to the appropriate offset register */
    uint32 offset = Base + ADC_O_INTSOCSEL1 + ((uint32)4U * (((uint32)SocNum) / (uint32)16U));
    HWREG(offset) = (HWREG(offset) & ~((uint32)ADC_INTSOCSEL1_SOC0_M << shift_val)) | ((uint32)Trigger << shift_val);
}

/* ADC global registers */
#if (CDD_ADC_GLBSW_TRIG_API == STD_ON)

/* Design: MCAL-31363 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_GlobalSwTrigger(uint8 AdcMask)
{
    uint32 addr = Cdd_Adc_ConfigPtr->glbsw_baseaddr + ASYSCTL_O_ADCSOCFRCGBSEL;
    /* Configuring the register ADCSOCFRCGBSEL to select the ADC instances*/
    HWREG(addr) = (uint32)AdcMask;
}

/* Design: MCAL-31364 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SocGlobalSwTrigger(uint32 SocMask)
{
    uint32 addr = Cdd_Adc_ConfigPtr->glbsw_baseaddr + ASYSCTL_O_ADCSOCFRCGB;
    /* Configuring the SocMask to select the SOCs to be triggered simultaneously on differen ADCs */
    HWREG(addr) = SocMask;
}
#endif

#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)

/* Design: MCAL-31365 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelSocExtChn(uint32 Base, uint8 SocNum, uint8 ExtChannel)
{
    uint32 ctlreg_addr = Base + ADC_O_SOC0CTL + ((uint32)SocNum * (ADC_SOCXCTL_STEP));

    /* Set the external channel configuration of the specified SOC. */
    HWREG(ctlreg_addr) =
        (HWREG(ctlreg_addr) & ~((uint32)ADC_SOC0CTL_EXTCHSEL_M)) | ((uint32)ExtChannel << ADC_SOC0CTL_EXTCHSEL_S);
}

/* Design: MCAL-31366 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureExtMuxPreselect(uint32 Base)
{
    /* Enable the external mux selection at the beginning of S+H window of current conversion */

    HWREGH(Base + ADC_O_CTL1) |= (uint16)ADC_CTL1_EXTMUXPRESELECTEN;
}
#endif

#if (CDD_ADC_TRIG_REP_ENABLE == STD_ON)

/* Design: MCAL-31367,MCAL-31127 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepMode(uint32 Base, Cdd_Adc_RepeaterType RepInstance, Cdd_Adc_RepeaterModeType RepMode)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    /* Set the specified repeater trigger source to modify. */
    HWREG(regoffset) = (HWREG(regoffset) & ~ADC_REP1CTL_MODE) | (uint32)RepMode;
}

/* Design: MCAL-31368 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SelTrigRepTrigger(uint32 Base, Cdd_Adc_RepeaterType RepInstance, Cdd_Adc_TriggerType Trigger)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    /* Set the specified repeater trigger source to modify */
    HWREG(regoffset) =
        (HWREG(regoffset) & ~((uint32)ADC_REP1CTL_TRIGGER_M)) | ((uint32)Trigger << ADC_REP1CTL_TRIGGER_S);
}

/* Design: MCAL-31369 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceRepeaterTriggerSync(uint32 Base, Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    /* Force software sync for the trigger repeater block */
    HWREG(regoffset) |= (uint32)ADC_REP1CTL_SWSYNC;
}

/* Design: MCAL-31370 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepCount(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint8 RepCount)
{
    uint32 regoffset = Base + ((uint32)RepInstance * ADC_REPXN_STEP) + ADC_O_REP1N;
    /* Configure repeater count */
    HWREG(regoffset) = (HWREG(regoffset) & ~(ADC_REP1N_NSEL_M)) | (uint32)RepCount;
}

/* Design: MCAL-31371 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepPhase(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint16 RepPhase)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXPHASE_STEP)) + ADC_O_REP1PHASE;
    /* Configure repeater phase */
    HWREG(regoffset) = (HWREG(regoffset) & ~ADC_REP1PHASE_PHASE_M) | (uint32)RepPhase;
}

/* Design: MCAL-31372 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTrigRepSpread(uint32 Base, Cdd_Adc_RepeaterType RepInstance, uint16 RepSpread)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXSPREAD_STEP)) + ADC_O_REP1SPREAD;
    /* Configure repeater spread. */
    HWREG(regoffset) = (HWREG(regoffset) & ~(ADC_REP1SPREAD_SPREAD_M)) | (uint32)RepSpread;
}

/* Design: MCAL-31373 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearPhaseOvf(uint32 Base, Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;

    /* Clear repeater phase overflow flags */
    HWREG(regoffset) |= ((uint32)ADC_REP1CTL_PHASEOVF);
}

/* Design: MCAL-31374 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearTriggerOvf(uint32 Base, Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;

    /* Clear repeater phase overflow flags */
    HWREG(regoffset) |= ((uint32)ADC_REP1CTL_TRIGGEROVF);
}
#endif

/* Design: MCAL-31375 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureInterrupt(uint32 Base, Cdd_Adc_IntNumType IntNum, boolean Mode)
{
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + ((uint32)ADC_INTSELXNY_STEP * ((uint32)IntNum >> 1U));
    uint8  shiftval  = (((uint8)IntNum & (uint8)0x1U) << (uint8)3U);

    /* Enable/Disable the specified ADC interrupt. */
    if (TRUE == Mode)
    {
        HWREGH(base_addr) |= ((uint16)ADC_INTSEL1N2_INT1E << shiftval);
    }
    else
    {
        HWREGH(base_addr) &= ~(ADC_INTSEL1N2_INT1E << shiftval);
    }
}

/* Design: MCAL-31376 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureContinueToIntMode(uint32 Base, Cdd_Adc_IntNumType IntNum, boolean Mode)
{
    /* Each INTSEL register manages two interrupts. If the interrupt number is
     even, we'll be accessing the upper byte and will need to shift. */
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + ((uint32)ADC_INTSELXNY_STEP * ((uint32)IntNum >> 1U));
    uint8  shiftval  = (((uint8)IntNum & (uint8)0x1U) << (uint8)3U);

    /* Enable continuous mode for the specified ADC interrupt. */
    if (TRUE == Mode)
    {
        HWREGH(base_addr) |= ((uint16)ADC_INTSEL1N2_INT1CONT << shiftval);
    }
    else
    {
        HWREGH(base_addr) &= ~(ADC_INTSEL1N2_INT1CONT << shiftval);
    }
}

/* Design: MCAL-31377 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetIntSource(uint32 Base, Cdd_Adc_IntNumType IntNum, Cdd_Adc_IntTriggerType IntTrigger)
{
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + ((uint32)ADC_INTSELXNY_STEP * ((uint32)IntNum >> 1U));
    uint16 shiftval  = ((uint8)IntNum & (uint16)0x1U) << 3U;

    /* Set the specified ADC interrupt source. */
    HWREGH(base_addr) =
        (HWREGH(base_addr) & ~((uint16)ADC_INTSEL1N2_INT1SEL_M << shiftval)) | ((uint16)IntTrigger << shiftval);
}

/* Design: MCAL-31378 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearInterruptFlag(uint32 Base, Cdd_Adc_IntNumType IntNum)
{
    /* Clear the specified interrupt */
    HWREGH(Base + ADC_O_INTFLGCLR) |= ((uint16)1U << (uint8)IntNum);
}

/* Design: MCAL-31379 */
static FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetIntOvfStatus(uint32 Base, Cdd_Adc_IntNumType IntNum)
{
    /* Get the specified ADC interrupt status */
    return (boolean)((HWREGH(Base + ADC_O_INTOVF) >> (uint8)IntNum) & (uint8)ADC_INTOVF_ADCINT1);
}

/* Design: MCAL-31380 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearIntOvfStatus(uint32 Base, Cdd_Adc_IntNumType IntNum)
{
    /* Clear the specified interrupt overflow bit */
    HWREGH(Base + ADC_O_INTOVFCLR) |= ((uint16)1U << (uint8)IntNum);
}

/* Design: MCAL-31381 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetInterruptCycleOffset(uint32 Base, uint16 CycleOffset)
{
    /* Set the position of the pulse.Set the position of the pulse */
    HWREGH(Base + ADC_O_INTCYCLE) = CycleOffset;
}

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

/* Design: MCAL-31382 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_PpbOffsetCorrection(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 OffCal)
{
    /*Write the configuration to the register */
    HWREGH(Base + ((uint32)PpbNumber * ADC_PPBXOFFCAL_STEP) + ADC_O_PPB1OFFCAL) = OffCal;
}

/* Design: MCAL-31383 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPpbRefOffset(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 Offset)
{
    /* Write the offset amount */
    HWREGH(Base + ((uint32)PpbNumber * ADC_PPBXOFFREF_STEP) + ADC_O_PPB1OFFREF) = Offset;
}

/* Design: MCAL-31384 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigurePpbResult(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 ResConfig)
{
    /* Get the offset to the appropriate offset register */
    uint32 ppboffset = Base + ((uint32)PpbNumber * ADC_PPBXCONFIG_STEP) + ADC_O_PPB1CONFIG;
    /* Enable/Disable PPB's two's complement */
    HWREGH(ppboffset) =
        (HWREGH(ppboffset) & (uint16)(~(ADC_PPB1CONFIG_DELTAEN | ADC_PPB1CONFIG_TWOSCOMPEN | ADC_PPB1CONFIG_ABSEN |
                                        ADC_PPB1CONFIG_CBCEN | ADC_PPB1CONFIG_CONFIG_M))) |
        (ResConfig);
}

/* Design: MCAL-31385 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigurePpbHighLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, sint32 LimitHigh)
{
    /*Configure the register with the limit value provided*/
    HWREG(Base + ((uint32)PpbNumber * ADC_PPBXTRIPHI_STEP) + ADC_O_PPB1TRIPHI) =
        ((uint32)LimitHigh & ADC_PPB1TRIPHI_LIMITHI_M);
}

/* Design: MCAL-31386 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnablePpbExtendedLowLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /*Enable PPB extended trip low limit*/
    HWREG(Base + ((uint32)PpbNumber * ADC_PPBXTRIPLO_STEP) + ADC_O_PPB1TRIPLO) |= ADC_PPB1TRIPLO_LIMITLO2EN;
}

/* Design: MCAL-31387 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetPpbExtendedLowLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, sint32 TripLowLimit)
{
    /*Configure the register with the limit value provided*/
    HWREG(Base + ((uint32)PpbNumber * ADC_PPBXTRIPLO2_STEP) + ADC_O_PPB1TRIPLO2) =
        ((uint32)TripLowLimit & ADC_PPB1TRIPHI_LIMITHI_M);
}

/* Design: MCAL-31388 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureTripFilter(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 TripFilCfg)
{
    /* Configure digital trip filter */
    uint32 offset  = Base + ((uint32)PpbNumber * ADC_PPBXTRIPFIL_STEP) + ADC_O_PPBTRIP1FILCTL;
    HWREGH(offset) = (HWREGH(offset) & (uint16)(~(ADC_PPBTRIP1FILCTL_THRESH_M | ADC_PPBTRIP1FILCTL_SAMPWIN_M |
                                                  ADC_PPBTRIP1FILCTL_FILTLOEN | ADC_PPBTRIP1FILCTL_FILTHIEN))) |
                     TripFilCfg;
}

/* Design: MCAL-31389 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_TripFilterInit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Enable/disable digital trip filter */
    uint32 offset   = Base + ((uint32)PpbNumber * ADC_PPBXTRIPFIL_STEP) + ADC_O_PPBTRIP1FILCTL;
    HWREGH(offset) |= ((uint16)ADC_PPBTRIP1FILCTL_FILINIT);
}

/* Design: MCAL-31390 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetTripFilPrescale(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 ClkPrescale)
{
    /* Set trip filter sample clock prescale */
    HWREG(Base + ((uint32)PpbNumber * ADC_PPBXTRIPFILCLK_STEP) + ADC_O_PPBTRIP1FILCLKCTL) = ClkPrescale;
}

/* Design: MCAL-31391 */
static FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetPpbEvtStatus(uint32 Base)
{
    /* Get the event status for the specified post-processing block */
    return (HWREGH(Base + ADC_O_EVTSTAT));
}

/* Design: MCAL-31392 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigPpbEvent(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 EvtFlags, boolean Mode)
{
    /* Confiure the specified event */
    if (TRUE == Mode)
    {
        HWREGH(Base + ADC_O_EVTSEL) |= (((uint16)EvtFlags & (uint16)ADC_PPBEVTMASK) << ((uint16)PpbNumber * 4U));
    }
    else
    {
        HWREGH(Base + ADC_O_EVTSEL) &= ~(((uint16)EvtFlags & (uint16)ADC_PPBEVTMASK) << ((uint16)PpbNumber * 4U));
    }
}

/* Design: MCAL-31393 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigPpbEventInterrupt(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 IntFlags, boolean Mode)
{
    /* Enable the specified event interrupts */
    if (TRUE == Mode)
    {
        HWREGH(Base + ADC_O_EVTINTSEL) |= (((uint16)IntFlags & (uint16)ADC_PPBEVTMASK) << ((uint16)PpbNumber * 4U));
    }
    else
    {
        HWREGH(Base + ADC_O_EVTINTSEL) &= ~(((uint16)IntFlags & (uint16)ADC_PPBEVTMASK) << ((uint16)PpbNumber * 4U));
    }
}

/* Design: MCAL-31394 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetPpbCountLimit(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 Limit)
{
    /* Set ppb count limit */
    HWREGH(Base + ((uint32)PpbNumber * ADC_PPBXLIMIT_STEP) + ADC_O_PPB1LIMIT) = (Limit & ADC_PPB1LIMIT_LIMIT_M);
}

/* Design: MCAL-31395 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigPpb2(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint16 PpbCfg2)
{
    /* Get the offset to the appropriate delay */
    uint32 ppboffset = Base + ((uint32)PpbNumber * ADC_PPBXCONFIG2_STEP) + ADC_O_PPB1CONFIG2;

    /* Select sync input for the PPB */
    HWREGH(ppboffset) =
        (HWREGH(ppboffset) & (uint16)(~(ADC_PPB1CONFIG2_COMPSEL_M | ADC_PPB1CONFIG2_SHIFT_M))) | (PpbCfg2);
}

/* Design: MCAL-31396 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForcePpbSync(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Force software sync for the PPB */
    HWREGH(Base + ((uint32)PpbNumber * ADC_PPBXCONFIG2_STEP) + ADC_O_PPB1CONFIG2) |= ((uint16)ADC_PPB1CONFIG2_SWSYNC);
}
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

/* Design: MCAL-31399,MCAL-31137 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureSafetyCheckerInput(uint32 Base, uint8 SocNum, Cdd_Adc_CheckerInputType ScInput)
{
    /* Calculate the SOC shift. */
    uint16 socshift = (((uint16)SocNum % 16U) * (uint16)2U);
    uint32 offset   = Base + ADC_O_SAFECHECKRESEN + ((uint32)ADC_SAFECHECKRESEN_STEP * ((uint32)SocNum / 16U));
    /* Configure the Safety Checker Result mode */
    HWREG(offset) = (HWREG(offset) & ~(ADC_SAFECHECKRESEN_SOC0CHKEN_M << socshift)) | ((uint32)ScInput << socshift);
}

/* Design: MCAL-31400 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureSafetyChecker(uint32 ScBase, uint8 CheckerResNum, Cdd_Adc_HwUnitType Instance, uint8 ResultNum)
{
    uint32 offset = ScBase + ADC_O_RESSEL1 + ((uint32)(ADC_O_RESSEL2 - ADC_O_RESSEL1) * CheckerResNum);
    /* Configure safety checker instance */
    HWREGH(offset) = (HWREGH(offset) & (uint16)(~(ADC_RESSEL1_ADCSEL_M | ADC_RESSEL1_ADCRESULTSEL_M))) |
                     ((((uint16)Instance << (uint16)ADC_RESSEL1_ADCSEL_S) |
                       ((uint16)ResultNum << (uint16)ADC_RESSEL1_ADCRESULTSEL_S)));
}

/* Design: MCAL-31401 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetSafetyCheckerTolerance(uint32 ScBase, uint32 Tolerance)
{
    /* Set safety checker tolerance */
    HWREG(ScBase + ADC_O_TOLERANCE) = (Tolerance & ADC_TOLERANCE_TOLERANCE_M);
}

/* Design: MCAL-31402,MCAL-31141 */
LOCAL_INLINE FUNC(uint8, CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckStatus(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,
                                                                    Cdd_Adc_SafetyCheckFlagType CheckerFlag)
{
    /* Get the specified safety checker event status */
    return (uint8)((HWREG(Base + ADC_O_OOTFLG + (uint8)CheckerFlag) >> (uint16)CheckerNumber) & (uint16)1U);
}

/* Design: MCAL-31403 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ClearCheckEvtFlag(uint32 Base, Cdd_Adc_CheckerType CheckerNumber, Cdd_Adc_SafetyCheckFlagType CheckerFlag)
{
    /* Clear the specified safety checker event status */
    HWREG(Base + ADC_O_OOTFLGCLR + (uint8)CheckerFlag) |= ((uint32)1U << (uint8)CheckerNumber);
}

/* Design: MCAL-31405 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ClearCheckEvtStatus(uint32 Base, Cdd_Adc_SafetyCheckFlagType CheckerFlag, uint16 EvtMask)
{
    /* Clear the specified safety checker event status */
    HWREG((Base + ADC_O_OOTFLGCLR) + (uint8)CheckerFlag) |= ((uint32)EvtMask);
}

/* Design: MCAL-31406,MCAL-31142 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureCheckIntSrc(uint32 Base, Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag, uint16 IntFlagMask,
                                 boolean Mode)
{
    uint32 offset = Base + ADC_O_CHECKINTSEL1 + (uint8)CheckerFlag;

    /* Configure the interrupt flags */
    if (TRUE == Mode)
    {
        HWREG(offset) |= ((uint32)IntFlagMask & CHECKER_EVT_SEL_M);
    }
    else
    {
        HWREG(offset) &= ~((uint32)IntFlagMask & CHECKER_EVT_SEL_M);
    }
}

/* Design: MCAL-31404 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearSafetyCheckIntStatus(uint32 Base)
{
    /* Clear the specified safety checker interrupt status */
    HWREGH(Base + ADC_O_CHECKINTFLGCLR) = ((uint16)1U);
}

/* Design: MCAL-31407 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_ConfigureCheckEvtSrc(uint32 Base, Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag, uint8 CheckEvt,
                                 uint16 EvtFlagMask, boolean Mode)
{
    uint32 offset = Base + ((ADC_O_CHECKEVT2SEL1 - ADC_O_CHECKEVT1SEL1) * (uint32)CheckEvt) + ADC_O_CHECKEVT1SEL1 +
                    (uint8)CheckerFlag;

    /* Clear the specified safety checker event status */
    if (TRUE == Mode)
    {
        HWREG(offset) |= ((uint32)EvtFlagMask & CHECKER_EVT_SEL_M);
    }
    else
    {
        HWREG(offset) &= ~((uint32)EvtFlagMask & CHECKER_EVT_SEL_M);
    }
}
#endif

#if (STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)

/* Design: MCAL-31408,MCAL-31337 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigOSDetectMode(uint32 Base, Cdd_Adc_OsDetectModeType Mode)
{
    HWREGH(Base + ADC_O_OSDETECT) =
        (HWREGH(Base + ADC_O_OSDETECT) & (uint16)(~ADC_OSDETECT_DETECTCFG_M)) | ((uint16)Mode);
}
#endif

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)

/* Design: MCAL-31409,MCAL-31120 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureTempSensor(boolean Mode)
{
    /* Enable/Disable the temperature sensor */
    if (TRUE == Mode)
    {
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) |= (uint16)ASYSCTL_TSNSCTL_ENABLE;
    }
    else
    {
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) &= (uint16)(~ASYSCTL_TSNSCTL_ENABLE);
    }
}

/* Design: MCAL-31410 */
LOCAL_INLINE FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetTempSensorLockStatus(void)
{
    /* Enable/Disable the temperature sensor */
    return (boolean)(HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) & ASYSCTL_LOCK_TSNSCTL);
}
#endif

#if (STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)

/* Design: MCAL-31411,MCAL-31398 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_LockTempSensor(void)
{
    /* Lock temperature sensor */
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= (uint16)ASYSCTL_LOCK_TSNSCTL;
}
#endif

/* Design: MCAL-31412 */
LOCAL_INLINE FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureConverter(uint32 Base, boolean Mode)
{
    if (TRUE == Mode)
    {
        HWREGH(Base + ADC_O_CTL1) |= (uint16)ADC_CTL1_ADCPWDNZ;
    }
    else
    {
        HWREGH(Base + ADC_O_CTL1) &= (uint16)(~ADC_CTL1_ADCPWDNZ);
    }
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* Design: MCAL-31424 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetMode(Cdd_Adc_HwUnitInstanceType HwUnitId, Cdd_Adc_ResolutionType Resolution,
                Cdd_Adc_SignalModeType SignalMode)
{
    uint32 base               = Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].base_addr;
    HWREGH(base + ADC_O_CTL2) = (HWREGH(base + ADC_O_CTL2) & (uint16)(~(ADC_CTL2_RESOLUTION | ADC_CTL2_SIGNALMODE))) |
                                (((uint16)Resolution << 6U) | (uint16)SignalMode);
    /* Apply INL and offset trims */
    Cdd_Adc_SetINLTrim(HwUnitId);
    Cdd_Adc_SetOffsetTrim(base);
}

/* Design: MCAL-31339 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelectInternalTestNode(Cdd_Adc_InternalTestNodeType TestNode)
{
    uint32 offset = ANALOGSUBSYS_BASE + ASYSCTL_O_INTERNALTESTCTL;
    HWREG(offset) = (HWREG(offset) & ~ASYSCTL_INTERNALTESTCTL_TESTSEL_M) | (0xA5A5UL << ASYSCTL_INTERNALTESTCTL_KEY_S) |
                    ((uint32)TestNode << ASYSCTL_INTERNALTESTCTL_TESTSEL_S);
}

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/*
 * PPB related function
 */

/* Design: MCAL-31352 */
sint32 Cdd_Adc_ReadPpbResult(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1RESULT + ((uint32)PpbNumber * ADC_PPBXRESULT_STEP);
    /* Return the result of selected PPB */
    return (sint32)(HWREG(offset));
}

/* Design: MCAL-31353 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearPpbEvtStatus(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 TripEvtMask)
{
    /* Clear the specified event flags */
    HWREGH(Base + ADC_O_EVTCLR) |= ((uint16)TripEvtMask << ((uint16)PpbNumber * 4U));
}

/* Design: MCAL-31425 */
FUNC(Cdd_Adc_TriggerSrcType, CDD_ADC_CODE) Cdd_Adc_PrivGetTrigSrc(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId)
{
    Cdd_Adc_TriggerSrcType triggersrc_type = CDD_ADC_TRIGG_SRC_SW;
    /* Get the hardware unit index */
    uint8                  hwunitindex = Cdd_Adc_ConfigPtr->ppbcfg[PpbId].hwunitindex;

    /* Iterate through each group of the hardware unit and get the trigger source of the group the PPB is linked to */
    for (Cdd_Adc_GroupType group = Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startgroupnum;
         ((group <= Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].lastgroupnum)); group++)
    {
        /* If PPB is configured for the group */
        if ((((uint32)1U << Cdd_Adc_ConfigPtr->ppbcfg[PpbId].soc_num) & Cdd_Adc_ConfigPtr->groupcfg[group].soc_mask) !=
            0U)
        {
            /* Get the trigger source type of the group */
            triggersrc_type = Cdd_Adc_ConfigPtr->groupcfg[group].trigsrc_type;
            break;
        }
    }
    return triggersrc_type;
}

/* Design: MCAL-31354 */
uint16 Cdd_Adc_GetPpbDelayTimeStamp(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Get the offset to the appropriate delay */
    uint32 ppboffset = Base + (ADC_PPBXSTAMP_STEP * (uint32)PpbNumber) + ADC_O_PPB1STAMP;
    /* Return the delay time stamp */
    return (HWREGH(ppboffset) & ADC_PPB2STAMP_DLYSTAMP_M);
}

/* Partial PPB register read */

/* Design: MCAL-31343 */
uint16 Cdd_Adc_ReadPpbPCount(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = Base + ADC_O_PPBP1PCOUNT + ((uint32)PpbNumber * ADC_PPBXPCOUNT_STEP);
    /* Returns the partial count of the selected PPB */
    return (HWREGH(offset));
}

/* Design: MCAL-31342 */
sint32 Cdd_Adc_ReadPpbPSum(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = Base + ADC_O_PPB1PSUM + ((uint32)PpbNumber * ADC_PPBXPSUM_STEP);
    /* Return the result of selected PPB */
    return ((sint32)HWREG(offset));
}

/* Design: MCAL-31344 */
uint16 Cdd_Adc_ReadPpbPMaxIndex(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final maximum value of selected PPB */
    return (HWREGH(Base + ADC_O_PPB1PMAXI + ((uint32)PpbNumber * ADC_PPBXPMAXI_STEP)));
}

/* Design: MCAL-31345 */
uint16 Cdd_Adc_ReadPpbPMinIndex(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final minimum value of the selected PPB */
    return (HWREGH(Base + ADC_O_PPB1PMINI + ((uint32)PpbNumber * ADC_PPBXPMINI_STEP)));
}

/* Design: MCAL-31341 */
sint32 Cdd_Adc_ReadPpbPMax(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final maximum value of selected PPB */
    return ((sint32)HWREG(Base + ADC_O_PPB1PMAX + ((uint32)PpbNumber * ADC_PPBXPMAX_STEP)));
}

/* Design: MCAL-31340 */
sint32 Cdd_Adc_ReadPpbPMin(uint32 Base, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final minimum value of selected PPB */
    return ((sint32)HWREG(Base + ADC_O_PPB1PMIN + ((uint32)PpbNumber * ADC_PPBXPMIN_STEP)));
}

/* Design: MCAL-31348 */
sint32 Cdd_Adc_ReadPpbSum(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1SUM + ((uint32)PpbNumber * ADC_PPBXSUM_STEP);
    /* Return the result of selected PPB */
    return ((sint32)HWREG(offset));
}

/* Design: MCAL-31347 */
sint32 Cdd_Adc_ReadPpbMax(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final maximum value of selected PPB */
    return ((sint32)HWREG(ResultBase + ADC_O_PPB1MAX + ((uint32)PpbNumber * ADC_PPBXMAX_STEP)));
}

/* Design: MCAL-31346 */
sint32 Cdd_Adc_ReadPpbMin(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final minimum value of selected PPB */
    return ((sint32)HWREG(ResultBase + ADC_O_PPB1MIN + ((uint32)PpbNumber * ADC_PPBXMIN_STEP)));
}

/* PPB register read */
/* Design: MCAL-31349 */
uint16 Cdd_Adc_ReadPpbCount(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1COUNT + ((uint32)PpbNumber * ADC_PPBXCOUNT_STEP);
    /* Returns the partial count of the selected PPB */
    return (HWREGH(offset));
}

/* Design: MCAL-31350 */
uint16 Cdd_Adc_ReadPpbMaxIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final maximum value of selected PPB */
    return (HWREGH(ResultBase + ADC_O_PPB1MAXI + ((uint32)PpbNumber * ADC_PPBXMAXI_STEP)));
}

/* Design: MCAL-31351 */
uint16 Cdd_Adc_ReadPpbMinIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final minimum value of the selected PPB */
    return (HWREGH(ResultBase + ADC_O_PPB1MINI + ((uint32)PpbNumber * ADC_PPBXMINI_STEP)));
}
#endif

#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)

/* Design: MCAL-31331 */
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_UpdateResolution(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                         VAR(Cdd_Adc_ResolutionType, AUTOMATIC) Resolution)
{
    Cdd_Adc_GroupType group;
    Std_ReturnType    return_value = E_NOT_OK;
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Adc_ConfigPtr->hwunitcfg[HwUnit].resolution_update)
    {
        /* Report DET error if resolution requested is not supported by the specified ADC and
            internal 3.3V reference mode is not supported in 16-bit resolution mode */
        (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION,
                              CDD_ADC_E_WRONG_RESOLUTION_MODE);
    }
    else
#endif
    {
        if (Cdd_Adc_DrvObjPtr->hwunit_obj[HwUnit].cur_resolution == Resolution)
        {
            /* Report DET runtime error if the Adc was already configured with the requested resolution. */
            (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION,
                                         CDD_ADC_E_ALREADY_SET);
        }
        else
        {
            /* Report Det runtime error if any of the group is in IDLE state */
            for (group = Cdd_Adc_ConfigPtr->hwunitcfg[HwUnit].startgroupnum;
                 ((group <= Cdd_Adc_ConfigPtr->hwunitcfg[HwUnit].lastgroupnum)); group++)
            {
                /* Skip to the next group if the group is in IDLE state */
                if (Cdd_Adc_DrvObjPtr->group_obj[group].grp_status != CDD_ADC_IDLE)
                {
                    /* Check if the group is in IDLE state, else report det runtime error */
                    (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_SET_RESOLUTION,
                                                 CDD_ADC_E_BUSY);
                    break;
                }
            }

            /* When all the groups are IDLE, the group ID exceeds the last group number of the
             * hardware unit */

            /* If any of the groups is BUSY then return the function without any action */
            if (group > Cdd_Adc_ConfigPtr->hwunitcfg[HwUnit].lastgroupnum)
            {
                /* Set the resolution of the specified hardware unit. */
                Cdd_Adc_SetMode(HwUnit, Resolution, Cdd_Adc_ConfigPtr->hwunitcfg[HwUnit].signal_mode);
                Cdd_Adc_DrvObjPtr->hwunit_obj[HwUnit].cur_resolution = Resolution;
                return_value = E_OK; /* Return E_OK if the resolution configuration is successful */
            }
        }
    }
    return return_value;
}
#endif

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)

/* Design: MCAL-31328 */
FUNC(Std_ReturnType, CDD_ADC_CODE) Cdd_Adc_CheckGlbTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig)
{
    uint32               groupmask;
    Cdd_Adc_GlbSwCfgType glbsw      = Cdd_Adc_ConfigPtr->glbtrigcfg[GlbSwTrig];
    Cdd_Adc_GroupType    group_id   = 0U;
    Std_ReturnType       return_val = E_OK;

    for (groupmask = glbsw.group_mask; ((groupmask > 0U)); (groupmask = groupmask >> 1U))
    {
        if ((groupmask & 1U) != 0U)
        {
            if (((Cdd_Adc_DrvObjPtr->group_obj[group_id].grp_status != CDD_ADC_COMPLETED) &&
                 (Cdd_Adc_DrvObjPtr->glbsw_obj[GlbSwTrig].status == TRUE)) ||
                ((Cdd_Adc_DrvObjPtr->group_obj[group_id].grp_status != CDD_ADC_IDLE) &&
                 (Cdd_Adc_DrvObjPtr->glbsw_obj[GlbSwTrig].status == FALSE)))
            {
                /* Report runtime error if the group conversion is not done for the previous API
                    call or when the group is not in IDLE state and the API is called after
                    StopGlobalSwTrig API */
                (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GLBSW_TRIG,
                                             CDD_ADC_E_BUSY);
                return_val = E_NOT_OK;
                break;
            }
#if (STD_ON == CDD_ADC_DEV_ERROR_DETECT)
            else if ((Cdd_Adc_DrvObjPtr->group_obj[group_id].resbuffer == ((Cdd_Adc_ValueGroupType *)NULL_PTR)) &&
                     (FALSE == Cdd_Adc_ConfigPtr->groupcfg[group_id].dma_mode))
            {
                /* Report DET error if the result buffer is NULL for any one of the groups and
                 * this check is not when the API is called more than once without calling
                 * StopGlobalSwTrig API.
                 */
                (void)Det_ReportError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_START_GLBSW_TRIG,
                                      CDD_ADC_E_BUFFER_UNINIT);
                return_val = E_NOT_OK;
                break;
            }
#endif
            else
            {
                /* Move to the next group if all the checks are passed */
            }
        }
        group_id++;
    }
    return return_val;
}
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/* Design: MCAL-31312 */
/*
 * Safety-checker functions
 */

/* Design: MCAL-31333*/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureCheckerTile(uint32 ScBase, boolean Mode)
{
    /* Enable the Saftey Checker module */
    if (TRUE == Mode)
    {
        HWREGH(ScBase + ADC_O_CHECKCONFIG) |= (uint16)ADC_CHECKCONFIG_CHKEN;
    }
    else
    {
        HWREGH(ScBase + ADC_O_CHECKCONFIG) &= (uint16)(~ADC_CHECKCONFIG_CHKEN);
    }
}

/* Design: MCAL-31332 */
FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetCheckerStatus(uint32 ScBase)
{
    /* Return the Saftey Checker status */
    return (boolean)((HWREGH(ScBase + ADC_O_CHECKCONFIG) & ADC_CHECKCONFIG_CHKEN) >> 15U);
}

/* Design: MCAL-31334 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceSafetyCheckerSync(uint32 ScBase)
{
    /* Force software sync for the safety checker module */
    HWREGH(ScBase + ADC_O_CHECKCONFIG) |= (uint16)ADC_CHECKCONFIG_SWSYNC;
}

/* Design: MCAL-31336 */
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckIntStatus(uint32 Base)
{
    /* Get the specified safety checker interrupt status */
    return (HWREGH(Base + ADC_O_CHECKINTFLG));
}

/* Design: MCAL-31338 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearCheckerStatus(Cdd_Adc_CheckerIntEvtType IntEvtId, Cdd_Adc_CheckerEventType Event_Id)
{
    uint32 intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].base_addr;
    /* Clear Safety checker flags that generated the interrupt*/
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_OOT_FLG,
                                Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].ootflg);
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_RES1OVF_FLG,
                                Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].res1ovf);
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_RES2OVF_FLG,
                                Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].res2ovf);
}

/* Design: MCAL-31335 */
/* Stop the result checker unit */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopChecker(Cdd_Adc_CheckerType CheckerId)
{
    /* Disable the safety checker unit */
    Cdd_Adc_ConfigureCheckerTile(Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].base_addr, FALSE);
    /* Force Software sync to clear any result safety checker event flags that are set */
    Cdd_Adc_ForceSafetyCheckerSync(Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].base_addr);

    if (CDD_ADC_CHECKER_INTEVT_CNT != 0U)
    {
        uint8  checkernum = (Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].checker_id);
        uint32 intevt_baseaddr;

        /* Iterate through all the interrupt event blocks and then clear the corresponding safety
         * checker flags */
        for (Cdd_Adc_CheckerIntEvtType intevt_id = 0U; intevt_id < CDD_ADC_CHECKER_INTEVT_CNT; intevt_id++)
        {
            intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id].base_addr;
            /* Clear all the flags */
            Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_OOT_FLG, ((uint16)1U << checkernum));
            Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_RES1OVF_FLG, ((uint16)1U << checkernum));
            Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr, CDD_ADC_SAFETY_CHECK_RES2OVF_FLG, ((uint16)1U << checkernum));
        }
    }
}
#endif

/* Design: MCAL-31321,MCAL-31320 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetDrvObj(Cdd_Adc_DriverObjType *DrvObj, const Cdd_Adc_ConfigType *CfgPtr)
{
    /* Set the global driver object pointer */
    Cdd_Adc_DrvObjPtr = DrvObj;
    /* Initialize Ppb config array */
    Cdd_Adc_ConfigPtr = CfgPtr;
}

/* Design: MCAL-31322 */
/* Reset the driver object to the power on reset mode */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DrvObjInit(void)
{
    uint8                 hw_int, hw_index;
    Cdd_Adc_GroupObjType *group_obj;

    for (Cdd_Adc_GroupType grp_id = 0U; grp_id < CDD_ADC_GROUP_CNT; grp_id++)
    {
        group_obj                = &(Cdd_Adc_DrvObjPtr->group_obj[grp_id]);
        group_obj->grp_status    = CDD_ADC_IDLE;                       /* Set the group status to IDLE */
        group_obj->cur_resultptr = (Cdd_Adc_ValueGroupType *)NULL_PTR; /* Set the current result pointer to NULL */
        group_obj->resbuffer     = (Cdd_Adc_ValueGroupType *)NULL_PTR; /* Set the result buffer pointer to NULL */
        group_obj->implicit_stop = FALSE;                              /* Set the implicit stop to FALSE */
        group_obj->grp_active    = FALSE;                              /* Set the group active status to FALSE */

#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
        group_obj->grp_notification = FALSE;
#endif /* #if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API) */

        group_obj->triggersrc    = CDD_ADC_GRP_TRIGG_SRC_SW; /* Set the trigger source to SW */
        group_obj->valid_samples = 0U;                       /* Set the valid samples count to zero */

        /* Group ID for the i th interrupt of j th ADC hardware unit ID is - i + (j*4U).
         * This is used to retrieve the group ID when the ISR is executed(ProcessIsr function)
         */
        hw_index = Cdd_Adc_ConfigPtr->groupcfg[grp_id].hwunit_index;
        hw_int   = (((uint8)(Cdd_Adc_ConfigPtr->hwunitcfg[hw_index].hwunit_id)) * 4U) +
                 ((uint8)(Cdd_Adc_ConfigPtr->groupcfg[grp_id].grp_int));

        /* Assign the group ID that is linked to the interrupt. */
        Cdd_Adc_DrvObjPtr->interrupt_obj[hw_int] = grp_id;
    }

#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
    for (Cdd_Adc_HwUnitInstanceType hwunit_id = 0U; hwunit_id < CDD_ADC_HW_CNT; hwunit_id++)
    {
        /* Store the current resolution mode of the ADC instance */
        Cdd_Adc_DrvObjPtr->hwunit_obj[hwunit_id].cur_resolution = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id].resolution;
    }
#endif /* #if (STD_ON == CDD_ADC_SET_RESOLUTION_API) */

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
    for (Cdd_Adc_GlbTrigType glbswid = 0U; glbswid < CDD_ADC_GLBSW_TRIG_CNT; glbswid++)
    {
        Cdd_Adc_DrvObjPtr->glbsw_obj[glbswid].status = FALSE; /* Set the global software trigger status to FALSE */
    }
#endif /* #if (STD_ON == CDD_ADC_GLBSW_TRIG_API) */

#if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API) && (STD_ON == CDD_ADC_ENABLE_PPB_API)
    for (Cdd_Adc_PpbType ppbid = 0U; ppbid < CDD_ADC_PPB_CNT; ppbid++)
    {
        Cdd_Adc_DrvObjPtr->ppb_obj[ppbid] = FALSE; /* Set the notification of PPB to FALSE */
    }
#endif /* #if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API) && (STD_ON == CDD_ADC_ENABLE_PPB_API) */
}

/* Design: MCAL-31323 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_HwUnitInit(void)
{
    /* Initialize each HW instance */
    uint32                       base_addr;
    const Cdd_Adc_HwUnitCfgType *hwunitcfg;
    const Cdd_Adc_GroupCfgType  *group_cfg;

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
    const Cdd_Adc_CheckerResCfgType    *checkerunit_cfg;
    const Cdd_Adc_CheckerIntEvtCfgType *intevt_cfg;
    const Cdd_Adc_HwUnitCfgType        *hwunit_cfg;
#endif

#if (STD_ON == CDD_ADC_TRIG_REP_ENABLE)
    const Cdd_Adc_TrigRepCfgType *repunitcfg;
#endif

    Cdd_Adc_SelectInternalTestNode(Cdd_Adc_ConfigPtr->test_input);

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
    if (Cdd_Adc_GetTempSensorLockStatus() == 0U)
    {
        Cdd_Adc_ConfigureTempSensor(TRUE);
#if (STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)
        Cdd_Adc_LockTempSensor();
#endif /* #if (STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR) */
    }
#endif /* #if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE) */

    /* Iterate through each ADC HW Instances */
    for (Cdd_Adc_HwUnitInstanceType hwunit_id = 0U; hwunit_id < CDD_ADC_HW_CNT; hwunit_id++)
    {
        /* Assign base address,result address based on the ADC Instance Specified*/
        hwunitcfg = &(Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id]);

        /* Set the Prescaler for ADC HW unit. */
        Cdd_Adc_SetPrescaler(hwunitcfg->base_addr, hwunitcfg->prescale);
        /* Set the resolution and signal mode */
        Cdd_Adc_SetMode(hwunit_id, hwunitcfg->resolution, hwunitcfg->signal_mode);
        /* Set voltage reference mode and voltage reference*/
        Cdd_Adc_SetVREF(hwunit_id, hwunitcfg->voltrefmode, hwunitcfg->voltref);
        /* Enable ADC converter */
        Cdd_Adc_ConfigureConverter(hwunitcfg->base_addr, TRUE);
        /* Configure the interrput pulse mode */
        Cdd_Adc_SetIntPulseMode(hwunitcfg->base_addr, hwunitcfg->intpulsemode);
        /* Configure the interrupt offset */
        Cdd_Adc_SetInterruptCycleOffset(hwunitcfg->base_addr, hwunitcfg->intoffset);
#if (STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
        /* Set Opens/Shorts dectection circuit mode */
        Cdd_Adc_ConfigOSDetectMode(hwunitcfg->base_addr, hwunitcfg->osdetectmode);
#endif
        /* Set SOC Priority mode for each hardware unit*/
        Cdd_Adc_SetSocPriority(hwunitcfg->base_addr, hwunitcfg->socpriority);

        /* Always trigger DMA at tDMA regardless or whether the ADC is in early or late interrupt mode */
        Cdd_Adc_EnableAltDmaTiming(hwunitcfg->base_addr);

        /* Configure external mux preselect configuration */
#if (STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)
        if (hwunitcfg->extmuxpreselect != 0U)
        {
            /* Enable external mux preselect mode */
            Cdd_Adc_ConfigureExtMuxPreselect(hwunitcfg->base_addr);
        }
#endif
    }

    for (Cdd_Adc_GroupType group_id = 0U; group_id < CDD_ADC_GROUP_CNT; group_id++)
    {
        group_cfg = &(Cdd_Adc_ConfigPtr->groupcfg[group_id]);
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(group_cfg->hwunit_index)].base_addr;

        /* All modes except one shot software trigger and linear streaming needs to be stopped
         * explicitly */
        if (((group_cfg->trigsrc_type == CDD_ADC_TRIGG_SRC_SW) &&
             (CDD_ADC_CONV_MODE_ONESHOT == group_cfg->conversion_mode)) ||
            ((CDD_ADC_ACCESS_MODE_STREAMING == group_cfg->access_mode) &&
             (CDD_ADC_STREAM_BUFFER_LINEAR == group_cfg->streambuffermode)))
        {
            Cdd_Adc_DrvObjPtr->group_obj[group_id].implicit_stop = TRUE;
        }
        else
        {
            Cdd_Adc_DrvObjPtr->group_obj[group_id].implicit_stop = FALSE;
        }

        /* Assign the SOC number to the interrupt. */
        Cdd_Adc_SetIntSource(base_addr, group_cfg->grp_int, group_cfg->lastsocnum);

        for (uint8 channel_num = group_cfg->startchannelnum;
             ((channel_num < (group_cfg->channelcount + group_cfg->startchannelnum))); channel_num++)
        {
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            if (Cdd_Adc_ConfigPtr->hwunitcfg[group_cfg->hwunit_index].extchnsel != 0U)
            {
                /* Configure the external channel */
                Cdd_Adc_SelSocExtChn(base_addr, Cdd_Adc_ConfigPtr->channelcfg[channel_num].soc_num,
                                     Cdd_Adc_ConfigPtr->channelcfg[channel_num].extchannelnum);
            }
#endif
            /* Assign the soc number to the channel and configure the SOC.*/
            Cdd_Adc_SetupSoc(base_addr, Cdd_Adc_ConfigPtr->channelcfg[channel_num].soc_num, CDD_ADC_TRIGGER_SW_ONLY,
                             Cdd_Adc_ConfigPtr->channelcfg[channel_num].channel_id,
                             Cdd_Adc_ConfigPtr->channelcfg[channel_num].sample_window);
        }
    }

/* When safety checker API is ON then initialize the safety checker */
#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

    for (Cdd_Adc_CheckerType checkerid = 0U; checkerid < CDD_ADC_CHECKER_CNT; checkerid++)
    {
        checkerunit_cfg = &(Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checkerid]);
        for (uint8 res_num = 0U; res_num < 2U; res_num++)
        {
            hwunit_cfg = &(Cdd_Adc_ConfigPtr->hwunitcfg[(checkerunit_cfg->selresult[res_num].hwunit_index)]);
            /* Configure Safety checker input */
            Cdd_Adc_ConfigureSafetyCheckerInput(hwunit_cfg->base_addr, checkerunit_cfg->selresult[res_num].soc_num,
                                                checkerunit_cfg->selresult[res_num].res_type);
            /* Configure Safety checker */
            Cdd_Adc_ConfigureSafetyChecker(checkerunit_cfg->base_addr, res_num, hwunit_cfg->hwunit_id,
                                           checkerunit_cfg->selresult[res_num].res_num);
        }
        /* Set the tolerance of the result checker.*/
        Cdd_Adc_SetSafetyCheckerTolerance(checkerunit_cfg->base_addr, checkerunit_cfg->tolerance);
    }

    for (Cdd_Adc_CheckerIntEvtType intevt_id = 0U; intevt_id < CDD_ADC_CHECKER_INTEVT_CNT; intevt_id++)
    {
        intevt_cfg = &(Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id]);

        /* Enable interrupt event source flags */
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_RES1OVF,
                                     intevt_cfg->checkevtint.res1ovf, TRUE);
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_RES2OVF,
                                     intevt_cfg->checkevtint.res2ovf, TRUE);
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_OOT, intevt_cfg->checkevtint.ootflg,
                                     TRUE);

        for (uint8 evtid = 0U; evtid < CDD_ADC_CHECKER_EVT_CNT; evtid++)
        {
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_RES1OVF, evtid,
                                         intevt_cfg->checkevt[evtid].res1ovf, TRUE);
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_RES2OVF, evtid,
                                         intevt_cfg->checkevt[evtid].res2ovf, TRUE);
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg->base_addr, CDD_ADC_SAFETY_CHECK_OOT, evtid,
                                         intevt_cfg->checkevt[evtid].ootflg, TRUE);
        }
    }

#endif /* #if (STD_ON == CDD_ADC_SAFETY_CHECK_API) */

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    /* Configure the PPB units */
    for (Cdd_Adc_PpbType ppb_id = 0U; ppb_id < CDD_ADC_PPB_CNT; ppb_id++)
    {
        Cdd_Adc_ConfigPpbUnit(ppb_id);
    }
#endif /* #if (STD_ON == CDD_ADC_ENABLE_PPB_API) */

#if (STD_ON == CDD_ADC_TRIG_REP_ENABLE)
    for (uint8 trigrep_id = 0U; trigrep_id < CDD_ADC_TRIG_REP_CNT; trigrep_id++)
    {
        repunitcfg = &(Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id]);
        base_addr  = Cdd_Adc_ConfigPtr->hwunitcfg[(repunitcfg->hwunit_index)].base_addr;
        Cdd_Adc_ForceRepeaterTriggerSync(base_addr, repunitcfg->repeater_instance);
        Cdd_Adc_ClearTriggerOvf(base_addr, repunitcfg->repeater_instance);
        Cdd_Adc_ClearPhaseOvf(base_addr, repunitcfg->repeater_instance);
        Cdd_Adc_SelTrigRepTrigger(base_addr, repunitcfg->repeater_instance, repunitcfg->trigger_source);
        Cdd_Adc_SetTrigRepMode(base_addr, repunitcfg->repeater_instance, repunitcfg->repeater_mode);
        Cdd_Adc_SetTrigRepCount(base_addr, repunitcfg->repeater_instance, repunitcfg->repeater_count);
        Cdd_Adc_SetTrigRepPhase(base_addr, repunitcfg->repeater_instance, repunitcfg->repeater_phase);
        Cdd_Adc_SetTrigRepSpread(base_addr, repunitcfg->repeater_instance, repunitcfg->repeater_spread);
    }
#endif /* #if (STD_ON == CDD_ADC_TRIG_REP_ENABLE) */
}

#if (STD_ON == CDD_ADC_DEINIT_API)
/* Design: MCAL-31324 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_HwUnitDeinit(void)
{
    /* De-Init the HW instance */
    uint32 base_addr;

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
    uint32 checker_baseaddr, intevt_baseaddr;
#endif

    for (Cdd_Adc_HwUnitInstanceType hwunit_id = 0U; hwunit_id < CDD_ADC_HW_CNT; hwunit_id++)
    {
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id].base_addr;
        /* Disable all the ADC Hardware unit converters */
        Cdd_Adc_ConfigureConverter(base_addr, FALSE);

#if (STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
        /* Disable Opens/Shorts dectection circuit mode */
        Cdd_Adc_ConfigOSDetectMode(base_addr, CDD_ADC_OSDETECT_MODE_DISABLED);
#endif /* #if (STD_ON == CDD_ADC_GLBSW_TRIG_API) */
    }

    for (Cdd_Adc_GroupType group_id = 0U; group_id < CDD_ADC_GROUP_CNT; group_id++)
    {
        if (TRUE == Cdd_Adc_DrvObjPtr->group_obj[group_id].grp_active)
        {
            /* Stop the group conversion if the group conversion has not already been stopped before
             * calling DeInit API.
             */
            Cdd_Adc_StopGroup(group_id);
        }
    }

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
    /* Disable safety checker tiles */
    for (Cdd_Adc_CheckerType checker_id = 0U; checker_id < CDD_ADC_CHECKER_CNT; checker_id++)
    {
        checker_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checker_id].base_addr;
        /* If the safety checker has already stopped them it can be ignored */
        if (Cdd_Adc_GetCheckerStatus(checker_baseaddr) == TRUE)
        {
            Cdd_Adc_StopChecker(checker_id);
        }
    }

    /* Clear all safety checker interrupts */
    for (Cdd_Adc_CheckerIntEvtType intevt_id = 0U; intevt_id < CDD_ADC_CHECKER_INTEVT_CNT; intevt_id++)
    {
        intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id].base_addr;
        /* Clear safety checker interrupt flag */
        Cdd_Adc_ClearSafetyCheckIntStatus(intevt_baseaddr);
    }
#endif /* #if (STD_ON == CDD_ADC_SAFETY_CHECK_API) */

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
    /* Disable global software trigger */
    for (Cdd_Adc_GlbTrigType glbswid = 0U; glbswid < CDD_ADC_GLBSW_TRIG_CNT; glbswid++)
    {
        Cdd_Adc_StopGlbTrig(glbswid);
    }
#endif /* #if (STD_ON == CDD_ADC_GLBSW_TRIG_API) */

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
    /* Disable temperature sensor if not locked. */
    if (Cdd_Adc_GetTempSensorLockStatus() == 0U)
    {
        Cdd_Adc_ConfigureTempSensor(FALSE);
    }
#endif /* #if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE) */

    Cdd_Adc_SelectInternalTestNode(CDD_ADC_TEST_NODE_NO_CONN); /* Reset the internal test node */
}
#endif

/* Design: MCAL-31325 */
/* start the requested group conversion */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGroup(Cdd_Adc_GroupType Group)
{
    /* Configure group settings like enabling interrupts */
    Cdd_Adc_SetGroup(Group);

    /* Start Group trigger */
    Cdd_Adc_SetGrpTrigger(Group);
}

/* Design: MCAL-31325 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGroup(Cdd_Adc_GroupType Group)
{
    const Cdd_Adc_GroupCfgType *groupcfg    = &(Cdd_Adc_ConfigPtr->groupcfg[Group]);
    Cdd_Adc_GroupObjType       *group_obj   = &(Cdd_Adc_DrvObjPtr->group_obj[Group]);
    uint8                       hwunitindex = Cdd_Adc_ConfigPtr->groupcfg[Group].hwunit_index;
    uint32                      base_addr   = Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].base_addr;

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    Cdd_Adc_PpbType               ppb_num, lastppbnum;
    const Cdd_Adc_PpbUnitCfgType *ppbcfg;
#endif

    /* Disable the corresponding interrupt for software triggered groups */
    Cdd_Adc_ConfigureInterrupt(base_addr, groupcfg->grp_int, FALSE);
    Cdd_Adc_ConfigureContinueToIntMode(base_addr, groupcfg->grp_int, FALSE);

    /* Clear the interrupt flag and the result ready flag */
    Cdd_Adc_ClearInterruptFlag(base_addr, groupcfg->grp_int);

    /* Set the group status to Idle */
    group_obj->grp_status = CDD_ADC_IDLE;

    /* Set the group active status to FALSE */
    group_obj->grp_active = FALSE;

#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
    /* Disable group notification */
    group_obj->grp_notification = FALSE;
#endif

    /* Disable trigger sources and interrupt trigger source for hardware triggered groups whose conversion is
     * incomplete. */
    if ((groupcfg->trigsrc_type == CDD_ADC_TRIGG_SRC_HW) &&
        ((group_obj->grp_status != CDD_ADC_IDLE) &&
         ((group_obj->implicit_stop == FALSE) || (group_obj->grp_status != CDD_ADC_STREAM_COMPLETED))))
    {
        /* Disable trigger and interrupt trigger source for explicitly stopped hardware triggered groups
         * which are not IDLE and for implicitly stopped groups which are not in IDLE or STREAM_COMPLETED state
         */
        Cdd_Adc_StopHwGrpTrigger(Group);
    }

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    /* Get the last PPB ID */
    lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].ppbcount +
                                   Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum);

    /* Disable all PPB units which are linked to the group */
    for (ppb_num = Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum; ((ppb_num < lastppbnum)); ppb_num++)
    {
        /* If PPB is configured for the channel */
        if ((((uint32)1U << Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].soc_num) & groupcfg->soc_mask) != (uint32)0U)
        {
            /* If any PPB is configured for the channel */
            ppbcfg = &(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num]);
            /* Configure the interrupt and event flags */
            Cdd_Adc_ConfigPpbEventInterrupt(base_addr, ppbcfg->ppb_id, ppbcfg->tripevtintsel, FALSE);
            Cdd_Adc_ConfigPpbEvent(base_addr, ppbcfg->ppb_id, ppbcfg->tripevtsel, FALSE);

            /* Clear all the PPB event flags */
            Cdd_Adc_ClearPpbEvtStatus(base_addr, ppbcfg->ppb_id, (uint8)ADC_PPBEVTMASK);

            /* When there are incomplete result accumulation force software sync to the PPB to reset the
             * partial PPB count.
             */
            if (Cdd_Adc_ReadPpbPCount(base_addr, ppbcfg->ppb_id) != 0U)
            {
                /* Force PPB Sync to start PPB accumulation and get rid of unwanted accumulation from past group
                 * conversions */
                Cdd_Adc_ForcePpbSync(base_addr, ppbcfg->ppb_id);
            }

#if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            Cdd_Adc_DrvObjPtr->ppb_obj[ppb_num] = FALSE; /* Set the notification of PPB to FALSE */
#endif
        }
    }
#endif

    /* Update the trigger source type */
    group_obj->triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;
}

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)

/* Design: MCAL-31329 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig)
{
    Cdd_Adc_GlbSwCfgType glbsw = Cdd_Adc_ConfigPtr->glbtrigcfg[GlbSwTrig];
    uint32               groupmask;
    Cdd_Adc_GroupType    group = 0U;

    for (groupmask = glbsw.group_mask; ((groupmask > 0U)); (groupmask = groupmask >> 1U))
    {
        /* Check if the group is configured for the specified global software trigger */
        if ((groupmask & 1U) != 0U)
        {
            Cdd_Adc_DrvObjPtr->group_obj[group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_GLBSW;
            Cdd_Adc_SetGroup(group);
        }
        group++;
    }
    /* Set the global software trigger status to TRUE */
    Cdd_Adc_DrvObjPtr->glbsw_obj[GlbSwTrig].status = TRUE;

    /* Configure the ADC instances for global software trigger */
    Cdd_Adc_GlobalSwTrigger(glbsw.hwunit_mask);
    /* Configure SOCs for the global software trigger */
    Cdd_Adc_SocGlobalSwTrigger(glbsw.soc_mask);
}

/* Design: MCAL-31330 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig)
{
    Cdd_Adc_GlbSwCfgType glbsw = Cdd_Adc_ConfigPtr->glbtrigcfg[GlbSwTrig];
    uint32               groupmask;
    Cdd_Adc_GroupType    group = 0U;
    /* If any of the group SOC is pending then trigger is ignored so report an error that ADC is
     * busy. */
    for (groupmask = glbsw.group_mask; ((groupmask > 0U)); (groupmask = groupmask >> 1U))
    {
        if ((groupmask & 1U) != 0U)
        {
            Cdd_Adc_DrvObjPtr->group_obj[group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;
            Cdd_Adc_StopGroup(group);
        }
        group++;
    }

    Cdd_Adc_DrvObjPtr->glbsw_obj[GlbSwTrig].status = FALSE;
    /* Configure SOCs for the global software trigger */
    Cdd_Adc_SocGlobalSwTrigger(0U);
    /* Configure the ADC instances for global software trigger */
    Cdd_Adc_GlobalSwTrigger(0U);
}
#endif

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

/* Design: MCAL-31418 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_PpbEvtIsr(Cdd_Adc_HwUnitType HwUnitId)
{
    Cdd_Adc_PpbType               ppb_num;
    Cdd_Adc_PpbType               lastppbnum;
    const Cdd_Adc_PpbUnitCfgType *ppbcfg;
    uint8                         hwunit_index;
    uint16                        evtintstat;
    uint32                        base_addr;

    for (hwunit_index = 0U; hwunit_index < CDD_ADC_HW_CNT; hwunit_index++)
    {
        if (Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].hwunit_id == HwUnitId)
        {
            break;
        }
    }

    if (hwunit_index != CDD_ADC_HW_CNT)
    {
        base_addr  = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].base_addr;
        evtintstat = Cdd_Adc_GetPpbEvtStatus(base_addr);
        /* Last PPB number */
        lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].ppbcount +
                                       Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].startppbnum);
        for (ppb_num = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].startppbnum; ((ppb_num < lastppbnum)); ppb_num++)
        {
            if (((evtintstat >> (((uint8)Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id) * 4U)) &
                 Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtintsel) != 0U)
            {
                ppbcfg = &(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num]);

                /* Clear the flags that triggered the interrupt */
                Cdd_Adc_ClearPpbEvtStatus(base_addr, ppbcfg->ppb_id, ppbcfg->tripevtintsel);
#if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
                /* Call notification function if exists*/
                if ((ppbcfg->ppbevtint_notification != ((Cdd_Adc_PpbNotifyType)NULL_PTR)) &&
                    (TRUE == Cdd_Adc_DrvObjPtr->ppb_obj[ppb_num]))
                {
                    /* Design: MCAL-31138 */
                    ppbcfg->ppbevtint_notification();
                }
#endif
            }
        }
    }
}
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/* Design: MCAL-31419 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_CheckerIsr(Cdd_Adc_CheckerIntEvtType IntEvtId, Cdd_Adc_CheckFlagStatusType *FlagStatus)
{
    Cdd_Adc_CheckerType       checker_id, checker_number;
    uint32                    base_addr     = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].base_addr;
    const Cdd_Adc_IntSrcType *checkerevtint = &(Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevtint);

    for (checker_number = 0U; checker_number < CDD_ADC_CHECKER_CNT; checker_number++)
    {
        checker_id = Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checker_number].checker_id;
        /* Check if the interrupt source is configured for the specified safety checker */
        if ((Cdd_Adc_GetSafetyCheckStatus(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_OOT_FLG) &
             (uint8)((checkerevtint->ootflg >> checker_id) & 1U)) != 0U)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_OOT_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_OOT_FLG);
        }
        else if ((Cdd_Adc_GetSafetyCheckStatus(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_RES1OVF_FLG) &
                  (uint8)((checkerevtint->res1ovf >> checker_id) & 1U)) != 0U)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_RES1OVF_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_RES1OVF_FLG);
        }
        else if ((Cdd_Adc_GetSafetyCheckStatus(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_RES2OVF_FLG) &
                  (uint8)((checkerevtint->res2ovf >> checker_id) & 1U)) != 0U)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_RES2OVF_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr, checker_id, CDD_ADC_SAFETY_CHECK_RES2OVF_FLG);
        }
        else
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_FLG_NONE;
        }
    }
    /* Clear safety checker interrupt flag */
    Cdd_Adc_ClearSafetyCheckIntStatus(base_addr);
}
#endif

FUNC(void, CDD_ADC_CODE) Cdd_Adc_PrivUpdateStatusThroughDma(Cdd_Adc_IntNumType IntNum, Cdd_Adc_HwUnitType HwUnitId)
{
    Cdd_Adc_GroupType group_id, hwint;

    /* Get the interrupt_obj index which stores the group ID */
    hwint = ((Cdd_Adc_GroupType)IntNum) + (((Cdd_Adc_GroupType)HwUnitId) * 4U);

    /* Get the group ID */
    group_id = Cdd_Adc_DrvObjPtr->interrupt_obj[hwint];

    /* Check if group ID is in range */
    // if (CDD_ADC_GROUP_CNT > group_id)
    // {
    if (FALSE == Cdd_Adc_ConfigPtr->groupcfg[group_id].dma_mode)
    {
        /* Report Det runtime error if the group is not configured for DMA mode */
        (void)Det_ReportRuntimeError(CDD_ADC_MODULE_ID, CDD_ADC_INSTANCE_ID, CDD_ADC_SID_UPDATE_STATUS_THROUGH_DMA,
                                     CDD_ADC_E_WRONG_PROCESSING_MODE);
    }
    else
    {
        /* Process the group if the group ID exists */
        Cdd_Adc_ProcessGroup(group_id);
    }
    // }
}

/* Design: MCAL-31416 */
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ProcessIsr(Cdd_Adc_IntNumType IntNum, Cdd_Adc_HwUnitType HwUnitId)
{
    Cdd_Adc_GroupType group_id, hwint;

    /* Get the interrupt_obj index which stores the group ID */
    hwint = ((Cdd_Adc_GroupType)IntNum) + (((Cdd_Adc_GroupType)HwUnitId) * 4U);

    /* Get the group ID */
    group_id = Cdd_Adc_DrvObjPtr->interrupt_obj[hwint];

    // if (CDD_ADC_GROUP_CNT > group_id)
    // {
    /* Process the group if the group ID exists */
    Cdd_Adc_ProcessGroup(group_id);
    // }
}

#if (STD_ON == CDD_ADC_READ_GROUP_API)

/* Design: MCAL-31326 */
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ReadGroupResult(Cdd_Adc_GroupType Group, Cdd_Adc_ValueGroupType *DataPtr)
{
    uint8 channelnum;
    /* Copying the results from the result buffer to read group buffer*/
    for (channelnum = 0U; channelnum < Cdd_Adc_ConfigPtr->groupcfg[Group].channelcount; channelnum++)
    {
        *(DataPtr + channelnum) = *(Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr +
                                    (channelnum * Cdd_Adc_ConfigPtr->groupcfg[Group].stream_numsamples));
    }

    /* If group trigger source is Global software trigger then don't change the group status */
    if (Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_GLBSW)
    {
        /* Update the group status if the group is not called with StartGlobalTrig API */
        Cdd_Adc_UpdateGroupStatus(Group);
    }
}
#endif

/* Design: MCAL-31327 */
Cdd_Adc_StreamNumSampleType Cdd_Adc_GetValidSampleCnt(Cdd_Adc_GroupType Group, Cdd_Adc_ValueGroupType **PtrToSamplePtr)
{
    Cdd_Adc_StreamNumSampleType num_samples = Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples;
    /* This shall set the pointer, passed as parameter (PtrToSamplePtr) to point in the ADC result
     * buffer to the latest result of the first group channel of the last completed conversion
     * round.
     */
    /* Assign the pointer to the result buffer based on the number of valid samples count*/
    *PtrToSamplePtr = (Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr);

    /* If group trigger source is Global software trigger then don't change the group status */
    if (Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_GLBSW)
    {
        /* Update the group status if the group is not called with StartGlobalTrig API */
        Cdd_Adc_UpdateGroupStatus(Group);
    }

    /* Return the number of valid samples count */
    return num_samples;
}

#define CDD_ADC_STOP_SEC_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* Design: MCAL-31421 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetOffsetTrim(uint32 Base)
{
    /*
     * Selecting the individual offset trim mode wherein offset trim will be
     * supplied from individual registers already programmed by device_cal api.
     */
    Cdd_Adc_SelectOffsetTrimMode(Base, CDD_ADC_OFFSET_TRIM_INDIVIDUAL);
}

/* Design: MCAL-31423,MCAL-31132 */
static FUNC(void, CDD_ADC_CODE)
    Cdd_Adc_SetVREF(Cdd_Adc_HwUnitInstanceType HwUnitId, Cdd_Adc_RefModeType RefMode, Cdd_Adc_RefVoltType RefVoltage)
{
    uint32 analogrefctl_addr = (ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL);

    /* Configure the reference mode (internal or external) */
    if (RefMode == CDD_ADC_REFERENCE_INTERNAL)
    {
        HWREGH(analogrefctl_addr) &= ~(Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].analogrefsel);
        if (RefVoltage == CDD_ADC_REFERENCE_3_3V)
        {
            /* Configure the reference voltage 3.3V */
            HWREGH(analogrefctl_addr) &= ~(Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].analogrefvoltsel);
        }
        else
        {
            /* configure the reference voltage 2.5V */
            HWREGH(analogrefctl_addr) |= (Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].analogrefvoltsel);
        }
    }
    else
    {
        HWREGH(analogrefctl_addr) |= (Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].analogrefsel);
    }
}

/* Design: MCAL-31422 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetINLTrim(Cdd_Adc_HwUnitInstanceType HwUnitId)
{
    uint8   i;
    uint32  base = Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].base_addr;
    uint32 *trimaddress;
    trimaddress = (uint32 *)Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].inltrimaddress;
    Cdd_Adc_ResolutionType resolution =
        (Cdd_Adc_ResolutionType)((HWREGH(base + ADC_O_CTL2) & ADC_CTL2_RESOLUTION) >> 6U);

    /* Update INL trim values to ADC trim registers */
    for (i = 0U; i < Cdd_Adc_ConfigPtr->hwunitcfg[HwUnitId].numadc_inltrim; i++)
    {
        HWREG(base + ADC_O_INLTRIM1 + (i * (uint8)4U)) = *trimaddress;
        trimaddress++;
    }

    /* Apply linearity trim workaround for 12-bit resolution */
    if (resolution == CDD_ADC_RESOLUTION_12BIT)
    {
        /* 12-bit linearity trim workaround */
        HWREG(base + ADC_O_INLTRIM1) &= 0xFFFF0000U;
        HWREG(base + ADC_O_INLTRIM2) &= 0xFFFF0000U;
        HWREG(base + ADC_O_INLTRIM4) &= 0xFFFF0000U;
        HWREG(base + ADC_O_INLTRIM5) &= 0xFFFF0000U;
    }
}

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Design MCAL-31397 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigPpbUnit(Cdd_Adc_PpbType PpbId)
{
    const Cdd_Adc_PpbUnitCfgType *ppbcfg    = &Cdd_Adc_ConfigPtr->ppbcfg[PpbId];
    uint32                        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(ppbcfg->hwunitindex)].base_addr;

    /* PPB offset configuration */
    Cdd_Adc_ForcePpbSync(base_addr, ppbcfg->ppb_id);
    /* Set the calibration offset for the hardware unit */
    Cdd_Adc_PpbOffsetCorrection(base_addr, ppbcfg->ppb_id, ppbcfg->ppb_caloffset);
    /* Set the reference offset for the hardware unit */
    Cdd_Adc_SetPpbRefOffset(base_addr, ppbcfg->ppb_id, ppbcfg->ppb_refoffset);
    /* PPB result configuration */
    Cdd_Adc_ConfigurePpbResult(base_addr, ppbcfg->ppb_id, (ppbcfg->ppbresconfig | ppbcfg->soc_num));
    /* PPB trip high configuration */
    Cdd_Adc_ConfigurePpbHighLimit(base_addr, ppbcfg->ppb_id, ppbcfg->triplimithi);
    /* Enable extended trip low limit */
    Cdd_Adc_EnablePpbExtendedLowLimit(base_addr, ppbcfg->ppb_id);
    /* Set trip limit low2 enable */
    Cdd_Adc_SetPpbExtendedLowLimit(base_addr, ppbcfg->ppb_id, ppbcfg->triplimitlow);
    /* Configure PPB2 */
    Cdd_Adc_ConfigPpb2(base_addr, ppbcfg->ppb_id, ppbcfg->ppbcfg2);
    /* Set PPB count limit */
    Cdd_Adc_SetPpbCountLimit(base_addr, ppbcfg->ppb_id, ppbcfg->ppbcountlimit);

    /* PPB trip filter settings */
    /* Configure trip filter if not enabled */
    if (ppbcfg->tripfilterenable == TRUE)
    {
        Cdd_Adc_SetTripFilPrescale(base_addr, ppbcfg->ppb_id, ppbcfg->tripfilclk);
        Cdd_Adc_ConfigureTripFilter(base_addr, ppbcfg->ppb_id, ppbcfg->tripfilctl);
    }
}
#endif

/* Design: MCAL-31420 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetGrpTrigger(Cdd_Adc_GroupType Group)
{
    const Cdd_Adc_GroupCfgType *group_cfg = &(Cdd_Adc_ConfigPtr->groupcfg[Group]);
    uint8                       channel_id;
    uint32                      base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(group_cfg->hwunit_index)].base_addr;

    if (group_cfg->trigsrc_type == CDD_ADC_TRIGG_SRC_HW)
    {
        Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_HW;
        /* Enable trigger sources for hardware trigger groups */
        for (channel_id = group_cfg->startchannelnum;
             ((channel_id < (group_cfg->channelcount + group_cfg->startchannelnum))); channel_id++)
        {
            /* Assign the soc number to the channel and configure the SOC */
            Cdd_Adc_SetupSoc(base_addr, Cdd_Adc_ConfigPtr->channelcfg[channel_id].soc_num, group_cfg->trigger_src,
                             Cdd_Adc_ConfigPtr->channelcfg[channel_id].channel_id,
                             Cdd_Adc_ConfigPtr->channelcfg[channel_id].sample_window);
            if (group_cfg->intsocsel != CDD_ADC_INT_SOC_TRIGGER_NONE)
            {
                /* Set the interrupt trigger source */
                Cdd_Adc_SetIntSocTrigger(base_addr, Cdd_Adc_ConfigPtr->channelcfg[channel_id].soc_num,
                                         group_cfg->intsocsel);
            }
        }
    }
    else
    {
        /* For groups triggered through software (group_cfg->trigsrc_type == CDD_ADC_TRIGG_SRC_SW) */
        Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;
        Cdd_Adc_ForceMultipleSoc(base_addr, group_cfg->soc_mask);
    }
}

/* Design: MCAL-31413 */
/* Private function to update the status of the group */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_UpdateGroupStatus(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupObjType *group_obj = &(Cdd_Adc_DrvObjPtr->group_obj[Group]);
    /* Groups in IDLE state or in STREAM_COMPLETED state that are stopped implicitly are updated to
     * IDLE state*/
    if ((group_obj->grp_status == CDD_ADC_IDLE) ||
        ((group_obj->implicit_stop == TRUE) && (group_obj->grp_status == CDD_ADC_STREAM_COMPLETED)))
    {
        group_obj->grp_status = CDD_ADC_IDLE;
    }
    else
    {
        /* Group that are not stopped implicilty or in BUSY state are moved to BUSY state. */
        group_obj->grp_status = CDD_ADC_BUSY;
    }
}

/* Design: MCAL-31414 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopHwGrpTrigger(Cdd_Adc_GroupType Group)
{
    const Cdd_Adc_GroupCfgType   *group_cfg = &(Cdd_Adc_ConfigPtr->groupcfg[Group]);
    const Cdd_Adc_ChannelCfgType *channelcfg;
    uint8                         channelnum;
    uint8                         hwunit_index = group_cfg->hwunit_index;
    uint32                        base_addr    = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].base_addr;

    /* Disable trigger sources for the hardware trigger groups which can be stopped impliclitly */
    for (channelnum = group_cfg->startchannelnum; (channelnum < (group_cfg->channelcount + group_cfg->startchannelnum));
         channelnum++)
    {
        channelcfg = &(Cdd_Adc_ConfigPtr->channelcfg[channelnum]);
        /* Assign the soc number to the channel and configure the SOC.*/
        Cdd_Adc_SetupSoc(base_addr, channelcfg->soc_num, CDD_ADC_TRIGGER_SW_ONLY, channelcfg->channel_id,
                         channelcfg->sample_window);

        if (group_cfg->intsocsel != CDD_ADC_INT_SOC_TRIGGER_NONE)
        {
            /* Set the interrupt trigger source */
            Cdd_Adc_SetIntSocTrigger(base_addr, channelcfg->soc_num, CDD_ADC_INT_SOC_TRIGGER_NONE);
        }
    }
}

/* Design: MCAL-31415 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_SetGroup(Cdd_Adc_GroupType Group)
{
    const Cdd_Adc_GroupCfgType *groupcfg    = &(Cdd_Adc_ConfigPtr->groupcfg[Group]);
    Cdd_Adc_GroupObjType       *group_obj   = &(Cdd_Adc_DrvObjPtr->group_obj[Group]);
    uint8                       hwunitindex = groupcfg->hwunit_index;
    uint32                      base_addr   = Cdd_Adc_ConfigPtr->hwunitcfg[(hwunitindex)].base_addr;

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    Cdd_Adc_PpbType               ppb_num, lastppbnum;
    const Cdd_Adc_PpbUnitCfgType *ppbcfg;
#endif

    /* Set the valid samples count to Zero. */
    group_obj->valid_samples = 0U;

    /* Update the current result pointer only if DMA is not enabled for the group */
    if (FALSE == Cdd_Adc_ConfigPtr->groupcfg[Group].dma_mode)
    {
        /* Reset the internal result buffer pointer. */
        group_obj->cur_resultptr = (Cdd_Adc_ValueGroupType *)(group_obj->resbuffer);
    }

    /* Set the group active status to TRUE */
    group_obj->grp_active = TRUE;

    /* Clear the interrupt flag before enabling it */
    Cdd_Adc_ClearInterruptFlag(base_addr, groupcfg->grp_int);
    /* Enable the corresponding interrupt */
    Cdd_Adc_ConfigureInterrupt(base_addr, groupcfg->grp_int, TRUE);
    Cdd_Adc_ConfigureContinueToIntMode(base_addr, groupcfg->grp_int, (boolean)groupcfg->continuetoint);

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

    /* Fetch the last PPB ID linked to the ADC instance */
    lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].ppbcount +
                                   Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum);

    for (ppb_num = Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum; ((ppb_num < lastppbnum)); ppb_num++)
    {
        if ((((uint32)1U << Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].soc_num) & groupcfg->soc_mask) != (uint32)0U)
        {
            ppbcfg = &(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num]);

            /* Clear all the PPB event flags to avoid unneccessary interrupt or event generation */
            Cdd_Adc_ClearPpbEvtStatus(base_addr, Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id, (uint8)ADC_PPBEVTMASK);

            /* Enable interrupt and event flags */
            Cdd_Adc_ConfigPpbEvent(base_addr, ppbcfg->ppb_id, ppbcfg->tripevtsel, TRUE);
            Cdd_Adc_ConfigPpbEventInterrupt(base_addr, ppbcfg->ppb_id, ppbcfg->tripevtintsel, TRUE);

            /* Don't configure trip filter if not enabled */
            if (ppbcfg->tripfilterenable == TRUE)
            {
                Cdd_Adc_TripFilterInit(base_addr, ppbcfg->ppb_id);
            }
        }
    }

#endif

    /* Set the group status to Busy */
    group_obj->grp_status = CDD_ADC_BUSY;
}

/* Design: MCAL-31417 */
static FUNC(void, CDD_ADC_CODE) Cdd_Adc_ProcessGroup(Cdd_Adc_GroupType Group)
{
    const Cdd_Adc_GroupCfgType *groupcfg  = &(Cdd_Adc_ConfigPtr->groupcfg[Group]);
    Cdd_Adc_GroupObjType       *group_obj = &(Cdd_Adc_DrvObjPtr->group_obj[Group]);

    uint32 base_addr, result_baseaddr;

    if (!(((group_obj->implicit_stop == TRUE) && (group_obj->valid_samples == groupcfg->stream_numsamples)) ||
          (group_obj->grp_status == CDD_ADC_IDLE)))
    {
        base_addr       = Cdd_Adc_ConfigPtr->hwunitcfg[(groupcfg->hwunit_index)].base_addr;
        result_baseaddr = Cdd_Adc_ConfigPtr->hwunitcfg[(groupcfg->hwunit_index)].result_baseaddr;

        /* Update the current result pointer only if DMA is not enabled for the group */
        if (FALSE == groupcfg->dma_mode)
        {
            if ((group_obj->valid_samples == groupcfg->stream_numsamples) || (group_obj->valid_samples == 0U))
            {
                /* If the buffer is filled wrap around the buffer */
                group_obj->cur_resultptr = (Cdd_Adc_ValueGroupType *)(group_obj->resbuffer);
            }
            else
            {
                group_obj->cur_resultptr++; /* Update the current result buffer pointer */
            }
        }

        /* Continue with ISR execution */
        if ((group_obj->valid_samples == groupcfg->stream_numsamples) || (group_obj->valid_samples == 0U))
        {
            /* Valid samples has become equal to maximum streaming number of samples for the group */
            group_obj->valid_samples = 1U;
        }
        else
        {
            group_obj->valid_samples++; /* Number of valid samples per channel */
        }

        /* Update the group status to CDD_ADC_COMPLETED when global software trigger is the source
            and when the result buffer is not completely filled */
        if ((group_obj->triggersrc == CDD_ADC_GRP_TRIGG_SRC_GLBSW) ||
            (group_obj->valid_samples != groupcfg->stream_numsamples))
        {
            group_obj->grp_status = CDD_ADC_COMPLETED;
        }
        else
        {
            /* Update the group status to CDD_ADC_STREAM_COMPLETED when the buffer is completely
             * filled */
            group_obj->grp_status = CDD_ADC_STREAM_COMPLETED;
        }

        /* Clear the interrupt flag and the result ready flag */
        Cdd_Adc_ClearInterruptFlag(base_addr, groupcfg->grp_int);
        /* Check if interrupt overflow has occurred */
        if (TRUE == Cdd_Adc_GetIntOvfStatus(base_addr, groupcfg->grp_int))
        {
            Cdd_Adc_ClearIntOvfStatus(base_addr, groupcfg->grp_int);
            Cdd_Adc_ClearInterruptFlag(base_addr, groupcfg->grp_int);
        }

        /* Do not disable interrupts for explicitly stopped groups and don't stop if the buffer
               is not completely filled implicitly stopped groups */
        if ((group_obj->implicit_stop == TRUE) && (group_obj->valid_samples == groupcfg->stream_numsamples))
        {
            /* Disable interrups if the buffer is completely filled for the implicitly stopped
             * groups */
            Cdd_Adc_ConfigureInterrupt(base_addr, groupcfg->grp_int, FALSE);
            /* Disable continue to interrupt mode */
            Cdd_Adc_ConfigureContinueToIntMode(base_addr, groupcfg->grp_int, FALSE);
        }

        /* Copy the results to the result buffer of the group if DMA is not enabled for the group */
        if (FALSE == groupcfg->dma_mode)
        {
            for (uint8 channelnum = 0U; channelnum < groupcfg->channelcount; channelnum++)
            {
                /* Read the corresponding SOC result and store it in the group result buffer */
                *(group_obj->cur_resultptr + (channelnum * (groupcfg->stream_numsamples))) = Cdd_Adc_ReadResult(
                    result_baseaddr, Cdd_Adc_ConfigPtr->channelcfg[(channelnum + groupcfg->startchannelnum)].soc_num);
            }
        }

#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
        if (group_obj->grp_notification == TRUE)
        {
            /* Call the specified end group notification function */
            groupcfg->groupend_notification();
        }
#endif /*(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API) */

        /* Manual re-trigger is necessary only for the software triggered groups */
        if ((group_obj->triggersrc == CDD_ADC_GRP_TRIGG_SRC_SW) &&
            ((group_obj->implicit_stop == FALSE) || (group_obj->valid_samples < groupcfg->stream_numsamples)))
        {
            /* Retrigger the group conversion if the group doesn't stop implicitly or the buffer is
            not completely filled for implicitly stopped groups */
            Cdd_Adc_ForceMultipleSoc(base_addr, groupcfg->soc_mask);
        }
        else if ((group_obj->triggersrc == CDD_ADC_GRP_TRIGG_SRC_HW) && (group_obj->implicit_stop == TRUE) &&
                 (group_obj->valid_samples == groupcfg->stream_numsamples))
        {
            /* Disable group trigger sources and interrupt trigger source for the hardware trigger
             * source groups which ae impliclitly stoped. If the  hardware group trigger source is
             * left unchanged the hardware trigger might start ADC conversion when the trigger is
             * received blocking other group conversions. No need to perform any action for software
             * triggers except disabling interrupts
             */
            Cdd_Adc_StopHwGrpTrigger(Group);
        }
        else
        {
            /* For explicitly stopped hardware groups don't stop hardware triggers and
                for implicitly stopped software groups don't trigger the group for another
               conversion */
        }
    }
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Priv.c
 *********************************************************************************************************************/
