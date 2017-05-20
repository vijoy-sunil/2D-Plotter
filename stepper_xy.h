#ifndef STEPPER_XY_H_INCLUDED
#define STEPPER_XY_H_INCLUDED

#define EN2 P1_0
#define ST2 P1_1
#define DR2 P1_4

void motor_1(float x);
void motor_2(float y);

void goto_origin (float origin_x,float origin_y);
void motor_goto_xy(float x,float y);

#endif // STEPPER_XY_H_INCLUDED
