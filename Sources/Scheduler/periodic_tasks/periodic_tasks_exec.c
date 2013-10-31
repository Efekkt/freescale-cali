/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Este archivo contiene funciones periodicas.
 */

#include "periodic_tasks_exec.h"
#include "periodic_tasks_modules.h"


 /**************************************************************
 *  Name                 : periodic_tasks_exec_5tks
 *	ID					 : TASK_5TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_5tks(void)
{

}

 /**************************************************************
 *  Name                 : periodic_tasks_exec_10tks
 *	ID					 : TASK_10TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_10tks(void)
{

}
 
 /**************************************************************
 *  Name                 : periodic_tasks_exec_20tks
 *	ID					 : TASK_20TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_20tks(void)
{
//SeguirLineaCamara();
if(TFC_GetDIP_Switch()&0x01)
	Pruebas();
//else
	//SeguirLineaCamara();
}
 
 /**************************************************************
 *  Name                 : periodic_tasks_exec_50tks
 *	ID					 : TASK_50TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_50tks(void)
{
TFC_Task();
}

 /**************************************************************
 *  Name                 : periodic_tasks_exec_100tks
 *	ID					 : TASK_100TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_100tks(void)
{ 
//Opcion1();
//Opcion2();
//Opcion3();
if(TFC_GetDIP_Switch()&0x01)
	Opcion4();
}
 
 /**************************************************************
 *  Name                 : periodic_tasks_exec_500tks
 *	ID					 : TASK_500TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_500tks(void)
{
BLUE_TOGGLE;
//int i,j;
//i=(int)((TFC_ReadPot0()-1.0)*(-127.5));
//j=(int)((TFC_ReadPot1()-1.0)*(-127.5));
//TERMINAL_PRINTF("%d      %d   %d %d %d   %d      %d  -> %d . %d\r\n",TFC_SENSOR_1,TFC_SENSOR_2,TFC_SENSOR_3,TFC_SENSOR_4,TFC_SENSOR_5,TFC_SENSOR_6,TFC_SENSOR_7,i,j);	 
}
 
 /**************************************************************
 *  Name                 : periodic_tasks_exec_1Mtks
 *	ID					 : TASK_1MTKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 **************************************************************/
void periodic_tasks_exec_1Mtks(void)
{	 	 
VoltajeBateria();
RED_TOGGLE;
}
