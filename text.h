#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

// define shapes here
// {start cordinates x,y,end corrdinates x,y}

//float line_long_horizontal[4] = {0.0,0.0,x2,y2};
//float line_long_vertical[4] = {0.0,0.0,x2,y2};
//int line_long_front[4] = {30,0,0,10};
//float line_long_back[4] = {0.0,0.0,x2,y2};
//
//float line_short_horizontal[4] = {0.0,0.0,x2,y2};
//float line_short_vertical[4] = {0.0,0.0,x2,y2};
//float line_short_front[4] = {x1,y1,x2,y2};
//float line_short_back[4] = {0.0,0.0,x2,y2};
//
//float semicircle_large_right[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_large_left[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_large_up[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_large_down[6] = {0.0,0.0,x2,y2,x3,y3};
//
//float semicircle_small_right[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_small_left[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_small_up[6] = {0.0,0.0,x2,y2,x3,y3};
//float semicircle_small_down[6] = {0.0,0.0,x2,y2,x3,y3};
//
//float small_tail_right[4] = {x1,y1,x2,y2};
//float small_tail_left[4] = {x1,y1,x2,y2};


//QUARTER CIRCLE vlaues
char quad_value[] = {   0,0,0,0,0,0,1,   //1
                        0,0,0,0,0,1,1,   //2
                        0,0,0,0,1,1,1,   //3
                        0,0,0,1,0,1,1,   //4
                        0,0,0,1,1,1,1,   //5
                        0,0,1,1,0,1,1,   //6
                        0,0,1,1,1,1,1,   //7
                        0,1,0,1,1,1,1,   //8
                        0,1,1,1,0,1,1,   //9
                        0,1,1,1,1,1,1,   //10
                        1,0,1,1,0,1,1,   //11
                        1,0,1,1,1,1,1,   //12
                        1,1,1,0,1,1,1,   //13
                        1,1,1,1,0,1,1,   //14
                        1,1,1,1,1,1,1};  //15

char step_value[] = {5,3,2,2,1,1,1};
#define MAX_STEP_CIRCLE 7


//page start end cordinates
#define X_STARTPAGE 0
#define Y_STARTPAGE 0
#define X_ENDPAGE   10000
#define Y_ENDPAGE   10000

//attributes
#define WORD_SPACE      0
#define LETTER_SPACE    0
#define LINE_SPACE      0

#define BT_RESET P2_7


void next_line(void);
void next_word (void);
void next_letter (void);
void draw_char (char letter);
void draw_string (void);


#endif // TEXT_H_INCLUDED
