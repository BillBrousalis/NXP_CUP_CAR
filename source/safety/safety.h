#pragma once

/* Throttle safety */
void throttle_control(float *s);
void throttle_rate_limiter(float *speed);
void throttle_hard_limits(float *speed);

/* Steering */
void steer_control(float *steer);
void steer_rate_limiter(float *s);
void steer_hard_limits(float *s);
