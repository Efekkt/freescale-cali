/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "..\TFC.h"

void TFC_RGB_Init(void)
{
//	/* Turn on clock to PortB and PortD module */
//SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK;

PORTB_PCR18 = PORT_PCR_MUX(1); /* Set the PTB18 pin multiplexer to GPIO mode */		
GPIOB_PSOR |= RED_SHIFT; /* Set the initial output state to high */		
GPIOB_PDDR |= RED_SHIFT; /* Set the pins direction to output */

PORTB_PCR19 = PORT_PCR_MUX(1); /* Set the PTB19 pin multiplexer to GPIO mode */
GPIOB_PSOR |= GREEN_SHIFT; /* Set the initial output state to high */	
GPIOB_PDDR |= GREEN_SHIFT; /* Set the pins direction to output */

PORTD_PCR1 = PORT_PCR_MUX(1); /* Set the PTD1 pin multiplexer to GPIO mode */	
GPIOD_PSOR = BLUE_SHIFT; /* Set the initial output state to high */
GPIOD_PDDR |= BLUE_SHIFT; /* Set the pins direction to output */

//Indicador
PORTC_PCR9 = PORT_PCR_MUX(1); /* Set the PTC9 pin multiplexer to GPIO mode */	
GPIOC_PSOR = TFC_SEN; /* Set the initial output state to high */
GPIOC_PDDR |= TFC_SEN; /* Set the pins direction to output */
}
