#pragma once

#define start_timer()	FTM_StartTimer(FTM3_PERIPHERAL, kFTM_SystemClock)
#define stop_timer()	FTM_StopTimer(FTM3_PERIPHERAL)
#define adc_CamStart()  __asm volatile("nop")

#define	  LINEMAXPIX	128

void CamScanStart();
void CamScanPix();
void PixRead();
