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
#include "safety/safety.h"

#include "motors.h"

#define WHEEL_DIFF_MULT 0.4f

/* Because writing motors_set(0.0f, 0.0f); is too much work */
void motors_stop() {
	motors_set(0.0f, 0.0f);
}

/* Set speeds of L / R motors, ranges (-1, 1) */
void motors_set(float speedL, float speedR) {
	/* Flip speeds to make + forwards / - backwards */
	/* Preserve stack space by allocating one float for % */
	float perc;
	/* Set - Set */
	perc = map(-speedL, -1.0f, 1.0f, 50.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	perc = map(-speedR, -1.0f, 1.0f, 50.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, perc);
	/* Trigger */
	FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, 1);
	/* update speed of state struct */
	car_state->speed = speedL >= speedR ? speedL : speedR;
}

/* Calculate differential -> TODO: fix this */
void motors_diff(float *speedL, float *speedR) {
	if(car_state->steering > 0)
		*speedR -= car_state->steering * *speedR * WHEEL_DIFF_MULT;
	else
		*speedL += car_state->steering * *speedL * WHEEL_DIFF_MULT;
}

/* Set speed - function takes care of the rest */
void speed_set(float speed) {
	throttle_control(&speed);
	float sL = speed, sR = speed;
	/* Account steering angle with wheel differential */
	motors_diff(&sL, &sR);
	/* Give motors their individual speeds */
	motors_set(sL, sR);
}

/* Initialize both brushless motors */
void motors_init() {
	float s = -0.25f;
	while(s <= 0.25f) {
		motors_set(s, s);
		vTaskDelay(pdMS_TO_TICKS(100));
		s += 0.02f;
	}
}
