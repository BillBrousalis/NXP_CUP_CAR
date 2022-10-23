//////////////////////////////////////////////////////////////
/////////          		NXP CAR 2023        		 /////////
//////////////////////////////////////////////////////////////
extern "C"
{
#include "includes.h"
#include "globals.h"
#include "car_tasks/car_tasks.h"
#include "tests/pot_testing.h"
#include "base_drivers/gpio.h"
}
//-----------------------------------------------------------------------------------------
//  @brief Application entry point.
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

    adc1_Semaphore = xSemaphoreCreateBinary();
    CarControlQueueHandle = xQueueCreate((UBaseType_t)3, (UBaseType_t)sizeof(RequestedState));
    //------------------------------------------------------
    /* Start Initialization / Housekeeping task */
    xTaskCreate(Housekeeping_task, "Housekeeping", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &Housekeeping_handle);
    //------------------------------------------------------
    /* Start Initialization / Housekeeping task */
    xTaskCreate(Car_task, "Car", configMINIMAL_STACK_SIZE * 4, NULL, HIGH_TASK_PRIO, &Car_handle);
    //------------------------------------------------------
    /* Start Pots Reading Task */
    xTaskCreate(PotsBatUpdate_task, "PotsBatUpdate_task", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &PotsBatUpdate_handle);
    /* Start Camera Reading Task */
    xTaskCreate(LineCam_task, "LineCam_task", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &LineCam_handle);
    //------------------------------------------------------
    /* Switch-Based Mode Startup */
    if(SW1_read() == 1) 	 	xTaskCreate(test_all, "Test All", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &TestAll_handle);
    //else if(SW2_read() == 1)	xTaskCreate(TestCam_task, "Test Cam", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &TestCam_handle);
    if(SW3_read() == 1)	xTaskCreate(Commands_task, "COMMANDS", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &Commands_handle);
    else if(SW4_read() == 1) xTaskCreate(NativeControl_task, "Native", configMINIMAL_STACK_SIZE * 12, NULL, DEFAULT_TASK_PRIO, &NativeControl_handle);
    //------------------------------------------------------
    /* Start Tasks */
    vTaskStartScheduler();
    /* Shouldn't get here */
    for(;;);
    /* Force the counter to be placed into memory. */
    volatile static int i = 0;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

