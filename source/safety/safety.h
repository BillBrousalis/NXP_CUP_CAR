#pragma once
//---------------------------------
#define THROTTLE_MAX 		(int16_t)50
#define THROTTLE_MIN 		(int16_t)-50	// can't set to 0 to allow current initialization process - fix init
#define THROTTLE_MAX_STEP 	(uint16_t)3
//---------------------------------
#define STEER_MAX 		(int16_t)70 //60
#define STEER_MIN 		(int16_t)-70 //-60
#define STEER_MAX_STEP 	(uint16_t)20
//---------------------------------
/* Throttle safety */
void throttle_control(int16_t *s);
void throttle_rate_limiter(int16_t *speed);
void throttle_hard_limits(int16_t *speed);
//---------------------------------
/* Steering */
void steer_control(int16_t *steer);
void steer_rate_limiter(int16_t *s);
void steer_hard_limits(int16_t *s);
