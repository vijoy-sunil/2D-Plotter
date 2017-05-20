#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

#include "stdint.h"
//LCD Functions Developed by electroSome

//LCD Module Connections
#define RS P1_6
#define RW P1_7
#define BUSY_MASK 0x80

#define FIRST_LINE      0x10
#define SECOND_LINE     0x50
#define THIRD_LINE      0x20
#define FORTH_LINE      0x60

#define LCD_PTR ((xdata unsigned char *)0x9000)
//End LCD Module Connections
void Lcd_Delay(int a);
void Lcd_Busywait(void);
void Lcd8_Port(char a);
void Lcd8_Cmd(char a);
void Lcd8_Clear(void);
void Lcd_gotoaddr(char a);
void Lcd_gotoxy(char x, char y);
void Lcd8_Init(void);
void Lcd8_Write_Char(char a);
void Lcd8_Write_String(char *a);


void dump_dd(void);
void dump_cg(void);

uint8_t *mod_itoa(uint8_t * str, uint32_t data);
uint8_t read_ddram_address(void);
void line_mod(void);
void show_lcd(int eeprom_Address,unsigned char row,unsigned char eeprom_Data);
void lcdcreatechar(unsigned char ccode,unsigned char rows[]);
void lcd_number(int number,char digits);

void lcd_screen_1(void);
void lcd_screen_2(void);
void lcd_screen_2_1(void);
void lcd_screen_2_2(void);
void lcd_screen_2_3(void);
void lcd_screen_2_3_1(void);
void lcd_screen_2_3_2(void);
#endif // LCD_H_INCLUDED
