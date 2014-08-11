//******************************************************************************
#include "stm32f4xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//******************************************************************************

//******************************************************************************
void UART_Configuration(void);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);
void GPIO_RE_DE_485_Motor(void);
void GPIO_RE_DE_485_PC(void);
void MAX485_DIR_OUT_PC(void);
void MAX485_DIR_IN_PC(void);
//******************************************************************************
