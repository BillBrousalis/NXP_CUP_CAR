//////////////////////////////////////////////////////////////
/////////          		NXP CAR 2023        		 /////////
//////////////////////////////////////////////////////////////
extern "C"
{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* TODO: insert other include files here. */
#include "drive_tracking.h"
#include "base_drivers/servo.h"
#include "base_drivers/motors.h"
#include "tests/pot_testing.h"
}

#include "irq_handler.h"

/* TODO: insert other definitions and declarations here. */
#define DEFAULT_TASK_PRIO (configMAX_PRIORITIES - 2)

void default_task(void *pvParameters);
TaskHandle_t default_handle;

/*
 * @brief   Application entry point.
 */
int main(void) {
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#if 0 //#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    //xTaskCreate(default_task, "Default task", configMINIMAL_STACK_SIZE, NULL, DEFAULT_TASK_PRIO, &default_handle);
    xTaskCreate(test_all, "Default task", configMINIMAL_STACK_SIZE, NULL, DEFAULT_TASK_PRIO, NULL);
    vTaskStartScheduler();
    for(;;);

    /* Force the counter to be placed into memory. */
    volatile static int i = 0;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}


/*
void default_task(void *pvParameters) {
	for (;;) {
		steer_set(car_state->pot1);
        vTaskDelay(pdMS_TO_TICKS(10));
	}
}
*/
