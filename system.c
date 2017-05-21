#include "system.h"


void system_init(void)
{
    Lcd8_Init();                        //lcd initialise
    EXPANDER_WriteByte(EXP_INPUT);      //config input and output pins
    EXPANDER_WriteByte(EN1_1 | EN2_1 | DR1_1 | DR2_1);
    Lcd8_Clear();
    delay_ms(5);

    motor_goto_xy(0,0);                 //on power up goto default location 0,0
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

