


#ifndef BXCAN_H
#define BXCAN_H


/****************************typedefs****************************/
typedef enum{
	NORMAL,//Normal mode
	LOOPBACK,//LoopBack mode
	SILENT,//Silent mode
	SILENT_LOOPBACK//SilentLoopBack mode
}BxCAN_Modes;

//To Enable or Disable a feature 
typedef enum{
	Disable,//Disable this mode
	Enable//Enable this mode
}BxCAN_ModeState;

//To assign TxMessage components 
typedef struct{
	uint32_t        ID;     //message ID
	uint8_t         DLC;    //message data length
	uint8_t         DATA[8];//the data to be transfered
	BxCAN_ModeState RTR;    //remote request
	BxCAN_ModeState ExtID;  //ID is extened or not	
}BxCAN_TxMessage;
//To assign Init components
typedef struct{
	BxCAN_Modes     MODE;          //Choose the BxCAN mode
	BxCAN_ModeState AUWAKE;        //Choose to Enable or Disable Automatic wakeup mode   
	BxCAN_ModeState AUTO_RETx;     //Enable or Disable auto retransmission mode
	uint32_t        SYNC_JSW;      //Set the synch jump width
	uint32_t        TIME_SEG1;     //Choose the time segmant 1 for transmission sampling
	uint32_t        TIME_SEG2;     //Choose the time segmant 2 for transmission sampling
	uint32_t        BAUD_PRESCALER;//choose prescaler for BxCAN 
}BxCAN_InitPrams;

typedef enum{
	MAILBOX0,//Tx mailbox0
	MAILBOX1,//Tx mailbox1
	MAILBOX2 //Tx mailbox2
}BxCAN_MailBoxNum;

/****************************prototypes****************************/

/******************************************
  syntax : void BxCAN_init(BxCAN_InitPrams *initparams);

  Description : It should perform initialization sequence as mentioned in data sheet for BxCAN

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  BxCAN_InitPrams *initparams
  parameters (out) :  Non
  Return Value     : void
******************************************/
void BxCAN_init(BxCAN_InitPrams *initparams);

/******************************************
  syntax : void BxCAN_initParams(BxCAN_InitPrams *initparams);

  Description : It performs initialize the BxCAN params to the default values

  Synch/Asynch     : Synch
  Reentrance       : Non
  parameters (in)  : BxCAN_InitPrams *initparams
  parameters (out) : Non
  Return Value     : void
******************************************/
void BxCAN_initParams(BxCAN_InitPrams *initparams);

/******************************************
  syntax : void BxCAN_TxMailBoxRQ(BxCAN_TxMessage *message);

  Description : It performs initialize the BxCAN params to the default values

  Synch/Asynch     : Synchronouse
  Reentrance       : Non
  parameters (in)  : BxCAN_TxMessage *message
  parameters (out) : Non
  Return Value     : void
******************************************/
void BxCAN_TxMailBoxRQ(BxCAN_TxMessage *message);


#endif

