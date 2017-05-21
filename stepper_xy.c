#include "system.h"

extern unsigned char menu_action;

void line_mod(void)
{
    if(LEFT_END == 0)
    {
        printf("\r\nleft end");
    }
    else if(RIGHT_END == 0)
    {
      printf("\r\nright end");
    }
}
void move_left(unsigned int l)
{
    EN1 = 0;
    EN2 = 0;

    DR1 = 1;
    DR2 = 1;

    while(l>0)
    {
        STEPPER_STEP1=0;
        STEPPER_STEP2=0;
        delay_us(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_us(STEP_DELAY);
        l--;
    }
    EN1 = 1;
    EN2 = 1;
}

void move_right(unsigned int r)
{
    EN1 = 0;
    EN2 = 0;

    DR1 = 0;
    DR2 = 0;

    while(r>0)
    {
        STEPPER_STEP1=0;
        STEPPER_STEP2=0;
        delay_us(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_us(STEP_DELAY);
        r--;
    }
    EN1 = 1;
    EN2 = 1;
}

void move_down_right(unsigned int dr)
{
    while(dr>0)
    {
        move_down(STEPS_PER_UNIT);
        move_right(STEPS_PER_UNIT);
        dr--;
    }
}
void move_up_right(unsigned int dr)
{
    while(dr>0)
    {
        move_up(STEPS_PER_UNIT);
        move_right(STEPS_PER_UNIT);
        dr--;
    }
}
void move_down_left(unsigned int dr)
{
    while(dr>0)
    {
        move_down(STEPS_PER_UNIT);
        move_left(STEPS_PER_UNIT);
        dr--;
    }

}
void move_up_left(unsigned int dr)
{
    while(dr>0)
    {
        move_up(STEPS_PER_UNIT);
        move_left(STEPS_PER_UNIT);
        dr--;
    }
}
void top_down_right(float new_steps)
{
    new_steps= new_steps*STEPS_PER_UNIT_ARC;
    move_right(4*new_steps);
    move_down(1*new_steps);
    move_right(3*new_steps);
    move_down(1*new_steps);
    move_right(2*new_steps);
    move_down(1*new_steps);
    move_right(2*new_steps);
    move_down(1*new_steps);
    move_right(1*new_steps);
    move_down(1*new_steps);
    move_right(1*new_steps);
    move_down(1*new_steps);
    move_right(1*new_steps);
    move_down(2*new_steps);
    move_right(1*new_steps);
    move_down(3*new_steps);
    move_right(1*new_steps);
    move_down(4*new_steps);
}

void right_down_left(float new_steps)
{
    new_steps= new_steps*STEPS_PER_UNIT_ARC;
    move_down(4*new_steps);
    move_left(1*new_steps);
    move_down(3*new_steps);
    move_left(1*new_steps);
    move_down(2*new_steps);
    move_left(1*new_steps);
    move_down(2*new_steps);
    move_left(1*new_steps);
    move_down(1*new_steps);
    move_left(1*new_steps);
    move_down(1*new_steps);
    move_left(1*new_steps);
    move_down(1*new_steps);
    move_left(2*new_steps);
    move_down(1*new_steps);
    move_left(3*new_steps);
    move_down(1*new_steps);
    move_left(4*new_steps);
}
void down_up_left(float new_steps)
{
    new_steps= new_steps*STEPS_PER_UNIT_ARC;
    move_left(4*new_steps);
    move_up(1*new_steps);
    move_left(3*new_steps);
    move_up(1*new_steps);
    move_left(2*new_steps);
    move_up(1*new_steps);
    move_left(2*new_steps);
    move_up(1*new_steps);
    move_left(1*new_steps);
    move_up(1*new_steps);
    move_left(1*new_steps);
    move_up(1*new_steps);
    move_left(1*new_steps);
    move_up(2*new_steps);
    move_left(1*new_steps);
    move_up(3*new_steps);
    move_left(1*new_steps);
    move_up(4*new_steps);
}

void left_up_right(float new_steps)
{
    new_steps= new_steps*STEPS_PER_UNIT_ARC;
    move_up(4*new_steps);
    move_right(1*new_steps);
    move_up(3*new_steps);
    move_right(1*new_steps);
    move_up(2*new_steps);
    move_right(1*new_steps);
    move_up(2*new_steps);
    move_right(1*new_steps);
    move_up(1*new_steps);
    move_right(1*new_steps);
    move_up(1*new_steps);
    move_right(1*new_steps);
    move_up(1*new_steps);
    move_right(2*new_steps);
    move_up(1*new_steps);
    move_right(3*new_steps);
    move_up(1*new_steps);
    move_right(4*new_steps);
}
void move_up(unsigned int u)
{
    EN1 = 0;
    EN2 = 0;
    DR1 = 0;
    DR2 = 1;

    while(u>0)
    {
        STEPPER_STEP1=0;
        STEPPER_STEP2=0;
        delay_us(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_us(STEP_DELAY);
        u--;
    }
    EN1 = 1;
    EN2 = 1;
}
void move_down(unsigned int d)
{
    EN1 = 0;
    EN2 = 0;

    DR1 = 1;
    DR2 = 0;

    while(d>0)
    {
        STEPPER_STEP1=0;
        STEPPER_STEP2=0;
        delay_us(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_us(STEP_DELAY);
        d--;
    }
    EN1 = 1;
    EN2 = 1;
}

