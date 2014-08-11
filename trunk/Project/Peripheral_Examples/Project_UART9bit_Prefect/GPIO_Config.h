/**
  ******************************************************************************
  * File Name          : mx_gpio.h
  * Date               : 21/07/2013 08:39:51
  * Description        : This file contains all the functions prototypes for 
  *                      the mx_gpio  
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __mx_pinoutConfig_H
#define __mx_pinoutConfig_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
void mx_pinout_config(void);
void GPIO_TIM1_Config(void);
void GPIO_TIM2_Config(void);
void GPIO_TIM3_Config(void);
void GPIO_TIM4_Config(void);
void GPIO_TIM5_Config(void);
void GPIO_TIM8_Config(void);
void GPIO_TIM9_Config(void);
void GPIO_TIM10_Config(void);
void GPIO_TIM11_Config(void);
void GPIO_TIM12_Config(void);
void GPIO_TIM13_Config(void);
void GPIO_TIM14_Config(void);
void TIM1_Config(void);
void TIM2_Config(void);
void TIM3_Config(void);
void TIM4_Config(void);
void TIM5_Config(void);
void TIM8_Config(void);
void TIM9_Config(void);
void TIM10_Config(void);
void TIM11_Config(void);
void TIM12_Config(void);
void TIM13_Config(void);
void TIM14_Config(void);

#ifdef __cplusplus
}
#endif
#endif /*__ mx_pinoutConfig_H */
