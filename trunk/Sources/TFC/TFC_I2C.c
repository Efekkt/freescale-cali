/*
 *  Ultima modificacion: Octubre 16, 2013
 *  Equipo: CALI
 */

#include "TFC\TFC.h"

void i2c_set_tx_mode(I2C_MemMapPtr p)		{	p->C1 |= I2C_C1_TX_MASK;	}

void i2c_set_rx_mode(I2C_MemMapPtr p)		{   p->C1 &= ~I2C_C1_TX_MASK;	}

void i2c_set_slave_mode(I2C_MemMapPtr p)	{   p->C1  &= ~I2C_C1_MST_MASK;	}

void i2c_set_master_mode(I2C_MemMapPtr p)	{	p->C1  |=  I2C_C1_MST_MASK;	}


// i2c general

void i2c_give_nack(I2C_MemMapPtr p)					{	p->C1 |= I2C_C1_TXAK_MASK;	}

void i2c_give_ack(I2C_MemMapPtr p)					{   p->C1 &= ~I2C_C1_TXAK_MASK;	}

void i2c_repeated_start(I2C_MemMapPtr p)			{	p->C1     |= 0x04;			}

void i2c_write_byte(I2C_MemMapPtr p, uint8 data)	{	p->D = data;				}

uint8 i2c_read_byte(I2C_MemMapPtr p)				{	return p->D;				}


void i2c_start(I2C_MemMapPtr p)
{
i2c_set_master_mode(p);
i2c_set_tx_mode(p);
}


void i2c_stop(I2C_MemMapPtr p)
{
i2c_set_slave_mode(p);
i2c_set_rx_mode(p);
}


void i2c_wait(I2C_MemMapPtr p)
{
//Wait flag
while((p->S & I2C_S_IICIF_MASK)==0);

//Clear flag
p->S |= I2C_S_IICIF_MASK;
}


uint16 i2c_get_ack(I2C_MemMapPtr p)
{
if((p->S & I2C_S_RXAK_MASK) == 0)
	return TRUE;
else
	return FALSE;
}


void hal_i2c0_init(I2C_MemMapPtr p)
{
SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;
SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;

//Configure GPIO for I2C function
PORTE_PCR24 = PORT_PCR_MUX(5);
PORTE_PCR25 = PORT_PCR_MUX(5);

p->F  = 0x14; //Baudrate
p->C1 = 0x80; //Enable IIC
}


void hal_i2c1_init(I2C_MemMapPtr p)
{
SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK;
SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

//Configure GPIO for I2C function
PORTC_PCR2 = PORT_PCR_MUX(2)|PORT_PCR_DSE_MASK;
PORTC_PCR1 = PORT_PCR_MUX(2)|PORT_PCR_DSE_MASK;

p->F  = 0x1F; //Baudrate
p->C1 = 0x80; //Enable IIC
}


void hal_i2c0_deinit(I2C_MemMapPtr p)
{
p->C1 = 0x00;    
SIM_SCGC4 &= ~SIM_SCGC4_I2C0_MASK;
}


void hal_i2c1_deinit(I2C_MemMapPtr p)
{
p->C1 = 0x00;
SIM_SCGC4 &= ~SIM_SCGC4_I2C1_MASK;
}
