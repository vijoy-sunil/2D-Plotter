#include "system.h"

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
    Lcd_Busywait();
    RS=1;
    RW=0;
    //*LCD_PTR = 0;           //write to ddram

    Lcd8_Port(0);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(1,4);
    Lcd_Busywait();
    RS=1;
    RW=0;
    //*LCD_PTR = 1;           //write to ddram

    Lcd8_Port(1);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(2,4);
    Lcd_Busywait();
    RS=1;
    RW=0;
    //*LCD_PTR = 2;           //write to ddram

    Lcd8_Port(2);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(2,3);
    Lcd_Busywait();
    RS=1;
    RW=0;
    //*LCD_PTR = 3;           //write to ddram

    Lcd8_Port(3);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(1,5);
    Lcd_Busywait();
    Lcd8_Write_String("WERTY PEN");
    Lcd_Delay(5);
}

void cursor_display(char x)           //display cursor- custom char - stored at character code 0
{
    unsigned char cursor_logo[8] = {0x18,0x14,0x0A,0x05,0x05,0x0A,0x14,0x18};
    lcdcreatechar(7,cursor_logo);

    Lcd_gotoxy(x,0);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 7;           //write to ddram
    Lcd8_Port(7);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0
}

void hour_glass(char x,char y)           //display logo while printing
{
    unsigned char glass_logo[8] = {0xFF,0x11,0x0A,0x04,0x04,0x0A,0x11,0xFF};
    lcdcreatechar(6,glass_logo);

    Lcd_gotoxy(x,y);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 6;               //write to ddram
    Lcd8_Port(6);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0
}

void stop_logo(char x,char y)           //display logo while printing
{
    unsigned char glass_logo[8] = {0x0E,0x0E,0x0E,0x0E,0x0E,0x04,0x00,0x04};
    lcdcreatechar(5,glass_logo);

    Lcd_gotoxy(x,y);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 5;               //write to ddram
    Lcd8_Port(5);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0
}

void origin_menu_x(char x1,char y1,char x2,char y2)
{
    unsigned char origin_left[8] = {0x00,0x02,0x04,0x08,0x04,0x02,0x00,0x00};
    unsigned char origin_right[8] = {0x00,0x08,0x04,0x02,0x04,0x08,0x00,0x00};

    lcdcreatechar(4,origin_left);
    lcdcreatechar(3,origin_right);

    Lcd_gotoxy(x1,y1);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 4;               //write to ddram
    Lcd8_Port(4);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(x2,y2);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 3;               //write to ddram
    Lcd8_Port(3);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0
}

void origin_menu_y(char x1,char y1,char x2,char y2)
{
    unsigned char origin_up[8] = {0x00,0x00,0x00,0x00,0x04,0x0A,0x11,0x00};
    unsigned char origin_down[8] = {0x00,0x11,0x0A,0x04,0x00,0x00,0x00,0x00};

    lcdcreatechar(2,origin_up);
    lcdcreatechar(1,origin_down);

    Lcd_gotoxy(x1,y1);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 2;               //write to ddram
    Lcd8_Port(2);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0

    Lcd_gotoxy(x2,y2);
    Lcd_Delay(5);
    RS=1;
    RW=0;
    //*LCD_PTR = 1;               //write to ddram
    Lcd8_Port(1);
    LCD_EN  = 1;             // => E = 1
    Lcd_Busywait();
    LCD_EN  = 0;             // => E = 0
}
