#ifndef MOTORS_H_
#define MOTORS_H_
//---------------------------------
#define WHEEL_DIFF_MULT	0.007f // 0.005f cuts speed (one side) in half at most
//---------------------------------
#define MOTORSIDLE	(int16_t)6
#define MOTORSMIN	(int16_t)-100
#define MOTORSMAX	(int16_t)100
//---------------------------------
void motors_init(void);
void motors_stop(void);
void speed_set(int16_t speed);
void motors_set(int16_t speedL, int16_t speedR);
void motors_diff(int16_t *speedL, int16_t *speedR);

#endif
