#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

/* written includes */
#include "drive_tracking.h"
#include "signals.h"

#include "servo.h"

#define SERVO_CENTER -0.2f
#define SERVO_STEP 0.01f;

/*
 * Use this function to set steering servo to desired angle
 * Input: float value range (-1, 1)
 */
void servo_set(float steer) {
	steer += SERVO_CENTER;
	servo_step(steer);
	/* update state */
	car_state->steering = steer;
}

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

void servo_center() {
	// steer = (-1, 1) -> map to (0, 100)
	float perc = map(SERVO_CENTER, -1.0f, 1.0f, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = SERVO_CENTER;
}
