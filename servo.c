//THIS MODULE CONTAINS THE CODE FOR CONTROLLING SERVO MOTOR TO MOVE PEN UP AND DOWN TO TOUCH THE PAPER
//AUTHOR(S): VIJOY SUNIL KUMAR, PRAVEEN GNANASEKARAN

#include "system.h"

void pen_down(void)           //servo motor control
{
    int exit = 5;	//A VARAIBLE COUNT IS KEPT TO ENSURE THE SERVO TOUCHES THE PAPER PROPERLY
    while(exit!=0)          //1.5 ms step neutral   
    {
        SERVO_STEP =1;	//APPROX 20ms PWM DUTY CYCLE USED FOR THE MICRO SERVO MOTOR
        delay_ms(1);
        delay_us(35);
        SERVO_STEP =0;
        delay_ms(18);
        exit --;
    }

}

void pen_up(void)       //servo motor control
{
    int exit = 5;	//A VARAIBLE COUNT IS KEPT TO ENSURE THE SERVO RELEASES CONTACT FROM PAPER
    while(exit!=0)
    {
        SERVO_STEP =1;	//APPROX 20ms PWM DUTY CYCLE USED FOR THE MICRO SERVO MOTOR
        delay_us(35);
        delay_us(30);
        SERVO_STEP =0;
        delay_ms(18);
        exit--;
    }

}


