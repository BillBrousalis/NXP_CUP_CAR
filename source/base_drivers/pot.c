#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

/* written includes */
#include "drive_tracking.h"
#include "signals.h"

#include "pot.h"

int16_t pots_watch[2];
void pot_update(int chnl, int32_t val) {
	/* Normalize to (-100, 100) - no need for map function */
	car_state->pot[chnl] = -(int32_t)(-100 + ((float)val * 100.0f / POT_MID));
	pots_watch[chnl] = car_state->pot[chnl];
}
