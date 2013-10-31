/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Header of the tick source file for the "Grandpa´s Clock Scheduler"
 * 
 * Comentarios: Header of the tick source file
 */

#ifndef GSC_SCH_CORE_TICK_ISR_H
#define GSC_SCH_CORE_TICK_ISR_H

#include "stdtypedef.h"
#include "gsc_sch_core.h"

/* Custom type RAM variables */
	// Module execution flag is set in timer interrupt handler
PUBLIC_DATA SCH_BOOLEAN re_sch_mngExecflag;

/* Functions prototypes */
void gsc_sch_core_tick_isr(void);

#endif
