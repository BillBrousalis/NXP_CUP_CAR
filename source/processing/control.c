#include "includes.h"
#include "globals.h"
#include "misc.h"
#include "base_drivers/servo.h"
#include "base_drivers/motors.h"
#include "processing/peak_detector.h"
#include "processing/pid.h"

#include "control.h"

void cam_data_process(void) {
	static int emi_peaks[EMI_SZ];
	static int absop_peaks[ABSOP_SZ];
	static float data[LINEMAXPIX];
	int n_emi_peaks = 0;
	int n_absop_peaks = 0;
	float delta = 120.0f;
	int emi_first = 0;
	for(int i=0; i<LINEMAXPIX; ++i) {
    	data[i] = (float)data_buf[i];
    }
	/* peak detection */
	memset(emi_peaks, 0, sizeof(emi_peaks));
	memset(absop_peaks, 0, sizeof(absop_peaks));
	detect_peak(data, LINEMAXPIX, emi_peaks, &n_emi_peaks, EMI_SZ, absop_peaks, &n_absop_peaks, ABSOP_SZ, delta, emi_first);
	/* set cam_dat->error / prev_error */
	error_calculation(absop_peaks, n_absop_peaks);

	/* update data_buf for plotting detected peaks in GUI */
	data_buf[LINEMAXPIX+2] = (uint8_t)0;
	data_buf[LINEMAXPIX+3] = (uint8_t)0;
	for(int i = 0; i < n_absop_peaks; ++i) {
		data_buf[LINEMAXPIX+2+i] = (uint8_t)absop_peaks[i];
	}

	/*
	int16_t target_steer = error2input();
	// TODO: fix me
    int16_t target_speed = (int16_t)(29.0f - (float_abs(cam_dat->error) * 8.0f));
    */

    /*
    if(cam_dat->uncertainty_counter > 20) {
		static RequestedState reqstate = {.req_speed = MOTORSIDLE, .req_steer = 0};
		xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);
		for(;;);
    }
    */

	/*
	// append request
	static RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
    reqstate.req_steer = target_steer;
	reqstate.req_speed = target_speed;
    xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);
    */

}

static void error_calculation(int *peaks, int npeaks) {
	/* Normalized error [-1.0, 1.0] */
	float err = 0.0f;
	switch(npeaks) {
		case 0: // 0 peaks
			//cam_dat->uncertainty_counter += 1;
			err = cam_dat->prev_error;
			break;
		case 1:	// 1 peak
			//cam_dat->uncertainty_counter = 0;
			if(peaks[0] >= LINEMID) {
				err = (float)((peaks[0] - cam_dat->lane_width) + peaks[0]) / 2.0f;
			}
			else {
				err = (float)(peaks[0] + (peaks[0] + cam_dat->lane_width)) / 2.0f;
			}
			err -= (float)LINEMID;
			err /= (float)LINEMID;
			if(prev_err_check(err) == (int16_t)0) {
				if(peaks[0] < LINEMID) {
					err = (float)((peaks[0] - cam_dat->lane_width) + peaks[0]) / 2.0f;
				}
				else {
					err = (float)(peaks[0] + (peaks[0] + cam_dat->lane_width)) / 2.0f;
				}
				err -= (float)LINEMID;
				err /= (float)LINEMID;
			}
			break;
		case 2: // 2 peaks
			//cam_dat->uncertainty_counter = 0;
			// peaks[0] always < peaks[1]
			if(peaks[0] < LINEMID && peaks[1] >= LINEMID) { // peaks[0] is left and peaks[1] is right
				err = ((float)(peaks[0] + peaks[1]) / 2.0f);
				/* update lane width */
				cam_dat->lane_width = (int16_t)(peaks[1] - peaks[0]);
			}
			else if(peaks[0] >= LINEMID) { // peaks[0] is right
				err = ((float)((peaks[0] - cam_dat->lane_width) + peaks[0]) / 2.0f);
			}
			else { // peaks[1] is left
				err = ((float)(peaks[1] + (peaks[1] + cam_dat->lane_width)) / 2.0f);
			}
			err -= (float)LINEMID;
			err /= (float)LINEMID;
			if(prev_err_check(err) == (int16_t)0) {
				if(peaks[0] < LINEMID && peaks[1] >= LINEMID) { // peaks[0] is left and peaks[1] is right
					err = ((float)(peaks[0] + peaks[1]) / 2.0f);
					/* update lane width */
					cam_dat->lane_width = (int16_t)(peaks[1] - peaks[0]);
				}
				else if(peaks[0] < LINEMID) { // peaks[0] is right
					err = ((float)((peaks[0] - cam_dat->lane_width) + peaks[0]) / 2.0f);
				}
				else {
					err = ((float)(peaks[1] + (peaks[1] + cam_dat->lane_width)) / 2.0f);
				}
				err -= (float)LINEMID;
				err /= (float)LINEMID;
			}
			break;
		default:
			// something went very wrong
			return;
	}
	cam_dat->prev_error = cam_dat->error;
	cam_dat->error = err;
}

static int16_t prev_err_check(float err) {
	/* err jump too large - crossover */
	if(abs(err - cam_dat->prev_error) >= ERR_DIFF_THRESHOLD) return 0;
	/* err jump ok */
	return 1;
}
