#ifndef SAFETY_H_
#define SAFETY_H_
//---------------------------------
#define THROTTLE_MAX 		(int16_t)45
#define THROTTLE_MIN 		(int16_t)-20
#define THROTTLE_MAX_STEP 	(uint16_t)3
//---------------------------------
#define STEER_MAX 		(int16_t)75
#define STEER_MIN 		(int16_t)-75
#define STEER_MAX_STEP 	(uint16_t)25
//---------------------------------
/* Higher -> less slow-down */
#define THROTTLE_LIMITER_MULT	2.8f
//---------------------------------
/* Throttle */
void throttle_control(int16_t *s);
void throttle_rate_limiter(int16_t *speed);
void throttle_hard_limits(int16_t *speed);
//---------------------------------
/* Steering */
void steer_control(int16_t *steer);
void steer_rate_limiter(int16_t *s);
void steer_hard_limits(int16_t *s);
//---------------------------------
/* Throttle control when turning */
void throttle_limiter(int16_t *s);

#endif
