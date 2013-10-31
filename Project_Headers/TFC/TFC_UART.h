/*
 *  Ultima modificacion: Octubre 17, 2013
 *  Equipo: CALI
 */

#ifndef TFC_UART_H_
#define TFC_UART_H_

void TFC_InitUARTs();
void TFC_UART_Process();

extern ByteQueue SDA_SERIAL_OUTGOING_QUEUE;
extern ByteQueue SDA_SERIAL_INCOMING_QUEUE;

#endif
