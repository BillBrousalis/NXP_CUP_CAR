#ifndef GLOBALS_H_
#define GLOBALS_H_
//-------------------
typedef struct {
	/* driving */
	int16_t steering;
	int16_t speed;
	/* camera */
	int16_t error;
	int16_t preverror;
	/* generic board */
	int16_t pot[2];
	int16_t battery;
} TrackingState;
//-------------------
typedef struct {
	int16_t req_speed;
	int16_t req_steer;
} RequestedState;
//-------------------
void init_tracking(void);
//-------------------
extern QueueHandle_t CarControlQueueHandle;
extern TaskHandle_t Housekeeping_handle;
extern TaskHandle_t Car_handle;
extern TaskHandle_t PotsBatUpdate_handle;
extern TaskHandle_t TestCam_handle;
extern TaskHandle_t LineCam_handle;
extern TaskHandle_t Commands_handle;
//-------------------
extern TaskHandle_t TestAll_handle;
//-------------------
extern SemaphoreHandle_t adc1_Semaphore;
//-------------------
extern TrackingState *car_state;
//-------------------
extern uint32_t adc1_result;
//-------------------
extern int32_t CarInitialized;

#endif
