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

/* Baseline servo-setting function - NO CHECKS */
void servo_set(int16_t steer) {
	/* add servo offset to equation for more precision */
	steer += SERVOCENTER;
	float perc = fmap(steer, SERVOMAXL, SERVOMAXR, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = steer - SERVOCENTER;
}

/* Center the steering servo */
void servo_center(void) {
	float perc = fmap(SERVOCENTER, SERVOMAXL, SERVOMAXR, 50.0f, 100.0f);
	// set compare register to appropriate value
	FTM_SetPpm(FTM2_PERIPHERAL, kFTM_Chnl_0, kFTM_EdgeAlignedPwm, perc);
	FTM_SetSoftwareTrigger(FTM2_PERIPHERAL, 1);
	/* update state */
	car_state->steering = SERVOCENTER;
}

/* Set steering to desired value (-100, 100) */
/* Use this in application layer         */
void steer_set(int16_t steer) {
	steer_control(&steer);
	servo_set(steer);
}
