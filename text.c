#include "system.h"
extern float current_x,current_y;
extern unsigned char cursor_x;
extern unsigned char menu_action;
//character mapping here


void next_line(void)
{
    motor_x(0);
    motor_y(current_y + LINE_SPACE);
}

void next_word (void)
{
    motor_x(current_x + WORD_SPACE);
}

void next_letter (void)
{
    motor_x(current_x + LETTER_SPACE);
}

void draw_char (char letter)
{
//start print fom origin_x and origin_y - do not change these
 letter=0;
}

void draw_string (void)
{
//start print fom origin_x and origin_y - do not change these
//calls next_line,next_word,next_letter PEN_UP AND PEN_DOWN automatically
//calls draw char here
//read from buffer here
    while(1)
    {
        menu_scroll();              //break condition 1 - on pressing stop
        if(menu_action == ENTER)
        {
            menu_action = 0;
            if(cursor_x == 1)
                break;
        }
        //if(string count reached break)    //break condition 2 - print complete
    }
}


void quick_circle(void)
{

}

void quick_triangle(void)
{

}

void quick_square(void)
{

}

