#ifndef STEPPER_XY_H_INCLUDED
#define STEPPER_XY_H_INCLUDED


#define ST1 P1_0
#define ST2 P1_4

#define EN1_1 0x80 | 0x0F
#define DR1_1 0x40 | 0x0F

#define EN1_0 0x00 | 0x0F
#define DR1_0 0x00 | 0x0F

#define EN2_1 0x10 | 0x0F
#define DR2_1 0x20 | 0x0F

#define EN2_0 0x00 | 0x0F
#define DR2_0 0x00 | 0x0F


void motor_x(float x);
void motor_y(float y);

void goto_origin (float origin_x,float origin_y);
void motor_goto_xy(float x,float y);

#endif // STEPPER_XY_H_INCLUDED
