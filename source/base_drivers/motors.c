#include "includes.h"
#include "signals.h"
#include "misc.h"
#include "safety/safety.h"
#include "defines.h"
#include "globals.h"

#include "motors.h"

//----------------------------------------------------
//		API
//----------------------------------------------------
/* Initialize both brushless motors
	- There has to be a better way to do this */
void motors_init(void) {
	int16_t s = -5;
	while(s <= 8) {
		motors_set(s, s);
		osDelay(250);
		++s;
	}
	motors_stop();
}

/* Because writing motors_set(0, 0); is too much work */
void motors_stop(void) {
	motors_set(MOTORSIDLE, MOTORSIDLE);
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

//----------------------------------------------------
//		DONT USE ON APPLICATION LAYER
//----------------------------------------------------
/* Set speeds of L / R motors, ranges (-1, 1) */
void motors_set(int16_t speedL, int16_t speedR) {
	float perc;
	/* Flip speeds to make + forwards / - backwards */
	/* Map motor speed to PPM percentage --> Set - Set */
	perc = map(-speedL, MOTORSMIN, MOTORSMAX, 0.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	perc = map(-speedR, MOTORSMIN, MOTORSMAX, 0.0f, 100.0f);
	FTM_SetPpm(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, perc);
	/* Trigger */
	FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, true);
	/* update speed of car state struct */
	car_state->speed = max(speedL, speedR); // speedL >= speedR ? speedL : speedR;
}

/* Calculate differential -> TODO: implement a more math driven approach */
void motors_diff(int16_t *speedL, int16_t *speedR) {
	if(car_state->steering > 0) {
		*speedR -= (int16_t)((float)car_state->steering * *speedR * WHEEL_DIFF_MULT);
	}
	else {
		*speedL += (int16_t)((float)car_state->steering * *speedL * WHEEL_DIFF_MULT);
	}
}
