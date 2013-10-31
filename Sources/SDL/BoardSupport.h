/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include <stdint.h>

#ifndef TFC_BOARDSUPPORT_H_
#define TFC_BOARDSUPPORT_H_

#define TFC_HBRIDGE_EN_LOC			(uint32_t)(1<<21)
#define TFC_HBRIDGE_FAULT_LOC     	(uint32_t)(1<<20)

#define TFC_HBRIDGE_ENABLE			GPIOE_PSOR = TFC_HBRIDGE_EN_LOC	
#define TFC_HBRIDGE_DISABLE			GPIOE_PCOR = TFC_HBRIDGE_EN_LOC	

#define TFC_DIP_SWITCH0_LOC			((uint32_t)(1<<2))
#define TFC_DIP_SWITCH1_LOC			((uint32_t)(1<<3))
#define TFC_DIP_SWITCH2_LOC			((uint32_t)(1<<4))
#define TFC_DIP_SWITCH3_LOC			((uint32_t)(1<<5))

#define TFC_PUSH_BUTT0N0_LOC		((uint32_t)(1<<13))
#define TFC_PUSH_BUTT0N1_LOC		((uint32_t)(1<<17))	

#define TFC_BAT_LED0_LOC			((uint32_t)(1<<8))
#define TFC_BAT_LED1_LOC			((uint32_t)(1<<9))
#define TFC_BAT_LED2_LOC			((uint32_t)(1<<10))
#define TFC_BAT_LED3_LOC			((uint32_t)(1<<11))

#define TFC_BAT_LED0_ON				GPIOB_PSOR = TFC_BAT_LED0_LOC
#define TFC_BAT_LED1_ON				GPIOB_PSOR = TFC_BAT_LED1_LOC
#define TFC_BAT_LED2_ON				GPIOB_PSOR = TFC_BAT_LED2_LOC
#define TFC_BAT_LED3_ON				GPIOB_PSOR = TFC_BAT_LED3_LOC

#define TFC_BAT_LED0_OFF			GPIOB_PCOR = TFC_BAT_LED0_LOC
#define TFC_BAT_LED1_OFF			GPIOB_PCOR = TFC_BAT_LED1_LOC
#define TFC_BAT_LED2_OFF			GPIOB_PCOR = TFC_BAT_LED2_LOC
#define TFC_BAT_LED3_OFF			GPIOB_PCOR = TFC_BAT_LED3_LOC

#define TFC_BAT_LED0_TOGGLE			GPIOB_PTOR = TFC_BAT_LED0_LOC
#define TFC_BAT_LED1_TOGGLE			GPIOB_PTOR = TFC_BAT_LED1_LOC
#define TFC_BAT_LED2_TOGGLE			GPIOB_PTOR = TFC_BAT_LED2_LOC
#define TFC_BAT_LED3_TOGGLE			GPIOB_PTOR = TFC_BAT_LED3_LOC

#define TFC_PUSH_BUTTON_0_PRESSED	((GPIOC_PDIR&TFC_PUSH_BUTT0N0_LOC)>0)
#define TFC_PUSH_BUTTON_1_PRESSED	((GPIOC_PDIR&TFC_PUSH_BUTT0N1_LOC)>0)

//Sensores QRD1114
#define TFC_SENSOR_1_PIN    			((uint32_t)(1<<7))
#define TFC_SENSOR_2_PIN    			((uint32_t)(1<<0))
#define TFC_SENSOR_3_PIN    			((uint32_t)(1<<5))
#define TFC_SENSOR_4_PIN    			((uint32_t)(1<<6))
#define TFC_SENSOR_5_PIN    			((uint32_t)(1<<10))
#define TFC_SENSOR_6_PIN    			((uint32_t)(1<<11))
#define TFC_SENSOR_7_PIN    			((uint32_t)(1<<12))
#define TFC_SENSOR_8_PIN    			((uint32_t)(1<<16))
//#define TFC_SENSOR_9_PIN    			((uint32_t)(1<<8))
//#define TFC_SENSOR_10_PIN    			((uint32_t)(1<<9))

#define TFC_SENSOR_1		!((GPIOC_PDIR&TFC_SENSOR_1_PIN)>0)
#define TFC_SENSOR_2		!((GPIOC_PDIR&TFC_SENSOR_2_PIN)>0)
#define TFC_SENSOR_3		!((GPIOC_PDIR&TFC_SENSOR_3_PIN)>0)
#define TFC_SENSOR_4		!((GPIOC_PDIR&TFC_SENSOR_4_PIN)>0)
#define TFC_SENSOR_5		!((GPIOC_PDIR&TFC_SENSOR_5_PIN)>0)
#define TFC_SENSOR_6		!((GPIOC_PDIR&TFC_SENSOR_6_PIN)>0)
#define TFC_SENSOR_7		!((GPIOC_PDIR&TFC_SENSOR_7_PIN)>0)
#define TFC_SENSOR_8		!((GPIOC_PDIR&TFC_SENSOR_8_PIN)>0)

void    TFC_InitGPIO();
void    TFC_SetBatteryLED_Level(uint8_t BattLevel);
uint8_t TFC_GetDIP_Switch();

#endif
