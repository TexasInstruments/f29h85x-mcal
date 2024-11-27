//###########################################################################
//
// FILE:    hw_wadi.h
//
// TITLE:   Definitions for the WADI registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_WADI_H
#define HW_WADI_H

//*************************************************************************************************
//
// The following are defines for the WADI register offsets
//
//*************************************************************************************************
#define WADI_O_COMMON_CONFIG                   0x0U    // Block Clock Divider Control
#define WADI_O_SIG_TO_SIG_CONFIG               0x4U    // Configuration for SIG1 to SIG2 comparison
                                                       // for WADI Block
#define WADI_O_SIG_TO_SIG_PK_CMPARE            0x8U    // Signal1 to Signal2 peak comparison value
                                                       // and margin for WADI Block
#define WADI_O_SIG_TO_SIG_AVG_CMPARE           0xCU    // Signal1 to Signal2 average comparison
                                                       // value and margin for WADI Block
#define WADI_O_SIG_TO_SIG_DBAND_OLAP_CMPARE1   0x10U   // Signal1 to Signal2 dead-band comparison
                                                       // difference and margin for WADI Block
#define WADI_O_SIG_TO_SIG_DBAND_OLAP_CMPARE2   0x14U   // Signal1 to Signal2 dead-band and Overlap
                                                       // compare values for WADI Block
#define WADI_O_COMMON_TRIG_CFG                 0x18U   // The trigger configuration for SIG1 and
                                                       // SIG2 of the WADI Block
#define WADI_O_SIG1_CONFIG                     0x40U   // Measurement configuration for SIG1 of
                                                       // WADI Block
#define WADI_O_SIG1_CMPARE1                    0x44U   // Envelope-1 compare value and margin for
                                                       // SIG1 for WADI Block
#define WADI_O_SIG1_CMPARE2                    0x48U   // Envelope-2 compare value and margin for
                                                       // SIG1 for WADI Block
#define WADI_O_SIG1_PK_CMPARE                  0x4CU   // Peak of the aggregation compare
                                                       // configuration for  SIG1 of WADI Block
#define WADI_O_SIG1_AVG_CMPARE                 0x50U   // Average of the aggregation comparison
                                                       // configuration for SIG1 of WADI Block
#define WADI_O_SIG1_EDGE_CONFIG                0x54U   // Frequency measurement  configuration for
                                                       // SIG1 of WADI Block
#define WADI_O_SIG1_EDGE_MVW_CONFIG            0x58U   // Moving Window Configuration for SIG1 of
                                                       // WADI Block
#define WADI_O_SIG2_CONFIG                     0x80U   // Measurement configuration for SIG2 of
                                                       // WADI Block
#define WADI_O_SIG2_CMPARE1                    0x84U   // Envelope-1 compare value and margin for
                                                       // SIG2 for WADI Block
#define WADI_O_SIG2_CMPARE2                    0x88U   // Envelope-2 compare value and margin for
                                                       // SIG2 for WADI Block
#define WADI_O_SIG2_PK_CMPARE                  0x8CU   // Peak of the aggregation compare
                                                       // configuration for  SIG2 of WADI Block
#define WADI_O_SIG2_AVG_CMPARE                 0x90U   // Average of the aggregation comparison
                                                       // configuration for SIG2 of WADI Block
#define WADI_O_SIG2_EDGE_CONFIG                0x94U   // Frequency measurement  configuration for
                                                       // SIG2 of WADI Block
#define WADI_O_SIG2_EDGE_MVW_CONFIG            0x98U   // Moving Window Configuration for SIG2 of
                                                       // WADI Block
#define WADI_O_ERR_STATUS                      0xC0U   // Block status register.
#define WADI_O_ERR_DBG_CNT                     0xC4U   // Block count value of failed register
#define WADI_O_ERR_HANDLING                    0xC8U   // Block Debug additional info.
#define WADI_O_SSS_EVT_WORD_MASK               0xCCU   // Mask to combine Block errors for trigger
                                                       // of SSS in event word Output by WADI block
#define WADI_O_PARITY_TEST                     0xE8U   // Enables parity test

#define WADI_O_BASE_TIMER_LOW                0x0U     // Read only value for lower word of the base
                                                      // timer.
#define WADI_O_BASE_TIMER_HIGH               0x4U     // Upper word of the base timer and trigger
                                                      // to start the timer.
#define WADI_O_RAW_INT_STATUS                0x8U     // Gives the block wise aggregated raw error
                                                      // status that shall trigger the interrupt.
#define WADI_O_INT_STATUS_MASK               0xCU     // Provides mask for application to suppress
                                                      // or allow a particular block related errors
                                                      // to cause interrupt or not
#define WADI_O_MASKED_INT_STATUS             0x10U    // This is AND combination of active high
                                                      // indication of block-wise status asserting
                                                      // an interrupt.
#define WADI_O_RAW_INT_STATUS_CLR            0x14U    // Provides way for application to clear the
                                                      // interrupt status.
#define WADI_O_RAW_INT_STATUS_FRC            0x18U    // Allows emulation of the RIS to raise
                                                      // interrupt in software
#define WADI_O_INP_CBAR_OP_SYNC_FILT_SEL     0x1CU    // Each input SIG to be connected through
                                                      // synchroniser or not
#define WADI_O_TRIG_CBAR_OP_SYNC_FILT_SEL    0x20U    // Each trigger to be connected through
                                                      // synchroniser or not
#define WADI_O_REVISION                      0x3CU    // IP Revision
#define WADI_O_DMA_TRIGGER_STATUS            0x40U    // Status of the DMA triggers active
#define WADI_O_DMA_TRIGGER_EN_MASK           0x44U    // Mask to enable individual trigger cause
#define WADI_O_DMA_UPDATE_STATUS             0x48U    // Indicates the register set updated post
                                                      // DMA write
#define WADI_O_DMA_FILTERED_WR_EN            0x4CU    // DMA writes Filter enable for each of WADI
                                                      // & SSS blocks
#define WADI_O_CONFIG_REG_LOCK               0xA4U    // Configuration Register Lock
#define WADI_O_CONFIG_REG_COMMIT             0xA8U    // Configuration Register Commit
#define WADI_O_OPER_REG_LOCK                 0xACU    // Operating Register Lock
#define WADI_O_OPER_REG_COMMIT               0xB0U    // Operating Register Commit
#define WADI_O_SSS_EVT_TRIG_WORD             0xB8U    // Event trigger word output by WADI instance
                                                      // for SSS
#define WADI_O_SSS_SEQ_WORD_ACTIVE_STATUS    0xBCU    // Status of the active sequence word
#define WADI_O_SSS_OUTPUT_SELECT_1           0xC0U    // Mux select word for outputs 0-3
#define WADI_O_SSS_OUTPUT_SELECT_2           0xC4U    // Mux select word for outputs 4-7
#define WADI_O_SSS_OUTPUT_SELECT_3           0xC8U    // Mux select word for outputs 8-11
#define WADI_O_SSS_OUTPUT_SELECT_4           0xCCU    // Mux select word for outputs 12-15
#define WADI_O_SSS_OUTPUT_SELECT_5           0xD0U    // Mux select word for outputs 16-19
#define WADI_O_SSS_OUTPUT_SELECT_6           0xD4U    // Mux select word for outputs 20-23
#define WADI_O_SSS_OUTPUT_SELECT_7           0xD8U    // Mux select word for outputs 24-27
#define WADI_O_SSS_OUTPUT_SELECT_8           0xDCU    // Mux select word for outputs 28-31
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG1     0xE0U    // Sequence word-1 Link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG2     0xE4U    // Sequence word-2 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG3     0xE8U    // Sequence word-3 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG4     0xECU    // Sequence word-4 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG5     0xF0U    // Sequence word-5 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG6     0xF4U    // Sequence word-6 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG7     0xF8U    // Sequence word-7 link configuration
#define WADI_O_SSS_SEQUENCE_LINK_CONFIG8     0xFCU    // Sequence word-8 link configuration
#define WADI_O_SSS_EVENT_WORD1               0x100U   // Event match word-1 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD2               0x104U   // Event match word-2 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD3               0x108U   // Event match word-3 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD4               0x10CU   // Event match word-4 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_MULTI_WORD_TRIG_CONFIG1   0x110U   // Configuration for using trigger word in
                                                      // specific manner
#define WADI_O_SSS_SEQUENCE_WORD1            0x180U   // Sequence word-1 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD2            0x184U   // Sequence word-2 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD3            0x188U   // Sequence word-3 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD4            0x18CU   // Sequence word-4 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG1     0x190U   // Sequence word-1 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG2     0x194U   // Sequence word-2 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG3     0x198U   // Sequence word-3 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG4     0x19CU   // Sequence word-4 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_DELAY1           0x1A0U   // Sequence word-1 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY2           0x1A4U   // Sequence word-2 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY3           0x1A8U   // Sequence word-3 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY4           0x1ACU   // Sequence word-4 configuration of delays
#define WADI_O_SSS_EVENT_WORD5               0x200U   // Event match word-5 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD6               0x204U   // Event match word-6 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD7               0x208U   // Event match word-7 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_EVENT_WORD8               0x20CU   // Event match word-8 that compares to
                                                      // trigger word SSS_EVT_TRIG_WORD
#define WADI_O_SSS_MULTI_WORD_TRIG_CONFIG2   0x210U   // Configuration for using trigger word in
                                                      // specific manner
#define WADI_O_SSS_SEQUENCE_WORD5            0x280U   // Sequence word-5 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD6            0x284U   // Sequence word-6 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD7            0x288U   // Sequence word-7 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_WORD8            0x28CU   // Sequence word-8 to be applied for output
                                                      // based on SEQUENCE_CONFIG setting
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG5     0x290U   // Sequence word-5 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG6     0x294U   // Sequence word-6 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG7     0x298U   // Sequence word-7 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_TRIG_CONFIG8     0x29CU   // Sequence word-8 configuration for
                                                      // triggers, link
#define WADI_O_SSS_SEQUENCE_DELAY5           0x2A0U   // Sequence word-5 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY6           0x2A4U   // Sequence word-6 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY7           0x2A8U   // Sequence word-7 configuration of delays
#define WADI_O_SSS_SEQUENCE_DELAY8           0x2ACU   // Sequence word-8 configuration of delays
#define WADI_O_PARITY_TEST                   0x2C8U   // Enables parity test


//*************************************************************************************************
//
// The following are defines for the bit fields in the COMMON_CONFIG register
//
//*************************************************************************************************
#define WADI_COMMON_CONFIG_CLOCK_DIV_S          0U
#define WADI_COMMON_CONFIG_CLOCK_DIV_M          0x7U          // SIG_TO_SIG_DBAND_OLAP_CMPARE1
#define WADI_COMMON_CONFIG_CLOCK_EN             0x10U         // Enables the clock to WADI block
#define WADI_COMMON_CONFIG_IN_CBAR_SEL_SIG1_S   8U
#define WADI_COMMON_CONFIG_IN_CBAR_SEL_SIG1_M   0x1F00U       // Selects the input signal for the
                                                              // SIG1 input of WADI block
#define WADI_COMMON_CONFIG_IN_CBAR_SEL_SIG2_S   16U
#define WADI_COMMON_CONFIG_IN_CBAR_SEL_SIG2_M   0x1F0000U     // Selects the input signal for the
                                                              // SIG2 input of WADI block
#define WADI_COMMON_CONFIG_TRIG_SEL_SIG1_S      24U
#define WADI_COMMON_CONFIG_TRIG_SEL_SIG1_M      0xF000000U    // WADI Block Mux select for SIG1 HW
                                                              // Trigger
#define WADI_COMMON_CONFIG_TRIG_SEL_SIG2_S      28U
#define WADI_COMMON_CONFIG_TRIG_SEL_SIG2_M      0xF0000000U   // WADI Block Mux select for SIG2 HW
                                                              // Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG_TO_SIG_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG_TO_SIG_CONFIG_DIFF_CMPARE_CNTRE_S       0U
#define WADI_SIG_TO_SIG_CONFIG_DIFF_CMPARE_CNTRE_M       0xFFFFU       // Compare value for
                                                                       // difference of width/sum measurement
#define WADI_SIG_TO_SIG_CONFIG_DIFF_CMPARE_MARGIN_S      16U
#define WADI_SIG_TO_SIG_CONFIG_DIFF_CMPARE_MARGIN_M      0xF0000U      // Margin of error for
                                                                       // difference of width/sum measurement
#define WADI_SIG_TO_SIG_CONFIG_SIG_TO_SIG_CMP_EN         0x1000000U    // Enables the signal to
                                                                       // signal compare
#define WADI_SIG_TO_SIG_CONFIG_SIG_TO_SIG_DBAND_CHK_EN   0x4000000U    // Enables the dead-band
                                                                       // check between two signals
#define WADI_SIG_TO_SIG_CONFIG_SIG_TO_SIG_OLAP_CHK_EN    0x8000000U    // Enables the overlap check
                                                                       // between two signals
#define WADI_SIG_TO_SIG_CONFIG_DBAND_CHK_TYPE            0x10000000U   // Selects the check type
                                                                       // for dead-band control
#define WADI_SIG_TO_SIG_CONFIG_OLAP_CHK_TYPE             0x20000000U   // Selects the check type
                                                                       // for overlap control

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG_TO_SIG_PK_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG_TO_SIG_PK_CMPARE_PK_CMPARE_CNTRE_S    0U
#define WADI_SIG_TO_SIG_PK_CMPARE_PK_CMPARE_CNTRE_M    0xFFFFFFU     // Compare value for
                                                                     // difference of peak measurement
#define WADI_SIG_TO_SIG_PK_CMPARE_PK_CMPARE_MARGIN_S   24U
#define WADI_SIG_TO_SIG_PK_CMPARE_PK_CMPARE_MARGIN_M   0xFF000000U   // Margin of error for
                                                                     // difference of peak measurement

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG_TO_SIG_AVG_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG_TO_SIG_AVG_CMPARE_AVG_CMPARE_CNTRE_S    0U
#define WADI_SIG_TO_SIG_AVG_CMPARE_AVG_CMPARE_CNTRE_M    0xFFFFFFU     // Compare difference for
                                                                       // measurements average of both signals
#define WADI_SIG_TO_SIG_AVG_CMPARE_AVG_CMPARE_MARGIN_S   24U
#define WADI_SIG_TO_SIG_AVG_CMPARE_AVG_CMPARE_MARGIN_M   0xFF000000U   // Margin for difference of
                                                                       // average of both signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG_TO_SIG_DBAND_OLAP_CMPARE1 register
//
//*************************************************************************************************
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_DBAND_CMPARE_VALUE_S   0U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_DBAND_CMPARE_VALUE_M   0xFFU         // Compare value
                                                                                // for dead-band between both signals
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_OLAP_CMPARE_VALUE_S    8U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_OLAP_CMPARE_VALUE_M    0xFFFF00U     // Compare value
                                                                                // for Overlap between both signal
                                                                                // levels
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_OLAP_CMPARE_MARGIN_S   24U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE1_OLAP_CMPARE_MARGIN_M   0x3F000000U   // Margin of
                                                                                // variation of overlap between both
                                                                                // signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG_TO_SIG_DBAND_OLAP_CMPARE2 register
//
//*************************************************************************************************
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_DBAND_CMPARE_VALUE_S   0U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_DBAND_CMPARE_VALUE_M   0xFFU         // Compare value
                                                                                // for dead-band between both signals
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_OLAP_CMPARE_VALUE_S    8U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_OLAP_CMPARE_VALUE_M    0xFFFF00U     // Compare value
                                                                                // for Overlap between both signal
                                                                                // levels
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_OLAP_CMPARE_MARGIN_S   24U
#define WADI_SIG_TO_SIG_DBAND_OLAP_CMPARE2_OLAP_CMPARE_MARGIN_M   0x3F000000U   // Margin of
                                                                                // variation of overlap between both
                                                                                // signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMMON_TRIG_CFG register
//
//*************************************************************************************************
#define WADI_COMMON_TRIG_CFG_SIG1_TRIG_TYPE_S   0U
#define WADI_COMMON_TRIG_CFG_SIG1_TRIG_TYPE_M   0x7U         // The trigger type for SIG1 signal
                                                             // input.
#define WADI_COMMON_TRIG_CFG_SIG1_SW_TRIG       0x100U       // Software trigger for the SIG1
#define WADI_COMMON_TRIG_CFG_SIG2_TRIG_TYPE_S   16U
#define WADI_COMMON_TRIG_CFG_SIG2_TRIG_TYPE_M   0x70000U     // The trigger type for SIG2 signal
                                                             // input.
#define WADI_COMMON_TRIG_CFG_SIG2_SW_TRIG       0x1000000U   // Software trigger for the SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG1_CONFIG_EDGE_TYPE_S     0U
#define WADI_SIG1_CONFIG_EDGE_TYPE_M     0x3U         // Starting edge select as rise, fall or
                                                      // either
#define WADI_SIG1_CONFIG_EDGE_SPAN_S     8U
#define WADI_SIG1_CONFIG_EDGE_SPAN_M     0xF00U       // Defines span of edges of given type to
                                                      // measure the width.
#define WADI_SIG1_CONFIG_AGGREGATION_S   16U
#define WADI_SIG1_CONFIG_AGGREGATION_M   0x70000U     // Defines number of measurements to be
                                                      // aggregated
#define WADI_SIG1_CONFIG_AGGR_PK_AVG_S   24U
#define WADI_SIG1_CONFIG_AGGR_PK_AVG_M   0x3000000U   // Whether peak or average or both
                                                      // measurements to compute

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_CMPARE1 register
//
//*************************************************************************************************
#define WADI_SIG1_CMPARE1_CMPARE_CNTRE_S    0U
#define WADI_SIG1_CMPARE1_CMPARE_CNTRE_M    0xFFFFFFU     // Compare-1 value for measured count of
                                                          // the SIG1
#define WADI_SIG1_CMPARE1_CMPARE_MARGIN_S   24U
#define WADI_SIG1_CMPARE1_CMPARE_MARGIN_M   0xFF000000U   // +/- Margin for compare-1 around
                                                          // CMPARE_CNTRE

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_CMPARE2 register
//
//*************************************************************************************************
#define WADI_SIG1_CMPARE2_CMPARE_CNTRE2_S    0U
#define WADI_SIG1_CMPARE2_CMPARE_CNTRE2_M    0xFFFFFFU     // Compare-2 value for measured count of
                                                           // the SIG1
#define WADI_SIG1_CMPARE2_CMPARE_MARGIN2_S   24U
#define WADI_SIG1_CMPARE2_CMPARE_MARGIN2_M   0xFF000000U   // +/- Margin for compare-2 around
                                                           // CMPARE_CNTRE2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_PK_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG1_PK_CMPARE_PK_CMPARE_CNTRE_S    0U
#define WADI_SIG1_PK_CMPARE_PK_CMPARE_CNTRE_M    0xFFFFFFU     // Compare value for peak
                                                               // measurements of SIG1
#define WADI_SIG1_PK_CMPARE_PK_CMPARE_MARGIN_S   24U
#define WADI_SIG1_PK_CMPARE_PK_CMPARE_MARGIN_M   0xFF000000U   // Margin of variation for peak
                                                               // measurements of SIG1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_AVG_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG1_AVG_CMPARE_AVG_CMPARE_CNTRE_S    0U
#define WADI_SIG1_AVG_CMPARE_AVG_CMPARE_CNTRE_M    0xFFFFFFU     // Compare value for average of
                                                                 // measurements of SIG1
#define WADI_SIG1_AVG_CMPARE_AVG_CMPARE_MARGIN_S   24U
#define WADI_SIG1_AVG_CMPARE_AVG_CMPARE_MARGIN_M   0xFF000000U   // Margin for average of
                                                                 // measurements of SIG1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_EDGE_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG1_EDGE_CONFIG_EDGE_TIME_WNDOW_S   0U
#define WADI_SIG1_EDGE_CONFIG_EDGE_TIME_WNDOW_M   0xFFFFFFFU    // Time window to count edges of
                                                                // SIG1
#define WADI_SIG1_EDGE_CONFIG_EDGE_CNT_EN         0x80000000U   // SIG1 Edge count mode enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1_EDGE_MVW_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG1_EDGE_MVW_CONFIG_MVW_TIME_S   0U
#define WADI_SIG1_EDGE_MVW_CONFIG_MVW_TIME_M   0x3FFFFFFU    // Moving Window time
#define WADI_SIG1_EDGE_MVW_CONFIG_MVW_CNT_S    28U
#define WADI_SIG1_EDGE_MVW_CONFIG_MVW_CNT_M    0x30000000U   // Moving window count:number of
                                                             // MWV_TIME windows to accumulate
#define WADI_SIG1_EDGE_MVW_CONFIG_MVW_EN       0x80000000U   // Moving window operation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG2_CONFIG_EDGE_TYPE_S     0U
#define WADI_SIG2_CONFIG_EDGE_TYPE_M     0x3U         // Starting edge select as rise, fall or
                                                      // either
#define WADI_SIG2_CONFIG_EDGE_SPAN_S     8U
#define WADI_SIG2_CONFIG_EDGE_SPAN_M     0xF00U       // Defines span of edges of given type to
                                                      // measure the width.
#define WADI_SIG2_CONFIG_AGGREGATION_S   16U
#define WADI_SIG2_CONFIG_AGGREGATION_M   0x70000U     // Defines number of measurements to be
                                                      // aggregated
#define WADI_SIG2_CONFIG_AGGR_PK_AVG_S   24U
#define WADI_SIG2_CONFIG_AGGR_PK_AVG_M   0x3000000U   // Whether peak or average or both
                                                      // measurements to compute

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_CMPARE1 register
//
//*************************************************************************************************
#define WADI_SIG2_CMPARE1_CMPARE_CNTRE_S    0U
#define WADI_SIG2_CMPARE1_CMPARE_CNTRE_M    0xFFFFFFU     // Compare-1 value for measured count of
                                                          // the SIG2
#define WADI_SIG2_CMPARE1_CMPARE_MARGIN_S   24U
#define WADI_SIG2_CMPARE1_CMPARE_MARGIN_M   0xFF000000U   // +/- Margin for compare-1 around
                                                          // CMPARE_CNTRE

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_CMPARE2 register
//
//*************************************************************************************************
#define WADI_SIG2_CMPARE2_CMPARE_CNTRE2_S    0U
#define WADI_SIG2_CMPARE2_CMPARE_CNTRE2_M    0xFFFFFFU     // Compare-2 value for measured count of
                                                           // the SIG2
#define WADI_SIG2_CMPARE2_CMPARE_MARGIN2_S   24U
#define WADI_SIG2_CMPARE2_CMPARE_MARGIN2_M   0xFF000000U   // +/- Margin for compare-2 around
                                                           // CMPARE_CNTRE2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_PK_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG2_PK_CMPARE_PK_CMPARE_CNTRE_S    0U
#define WADI_SIG2_PK_CMPARE_PK_CMPARE_CNTRE_M    0xFFFFFFU     // Compare value for peak
                                                               // measurements of SIG2
#define WADI_SIG2_PK_CMPARE_PK_CMPARE_MARGIN_S   24U
#define WADI_SIG2_PK_CMPARE_PK_CMPARE_MARGIN_M   0xFF000000U   // Margin of variation for peak
                                                               // measurements of SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_AVG_CMPARE register
//
//*************************************************************************************************
#define WADI_SIG2_AVG_CMPARE_AVG_CMPARE_CNTRE_S    0U
#define WADI_SIG2_AVG_CMPARE_AVG_CMPARE_CNTRE_M    0xFFFFFFU     // Compare value for average of
                                                                 // measurements of SIG2
#define WADI_SIG2_AVG_CMPARE_AVG_CMPARE_MARGIN_S   24U
#define WADI_SIG2_AVG_CMPARE_AVG_CMPARE_MARGIN_M   0xFF000000U   // Margin for average of
                                                                 // measurements of SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_EDGE_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG2_EDGE_CONFIG_EDGE_TIME_WNDOW_S   0U
#define WADI_SIG2_EDGE_CONFIG_EDGE_TIME_WNDOW_M   0xFFFFFFFU    // Time window to count edges of
                                                                // SIG2
#define WADI_SIG2_EDGE_CONFIG_EDGE_CNT_EN         0x80000000U   // SIG2 Edge count mode enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2_EDGE_MVW_CONFIG register
//
//*************************************************************************************************
#define WADI_SIG2_EDGE_MVW_CONFIG_MVW_TIME_S   0U
#define WADI_SIG2_EDGE_MVW_CONFIG_MVW_TIME_M   0x3FFFFFFU    // Moving Window time
#define WADI_SIG2_EDGE_MVW_CONFIG_MVW_CNT_S    28U
#define WADI_SIG2_EDGE_MVW_CONFIG_MVW_CNT_M    0x30000000U   // Moving window count:number of
                                                             // MWV_TIME windows to accumulate
#define WADI_SIG2_EDGE_MVW_CONFIG_MVW_EN       0x80000000U   // Moving window operation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_STATUS register
//
//*************************************************************************************************
#define WADI_ERR_STATUS_SIG1_COMPARE1_ERR_S              0U
#define WADI_ERR_STATUS_SIG1_COMPARE1_ERR_M              0x3U          // Compare1 Envelop Error
                                                                       // for the SIG1 measurements
#define WADI_ERR_STATUS_SIG1_PK_ERR_S                    2U
#define WADI_ERR_STATUS_SIG1_PK_ERR_M                    0xCU          // Error of SIG1 Peak
                                                                       // measurements
#define WADI_ERR_STATUS_SIG1_AVG_ERR_S                   4U
#define WADI_ERR_STATUS_SIG1_AVG_ERR_M                   0x30U         // Average of aggregation
                                                                       // Error for the SIG1 measurements
#define WADI_ERR_STATUS_SIG1_COMPARE2_ERR_S              6U
#define WADI_ERR_STATUS_SIG1_COMPARE2_ERR_M              0xC0U         // Compare2 Envelop Error
                                                                       // for the SIG1 measurements
#define WADI_ERR_STATUS_SIG2_COMPARE1_ERR_S              8U
#define WADI_ERR_STATUS_SIG2_COMPARE1_ERR_M              0x300U        // Compare1 Envelop Error
                                                                       // for the SIG2 measurements
#define WADI_ERR_STATUS_SIG2_PK_ERR_S                    10U
#define WADI_ERR_STATUS_SIG2_PK_ERR_M                    0xC00U        // Error of SIG2 Peak
                                                                       // measurements
#define WADI_ERR_STATUS_SIG2_AVG_ERR_S                   12U
#define WADI_ERR_STATUS_SIG2_AVG_ERR_M                   0x3000U       // Average of aggregation
                                                                       // Error for the SIG2 measurements
#define WADI_ERR_STATUS_SIG2_COMPARE2_ERR_S              14U
#define WADI_ERR_STATUS_SIG2_COMPARE2_ERR_M              0xC000U       // Compare2 Envelop Error
                                                                       // for the SIG2 measurements
#define WADI_ERR_STATUS_SIG_TO_SIG_ERR_S                 16U
#define WADI_ERR_STATUS_SIG_TO_SIG_ERR_M                 0x30000U      // Compare Error for the
                                                                       // SIG_TO_SIG measurements difference
#define WADI_ERR_STATUS_SIG_TO_SIG_PK_WRR_S              18U
#define WADI_ERR_STATUS_SIG_TO_SIG_PK_WRR_M              0xC0000U      // Error of SIG_TO_SIG Peak
                                                                       // measurements difference
#define WADI_ERR_STATUS_SIG_TO_SIG_AVG_ERR_S             20U
#define WADI_ERR_STATUS_SIG_TO_SIG_AVG_ERR_M             0x300000U     // Average Error for the
                                                                       // SIG_TO_SIG measurements difference
#define WADI_ERR_STATUS_SIG_TO_SIG_DBAND_COMPARE1_ERR    0x400000U     // Dead-band Compare1 Error
                                                                       // for the SIG_TO_SIG measurements
#define WADI_ERR_STATUS_SIG_TO_SIG_DBAND_COMPARE2_ERR    0x800000U     // Dead-band Compare2 Error
                                                                       // for the SIG_TO_SIG measurements
#define WADI_ERR_STATUS_SIG_TO_SIG_OLAP_COMPARE1_ERR_S   24U
#define WADI_ERR_STATUS_SIG_TO_SIG_OLAP_COMPARE1_ERR_M   0x3000000U    // Overlap check Compare1
                                                                       // Error of SIG_TO_SIG measurements
#define WADI_ERR_STATUS_SIG_TO_SIG_OLAP_COMPARE2_ERR_S   26U
#define WADI_ERR_STATUS_SIG_TO_SIG_OLAP_COMPARE2_ERR_M   0xC000000U    // Overlap check Compare2
                                                                       // Error of SIG_TO_SIG measurements
#define WADI_ERR_STATUS_READING_MEASUREMENT_ERR          0x40000000U   // Measurement error of
                                                                       // unexpected waveform anomaly
#define WADI_ERR_STATUS_READING_MISMATCH_ERR             0x80000000U   // Mismatch in number of
                                                                       // readings between signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_DBG_CNT register
//
//*************************************************************************************************
#define WADI_ERR_DBG_CNT_ERR_DBG_CNT_S    0U
#define WADI_ERR_DBG_CNT_ERR_DBG_CNT_M    0x1FFFFFFU    // First failed count of SIGx multiplexed 
                                                        // to this register
#define WADI_ERR_DBG_CNT_ERR_DBG_TYPE_S   28U
#define WADI_ERR_DBG_CNT_ERR_DBG_TYPE_M   0x70000000U   // Type of error of the registered count

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_HANDLING register
//
//*************************************************************************************************
#define WADI_ERR_HANDLING_ERR_DBG_CNT_SEL_S          0U
#define WADI_ERR_HANDLING_ERR_DBG_CNT_SEL_M          0x3U         // Selects the count to be
                                                                  // multiplexed for debug
#define WADI_ERR_HANDLING_CORR_ACTION_SIG1_S         8U
#define WADI_ERR_HANDLING_CORR_ACTION_SIG1_M         0xF00U       // Drives the signal correction
                                                                  // for outputting the SIG1
#define WADI_ERR_HANDLING_CORR_ACTION_SIG2_S         16U
#define WADI_ERR_HANDLING_CORR_ACTION_SIG2_M         0xF0000U     // Drives the signal correction
                                                                  // for outputting the SIG2
#define WADI_ERR_HANDLING_CORR_ACTION_SIG_TO_SIG_S   24U
#define WADI_ERR_HANDLING_CORR_ACTION_SIG_TO_SIG_M   0xF000000U   // Drives the correction to both
                                                                  // signals if SIG_TO_SIG error

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT_WORD_MASK register
//
//*************************************************************************************************
#define WADI_SSS_EVT_WORD_MASK_BLK_EVT_WORD_MASK_SIG1_S   0U
#define WADI_SSS_EVT_WORD_MASK_BLK_EVT_WORD_MASK_SIG1_M   0x7FFFU    // Mask for specific WADI
                                                                     // events to SSS event word or not
#define WADI_SSS_EVT_WORD_MASK_BLK_EVT_WORD_MASK_SIG2_S   16U
#define WADI_SSS_EVT_WORD_MASK_BLK_EVT_WORD_MASK_SIG2_M   0xF0000U   // Mask for specific WADI
                                                                     // events to SSS event word or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define WADI_PARITY_TEST_TESTEN_S   0U
#define WADI_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the BASE_TIMER_HIGH register
//
//*************************************************************************************************
#define WADI_BASE_TIMER_HIGH_TIM_UP_WORD_S      0U
#define WADI_BASE_TIMER_HIGH_TIM_UP_WORD_M      0xFFFFFFFU    // Upper word of the base timer
#define WADI_BASE_TIMER_HIGH_START_BASE_TIMER   0x80000000U   // Start base timer trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAW_INT_STATUS register
//
//*************************************************************************************************
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS0    0x1U          // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS1    0x2U          // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS2    0x4U          // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS3    0x8U          // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS4    0x10U         // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS5    0x20U         // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS6    0x40U         // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS7    0x80U         // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS8    0x100U        // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS9    0x200U        // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS10   0x400U        // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS11   0x800U        // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS12   0x1000U       // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS13   0x2000U       // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS14   0x4000U       // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS15   0x8000U       // Raw interrupt status by ORing all
                                                             // WADI block errors
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS30   0x40000000U   // ORed RAW int status of measurement
                                                             // error for all WADI blocks
#define WADI_RAW_INT_STATUS_RAW_INT_STATUS31   0x80000000U   // ORed RAW int status of mismatch
                                                             // error for all WADI blocks

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_STATUS_MASK register
//
//*************************************************************************************************
#define WADI_INT_STATUS_MASK_INT_STATUS_MASK_S   0U
#define WADI_INT_STATUS_MASK_INT_STATUS_MASK_M   0xFFFFU       // Line wise mask to propagate
                                                               // interrupt or not
#define WADI_INT_STATUS_MASK_INT_STATUS_MASK30   0x40000000U   // Line wise mask to propagate
                                                               // interrupt or not
#define WADI_INT_STATUS_MASK_INT_STATUS_MASK31   0x80000000U   // Line wise mask to propagate
                                                               // interrupt or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the MASKED_INT_STATUS register
//
//*************************************************************************************************
#define WADI_MASKED_INT_STATUS_MASKED_INT_STATUS_S   0U
#define WADI_MASKED_INT_STATUS_MASKED_INT_STATUS_M   0xFFFFU       // This is AND of RAW_INT_STATUS
                                                                   // and INT_STATUS_MASK
#define WADI_MASKED_INT_STATUS_MASKED_INT_STATUS30   0x40000000U   // This is AND of RAW_INT_STATUS
                                                                   // and INT_STATUS_MASK
#define WADI_MASKED_INT_STATUS_MASKED_INT_STATUS31   0x80000000U   // This is AND of RAW_INT_STATUS
                                                                   // and INT_STATUS_MASK

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAW_INT_STATUS_CLR register
//
//*************************************************************************************************
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS0    0x1U          // Clears the status of the
                                                                 // RAW_INT_STATUS0
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS1    0x2U          // Clears the status of the
                                                                 // RAW_INT_STATUS1
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS2    0x4U          // Clears the status of the
                                                                 // RAW_INT_STATUS2
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS3    0x8U          // Clears the status of the
                                                                 // RAW_INT_STATUS3
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS4    0x10U         // Clears the status of the
                                                                 // RAW_INT_STATUS4
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS5    0x20U         // Clears the status of the
                                                                 // RAW_INT_STATUS5
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS6    0x40U         // Clears the status of the
                                                                 // RAW_INT_STATUS6
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS7    0x80U         // Clears the status of the
                                                                 // RAW_INT_STATUS7
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS8    0x100U        // Clears the status of the
                                                                 // RAW_INT_STATUS8
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS9    0x200U        // Clears the status of the
                                                                 // RAW_INT_STATUS9
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS10   0x400U        // Clears the status of the
                                                                 // RAW_INT_STATUS10
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS11   0x800U        // Clears the status of the
                                                                 // RAW_INT_STATUS11
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS12   0x1000U       // Clears the status of the
                                                                 // RAW_INT_STATUS12
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS13   0x2000U       // Clears the status of the
                                                                 // RAW_INT_STATUS13
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS14   0x4000U       // Clears the status of the
                                                                 // RAW_INT_STATUS14
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS15   0x8000U       // Clears the status of the
                                                                 // RAW_INT_STATUS15
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS30   0x40000000U   // Clears the status of the
                                                                 // RAW_INT_STATUS
#define WADI_RAW_INT_STATUS_CLR_RAW_INT_STATUS31   0x80000000U   // Clears the status of the
                                                                 // RAW_INT_STATUS

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAW_INT_STATUS_FRC register
//
//*************************************************************************************************
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS0    0x1U          // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS1    0x2U          // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS2    0x4U          // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS3    0x8U          // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS4    0x10U         // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS5    0x20U         // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS6    0x40U         // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS7    0x80U         // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS8    0x100U        // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS9    0x200U        // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS10   0x400U        // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS11   0x800U        // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS12   0x1000U       // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS13   0x2000U       // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS14   0x4000U       // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS15   0x8000U       // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS30   0x40000000U   // Allows emulation of the RIS to
                                                                 // raise interrupt in software
#define WADI_RAW_INT_STATUS_FRC_RAW_INT_STATUS31   0x80000000U   // Allows emulation of the RIS to
                                                                 // raise interrupt in software

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define WADI_REVISION_MINOR_S    0U
#define WADI_REVISION_MINOR_M    0x3FU         // Minor Revision Number
#define WADI_REVISION_CUSTOM_S   6U
#define WADI_REVISION_CUSTOM_M   0xC0U         // Custom Module Number
#define WADI_REVISION_MAJOR_S    8U
#define WADI_REVISION_MAJOR_M    0x700U        // Major Revision Number
#define WADI_REVISION_RTL_S      11U
#define WADI_REVISION_RTL_M      0xF800U       // Design Release Number
#define WADI_REVISION_FUNC_S     16U
#define WADI_REVISION_FUNC_M     0xFFF0000U    // Functional Release Number
#define WADI_REVISION_SCHEME_S   30U
#define WADI_REVISION_SCHEME_M   0xC0000000U   // Defines Scheme for Module

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMA_TRIGGER_STATUS register
//
//*************************************************************************************************
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT0    0x1U          // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT1    0x2U          // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT2    0x4U          // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT3    0x8U          // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT4    0x10U         // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT5    0x20U         // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT6    0x40U         // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT7    0x80U         // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT8    0x100U        // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT9    0x200U        // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT10   0x400U        // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT11   0x800U        // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT12   0x1000U       // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT13   0x2000U       // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT14   0x4000U       // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_BLOCK_WISE_DMA_EVENT15   0x8000U       // Indicates the WADI Block
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD1          0x10000U      // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD2          0x20000U      // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD3          0x40000U      // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD4          0x80000U      // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD5          0x100000U     // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD6          0x200000U     // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD7          0x400000U     // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_EVENT_WORD8          0x800000U     // Indicates the SSS Event
                                                                       // event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD1       0x1000000U    // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD2       0x2000000U    // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD3       0x4000000U    // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD4       0x8000000U    // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD5       0x10000000U   // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD6       0x20000000U   // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD7       0x40000000U   // Indicates the SSS
                                                                       // Sequence event for DMA trigger
#define WADI_DMA_TRIGGER_STATUS_SSS_SEQEUNCE_WORD8       0x80000000U   // Indicates the SSS
                                                                       // Sequence event for DMA trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMA_TRIGGER_EN_MASK register
//
//*************************************************************************************************
#define WADI_DMA_TRIGGER_EN_MASK_WADI_BLK_EVENT_MASK_S           0U
#define WADI_DMA_TRIGGER_EN_MASK_WADI_BLK_EVENT_MASK_M           0xFFFFU       // WADI Block event
                                                                               // enables for DMA request trigger
#define WADI_DMA_TRIGGER_EN_MASK_SSS_EVENT_WORD_SET1_MASK_S      16U
#define WADI_DMA_TRIGGER_EN_MASK_SSS_EVENT_WORD_SET1_MASK_M      0xF0000U      // SSS Event word
                                                                               // Set-1 enables for DMA request
                                                                               // Trigger
#define WADI_DMA_TRIGGER_EN_MASK_SSS_EVENT_WORD_SET2_MASK_S      20U
#define WADI_DMA_TRIGGER_EN_MASK_SSS_EVENT_WORD_SET2_MASK_M      0xF00000U     // SSS Event word
                                                                               // Set-2 enables for DMA request
                                                                               // Trigger
#define WADI_DMA_TRIGGER_EN_MASK_SSS_SEQEUNCE_WORD_SET1_MASK_S   24U
#define WADI_DMA_TRIGGER_EN_MASK_SSS_SEQEUNCE_WORD_SET1_MASK_M   0xF000000U    // SSS Sequence word
                                                                               // Set-1 enables for DMA request
                                                                               // Trigger
#define WADI_DMA_TRIGGER_EN_MASK_SSS_SEQUENCE_WORD_SET2_MASK_S   28U
#define WADI_DMA_TRIGGER_EN_MASK_SSS_SEQUENCE_WORD_SET2_MASK_M   0xF0000000U   // SSS Sequence word
                                                                               // Set-2 enables for DMA request
                                                                               // Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMA_UPDATE_STATUS register
//
//*************************************************************************************************
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK0      0x1U          // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK1      0x2U          // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK2      0x4U          // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK3      0x8U          // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK4      0x10U         // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK5      0x20U         // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK6      0x40U         // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK7      0x80U         // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK8      0x100U        // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK9      0x200U        // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK10     0x400U        // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK11     0x800U        // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK12     0x1000U       // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK13     0x2000U       // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK14     0x4000U       // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_WADI_BLOCK15     0x8000U       // Status of DMA
                                                                               // update for register set of WADI
                                                                               // Block
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD1      0x10000U      // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD2      0x20000U      // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD3      0x40000U      // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD4      0x80000U      // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD5      0x100000U     // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD6      0x200000U     // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD7      0x400000U     // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_EVENT_WORD8      0x800000U     // DMA MMR write
                                                                               // status of  SSS Event word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD1   0x1000000U    // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD2   0x2000000U    // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD3   0x4000000U    // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD4   0x8000000U    // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD5   0x10000000U   // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD6   0x20000000U   // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD7   0x40000000U   // DMA MMR write
                                                                               // status of  SSS Sequence word
#define WADI_DMA_UPDATE_STATUS_DMA_WRITE_STATUS_SEQUENCE_WORD8   0x80000000U   // DMA MMR write
                                                                               // status of  SSS Sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMA_FILTERED_WR_EN register
//
//*************************************************************************************************
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_WADI_BLK_S                 0U
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_WADI_BLK_M                 0xFFFFU       // Enable
                                                                                       // for filtered DMA write for WADI
                                                                                       // Block
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_EVENT_WORD_SET1_S      16U
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_EVENT_WORD_SET1_M      0xF0000U      // Enable
                                                                                       // for filtered DMA write for SSS Event
                                                                                       // word Set-1
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_EVENT_WORD_SET2_S      20U
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_EVENT_WORD_SET2_M      0xF00000U     // Enable
                                                                                       // for filtered DMA write for  SSS
                                                                                       // Event word Set-2
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_SEQEUNCE_WORD_SET1_S   24U
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_SEQEUNCE_WORD_SET1_M   0xF000000U    // Enable
                                                                                       // for filtered DMA write for SSS
                                                                                       // Sequence word Set-1
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_SEQUENCE_WORD_SET2_S   28U
#define WADI_DMA_FILTERED_WR_EN_DMA_FILT_WREN_SSS_SEQUENCE_WORD_SET2_M   0xF0000000U   // Enable
                                                                                       // for filtered DMA write for SSS
                                                                                       // Sequence word Set-2

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIG_REG_LOCK register
//
//*************************************************************************************************
#define WADI_CONFIG_REG_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIG_REG_COMMIT register
//
//*************************************************************************************************
#define WADI_CONFIG_REG_COMMIT_COMMIT   0x1U   // CONFIG_REG_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the OPER_REG_LOCK register
//
//*************************************************************************************************
#define WADI_OPER_REG_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the OPER_REG_COMMIT register
//
//*************************************************************************************************
#define WADI_OPER_REG_COMMIT_COMMIT   0x1U   // OPER_REG_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQ_WORD_ACTIVE_STATUS register
//
//*************************************************************************************************
#define WADI_SSS_SEQ_WORD_ACTIVE_STATUS_SEQ_WORD1_ACTIVITY_STATUS_S   0U
#define WADI_SSS_SEQ_WORD_ACTIVE_STATUS_SEQ_WORD1_ACTIVITY_STATUS_M   0xFU    // Active seq word
                                                                              // status for first set
#define WADI_SSS_SEQ_WORD_ACTIVE_STATUS_SEQ_WORD2_ACTIVITY_STATUS_S   4U
#define WADI_SSS_SEQ_WORD_ACTIVE_STATUS_SEQ_WORD2_ACTIVITY_STATUS_M   0xF0U   // Active seq word
                                                                              // status for Second set

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_1 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK0_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK0_SIG1_M   0xFFU         // Maps the  sequence words
                                                                    // associated with BLK0:SIG1
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK0_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK0_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                    // associated with BLK0:SIG2
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK1_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK1_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                    // associated with BLK1:SIG1
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK1_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_1_SELECT_BLK1_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                    // associated with BLK1:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_2 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK2_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK2_SIG1_M   0xFFU         // Maps the  sequence words
                                                                    // associated with BLK2:SIG1
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK2_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK2_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                    // associated with BLK2:SIG2
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK3_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK3_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                    // associated with BLK3:SIG1
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK3_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_2_SELECT_BLK3_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                    // associated with BLK3:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_3 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK4_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK4_SIG1_M   0xFFU         // Maps the  sequence words
                                                                    // associated with BLK4:SIG1
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK4_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK4_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                    // associated with BLK4:SIG2
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK5_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK5_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                    // associated with BLK5:SIG1
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK5_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_3_SELECT_BLK5_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                    // associated with BLK5:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_4 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK6_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK6_SIG1_M   0xFFU         // Maps the  sequence words
                                                                    // associated with BLK6:SIG1
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK6_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK6_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                    // associated with BLK6:SIG2
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK7_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK7_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                    // associated with BLK7:SIG1
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK7_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_4_SELECT_BLK7_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                    // associated with BLK7:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_5 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK8_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK8_SIG1_M   0xFFU         // Maps the  sequence words
                                                                    // associated with BLK8:SIG1
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK8_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK8_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                    // associated with BLK8:SIG2
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK9_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK9_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                    // associated with BLK9:SIG1
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK9_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_5_SELECT_BLK9_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                    // associated with BLK9:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_6 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK10_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK10_SIG1_M   0xFFU         // Maps the  sequence words
                                                                     // associated with BLK10:SIG1
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK10_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK10_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                     // associated with BLK10:SIG2
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK11_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK11_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                     // associated with BLK11:SIG1
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK11_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_6_SELECT_BLK11_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                     // associated with BLK11:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_7 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK12_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK12_SIG1_M   0xFFU         // Maps the  sequence words
                                                                     // associated with BLK12:SIG1
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK12_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK12_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                     // associated with BLK12:SIG2
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK13_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK13_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                     // associated with BLK13:SIG1
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK13_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_7_SELECT_BLK13_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                     // associated with BLK13:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTPUT_SELECT_8 register
//
//*************************************************************************************************
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK14_SIG1_S   0U
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK14_SIG1_M   0xFFU         // Maps the  sequence words
                                                                     // associated with BLK14:SIG1
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK14_SIG2_S   8U
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK14_SIG2_M   0xFF00U       // Maps the  sequence words
                                                                     // associated with BLK14:SIG2
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK15_SIG1_S   16U
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK15_SIG1_M   0xFF0000U     // Maps the  sequence words
                                                                     // associated with BLK15:SIG1
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK15_SIG2_S   24U
#define WADI_SSS_OUTPUT_SELECT_8_SELECT_BLK15_SIG2_M   0xFF000000U   // Maps the  sequence words
                                                                     // associated with BLK15:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG1 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG1_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG1_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG2 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG2_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG2_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG3 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG3_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG3_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG4 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG4_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG4_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG5 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG5_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG5_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG6 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG6_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG6_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG7 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG7_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG7_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_LINK_CONFIG8 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_LINK_CONFIG8_SEQ_LINK_ENABLE_S   0U
#define WADI_SSS_SEQUENCE_LINK_CONFIG8_SEQ_LINK_ENABLE_M   0xFFU   // Links sequence word as per
                                                                   // one hot word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_MULTI_WORD_TRIG_CONFIG1 register
//
//*************************************************************************************************
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD1_S   0U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD1_M   0xFU         // Selects action
                                                                                // associated with event word-1
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD2_S   8U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD2_M   0xF00U       // Selects action
                                                                                // associated with event word-2
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD3_S   16U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD3_M   0xF0000U     // Selects action
                                                                                // associated with event word-3
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD4_S   24U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG1_WORD_TRI_CONFIG_WORD4_M   0xF000000U   // Selects action
                                                                                // associated with event word-4

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG1 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG1_ENABLE   0x1U    // Activates Sequence word-1 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG2_ENABLE   0x2U    // Activates Sequence word-1 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG3_ENABLE   0x4U    // Activates Sequence word-1 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG4_ENABLE   0x8U    // Activates Sequence word-1 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG5_ENABLE   0x10U   // Activates Sequence word-1 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG6_ENABLE   0x20U   // Activates Sequence word-1 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG7_ENABLE   0x40U   // Activates Sequence word-1 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG1_TRIG8_ENABLE   0x80U   // Activates Sequence word-1 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG2 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG1_ENABLE   0x1U    // Activates Sequence word-2 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG2_ENABLE   0x2U    // Activates Sequence word-2 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG3_ENABLE   0x4U    // Activates Sequence word-2 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG4_ENABLE   0x8U    // Activates Sequence word-2 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG5_ENABLE   0x10U   // Activates Sequence word-2 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG6_ENABLE   0x20U   // Activates Sequence word-2 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG7_ENABLE   0x40U   // Activates Sequence word-2 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG2_TRIG8_ENABLE   0x80U   // Activates Sequence word-2 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG3 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG1_ENABLE   0x1U    // Activates Sequence word-3 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG2_ENABLE   0x2U    // Activates Sequence word-3 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG3_ENABLE   0x4U    // Activates Sequence word-3 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG4_ENABLE   0x8U    // Activates Sequence word-3 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG5_ENABLE   0x10U   // Activates Sequence word-3 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG6_ENABLE   0x20U   // Activates Sequence word-3 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG7_ENABLE   0x40U   // Activates Sequence word-3 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG3_TRIG8_ENABLE   0x80U   // Activates Sequence word-3 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG4 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG1_ENABLE   0x1U    // Activates Sequence word-4 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG2_ENABLE   0x2U    // Activates Sequence word-4 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG3_ENABLE   0x4U    // Activates Sequence word-4 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG4_ENABLE   0x8U    // Activates Sequence word-4 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG5_ENABLE   0x10U   // Activates Sequence word-4 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG6_ENABLE   0x20U   // Activates Sequence word-4 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG7_ENABLE   0x40U   // Activates Sequence word-4 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG4_TRIG8_ENABLE   0x80U   // Activates Sequence word-4 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY1 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY1_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY1_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY2 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY2_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY2_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY3 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY3_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY3_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY4 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY4_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY4_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_MULTI_WORD_TRIG_CONFIG2 register
//
//*************************************************************************************************
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD5_S   0U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD5_M   0xFU         // Selects action
                                                                                // associated with event word-5
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD6_S   8U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD6_M   0xF00U       // Selects action
                                                                                // associated with event word-6
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD7_S   16U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD7_M   0xF0000U     // Selects action
                                                                                // associated with event word-7
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD8_S   24U
#define WADI_SSS_MULTI_WORD_TRIG_CONFIG2_WORD_TRI_CONFIG_WORD8_M   0xF000000U   // Selects action
                                                                                // associated with event word-8

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG5 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG1_ENABLE   0x1U    // Activates Sequence word-5 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG2_ENABLE   0x2U    // Activates Sequence word-5 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG3_ENABLE   0x4U    // Activates Sequence word-5 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG4_ENABLE   0x8U    // Activates Sequence word-5 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG5_ENABLE   0x10U   // Activates Sequence word-5 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG6_ENABLE   0x20U   // Activates Sequence word-5 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG7_ENABLE   0x40U   // Activates Sequence word-5 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG5_TRIG8_ENABLE   0x80U   // Activates Sequence word-5 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG6 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG1_ENABLE   0x1U    // Activates Sequence word-6 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG2_ENABLE   0x2U    // Activates Sequence word-6 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG3_ENABLE   0x4U    // Activates Sequence word-6 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG4_ENABLE   0x8U    // Activates Sequence word-6 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG5_ENABLE   0x10U   // Activates Sequence word-6 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG6_ENABLE   0x20U   // Activates Sequence word-6 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG7_ENABLE   0x40U   // Activates Sequence word-6 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG6_TRIG8_ENABLE   0x80U   // Activates Sequence word-6 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG7 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG1_ENABLE   0x1U    // Activates Sequence word-7 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG2_ENABLE   0x2U    // Activates Sequence word-7 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG3_ENABLE   0x4U    // Activates Sequence word-7 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG4_ENABLE   0x8U    // Activates Sequence word-7 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG5_ENABLE   0x10U   // Activates Sequence word-7 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG6_ENABLE   0x20U   // Activates Sequence word-7 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG7_ENABLE   0x40U   // Activates Sequence word-7 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG7_TRIG8_ENABLE   0x80U   // Activates Sequence word-7 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_TRIG_CONFIG8 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG1_ENABLE   0x1U    // Activates Sequence word-8 based on
                                                              // Event-Word-1 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG2_ENABLE   0x2U    // Activates Sequence word-8 based on
                                                              // Event-Word-2 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG3_ENABLE   0x4U    // Activates Sequence word-8 based on
                                                              // Event-Word-3 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG4_ENABLE   0x8U    // Activates Sequence word-8 based on
                                                              // Event-Word-4 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG5_ENABLE   0x10U   // Activates Sequence word-8 based on
                                                              // Event-Word-5 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG6_ENABLE   0x20U   // Activates Sequence word-8 based on
                                                              // Event-Word-6 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG7_ENABLE   0x40U   // Activates Sequence word-8 based on
                                                              // Event-Word-7 Trigger
#define WADI_SSS_SEQUENCE_TRIG_CONFIG8_TRIG8_ENABLE   0x80U   // Activates Sequence word-8 based on
                                                              // Event-Word-8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY5 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY5_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY5_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY6 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY6_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY6_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY7 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY7_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY7_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_SEQUENCE_DELAY8 register
//
//*************************************************************************************************
#define WADI_SSS_SEQUENCE_DELAY8_SEQ_DELAY_S   0U
#define WADI_SSS_SEQUENCE_DELAY8_SEQ_DELAY_M   0xFFFFFFU   // Delay period for application of
                                                           // sequence word

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define WADI_PARITY_TEST_TESTEN_S   0U
#define WADI_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable configuration



#endif
