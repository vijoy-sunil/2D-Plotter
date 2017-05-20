#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

//define shapes here
void goto_default(float origin_x,float origin_y);
void next_line(void);
void next_word (void);
void next_letter (void);
void draw_char (char letter);
void draw_string (char *str);
void pen_up(void);
void pen_down(void);

void quick_square(void);
void quick_triangle(void);
void quick_circle(void);

#endif // TEXT_H_INCLUDED
