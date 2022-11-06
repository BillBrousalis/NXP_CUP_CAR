#include "includes.h"
#include "defines.h"
#include "base_drivers/linescan.h"
#include "base_drivers/uart.h"
#include "base_drivers/motors.h"
#include "base_drivers/servo.h"
#include "base_drivers/pot_bat.h"
#include "base_drivers/gpio.h"
#include "base_drivers/led.h"
#include "globals.h"
#include "processing/peak_detector.h"
#include "processing/control.h"

#include "car_tasks.h"

//-----------------------------------------
void Housekeeping_task(void *pvParaments) {
	/* Initialization */
	servo_center();
	/* Set ready flag */
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = CAR_CONTROL_PERIOD;
	CarInitialized = 1;
	for(;;) {
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}
//-----------------------------------------
void Car_task(void *pvParameters) {
	static RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = CAR_CONTROL_PERIOD;
	while(CarControlQueueHandle == NULL) osDelay(1);
	for(;;) {
		if(PB1_read() == PB_ON) motors_init();
		else if(xQueueReceive(CarControlQueueHandle, &reqstate, (TickType_t)0) == pdPASS) {
			speed_set(reqstate.req_speed);
			steer_set(reqstate.req_steer);

			osDelay(20);
		}
		//vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}

//-----------------------------------------------------------------------------------------
//		Run controls natively
//-----------------------------------------------------------------------------------------
void NativeControl_task(void *pvParameters) {
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = CAR_CONTROL_PERIOD/3;
	//----------------------------------------
	while(LineCam_IsInit == 0) osDelay(1);
	//----------------------------------------
	for (;;) {
		//---------------------------------------
		if(SW1_read() == 1) Led1_ON();
		else Led1_OFF();
		//---------------------------------------
		if(LineCamGetLast(data_buf) == 1) {
			/* Send to RPI */
			drive_control();
			data_buf[LINEMAXPIX] = car_state->speed;
			data_buf[LINEMAXPIX+1] = car_state->steering;
			UartSendPi(data_buf, sizeof(data_buf));
			vTaskDelayUntil(&xLastWakeTime, xPeriod);
        }
	}
}

//-----------------------------------------------------------------------------------------
//		test_cam_task - send linescan output data over to RPI
//-----------------------------------------------------------------------------------------
void TestCam_task(void *pvParameters) {
	while(LineCam_IsInit == 0) osDelay(1);		// Wait for LineCam task to start
	for (;;) {
		//---------------------------------------
		if(SW1_read() == 1) Led1_ON();
		else Led1_OFF();
		//---------------------------------------
		/* Fetch Line */
		if(LineCamGetLast(data_buf) == 1) {
			data_buf[LINEMAXPIX] = car_state->speed;
			data_buf[LINEMAXPIX+1] = car_state->steering;
			UartSendPi(data_buf, LINEMAXPIX+2);
		}
	}
}

//-----------------------------------------------------------------------------------------
//		Adc task -> Read Pots - Battery
//-----------------------------------------------------------------------------------------
void PotsBatUpdate_task(void *pvParameters) {
	uint32_t delay = 33;
	uint8_t nchnls = 2;
	uint8_t adc1_chnl = 0;
	for(;;) {
		if(xSemaphoreTake(adc1_Semaphore, portMAX_DELAY) == pdTRUE) {
			adc1_chnl %= nchnls;
			switch(adc1_chnl) {
				case 0:
					ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					break;
				case 1:
					ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH1_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					break;
				case 2:
					// TODO: add this
					//ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH2_CONTROL_GROUP, &ADC1_channelsConfig[adc1_chnl]);
					//break;
					continue;
				default:
					continue;
			}
			adc1_vals_store(adc1_chnl++, adc1_result);
			osDelay(delay);
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
int16_t uartrec = 0; //watch
void Commands_task(void *pvParameters) {
	static RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
	while(!CarInitialized) osDelay(1);
	/* speed - steer buffer */
	uint8_t buf[1] = {0};
	size_t recv;
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = pdMS_TO_TICKS(44);
	for(;;) {
		/* Get Line - Send to RPI */
		if(LineCamGetLast(data_buf) == 1) {
			data_buf[LINEMAXPIX] = car_state->speed;
			data_buf[LINEMAXPIX+1] = car_state->steering;
			UartSendPi(data_buf, LINEMAXPIX+2);
			/* Get Updated Speed - Steer */
			UartRecvPi(buf, 1*sizeof(buf));
			//------
			/* Don't mess with the casting */
			reqstate.req_speed = (int16_t)30;
   		    reqstate.req_steer = (int16_t)((int8_t)buf[0]);
			//------
			xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);
			vTaskDelayUntil(&xLastWakeTime, xPeriod);
		}
	}
}

//-----------------------------------------------------------------------------------------
//		IMU Task
//-----------------------------------------------------------------------------------------
void IMU_Task(void *pvParameters)
{
	IMU_init();
	for(;;)
	{
		IMU_loop();
	}
}
