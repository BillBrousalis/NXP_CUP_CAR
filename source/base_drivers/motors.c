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
#include "misc.h"

#include "motors.h"

/* TODO: INDIVIDUAL SPEEDS ADJUSTED FOR STEERING ANGLE */

/* Because writing motors_set(0.0f, 0.0f); is too much work */
void motors_stop() {
	motors_set(0.0f, 0.0f);
}

/* Set speeds of L / R motors, ranges (-1, 1) */
void motors_set(float speedL, float speedR) {
	/* Flip speeds to make + forward / - backwards */
	/* Preserve stack space by allocating one float */
	float perc;
	perc = map(-speedL, -1.0f, 1.0f, 50.0f, 100.0f);
	/* Set - Set */
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	perc = map(-speedR, -1.0f, 1.0f, 50.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, perc);
	/* Trigger */
	FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, 1);
	/* update prevspeed of state struct */
	car_state->speed = speedL >= speedR ? speedL : speedR;
}

/* Initialize both brushless motors */
void motors_init() {
	float s = -0.1;
	while(s <= 0.0f) {
		motors_set(s, s);
		vTaskDelay(pdMS_TO_TICKS(500));
		s += 0.02f;
	}
}
