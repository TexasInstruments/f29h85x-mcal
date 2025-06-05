/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited. This product is protected under copyright law and
 *                 trade secret law as an unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc. All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:        Cdd_Xbar.h
 *  Generator:   None
 *
 *  Description: Interface Header file for CDD XBar module.
 *
 *********************************************************************************************************************/
#ifndef CDD_XBAR_H
#define CDD_XBAR_H
/**
 * \defgroup CDD_XBAR Cdd_Xbar
 * @{
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Cdd_Xbar_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief Driver Implementation Major Version. */
#define CDD_XBAR_SW_MAJOR_VERSION (2U)
/** \brief Driver Implementation Minor Version. */
#define CDD_XBAR_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version. */
#define CDD_XBAR_SW_PATCH_VERSION (0U)

/** \brief AUTOSAR Release Spec. Major Version. */
#define CDD_XBAR_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Release Spec. Minor Version. */
#define CDD_XBAR_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Release Spec. Revision Version. */
#define CDD_XBAR_AR_RELEASE_REVISION_VERSION (1U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/** \brief Texas Instruments Vendor ID. */
#define CDD_XBAR_VENDOR_ID ((uint16)0x2C)
/** \brief CDD XBar Module ID */
#define CDD_XBAR_MODULE_ID ((uint16)0xFF)
/** \brief CDD XBar Instance ID */
#define CDD_XBAR_INSTANCE_ID ((uint8)0x00)

/* CDD XBar Error Codes. */
/** \brief API called for reinitialization of already initialized crossbars */
#define CDD_XBAR_E_INIT_ALREADY (0x01) /* Design: MCAL-25815 */
/** \brief API called with invaid parameter */
#define CDD_XBAR_E_PARAM_VALUE (0x02) /* Design: MCAL-25816 */
/** \brief API called with invaid parameter pointer */
#define CDD_XBAR_E_PARAM_POINTER (0x03) /* Design: MCAL-25817 */
/** \brief API called with invaid operations on a locked crossbar */
#define CDD_XBAR_E_LOCK (0x04) /* Design: MCAL-25818 */
/** \brief API called with uninitialized driver */
#define CDD_XBAR_E_UNINIT (0x05) /* Design: MCAL-25819 */

/*
 * CDD XBar API service IDs.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 */
/** \brief Cdd_Xbar_GetVersionInfo() */
#define CDD_XBAR_SID_GET_VERSION_INFO (0x1)
/** \brief Cdd_Xbar_Init() */
#define CDD_XBAR_SID_INIT (0x2)
/** \brief Cdd_Xbar_SelectInput() */
#define CDD_XBAR_SID_SELECT_INPUT (0x3)
/** \brief Cdd_Xbar_OutLatchSelect() */
#define CDD_XBAR_SID_OUT_LATCH_SELECT (0x4)
/** \brief Cdd_Xbar_OutLatchSelectSts() */
#define CDD_XBAR_SID_OUT_LATCH_SELECT_STS (0x5)
/** \brief Cdd_Xbar_OutLatchFlagStatus() */
#define CDD_XBAR_SID_OUT_LATCH_FLAG_STATUS (0x6)
/** \brief Cdd_Xbar_OutLatchFlagForce() */
#define CDD_XBAR_SID_OUT_LATCH_FLAG_FORCE (0x7)
/** \brief Cdd_Xbar_OutLatchFlagClear() */
#define CDD_XBAR_SID_OUT_LATCH_FLAG_CLEAR (0x8)
/** \brief Cdd_Xbar_OutInvBeforeLatch() */
#define CDD_XBAR_SID_OUT_INV_BEFORE_LATCH (0x9)
/** \brief Cdd_Xbar_OutInvCheckBeforeLatch() */
#define CDD_XBAR_SID_OUT_INV_CHECK_BEFORE_LATCH (0xA)
/** \brief Cdd_Xbar_OutOutputSignal() */
#define CDD_XBAR_SID_OUT_OUTPUT_SIGNAL (0xB)
/** \brief Cdd_Xbar_OutStretchPulse() */
#define CDD_XBAR_SID_OUT_STRETCH_PULSE (0xC)
/** \brief Cdd_Xbar_OutStretchPulseClear() */
#define CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR (0xD)
/** \brief Cdd_Xbar_OutStretchPulseCheck() */
#define CDD_XBAR_SID_OUT_STRETCH_PULSE_CHECK (0xE)
/** \brief Cdd_Xbar_SelectOutputInversion() */
#define CDD_XBAR_SID_SELECT_OUTPUT_INVERSION (0xF)
/** \brief Cdd_Xbar_CheckOutputInversion() */
#define CDD_XBAR_SID_CHECK_OUTPUT_INVERSION (0x10)
/** \brief Cdd_Xbar_Lock() */
#define CDD_XBAR_SID_LOCK (0x11)
/** \brief Cdd_Xbar_LockStatus() */
#define CDD_XBAR_SID_LOCKSTATUS (0x12)
/** \brief Cdd_Xbar_InputFlagStatus() */
#define CDD_XBAR_SID_INPUTFLAGSTATUS (0x13)
/** \brief Cdd_Xbar_InputFlagClear() */
#define CDD_XBAR_SID_INPUTFLAGCLEAR (0x14)

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/* None */

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == CDD_XBAR_API_ENABLE)
#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
/* Design: MCAL-25737, MCAL-25738 */
/** \brief Service for getting CDD crossbar driver version information.
 *
 * Loads the corresponding vendor ID, module ID and software release version information for CDD
 *Crossbar module.
 *
 * \param[out] VersionInfoPtr is the pointer to a Std_VersionInfoType struct.
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_XBAR_APPL_DATA) VersionInfoPtr);
#endif /* STD_ON == CDD_XBAR_GET_VERSION_INFO_API */

/* Design: MCAL-25733, MCAL-25734, MCAL-25735, MCAL-25736, MCAL-28136, MCAL-28137,
 * MCAL-28138,MCAL-28139, MCAL-28140*/
/** \brief Service to initialize CDD Crossbar driver.
 *
 * Initializes crossbar driver for usage with the configured settings and enabling its other
 *functionalities offered.
 *
 * \param[in] ConfigPtr is the configuration pointer pointing to a generated configuration variant
 *from plugin.
 * \pre Preconditions - Driver not already initialized.
 * \post Postconditions - Driver in initialized state.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_Init(P2CONST(Cdd_Xbar_ConfigType, AUTOMATIC, CDD_XBAR_CONFIG_DATA) ConfigPtr);

#if ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) ||     \
     (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
/* Design: MCAL-25739, MCAL-25740 */
/** \brief Service for selecting available inputs for a given Crossbar Module.
 *
 * Selection of one input line at a time from a group to enable or
 * disable their signal route to the output lines if selectable
 * (i.e., not in a locked state).
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] InputLine is the crossbar input. In case of Input Xbar: PortPinId. In case of other
 *Xbars, enumerations available in Cdd_Xbar_Output_Xbar_Input_LinesType,
 *Cdd_Xbar_Epwm_Xbar_Input_LinesType, Cdd_Xbar_Clb_Xbar_Input_LinesType,
 *Cdd_Xbar_Mindb_Xbar_Input_LinesType or Cdd_Xbar_Icl_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if inputs selected.
 * \retval E_NOT_OK if input selection failed.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_SelectInput(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                     VAR(boolean, AUTOMATIC) Selection);

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-25741, MCAL-25742 */
/** \brief Service for enabling or disabling the output latch to drive the output of the selected
 *output crossbar instance.
 *
 * Enables/Disables the latched output for the given output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] LatchEnable is the parameter to determines whether or not to select latch,
 *  to drive the output of output crossbar instance., TRUE or FALSE.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Enablement status of output latch.
 * \retval E_OK on enabling/disabling as per LatchEnable.
 * \retval E_NOT_OK on failure to enable/disable as per LatchEnable.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchSelect(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) LatchEnable);

/* Design: MCAL-25743, MCAL-25744 */
/** \brief Service for checking the status of enabling the latched event as output of any output
 *crossbar instance.
 *
 * Fetches Output Latch enablement status of the given output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Enablement status of setting latched event as output.
 * \retval TRUE if latched event selected as output.
 * \retval FALSE if latch event not selected as output.
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLatchSelectSts(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/*Design: MCAL-28141, MCAL-28142 */
/** \brief Service for fetching latch status of output crossbar instance.
 *
 * Fetches Output Latch status on the given output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Latch status of the output crossbar instance.
 * \retval True if there is a latched event.
 * \retval False if latched event is not present.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchFlagStatus(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28143, MCAL-28144 */
/** \brief Service for setting the respective Output X-BAR output signal latch.
 *
 * Forces the output latch of the given output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of the setting the latch of output LineNumber of output crossbar.
 * \retval E_OK if latch setting is successful.
 * \retval E_OK if latch setting failed.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchFlagForce(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28145, MCAL-28146 */
/** \brief Service for clearing the respective Output X-BAR output signal latch.
 *
 * Cleares the output latch of the given output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of clearing the latch of output crossbar instance.
 * \retval E_OK if latch clearing is successful.
 * \retval E_OK if latch clearing failed.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchFlagClear(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28147, MCAL-28148 */
/** \brief Service for setting and restoring output line inversion before latch for a chosen output
 *crossbar instance.
 *
 * Sets and restores output line inversion before latch for a chosen output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Status of the setting and resetting the output line inversion before latch of output
 *crossbar instance.
 * \retval E_OK if setting and resetting is successful.
 * \retval E_OK if setting and resetting failed.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutInvBeforeLatch(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28149, MCAL-28150 */
/** \brief Service to check inversion before latching for an output line of the given output
 *crossbar instance.
 *
 * Returns status of output line inversion before latch for a chosen output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of inversion set before latch.
 * \retval TRUE if inverted.
 * \retval FALSE if uninverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutInvCheckBeforeLatch(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-25745, MCAL-25746 */
/** \brief Service for finding the signal on a output of an output crossbar instance.
 *
 * Getting signal value as high or low as output of output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Output Polarity.
 * \retval STD_HIGH if Logic High (1).
 * \retval STD_LOW if Logic Low (0).
 *
 *********************************************************************************************************************/
FUNC(Cdd_Xbar_OutputlevelType, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputSignal(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-25747, MCAL-25748 */
/** \brief Service for selecting 16 or 32-bit stretched pulse selection at the output of an output
 *crossbar instance.
 *
 * Selects or de-selects stretched pulse at the given output line of an output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] TickStretch  is the stretch in ticks as available with enumeration.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Status whether Output XBar out stretch pulse was set or not.
 * \retval E_OK if stretched or unstretched as per Ticks.
 * \retval E_NOT_OK if not stretched or unstretched as per Ticks.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulse(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit,
                         VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch);

/* Design: MCAL-25749, MCAL-25750 */
/** \brief Service for clearing a stretched pulse selection as output crossbar instance.
 *
 * Clears output line stretched pulse selection for output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Status of output stretched pulse selection clearance.
 * \retval E_OK if unstretched.
 * \retval E_NOT_OK if not stretched.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulseClear(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-25751, MCAL-25752 */
/** \brief Service for checking a stretched pulse selection of output of output crossbar instance.
 *
 * Checks for output line stretched pulse selection of an output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Output stretched pulse selection in Sys Ticks.
 * \retval CDD_XBAR_SYSTICKS_16 or CDD_XBAR_SYSTICKS_32 stretch as per stretch,
 *CDD_XBAR_SYSTICKS_STRETCH_OFF otherwise.
 *
 *********************************************************************************************************************/
FUNC(Cdd_Xbar_TickStretchType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulseCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* STD_ON == CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */

#if ((0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) ||   \
     (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
/* Design: MCAL-25753, MCAL-25754 */
/** \brief Service for inverting and restoring inversion of an output crossbar instance.
 *
 * Sets and restores output line inversion for a chosen output crossbar instance.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] Selection is the selection for inversion enablement.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Status of output inversion.
 * \retval E_OK if inverted.
 * \retval E_NOT_OK if not inverted.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_SelectOutputInversion(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25755, MCAL-25756 */
/** \brief Service for getting the current status of inversion on the
 *         output line of a crossbar instance in a given Crossbar Entity.
 *
 * Checks whether any given Output Line of a Crossbar type has been set
 * for inversion of its output signal or not, and returns the inversion.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Output inversion status.
 * \retval TRUE if inverted.
 * \retval FALSE if not inverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_CheckOutputInversion(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* ((0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) ||                                         \ \
          (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) || \ \
          (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/

/* Design: MCAL-25757, MCAL-25758 */
/** \brief Service for locking the given Crossbar entity for freezing the inputs and output
 *inversion unless reset.
 *
 * Locks a given Crossbar Entity or its Input Select instance as per the
 * case if it is not already in a locked state for preventing any
 * further modification to input selection and output inversion.
 * Please mind that once a unit is locked, it can not unlock until
 * system reset.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized but not locked.
 * \post Postconditions - None.
 * \return Locking attempt status.
 * \retval E_OK if the unlocked crossbar passed becomes locked, E_NOT_OK otherwise.
 * \retval E_NOT_OK if the unlocked crossbar not locked.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Lock(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-25759, MCAL-25760 */
/** \brief Service for checking lock status on a given Crossbar Unit.
 *
 * Tells whether the given Crossbar or its given Input Select line is locked or not.
 *
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of crossbar lock.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_LockStatus(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) \ \
          || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)   \ \
          || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U <                                    \ \
          CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/

#if (STD_ON == CDD_XBAR_INPUT_FLAG_API)
/* Design: MCAL-28151, MCAL-28152 */
/** \brief Service for checking status of a crossbar input flag.
 *
 * Returns whether the input flag is triggerred or not. Cdd_Xbar_InputFlagType can be used as an
 *argument to check the input flag status.
 *
 * \param[in] InputFlag is the crossbar input flag type.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of input flag.
 * \retval TRUE if input flag is triggerred.
 * \retval FALSE if input flag is not triggerred.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InputFlagStatus(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag);

/* Design: MCAL-28153, MCAL-28154 */
/** \brief Service for clearing a crossbar input flag.
 *
 * Clears the XBAR input flags.Cdd_Xbar_InputFlagType can be used as an argument to clear the input
 *flag.
 *
 * \param[in] InputFlag is the crossbar input flag type.
 * \pre Preconditions - Driver is already initialized.
 * \post Postconditions - None.
 * \return Status of clearing input flag.
 * \retval TRUE if input flag is cleared.
 * \retval FALSE if input flag is not cleared.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_InputFlagClear(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag);
#endif /* STD_ON == CDD_XBAR_INPUT_FLAG_API */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/** \brief Get Line Number selection mask.
 *
 * Returns the line number selection mask for an input line.
 *
 * \param[in] InputLine is the crossbar input.
 * \pre None
 * \post None
 * \return Line Number selection mask.
 *********************************************************************************************************************/
static inline FUNC(uint32, CDD_XBAR_CODE) Cdd_Xbar_Input_Selection_Mask(VAR(uint32, AUTOMATIC) InputLine)
{
    return (uint32)1U << (InputLine & 0xFFU);
}

/** \brief Get group number for a given input line */
#define CDD_XBAR_GET_GROUP_NUMBER(InputLine) ((uint8)((InputLine & 0xFF00U) >> 8U))

/** \brief Get crossbar type */
#define CDD_XBAR_GET_XBAR_TYPE(xbar) ((uint8)((xbar & 0xFF00U) >> 8U))

/** \brief Get crossbar output line */
#define CDD_XBAR_GET_XBAR_INSTANCE(xbar) ((uint8)(xbar & 0x00FFU))

/** \brief Get input flag number for a given input flag */
#define CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag) (((uint16)InputFlag & 0xFF00U) >> (uint16)8U)

/** \brief Get the bit corresponding to the input in the input flag */
#define CDD_XBAR_INPUT_FLAG_BIT(InputFlag) ((uint16)InputFlag & 0x00FFU)

#endif /* STD_ON == CDD_XBAR_API_ENABLE */
/**
 * @}
 */
#endif /* CDD_XBAR_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar.h
 *********************************************************************************************************************/
