//#include "includes.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "defines.h"
#include "base_drivers/linescan.h"
#include "base_drivers/uart.h"
#include "base_drivers/motors.h"
#include "base_drivers/servo.h"
#include "drive_tracking.h"

#include "mytasks.h"

//-----------------------------------------
/* 128 pixel values + speed + steer */
uint8_t Sbuf[LINEMAXPIX+2];
uint8_t LineCam_IsInit = 0;
//-----------------------------------------------------------------------------------------
//		test_cam_task - send linescan output data over to RPI
//-----------------------------------------------------------------------------------------
void TestCam_task(void *pvParameters) {
	TickType_t xLastWakeTime;
	while(LineCam_IsInit == 0) osDelay(1);		// Wait for LineCam task to start
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		//---------------------------------------
		if(SW1_read() == 1) Led1_ON();
		else Led1_OFF();
		//---------------------------------------
		/* Fetch Line */
		if(LineCamGetLast(Sbuf) == 1) {
			Sbuf[LINEMAXPIX] = car_state->speed;
			Sbuf[LINEMAXPIX+1] = car_state->steering;
			UartSendPi(Sbuf, LINEMAXPIX+2);
		}
	}
}
//-----------------------------------------------------------------------------------------
//		Line camera task - Read
//-----------------------------------------------------------------------------------------
void LineCam_task(void *pvParameters) {
	LineCamInit();
	LineCam_IsInit = 1;
	for(;;) LineCamProcess();
}
//-----------------------------------------------------------------------------------------
//		Commands mode - Run algorithm on RPI
//-----------------------------------------------------------------------------------------
// TODO: test this
void Commands_task(void *pvParameters) {
	size_t recv;
	/* speed - steer buffer */
	uint8_t buf[2] = {0};
	for(;;) {
		/* Get Line - Send to RPI */
		if(LineCamGetLast(Sbuf) == 0) {
			speed_set(0);
			break;
		}
		Sbuf[LINEMAXPIX] = car_state->speed;
		Sbuf[LINEMAXPIX+1] = car_state->steering;
		UartSendPi(Sbuf, LINEMAXPIX+2);
		/* Get Updated Speed - Steer */
		UartRecvPi(buf, 2*sizeof(buf));
		speed_set((int8_t)buf[0]);
		steer_set((int8_t)buf[1]);
	}
}
//-----------------------------------------------------------------------------------------
//		Read Pots - Battery
//-----------------------------------------------------------------------------------------
// TODO: make it work
int32_t x;
void PotsUpdate_task(void *pvParameters) {
	x = ADC16_GetChannelConversionValue(ADC1_PERIPHERAL, 0U);
	osDelay(100);
}
