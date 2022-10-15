#ifndef CONTROL_H_
#define CONTROL_H_

#define emi_sz 1
#define absop_sz 2

void drive_control(void);
void error_calculation(int npeaks, int peak1, int peak2);
int16_t error2input(void);

#endif
