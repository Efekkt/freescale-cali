/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: This file contains the prototypes functions to initialize the periodic tasks
 * 
 * Comentarios: Main header for periodic_task_init module
 */

#ifndef PERIODIC_TASKS_INIT_H
#define PERIODIC_TASKS_INIT_H

//#include "stdtypedef.h"

/* Exported functions prototypes and macros */
void periodic_tasks_init_MclDrvs(void);
void periodic_tasks_init_SysDrvs(void);
void periodic_tasks_init_task_5tks(void);
void periodic_tasks_init_task_10tks(void);
void periodic_tasks_init_task_20tks(void);
void periodic_tasks_init_task_50tks(void);
void periodic_tasks_init_task_100tks(void);
void periodic_tasks_init_task_500tks(void);
void periodic_tasks_init_task_1Mtks(void);

#endif
