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
void test_servo(void *pvParameters) {
	/* Make sure POT ADC (ADC1) is initialized */
	for (;;) {
		servo_set(car_state->pot1);
        vTaskDelay(pdMS_TO_TICKS(10));
	}
}

/* Motor control with pot */
void test_motors(void *pvParameters) {
	motors_init();
	float speed = 0.0f;
	for (;;) {
		speed = car_state->pot1;
		throttle_control(&speed);
		motors_set(speed, speed);
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
