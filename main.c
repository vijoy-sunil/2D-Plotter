/*
* QWERTY_PEN REV
*
 */


#include "system.h"

unsigned char cursor_x;
unsigned char sw_press,menu_action;
char circular_buffer[BUFFER_SIZE];
unsigned int i,u,d,l,r,ul,ur,dl,dr;

_sdcc_external_startup()
{
    AUXR |= 0x0C;
                                                            //setting baud to 9600
    TMOD=0X20;
    TH1=-3;
    SCON=0X50;
    TR1=1;

//    AUXR |= 0x0C;
//    PCON=0x080;
//    SCON|=0x050;
//    BDRCON|=0x002;
//    RCAP2H=0x0FF;
//    RCAP2L=0x0FD;
//    T2CON|=0x034;

    TCON |= INT0_EDGE;                                    //edge triggered
    IEN0 = GLOBAL_INT | INT0_MASK;// | SERIAL_MASK;          //enable global and int0 interrrupt
    return 0;
}


void main()
{
    int ii;
    char c;
    char row_len,col_len;
    int pixels,pix_chunk,pix_size;

    system_init();

    while(1)
    {

        c=getchar();


        line_mod();
        if(c=='w'){
            move_up(STEPS_PER_UNIT);
            u++;
//            printf("UP- %d\n\r",u);
        }
        else if(c=='x'){
            move_down(STEPS_PER_UNIT);
            d++;
//            printf("DOWN- %d\n\r",d);
        }
       else if(c=='a'){
            move_left(STEPS_PER_UNIT);
            l++;
//            printf("LEFT- %d\n\r",l);
        }
       else if(c=='d'){
            move_right(STEPS_PER_UNIT);
            r++;
//            printf("RIGHT- %d\n\r",r);
        }
       else if(c=='z'){
            move_down_left(1);
            dl++;
//            printf("DL- %d\n\r",dl);
        }
       else if(c=='q'){
            move_up_left(1);
            ul++;
//            printf("UL- %d\n\r",ul);
        }
       else if(c=='e'){
            move_up_right(1);
            ur++;
//    printf("UR- %d\n\r",ur);
        }
       else if(c=='c'){
           move_down_right(1);
           dr++;
//           printf("DR- %d\n\r",dr);
        }
       else if(c=='u'){
            pen_up();
//           printf("DR- %d\n\r",dr);
        }
       else if(c=='j'){
            pen_down();
//           printf("DR- %d\n\r",dr);
        }
        else if(c=='?')
        {
            break;
        }
//        putchar('A');
//        printf("ABC");
    }
//
    ii=0;

    row_len = getchar();   //1 = 10*10, 2= 20*20, 3= 30*30
    col_len = getchar();
    pix_size = getchar();

    row_len = (row_len -48) * 10;
    col_len = (col_len -48) * 10;
    pix_size =  (pix_size -48) * 10;    // for 200*200 , pixel is 20; for 20*20, pixel is 10

    pixels= row_len*col_len;

if(pix_size==20)
{
    for(pix_chunk=0;pix_chunk<99;pix_chunk++)
    {
        ii=0;
        while(ii < pixels)
        {
    //        printf("%d\n\r",ii);
            circular_buffer[ii]=getchar();
            putchar('Q');           //ACK
            ii++;
        }
       // printf("\n\r%d ",ii);
        for(ii=0;ii<pixels;ii++)
        {
    //        printf("\n\rNEW %d ",ii);
           // putchar(circular_buffer[ii]);
            if(circular_buffer[ii] == '1')
            {
                pen_down();
                move_right(25); //125
                pen_up();
            }
            else
            {
               move_right(25);
            }
            if(((ii+1) % row_len)==0)
            {
    //            printf("DOWN\n\r");
                 move_down(25);
                 move_left(25 * row_len);

            }
        }
//        BT_RESET = 0;
//        BT_RESET = 1;
//        delay_ms(3000);
        putchar('S');
        if((pix_chunk+1)%10==0){
            move_right(25*row_len);
            move_up(25*10*col_len);
    //            move_up(25*col_len);
        }
    }
}
else
{
        ii=0;
        while(ii < pixels)
        {

            circular_buffer[ii]=getchar();
            putchar('Q');
            ii++;
        }
       // printf("\n\r%d ",ii);
        for(ii=0;ii<pixels;ii++)
        {
    //        printf("\n\rNEW %d ",ii);
           // putchar(circular_buffer[ii]);
            if(circular_buffer[ii] == '1')
            {
                pen_down();
                move_right(25); //125
            }
            else
            {
                pen_up();
               move_right(25);
            }
            if(((ii+1) % row_len)==0)
            {
    //            printf("DOWN\n\r");
                pen_up();
                 move_down(25);
                 move_left(25 * row_len);

            }
        }
     BT_RESET = 0;
     BT_RESET = 1;
    move_right(25*row_len);
    move_up(25*col_len);
}
//    while(1)                //menu loop
//    {
//        lcd_screen_1();     //qwerty pen
//        delay_sec(1);
//        lcd_screen_2();     //menu - origin/quick/custom
//
//        cursor_display(1);   //cursor display - initial location
//        delay_ms(1);
//
//        while(1)
//        {
//            menu_scroll();
//            if(menu_action == ENTER)            //enter option
//            {
//                menu_action = 0;
//                if(cursor_x == 0)               //origin set
//                    origin_menu_1_1();
//                if(cursor_x == 1)               //quick print
//                    quick_menu_1_2();
//                if(cursor_x == 2)               //custom print
//                    custom_menu_1_3();
//            }
//        }
//    }
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

//void serial_interrupt(void)__interrupt 4    //Subroutine for SERIAL ISR Interrupt
//{
//    if(RI==1)
//    {
//        while (!RI);
//        RI=0;
//        circular_buffer[wr_pntr]=SBUF;
//        wr_pntr=((wr_pntr+1)%BUFFER_SIZE);
//    }
//}
