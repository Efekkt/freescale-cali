/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Este archivo contiene funciones periodicas.
 */

#include "Periodic_Tasks.h"
#include "Periodic_Tasks_Modules.h"


void periodic_tasks_exec_5tks(void)
{
DetectarLinea();
VelocidadMotor();
}


void periodic_tasks_exec_10tks(void)
{

}
 

/*******************************************************************************************
*  Name                 : periodic_tasks_exec_20tks
*  Description          : Esta funcion se ejecuta cada 20mS
*  						  Es la funcion donde se encuentra el control
********************************************************************************************/
void periodic_tasks_exec_20tks(void)
{
int sel=0;
if(TFC_GetDIP_Switch()&0x01) sel+=1;
if(TFC_GetDIP_Switch()&0x02) sel+=2;
if(TFC_GetDIP_Switch()&0x04) sel+=4;
if(TFC_GetDIP_Switch()&0x08) sel+=8;

if(TFC_PUSH_BUTTON_0_PRESSED) TFC_HBRIDGE_ENABLE;
if(TFC_PUSH_BUTTON_1_PRESSED) TFC_HBRIDGE_DISABLE;

Centro=TFC_ReadPot0()/8.0;

//Controles para el servomotor
ControlDifuso();
if(sel==3) ControlLineal();
}
 

void periodic_tasks_exec_50tks(void)
{
TFC_Task();
}


/*******************************************************************************************
*  Name                 : periodic_tasks_exec_100tks
*  Description          : Esta funcion se ejecuta cada 100mS
*  						  Manda valores a LabVIEW para mostrar la grafica
********************************************************************************************/
void periodic_tasks_exec_100tks(void)
{
int sel=0;
if(TFC_GetDIP_Switch()&0x01) sel+=1;
if(TFC_GetDIP_Switch()&0x02) sel+=2;
if(TFC_GetDIP_Switch()&0x04) sel+=4;
if(TFC_GetDIP_Switch()&0x08) sel+=8;

if(sel==4 || sel==12) GraficarLabVIEW();
}
 

void periodic_tasks_exec_500tks(void)
{
	 
}
 

void periodic_tasks_exec_1Mtks(void)
{	 	 
VoltajeBateria();
RED_TOGGLE;
}
