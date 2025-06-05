#include<LPC17xx.h>
#include "lcd.h"
#include "lcdfunction.c"
#include "pll_main1.c"
#include "canfuntion.c"
int main(){
	unsigned int val, i, val1;
	LPC_GPIO1->FIODIR = (1<<27);
	lcd_config();
	pll_96mhz();
	can_config();
	while(1){
		val=can_rx();
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_data(val);
		delay(200);
		if(val == 'A'){
			LPC_GPIO1->FIOSET = (1<<27);
			delay(500);
			LPC_GPIO1->FIOCLR = (1<<27);
			delay(500);
		}
	}
}
			