#include "includes.h"
#include "globals.h"
#include "pot_bat.h"

void adc1_vals_store(uint8_t chnl, uint32_t val)
{
	if(chnl < 2) {
		/* Normalize to (-100, 100) - no need for map function */
		car_state->pot[chnl] = -(int32_t)(-100 + ((float)val * 100.0f / POT_MID));
	}
	else {
		car_state->battery = val;
	}
}
