#include "system.h"
float current_x,current_y;

void motor_1(float x)    //XY AXIS MOTOR CONTROL
{
    if(current_x > x)       //move right
    {

    }
    else                    //move left
    {

    }
}

void motor_2(float y)    //XY AXIS MOTOR CONTROL
{
    if(current_y > y)       //move down
    {

    }
    else                    //move up
    {

    }
}

void motor_goto_xy(float x,float y)
{
    x=0;
    y=0;
}
