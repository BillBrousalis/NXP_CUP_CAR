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

/* Baseline servo-setting function - NO CHECKS */
void servo_set(float steer) {
	steer += SERVO_CENTER;
	/* add servo offset to equation for more precision */
	float perc = map(steer, -1.0f, 1.0f, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state - offset makes it confusing; remove it */
	car_state->steering = steer - SERVO_CENTER;
}

/* Center the steering servo */
void servo_center() {
	float perc = map(SERVO_CENTER, -1.0f, 1.0f, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = SERVO_CENTER;
}

/* Set steering to desired value (-1, 1) */
/* Use this in application layer         */
void steer_set(float steer) {
	steer_control(&steer);
	servo_set(steer);
}
