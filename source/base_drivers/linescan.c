//============================================================================================================
//!	linecam.c
//!
//============================================================================================================
//  Pixel budget : timer interrupt ~ 4.2uS +  adc interrupt ~1.85uS  -> total ~ 6uS
//  Total CPU load 6us/330uS = 1.8%
//============================================================================================================
#include "includes.h"
//============================================================================================================
#define   LINECAM_RATE_15FPS		7560
#define   LINECAM_RATE_20FPS		5740
#define   LINECAM_RATE_25FPS		4615
#define   LINECAM_RATE_50FPS		2275
//------------------------------------------
#define   LINECAM_RATE_FPS			LINECAM_RATE_25FPS
//============================================================================================================
uint8_t	LinePixInProgress = 0;						// if 1 line scan is currently in progress
static uint8_t clk_state;
static uint32_t clk_count;
static uint16_t  LCamData[LINEMAXPIX + 2];			// This is the work buffer of the line cam process - do not use
#define LC_MAX_ENTRIES	3
uint16_t  LineCamData[LC_MAX_ENTRIES][LINEMAXPIX + 2];				// Contains the last line scanned - triple buffering may be necessary
static uint32_t  PixCount = 0;
uint32_t	LineCam_Inntensity;						//
SemaphoreHandle_t xSemaphoreLineCam = NULL;
uint32_t  LineCamIdx = 0;
extern TaskHandle_t LineCam_handle;
QueueHandle_t LCqueue;
//============================================================================================================
//
//============================================================================================================
void LineCamInit(void)
{
	LineCam_Inntensity = LINECAM_RATE_FPS;
	LCqueue = xQueueCreate( 3, sizeof( unsigned long ) );
    if( LCqueue == NULL )
    {
        /* Queue was not created and must not be used. */
    }
	xSemaphoreLineCam = xSemaphoreCreateMutex();			// Create a mutex for Line cam array copy safety
}
//============================================================================================================
//
//============================================================================================================
static inline void adc_CamStart()
{
	uint32_t sc1;
	sc1 = ADC0_PERIPHERAL->SC1[0];			// Trigger an AD conversion
	ADC0_PERIPHERAL->SC1[0] = sc1;
}
//============================================================================================================
//
//============================================================================================================
void CamScanStart() {

	dbg2_tog();							// Debug pin --- Remove
	//LineCam_Inntensity = 100 + (uint32_t)(car_state->pot[0] * 10000.0F);

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
//		This is called from Timer int.
//		WARNING : Clock states are inverted since we are using the buffered camera CLK input
//		for better noise immunity
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
//			Called from ADC complete int to store the next pixel
//============================================================================================================
void PixRead() {
	if(PixCount <= LINEMAXPIX)
		LCamData[PixCount++] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U);
	else {
		// overrun bullshit
	}
}

//============================================================================================================
//	Main camera process - MUST be called in constant loop
//============================================================================================================
void 	LineCamProcess(void)
{
	UBaseType_t self_priority;

	CamScanStart();																		// Scan one line
	while(LinePixInProgress){															// wait for the background processes to finish
		osDelay(1);
	}

	self_priority = uxTaskPriorityGet( LineCam_handle );								// Save task's original priority - if it is fixed we could save some time here later
	vTaskPrioritySet( LineCam_handle, MAX_TASK_PRIO );									// escalate task priority to avoid transaction corruption

	if( LCqueue != 0 )
    {
        if( xQueueSend( LCqueue, ( void * ) &LineCamIdx, ( TickType_t ) 0 ) != pdPASS )	// try to send the index to queue
        {
            /* Failed to post the message, even after 10 ticks. */
        }
        else
        {
        	uint16_t  *LCptr = &LineCamData[LineCamIdx++][0];							// Index is already queued
        	memcpy(LCptr, LCamData, 128);												// Copy the actual data
        	if(LineCamIdx >= LC_MAX_ENTRIES) LineCamIdx = 0;							// circulate buffer
        }
    }
	vTaskPrioritySet( LineCam_handle, self_priority );									// Restore task's origina priority
}

//============================================================================================================
//Z
//============================================================================================================
uint32_t LineCamGetLast(uint8_t *buff)
{
	uint32_t i;


	if(LCqueue != 0)															// Check if queue is created
	{
		if( xQueueReceive( LCqueue, &i,( TickType_t ) 10 ) == pdPASS )			// check if new entry is available
		{
			uint16_t  *LCptr = &LineCamData[i][0];								// Get the right pointer
			memcpy(buff , LCptr, 128);
			return(1);
		}
		else
		{
			return(0);
		}
	}
}
//============================================================================================================

//============================================================================================================
//	TBD -
//============================================================================================================
uint32_t	LineCamAutoCalibrate(void)
{


}
//============================================================================================================
//============================================================================================================
