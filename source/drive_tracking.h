typedef struct {
	float steering;
	float speed;
	float error;
} TrackingState;

extern TrackingState *car_state;
