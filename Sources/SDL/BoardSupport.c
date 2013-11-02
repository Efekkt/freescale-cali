/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "..\TFC.h"

#define LED1	8
#define LED2	9
#define LED3	10
#define LED4	11
#define BIT_POSITION(x)	1<<(x)

//Set I/O for H-BRIDGE enables, switches and LEDs
void TFC_InitGPIO()
{
//Enable Clocks to all ports	
SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;

//Setup Pins as GPIO
PORTE_PCR21 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
PORTE_PCR20 = PORT_PCR_MUX(1);    

//Port for Pushbuttons
PORTC_PCR13 = PORT_PCR_MUX(1);   
PORTC_PCR17 = PORT_PCR_MUX(1);   

// Puertos para los sensores
PORTC_PCR0 = PORT_PCR_MUX(1);
PORTC_PCR5 = PORT_PCR_MUX(1);
PORTC_PCR6 = PORT_PCR_MUX(1);
PORTC_PCR7 = PORT_PCR_MUX(1);
PORTC_PCR8 = PORT_PCR_MUX(1);
PORTC_PCR9 = PORT_PCR_MUX(1);
PORTC_PCR10 = PORT_PCR_MUX(1);
PORTC_PCR11 = PORT_PCR_MUX(1);
PORTC_PCR12 = PORT_PCR_MUX(1);
PORTC_PCR16 = PORT_PCR_MUX(1);

//Ports for DIP Switches
PORTE_PCR2 = PORT_PCR_MUX(1); 
PORTE_PCR3 = PORT_PCR_MUX(1);
PORTE_PCR4 = PORT_PCR_MUX(1); 
PORTE_PCR5 = PORT_PCR_MUX(1);

//Ports for LEDs
PORTB_PCR8 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
PORTB_PCR9 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
PORTB_PCR10 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
PORTB_PCR11 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   

//Setup the output pins
GPIOE_PDDR =  TFC_HBRIDGE_EN_LOC;  
GPIOB_PDDR =  TFC_BAT_LED0_LOC	| TFC_BAT_LED1_LOC | TFC_BAT_LED2_LOC | TFC_BAT_LED3_LOC;

TFC_SetBatteryLED_Level(0);
TFC_HBRIDGE_DISABLE;
}

/***************************************************************
	 Valores Medidos
	 ADC	Voltaje
	 68	 	4.39v
	 79	 	5.10v
	 119	7.68v
	 131	8.45v
	 
	 99		>6.7v
	 92		6.2v
	 85		5.7v
	 77		5.2v
 ****************************************************************/
void TFC_SetBatteryLED_Level(uint8_t BattLevel)
{
switch(BattLevel)
	{	
	case 0:
		EstadoLed(LED1,0);
		EstadoLed(LED2,0);
		EstadoLed(LED3,0);
		EstadoLed(LED4,0);
		break;
	case 1:
		EstadoLed(LED1,1);
		EstadoLed(LED2,0);
		EstadoLed(LED3,0);
		EstadoLed(LED4,0);
		break;	
	case 2:
		EstadoLed(LED1,1);
		EstadoLed(LED2,1);
		EstadoLed(LED3,0);
		EstadoLed(LED4,0);
		break;	
	case 3:
		EstadoLed(LED1,1);
		EstadoLed(LED2,1);
		EstadoLed(LED3,1);
		EstadoLed(LED4,0);
		break;	
	case 4:
		EstadoLed(LED1,1);
		EstadoLed(LED2,1);
		EstadoLed(LED3,1);
		EstadoLed(LED4,1);
		break;	
	case 5:
		EstadoLed(LED1,1);
		EstadoLed(LED2,0);
		EstadoLed(LED3,0);
		EstadoLed(LED4,1);
		break;			
	}
}

void EstadoLed(int pin, int estado)
{
if(pin<32)
	{
	if(estado==1) GPIOB_PSOR=BIT_POSITION(pin);
	else if(estado==0) GPIOB_PCOR=BIT_POSITION(pin);
	}
}

uint8_t TFC_GetDIP_Switch()
{
uint8_t DIP_Val=0;
DIP_Val = (GPIOE_PDIR>>2) & 0xF;
return DIP_Val;
}
