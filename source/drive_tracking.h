typedef struct {
	/* driving */
	float steering;
	float speed;
	/* camera */
	float error;
	float preverror;
	/* generic board */
	float pot[2];
} TrackingState;

void init_tracking();
extern TrackingState *car_state;
