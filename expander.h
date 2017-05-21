#ifndef EXPANDER_H_INCLUDED
#define EXPANDER_H_INCLUDED

#define EXPANDER_ID_W 0x70
#define EXPANDER_ID_R 0x71
#define EXP_INPUT     0x0F

//switches
#define LEFT 0x0B   //connencted to P2
#define RIGHT 0x07  //connected to P3
#define UP 0x0D     //connected to P1
#define DOWN 0x0E   //connected to P0

//menu actions
#define BACK 0x0B
#define ENTER 0x0E
#define SCROLL_UP 0x0A
#define SCROLL_DOWN 0x0F
#define VALUE_SET 0x0D

#define SW_MASK 0x0F

void EXPANDER_WriteByte(unsigned char expander_Data);
unsigned char EXPANDER_ReadByte(void);


#endif // EXPANDER_H_INCLUDED
