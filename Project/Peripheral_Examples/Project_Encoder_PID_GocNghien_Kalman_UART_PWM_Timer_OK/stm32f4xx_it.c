/**
  ******************************************************************************
  * @file    EXTI/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "main.h"
#include "stm32f4xx_it.h"
#include "stm32f4_discovery.h"
#include "Encoder_Interface.h"
#include <stdio.h>
#include "GPIO_Config.h"
#include "stm32f4xx.h"
#include "MPU_6050.h"
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup EXTI_Example
  * @{
  */ 

/* Global variables ---------------------------------------------------------*/
extern  uint16_t  Sample_time;
extern	uint16_t   Resolution;
extern 	uint16_t TimeDelay ;
extern int ACCEL_ZOUT;
extern int32_t Err;
extern __IO int32_t Set_Point;

/* Private define ------------------------------------------------------------*/
//======= Define =================
#define Kp 15  //5.01
#define Kd 0.2  //0.01
#define Ki 1  //0.5
int16_t count=0, speed;
//PID myPID;
//======= Private variables ======
volatile int16_t Out = 0;
volatile int16_t Speed_des = 10;
//volatile int16_t Pre_Err = 0;
//volatile int16_t Err=0;
volatile float pP=0;
//volatile float dP = 0;
volatile float iP = 0;
/* Private macro -------------------------------------------------------------*/
	uint8_t dem=0;
/* Private UART variables -------------------------------------------------------------*/
	int UART_count=0;
	char UART_chuoi[8];
/* Private function -----------------------------------------------------------------*/
	void PID_speed(uint16_t desire_speed);
	void	Motor_Speed_PID(__IO uint32_t Set_Point);
/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/
/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	/* Void Delay()--------------------------------------- */
	//TimeDelay--;
	//*******************************************************
//	dem++;
//	if(dem==100)
//	{
//		dem=0;
//		//dem = ((encodersRead()*Sample_time)/(4*Resolution));
//		//printf("Gia tri count: %d\n",encodersRead());
//		//Get_Accel_Values();
//		//printf("Gia tri goc: %d\n",ACCEL_ZOUT);
//		//Motor_Speed_PID(10);
//		
//	}
	//puts("pid");
	Motor_Speed_PID(Set_Point);
	//puts("pid_done!!");
	//TIM_SetCounter (TIM3, 0);
	//********************************************************
	
	//puts("A\n");
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/
/**
  * @brief  This function handles EXTI0_IRQ Handler.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  //UserButtonPressed = 0x01;
  
  /* Clear the EXTI line pending bit */
  EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
}
// USART
void USART2_IRQHandler(void) {
	//
	char c;
	//========
	if(USART_GetITStatus(USART2, USART_IT_RXNE)==SET) {
		//nhan duoc 1 ky tu
		//kiem tra xem no la ky tu nao
		c=USART_ReceiveData(USART2);
		if (c!='e')
   {
      if (UART_count==0)
      {
         memset(UART_chuoi, '\0', sizeof(UART_chuoi));
      }
      UART_chuoi[UART_count]=c;
      UART_count++;
   }
	 else
   {
      UART_count=0;
			printf("So gui: %d \n",atoi(UART_chuoi));
			Set_Point=atoi(UART_chuoi);
   }

		//USART_SendData(USART2, 'A');
		//puts("Da Nhan");
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}
}

/**
  * @}
  */ 

//***************ham tinh toan PID***************************//

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
