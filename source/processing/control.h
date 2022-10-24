#ifndef CONTROL_H_
#define CONTROL_H_
//--------------------------------
#define EMI_SZ 1
#define ABSOP_SZ 2
//--------------------------------
#define ERR_DIFF_THRESHOLD	0.9f
//--------------------------------
void drive_control(void);
void error_calculation(int *peaks, int npeaks);
int16_t error2input(void);
int16_t prev_err_check(float err);
//--------------------------------

#endif
