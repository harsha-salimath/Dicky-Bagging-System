#include<LPC17xx.h>
#define RS (1<<10)
#define EN (1<<11)
#define DATA (0xFF<<15)

void delay(unsigned int a);
void lcd_config(void);
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char d);
//void lcd_str(unsigned char *ptr);
void lcd_str(unsigned char str[20]);
 void lcd_num(unsigned int num);