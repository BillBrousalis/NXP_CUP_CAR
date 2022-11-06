#include "includes.h"
#include "globals.h"
#include "base_drivers/gpio.h"
#include "led.h"

void Led1_ON(void) {
	DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, LED_DRIVE);
	DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
	LED1_ON();
}

void Led1_OFF(void) {
	DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, 0U);
	DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
	LED1_OFF();
}
