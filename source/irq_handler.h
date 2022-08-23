#pragma once
//---------------------------------------
extern SemaphoreHandle_t adc1_Semaphore;
extern uint32_t adc1_result;
//---------------------------------------
void ADC0_IRQHANDLER(void);
void ADC1_IRQHANDLER(void);
