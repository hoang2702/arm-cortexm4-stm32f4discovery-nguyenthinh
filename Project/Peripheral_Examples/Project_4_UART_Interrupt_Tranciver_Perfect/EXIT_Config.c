/* Includes ------------------------------------------------------------------*/
#include "EXIT_Config.h"
/** @addtogroup STM32F4_Discovery_Peripheral
  * @{
  */

/** @addtogroup EXTI_Config
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	extern NVIC_InitTypeDef   NVIC_InitStructure;  // ben discovery f4 da khai bao roi, nen phai dung extern
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*              Econder_1_Config   Function                                   */
/******************************************************************************/
void Econder_1_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_1_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure channel A pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_1A_pin|Encode_1B_pin;   // 2 pin phai cung port moi cau hinh vay
  GPIO_Init(Encode_1A_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_1_port_source, Encode_1_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_1_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_1_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_1_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/******************************************************************************/
/*              Econder_2_Config   Function                                   */
/******************************************************************************/
void Econder_2_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_2_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_2A_pin|Encode_2B_pin;   // 2 pin phai cung port moi cau hinh vay
  GPIO_Init(Encode_2A_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_2_port_source, Encode_2_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_2_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_2_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_2_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/******************************************************************************/
/*              Econder_3_Config   Function                                   */
/******************************************************************************/
void Econder_3_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_3_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_3A_pin|Encode_3B_pin;   // 2 pin phai cung port moi cau hinh vay
  GPIO_Init(Encode_3A_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_3_port_source, Encode_3_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_3_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_3_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_3_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/******************************************************************************/
/*              Econder_2_Config   Function                                   */
/******************************************************************************/
void Econder_4_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_4_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_4A_pin|Encode_4B_pin;   // 2 pin phai cung port moi cau hinh vay
  GPIO_Init(Encode_4A_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_4_port_source, Encode_4_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_4_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_4_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_4_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/******************************************************************************/
/*              Econder_5_Config   Function                                   */
/*  Note: Econder_5 is diffrent from the orther encoder, 											*/
/*        because it have 2 pin at 2 diffrent port														*/
/******************************************************************************/
void Econder_5_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_5_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_5A_pin;   
  GPIO_Init(Encode_5A_port, &GPIO_InitStructure);
	  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_5B_pin;   
  GPIO_Init(Encode_5B_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_5_port_source, Encode_5_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_5_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_5_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_5_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/******************************************************************************/
/*              Econder_6_Config   Function                                   */
/******************************************************************************/
void Econder_6_Config(void){
  /* Enable GPIOE clock */
  RCC_AHB1PeriphClockCmd(Encode_6_rcc, ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Configure PE pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = Encode_6A_pin|Encode_6B_pin;   // 2 pin phai cung port moi cau hinh vay
  GPIO_Init(Encode_6A_port, &GPIO_InitStructure);

  /* Connect EXTI Line1 to PA0 pin */
  SYSCFG_EXTILineConfig(Encode_6_port_source, Encode_6_pin_source);

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = Encode_6_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = Encode_6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Encode_6_PreePri;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = Encode_6_SubPri;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
