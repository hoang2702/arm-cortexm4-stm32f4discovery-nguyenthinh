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
#include "main.h"
#include <stdio.h>


/** @addtogroup EXTI
  * @{
  */ 
uint16_t TimeDelay=0;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
void MAX485_DIR_OUT()
{
	GPIO_SetBits(GPIOE, GPIO_Pin_2);
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
}

void MAX485_DIR_IN()
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_2);
	GPIO_ResetBits(GPIOE, GPIO_Pin_3);
}
void uart_sent(u16 data)
{
	USART_SendData(USART2,data);
	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
	{}
}
void delay_us()
{
	
}

int rs485_send_message(u8 to, u8 len, u8* data) {			 
   u8  i, cs,try;
      
   for(try=0; try<5; ++try) {
		s16 timeWait = 2200;

		 MAX485_DIR_OUT(); // huong truyen du lieu, 2 chan de va te
		 //RCV_OFF();		   //Turn off Interrupt Uart Receiver.
		 //delay_us(1);
		 
		 if(len>32){
		   	return -1; //leng have to <32;
		 }
///////////// vd = (u16)cmWriteData|len;
		 uart_sent((u16)0x100|len);			//0x100 sending Start of frame and leng of data , comand tai bit 7 =0 quy dinh write data.
		 uart_sent(RS485_ID);						//Soure RS485_ID
		 uart_sent(to);						 		//Dest RS485_ID

		 for(i=0, cs = RS485_ID^to^len; i<len; i++) {
				 cs ^= data[i];									  //Create CheckSum
				 uart_sent(data[i]);
				 
		 }
		 uart_sent((u8)cs);									 //Send CheckSum
		 uart_sent(0); // data will loose. so you don't care. hatware don't send one the end of frame because we switch max485_DIR_IN now .so i need send fake data.
		 MAX485_DIR_IN();
		  
		 ///////////////////////// wait for ACK.use sycronus
		 /*
		 while(timeWait-- !=0){
		   
			 if( USART_ReceiveData(RS485_PORT)  == ACK  ){	//received data ok
			   		RCV_ON();				
	   				return 1;		 //data is ok.
			 }
		 }
		 
		 if(try==4){
		 	RCV_ON();
		  	return -1;
		 }
		 */
   }
   return 1;
}

int MSD_SenCmd(u8 to,u8 cmd1, s32 data1) {             
      u8 dataTerm[5];
			u8 i=0;
    dataTerm[0] = cmd1;
    dataTerm[1] = data1;
    dataTerm[2]    = data1>>8;
    dataTerm[3]    = data1>>16;
    dataTerm[4]    = data1>>24;
		
		uart_sent(0x0);
    return rs485_send_message(to,5, dataTerm);
}
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
void Init_System(void)
{
		GPIO_InitTypeDef  GPIO_InitStructure;
/*Buoc 1: Init UART*/
		UART_Configuration();
		//printf("USART %i\n",2);
		//puts("Nguyen Thinh\n");
/*Buoc 2: Init nut nhan*/	
		STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI); // nut nhan chon mode
		//puts("Nut nhan\n");
/*Buoc 3: Init LED, chieu dong co*/  
////////////////////////////////////////////////
		
  
  /* Enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
////////////////////////////////////////////////
		STM_EVAL_LEDInit(LED3); // chieu dong co
		STM_EVAL_LEDInit(LED4); //
		STM_EVAL_LEDInit(LED5); //
		STM_EVAL_LEDInit(LED6); //
		//puts("LED\n");

	//===========================================================
	/* Setup SysTick Timer for 1 msec interrupts.
			 ------------------------------------------
			4. To adjust the SysTick time base, use the following formula:
															
					 Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
			
				 - Reload Value is the parameter to be passed for SysTick_Config() function
				 - Reload Value should not exceed 0xFFFFFF
		 */
/*Buoc 6: Init SysTick*/
		SysTick_Config(SystemCoreClock /1000);
		//puts("SysTick\n");
}
//
int main(void){
	  uint32_t i=0;
		Init_System();
		//USART_SendData(USART2,0x48) ;
		MSD_SenCmd(Bx1,2, 10000);
		MSD_SenCmd(Bx2,2, 10000);
		MSD_SenCmd(Bx3,2, 10000);
		//uart_sent(0x49);
		//============
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
