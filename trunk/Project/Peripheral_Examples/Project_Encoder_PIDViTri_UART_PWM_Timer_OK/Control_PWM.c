

#include "Control_PWM.h"

/*----------------------------------
Sets the TIMx duty cycle. 

Parameters:
timer	   : can be 1, 2, 3, 4, 5 or 8, 9, 10, 11, 12, 13, 14, to select the TIM peripheral.  
channel  : specifies the channel of timer, can be: 1, 2, 3 or 4 
	@Note  : timer 1, 2, 3, 4, 5 or 8   have 4 channel 
				   timer 9, 11 								have 2 channel
				   timer 10, 12, 13, 14 			have 1 channel
duty     : specifies value of duty cycle, any number from 0 to 100
frequency: specifies the frequency of PWM, unit KHz. 
 @Exampel: you need 20KHZ, you must write 20 instead of 20000

Return values:
None  
---------------------------------------------*/
void Set_DutyCycle(uint8_t timer, uint8_t channel, uint8_t duty, uint16_t frequency){ // duty tinh bang %, vi du: 50% thi ghi la 50
	uint32_t CCR, ARR;											// tan so tinh bang KHz, vi du: 20KHz thi ghi la 20
	if (frequency==0)												// mac dinh ban dau frequency = 30KHz, tuc la tan so 30KHz neu truyen gia tri ARR=0
		frequency=30;
	ARR = (42000000/(frequency*1000)) - 1 ;
	if ((timer == 1) | (timer == 8))
		CCR = (uint32_t) (((uint32_t) duty * (ARR - 1)) / 100);
	else
		CCR = (uint32_t) (((uint32_t) duty * ARR ) / 100);
	switch (timer){
		case 1:
			if (channel==1)
				TIM_SetCompare1(TIM1, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM1, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM1, CCR) ;
			else
				TIM_SetCompare4(TIM1, CCR) ;
			break;
		case 2:
			if (channel==1)
				TIM_SetCompare1(TIM2, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM2, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM2, CCR) ;
			else
				TIM_SetCompare4(TIM2, CCR) ;
			break;
		case 3:
			if (channel==1)
				TIM_SetCompare1(TIM3, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM3, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM3, CCR) ;
			else
				TIM_SetCompare4(TIM3, CCR) ;
			break;
		case 4:
			if (channel==1)
				TIM_SetCompare1(TIM4, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM4, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM4, CCR) ;
			else
				TIM_SetCompare4(TIM4, CCR) ;
			break;
		case 5:
			if (channel==1)
				TIM_SetCompare1(TIM5, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM5, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM5, CCR) ;
			else
				TIM_SetCompare4(TIM5, CCR) ;
			break;
		case 8:
			if (channel==1)
				TIM_SetCompare1(TIM8, CCR) ;
			else if (channel==2)
				TIM_SetCompare2(TIM8, CCR) ;
			else if (channel==3)
				TIM_SetCompare3(TIM8, CCR) ;
			else
				TIM_SetCompare4(TIM8, CCR) ;
			break;
		case 9:
			if (channel==1)
				TIM_SetCompare1(TIM9, CCR) ;
			else
				TIM_SetCompare2(TIM9, CCR) ;
			break;
		case 10:
			TIM_SetCompare1(TIM10, CCR) ;
			break;
		case 11:
			TIM_SetCompare1(TIM11, CCR) ;
			break;
		case 12:
			if (channel==1)
				TIM_SetCompare1(TIM12, CCR) ;
			else
				TIM_SetCompare2(TIM12, CCR) ;
			break;
		case 13:
			TIM_SetCompare1(TIM13, CCR) ;
			break;
		case 14:
			TIM_SetCompare1(TIM14, CCR) ;
			break;
	}

}
/*----------------------------------
Sets the TIMx frequency. 

Parameters:
timer	   : can be 1, 2, 3, 4, 5 or 8, 9, 10, 11, 12, 13, 14, to select the TIM peripheral.  
frequency: specifies the frequency of PWM, unit KHz. 
 @Exampel: you need 20KHZ, you write 20 instead of 20000
 @Note: the value 42000000 is timer counter clock, which is defaut value, if you want to
				change it, must see in "GPIO_Config.c" file.
				Defaut frequency is 30KHz

Return values:
None  
---------------------------------------------*/
void Set_Frequency(uint16_t timer, uint16_t frequency){   // tan so tinh bang KHz, vi du: 20KHz thi ghi la 20
	uint32_t ARR = (42000000/(frequency*1000)) - 1 ;
	switch (timer){
		case 1:
			TIM_SetAutoreload( TIM1, ARR) ;
			break;
		case 2:
			TIM_SetAutoreload( TIM2, ARR) ;
			break;
		case 3:
			TIM_SetAutoreload( TIM3, ARR) ;
			break;
		case 4:
			TIM_SetAutoreload( TIM4, ARR) ;
			break;
		case 5:
			TIM_SetAutoreload( TIM5, ARR) ;
			break;
		case 8:
			TIM_SetAutoreload( TIM8, ARR) ;
			break;
		case 9:
			TIM_SetAutoreload( TIM9, ARR) ;
			break;
		case 10:
			TIM_SetAutoreload( TIM10, ARR) ;
			break;
		case 11:
			TIM_SetAutoreload( TIM11, ARR) ;
			break;
		case 12:
			TIM_SetAutoreload( TIM12, ARR) ;
			break;
		case 13:
			TIM_SetAutoreload( TIM13, ARR) ;
			break;
		case 14:
			TIM_SetAutoreload( TIM14, ARR) ;
			break;
	}
}
