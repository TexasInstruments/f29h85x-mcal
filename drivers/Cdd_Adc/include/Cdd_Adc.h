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
 *  File:       Cdd_Adc
 *  Generator:  None
 *
 *  Description:  This file contains CDD ADC driver public API function declarations .
 *********************************************************************************************************************/
#ifndef CDD_ADC_H
#define CDD_ADC_H

/**
 * \defgroup CDD_ADC Cdd_Adc API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* Defines for CDD_ADC Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_ADC_SW_MAJOR_VERSION (2U)
/** \brief Driver Implementation Minor Version */
#define CDD_ADC_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_ADC_SW_PATCH_VERSION (1U)

/*  Defines for CDD_ADC Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_ADC Driver*/
#define CDD_ADC_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_ADC Driver*/
#define CDD_ADC_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_ADC Driver*/
#define CDD_ADC_AR_RELEASE_REVISION_VERSION (1U)

/* CDD ADC Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_ADC_VENDOR_ID ((uint16)44U)
/** \brief CDD ADC Driver Module ID */
#define CDD_ADC_MODULE_ID ((uint16)255U)
/** \brief CDD ADC Instance ID */
#define CDD_ADC_INSTANCE_ID ((uint8)0U)

/* Error codes returned by Cdd Adc functions. */

/** \brief API service used without module initialization */
#define CDD_ADC_E_UNINIT ((uint8)0x0AU) /* Design: MCAL-31146 */

/** \brief API service called during ongoing process/conversion */
#define CDD_ADC_E_BUSY ((uint8)0x0BU) /* Design: MCAL-31147 */

/** \brief API service called while no conversion is ongoing */
#define CDD_ADC_E_IDLE ((uint8)0x0CU) /* Design: MCAL-31148 */

/** \brief API Cdd_Adc_Init service called while the ADC driver has already been initialized */
#define CDD_ADC_E_ALREADY_INITIALIZED ((uint8)0x0DU) /* Design: MCAL-31149 */

/** \brief  API service called with incorrect configuration parameter */
#define CDD_ADC_E_PARAM_CONFIG ((uint8)0x0EU) /* Design: MCAL-31150 */

/** \brief  API service called with invalid data buffer pointer */
#define CDD_ADC_E_PARAM_POINTER ((uint8)0x14U) /* Design: MCAL-31151 */

/** \brief  API service called with invalid group ID */
#define CDD_ADC_E_PARAM_GROUP ((uint8)0x15U) /* Design: MCAL-31152 */

/** \brief  API service called with invalid hardware unit ID */
#define CDD_ADC_E_WRONG_RESOLUTION_MODE ((uint8)0x18U) /* Design: MCAL-31153 */

/** \brief API service called on a group with conversion mode configured as continuous */
#define CDD_ADC_E_WRONG_CONV_MODE ((uint8)0x1AU) /* Design: MCAL-31154 */

/** \brief API service called for group with wrong trigger source*/
#define CDD_ADC_E_WRONG_TRIGG_SRC ((uint8)0x1BU) /* Design: MCAL-31155 */

/** \brief Enable/disable notification function for a group whose configuration set has no
 * notification available */
#define CDD_ADC_E_NOTIF_CAPABILITY ((uint8)0x1CU) /* Design: MCAL-311596 */

/** \brief Conversion started and result buffer pointer is not initialized */
#define CDD_ADC_E_BUFFER_UNINIT ((uint8)0x1DU) /* Design: MCAL-31157 */

/** \brief One or more ADC safety checker are IDLE */
#define CDD_ADC_E_CHECKER_IDLE ((uint8)0x1FU) /* Design: MCAL-31158 */

/** \brief One or more ADC safety checker are BUSY */
#define CDD_ADC_E_CHECKER_BUSY ((uint8)0x20U) /* Design: MCAL-31159 */

/** \brief API service called with invalid hardware unit ID */
#define CDD_ADC_E_ALREADY_SET ((uint8)0x21U) /* Design: MCAL-31160 */

/** \brief API service called with invalid hardware unit ID */
#define CDD_ADC_E_INVALID_ID ((uint8)0x22U) /* Design: MCAL-31161 */

/** \brief API service called with invalid hardware unit ID */
#define CDD_ADC_E_INVALID_RESOLUTION ((uint8)0x23U)  /* Design: MCAL-31162 */

/* The Service Id is one of the argument to Det_ReportError function and is used to identify the
 * source of the error. */
/** \brief Cdd_Adc_Init() API Service ID */
#define CDD_ADC_SID_INIT ((uint8)0x00U)
/** \brief Cdd_Adc_DeInit() API Service ID */
#define CDD_ADC_SID_DEINIT ((uint8)0x01U)
/** \brief Cdd_Adc_StartGroupConversion() API Service ID */
#define CDD_ADC_SID_START_GROUP_CONVERSION ((uint8)0x02U)
/** \brief Cdd_Adc_StopGroupConversion() API Service ID */
#define CDD_ADC_SID_STOP_GROUP_CONVERSION ((uint8)0x03U)
/** \brief Cdd_Adc_ReadGroup() API Service ID */
#define CDD_ADC_SID_READ_GROUP ((uint8)0x04U)
/** \brief Cdd_Adc_EnableHardwareTrigger() API Service ID */
#define CDD_ADC_SID_ENABLE_HARDWARE_TRIGGER ((uint8)0x05U)
/** \brief Cdd_Adc_DisableHardwareTrigger() API Service ID */
#define CDD_ADC_SID_DISABLE_HARDWARE_TRIGGER ((uint8)0x06U)
/** \brief Cdd_Adc_EnableGroupNotification() API Service ID */
#define CDD_ADC_SID_ENABLE_GROUP_NOTIFICATION ((uint8)0x07U)
/** \brief Cdd_Adc_DisableGroupNotification() API Service ID */
#define CDD_ADC_SID_DISABLE_GROUP_NOTIFICATION ((uint8)0x08U)
/** \brief  Cdd_Adc_GetGroupStatus() API Service ID */
#define CDD_ADC_SID_GET_GRP_STATUS ((uint8)0x09U)
/** \brief Cdd_Adc_GetVersionInfo() API Service ID */
#define CDD_ADC_SID_GET_VERSION_INFO ((uint8)0x0AU)
/** \brief Cdd_Adc_GetStreamLastPointer() API Service ID */
#define CDD_ADC_SID_GET_STREAM_LAST_POINTER ((uint8)0x0BU)
/** \brief Cdd_Adc_SetupResultBuffer() API Service ID */
#define CDD_ADC_SID_SETUP_RESULT_BUFFER ((uint8)0x0CU)
/** \brief Cdd_Adc_StartResultChecker service ID */
#define CDD_ADC_SID_START_RESULT_CHECKER ((uint8)0xDU)
/** \brief Cdd_Adc_StopResultChecker API service ID */
#define CDD_ADC_SID_STOP_RESULT_CHECKER ((uint8)0xEU)
/** \brief Cdd_Adc_ReadCheckerStatus API service ID */
#define CDD_ADC_SID_READ_RESULT_CHECKER ((uint8)0xFU)
/** \brief Cdd_Adc_ClearCheckerEvt API service ID */
#define CDD_ADC_SID_CLEAR_CHECKER_EVT ((uint8)0x10U)
/** \brief Cdd_Adc_StartGlobalSwTrig service ID */
#define CDD_ADC_SID_START_GLBSW_TRIG ((uint8)0x11U)
/** \brief Cdd_Adc_StopGlobalSwTrig service ID */
#define CDD_ADC_SID_STOP_GLBSW_TRIG ((uint8)0x12U)
/** \brief  Cdd_Adc_SetResolution() service ID */
#define CDD_ADC_SID_SET_RESOLUTION ((uint8)0x13U)
/** \brief  Cdd_Adc_ReadPpbValue() service ID */
#define CDD_ADC_SID_READ_PARTIAL_PPB_VALUE ((uint8)0x14U)
/** \brief Cdd_Adc_ReadPartialPpbValue() service ID */
#define CDD_ADC_SID_READ_PPB_VALUE ((uint8)0x15U)
/** \brief Cdd_Adc_ReadPpb() service ID */
#define CDD_ADC_SID_READ_PPB ((uint8)0x16U)
/** \brief Cdd_Adc_ClearPpbEvt() service ID */
#define CDD_ADC_SID_CLEAR_PPB_EVT ((uint8)0x17U)
/** \brief Cdd_Adc_GetDelayStamp() service ID */
#define CDD_ADC_SID_GET_DELAY_STAMP ((uint8)0x18U)
/** \brief Cdd_Adc_GetTemperatureC() service ID */
#define CDD_ADC_SID_GET_TEMPERATURE_C ((uint8)0x19U)
/** \brief Cdd_Adc_GetTemperatureK() service ID */
#define CDD_ADC_SID_GET_TEMPERATURE_K ((uint8)0x1AU)
/** \brief Cdd_Adc_SetInternalTestNode() service ID */
#define CDD_ADC_SID_INTERNAL_TEST_NODE ((uint8)0x1BU)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Numeric ID of an ADC channel group */
typedef uint8  Cdd_Adc_GroupType;
/** \brief Numeric ID of the PPB unit */
typedef uint8  Cdd_Adc_PpbType;
/** \brief Type for reading the converted values of a channel group */
typedef uint16 Cdd_Adc_ValueGroupType;
/** \brief Type for configuring the number of channel conversions results in
 * streaming access mode (in single access mode, parameter is 1) */
typedef uint8  Cdd_Adc_StreamNumSampleType;
/** \brief Specifies the checker event id */
typedef uint8  Cdd_Adc_CheckEvtType;
/** \brief Specifies ID of the global software trigger  */
typedef uint8  Cdd_Adc_GlbTrigType;
/** \brief Numeric ID of an ADC safety result checker */
typedef uint8  Cdd_Adc_CheckerType;
/** \brief Numeric ID of a safety checker interrupt event instance */
typedef uint8  Cdd_Adc_CheckerIntEvtType;
/** \brief Hardware unit instance type */
typedef uint8  Cdd_Adc_HwUnitInstanceType;
/** \brief Group end notification function pointer */
typedef P2FUNC(void, CDD_ADC_CODE, Cdd_Adc_GroupEndNotifyType)(void);  /* Design: MCAL-31119 */

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Design: MCAL-31136 */
/** \brief Ppb notification function pointer */
typedef P2FUNC(void, CDD_ADC_CODE, Cdd_Adc_PpbNotifyType)(void);
#endif

/** \brief Status type */
typedef enum
{
    CDD_ADC_IDLE,            /*!< \brief  The conversion of the specified group has not been started */
    CDD_ADC_BUSY,            /*!< \brief  The conversion of the specified group has been started and is still
                                going on */
    CDD_ADC_COMPLETED,       /*!< \brief  A conversion round (not the final one) of the group has been
                                finished.*/
    CDD_ADC_STREAM_COMPLETED /*!< \brief  The result buffer is completely filled */
} Cdd_Adc_StatusType;

/** \brief Trigger source type */
/* Design: MCAL-31122 */
typedef enum {
    CDD_ADC_TRIGG_SRC_SW, /*!< \brief  Group is triggered by a software API call */
    CDD_ADC_TRIGG_SRC_HW  /*!< \brief  Group is triggered by a hardware event */
} Cdd_Adc_TriggerSrcType;

/** \brief Stream buffer mode type */
/* Design: MCAL-31125 */
typedef enum {
    /** \brief The ADC Driver stops the conversion as soon as the stream buffer is full (number of
       samples reached) */
    CDD_ADC_STREAM_BUFFER_LINEAR,
    /** \brief The ADC Driver continues the conversion  even if the stream buffer is full (number of
        samples reached) by wrapping around the stream buffer itself */
    CDD_ADC_STREAM_BUFFER_CIRCULAR
} Cdd_Adc_StreamBufferModeType;

/** \brief Group access mode type */
/* Design: MCAL-31124 */
typedef enum {
    CDD_ADC_ACCESS_MODE_SINGLE,   /*!< \brief  Single value access mode */
    CDD_ADC_ACCESS_MODE_STREAMING /*!< \brief  Streaming access mode */
} Cdd_Adc_GroupAccessModeType;

/** \brief Group conversion mode type */
/* Design: MCAL-31121,MCAL-31116 */
typedef enum {
    /** \brief Exactly one conversion of each channel in an ADC channel group is performed after the
       trigger event */
    CDD_ADC_CONV_MODE_ONESHOT,
    /** \brief Repeated conversions of each ADC channel in an ADC channel group are performed */
    CDD_ADC_CONV_MODE_CONTINUOUS
} Cdd_Adc_GroupConvModeType;

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
/** \brief PPB value type */
typedef struct
{
    sint32 ppbmin;      /*!< \brief  Minimum PPB value */
    sint32 ppbmax;      /*!< \brief  Minimum PPB value */
    sint32 ppbsum;      /*!< \brief  PPB SUM value */
    uint16 ppbcount;    /*!< \brief  PPB count value */
    uint16 ppbmaxindex; /*!< \brief  PPB maximum result index */
    uint16 ppbminindex; /*!< \brief  PPB minimum result index */
} Cdd_Adc_PpbValType;

/* Design MCAL-31429 */
/** \brief PPB unit config type */
typedef struct Cdd_Adc_PpbUnitCfgTag
{
    /** \brief  ADC HW Unit PPB ID */
    Cdd_Adc_PpbIdType ppb_id;
    /** \brief  Soc number associated with the PPB */
    uint8             soc_num;
    /** \brief  Index of the hardware unit in the array of the hardware units */
    uint8             hwunitindex;
    /** \brief  offset due to external sensors and signal resources*/
    uint32            ppb_caloffset;
    /** \brief  Reference offset */
    uint32            ppb_refoffset;
    /** \brief  Determines delta enable, two's complement, absolute enable, cycle by cycle enable
     * functionality */
    uint16            ppbresconfig;
    /** \brief  PPB limit high */
    sint32            triplimithi;
    /** \brief  Trip low limit if trip limit low2 is enabled */
    sint32            triplimitlow;
    /** \brief  PPB trip event select */
    uint8             tripevtsel;
    /** \brief  PPB trip event interrupt select */
    uint8             tripevtintsel;
#if (STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
    /** \brief  Ppb event interrupt notification */
    Cdd_Adc_PpbNotifyType ppbevtint_notification;
#endif
    /** \brief  ppb sample count limit*/
    uint16  ppbcountlimit;
    /** \brief  shift value for automatic averaging and sync input select, OSINTSEL and COMPSEL*/
    uint16  ppbcfg2;
    /** \brief  Trip filter enable */
    boolean tripfilterenable;
    /** \brief  Trip filter clock */
    uint16  tripfilclk;
    /** \brief  Trip filter */
    uint16  tripfilctl;
} Cdd_Adc_PpbUnitCfgType;

#endif

/* Design MCAL-31428 */
/** \brief Channel config type */
typedef struct Cdd_Adc_ChannelCfgTag
{
    /** \brief  Numeric Id of the channel */
    uint8  channel_id;
    /** \brief  Sample window associated with the channel */
    uint16 sample_window;
#if (STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)
    /** \brief  External channel number */
    uint8 extchannelnum;
#endif
    /** \brief  Soc number assigned to the channel */
    uint8 soc_num;
} Cdd_Adc_ChannelCfgType;

#if (STD_ON == CDD_ADC_TRIG_REP_ENABLE)
/* Design MCAL-31432 */
/** \brief Trigger repeater config type */
typedef struct Cdd_Adc_TrigRepCfgTag
{
    /** \brief  ADC hardware unit index */
    uint8                    hwunit_index;
    /** \brief  Trigger repeater instance ID */
    Cdd_Adc_RepeaterType     repeater_instance;
    /** \brief  Trigger repeater mode */
    Cdd_Adc_RepeaterModeType repeater_mode;
    /** \brief  Trigger repeater source */
    Cdd_Adc_TriggerType      trigger_source;
    /** \brief  Trigger count */
    uint8                    repeater_count;
    /** \brief  Phase delay */
    uint16                   repeater_phase;
    /** \brief  Spread delay */
    uint16                   repeater_spread;
} Cdd_Adc_TrigRepCfgType;
#endif

/* Design MCAL-31426 */
/** \brief Group config type */
typedef struct Cdd_Adc_GroupCfgTag
{
    /** \brief  Hw unit index in the configuration structure */
    uint8                     hwunit_index;
    /** \brief  Group Interrupt Source */
    Cdd_Adc_IntNumType        grp_int;
    /** \brief  Boolean to determine if the continue to interrupt mode is enabled */
    boolean                   continuetoint;
    /** \brief  Boolean to detetrmine if the interrupt is configured as a trigger source for the
     * group */
    Cdd_Adc_IntSocTriggerType intsocsel;
#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
    /** \brief  Group end notification callback fxn pointer */
    Cdd_Adc_GroupEndNotifyType groupend_notification;
#endif
    /** \brief  Contains how many samples fit into result buffer */
    Cdd_Adc_StreamNumSampleType  stream_numsamples;
    /** \brief  Operation mode of the group */
    Cdd_Adc_GroupConvModeType    conversion_mode;
    /** \brief  Determines the trigger source (hw or sw trigger) */
    Cdd_Adc_TriggerSrcType       trigsrc_type;
    /** \brief  0 refers to software trigger other than zero refers hardware triggers */
    Cdd_Adc_TriggerType          trigger_src;
    /** \brief  Defines the type of the groups buffer */
    Cdd_Adc_GroupAccessModeType  access_mode;
    /** \brief  Use linear or circular stream buffer */
    Cdd_Adc_StreamBufferModeType streambuffermode;
    /** \brief  First channel number of the group */
    uint8                        startchannelnum;
    /** \brief  Number of channels configured for this group */
    uint8                        channelcount;
    /** \brief  soc mask initiates a conversion once that SOC is given priority */
    uint32                       soc_mask;
    /** \brief  Last SOC number of the group to be assigned to the interrupt */
    uint8                        lastsocnum;
} Cdd_Adc_GroupCfgType;

/* Design MCAL-31427 */
/** \brief Hardware unit config type */
typedef struct Cdd_Adc_HwUnitCfgTag
{
    Cdd_Adc_HwUnitType      hwunit_id;   /*!< \brief  ADC HW unit base addr */
    Cdd_Adc_PrescaleType    prescale;    /*!< \brief  ADC HW unit prescale*/
    Cdd_Adc_ResolutionType  resolution;  /*!< \brief  ADC HW Unit resolution */
    Cdd_Adc_SignalModeType  signal_mode; /*!< \brief  ADC HW Unit signal mode*/
    Cdd_Adc_RefVoltType     voltref;     /*!< \brief  ADC HW Unit Voltage reference */
    Cdd_Adc_RefModeType     voltrefmode; /*!< \brief  ADC HW Unit signal reference */
    /** \brief  Adc hardwrae unit Soc priority number. Based on this RoundRobin, high priority are
     * decided */
    Cdd_Adc_SocPriorityType socpriority;
    /** \brief  Interrupt pulse mode */
    Cdd_Adc_EocPulseType    intpulsemode;
    /** \brief  Determines the interrupy cycle offset */
    uint16                  intoffset;
    /** \brief  Start group number for the hardware unit */
    Cdd_Adc_GroupType       startgroupnum;
    /** \brief  Last group number for the hardware unit */
    Cdd_Adc_GroupType       lastgroupnum;
#if (STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
    Cdd_Adc_OsDetectModeType osdetectmode; /*!< \brief ADC Hw Unit OS detect mode */
#endif
#if (STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)
    /** \brief  Enable/Disable the external channel selection */
    boolean extchnsel;
    /** \brief  Boolean to determines whether the external mux preselect is enabled or not */
    boolean extmuxpreselect;
#endif
#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    /** \brief  Starting Ppb number */
    Cdd_Adc_PpbType startppbnum;
    Cdd_Adc_PpbType ppbcount;
#endif
    /** \brief  ADC HW unit result base addr */
    uint32 base_addr;
    /** \brief  ADC result registers base */
    uint32 result_baseaddr;
} Cdd_Adc_HwUnitCfgType;

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
/* Design: MCAL-31435 */
/** \brief Select result config type */
typedef struct Cdd_Adc_SelResCfgTag
{
    /** \brief  ADC HW Unit index */
    uint8                    hwunit_index;
    /** \brief  ADC result Number whose value is to be compared*/
    uint8                    res_num;
    /** \brief  SOC number whose result type value should be passed for the comparison */
    uint8                    soc_num;
    /** \brief  Result input type to the safety checker tile */
    Cdd_Adc_CheckerInputType res_type;
} Cdd_Adc_SelResCfgType;

/* Design: MCAL-31436 */
/** \brief Interrupt source type */
typedef struct Cdd_Adc_IntSrcTag
{
    /** \brief  Bitset to determine result1 overflow triggers interrupt to the CPU or events signals
     * to EPWM/OUTPUT-XBAR */
    uint16 res1ovf;
    /** \brief  Bitset to determine result2 overflow triggers interrupt to the CPU or events signals
     * to EPWM/OUTPUT-XBAR  */
    uint16 res2ovf;
    /** \brief  Bitset to determine out-of-tolerance triggers interrupt to the CPU or events signals
     * to EPWM/OUTPUT-XBAR */
    uint16 ootflg;
} Cdd_Adc_IntSrcType;

/* Design: MCAL-31433 */
/** \brief Checker response config type */
typedef struct Cdd_Adc_CheckerResCfgTag
{
    /** \brief  Id of the result safety checker tile*/
    Cdd_Adc_CheckerType   checker_id;
    /** \brief  Tolerance of the safety checker unit */
    uint32                tolerance;
    /** \brief  Base address of the safety checker instance */
    uint32                base_addr;
    /** \brief  The two results can be from the same or different ADC HW Units whose result is to be
     * compared */
    Cdd_Adc_SelResCfgType selresult[2];
} Cdd_Adc_CheckerResCfgType;

/* Design: MCAL-31434 */
/** \brief Checker interrupt event config type */
typedef struct Cdd_Adc_CheckerIntEvtCfgTag
{
    /** \brief  Interrupt event base addresss */
    uint32                    base_addr;
    /** \brief  Interrupt event instance ID */
    Cdd_Adc_CheckerIntEvtType intevt_id;
    /** \brief  Checker event interrupt */
    Cdd_Adc_IntSrcType        checkevtint;
    /** \brief  Checker event flags */
    Cdd_Adc_IntSrcType        checkevt[CDD_ADC_CHECKER_EVT_CNT];
} Cdd_Adc_CheckerIntEvtCfgType;

/* Design MCAL-31430 */
/** \brief Checker config type */
typedef struct Cdd_Adc_CheckerCfgTag
{
    /** \brief  Safety checker instance configuration */
    Cdd_Adc_CheckerResCfgType    checkerunitcfg[CDD_ADC_CHECKER_CNT];
    /** \brief  Interrupt event configuration */
    Cdd_Adc_CheckerIntEvtCfgType checkerintevtcfg[CDD_ADC_CHECKER_INTEVT_CNT];
} Cdd_Adc_CheckerCfgType;
#endif

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
/* Design MCAL-31431 */
/** \brief Global software config type */
typedef struct Cdd_Adc_GlbSwCfgTag
{
    /** \brief  HwIndex mask to enable global sw trigger (with respect to the index of the hardware
     * units)*/
    uint8  hwunit_mask;
    /** \brief  Soc number mask */
    uint32 soc_mask;
    /** \brief  Group Mask to start the corresponding group conversions */
    uint32 group_mask;
} Cdd_Adc_GlbSwCfgType;
#endif

/** \brief ADC config type */

/* Design: MCAL-31319 */
typedef struct Cdd_Adc_ConfigTag {
    /** \brief  Group configurations */
    Cdd_Adc_GroupCfgType   groupcfg[CDD_ADC_GROUP_CNT];
    /** \brief  HW Unit configurations */
    Cdd_Adc_HwUnitCfgType  hwunitcfg[CDD_ADC_HW_CNT];
    /** \brief  Channel configuration */
    Cdd_Adc_ChannelCfgType channelcfg[CDD_ADC_CHN_COUNT];
#if (STD_ON == CDD_ADC_ENABLE_PPB_API)
    /** \brief  Ppb configuration */
    Cdd_Adc_PpbUnitCfgType ppbcfg[CDD_ADC_PPB_CNT];
#endif
#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)
    /** \brief  ADC Result Safety Checker Configuration */
    Cdd_Adc_CheckerCfgType checkercfg;
#endif
#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
    /** \brief  Global software trigger configuration */
    Cdd_Adc_GlbSwCfgType glbtrigcfg[CDD_ADC_GLBSW_TRIG_CNT];
#endif
#if (STD_ON == CDD_ADC_TRIG_REP_ENABLE)
    /** \brief  Trigger repeater configuration */
    Cdd_Adc_TrigRepCfgType repunitcfg[CDD_ADC_TRIG_REP_CNT];
#endif
    /** \brief  Input to the internal test node */
    Cdd_Adc_InternalTestNodeType test_input;
} Cdd_Adc_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service to initialize Cdd Adc driver.
 *
 * This service initializes all the ADC HW units and safety checker units (Cdd_Adc driver).
 *
 * \param[in] CfgPtr Pointer to configuration set (Varaint PC requires a NULL_PTR)
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_Init(P2CONST(Cdd_Adc_ConfigType, AUTOMATIC, CDD_ADC_CFG) CfgPtr);

/** \brief This service initializes ADC driver with the group specific result buffer start address
 *where the conversion results will be stored.
 *
 *  This function initializes the group specific result buffer start address with the passed
 *DataBufferPtr parameter where the conversion results will be stored. Note: The application has to
 *ensure that the application buffer, where DataBufferPtr points to, can hold all the conversion
 *results of the specified group. The initialization with Cdd_Adc_SetupResultBuffer is required
 *after reset, before a group conversion can be started.
 *
 * \param[in] Group             Numeric ID of requested ADC Channel group.
 * \param[in] DataBufferPtr     Pointer to result data buffer
 * \pre None
 * \post None
 * \return Returns if the result buffer setup is successful.
 * \retval  E_OK: result buffer pointer initialized correctly
 * \retval  E_NOT_OK: operation failed or development error occured
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_SetupResultBuffer(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                          P2CONST(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr);

#if (STD_ON == CDD_ADC_DEINIT_API)
/** \brief Service to deinitialize Cdd Adc driver.
 *
 * This service returns all ADC HW Units to a state comparable to their power on reset state.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DeInit(void);
#endif

#if (STD_ON == CDD_ADC_ENABLE_START_STOP_GROUP_API)
/** \brief Service to start a group conversion.
 *
 * This service starts the conversion of all channels of the requested ADC Channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartGroupConversion(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);

/** \brief Service to stop a group conversion.
 *
 * This service Stops the conversion of the requested ADC Channel group
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGroupConversion(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);
#endif

#if (STD_ON == CDD_ADC_GLBSW_TRIG_API)
/** \brief Service to start the global software trigger
 *
 * This service starts global software trigger and returns E_OK if it is successful.
 *
 * \param[in] GlbSwTrig     Numeric ID of global software trigger configuration.
 * \pre None
 * \post None
 * \return Return whether the global software trigger is configured or not
 * \retval  E_OK - If the global software trigger is configured successfully
 *          E_NOT_OK - If the global software trigger is not configured
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_StartGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig);

/** \brief Service to stop the global software trigger
 *
 * This service stops global software trigger.
 *
 * \param[in] GlbSwTrig     Numeric ID of global software trigger configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopGlobalSwTrig(VAR(Cdd_Adc_GlbTrigType, AUTOMATIC) GlbSwTrig);
#endif

#if (STD_ON == CDD_ADC_HW_TRIGGER_API)
/** \brief Service to enables the HW trigger for a group.
 *
 * This service enableS the HW trigger source for the requested ADC channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);

/** \brief Service to disable the HW trigger for a group.
 *
 * This service disables the hardware trigger for the requested ADC Channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DisableHardwareTrigger(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);
#endif

#if (STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
/** \brief Service to enable the notification for a group.
 *
 * This service enables the notification mechanism for the requested ADC Channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_EnableGroupNotification(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);

/** \brief Service to disable the notification for a group.
 *
 * This service disables the notification mechanism for the requested ADC Channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_DisableGroupNotification(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);
#endif

/** \brief Service to get the conversion status of the group.
 *
 * This service returns the conversion status of the requested ADC Channel group.
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \pre None
 * \post None
 * \return Returns the conversion status of the group
 * \retval Cdd_Adc_StatusType
 *              CDD_ADC_IDLE:             The conversion of the specified group has not been started
 *              CDD_ADC_BUSY:             The conversion of the specified group has been started and
 *is still going on CDD_ADC_COMPLETED:        A conversion round of the specified group has been
 *finished. CDD_ADC_STREAM_COMPLETED: The result buffer is completely filled.
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_StatusType, CDD_ADC_CODE) Cdd_Adc_GetGroupStatus(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group);

#if (STD_ON == CDD_ADC_READ_GROUP_API)
/** \brief service that reads the group conversion result of the last completed conversion round
 *
 * This service reads the group conversion result of the last completed conversion round of the
 *requested group and stores the channel values starting at the DataBufferPtr address. The group
 *channel values are stored in ascending channel number order (in contrast to the storage layout of
 *the result buffer ifstreaming access is configured).
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \param[out] DataBufferPtr  Results of all channels of the group are stored where this pointer
 *points to.
 * \pre None
 * \post None
 * \return Returns if the results are available or not.
 * \retval E_OK: Results are available and written to the data buffer
 * \retval E_NOT_OK: No results are available or development error occured
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_ReadGroup(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                  P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) DataBufferPtr);
#endif

/** \brief service that returns the number of valid samples per channel, stored in the result
 *buffer.
 *
 * This service returns the number of valid samples per channel, stored in the result buffer. Reads
 *a pointer, pointing to a position in the group result buffer. With the pointer position, the
 *results of all groupchannels of the last completed conversion round can be accessed .With the
 *pointer and the return value, all valid group conversion results can be accessed (the user has to
 *take the layout of the result buffer into account).
 *
 * \param[in] Group     Numeric ID of requested ADC Channel group.
 * \param[out] PtrToSamplePtr  Pointer to result buffer pointer.
 * \pre None
 * \post None
 * \return Returns the number of valid samples per channel
 * \retval Returns the number of valid samples available for the group
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_StreamNumSampleType, CDD_ADC_CODE)
Cdd_Adc_GetStreamLastPointer(VAR(Cdd_Adc_GroupType, AUTOMATIC) Group,
                             P2VAR(Cdd_Adc_ValueGroupType, AUTOMATIC, CDD_ADC_DATA) * PtrToSamplePtr);

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/** \brief service that returns the version information of the module.
 *
 * This service returns the version information of the Adc module.
 *
 * \param[in] VersionInfo    Pointer to where to store the version information of this module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_ADC_DATA) VersionInfo);

#endif

#if (STD_ON == CDD_ADC_SAFETY_CHECK_API)

/** \brief service to start the safety result checker.
 *
 * This service starts the requested safety result checker unit.
 *
 * \param[in] CheckerId    Numeric ID of the result safety checker unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StartResultChecker(VAR(Cdd_Adc_CheckerType, AUTOMATIC) CheckerId);

/** \brief service to stop the safety result checker.
 *
 * This service stops the requested safety result checker unit.
 *
 * \param[in] CheckerId    Numeric ID of the result safety checker unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_StopResultChecker(VAR(Cdd_Adc_CheckerType, AUTOMATIC) CheckerId);

/** \brief service to get the safety checker status
 *
 * This service returns the safety checker status and clears the interrupt flags. This API needs to
 *be called inside ESM ISR. This shouldn't be called directly.
 *
 * \param[in] IntEvt    is the numeric ID of the interrupt event instance ID
 * \param[in] CheckerFlag    Pointer to the array of the status flag
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ReadCheckerStatus(VAR(Cdd_Adc_CheckerIntEvtType, AUTOMATIC) IntEvt,
                          P2VAR(Cdd_Adc_CheckFlagStatusType, AUTOMATIC, CDD_ADC_DATA) CheckerFlag);

/** \brief service to clears the status flags for the specified event
 *
 * This service clears the safety checker status flags that generated the specified event from the
 *specified interrupt event instance
 *
 * \param[in] IntEvt    is the numeric ID of the interrupt event instance ID
 * \param[in] Event_Id    is the numeric ID of the event
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_ClearCheckerEvt(VAR(Cdd_Adc_CheckerIntEvtType, AUTOMATIC) IntEvt,
                        VAR(Cdd_Adc_CheckerEventType, AUTOMATIC) Event_Id);

#endif

#if (STD_ON == CDD_ADC_ENABLE_PPB_API)

/** \brief service to get the PPB results
 *
 * This service returns the PPB results among multiple conversion results of the specified PPB
 *
 * \param[in] PpbId       Numeric ID of the PPB unit
 * \pre None
 * \post None
 * \return Returns a structure with final PPB min,max,sum,min index,max index and count values
 * \retval Cdd_Adc_PpbValType structure
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_PpbValType, CDD_ADC_CODE) Cdd_Adc_ReadPpbValue(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);

/** \brief service to get the partial PPB results
 *
 * This service returns the partial PPB results among multiple conversion results of the specified
 *PPB
 *
 * \param[in] PpbId       Numeric ID of the PPB unit
 * \pre None
 * \post None
 * \return Returns a structure with partial PPB min,max,sum,min index,max index and count values
 * \retval Cdd_Adc_PpbValType structure
 *
 *********************************************************************************************************************/
FUNC(Cdd_Adc_PpbValType, CDD_ADC_CODE)
Cdd_Adc_ReadPartialPpbValue(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);

/** \brief service to get the PPB result of the specified PPB
 *
 * This service returns the the PPB result of the specified PPB
 *
 * \param[in] PpbId       Numeric ID of the PPB unit
 * \pre None
 * \post None
 * \return Returns the ppb result register value
 * \retval sint32 signed 32bit value
 *
 *********************************************************************************************************************/
FUNC(sint32, CDD_ADC_CODE) Cdd_Adc_ReadPpb(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);

/** \brief service to clear the PPB event flags
 *
 * This service clears the event flags of the specified PPB results
 *
 * \param[in] PpbId       Numeric ID of the PPB unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE) Cdd_Adc_ClearPpbEvt(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);

/** \brief service to get the delay between the the SOC trigger and the actual start of the SOC
 *acquisition
 *
 * This service returns the delay between the the SOC trigger and the actual start of the SOC
 *acquisition of the specified PPB in SYSCLK cycles.
 *
 * \param[in] PpbId       Numeric ID of the PPB unit
 * \pre None
 * \post None
 * \return Number of SYSCLK cycles between the trigger and the actual sampling of the SOC linked to
 *the specified PPB.
 * \retval uint16 - Max value is 4095, if the delay exceeds 4096 SYSCLK cycles it overflows
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_ADC_CODE) Cdd_Adc_GetDelayStamp(VAR(Cdd_Adc_PpbType, AUTOMATIC) PpbId);
#endif

#if (STD_ON == CDD_ADC_SET_RESOLUTION_API)
/** \brief service to set the resolution of the ADC hardware unit.
 *
 * This service to set the resolution of the specified ADC hardware unit.
 *
 * \param[in] HwUnit  Instance ID of the specified ADC Hw Unit
 * \param[in] Resolution Resolution to be set for the ADC Hw Unit
 * \pre None
 * \post None
 * \return Returns if the resolution update is successful.
 * \retval  E_OK: Resolution update successfully
 *          E_NOT_OK: Resolution update failed
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_ADC_CODE)
Cdd_Adc_SetResolution(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                      VAR(Cdd_Adc_ResolutionType, AUTOMATIC) Resolution);
#endif

#if (STD_ON == CDD_ADC_TEMPERATURE_SENSOR_ENABLE)
/** \brief service to convert the ADC conversion value to Celsius.
 *
 * This service to convert the ADC conversion value to Celsius.
 *
 * \param[in] HwUnit  ADC hardware unit
 * \param[in] TempResult  ADC conversion result
 * \pre None
 * \post None
 * \return Returns the values converted to Celsius
 * \retval sint16 - Value after the result is converted to Celsius
 *
 *********************************************************************************************************************/
FUNC(sint16, CDD_ADC_CODE)
Cdd_Adc_GetTemperatureC(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                        VAR(Cdd_Adc_ValueGroupType, AUTOMATIC) TempResult);

/** \brief service to convert the ADC conversion value to Kelvin.
 *
 * This service to convert the ADC conversion value to Kelvin.
 *
 * \param[in] HwUnit  ADC hardware unit
 * \param[in] TempResult  ADC conversion result
 * \pre None
 * \post None
 * \return Returns the values converted to Kelvin
 * \retval sint16 - Value after the result is converted to Kelvin
 *
 *********************************************************************************************************************/
FUNC(sint16, CDD_ADC_CODE)
Cdd_Adc_GetTemperatureK(VAR(Cdd_Adc_HwUnitInstanceType, AUTOMATIC) HwUnit,
                        VAR(Cdd_Adc_ValueGroupType, AUTOMATIC) TempResult);
#endif

/** \brief service to set the internal test node
 *
 * This service to set the internal test node for all the hardware units
 *
 * \param[in] TestNode  Internal test node
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_ADC_CODE)
Cdd_Adc_SetInternalTestNode(VAR(Cdd_Adc_InternalTestNodeType, AUTOMATIC) TestNode);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_ADC_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Adc.h
 *********************************************************************************************************************/
