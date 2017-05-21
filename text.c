//THIS MODULE CONTAINS THE CODE FOR DRAWING A SENTENCE OR CHARACTER OR CUSTOM IMAGE AND RECEIVING PIXEL CHUNKS 
//AUTHOR(S): VIJOY SUNIL KUMAR, PRAVEEN GNANASEKARAN

#include "system.h"
extern float current_x,current_y;
extern unsigned char cursor_x;
extern unsigned char menu_action;
char circular_buffer[BUFFER_SIZE];
char stop_draw,end_origin;
extern char in_origin;

void line_mod(void)	// IF THE PLOTTER REACHES AN END, IT AUTOMATIICALY GOES TO NEXT LINE DUE TO PUSH BUTTONS ON EITHER SIDE
{
    stop_draw = 0;
    if(LEFT_END == 0)
    {

    }
    else if(RIGHT_END == 0)
    {
        stop_draw = 1;
        pen_up();
        move_down(25 * 2 * 20);
        while(LEFT_END !=0)
        {
            move_left(25);
        }
    }
}

void line_mod_left(void)
{
    if(LEFT_END == 0)
    {
        end_origin = 1;
    }
}

void line_mod_right(void)
{
    if(RIGHT_END == 0)
    {
        end_origin = 1;
    }
}

void draw_string (void)
{
    int pixels,pix_chunk,pix_size,ii;

    char row_len,col_len,loop_break,str_len;
    int down_fl = 0,up_fl=0;
    stop_draw = 0;
    loop_break = 0;

    putchar('!');               //in print function
    while(1)
    {
        pixels=0;
        pix_chunk=0;
        pix_size=0;

        row_len=0,col_len=0;

        row_len = getchar();
        col_len = getchar();
        pix_size = getchar();
        str_len = getchar();

        row_len = (row_len -48) * 10;
        col_len = (col_len -48) * 10;
        pix_size =  (pix_size -48) * 10;    // for 200*200 , pixel is 20; for 20*20, pixel is 10
        str_len =  (str_len -48);

        pixels= row_len*col_len;

        ii=0;

        if(pix_size==20)    //image 400 * 400
        {
            for(pix_chunk=0;pix_chunk<=99;pix_chunk++)
            {
                ii=0;
                while(ii < pixels)
                {
                    circular_buffer[ii]=getchar();
                    putchar('Q');           //ACK
                    ii++;
                }
                for(ii=0;ii<pixels;ii++)
                {
                    if(circular_buffer[ii] == '1')
                    {
                        if(down_fl == 0)
                        {
                            pen_down();
                            down_fl = 1;
                            up_fl = 0;
                        }
                         move_right(25);

                    }
                    else
                    {
                        if(up_fl == 0)
                        {
                            pen_up();
                            up_fl = 1;
                            down_fl = 0;
                        }
                        move_right(25);
                    }
                    if(((ii+1) % row_len)==0)
                    {
                         pen_up();
                        up_fl = 1;
                        down_fl = 0;
                        move_down(25);
                        move_left(25 * row_len);

                    }
                    line_mod(); //stop printing
                    if(stop_draw == 1)
                    {
                        loop_break = 1;
                        break;
                    }
                    menu_scroll();
                    if(menu_action == ENTER)  // break condition - ADD STOP BUTTON ALSO
                    {
                        menu_action = 0;
                        if(cursor_x == 1)               //start option
                        {
                            loop_break =1;
                            break;
                        }
                    }
                }
                if(loop_break == 1)
                    break;
                putchar('S');
                if((pix_chunk+1)%10==0)
                {
                    move_right(22*row_len);
                    move_up(25*10*col_len);
                }
            }
            if(loop_break == 1)
                break;
        }
        else        //letters 20*20
        {
                ii=0;

                while(ii < pixels)
                {
                    circular_buffer[ii]=getchar();
                    putchar('Q');
                    ii++;
                }

                for(ii=0;ii<pixels;ii++)
                {
                    if(circular_buffer[ii] == '1')
                    {
                        if(down_fl == 0)
                        {
                            pen_down();
                            down_fl = 1;
                            up_fl = 0;
                        }
                        move_right(25);
                    }
                    else
                    {
                        if(up_fl == 0)
                        {
                            pen_up();
                            up_fl = 1;
                            down_fl = 0;
                        }
                        move_right(25);
                    }
                    if(((ii+1) % row_len)==0)
                    {
                        pen_up();
                        up_fl = 1;
                        down_fl = 0;
                        move_down(25);
                        move_left(25 * row_len);

                    }
                    line_mod();                 //move to next line - start
                    menu_scroll();
                    if(menu_action == ENTER)  // break condition - ADD STOP BUTTON ALSO
                    {
                        menu_action = 0;
                        if(cursor_x == 1)               //start option
                        {
                            loop_break =1;
                            break;
                        }
                    }
                }
            if(loop_break == 1)
                break;
            move_right(25*row_len);
            move_up(25*col_len);
            putchar('S');   //ack
             if(str_len == 1)
                break;

        }
    }
}

