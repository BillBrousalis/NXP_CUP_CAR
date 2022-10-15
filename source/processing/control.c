#include "includes.h"
#include "globals.h"
#include "processing/peak_detector.h"

#include "control.h"

void drive_control(void) {
	static int emi_peaks[emi_sz];
	static int absop_peaks[absop_sz];
	static float data[LINEMAXPIX];
	int n_emi_peaks = 0;
	int n_absop_peaks = 0;
	float delta = 40.0f;
	int emi_first = 0;

	for(int i=0; i<LINEMAXPIX; i++) {
    	data[i] = (float)data_buf[i];
    }

	/* peak detection */
	memset(emi_peaks, 0, sizeof(emi_peaks));
	memset(absop_peaks, 0, sizeof(absop_peaks));
	detect_peak(data, LINEMAXPIX, emi_peaks, &n_emi_peaks, emi_sz, absop_peaks, &n_absop_peaks, absop_sz, delta, emi_first);

	error_calculation(n_absop_peaks, absop_peaks[0], absop_peaks[1]);

	/* update data_buf for plotting detected peaks in GUI */
	data_buf[LINEMAXPIX+2] = (uint8_t)0;
	data_buf[LINEMAXPIX+3] = (uint8_t)0;
	if(n_absop_peaks > 0) {
		data_buf[LINEMAXPIX+2] = absop_peaks[0];
		if(n_absop_peaks > 1) {
			data_buf[LINEMAXPIX+3] = absop_peaks[1];
		}
	}
}

void error_calculation(int npeaks, int peak1, int peak2) {
	// TODO: fix error "scaling"
	/* Normalized error -1 to 1 */
	float err = 0.0f;
	switch(npeaks) {
		case 0: // 0 peaks
			err = cam_dat->prev_error;
			break;
		//TODO: fix this approach, not correct for 1 line case
		case 1:	// 1 peak
			/* negative error -> is left | positive error -> is right */
			err = ((float)peak1 / 2.0f) - (float)LINEMID;
			err /=  ((float)LINEMID / 2.0f);
			break;
		case 2: // 2 peaks
			/* negative error -> is left | positive error -> is right */
			err = ((float)(peak1 + peak2) / 2.0f) - (float)LINEMID;
			err /= (float)LINEMID;
			break;
		default:
			return;
	}
	cam_dat->prev_error = cam_dat->error;
	cam_dat->error = err;
}

int16_t error2input(void) {
	/* convert calculated error to target vector for gyro | steering */
	return 0;
}


/*
 * func():
 	put state machine here:
	 state certain:
		 pass calculated error to pid
		 update prev error
		 update outputs with pid_out
	 state uncertain:
	 	 pass prev error to pid
	 	 update outputs with pid_out

*/
