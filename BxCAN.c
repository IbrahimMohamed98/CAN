

#include "stm32f1xx_hal.h"
#include "BxCAN.h"
#include "BxCAN_Regs.h"




/*
this function initialize the BxCAN
*/
void BxCAN_init(BxCAN_InitPrams *initparams){
	//Enable initialization mode the BxCAN By setting INRQ Bit
	SET_BIT(BxCAN -> MCR , CAN_MCR_INRQ);
	//wait while INRQ is setted by waiting for BxCAN_MSR_INAK
	while((BxCAN->MSR & CAN_MSR_INAK) == 0);
	//Disable Sleep mode the BxCAN By Clearing SLEEP Bit
	BxCAN -> MCR &=  ~(1<<BxCAN_MCR_SLEEP);
	//wait while SLEEP is cleared by waiting for BxCAN_MSR_SLAK
	while((BxCAN->MSR & BxCAN_MSR_SLAK) != 0);
	//Set the automatic retransmission mode
	if(initparams->AUTO_RETx == Enable){
		CLEAR_BIT(BxCAN->MCR,BxCAN_MCR_NART);
	}else{
		SET_BIT(BxCAN->MCR,(BxCAN->MCR|(1<<BxCAN_MCR_NART)));
	}
	//set the Automatic wakeup mode
	if(initparams->AUWAKE == Enable){
		SET_BIT(BxCAN->MCR,(BxCAN->MCR|(1<<BxCAN_MCR_AWUM)));
	}else{
		CLEAR_BIT(BxCAN->MCR,CAN_MCR_AWUM);
	}
	//Set the Bittiming timing 
	WRITE_REG(BxCAN->BTR,(initparams->TIME_SEG1<<BxCAN_BTR_TS1_SHIFT)     |
	                     (initparams->TIME_SEG2<<BxCAN_BTR_TS2_SHIFT)     |
											 (initparams->SYNC_JSW<<BxCAN_BTR_SJW_SHIFT)      |
											 (initparams->BAUD_PRESCALER<<BxCAN_BTR_BRP_SHIFT));
	//Set the mode 
	switch(initparams->MODE){
		case LOOPBACK:
			//Set the BTR_LBKM to Enable LoopBack mode
			BxCAN->BTR|= (1<<BxCAN_BTR_LBKM);
		  //Disable initialization mode the BxCAN By setting INRQ Bit
	    BxCAN -> MCR &=  ~(1<<CAN_MCR_INRQ_Pos);
	    //wait while INRQ is setted by waiting for BxCAN_MSR_INAK
	    while((BxCAN->MSR & CAN_MSR_INAK) != 0);
		  break;
		case SILENT:
			//Set the BTR_SLIM to Enable silent mode
			SET_BIT(BxCAN->BTR,BxCAN_BTR_SILM);
		  //Disable initialization mode the BxCAN By setting INRQ Bit
	    BxCAN -> MCR &=  ~(1<<CAN_MCR_INRQ_Pos);
	    //wait while INRQ is setted by waiting for BxCAN_MSR_INAK
	    while((BxCAN->MSR & CAN_MSR_INAK) != 0);
		  break;
		case SILENT_LOOPBACK:
			//Set the BTR_LBKM to Enable LoopBack mode
			SET_BIT(BxCAN->BTR,BxCAN_BTR_LBKM);
			//Set the BTR_SLIM to Enable silent mode
		  SET_BIT(BxCAN->BTR,BxCAN_BTR_SILM);
		  //Disable initialization mode the BxCAN By setting INRQ Bit
	    BxCAN -> MCR &=  ~(1<<CAN_MCR_INRQ_Pos);
	    //wait while INRQ is setted by waiting for BxCAN_MSR_INAK
	    while((BxCAN->MSR & CAN_MSR_INAK) != 0);
		  break;
		default://setting normal mode as the default mode
			//Disable initialization mode the BxCAN By setting INRQ Bit
	    BxCAN -> MCR &=  ~(1<<CAN_MCR_INRQ_Pos);
	    //wait while INRQ is setted by waiting for BxCAN_MSR_INAK
	    while((BxCAN->MSR & CAN_MSR_INAK) != 0);
		  break;
	}
	
}

/*
this function initialize the BxCAN initparams to a default values
*/
void BxCAN_initParams(BxCAN_InitPrams *initparams){
	//Set the normal mode as the default mode
	initparams->MODE = NORMAL;
	//Set the default is off for automatic wakeup mode
	initparams->AUTO_RETx = Disable;
	//Disable the automatic retransmission mode
    initparams->AUTO_RETx = Disable;
	//Set the default Resynchronization Jump width as 2
	initparams->SYNC_JSW = 0;
	//Set the dafault Time_segmant1 as 1
	initparams->TIME_SEG1 = 11;
	//Set the dafault Time_segmant2 as 1
	initparams->TIME_SEG2 = 4;
	//Set the dafault Set the default prescaler as 8
	initparams->BAUD_PRESCALER = 0;
}

/*
This function  fires tx requests
*/
void BxCAN_TxMailBoxRQ(BxCAN_TxMessage *message){
	  volatile uint8_t freetxMailBox = 0;
		if(message != NULL){
			//Check if empty MailBox exist
			if(((BxCAN->TSR & BxCAN_TSR_TME0)!= 0U)||
				 ((BxCAN->TSR & BxCAN_TSR_TME1)!= 0U)||
			   ((BxCAN->TSR & BxCAN_TSR_TME2)!= 0U)){
					//get the lowest priority mailBox  
					freetxMailBox = (BxCAN->TSR & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos;
					//Set the ID and RTR 
				  if(message->ExtID == Disable){
						BxCAN->MAILBOX[freetxMailBox].TIR = ((message->ID<<BxCAN_TIR_STID_SHIFT)|
						                                     (message->RTR<<BxCAN_TIR_RTR));
					}else{
						BxCAN->MAILBOX[freetxMailBox].TIR = ((message->ID<<BxCAN_TIR_EXID_SHIFT)|
						                                     (message->RTR<<BxCAN_TIR_RTR));
					}
					//Set the DLC
					BxCAN->MAILBOX[freetxMailBox].TDTR = message->DLC;
					//But the data into TDR
					/*for(int i = 0;i < message->DLC;i++){
						BxCAN->MAILBOX[freetxMailBox].TDR[i] = message->DATA[i];
					}*/
					BxCAN->MAILBOX[freetxMailBox].TDLR = ((message->DATA[0])    |
																	  (message->DATA[1]<<8) |
					                          (message->DATA[2]<<16)|
					                          (message->DATA[3]<<24));
					BxCAN->MAILBOX[freetxMailBox].TDHR = ((message->DATA[4])    |
																	  (message->DATA[5]<<8) |
					                          (message->DATA[6]<<16)|
					                          (message->DATA[7]<<24));
					
					//Fire Tx request
					SET_BIT(BxCAN->MAILBOX[freetxMailBox].TIR,BxCAN_TIR_TXRQ);
			}
		}else{
			return;
		}
}


















