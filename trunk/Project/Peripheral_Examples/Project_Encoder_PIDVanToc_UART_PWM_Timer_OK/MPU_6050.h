
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MPU_6050_H
#define __MPU_6050_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_i2c.h"

//*** define
#define MPU_6050_add  0x68

//*** void()
void Mpu6050_Write(unsigned char add,unsigned char Data);
void Mpu6050_Init(void);
void Get_Accel_Angles(void);
void Get_Accel_Values(void);
void Get_Gyro_Rates(void);
void Get_GYRO_RATE(void);
//*** function()
int32_t Mpu6050_Read (unsigned char add);
int GetData(unsigned char add);
/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM324xG_EVAL_H */
