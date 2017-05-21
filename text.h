#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

//define shapes here
//float shape_1[4] = {x1,y1,x2,y2};

//page start end cordinates
#define X_STARTPAGE 0
#define Y_STARTPAGE 0
#define X_ENDPAGE   0
#define Y_ENDPAGE   0

//attributes
#define WORD_SPACE      0
#define LETTER_SPACE    0
#define LINE_SPACE      0


#define MAX_FONTSIZE 5

void next_line(void);
void next_word (void);
void next_letter (void);
void draw_char (char letter);
void draw_string (void);


void quick_square(void);
void quick_triangle(void);
void quick_circle(void);

#endif // TEXT_H_INCLUDED
