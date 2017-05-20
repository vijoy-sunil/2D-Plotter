/*
* QWERTY_PEN REV 0.1
* LCD MENU
 */


#include "system.h"
_sdcc_external_startup()
{
    AUXR |= 0x0C;
//setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;


    return 0;
}

void main(void)
{
    system_init();
while(1)
{
    lcd_screen_2();
    delay_sec(5);
    lcd_screen_2_1();
    delay_sec(5);
    lcd_screen_2_2();
    delay_sec(5);
    lcd_screen_2_3();
    delay_sec(5);
    lcd_screen_2_3_1();
    delay_sec(5);
    lcd_screen_2_3_2();
    delay_sec(5);
}
}

void putchar(char ch)
{
    SBUF = ch;  	                // load serial port with transmit value
    while(!TI);				        // compare asm code generated for these three lines
    TI=0;  	                        // clear TI flag
}

char getchar (void)
{
    while ((SCON & 0x01) == 0);     // wait for character to be received, spin on RI
	RI = 0;			                // clear RI flag
	return SBUF;  	                // return character from SBUF
}
