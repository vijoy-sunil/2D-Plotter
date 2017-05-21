//THIS MODULE CONTAINS THE CODE FOR DELAYS USED FOR GENERATING PWM TO CONTROL THE SERVO AND STEPPER MOTORS
//AUTHOR(S): VIJOY SUNIL KUMAR, PRAVEEN GNANASEKARAN
#include "system.h"

void delay_us(unsigned int us_count)
{
    while(us_count!=0)
    {
        us_count--;
    }
}

void delay_ms(unsigned int ms_count)
{
    while(ms_count!=0)
    {
        delay_us(52);	 //delay_us is called to generate 1ms delay
        ms_count--;
    }

}

void delay_sec(unsigned char sec_count)
{
	 while(sec_count!=0)
    {
        delay_ms(1000);	//delay_ms is called to generate 1sec delay
        sec_count--;
    }
}
