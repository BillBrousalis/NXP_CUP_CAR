#pragma once

//------------------------------------------
#define	LINEMAXPIX		128			// Number of pixels that cam reads
#define	LINEMINITER		129			// Minimum amount of iterations(clock cycles) required for a correctly executed read
//------------------------------------------
#define	LINECAM_RATE_15FPS		7560
#define	LINECAM_RATE_20FPS		5740
#define	LINECAM_RATE_25FPS		4615
#define	LINECAM_RATE_50FPS		2275
//------------------------------------------
#define	F_PI	3.141592653589793f
//------------------------------------------
#define start_timer()	FTM_StartTimer(FTM3_PERIPHERAL, kFTM_SystemClock)
#define stop_timer()	FTM_StopTimer(FTM3_PERIPHERAL)
//------------------------------------------
void LineCamInit(void);
void LineCamProcess(void);
void CamScanStart(void);
void CamScanPix(void);
void PixRead(void);
uint32_t LineCamGetLast(uint8_t *buff);

extern uint8_t LinePixInProgress;						// if 1 line scan is currently in progress
