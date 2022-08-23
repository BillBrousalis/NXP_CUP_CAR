#include "includes.h"
#include "drive_tracking.h"

TrackingState s;
TrackingState *car_state = &s;

void init_tracking(void) {
	/* driving */
	car_state->steering = 0;
	car_state->speed = 0;
	/* camera */
	car_state->error = 0;
	car_state->preverror = 0;
	/* generic */
	car_state->pot[0] = 0;
	car_state->pot[1] = 0;
}
