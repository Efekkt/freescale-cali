/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Header of the configuartion file of the "Grandpa´s Clock Scheduler" core
 * 
 * Comentarios: Header of the configurationfor the scheduler
 */

#ifndef GSC_SCH_CORE_CFG_H
#define GSC_SCH_CORE_CFG_H

#include "stdtypedef.h"
#include "gsc_sch_core.h"

typedef enum {
    /* Add here the IDs Tasks, order them same to Manager/Aplication main function list */
    TASK_INIT,
    TASK_SYSIN,
    TASK_5TKS, 
    TASK_10TKS,
    TASK_20TKS,
    TASK_50TKS,
    TASK_100TKS,
    TASK_500TKS,
    TASK_1MTKS,
    /* Number of Managers/Applications */
    SCHD_MANAGERS_NUMBER
} E_MODULES_ID_TYPE;


/* LONG and STRUCTURE constants */
	/* Managers/Application main function List */
PUBLIC_DATA const S_SCH_MANAGER_EXEC_TYPE cps_mngTaskList[SCHD_MANAGERS_NUMBER]; 

/* Operational Modes of the system */
#define ALL_MODES (T_OpModeType)0xFFFF
#define NORMAL_MODE (T_OpModeType)0x0001

/* This callback must be used to disable interrupts */
#define gsc_sch_disable_interrupts_cb() /* Put here the function of the platform used to disable interrupts */

/* This callback must be used to initialize and configure interrupts */
#define gsc_sch_interrupts_init_cfg_cb() /* Put here the function of the platform used to initialize and configure interrupts */

/* This callback must be used to enable interrupts */
#define gsc_sch_enable_interrupts_cb() /* Put here the function of the platform used to enable interrupts */

#endif
