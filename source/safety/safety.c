#include "includes.h"
#include "safety.h"

/* Pass calculated speed to this */
void throttle_control(int16_t *s) {
	throttle_rate_limiter(s);
	throttle_hard_limits(s);
}

/* Smooth throttle transitions */
void throttle_rate_limiter(int16_t *s) {
	int16_t sign = 1;
	uint16_t diff = abs(car_state->speed - *s);
	if(diff > THROTTLE_MAX_STEP) {
		if(same_sign(car_state->speed, *s) && (car_state->speed > *s))
			sign *= -1;
		else if(*s < 0)
			sign *= -1;
		*s = car_state->speed + (int16_t)(sign * THROTTLE_MAX_STEP);
	}
}

/* Hard throttle limits for safety */
void throttle_hard_limits(int16_t *s) {
	if(*s > THROTTLE_MAX && *s > 0)
		*s = THROTTLE_MAX;
	else if(*s < THROTTLE_MIN && *s < 0)
		*s = THROTTLE_MIN;
}

/* Pass calculated steer to this */
void steer_control(int16_t *s) {
	steer_rate_limiter(s);
	steer_hard_limits(s);
}

/* Smooth steering transitions */
void steer_rate_limiter(int16_t *s) {
	int16_t sign = 1;
	uint16_t diff = abs(car_state->steering - *s);
	if(diff > STEER_MAX_STEP) {
		if(same_sign(car_state->steering, *s) && (car_state->steering > *s))
			sign *= -1;
		else if(*s < 0)
			sign *= -1;
		*s = car_state->steering + (int16_t)(sign * STEER_MAX_STEP);
	}
}

/* Hard steer limits for safety */
void steer_hard_limits(int16_t *s) {
	if(*s > STEER_MAX && *s > 0)
		*s = STEER_MAX;
	else if(*s < STEER_MIN && *s < 0)
		*s = STEER_MIN;
}
