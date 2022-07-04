typedef struct {
	/* driving */
	float steering;
	float speed;
	/* camera */
	float error;
	float preverror;
	/* generic board */
	float pot1;
	float pot2;
} TrackingState;

void init_tracking();
extern TrackingState *car_state;
