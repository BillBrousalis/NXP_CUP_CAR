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
//------------------------------------
TaskHandle_t TestAll_handle;
//------------------------------------
SemaphoreHandle_t adc1_Semaphore;
//------------------------------------
QueueHandle_t CarControlQueueHandle;
//------------------------------------
uint32_t adc1_result = 0;
//------------------------------------
TrackingState s;
TrackingState *car_state = &s;
//------------------------------------
RequestedState rs;
RequestedState *requested_state = &rs;
//------------------------------------
int32_t CarInitialized = 0;
//------------------------------------
/* Zero-out on startup */
void init_tracking(void) {
	/* driving */
	car_state->steering = 0;
	car_state->speed = 0;
	/* camera */
	car_state->error = 0;
	car_state->preverror = 0;
	/* generic */
	car_state->pot[0] = 0;
	car_state->pot[1] = 0;
	car_state->battery = 0;
}
