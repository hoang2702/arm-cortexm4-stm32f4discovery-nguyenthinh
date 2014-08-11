/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ENCODER_INTERFACE_H
#define __ENCODER_INTERFACE_H

#include <stm32f4xx.h>
/*
   * definitions for the quadrature encoder pins
   */
// Left Motor Channels
#define ENCLA_PIN               GPIO_Pin_15
#define ENCLA_GPIO_PORT         GPIOA
#define ENCLA_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCLA_SOURCE            GPIO_PinSource15
#define ENCLA_AF                GPIO_AF_TIM2

#define ENCLB_PIN               GPIO_Pin_3
#define ENCLB_GPIO_PORT         GPIOB
#define ENCLB_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define ENCLB_SOURCE            GPIO_PinSource3
#define ENCLB_AF                GPIO_AF_TIM2

// Right Motor Channels
#define ENCRA_PIN               GPIO_Pin_6
#define ENCRA_GPIO_PORT         GPIOA
#define ENCRA_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCRA_SOURCE            GPIO_PinSource6
#define ENCRA_AF                GPIO_AF_TIM3

#define ENCRB_PIN               GPIO_Pin_7
#define ENCRB_GPIO_PORT         GPIOA
#define ENCRB_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCRB_SOURCE            GPIO_PinSource7
#define ENCRB_AF                GPIO_AF_TIM3

// determine the timers to use
#define ENCL_TIMER              TIM2
#define ENCL_TIMER_CLK          RCC_APB1Periph_TIM2
#define ENCR_TIMER              TIM3
#define ENCR_TIMER_CLK          RCC_APB1Periph_TIM3

#define LEFT_COUNT()            ENCL_TIMER->CNT
#define RIGHT_COUNT()           ENCR_TIMER->CNT


//
int16_t encodersRead (void);
void encodersReset (void);
void encodersInit (void);
#endif /* __STM32F4xx_IT_H */
