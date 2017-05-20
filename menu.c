#include "system.h"

float origin_x=0.0,origin_y=0.0;         //pen location


extern unsigned char cursor_x;
extern unsigned char menu_action;

void origin_menu_1_1(void)              //origin setting menu option
{
    lcd_screen_2_1();
    cursor_x = 0;
    origin_menu_x(2,6,2,8);            //custom logo for x dir
    origin_menu_y(1,7,3,7);            //custom logo for y dir
    while(1)
    {

        if(menu_action == BACK)
        {
            if(origin_x > X_STARTPAGE)
                origin_x = origin_x - 0.1;
            menu_action=0;
            motor_goto_xy(origin_x,origin_y);
        }
        else if(menu_action == ENTER)
        {
            if(origin_x < X_ENDPAGE)
                origin_x = origin_x + 0.1;
            menu_action=0;
            motor_goto_xy(origin_x,origin_y);
        }
        else if(menu_action == SCROLL_UP)
        {
            if(origin_y > Y_STARTPAGE)
                origin_y = origin_y - 0.1;
            menu_action=0;
            motor_goto_xy(origin_x,origin_y);
        }
        else if(menu_action == SCROLL_DOWN)
        {
            if(origin_y < Y_ENDPAGE)
                origin_y = origin_y + 0.1;
            menu_action=0;
            motor_goto_xy(origin_x,origin_y);
        }

        else if(menu_action == ORIGIN_SET)   //condition for exit loop
        {
            menu_action = 0;
            Lcd8_Clear();
            Lcd_gotoxy(1,3);
            Lcd8_Write_String("ORIGIN SET");
            delay_sec(1);
            lcd_screen_2();             //menu - origin/quick/custom
            cursor_display(1);          //cursor display initial location
            menu_action=0;
            cursor_x = 0;
            break;
        }
    }
}

void quick_menu_1_2(void)        //quick print menu option
{
    lcd_screen_2_2();            //cursor display - initial location
    cursor_display(1);
    cursor_x = 0;
    while(1)
    {
        menu_scroll();
        if(menu_action == ENTER)            //enter option
        {
            menu_action = 0;
            if(cursor_x == 0)               //1x1 SQUARE
            {
                hour_glass(1,15);           //hour glass logo next to 1x1 square
                quick_square();
                Lcd_gotoxy(1,15);               //clear hour glass logo
                Lcd8_Write_Char(' ');
            }
            else if(cursor_x == 1)           //1x1 TRIANGLES
            {
                hour_glass(2,15);           //hour glass logo next to 1x1 triangle
                quick_triangle();
                Lcd_gotoxy(2,15);               //clear hour glass logo
                Lcd8_Write_Char(' ');
            }
            else if(cursor_x == 2)           //1x1 CIRCLE
            {
                hour_glass(3,15);           //hour glass logo next to 1x1 circle
                quick_circle();
                Lcd_gotoxy(3,15);               //clear hour glass logo
                Lcd8_Write_Char(' ');
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

void custom_menu_1_3(void)      //custom print option
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
                            while(1)
                            {
                                //up/down switch press
                                //increment font - font_size
                                //display font_size -initial value
                                //condition for break

                            }
                        }
                        else if(cursor_x == 1)          //FONT STYLE
                        {
                            cursor_x=0;
                            while(1)
                            {
                                //up/down switch press
                                //default: light
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
                    if(menu_action == ENTER)            //enter option
                    {
                        menu_action = 0;
                        if(cursor_x == 0)               //start option
                        {
                            Lcd_gotoxy(2,11);            //clear stop logo
                            Lcd8_Write_Char(' ');
                            cursor_x=0;
                            hour_glass(1,11);               //hour glas  logo display next to print
                            //main print function - loop - in isr - down switch  - move cursor - break
                            //goto origin
                        }
                        else if(cursor_x == 1)           //stop option
                        {
                            Lcd_gotoxy(1,11);            //clear hour glass logo
                            Lcd8_Write_Char(' ');
                            stop_logo(2,11);                 //exclamatio logo next to stop
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
