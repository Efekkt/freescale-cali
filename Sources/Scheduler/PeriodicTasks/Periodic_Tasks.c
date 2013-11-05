/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Este archivo contiene funciones periodicas.
 */

#include "Periodic_Tasks.h"
#include "Periodic_Tasks_Modules.h"


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
(TFC_GetDIP_Switch()&0x01) ? Pruebas() : SeguirLineaCamara();
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
//Opcion4();
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
