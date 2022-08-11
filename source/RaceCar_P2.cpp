//////////////////////////////////////////////////////////////
/////////          		NXP CAR 2023        		 /////////
//////////////////////////////////////////////////////////////
extern "C"
{
#include "includes.h"
}

//-----------------------------------------------------------------------------------------
void default_task(void *pvParameters);
void LineCam_task(void *pvParameters);
TaskHandle_t default_handle;
TaskHandle_t LineCam_handle;

uint8_t Sbuf[128];
uint8_t	LineCam_IsInit = 0;

#define 	LED_DRIVE		720U						//750U // 350mA

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
    xTaskCreate(LineCam_task, "LineCam_task", configMINIMAL_STACK_SIZE * 4, NULL, DEFAULT_TASK_PRIO, &LineCam_handle);

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
	TickType_t xLastWakeTime;
	while(LineCam_IsInit ==0) osDelay(1);								// Wait for LineCam task to start

	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		//---------------------------------------
		if(SW1_read() == 1) {
			DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, LED_DRIVE);
			DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
			LED1_ON();
		}
		else {
			DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, 0U);
		    DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
		    LED1_OFF();
		}
		//---------------------------------------
		if(LineCamGetLast(Sbuf) == 1) {
			UART_RTOS_Send(&UART3_rtos_handle, Sbuf, 128);
		}
	}
}
//-----------------------------------------------------------------------------------------
//		Line camera task
//-----------------------------------------------------------------------------------------
void LineCam_task(void *pvParameters) {
	LineCamInit();
	LineCam_IsInit = 1;
	for(;;) {
		LineCamProcess();
	}
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
