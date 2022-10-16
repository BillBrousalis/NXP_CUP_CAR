#ifndef CONTROL_H_
#define CONTROL_H_

#define EMI_SZ 1
#define ABSOP_SZ 2

void drive_control(void);
void error_calculation(int peaks[], int npeaks);
int16_t error2input(void);

#endif
