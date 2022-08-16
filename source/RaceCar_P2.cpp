//////////////////////////////////////////////////////////////
/////////          		NXP CAR 2023        		 /////////
//////////////////////////////////////////////////////////////
extern "C"
{
#include "includes.h"
}

//------------------------------------
/* Task Handles */
TaskHandle_t PotsUpdate_handle;
TaskHandle_t TestCam_handle;
TaskHandle_t LineCam_handle;
TaskHandle_t Commands_handle;
//------------------------------------
TaskHandle_t TestAll_handle;

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

    //------------------------------------------------------
    /* Start Camera Reading Task */
    //xTaskCreate(LineCam_task, "LineCam_task", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &LineCam_handle);
    /* Start Pots Reading Task */
    //xTaskCreate(PotsUpdate_task, "PotsUpdate_task", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &PotsUpdate_handle);
    //------------------------------------------------------
    /* Switch-Based Mode Startup */
    if(SW1_read() == 1) xTaskCreate(test_all, "Test All", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &TestAll_handle);
    else if(SW2_read() == 1) xTaskCreate(TestCam_task, "Test Cam", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &TestCam_handle);
    else if(SW3_read() == 1) xTaskCreate(Commands_task, "COMMANDS", configMINIMAL_STACK_SIZE * 8, NULL, DEFAULT_TASK_PRIO, &Commands_handle);
    //------------------------------------------------------
    /* Start Tasks */
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
