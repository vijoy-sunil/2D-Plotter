#include "system.h"
float current_x,current_y;

void motor_x(float x)    //X AXIS MOTOR CONTROL
{
    if(current_x > x)       //move right
    {

    }
    else                    //move left
    {

    }
}

void motor_y(float y)    //Y AXIS MOTOR CONTROL
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
