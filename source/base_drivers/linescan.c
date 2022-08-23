//============================================================================================================
//!	linescan.c
//============================================================================================================
//  Pixel budget: timer interrupt ~ 4.2uS +  adc interrupt ~1.85uS  -> total ~ 6uS
//  Total CPU load 6us/330uS = 1.8%
//============================================================================================================
#include "includes.h"
//============================================================================================================
#define	LINECAM_RATE_FPS		LINECAM_RATE_25FPS
//------------------------------------------
#define	LENS_COSINE_CORRECTION

#ifdef 	LENS_COSINE_CORRECTION
//============================================================================================================
// cosine correction table total 55deg  (+/-27.5Deg)
//============================================================================================================
//---------- 55* deg Table ---------
//const float CosTable[128] = {1.1273820675880772, 1.1229955198345052, 1.1187066401355177, 1.1145138263957097, 1.1104155260450654, 1.1064102344955917, 1.1024964936621942, 1.0986728905448913, 1.0949380558696205, 1.091290662785032, 1.087729425612804, 1.0842530986491463, 1.080860475015273, 1.0775503855547495, 1.074321697775719, 1.071173314836124, 1.068104174570126, 1.065113248554031, 1.0621995412100973, 1.059362088946705, 1.056599959333424, 1.0539122503096043, 1.0512980894251787, 1.0487566331124263, 1.0462870659875225, 1.0438886001807448, 1.041560474694271, 1.0393019547865556, 1.037112331382318, 1.0349909205072347, 1.0329370627464582, 1.030950122726146, 1.0290294886172069, 1.0271745716605314, 1.0253848057129917, 1.023659646813545, 1.0219985727688052, 1.0204010827574799, 1.0188666969531024, 1.0173949561645161, 1.0159854214936035, 1.014637674009772, 1.01335131444074, 1.012125962879194, 1.0109612585049066, 1.00985685932193, 1.0088124419105116, 1.0078277011933827, 1.006902350216112, 1.0060361199412184, 1.0052287590557734, 1.0044800337922282, 1.0037897277622319, 1.003157641803215, 1.0025835938375383, 1.002067418744017, 1.001608968241657, 1.001208110785441, 1.000864731474039, 1.000578731969313, 1.0003500304275146, 1.0001785614420882, 1.000064275998, 1.000007141437539, 1.000007141437539, 1.000064275998, 1.0001785614420882, 1.0003500304275146, 1.000578731969313, 1.000864731474039, 1.001208110785441, 1.001608968241657, 1.002067418744017, 1.0025835938375383, 1.003157641803215, 1.0037897277622319, 1.0044800337922282, 1.0052287590557734, 1.0060361199412184, 1.006902350216112, 1.0078277011933827, 1.0088124419105116, 1.00985685932193, 1.0109612585049066, 1.012125962879194, 1.01335131444074, 1.014637674009772, 1.0159854214936035, 1.0173949561645161, 1.0188666969531024, 1.0204010827574799, 1.0219985727688052, 1.023659646813545, 1.0253848057129917, 1.0271745716605314, 1.0290294886172069, 1.030950122726146, 1.0329370627464582, 1.0349909205072347, 1.037112331382318, 1.0393019547865556, 1.041560474694271, 1.0438886001807448, 1.0462870659875225, 1.0487566331124263, 1.0512980894251787, 1.0539122503096043, 1.056599959333424, 1.059362088946705, 1.0621995412100973, 1.065113248554031, 1.068104174570126, 1.071173314836124, 1.074321697775719, 1.0775503855547495, 1.080860475015273, 1.0842530986491463, 1.087729425612804, 1.091290662785032, 1.0949380558696205, 1.0986728905448913, 1.1024964936621942, 1.1064102344955917, 1.1104155260450654, 1.1145138263957097, 1.1187066401355177, 1.1229955198345052, 1.1273820675880772 };
//---------- 80* deg Table ---------
const float CosTable[128] = {1.305407617068643, 1.2935527016911932, 1.2820647369633984, 1.2709312907852797, 1.2601405490383033, 1.2496812794600143, 1.239542798072898, 1.229714937961002, 1.2201880202067628, 1.2109528268174863, 1.2020005754862226, 1.193322896045537, 1.1849118084850943, 1.1767597024151812, 1.1688593178684097, 1.1612037273410094, 1.1537863189834152, 1.1466007808573795, 1.1396410861836672, 1.1329014795106, 1.1263764637393625, 1.1200607879471223, 1.1139494359537048, 1.108037615581839, 1.1023207485648925, 1.0967944610595932, 1.0914545747244928, 1.086297098327926, 1.0813182198519675, 1.076514299061393, 1.0718818605089853, 1.0674175869506346, 1.0631183131456508, 1.0589810200195087, 1.055002829167907, 1.0511809976825592, 1.0475129132805547, 1.0439960897204388, 1.040628162489376, 1.0374068847468874, 1.034330123511697, 1.031395856079195, 1.0286021666579246, 1.0259472432143477, 1.0234293745159158, 1.0210469473632209, 1.0187984440026738, 1.0166824397117993, 1.0146976005498507, 1.0128426812669933, 1.0111165233658566, 1.0095180533097459, 1.0080462808722814, 1.0067002976236867, 1.0054792755493702, 1.0043824657968554, 1.0034091975475012, 1.0025588770098268, 1.0018309865316155, 1.0012250838283145, 1.0007408013255834, 1.000377845614166, 1.000135997015581, 1.0000151092574292, 1.0000151092574292, 1.000135997015581, 1.000377845614166, 1.0007408013255834, 1.0012250838283145, 1.0018309865316155, 1.0025588770098268, 1.0034091975475012, 1.0043824657968554, 1.0054792755493702, 1.0067002976236867, 1.0080462808722814, 1.0095180533097459, 1.0111165233658566, 1.0128426812669933, 1.0146976005498507, 1.0166824397117993, 1.0187984440026738, 1.0210469473632209, 1.0234293745159158, 1.0259472432143477, 1.0286021666579246, 1.031395856079195, 1.034330123511697, 1.0374068847468874, 1.040628162489376, 1.0439960897204388, 1.0475129132805545, 1.0511809976825592, 1.055002829167907, 1.0589810200195087, 1.0631183131456508, 1.0674175869506346, 1.0718818605089853, 1.076514299061393, 1.0813182198519675, 1.086297098327926, 1.0914545747244928, 1.0967944610595932, 1.1023207485648925, 1.1080376155818388, 1.1139494359537045, 1.120060787947122, 1.1263764637393623, 1.1329014795106, 1.1396410861836672, 1.1466007808573795, 1.1537863189834152, 1.1612037273410094, 1.1688593178684097, 1.1767597024151812, 1.1849118084850943, 1.193322896045537, 1.2020005754862226, 1.2109528268174863, 1.2201880202067625, 1.2297149379610017, 1.2395427980728975, 1.2496812794600143, 1.2601405490383033, 1.2709312907852797, 1.2820647369633984, 1.2935527016911932, 1.305407617068643};
#endif
//============================================================================================================
uint8_t	LinePixInProgress = 0;						// if 1 line scan is currently in progress
static uint8_t clk_state;
static uint32_t clk_count;
static uint16_t LCamData[LINEMAXPIX];				// This is the work buffer of the line cam process - do not use
#define LC_MAX_ENTRIES	3
uint16_t LineCamData[LC_MAX_ENTRIES][LINEMAXPIX];	// Contains the last line scanned - triple buffering may be necessary
static uint32_t PixCount = 0;
uint32_t LineCam_Inntensity;
uint32_t LineCamIdx = 0;
extern TaskHandle_t LineCam_handle;
QueueHandle_t LCqueue;
//============================================================================================================
//
//============================================================================================================
void LineCamInit(void) {
	LineCam_Inntensity = LINECAM_RATE_FPS;
	LCqueue = xQueueCreate(3, sizeof(unsigned long));
	if( LCqueue == NULL ) {
		/* Queue was not created and must not be used. */
	}
}
//============================================================================================================
//
//============================================================================================================
static inline void adc_CamStart(void) {
	uint32_t sc1;
	sc1 = ADC0_PERIPHERAL->SC1[0];			// Trigger an AD conversion - FixMe
	ADC0_PERIPHERAL->SC1[0] = sc1;
}
//============================================================================================================
//
//============================================================================================================
void CamScanStart(void) {
	dbg2_tog();
	//LineCam_Inntensity = 100 + (uint32_t)(car_state->pot[0] * 10000.0F);
	LinePixInProgress = 1;											// If == 1 then Line scan is in progress
	ls_si_set();
	FTM_SetTimerPeriod(FTM3_PERIPHERAL, LineCam_Inntensity);  		// This one between SI(H) and CLK(H) guarantees that Tsu>20nS (per man page 9)
	ls_clk_set();
	clk_state = 1;													// Clock current state (H/L)
	clk_count = 0;
	PixCount = 0;													// Reset the pixel count
	ls_si_clr();													// Clear the SI signal
	start_timer();
}

//============================================================================================================
//		This is called from Timer int.
//		WARNING: Clock states are inverted since we are using the buffered camera CLK input
//		for better noise immunity
//============================================================================================================
void CamScanPix(void) {
	if(clk_state == 0) {
		if(clk_count++ >= LINEMINITER) {
			stop_timer();
			LinePixInProgress = 0;
			return;
		}
		ls_clk_set();
		clk_state = 1;
	}
	else {
		ls_clk_clr();
		clk_state = 0;
		adc_CamStart();												// initiate next pixel read
	}
}
//============================================================================================================
//			Called from ADC complete int to store the next pixel
//============================================================================================================
void PixRead(void) {
	if(PixCount < LINEMAXPIX) {
	#ifdef LENS_COSINE_CORRECTION
		float tmp = (float)(ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U) << 4);		// Convert to 16bit
		tmp *= CosTable[PixCount];
		/* overflow protection */
		if(tmp>65535.0f) tmp = 65535.0f;
		LCamData[PixCount++] = (uint16_t)tmp;
	#else
		LCamData[PixCount++] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U) << 4;	// Convert to 16bit
	#endif
	}
	else {
		/* Make read without storing value - complete LINEMINITER reads*/
		ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U);
	}
}

//============================================================================================================
//	Main camera process - MUST be called in constant loop
//============================================================================================================
void LineCamProcess(void) {
	UBaseType_t self_priority;
	CamScanStart();																			// Scan one line
	while(LinePixInProgress) osDelay(1);													// wait for the background processes to finish
	self_priority = uxTaskPriorityGet(LineCam_handle);										// Save task's original priority - if it is fixed we could save some time here later
	vTaskPrioritySet(LineCam_handle, MAX_TASK_PRIO);										// escalate task priority to avoid transaction corruption
	if(LCqueue != 0) {
		if(xQueueSend(LCqueue, (void *)&LineCamIdx, (TickType_t)0 ) != pdPASS) { 			// try to send the index to queue
			/* Failed to post the message, even after 10 ticks. */
		}
		else {
			uint16_t *LCptr = &LineCamData[LineCamIdx++][0];								// Index is already queued
			memcpy((uint16_t *)LCptr, (uint16_t *)LCamData, LINEMAXPIX*sizeof(uint16_t));	// Copy the actual data
			if(LineCamIdx >= LC_MAX_ENTRIES) LineCamIdx = 0;								// circulate buffer
		}
	}
	vTaskPrioritySet(LineCam_handle, self_priority);										// Restore task's original priority
}
//============================================================================================================
//
//============================================================================================================
uint32_t LineCamGetLast(uint8_t *buff) {
	uint32_t i;
	if(LCqueue != 0) {															// Check if queue is created
		if(xQueuePeek(LCqueue, &i, (TickType_t)10) == pdPASS) {					// check if new entry is available but do not remove yet to guarantee atomicity
			uint16_t *LCptr = &LineCamData[i][0];								// Get the right pointer
			for(uint8_t z=0; z<LINEMAXPIX; z++) {
				buff[z] = LCptr[z] >> 8;										// ShiftR 8 because buff is uint8_t type
			}
			xQueueReceive(LCqueue, &i, (TickType_t)0);							// Now remove the entry and free the associated resource
			return 1;
		}
		//----------------------------------------------------
		else {
			return 0;
		}
	}
	return 0;
}
//============================================================================================================
//	TBD -
//============================================================================================================
uint32_t LineCamAutoCalibrate(void) {
	return 0;
}
