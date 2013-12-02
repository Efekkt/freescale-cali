/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef TFC_TASKS_H_
#define TFC_TASKS_H_

void CapturarLineaBase(void);

void DetectarLinea(void);
void BinarizarImagen(void);
int HayLinea(int);

void ControlDifuso(void);
void VelocidadMotor(void);

void ControlLineal(void);

void VoltajeBateria(void);
void GraficarLabVIEW(void);

extern int pos;

#endif
