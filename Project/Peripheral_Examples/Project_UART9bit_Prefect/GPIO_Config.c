/**
  ******************************************************************************
  * File Name          : mx_gpio.c
  * Date               : 21/07/2013 10:03:52
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  * COPYRIGHT 2013 STMicroelectronics
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "GPIO_Config.h"

/* Private typedef ---------------------------------------------------------*/
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */


/*-----------------------------------------------------------------------------*/
/*------ cau hinh GPIO o chuc nang timer, ko phai cau hinh timer-------------- */
/*-----------------------------------------------------------------------------*/
void GPIO_TIM1_Config(void){
	/** TIM1 GPIO Configuration	
		 PE9	 ------> TIM1_CH1
		 PE11	 ------> TIM1_CH2
		 PE13	 ------> TIM1_CH3
		 PE14	 ------> TIM1_CH4
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	/*Enable or disable TIMER the AHB1 peripheral clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);
}

/*-----------------------------------------------------------------------------*/
/*---------------------- cau hinh cho timer ---------------------------------- */
/*-----------------------------------------------------------------------------*/
void TIM1_Config(void){
	/** TIM1 GPIO Configuration	
		 PE9	 ------> TIM1_CH1
		 PE11	 ------> TIM1_CH2
		 PE13	 ------> TIM1_CH3
		 PE14	 ------> TIM1_CH4
	*/

  /* TIM1 Configuration ---------------------------------------------------
   Generate 4 PWM signals with 4 different duty cycles:
   TIM1 input clock (TIM1CLK) is set to 2 * APB2 clock (PCLK2), since APB2 		//see in Referen_Manual
    prescaler is different from 1.   																					// APB2 Prescaler = 2, see in stm32f4xx.c
    TIM1CLK = 2 * PCLK2  
    PCLK2 = HCLK / 2 
    => TIM1CLK = 2 * (HCLK / 2) = HCLK = SystemCoreClock = 168MHz
		=> TIM1CLK = SystemCoreClock
	
	 To get TIM1 counter clock at 42MHz, the prescaler is computed as follows:
   Prescaler = (TIM1CLK / TIM1 counter clock) - 1
   Prescaler = (SystemCoreClock /42 MHz) - 1 = 3
   SystemCoreClock is set to 168 MHz for STM32F4xx devices
	
   To get TIM1 output clock at 30 KHz, the period (ARR)) is computed as follows:
      TIM1_Period = ARR = (TIM1 counter clock / TIM1 output clock) - 1
												= 1399	
   The channel 1 duty cycle is set to 50%
   The channel 2 duty cycle is set to 37.5%
   The channel 3 duty cycle is set to 25%
   The channel 4 duty cycle is set to 12.5%
   The Timer pulse is calculated as follows:
     - ChannelxPulse = DutyCycle * (TIM1_Period-1) / 100
										 = 699  (50%)
										 = 524  (37.5%)
										 = 350  (25%)
										 = 175   (12.5%)
   Note: 
    SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
    Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
    function to update SystemCoreClock variable value. Otherwise, any configuration
    based on this variable will be incorrect. 
  ----------------------------------------------------------------------- */
  /* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 3;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 1399;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;// ?

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

  /* Channel 1, 2,3 and 4 Configuration in PWM mode */
	// channel 1
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OCInitStructure.TIM_Pulse = 699;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
	
  TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	// channel 2
  TIM_OCInitStructure.TIM_Pulse = 524;
  TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	// channel 3
  TIM_OCInitStructure.TIM_Pulse = 350;
  TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	// channel 4
  TIM_OCInitStructure.TIM_Pulse = 175;
  TIM_OC4Init(TIM1, &TIM_OCInitStructure);

  /* TIM1 counter enable */
  TIM_Cmd(TIM1, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
