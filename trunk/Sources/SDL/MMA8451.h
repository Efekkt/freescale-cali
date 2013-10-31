/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#ifndef MMA8451_H_
#define MMA8451_H_

#define MMA8451_I2C_ADDRESS (0x1d<<1)
#define I2C0_B  I2C0_BASE_PTR

void hal_dev_mma8451_init(void); //Preparar puerto I2C
uint8 hal_dev_mma8451_read_reg(uint8 addr);
void hal_dev_mma8451_write_reg(uint8 addr, uint8 data);
uint16 hal_dev_mma8451_test_reg_rw(void);
void hal_dev_mma8451_test_function(void);

int TFC_Accel_Read(void);
void TFC_Accel_Init(void);

#endif
