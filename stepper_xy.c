#include "system.h"
int current_x,current_y,origin_set;
extern unsigned char menu_action;
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
        delay_ms(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_ms(STEP_DELAY);
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
        delay_ms(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_ms(STEP_DELAY);
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
void circle(float new_steps)
{
    new_steps=new_steps*5;
    top_down_right(new_steps);
    right_down_left(new_steps);
    down_up_left(new_steps);
    left_up_right(new_steps);
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
        delay_ms(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_ms(STEP_DELAY);
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
        delay_ms(STEP_DELAY);
        STEPPER_STEP1=1;
        STEPPER_STEP2=1;
        delay_ms(STEP_DELAY);
        d--;
    }
    EN1 = 1;
    EN2 = 1;
}

void motor_x(int x)               //X AXIS head CONTROL
{
    int loop_count=0;
    int x_steps=0;

    if((x == 0) & (current_x == 0)) //to go to origin at start
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;

        DR1 = 1;
        DR2 = 1;                        //set direction motor - LEFT MOST

        while(1)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(1);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(1);

            if(menu_action == BACK)
                        break;
        }
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }
    else if(x > current_x)             //move right
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;

        DR1 = 0;
        DR2 = 0;                        //set direction motor

        x_steps = (x - current_x) * STEPS_PER_UNIT;
        printf("\r\n +x : %d",x_steps);
        while(loop_count < x_steps)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(1);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(1);
            loop_count ++;
        }
        loop_count = 0;
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }

    else if(x < current_x)              //move left
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;


        DR1 = 1;
        DR2 = 1;                        //set direction motor
        x_steps = (current_x - x) * STEPS_PER_UNIT;
        printf("\r\n -x : %d",x_steps);
        while(loop_count < x_steps)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(1);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(1);
            loop_count ++;
        }
        loop_count = 0;
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }

    current_x = x;                  //set current x cordinate
}

void motor_y(int y)               //Y AXIS head CONTROL
{
    int loop_count=0;
    int y_steps=0;


    if((y == 0) & (current_y == 0)) //to go to origin at start
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;

        DR1 = 0;
        DR2 = 1;                        //set direction motor - TOP MOST

        while(1)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(5);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(5);

            if(menu_action == SCROLL_UP)
                        break;
        }
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }

    else if(y > current_y)              //move down
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;

        DR1 = 1;
        DR2 = 0;                        //set direction motor
        y_steps = (y - current_y) * STEPS_PER_UNIT;
        printf("\r\n +y : %d",y_steps);
        while(loop_count < y_steps)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(5);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(5);
            loop_count ++;
        }
        loop_count = 0;
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }

    else if(y < current_y)              //move up
    {
        EN1 = 0;                        //set motor enable
        EN2 = 0;

        DR1 = 0;
        DR2 = 1;                        //set direction motor
        y_steps = (current_y - y) * STEPS_PER_UNIT;
        printf("\r\n -y : %d",y_steps);
        while(loop_count < y_steps)
        {
            STEPPER_STEP1 = 0;          //set step motor
            STEPPER_STEP2 = 0;
            delay_ms(5);
            STEPPER_STEP1 = 1;
            STEPPER_STEP2 = 1;
            delay_ms(5);
            loop_count ++;
        }
        loop_count = 0;
        EN1 = 1;                        //set motor disable
        EN2 = 1;
    }

    current_y = y;                  //set current x cordinate
}

void motor_goto_xy(int x,int y) //merge both functions into one
{
    motor_x(x);
    motor_y(y);
    origin_set=1;
}
