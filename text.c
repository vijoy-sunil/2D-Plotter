#include "system.h"
extern float current_x,current_y;
extern unsigned char cursor_x;
extern unsigned char menu_action;


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
    switch(letter)
    {
        case 'A':
//            draw_long_forward_slash();
//            //adjust pen here
//            draw_long_backward_slash();
//            //adjust pen here
//            draw_small_horizontal();
            //adjust pen here
            break;

        case 'B':
            break;

        case 'C':
            break;

        case 'D':
            break;

        case 'E':
            break;

        case 'F':
            break;

        case 'G':
            break;

        case 'H':
            break;

        case 'I':
            break;

        case 'J':
            break;

        case 'K':
            break;

        case 'L':
            break;

        case 'M':
            break;

        case 'N':
            break;

        case 'O':
            break;

        case 'P':
            break;

        case 'Q':
            break;

        case 'R':
            break;

        case 'S':
            break;

        case 'T':
            break;

        case 'U':
            break;

        case 'V':
            break;

        case 'W':
            break;

        case 'X':
            break;

        case 'Y':
            break;

        case 'Z':
            break;

        case 'a':
            break;

        case 'b':
            break;

        case 'c':
            break;

        case 'd':
            break;

        case 'e':
            break;

        case 'f':
            break;

        case 'g':
            break;

        case 'h':
            break;

        case 'i':
            break;

        case 'j':
            break;

        case 'k':
            break;

        case 'l':
            break;

        case 'm':
            break;

        case 'n':
            break;

        case 'o':
            break;

        case 'p':
            break;

        case 'q':
            break;

        case 'r':
            break;

        case 's':
            break;

        case 't':
            break;

        case 'u':
            break;

        case 'v':
            break;

        case 'w':
            break;

        case 'x':
            break;

        case 'y':
            break;

        case 'z':
            break;

        case '0':
            break;

        case '1':
            break;

        case '2':
            break;

        case '3':
            break;

        case '4':
            break;

        case '5':
            break;

        case '6':
            break;

        case '7':
            break;

        case '8':
            break;

        case '9':
            break;

        default:
            break;
    }
}

void draw_string (void)
{
//start print fom origin_x and origin_y - do not change these
//read from buffer here
//calls draw char here
//calls next_line,next_word,next_letter PEN_UP AND PEN_DOWN automatically
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

/* --------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  Sub shapes that make up the alphabets - LARGE SHAPES - LINES
   --------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
void draw_long_forward_slash(void) // /
{
    int total_steps_x = 0;
    int total_steps_y = 0;
    int slope = 0;
    int loop_x=0,loop_y=0,i,j;

    total_steps_y = line_long_front[3] - line_long_front[1];  //height from y2-y1 coordinates
    total_steps_x = line_long_front[2] - line_long_front[0];  //width from x2-x1 coordinates

    total_steps_y = total_steps_y * STEPS_PER_UNIT * 2;
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    slope = total_steps_y/total_steps_x;

    loop_y = current_y + line_long_front[1];    //temp var
    loop_x = current_x + line_long_front[0];

    for(i=0;i<total_steps_x;i++)
    {
        for(j=0;j<slope-1;j++)
        {
            loop_y += STEP_INCR;  //increment y
            motor_goto_xy(loop_x,loop_y);
        }
        loop_x -= STEP_INCR;       //decrement x
        motor_goto_xy(loop_x,loop_y);
    }
}
*/
/*
void draw_long_backward_slash(void)
{
    int total_steps_x = 0;
    int total_steps_y = 0;
    int slope = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_y = line_long_back[3] - line_long_back[1];  //height from y2-y1 coordinates
    total_steps_x = line_long_back[2] - line_long_back[0];  //width from x2-x1 coordinates

    total_steps_y = total_steps_y * STEPS_PER_UNIT * 2;
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    slope = total_steps_y/total_steps_x;

    loop_y = current_y + line_long_back[1];    //temp var
    loop_x = current_x + line_long_back[0];

    for(i=0;i<total_steps_x;i++)
    {
        for(j=0;j<slope-1;j++)
        {
            loop_y += 0.1;      //increment y
            motor_goto_xy(loop_x,loop_y);
        }
        loop_x += 0.1           //increment x
        motor_goto_xy(loop_x,loop_y);
    }
}

void draw_long_horizontal(void)
{
    int total_steps_x = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_x = line_long_horizontal[2] - line_long_horizontal[0];
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    loop_x = current_x + line_long_horizontal[0];
    loop_y = current_y;

    for(i=0;i<total_steps_x;i++)
    {
        loop_x += 0.1;  //increment x
        motor_goto_xy(loop_x,loop_y);
    }
}

void draw_long_vertical(void)
{
    int total_steps_y = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_y = line_long_vertical[2] - line_long_vertical[0];
    total_steps_y = total_steps_y * STEPS_PER_UNIT;

    loop_x = current_x;
    loop_y = current_y + line_long_vertical[0];

    for(i=0;i<total_steps_y;i++)
    {
        loop_y += 0.1;
        motor_goto_xy(loop_x,loop_y);
    }
}*/
/* --------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  Sub shapes that make up the alphabets - SMALL SHAPES - LINES
   --------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
void draw_small_forward_slash(void) // /
{
    int total_steps_x = 0;
    int total_steps_y = 0;
    int slope = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_y = line_short_front[3] - line_short_front[1];  //height from y2-y1 coordinates
    total_steps_x = line_short_front[2] - line_short_front[0];  //width from x2-x1 coordinates

    total_steps_y = total_steps_y * STEPS_PER_UNIT * 2;
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    slope = total_steps_y/total_steps_x;

    loop_y = current_y + line_short_front[1];    //temp var
    loop_x = current_x + line_short_front[0];

    for(i=0;i<total_steps_x;i++)
    {
        for(j=0;j<slope-1;j++)
        {
            loop_y += 0.1;  //increment y
            motor_goto_xy(loop_x,loop_y);
        }
        loop_x -= 0.1       //decrement x
        motor_goto_xy(loop_x,loop_y);
    }
}


void draw_small_backward_slash(void)
{
    int total_steps_x = 0;
    int total_steps_y = 0;
    int slope = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_y = line_short_back[3] - line_short_back[1];  //height from y2-y1 coordinates
    total_steps_x = line_short_back[2] - line_short_back[0];  //width from x2-x1 coordinates

    total_steps_y = total_steps_y * STEPS_PER_UNIT * 2;
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    slope = total_steps_y/total_steps_x;

    loop_y = current_y + line_short_back[1];    //temp var
    loop_x = current_x + line_short_back[0];

    for(i=0;i<total_steps_x;i++)
    {
        for(j=0;j<slope-1;j++)
        {
            loop_y += 0.1;      //increment y
            motor_goto_xy(loop_x,loop_y);
        }
        loop_x += 0.1           //increment x
        motor_goto_xy(loop_x,loop_y);
    }
}

void draw_small_horizontal(void)
{
    int total_steps_x = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_x = line_short_horizontal[2] - line_short_horizontal[0];
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    loop_x = current_x + line_short_horizontal[0];
    loop_y = current_y;

    for(i=0;i<total_steps_x;i++)
    {
        loop_x += 0.1;  //increment x
        motor_goto_xy(loop_x,loop_y);
    }
}

void draw_small_vertical(void)
{
    int total_steps_y = 0;
    float loop_x=0.0,loop_y=0.0;

    total_steps_y = line_short_vertical[2] - line_short_vertical[0];
    total_steps_y = total_steps_y * STEPS_PER_UNIT;

    loop_x = current_x;
    loop_y = current_y + line_short_vertical[0];

    for(i=0;i<total_steps_y;i++)
    {
        loop_y += 0.1;
        motor_goto_xy(loop_x,loop_y);
    }
}
*/
/* --------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  Sub shapes that make up the alphabets - LARGE SHAPES - SEMI CIRCLES
   --------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*void draw_semi_large_left(void)
{
    int total_steps_x = 0;
    int half_steps_x = 0;

    float loop_x=0.0,loop_y=0.0;

    total_steps_x = semicircle_large_left[2] - semicircle_large_left[0];  //width from x2-x1 coordinates
    total_steps_x = total_steps_x * STEPS_PER_UNIT;

    half_steps_x = total_steps_x/2;

    loop_y = current_y + semicircle_large_left[1];    //temp var
    loop_x = current_x + semicircle_large_left[0];


    for(i=0;i<MAX_STEP_CIRCLE;i++)    //1st quarter circle
    {
        for(j=0;j<(quad_value[half_steps_x + i] * step_value[i];j++)
        {
            loop_x += 0.1;          //increment x
            motor_goto_xy(loop_x,loop_y);
        }
        if(quad_value[half_steps_x + i] != 0)
        {
            loop_y += 0.1           //increment y
            motor_goto_xy(loop_x,loop_y);
        }
    }

    for(i=0;i<MAX_STEP_CIRCLE;i++)    //2nd quarter circle
    {
        for(j=0;j<(quad_value[half_steps_x + MAX_STEP_CIRCLE - i] * step_value[MAX_STEP_CIRCLE - i];j++)
        {
            loop_y += 0.1;          //increment y
            motor_goto_xy(loop_x,loop_y);
        }
        if(quad_value[half_steps_x + i] != 0)
        {
            loop_x -= 0.1           //decrement x
            motor_goto_xy(loop_x,loop_y);
        }
    }

}
*/
