/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef GPIO_H_
#define GPIO_H_

void TFC_RGB_Init(void);

#define pin(x)			1 << x

#define RED				(18)
#define RED_SHIFT		(1 << 18)
#define GREEN			(19)
#define GREEN_SHIFT		(1 << 19)
#define BLUE			(1)
#define BLUE_SHIFT		(1 << 1)

//Indicador
#define TFC_SEN    		(1<<9)

#define RED_OFF			(GPIOB_PSOR = RED_SHIFT)
#define RED_ON			(GPIOB_PCOR = RED_SHIFT)
#define RED_TOGGLE		(GPIOB_PTOR = RED_SHIFT)

#define GREEN_OFF		(GPIOB_PSOR = GREEN_SHIFT)
#define GREEN_ON		(GPIOB_PCOR = GREEN_SHIFT)
#define GREEN_TOGGLE	(GPIOB_PTOR = GREEN_SHIFT)

#define BLUE_OFF		(GPIOD_PSOR = BLUE_SHIFT)
#define BLUE_ON			(GPIOD_PCOR = BLUE_SHIFT)
#define BLUE_TOGGLE		(GPIOD_PTOR = BLUE_SHIFT)

//Indicador
#define INDICADOR_OFF		(GPIOC_PSOR = TFC_SEN)
#define INDICADOR_ON		(GPIOC_PCOR = TFC_SEN)
#define INDICADOR_TOGGLE	(GPIOC_PTOR = TFC_SEN)

#endif
