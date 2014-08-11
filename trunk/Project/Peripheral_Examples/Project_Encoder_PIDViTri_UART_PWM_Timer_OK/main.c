/**
  ******************************************************************************
  * @file    EXTI/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  Cau truc chuong trinh gom co:
		- 1 UART:
			RX : -------------------- PA3
			TX : -------------------- PA2
		- 2 encoder interface: Timer 
			ENCL : ------------------ PA15 va PB3  --- Timer 2
			ENCR : ------------------ PA6 va PA7   --- Timer 3
		- 2 PWM channle Timer 1
			Channel 1 : -------------	PE9 ---- Left
			Channel 2 : ------------- PE11 --- Right
		- 1 I2C communication:
			SCL : -------------------	PB6
			SDA : ------------------- PB7
		- SysTick : De canh thoi gian lay mau
		- Khoi tao 4 LED de quy dinh chieu dong co
			LED4 -------------------- PD12 --- Right
			LED3 -------------------- PD13 --- Left
			LED5 -------------------- PD14
			LED6 -------------------- PD15
		- Khoi tao 1 button de chon MODE
			Button ------------------ PA0 ---- EXIT Line 0
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "uart_to_printf.h"
#include "stm32f4_discovery.h"
#include "EXIT_Config.h"
#include "GPIO_Config.h"
#include "Control_PWM.h"
#include "main.h"
#include "i2c.h"
#include "MPU_6050.h"
#include "Encoder_Interface.h"
#include <stdio.h>

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup EXTI
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define Read_ECNL() TIM_GetCounter (ENCL_TIMER)
#define Read_ECNR() TIM_GetCounter (ENCR_TIMER)
#define Tien_R() 		STM_EVAL_LEDOff(LED3)
#define Tien_L() 		STM_EVAL_LEDOff(LED4)
#define Lui_R() 		STM_EVAL_LEDOn(LED3)
#define Lui_L() 		STM_EVAL_LEDOn(LED4)
#define L	1
#define R	0
/* Private typedef -----------------------------------------------------------*/
__IO int32_t Err=0;
__IO int32_t Old_Err=0;
float Kp=18; //10
float Kd=1;
float Ki=40;//20
float pPart=0;
float dPart=0;
float iPart=0;
__IO int32_t Out_Put=0;
__IO int32_t PWM=0;
__IO int32_t Sampling_Time=100;				//ms
__IO int32_t Inv_Sampling_Time=10;		// 	1/ms
__IO int32_t a= 0,c=0,i=0;
__IO int32_t Set_Point =3000;
__IO int32_t Process_Value=0;
__IO int32_t Pre_Err=0;
int32_t dP=0;
int32_t k1;
int32_t k2;
int32_t k3;
int32_t k4;

/* Private macro -------------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
	uint16_t  Resolution = 400;
	uint16_t Sample_time = 100;  // so lan lay mau trong 1s
	uint16_t TimeDelay ;
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
//
void Set_PWM(int hand, int32_t PWM)
{
	// Left
	if(hand==1)
	{
		if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12))
			TIM_SetCompare1(TIM1, 1400-PWM) ;
		else
			TIM_SetCompare1(TIM1, PWM) ;
	}
	// Right
	else
	{
		if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_13))
			TIM_SetCompare2(TIM1, 1400-PWM) ;
		else
			TIM_SetCompare2(TIM1, PWM) ;
	}
}
//
void Motor_Speed_PID(__IO uint32_t Set_Point)
{
	a++;
	Process_Value = Read_ECNL();
	// tinh sai so
	Err= Set_Point - Process_Value;				
//	if(a==20)
//	{
//		//a=0;
//		printf("count = %d   :\n",Process_Value);
//		printf("Err = %d   :\n",Err);
//	}
//********* khau PID*****************//

	pPart=Kp*Err;
	dPart = Kd*(Err-Old_Err)*Sample_time;
	iPart+=Ki*Err*Sample_time/1000;
	if(iPart>1400)
		iPart=1400;
	if(iPart<-1400)
		iPart=-1400;
	Out_Put=(int32_t)(pPart + dPart + iPart);

//***********************************//
if(Out_Put>=0)
{
	if(Out_Put>1400)
		Out_Put=1400;
	Lui_R();
	Lui_L();
}
else
{
	if(Out_Put<-1400)
		Out_Put=-1400;
	Tien_R();
	Tien_L();
}
// gan duty cycle cho thanh ghi CCR2(update PWM)
	PWM = abs(Out_Put);
	Set_PWM(L, PWM);
	Set_PWM(R, PWM);
	 //printf("out = %d   :\n",Out_Put);
	if(a==25)
	{
		a=0;
		//printf("Count = %d: Ki = %f	: Kp= %f	Kd= %f	Err= %d	Out= %d\n",Process_Value,iPart,pPart,dPart,Err,Out_Put);
		printf("%d: %d\n",Process_Value,Out_Put);
		//putc((char)(Process_Value));
		//printf("Out = %d   :\n",Out_Put);
	}
// luu lai gia tri sai so
Old_Err=Err;	
//TIM_SetCounter (ENCL_TIMER, 0);
//TIM_SetCounter (ENCR_TIMER, 0);
}

void Init_System(void)
{
/*Buoc 1: Init UART*/
		UART_Configuration();
		printf("USART %i\n",2);
		puts("Nguyen Thinh\n");
/*Buoc 2: Init nut nhan*/	
		STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI); // nut nhan chon mode
		puts("Nut nhan\n");
/*Buoc 3: Init LED, chieu dong co*/  
		STM_EVAL_LEDInit(LED3); // chieu dong co
		STM_EVAL_LEDInit(LED4); //
		STM_EVAL_LEDInit(LED5); //
		STM_EVAL_LEDInit(LED6); //
		puts("LED\n");

/*Buoc 4: Init I2C*/
		init_I2C1();
		puts("I2C\n");
/*Buoc 5: Init MPU6050 */
		Mpu6050_Init();
		puts("MPU_6050\n");
	//===========================================================
	/* Setup SysTick Timer for 1 msec interrupts.
			 ------------------------------------------
			4. To adjust the SysTick time base, use the following formula:
															
					 Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
			
				 - Reload Value is the parameter to be passed for SysTick_Config() function
				 - Reload Value should not exceed 0xFFFFFF
		 */
/*Buoc 6: Init SysTick*/
		SysTick_Config(SystemCoreClock /Sample_time);
		puts("SysTick\n");
/*Buoc 7: Init Timer, PWM*/
		GPIO_TIM1_Config();
		TIM1_Config();
		puts("PWM\n");
/*Buoc 8: Init Encoder*/
		encodersInit();
		puts("ENC\n");
		puts("All OK!!!\n");
}
//
int main(void){
		Init_System();
		//============
		Lui_R();
		Lui_L();
		//Set_PWM(L, 1000);
		//Set_PWM(R, 1000);
		while (1)
		{	
		}
}


//****************************************************//
void Delay(uint16_t n){
	TimeDelay = n;
	while(TimeDelay!=0);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
