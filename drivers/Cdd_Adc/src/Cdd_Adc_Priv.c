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
 *  Description: This file contains private function definitions that are defined in Cdd_Adc_Priv.h file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Priv.h"
#include "Mcal_Lib_BootRom.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define ADC_SOCXCTL_STEP            (ADC_O_SOC1CTL - ADC_O_SOC0CTL)

#define ADC_REPXCTL_STEP            (ADC_O_REP2CTL - ADC_O_REP1CTL)
#define ADC_REPXN_STEP              (ADC_O_REP2N - ADC_O_REP1N)
#define ADC_REPXPHASE_STEP          (ADC_O_REP2PHASE - ADC_O_REP1PHASE)
#define ADC_REPXSPREAD_STEP         (ADC_O_REP2SPREAD - ADC_O_REP1SPREAD)
#define ADC_INTSELXNY_STEP          (ADC_O_INTSEL3N4 - ADC_O_INTSEL1N2)

#define ADC_PPBXCONFIG_STEP         (ADC_O_PPB2CONFIG - ADC_O_PPB1CONFIG)
#define ADC_PPBXOFFCAL_STEP         (ADC_O_PPB2OFFCAL - ADC_O_PPB1OFFCAL)
#define ADC_PPBXOFFREF_STEP         (ADC_O_PPB2OFFREF - ADC_O_PPB1OFFREF)
#define ADC_PPBXTRIPHI_STEP         (ADC_O_PPB2TRIPHI - ADC_O_PPB1TRIPHI)
#define ADC_PPBXTRIPLO_STEP         (ADC_O_PPB2TRIPLO - ADC_O_PPB1TRIPLO)
#define ADC_PPBXTRIPLO2_STEP        (ADC_O_PPB2TRIPLO2 - ADC_O_PPB1TRIPLO2)

#define ADC_PPBXSTAMP_STEP          (ADC_O_PPB2STAMP - ADC_O_PPB1STAMP)
#define ADC_PPBXLIMIT_STEP          (ADC_O_PPB2LIMIT - ADC_O_PPB1LIMIT)
#define ADC_PPBXCONFIG2_STEP        (ADC_O_PPB2CONFIG2 - ADC_O_PPB1CONFIG2)
#define ADC_PPBXSUM_STEP            (ADC_O_PPB2SUM -  ADC_O_PPB1SUM)
#define ADC_PPBXMAX_STEP            (ADC_O_PPB2MAX - ADC_O_PPB1MAX)
#define ADC_PPBXMAXI_STEP           (ADC_O_PPB2MAXI - ADC_O_PPB1MAXI) 
#define ADC_PPBXMIN_STEP            (ADC_O_PPB2MIN - ADC_O_PPB1MIN)   
#define ADC_PPBXMINI_STEP           (ADC_O_PPB2MINI- ADC_O_PPB1MINI)
#define ADC_PPBXRESULT_STEP         (ADC_O_PPB2RESULT -  ADC_O_PPB1RESULT)
#define ADC_PPBXCOUNT_STEP          (ADC_O_PPB2COUNT -  ADC_O_PPB1COUNT)

#define ADC_PPBXPSUM_STEP            (ADC_O_PPB2PSUM -  ADC_O_PPB1PSUM)
#define ADC_PPBXPMAX_STEP            (ADC_O_PPB2PMAX - ADC_O_PPB1PMAX)
#define ADC_PPBXPMAXI_STEP           (ADC_O_PPB2PMAXI - ADC_O_PPB1PMAXI) 
#define ADC_PPBXPMIN_STEP            (ADC_O_PPB2PMIN - ADC_O_PPB1PMIN)   
#define ADC_PPBXPMINI_STEP           (ADC_O_PPB2PMINI- ADC_O_PPB1PMINI)
#define ADC_PPBXPCOUNT_STEP          (ADC_O_PPBP2PCOUNT -  ADC_O_PPBP1PCOUNT)
#define ADC_PPBXTRIPFIL_STEP         (ADC_O_PPBTRIP2FILCTL - ADC_O_PPBTRIP1FILCTL)
#define ADC_PPBXTRIPFILCLK_STEP      (ADC_O_PPBTRIP2FILCLKCTL - ADC_O_PPBTRIP1FILCLKCTL)
#define ADC_PPBEVTMASK              (ADC_EVTSEL_PPB1TRIPHI | ADC_EVTSEL_PPB1TRIPLO | ADC_EVTSEL_PPB1ZERO) 

#define ADC_RESULT_STEP             (ADC_O_RESULT1 - ADC_O_RESULT0)
#define ADC_SAFECHECKRESEN_STEP     (ADC_O_SAFECHECKRESEN2 - ADC_O_SAFECHECKRESEN)

#define ADC_CHECKERINTEVTBASE_STEP      (ADCSAFETYCHECKINTEVT2_BASE - ADCSAFETYCHECKINTEVT1_BASE)

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
P2VAR(Cdd_Adc_DriverObjType,AUTOMATIC,CDD_ADC_VAR_FAST_INIT) Cdd_Adc_DrvObjPtr = NULL_PTR;
#define CDD_ADC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"

#define CDD_ADC_START_SEC_VAR_INIT_PTR
#include "Cdd_Adc_MemMap.h"
P2CONST(Cdd_Adc_ConfigType,AUTOMATIC,CDD_ADC_CONST) Cdd_Adc_ConfigPtr = NULL_PTR;
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelectOffsetTrimMode(uint32 Base, Cdd_Adc_OffsetTrimType TrimMode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPrescaler(uint32 Base, Cdd_Adc_PrescaleType Prescale);


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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntPulseMode(uint32 Base, Cdd_Adc_EocPulseType PulseMode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetupSoc(uint32 Base, uint8 SocNum, Cdd_Adc_TriggerType Trigger,\
                                            uint8 Channel, uint32 SampleWindow);
                                            
/** \brief Force Multiple SOC function
 *
 * This function triggers the software conversion for the SOCs configured in the SocMask where SOC ID th bit is set 
 * in the SocMask
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  SocMask     SOC mask to trigger conversion for all the SOCs whose corresponding bit is set in the mask
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForceMultipleSoc(uint32 Base, uint32 SocMask);

/** \brief Set SOC priority function
 *
 * This function sets the SOC priority mode for the ADC hardware unit. The SOCs whose ID is below this value will be 
 * considered as high priority and the rest will be considered in ROUND-ROBIN mode.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PriorityMode     Priority mode for the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetSocPriority(uint32 Base, Cdd_Adc_SocPriorityType PriorityMode);

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
static FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_ReadResult(uint32 ResultBase, uint8 SocNumber);

/** \brief Set interrupt as the SOC trigger function
 *
 * This function selects the specified interrupt as the SOC trigger in addition to the selected trigger. 
 * This is applicable to only INT & INT2. 
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntSocTrigger(uint32 Base, uint8 SocNum,\
                                            Cdd_Adc_IntSocTriggerType Trigger);

/* ADC global registers */
#if(CDD_ADC_GLBSW_TRIG_API == STD_ON)
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_GlobalSwTrigger(uint8 AdcMask);

/** \brief Global software SOC select function
 *
 * This function enables triggers the software conversion for the specified SOC whose ADC hardware unit is configured
 * for the global software trigger
 *
 * \param[in]  SocMask   Mask to select the SOCs for the global software trigger. All the selected SOCs in the 
 *                          selected hardware unit will be triggered for the ADC conversion.
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SocGlobalSwTrigger(uint32 SocMask);
#endif

#if(CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelSocExtChn(uint32 Base, uint8 SocNum, uint8 ExtChannel);

/** \brief Configure external mux preselect function
 *
 * This enables/disables the external mux preselect for the specified ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  Mode     Enable/Disable to select/deselect external mux preselection
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureExtMuxPreselect(uint32 Base, boolean Mode);
#endif

#if(CDD_ADC_TRIG_REP_ENABLE == STD_ON)

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepMode(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                Cdd_Adc_RepeaterModeType RepMode);

/** \brief Select trigger for the trigger repeater function
 *
 * This function selects the trigger for the trigger repeater of an ADC hardware unit whose trigger will be generated 
 * repeatedly for a configured count limit
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelTrigRepTrigger(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                    Cdd_Adc_TriggerType Trigger);

/** \brief Trigger repeater sync function
 *
 * This function resets the trigger repeater flags except for the count, phase and spread delay values.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForceRepeaterTriggerSync(uint32 Base, Cdd_Adc_RepeaterType RepInstance);

/** \brief Set trigger repeater count function
 *
 * This function configures the trigger count for the repeater of an ADC hardware unit. The configured count number of
 * triggers will be generated once the trigger is received by the repeater instance.
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepCount(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                            uint8 RepCount);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepPhase(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                uint16 RepPhase);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepSpread(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                    uint16 RepSpread);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearPhaseOvf(uint32 Base,Cdd_Adc_RepeaterType RepInstance);

/** \brief Clear trigger overflow function
 *
 * This function clears the trigger overflow flow for the specified trigger repeater of an ADC HW unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  RepInstance     Numeric ID of the repeater instance of an ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearTriggerOvf(uint32 Base,Cdd_Adc_RepeaterType RepInstance);
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureInterrupt(uint32 Base,Cdd_Adc_IntNumType IntNum,\
                                                                    boolean Mode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) 
Cdd_Adc_ConfigureContinueToIntMode(uint32 Base,Cdd_Adc_IntNumType IntNum, boolean Mode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntSource(uint32 Base,Cdd_Adc_IntNumType IntNum,\
                                                Cdd_Adc_IntTriggerType IntTrigger);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearInterruptFlag(uint32 Base,Cdd_Adc_IntNumType IntNum);

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
static FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetIntOvfStatus(uint32 Base,Cdd_Adc_IntNumType IntNum);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearIntOvfStatus(uint32 Base,Cdd_Adc_IntNumType IntNum);

/** \brief Set interrupt cycle offset function
 *
 * This functions sets the interrupt cycle offset for the ADC hardware unit. Used when the interrupt pulse mode is 
 * configured as END_OF_ACQ_WIN. This allows the time to delay the interrupt after the SOC acquisition.
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  CycleOffset     Number of SYSCLK cycles to be waited before generating the interrupt
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetInterruptCycleOffset(uint32 Base, uint16 CycleOffset);

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_PpbOffsetCorrection(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                uint16 OffCal);

/** \brief Set Ppb reference offset function
 *
 * This function sets the PPB reference offset of the PPB of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  OffCal     Reference offset configured for the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbRefOffset(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 Offset);

/** \brief Set Ppb configuration function
 *
 * This function configures PPB of the ADC hardware unit
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  ResConfig     Configuration of the PPB (Like Delta enable, absolute enable & two's complement)
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigurePpbResult(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                            uint16 ResConfig);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigurePpbHighLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                    sint32 LimitHigh);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_EnablePpbExtendedLowLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber);

/** \brief Set Ppb extended trip low limit function
 *
 * This function configures extended trip low limit of the PPB
 *
 * \param[in]  Base     Base address of the ADC hardware unit
 * \param[in]  PpbNumber     Number ID of the PPB
 * \param[in]  LimitHigh     Extended trip low limit of the PPB
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbExtendedLowLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                                     sint32 TripLowLimit);
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureTripFilter(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                        uint16 TripFilCfg);

/** \brief Initialize Ppb trip filter function
 *
 * This function Initialize Ppb trip filter of the PPB
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_TripFilterInit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTripFilPrescale(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                            uint16 ClkPrescale);

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
static FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_GetPpbEvtStatus(uint32 Base);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpbEvent(uint32 Base,Cdd_Adc_PpbIdType PpbNumber, uint16 EvtFlags,\
        boolean Mode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpbEventInterrupt(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                uint16 IntFlags,boolean Mode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbCountLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber, uint16 Limit);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpb2(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 PpbCfg2);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForcePpbSync(uint32 Base,Cdd_Adc_PpbIdType PpbNumber);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpbUnit(Cdd_Adc_PpbType PpbId);

#endif

#if(STD_ON == CDD_ADC_SAFETY_CHECK_API)

/** \brief Sets the safety checker input for the SOC
 *
 * This function sets the safety checker input for the SOC, this selects whether SOC result, PPB result or PPBSUM 
 * result is passed to the safety checker
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureSafetyCheckerInput(uint32 Base,uint8 SocNum,\
                                                                Cdd_Adc_CheckerInputType ScInput);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureSafetyChecker(uint32 ScBase,uint8 CheckerResNum,\
            Cdd_Adc_HwUnitType Instance,uint8 ResultNum);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetSafetyCheckerTolerance(uint32 ScBase, uint32 Tolerance);

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
LOCAL_INLINE FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckStatus(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,\
                            Cdd_Adc_SafetyCheckFlagType CheckerFlag);

/** \brief Clears the safety checker flag status for the specified flag
 *
 * This function clears the safety checker flag status for the safety checker unit for the specified flag
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearCheckEvtFlag(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,\
                                        Cdd_Adc_SafetyCheckFlagType CheckerFlag);

/** \brief Clears the safety checker flags for multiple safety checker units for a specified flag
 *
 * This function clears the safety checker flag for multiple safety checker units for a specified flag
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) 
Cdd_Adc_ClearCheckEvtStatus(uint32 Base,Cdd_Adc_SafetyCheckFlagType CheckerFlag,uint16 EvtMask);

/** \brief Configures interrupt for a specified flag function for a safety checker interrupt event instance
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureCheckIntSrc(uint32 Base,\
        Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag,uint16 IntFlagMask,boolean Mode);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearSafetyCheckIntStatus(uint32 Base);

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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureCheckEvtSrc(uint32 Base,\
        Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag,\
    uint8 CheckEvt,uint16 EvtFlagMask,boolean Mode);
#endif

#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigOSDetectMode(uint32 Base, Cdd_Adc_OsDetectModeType Mode);
#endif

#if(STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureTempSensor(boolean Mode);

/** \brief Returns lock temperature sensor function
 *
 * This function returns the temperature sensor lock status
 *
 * \param[in]  None
 * \pre None
 * \post None
 * \return Returns the temperature sensor lock status
 * \retval boolean - TRUE if the temperature sensor is locked
 *                  FALSE if the temperature sensor is not locked
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetTempSensorLockStatus(void);
#endif

#if(STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)
/** \brief Lock temperature sensor function
 *
 * This function locks temperature sensor
 *
 * \param[in]  None
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_LockTempSensor(void);
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
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureConverter(uint32 Base, boolean Mode);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_UpdateGroupStatus(Cdd_Adc_GroupType Group);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopHwGrpTrigger(Cdd_Adc_GroupType Group);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetGroup(Cdd_Adc_GroupType Group);

/** \brief Process group conversion after one complete conversion round
 *
 * This function manages the group conversion and status update after every complete conversion round
 *
 * \param[in]  Group   Group ID
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_ProcessGroup(Cdd_Adc_GroupType Group);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetGrpTrigger(Cdd_Adc_GroupType Group);

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
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetOffsetTrim(uint32 Base);

/** \brief Set INL TRIM values for the ADC HW Unit function
 *
 * This function sets INL TRIM values for the ADC HW Unit
 *
 * \param[in]  Base     ADC hardware unit base address
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetINLTrim(uint32 Base);

/** \brief Set voltage reference for the ADC HW Unit function
 *
 * This function sets the voltage reference for the ADC HW Unit
 *
 * \param[in]  Base     ADC hardware unit base address
 * \param[in]  RefMode     voltage reference mode
 * \param[in]  RefVoltage     reference voltage configured for the ADC HW Unit
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetVREF(uint32 Base, Cdd_Adc_RefModeType RefMode,\
                                            Cdd_Adc_RefVoltType RefVoltage);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_ADC_START_SEC_CODE
#include "Cdd_Adc_MemMap.h"

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelectOffsetTrimMode(uint32 Base, Cdd_Adc_OffsetTrimType TrimMode)
{
    /* Select offset trim mode for the ADC hardware instance */ 
    HWREGH(Base + ADC_O_CTL2) = (HWREGH(Base + ADC_O_CTL2) & ~(ADC_CTL2_OFFTRIMMODE)) | (uint16)TrimMode;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPrescaler(uint32 Base, Cdd_Adc_PrescaleType Prescale)
{
    HWREGH(Base + ADC_O_CTL2) = (HWREGH(Base + ADC_O_CTL2) & \
                                 ~ADC_CTL2_PRESCALE_M) | (uint16)Prescale;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntPulseMode(uint32 Base, Cdd_Adc_EocPulseType PulseMode)
{
    /* Set the position of the pulse */
    HWREGH(Base + ADC_O_CTL1) = (HWREGH(Base + ADC_O_CTL1) & ~ADC_CTL1_INTPULSEPOS)\
                             | ((uint16)PulseMode);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetupSoc(uint32 Base, uint8 SocNum, Cdd_Adc_TriggerType Trigger,\
                                            uint8 Channel, uint32 SampleWindow)
{
    /* Calculate address for the SOC control register */
    uint32 ctrlreg_addr = Base + ADC_O_SOC0CTL + ((uint32)SocNum * ADC_SOCXCTL_STEP);

    /* Set the configuration of the specified SOC */
    HWREG(ctrlreg_addr) = (HWREG(ctrlreg_addr) & ~(ADC_SOC0CTL_CHSEL_M | ADC_SOC0CTL_ACQPS_M | ADC_SOC0CTL_TRIGSEL_M)) 
                        | ((uint32)Channel << ADC_SOC0CTL_CHSEL_S) |
                        ((uint32)Trigger << ADC_SOC0CTL_TRIGSEL_S) | (SampleWindow);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForceMultipleSoc(uint32 Base, uint32 SocMask)
{
    /* Write to the register that will force a 1 to desired SOCs */
    HWREG(Base + ADC_O_SOCFRC1) |= SocMask;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetSocPriority(uint32 Base, Cdd_Adc_SocPriorityType PriorityMode)
{
    HWREGH(Base + ADC_O_SOCPRICTL) = (HWREGH(Base + ADC_O_SOCPRICTL) & ~ ADC_SOCPRICTL_SOCPRIORITY_M) | \
                                                                                    ((uint16)PriorityMode);
}

static FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_ReadResult(uint32 ResultBase, uint8 SocNumber)
{
/*  Return the ADC result for the selected SOC */
    return (uint16)(HWREGH(ResultBase + ADC_O_RESULT0 + ((uint32)SocNumber * ADC_RESULT_STEP)));
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntSocTrigger(uint32 Base, uint8 SocNum,\
                                            Cdd_Adc_IntSocTriggerType Trigger)
{
    /* Each SOC has a 2-bit field in this register */
    uint16 shift_val = ((SocNum%((uint16)16U)) << 1U);
    /* Get the offset to the appropriate offset register */
    uint32 offset =  Base + ADC_O_INTSOCSEL1 + ((((uint32)SocNum)/16U) * 4U);
    HWREG(offset) = (HWREG(offset) & ~((uint32)ADC_INTSOCSEL1_SOC0_M << shift_val)) | \
                    ((uint8)Trigger << shift_val);
}

/* ADC global registers */
#if(CDD_ADC_GLBSW_TRIG_API == STD_ON)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_GlobalSwTrigger(uint8 AdcMask)
{
    /* Configuring the register ADCSOCFRCGBSEL to select the ADC instances*/
    HWREG(ADCGLOBAL_BASE + ASYSCTL_O_ADCSOCFRCGBSEL) = (uint32)AdcMask;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SocGlobalSwTrigger(uint32 SocMask)
{
    /* Configuring the SocMask to select the SOCs to be triggered simultaneously on differen ADCs */
    HWREG(ADCGLOBAL_BASE + ASYSCTL_O_ADCSOCFRCGB) = SocMask;  
}
#endif

#if(CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelSocExtChn(uint32 Base, uint8 SocNum, uint8 ExtChannel)
{
    uint32 ctlreg_addr = Base + ADC_O_SOC0CTL + ((uint32)SocNum * (ADC_SOCXCTL_STEP));

    /* Set the external channel configuration of the specified SOC. */ 
    HWREG(ctlreg_addr) = (HWREG(ctlreg_addr) & ~((uint32)ADC_SOC0CTL_EXTCHSEL_M)) | \
                   ((uint32)ExtChannel << ADC_SOC0CTL_EXTCHSEL_S);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureExtMuxPreselect(uint32 Base, boolean Mode)
{
    /* Enable the external mux selection at the beginning of S+H window of current conversion */
    HWREGH(Base + ADC_O_CTL1) = (HWREGH(Base + ADC_O_CTL1) & ~ ADC_CTL1_EXTMUXPRESELECTEN) | \
                                ((uint16)Mode*ADC_CTL1_EXTMUXPRESELECTEN);
}
#endif

#if(CDD_ADC_TRIG_REP_ENABLE == STD_ON)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepMode(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                Cdd_Adc_RepeaterModeType RepMode)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    /* Set the specified repeater trigger source to modify. */
    HWREG(regoffset) = (HWREG(regoffset) & ~ ADC_REP1CTL_MODE) | (uint32)RepMode;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelTrigRepTrigger(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                    Cdd_Adc_TriggerType Trigger)
{
   uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
   /*Set the specified repeater trigger source to modify */
   HWREG(regoffset  ) = (HWREG(regoffset) & ~((uint32)ADC_REP1CTL_TRIGGER_M)) | \
                       ((uint32)Trigger << ADC_REP1CTL_TRIGGER_S);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForceRepeaterTriggerSync(uint32 Base, Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    /* Force software sync for the trigger repeater block */ 
    HWREG(regoffset) |= ADC_REP1CTL_SWSYNC;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepCount(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                uint8 RepCount)
{
    uint32 regoffset = Base + ((uint32)RepInstance * ADC_REPXN_STEP)+ ADC_O_REP1N;
    /* Configure repeater count */ 
    HWREG(regoffset) = (HWREG(regoffset) & ~(ADC_REP1N_NSEL_M)) | RepCount;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepPhase(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                uint16 RepPhase)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXPHASE_STEP)) + ADC_O_REP1PHASE;
    /* Configure repeater phase */
    HWREG(regoffset) = (HWREG(regoffset) & ~ ADC_REP1PHASE_PHASE_M) | RepPhase;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTrigRepSpread(uint32 Base,Cdd_Adc_RepeaterType RepInstance,\
                                                                    uint16 RepSpread)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXSPREAD_STEP)) + ADC_O_REP1SPREAD;
    /* Configure repeater spread. */
    HWREG(regoffset ) =(HWREG(regoffset) & ~ (ADC_REP1SPREAD_SPREAD_M)) | RepSpread;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearPhaseOvf(uint32 Base,Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    
    /* Clear repeater phase overflow flags */ 
    HWREG(regoffset ) |= (ADC_REP1CTL_PHASEOVF) ;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearTriggerOvf(uint32 Base,Cdd_Adc_RepeaterType RepInstance)
{
    uint32 regoffset = Base + ((uint32)RepInstance * (ADC_REPXCTL_STEP)) + ADC_O_REP1CTL;
    
    /* Clear repeater phase overflow flags */ 
    HWREG(regoffset) |= (ADC_REP1CTL_TRIGGEROVF);
}
#endif

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureInterrupt(uint32 Base,Cdd_Adc_IntNumType IntNum,\
                                                                    boolean Mode)
{
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + (((uint8)IntNum >> 1U) * ADC_INTSELXNY_STEP);
    uint16 shiftval = (((uint8)IntNum & (uint16)0x1U) << 3U);
    /* Enable/Disable the specified ADC interrupt. */
    HWREGH(base_addr) = (HWREGH(base_addr) & ~(ADC_INTSEL1N2_INT1E << shiftval)) | \
                        ((uint8)(Mode*ADC_INTSEL1N2_INT1E) << shiftval);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) 
Cdd_Adc_ConfigureContinueToIntMode(uint32 Base,Cdd_Adc_IntNumType IntNum, boolean Mode)
{
    /* Each INTSEL register manages two interrupts. If the interrupt number is
     even, we'll be accessing the upper byte and will need to shift. */
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + (((uint8)IntNum >> 1U) * ADC_INTSELXNY_STEP);
    uint16 shiftval = ((uint8)IntNum & (uint16)0x1U) << 3U;
    /* Enable continuous mode for the specified ADC interrupt. */
    HWREGH(base_addr) = ((HWREGH(base_addr) & ~(ADC_INTSEL1N2_INT1CONT << shiftval)) |\
                                             ((Mode*ADC_INTSEL1N2_INT1CONT) << (shiftval)));
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetIntSource(uint32 Base,Cdd_Adc_IntNumType IntNum,\
                                                Cdd_Adc_IntTriggerType IntTrigger)
{
    uint32 base_addr = Base + ADC_O_INTSEL1N2 + (((uint8)IntNum >> 1U) * ADC_INTSELXNY_STEP);
    uint16 shiftval = ((uint8)IntNum & (uint16)0x1U) << 3U;

    /* Set the specified ADC interrupt source. */
    HWREGH(base_addr) = (HWREGH(base_addr) & ~(ADC_INTSEL1N2_INT1SEL_M << shiftval)) | \
                                                                                    ((uint8)IntTrigger << shiftval);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearInterruptFlag(uint32 Base,Cdd_Adc_IntNumType IntNum)
{
    /* Clear the specified interrupt */
    HWREGH(Base + ADC_O_INTFLGCLR) |= (1U << (uint8)IntNum);
}

static FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetIntOvfStatus(uint32 Base,Cdd_Adc_IntNumType IntNum)
{
    /* Get the specified ADC interrupt status */
    return (boolean)((HWREGH(Base + ADC_O_INTOVF)>>(uint8)IntNum) & ADC_INTOVF_ADCINT1);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearIntOvfStatus(uint32 Base,Cdd_Adc_IntNumType IntNum)
{
    /* Clear the specified interrupt overflow bit */
    HWREGH(Base + ADC_O_INTOVFCLR) |= (1U << (uint8)IntNum);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetInterruptCycleOffset(uint32 Base, uint16 CycleOffset)
{
    /* Set the position of the pulse.Set the position of the pulse */
    HWREGH(Base + ADC_O_INTCYCLE) = CycleOffset;
}

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_PpbOffsetCorrection(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 OffCal)
{
    /*Write the configuration to the register */
    HWREGH(Base + (ADC_PPBXOFFCAL_STEP * (uint32)PpbNumber) + ADC_O_PPB1OFFCAL) = OffCal;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbRefOffset(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 Offset)
{
    /* Write the offset amount */
    HWREGH(Base + (ADC_PPBXOFFREF_STEP * (uint32)PpbNumber) + ADC_O_PPB1OFFREF) = Offset;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigurePpbResult(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                            uint16 ResConfig)
{
    /* Get the offset to the appropriate offset register */
    uint32 ppboffset = Base + (ADC_PPBXCONFIG_STEP * (uint32)PpbNumber) + ADC_O_PPB1CONFIG;
    /* Enable/Disable PPB's two's complement */
    HWREGH(ppboffset)  = ( HWREGH(ppboffset) & ~ (ADC_PPB1CONFIG_DELTAEN | \
    ADC_PPB1CONFIG_TWOSCOMPEN | ADC_PPB1CONFIG_ABSEN | ADC_PPB1CONFIG_CBCEN | ADC_PPB1CONFIG_CONFIG_M)) | (ResConfig);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigurePpbHighLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                    sint32 LimitHigh)
{
    /*Configure the register with the limit value provided*/
    HWREG(Base + (ADC_PPBXTRIPHI_STEP * (uint32)PpbNumber) + ADC_O_PPB1TRIPHI) =  LimitHigh;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_EnablePpbExtendedLowLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /*Enable PPB extended trip low limit*/
    HWREG(Base + (ADC_PPBXTRIPLO_STEP * (uint32)PpbNumber) +  ADC_O_PPB1TRIPLO) |=  ADC_PPB1TRIPLO_LIMITLO2EN;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbExtendedLowLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                                        sint32 TripLowLimit)
{
    /*Configure the register with the limit value provided*/
    HWREG(Base + (ADC_PPBXTRIPLO2_STEP * (uint32)PpbNumber) + ADC_O_PPB1TRIPLO2) = TripLowLimit;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureTripFilter(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                        uint16 TripFilCfg)
{
    /* Configure digital trip filter */
    uint32 offset = Base + (ADC_PPBXTRIPFIL_STEP * (uint32)PpbNumber) +  ADC_O_PPBTRIP1FILCTL ;
    HWREGH(offset) =  (HWREGH(offset) & ~ (ADC_PPBTRIP1FILCTL_THRESH_M |\
            ADC_PPBTRIP1FILCTL_SAMPWIN_M | ADC_PPBTRIP1FILCTL_FILTLOEN | ADC_PPBTRIP1FILCTL_FILTHIEN)) | TripFilCfg;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_TripFilterInit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Enable/disable digital trip filter */
    uint32 offset = Base + (ADC_PPBXTRIPFIL_STEP * (uint32)PpbNumber) +  ADC_O_PPBTRIP1FILCTL ;
    HWREGH(offset) |= ADC_PPBTRIP1FILCTL_FILINIT;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetTripFilPrescale(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,\
                                                            uint16 ClkPrescale)
{
    /* Set trip filter sample clock prescale */
    HWREG(Base + (ADC_PPBXTRIPFILCLK_STEP * (uint32)PpbNumber) +  ADC_O_PPBTRIP1FILCLKCTL) = ClkPrescale;
}

static FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_GetPpbEvtStatus(uint32 Base)
{
    /* Get the event status for the specified post-processing block */
    return (HWREGH(Base + ADC_O_EVTSTAT));
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpbEvent(uint32 Base,Cdd_Adc_PpbIdType PpbNumber, uint16 EvtFlags,\
        boolean Mode)
{
    /* Confiure the specified event */
    HWREGH(Base + ADC_O_EVTSEL) = (HWREGH(Base + ADC_O_EVTSEL) & ~(ADC_PPBEVTMASK << ((uint16)PpbNumber * 4U))) | \
                                ((EvtFlags & ((uint16)Mode*ADC_PPBEVTMASK)) << ((uint16)PpbNumber * 4U));
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE)
Cdd_Adc_ConfigPpbEventInterrupt(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 IntFlags,boolean Mode)
{
    /* Enable the specified event interrupts */ 
    HWREGH(Base + ADC_O_EVTINTSEL) = (HWREGH(Base + ADC_O_EVTINTSEL) & ~(ADC_PPBEVTMASK<<((uint16)PpbNumber * 4U)))| \
                                        ((IntFlags & ((uint16)Mode*ADC_PPBEVTMASK)) << ((uint16)PpbNumber * 4U));
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetPpbCountLimit(uint32 Base,Cdd_Adc_PpbIdType PpbNumber, uint16 Limit)
{
    /* Set ppb count limit */
    HWREGH(Base + (ADC_PPBXLIMIT_STEP * (uint32)PpbNumber) + ADC_O_PPB1LIMIT) = Limit;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpb2(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint16 PpbCfg2)
{
    /* Get the offset to the appropriate delay */ 
    uint32 ppboffset = Base + (ADC_PPBXCONFIG2_STEP * (uint32)PpbNumber) + ADC_O_PPB1CONFIG2;

    /* Select sync input for the PPB */
    HWREGH(ppboffset) = (HWREGH(ppboffset) & ~(ADC_PPB1CONFIG2_COMPSEL_M | ADC_PPB1CONFIG2_SHIFT_M)) | (PpbCfg2);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForcePpbSync(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Force software sync for the PPB */
    HWREGH(Base + (ADC_PPBXCONFIG2_STEP * (uint32)PpbNumber) + ADC_O_PPB1CONFIG2) |= ADC_PPB1CONFIG2_SWSYNC;
}
#endif


#if(STD_ON == CDD_ADC_SAFETY_CHECK_API)

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureSafetyCheckerInput(uint32 Base,uint8 SocNum,\
                                                                Cdd_Adc_CheckerInputType ScInput)
{
    /* Calculate the SOC shift. */
    uint8 socshift = ((SocNum%16U) * 2U);
    uint32 offset = Base + (ADC_SAFECHECKRESEN_STEP*(SocNum/16U)) + ADC_O_SAFECHECKRESEN ; 
    /* Configure the Safety Checker Result mode */
    HWREG(offset) = (HWREG(offset) & ~(ADC_SAFECHECKRESEN_SOC0CHKEN_M << socshift)) | ((uint8)ScInput<<socshift);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureSafetyChecker(uint32 ScBase,uint8 CheckerResNum,\
            Cdd_Adc_HwUnitType Instance,uint8 ResultNum)
{
    uint32 offset = ScBase + ((ADC_O_RESSEL2 - ADC_O_RESSEL1) * CheckerResNum) + ADC_O_RESSEL1;
    /* Configure safety checker instance */
    HWREGH(offset) =(HWREGH(offset) & ~(ADC_RESSEL1_ADCSEL_M | ADC_RESSEL1_ADCRESULTSEL_M)) | \
                ((((uint8)Instance << ADC_RESSEL1_ADCSEL_S) | ((uint8)ResultNum << ADC_RESSEL1_ADCRESULTSEL_S)));        
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetSafetyCheckerTolerance(uint32 ScBase, uint32 Tolerance)
{
    /* Set safety checker tolerance */ 
    HWREG(ScBase + ADC_O_TOLERANCE) = Tolerance;
}

LOCAL_INLINE FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckStatus(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,\
                            Cdd_Adc_SafetyCheckFlagType CheckerFlag)
{
    /* Get the specified safety checker event status */
    return (boolean)((HWREG(Base + ADC_O_OOTFLG + (uint32)CheckerFlag)>>(uint32)CheckerNumber) & 1U);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearCheckEvtFlag(uint32 Base, Cdd_Adc_CheckerType CheckerNumber,\
                                        Cdd_Adc_SafetyCheckFlagType CheckerFlag)
{
    /* Clear the specified safety checker event status */
    HWREG(Base + ADC_O_OOTFLGCLR + (uint32)CheckerFlag) |= (1U << (uint8)CheckerNumber);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) 
Cdd_Adc_ClearCheckEvtStatus(uint32 Base,Cdd_Adc_SafetyCheckFlagType CheckerFlag,uint16 EvtMask)
{
    /* Clear the specified safety checker event status */
    HWREG(Base + ADC_O_OOTFLGCLR + (uint32)CheckerFlag) |= (uint32)(EvtMask);
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureCheckIntSrc(uint32 Base,\
        Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag,uint16 IntFlagMask,boolean Mode)
{
    uint32 offset = Base + ADC_O_CHECKINTSEL1 + (uint32)CheckerFlag;
    /* Configure the interrupt flags */
    HWREG(offset) =  (HWREG(offset) & ~(CHECKER_EVT_SEL_M)) | (Mode*IntFlagMask) ;                     
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearSafetyCheckIntStatus(uint32 Base)
{
    /* Clear the specified safety checker interrupt status */
    HWREGH(Base + ADC_O_CHECKINTFLGCLR) = 1U;
}

LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureCheckEvtSrc(uint32 Base,\
        Cdd_Adc_SafetyCheckEvtSrcType CheckerFlag,\
    uint8 CheckEvt,uint16 EvtFlagMask,boolean Mode)
{
    uint32 offset = Base +((ADC_O_CHECKEVT2SEL1-ADC_O_CHECKEVT1SEL1)*(uint32)CheckEvt) + ADC_O_CHECKEVT1SEL1 + \
                            (uint32)CheckerFlag;
    /* Clear the specified safety checker event status */
    HWREG(offset) = (HWREG(offset) & ~(CHECKER_EVT_SEL_M)) | ((uint32)Mode*EvtFlagMask) ;                             
}
#endif

#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigOSDetectMode(uint32 Base, Cdd_Adc_OsDetectModeType Mode)
{
    HWREGH(Base + ADC_O_OSDETECT) = (HWREGH(Base + ADC_O_OSDETECT) & ~(ADC_OSDETECT_DETECTCFG_M)) | (uint16)Mode;
}
#endif

#if(STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureTempSensor(boolean Mode)
{
    uint32 offset = ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL;
    /* Enable/Disable the temperature sensor */
    HWREG(offset) =  (HWREG(offset) & ~ASYSCTL_TSNSCTL_ENABLE) | (uint16)Mode;
}

LOCAL_INLINE FUNC(boolean,CDD_ADC_CODE) Cdd_Adc_GetTempSensorLockStatus(void)
{
    /* Enable/Disable the temperature sensor */
    return (boolean)(HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) & ASYSCTL_LOCK_TSNSCTL);
}
#endif

#if(STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)
LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_LockTempSensor(void)
{
    /* Enable/Disable the temperature sensor */
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_TSNSCTL;
}
#endif


LOCAL_INLINE FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigureConverter(uint32 Base, boolean Mode)
{
    HWREGH(Base + ADC_O_CTL1) = (HWREGH(Base + ADC_O_CTL1) & ~ADC_CTL1_ADCPWDNZ) | ((uint8)Mode << 7U);
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*
 *Design: MCAL-
 */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetMode(uint32 Base, Cdd_Adc_ResolutionType Resolution,\
                                        Cdd_Adc_SignalModeType SignalMode)
{
    HWREGH(Base + ADC_O_CTL2) = (HWREGH(Base + ADC_O_CTL2) & ~(ADC_CTL2_RESOLUTION | ADC_CTL2_SIGNALMODE)) | \
                            ((uint16)Resolution | (uint16)SignalMode);
    /* Apply INL and offset trims */
    Cdd_Adc_SetINLTrim(Base);
    Cdd_Adc_SetOffsetTrim(Base);
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_SelectInternalTestNode(Cdd_Adc_InternalTestNodeType TestNode)
{
    uint32 offset = ANALOGSUBSYS_BASE + ASYSCTL_O_INTERNALTESTCTL;
    HWREG(offset) = (HWREG(offset) & ~ASYSCTL_INTERNALTESTCTL_TESTSEL_M) |
                            (0xA5A5UL << ASYSCTL_INTERNALTESTCTL_KEY_S) |
                            ((uint32)TestNode << ASYSCTL_INTERNALTESTCTL_TESTSEL_S);
}

Cdd_Adc_TriggerType Cdd_Adc_ReadSocTrigSrc(uint32 Base,uint8 SocNum)
{
    return ((HWREG(Base + ADC_O_SOC0CTL + ((uint32)SocNum * ADC_SOCXCTL_STEP)) & ADC_SOC0CTL_TRIGSEL_M)>>20U);
}

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
/* 
 * PPB related function
 */

sint32 Cdd_Adc_ReadPpbResult(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1RESULT + ((uint32)PpbNumber * ADC_PPBXRESULT_STEP);
    /* Return the result of selected PPB */
    return (sint32)(HWREG(offset));
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearPpbEvtStatus(uint32 Base,Cdd_Adc_PpbIdType PpbNumber,uint8 TripEvtMask)
{
    /* Clear the specified event flags */
    HWREGH(Base + ADC_O_EVTCLR) |= (TripEvtMask << ((uint16)PpbNumber * 4U));
}

uint16 Cdd_Adc_GetPpbDelayTimeStamp(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Get the offset to the appropriate delay */ 
    uint32 ppboffset = Base + (ADC_PPBXSTAMP_STEP*(uint32)PpbNumber) + ADC_O_PPB1STAMP;
    /* Return the delay time stamp */ 
    return (HWREGH(ppboffset) & ADC_PPB2STAMP_DLYSTAMP_M);
}

/* Partial PPB register read */
uint16 Cdd_Adc_ReadPpbPCount(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = Base + ADC_O_PPBP1PCOUNT + ((uint32)PpbNumber * ADC_PPBXPCOUNT_STEP);
    /* Returns the partial count of the selected PPB */
    return (HWREGH(offset));
}

sint32 Cdd_Adc_ReadPpbPSum(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = Base + ADC_O_PPB1PSUM + ((uint32)PpbNumber * ADC_PPBXPSUM_STEP);
    /* Return the result of selected PPB */
    return ((sint32)HWREG(offset));
}

uint16 Cdd_Adc_ReadPpbPMaxIndex(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final maximum value of selected PPB */
    return (HWREGH(Base + ADC_O_PPB1PMAXI + ((uint32)PpbNumber * ADC_PPBXPMAXI_STEP)));
}

uint16 Cdd_Adc_ReadPpbPMinIndex(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final minimum value of the selected PPB */
    return (HWREGH(Base + ADC_O_PPB1PMINI + ((uint32)PpbNumber * ADC_PPBXPMINI_STEP)));
}

sint32 Cdd_Adc_ReadPpbPMax(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final maximum value of selected PPB */
    return ((sint32)HWREG(Base + ADC_O_PPB1PMAX + ((uint32)PpbNumber * ADC_PPBXPMAX_STEP)));
}

sint32 Cdd_Adc_ReadPpbPMin(uint32 Base,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final minimum value of selected PPB */
    return ((sint32)HWREG(Base + ADC_O_PPB1PMIN + ((uint32)PpbNumber * ADC_PPBXPMIN_STEP)));
}

sint32 Cdd_Adc_ReadPpbSum(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1SUM + ((uint32)PpbNumber * ADC_PPBXSUM_STEP);
    /* Return the result of selected PPB */
    return ((sint32)HWREG(offset));
}

sint32 Cdd_Adc_ReadPpbMax(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final maximum value of selected PPB */
    return ((sint32)HWREG(ResultBase + ADC_O_PPB1MAX + ((uint32)PpbNumber*ADC_PPBXMAX_STEP)));
}

sint32 Cdd_Adc_ReadPpbMin(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Return the final minimum value of selected PPB */
    return ((sint32)HWREG(ResultBase + ADC_O_PPB1MIN + ((uint32)PpbNumber*ADC_PPBXMIN_STEP)));
}

/* PPB register read */
uint16 Cdd_Adc_ReadPpbCount(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    uint32 offset = ResultBase + ADC_O_PPB1COUNT + ((uint32)PpbNumber * ADC_PPBXCOUNT_STEP);
    /* Returns the partial count of the selected PPB */
    return (HWREGH(offset));
}

uint16 Cdd_Adc_ReadPpbMaxIndex(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final maximum value of selected PPB */
    return (HWREGH(ResultBase + ADC_O_PPB1MAXI + ((uint32)PpbNumber * ADC_PPBXMAXI_STEP)));
}

uint16 Cdd_Adc_ReadPpbMinIndex(uint32 ResultBase,Cdd_Adc_PpbIdType PpbNumber)
{
    /* Returns the index of the final minimum value of the selected PPB */
    return (HWREGH(ResultBase + ADC_O_PPB1MINI + ((uint32)PpbNumber * ADC_PPBXMINI_STEP)));
}

#endif

#if(STD_ON == CDD_ADC_SAFETY_CHECK_API)
/*
 * Safety-checker functions
 */

FUNC(void,CDD_ADC_CODE)  Cdd_Adc_ConfigureCheckerTile(uint32 ScBase, boolean Mode)
{
    /* Enable the Saftey Checker module */
    HWREGH(ScBase + ADC_O_CHECKCONFIG) = (HWREGH(ScBase + ADC_O_CHECKCONFIG) & ~ ADC_CHECKCONFIG_CHKEN) | \
                                                                                        ((Mode << 15U));
}

boolean Cdd_Adc_GetCheckerStatus(uint32 ScBase)
{ 
    /* Return the Saftey Checker status */
    return (boolean)((HWREGH(ScBase + ADC_O_CHECKCONFIG) & ADC_CHECKCONFIG_CHKEN)>>15U);
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_ForceSafetyCheckerSync(uint32 ScBase)
{
    /* Force software sync for the safety checker module */
    HWREGH(ScBase + ADC_O_CHECKCONFIG) |= ADC_CHECKCONFIG_SWSYNC;
}

FUNC(uint16,CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckIntStatus(uint32 Base)
{
    /* Get the specified safety checker interrupt status */
    return (HWREGH(Base + ADC_O_CHECKINTFLG));
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_ClearCheckerStatus(Cdd_Adc_CheckerIntEvtType IntEvtId,\
                                                        Cdd_Adc_CheckerEventType Event_Id)
{
    uint32 intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].base_addr;
    /* Clear Safety checker flags that generated the interrupt*/
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_OOT_FLG,\
            Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].ootflg);
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_RES1OVF_FLG,\
                Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].res1ovf);
    Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_RES2OVF_FLG,\
                Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevt[Event_Id].res2ovf);
}

/* Stop the result checker unit */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopChecker(Cdd_Adc_CheckerType CheckerId)
{
    Cdd_Adc_CheckerIntEvtType intevt_id;
    uint8 checkernum = (Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].checker_id);
    /* Force Software sync */
    Cdd_Adc_ForceSafetyCheckerSync(Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].base_addr);
    /* Disable the safety checker unit */  
    Cdd_Adc_ConfigureCheckerTile(Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[CheckerId].base_addr,FALSE);
    /* Iterate through all the interrupt event blocks and then clear the corresponding safety checker flags */
    for(intevt_id = 0U; intevt_id < CDD_ADC_CHECKER_INTEVT_CNT;intevt_id++)
    {
        uint32 intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id].base_addr;
        /* Clear all the flags */
        Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_OOT_FLG,(1U<<checkernum));
        Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_RES1OVF_FLG,(1U<<checkernum));
        Cdd_Adc_ClearCheckEvtStatus(intevt_baseaddr,CDD_ADC_SAFETY_CHECK_RES2OVF_FLG,(1U<<checkernum));
    }
}
#endif

FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetDrvObj(Cdd_Adc_DriverObjType *DrvObj,const Cdd_Adc_ConfigType *CfgPtr)
{
    /* Set the global driver object pointer */
    Cdd_Adc_DrvObjPtr = DrvObj;
    /* Initialize Ppb config array */
    Cdd_Adc_ConfigPtr = CfgPtr;
}

/* Reset the driver object to the power on reset mode */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_DrvObjInit(void)
{
    Cdd_Adc_GroupType grp_id;
#if(STD_ON == CDD_ADC_SET_RESOLUTION_API)
    uint8 hwunit_id;
#endif
#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
    Cdd_Adc_GlbTrigType glbswid;
#endif
    for (grp_id = 0U; grp_id < CDD_ADC_GROUP_CNT; grp_id++)
    {
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].grp_status        = CDD_ADC_IDLE;
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].cur_resultptr     = NULL_PTR;
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].resbuffer         = NULL_PTR;
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].implicit_stop     = FALSE;
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].grp_notification  = FALSE;
#endif
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].triggersrc  = CDD_ADC_GRP_TRIGG_SRC_SW;
        Cdd_Adc_DrvObjPtr->group_obj[grp_id].valid_samples = 0U;
    }
#if(STD_ON == CDD_ADC_SET_RESOLUTION_API)
    for(hwunit_id=0U;hwunit_id < CDD_ADC_HW_CNT;hwunit_id++)
    {
        Cdd_Adc_DrvObjPtr->hwunit_obj[hwunit_id].cur_resolution = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id].resolution;
    }
#endif
#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
    for(glbswid=0U;glbswid < CDD_ADC_GLBSW_TRIG_CNT;glbswid++)
    {
        Cdd_Adc_DrvObjPtr->glbsw_obj[glbswid].status = FALSE;
    }
#endif
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_HwUnitInit(void)
{
    /* Initialize each HW instance */ 
    uint8 hwunit_id,channel_num;
    Cdd_Adc_GroupType group_id;
    uint32 base_addr;
    Cdd_Adc_HwUnitCfgType hwunitcfg;
    Cdd_Adc_GroupCfgType group_cfg;
    uint8 internal_vref = 0U;

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
    Cdd_Adc_PpbType ppb_id;
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
    uint8 evtid;
    Cdd_Adc_CheckerType checkerid;
    Cdd_Adc_CheckerIntEvtType intevt_id;
    Cdd_Adc_CheckerResCfgType checkerunit_cfg;
    Cdd_Adc_CheckerIntEvtCfgType intevt_cfg;
#endif

#if(STD_ON == CDD_ADC_TRIG_REP_ENABLE)
    uint8 trigrep_id;
#endif

    Cdd_Adc_SelectInternalTestNode(Cdd_Adc_ConfigPtr->test_input);

#if(STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE) 
    if(Cdd_Adc_GetTempSensorLockStatus() == 0U)
    {
        Cdd_Adc_ConfigureTempSensor(TRUE);
#if(STD_ON == CDD_ADC_LOCK_TEMPERATURE_SENSOR)
        Cdd_Adc_LockTempSensor();
#endif
    }
    else
    {
        /* Do nothing */
    }
#endif

    /* Iterate through each ADC HW Instances */
    for(hwunit_id=0U;hwunit_id < CDD_ADC_HW_CNT;hwunit_id++)
    {
        /* Assign base address,result address based on the ADC Instance Specified*/
        hwunitcfg = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id];

        /* Set the Prescaler for ADC HW unit. */
        Cdd_Adc_SetPrescaler(hwunitcfg.base_addr, hwunitcfg.prescale);
        /* Set the resolution and signal mode */
        Cdd_Adc_SetMode(hwunitcfg.base_addr,hwunitcfg.resolution,hwunitcfg.signal_mode);
        /* Set voltage reference mode and voltage reference*/
        Cdd_Adc_SetVREF(hwunitcfg.base_addr,hwunitcfg.voltrefmode, hwunitcfg.voltref);
        /* Enable ADC converter */
        Cdd_Adc_ConfigureConverter(hwunitcfg.base_addr,TRUE);
        /* Configure the interrput pulse mode */
        Cdd_Adc_SetIntPulseMode(hwunitcfg.base_addr,hwunitcfg.intpulsemode);
        /* Configure the interrupt offset */
        Cdd_Adc_SetInterruptCycleOffset(hwunitcfg.base_addr,hwunitcfg.intoffset);
        internal_vref = (hwunitcfg.voltrefmode == CDD_ADC_REFERENCE_INTERNAL)?(internal_vref+1U):(internal_vref);
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
        /* Set Opens/Shorts dectection circuit mode */
        Cdd_Adc_ConfigOSDetectMode(hwunitcfg.base_addr,hwunitcfg.osdetectmode);
#endif
        /* Set SOC Priority mode for each hardware unit*/
        Cdd_Adc_SetSocPriority(hwunitcfg.base_addr,hwunitcfg.socpriority);

        /* Configure external mux preselect configuration */
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)        
        if(hwunitcfg.extmuxpreselect != 0U)
        {
            /* Enable external mux preselect mode */
            Cdd_Adc_ConfigureExtMuxPreselect(hwunitcfg.base_addr,TRUE);
        }
        else
        {
            /* Don't configure ExtMuxPreselect mode if not enabled */
        }
#endif
    }

    /* only one delay is necessary as long as the delay occurs after all the ADCs have begun powering up */
    if(internal_vref == 0U)
    {   
        /* When all the hardware instances are configured in external reference mode */
        McalLib_Delay(24997);   /* Allow 500us(0.5ms) delay for the ADC converter power-up */
    }
    else
    {
        /* When atleast one of the hardware instances is configured in internal reference mode */
        McalLib_Delay(249970);  /* Allow 5000us(5ms) delay for the ADC converter power-up */
    }

    for(group_id=0U; group_id < CDD_ADC_GROUP_CNT; group_id++)
    {
        group_cfg = Cdd_Adc_ConfigPtr->groupcfg[group_id];
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(group_cfg.hwunit_index)].base_addr;

        /* All modes except one shot software trigger and linear streaming needs to be stopped explicitly */
        if(((group_cfg.trigsrc_type==CDD_ADC_TRIGG_SRC_SW) && (CDD_ADC_CONV_MODE_ONESHOT==group_cfg.conversion_mode))\
         || ((CDD_ADC_ACCESS_MODE_STREAMING == group_cfg.access_mode) && \
                    (CDD_ADC_STREAM_BUFFER_LINEAR == group_cfg.streambuffermode)))
        {
            Cdd_Adc_DrvObjPtr->group_obj[group_id].implicit_stop = TRUE;
        }
        else
        {
            Cdd_Adc_DrvObjPtr->group_obj[group_id].implicit_stop = FALSE;
        }

        /* Assign the SOC number to the interrupt. */
        Cdd_Adc_SetIntSource(base_addr,group_cfg.grp_int,group_cfg.lastsocnum);

        for(channel_num=group_cfg.startchannelnum;
            ((channel_num<(group_cfg.channelcount+group_cfg.startchannelnum)) && (channel_num < CDD_ADC_CHN_COUNT));\
                channel_num++)
        {
        #if(CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            if(Cdd_Adc_ConfigPtr->hwunitcfg[group_cfg.hwunit_index].extchnsel != 0U)
            {
                /* Configure the external channel */
                Cdd_Adc_SelSocExtChn(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channel_num].soc_num,\
                        Cdd_Adc_ConfigPtr->channelcfg[channel_num].extchannelnum);
            }
            else
            {
                /* Do nothing */
            }
        #endif
            /* Assign the soc number to the channel and configure the SOC.*/
            Cdd_Adc_SetupSoc(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channel_num].soc_num,CDD_ADC_TRIGGER_SW_ONLY,\
                                                        Cdd_Adc_ConfigPtr->channelcfg[channel_num].channel_id,\
                                                        Cdd_Adc_ConfigPtr->channelcfg[channel_num].sample_window);
        }      
    }

/* When safety checker API is ON then initialize the safety checker */
#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

    for(checkerid=0U;checkerid < CDD_ADC_CHECKER_CNT;checkerid++)
    {
        checkerunit_cfg = Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checkerid];
        uint8 res_num=0U;
        for(res_num=0U;res_num<2U;res_num++)
        {
            Cdd_Adc_HwUnitCfgType hwunit_cfg = \
                                    Cdd_Adc_ConfigPtr->hwunitcfg[(checkerunit_cfg.selresult[res_num].hwunit_index)];
            /* Configure Safety checker input */
            Cdd_Adc_ConfigureSafetyCheckerInput(hwunit_cfg.base_addr,checkerunit_cfg.selresult[res_num].soc_num,\
                        checkerunit_cfg.selresult[res_num].res_type);
            /* Configure Safety checker */
            Cdd_Adc_ConfigureSafetyChecker(checkerunit_cfg.base_addr,res_num,\
                        hwunit_cfg.hwunit_id,checkerunit_cfg.selresult[res_num].res_num);
        }
        /* Set the tolerance of the result checker.*/
        Cdd_Adc_SetSafetyCheckerTolerance(checkerunit_cfg.base_addr,checkerunit_cfg.tolerance);
    }

    for(intevt_id=0U;intevt_id<CDD_ADC_CHECKER_INTEVT_CNT;intevt_id++)
    {
        intevt_cfg = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id];

        /* Enable interrupt event source flags */
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_RES1OVF,\
                                    intevt_cfg.checkevtint.res1ovf,TRUE);
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_RES2OVF,\
                                    intevt_cfg.checkevtint.res2ovf,TRUE);
        Cdd_Adc_ConfigureCheckIntSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_OOT,\
                                    intevt_cfg.checkevtint.ootflg,TRUE);

        for(evtid=0U;evtid<CDD_ADC_CHECKER_EVT_CNT;evtid++)
        {
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_RES1OVF,evtid,\
                            intevt_cfg.checkevt[evtid].res1ovf,TRUE);
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_RES2OVF,evtid,\
                            intevt_cfg.checkevt[evtid].res2ovf,TRUE);
            Cdd_Adc_ConfigureCheckEvtSrc(intevt_cfg.base_addr,CDD_ADC_SAFETY_CHECK_OOT,evtid,\
                            intevt_cfg.checkevt[evtid].ootflg,TRUE);
        }
    }

#endif /* #if (STD_ON == CDD_ADC_SAFETY_CHECK_API) */

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    /* Configure the PPB units */
    for(ppb_id=0U;ppb_id < CDD_ADC_PPB_CNT;ppb_id++)
    {
        Cdd_Adc_ConfigPpbUnit(ppb_id);
    }
#endif

#if(STD_ON == CDD_ADC_TRIG_REP_ENABLE)
    for(trigrep_id=0U;trigrep_id<CDD_ADC_TRIG_REP_CNT;trigrep_id++)
    {
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].hwunit_index)].base_addr;
        Cdd_Adc_ForceRepeaterTriggerSync(base_addr,Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance);
        Cdd_Adc_ClearTriggerOvf(base_addr,Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance);
        Cdd_Adc_ClearPhaseOvf(base_addr,Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance);
        Cdd_Adc_SelTrigRepTrigger(base_addr, Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance,\
                        Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].trigger_source);
        Cdd_Adc_SetTrigRepMode(base_addr, Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance,\
                        Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_mode);
        Cdd_Adc_SetTrigRepCount(base_addr, Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance,\
                        Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_count);
        Cdd_Adc_SetTrigRepPhase(base_addr, Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance,
                        Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_phase);
        Cdd_Adc_SetTrigRepSpread(base_addr, Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_instance,\
                        Cdd_Adc_ConfigPtr->repunitcfg[trigrep_id].repeater_spread);
    }
#endif

}

#if (STD_ON == CDD_ADC_DEINIT_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_HwUnitDeinit(void)
{
    /* De-Init the HW instance */
    uint8 hwunit_id;
    Cdd_Adc_GroupType group_id;
    uint32 base_addr;

#if(STD_ON == CDD_ADC_SAFETY_CHECK_API)
    uint8 checker_id;
    Cdd_Adc_CheckerIntEvtType intevt_id;
    uint32 checker_baseaddr;
#endif
    
#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
    Cdd_Adc_GlbTrigType glbswid;
#endif

    for(hwunit_id=0U;hwunit_id < CDD_ADC_HW_CNT;hwunit_id++)
    {
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_id].base_addr;
        /* Disable all the ADC Hardware unit converters */
        Cdd_Adc_ConfigureConverter(base_addr,FALSE);
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
        /* Disable Opens/Shorts dectection circuit mode */
        Cdd_Adc_ConfigOSDetectMode(base_addr,CDD_ADC_OSDETECT_MODE_DISABLED);
#endif
    }

    for(group_id=0U;group_id < CDD_ADC_GROUP_CNT;group_id++)
    {
        if((Cdd_Adc_DrvObjPtr->group_obj[group_id].valid_samples == 0U) && \
                (Cdd_Adc_DrvObjPtr->group_obj[group_id].grp_status == CDD_ADC_IDLE))
        {
            /* Nothing to be done if the group conversion has already stopped before calling DeInit API. */
        }
        else
        {
            /* Stop the group conversion if the group conversion hasnot already stopped before calling DeInit API. */
            Cdd_Adc_StopGroup(group_id);
        }
    }

#if(STD_ON == CDD_ADC_SAFETY_CHECK_API) 
    /* Disable safety checker tiles */
    for(checker_id=0U;checker_id < CDD_ADC_CHECKER_CNT;checker_id++)
    {
        checker_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checker_id].base_addr;
        if(Cdd_Adc_GetCheckerStatus(checker_baseaddr) == TRUE)
        {
            Cdd_Adc_StopChecker(checker_id);
        }
        else
        {
            /* If the safety checker has already stopped them it can be ignored */
        }
    }

    /* Clear all safety checker interrupts */
    for(intevt_id=0U;intevt_id<CDD_ADC_CHECKER_INTEVT_CNT;intevt_id++)
    {
        uint32 intevt_baseaddr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[intevt_id].base_addr;
        /* Clear safety checker interrupt flag */
        Cdd_Adc_ClearSafetyCheckIntStatus(intevt_baseaddr);
    }
#endif

#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
    /* Disable global software trigger */
    Cdd_Adc_GlobalSwTrigger(0U);
    Cdd_Adc_SocGlobalSwTrigger(0U);
    for(glbswid=0U;glbswid < CDD_ADC_GLBSW_TRIG_CNT;glbswid++)
    {
        Cdd_Adc_DrvObjPtr->glbsw_obj[glbswid].status = FALSE;
    }
#endif  

#if(STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE) 
    if(Cdd_Adc_GetTempSensorLockStatus() == 0U)
    {
        Cdd_Adc_ConfigureTempSensor(FALSE);   /* Disable temperature sensor if not locked. */
    }
    else
    {
        /* Do nothing if the temperature sensor is locked */
    }
#endif
    Cdd_Adc_SelectInternalTestNode(CDD_ADC_TEST_NODE_NO_CONN);
}
#endif

/* start the requested group conversion */
FUNC(void,CDD_ADC_CODE) Cdd_Adc_StartGroup(Cdd_Adc_GroupType Group)
{
    /* Configure group */
    Cdd_Adc_SetGroup(Group);

    /* Start Group trigger */
    Cdd_Adc_SetGrpTrigger(Group);
}

FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopGroup(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupCfgType groupcfg = Cdd_Adc_ConfigPtr->groupcfg[Group];
    uint8 hwunitindex = Cdd_Adc_ConfigPtr->groupcfg[Group].hwunit_index;
    uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].base_addr;
#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
    Cdd_Adc_PpbType ppb_num,lastppbnum;
#endif

    /* Disable the corresponding interrupt for software triggered groups */
    Cdd_Adc_ConfigureInterrupt(base_addr,groupcfg.grp_int,FALSE);
    Cdd_Adc_ConfigureContinueToIntMode(base_addr,groupcfg.grp_int,FALSE);

    /* Set the group status to Idle */
    Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_IDLE;
    /* Set the group active status to FALSE */
    Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples = 0U;

#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
    /* Disable group notification */
    Cdd_Adc_DrvObjPtr->group_obj[Group].grp_notification = FALSE;
#endif

    /* Disable trigger sources and interrupt trigger source */
    if((groupcfg.trigsrc_type == CDD_ADC_TRIGG_SRC_HW) && \
    (((Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == TRUE) && \
    (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == Cdd_Adc_ConfigPtr->groupcfg[Group].stream_numsamples)) || \
        (Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status == CDD_ADC_IDLE)))
    {
        /* The trigger and interrupt is already disabled for implicitly stopped hardware group 
            when the buffer is completely filled or the groups that were already in IDLE state*/
    }
    else if(groupcfg.trigsrc_type == CDD_ADC_TRIGG_SRC_HW)
    {
        /* Disable trigger and interrupt for explicitly stopped hardware triggered groups */
        Cdd_Adc_StopHwGrpTrigger(Group);
    }
    else
    {
        /* Do nothing */
    }

    Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

    lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].ppbcount + \
                     Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum);
    for(ppb_num=Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum; \
                    ((ppb_num < lastppbnum) && (ppb_num < CDD_ADC_PPB_CNT)) ;ppb_num++)
    {
        if(((1U<<Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].soc_num) & groupcfg.soc_mask) != 0U)
        {
            /* If any PPB is configured for the channel */
            Cdd_Adc_ForcePpbSync(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id);
            Cdd_Adc_ConfigPpbEvent(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,\
                                        Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtsel,FALSE);
            Cdd_Adc_ConfigPpbEventInterrupt(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,\
                                Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtintsel,FALSE);
            /* Clear all the PPB event flags */
            Cdd_Adc_ClearPpbEvtStatus(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,(uint8)ADC_PPBEVTMASK);      
            if(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripfilterenable == TRUE)
            {
                Cdd_Adc_TripFilterInit(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id);
            }
            else
            {
                /* Don't configure trip filter if not enabled */
            }
        }
        else
        {
            /* Skip if no PPB is configured for the channel */
        }
    }
#endif   
}

#if(STD_ON == CDD_ADC_GLBSW_TRIG_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_StartGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig)
{
    Cdd_Adc_GlbSwCfgType glbsw = Cdd_Adc_ConfigPtr->glbtrigcfg[GlbSwTrig];
    uint16 groupmask;
    Cdd_Adc_GroupType group = 0U;

    for(groupmask = glbsw.group_mask;((groupmask > 0U) && (group < CDD_ADC_GROUP_CNT));(groupmask = groupmask>>1U))
    {
        /* Check if the group is configured for the specified global software trigger */
        if((groupmask & 1U) != 0U)
        {
            Cdd_Adc_DrvObjPtr->group_obj[group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_GLBSW;
            Cdd_Adc_SetGroup(group);
        }
        else
        {
            /* Skip if the group is not configured for the specified global software trigger */
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

FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig)
{
    Cdd_Adc_GlbSwCfgType glbsw = Cdd_Adc_ConfigPtr->glbtrigcfg[GlbSwTrig];
    uint16 groupmask;
    Cdd_Adc_GroupType group = 0U;
    /* If any of the group SOC is pending then trigger is ignored so report an error that ADC is busy. */
    for(groupmask = glbsw.group_mask;((groupmask > 0U) && (group < CDD_ADC_GROUP_CNT));(groupmask = groupmask>>1U))
    {
        if((groupmask & 1U) != 0U)
        {
            Cdd_Adc_DrvObjPtr->group_obj[group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;
            Cdd_Adc_StopGroup(group);
        }
        else
        {
            /* Do nothing */
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
FUNC(void,CDD_ADC_CODE) Cdd_Adc_PpbEvtIsr(Cdd_Adc_HwUnitType HwUnitId)
{
    Cdd_Adc_PpbType ppb_num;
    uint8 hwunit_index;
    uint16 evtintstat;
    uint32 base_addr;

    for(hwunit_index = 0U;hwunit_index<CDD_ADC_HW_CNT;hwunit_index++)
    {
        if(Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].hwunit_id == HwUnitId)
        {
            break;
        }
        else
        {
            /* Skip to the next hardware unit */
        }
    }

    if(hwunit_index != CDD_ADC_HW_CNT)
    {
        base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].base_addr;
        evtintstat = Cdd_Adc_GetPpbEvtStatus(base_addr);
        /* Last PPB number */
        Cdd_Adc_PpbType lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].ppbcount + \
                                    Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].startppbnum);
        for(ppb_num = Cdd_Adc_ConfigPtr->hwunitcfg[hwunit_index].startppbnum;\
                            ((ppb_num < lastppbnum) && (ppb_num < CDD_ADC_PPB_CNT)) ;ppb_num++)
        {
            if(((evtintstat>>(((uint8)Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id) * 4U)) & \
                        Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtintsel) != 0U)
            {
                /* Clear the flags that triggered the interrupt */
                Cdd_Adc_ClearPpbEvtStatus(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,\
                                            Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtintsel);
            #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
                /* Call notification function if exists*/
                if(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppbevtint_notification != NULL_PTR)
                {
                    Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppbevtint_notification();
                }
                else
                {
                    /* When no notification function  pointer is available */
                }
            #endif
            }
        }
    }
    else
    {
        /* Hwunit ID isn't matching with any ADC hardware units */
    }
}
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_CheckerIsr(Cdd_Adc_CheckerIntEvtType IntEvtId,Cdd_Adc_CheckFlagStatusType *FlagStatus)
{
    Cdd_Adc_CheckerType checker_id,checker_number;
    uint32 base_addr = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].base_addr;
    Cdd_Adc_IntSrcType checkerevtint = Cdd_Adc_ConfigPtr->checkercfg.checkerintevtcfg[IntEvtId].checkevtint;
    for(checker_number=0U;checker_number<CDD_ADC_CHECKER_CNT;checker_number++)
    {
        checker_id = Cdd_Adc_ConfigPtr->checkercfg.checkerunitcfg[checker_number].checker_id;
        /* Check if the interrupt source is configured for the specified safety checker */
        if((boolean)(Cdd_Adc_GetSafetyCheckStatus(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_OOT_FLG) && \
                        ((checkerevtint.ootflg>>checker_id) & 1U)) == TRUE)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_OOT_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_OOT_FLG);
        }
        else if((boolean)(Cdd_Adc_GetSafetyCheckStatus(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_RES1OVF_FLG) && \
                        ((checkerevtint.res1ovf>>checker_id) & 1U)) == TRUE)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_RES1OVF_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_RES1OVF_FLG);
        }
        else if((boolean)(Cdd_Adc_GetSafetyCheckStatus(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_RES2OVF_FLG) &&\
                        ((checkerevtint.res2ovf>>checker_id) & 1U)) == TRUE)
        {
            FlagStatus[checker_number] = CDD_ADC_SAFETY_CHECKER_RES2OVF_FLG;
            Cdd_Adc_ClearCheckEvtFlag(base_addr,checker_id,CDD_ADC_SAFETY_CHECK_RES2OVF_FLG);
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

FUNC(void,CDD_ADC_CODE) Cdd_Adc_ProcessIsr(Cdd_Adc_IntNumType IntNum,Cdd_Adc_HwUnitType HwUnitId)
{
    uint8 hw_id;
    Cdd_Adc_GroupType group_id = 0U;

    for(hw_id = 0U;hw_id<CDD_ADC_HW_CNT;hw_id++)
    {
        if(Cdd_Adc_ConfigPtr->hwunitcfg[hw_id].hwunit_id == HwUnitId)
        {
            break;
        }
        else
        {
            /* Skip to the next hardware unit */
        }
    }

    if(hw_id != CDD_ADC_HW_CNT)
    {
        for(group_id = Cdd_Adc_ConfigPtr->hwunitcfg[hw_id].startgroupnum;\
            ((group_id <= Cdd_Adc_ConfigPtr->hwunitcfg[hw_id].lastgroupnum) && (group_id < CDD_ADC_GROUP_CNT));\
                    group_id++)
        {
            if(Cdd_Adc_ConfigPtr->groupcfg[group_id].grp_int == IntNum)
            {
                break;
            }
            else
            {
                /* Check others groups if the hardware unit is matching*/
            }
        }
        
        if(group_id > Cdd_Adc_ConfigPtr->hwunitcfg[hw_id].lastgroupnum)
        {
            /* Do nothing if the group couldn't be found */
        }
        else
        {
            /* Process the group */
            Cdd_Adc_ProcessGroup(group_id);
        }
    }
    else
    {
        /* Do nothing if the hardware unit is not found */
    }
}

#if (STD_ON == CDD_ADC_READ_GROUP_API)
FUNC(void,CDD_ADC_CODE) Cdd_Adc_ReadGroupResult(Cdd_Adc_GroupType Group,Cdd_Adc_ValueGroupType *DataPtr)
{
    uint8 channelnum;
    /* Copying the results from the result buffer to read group buffer*/
    for (channelnum=0U;channelnum < Cdd_Adc_ConfigPtr->groupcfg[Group].channelcount;channelnum++)
    {
        *(DataPtr + channelnum) = *(Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr + \
                                    (channelnum*Cdd_Adc_ConfigPtr->groupcfg[Group].stream_numsamples));
    }
    Cdd_Adc_UpdateGroupStatus(Group);
}
#endif

Cdd_Adc_StreamNumSampleType Cdd_Adc_GetValidSampleCnt(Cdd_Adc_GroupType Group,Cdd_Adc_ValueGroupType **PtrToSamplePtr)
{
    Cdd_Adc_StreamNumSampleType num_samples = Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples;
    /* This shall set the pointer, passed as parameter (PtrToSamplePtr) to point in the ADC result buffer 
     * to the latest result of the first group channel of the last completed conversion round.
     */
    /* Assign the pointer to the result buffer based on the number of valid samples count*/
    *PtrToSamplePtr =  (Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr);
    Cdd_Adc_UpdateGroupStatus(Group);
    /* Return the number of valid samples count */
    return num_samples;
}


#define CDD_ADC_STOP_SEC_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetOffsetTrim(uint32 Base)
{
   /*
    * Selecting the individual offset trim mode wherein offset trim will be
    * supplied from individual registers already programmed by device_cal api.
    */
    Cdd_Adc_SelectOffsetTrimMode(Base, CDD_ADC_OFFSET_TRIM_INDIVIDUAL);
}


static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetVREF(uint32 Base, Cdd_Adc_RefModeType RefMode,\
                                            Cdd_Adc_RefVoltType RefVoltage)
{
   uint32 analogrefsel,analogrefvoltsel;
   uint32 analogrefctl_addr  =  (ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL);
   
   switch (Base)
   {
        case ADCA_BASE:
            analogrefsel = ASYSCTL_ANAREFCTL_ANAREFABSEL;  /* Select Analog Reference Select for ADC A & B */
            analogrefvoltsel = ASYSCTL_ANAREFCTL_ANAREF1_2P5SEL; /* Select Analog Voltage Reference for ADC A & B */
            break;
        case ADCB_BASE:
            analogrefsel = ASYSCTL_ANAREFCTL_ANAREFABSEL;  /* Select Analog Reference Select for ADC A & B */
            analogrefvoltsel = ASYSCTL_ANAREFCTL_ANAREF1_2P5SEL; /* Select Analog Voltage Reference for ADC A & B */
            break;
        case ADCC_BASE:  
            analogrefsel = ASYSCTL_ANAREFCTL_ANAREFCDESEL;  /* Select Analog Reference Select for ADC C,D & E */
            analogrefvoltsel = ASYSCTL_ANAREFCTL_ANAREF2_2P5SEL; /*Select Analog Voltage Reference for ADC C,D & E*/ 
            break;
        case ADCD_BASE:  
            analogrefsel = ASYSCTL_ANAREFCTL_ANAREFCDESEL;  /* Select Analog Reference Select for ADC C,D & E */
            analogrefvoltsel = ASYSCTL_ANAREFCTL_ANAREF2_2P5SEL; /*Select Analog Voltage Reference for ADC C,D & E*/ 
            break;
        case ADCE_BASE:
            analogrefsel = ASYSCTL_ANAREFCTL_ANAREFCDESEL;  /* Select Analog Reference Select for ADC C,D & E */
            analogrefvoltsel = ASYSCTL_ANAREFCTL_ANAREF2_2P5SEL; /*Select Analog Voltage Reference for ADC C,D & E*/ 
            break;
        default:
            /* By default configure all the ADCs with the same configuration  */
            analogrefsel = (ASYSCTL_ANAREFCTL_ANAREFABSEL | ASYSCTL_ANAREFCTL_ANAREFCDESEL); 
            analogrefvoltsel = (ASYSCTL_ANAREFCTL_ANAREF1_2P5SEL | ASYSCTL_ANAREFCTL_ANAREF2_2P5SEL);
            break;
   } 
   /* Configure the reference mode (internal or external) */
   if(RefMode == CDD_ADC_REFERENCE_INTERNAL)
   {
       HWREG(analogrefctl_addr) &= ~(analogrefsel);
        if(RefVoltage == CDD_ADC_REFERENCE_3_3V)
        {
            /* Configure the reference voltage 3.3V */
            HWREG(analogrefctl_addr) &= ~(analogrefvoltsel);
        }
        else
        {
            /* configure the reference voltage 2.5V */
            HWREG(analogrefctl_addr) |=(analogrefvoltsel);
        }
   }
   else
   {
       HWREG(analogrefctl_addr) |= (analogrefsel);
   }
}

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetINLTrim(uint32 Base)
{
    uint16 i;
    uint32 * inlTrimAddress;
    uint32 numAdcInlTrim;
    Cdd_Adc_ResolutionType resolution = (HWREGH(Base + ADC_O_CTL2) & ADC_CTL2_RESOLUTION);

    switch(Base)
    {
        case ADCA_BASE:
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcAInlTrim[0U];
            numAdcInlTrim  = 6U;
            break;
        case ADCB_BASE:
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcBInlTrim[0U];
            numAdcInlTrim  = 6U;
            break;
        case ADCC_BASE:
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcCInlTrim[0U];
            numAdcInlTrim  = 3U;
            break;
        case ADCD_BASE:
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcDInlTrim[0U];
            numAdcInlTrim  = 3U;
            break;
        case ADCE_BASE:
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcEInlTrim[0U];
            numAdcInlTrim  = 3U;
            break;
        default:
            /* Invalid base address */
            inlTrimAddress = (uint32*)&McalLib_DeviceCalibrationData.AdcAInlTrim[0U];
            numAdcInlTrim  = 6U;
            break;
    }

    /* Update INL trim values to ADC trim registers */

    for(i = 0U; i < numAdcInlTrim; i++)
    {
        HWREG(Base + ADC_O_INLTRIM1 + (i * 4U)) = (*inlTrimAddress++);
    }

    /* Apply linearity trim workaround for 12-bit resolution */
    if(resolution == CDD_ADC_RESOLUTION_12BIT)
    {
        /* 12-bit linearity trim workaround */
        HWREG(Base + ADC_O_INLTRIM1) &= 0xFFFF0000U;
        HWREG(Base + ADC_O_INLTRIM2) &= 0xFFFF0000U;
        HWREG(Base + ADC_O_INLTRIM4) &= 0xFFFF0000U;
        HWREG(Base + ADC_O_INLTRIM5) &= 0xFFFF0000U;
    }
    else
    {
        /* Do nothing */
    }
}

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_ConfigPpbUnit(Cdd_Adc_PpbType PpbId)
{
    uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(Cdd_Adc_ConfigPtr->ppbcfg[PpbId].hwunitindex)].base_addr;
    Cdd_Adc_PpbIdType ppbid = Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppb_id;
    /* PPB offset configuration */
    Cdd_Adc_ForcePpbSync(base_addr,ppbid);
    /* Set the calibration offset for the hardware unit */
    Cdd_Adc_PpbOffsetCorrection(base_addr,ppbid,\
                                    Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppb_caloffset);
    /* Set the reference offset for the hardware unit */
    Cdd_Adc_SetPpbRefOffset(base_addr,ppbid,\
                                    Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppb_refoffset);
    /* PPB result configuration */
    Cdd_Adc_ConfigurePpbResult(base_addr,ppbid,\
                        (Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppbresconfig | Cdd_Adc_ConfigPtr->ppbcfg[PpbId].soc_num));
    /* PPB trip high configuration */
    Cdd_Adc_ConfigurePpbHighLimit(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].triplimithi);
    /* Enable extended trip low limit */
    Cdd_Adc_EnablePpbExtendedLowLimit(base_addr,ppbid);
    /* Set trip limit low2 enable */
    Cdd_Adc_SetPpbExtendedLowLimit(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].triplimitlow);
    /* Configure PPB2 */
    Cdd_Adc_ConfigPpb2(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppbcfg2);
    /* Set PPB count limit */
    Cdd_Adc_SetPpbCountLimit(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].ppbcountlimit);
    /* PPB trip filter settings */
    if(Cdd_Adc_ConfigPtr->ppbcfg[PpbId].tripfilterenable == TRUE)
    {
        Cdd_Adc_SetTripFilPrescale(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].tripfilclk);
        Cdd_Adc_ConfigureTripFilter(base_addr,ppbid,Cdd_Adc_ConfigPtr->ppbcfg[PpbId].tripfilctl);
    }
    else
    {
        /* Don't configure trip filter if not enabled */
    }
}
#endif

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetGrpTrigger(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupCfgType group_cfg = Cdd_Adc_ConfigPtr->groupcfg[Group];
    uint8 channel_id;
    uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(group_cfg.hwunit_index)].base_addr;

    if(group_cfg.trigsrc_type == CDD_ADC_TRIGG_SRC_HW)
    {
        Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_HW;
       /* Enable trigger sources for hardware trigger groups */
        for(channel_id = group_cfg.startchannelnum; \
            ((channel_id < (group_cfg.channelcount+group_cfg.startchannelnum) && (channel_id < CDD_ADC_CHN_COUNT)));\
                channel_id++)
        {
            /* Assign the soc number to the channel and configure the SOC */
            Cdd_Adc_SetupSoc(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channel_id].soc_num,group_cfg.trigger_src,\
                            Cdd_Adc_ConfigPtr->channelcfg[channel_id].channel_id,
                            Cdd_Adc_ConfigPtr->channelcfg[channel_id].sample_window);
            if(group_cfg.intsocsel != CDD_ADC_INT_SOC_TRIGGER_NONE)
            {
                /* Set the interrupt trigger source */
                Cdd_Adc_SetIntSocTrigger(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channel_id].soc_num,\
                                                                                        group_cfg.intsocsel);
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    else if(group_cfg.trigsrc_type == CDD_ADC_TRIGG_SRC_SW)
    {
        /* Software trigger */
        Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc = CDD_ADC_GRP_TRIGG_SRC_SW;
        Cdd_Adc_ForceMultipleSoc(base_addr,group_cfg.soc_mask);        
    }
    else
    {
        /* Do nothing */
    }
}

/* Private function to update the status of the group */
static FUNC(void,CDD_ADC_CODE) Cdd_Adc_UpdateGroupStatus(Cdd_Adc_GroupType Group)
{
    /* Groups in IDLE state or in STREAM_COMPLETED state that are stopped implicitly are updated to IDLE state*/
    if(Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc != CDD_ADC_GRP_TRIGG_SRC_GLBSW)
    {
        if((Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status == CDD_ADC_IDLE) || \
        ((Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == TRUE) && \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status == CDD_ADC_STREAM_COMPLETED)))
        {
            Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_IDLE;
        }
        else
        {
            /* Group that are not stopped implicilty or in BUSY state are moved to BUSY state. */
            Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_BUSY;
        }
    }
    else
    {
        /* If group trigger source is Global software trigger then don't change the group status */
    }
    return;
}

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_StopHwGrpTrigger(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupCfgType group_cfg = Cdd_Adc_ConfigPtr->groupcfg[Group];
    uint8 channelnum;
    uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(group_cfg.hwunit_index)].base_addr;

    /* Disable trigger sources for the hardware trigger groups which can be stopped impliclitly */
    for(channelnum = group_cfg.startchannelnum;\
        (channelnum<(group_cfg.channelcount+group_cfg.startchannelnum) && (channelnum < CDD_ADC_CHN_COUNT));\
            channelnum++)
    {
        /* Assign the soc number to the channel and configure the SOC.*/
        Cdd_Adc_SetupSoc(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channelnum].soc_num,CDD_ADC_TRIGGER_SW_ONLY,\
        Cdd_Adc_ConfigPtr->channelcfg[channelnum].channel_id,Cdd_Adc_ConfigPtr->channelcfg[channelnum].sample_window);
        
        if(group_cfg.intsocsel != CDD_ADC_INT_SOC_TRIGGER_NONE)
        {
            /* Set the interrupt trigger source */
            Cdd_Adc_SetIntSocTrigger(base_addr,Cdd_Adc_ConfigPtr->channelcfg[channelnum].soc_num,\
                                        CDD_ADC_INT_SOC_TRIGGER_NONE);
        }
        else
        {
            /* Do nothing */
        }
    }
}

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_SetGroup(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupCfgType groupcfg = Cdd_Adc_ConfigPtr->groupcfg[Group];
    uint8 hwunitindex = groupcfg.hwunit_index;
    uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(hwunitindex)].base_addr;

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
    Cdd_Adc_PpbType ppb_num,lastppbnum;
#endif

    /* Set the valid samples count to Zero. */
    Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples = 0U;
    /* Reset the internal result buffer pointer. */
    Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr = \
                            (Cdd_Adc_ValueGroupType*)(Cdd_Adc_DrvObjPtr->group_obj[Group].resbuffer);

    /* Enable the corresponding interrupt */
    Cdd_Adc_ConfigureInterrupt(base_addr,groupcfg.grp_int,TRUE);
    Cdd_Adc_ConfigureContinueToIntMode(base_addr,groupcfg.grp_int,\
            (boolean)groupcfg.continuetoint);

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
    lastppbnum = (Cdd_Adc_PpbType)(Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].ppbcount + \
                        Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum);
    for(ppb_num=Cdd_Adc_ConfigPtr->hwunitcfg[hwunitindex].startppbnum; \
            ((ppb_num < lastppbnum) && (ppb_num < CDD_ADC_PPB_CNT)) ;ppb_num++)
    {
        if(((1U<<Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].soc_num) & groupcfg.soc_mask) != 0U)
        {
            /* Configure the interrupt and event flags */
            Cdd_Adc_ForcePpbSync(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id);
            /* If the group is started */
            Cdd_Adc_ConfigPpbEvent(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,\
                        Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtsel,TRUE);
            Cdd_Adc_ConfigPpbEventInterrupt(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id,\
                        Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripevtintsel,TRUE);
            if(Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].tripfilterenable == TRUE)
            {
                Cdd_Adc_TripFilterInit(base_addr,Cdd_Adc_ConfigPtr->ppbcfg[ppb_num].ppb_id);
            }
            else
            {
                /* Don't configure trip filter if not enabled */
            }
        }
    }
#endif

    /* Set the group status to Busy */
    Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_BUSY;
}

static FUNC(void,CDD_ADC_CODE) Cdd_Adc_ProcessGroup(Cdd_Adc_GroupType Group)
{
    Cdd_Adc_GroupCfgType groupcfg = Cdd_Adc_ConfigPtr->groupcfg[Group];
    if(((Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == TRUE) && \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == groupcfg.stream_numsamples)) || \
            ((Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc == CDD_ADC_GRP_TRIGG_SRC_SW) && \
                (groupcfg.trigsrc_type == CDD_ADC_TRIGG_SRC_HW)))
    {
        /* Don't perform any action if the buffer is completely filled for implictily stopped groups or stopped 
         * hardware groups. ISR may be called even after the buffer is complete when continuetointerrupt mode is 
         * enabled and the hardware triggers are really fast
         */
    }
    else
    {
        /* Continue with ISR execution */
        uint8 channelnum;
        uint32 base_addr = Cdd_Adc_ConfigPtr->hwunitcfg[(groupcfg.hwunit_index)].base_addr;
        uint32 result_baseaddr = Cdd_Adc_ConfigPtr->hwunitcfg[(groupcfg.hwunit_index)].result_baseaddr;

        if((Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == groupcfg.stream_numsamples) || \
                (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == 0U) )
        {
            /* If the buffer is filled wrap around the buffer */
            Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr = \
                                    (Cdd_Adc_ValueGroupType*)(Cdd_Adc_DrvObjPtr->group_obj[Group].resbuffer);
        }
        else
        {
            Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr++; /* Update the current result buffer pointer */
        }

        if(Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples < groupcfg.stream_numsamples)
        {
            Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples++; /* Number of valid samples per channel */
        }
        else
        {
            /* Valid samples has become equal to maximum streaming number of samples for the group */
            Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples = 1U;
        }

        /* Update the group status to CDD_ADC_COMPLETED when global software trigger is the source 
            and when the result buffer is not completely filled */
        if((Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc == CDD_ADC_GRP_TRIGG_SRC_GLBSW) || \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples != groupcfg.stream_numsamples))
        {
            Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_COMPLETED;
        }
        else 
        {
            /* Update the group status to CDD_ADC_STREAM_COMPLETED when the buffer is completely filled */
            Cdd_Adc_DrvObjPtr->group_obj[Group].grp_status = CDD_ADC_STREAM_COMPLETED;
        }

        /* Clear the interrupt flag and the result ready flag */
        Cdd_Adc_ClearInterruptFlag(base_addr,groupcfg.grp_int);
        /* Check if interrupt overflow has occurred */
        if(TRUE == Cdd_Adc_GetIntOvfStatus(base_addr,groupcfg.grp_int))
        {
            Cdd_Adc_ClearIntOvfStatus(base_addr,groupcfg.grp_int);
            Cdd_Adc_ClearInterruptFlag(base_addr,groupcfg.grp_int);
        }

        if((Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == TRUE) && \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == groupcfg.stream_numsamples))
        {
            /* Disable interrups if the buffer is completely filled for the implicitly stopped groups */
            Cdd_Adc_ConfigureInterrupt(base_addr,groupcfg.grp_int,FALSE);
            /* Disable continue to interrupt mode */
            Cdd_Adc_ConfigureContinueToIntMode(base_addr,groupcfg.grp_int,FALSE);
        }
        else
        {
            /* Do not disable interrupts for explicitly stopped groups and don't stop if the buffer is not 
                completely filled implicitly stopped groups */
        }

        /* Copy the results to the result buffer of the group */
        for (channelnum=0U;channelnum<groupcfg.channelcount;channelnum++)
        {
            /* Read the corresponding SOC result and store it in the group result buffer */
            *(Cdd_Adc_DrvObjPtr->group_obj[Group].cur_resultptr + (channelnum*(groupcfg.stream_numsamples))) = \
                        Cdd_Adc_ReadResult(result_baseaddr,\
                                    Cdd_Adc_ConfigPtr->channelcfg[(channelnum+groupcfg.startchannelnum)].soc_num);
        }

        #if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
        if(Cdd_Adc_DrvObjPtr->group_obj[Group].grp_notification == TRUE)
        {
            /* Call the specified end group notification function */
            groupcfg.groupend_notification();
        }
        else
        {
            /* Do nothing */
        }
        #endif /*(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API) */

        /* Manual re-trigger is necessary only for the software triggered groups */
        if((Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc == CDD_ADC_GRP_TRIGG_SRC_SW) && \
                ((Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == FALSE) || \
                (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples < groupcfg.stream_numsamples)))
        {
            /* Retrigger the group conversion if the group doesn't stop implicitly or the buffer is not completely 
            filled for implicitly stopped groups */
            Cdd_Adc_ForceMultipleSoc(base_addr,groupcfg.soc_mask);
        }
        else if((Cdd_Adc_DrvObjPtr->group_obj[Group].triggersrc == CDD_ADC_GRP_TRIGG_SRC_HW) && \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].implicit_stop == TRUE) && \
            (Cdd_Adc_DrvObjPtr->group_obj[Group].valid_samples == groupcfg.stream_numsamples))
        {
            /* Disable group trigger sources and interrupt trigger source for the hardware trigger source groups 
                *  which ae impliclitly stoped. If the  hardware group trigger source is left unchanged the hardware 
                *  trigger might start ADC conversion when the trigger is received blocking other group conversions.
                * No need to perform any action for software triggers except disabling interrupts
                */
            Cdd_Adc_StopHwGrpTrigger(Group);
        }
        else
        {
            /* For explicitly stopped hardware groups don't stop hardware triggers and 
                for implicitly stopped software groups don't trigger the group for another conversion */
        }

    }
    return;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Priv.c
 *********************************************************************************************************************/
