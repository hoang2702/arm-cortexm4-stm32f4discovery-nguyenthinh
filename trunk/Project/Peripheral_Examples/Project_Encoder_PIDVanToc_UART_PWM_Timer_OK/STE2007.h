
#include "stm32f4xx.h"
//*****************************************************************************				// 
// Pin configuration for ARM M3

// #define LCD_PIN_TYPE_OUTPUT	GPIO_Mode_Out_PP;

// #define LCD_SCE_LOW			GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(0))
// #define LCD_SCE_HIGH		GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(1))

// #define LCD_RESET_LOW		GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(0))
// #define LCD_RESET_HIGH	GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(1))

// #define LCD_SDIN_HIGH		GPIO_WriteBit(GPIOB, GPIO_Pin_10, (BitAction)(1))
// #define LCD_SDIN_LOW		GPIO_WriteBit(GPIOB, GPIO_Pin_10, (BitAction)(0))

// #define LCD_SCL_HIGH		GPIO_WriteBit(GPIOB, GPIO_Pin_11, (BitAction)(1))
// #define LCD_SCL_LOW			GPIO_WriteBit(GPIOB, GPIO_Pin_11, (BitAction)(0))
//*****************************************************************************				// 
// Pin configuration for ARM M4


#define LCD_SCE_HIGH			GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define LCD_SCE_LOW		GPIO_ResetBits(GPIOB, GPIO_Pin_12)

#define LCD_RESET_HIGH		GPIO_SetBits(GPIOB, GPIO_Pin_13)
#define LCD_RESET_LOW	GPIO_ResetBits(GPIOB, GPIO_Pin_13)

#define LCD_SDIN_HIGH		GPIO_SetBits(GPIOB, GPIO_Pin_14)
#define LCD_SDIN_LOW		GPIO_ResetBits(GPIOB, GPIO_Pin_14)

#define LCD_SCL_HIGH		GPIO_SetBits(GPIOB, GPIO_Pin_15)
#define LCD_SCL_LOW			GPIO_ResetBits(GPIOB, GPIO_Pin_15)
//*****************************************************************************				// 
// Pin configuration for PIC16F877A
/*
#define LCD_PIN_TYPE_OUTPUT	TRISD=0x00

#define LCD_SCE_LOW			RD0=0
#define LCD_SCE_HIGH		RD0=1

#define LCD_RESET_LOW		RD1=0
#define LCD_RESET_HIGH	    RD1=1

#define LCD_SDIN_HIGH		RD2=1
#define LCD_SDIN_LOW		RD2=0

#define LCD_SCL_HIGH		RD3=1
#define LCD_SCL_LOW			RD3=0

#define LCD_CONTRAST 		(15)
*/
//*****************************************************************************
// FUNTION HEADERS
//*****************************************************************************
void lcd_Init_HaW(void);
void lcd_write(char dc, char byte);
void lcd_init(void);
void lcd_refresh(void);
void lcd_clear(void);
void lcd_gotoxy(unsigned char col, unsigned char row);
void lcd_normal(void);
void lcd_all(void);
void lcd_contrast(unsigned char value);
void lcd_putc(char c);
void lcd_puts(char *s);
void lcd_start_line(unsigned char line);
void lcd_delay(int cycles);
void lcd_invert(unsigned char on_off);
void lcd_str_center(char *str);
void lcd_goto_x(unsigned char col);
void lcd_segment_direction(unsigned char reverse);
void lcd_column_direction(unsigned char reverse);
//void lcd_inverse_N_line(unsigned char line);
void lcd_display_all(unsigned char value);
//void lcd_number_line(unsigned char num_line);
//unsigned char lcd_read_ID(void);
//void lcd_imag(int *imag);
//lcd_big(unsigned char col, unsigned char row, char ch);
void lcd_bigC(int row, int col,char c);

//*****************************************************************************
// COMMAND LIST
//*****************************************************************************
#define LCD_CONTRAST    15
//#define LCD_RESET_CYCLES		(CPU_CLOCK_MHZ*200)

#define FLAG_CMD				(0x00)
#define FLAG_DATA				(0x01)

#define ON						(0x0F)
#define OFF						(0x0E)
#define ALL						(0x05)
#define NORMAL					(0x06)
#define INVERT					(0x07)
#define DISPLAY 				(0x04)

#define LCD_NOP 				(0xE3)
#define LCD_MODE 				(0xA0)
#define LCD_VOB_MSB 			(0x20)
#define LCD_VOB_LSB 			(0x80)
#define LCD_CHARGE_PUMP_ON		(0x2F)
#define LCD_RAM_ADDR_VER_MODE	(0xAB)
#define LCD_RAM_ADDR_HOR_MODE	(0xAA)
#define LCD_CHANGE_COL_LSB 		(0x00)
#define LCD_CHANGE_COL_MSB		(0x10)
#define LCD_CHANGE_ROW 			(0xB0)
#define LCD_MIRROR_Y			(0xC8)
#define LCD_MIRROR_X 			(0xA0)
#define LCD_EXT_OSC 			(0x3A)
#define LCD_SOFT_RESET 			(0xE2)


