#include "system.h"


void system_init(void)
{
    Lcd8_Init();                        //lcd initialise
    Lcd8_Clear();
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

