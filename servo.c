#include "system.h"

void pen_down(void)           //servo motor control
{
    int exit = 5;
    while(exit!=0)          //1.5 ms step neutral   WORKING
    {
        SERVO_STEP =1;
        delay_ms(1);
        delay_us(35);
        SERVO_STEP =0;
        delay_ms(18);
        exit --;
    }

}

void pen_up(void)       //servo motor control
{
    int exit = 5;
    while(exit!=0)
    {
        SERVO_STEP =1;
        delay_us(35);
        delay_us(30);
        SERVO_STEP =0;
        delay_ms(18);
        exit--;
    }

}


