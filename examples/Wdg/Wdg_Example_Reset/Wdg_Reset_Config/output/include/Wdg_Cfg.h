/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Wdg_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                     
 *********************************************************************************************************************/
#ifndef WDG_CFG_H
#define WDG_CFG_H

/**
 * \addtogroup WDG
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif
 
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * \brief Wdg Driver Configuration SW Version Info.
 *********************************************************************************************************************/
#define WDG_CFG_MAJOR_VERSION               (2U)
#define WDG_CFG_MINOR_VERSION               (0U)
#define WDG_CFG_PATCH_VERSION               (1U)


/*********************************************************************************************************************
 * \brief WDG Build Variant.
 * Build variants.(i.e Precompile, postbuild or linktime)
 *********************************************************************************************************************/

#define WDG_VARIANT_PRE_COMPILE       (STD_OFF)
#define WDG_VARIANT_POST_BUILD        (STD_ON)
#define WDG_VARIANT_LINK_TIME         (STD_OFF)



 /*
 * Design: MCAL-25217, MCAL-25219, MCAL-25246
 */
/*********************************************************************************************************************
 * \brief WDG configuration index
 *********************************************************************************************************************/
#define WDG_CFG_ID          (0x1U)
#define WDG_MAX_INSTANCES   (1U)


/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define WDG_DEM_ENABLE    (STD_ON)

 /*
 * Design: MCAL-25229, MCAL-25272, MCAL-25273
 */

/** \brief WDG DEM Event Configuration: WDG Disable feature rejected error */
#define WDG_E_DISABLE_REJECTED  (DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED)


 /*
 * Design: MCAL-25226, MCAL-25272, MCAL-25274
 */

/** \brief WDG DEM Event Configuration: WDG Mode failed error */
#define WDG_E_MODE_FAILED  (DemConf_DemEventParameter_WDG_E_MODE_FAILED)


/*********************************************************************************************************************
 * \brief Enable/Disable Development Error Detection.
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25276
 */
#define WDG_DEV_ERROR_DETECT       (STD_ON)

/*********************************************************************************************************************
 * \brief Enable/Disable Wdg_GetVersionInfo().
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25283
 */
#define WDG_GET_VERSION_INFO_API   (STD_ON)


/*********************************************************************************************************************
 * \brief Watchdog Initial Timeout and Watchdog Maximum Timeout.
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25308, MCAL-25309
 */
#define WDG_INITIAL_TIMEOUT        (uint16) (13)
#define WDG_MAX_TIMEOUT            (uint16) (3342)


/*********************************************************************************************************************
 * \brief Watchdog Maximum Windowed Threshold value
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25310
 */
#define WDG_MAX_THRESHOLD_VALUE    (uint16) (0xFFU)

/*********************************************************************************************************************
 * \brief Watchdog Disable Allowed
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25277
 */
#define WDG_DISABLE_ALLOWED        (STD_ON)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

 /*
 * Design: MCAL-25245
 */
 /** \brief This is a Watchdog status type value */
typedef enum
{
    /** \brief Watchdog driver is uninitialized. State on power on before invoking Wdg_Init() */
    WDG_UNINIT = 0U,
    /** \brief Watchdog driver is in idle state. Default state when WDG timer regs are not being programmed */
    WDG_IDLE = 1U,
    /** \brief Watchdog driver is reprogramming the WD to trigger the watchdog */
    WDG_BUSY = 2U
} Wdg_StatusType;


 /*
 * Design: MCAL-25303
 */
 /** \brief Watchdog module Reaction if watchdog counter reaches the maximum value */
typedef enum
{
    /** \brief Watchdog can generate a reset signal */
    WDG_GENERATE_RESET = 0U,
    /** \brief Watchdog can generate an interrupt signal; reset signal is disabled */
    WDG_GENERATE_INTERRUPT = 1U
}Wdg_Reaction;


 /*
 * Design: MCAL-25304
 */
 /** \brief Wdg_PreDivider  determines the watchdog clock pre-divider, which is the first of the two dividers 
  *         between INTOSC1 and the watchdog counter clock (WDCLK)
  */
typedef enum
{
    /** \brief PREDIVCLK = INTOSC1 / 2 */
    WDG_PREDIV_2    = 0x800, 
    /** \brief PREDIVCLK = INTOSC1 / 4 */
    WDG_PREDIV_4    = 0x900, 
    /** \brief PREDIVCLK = INTOSC1 / 8 */
    WDG_PREDIV_8    = 0xA00,
    /** \brief PREDIVCLK = INTOSC1 / 16 */
    WDG_PREDIV_16   = 0xB00, 
    /** \brief PREDIVCLK = INTOSC1 / 32 */
    WDG_PREDIV_32   = 0xC00, 
    /** \brief PREDIVCLK = INTOSC1 / 64 */
    WDG_PREDIV_64   = 0xD00,
    /** \brief PREDIVCLK = INTOSC1 / 128 */
    WDG_PREDIV_128  = 0xE00, 
    /** \brief PREDIVCLK = INTOSC1 / 256 */
    WDG_PREDIV_256  = 0xF00, 
    /** \brief PREDIVCLK = INTOSC1 / 512 */
    WDG_PREDIV_512  = 0x000, 
    /** \brief PREDIVCLK = INTOSC1 / 1024 */
    WDG_PREDIV_1024 = 0x100,
    /** \brief PREDIVCLK = INTOSC1 / 2048 */
    WDG_PREDIV_2048 = 0x200,
    /** \brief PREDIVCLK = INTOSC1 / 4096 */
    WDG_PREDIV_4096 = 0x300
} Wdg_PreDivider;


 /*
 * Design: MCAL-25305
 */
 /** \brief Wdg_PreScaler determines the watchdog clock prescaler, which is the second of the two dividers 
  *         between INTOSC1 and the watchdog counter clock (WDCLK).
  */
typedef enum
{
    /** \brief WDCLK = PREDIVCLK / 1 */
    WDG_PRESCALE_1  = 1U,
    /** \brief WDCLK = PREDIVCLK / 2 */
    WDG_PRESCALE_2  = 2U, 
    /** \brief WDCLK = PREDIVCLK / 4 */
    WDG_PRESCALE_4  = 3U,
    /** \brief WDCLK = PREDIVCLK / 8 */ 
    WDG_PRESCALE_8  = 4U,
    /** \brief WDCLK = PREDIVCLK / 16 */ 
    WDG_PRESCALE_16 = 5U,
    /** \brief WDCLK = PREDIVCLK / 32 */
    WDG_PRESCALE_32 = 6U,
    /** \brief WDCLK = PREDIVCLK / 64 */
    WDG_PRESCALE_64 = 7U
} Wdg_PreScaler;


 /*
 * Design: MCAL-25302
 */
 /** \brief Mode Information Type */
typedef struct
{
    /** \brief Reaction type : Reset or Interrupt */
    Wdg_Reaction     Reaction;
    /** \brief It specifies lower limit of the watchdog counter reset  window */
    uint16           Threshold;
    /** \brief It specifies maximum timeout value */
    uint16          Timeout;
    /** \brief The first of the two dividers between INTOSC1 and the watchdog counter clock (WDCLK) */
    Wdg_PreDivider   PreDivider;
    /** \brief The second of the two dividers between INTOSC1 and the watchdog counter clock (WDCLK) */
    Wdg_PreScaler    PreScaler;
} Wdg_ModeInfoType;


/** \brief WDG config root structure */
typedef struct Wdg_ConfigType_s
{
    /** \brief Default wdg mode */
    WdgIf_ModeType   Wdg_DefaultMode;
    /** \brief Instance ID */  
    uint8            Wdg_InstanceId;
    /** \brief Initial timeout  */
    uint16           Wdg_InitialTimeOut;
    /** \brief Maximum timeout */
    uint16           Wdg_MaxTimeOut;
    /** \brief Fast mode configuration */
    Wdg_ModeInfoType Wdg_FastModeCfg;
    /** \brief Slow mode configuration */
    Wdg_ModeInfoType Wdg_SlowModeCfg;
} Wdg_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/


 /** \brief Wdg config pointer */
extern const struct Wdg_ConfigType_s  Wdg_Config;


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 
#ifdef __cplusplus
}
#endif

/**
* @}
*/


#endif /* WDG_CFG_H */
/*********************************************************************************************************************
 *  End of File: Wdg_Cfg.h
 *********************************************************************************************************************/
