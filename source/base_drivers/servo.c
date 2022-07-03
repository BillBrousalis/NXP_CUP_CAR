/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

/* written includes */
#include "drive_tracking.h"
#include "signals.h"
#include "safety/safety.h"
#include "misc.h"

#include "servo.h"

#define SERVO_CENTER -0.2f

/*
 * Use this function to set steering servo to desired angle
 * Input: float value range (-1, 1)
 */
float current_steer = 0.0f;
float desired_steer = 0.0f;
void servo_set(float steer) {
	desired_steer = steer;
	steer_control(&steer);
	steer += SERVO_CENTER;
	float perc = map(steer, -1.0f, 1.0f, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state - offset makes it confusing; remove it */
	car_state->steering = steer - SERVO_CENTER;
	current_steer = steer - SERVO_CENTER;
	vTaskDelay(pdMS_TO_TICKS(10));
}

/*
void servo_step(float target) {
	float perc;
	float i = car_state->steering;
	if(i < target) {
		while(i < target) {
			perc = map(i, -1.0f, 1.0f, 50.0f, 100.0f);
			// set compare register to appropriate value
			FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
			FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
			// MISSING DELAY <<<<
			i += SERVO_STEP;
		}
	}
	else if(i > target) {
		while(i > target) {
			perc = map(i, -1.0f, 1.0f, 50.0f, 100.0f);
			// set compare register to appropriate value
			FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
			FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
			// MISSING DELAY <<<<
			i -= SERVO_STEP;
		}
	}
}
*/

void servo_center() {
	// steer = (-1, 1) -> map to (0, 100)
	float perc = map(SERVO_CENTER, -1.0f, 1.0f, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = SERVO_CENTER;
}
