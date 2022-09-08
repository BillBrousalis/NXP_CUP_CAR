#ifndef SIGNALS_H_
#define SIGNALS_H_
//---------------------------------------------------------------------------------------------
#define	FTM2_COUNTS_PER_US		1.88f
#define	FTM2_PPM_CENTER			FTM2_COUNTS_PER_US * 1500.0f
#define	FTM2_PPM_MIN          	FTM2_COUNTS_PER_US * 1000.0f
#define	FTM2_PPM_MAX            FTM2_COUNTS_PER_US * 2000.0f
//---------------------------------------------------------------------------------------------
status_t FTM_SetPpm(FTM_Type *base, ftm_chnl_t chnlNumber, ftm_pwm_mode_t pwm_mode, float perc);
status_t FTM_PpmInit(FTM_Type *base, ftm_chnl_t chnlNumber);

#endif
