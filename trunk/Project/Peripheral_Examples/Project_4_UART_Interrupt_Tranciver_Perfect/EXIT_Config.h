/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
/** @addtogroup STM32F4_Discovery_Peripheral
  * @{
  */

/** @addtogroup EXTI_Config
  * @{
  */ 

/******************************************************************************/
/*            Prototype function                                              */
/******************************************************************************/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/******************************************************************************/
/*                  Encode_1                                                  */
/******************************************************************************/
#define Encode_1A_pin      			GPIO_Pin_1
#define Encode_1B_pin      			GPIO_Pin_0
#define Encode_1A_port    		  GPIOE
#define Encode_1B_port     			GPIOE
#define Encode_1_line      			EXTI_Line1
#define Encode_1_rcc       			RCC_AHB1Periph_GPIOE
#define Encode_1_port_source    EXTI_PortSourceGPIOE
#define Encode_1_pin_source     EXTI_PinSource1
#define Encode_1_IRQn						EXTI1_IRQn
#define Encode_1_PreePri				0x01			// do uu tien truoc
#define Encode_1_SubPri					0x01			// do uu tien sau, thay the
/******************************************************************************/
/*                  Encode_2                                                  */
/******************************************************************************/
#define Encode_2A_pin     	    GPIO_Pin_7
#define Encode_2B_pin     	    GPIO_Pin_6
#define Encode_2A_port   	  	  GPIOB
#define Encode_2B_port   			  GPIOB
#define Encode_2_line    			  EXTI_Line7
#define Encode_2_rcc   			    RCC_AHB1Periph_GPIOB
#define Encode_2_port_source    EXTI_PortSourceGPIOB
#define Encode_2_pin_source     EXTI_PinSource7
#define Encode_2_IRQn						EXTI9_5_IRQn
#define Encode_2_PreePri				0x01			// do uu tien truoc
#define Encode_2_SubPri					0x01			// do uu tien sau, thay the
/******************************************************************************/
/*                  Encode_3                                                  */
/******************************************************************************/
#define Encode_3A_pin     	    GPIO_Pin_4
#define Encode_3B_pin   	      GPIO_Pin_3
#define Encode_3A_port   	      GPIOD
#define Encode_3B_port   	      GPIOD
#define Encode_3_line     	    EXTI_Line4
#define Encode_3_rcc      	    RCC_AHB1Periph_GPIOD
#define Encode_3_port_source    EXTI_PortSourceGPIOD
#define Encode_3_pin_source     EXTI_PinSource4
#define Encode_3_IRQn						EXTI4_IRQn
#define Encode_3_PreePri				0x01			// do uu tien truoc
#define Encode_3_SubPri					0x01			// do uu tien sau, thay the
/******************************************************************************/
/*                  Encode_4                                                  */
/******************************************************************************/
#define Encode_4A_pin     	    GPIO_Pin_2
#define Encode_4B_pin     	    GPIO_Pin_1
#define Encode_4A_port    	    GPIOD
#define Encode_4B_port    	    GPIOD
#define Encode_4_line      	    EXTI_Line2
#define Encode_4_rcc       	    RCC_AHB1Periph_GPIOD
#define Encode_4_port_source    EXTI_PortSourceGPIOD
#define Encode_4_pin_source     EXTI_PinSource2
#define Encode_4_IRQn						EXTI2_IRQn
#define Encode_4_PreePri				0x01			// do uu tien truoc
#define Encode_4_SubPri					0x01			// do uu tien sau, thay the
/******************************************************************************/
/*                  Encode_5                                                  */
/******************************************************************************/
#define Encode_5A_pin     	    GPIO_Pin_0
#define Encode_5B_pin     	    GPIO_Pin_12
#define Encode_5A_port     	    GPIOD
#define Encode_5B_port     	    GPIOC
#define Encode_5_line      	    EXTI_Line0
#define Encode_5_rcc       	    RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD
#define Encode_5_port_source    EXTI_PortSourceGPIOD
#define Encode_5_pin_source     EXTI_PinSource0
#define Encode_5_IRQn						EXTI0_IRQn
#define Encode_5_PreePri				0x01			// do uu tien truoc
#define Encode_5_SubPri					0x01			// do uu tien sau, thay the
/******************************************************************************/
/*                  Encode_6                                                  */
/******************************************************************************/
#define Encode_6A_pin      	    GPIO_Pin_11
#define Encode_6B_pin      	    GPIO_Pin_10
#define Encode_6A_port     	    GPIOC
#define Encode_6B_port     	    GPIOC
#define Encode_6_line      	    EXTI_Line11
#define Encode_6_rcc       	    RCC_AHB1Periph_GPIOC
#define Encode_6_port_source    EXTI_PortSourceGPIOC
#define Encode_6_pin_source     EXTI_PinSource11
#define Encode_6_IRQn					  EXTI15_10_IRQn
#define Encode_6_PreePri			  0x01			// do uu tien truoc
#define Encode_6_SubPri			    0x01		// do uu tien sau, thay the


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Econder_1_Config(void);
void Econder_2_Config(void);
void Econder_3_Config(void);
void Econder_4_Config(void);
void Econder_5_Config(void);
void Econder_6_Config(void);
/* Private functions ---------------------------------------------------------*/




