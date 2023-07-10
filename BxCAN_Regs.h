/*
	this file includes the BxCAN registers
*/

#ifndef BXCAN_REGS_H
#define BXCAN_REGS_H

// BxCAN MCR Register Bit Definitions
#define BxCAN_MCR_INRQ          ( 0U)  // Initialization Request
#define BxCAN_MCR_SLEEP         ( 1U)  // Sleep Mode Request
#define BxCAN_MCR_TXFP          ( 2U)  // Transmit FIFO Priority
#define BxCAN_MCR_RFLM          ( 3U)  // Receive FIFO Locked Mode
#define BxCAN_MCR_NART          ( 4U)  // No Automatic Retransmission
#define BxCAN_MCR_AWUM          ( 5U)  // Automatic Wakeup Mode
#define BxCAN_MCR_ABOM          ( 6U)  // Automatic Bus-Off Management
#define BxCAN_MCR_TTCM          ( 7U)  // Time Triggered Communication Mode
#define BxCAN_MCR_RESET         (15U)  // CAN Software Reset
#define BxCAN_MCR_DBF           (16U)  // Debug Freeze

// BxCAN MSR Register Bit Definitions
#define BxCAN_MSR_INAK          ((uint32_t)0x00000001)  // Initialization Acknowledge
#define BxCAN_MSR_SLAK          ((uint32_t)0x00000002)  // Sleep Acknowledge
#define BxCAN_MSR_ERRI          ((uint32_t)0x00000004)  // Error Interrupt
#define BxCAN_MSR_WKUI          ((uint32_t)0x00000008)  // Wakeup Interrupt
#define BxCAN_MSR_SLAKI         ((uint32_t)0x00000010)  // Sleep Acknowledge Interrupt
#define BxCAN_MSR_TXM           ((uint32_t)0x00000100)  // Transmit Mode
#define BxCAN_MSR_RXM           ((uint32_t)0x00000200)  // Receive Mode
#define BxCAN_MSR_SAMP          ((uint32_t)0x00000400)  // Last Sample Point
#define BxCAN_MSR_RX            ((uint32_t)0x00000800)  // CAN Rx Signal
#define BxCAN_MSR_SOF           ((uint32_t)0x00001000)  // Start Of Frame
#define BxCAN_MSR_EPV           ((uint32_t)0x00002000)  // Error Passive
#define BxCAN_MSR_EWGF          ((uint32_t)0x00004000)  // Error Warning
#define BxCAN_MSR_BOFF          ((uint32_t)0x00008000)  // Bus-Off
#define BxCAN_MSR_LEC_SHIFT     ((uint32_t)16)         // Last Error Code Shift
#define BxCAN_MSR_LEC_MASK      ((uint32_t)0x000F0000)  // Last Error Code Mask
#define BxCAN_MSR_TXM_SHIFT     ((uint32_t)24)         // Transmit Mode Shift
#define BxCAN_MSR_RXM_SHIFT     ((uint32_t)25)         // Receive Mode Shift


// BxCAN TSR Register Bit Definitions
#define BxCAN_TSR_RQCP0         ((uint32_t)0x00000001)  // Request Completed Mailbox 0
#define BxCAN_TSR_TXOK0         ((uint32_t)0x00000002)  // Transmission OK of Mailbox 0
#define BxCAN_TSR_ALST0         ((uint32_t)0x00000004)  // Arbitration Lost for Mailbox 0
#define BxCAN_TSR_TERR0         ((uint32_t)0x00000008)  // Transmission Error of Mailbox 0
#define BxCAN_TSR_ABRQ0         ((uint32_t)0x00000080)  // Abort Request for Mailbox 0
#define BxCAN_TSR_RQCP1         ((uint32_t)0x00000100)  // Request Completed Mailbox 1
#define BxCAN_TSR_TXOK1         ((uint32_t)0x00000200)  // Transmission OK of Mailbox 1
#define BxCAN_TSR_ALST1         ((uint32_t)0x00000400)  // Arbitration Lost for Mailbox 1
#define BxCAN_TSR_TERR1         ((uint32_t)0x00000800)  // Transmission Error of Mailbox 1
#define BxCAN_TSR_ABRQ1         ((uint32_t)0x00008000)  // Abort Request for Mailbox 1
#define BxCAN_TSR_RQCP2         ((uint32_t)0x00010000)  // Request Completed Mailbox 2
#define BxCAN_TSR_TXOK2         ((uint32_t)0x00020000)  // Transmission OK of Mailbox 2
#define BxCAN_TSR_ALST2         ((uint32_t)0x00040000)  // Arbitration Lost for Mailbox 2
#define BxCAN_TSR_TERR2         ((uint32_t)0x00080000)  // Transmission Error of Mailbox 2
#define BxCAN_TSR_ABRQ2         ((uint32_t)0x00800000)  // Abort Request for Mailbox 2
#define BxCAN_TSR_CODE_SHIFT    ((uint32_t)24)         // Mailbox Code Shift
#define BxCAN_TSR_CODE_MASK     ((uint32_t)0x00300000)  // Mailbox Code Mask
#define BxCAN_TSR_TME0          ((uint32_t)0x04000000)  // Transmit Mailbox 0 Empty
#define BxCAN_TSR_TME1          ((uint32_t)0x08000000)  // Transmit Mailbox 1 Empty
#define BxCAN_TSR_TME2          ((uint32_t)0x10000000)  // Transmit Mailbox 2 Empty
#define BxCAN_TSR_LOW0          ((uint32_t)0x20000000)  // Lowest Priority Mailbox 0
#define BxCAN_TSR_LOW1          ((uint32_t)0x40000000)  // Lowest Priority Mailbox 1
#define BxCAN_TSR_LOW2          ((uint32_t)0x80000000)  // Lowest Priority Mailbox 2


// BxCAN RFxR Register Bit Definitions
#define BxCAN_RF0R_FMP    (0U)  // FIFO Message Pending Shift
#define BxCAN_RF0R_FULL   (3U)  // FIFO 0 Full
#define BxCAN_RF0R_FOVR   (4U)  // FIFO 0 Overrun
#define BxCAN_RF0R_RFOM   (5U)  // Release FIFO 0 Output Mailbox

// BxCAN BTR Register Bit Definitions
#define BxCAN_BTR_BRP_SHIFT     (0U)    // Baud Rate Prescaler Shift
#define BxCAN_BTR_TS1_SHIFT     (16U)   // Time Segment 1 Shift
#define BxCAN_BTR_TS2_SHIFT     (20U)   // Time Segment 2 Shift
#define BxCAN_BTR_SJW_SHIFT     (24U)   // Resynchronization Jump Width Shift
#define BxCAN_BTR_LBKM          (30U)   // Loop Back Mode (Debug)
#define BxCAN_BTR_SILM          (31U)   // Silent Mode (Debug)

// BxCAN TIR Register Bit Definitions
#define BxCAN_TIR_TXRQ         ((uint32_t)1U)  // Transmit Mailbox Request
#define BxCAN_TIR_RTR          ((uint32_t)2U)  // Remote Transmission Request
#define BxCAN_TIR_IDE          ((uint32_t)4U)  // Identifier Extension
#define BxCAN_TIR_EXID_SHIFT   ((uint32_t)3U)  // Extended Identifier Shift
#define BxCAN_TIR_STID_SHIFT   ((uint32_t)21u) // Standard Identifier Shift

//BxCAN Register offset 
#define BxCAN  ((volatile CAN_t*)0x40006400)





typedef struct{
	uint32_t TIR;
	uint32_t TDTR;
	uint32_t  TDLR;
	uint32_t  TDHR;
}MailBox_t;

typedef struct{
	uint32_t RIR;
	uint32_t RDTR;
	uint32_t  RDLR;
	uint32_t  RDHR;
}ReceiveFifo_t;

typedef struct{
	uint32_t R0;
	uint32_t R1;
}Filter_t;

typedef struct{
	uint32_t MCR;
	uint32_t MSR;
	uint32_t TSR;
	uint32_t RF0R;
	uint32_t RF1R;
	uint32_t IER;
	uint32_t ESR;
	uint32_t BTR;
	uint32_t RES0[88];
	MailBox_t MAILBOX[3];
	ReceiveFifo_t RECEIVEFIFO[2];
	uint32_t RES1[12];
	uint32_t FMR;
	uint32_t FM1R;
	uint32_t RES2;
	uint32_t FS1R;
  uint32_t RES3;	
	uint32_t FFA1R;
	uint32_t RES4;
	uint32_t FA1R;
	uint32_t RES5[8];
	Filter_t FILTER[28];
}CAN_t;


#endif
