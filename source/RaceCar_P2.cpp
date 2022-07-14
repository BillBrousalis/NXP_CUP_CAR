//////////////////////////////////////////////////////////////
/////////          		NXP CAR 2023        		 /////////
//////////////////////////////////////////////////////////////
extern "C"
{
#include "includes.h"
}

//-----------------------------------------------------------------------------------------

/* TODO: insert other definitions and declarations here. */
#define DEFAULT_TASK_PRIO (configMAX_PRIORITIES - 2)

void default_task(void *pvParameters);
TaskHandle_t default_handle;

//-----------------------------------------------------------------------------------------
//  @brief   Application entry point.
//-----------------------------------------------------------------------------------------
int main(void) {
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#if 0 //#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    xTaskCreate(default_task, "Default task", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &default_handle);
    //xTaskCreate(test_all, "Default task", configMINIMAL_STACK_SIZE, NULL, DEFAULT_TASK_PRIO, NULL);
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
//-----------------------------------------------------------------------------------------
//		Default task
//-----------------------------------------------------------------------------------------
void default_task(void *pvParameters) {

	fileSyetemInit();
	for (;;) {
		LineCamProcess();
	}
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
