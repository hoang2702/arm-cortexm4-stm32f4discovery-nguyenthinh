
#include "USART_Config.h"

/*----------------UART config-------------------*/
void Init_USART(void) {
	GPIO_InitTypeDef gpioInit;
	USART_InitTypeDef usartInit;
	NVIC_InitTypeDef nvicInit;

	//****************************************************************
	//cau hinh ngat
	
	//den phan cau hinh cho EUART
	//su dung cong COM
	//du tinh su dung cong COM 1
	//dau tien cho phep clock toi cong do
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	//cho phep clock toi chan Rx Tx
	//khoi dong chan PA2, PA3
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	//cau hinh chan Rx Tx
	gpioInit.GPIO_Mode=GPIO_Mode_AF;
	gpioInit.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;
	gpioInit.GPIO_Speed=GPIO_Speed_100MHz;
	gpioInit.GPIO_OType=GPIO_OType_PP;
	gpioInit.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &gpioInit);
	//gan chan Rx Tx
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	//cau hinh cho USART2
	usartInit.USART_BaudRate=256000;
	usartInit.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	usartInit.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	usartInit.USART_Parity=USART_Parity_No;
	usartInit.USART_StopBits=USART_StopBits_1;
	usartInit.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART2, &usartInit);
	//cho phep ngat nhan
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	//cau hinh NVIC
	nvicInit.NVIC_IRQChannel=USART2_IRQn;
	nvicInit.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&nvicInit);
	
	//cho phep USART1 hoat dong
	USART_Cmd(USART2, ENABLE);
	
}
void Send(char *szData) {
	char c;
	while(c=*(szData++)) {
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE)!=SET);
		USART_SendData(USART2, c);
	}
}

