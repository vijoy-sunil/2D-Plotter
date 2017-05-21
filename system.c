#include "system.h"
extern unsigned char cursor_x;
extern float current_x,current_y;
extern int font_size;
extern char font_style;

void system_init(void)
{
    Lcd8_Init();                        //lcd initialise
    EXPANDER_WriteByte(EXP_INPUT);      //config input and output pins
    EXPANDER_WriteByte(EN1_1 | EN2_1 | DR1_1 | DR2_1);
    Lcd8_Clear();
    delay_ms(5);
    //-------- init values of global vars --------//
    cursor_x = 0;                       //init value of cursor
    current_x = 0;                      //current cordinates default
    current_y = 0;
    font_size = 1;                      //default font size
    font_style = 0;                     //0 - light , 1 - dark
    //--------------------------------------------//
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

