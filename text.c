#include "system.h"
extern float current_x,current_y;
extern unsigned char cursor_x;
extern unsigned char menu_action;


void next_line(void)
{
    //motor_x(0);
    //motor_y(current_y + LINE_SPACE);
}

void next_word (void)
{
    //motor_x(current_x + WORD_SPACE);
}

void next_letter (void)
{
    //motor_x(current_x + LETTER_SPACE);
}

//void draw_char (char letter)
//{
//    int i;
//    switch(letter)
//    {
//        case 'A':
//            pen_down();
//            forward_slash_steep();
//            pen_up();
//            for(i=0;i<LR_SIZE;i++)
//                move_up(STEPS_PER_UNIT);
//            for(i=0;i<LR_SIZE;i++)
//                move_right(STEPS_PER_UNIT_SL-2);
//            pen_down();
//            backward_slash_steep();
//            pen_up();
//            break;
//
//        case 'B':
//            break;
//
//        case 'C':
//            break;
//
//        case 'D':
//            break;
//
//        case 'E':
//            break;
//
//        case 'F':
//            break;
//
//        case 'G':
//            break;
//
//        case 'H':
//            break;
//
//        case 'I':
//            break;
//
//        case 'J':
//            break;
//
//        case 'K':
//            break;
//
//        case 'L':
//            break;
//
//        case 'M':
//            break;
//
//        case 'N':
//            break;
//
//        case 'O':
//            break;
//
//        case 'P':
//            break;
//
//        case 'Q':
//            break;
//
//        case 'R':
//            break;
//
//        case 'S':
//            break;
//
//        case 'T':
//            break;
//
//        case 'U':
//            break;
//
//        case 'V':
//            break;
//
//        case 'W':
//            break;
//
//        case 'X':
//            break;
//
//        case 'Y':
//            break;
//
//        case 'Z':
//            break;
//
//        case 'a':
//            break;
//
//        case 'b':
//            break;
//
//        case 'c':
//            break;
//
//        case 'd':
//            break;
//
//        case 'e':
//            break;
//
//        case 'f':
//            break;
//
//        case 'g':
//            break;
//
//        case 'h':
//            break;
//
//        case 'i':
//            break;
//
//        case 'j':
//            break;
//
//        case 'k':
//            break;
//
//        case 'l':
//            break;
//
//        case 'm':
//            break;
//
//        case 'n':
//            break;
//
//        case 'o':
//            break;
//
//        case 'p':
//            break;
//
//        case 'q':
//            break;
//
//        case 'r':
//            break;
//
//        case 's':
//            break;
//
//        case 't':
//            break;
//
//        case 'u':
//            break;
//
//        case 'v':
//            break;
//
//        case 'w':
//            break;
//
//        case 'x':
//            break;
//
//        case 'y':
//            break;
//
//        case 'z':
//            break;
//
//        case '0':
//            break;
//
//        case '1':
//            break;
//
//        case '2':
//            break;
//
//        case '3':
//            break;
//
//        case '4':
//            break;
//
//        case '5':
//            break;
//
//        case '6':
//            break;
//
//        case '7':
//            break;
//
//        case '8':
//            break;
//
//        case '9':
//            break;
//
//        default:
//            break;
//    }
//}

void draw_string (void)
{
    char bitmap_byte;
    int ii;
//read from buffer here
//calls draw char here
//calls next_line,next_word,next_letter PEN_UP AND PEN_DOWN automatically

    for(ii=0;ii<400;ii++)
    {
        bitmap_byte = getchar();

        if(bitmap_byte == 1)
        {
            pen_down();
            move_right(125);
            pen_up();
        }
        else
        {
           move_right(125);
        }
        if((ii+1)%20==0)
        {
             move_down(125);
             move_left(2500);
        }

        putchar('S');
    }
}

