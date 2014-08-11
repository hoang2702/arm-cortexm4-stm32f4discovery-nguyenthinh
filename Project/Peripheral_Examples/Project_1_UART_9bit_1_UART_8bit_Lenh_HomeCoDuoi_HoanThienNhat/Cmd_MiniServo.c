#include "Cmd_MiniServo.h"
#include "uart_to_printf.h"

#define RS485_ID 0x09
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

void MAX485_DIR_OUT(void)
{
	GPIO_SetBits(GPIOE, GPIO_Pin_2);
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
}

void MAX485_DIR_IN(void)
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

int rs485_send_message(u8 to, u8 len, u8* data) {			 
   u8  i, cs,try;
      
   for(try=0; try<3; ++try) {

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
   }
   return 1;
}

int MSD_SenCmd(u8 to,u8 cmd1, s32 data1) {             
      u8 dataTerm[5];
    dataTerm[0] = cmd1;
    dataTerm[1] = data1;
    dataTerm[2]    = data1>>8;
    dataTerm[3]    = data1>>16;
    dataTerm[4]    = data1>>24;
		
		uart_sent(0x0);
    return rs485_send_message(to,5, dataTerm);
}
