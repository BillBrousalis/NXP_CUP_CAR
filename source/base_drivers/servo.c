#include "includes.h"
#include "signals.h"
#include "safety/safety.h"
#include "misc.h"
#include "globals.h"

#include "servo.h"

//----------------------------------------------------
//		API
//----------------------------------------------------
/* Center the steering servo */
void servo_center(void) {
	servo_set(SERVOCENTER);
}

/* Set steering to desired value (-100, 100)
	Use this in application layer */
void steer_set(int16_t steer) {
	steer_control(&steer);
	servo_set(steer);
}

//----------------------------------------------------
//		DONT USE ON APPLICATION LAYER
//----------------------------------------------------
/* Baseline servo-setting function - NO CHECKS */
void servo_set(int16_t steer) {
	/* add servo offset to equation for more precision */
	steer += SERVOCENTER;
	float perc = map(-steer, SERVOMAXL, SERVOMAXR, 0.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = steer - SERVOCENTER;
}
