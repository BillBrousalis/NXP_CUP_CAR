#include "includes.h"
#include "globals.h"
#include "processing/pid.h"
#include "car_tasks/car_tasks.h"
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
CameraDat cdat = {
	.calibration_max = 0,
	.calibration_min = 0,
	.error = 0.0f,
	.prev_error = 0.0f,
	.peak_idx1 = 0,
	.peak_idx2 = 0,
	.lane_width = 80,
	.uncertainty_counter = 0
};
CameraDat *cam_dat = &cdat;
//------------------------------------
Drive_PID dpid= {
	.kp = 100.0f,
	.ki = 0.0f,
	.kd = 0.0f,
	.dt = (float)CAR_CONTROL_PERIOD,
	.setpoint = 0.0f,
	.out = 0.0f,
	.min = -100.0f,
	.max = 100.0f
};
Drive_PID *drive_pid = &dpid;
//------------------------------------
struct pid_controller ctrldata;
// fixme
/*pid = pid_create(&ctrldata, &cam_dat->error, &drive_pid->out, &drive_pid->setpoint,
						  drive_pid->kp, drive_pid->ki, drive_pid->kd, drive_pid->dt);
pid_limits(pid, drive_pid->min, drive_pid->max);
// Allow PID to compute and change output
pid_auto(pid);
*/
//------------------------------------
int16_t CarInitialized = 0;
//------------------------------------
/* 128 pixel values + speed + steer + 2 peaks idx */
uint8_t data_buf[LINEMAXPIX+4];
uint8_t LineCam_IsInit = 0;
