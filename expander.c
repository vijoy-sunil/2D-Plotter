//THIS MODULE CONTAINS THE CODE FOR I/O EXPANDER WHICH ARE USED TO CONTROL THE 4 LCD CONTROL BUTTONS ON BOARD
//AUTHOR(S): VIJOY SUNIL KUMAR, PRAVEEN GNANASEKARAN
#include "system.h"

void EXPANDER_WriteByte(unsigned char expander_Data)
{

    I2C_Start();               // Start i2c communication
   	I2C_Write(EXPANDER_ID_W);	   // connect to AT2404 by sending its ID on I2c Bus
	I2C_Ack();

   	I2C_Write(expander_Data);    // Write the data at specified address
	I2C_Ack();

    I2C_Stop();           	   // Stop i2c communication after Writing the data
	delay_ms(5);               // Write operation takes max 5ms, refer At2404 datasheet
}


unsigned char EXPANDER_ReadByte(void)
{
  unsigned char expander_Data;

    I2C_Start();               // Start i2c communication
   	I2C_Write(EXPANDER_ID_R);
	I2C_Ack();

	expander_Data = I2C_Read();      // Read the data from specified address
	//I2C_NoAck();
    I2C_Stop();		                 // Stop i2c communication after Reading the data
    I2C_NoAck();
	delay_ms(5);

  return expander_Data;              // Return the Read data
}
