typedef struct {
	/* driving */
	float steering;
	float speed;
	float error;

	/* generic */
	float pot1;
	float pot2;
} TrackingState;

extern TrackingState *car_state;
