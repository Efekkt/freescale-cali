/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Tick source file for the "Grandpa´s Clock Scheduler"
 * 
 * Comentarios: Tick generation source file
 */

#include "gsc_sch_core_tick_isr.h"
/* Custom type RAM variables */
	// Module execution flag
SCH_BOOLEAN re_sch_mngExecflag = SCH_FALSE;


 /**************************************************************
 *  Name                 : gsc_sch_core_tick_isr
 *  Description          : This is the tick flag generation. This function must be 
                           called from a periodic high priority interrupt. The period
						   of this interrupt must define the "tick cycle time"
 **************************************************************/
INLINE_FCT void gsc_sch_core_tick_isr (void)
{
/* Set flag so background will run */
re_sch_mngExecflag = SCH_TRUE;
}
