/*
* QWERTY_PEN REV 0.1
* LCD MENU
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
            if(menu_action == ENTER)       //enter option
            {
                menu_action = 0;
                if(cursor_x == 0)               //origin set - no cursor location
                {
                    lcd_screen_2_1();
                    cursor_x = 0;
                    while(1)
                    {
                        set_origin();
                        //condition for exit loop
                        //print on lcd : x,y
                        //lcd_screen_2();     //menu - origin/quick/custom
                        //cursor_display(1);   //cursor display - initial location
                        //break;
                    }
                }
                else if(cursor_x == 1)          //quick print
                {
                    lcd_screen_2_2();            //cursor display - initial location
                    cursor_display(1);
                    cursor_x = 0;
                    while(1)
                    {
                        menu_scroll();
                        if(menu_action == ENTER)       //enter option
                        {
                            menu_action = 0;
                            if(cursor_x == 0)               //1x1 SQUARE
                            {
                                cursor_x = 0;
                                //hour glass logo next to 1x1 square
                                quick_square();
                                //clear hour glass logo
                            }
                            else if(cursor_x == 1)           //1x1 TRIANGLES
                            {
                                cursor_x = 0;
                                //hour glass logo next to 1x1 triangle
                                quick_triangle();
                                //clear hour glass logo
                            }
                            else if(cursor_x == 2)           //1x1 CIRCLE
                            {
                                cursor_x = 0;
                                //hour glass logo next to 1x1 circle
                                quick_circle();
                                //clear hour glass logo
                            }
                        }
                        else if(menu_action == BACK)
                        {
                            cursor_x = 0;
                            lcd_screen_2();             //menu - origin/quick/custom
                            cursor_display(1);          //cursor display - initial location
                            menu_action=0;
                            delay_ms(1);
                            break;
                        }
                    }
                }
                else if(cursor_x == 2)          //custom print
                {
                    lcd_screen_2_3();           //cursor display - initial location
                    cursor_display(1);
                    cursor_x = 0;
                    while(1)
                    {
                        menu_scroll();
                        if(menu_action == ENTER)       //enter option
                        {
                            menu_action = 0;
                            if(cursor_x == 0)               //STYLE select
                            {
                                lcd_screen_2_3_1();         //cursor display - initial location
                                cursor_display(1);
                                cursor_x = 0;
                                while(1)
                                {
                                    menu_scroll();
                                    if(menu_action == ENTER)       //enter option
                                    {
                                        menu_action = 0;
                                        if(cursor_x == 0)               //FONT SIZE
                                        {
                                            cursor_x=0;
                                            //display custom up/down button
                                            while(1)
                                            {
                                                //up/down switch press
                                                //increment font - font_size
                                                //display font_size
                                                //condition for break

                                            }
                                        }
                                        else if(cursor_x == 1)          //FONT STYLE
                                        {
                                            cursor_x=0;
                                            //display custom up/down button
                                            while(1)
                                            {
                                                //up/down switch press
                                                //bold-no bold display
                                                //condition for break
                                            }
                                        }
                                    }
                                    else if(menu_action == BACK)
                                    {
                                        cursor_x = 0;
                                        lcd_screen_2_3();            //custom print
                                        cursor_display(1);          //cursor display - initial location
                                        menu_action=0;
                                        delay_ms(1);
                                        break;
                                    }
                                }
                            }
                            else if(cursor_x == 1)           //PRINT select
                            {
                                lcd_screen_2_3_2();
                                cursor_display(1);          //cursor display initial location
                                cursor_x = 0;
                                while(1)
                                {
                                    menu_scroll();
                                    if(menu_action == ENTER)       //enter option
                                    {
                                        menu_action = 0;
                                        if(cursor_x == 0)               //start option
                                        {
                                            cursor_x=0;
                                            //hour glas  logo display next to print
                                            //main print function - loop - in isr - down switch  - move cursor - break
                                            //goto orogon
                                        }
                                        else if(cursor_x == 1)           //stop option
                                        {
                                            cursor_x=0;
                                            //exclamatio logo next to stop
                                            //stop print
                                            //back to origin
                                        }
                                    }
                                    else if(menu_action == BACK)
                                    {
                                        cursor_x = 0;
                                        lcd_screen_2_3();            //custom print
                                        cursor_display(1);          //cursor display - initial location
                                        menu_action=0;
                                        delay_ms(1);
                                        break;
                                    }
                                }
                            }
                        }


                        else if(menu_action == BACK)
                        {
                            lcd_screen_2();             //menu - origin/quick/custom
                            cursor_display(1);          //cursor display initial location
                            menu_action=0;
                            cursor_x = 0;
                            break;
                        }
                    }
                }
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
        printf_tiny("%x",sw_press);
        if(sw_press == LEFT)                //identify switch and set flag
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


