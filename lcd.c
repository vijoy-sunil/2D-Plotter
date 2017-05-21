
#include "system.h"
extern unsigned char cursor_x;
extern unsigned char menu_action;
void Lcd_Delay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}

void Lcd_Busywait(void)
{
//    RW = 1;
//    while(*LCD_PTR & BUSY_MASK);
//    RW = 0;
    Lcd_Delay(5);
}

void Lcd8_Port(char a)
{
    P0 = a;
}
void Lcd8_Cmd(char a)
{
  RS = 0;             // => RS = 0
  RW = 0;

  Lcd8_Port(a);             //Data transfer
  LCD_EN  = 1;             // => E = 1
  Lcd_Busywait();
  LCD_EN  = 0;             // => E = 0
}

void Lcd8_Clear(void)
{
	  Lcd8_Cmd(1);
}
void Lcd_gotoaddr(char a)
{
    Lcd_Busywait();
    Lcd8_Cmd(0x80 + a);     //setting d7 to 1
}

void Lcd_gotoxy(char x, char y)
{
    if(y<16)
    {
        if(x == 0)
            Lcd_gotoaddr(y);
        else if(x == 1)
            Lcd_gotoaddr(0x40 + y);
        else if(x == 2)
            Lcd_gotoaddr(0x10 + y);
        else
            Lcd_gotoaddr(0x50 + y);
    }
}

void Lcd8_Init(void)
{
	Lcd8_Port(0x00);
	RS = 0;
	Lcd_Delay(200);
	///////////// Reset process from datasheet /////////
    Lcd8_Cmd(0x30);
	Lcd_Delay(50);
    Lcd8_Cmd(0x30);
	Lcd_Delay(110);
    Lcd8_Cmd(0x30);
  /////////////////////////////////////////////////////
    Lcd8_Cmd(0x38);    //function set
    Lcd8_Cmd(0x0C);    //display on,cursor off,blink off
    Lcd8_Cmd(0x01);    //clear display
    Lcd8_Cmd(0x06);    //entry mode, set increment
}

void Lcd8_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   RW = 0;

   Lcd8_Port(a);             //Data transfer
   LCD_EN=1;          // => E = 1
   Lcd_Busywait();
   LCD_EN=0;        // => E = 0
}

void Lcd8_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd8_Write_Char(a[i]);
}

uint8_t *mod_itoa(uint8_t * str, uint32_t dat)
{
    uint16_t count=0;
    uint32_t length_count=0;
    uint16_t i;
    uint8_t temp,base = 16;

    //Condition for input 0
    if(dat == 0)
    {
        *str = '0';
        str++;
        *str = '\0';
        return str;
    }

    //Converting integer to  reverse ascii string
    while(dat!=0)
    {
        uint16_t rem = dat % base;

        if (rem>9)                              //digits greater than 9
        {
	     *str= (rem-10)+'A';
	     str++;
        }
        else                                    //digits less than 9
        {
	     *str= rem+'0';
	     str++;
        }
        dat = dat/base;
        length_count++;                         //count increment
    }

    *str='\0';
     str--;

    //Reversing the calculated ascii string to get correct ascii string

    for(i=0;i<length_count/2;i++)
    {
	temp=*(str-i);
	*(str-i)=*(str+1+i-length_count);
	*(str+1+i-length_count)=temp;
    }

   return str;
}



void lcdcreatechar(unsigned char ccode,unsigned char rows[])
{
    char cg_add=0;
    char pixel_row;

    ccode=ccode*8;
    cg_add = 64 + ccode;


    for(pixel_row=0;pixel_row<8;pixel_row++)
    {
        Lcd8_Cmd(0x40 | cg_add);

        Lcd_Busywait();
        //*LCD_PTR = cg_add;          //set cgram address
        //Lcd_Delay(5);


        RS=1;
        RW=0;
        //*LCD_PTR = rows[pixel_row]; //write to cgram

        Lcd8_Port(rows[pixel_row]);
        LCD_EN  = 1;             // => E = 1
        Lcd_Busywait();
        LCD_EN  = 0;             // => E = 0

        cg_add++;
    }
}


void lcd_screen_2(void)         //MENU items
{
    Lcd8_Clear();
    Lcd_gotoxy(0,6);
    Lcd8_Write_String("MENU");
    Lcd_gotoxy(1,1);
    Lcd8_Write_String("ORIGIN set");
    Lcd_gotoxy(2,1);                    //space for cursor
    Lcd8_Write_String("Quick Print");   //origin - quick shapes
    Lcd_gotoxy(3,1);
    Lcd8_Write_String("Custom Print");  //origin -  ply/pause/stop
}

void lcd_screen_2_1(void)               //origin set menu
{
    Lcd8_Clear();
    Lcd_gotoxy(0,5);
    Lcd8_Write_String("ORIGIN");

}
void lcd_screen_2_2(void)               //quick print
{
    Lcd8_Clear();
    Lcd_gotoxy(0,5);
    Lcd8_Write_String("QUICK");
    Lcd_gotoxy(1,1);
    Lcd8_Write_String("5x5 SQUARE");
    Lcd_gotoxy(2,1);
    Lcd8_Write_String("5x5 TRIANGLE");
    Lcd_gotoxy(3,1);
    Lcd8_Write_String("5x5 CIRCLE");
}

void lcd_screen_2_3(void)               //custom print on switch press
{
   Lcd8_Clear();
   Lcd_gotoxy(0,2);
   Lcd8_Write_String("Custom Print");
   Lcd_gotoxy(1,1);
   Lcd8_Write_String("STYLE options");  //font size/bold
   Lcd_gotoxy(2,1);
   Lcd8_Write_String("PRINT options");  //start-stop-pause
}

void lcd_screen_2_3_1(void)
{
    Lcd8_Clear();
    Lcd_gotoxy(0,5);
    Lcd8_Write_String("STYLE");
    Lcd_gotoxy(1,1);
    Lcd8_Write_String("FONT size");   // increment on press
    Lcd_gotoxy(2,1);
    Lcd8_Write_String("FONT style");  //BOLD / LIGHT
}

void lcd_screen_2_3_2(void)
{
    Lcd8_Clear();
    Lcd_gotoxy(0,5);
    Lcd8_Write_String("PRINT");
    Lcd_gotoxy(1,1);
    Lcd8_Write_String("START");
    Lcd_gotoxy(2,1);
    Lcd8_Write_String("STOP");
}


void menu_scroll(void)
{
    if(menu_action == SCROLL_DOWN)
    {
        menu_action=0;
        Lcd_gotoxy(1 + cursor_x,0);                //clear cursor on next line
        Lcd8_Write_Char(' ');
        cursor_x++;
        if(cursor_x > 2)
            cursor_x =2;

        cursor_display(1 + cursor_x);    //display cursor
    }
    else if(menu_action == SCROLL_UP)
    {
        menu_action=0;
        Lcd_gotoxy(1 + cursor_x,0);                //clear cursor on prev line
        Lcd8_Write_Char(' ');
        cursor_x--;
        if(cursor_x >2)
            cursor_x = 0;

        cursor_display(1 + cursor_x);   //display cursor
    }
}


