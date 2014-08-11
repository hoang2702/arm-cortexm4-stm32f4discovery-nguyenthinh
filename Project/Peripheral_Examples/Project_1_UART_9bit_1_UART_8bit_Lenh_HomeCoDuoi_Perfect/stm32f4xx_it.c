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
#include <stdio.h>
#include "GPIO_Config.h"
#include "stm32f4xx.h"
#include "uart_to_printf.h"
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */
#define convert 100
/** @addtogroup EXTI_Example
  * @{
  */ 


/* Global variables ---------------------------------------------------------*/
extern volatile uint16_t ADCConvertedValues[6];
extern s32 data;
extern u8 Truyen;
extern u8 mod;
volatile uint16_t ViTri_Visme_Desire[]={0,0,0,0,0,0};
/*
ViTri_Visme_real = ViTri_DongCo + ADCConvertedValues/convert
Do cung trung binh: 160 dv ADC / 1 mm / 2pi
Gia tri truyen vi tri toi thieu la 1 rad tuong ung voi 50 dv ADC
*/
volatile uint16_t ADC_old[]={4095,4095,4095,3380,3400,3470};
volatile s16 ADC_delta[6];
volatile uint16_t ViTri_DC[6];
volatile uint16_t ViTri_Visme_delta[6];

u8 chieu=0;
uint16_t dem=0;
u8 i=0;
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
	dem++;
	if(dem==10)
	{
		dem=0;
		//printf("ADC4 %d \n",ADCConvertedValues[3]); //3380 . 25,40mm - 16,20:1790-----------172.83
		//printf("ADC5 %d \n",ADCConvertedValues[4]); //3400 - 25,2  ----- 2185 - 14,77-------116.5
		//printf("ADC6 %d \n",ADCConvertedValues[5]); //3470 - 25,5 -------- 17,10 - 2070-----166.77
		
		STM_EVAL_LEDToggle(LED3);
		if(mod!=0)
		{
			for (i=0;i<6;i++)
			{
				if(ADCConvertedValues[i]<1000)
					ADCConvertedValues[i]=4095;
				
				ADC_delta[i]=ADC_old[i]-ADCConvertedValues[i];
				if(((ADC_delta[i]>25)||(ADC_delta[i]<-25))&(i!=1))
				{
					ADC_old[i]=ADCConvertedValues[i];
					
					ViTri_DC[i]=ViTri_Visme_Desire[i]-ADCConvertedValues[i]*0.0203;
					MSD_SenCmd(11+i,1, -ViTri_DC[i]*1000);
				}
			}
		}
	}
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
  /* Clear the EXTI line pending bit */
  EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
}


void TIM2_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    //GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
  }
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
				Truyen=1;
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
