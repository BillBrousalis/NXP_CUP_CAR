#include "includes.h"
#include "base_drivers/servo.h"
#include "base_drivers/motors.h"
#include "safety/safety.h"
#include "globals.h"

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
	static RequestedState reqstate = {.req_speed = 0, .req_steer = 0};
	while(!CarInitialized) osDelay(1);
	for (;;) {
		reqstate.req_speed = car_state->pot[0];
		reqstate.req_steer = car_state->pot[1];
		xQueueSend(CarControlQueueHandle, &reqstate, (TickType_t)1);
		osDelay(50);
	}
}
