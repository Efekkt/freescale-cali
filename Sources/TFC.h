/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef TFC_H_
#define TFC_H_

/* Librerias principales */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include "derivative.h" 

/* Microcontroller Abstraction Layer: MCL */
#include "MCL\arm_cm0.h"
#include "MCL\ARM_SysTick.h"
#include "MCL\CrystalClock.h"

/* System Drivers Abstraction Layer: SDL */
#include "SDL\ADC.h"
#include "SDL\BoardSupport.h"
#include "SDL\Motor.h"
#include "SDL\Potentiometer.h"
#include "SDL\Servo.h"
#include "SDL\Led_RGB.h"
#include "SDL\I2C.h"
#include "SDL\MMA8451.h"
#include "SDL\LineScanCamera.h"

#include "Config.h"
#include "SDL\Queue.h"
#include "SDL\UART.h"
#include "SDL\Terminal.h"

/* Application Abstraction Layer: APP */
#include "APP\Coeficientes.h"
#include "APP\Tasks.h"

void TFC_Task();
void TFC_Init();

#endif
