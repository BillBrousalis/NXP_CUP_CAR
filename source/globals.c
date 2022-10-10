#include "includes.h"
#include "globals.h"

//------------------------------------
/* Task Handles */
TaskHandle_t Housekeeping_handle;
TaskHandle_t Car_handle;
TaskHandle_t PotsBatUpdate_handle;
TaskHandle_t TestCam_handle;
TaskHandle_t LineCam_handle;
TaskHandle_t Commands_handle;
TaskHandle_t NativeControl_handle;
//------------------------------------
TaskHandle_t TestAll_handle;
//------------------------------------
SemaphoreHandle_t adc1_Semaphore;
//------------------------------------
QueueHandle_t CarControlQueueHandle;
//------------------------------------
uint32_t adc1_result = 0;
//------------------------------------
TrackingState s = {
	.steering = 0,
	.speed = 0,
	.pot[0] = 0,
	.pot[1] = 0,
	.battery = 0
};
TrackingState *car_state = &s;
//------------------------------------
RequestedState rs;
RequestedState *requested_state = &rs;
//------------------------------------
CameraDat camdat = {
	.calibration_max = 0,
	.calibration_min = 0,
	.error = 0,
	.prev_error = 0,
	.l_edge_idx = 0,
	.r_edge_idx = 0
};
CameraDat *cameradat = &camdat;
//------------------------------------
int16_t CarInitialized = 0;
