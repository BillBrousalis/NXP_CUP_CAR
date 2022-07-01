#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

#include "signals.h"

/* FTM2 TIMER MAX COUNT*/
#define TIMER_MAX 37500

status_t FTM_SetPpm(FTM_Type *base, ftm_chnl_t chnlNumber, ftm_pwm_mode_t pwm_mode, float perc) {
	/* range checking */
	if(perc > 100.0f || perc < 0)
		return kStatus_OutOfRange;
	int cnv = (int)(((perc/10.0f) / 100.0f) * TIMER_MAX) - 1;
	base->CONTROLS[chnlNumber].CnV = cnv;
	return kStatus_Success;
}

int map(float in, float in_low, float in_high, float out_low, float out_high) {
	float out = out_low + ((out_high - out_low) / (in_high - in_low)) * (in - in_low);
	return out;
}
