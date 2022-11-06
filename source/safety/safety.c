#include "includes.h"
#include "globals.h"
#include "base_drivers/servo.h"
#include "misc.h"
#include "safety.h"

//--------------------------------------------------------------------
//		Throttle
//--------------------------------------------------------------------
/* Pass calculated speed to this */
void throttle_control(int16_t *s) {
	//throttle_limiter(s);
	//throttle_rate_limiter(s);
	throttle_hard_limits(s);
}

/* Smoother throttle transitions */
void throttle_rate_limiter(int16_t *s) {
	if(abs(car_state->speed - *s) > THROTTLE_MAX_STEP) {
		if(car_state->speed < *s) {
			*s = car_state->speed + THROTTLE_MAX_STEP;
		}
		else {
			*s = car_state->speed - THROTTLE_MAX_STEP;
		}
	}
}

/* Hard throttle limits for safety */
void throttle_hard_limits(int16_t *s) {
	if(*s > THROTTLE_MAX && *s > 0) {
		*s = THROTTLE_MAX;
	}
	else if(*s < THROTTLE_MIN && *s < 0) {
		*s = THROTTLE_MIN;
	}
}

//--------------------------------------------------------------------
// 		Steering
//--------------------------------------------------------------------
/* Pass calculated steer to this */
void steer_control(int16_t *s) {
	//steer_rate_limiter(s);
	steer_hard_limits(s);
}

/* Smoother steering transitions */
void steer_rate_limiter(int16_t *s) {
	if(abs(car_state->steering - *s) > STEER_MAX_STEP) {
		if(car_state->steering < *s) {
			*s = car_state->steering + STEER_MAX_STEP;
		}
		else {
			*s = car_state->steering - STEER_MAX_STEP;
		}
	}
}

/* Hard steer limits for safety */
void steer_hard_limits(int16_t *s) {
	if(*s > STEER_MAX && *s > 0) {
		*s = STEER_MAX;
	}
	else if(*s < STEER_MIN && *s < 0) {
		*s = STEER_MIN;
	}
}

//--------------------------------------------------------------------
// 		Throttle Control for turns
//--------------------------------------------------------------------
/* Cut down speed when turning */
/* TODO: come up with a better name for this */
void throttle_limiter(int16_t *s) {
	*s = (int16_t)(*s * (((THROTTLE_LIMITER_MULT * (float)SERVOABSMAX) - (float)abs(car_state->steering)) / (THROTTLE_LIMITER_MULT * (float)SERVOABSMAX)));
}
