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
  
 	}
	 
 unsigned int can_rx(){ 	// CAN1 as Rx
	 while((LPC_CAN1->GSR & (1<<0))); 
//Check RBR Received data or not
 	MSG[0]=LPC_CAN1->RID;		 //Load ID to variable
	MSG[1]=LPC_CAN1->RDA;		 //Load data to variable
	LPC_CAN1->CMR=(1<<2); 
	//Release the receiver buffer
 	 return MSG[1];
	return MSG[0];	}
