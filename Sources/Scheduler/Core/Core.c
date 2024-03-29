/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 *
 * Descripcion: Core of the "Grandpa�s Clock Scheduler"
 * 
 * Comentarios: Main scheduler file with initailization and manager
 */

#include "Core.h"
#include "Core_Config.h"
#include "Core_Tick_ISR.h"

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* Custom type RAM variables */
    // rt_curOpMode stores the current mode of operation of the system
T_OpModeType  rt_curOpMode; 


/* Exported functions */

/**************************************************************
 *  Name                 :  gsc_sch_core_Init
 *  Description          :  Init function of Scheduler module
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  This function must be called after cpu initialization.
 *  Postcondition        :  Function gsc_sch_core_exec can be called.
 **************************************************************/
void gsc_sch_core_Init(void)
{
E_MODULES_ID_TYPE le_mngIndex;

/* clear timer interrupt flag */
re_sch_mngExecflag = SCH_FALSE;

/* Disable Interrupt */
gsc_sch_disable_interrupts_cb();

/* Call Init function of modules */
for (le_mngIndex = (E_MODULES_ID_TYPE)0; le_mngIndex < SCHD_MANAGERS_NUMBER; le_mngIndex++)
	{ 
	if (cps_mngTaskList[le_mngIndex].ManagerInitAPI != SCHM_NULL_PTR)
		{
		cps_mngTaskList[le_mngIndex].ManagerInitAPI();    
		}
	}

gsc_sch_interrupts_init_cfg_cb();

/* Enable Interrupt */
gsc_sch_enable_interrupts_cb();

rt_curOpMode = NORMAL_MODE;
}


/**************************************************************
 *  Name                 :  gsc_sch_core_exec
 *  Description          :  Main function of Scheduler module.
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  This function must be called after scheduler initialization.
 *  Postcondition        :  none.
 *  Critical/explanation :  This function contains an infite loop.
 **************************************************************/
void gsc_sch_core_exec(void)
{
E_MODULES_ID_TYPE le_mngIndex;
T_DelayMainType lasw_MngTimeCnt[SCHD_MANAGERS_NUMBER];    

/* Initialization of local modules counters to delay of module execution from Scheduler start */
for (le_mngIndex = (E_MODULES_ID_TYPE)0; le_mngIndex < SCHD_MANAGERS_NUMBER; le_mngIndex++)
	{
	lasw_MngTimeCnt[le_mngIndex] = (T_DelayMainType)cps_mngTaskList[le_mngIndex].StartUpDelay;    
	}  

do
	{
	/* wait for timer interrupt */
	if (re_sch_mngExecflag)
		{
		/* clear timer interrupt flag */
		re_sch_mngExecflag = SCH_FALSE;
		/* check each module from the list of modules */
		for (le_mngIndex = (E_MODULES_ID_TYPE)0; le_mngIndex < SCHD_MANAGERS_NUMBER; le_mngIndex++)
			{
			if (cps_mngTaskList[le_mngIndex].ManagerAPI != SCHM_NULL_PTR)
				{
				/* decrement the local counter of modules  */
				lasw_MngTimeCnt[le_mngIndex] -= STEP_IN_TICKS;    
				/* check whether counter is expired */
				if (lasw_MngTimeCnt[le_mngIndex] <= 0)
					{
					/* set the local module counter */
					lasw_MngTimeCnt[le_mngIndex] = (T_DelayMainType)cps_mngTaskList[le_mngIndex].ExecutionPeriod;
					/* check whether the module starts for the currecnt Mode */
					if (0 != (cps_mngTaskList[le_mngIndex].UsedInMode & rt_curOpMode))
						{
						cps_mngTaskList[le_mngIndex].ManagerAPI();    
						}
					}
				}
			}  
		}
	} while (SCH_TRUE);
}
