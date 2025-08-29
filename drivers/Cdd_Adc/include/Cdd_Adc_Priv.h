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
 *  File:       Cdd_Adc_Priv.h
 *  Generator:  None
 *
 *  Description:   This file contains data structures and private function declarations of private
 *API's.
 *********************************************************************************************************************/
#ifndef CDD_ADC_PRIV_H
#define CDD_ADC_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc.h"
#include "hw_adc.h"
#include "hw_asysctl.h"
#include "hw_types.h"
#include "Mcal_Lib.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define CHECKER_EVT_SEL_M                                                                      \
    (ADC_CHECKINTSEL1_RES1OVF1EN | ADC_CHECKINTSEL1_RES1OVF2EN | ADC_CHECKINTSEL1_RES1OVF3EN | \
     ADC_CHECKINTSEL1_RES1OVF4EN | ADC_CHECKINTSEL1_RES1OVF5EN | ADC_CHECKINTSEL1_RES1OVF6EN | \
     ADC_CHECKINTSEL1_RES1OVF7EN | ADC_CHECKINTSEL1_RES1OVF8EN | ADC_CHECKINTSEL1_RES1OVF9EN)
#define CDD_ADC_INT_REF_TSSLOPE  (*(sint16 *)((uint64)0x20000FDC))
#define CDD_ADC_INT_REF_TSOFFSET (*(sint16 *)((uint64)0x20000FE0))
#define CDD_ADC_EXT_REF_TSSLOPE  (*(sint16 *)((uint64)0x20000FD4))
#define CDD_ADC_EXT_REF_TSOFFSET (*(sint16 *)((uint64)0x20000FD8))
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/* Design: MCAL-31145 */
/** \brief Group trigger type */
typedef enum
{
    CDD_ADC_GRP_TRIGG_SRC_SW,   /*!< \brief Group is triggered by a software API call */
    CDD_ADC_GRP_TRIGG_SRC_HW,   /*!< \brief Group is triggered by a hardware event */
    CDD_ADC_GRP_TRIGG_SRC_GLBSW /*!< \brief Group is triggered by gloval software trigger call */
} Cdd_Adc_GroupTriggerType;

/* Design: MCAL-31140 */
/** \brief Interrupt trigger type */
typedef enum
{
    CDD_ADC_INT_TRIGGER_EOC0   = 0U,  /*!< \brief SOC/EOC0  */
    CDD_ADC_INT_TRIGGER_EOC1   = 1U,  /*!< \brief SOC/EOC1  */
    CDD_ADC_INT_TRIGGER_EOC2   = 2U,  /*!< \brief SOC/EOC2  */
    CDD_ADC_INT_TRIGGER_EOC3   = 3U,  /*!< \brief SOC/EOC3  */
    CDD_ADC_INT_TRIGGER_EOC4   = 4U,  /*!< \brief SOC/EOC4  */
    CDD_ADC_INT_TRIGGER_EOC5   = 5U,  /*!< \brief SOC/EOC5  */
    CDD_ADC_INT_TRIGGER_EOC6   = 6U,  /*!< \brief SOC/EOC6  */
    CDD_ADC_INT_TRIGGER_EOC7   = 7U,  /*!< \brief SOC/EOC7  */
    CDD_ADC_INT_TRIGGER_EOC8   = 8U,  /*!< \brief SOC/EOC8  */
    CDD_ADC_INT_TRIGGER_EOC9   = 9U,  /*!< \brief SOC/EOC9  */
    CDD_ADC_INT_TRIGGER_EOC10  = 10U, /*!< \brief SOC/EOC10 */
    CDD_ADC_INT_TRIGGER_EOC11  = 11U, /*!< \brief SOC/EOC11 */
    CDD_ADC_INT_TRIGGER_EOC12  = 12U, /*!< \brief SOC/EOC12 */
    CDD_ADC_INT_TRIGGER_EOC13  = 13U, /*!< \brief SOC/EOC13 */
    CDD_ADC_INT_TRIGGER_EOC14  = 14U, /*!< \brief SOC/EOC14 */
    CDD_ADC_INT_TRIGGER_EOC15  = 15U, /*!< \brief SOC/EOC15 */
    CDD_ADC_INT_TRIGGER_EOC16  = 16U, /*!< \brief SOC/EOC16 */
    CDD_ADC_INT_TRIGGER_EOC17  = 17U, /*!< \brief SOC/EOC17 */
    CDD_ADC_INT_TRIGGER_EOC18  = 18U, /*!< \brief SOC/EOC18 */
    CDD_ADC_INT_TRIGGER_EOC19  = 19U, /*!< \brief SOC/EOC19 */
    CDD_ADC_INT_TRIGGER_EOC20  = 20U, /*!< \brief SOC/EOC20 */
    CDD_ADC_INT_TRIGGER_EOC21  = 21U, /*!< \brief SOC/EOC21 */
    CDD_ADC_INT_TRIGGER_EOC22  = 22U, /*!< \brief SOC/EOC22 */
    CDD_ADC_INT_TRIGGER_EOC23  = 23U, /*!< \brief SOC/EOC23 */
    CDD_ADC_INT_TRIGGER_EOC24  = 24U, /*!< \brief SOC/EOC24 */
    CDD_ADC_INT_TRIGGER_EOC25  = 25U, /*!< \brief SOC/EO25  */
    CDD_ADC_INT_TRIGGER_EOC26  = 26U, /*!< \brief SOC/EOC26 */
    CDD_ADC_INT_TRIGGER_EOC27  = 27U, /*!< \brief SOC/EOC27 */
    CDD_ADC_INT_TRIGGER_EOC28  = 28U, /*!< \brief SOC/EOC28 */
    CDD_ADC_INT_TRIGGER_EOC29  = 29U, /*!< \brief SOC/EOC29 */
    CDD_ADC_INT_TRIGGER_EOC30  = 30U, /*!< \brief SOC/EOC30 */
    CDD_ADC_INT_TRIGGER_EOC31  = 31U, /*!< \brief SOC/EOC31 */
    CDD_ADC_INT_TRIGGER_OSINT1 = 32U, /*!< \brief OSINT1    */
    CDD_ADC_INT_TRIGGER_OSINT2 = 33U, /*!< \brief OSINT2    */
    CDD_ADC_INT_TRIGGER_OSINT3 = 34U, /*!< \brief OSINT3    */
    CDD_ADC_INT_TRIGGER_OSINT4 = 35U  /*!< \brief OSINT4    */
} Cdd_Adc_IntTriggerType;

/* Design: MCAL-31139 */
/** \brief Offset trim type */
typedef enum
{
    CDD_ADC_OFFSET_TRIM_COMMON     = 0x0000U, /*!< \brief Common Trim register for all ADC modes */
    CDD_ADC_OFFSET_TRIM_INDIVIDUAL = 0x0100U  /*!< \brief Individual Trim registers for different ADC modes */
} Cdd_Adc_OffsetTrimType;

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/** \brief Result safety checker tile object structure */
typedef struct Cdd_Adc_CheckerUnitObjTag
{
    /** \brief  Base address of the safety checker unit */
    uint32 base_addr;
} Cdd_Adc_CheckerUnitObjType;

/** \brief Checker interrupt event object structure */
typedef struct Cdd_Adc_CheckerIntEvtObjTag
{
    /** \brief  Base address of the safety checker unit */
    uint32 base_addr;
} Cdd_Adc_CheckerIntEvtObjType;

#endif

/** \brief Group object structure */
typedef struct Cdd_Adc_GroupObjTag
{
    /** \brief  ADC group result/status */
    Cdd_Adc_StatusType grp_status;
    /** \brief  Determines whether the group stops implicitly or has to be stopped by the user */
    boolean            implicit_stop;
    /** \brief  Determines whether the group stops implicitly or has to be stopped by the user */
    boolean            grp_active;
#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
    /** \brief  Flag to enable or disable group notify function */
    boolean grp_notification;
#endif
    /** \brief  Result buffer pointer - fixed for a group */
    const Cdd_Adc_ValueGroupType *resbuffer;
    /** \brief  Pointer to the latest conversion  round results */
    Cdd_Adc_ValueGroupType       *cur_resultptr;
    /** \brief  Number of valid samples - incremented after conversion of all
     * channels in the group */
    Cdd_Adc_StreamNumSampleType   valid_samples;
    /** \brief  Group trigger source type.*/
    Cdd_Adc_GroupTriggerType      triggersrc;
} Cdd_Adc_GroupObjType;

/** \brief Hardware unit object structure */
typedef struct Cdd_Adc_HwUnitObjTag
{
#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
    /** \brief  ADC HW Unit resolution */
    Cdd_Adc_ResolutionType cur_resolution;
#endif
} Cdd_Adc_HwUnitObjType;

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
/** \brief Global software object structure */
typedef struct Cdd_Adc_GlbSwObjTag
{
    /** \brief  hwunit mask */
    boolean status;
} Cdd_Adc_GlbSwObjType;
#endif

/* Design: MCAL-31437 */
/** \brief Driver object structure */
typedef struct Cdd_Adc_DriverObjTag
{
#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
    /** \brief  ADC hw unit objects */
    /* Design: MCAL-31439 */
    Cdd_Adc_HwUnitObjType hwunit_obj[CDD_ADC_HW_CNT];
#endif
    /** \brief  ADC group objects */
    /* Design: MCAL-31438 */
    Cdd_Adc_GroupObjType group_obj[CDD_ADC_GROUP_CNT];
#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
    /* Design: MCAL-31440 */
    Cdd_Adc_GlbSwObjType glbsw_obj[CDD_ADC_GLBSW_TRIG_CNT];
#endif
    Cdd_Adc_GroupType interrupt_obj[CDD_ADC_MAX_HW_UNIT_COUNT * CDD_ADC_MAX_INT_COUNT];
} Cdd_Adc_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Sets the driver object
 *
 * This private function sets the driver object
 *
 * \param[in]  DrvObj Driver object
 * \param[in]  CfgPtr Configuration pointer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetDrvObj(Cdd_Adc_DriverObjType *DrvObj, const Cdd_Adc_ConfigType *CfgPtr);

/** \brief Initializes the driver object
 *
 * This private function resets the driver object to the power on reset mode
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DrvObjInit(void);

/** \brief Initializes the Cdd Adc driver
 *
 * This private function initializes the Cdd Adc driver.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_HwUnitInit(void);

/** \brief Sets the internal test node for all the ADC hardware units
 *
 * This private function sets the internal test mode. This is common for all the ADC hardware units
 *
 * \param[in]  TestNode test node source
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_SelectInternalTestNode(Cdd_Adc_InternalTestNodeType TestNode);

#if (STD_ON == CDD_ADC_DEINIT_API)
/** \brief De-initializes the Adc driver
 *
 * This private function de-initializes the Adc driver.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_HwUnitDeinit(void);
#endif

/** \brief Configures the SOCs of a HW unit to accept the triggers
 *
 * This private function configures the SOCs of the specified so that any further triggers can be
 *used to starting a group conversion.
 *
 * \param[in]  Group    Numeric ID of the Group
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGroup(Cdd_Adc_GroupType Group);

/** \brief Disables SOCs to accept further triggers
 *
 * This private function disables the further triggers for the SOCs associated with the requested
 *group.
 *
 * \param[in]  Group    Numeric ID of the Group
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGroup(Cdd_Adc_GroupType Group);

/** \brief Disables SOCs to accept further triggers
 *
 * This private function disables the further triggers for the SOCs associated with the requested
 *group.
 *
 * \param[in]  Base    Base address of the ADC hardware unit
 * \param[in]  Resolution    Resolution mode of the ADC hardware unit
 * \param[in]  SignalMode    Signal mode of the ADC hardware unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetMode(uint32 Base, Cdd_Adc_ResolutionType Resolution, Cdd_Adc_SignalModeType SignalMode);

#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
/** \brief Updates the resolution of the specified ADC hardware unit if no DET errors are reported
 *
 * This private updates the resolution of the specified ADC hardware unit if no DET errors are reported
 *
 * \param[in] HwUnit  Instance ID of the specified ADC Hw Unit
 * \param[in] Resolution Resolution to be set for the ADC Hw Unit
 * \pre None
 * \post None
 * \return Return E_OK/E_NOT_OK based on whether the resolution update is successful
 * \retval  E_OK - If resolution is updated
 *          E_NOT_OK - If resolution is not updated because of DET errors
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_UpdateResolution(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                         VAR(Cdd_Adc_ResolutionType, AUTOMATIC) Resolution);
#endif

#if (STD_ON == CDD_ADC_READ_GROUP_API)
/** \brief Read the specified group results
 *
 * This private function reads the results of the specified group and stores them in the application
 *buffer.
 *
 * \param[in]  Group    Numeric ID of the Group
 * \param[in]  DataPtr  Pointer to result buffer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ReadGroupResult(Cdd_Adc_GroupType Group, Cdd_Adc_ValueGroupType *DataPtr);
#endif

/** \brief Read the specified group results
 *
 * This private function reads the results of the specified group and stores them in the application
 *buffer.
 *
 * \param[in]  Group    Numeric ID of the Group
 * \param[in]  PtrToSamplePtr  Pointer to result buffer pointer.
 * \pre None
 * \post None
 * \return Returns number of valid samples for each chanel in the group
 * \retval Cdd_Adc_StreamNumSampleType - Number of valid samples count
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_StreamNumSampleType, CDD_ADC_CODE)
Cdd_Adc_GetValidSampleCnt(Cdd_Adc_GroupType Group, Cdd_Adc_ValueGroupType **PtrToSamplePtr);

/** \brief ISR function called by a specific interrupt
 *
 * This ISR updates the status of the group and call the notification function if enabled for the
 *group. Also clears the interrupt flags and for continuous sofware triggers it triggers the
 *conversion again.
 *
 * \param[in]  IntNum   Interrupt number
 * \param[in]  HwUnitId   Hwunit object to which the the group belongs
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ProcessIsr(Cdd_Adc_IntNumType IntNum, Cdd_Adc_HwUnitType HwUnitId);

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/** \brief Ppb ISR function
 *
 * This ISR updates clears the flags of the interrupts of the PPB of the ADC hardware unit
 *
 * \param[in]  HwUnitId   Group object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_PpbEvtIsr(Cdd_Adc_HwUnitType HwUnitId);
#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/** \brief Safety checker ISR function
 *
 * This ISR updates clears the flags of the interrupts and stores the flag that generated the
 *interrupt for each safety checker unit.
 *
 * \param[in]  IntEvtId   Group object
 * \param[in]  FlagStatus   Pointer to the array
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_CheckerIsr(Cdd_Adc_CheckerIntEvtType IntEvtId, Cdd_Adc_CheckFlagStatusType *FlagStatus);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/*
 * ADC functions
 */

/*
 * SOC configuration Functions
 */

/** \brief Returns trigger source of the SOC
 *
 * This function returns trigger source of the specified SOC.
 *
 * \param[in] Base is the Base address of the ADC instance
 * \param[in] SocNum is the number of the start-of-conversion.
 * \pre None
 * \post None
 * \return Trigger source configured for the SOC
 * \retval Cdd_Adc_TriggerType - Returns the value corresponding to the SOC trigger source
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_TriggerType, CDD_ADC_CODE) Cdd_Adc_ReadSocTrigSrc(uint32 Base, uint8 SocNum);

#if (CDD_ADC_GLBSW_TRIG_API == STD_ON)

/*
 *  Global software trigger related functions
 */

/** \brief Function to start the global software trigger.
 *
 * This function configures the global software trigger for the specified ADC hardware units.
 *
 * \param[in] GlbSwTrig Numeric ID of the Global software trigger
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig);

/** \brief Function to stop the global software trigger.
 *
 * This function to stop the global software trigger for the specified ADC hardware units.
 *
 * \param[in] GlbSwTrig Numeric ID of the Global software trigger
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGlbTrig(Cdd_Adc_GlbTrigType GlbSwTrig);

/** \brief CHeck if any group is BUSY
 *
 * This function check if any group of the specified global software trigger is busy
 *
 * \param[in] GlbSwTrig     Numeric ID of global software trigger configuration.
 * \pre None
 * \post None
 * \return Return E_OK/E_NOT_OK based on whether any DET errors are reported or not
 * \retval  E_OK - If no DET errors are reported
 *          E_NOT_OK - If any DET error is reported
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE) Cdd_Adc_CheckGlbTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig);
#endif

#if (CDD_ADC_ENABLE_PPB_API == STD_ON)
/*
 *  PPB Functions
 */

/** \brief Reads the processed conversion result from the PPB.
 *
 * This function returns the processed conversion result of the specified PPB of the specified ADC
 *hardware unit.
 *
 * \param[in] ResultBase is the Base address of the ADC results
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbResult(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Clears ADC event flags.
 *
 * This function clears the indicated PPB event flags by the trip event mask.
 *
 * \param[in] Base is the Base address of the ADC instance
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \param[in] TripEvtMask Trip event mask
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearPpbEvtStatus(uint32 Base, Cdd_Adc_PpbIdType PpbNumber, uint8 TripEvtMask);

/** \brief Return the trigger of the group to which the PPB is linked
 *
 * This function return the trigger of the group to which the PPB is linked
 *
 * \param[in] PpbId Numeric ID of the Ppb unit
 * \pre None
 * \post None
 * \return Returns the trigger source type of the group that is linked to the PPB
 * \retval CDD_ADC_TRIGG_SRC_SW - Group is triggered by software
 *          CDD_ADC_TRIGG_SRC_HW - Group is triggered by hardware
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_TriggerSrcType, CDD_ADC_CODE) Cdd_Adc_PrivGetTrigSrc(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);

/** \brief Reads sample delay time stamp from a PPB.
 *
 * This function returns the sample delay time stamp. This delay is the number of system clock
 *cycles between the SOC being Triggered and when it began converting.
 *
 * \param[in] Base is the Base address of the ADC instance
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the number of system clock(SYSCLK) cycles delay between the SOC trigger and
 * the actual start of the sample
 * \retval uint16 - Delay value in SYSCLK cycles
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetPpbDelayTimeStamp(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the oversampled partial count from the PPB.
 *
 * This function returns the oversampled partial count of the specified PPB.
 *
 * \param[in] Base is the Base address of the ADC instance
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the partial PPB count limit.
 * \retval uint16 - partial PPB count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbPCount(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the over sampled partial sum from the PPB.
 *
 * This function returns the partial sum of results of the specified PPB.
 *
 * \param[in] Base is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the over sampled partial sum value.
 * \retval sint32 -  PPB partial sum value
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbPSum(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the partial conversion result's maximum value from the PPB.
 *
 * This function returns the over sampled partial maximum of the specified PPB.
 *
 * \param[in] Base is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the over sampled partial maximum value.
 * \retval sint32 - maximum partial value of the PPB
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbPMax(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the partial conversion result's minimum value from the PPB.
 *
 * This function returns the oversampled partial minimum of the specified PPB.
 *
 * \param[in] Base is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled partial minimum value.
 * \retval sint32 - minimum partial value of the PPB
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbPMin(uint32 Base, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the partial index of the result with maximum value from the PPB.
 *
 * This function returns the partial index of the processed conversion's maximum value of the
 *specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the partial index of the result with maximum value.
 * \retval uint16 - index of the PPB maximum partial value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbPMaxIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the partial index of the result with minimum value from the PPB.
 *
 * his function returns the partial index of the processed conversion's minimum value of the
 *specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled partial minimum value.
 * \retval uint16 - index of the minimum partial value of the PPB
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbPMinIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the oversampled final sum from the PPB.
 *
 * This function returns the processed sum of results of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled final sum value.
 * \retval sint32 - value of the final PPB sum
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbSum(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the processed conversion result's maximum value from the PPB.
 *
 * This function returns the oversampled final maximum of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled final maximum value.
 * \retval sint32 - value of the maximum PPB value
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbMax(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the processed conversion result's minimum value from the PPB.
 *
 * This function returns the oversampled final minimum of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled final minimum value.
 * \retval sint32 - value of the  minimum PPB value
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpbMin(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the oversampled final count from the PPB.
 *
 * This function returns the oversampled final count of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled final count value.
 * \retval uint16 - value of the PPB count at which partial register value is loaded to final sum
 *register
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbCount(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the index of the result with maximum value from the PPB.
 *
 * This function returns the index of the processed conversion's maximum value of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the index of the result with maximum value.
 * \retval uint16 - value of the PPB maximum index
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbMaxIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

/** \brief Reads the index of the result with minimum value from the PPB.
 *
 * his function returns the index of the processed conversion's minimum value of the specified PPB.
 *
 * \param[in] ResultBase is the Base address of the ADC results.
 * \param[in] PpbNumber is the numeric ID of the post-processing block
 * \pre None
 * \post None
 * \return Returns the oversampled final minimum value.
 * \retval uint16 - value of the PPB minimum index
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_ReadPpbMinIndex(uint32 ResultBase, Cdd_Adc_PpbIdType PpbNumber);

#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/*
 * Safety checker related functions
 */

/** \brief Enables/Disables the result safety checker module.
 *
 * This function enables/disables the result safety checker module.
 *
 * \param[in] ScBase is the Base address of the safety checker module.
 * \param[in] Mode Enable/Disable
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ConfigureCheckerTile(uint32 ScBase, boolean Mode);

/** \brief Stops and clears the safety checker flags of the result safety checker module.
 *
 * This function enables/disables the result safety checker unit.
 *
 * \param[in] CheckerId is the numeric ID of the safety checker unit.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopChecker(Cdd_Adc_CheckerType CheckerId);

/** \brief Forces the software sync for the safety checker module
 *
 * This function forces the software sync for the safety checker module.
 *
 * \param[in] ScBase is the Base address of the safety checker module
 * \pre None
 * \post None
 * \return Returns the safety checker enable/disable status
 * \retval boolean - TRUE if the safety checker is enabled
 *                   FALSE if the safety checker is enabled
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_ADC_CODE) Cdd_Adc_GetCheckerStatus(uint32 ScBase);

/** \brief Forces the software sync for the safety checker module
 *
 * This function forces the software sync for the safety checker module.
 *
 * \param[in] ScBase is the Base address of the safety checker module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ForceSafetyCheckerSync(uint32 ScBase);

/** \brief Returns the safety checker interrupt status.
 *
 * This function returns the safety checker interrupt status for the specified interrupt event
 *instance
 *
 * \param[in] Base is the base address of the safety checker interrupt event instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetSafetyCheckIntStatus(uint32 Base);

/** \brief Clears safety checker event source flags
 *
 * This function clears the safety checker event source flags for the specified interrupt event
 *instance and for the specified event ID
 *
 * \param[in] IntEvtId is the numeric ID of the safety checker interrupt event instance.
 * \param[in] Event_Id is the event ID of the safety checker interrupt event instance.
 * \pre None
 * \post None
 * \return None.
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearCheckerStatus(Cdd_Adc_CheckerIntEvtType IntEvtId, Cdd_Adc_CheckerEventType Event_Id);

#endif

#ifdef __cplusplus
}
#endif

#endif /* CDD_ADC_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Priv.h
 *********************************************************************************************************************/
