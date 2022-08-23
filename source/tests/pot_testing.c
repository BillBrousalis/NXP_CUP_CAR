/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* written includes */
#include "drive_tracking.h"
#include "base_drivers/servo.h"
#include "base_drivers/motors.h"
#include "safety/safety.h"
#include "defines.h"

#include "pot_testing.h"

//============================================================================================================
// Control Steering with Pot
//============================================================================================================
void test_steer(void *pvParameters) {
	/* Make sure POT ADC (ADC1) is initialized */
	for (;;) {
		steer_set(car_state->pot[0]);
		osDelay(10);
	}

}
//============================================================================================================
// Control Motor Speed with Pot
//============================================================================================================
void test_motors(void *pvParameters) {
	osDelay(1000);
	for (;;) {
		speed_set(car_state->pot[0]);
		osDelay(10);
	}
}

//============================================================================================================
// Control Motor Speed + Steering with both Pots
//============================================================================================================
void test_all(void *pvParameters) {
    /* INITIALIZATION FUNCTIONS HERE */
    init_tracking();
    motors_init();
    servo_center();
    motors_stop();
	osDelay(1000);
	for (;;) {
		speed_set(car_state->pot[0]);
		steer_set(car_state->pot[1]);
		osDelay(10);
	}
}
