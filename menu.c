#include "system.h"


extern unsigned char cursor_x;
extern unsigned char menu_action;

int temp;

void origin_menu_1_1(void)              //origin setting menu option
{
    lcd_screen_2_1();
    cursor_x = 0;
    origin_menu_x(2,6,2,8);            //custom logo for x dir
    origin_menu_y(1,7,3,7);            //custom logo for y dir
    menu_action = 0;
    while(1)
    {
        if(menu_action == BACK)
        {
            menu_action = 0;
            while(menu_action != BACK)
            {
                move_left(STEPS_PER_UNIT);
            }
            menu_action = 0;
        }

        if(menu_action == ENTER)
        {
            menu_action = 0;
            while(menu_action != ENTER)
            {
                move_right(STEPS_PER_UNIT);
            }
            menu_action = 0;
        }

        if(menu_action == SCROLL_UP)
        {
            menu_action = 0;
            while(menu_action != SCROLL_UP)
            {
                move_up(STEPS_PER_UNIT);
            }
            menu_action = 0;
        }

        if(menu_action == SCROLL_DOWN)
        {
            menu_action = 0;
            while(menu_action != SCROLL_DOWN)
            {
                move_right(STEPS_PER_UNIT);
            }
            menu_action = 0;
        }

        if(menu_action == VALUE_SET)   //condition for exit loop
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
            if(cursor_x == 0)               //3x3 SQUARE
            {
                hour_glass(1,15);           //hour glass logo next to 1x1 square
                pen_down();
                square_draw(3);
                pen_up();
                Lcd_gotoxy(1,15);               //clear hour glass logo
                Lcd8_Write_Char(' ');
            }
            else if(cursor_x == 1)           //3x3 TRIANGLES
            {
                hour_glass(2,15);           //hour glass logo next to 1x1 triangle
                pen_down();
                triangle_draw(3);
                pen_up();
                Lcd_gotoxy(2,15);               //clear hour glass logo
                Lcd8_Write_Char(' ');
            }
            else if(cursor_x == 2)           //3x3 CIRCLE
            {
                hour_glass(3,15);           //hour glass logo next to 1x1 circle
                pen_down();
                circle_draw(3);
                pen_up();
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
    lcd_screen_2_3_2();          //cursor display - initial location
    cursor_display(1);
    cursor_x = 0;

    while(1)
    {
        menu_scroll();
        if(menu_action == ENTER)            //enter option
        {
            menu_action = 0;
            if(cursor_x == 0)               //start option
            {
                Lcd_gotoxy(2,11);           //clear stop logo
                Lcd8_Write_Char(' ');
                cursor_x=0;
                hour_glass(1,11);           //hour glas  logo display next to print
                draw_string();              //main orint function
                Lcd_gotoxy(1,11);            //clear hour glass logo
                Lcd8_Write_Char(' ');
                pen_up();
            }
            else if(cursor_x == 1)           //stop option
            {
                Lcd_gotoxy(1,11);            //clear hour glass logo
                Lcd8_Write_Char(' ');
                stop_logo(2,11);             //exclamation logo next to stop
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




