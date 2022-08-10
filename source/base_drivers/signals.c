#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

#include "signals.h"

status_t FTM_SetPpm(FTM_Type *base, ftm_chnl_t chnlNumber, ftm_pwm_mode_t pwm_mode, float perc) {
	/* range checking */
	if(perc > 100.0f || perc < 0)
		return kStatus_OutOfRange;
	if(pwm_mode == kFTM_EdgeAlignedPwm) {
		float cnv = (perc/10.0f) / 100.0f;
		base->CONTROLS[chnlNumber].CnV = base->MOD * cnv;
		return kStatus_Success;
	}
	return kStatus_Fail;
}

