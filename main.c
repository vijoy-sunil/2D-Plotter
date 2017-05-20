/*
//Stepper motor control
 */

#include <mcs51/8051.h>
#include <at89c51ed2.h>

#include "stepper_xy.h"
#include "delays.h"

_sdcc_external_startup()
{
//    AUXR|=0x0C; //enable 1kb xram
//
//setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;


    return 0;
}

void main(void)
{
    int i=0;
    EN2 = 0;
while(1)
{
    DR2 = 0;

    while(i<300)
    {
        ST2 =1;
        delay_ms(10);
        ST2 =0;
        delay_ms(10);
        i++;
    }

    DR2 = 1;
    i=0;
    while(i<300)
    {
        ST2 =1;
        delay_ms(10);
        ST2 =0;
        delay_ms(10);
        i++;
    }
    i=0;
}

}
