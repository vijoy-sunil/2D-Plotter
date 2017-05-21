#ifndef STEPPER_XY_H_INCLUDED
#define STEPPER_XY_H_INCLUDED


#define STEPPER_STEP1 P1_0                //step for motor 1
#define STEPPER_STEP2 P1_4                //step for motor 2

#define EN1 P2_0
#define DR1 P2_3

#define EN2 P2_1
#define DR2 P2_4

#define LEFT_END    P2_2
#define RIGHT_END   P2_6

#define STEP_INCR 1
#define STEPS_PER_UNIT 25   // for straight lines to mov 1 unit (0,0) to (1,0) move this many steps
#define STEPS_PER_UNIT_ARC 4
#define STEPS_PER_UNIT_SL 15    //for slash
#define STEP_DELAY 15       //delay between stepper steps

void line_mod(void);

void motor_x(int x);
void motor_y(int y);

void goto_origin (int origin_x,int origin_y);
void motor_goto_xy(int x,int y);

void move_left(unsigned int l);
void move_right(unsigned int l);
void move_down(unsigned int l);
void move_up(unsigned int l);
void move_down_right(unsigned int dr);
void move_up_right(unsigned int dr);
void move_up_left(unsigned int dr);
void move_down_left(unsigned int dr);
void top_down_right(float rd);
void right_down_left(float rd);
void down_up_left(float rd);
void left_up_right(float rd);


#endif // STEPPER_XY_H_INCLUDED
