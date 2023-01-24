#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

#include "signals.h"

status_t FTM_SetPpm(FTM_Type *base, ftm_chnl_t chnlNumber, ftm_pwm_mode_t pwm_mode, float perc)
{
	/* range checking */
	if(perc >= 100.0f || perc <= 0) {
		return kStatus_OutOfRange;
	}
	if(pwm_mode == kFTM_EdgeAlignedPwm) {
		float cnv = FTM2_PPM_MIN + ((FTM2_PPM_MAX - FTM2_PPM_MIN) * (perc / 100.0f));
		base->CONTROLS[chnlNumber].CnV = (uint32_t)cnv;
		return kStatus_Success;
	}
	return kStatus_Fail;
}


status_t FTM_PpmInit(FTM_Type *base, ftm_chnl_t chnlNumber) {
	base->CONTROLS[chnlNumber].CnV = (uint32_t)FTM2_PPM_CENTER;
	return kStatus_Success;
}
