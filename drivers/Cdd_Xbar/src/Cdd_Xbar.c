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
 *  File:       Cdd_Xbar.c
 *  Generator:  None
 *
 *  Description:  Interface source file for CDD XBar module.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Xbar.h"
#include "Cdd_Xbar_Priv.h"
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*
 *  AUTOSAR version information check has to match definition in header file
 */
#if ((CDD_XBAR_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_XBAR_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_XBAR_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "CDD XBAR: AUTOSAR Version Numbers of CDD XBAR are different"
#endif

/* vendor specific version information is BCD coded */
#if ((CDD_XBAR_SW_MAJOR_VERSION != (2U)) || (CDD_XBAR_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != (2U)) || (CDD_XBAR_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

#define CDD_XBAR_START_SEC_VAR_INIT_8
#include "Cdd_Xbar_MemMap.h"

/** \brief Internal Driver Status */
VAR(Cdd_Xbar_StatusType, CDD_XBAR_VAR_INIT) Cdd_Xbar_DriverStatus = CDD_XBAR_UNINIT;

#define CDD_XBAR_STOP_SEC_VAR_INIT_8
#include "Cdd_Xbar_MemMap.h"

#define CDD_XBAR_START_SEC_VAR_INIT_PTR
#include "Cdd_Xbar_MemMap.h"

/* Global configuration structure object */
P2CONST(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = NULL_PTR;

#define CDD_XBAR_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
#if ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) ||     \
     (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
/* Design: MCAL-28364 */
/** \brief Checks for DET error related to output line of input crossbar, output crossbar and CLB
 *crossbar.
 * \param[in] CrossbarType is the type of crossbar.
 * \param[in] DestLine is the output line of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Output_Valid_Firstgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                          P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) DestLine,
                                          VAR(uint8, AUTOMATIC) ServID);

/* Design: MCAL-28365 */
/** \brief Checks for DET error related to output line of EPWM crossbar, MINDB crossbar and ICL
 *crossbar.
 * \param[in] CrossbarType is the type of crossbar.
 * \param[in] DestLine is the output line of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Output_Valid_Secondgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                           P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) DestLine,
                                           VAR(uint8, AUTOMATIC) ServID);

/* Design: MCAL-28366 */
/** \brief Checks for DET error related to input line of input crossbar, output crossbar and CLB
 *crossbar.
 * \param[in] CrossbarType is the type of crossbar.
 * \param[in] InputLine is the input line of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Input_Valid_Firstgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                         P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine,
                                         VAR(uint8, AUTOMATIC) ServID);

/* Design: MCAL-28367 */
/** \brief Checks for DET error related to input line of EPWM crossbar, MINDB crossbar and ICL
 *crossbar.
 * \param[in] CrossbarType is the type of crossbar.
 * \param[in] InputLine is the input line of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Input_Valid_Secondgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                          P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine,
                                          VAR(uint8, AUTOMATIC) ServID);
#endif /* ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) \ \
          || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)   \ \
          || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U <                                    \ \
          CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28368 */
/** \brief Checks for DET error related to output crossbar .
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Output_Xbar_DetCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint8, AUTOMATIC) ServID);

/** \brief Checks for DET error related to Cdd_Xbar_OutStretchPulse API .
 * \param[in] CrossbarUnit is the symbolic name of the crossbar instance.
 * \param[in] ServID is the service ID of the API being called.
 * \param[in] TickStretch is the tick stretch value.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of error detection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutStretchPulseDetCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint8, AUTOMATIC) ServID,
                                     VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#endif /*STD_ON == CDD_XBAR_DEV_ERROR_DETECT*/

#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28369 */
/** \brief Checks for DET error during input crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Input_Xbar_Init_Priv(void);

/* Design: MCAL-28370 */
/** \brief Initializes input crossbar instance.
 * \param[in] config is the index of the input crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Input_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28371 */
/** \brief Checks for DET error during input crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the input crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, PortPinId.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_InSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                           VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28372 */
/** \brief Checks for DET error during input crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of the input crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar instance locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_InSelectLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28373 */
/** \brief Checks for DET error during input crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of the input crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar instance locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_InSelectLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28374 */
/** \brief Checks for DET error during output crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Output_Xbar_Init_Priv(void);

/* Design: MCAL-28375 */
/** \brief Initializes output crossbar instance.
 * \param[in] config is the index of the output crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Output_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28376 */
/** \brief Checks for DET error during output crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the output crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, Cdd_Xbar_Output_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28377 */
/** \brief Checks for DET error during output crossbar inversion selection.
 * \param[in] CrossbarUnit is the symbolic name of the output crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28378 */
/** \brief Checks for DET error during output crossbar inversion selection check.
 * \param[in] CrossbarUnit is the symbolic name of the output crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval TRUE if output is inverted.
 * \retval FALSE if errors are detected or output is not inverted.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28379 */
/** \brief Checks for DET error during output crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of any output crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output crossbar locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28380 */
/** \brief Checks for DET error during output crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of any output crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28381 */
/** \brief Checks for DET error during EPWM crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Epwm_Xbar_Init_Priv(void);

/* Design: MCAL-28382 */
/** \brief Initialize EPWM crossbar instance.
 * \param[in] config is the index of the EPWM crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Epwm_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28383 */
/** \brief Checks for DET error during EPWM crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the EPWM crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, Cdd_Xbar_Epwm_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_EpwmSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                             VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28384 */
/** \brief Checks for DET error during EPWM crossbar inversion selection.
 * \param[in] CrossbarUnit is the symbolic name of the EPWM crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_EpwmOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28385 */
/** \brief Checks for DET error during EPWM crossbar inversion selection check.
 * \param[in] CrossbarUnit is the symbolic name of the EPWM crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval TRUE if output is inverted.
 * \retval FALSE if errors are detected or output is not inverted.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28386 */
/** \brief Checks for DET error during EPWM crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of any EPWM crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output crossbar locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_EpwmLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28387 */
/** \brief Checks for DET error during EPWM crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of any EPWM crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS */

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28388 */
/** \brief Checks for DET error during CLB crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Clb_Xbar_Init_Priv(void);

/* Design: MCAL-28389 */
/** \brief Initializes CLB crossbar instance.
 * \param[in] config is the index of the CLB crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Clb_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28390 */
/** \brief Checks for DET error during CLB crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the CLB crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, Cdd_Xbar_Clb_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_ClbSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28391 */
/** \brief Checks for DET error during CLB crossbar inversion selection.
 * \param[in] CrossbarUnit is the symbolic name of the CLB crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_ClbOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28392 */
/** \brief Checks for DET error during CLB crossbar inversion selection check.
 * \param[in] CrossbarUnit is the symbolic name of the CLB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval TRUE if output is inverted.
 * \retval FALSE if errors are detected or output is not inverted.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28393 */
/** \brief Checks for DET error during CLB crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of any CLB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output crossbar locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_ClbLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28394 */
/** \brief Checks for DET error during CLB crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of any CLB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS */

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28395 */
/** \brief Checks for DET error during MINDB crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Mindb_Xbar_Init_Priv(void);

/* Design: MCAL-28396 */
/** \brief Initializes MINDB crossbar instance.
 * \param[in] config is the index of the MINDB crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Mindb_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28397 */
/** \brief Checks for DET error during MINDB crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the MINDB crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, Cdd_Xbar_Mindb_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_MdlSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28398 */
/** \brief Checks for DET error during MINDB crossbar inversion selection.
 * \param[in] CrossbarUnit is the symbolic name of the MINDB crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_MdlOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28399 */
/** \brief Checks for DET error during MINDB crossbar inversion selection check.
 * \param[in] CrossbarUnit is the symbolic name of the MINDB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval TRUE if output is inverted.
 * \retval FALSE if errors are detected or output is not inverted.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28400 */
/** \brief Checks for DET error during MINDB crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of any MINDB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output crossbar locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_MdlLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28401 */
/** \brief Checks for DET error during MINDB crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of any MINDB crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS */

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28402 */
/** \brief Checks for DET error during ICL crossbar initialization.
 * \param[in] None.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Icl_Xbar_Init_Priv(void);

/* Design: MCAL-28403 */
/** \brief Initializes ICL crossbar instance.
 * \param[in] config is the index of the ICL crossbar instance in configuration structure.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return None.
 *********************************************************************************************************************/
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Icl_Priv(VAR(uint8, AUTOMATIC) config);

/* Design: MCAL-28404 */
/** \brief Checks for DET error during ICL crossbar input selection.
 * \param[in] CrossbarUnit is the symbolic name of the ICL crossbar instance.
 * \param[in] InputLine is the crossbar input i.e, Cdd_Xbar_Icl_Xbar_Input_LinesType.
 * \param[in] Selection is the selection updation for the identified inputs, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_IclSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28405 */
/** \brief Checks for DET error during ICL crossbar inversion selection.
 * \param[in] CrossbarUnit is the symbolic name of the ICL crossbar instance.
 * \param[in] Selection is the selection for inversion enablement, TRUE or FALSE.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_IclOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-28406 */
/** \brief Checks for DET error during ICL crossbar inversion selection check.
 * \param[in] CrossbarUnit is the symbolic name of the ICL crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output inversion selection.
 * \retval TRUE if output is inverted.
 * \retval FALSE if errors are detected or output is not inverted.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_IclOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28407 */
/** \brief Checks for DET error during ICL crossbar locking.
 * \param[in] CrossbarUnit is the symbolic name of any ICL crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of output crossbar locking.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_IclLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);

/* Design: MCAL-28408 */
/** \brief Checks for DET error during ICL crossbar locking status check.
 * \param[in] CrossbarUnit is the symbolic name of any ICL crossbar instance.
 * \pre Preconditions - None.
 * \post Postconditions - None.
 * \return Status of input crossbar locking check.
 * \retval E_OK if errors are detected.
 * \retval E_NOT_OK if errors are not detected.
 *********************************************************************************************************************/
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_IclLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit);
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CDD_XBAR_START_SEC_CODE
#include "Cdd_Xbar_MemMap.h"

#if (STD_ON == CDD_XBAR_API_ENABLE)
#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
/*
 * Design: MCAL-25737, MCAL-25738
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_XBAR_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_GET_VERSION_INFO,
                              CDD_XBAR_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = CDD_XBAR_VENDOR_ID;
        VersionInfoPtr->moduleID         = CDD_XBAR_MODULE_ID;
        VersionInfoPtr->instanceID       = CDD_XBAR_INSTANCE_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_XBAR_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_XBAR_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_XBAR_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == CDD_XBAR_GET_VERSION_INFO_API */

/*
 * Design: MCAL-25733, MCAL-25734, MCAL-25735, MCAL-25736
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_Init(P2CONST(Cdd_Xbar_ConfigType, AUTOMATIC, CDD_XBAR_CONFIG_DATA) ConfigPtr)
{
    /* Config pointer initialised with NULL_PTR */
    P2CONST(Cdd_Xbar_ConfigType, AUTOMATIC, CDD_XBAR_CONFIG_DATA) config_ptr = NULL_PTR;
#if (STD_ON == CDD_XBAR_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        config_ptr = &CDD_XBAR_PRE_COMPILE_VARIANT_CONFIG;
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        config_ptr = ConfigPtr;
    }
#endif /*CDD_XBAR_PRE_COMPILE_VARIANT*/

    /* Cdd_Xbar module must not be initialized. Otherwise call the Det with CDD_XBAR_E_INIT_ALREADY
     */
    if (CDD_XBAR_UNINIT != Cdd_Xbar_DriverStatus)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INIT, CDD_XBAR_E_INIT_ALREADY);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == config_ptr)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        /* API is being called with invalid config param */
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INIT, CDD_XBAR_E_PARAM_POINTER);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    }
    else
    {
        Cdd_Xbar_Config = config_ptr;

/* Save the pointer to configuration */
/* Input XBar Configs */
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Input_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

/* Output XBar Configs */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Output_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */

        /* Lock Output Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->outConfigLock)
        {
            Cdd_Xbar_OutLock();
        }

/* EPWM XBar Configs */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Epwm_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS */

        /* Lock EPWM Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->epwmConfigLock)
        {
            Cdd_Xbar_EpwmLock();
        }

/* CLB XBar Configs */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Clb_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS */

        /* Lock CLB Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->clbConfigLock)
        {
            Cdd_Xbar_ClbLock();
        }

/* MINDB XBar Configs */
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Mindb_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS */

        /* Lock MINDB Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->mindbConfigLock)
        {
            Cdd_Xbar_MdlLock();
        }

        /* ICL XBar Configs */
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
        Cdd_Xbar_Icl_Xbar_Init_Priv();
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS */

        /* Lock ICL Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->iclConfigLock)
        {
            Cdd_Xbar_IclLock();
        }
        /* Set Init Done flag */
        Cdd_Xbar_DriverStatus = CDD_XBAR_INIT;
    }
}

/*
 * Design: MCAL-25739, MCAL-25740
 */
#if ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) ||     \
     (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_SelectInput(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                     VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_UNINIT);
    }
    else if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit), &InputLine,
                                                           CDD_XBAR_SID_SELECT_INPUT)) ||
             (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit), &InputLine,
                                                            CDD_XBAR_SID_SELECT_INPUT)))
    {
        /* This function will throw DET for invalid inputs */
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                retval = Cdd_Xbar_InSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                retval = Cdd_Xbar_OutSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                retval = Cdd_Xbar_EpwmSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                retval = Cdd_Xbar_ClbSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                retval = Cdd_Xbar_MdlSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                retval = Cdd_Xbar_IclSelect_Priv(CrossbarUnit, InputLine, Selection);
                break;
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
/* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                                      CDD_XBAR_E_PARAM_VALUE);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }

    return retval;
}

/*
 * Design: MCAL-25741, MCAL-25742
 */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchSelect(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) LatchEnable)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_LATCH_SELECT);

    if (E_NOT_OK == retval)
    {
        /* DET will be triggered by Cdd_Xbar_Output_Xbar_DetCheck*/
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT, CDD_XBAR_E_LOCK);
        retval = E_NOT_OK;
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputLatchSelect(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                &LatchEnable);
        }
    }

    return retval;
}

/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLatchSelectSts(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status        = FALSE;
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_LATCH_SELECT_STS);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_OutputLatchSelectSts(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return status;
}

/*
 * Design: MCAL-28141, MCAL-28142
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLatchFlagStatus(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status        = FALSE;
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_LATCH_FLAG_STATUS);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_OutputLatchFlagStatus(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return status;
}

/*
 * Design: MCAL-28143, MCAL-28144
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchFlagForce(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_LATCH_FLAG_FORCE);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputLatchFlagForce(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return retval;
}

/*
 * Design: MCAL-28145, MCAL-28146
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutLatchFlagClear(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_LATCH_FLAG_CLEAR);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputLatchFlagClear(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return retval;
}

/*
 * Design: MCAL-28147, MCAL-28148
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutInvBeforeLatch(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH);

    if (E_NOT_OK == retval)
    {
        /* DET will be triggered by Cdd_Xbar_Output_Xbar_DetCheck*/
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH,
                              CDD_XBAR_E_LOCK);
        retval = E_NOT_OK;
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputInvLatch(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
        }
    }

    return retval;
}

/*
 * Design: MCAL-28149, MCAL-28150
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutInvCheckBeforeLatch(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status        = FALSE;
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_INV_CHECK_BEFORE_LATCH);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_OutputInvLatchSts(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return status;
}

/*
 * Design: MCAL-25745, MCAL-25746
 */
FUNC(Cdd_Xbar_OutputlevelType, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputSignal(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Cdd_Xbar_OutputlevelType, AUTOMATIC) output = ((Cdd_Xbar_OutputlevelType)STD_LOW);
    VAR(Std_ReturnType, AUTOMATIC) retval           = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_OUTPUT_SIGNAL);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            /* Gather output from Output X-Bar Status Flag */
            output = Cdd_Xbar_OutOutputState(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return output;
}

/*
 * Design: MCAL-25747, MCAL-25748
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulse(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit,
                         VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (E_NOT_OK == Cdd_Xbar_OutStretchPulseDetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_STRETCH_PULSE, TickStretch))
    {
        /* DET will be triggered by Cdd_Xbar_OutStretchPulseDetCheck*/
        retval = E_NOT_OK;
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputStretchPulse(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                &TickStretch);
        }
    }

    return retval;
}

/*
 * Design: MCAL-25749, MCAL-25750
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulseClear(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval                = E_OK;
    VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch = CDD_XBAR_SYSTICKS_STRETCH_OFF;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR);

    if (E_NOT_OK == retval)
    {
        /* DET will be triggered by Cdd_Xbar_Output_Xbar_DetCheck*/
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR,
                              CDD_XBAR_E_LOCK);
        retval = E_NOT_OK;
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutputStretchPulse(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                &TickStretch);
        }
    }

    return retval;
}

/*
 * Design: MCAL-25751, MCAL-25752
 */
FUNC(Cdd_Xbar_TickStretchType, CDD_XBAR_CODE)
Cdd_Xbar_OutStretchPulseCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval            = E_OK;
    VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) stretch = CDD_XBAR_SYSTICKS_STRETCH_OFF;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    retval = Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, CDD_XBAR_SID_OUT_STRETCH_PULSE_CHECK);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

    if (E_OK == retval)
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            stretch = Cdd_Xbar_OutputStretchGet(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }

    return stretch;
}
#endif /* STD_ON == CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */

#if ((0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) ||   \
     (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
/*
 * Design: MCAL-25753, MCAL-25754
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_SelectOutputInversion(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_UNINIT);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
        {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                retval = Cdd_Xbar_OutOutputInvert_Priv(CrossbarUnit, Selection);
                break;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                retval = Cdd_Xbar_EpwmOutputInvert_Priv(CrossbarUnit, Selection);
                break;
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                retval = Cdd_Xbar_ClbOutputInvert_Priv(CrossbarUnit, Selection);
                break;
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                retval = Cdd_Xbar_MdlOutputInvert_Priv(CrossbarUnit, Selection);
                break;
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                retval = Cdd_Xbar_IclOutputInvert_Priv(CrossbarUnit, Selection);
                break;
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
/* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                                      CDD_XBAR_E_PARAM_VALUE);
#else
                retval = E_OK;
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return retval;
}

/*
 * Design: MCAL-25755, MCAL-25756
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_CheckOutputInversion(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_UNINIT);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
        {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                status = Cdd_Xbar_OutOutputInvertCheck_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                status = Cdd_Xbar_EpwmOutputInvertCheck_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                status = Cdd_Xbar_ClbOutputInvertCheck_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                status = Cdd_Xbar_MdlOutputInvertCheck_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                status = Cdd_Xbar_IclOutputInvertCheck_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
/* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                                      CDD_XBAR_E_PARAM_VALUE);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return status;
}
#endif /* ((0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) ||                                         \ \
          (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) || \ \
          (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/
/*
 * Design: MCAL-25757, MCAL-25758
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Lock(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_UNINIT);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                retval = Cdd_Xbar_InSelectLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                retval = Cdd_Xbar_OutLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                retval = Cdd_Xbar_EpwmLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                retval = Cdd_Xbar_ClbLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                retval = Cdd_Xbar_MdlLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                retval = Cdd_Xbar_IclLock_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
/* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK,
                                      CDD_XBAR_E_PARAM_VALUE);
#else
                retval = E_OK;
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return retval;
}

/*
 * Design: MCAL-25759, MCAL-25760
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_LockStatus(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_UNINIT);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                status = Cdd_Xbar_InSelectLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                status = Cdd_Xbar_OutLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                status = Cdd_Xbar_EpwmLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                status = Cdd_Xbar_ClbLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                status = Cdd_Xbar_MdlLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                status = Cdd_Xbar_IclLockStatus_Priv(CrossbarUnit);
                break;
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
                /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                                      CDD_XBAR_E_PARAM_VALUE);
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return status;
}
#endif /* ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) \ \
          || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)   \ \
          || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U <                                    \ \
          CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/

#if (STD_ON == CDD_XBAR_INPUT_FLAG_API)
/*
 * Design: MCAL-28151, MCAL-28152
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InputFlagStatus(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGSTATUS,
                              CDD_XBAR_E_UNINIT);
    }
    else if (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag)) > (uint16)18U) ||
             ((CDD_XBAR_INPUT_FLAG_BIT(InputFlag)) > (uint16)31U))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_InFlagStatus(InputFlag);
    }

    return status;
}

/*
 * Design: MCAL-28153, MCAL-28154
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE)
Cdd_Xbar_InputFlagClear(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGCLEAR, CDD_XBAR_E_UNINIT);
    }
    else if (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag)) > (uint16)18U) ||
             ((CDD_XBAR_INPUT_FLAG_BIT(InputFlag)) > (uint16)31U))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGCLEAR,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_InFlagClear(InputFlag);
        retval = E_OK;
    }

    return retval;
}

#endif /* STD_ON == CDD_XBAR_INPUT_FLAG_API */

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
#if ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) || \
     (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS) ||     \
     (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS))
/* Design: MCAL-28364 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Output_Valid_Firstgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                          P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                                          VAR(uint8, AUTOMATIC) ServID)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if ((CddXbarConf_CddXbarInputXbar == CrossbarType) &&
        ((*OutputLine > CDD_XBAR_INPUT_SELECT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarOutputXbar == CrossbarType) &&
             ((*OutputLine > CDD_XBAR_OUTPUT_XBAR_OUTPUT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarClbXbar == CrossbarType) &&
             ((*OutputLine > CDD_XBAR_CLB_XBAR_OUTPUT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}

/* Design: MCAL-28365 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Output_Valid_Secondgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                           P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                                           VAR(uint8, AUTOMATIC) ServID)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if ((CddXbarConf_CddXbarEpwmXbar == CrossbarType) &&
        ((*OutputLine > CDD_XBAR_EPWM_XBAR_OUTPUT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarMindbXbar == CrossbarType) &&
             ((*OutputLine > CDD_XBAR_MINDB_XBAR_OUTPUT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarIclXbar == CrossbarType) &&
             ((*OutputLine > CDD_XBAR_ICL_XBAR_OUTPUT_COUNT) || (*OutputLine == 0U)))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}

/* Design: MCAL-28366 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Input_Valid_Firstgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                         P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine,
                                         VAR(uint8, AUTOMATIC) ServID)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if ((CddXbarConf_CddXbarInputXbar == CrossbarType) && (0xFFFFU < *InputLine))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarOutputXbar == CrossbarType) &&
             ((CDD_XBAR_OUTPUT_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(*InputLine)) ||
              (CDD_XBAR_MAX_INPUT_LINES <= (*InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarClbXbar == CrossbarType) &&
             ((CDD_XBAR_CLB_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(*InputLine)) ||
              (CDD_XBAR_MAX_INPUT_LINES <= (*InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}

/* Design: MCAL-28367 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Type_Input_Valid_Secondgroup(VAR(uint8, AUTOMATIC) CrossbarType,
                                          P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine,
                                          VAR(uint8, AUTOMATIC) ServID)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if ((CddXbarConf_CddXbarEpwmXbar == CrossbarType) &&
        ((CDD_XBAR_EPWM_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(*InputLine)) ||
         (CDD_XBAR_MAX_INPUT_LINES <= (*InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarMindbXbar == CrossbarType) &&
             ((CDD_XBAR_MINDB_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(*InputLine)) ||
              (CDD_XBAR_MAX_INPUT_LINES <= (*InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarIclXbar == CrossbarType) &&
             ((CDD_XBAR_ICL_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(*InputLine)) ||
              (CDD_XBAR_MAX_INPUT_LINES <= (*InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}
#endif /* ((0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS) \ \
          || (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS) || (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)   \ \
          || (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS) || (0U <                                    \ \
          CDD_XBAR_ICL_XBAR_CONFIGURATIONS))*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28368 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_Output_Xbar_DetCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint8, AUTOMATIC) ServID)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }
    return retval;
}

static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutStretchPulseDetCheck(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint8, AUTOMATIC) ServID,
                                     VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

    if (E_NOT_OK == Cdd_Xbar_Output_Xbar_DetCheck(CrossbarUnit, ServID))
    {
        /* DET will be triggered by Cdd_Xbar_Output_Xbar_DetCheck*/
    }
    else if ((TickStretch != CDD_XBAR_SYSTICKS_STRETCH_OFF) && (TickStretch != CDD_XBAR_SYSTICKS_16) &&
             (TickStretch != CDD_XBAR_SYSTICKS_32))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_LOCK);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#endif /*STD_ON == CDD_XBAR_DEV_ERROR_DETECT*/

#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28369 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Input_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarInputXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputSelect,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarInputXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputSelect,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarInputXbar,
                                                               &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputLine,
                                                               CDD_XBAR_SID_INIT)) ||
                 (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CddXbarConf_CddXbarInputXbar,
                                                                &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputLine,
                                                                CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Input_Priv(config);
        }
    }
}

/* Design: MCAL-28370 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Input_Priv(VAR(uint8, AUTOMATIC) config)
{
    /* Select given Input Line */
    Cdd_Xbar_InSelect(&Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputSelect,
                      &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputLine, TRUE);
    /* Lock Crossbar Select Line */
    if (TRUE == Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].selectConfigLock)
    {
        Cdd_Xbar_InSelectLock(&Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputSelect);
    }
}
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28374 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Output_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarOutputXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarOutputXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Output_Priv(config);
        }
    }
}

/* Design: MCAL-28375 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Output_Priv(VAR(uint8, AUTOMATIC) config)
{
    VAR(uint8, AUTOMATIC) input;

    for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].input_count; input++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarOutputXbar,
                                                          &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].inputLine[input],
                                                          CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(
                         CddXbarConf_CddXbarOutputXbar, &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].inputLine[input],
                         CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            /* Select given Input Line */
            Cdd_Xbar_OutSelect(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                               &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].inputLine[input], TRUE);
        }
    }
    /* Select Output Inversion for chosen destination line */
    Cdd_Xbar_OutOutputInvert(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                             &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputInversion);

    /* Output Pulse Stretch */
    Cdd_Xbar_OutputStretchPulse(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputStretchPulse);

    /* Output Latch selection*/
    Cdd_Xbar_OutputLatchSelect(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                               &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLatch);

    /* Output inversion before latch selection*/
    Cdd_Xbar_OutputInvLatch(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine,
                            &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputInversionBeforeLatch);

    if (CDD_XBAR_OUTPUTCLEARFLAG == Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputFlag)
    {
        /* Output crossbar output latch clear during init */
        Cdd_Xbar_OutputLatchFlagClear(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine);
    }
    else if (CDD_XBAR_OUTPUTFORCEFLAG == Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputFlag)
    {
        /* Output crossbar output latch force during init */
        Cdd_Xbar_OutputLatchFlagForce(&Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine);
    }
    else
    {
        /* Output crossbar output latch in default state */
    }
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28381 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Epwm_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarEpwmXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputLine,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarEpwmXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputLine,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Epwm_Priv(config);
        }
    }
}

/* Design: MCAL-28382 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Epwm_Priv(VAR(uint8, AUTOMATIC) config)
{
    VAR(uint8, AUTOMATIC) input;

    for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].input_count; input++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarEpwmXbar,
                                                          &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].inputLine[input],
                                                          CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CddXbarConf_CddXbarEpwmXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].inputLine[input],
                                                           CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            /* Select given Input Line */
            Cdd_Xbar_EpwmSelect(&Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputLine,
                                &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].inputLine[input], TRUE);
        }
    }
    /* Select Output Inversion for chosen destination line */
    Cdd_Xbar_EpwmOutputInvert(&Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputLine,
                              &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputInversion);
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28388 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Clb_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_CLB_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarClbXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputLine,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarClbXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputLine,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Clb_Priv(config);
        }
    }
}

/* Design: MCAL-28389 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Clb_Priv(VAR(uint8, AUTOMATIC) config)
{
    VAR(uint8, AUTOMATIC) input;

    for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].input_count; input++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarClbXbar,
                                                          &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].inputLine[input],
                                                          CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CddXbarConf_CddXbarClbXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].inputLine[input],
                                                           CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            /* Select given Input Line */
            Cdd_Xbar_ClbSelect(&Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputLine,
                               &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].inputLine[input], TRUE);
        }
    }
    /* Select Output Inversion for chosen destination line */
    Cdd_Xbar_ClbOutputInvert(&Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputLine,
                             &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputInversion);
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28395 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Mindb_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarMindbXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputLine,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarMindbXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputLine,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Mindb_Priv(config);
        }
    }
}

/* Design: MCAL-28396 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Mindb_Priv(VAR(uint8, AUTOMATIC) config)
{
    VAR(uint8, AUTOMATIC) input;

    for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].input_count; input++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarMindbXbar,
                                                          &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].inputLine[input],
                                                          CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CddXbarConf_CddXbarMindbXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].inputLine[input],
                                                           CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            /* Select given Input Line */
            Cdd_Xbar_MdlSelect(&Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputLine,
                               &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].inputLine[input], TRUE);
        }
    }
    /* Select Output Inversion for chosen destination line */
    Cdd_Xbar_MdlOutputInvert(&Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputLine,
                             &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputInversion);
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28402 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Icl_Xbar_Init_Priv(void)
{
    VAR(uint8, AUTOMATIC) config;

    for (config = 0U; config < CDD_XBAR_ICL_XBAR_CONFIGURATIONS; config++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Output_Valid_Firstgroup(CddXbarConf_CddXbarIclXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputLine,
                                                           CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Output_Valid_Secondgroup(CddXbarConf_CddXbarIclXbar,
                                                            &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputLine,
                                                            CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid outputs selected */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            Cdd_Xbar_Icl_Priv(config);
        }
    }
}

/* Design: MCAL-28403 */
static FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Icl_Priv(VAR(uint8, AUTOMATIC) config)
{
    VAR(uint8, AUTOMATIC) input;

    for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].input_count; input++)
    {
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
        if ((E_OK != Cdd_Xbar_Type_Input_Valid_Firstgroup(CddXbarConf_CddXbarIclXbar,
                                                          &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].inputLine[input],
                                                          CDD_XBAR_SID_INIT)) ||
            (E_OK != Cdd_Xbar_Type_Input_Valid_Secondgroup(CddXbarConf_CddXbarIclXbar,
                                                           &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].inputLine[input],
                                                           CDD_XBAR_SID_INIT)))
        {
            /* This function will throw DET for invalid inputs */
        }
        else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
        {
            /* Select given Input Line */
            Cdd_Xbar_IclSelect(&Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputLine,
                               &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].inputLine[input], TRUE);
        }
    }
    /* Select Output Inversion for chosen destination line */
    Cdd_Xbar_IclOutputInvert(&Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputLine,
                             &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputInversion);
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28371 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_InSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                           VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_InSelectLockStatus(
                         &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_InSelect(&Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect,
                              &InputLine, Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28376 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutSelect(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &InputLine,
                Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28383 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_EpwmSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                             VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_EpwmLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_EpwmSelect(&Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                                &InputLine, Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28390 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_ClbSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_ClbLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_ClbSelect(&Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                               &InputLine, Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28397 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_MdlSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_MdlLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_MdlSelect(&Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                               &InputLine, Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28404 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_IclSelect_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(uint16, AUTOMATIC) InputLine,
                            VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_IclLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_IclSelect(&Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine,
                               &InputLine, Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28377 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_OutOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_OutOutputInvert(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28384 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_EpwmOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_EpwmLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_EpwmOutputInvert(
                &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28391 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_ClbOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_ClbLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_ClbOutputInvert(
                &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28398 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_MdlOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_MdlLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_MdlOutputInvert(
                &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28405 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE)
    Cdd_Xbar_IclOutputInvert_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_IclLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_IclOutputInvert(
                &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine, &Selection);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28378 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_OutOutputInvertCheck(
                &Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28385 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_EpwmOutputInvertCheck(
                &Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28392 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_ClbOutputInvertCheck(
                &Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28399 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_MdlOutputInvertCheck(
                &Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
static FUNC(boolean, CDD_XBAR_CODE)
    /* Design: MCAL-28406 */
    Cdd_Xbar_IclOutputInvertCheck_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_IclOutputInvertCheck(
                &Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28372 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_InSelectLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_InSelectLockStatus(
                         &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            Cdd_Xbar_InSelectLock(
                &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect);
            retval = E_OK;
        }
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28379 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_OutLock();
        retval = E_OK;
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28386 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_EpwmLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_EpwmLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_EpwmLock();
        retval = E_OK;
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28393 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_ClbLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_ClbLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_ClbLock();
        retval = E_OK;
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28400 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_MdlLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_MdlLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_MdlLock();
        retval = E_OK;
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28407 */
static FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_IclLock_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (TRUE == Cdd_Xbar_IclLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_IclLock();
        retval = E_OK;
    }
    return retval;
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28373 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_InSelectLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS > CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
        {
            status = Cdd_Xbar_InSelectLockStatus(
                &Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect);
        }
    }
    return status;
}
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-28380 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_OutLockStatus();
    }
    return status;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-28387 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_EpwmLockStatus();
    }
    return status;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28394 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_ClbLockStatus();
    }
    return status;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28401 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_MdlLockStatus();
    }
    return status;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28408 */
static FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_IclLockStatus_Priv(VAR(Cdd_Xbar_Type, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS,
                              CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_IclLockStatus();
    }
    return status;
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#endif /* STD_ON == CDD_XBAR_API_ENABLE */

#define CDD_XBAR_STOP_SEC_CODE
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar.c
 *********************************************************************************************************************/
