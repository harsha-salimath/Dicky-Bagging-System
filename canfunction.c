/*CAN1 ->  TD1- P0.0, RD1->P0.1
 		 CAN2 -> TD2-P2.7, RD2->P2.8*/  
 		unsigned int MSG[30]; 
		void can_config(void) {
	LPC_SC->PCONP|=(1<<13)|(1<<14); 
	//Enable POwer CAN1 and CAN2
LPC_SC->PCLKSEL0 &= ~((1<<26)|(1<<27)|(1<<28)|(1<<29));
//Enable CLK, and Pclk--> 24Mhz //clk for acf
 LPC_PINCON->PINSEL0|=(1<<0)|(1<<2); //CAN1	Config CAN1 Port pins 		    	//Config CAN1 Port pins 
 LPC_PINCON->PINSEL4|=(1<<14)|(1<<16);//CAN2 Config CAN2 Port pins 	
 /*CAN config  BRP=24   TSEG1=16->15, TSEG2=4->3*/
   LPC_CAN1->MOD=(1<<0);	//NOT OPERATIONAL					// Disable CAN1
   LPC_CAN1->BTR=(23<<0)|(15<<16)|(3<<20); //speed can=500kbps,20tq,24MHZ
   LPC_CAN1->MOD=0; //ENABLE CAN1						//Enable CAN1
   LPC_CAN2->MOD=(1<<0);	// Disable CAN2
 	 LPC_CAN2->BTR=(23<<0)|(15<<16)|(3<<20);
 	 LPC_CAN2->MOD=0;	//ENABLE CAN2						//Enable CAN2 
 	}
		
 	void can_tx(unsigned int d) { // CAN2 as Tx
	while(!(LPC_CAN2->GSR & (1<<2)));//Check TBR Empty or not use Polling method
	LPC_CAN2->TID1=147;//Load Id,address 11bit
	LPC_CAN2->TFI1=(1<<18);// LOad frame info, DLC=0100=4byte, RTR=0, IDE=0
  LPC_CAN2->TDA1=d;//Load the 4byte Data
	LPC_CAN2->CMR=(1<<0)|(1<<5);//Select TB1, requesting transmission
	while(!(LPC_CAN2->GSR & (1<<3)));//Check Tx Status Bit ,transmission is completed or not  
		}
	