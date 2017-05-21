/*
* QWERTY_PEN REV
*
 */


#include "system.h"

unsigned char cursor_x=0;
unsigned char sw_press,menu_action;

xdata char circular_buffer[BUFFER_SIZE];    //uart buffer components
xdata unsigned char rd_pntr,wr_pntr;

_sdcc_external_startup()
{
    AUXR |= 0x0C;
                                            //setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;

    TCON |= INT0_EDGE;                                    //edge triggered
    IEN0 = GLOBAL_INT | INT0_MASK | SERIAL_MASK;          //enable global and int0 interrrupt
    return 0;
}

void main(void)
{
    int i=0,x=0,y=0;
    system_init();
    while(1)                //menu loop
    {
        lcd_screen_1();     //qwerty pen
        delay_sec(1);
        lcd_screen_2();     //menu - origin/quick/custom

        cursor_display(1);   //cursor display - initial location
        delay_ms(1);

        if(wr_pntr!=rd_pntr) //ONLY IF KEY IS PRESSED AND WR_PNTR!=0, THIS WILL PRINT
        {
            putchar(circular_buffer[rd_pntr]);
            rd_pntr=((rd_pntr+1)%BUFFER_SIZE);
        }
        while(1)
        {
            menu_scroll();
            if(menu_action == ENTER)            //enter option
            {
                menu_action = 0;
                if(cursor_x == 0)               //origin set
                    origin_menu_1_1();
                else if(cursor_x == 1)          //quick print
                    quick_menu_1_2();
                else if(cursor_x == 2)          //custom print
                    custom_menu_1_3();
            }
        }
    }
}

void ex0_isr(void) __interrupt 0         //isr for external interrupt
{
    IEN0 &=~(GLOBAL_INT | INT0_MASK);   //disable int0 and global  interrupt
    sw_press = EXPANDER_ReadByte();     //read expander

    if(sw_press != 0xFF)                //identify switch and set flag
    {
        if((sw_press & SW_MASK) == (LEFT & RIGHT))
        {
            menu_action = ORIGIN_SET;
        }
        else if((sw_press & SW_MASK) == LEFT)
        {
            menu_action = BACK;
        }
        else if((sw_press & SW_MASK) == RIGHT)
        {
            menu_action = ENTER;
        }
        else if((sw_press & SW_MASK) == UP)
        {
            menu_action = SCROLL_UP;
        }
        else if((sw_press & SW_MASK) == DOWN)
        {
            menu_action = SCROLL_DOWN;
        }
    }
    sw_press=0;
    IEN0 |=(GLOBAL_INT | INT0_MASK);    //enable int0 and global interrupt
}

void serial_interrupt(void)__interrupt 4    //Subroutine for SERIAL ISR Interrupt
{
    if(RI==1)
    {
        while (!RI);
        RI=0;
        circular_buffer[wr_pntr]=SBUF;
        wr_pntr=((wr_pntr+1)%BUFFER_SIZE);
    }
}
