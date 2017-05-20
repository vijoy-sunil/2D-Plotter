#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

//define shapes here

//page start end cordinates
#define X_STARTPAGE 0
#define Y_STARTPAGE 0
#define X_ENDPAGE   0
#define Y_ENDPAGE   0

void next_line(void);
void next_word (void);
void next_letter (void);
void draw_char (char letter);
void draw_string (void);
void pen_up(void);
void pen_down(void);

void quick_square(void);
void quick_triangle(void);
void quick_circle(void);

#endif // TEXT_H_INCLUDED
