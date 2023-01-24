#include "includes.h"
#include "globals.h"
#include "defines.h"
#include "misc.h"
#include "base_drivers/linescan.h"
#include "base_drivers/uart.h"
#include "base_drivers/motors.h"
#include "base_drivers/servo.h"
#include "base_drivers/pot_bat.h"
#include "base_drivers/gpio.h"
#include "base_drivers/led.h"
#include "base_drivers/WheelEncoder.h"
#include "processing/peak_detector.h"
#include "processing/control.h"
#include "processing/pid.h"
#include <imu.h>
#include "car_tasks.h"

uint32_t	estop_flag = 0;
//-----------------------------------------
void Housekeeping_task(void *pvParaments) {
	/* Initialization */
	//WheelEncoderInit();
	servo_center();
	/* Set ready flag */
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = CAR_CONTROL_PERIOD;
	CarInitialized = 1;
	for(;;) {
		/* Lights */
		if(SW1_read() == 1) Led1_ON();
		else Led1_OFF();
		//--------------------------------------
		if(ESTOP_read() == 1) {							// read remote estop input
			if(estop_flag == 1) {						// toggle state
				estop_flag = 0;
				LED4_OFF();
			}
			else {
				estop_flag = 1;
				LED4_ON();
			}
			while(ESTOP_read() == 1) osDelay(50);
		}
		//---------------------------------------
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
		if(PB1_read() == PB_ON) {
			motors_init();
			osDelay(20);
		}
		else if(xQueueReceive(CarControlQueueHandle, &reqstate, (TickType_t)portMAX_DELAY ) == pdPASS) {
			steer_set(reqstate.req_steer);
			if(estop_flag == 0) {
				speed_set(reqstate.req_speed);
			}
			else {
				motors_stop();
				osDelay(20);
			}
			//osDelay(20);
		}
		//vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}

//-----------------------------------------------------------------------------------------
//		Run controls natively
//-----------------------------------------------------------------------------------------
void NativeControl_task(void *pvParameters) {
	float kp = 110.0f;
	float ki = 0.05f;
	float kd = 0.05f;
	float pid_out = 0.0f;
	float setpoint = 0.0f;
	struct pid_controller drive_pid_controller;
	pid_ctrl drive_pid = pid_create(&drive_pid_controller, &cam_dat->error, &pid_out, &setpoint, kp, ki, kd, -100.0f, 100.0f);
	//----------------------------------------
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xPeriod = CAR_CONTROL_PERIOD;
	//----------------------------------------
	while(LineCam_IsInit == 0) osDelay(1);
	//----------------------------------------
	for (;;) {
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
		if(LineCamGetLast(data_buf) == 0) continue;
		/* process camera data */
		cam_data_process();
		/* compute with new cam->error */
		pid_compute(drive_pid);
		/* new state */
		int16_t target_steer = (int16_t)pid_out;
		int16_t target_speed = (int16_t)(32.0f - (float_abs(target_steer) * 7.0f / 100.0f));
		/* append state request */
		RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
		reqstate.req_steer = target_steer;
		reqstate.req_speed = target_speed;
		xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);
		if(DEBUG) {
			/* Send to RPI */
			data_buf[LINEMAXPIX] = car_state->speed;
			data_buf[LINEMAXPIX+1] = car_state->steering;
			UartSendPi(data_buf, sizeof(data_buf));
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
	uint32_t delay = 20;
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
					// TODO: implemenet
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
			/* Don't mess with the casting please */
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
void IMU_Task(void *pvParameters) {
	IMU_init();
	for(;;) IMU_loop();
}
