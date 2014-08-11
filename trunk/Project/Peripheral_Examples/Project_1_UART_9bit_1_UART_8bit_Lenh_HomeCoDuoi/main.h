/* Private function prototypes -----------------------------------------------*/
//void printf(uint16_t number, uint8_t motor);
#include <stm32f4xx.h>
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

#define Bx1 60
#define Bx2 20
#define Bx3 40
int MSD_SenCmd(u8 to,u8 cmd1, s32 data1);
void Delay(uint16_t n);
void lcd_print(uint16_t number, uint8_t line);

void Delay_us(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
