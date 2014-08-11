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
//#include "TIM_Config.h"
#include "main.h"
#include <stdio.h>
#include "ADC_DMA.h"
#include "Cmd_MiniServo.h"
#include "GPIO_LimitSwitch.h"
/** @addtogroup EXTI
  * @{
  */ 
uint16_t TimeDelay=0;


extern volatile uint16_t ADCConvertedValues[6];
extern volatile uint16_t ViTri_Visme_Desire[];

/* Global variables------------------------------*/
u8 Truyen=0;
u8 mod=0;
s32 data=1000;


void delay_us()
{
	
}



void Init_System(void)
{
		
/*Buoc 1: Init UART*/
		UART_Configuration();
		ADC1_Configuration();
		GPIO_Config_LimitSwitch();
		//INTTIM_Config();
		STM_EVAL_LEDInit(LED3); // chieu dong co
		STM_EVAL_LEDInit(LED4); //
		STM_EVAL_LEDInit(LED5); //
		STM_EVAL_LEDInit(LED6); //
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
}
//
int main(void)
{
	u8 select=0;
	u8 visme=0;
	u8 sw1=0,sw2=0,sw3=0,sw4=0,sw5=0,sw6=0;
	u8 h1=0,h2=0,h3=0,h4=0,h5=0,h6=0;
	
	Init_System();
	
	printf("Nguyen thinh %d \n",123);
/**
		@Frame truyen gom 5 con so x1x2x3x4x5
		x1: quy dinh truyen cho visme hay banh xe
		
		x1=0:
		- Reset Visme
		- x1x2 quy dinh visme nao bi Reset
		x1=1:
		- Truyen lenh cho visme  : 
			+ x1x2 quy dinh visme nao nhan du lieu
			+ x4x5 là gia tri vi tri cua visme
											dao dong tu 0<->95.
		x1=2:
		- Truyen lenh cho banh xe: 
			+ x2x3x4x5 quy dinh toc do banh xe, gia tri tu 0<->1500
		x1=3:
		- Truyen lenh cho visme co ve
		- x4x5 la gia tri co ve cua visme
		x1=4:
		- Truyen lenh ve HOME
		
*/
	while (1)
	{

		if(Truyen==1)
		{
			Truyen=0;
			select=(u8)(data/10000); // select = x1
			visme=(u8)(data/1000);   // visme = x1x2
			data=data%10000;				// data = x2x3x4x5
//=================================================================
// Lenh truyen data cho visme - Use for debug only
// Ma lenh: 1-visme-x-data
// Vi du: Truyen cho visme 11, khoang cach 23 => Frame: 11x23
			if(select==1)
			{
				mod=1;
				data=data%100;  // data = x4x5
				switch (visme)
				{
					case 11:
						MSD_SenCmd(11,1, -1000*data);
						ViTri_Visme_Desire[0]=data+83;
						printf("Vi tri 11: %d \n",data);
						break;
					case 12:
						MSD_SenCmd(12,1, -1000*data);
						ViTri_Visme_Desire[1]=data+83;
						printf("Vi tri 12: %d \n",data);
						break;
					case 13:
						MSD_SenCmd(13,1, -1000*data);
						ViTri_Visme_Desire[2]=data+83;
						printf("Vi tri 13: %d \n",data);
						break;
					case 14:
						MSD_SenCmd(14,1, -1000*(data+1));
						ViTri_Visme_Desire[3]=data+1+83;
						printf("Vi tri 14: %d \n",data+1);
						break;
					case 15:
						MSD_SenCmd(15,1, -1000*data);
						ViTri_Visme_Desire[4]=data+83;
						printf("Vi tri 15: %d \n",data);
						break;
					case 16:
						MSD_SenCmd(16,1, -1000*data);
						ViTri_Visme_Desire[5]=data+83;
						printf("Vi tri 16: %d \n",data);
						break;
				}
			}
// Lenh truyen data cho banh xe
// Ma lenh: 2-data
// Vi du: Truyen van toc 1234 => Frame: 21234
			else if(select==2)		// data = x2x3x4x5
			{
				MSD_SenCmd(1,2, data);
				MSD_SenCmd(2,2, data);
				MSD_SenCmd(3,2, data);
				MSD_SenCmd(4,2, data);
				MSD_SenCmd(5,2, data);
				MSD_SenCmd(6,2, data);
				printf("Van toc: %d \n",data);
			}
// Lenh co visme - Use for debug only
// Dung trong truong hop visme bi reset dot ngot ma visme ko o vi tri HOME
// Ma lenh: 0-visme-x-data
// Vi du: Truyen cho visme 11, co 23 => Frame: 01x23
			else if(select==0)
			{
				data=data%100;
				mod=0;
				switch (visme)
				{
					case 1:
						MSD_SenCmd(11,1, 1000*data);
						printf("Vi tri 11: %d \n",data);
						break;
					case 2:
						MSD_SenCmd(12,1, 1000*data);
						printf("Vi tri 12: %d \n",data);
						break;
					case 3:
						MSD_SenCmd(13,1, 1000*data);
						printf("Vi tri 13: %d \n",data);
						break;
					case 4:
						MSD_SenCmd(14,1, 1000*data);
						printf("Vi tri 14: %d \n",data);
						break;
					case 5:
						MSD_SenCmd(15,1, 1000*data);
						printf("Vi tri 15: %d \n",data);
						break;
					case 6:
						MSD_SenCmd(16,1, 1000*data);
						printf("Vi tri 16: %d \n",data);
						break;
				}
			}
// Lenh Reset visme - Use for debug only
// Ma lenh: 0-visme-xxx
// Vi du: Reset visme 11 => Frame: 01xxx
			else if (select==3)
			{
				switch (visme)
				{
					case 31:
						MSD_SenCmd(11,4, 0);
						printf("Vi tri 11 Reset");
						break;
					case 32:
						MSD_SenCmd(12,4, 0);
						printf("Vi tri 12 Reset");
						break;
					case 33:
						MSD_SenCmd(13,4, 0);
						printf("Vi tri 13 Reset");
						break;
					case 34:
						MSD_SenCmd(14,4, 0);
						printf("Vi tri 14 Reset");
						break;
					case 35:
						MSD_SenCmd(15,4, 0);
						printf("Vi tri 15 Reset");
						break;
					case 36:
						MSD_SenCmd(16,4, 0);
						printf("Vi tri 16 Reset");
						break;
				}
			}
// Lenh Reset HOME
// Ma lenh: 4xxxx
// Vi du: 40000
			else if(select==4)
			{
				mod=0;
				h1=h2=h3=h4=h5=h6=0;
				sw1=sw2=sw3=sw4=sw5=sw6=0;
				MSD_SenCmd(11,1, 100000);
				MSD_SenCmd(12,1, 100000);
				MSD_SenCmd(13,1, 100000);
				MSD_SenCmd(14,1, 100000);
				MSD_SenCmd(15,1, 100000);
				MSD_SenCmd(16,1, 100000);
				printf("Dang ve \n");
				while(!(sw6 && sw5 && sw4 && sw3 && sw2 && sw1))
				{
					
					sw1=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_10);
					sw2=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11);
					sw3=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_12);
					sw4=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
					sw5=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14);
					sw6=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15);
					if(sw1)
					{
						if(h1==0)
						{
							MSD_SenCmd(11,4, 0);
							printf("Vi tri 11 Reset \n");
							STM_EVAL_LEDOn(LED4);
							STM_EVAL_LEDOff(LED5);
							STM_EVAL_LEDOff(LED6);
							h1=1;
						}
					}
					if(sw2)
					{
						if(h2==0)
						{
							MSD_SenCmd(12,4, 0);
							printf("Vi tri 12 Reset \n");
							STM_EVAL_LEDOff(LED4);
							STM_EVAL_LEDOn(LED5);
							STM_EVAL_LEDOff(LED6);
							h2=1;
						}
					}
					if(sw3)
					{
						if(h3==0)
						{
							MSD_SenCmd(13,4, 0);
							printf("Vi tri 13 Reset \n");
							STM_EVAL_LEDOn(LED4);
							STM_EVAL_LEDOn(LED5);
							STM_EVAL_LEDOff(LED6);
							h3=1;
						}
					}
					if(sw4)
					{
						if(h4==0)
						{
							MSD_SenCmd(14,4, 0);
							printf("Vi tri 14 Reset \n");
							STM_EVAL_LEDOff(LED4);
							STM_EVAL_LEDOff(LED5);
							STM_EVAL_LEDOn(LED6);
							h4=1;
						}
					}
					if(sw5)
					{
						if(h5==0)
						{
							MSD_SenCmd(15,4, 0);
							printf("Vi tri 15 Reset \n");
							STM_EVAL_LEDOn(LED4);
							STM_EVAL_LEDOff(LED5);
							STM_EVAL_LEDOn(LED6);
							h5=1;
						}
					}
					
					if(sw6)
					{
						if(h6==0)
						{
							MSD_SenCmd(16,4, 0);
							printf("Vi tri 16 Reset \n");
							STM_EVAL_LEDOff(LED4);
							STM_EVAL_LEDOff(LED5);
							STM_EVAL_LEDOn(LED6);
							h6=1;
						}
					}
				}
				printf("HOME!!! \n");
			}
// Lenh co-duoi visme 
// Ma lenh: 5-xx-data
// Vi du: Truyen cho visme khoang cach 23 => Frame: 5xx23
			else if(select==5)
			{
				mod=1;
				data=data%100;  // data = x4x5
				
				MSD_SenCmd(11,1, -1000*data);
				MSD_SenCmd(12,1, -1000*data);
				MSD_SenCmd(13,1, -1000*data);
				MSD_SenCmd(14,1, -1000*data);
				MSD_SenCmd(15,1, -1000*data);
				MSD_SenCmd(16,1, -1000*data);
				
				ViTri_Visme_Desire[0]=data+83;
				ViTri_Visme_Desire[1]=data+83;
				ViTri_Visme_Desire[2]=data+83;
				ViTri_Visme_Desire[3]=data+83;
				ViTri_Visme_Desire[4]=data+83;
				ViTri_Visme_Desire[5]=data+83;
				
				printf("Vi tri Visme: %d \n",data);
			}
// Lenh truyen data cho banh xe, chay nguoc chieu
// Ma lenh: 6-data
// Vi du: Truyen van toc -1234 => Frame: 61234
			else if(select==6)		// data = x2x3x4x5
			{
				MSD_SenCmd(1,2, -data);
				MSD_SenCmd(2,2, -data);
				MSD_SenCmd(3,2, -data);
				MSD_SenCmd(4,2, -data);
				MSD_SenCmd(5,2, -data);
				MSD_SenCmd(6,2, -data);
				printf("Van toc: %d \n",-data);
			}
		}
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
