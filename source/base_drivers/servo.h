#pragma once
//-----------------------------
#define SERVOCENTER (int16_t)-20
#define SERVOMAXR	(int16_t)100
#define SERVOMAXL	(int16_t)-100
//-----------------------------
void servo_set(int16_t steer);
void servo_center(void);
void steer_set(int16_t steer);
