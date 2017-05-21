#include "system.h"
float current_x,current_y;

void motor_x(float x)               //X AXIS head CONTROL
{
    int loop_count=0;
    int x_diff=0,x_steps=0;

    //set motor enable
    if(x > current_x)               //move right
    {
        //set direction motor
        x_diff = x - current_x;
        x_steps = x_diff * 10;      //calculate number of steps (1 step = 0.1 units)

        while(loop_count < x_steps)
        {
            //set step motor
            loop_count ++;
        }
    }
    else                            //move left
    {
        //set direction motor
        if(x < current_x)
        {
            //set direction motor
            x_diff = current_x - x;
            x_steps = x_diff * 10;

            while(loop_count < x_steps)
            {
                //set step motor
                loop_count ++;
            }
        }
    }
    current_x = x;                  //set current x cordinate
}

void motor_y(float y)               //Y AXIS head CONTROL
{
    int loop_count=0;
    int y_diff=0,y_steps=0;

    //set motor enable
    if(y > current_y)               //move down
    {
        //set direction motor
        y_diff = y - current_y;
        y_steps = y_diff * 10;      //calculate number of steps (1 step = 0.1 units)

        while(loop_count < y_steps)
        {
            //set step motor
            loop_count ++;
        }
    }
    else                            //move up
    {
        //set direction motor
        if(y < current_y)
        {
            //set direction motor
            y_diff = current_y - y;
            y_steps = y_diff * 10;

            while(loop_count < y_steps)
            {
                //set step motor
                loop_count ++;
            }
        }
    }
    current_y = y;                  //set current x cordinate
}

void motor_goto_xy(float x,float y) //merge both functions into one
{
    motor_x(x);
    motor_y(y);
}
