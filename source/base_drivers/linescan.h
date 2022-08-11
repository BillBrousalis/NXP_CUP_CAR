#pragma once

#define start_timer()	FTM_StartTimer(FTM3_PERIPHERAL, kFTM_SystemClock)
#define stop_timer()	FTM_StopTimer(FTM3_PERIPHERAL)

#define	LINEMAXPIX		128
#define	LINEMINITER		129

void LineCamInit(void);
void LineCamProcess(void);
void CamScanStart(void);
void CamScanPix(void);
void PixRead(void);
uint32_t LineCamGetLast(uint8_t *buff);

extern uint8_t LinePixInProgress;						// if 1 line scan is currently in progress
