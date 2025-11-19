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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Dio_Lcfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated link time configuration data
 *********************************************************************************************************************/
[!SKIPFILE "node:value(as:modconf('Dio')[as:path(node:dtos(.))='/TI_F29H85x/Dio']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantLinkTime'"!]
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 /* Design: MCAL-22532 */
#include "Dio.h"

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
#if ((DIO_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    || (DIO_SW_MINOR_VERSION !=([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Dio_Lcfg.c and Dio.h are inconsistent!"
#endif

 #if ((DIO_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||\
    (DIO_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Dio_Lcfg.c and Dio_Cfg.h are inconsistent!"
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
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Object Definitions
 *********************************************************************************************************************/
[!SELECT "as:modconf('Dio')[as:path(node:dtos(.))='/TI_F29H85x/Dio']"!][!//
[!IF "num:i(count(DioConfig/DioPort/*/DioChannelGroup/*)) > 0"!][!//
#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
/* Global Data */
[!LOOP "DioConfig/DioPort/*"!]
[!LOOP "DioChannelGroup/*"!][!//
 /* Design : MCAL-22510, MCAL-22511 */
CONST(Dio_ChannelGroupType, DIO_CONFIG_DATA) [!"DioChannelGroupIdentification"!] =
{
    .port =   ((Dio_PortType) [!"concat('GPIO_PORT_', translate(../../DioPortId, '01234567', 'ABCDEFGH'))"!]),
    .mask =   ((Dio_PortLevelType) [!"num:inttohex(DioPortMask,8)"!]U),
    .offset = ((uint8) [!"num:i(DioPortOffset)"!]U),
};
[!ENDLOOP!][!ENDLOOP!]


[!VAR "var1" = "0"!][!//
P2CONST(struct Dio_ChannelGroupType_s, DIO_CONFIG_DATA, DIO_CONFIG_DATA) Dio_ChannelGroupRef[DIO_MAX_NO_OF_CHANNEL_GROUPS] =
{[!LOOP "DioConfig/DioPort/*"!][!LOOP "DioChannelGroup/*"!]
    [[!"num:i($var1)"!]] = ((P2CONST(Dio_ChannelGroupType, DIO_CONFIG_DATA, DIO_CONFIG_DATA)) (&[!"DioChannelGroupIdentification"!])),
[!VAR "var1" = "$var1+1"!][!//
[!ENDLOOP!][!ENDLOOP!]};

#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
[!ENDIF!][!ENDSELECT!][!//
/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * End of File: Dio_Lcfg.c
 *********************************************************************************************************************/
