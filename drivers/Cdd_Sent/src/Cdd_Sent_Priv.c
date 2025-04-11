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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Sent_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains private function definitions for CDD SENT
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent_Priv.h"
#include "Cdd_Sent_Reg_Access.h"
#if (STD_ON == CDD_SENT_CFG_DEM_ENABLE)
    #include "Dem.h"
#endif /*CDD_SENT_CFG_DEM_ENABLE*/
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
#define CDD_SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"
P2VAR(Cdd_Sent_ConfigType, CDD_SENT_VAR_FAST_NO_INIT, CDD_SENT_VAR_FAST_NO_INIT) Cdd_Sent_DrvObjPtr;
#define CDD_SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_CODE
#include "Cdd_Sent_MemMap.h"
FUNC(void, CDD_SENT_CODE) Cdd_Sent_SetDriverObjPtr( Cdd_Sent_ConfigType* Set_DrvObj)
{
    Cdd_Sent_DrvObjPtr = Set_DrvObj;
}

/*
 *Design: MCAL-xxxxx
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwInitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
		uint32	BaseAddress = ConfigPtr->Cdd_SentBaseAddress;
		
        /* Disable SENT receiver */
		Cdd_Sent_disableSentReceiver(BaseAddress);
		
		Cdd_Sent_clearInterruptFlag(BaseAddress, (0xFFFFFFFFU));

		/* Enable interrupt*/
		Cdd_Sent_enableInterrupt(BaseAddress, ConfigPtr->Enable_Fast_Interrupt);

		/* Enable Error interrupt*/
		if(ConfigPtr->Enable_Fast_Interrupt == SENT_REINT_RFAST_S1DV_E)
		{
			Cdd_Sent_enableInterrupt(BaseAddress, SENSOR_1_ERROR_INTERRUPTS);
		}
		else if(ConfigPtr->Enable_Fast_Interrupt == SENT_REINT_RFAST_S2DV_E)
		{
			Cdd_Sent_enableInterrupt(BaseAddress, SENSOR_2_ERROR_INTERRUPTS);
		}
		else if(ConfigPtr->Enable_Fast_Interrupt == SENT_REINT_RFAST_S3DV_E)
		{
			Cdd_Sent_enableInterrupt(BaseAddress, SENSOR_3_ERROR_INTERRUPTS);
		}
		else if(ConfigPtr->Enable_Fast_Interrupt == SENT_REINT_RFAST_S4DV_E)
		{
			Cdd_Sent_enableInterrupt(BaseAddress, SENSOR_4_ERROR_INTERRUPTS);
		}
		else
		{
			Cdd_Sent_enableInterrupt(BaseAddress, 0x0U);
		}

		/* Enable interrupt*/
		Cdd_Sent_enableInterrupt(BaseAddress, ConfigPtr->Enable_Slow_Interrupt);

		/* CRC setting As per the configuration */
		if (CDD_SENT_CRC_NONE == ConfigPtr->Cdd_SentCRCType)
		{
			/* Disable CRC */
			HWREG(BaseAddress + SENT_O_RCFG) &= ~SENT_RCFG_RX_CRCENB;
		}
		else
		{
			/* Enable CRC */
			Cdd_Sent_RegBitSet32(BaseAddress + SENT_O_RCFG,
						SENT_RCFG_RX_CRCENB);

			/* Configuring CRC Type */	
			Cdd_Sent_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG),
									SENT_RCFG_RX_CRCTYPE,0,
									ConfigPtr->Cdd_SentCRCType);
			
			/* Configuring CRC width */
			Cdd_Sent_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG),
									SENT_RCFG_CRC_WIDTH_M,
									SENT_RCFG_CRC_WIDTH_S,
									ConfigPtr->Cdd_SentCRCWidth);
			/* Configuring CRC status*/
			Cdd_Sent_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG),
							SENT_RCFG_RX_CRC_WITH_STATUS,
							0,
							ConfigPtr->Cdd_SentCRCWithStatus);
		}

		/* Configuring Tick clock */
		HWREG(BaseAddress+SENT_O_RCFG) = ConfigPtr->Cdd_SentClockTick<<SENT_RCFG_TTCLK_S;

        /* Configuring GFlit */
		Cdd_Sent_setGFILTClockCycle(BaseAddress, ConfigPtr->GlitchFilter);

		/* set data nibbles count*/
		Cdd_Sent_setDataNibble(BaseAddress, ConfigPtr->Cdd_SentDataNibblesCount);
		
		/* Map data nibbles to data 0*/
		Cdd_Sent_setDataSortingFormat(BaseAddress, 
				CDD_SENT_RECEIVER_DATA0, CDD_SENT_DATAX_NIB0, CDD_SENT_DATA_NIBBLE6);
		Cdd_Sent_setDataSortingFormat(BaseAddress,\
				CDD_SENT_RECEIVER_DATA0,CDD_SENT_DATAX_NIB1, CDD_SENT_DATA_NIBBLE5);
		Cdd_Sent_setDataSortingFormat(BaseAddress, \
				CDD_SENT_RECEIVER_DATA0, CDD_SENT_DATAX_NIB2, CDD_SENT_DATA_NIBBLE4);
		Cdd_Sent_setDataSortingFormat(BaseAddress, \
				CDD_SENT_RECEIVER_DATA0, CDD_SENT_DATAX_NIB3, CDD_SENT_DATA_NIBBLE3);
		Cdd_Sent_setDataSortingFormat(BaseAddress, \
				CDD_SENT_RECEIVER_DATA0, CDD_SENT_DATAX_NIB4, CDD_SENT_DATA_NIBBLE2);
		Cdd_Sent_setDataSortingFormat(BaseAddress, \
				CDD_SENT_RECEIVER_DATA0, CDD_SENT_DATAX_NIB5, CDD_SENT_DATA_NIBBLE1);

		/* Configuring the Pause pulse based on the configuration. */
		if (CDD_SENT_CRC_NONE == ConfigPtr->Cdd_SentCRCType)
		{
			/* Disable Pause Pulse */
			Cdd_Sent_RegBitClear32((BaseAddress + SENT_O_RCFG),
									SENT_RCFG_RX_PPENB);
		}
		else
		{
			/* Enable Pause Pulse */
			Cdd_Sent_RegBitSet32((BaseAddress + SENT_O_RCFG),
									SENT_RCFG_RX_PPENB);
		}

		/* Configuring the Accepting error data based on the configuration. */
		if (TRUE == ConfigPtr->AcceptErrorData)
		{
			/* Enable Error date to written into fifo */
			Cdd_Sent_RegBitClear32((BaseAddress + SENT_O_RCFG2),
									SENT_RCFG2_NOWR_ERRDATA);
		}
		else
		{
			/* Disable Error date to written into memory */
			Cdd_Sent_RegBitSet32((BaseAddress + SENT_O_RCFG2),
									SENT_RCFG2_NOWR_ERRDATA);
		}
		
#if ENABLE_TIMESTAMP
		/* Enable Timestamp */
		Cdd_Sent_RegBitClear32((BaseAddress + SENT_O_RCFG2),
								SENT_RCFG2_TSTAMP_DIS);
#endif

		/* Always Enable the Direct mode */
		Sent_ConfigureFifoMode(BaseAddress, SENT_DIRECT_MEMMAPPED);
} 

/*
 *Design: MCAL-xxxxx
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwDenitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
	uint32	Base_Address = ConfigPtr->Cdd_SentBaseAddress;
	/* Disable SENT receiver */
	Cdd_Sent_RegBitClear32((Base_Address + SENT_O_RCFG),
								SENT_RCFG_RX_ENB);
}

void Cdd_Sent_ProcessISR(Cdd_SentInstance SentInstance)
{

	PduInfoType Info;
	PduIdType id = 0;
	uint8 Channel_count = (uint8 )0U;
	Cdd_Sent_HWUnitType* Sent_Instance_Object= Cdd_Sent_DrvObjPtr->Cdd_Sent_HWUnit[SentInstance];
	uint32 Sent_Interrupt_Status= HWREG(Sent_Instance_Object->Cdd_SentBaseAddress+0x40U);
	uint32 Interrupt_Enable_Status = HWREG(Sent_Instance_Object->Cdd_SentBaseAddress+0x44U);
	Cdd_Sent_ChannelConfigType *ChannelConfig = NULL;
	
	if(((Sent_Interrupt_Status & SENT_REINT_RFAST_S1DV_E) == SENT_REINT_RFAST_S1DV_E) && ((Interrupt_Enable_Status  & SENT_REINT_RFAST_S1DV_E) == SENT_REINT_RFAST_S1DV_E))
	{
		for(Channel_count = 0U; Channel_count < Sent_Instance_Object->Cdd_SentChannelCount; Channel_count++)
		{
			ChannelConfig = Sent_Instance_Object->Cdd_SentChannelConfigList[Channel_count];
			Cdd_Sent_Data_Buffer Fast_Buffer_Object=ChannelConfig->Cdd_Sent_Buffer_Data;

			if(ChannelConfig->Cdd_SentChannelType == FAST_CHANNEL)
			{
			#if ENABLE_TIMESTAMP
			if(ChannelConfig->EnableTimeStamp == TRUE)
			{
				Fast_Buffer_Object.Timestamp[0]=
				Cdd_Sent_getFrameData(Sent_Instance_Object->Cdd_SentBaseAddress, \
				(((uint16)Sent_Instance_Object->Cdd_SentChannelConfigList[Channel_count]->\
				Cdd_SentSensorType) * TIMESTAMP_MEMDATA));
			}
			else
			{
				/* Do Nothing*/
			}
			#endif
			Fast_Buffer_Object.Data_Buffer[0]=
			Cdd_Sent_getFrameData(Sent_Instance_Object->Cdd_SentBaseAddress, \
			(((uint16)Sent_Instance_Object->Cdd_SentChannelConfigList[Channel_count]->\
			Cdd_SentSensorType) * TIMESTAMP_MEMDATA) + DATA0_MEMDATA);
				
				if(Sent_Instance_Object->Cdd_SentUserCallbackFunction != NULL_PTR)
				{
					Info.SduDataPtr= (uint8 *)&Fast_Buffer_Object;
					Info.MetaDataPtr=NULL_PTR;
					Info.SduLength=4;
					#if ENABLE_TIMESTAMP
					if(ChannelConfig->EnableTimeStamp == TRUE)
					{
						Info.SduLength=8;
					}
					else
					{
						/* Do Nothing*/
					}
					#endif
					id= ChannelConfig->Cdd_Sent_channelID;

					Sent_Instance_Object->Cdd_SentUserCallbackFunction(id, &Info);
				}
				else
				{
					/*Do Nothing*/
				}
				#ifdef CDD_E_HARDWARE_ERROR
					(void)Dem_SetEventStatus(CDD_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
				#endif

				break;
			}
			else
			{
				/* Do Nothing*/
			}
		}
	}
	else if(((Sent_Interrupt_Status & SENT_REINT_RSLOW_DV_E) == SENT_REINT_RSLOW_DV_E) && ((Interrupt_Enable_Status  & SENT_REINT_RSLOW_DV_E) == SENT_REINT_RSLOW_DV_E))
	{
		for(Channel_count = 0U; Channel_count < Sent_Instance_Object->Cdd_SentChannelCount; Channel_count++)
		{
			ChannelConfig = Sent_Instance_Object->Cdd_SentChannelConfigList[Channel_count];
			Cdd_Sent_Data_Buffer Slow_Buffer_Object=ChannelConfig->Cdd_Sent_Buffer_Data;

			if(((uint32) ChannelConfig->Cdd_Sent_MessageID) == ((uint32) Cdd_Sent_getMessageID(SentInstance)))
			{
				Slow_Buffer_Object.Data_Buffer[0]= Cdd_Sent_getSlowData(SentInstance);

				if(Sent_Instance_Object->Cdd_SentUserCallbackFunction != NULL_PTR)
				{
					Info.SduDataPtr= (uint8 *)&Slow_Buffer_Object.Data_Buffer[0];
					Info.MetaDataPtr=NULL_PTR;
					Info.SduLength=2;
					id= ChannelConfig->Cdd_Sent_channelID;

					Sent_Instance_Object->Cdd_SentUserCallbackFunction(id, &Info);
				}
				else
				{
					/* Do Nothing*/
				}

				#ifdef CDD_E_HARDWARE_ERROR
					(void)Dem_SetEventStatus(CDD_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
				#endif

				break;
			}
			else
			{
				/* Do Nothing*/
			}
		}
	}
	else
	{
		#ifdef CDD_E_HARDWARE_ERROR
                (void)Dem_SetEventStatus(CDD_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
		#else
			/* Do Nothing*/
        #endif
	}

	Cdd_Sent_clearInterruptFlag(SENT1CSENT_BASE, (0xFFFFFFFFU));
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define CDD_SENT_STOP_SEC_CODE
#include "Cdd_Sent_MemMap.h"


/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Priv.c
 *********************************************************************************************************************/
