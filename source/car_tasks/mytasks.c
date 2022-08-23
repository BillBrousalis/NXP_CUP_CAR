//#include "includes.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "irq_handler.h"
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
//-----------------------------------------
#define ADC1_DELAY	33
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
//		Adc task -> Read Pots - Battery
//-----------------------------------------------------------------------------------------
uint32_t adc1_chnl = 0;
uint32_t adc1_result;
void adc1_task(void *pvParameters) {
	for(;;) {
		if(xSemaphoreTake(adc1_Semaphore, portMAX_DELAY) == pdTRUE) {
			adc1_channels[adc1_chnl++] = adc1_result;
			if(adc1_chnl > 2) adc1_chnl = 0;
			osDelay(ADC1_DELAY);
			switch(adc1_chnl) {
				case 0:
					ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					break;
				case 1:
					ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH1_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					break;
				case 2:
					ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH2_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					break;
				default:
					break;
			}
		}
	}
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
