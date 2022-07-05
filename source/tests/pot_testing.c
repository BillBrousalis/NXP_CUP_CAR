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

#include "pot_testing.h"

/* Servo control with pot */
void test_steer(void *pvParameters) {
    /* INITIALIZATION FUNCTIONS HERE */
    init_tracking();
	/*
	motors_init();
    servo_center();
    motors_stop();
    */

	/* Make sure POT ADC (ADC1) is initialized */
	for (;;) {
		steer_set(car_state->pot[0]);
		vTaskDelay(pdMS_TO_TICKS(5));
	}

}

/* Motor control with pot */
void test_motors(void *pvParameters) {
    /* INITIALIZATION FUNCTIONS HERE */
    init_tracking();
	motors_init();
    servo_center();
    motors_stop();

	vTaskDelay(pdMS_TO_TICKS(1000));
	servo_set(0.5f);
	float speed = 0.0f;
	for (;;) {
		speed = car_state->pot[0];
		speed_set(speed);
		vTaskDelay(pdMS_TO_TICKS(5));
	}
}

void test_all(void *pvParameters) {
    /* INITIALIZATION FUNCTIONS HERE */
    init_tracking();
	motors_init();
    servo_center();
    motors_stop();

	vTaskDelay(pdMS_TO_TICKS(1000));
	float speed = 0.0f;
	float steer = 0.0f;
	for (;;) {
		speed = car_state->pot[0];
		steer = car_state->pot[1];
		speed_set(speed);
		steer_set(steer);
		vTaskDelay(pdMS_TO_TICKS(5));
	}
}
