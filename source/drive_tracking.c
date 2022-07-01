#include "drive_tracking.h"

TrackingState *car_state;

void init_tracking() {
	car_state->steering = 0.0f;
	car_state->speed = 0.0f;
	car_state->error = 0.0f;
}
