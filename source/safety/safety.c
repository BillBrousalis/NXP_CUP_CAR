#include "drive_tracking.h"
#include "misc.h"

#include "safety.h"

#define THROTTLE_MAX 0.5f
#define THROTTLE_MIN -0.5f
#define THROTTLE_MAX_STEP 0.03f

/* Pass calculated speed to this */
void throttle_control(float *s) {
	throttle_rate_limiter(s);
	throttle_hard_limits(s);
}

/* Smooth throttle transitions */
void throttle_rate_limiter(float *s) {
	float sign = 1.0f;
	float diff = fabs(car_state->speed - *s);
	if(diff > THROTTLE_MAX_STEP) {
		if(same_sign(car_state->speed, *s) && (car_state->speed > *s))
			sign *= -1.0f;
		else if(*s < 0)
			sign *= -1.0f;
		*s = car_state->speed + sign * THROTTLE_MAX_STEP;
	}
}

/* Hard limits for safety */
void throttle_hard_limits(float *s) {
	if(*s > THROTTLE_MAX && *s > 0.0f)
		*s = THROTTLE_MAX;
	else if(*s < THROTTLE_MIN && *s < 0.0f)
		*s = THROTTLE_MIN;
}
