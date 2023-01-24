#ifndef CONTROL_H_
#define CONTROL_H_
//--------------------------------
#define EMI_SZ 1
#define ABSOP_SZ 2
//--------------------------------
#define ERR_DIFF_THRESHOLD	0.9f
//--------------------------------
void cam_data_process(void);
static void error_calculation(int *peaks, int npeaks);
static int16_t prev_err_check(float err);
//--------------------------------

#endif
