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
//#include "main.h"
#include "stm32f4xx_it.h"
#include "stm32f4_discovery.h"
#include <stdio.h>
//#include "GPIO_Config.h"
#include "stm32f4xx.h"
#include "uart_to_printf.h"
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup EXTI_Example
  * @{
  */ 

/* Global variables ---------------------------------------------------------*/
extern s32 data;
extern u8 Truyen_VanToc;
u8 chieu=0;
//PID myPID;
//======= Private variables ======
/* Private UART variables -------------------------------------------------------------*/
	int UART1_count=0;
	char UART1_chuoi[10];
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
  //USART_SendData(USART2,0x48) ;
//	if(chieu==0)
//	{
//		data=data-100;
//		if(data<-1500)
//			chieu=1;
//	}
//	else
//	{
//		data=data+100;
//		if(data>1500)
//			chieu=0;
//	}
//		MSD_SenCmd(Bx1,2, data);
//		MSD_SenCmd(Bx2,2, data);
//		MSD_SenCmd(Bx3,2, data);
//		STM_EVAL_LEDToggle(LED3);
  /* Clear the EXTI line pending bit */
  EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
}
// USART
void USART1_IRQHandler(void) {
	//
	char c;
	//========
	if(USART_GetITStatus(USART1, USART_IT_RXNE)==SET) 
	{
		//nhan duoc 1 ky tu
		//kiem tra xem no la ky tu nao
		//USART_puts(USART1,"Vao ngat");
		
		c=USART_ReceiveData(USART1);
		if (c!='e')
		 {
				if (UART1_count==0)
				{
					 memset(UART1_chuoi, '\0', sizeof(UART1_chuoi));
				}
				UART1_chuoi[UART1_count]=c;
				UART1_count++;
		 }
	  else
		 {
				UART1_count=0;
				data=atoi(UART1_chuoi);
				Truyen_VanToc=1;
		 }
		USART_ClearFlag(USART1, USART_FLAG_RXNE);
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
