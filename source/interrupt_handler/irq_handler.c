//===================================================================================================
//!irq_handler.c
//===================================================================================================
#include "includes.h"
#include "globals.h"
#include "base_drivers/gpio.h"
#include "base_drivers/WheelEncoder.h"
#include "base_drivers/linescan.h"

extern void PixRead(void);
//====================================================================================================
///* ADC0_IRQn interrupt handler
//====================================================================================================
void ADC0_IRQHANDLER(void) {
  /* Get flags for each group */
	uint32_t status = ADC16_GetChannelStatusFlags(ADC0_PERIPHERAL, 0);
  	if (status == kADC16_ChannelConversionDoneFlag) {
  		PixRead();	//result_values[i] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0);
  	}
  	ADC16_ClearStatusFlags(ADC0_PERIPHERAL, 0);
  	/* Place your code here */

  	/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
   	   Store immediate overlapping exception return operation might vector to incorrect interrupt. */
	#if defined __CORTEX_M && (__CORTEX_M == 4U)
  		__DSB();
	#endif
}
//==========================================================================================================
/* ADC1_IRQn interrupt handler */
//==========================================================================================================
void ADC1_IRQHANDLER(void) {
	static BaseType_t xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;
	uint32_t result_values[2] = {0};
	/* Get flags for each group */
	for (int i=0; i<2; i++){
		uint32_t status = ADC16_GetChannelStatusFlags(ADC1_PERIPHERAL, i);
		if (status == kADC16_ChannelConversionDoneFlag) {
			result_values[i] = ADC16_GetChannelConversionValue(ADC1_PERIPHERAL, i);
			xSemaphoreGiveFromISR(adc1_Semaphore, &xHigherPriorityTaskWoken);
		}
	}
	adc1_result = result_values[0];
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
	   Store immediate overlapping exception return operation might vector to incorrect interrupt. */
	#if defined __CORTEX_M && (__CORTEX_M == 4U)
		__DSB();
	#endif
}
//====================================================================================================
/* LineScan clock interrupt    */
/* FTM3_IRQn interrupt handler */
//====================================================================================================
void FTM3_IRQHANDLER(void) {
	uint32_t intStatus;
	/* Reading all interrupt flags of status register */
	intStatus = FTM_GetStatusFlags(FTM3_PERIPHERAL);
	FTM_ClearStatusFlags(FTM3_PERIPHERAL, intStatus);
	/* Place your code here */
	CamScanPix();
	/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
       Store immediate overlapping exception return operation might vector to incorrect interrupt. */
	#if defined __CORTEX_M && (__CORTEX_M == 4U)
		__DSB();
  	#endif
}
//====================================================================================================
/* PORTA_IRQn interrupt handler */
/* MOTOR A&B ENCODER  */
/* GPIOA_IRQn interrupt handler */
//====================================================================================================
void GPIOA_IRQHANDLER(void) {
  /* Get pin flags */
  uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIOA);

  /* Place your interrupt code here */

  WheelEncoderProcess();

  /* Clear pin flags */
  GPIO_PortClearInterruptFlags(GPIOA, pin_flags);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

//====================================================================================================
/* FTM1_IRQn interrupt handler */
//====================================================================================================

void FTM1_IRQHANDLER(void) {
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = FTM_GetStatusFlags(FTM1_PERIPHERAL);
  FTM_ClearStatusFlags(FTM1_PERIPHERAL, intStatus);

  WrapAround();
  /* Place your code here */

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

//====================================================================================================
//====================================================================================================
