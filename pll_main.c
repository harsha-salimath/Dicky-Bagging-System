#include<LPC17xx.h>		 
void pll_96mhz(void){
LPC_SC->SCS=(1<<4)|(1<<5);  //enable main oscillator
 LPC_SC->PLL0CON = 0; //disable pll
LPC_SC->PLL0FEED=0XAA; //give feed signal
 LPC_SC->PLL0FEED=0X55;
while(!(LPC_SC->SCS & (1<<6)));  
//check main oscillator stable or not
 LPC_SC->CLKSRCSEL = 1; //select clk source from PLL
LPC_SC->PLL0CFG = 0x00F; //config PLL with	
LPC_SC->PLL0CON = 1;   //enable PLL
   LPC_SC->PLL0FEED=0XAA;  //feed signal
 LPC_SC->PLL0FEED=0X55;
LPC_SC->CCLKCFG = 3;    //divide clk=FCC0/3
while(!( LPC_SC->PLL0STAT & (1<<26)));  //check PLL locked or not
	 LPC_SC->PLL0CON=(1<<0) | (1<<1); //enable PLL & connect to CPU
   		 LPC_SC->PLL0FEED=0XAA; //feed signal
 		LPC_SC->PLL0FEED=0X55;
		 }