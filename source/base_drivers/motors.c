#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

#include "drive_tracking.h"
#include "signals.h"
#include "misc.h"
#include "safety/safety.h"
#include "defines.h"

#include "motors.h"

/* Because writing motors_set(0.0f, 0.0f); is too much work */
void motors_stop(void) {
	motors_set(MOTORSIDLE, MOTORSIDLE);
}

/* Set speeds of L / R motors, ranges (-1, 1) */
void motors_set(int16_t speedL, int16_t speedR) {
	float perc;
	/* Flip speeds to make + forwards / - backwards */
	/* Map motor speed to PPM percentage --> Set - Set */
	perc = fmap(-speedL, MOTORSMIN, MOTORSMAX, 50.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	perc = fmap(-speedR, MOTORSMIN, MOTORSMAX, 50.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, perc);
	/* Trigger */
	FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, 1);
	/* update speed of state struct */
	car_state->speed = speedL >= speedR ? speedL : speedR;
}

/* Calculate differential -> TODO: implement a more math driven approach */
void motors_diff(int16_t *speedL, int16_t *speedR) {
	if(car_state->steering > 0)
		*speedR -= (int16_t)((float)car_state->steering * *speedR * WHEEL_DIFF_MULT);
	else
		*speedL += (int16_t)((float)car_state->steering * *speedL * WHEEL_DIFF_MULT);
}

/* Set speed - function takes care of the rest */
void speed_set(int16_t speed) {
	throttle_control(&speed);
	int16_t sL = speed, sR = speed;
	/* Account steering angle with wheel differential */
	motors_diff(&sL, &sR);
	/* Give motors their individual speeds */
	motors_set(sL, sR);
}

/* Initialize both brushless motors
  	- There has to be a better way to do this */
void motors_init(void) {
	int16_t s = -25;
	while(s <= 25) {
		motors_set(s, s);
		osDelay(100);
		++s;
	}
}
