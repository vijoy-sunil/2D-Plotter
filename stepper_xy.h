#ifndef STEPPER_XY_H_INCLUDED
#define STEPPER_XY_H_INCLUDED


#define STEPPER_STEP1 P1_0                //step for motor 1
#define STEPPER_STEP2 P1_4                //step for motor 2

#define EN1_1 0x80 | 0x0F       //enable high for motor 1 with p0-p3 as inputs to send to expander
#define DR1_1 0x40 | 0x0F       //direction 1 for motor 1

#define EN1_0 0x00 | 0x0F       //enable low for motor 1 with p0-p3 as inputs to send to expander
#define DR1_0 0x00 | 0x0F       //direction 0 for motor 1

#define EN2_1 0x10 | 0x0F       //enable high for motor 2 with p0-p3 as inputs to send to expander
#define DR2_1 0x20 | 0x0F       //direction 1 for motor 2

#define EN2_0 0x00 | 0x0F       //enable low for motor 2 with p0-p3 as inputs to send to expander
#define DR2_0 0x00 | 0x0F       //direction 0 for motor 2


void motor_x(float x);
void motor_y(float y);

void goto_origin (float origin_x,float origin_y);
void motor_goto_xy(float x,float y);

#endif // STEPPER_XY_H_INCLUDED
