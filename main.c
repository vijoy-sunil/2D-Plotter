/*
* QWERTY_PEN REV
*
 */


#include "system.h"

unsigned char cursor_x=0;
unsigned char sw_press,menu_action;


_sdcc_external_startup()
{
    AUXR |= 0x0C;
                        //setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;

    TCON |= INT0_EDGE;                      //edge triggered
    IEN0 = GLOBAL_INT | INT0_MASK;          //enable global and int0 interrrupt


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

void ex0_isr(void) __interrupt 0        //isr for external interrupt
{
    IEN0 &=~(GLOBAL_INT | INT0_MASK);   //disable int0 and global  interrupt
    sw_press = EXPANDER_ReadByte();     //read expander


    if(sw_press != 0xFF)
    {
        if(sw_press == (LEFT & RIGHT))
        {
            menu_action = ORIGIN_SET;
        }
        else if(sw_press == LEFT)                //identify switch and set flag
        {
            menu_action = BACK;
        }
        else if (sw_press == RIGHT)
        {
            menu_action = ENTER;
        }
        else if (sw_press == UP)
        {
            menu_action = SCROLL_UP;
        }
        else if (sw_press == DOWN)
        {
            menu_action = SCROLL_DOWN;
        }
    }
    sw_press=0;
    IEN0 |=(GLOBAL_INT | INT0_MASK);    //enable int0 and global interrupt
}


