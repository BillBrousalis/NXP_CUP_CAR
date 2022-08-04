//============================================================================================================
//
//============================================================================================================
#include "includes.h"
//============================================================================================================
uint8_t	LinePixInProgress = 0;						// if 1 line scan is currently in progress
static uint8_t clk_state;
static uint32_t clk_count;
static uint16_t  LineCamData[LINEMAXPIX + 2];		// Contains the last line scanned - Double buffering may be necessary
static uint32_t  PixCount = 0;

uint32_t	LineCam_Inntensity = 1400;				//FTM3_TIMER_MODULO_VALUE  -- usable range 110 - 11000 counts


SemaphoreHandle_t xSemaphoreLineCam = NULL;
//============================================================================================================
//
//============================================================================================================
void LineCamInit(void)
{
	xSemaphoreLineCam = xSemaphoreCreateMutex();			// Create a mutex for Line cam array copy safety
}
//============================================================================================================
//
//============================================================================================================
static inline void adc_CamStart()
{
	uint32_t sc1;
	dbg2_set();								// Debug pin --- Remove
	sc1 = ADC0_PERIPHERAL->SC1[0];			// Trigger an AD conversion
	ADC0_PERIPHERAL->SC1[0] = sc1;
}
//============================================================================================================
//
//============================================================================================================
void CamScanStart() {
	LinePixInProgress = 1;											// If == 1 then Line scan is in progress
	ls_si_set();
	FTM_SetTimerPeriod(FTM3_PERIPHERAL, LineCam_Inntensity);  		// This one between SI(H) and CLK(H) guarantees that Tsu>20nS (per man page 9)
    ls_clk_set();
    clk_state = 1;													// Clock current state (H/L)
    clk_count = 0;
    PixCount = 0;													// Reset the pixel counet
    ls_si_clr();													// Clear the SI signal
    start_timer();
}

//============================================================================================================
//			 Called from Timer int
//============================================================================================================
void CamScanPix() {
	stop_timer();
	if(clk_state == 0) {
		if(clk_count++ >= LINEMAXPIX)
		{
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
	FTM_SetTimerPeriod(FTM3_PERIPHERAL, LineCam_Inntensity);	// Restart timer for the next state
	start_timer();
}
//============================================================================================================
//			From ADC complete int
//============================================================================================================
void PixRead() {
	dbg2_clr();						// Debug pin --- Remove
	if(PixCount <= LINEMAXPIX)
		LineCamData[PixCount++] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U);
	else {
		// overrun bullshit
	}
}

//============================================================================================================
//
//============================================================================================================
void 	LineCamProcess(void)
{
	if( xSemaphoreLineCam != NULL )														// Make sure that semaphore is valid before use
	{
		if( xSemaphoreTake( xSemaphoreLineCam, ( TickType_t )portMAX_DELAY ) == pdTRUE )
		{
			CamScanStart();																// Scan one line
			while(LinePixInProgress){
				osDelay(1);
			}
			xSemaphoreGive( xSemaphoreLineCam );												// Release the semaphore - Scan is finished
		}
		else
		{
			osDelay(1);
		}
	}
	osDelay(20);
}
//============================================================================================================
//
//============================================================================================================
uint32_t LineCamGetLast(uint8_t *buff)
{
	if( xSemaphoreLineCam != NULL ){													// Make sure that semaphore is valid before use
		if( xSemaphoreTake( xSemaphoreLineCam, ( TickType_t ) 100 ) == pdTRUE )			// Take the semaphore to safeguard the copy
		{
			memcpy(buff, LineCamData, 128);												// copy the working pixel array to user mem
			xSemaphoreGive( xSemaphoreLineCam );												// release the semaphore and let the camera go
			return(1);
		}
		else
		{
			return(0);																	// Failed to take the semaphore - something is wrong
		}
	}
	return(0);
}

//============================================================================================================
//============================================================================================================
