#include "system.h"

void vertical_up_draw(void)    //1 cm = 20 steps
{
    unsigned int v_steps = 0;
    while(v_steps < UD_SIZE)
    {
        move_up(STEPS_PER_UNIT);
        v_steps++;
    }
}

void vertical_down_draw(void)   //1 cm = 20 steps
{
    unsigned int v_steps = 0;
    while(v_steps < UD_SIZE)
    {
        move_down(STEPS_PER_UNIT);
        v_steps++;
    }
}

void horizontal_left_draw(void) //1 cm = 20 steps
{
    unsigned int h_steps = 0;
    while(h_steps < LR_SIZE)
    {
        move_left(STEPS_PER_UNIT);
        h_steps++;
    }

}

void horizontal_right_draw(void) //1 cm = 20 steps
{
    unsigned int h_steps = 0;
    while(h_steps < LR_SIZE)
    {
        move_right(STEPS_PER_UNIT);
        h_steps++;
    }

}

void forward_slash_draw(void) //1 cm = 20 steps
{
    unsigned int fs_steps = 0;
    while(fs_steps < SL_SIZE)
    {
        move_down_left(STEPS_PER_UNIT_SL);
        fs_steps++;
    }
}

void backward_slash_draw(void) //1 cm = 20 steps
{
    unsigned int bs_steps = 0;
    while(bs_steps < SL_SIZE)
    {
        move_down_right(STEPS_PER_UNIT_SL);
        bs_steps++;
    }
}

void square_draw(char size_square_cm)
{
    char loop_cnt = 0;

    while(loop_cnt < size_square_cm)
    {
        horizontal_right_draw();
        loop_cnt++;
    }

    loop_cnt = 0;
    while(loop_cnt < size_square_cm)
    {
        vertical_down_draw();
        loop_cnt++;
    }
    loop_cnt = 0;
    while(loop_cnt < size_square_cm)
    {
        horizontal_left_draw();
        loop_cnt++;
    }
    loop_cnt = 0;
    while(loop_cnt < size_square_cm)
    {
        vertical_up_draw();
        loop_cnt++;
    }
}

void triangle_draw(char size_triangle_cm)
{
    char loop_cnt = 0;

    while(loop_cnt < size_triangle_cm)
    {
        forward_slash_draw();
        loop_cnt++;
    }
    loop_cnt = 0;

    while(loop_cnt < (size_triangle_cm*2))
    {
        horizontal_right_draw();
        loop_cnt++;
    }
    loop_cnt = 0;
    //pen_up();

    while(loop_cnt < (size_triangle_cm * UD_SIZE))
    {
        move_up(STEPS_PER_UNIT);
        loop_cnt++;
    }

    loop_cnt = 0;
    while(loop_cnt < (size_triangle_cm * LR_SIZE) + 1)
    {
        move_left(STEPS_PER_UNIT);
        loop_cnt++;
    }
    //pen_down();

    loop_cnt = 0;
    while(loop_cnt < size_triangle_cm)
    {
        backward_slash_draw();
        loop_cnt++;
    }
}
