#pragma once

typedef struct {
	/* driving */
	int16_t steering;
	int16_t speed;
	/* camera */
	int16_t error;
	int16_t preverror;
	/* generic board */
	int16_t pot[2];
} TrackingState;

void init_tracking(void);
extern TrackingState *car_state;
