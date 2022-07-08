#include "fsl_adc16.h"
#include "peripherals.h"
#include "gpio.h"
#include "linescan.h"

static uint8_t clk_state;
static uint32_t clk_count;

static uint16_t  LinePixTmp[LINEMAXPIX];
static uint32_t  PixCount = 0;

void CamScanStart() {
	ls_si_set();
	FTM_SetTimerPeriod(FTM3_PERIPHERAL, FTM3_TIMER_MODULO_VALUE);
    ls_clk_set();
    for(int i=0; i<10; i++)
		__asm volatile ("nop");
    clk_count = 0;
    PixCount = 0;
    clk_state = 1;
    ls_si_clr();
    start_timer();
}

//------------------------ From Timer int --------------
void CamScanPix() {
	if(clk_state == 0) {
		if(clk_count++ > 127) {
			stop_timer();
			CamScanStart();
			return;
		}
		ls_clk_set();
		clk_state = 1;
		start_timer();
	}
	else {
		ls_clk_clr();
		clk_state = 0;
		adc_CamStart();
		start_timer();
	}
}

//----------------------- From ADC complete int ------------------------
void PixRead() {
	if(PixCount <= LINEMAXPIX)
		LinePix[PixCount++] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U);
	else {
		// overrun bullshit
	}
}
