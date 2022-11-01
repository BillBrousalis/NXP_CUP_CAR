#ifndef ACCEL_ACCEL_H_
#define ACCEL_ACCEL_H_

int ACCEL_GetAccelData(int *xp, int *yp, int *zp);
int ACCEL_Init(void);
void IMU_init(void);
void IMU_loop(void);


#endif /* ACCEL_ACCEL_H_ */
