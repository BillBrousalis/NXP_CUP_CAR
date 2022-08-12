#include "drive_tracking.h"

TrackingState s;
TrackingState *car_state = &s; //malloc(sizeof(TrackingState));

void init_tracking(void) {
	/* driving */
	car_state->steering = 0.0f;
	car_state->speed = 0.0f;
	/* camera */
	car_state->error = 0.0f;
	car_state->preverror = 0.0f;
	/* generic */
	car_state->pot[0] = 0.0f;
	car_state->pot[1] = 0.0f;
}
