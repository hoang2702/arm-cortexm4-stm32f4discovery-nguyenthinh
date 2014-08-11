/**
  ******************************************************************************
  * @file    ADC3_DMA/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
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
#include "stm32f4_discovery.h"
#include <stdio.h>
// STM32F2/4 Two Channel ADC1 Loop - sourcer32@gmail.com
  
#include "uart_to_printf.h"
  
#include "stm32f4xx.h"
  
//******************************************************************************
s32 data=1000;
u8 Truyen_VanToc=0;

volatile uint16_t ADCConvertedValues[6];
  
//******************************************************************************
  
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  /* Configure ADC1 Channel3 & 5 pins as analog input ******************************/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}
  
//******************************************************************************
  
void ADC1_Configuration(void)
{
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  DMA_InitTypeDef       DMA_InitStructure;
  
  /* Enable peripheral clocks *************************************************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
  
  /* DMA2_Stream0 channel0 configuration **************************************/
  DMA_DeInit(DMA2_Stream0);
  DMA_InitStructure.DMA_Channel = DMA_Channel_0;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADCConvertedValues[0];
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 6;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA2_Stream0, &DMA_InitStructure);
  /* DMA2_Stream0 enable */
  DMA_Cmd(DMA2_Stream0, ENABLE);
  
  /* ADC Common Init **********************************************************/
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);
  
  /* ADC1 Init ****************************************************************/
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 6;
  ADC_Init(ADC1, &ADC_InitStructure);
  
  /* ADC1 regular channel configuration ******************************/
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_480Cycles); // PA3
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_480Cycles); // PA5
  ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 3, ADC_SampleTime_480Cycles); // PA5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 4, ADC_SampleTime_480Cycles); // PA5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 5, ADC_SampleTime_480Cycles); // PA5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 6, ADC_SampleTime_480Cycles); // PA5
   /* Enable DMA request after last transfer (Single-ADC mode) */
  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
  
  /* Enable ADC1 DMA */
  ADC_DMACmd(ADC1, ENABLE);
  
    /* Enable ADC1 **************************************************************/
  ADC_Cmd(ADC1, ENABLE);
  
    /* Start ADC1 Software Conversion */
  ADC_SoftwareStartConv(ADC1);
}
  
//******************************************************************************
  
int main(void)
{
  GPIO_Configuration();
      
  ADC1_Configuration();
  UART_Configuration();
  
	printf("ADC Testing");
  
  while(1)
  {
    if (Truyen_VanToc)
    {
			Truyen_VanToc=0;
      printf("%03X %03X %03X %03X %03X %03X\n", ADCConvertedValues[0], ADCConvertedValues[1], ADCConvertedValues[2], ADCConvertedValues[3], ADCConvertedValues[4], ADCConvertedValues[5]);
    }
  }
  
  while(1); /* Infinite loop */
}































///** @addtogroup STM32F4_Discovery_Peripheral_Examples
//  * @{
//  */

///** @addtogroup ADC_ADC3_DMA
//  * @{
//  */ 

///* Private typedef -----------------------------------------------------------*/
///* Private define ------------------------------------------------------------*/
//#define ADC3_DR_ADDRESS     ((uint32_t)0x4001224C)

///* Private macro -------------------------------------------------------------*/
///* Private variables ---------------------------------------------------------*/
///* You can monitor the converted value by adding the variable "ADC3ConvertedValue" 
//   to the debugger watch window */
//__IO uint16_t ADC3ConvertedValue = 0;
//__IO uint32_t ADC3ConvertedVoltage = 0;

///* Private function prototypes -----------------------------------------------*/
///* Private functions ---------------------------------------------------------*/
//void ADC3_CH12_DMA_Config(void);

///**
//  * @brief  Main program
//  * @param  None
//  * @retval None
//  */
//int main(void)
//{
//  /*!< At this stage the microcontroller clock setting is already configured, 
//       this is done through SystemInit() function which is called from startup
//       file (startup_stm32f4xx.s) before to branch to application main.
//       To reconfigure the default setting of SystemInit() function, refer to
//       system_stm32f4xx.c file
//     */
//  /* ADC3 configuration *******************************************************/
//  /*  - Enable peripheral clocks                                              */
//  /*  - DMA2_Stream0 channel2 configuration                                   */
//  /*  - Configure ADC Channel12 pin as analog input                           */
//  /*  - Configure ADC3 Channel12                                              */
//  ADC3_CH12_DMA_Config();

//  /* Start ADC3 Software Conversion */ 
//  ADC_SoftwareStartConv(ADC3);

//  while (1)
//  {
//  /* convert the ADC value (from 0 to 0xFFF) to a voltage value (from 0V to 3.3V)*/
//    ADC3ConvertedVoltage = ADC3ConvertedValue *3300/0xFFF;
//  }
//}


///**
//  * @brief  ADC3 channel12 with DMA configuration
//  * @param  None
//  * @retval None
//  */
//void ADC3_CH12_DMA_Config(void)
//{
//  ADC_InitTypeDef       ADC_InitStructure;
//  ADC_CommonInitTypeDef ADC_CommonInitStructure;
//  DMA_InitTypeDef       DMA_InitStructure;
//  GPIO_InitTypeDef      GPIO_InitStructure;

//  /* Enable ADC3, DMA2 and GPIO clocks ****************************************/
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOC, ENABLE);
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);

//  /* DMA2 Stream0 channel0 configuration **************************************/
//  DMA_InitStructure.DMA_Channel = DMA_Channel_2;  
//  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC3_DR_ADDRESS;
//  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC3ConvertedValue;
//  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
//  DMA_InitStructure.DMA_BufferSize = 1;
//  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
//  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
//  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
//  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
//  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
//  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
//  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
//  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
//  DMA_Init(DMA2_Stream0, &DMA_InitStructure);
//  DMA_Cmd(DMA2_Stream0, ENABLE);

//  /* Configure ADC3 Channel12 pin as analog input ******************************/
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);

//  /* ADC Common Init **********************************************************/
//  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
//  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
//  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
//  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
//  ADC_CommonInit(&ADC_CommonInitStructure);

//  /* ADC3 Init ****************************************************************/
//  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
//  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
//  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
//  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
//  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//  ADC_InitStructure.ADC_NbrOfConversion = 1;
//  ADC_Init(ADC3, &ADC_InitStructure);

//  /* ADC3 regular channel12 configuration *************************************/
//  ADC_RegularChannelConfig(ADC3, ADC_Channel_12, 1, ADC_SampleTime_3Cycles);

// /* Enable DMA request after last transfer (Single-ADC mode) */
//  ADC_DMARequestAfterLastTransferCmd(ADC3, ENABLE);

//  /* Enable ADC3 DMA */
//  ADC_DMACmd(ADC3, ENABLE);

//  /* Enable ADC3 */
//  ADC_Cmd(ADC3, ENABLE);
//}

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
