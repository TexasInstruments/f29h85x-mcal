//###########################################################################
//
// FILE:    hw_xint.h
//
// TITLE:   Definitions for the XINT registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_XINT_H
#define HW_XINT_H

//*************************************************************************************************
//
// The following are defines for the XINT register offsets
//
//*************************************************************************************************
#define XINT_O_1CR    0x0U    // XINT1 configuration register
#define XINT_O_2CR    0x2U    // XINT2 configuration register
#define XINT_O_3CR    0x4U    // XINT3 configuration register
#define XINT_O_4CR    0x6U    // XINT4 configuration register
#define XINT_O_5CR    0x8U    // XINT5 configuration register
#define XINT_O_1CTR   0x10U   // XINT1 counter register
#define XINT_O_2CTR   0x12U   // XINT2 counter register
#define XINT_O_3CTR   0x14U   // XINT3 counter register


//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT1CR register
//
//*************************************************************************************************
#define XINT_1CR_ENABLE       0x1U   // XINT1 Enable
#define XINT_1CR_POLARITY_S   2U
#define XINT_1CR_POLARITY_M   0xCU   // XINT1 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT2CR register
//
//*************************************************************************************************
#define XINT_2CR_ENABLE       0x1U   // XINT2 Enable
#define XINT_2CR_POLARITY_S   2U
#define XINT_2CR_POLARITY_M   0xCU   // XINT2 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT3CR register
//
//*************************************************************************************************
#define XINT_3CR_ENABLE       0x1U   // XINT3 Enable
#define XINT_3CR_POLARITY_S   2U
#define XINT_3CR_POLARITY_M   0xCU   // XINT3 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT4CR register
//
//*************************************************************************************************
#define XINT_4CR_ENABLE       0x1U   // XINT4 Enable
#define XINT_4CR_POLARITY_S   2U
#define XINT_4CR_POLARITY_M   0xCU   // XINT4 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT5CR register
//
//*************************************************************************************************
#define XINT_5CR_ENABLE       0x1U   // XINT5 Enable
#define XINT_5CR_POLARITY_S   2U
#define XINT_5CR_POLARITY_M   0xCU   // XINT5 Polarity



#endif
