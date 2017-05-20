#ifndef EXPANDER_H_INCLUDED
#define EXPANDER_H_INCLUDED

#define EXPANDER_ID_W 0x70
#define EXPANDER_ID_R 0x71
#define EXP_INPUT     0x0F

//switches
#define LEFT 0xFB   //connencted to P2
#define RIGHT 0xF7  //connected to P3
#define UP 0xFD     //connected to P1
#define DOWN 0xFE   //connected to P0

//menu actions
#define BACK 0x0B
#define ENTER 0x0E
#define SCROLL_UP 0x0A
#define SCROLL_DOWN 0x0F
#define ORIGIN_SET 0x0D

void EXPANDER_WriteByte(unsigned char expander_Data);
unsigned char EXPANDER_ReadByte(void);


#endif // EXPANDER_H_INCLUDED
