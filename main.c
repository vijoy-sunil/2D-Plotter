/*
* QWERTY_PEN REV
*
 */


#include "system.h"

unsigned char cursor_x;
unsigned char sw_press,menu_action;
extern int origin_set;
xdata char circular_buffer[BUFFER_SIZE];                    //uart buffer components
xdata unsigned char rd_pntr,wr_pntr;

_sdcc_external_startup()
{
    AUXR |= 0x0C;
                                                            //setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;

    TCON |= INT0_EDGE;                                    //edge triggered
   // IEN0 = GLOBAL_INT | INT0_MASK | SERIAL_MASK;          //enable global and int0 interrrupt
    return 0;
}
unsigned int i,u,d,l,r,ul,ur,dl,dr;

void main()
{
char c;

    circle(2);

    //pen_down();
 //   square_draw(1);
//    triangle_draw(1);
//   system_init();
while(1)
{
    c=getchar();
    if(c=='w'){
        move_up(STEPS_PER_UNIT);
        u++;
        printf("UP- %d\n\r",u);
    }
    else if(c=='x'){
        move_down(STEPS_PER_UNIT);
        d++;
        printf("DOWN- %d\n\r",d);
    }
   else if(c=='a'){
        move_left(STEPS_PER_UNIT);
        l++;
        printf("LEFT- %d\n\r",l);
    }
   else if(c=='d'){
        move_right(STEPS_PER_UNIT);
        r++;
        printf("RIGHT- %d\n\r",r);
    }
   else if(c=='z'){
        move_down_left(1);
        dl++;
        printf("DL- %d\n\r",dl);
    }
   else if(c=='q'){
        move_up_left(1);
        ul++;
        printf("UL- %d\n\r",ul);
    }
   else if(c=='e'){
        move_up_right(1);
        ur++;
        printf("UR- %d\n\r",ur);
    }
   else if(c=='c'){
       move_down_right(1);
       dr++;
       printf("DR- %d\n\r",dr);
    }
}

/*
    while(1)                //menu loop
    {
        lcd_screen_1();     //qwerty pen
        delay_sec(1);
        lcd_screen_2();     //menu - origin/quick/custom

        cursor_display(1);   //cursor display - initial location
        delay_ms(1);

        if(wr_pntr!=rd_pntr)
        {
            putchar(circular_buffer[rd_pntr]);  //read value from buffer
            rd_pntr=((rd_pntr+1)%BUFFER_SIZE);  //increment read pointer
        }
        while(1)
        {
            menu_scroll();
            if(menu_action == ENTER)            //enter option
            {
                menu_action = 0;
                if(cursor_x == 0)               //origin set
                    origin_menu_1_1();
                if(cursor_x == 1)               //quick print
                    quick_menu_1_2();
                if(cursor_x == 2)               //custom print
                    custom_menu_1_3();
            }
        }
    }
*/
}

void ex0_isr(void) __interrupt 0         //isr for external interrupt
{
    IEN0 &=~(GLOBAL_INT | INT0_MASK);   //disable int0 and global  interrupt
    sw_press = EXPANDER_ReadByte();     //read expander

    sw_press = sw_press & SW_MASK;
    if(sw_press != 0xFF)                //identify switch and set flag
    {
        if(sw_press == (LEFT & RIGHT))
        {
            menu_action = VALUE_SET;
        }
        else if(sw_press == LEFT)
        {
            menu_action = BACK;
        }
        else if(sw_press == RIGHT)
        {
            menu_action = ENTER;
        }
        else if(sw_press == UP)
        {
            menu_action = SCROLL_UP;
        }
        else if(sw_press == DOWN)
        {
            menu_action = SCROLL_DOWN;
        }
    }
    sw_press=0;
    IEN0 |=(GLOBAL_INT | INT0_MASK);    //enable int0 and global interrupt
}

void serial_interrupt(void)__interrupt 4    //Subroutine for SERIAL ISR Interrupt
{
    if(RI==1)
    {
        while (!RI);
        RI=0;
        circular_buffer[wr_pntr]=SBUF;
        wr_pntr=((wr_pntr+1)%BUFFER_SIZE);
    }
}
