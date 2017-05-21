#include "system.h"

void pen_up(void)       //servo motor control
{
    int exit = 1000;
    while(exit != 0)         //Neutral Pulse 1250 �s
    {

        SERVO_STEP =0;
        delay_ms(1);
        delay_us(5);
        SERVO_STEP =1;
        delay_ms(1);
        delay_us(5);
        exit --;
    }
}


void pen_down(void)     //servo motor control
{
    int exit = 1000;
    while(exit != 0)          //Full CCW Pulse 2200 �s*
    {
        SERVO_STEP =0;
        delay_ms(2);
        delay_us(5);
        SERVO_STEP =1;
        delay_ms(2);
        delay_us(5);
        exit --;
    }
}
