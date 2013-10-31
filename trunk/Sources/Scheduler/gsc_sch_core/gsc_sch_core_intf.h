/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Interface of the gsc scheduler core
 * 
 * Comentarios: This header must be placed anywere scheduler is required.
 */

#ifndef GSC_SCH_CORE_INTF_H
#define GSC_SCH_CORE_INTF_H

#include "stdtypedef.h"

/* Functions prototypes */

/**************************************************************
 *  Name                 : gsc_sch_core_tick_isr
 *  Description          : This is the tick flag generation. This function must be 
                           called from a periodic high priority interrupt. The period
						   of this interrupt must define the "tick cycle time"
 *  Critical/explanation : No
 **************************************************************/
void gsc_sch_core_tick_isr(void);

/**************************************************************
 *  Name                 :  gsc_sch_core_Init
 *  Description          :  Init function of Scheduler module
 *  Precondition         :  This function must be called after cpu initialization.
 *  Postcondition        :  Function gsc_sch_core_exec can be called.
 **************************************************************/
void gsc_sch_core_Init(void);

/**************************************************************
 *  Name                 :  gsc_sch_core_exec
 *  Description          :  Main function of Scheduler module.
 *  Precondition         :  This function must be called after scheduler initialization.
 *  Postcondition        :  none.
 *  Critical/explanation :  This function contains an infite loop.
 **************************************************************/
void gsc_sch_core_exec(void);

#endif
