
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
uint8_t read_ddram_address(void)
{
    uint8_t dd_add;
    RS = 0;
    RW = 1;
    dd_add = *LCD_PTR;
    return dd_add;
}

void line_mod(void)
{
    uint8_t d_temp;
    d_temp = read_ddram_address();
    if(d_temp == 143)
        Lcd_gotoxy(1,0);
    else if(d_temp == 207)
        Lcd_gotoxy(2,0);
    else if(d_temp == 159)
        Lcd_gotoxy(3,0);
    else if(d_temp == 223)
    {
        Lcd8_Clear();
        Lcd_gotoxy(0,0);
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
    *LCD_PTR = a;
}
void Lcd8_Cmd(char a)
{
  RS = 0;             // => RS = 0
  RW = 0;

  Lcd8_Port(a);             //Data transfer
  //EN  = 1;             // => E = 1
  Lcd_Busywait();
  //EN  = 0;             // => E = 0
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
             // => E = 1
   Lcd_Busywait();
   line_mod();
            // => E = 0
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
void show_lcd(int eeprom_Address,unsigned char row,unsigned char eeprom_Data)
{
    uint8_t temp[10];
    mod_itoa(temp,eeprom_Address);
    Lcd_gotoxy(row,0);

    Lcd8_Write_String(temp);
    Lcd8_Write_Char(':');

    mod_itoa(temp,eeprom_Data);
    Lcd8_Write_String(temp);
}

void dump_dd(void)      //ddram dump memory
{
    int i;
    uint8_t dd_add;

    Lcd8_Cmd(0x80);
    dd_add = read_ddram_address();

    printf("%x :\t",dd_add);

    for(i=1;i<81;i++)
    {
        RS = 1;
        RW = 1;
        printf("%x\t",*LCD_PTR);
        if((i % 16 ==0) && (i !=80))
        {
            printf("\r\n");
            dd_add = read_ddram_address();
            printf("%x :\t",dd_add);
        }
    }

    RS=0;
    RW=0;
}

void dump_cg(void)      //cgram dump memory
{
    int i;
    uint8_t dd_add;

    Lcd8_Cmd(0x40);
    dd_add = read_ddram_address();

    printf("%x :\t",dd_add);

    for(i=1;i<65;i++)
    {
        RS = 1;
        RW = 1;
        printf("%x\t",*LCD_PTR);
        if((i % 16 ==0) && (i !=64))
        {
            printf("\r\n");
            dd_add = read_ddram_address();
            printf("%x :\t",dd_add);
        }
    }

    RS=0;
    RW=0;
}

void lcdcreatechar(unsigned char ccode,unsigned char rows[])
{
    char cg_add=0;
    char pixel_row;

    ccode=ccode*8;
    cg_add = 64 + ccode;


    for(pixel_row=0;pixel_row<8;pixel_row++)
    {
        Lcd8_Cmd(0x40);
        *LCD_PTR = cg_add;          //set cgram address

        Lcd_Delay(5);

        RS=1;
        RW=0;
        *LCD_PTR = rows[pixel_row]; //write to cgram
        Lcd_Delay(5);

        cg_add++;
    }
}


void lcd_number(int number,char digits)  //to display as a number on lcd
{
    int data_val;
    if(digits==0){
        data_val=number/10;
        Lcd8_Write_Char(data_val+48);
        data_val=number%10;
        Lcd8_Write_Char(data_val+48);
        }
    else
        Lcd8_Write_Char(number+48);
}

void lcd_screen_1(void)         //QWERTY PEN
{
    unsigned char main_logo0[8] = {0x00,0x01,0x03,0x06,0x0C,0x18,0x10,0x10};
    unsigned char main_logo1[8] = {0x00,0x10,0x18,0x0C,0x06,0x03,0x01,0x01};
    unsigned char main_logo2[8] = {0x01,0x01,0x1B,0x1E,0x0C,0x1E,0x17,0x03};
    unsigned char main_logo3[8] = {0x10,0x10,0x18,0x0C,0x06,0x03,0x01,0x00};

    lcdcreatechar(0,main_logo0);
    lcdcreatechar(1,main_logo1);
    lcdcreatechar(2,main_logo2);
    lcdcreatechar(3,main_logo3);

    Lcd_gotoxy(1,3);

    RS=1;
    RW=0;
    *LCD_PTR = 0;           //write to ddram

    Lcd_Delay(5);

    Lcd_gotoxy(1,4);

    RS=1;
    RW=0;
    *LCD_PTR = 1;           //write to ddram
    Lcd_Delay(5);

    Lcd_gotoxy(2,4);

    RS=1;
    RW=0;
    *LCD_PTR = 2;           //write to ddram
    Lcd_Delay(5);

    Lcd_gotoxy(2,3);

    RS=1;
    RW=0;
    *LCD_PTR = 3;           //write to ddram
    Lcd_Delay(5);

    Lcd_gotoxy(1,5);
    Lcd8_Write_String("WERTY PEN");
    Lcd_Delay(5);
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
    Lcd8_Write_String("1x1 SQUARE");
    Lcd_gotoxy(2,1);
    Lcd8_Write_String("1x1 TRIANGLE");
    Lcd_gotoxy(3,1);
    Lcd8_Write_String("1x1 CIRCLE");
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

void lcd_screen_2_3_2_1(void)
{
    Lcd8_Clear();
    Lcd_gotoxy(3,5);
    Lcd8_Write_String("Printing...");
}

void cursor_display(char x)           //display cursor- custom char - stored at character code 0
{
    unsigned char cursor_logo[8] = {0x18,0x14,0x0A,0x05,0x05,0x0A,0x14,0x18};
    lcdcreatechar(7,cursor_logo);

    Lcd_gotoxy(x,0);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    *LCD_PTR = 7;           //write to ddram
}

void menu_scroll(void)
{
    if(menu_action == SCROLL_DOWN)
    {
        Lcd_gotoxy(1 + cursor_x,0);                //clear cursor on next line
        Lcd8_Write_Char(' ');
        cursor_x++;
        cursor_display(1 + cursor_x);    //display cursor
        menu_action=0;
    }
    else if(menu_action == SCROLL_UP)
    {
        Lcd_gotoxy(1 + cursor_x,0);                //clear cursor on prev line
        Lcd8_Write_Char(' ');
        cursor_x--;
        cursor_display(1 + cursor_x);   //display cursor
        menu_action=0;
    }
}
