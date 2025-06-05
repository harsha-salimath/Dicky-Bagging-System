// dick contro s/m
#include<LPC17xx.h>
#include "canfunction.c"
#include "pll_main.c"
#define sw (1<<12)
void delay(unsigned int i);
int main(){
	pll_96mhz();
	can_config();
	LPC_GPIO2->FIODIR &= ~sw;
	while(1){
		if(LPC_GPIO2->FIOPIN &(sw)){
			can_tx('A');
			delay(100);
		}
	}
}
		void delay(unsigned int i){
			int j,k;
			for(j=0;j<i;j++)
			for(k=0;k<1275;k++);
		}