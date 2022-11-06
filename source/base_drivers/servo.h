#ifndef SERVO_H_
#define SERVO_H_
//-----------------------------
#define SERVOCENTER (int16_t)0
#define SERVOMAXR	(int16_t)100 + SERVOCENTER
#define SERVOMAXL	(int16_t)-100 + SERVOCENTER
//-----------------------------
#define SERVOABSMAX (int16_t)100 // for safety.c
//-----------------------------
void servo_center(void);
void steer_set(int16_t steer);
void servo_set(int16_t steer);

#endif
