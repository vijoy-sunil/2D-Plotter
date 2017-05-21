#ifndef I2C_H_INCLUDED
#define I2C_H_INCLUDED

#define SDA P1_3
#define SCL P1_2

void I2C_Init(void);
void I2C_Clock(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(unsigned char );
unsigned char I2C_Read(void);
void I2C_Ack(void);
void I2C_NoAck(void);


#endif // I2C_H_INCLUDED
