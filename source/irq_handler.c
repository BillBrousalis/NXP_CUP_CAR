//===================================================================================================
//!
//===================================================================================================
#include "includes.h"

extern void PixRead();

//====================================================================================================
///* ADC0_IRQn interrupt handler
//====================================================================================================

void ADC0_IRQHANDLER(void) {
  /* Get flags for each group */

  uint32_t status = ADC16_GetChannelStatusFlags(ADC0_PERIPHERAL, 0);
  	if ( status == kADC16_ChannelConversionDoneFlag){
  		PixRead();	//result_values[i] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, 0);
  	}

  /* Place your code here */

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

//====================================================================================================
//  ADC1_IRQn interrupt handler
//  POT ADC INTERRUPT
//====================================================================================================
int adc1_chnl = 0;
//====================================================================================================
void ADC1_IRQHANDLER(void) {
  /* Array of result values*/
  uint32_t result_values[2] = {0};
  /* Get flags for each group */
  for ( int i=0; i<2; i++){
  uint32_t status = ADC16_GetChannelStatusFlags(ADC1_PERIPHERAL, i);
  	if ( status == kADC16_ChannelConversionDoneFlag){
  		result_values[i] = ADC16_GetChannelConversionValue(ADC1_PERIPHERAL, i);
  	}
  }

  /* Place your code here */
  /* toggle pot channel (0 - 1) */
  adc1_chnl ^= 1;
  if(adc1_chnl == 0)
    ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channelsConfig[0]);
  else
    ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH1_CONTROL_GROUP, &ADC1_channelsConfig[1]);
  pot_update(adc1_chnl, result_values[0]);

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
//====================================================================================================
