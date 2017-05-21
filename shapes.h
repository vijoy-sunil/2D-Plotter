#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

void vertical_up_draw(void) ;
void vertical_down_draw(void);
void horizontal_left_draw(void);
void horizontal_right_draw(void);
void forward_slash_draw(void);
void backward_slash_draw(void);

void square_draw(char size_square_cm);
void triangle_draw(char size_triangle_cm);
void circle_draw(float rd);

void forward_slash_steep(void);
void backward_slash_steep(void);

#define UD_SIZE 20  //up down slash line size for 1 cm
#define LR_SIZE 20   //left right line size for 1cm
#define SL_SIZE 1
#endif // SHAPES_H_INCLUDED
