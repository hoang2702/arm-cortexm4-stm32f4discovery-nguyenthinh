#include "PID.h"
#include "Encoder_Interface.h"
#include "stm32f4_discovery.h"
#include <stdio.h>
//======= Define =================
#define Kp 15  //5.01
#define Kd 0.2  //0.01
#define Ki 1  //0.5
int16_t count=0, speed;
//PID myPID;
//======= Gloable variables ======

extern 	uint16_t  Resolution;
extern	uint16_t Sample_time;  // so lan lay mau trong 1s
//======= Private variables ======
volatile int16_t Out = 0;
volatile int16_t Speed_des = 10;
volatile int16_t Pre_Err = 0;
volatile int16_t Err=0;
volatile int16_t pP=0;
volatile int16_t dP = 0;
volatile float iP = 0;
//<==============================//
// PID
void PID_speed(uint16_t desire_speed)
{
		puts("vao pid");
	 count = encodersRead();
	 printf("count = %d   :",count);
   Err = desire_speed-count;
   pP = (int16_t)(Kp*Err);
   dP = Kd*(Err - Pre_Err)*Sample_time;
   iP = iP + 0.5*Err/Sample_time;
   Out += (int16_t)(pP+dP+iP);
   printf("Err = %d   :",Err);
   if (Out>=1400)
      Out = 1400;
   if (Out<=0)
      Out = 0; 
	
   TIM_SetCompare1(TIM1, Out) ;
   STM_EVAL_LEDOn(LED3);
   //printf("count = %ld   :",count);
   //printf("Out = %ld \n\r",Out);
   Pre_Err = Err;
}
