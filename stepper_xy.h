#ifndef STEPPER_XY_H_INCLUDED
#define STEPPER_XY_H_INCLUDED

#define EN2 P1_0
#define ST2 P1_1
#define DR2 P1_4

void motor_1_xy(int x,int y);
void motor_2_xy(int x,int y);
void set_origin (void);
void goto_origin (int origin_x,int origin_y);
void sw_motor_xy (void);

#endif // STEPPER_XY_H_INCLUDED
