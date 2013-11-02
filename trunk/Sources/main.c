/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "TFC.h"
#include "Scheduler\Core\Core_Intf.h"

volatile unsigned int sys_tick_counter = 0;

void WatchDog_cfg(void);

int main (void)
{
WatchDog_cfg();			/* Disable Watch Dog */
TFC_Init();				/* Inicializa todos los perifericos */
CapturarLineaBase();	/* Espera hasta que se capture la imagen base */
gsc_sch_core_Init();	/* Scheduler Initialization and tasks initialization  */
gsc_sch_core_exec();	/* Execute Scheduler */
return 0;
}

//Init watch dog
void WatchDog_cfg(void)
{
/* Disable watch dog */
SIM_COPC |= SIM_COPC_COPT(0);
}

void SysTick_Handler(void)
{
sys_tick_counter++;
gsc_sch_core_tick_isr();
}
