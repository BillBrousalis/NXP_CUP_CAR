#include "drive_tracking.h"

TrackingState s;
TrackingState *car_state = &s; //malloc(sizeof(TrackingState));

/*
void init_tracking() {
	car_state->steering = 0.0f;
	car_state->speed = 0.0f;
	car_state->error = 0.0f;
}
*/
