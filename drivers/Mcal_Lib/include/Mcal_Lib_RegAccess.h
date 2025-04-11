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
 *  File:       Mcal_Lib_RegAccess.h
 *  Generator:  None
 *
 *  Description:  This file contains macros for register access
 *********************************************************************************************************************/
#ifndef MCAL_LIB_REG_ACCESS_H
#define MCAL_LIB_REG_ACCESS_H
#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 #include "Std_Types.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief This macro calls read field API for 32 bit register. It also
 *        frames the mask and shift from register field macro.
 *
 * \param[in] regAddr Register Address.
 * \param[in] REG_FIELD Peripheral register bit field name, from which
 *                      specified bit-field value has to be read.
 * \pre None
 * \post None
 * \return Value of the bit-field
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
#define MCAL_LIB_REG_MF_READ32(regAddr, REG_FIELD)                           \
    (McalLib_RegMFReadRaw32((uint32) (regAddr), (uint32) REG_FIELD ## _MASK, \
                        (uint32) REG_FIELD ## _SHIFT))
/** \brief This macro calls read-modify-write API for 32 bit register. It also
 *        frames the mask and shift from register field macro.
 *
 * \param[in] regAddr Register Address.
 * \param[in] REG_FIELD Peripheral register bit field name, from which
 *                      specified bit-field value has to be read.
 * \param[in] fieldVal Value of the field which has to be set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
#define MCAL_LIB_REG_MF_WRITE32(regAddr, REG_FIELD, fieldVal)                   \
    (McalLib_RegMFWriteRaw32((uint32) (regAddr), (uint32) REG_FIELD ## _MASK,  \
                        (uint32) REG_FIELD ## _SHIFT, (uint32) (fieldVal)))

/** \brief This macro reads a 32-bit value from a hardware register
 *        and returns the value.
 *
 * \param[in] regAddr Register Address.
 * \pre None
 * \post None
 * \return Unsigned 32-bit value read from a register.
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
#define MCAL_LIB_REG_READ32(regAddr)                 \
    (uint32)(McalLib_RegReadRaw32((uint32) (regAddr)))


/** \brief This macro writes a 32-bit value to a hardware register.
 *
 * \param[in] regAddr Address of the memory mapped hardware register.
 * \param[in] value unsigned 32-bit value which has to be written to the
 *                  register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
#define MCAL_LIB_REG_WRITE32(regAddr, value)                     \
    (McalLib_RegWriteRaw32((uint32) (regAddr), (uint32) (value)))

/** \brief Macro to write a specific field value. This macro first clears the
 *        specified field value and then performs "OR" of the field value which
 *        is shifted and masked. This will set the field value at its
 *        desired position.
 *
 * \param[in] regVal 32-bit variable containing the register value.
 * \param[in] REG_FIELD Peripheral register bit field name, from which
 *                      specified bit-field value has to be read.
 * \param[in] fieldVal Value of the field which has to be set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
#define MCAL_LIB_REG_FIELD_SET32(regVal, REG_FIELD, fieldVal)                       \
    ((regVal) = ((regVal) & (uint32) (~(uint32) REG_FIELD##_MASK)) |       \
                    ((((uint32) (fieldVal)) << (uint32) REG_FIELD##_SHIFT) \
                     & (uint32) REG_FIELD##_MASK))

/** \brief Macro to extract a field value. This macro extracts the field value
 *        from a 32-bit variable (which contains the register value).
 *        This macro does not read from actual register address, and only
 *        extracts the field from a variable.
 *
 * \param[in] regVal 32-bit variable containing the register value.
 * \param[in] REG_FIELD Peripheral register bit field name, whose value has to
 *                   be extracted.
 * \pre None
 * \post None
 * \return Unsigned 32-bit field value read from a variable.
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
#define MCAL_LIB_REG_FIELD_GET(regVal, REG_FIELD)                                       \
    (((regVal) & (uint32) REG_FIELD ## _MASK) >> (uint32) REG_FIELD ## _SHIFT)
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief This function reads a 16 bit register, masks specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint16.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint16, MCAL_LIB_CODE) McalLib_RegMFReadRaw16(uint32 addr,\
                                        uint16 mask,\
                                        uint16 shift);

/** \brief This function writes a 16 bit register masking specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \param[in] value Value to write in the memory mapped hardware register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegMFWriteRaw16(uint32 addr,\
                                      uint16 mask,\
                                      uint16 shift,\
                                      uint16 value);

/** \brief This function reads a 16 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint16.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint16, MCAL_LIB_CODE) McalLib_RegReadRaw16(uint32 addr);

/** \brief This function writes a 16 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 16-bit register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw16(uint32 addr, uint16 value);


/** \brief This function sets one of the bit in 16 bit register
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask mask of the bit to set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitSet16(uint32 addr, uint16 mask);

/** \brief This function clears one of the bit in 16 bit register
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask mask of the bit to clear.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitClear16(uint32 addr, uint16 mask);

/** \brief This function writes a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 32-bit register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw32(uint32 addr, uint32 value);


/** \brief This function writes a 8 bit register value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write 8 bits to the 32-bit register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw8(uint32 addr, uint8 value);


/** \brief This function writes a 32 bit register masking specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \param[in] value Value to write in the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegMFWriteRaw32(uint32 addr,
                                      uint32 mask,
                                      uint32 shift,
                                      uint32 value);


/** \brief This function reads a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint32, MCAL_LIB_CODE) McalLib_RegReadRaw32(uint32 addr);


/** \brief This function reads a 8 bits of 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[out] None
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint8, MCAL_LIB_CODE) McalLib_RegReadRaw8(uint32 addr);

/** \brief This function reads a 32 bit register, masks specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(uint32, MCAL_LIB_CODE) McalLib_RegMFReadRaw32(uint32 addr, \
    uint32 mask, \
    uint32 shift);
/** \brief This function clears a 32 bit register masking field.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitClear32(uint32 addr, \
    uint32 mask);

/** \brief This function Set a 32 bit register masking field.
*
* \param[in] addr Address of the memory mapped hardware register.
* \param[in] mask Mask for the bit field.
* \pre None
* \post None
* \return None
* \retval None
*
******************************************************************************/
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitSet32(uint32 addr, \
    uint32 mask);
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint16, MCAL_LIB_CODE) McalLib_RegMFReadRaw16(uint32 addr,\
    uint16 mask,\
    uint16 shift)
{
uint16 regVal = *(volatile uint16 *)addr;
regVal = (regVal & mask) >> shift;
return (regVal);
}


LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegMFWriteRaw16(uint32 addr,\
    uint16 mask,\
    uint16 shift,\
    uint16 value)
{
uint16 regVal = *(volatile uint16 *)addr;
regVal &= (~mask);
regVal |= (uint16) ((uint16) (value << shift) & mask);
*(volatile uint16 *)addr = regVal;
}

LOCAL_INLINE FUNC(uint16, MCAL_LIB_CODE) McalLib_RegReadRaw16(uint32 addr)
{
    uint16 regVal = *(volatile uint16 *)addr;
    return (regVal);
}

LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw16(uint32 addr, uint16 value)
{
    *(volatile uint16 *) addr = value;
}

LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitSet16(uint32 addr, uint16 mask)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal |= mask;
    *(volatile uint16 *)addr = regVal;
}

LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitClear16(uint32 addr, uint16 mask)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal &= (~mask);
    *(volatile uint16 *)addr = regVal;
}

LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw32(uint32 addr, uint32 value)
{
    *(volatile uint32 *) addr = value;
}


LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegWriteRaw8(uint32 addr, uint8 value)
{
    *(volatile uint8 *) addr = value;
}


LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegMFWriteRaw32(uint32 addr,
                                      uint32 mask,
                                      uint32 shift,
                                      uint32 value)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32 *)addr = regVal;
}


LOCAL_INLINE FUNC(uint32, MCAL_LIB_CODE) McalLib_RegReadRaw32(uint32 addr)
{
    uint32 regVal = *(volatile uint32 *)addr;
    return (regVal);
}


LOCAL_INLINE FUNC(uint8, MCAL_LIB_CODE) McalLib_RegReadRaw8(uint32 addr)
{
    uint8 regVal = *(volatile uint8 *)addr;
    return (regVal);
}

LOCAL_INLINE FUNC(uint32, MCAL_LIB_CODE) McalLib_RegMFReadRaw32(uint32 addr, \
    uint32 mask, \
    uint32 shift)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal = (regVal & mask) >> shift;
    return (regVal);
}
LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitSet32(uint32 addr, \
    uint32 mask)
{

uint32 regVal = *(volatile uint32 *)addr;
regVal |= (mask);
*(volatile uint32 *)addr = regVal;
}

LOCAL_INLINE FUNC(void, MCAL_LIB_CODE) McalLib_RegBitClear32(uint32 addr, \
    uint32 mask)
{

uint32 regVal = *(volatile uint32 *)addr;
regVal &= (~mask);
*(volatile uint32 *)addr = regVal;

}
#ifdef __cplusplus
}
#endif
#endif /* MCAL_LIB_REG_ACCESS_H */
/*********************************************************************************************************************
 *  End of File: Mcal_Lib_RegAccess.h
 *********************************************************************************************************************/
