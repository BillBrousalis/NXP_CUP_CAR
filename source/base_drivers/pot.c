#include "fsl_ftm.h"
#include "peripherals.h"
#include "fsl_debug_console.h"

/* written includes */
#include "drive_tracking.h"
#include "signals.h"

#include "pot.h"

#define POT_MAX 4095.0f
#define POT_MID (POT_MAX / 2.0f)

void pot_update(int32_t val1, int32_t val2) {
	/* Normalize to (-1, 1) - no need for map function */
	car_state->pot1 = -(float)(-1.0f + ((float)val1 / POT_MID));
	//car_state->pot2 = (float)(-1.0f + ((float)val2 / POT_MID));
}
