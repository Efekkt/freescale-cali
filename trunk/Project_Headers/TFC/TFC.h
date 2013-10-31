/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef TFC_H_
#define TFC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "Derivative.h"

#include "TFC\ARM_SysTick.h"
#include "TFC\CrystalClock.h"

#include "TFC\TFC_Config.h"
#include "TFC\TFC_Types.h"
#include "TFC\TFC_arm_cm0.h"
#include "TFC\TFC_BoardSupport.h"
#include "TFC\TFC_Servo.h"
#include "TFC\TFC_Motor.h"
#include "TFC\TFC_ADC.h"
#include "TFC\TFC_Potentiometer.h"
#include "TFC\TFC_LineScanCamera.h"
#include "TFC\TFC_Queue.h"
#include "TFC\TFC_UART.h"
#include "TFC\TFC_Terminal.h"

#include "TFC\TFC_Led_RGB.h"
#include "TFC\TFC_I2C.h"
#include "TFC\TFC_MMA8451.h"

#include "TFC\TFC_Tasks.h"
#include "TFC\Coeficientes.h"

void TFC_Task();
void TFC_Init();

#endif
