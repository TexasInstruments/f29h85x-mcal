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
 *  File:       Can_Reg_Access.h
 *  Generator:  None
 *
 *  Description:  This file contains macros for CAN register access
 *********************************************************************************************************************/
#ifndef CAN_REG_ACCESS_H
#define CAN_REG_ACCESS_H

/** \addtogroup CAN Can API GUIDE Header file 
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/

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
#define CAN_REG_MF_READ32(regAddr, REG_FIELD)                           \
    (Can_RegMFReadRaw32((uint32) (regAddr), (uint32) REG_FIELD ## _MASK, \
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
#define CAN_REG_MF_WRITE32(regAddr, REG_FIELD, fieldVal)                   \
    (Can_RegMFWriteRaw32((uint32) (regAddr), (uint32) REG_FIELD ## _MASK,  \
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
#define CAN_REG_READ32(regAddr)                 \
    (uint32)(Can_RegReadRaw32((uint32) (regAddr)))

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
#define CAN_REG_WRITE32(regAddr, value)                     \
    (Can_RegWriteRaw32((uint32) (regAddr), (uint32) (value)))

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
#define CAN_FIELD_SET32(regVal, REG_FIELD, fieldVal)                       \
    ((regVal) = ((regVal) & (uint32) (~(uint32) REG_FIELD##_MASK)) |       \
                    ((((uint32) (fieldVal)) << (uint32) REG_FIELD##_SHIFT) \
                     & (uint32) REG_FIELD##_MASK))

/** \brief 
 *
 * \param regVal 32-bit variable containing the register value.
 * \param REG_FIELD Peripheral register bit field name, whose value has to
 *                   be extracted.
 *
******************************************************************************/
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
#define CAN_FIELD_GET(regVal, REG_FIELD)                                       \
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
static inline uint32 Can_RegMFReadRaw32(uint32 addr, \
                                        uint32 mask, \
                                        uint32 shift)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal = (regVal & mask) >> shift;
    return (regVal);
}

/** \brief This function writes a 32 bit register masking specific set of bits
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
static inline void Can_RegMFWriteRaw32(uint32 addr, \
                                      uint32 mask, \
                                      uint32 shift, \
                                      uint32 value)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32 *)addr = regVal;
}

/** \brief This function reads a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
static inline uint32 Can_RegReadRaw32(uint32 addr)
{
    uint32 regVal = *(volatile uint32 *)addr;
    return (regVal);
}

/** \brief This function writes a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 32-bit register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
static inline void Can_RegWriteRaw32(uint32 addr, \
                                     uint32 value)
{
    *(volatile uint32 *) addr = value;
}

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
#endif /* CAN_REG_ACCESS_H */
/*********************************************************************************************************************
 *  End of File: Can_Reg_Access.h
 *********************************************************************************************************************/
