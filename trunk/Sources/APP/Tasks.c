/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "..\TFC.h"


/****************************************************************************************************************
*	Variables Globales. Usadas en las funciones
****************************************************************************************************************/
uint32_t t;
int LineaBase[130];


/*******************************************************************************************
*  Name                 : CapturarLineaBase
*  Description          : Esta funcion adquiere la primer imagen que captura la camara
*  						  para poder ser comparada con las demas
********************************************************************************************/
void CapturarLineaBase()
{
int i,j,muestras=10;
while(!TFC_PUSH_BUTTON_1_PRESSED); //Retardo. Presionar Boton B
for(i=0 ; i<muestras ; i++)
	{
	while(LineScanImageReady==0);
	for(j=0 ; j<128 ; j++) LineaBase[j]+=LineScanImage0[j];	
	}
for(j=0 ; j<128 ; j++) LineaBase[j]/=muestras;
GREEN_ON;
}


/*******************************************************************************************
*  Name                 : DetectarLinea
*  Description          : Esta funcion obtiene los valores de la camara, recorre los valores
*  						  y determina la maxima diferencia con respecto a 'LineaBase'
********************************************************************************************/
int pos=63;
void DetectarLinea()
{
//int j,ancho=10;
int rango=60;
int i,suma,minimo=0;
for(i=15 ; i<=112 ; i++)
	{
	if(LineaBase[i]>LineScanImage0[i])
		suma=LineaBase[i]-LineScanImage0[i];
	else
		suma=0;
	if(suma>minimo && suma>70)
		{
		if(i>=(pos-rango) && i<=(pos+rango))
			{
			minimo=suma;
			pos=i;
			}
		}
	}
}


/*******************************************************************************************
*  Name                 : SeguirLineaCamara
*  Description          : Esta funcion obtiene los valores de la camara, recorre los valores
*  						  y determina la maxima diferencia con respecto a 'LineaBase'
********************************************************************************************/
void SeguirLineaCamara()
{
if(LineScanImageReady==1)
	{
	LineScanImageReady=0;					 										 		
	if(TFC_PUSH_BUTTON_0_PRESSED) TFC_HBRIDGE_ENABLE;
	if(TFC_PUSH_BUTTON_1_PRESSED) TFC_HBRIDGE_DISABLE;	
	
	DetectarLinea();
	TFC_SetServo(0,(float)((pos/63.5)-1.0));
	//TFC_SetServo(0,(float)(((pos-15)/48.5)-1.0));		
	
	if(pos>44 && pos<83)
		TFC_SetMotorPWM(TFC_ReadPot1(),TFC_ReadPot1());
	else 
		TFC_SetMotorPWM(TFC_ReadPot1()-0.1,TFC_ReadPot1()-0.1);
	}
}


/*******************************************************************************************
*  Name                 : VoltajeBateria
*  Description          : Esta funcion lee el ADC que se encuentra conectado a la Bateria, 
*  						  de acuerdo a su valor, prende una serie de LEDs 
********************************************************************************************/
void VoltajeBateria()
{
int bateria = BatSenseADC_Value,nivel=1;

if(bateria>=125)		nivel=4;	//Mayor de 8.0 volts
else if(bateria>=121)	nivel=3;	//Mayor de 7.8 volts
else if(bateria>=117)	nivel=2;	//Mayor de 7.6 volts 
else if(bateria>=114)	nivel=1;	//Mayor de 7.4 volts
else if(bateria>=99)	nivel=0;	//Mayor de 6.7 volts
//else if(bateria>=92) 	nivel=0;	//Mayor de 6.2 volts
//else if(bateria>=85) 	nivel=0;	//Mayor de 5.7 volts
//else if(bateria>=77) 	nivel=0;	//Mayor de 5.2 volts
else					nivel=5;	//Menor de 5.2 volts

//TERMINAL_PRINTF("Bat:%d  Nivel:%d\r\n",bateria,nivel);
TFC_SetBatteryLED_Level(nivel);
}


/*******************************************************************************************
*  Name                 : Pruebas
*  Description          : Esta funcion es para realizar pruebas
********************************************************************************************/
void Pruebas()
{
int indice_vector,p;
float a,b;
if(LineScanImageReady==1)
	{
	LineScanImageReady=0;
	
	DetectarLinea(); //Se obtiene pos con valores de [15-112]
	p=pos-15; //Se ajusta pos a valores de [0-97]
	
	////TERMINAL_PRINTF("*Pos:%d ",p);
	
	/* Si [0==0000 && 97==1000] then Se tienen aumentos de [1000/97=10.30927835], representa el indice del vector */
	indice_vector=(int)((1000.0/97.0)*p);
	
	/*	Para el vector de 'servomotor', los rangos son [0.000,1.000], X es algun punto, PuntoMedio=0.500
	Si X es menor a PM then izquierda: Val=X-PM
	else derecha: Val=PM-X	*/
	
	////TERMINAL_PRINTF("Indice:%d  Servomotor:[%d]",indice_vector,servomotor[indice_vector]);
	
	TFC_SetServo(0,servomotor[indice_vector]/1000.0);
	////TERMINAL_PRINTF(" : %d\n\r",(int)(((servomotor[indice_vector]/1000.0)-0.5)*1000));
	
	if(TFC_PUSH_BUTTON_0_PRESSED) TFC_HBRIDGE_ENABLE;
	if(TFC_PUSH_BUTTON_1_PRESSED) TFC_HBRIDGE_DISABLE;
	
	a=motor_izquierdo[indice_vector]/1000.0;
	b=motor_derecho[indice_vector]/1000.0;	
	
	if(a>TFC_ReadPot1()) a=TFC_ReadPot1();
	if(b>TFC_ReadPot1()) b=TFC_ReadPot1();
	
	TFC_SetMotorPWM(a,b);	
	}
}


/* Funcion sin usar */
void SeguirLineaQRD1114()
{
if(TFC_SENSOR_1 && TFC_SENSOR_2 && TFC_SENSOR_3 && TFC_SENSOR_4 && TFC_SENSOR_5 && TFC_SENSOR_6 && TFC_SENSOR_7)	
	TFC_SetServo(0,0);			
}


/* Tests the switches and LEDs */
void Opcion1()
{
if(TFC_PUSH_BUTTON_0_PRESSED)
	TFC_BAT_LED0_ON;									
else
	TFC_BAT_LED0_OFF;

if(TFC_PUSH_BUTTON_1_PRESSED)
	TFC_BAT_LED3_ON;
else
	TFC_BAT_LED3_OFF;

if(TFC_GetDIP_Switch()&0x01)
	TFC_BAT_LED1_ON;
else
	TFC_BAT_LED1_OFF;

if(TFC_GetDIP_Switch()&0x08)
	TFC_BAT_LED2_ON;
else
	TFC_BAT_LED2_OFF;					
}


/* Move the servos with the potentiometers */ 
// NOTA: Tiempo minimo de 20mS
void Opcion2()
{
//Every 20 mSeconds, update the Servos
float x;
x=TFC_ReadPot0();
TFC_SetServo(0,x);
////TERMINAL_PRINTF("Servomotor: %d\n\r",(int)(x*10000.0));

//Make sure motors are off
TFC_SetMotorPWM(0,0);
TFC_HBRIDGE_DISABLE;
}


void Opcion4()
{
//Demo Mode 3 will be in Freescale Garage Mode.  It will beam data from the Camera to the 
//Labview Application				
int i;
if(LineScanImageReady==1)
	{	
	LineScanImageReady=0;					 										 		
	if(TFC_PUSH_BUTTON_0_PRESSED) TFC_HBRIDGE_ENABLE;
	if(TFC_PUSH_BUTTON_1_PRESSED) TFC_HBRIDGE_DISABLE;

	DetectarLinea();
	TFC_SetServo(0,(float)((pos/63.5)-1.0));	
	TFC_SetMotorPWM(TFC_ReadPot1(),TFC_ReadPot1());	
	
	TERMINAL_PRINTF("\r\n");
	TERMINAL_PRINTF("L:");	
	for(i=0;i<128;i++)
		{
		if(i==0) 							 
			TERMINAL_PRINTF("%X,",pos);
		else
			TERMINAL_PRINTF("%X,",LineScanImage0[i]);
		}
	
	for(i=0;i<128;i++)
		{	
		TERMINAL_PRINTF("%X",LineaBase[i]);
		if(i==127)
			TERMINAL_PRINTF("\r\n",LineaBase[i]);
		else
			TERMINAL_PRINTF(",",LineaBase[i]);
		}
	}	
}
