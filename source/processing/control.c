#include "includes.h"
#include "globals.h"
#include "base_drivers/servo.h"
#include "processing/peak_detector.h"

#include "control.h"

void drive_control(void) {
	static int emi_peaks[EMI_SZ];
	static int absop_peaks[ABSOP_SZ];
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
	detect_peak(data, LINEMAXPIX, emi_peaks, &n_emi_peaks, EMI_SZ, absop_peaks, &n_absop_peaks, ABSOP_SZ, delta, emi_first);

	error_calculation(absop_peaks, n_absop_peaks);
	int16_t target_steer = error2input();

	// append request
	static RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
	reqstate.req_speed = (int16_t)20;
    reqstate.req_steer = target_steer;
    xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);

	/* update data_buf for plotting detected peaks in GUI */
	data_buf[LINEMAXPIX+2] = (uint8_t)0;
	data_buf[LINEMAXPIX+3] = (uint8_t)0;
	for(int i = 0; i < n_absop_peaks; ++i) {
		data_buf[LINEMAXPIX+2+i] = (uint8_t)absop_peaks[i];
	}
}

void error_calculation(int peaks[], int npeaks) {
	/* Normalized error [-1.0, 1.0] */
	float err = 0.0f;
	switch(npeaks) {
		case 0: // 0 peaks
			err = cam_dat->prev_error;
			break;
		//TODO: fix this approach, not correct for 1 line case
		case 1:	// 1 peak
			/* negative error -> is left | positive error -> is right */
			if(peaks[0] >= LINEMID) { // is right
				err = -(float)(LINEMAXPIX - peaks[0]) / (float)LINEMID * (-1.0f);
			}
			else{ // is left
				err = (float)peaks[0] / (float)LINEMID;
			}
			break;
		case 2: // 2 peaks
			/* negative error -> is left | positive error -> is right */
			// peaks[0] always < peaks[1]
			if(peaks[0] < LINEMID && peaks[1] >= LINEMID) { // peaks[0] is left and peaks[1] is right
				if(peaks[0] > (LINEMAXPIX - peaks[1])) {
					err = (float)peaks[0] / (float)LINEMID;
				}
				else {
					err = -(float)(LINEMAXPIX - peaks[1]) / (float)LINEMID;
				}
			}
			else if(peaks[0] >= LINEMID) { // peaks[0] is right
				err = -(float)(LINEMAXPIX - peaks[0]) / (float)LINEMID;
			}
			else { // peaks[1] is left
				err = (float)peaks[1] / (float)LINEMID;
			}
			break;
		default:
			// something went very wrong
			return;
	}
	cam_dat->prev_error = cam_dat->error;
	cam_dat->error = err;
}

int16_t error2input(void) {
	/* convert calculated error to target vector for gyro | steering */
	/* demo implementation to test*/
	float KP = 75.0f;
	int16_t servo = (int16_t)(KP * cam_dat->error);
	return servo;
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
