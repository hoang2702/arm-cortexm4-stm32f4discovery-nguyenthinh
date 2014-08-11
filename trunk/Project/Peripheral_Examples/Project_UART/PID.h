/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PID_H
#define __PID_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
void PID_speed(uint16_t desire_speed);

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM324xG_EVAL_H */
