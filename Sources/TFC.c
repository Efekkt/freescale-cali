/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "TFC.h"

void TFC_Init()
{
InitClock(); 	/* Initialize clock system for 48 MHz */ 
InitSysTick(); 	/* Configure the timer and the interrupt to be used to generate the tick of the scheduler */
TFC_InitGPIO();
TFC_InitServos();
TFC_InitMotorPWM();
TFC_InitADCs();
TFC_InitLineScanCamera();
TFC_InitTerminal();
TFC_InitUARTs();

TFC_HBRIDGE_DISABLE;
TFC_SetMotorPWM(0,0);

TFC_RGB_Init();
TFC_Accel_Init();
}

void TFC_Task()
{
#if defined(TERMINAL_USE_SDA_SERIAL)
	TFC_UART_Process();
#endif

TFC_ProcessTerminal();
}
