/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v11.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 11.0.1
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 5106ec8a-bf57-4099-b5e0-fe6130e159f6
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DMA initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DMA'
- type: 'edma'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'edma_6d0dd4e17e2f179c7d42d98767129ede'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DMA'
- config_sets:
  - fsl_edma:
    - common_settings:
      - enableContinuousLinkMode: 'false'
      - enableHaltOnError: 'true'
      - enableRoundRobinArbitration: '$parent.ERCA.getEnumItemValue()'
      - enableDebugMode: 'false'
    - dma_table: []
    - edma_channels: []
    - errInterruptConfig:
      - enableErrInterrupt: 'false'
      - errorInterrupt:
        - IRQn: 'DMA_Error_IRQn'
        - enable_interrrupt: 'enabled'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const edma_config_t DMA_config = {
  .enableContinuousLinkMode = false,
  .enableHaltOnError = true,
  .enableRoundRobinArbitration = false,
  .enableDebugMode = false
};

/* Empty initialization function (commented out)
static void DMA_init(void) {
} */

/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
      - 1: []
      - 2: []
      - 3: []
      - 4: []
      - 5: []
      - 6: []
      - 7: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * FTM2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FTM2'
- type: 'ftm'
- mode: 'EdgeAligned'
- custom_name_enabled: 'false'
- type_id: 'ftm_a206ca22312775f3c8a462078188c129'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FTM2'
- config_sets:
  - ftm_main_config:
    - ftm_config:
      - clockSource: 'kFTM_SystemClock'
      - clockSourceFreq: 'GetFreq'
      - timerPrescaler: '32'
      - timerOutputFrequency: '50 Hz'
      - systemClockSource: 'BusInterfaceClock'
      - systemClockSourceFreq: 'mirrored_value'
      - faultMode: 'kFTM_Fault_Disable'
      - inputFilterPeriod: '1'
      - faultInputs:
        - 0:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 1:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 2:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 3:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
      - deadTimePrescale: 'kFTM_Deadtime_Prescale_1'
      - deadTimePeriod: '0'
      - pwmSyncMode: 'kFTM_SoftwareTrigger'
      - reloadPoints: ''
      - extTriggers: ''
      - chnlInitState: ''
      - chnlPolarity: ''
      - bdmMode: 'kFTM_BdmMode_0'
      - useGlobalTimeBase: 'false'
    - timer_interrupts: ''
    - enable_irq: 'false'
    - ftm_interrupt:
      - IRQn: 'FTM2_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'true'
  - ftm_edge_aligned_mode:
    - ftm_edge_aligned_channels_config:
      - 0:
        - channelId: 'PWM_SERVO_1'
        - edge_aligned_mode: 'kFTM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kFTM_Chnl_0'
          - level: 'kFTM_HighTrue'
          - dutyValueStr: '6553'
          - enable_chan_irq: 'false'
      - 1:
        - channelId: 'PWM_SERVO_2'
        - edge_aligned_mode: 'kFTM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kFTM_Chnl_1'
          - level: 'kFTM_HighTrue'
          - dutyValueStr: '6553'
          - enable_chan_irq: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ftm_config_t FTM2_config = {
  .prescale = kFTM_Prescale_Divide_32,
  .faultMode = kFTM_Fault_Disable,
  .faultFilterValue = 0,
  .deadTimePrescale = kFTM_Deadtime_Prescale_1,
  .deadTimeValue = 0,
  .pwmSyncMode = kFTM_SoftwareTrigger,
  .reloadPoints = 0,
  .extTriggers = 0,
  .chnlInitState = 0,
  .chnlPolarity = 0,
  .bdmMode = kFTM_BdmMode_0,
  .useGlobalTimeBase = false
};

const ftm_chnl_pwm_config_param_t FTM2_pwmSignalParams[] = { 
  {
    .chnlNumber = kFTM_Chnl_0,
    .level = kFTM_HighTrue,
    .dutyValue = 6553,
  },
  {
    .chnlNumber = kFTM_Chnl_1,
    .level = kFTM_HighTrue,
    .dutyValue = 6553,
  }
};

static void FTM2_init(void) {
  FTM_Init(FTM2_PERIPHERAL, &FTM2_config);
  FTM_SetTimerPeriod(FTM2_PERIPHERAL, FTM2_TIMER_MODULO_VALUE);
  FTM_SetupPwmMode(FTM2_PERIPHERAL, FTM2_pwmSignalParams, sizeof(FTM2_pwmSignalParams) / sizeof(ftm_chnl_pwm_config_param_t), kFTM_EdgeAlignedPwm);
  FTM_StartTimer(FTM2_PERIPHERAL, kFTM_SystemClock);
}

/***********************************************************************************************************************
 * ADC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'ADC0'
- type: 'adc16'
- mode: 'ADC'
- custom_name_enabled: 'false'
- type_id: 'adc16_897558f9b7366ed198de18c33097d7d2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'ADC0'
- config_sets:
  - fsl_adc16:
    - adc16_config:
      - referenceVoltageSource: 'kADC16_ReferenceVoltageSourceVref'
      - clockSource: 'kADC16_ClockSourceAlt1'
      - enableAsynchronousClock: 'true'
      - clockDivider: 'kADC16_ClockDivider2'
      - resolution: 'kADC16_Resolution12or13Bit'
      - longSampleMode: 'kADC16_LongSampleDisabled'
      - hardwareAverageMode: 'kADC16_HardwareAverageDisabled'
      - enableHighSpeed: 'false'
      - enableLowPower: 'false'
      - enableContinuousConversion: 'false'
    - adc16_channel_mux_mode: 'kADC16_ChannelMuxB'
    - adc16_hardware_compare_config:
      - hardwareCompareModeEnable: 'false'
    - doAutoCalibration: 'true'
    - trigger: 'false'
    - enable_dma: 'false'
    - enable_irq: 'true'
    - adc_interrupt:
      - IRQn: 'ADC0_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '4'
      - enable_custom_name: 'false'
    - adc16_channels_config:
      - 0:
        - channelName: ''
        - enableDifferentialConversion: 'false'
        - channelNumber: 'SE.3'
        - enableInterruptOnConversionCompleted: 'true'
        - channelGroup: '0'
        - initializeChannel: 'true'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
adc16_channel_config_t ADC0_channelsConfig[1] = {
  {
    .channelNumber = 3U,
    .enableDifferentialConversion = false,
    .enableInterruptOnConversionCompleted = true,
  }
};
const adc16_config_t ADC0_config = {
  .referenceVoltageSource = kADC16_ReferenceVoltageSourceVref,
  .clockSource = kADC16_ClockSourceAlt1,
  .enableAsynchronousClock = true,
  .clockDivider = kADC16_ClockDivider2,
  .resolution = kADC16_Resolution12or13Bit,
  .longSampleMode = kADC16_LongSampleDisabled,
  .hardwareAverageMode = kADC16_HardwareAverageDisabled,
  .enableHighSpeed = false,
  .enableLowPower = false,
  .enableContinuousConversion = false
};
const adc16_channel_mux_mode_t ADC0_muxMode = kADC16_ChannelMuxB;

static void ADC0_init(void) {
  /* Initialize ADC16 converter */
  ADC16_Init(ADC0_PERIPHERAL, &ADC0_config);
  /* Make sure, that software trigger is used */
  ADC16_EnableHardwareTrigger(ADC0_PERIPHERAL, false);
  /* Configure channel multiplexing mode */
  ADC16_SetChannelMuxMode(ADC0_PERIPHERAL, ADC0_muxMode);
  /* Perform auto calibration */
  ADC16_DoAutoCalibration(ADC0_PERIPHERAL);
  /* Initialize channel */
  ADC16_SetChannelConfig(ADC0_PERIPHERAL, ADC0_CH0_CONTROL_GROUP, &ADC0_channelsConfig[0]);
  /* Interrupt vector ADC0_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(ADC0_IRQN, ADC0_IRQ_PRIORITY);
  /* Enable interrupt ADC0_IRQn request in the NVIC. */
  EnableIRQ(ADC0_IRQN);
}

/***********************************************************************************************************************
 * ADC1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'ADC1'
- type: 'adc16'
- mode: 'ADC'
- custom_name_enabled: 'false'
- type_id: 'adc16_897558f9b7366ed198de18c33097d7d2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'ADC1'
- config_sets:
  - fsl_adc16:
    - adc16_config:
      - referenceVoltageSource: 'kADC16_ReferenceVoltageSourceVref'
      - clockSource: 'kADC16_ClockSourceAlt2'
      - enableAsynchronousClock: 'true'
      - clockDivider: 'kADC16_ClockDivider8'
      - resolution: 'kADC16_ResolutionSE12Bit'
      - longSampleMode: 'kADC16_LongSampleDisabled'
      - hardwareAverageMode: 'kADC16_HardwareAverageCount8'
      - enableHighSpeed: 'false'
      - enableLowPower: 'false'
      - enableContinuousConversion: 'false'
    - adc16_channel_mux_mode: 'kADC16_ChannelMuxA'
    - adc16_hardware_compare_config:
      - hardwareCompareModeEnable: 'false'
    - doAutoCalibration: 'false'
    - offset: '0'
    - trigger: 'false'
    - enable_dma: 'false'
    - enable_irq: 'true'
    - adc_interrupt:
      - IRQn: 'ADC1_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '4'
      - enable_custom_name: 'false'
    - adc16_channels_config:
      - 0:
        - channelName: ''
        - enableDifferentialConversion: 'false'
        - channelNumber: 'SE.3'
        - enableInterruptOnConversionCompleted: 'true'
        - channelGroup: '0'
        - initializeChannel: 'true'
      - 1:
        - channelName: ''
        - enableDifferentialConversion: 'false'
        - channelNumber: 'SE.1'
        - enableInterruptOnConversionCompleted: 'true'
        - channelGroup: '0'
        - initializeChannel: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
adc16_channel_config_t ADC1_channelsConfig[2] = {
  {
    .channelNumber = 3U,
    .enableDifferentialConversion = false,
    .enableInterruptOnConversionCompleted = true,
  },
  {
    .channelNumber = 1U,
    .enableDifferentialConversion = false,
    .enableInterruptOnConversionCompleted = true,
  }
};
const adc16_config_t ADC1_config = {
  .referenceVoltageSource = kADC16_ReferenceVoltageSourceVref,
  .clockSource = kADC16_ClockSourceAlt2,
  .enableAsynchronousClock = true,
  .clockDivider = kADC16_ClockDivider8,
  .resolution = kADC16_ResolutionSE12Bit,
  .longSampleMode = kADC16_LongSampleDisabled,
  .hardwareAverageMode = kADC16_HardwareAverageCount8,
  .enableHighSpeed = false,
  .enableLowPower = false,
  .enableContinuousConversion = false
};
const adc16_channel_mux_mode_t ADC1_muxMode = kADC16_ChannelMuxA;

static void ADC1_init(void) {
  /* Initialize ADC16 converter */
  ADC16_Init(ADC1_PERIPHERAL, &ADC1_config);
  /* Make sure, that software trigger is used */
  ADC16_EnableHardwareTrigger(ADC1_PERIPHERAL, false);
  /* Configure channel multiplexing mode */
  ADC16_SetChannelMuxMode(ADC1_PERIPHERAL, ADC1_muxMode);
  /* Initialize channel */
  ADC16_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channelsConfig[0]);
  /* Interrupt vector ADC1_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(ADC1_IRQN, ADC1_IRQ_PRIORITY);
  /* Enable interrupt ADC1_IRQn request in the NVIC. */
  EnableIRQ(ADC1_IRQN);
}

/***********************************************************************************************************************
 * FTM0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FTM0'
- type: 'ftm'
- mode: 'EdgeAligned'
- custom_name_enabled: 'false'
- type_id: 'ftm_a206ca22312775f3c8a462078188c129'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FTM0'
- config_sets:
  - ftm_main_config:
    - ftm_config:
      - clockSource: 'kFTM_SystemClock'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - timerPrescaler: '32'
      - timerOutputFrequency: '50 Hz'
      - systemClockSource: 'BusInterfaceClock'
      - systemClockSourceFreq: 'mirrored_value'
      - faultMode: 'kFTM_Fault_Disable'
      - inputFilterPeriod: '1'
      - faultInputs:
        - 0:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 1:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 2:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 3:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
      - deadTimePrescale: 'kFTM_Deadtime_Prescale_1'
      - deadTimePeriod: '0'
      - pwmSyncMode: 'kFTM_SoftwareTrigger'
      - reloadPoints: ''
      - extTriggers: ''
      - chnlInitState: ''
      - chnlPolarity: ''
      - bdmMode: 'kFTM_BdmMode_0'
      - useGlobalTimeBase: 'false'
    - timer_interrupts: ''
    - enable_irq: 'false'
    - ftm_interrupt:
      - IRQn: 'FTM0_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'true'
  - ftm_edge_aligned_mode:
    - ftm_edge_aligned_channels_config:
      - 0:
        - channelId: 'PWM_MOT_A'
        - edge_aligned_mode: 'kFTM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kFTM_Chnl_0'
          - level: 'kFTM_HighTrue'
          - dutyValueStr: '2812'
          - enable_chan_irq: 'false'
      - 1:
        - channelId: 'PWM_MOT_B'
        - edge_aligned_mode: 'kFTM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kFTM_Chnl_1'
          - level: 'kFTM_HighTrue'
          - dutyValueStr: '2812'
          - enable_chan_irq: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ftm_config_t FTM0_config = {
  .prescale = kFTM_Prescale_Divide_32,
  .faultMode = kFTM_Fault_Disable,
  .faultFilterValue = 0,
  .deadTimePrescale = kFTM_Deadtime_Prescale_1,
  .deadTimeValue = 0,
  .pwmSyncMode = kFTM_SoftwareTrigger,
  .reloadPoints = 0,
  .extTriggers = 0,
  .chnlInitState = 0,
  .chnlPolarity = 0,
  .bdmMode = kFTM_BdmMode_0,
  .useGlobalTimeBase = false
};

const ftm_chnl_pwm_config_param_t FTM0_pwmSignalParams[] = { 
  {
    .chnlNumber = kFTM_Chnl_0,
    .level = kFTM_HighTrue,
    .dutyValue = 2812,
  },
  {
    .chnlNumber = kFTM_Chnl_1,
    .level = kFTM_HighTrue,
    .dutyValue = 2812,
  }
};

static void FTM0_init(void) {
  FTM_Init(FTM0_PERIPHERAL, &FTM0_config);
  FTM_SetTimerPeriod(FTM0_PERIPHERAL, FTM0_TIMER_MODULO_VALUE);
  FTM_SetupPwmMode(FTM0_PERIPHERAL, FTM0_pwmSignalParams, sizeof(FTM0_pwmSignalParams) / sizeof(ftm_chnl_pwm_config_param_t), kFTM_EdgeAlignedPwm);
  FTM_StartTimer(FTM0_PERIPHERAL, kFTM_SystemClock);
}

/***********************************************************************************************************************
 * FTM3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FTM3'
- type: 'ftm'
- mode: 'EdgeAligned'
- custom_name_enabled: 'false'
- type_id: 'ftm_a206ca22312775f3c8a462078188c129'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FTM3'
- config_sets:
  - ftm_main_config:
    - ftm_config:
      - clockSource: 'kFTM_SystemClock'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - timerPrescaler: '2'
      - timerOutputFrequency: '20 kHz'
      - systemClockSource: 'BusInterfaceClock'
      - systemClockSourceFreq: 'mirrored_value'
      - faultMode: 'kFTM_Fault_Disable'
      - inputFilterPeriod: '1'
      - faultInputs:
        - 0:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 1:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 2:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 3:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
      - deadTimePrescale: 'kFTM_Deadtime_Prescale_1'
      - deadTimePeriod: '0'
      - pwmSyncMode: 'kFTM_SoftwareTrigger'
      - reloadPoints: ''
      - extTriggers: ''
      - chnlInitState: ''
      - chnlPolarity: ''
      - bdmMode: 'kFTM_BdmMode_0'
      - useGlobalTimeBase: 'false'
    - timer_interrupts: 'kFTM_TimeOverflowInterruptEnable'
    - enable_irq: 'true'
    - ftm_interrupt:
      - IRQn: 'FTM3_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '4'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'true'
  - ftm_edge_aligned_mode:
    - ftm_edge_aligned_channels_config: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ftm_config_t FTM3_config = {
  .prescale = kFTM_Prescale_Divide_2,
  .faultMode = kFTM_Fault_Disable,
  .faultFilterValue = 0,
  .deadTimePrescale = kFTM_Deadtime_Prescale_1,
  .deadTimeValue = 0,
  .pwmSyncMode = kFTM_SoftwareTrigger,
  .reloadPoints = 0,
  .extTriggers = 0,
  .chnlInitState = 0,
  .chnlPolarity = 0,
  .bdmMode = kFTM_BdmMode_0,
  .useGlobalTimeBase = false
};

static void FTM3_init(void) {
  FTM_Init(FTM3_PERIPHERAL, &FTM3_config);
  FTM_SetTimerPeriod(FTM3_PERIPHERAL, FTM3_TIMER_MODULO_VALUE);
  FTM_EnableInterrupts(FTM3_PERIPHERAL, kFTM_TimeOverflowInterruptEnable);
  /* Interrupt vector FTM3_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(FTM3_IRQN, FTM3_IRQ_PRIORITY);
  /* Enable interrupt FTM3_IRQn request in the NVIC. */
  EnableIRQ(FTM3_IRQN);
  FTM_StartTimer(FTM3_PERIPHERAL, kFTM_SystemClock);
}

/***********************************************************************************************************************
 * GPIOC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPIOC'
- type: 'gpio'
- mode: 'GPIO'
- custom_name_enabled: 'false'
- type_id: 'gpio_5920c5e026e8e974e6dc54fbd5e22ad7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIOC'
- config_sets:
  - fsl_gpio:
    - enable_irq: 'false'
    - port_interrupt:
      - IRQn: 'PORTC_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - quick_selection: 'QS_GPIO_1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void GPIOC_init(void) {
  /* Make sure, the clock gate for port C is enabled (e. g. in pin_mux.c) */
}

/***********************************************************************************************************************
 * UART3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'UART3'
- type: 'uart'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'uart_9b45c456566d03f79ecfe90751c10bb4'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'UART3'
- config_sets:
  - fsl_uart_freertos:
    - uart_rtos_configuration:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'GetFreq'
      - baudrate: '115200'
      - parity: 'kUART_ParityDisabled'
      - stopbits: 'kUART_OneStopBit'
      - buffer_size: '512'
    - interrupt_rx_tx:
      - IRQn: 'UART3_RX_TX_IRQn'
      - enable_priority: 'true'
      - priority: '4'
    - interrupt_err:
      - IRQn: 'UART3_ERR_IRQn'
      - enable_priority: 'true'
      - priority: '4'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
uart_rtos_handle_t UART3_rtos_handle;
uart_handle_t UART3_uart_handle;
uint8_t UART3_background_buffer[UART3_BACKGROUND_BUFFER_SIZE];
uart_rtos_config_t UART3_rtos_config = {
  .base = UART3_PERIPHERAL,
  .baudrate = 115200UL,
  .parity = kUART_ParityDisabled,
  .stopbits = kUART_OneStopBit,
  .buffer = UART3_background_buffer,
  .buffer_size = UART3_BACKGROUND_BUFFER_SIZE
};

static void UART3_init(void) {
  /* UART clock source initialization */
  UART3_rtos_config.srcclk = UART3_CLOCK_SOURCE;
  /* UART rtos initialization */
  UART_RTOS_Init(&UART3_rtos_handle, &UART3_uart_handle, &UART3_rtos_config);
  /* Interrupt vector UART3_RX_TX_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(UART3_SERIAL_RX_TX_IRQN, UART3_SERIAL_RX_TX_IRQ_PRIORITY);
  /* Interrupt vector UART3_ERR_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(UART3_SERIAL_ERROR_IRQN, UART3_SERIAL_ERROR_IRQ_PRIORITY);
}

/***********************************************************************************************************************
 * UART4 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'UART4'
- type: 'uart'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'uart_9b45c456566d03f79ecfe90751c10bb4'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'UART4'
- config_sets:
  - fsl_uart_freertos:
    - uart_rtos_configuration:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'GetFreq'
      - baudrate: '115200'
      - parity: 'kUART_ParityDisabled'
      - stopbits: 'kUART_OneStopBit'
      - buffer_size: '512'
    - interrupt_rx_tx:
      - IRQn: 'UART4_RX_TX_IRQn'
      - enable_priority: 'true'
      - priority: '4'
    - interrupt_err:
      - IRQn: 'UART4_ERR_IRQn'
      - enable_priority: 'true'
      - priority: '4'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
uart_rtos_handle_t UART4_rtos_handle;
uart_handle_t UART4_uart_handle;
uint8_t UART4_background_buffer[UART4_BACKGROUND_BUFFER_SIZE];
uart_rtos_config_t UART4_rtos_config = {
  .base = UART4_PERIPHERAL,
  .baudrate = 115200UL,
  .parity = kUART_ParityDisabled,
  .stopbits = kUART_OneStopBit,
  .buffer = UART4_background_buffer,
  .buffer_size = UART4_BACKGROUND_BUFFER_SIZE
};

static void UART4_init(void) {
  /* UART clock source initialization */
  UART4_rtos_config.srcclk = UART4_CLOCK_SOURCE;
  /* UART rtos initialization */
  UART_RTOS_Init(&UART4_rtos_handle, &UART4_uart_handle, &UART4_rtos_config);
  /* Interrupt vector UART4_RX_TX_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(UART4_SERIAL_RX_TX_IRQN, UART4_SERIAL_RX_TX_IRQ_PRIORITY);
  /* Interrupt vector UART4_ERR_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(UART4_SERIAL_ERROR_IRQN, UART4_SERIAL_ERROR_IRQ_PRIORITY);
}

/***********************************************************************************************************************
 * I2C0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'I2C0'
- type: 'i2c'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'i2c_2566d7363e7e9aaedabb432110e372d7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'I2C0'
- config_sets:
  - fsl_i2c:
    - i2c_mode: 'kI2C_Master'
    - clockSource: 'BusInterfaceClock'
    - clockSourceFreq: 'GetFreq'
    - rtos_handle:
      - enable_custom_name: 'false'
    - i2c_master_config:
      - enableMaster: 'true'
      - enableStopHold: 'false'
      - baudRate_Bps: '100000'
      - glitchFilterWidth: '0'
    - interrupt_priority:
      - IRQn: 'I2C0_IRQn'
      - enable_priority: 'true'
      - priority: '4'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
i2c_rtos_handle_t I2C0_rtosHandle;
const i2c_master_config_t I2C0_config = {
  .enableMaster = true,
  .enableStopHold = false,
  .baudRate_Bps = 100000UL,
  .glitchFilterWidth = 0U
};

static void I2C0_init(void) {
  /* Initialization function */
  I2C_RTOS_Init(&I2C0_rtosHandle, I2C0_PERIPHERAL, &I2C0_config, I2C0_CLK_FREQ);
  /* Interrupt vector I2C0_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(I2C0_IRQN, I2C0_IRQ_PRIORITY);
}

/***********************************************************************************************************************
 * AIPS0_custom_init initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'AIPS0_custom_init'
- type: 'custom_init'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'custom_init_87bfd8659a9d6953df1cceb1e02ed9b8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'AIPS0'
- config_sets:
  - general:
    - user_includes: ''
    - user_definitions: ''
    - user_code: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void AIPS0_custom_init_init(void) {
} */

/***********************************************************************************************************************
 * DAC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DAC0'
- type: 'dac'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'dac_a54f338a6fa6fd273bc89d61f5a3b85e'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DAC0'
- config_sets:
  - fsl_dac:
    - dac_config:
      - referenceVoltageSource: 'kDAC_ReferenceVoltageSourceVref2'
      - enableLowPowerMode: 'false'
    - dac_enable: 'true'
    - dac_value: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const dac_config_t DAC0_config = {
  .referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2,
  .enableLowPowerMode = false
};

static void DAC0_init(void) {
  /* Initialize DAC converter */
  DAC_Init(DAC0_PERIPHERAL, &DAC0_config);
  /* Output value of DAC. */
  DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, 0U);
  /* Make sure the read pointer is set to the start */
  DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
  /* Enable DAC output */
  DAC_Enable(DAC0_PERIPHERAL, true);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Global initialization */
  DMAMUX_Init(DMA_DMAMUX_BASEADDR);
  EDMA_Init(DMA_DMA_BASEADDR, &DMA_config);

  /* Initialize components */
  FTM2_init();
  ADC0_init();
  ADC1_init();
  FTM0_init();
  FTM3_init();
  GPIOC_init();
  UART3_init();
  UART4_init();
  I2C0_init();
  DAC0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
