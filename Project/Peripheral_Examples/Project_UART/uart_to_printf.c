#include "uart_to_printf.h"


//******************************************************************************
/*
RX: Pin_B_6
TX: Pin_B_7
*/
void Init_USART1(uint32_t baudrate){
	
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the USART1 initilization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)

	/* enable APB2 peripheral clock for USART1 
	 * note that only USART1 and USART6 are connected to APB2
	 * the other USARTs are connected to APB1
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* enable the peripheral clock for the pins used by 
	 * USART1, PB6 for TX and PB7 for RX
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	/* This sequence sets up the TX and RX pins 
	 * so they work correctly with the USART1 peripheral
	 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOB, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	/* The RX and TX pins are now connected to their AF
	 * so that the USART1 can take over control of the 
	 * pins
	 */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

	/* Now the USART_InitStruct is used to define the 
	 * properties of USART1 
	 */
	USART_InitStruct.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART1, &USART_InitStruct);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	// finally this enables the complete USART1 peripheral
	USART_Cmd(USART1, ENABLE);
  USART_ClearFlag(USART1, USART_FLAG_RXNE);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
}

/* This function is used to transmit a string of characters via 
 * the USART specified in USARTx.
 * 
 * It takes two arguments: USARTx --> can be any of the USARTs e.g. USART1, USART2 etc.
 * 						   (volatile) char *s is the string you want to send
 * 
 * Note: The string has to be passed to the function as a pointer because
 * 		 the compiler doesn't know the 'string' data type. In standard
 * 		 C a string is just an array of characters
 * 
 * Note 2: At the moment it takes a volatile char because the received_string variable
 * 		   declared as volatile char --> otherwise the compiler will spit out warnings
 * */

/**************************************************************************************/
/*
RX: Pin_C_6
TX: Pin_C_7
*/
void Init_USART6(uint32_t baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	/*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
  */    
        
  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
 
  /* Enable USART6 clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
     
  /* Configure port as pushpull, 50MHz and No pull up & down  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
         
  /* Configure PC6 as alternate function  */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
 
  /* Configure PC7 as alternate function  */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
     
  /* Connect PC6 to USART6_Tx*/
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
 
  /* Connect PC7 to USART6_Rx*/
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
     
  /* USART6 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = baudrate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
   
 
  /* USART configuration */
  USART_Init(USART6, &USART_InitStructure);
	USART_ClearFlag(USART6, USART_FLAG_RXNE);
  
  /* Enable USART */
  USART_Cmd(USART6, ENABLE);
  //================================
	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//====================================       
 
}

/**************************************************************************************/
/*
RX: Pin_A_2
TX: Pin_A_3
*/
void Init_USART2(uint32_t baudrate)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	/* --------------------------- System Clocks Configuration -----------------*/
  /* USART2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
  /* GPIOA clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  /*-------------------------- GPIO Configuration ----------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Connect USART pins to AF */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);  // USART2_TX
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);  // USART2_RX
	
  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 19200 baud
        - Word Length = 9 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = baudrate;
  USART_InitStructure.USART_WordLength = USART_WordLength_9b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART2, &USART_InitStructure);
	//================================
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
//	
//  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
//	
	//====================================
  USART_Cmd(USART2, ENABLE);
}

/*
RX: Pin_C_10
TX: Pin_C_11
*/
void Init_USART3(uint32_t baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
  
	//==============================================================================
  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	/* Enable UART clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
  

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);

  /* Configure USART Tx as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* Configure USART Rx as alternate function  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* USARTx configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = baudrate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  /* USART configuration */
  USART_Init(USART3, &USART_InitStructure);
	USART_ClearFlag(USART3, USART_FLAG_RXNE);
  /* Enable USART */
  USART_Cmd(USART3, ENABLE);
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
//======================================================================
void USART_puts(USART_TypeDef* USARTx, volatile char *s){

	while(*s){
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) ); 
		USART_SendData(USARTx, *s);
		*s++;
	}
}
//========================================================================================================
void UART_Configuration(void)
{
	
	Init_USART1(115200);
	USART_puts(USART1,"USART 1");
	Init_USART2(19200);
	USART_puts(USART2,"USART 2");
	Init_USART3(115200);
	USART_puts(USART3,"USART 3");
	Init_USART6(115200);
	USART_puts(USART6,"USART 6");
//	
//	USART_SendData(USART1,"USART1");
//	/* Loop until the end of transmission */
//	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
//	{}
//	USART_SendData(USART3,0x48);
//	/* Loop until the end of transmission */
//	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
//	{}
//	
//	//================================
//	NVIC_Configuration(); /* Interrupt Config */
//	USART_6();
//	puts("Nguyen Thinh");
//	USART_SendData(USART6,0x48);
//	/* Loop until the end of transmission */
//	while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET)
//	{}
//	USART_SendData(USART6,0x48);
//	/* Loop until the end of transmission */
//	while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET)
//	{}
//		
// 	puts("USART2_Configuration: DONE");
}
//******************************************************************************
// Hosting of stdio functionality through USART2
//******************************************************************************

#include <rt_misc.h>

#pragma import(__use_no_semihosting_swi)

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f)
{
	static int last;

	if ((ch == (int)'\n') && (last != (int)'\r'))
	{
		last = (int)'\r';

  	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

 	  USART_SendData(USART1, last);
	}
	else
		last = ch;

	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

  USART_SendData(USART1, ch);

  return(ch);
}

int fgetc(FILE *f)
{
	char ch;

	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

	ch = USART_ReceiveData(USART1);

  return((int)ch);
}

int ferror(FILE *f)
{
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int ch)
{
	static int last;

	if ((ch == (int)'\n') && (last != (int)'\r'))
	{
		last = (int)'\r';

  	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

 	  USART_SendData(USART1, last);
	}
	else
		last = ch;

	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

  USART_SendData(USART1, ch);
}

void _sys_exit(int return_code)
{
label:  goto label;  /* endless loop */
}

//******************************************************************************

