
#include "MPU_6050.h"
#include "i2c.h"
#include "stm32f4xx.h"                  // Device header
#include "math.h"
///////////
//=====================================
//*** variables
char ACCEL_XANGLE, ACCEL_YANGLE, ACCEL_ZANGLE;
int ACCEL_XOUT, ACCEL_YOUT, ACCEL_ZOUT;
int GYRO_XOUT_OFFSET, GYRO_YOUT_OFFSET, GYRO_ZOUT_OFFSET;
int GYRO_XOUT, GYRO_YOUT, GYRO_ZOUT;
int GYRO_XRATE, GYRO_YRATE, GYRO_ZRATE;
int GYRO_XANGLE, GYRO_YANGLE, GYRO_ZANGLE;
float dt;
//=====================================
void Mpu6050_Init(void)
   {
   Mpu6050_Write(0x6B, 0x00);  // internal 8MHz, disabled SLEEP mode, disable CYCLE mode  
   Mpu6050_Write(0x19, 0x07);	 //sample rate: 8khz
   Mpu6050_Write(0x1A, 0x06);		 //DLPF disable
   Mpu6050_Write(0x1B, 0x18);  //full scale range mode 3 +-2000do/s
   Mpu6050_Write(0x1C, 0x01); //full scale range mode 1 +-4g
   }
//////////
void Mpu6050_Write(unsigned char add,unsigned char Data)
   {
   I2C_start(I2C1, MPU_6050_add<<1, I2C_Direction_Transmitter);
   I2C_write(I2C1, add);
	 I2C_write(I2C1, Data);
   I2C_stop(I2C1); // stop the transmission
   }

/////
int GetData(unsigned char add)
{
   int H,L;
   H=Mpu6050_Read(add);
   L=Mpu6050_Read(add+1);
   return (H<<8)+L;   
}

//////////////////////////////////////
unsigned char Mpu6050_Read (unsigned char add)
   {
   unsigned char Data;
   I2C_start(I2C1, MPU_6050_add<<1, I2C_Direction_Transmitter);
   I2C_write(I2C1, add);
   I2C_stop(I2C1);
   I2C_start(I2C1, MPU_6050_add<<1, I2C_Direction_Receiver);

   Data = I2C_read_nack(I2C1); // read one byte and don't request another byte, stop transmission
   return Data;
   }

//////////////////
void Get_Accel_Angles(void)
{
	ACCEL_XANGLE = 57.295*atan((float)ACCEL_YOUT/ sqrt(pow((float)ACCEL_ZOUT,2)+pow((float)ACCEL_XOUT,2)));
	ACCEL_YANGLE = 57.295*atan((float)-ACCEL_XOUT/ sqrt(pow((float)ACCEL_ZOUT,2)+pow((float)ACCEL_YOUT,2)));
	ACCEL_ZANGLE = 57.295*atan(sqrt(pow((float)ACCEL_ZOUT,2)+pow((float)ACCEL_XOUT,2))/(float)ACCEL_YOUT);	
}	
 
/////////////////////
void Get_Accel_Values(void)
{
	ACCEL_XOUT = GetData(0x3B);
	ACCEL_YOUT = GetData(0x3D);
	ACCEL_ZOUT = GetData(0x3F);		
}