#pragma once

#define start_timer()	FTM_StartTimer(FTM3_PERIPHERAL, kFTM_SystemClock)
#define stop_timer()	FTM_StopTimer(FTM3_PERIPHERAL)
//#define adc_CamStart()  __asm volatile("nop")

#define	  LINEMAXPIX	129

void LineCamInit(void);
void LineCamProcess(void);
void CamScanStart();
void CamScanPix();
void PixRead();
uint32_t LineCamGetLast(uint8_t *buff);


extern uint8_t	LinePixInProgress;						// if 1 line scan is currently in progress
