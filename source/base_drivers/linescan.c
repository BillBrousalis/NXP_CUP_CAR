#include "fsl_adc16.h"
#include "peripherals.h"

#include "gpio.h"

#include "linescan.h"

uint8_t ls_clk_state = 0;
uint32_t adcout = 0;

void ls_clk_mng() {
	/* toggle clk state */
	ls_clk_state ^= 1;
	ls_clk_set(ls_clk_state);
	/* on falling edge call adc */
	if(!ls_clk_state)
		adcout = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0U);
}
