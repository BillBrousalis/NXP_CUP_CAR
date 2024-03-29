#ifndef UART_H_
#define UART_H_
//----------------------------------------------------------------------
#include "includes.h"
//----------------------------------------------------------------------
#define UartSendPi(buf, l)	UART_RTOS_Send(&UART3_rtos_handle, buf, l);
#define UartRecvPi(buf, l)  UART_RTOS_Receive(&UART3_rtos_handle, buf, l, &recv);

#endif
