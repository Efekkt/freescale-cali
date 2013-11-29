/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef TFC_TASKS_H_
#define TFC_TASKS_H_

void CapturarLineaBase(void);

void DetectarLinea(void);
int HayDepresion(int);

void ControlDifuso(void);
void VelocidadMotor(void);

void ControlLineal(void);

void VoltajeBateria(void);
void GraficarLabVIEW(void);

extern int pos;
extern int META1,META3;

#endif
