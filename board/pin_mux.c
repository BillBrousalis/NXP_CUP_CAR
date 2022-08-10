/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v11.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 11.0.1
pin_labels:
- {pin_num: '77', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FB_AD10/CMP0_OUT/FTM0_CH2, label: SPI0_SCLK, identifier: SPI0_SCLK}
- {pin_num: '70', pin_signal: ADC0_SE14/PTC0/SPI0_PCS4/PDB0_EXTRG/USB_SOF_OUT/FB_AD14/I2S0_TXD1, label: LSC2_CSn, identifier: LSC2_CSn}
- {pin_num: '33', pin_signal: PTE26/ENET_1588_CLKIN/UART4_CTS_b/RTC_CLKOUT/USB_CLKIN, label: DEBUG_OUT, identifier: DEBUG_OUT}
- {pin_num: '81', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, label: DILSW1, identifier: SW1;DILSW1}
- {pin_num: '82', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, label: DILSW2, identifier: SW2;DILSW2}
- {pin_num: '83', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/I2S0_RXD1/FB_RW_b, label: DILSW3, identifier: SW3;DILSW3}
- {pin_num: '84', pin_signal: PTC12/UART4_RTS_b/FB_AD27/FTM3_FLT0, label: DILSW4, identifier: SW4;DILSW4}
- {pin_num: '20', pin_signal: ADC1_DP0/ADC0_DP3, label: LINECAM_IN, identifier: LINECAM_IN}
- {pin_num: '78', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_SOUT/PDB0_EXTRG/I2S0_RX_BCLK/FB_AD9/I2S0_MCLK, label: DEBUG_OUT2, identifier: DEBUG_OUT2}
- {pin_num: '7', pin_signal: PTE6/SPI1_PCS3/UART3_CTS_b/I2S0_MCLK/FTM3_CH1/USB_SOF_OUT, label: SD_DETECT, identifier: SD_DETECT}
- {pin_num: '66', pin_signal: PTB20/SPI2_PCS0/FB_AD31/CMP0_OUT, label: LED1, identifier: LED1}
- {pin_num: '67', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, label: LED2, identifier: LED2}
- {pin_num: '68', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, label: LED3, identifier: LED3}
- {pin_num: '69', pin_signal: PTB23/SPI2_SIN/SPI0_PCS5/FB_AD28, label: LED4, identifier: LED4}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '64', peripheral: FTM2, signal: 'CH, 0', pin_signal: PTB18/CAN0_TX/FTM2_CH0/I2S0_TX_BCLK/FB_AD15/FTM2_QD_PHA}
  - {pin_num: '65', peripheral: FTM2, signal: 'CH, 1', pin_signal: PTB19/CAN0_RX/FTM2_CH1/I2S0_TX_FS/FB_OE_b/FTM2_QD_PHB}
  - {pin_num: '16', peripheral: ADC1, signal: 'DP, 1', pin_signal: ADC1_DP1}
  - {pin_num: '18', peripheral: ADC1, signal: 'DP, 3', pin_signal: ADC0_DP0/ADC1_DP3}
  - {pin_num: '42', peripheral: FTM1, signal: 'CH, 0', pin_signal: CMP2_IN0/PTA12/CAN0_TX/FTM1_CH0/RMII0_RXD1/MII0_RXD1/I2C2_SCL/I2S0_TXD0/FTM1_QD_PHA}
  - {pin_num: '43', peripheral: FTM1, signal: 'CH, 1', pin_signal: CMP2_IN1/PTA13/LLWU_P4/CAN0_RX/FTM1_CH1/RMII0_RXD0/MII0_RXD0/I2C2_SDA/I2S0_TX_FS/FTM1_QD_PHB}
  - {pin_num: '27', peripheral: DAC0, signal: OUT, pin_signal: DAC0_OUT/CMP1_IN3/ADC0_SE23}
  - {pin_num: '50', peripheral: ENET, signal: RMII_CLKIN, pin_signal: EXTAL0/PTA18/FTM0_FLT2/FTM_CLKIN0}
  - {pin_num: '51', peripheral: OSC, signal: XTAL0, pin_signal: XTAL0/PTA19/FTM1_FLT0/FTM_CLKIN1/LPTMR0_ALT1}
  - {pin_num: '71', peripheral: FTM0, signal: 'CH, 0', pin_signal: ADC0_SE15/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FB_AD13/I2S0_TXD0}
  - {pin_num: '72', peripheral: FTM0, signal: 'CH, 1', pin_signal: ADC0_SE4b/CMP1_IN0/PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/FB_AD12/I2S0_TX_FS}
  - {pin_num: '77', peripheral: GPIOC, signal: 'GPIO, 5', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FB_AD10/CMP0_OUT/FTM0_CH2, direction: OUTPUT, slew_rate: fast,
    drive_strength: high}
  - {pin_num: '20', peripheral: ADC0, signal: 'DP, 3', pin_signal: ADC1_DP0/ADC0_DP3}
  - {pin_num: '70', peripheral: GPIOC, signal: 'GPIO, 0', pin_signal: ADC0_SE14/PTC0/SPI0_PCS4/PDB0_EXTRG/USB_SOF_OUT/FB_AD14/I2S0_TXD1, direction: OUTPUT, drive_strength: high}
  - {pin_num: '33', peripheral: GPIOE, signal: 'GPIO, 26', pin_signal: PTE26/ENET_1588_CLKIN/UART4_CTS_b/RTC_CLKOUT/USB_CLKIN, direction: OUTPUT, drive_strength: high}
  - {pin_num: '81', peripheral: GPIOC, signal: 'GPIO, 9', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, identifier: DILSW1, direction: INPUT,
    gpio_interrupt: kPORT_InterruptOrDMADisabled, slew_rate: slow, passive_filter: enable}
  - {pin_num: '82', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, identifier: DILSW2, direction: INPUT,
    slew_rate: slow, passive_filter: enable}
  - {pin_num: '83', peripheral: GPIOC, signal: 'GPIO, 11', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/I2S0_RXD1/FB_RW_b, identifier: DILSW3, direction: INPUT,
    slew_rate: slow, passive_filter: enable}
  - {pin_num: '84', peripheral: GPIOC, signal: 'GPIO, 12', pin_signal: PTC12/UART4_RTS_b/FB_AD27/FTM3_FLT0, identifier: DILSW4, direction: INPUT, slew_rate: slow,
    passive_filter: enable}
  - {pin_num: '78', peripheral: GPIOC, signal: 'GPIO, 6', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_SOUT/PDB0_EXTRG/I2S0_RX_BCLK/FB_AD9/I2S0_MCLK, direction: OUTPUT,
    gpio_init_state: 'false'}
  - {pin_num: '6', peripheral: SDHC, signal: 'DATA, 2', pin_signal: PTE5/SPI1_PCS2/UART3_RX/SDHC0_D2/FTM3_CH0}
  - {pin_num: '5', peripheral: SDHC, signal: 'DATA, 3', pin_signal: PTE4/LLWU_P2/SPI1_PCS0/UART3_TX/SDHC0_D3/TRACE_D0}
  - {pin_num: '4', peripheral: SDHC, signal: CMD, pin_signal: ADC0_DM2/ADC1_SE7a/PTE3/SPI1_SIN/UART1_RTS_b/SDHC0_CMD/TRACE_D1/SPI1_SOUT}
  - {pin_num: '3', peripheral: SDHC, signal: DCLK, pin_signal: ADC0_DP2/ADC1_SE6a/PTE2/LLWU_P1/SPI1_SCK/UART1_CTS_b/SDHC0_DCLK/TRACE_D2}
  - {pin_num: '2', peripheral: SDHC, signal: 'DATA, 0', pin_signal: ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/SDHC0_D0/TRACE_D3/I2C1_SCL/SPI1_SIN}
  - {pin_num: '1', peripheral: SDHC, signal: 'DATA, 1', pin_signal: ADC1_SE4a/PTE0/SPI1_PCS1/UART1_TX/SDHC0_D1/TRACE_CLKOUT/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '7', peripheral: GPIOE, signal: 'GPIO, 6', pin_signal: PTE6/SPI1_PCS3/UART3_CTS_b/I2S0_MCLK/FTM3_CH1/USB_SOF_OUT, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled}
  - {pin_num: '86', peripheral: UART4, signal: RX, pin_signal: PTC14/UART4_RX/FB_AD25}
  - {pin_num: '87', peripheral: UART4, signal: TX, pin_signal: PTC15/UART4_TX/FB_AD24}
  - {pin_num: '58', peripheral: UART3, signal: RX, pin_signal: ADC1_SE14/PTB10/SPI1_PCS0/UART3_RX/FB_AD19/FTM0_FLT1}
  - {pin_num: '59', peripheral: UART3, signal: TX, pin_signal: ADC1_SE15/PTB11/SPI1_SCK/UART3_TX/FB_AD18/FTM0_FLT2}
  - {pin_num: '31', peripheral: I2C0, signal: SCL, pin_signal: ADC0_SE17/PTE24/UART4_TX/I2C0_SCL/EWM_OUT_b}
  - {pin_num: '32', peripheral: I2C0, signal: SDA, pin_signal: ADC0_SE18/PTE25/UART4_RX/I2C0_SDA/EWM_IN}
  - {pin_num: '66', peripheral: GPIOB, signal: 'GPIO, 20', pin_signal: PTB20/SPI2_PCS0/FB_AD31/CMP0_OUT, direction: OUTPUT, slew_rate: slow}
  - {pin_num: '67', peripheral: GPIOB, signal: 'GPIO, 21', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, direction: OUTPUT, slew_rate: slow}
  - {pin_num: '68', peripheral: GPIOB, signal: 'GPIO, 22', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, direction: OUTPUT, slew_rate: slow}
  - {pin_num: '69', peripheral: GPIOB, signal: 'GPIO, 23', pin_signal: PTB23/SPI2_SIN/SPI0_PCS5/FB_AD28, direction: OUTPUT, slew_rate: slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t LED1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB20 (pin 66)  */
    GPIO_PinInit(BOARD_INITPINS_LED1_GPIO, BOARD_INITPINS_LED1_PIN, &LED1_config);

    gpio_pin_config_t LED2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB21 (pin 67)  */
    GPIO_PinInit(BOARD_INITPINS_LED2_GPIO, BOARD_INITPINS_LED2_PIN, &LED2_config);

    gpio_pin_config_t LED3_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB22 (pin 68)  */
    GPIO_PinInit(BOARD_INITPINS_LED3_GPIO, BOARD_INITPINS_LED3_PIN, &LED3_config);

    gpio_pin_config_t LED4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB23 (pin 69)  */
    GPIO_PinInit(BOARD_INITPINS_LED4_GPIO, BOARD_INITPINS_LED4_PIN, &LED4_config);

    gpio_pin_config_t LSC2_CSn_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC0 (pin 70)  */
    GPIO_PinInit(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, &LSC2_CSn_config);

    gpio_pin_config_t SPI0_SCLK_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC5 (pin 77)  */
    GPIO_PinInit(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, &SPI0_SCLK_config);

    gpio_pin_config_t DEBUG_OUT2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC6 (pin 78)  */
    GPIO_PinInit(BOARD_INITPINS_DEBUG_OUT2_GPIO, BOARD_INITPINS_DEBUG_OUT2_PIN, &DEBUG_OUT2_config);

    gpio_pin_config_t DILSW1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC9 (pin 81)  */
    GPIO_PinInit(BOARD_INITPINS_DILSW1_GPIO, BOARD_INITPINS_DILSW1_PIN, &DILSW1_config);

    gpio_pin_config_t DILSW2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC10 (pin 82)  */
    GPIO_PinInit(BOARD_INITPINS_DILSW2_GPIO, BOARD_INITPINS_DILSW2_PIN, &DILSW2_config);

    gpio_pin_config_t DILSW3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC11 (pin 83)  */
    GPIO_PinInit(BOARD_INITPINS_DILSW3_GPIO, BOARD_INITPINS_DILSW3_PIN, &DILSW3_config);

    gpio_pin_config_t DILSW4_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC12 (pin 84)  */
    GPIO_PinInit(BOARD_INITPINS_DILSW4_GPIO, BOARD_INITPINS_DILSW4_PIN, &DILSW4_config);

    gpio_pin_config_t SD_DETECT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE6 (pin 7)  */
    GPIO_PinInit(BOARD_INITPINS_SD_DETECT_GPIO, BOARD_INITPINS_SD_DETECT_PIN, &SD_DETECT_config);

    gpio_pin_config_t DEBUG_OUT_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE26 (pin 33)  */
    GPIO_PinInit(BOARD_INITPINS_DEBUG_OUT_GPIO, BOARD_INITPINS_DEBUG_OUT_PIN, &DEBUG_OUT_config);

    /* PORTA12 (pin 42) is configured as FTM1_CH0 */
    PORT_SetPinMux(PORTA, 12U, kPORT_MuxAlt3);

    /* PORTA13 (pin 43) is configured as FTM1_CH1 */
    PORT_SetPinMux(PORTA, 13U, kPORT_MuxAlt3);

    /* PORTA18 (pin 50) is configured as EXTAL0 */
    PORT_SetPinMux(PORTA, 18U, kPORT_PinDisabledOrAnalog);

    /* PORTA19 (pin 51) is configured as XTAL0 */
    PORT_SetPinMux(PORTA, 19U, kPORT_PinDisabledOrAnalog);

    /* PORTB10 (pin 58) is configured as UART3_RX */
    PORT_SetPinMux(PORTB, 10U, kPORT_MuxAlt3);

    /* PORTB11 (pin 59) is configured as UART3_TX */
    PORT_SetPinMux(PORTB, 11U, kPORT_MuxAlt3);

    /* PORTB18 (pin 64) is configured as FTM2_CH0 */
    PORT_SetPinMux(PORTB, 18U, kPORT_MuxAlt3);

    /* PORTB19 (pin 65) is configured as FTM2_CH1 */
    PORT_SetPinMux(PORTB, 19U, kPORT_MuxAlt3);

    /* PORTB20 (pin 66) is configured as PTB20 */
    PORT_SetPinMux(BOARD_INITPINS_LED1_PORT, BOARD_INITPINS_LED1_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[20] = ((PORTB->PCR[20] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB21 (pin 67) is configured as PTB21 */
    PORT_SetPinMux(BOARD_INITPINS_LED2_PORT, BOARD_INITPINS_LED2_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[21] = ((PORTB->PCR[21] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB22 (pin 68) is configured as PTB22 */
    PORT_SetPinMux(BOARD_INITPINS_LED3_PORT, BOARD_INITPINS_LED3_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[22] = ((PORTB->PCR[22] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB23 (pin 69) is configured as PTB23 */
    PORT_SetPinMux(BOARD_INITPINS_LED4_PORT, BOARD_INITPINS_LED4_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[23] = ((PORTB->PCR[23] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTC0 (pin 70) is configured as PTC0 */
    PORT_SetPinMux(BOARD_INITPINS_LSC2_CSn_PORT, BOARD_INITPINS_LSC2_CSn_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[0] = ((PORTC->PCR[0] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                     /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin
                      * is configured as a digital output. */
                     | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTC1 (pin 71) is configured as FTM0_CH0 */
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt4);

    /* PORTC10 (pin 82) is configured as PTC10 */
    PORT_SetPinMux(BOARD_INITPINS_DILSW2_PORT, BOARD_INITPINS_DILSW2_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[10] = ((PORTC->PCR[10] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate)

                      /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                       * pin is configured as a digital input.
                       * Refer to the device data sheet for filter characteristics. */
                      | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTC11 (pin 83) is configured as PTC11 */
    PORT_SetPinMux(BOARD_INITPINS_DILSW3_PORT, BOARD_INITPINS_DILSW3_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[11] = ((PORTC->PCR[11] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate)

                      /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                       * pin is configured as a digital input.
                       * Refer to the device data sheet for filter characteristics. */
                      | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTC12 (pin 84) is configured as PTC12 */
    PORT_SetPinMux(BOARD_INITPINS_DILSW4_PORT, BOARD_INITPINS_DILSW4_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[12] = ((PORTC->PCR[12] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_SlowSlewRate)

                      /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                       * pin is configured as a digital input.
                       * Refer to the device data sheet for filter characteristics. */
                      | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTC14 (pin 86) is configured as UART4_RX */
    PORT_SetPinMux(PORTC, 14U, kPORT_MuxAlt3);

    /* PORTC15 (pin 87) is configured as UART4_TX */
    PORT_SetPinMux(PORTC, 15U, kPORT_MuxAlt3);

    /* PORTC2 (pin 72) is configured as FTM0_CH1 */
    PORT_SetPinMux(PORTC, 2U, kPORT_MuxAlt4);

    /* PORTC5 (pin 77) is configured as PTC5 */
    PORT_SetPinMux(BOARD_INITPINS_SPI0_SCLK_PORT, BOARD_INITPINS_SPI0_SCLK_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[5] = ((PORTC->PCR[5] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_FastSlewRate)

                     /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin
                      * is configured as a digital output. */
                     | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTC6 (pin 78) is configured as PTC6 */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_OUT2_PORT, BOARD_INITPINS_DEBUG_OUT2_PIN, kPORT_MuxAsGpio);

    /* PORTC9 (pin 81) is configured as PTC9 */
    PORT_SetPinMux(BOARD_INITPINS_DILSW1_PORT, BOARD_INITPINS_DILSW1_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTC9 (pin 81): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_DILSW1_PORT, BOARD_INITPINS_DILSW1_PIN, kPORT_InterruptOrDMADisabled);

    PORTC->PCR[9] = ((PORTC->PCR[9] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate)

                     /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                      * pin is configured as a digital input.
                      * Refer to the device data sheet for filter characteristics. */
                     | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTE0 (pin 1) is configured as SDHC0_D1 */
    PORT_SetPinMux(PORTE, 0U, kPORT_MuxAlt4);

    /* PORTE1 (pin 2) is configured as SDHC0_D0 */
    PORT_SetPinMux(PORTE, 1U, kPORT_MuxAlt4);

    /* PORTE2 (pin 3) is configured as SDHC0_DCLK */
    PORT_SetPinMux(PORTE, 2U, kPORT_MuxAlt4);

    /* PORTE24 (pin 31) is configured as I2C0_SCL */
    PORT_SetPinMux(PORTE, 24U, kPORT_MuxAlt5);

    /* PORTE25 (pin 32) is configured as I2C0_SDA */
    PORT_SetPinMux(PORTE, 25U, kPORT_MuxAlt5);

    /* PORTE26 (pin 33) is configured as PTE26 */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_OUT_PORT, BOARD_INITPINS_DEBUG_OUT_PIN, kPORT_MuxAsGpio);

    PORTE->PCR[26] = ((PORTE->PCR[26] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                      /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if
                       * pin is configured as a digital output. */
                      | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTE3 (pin 4) is configured as SDHC0_CMD */
    PORT_SetPinMux(PORTE, 3U, kPORT_MuxAlt4);

    /* PORTE4 (pin 5) is configured as SDHC0_D3 */
    PORT_SetPinMux(PORTE, 4U, kPORT_MuxAlt4);

    /* PORTE5 (pin 6) is configured as SDHC0_D2 */
    PORT_SetPinMux(PORTE, 5U, kPORT_MuxAlt4);

    /* PORTE6 (pin 7) is configured as PTE6 */
    PORT_SetPinMux(BOARD_INITPINS_SD_DETECT_PORT, BOARD_INITPINS_SD_DETECT_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTE6 (pin 7): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SD_DETECT_PORT, BOARD_INITPINS_SD_DETECT_PIN, kPORT_InterruptOrDMADisabled);

    SIM->SOPT2 = ((SIM->SOPT2 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT2_RMIISRC_MASK)))

                  /* RMII clock source select: EXTAL clock. */
                  | SIM_SOPT2_RMIISRC(SOPT2_RMIISRC_EXTAL));

    SIM->SOPT4 = ((SIM->SOPT4 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT4_FTM1CH0SRC_MASK | SIM_SOPT4_FTM2CH0SRC_MASK)))

                  /* FTM1 channel 0 input capture source select: FTM1_CH0 signal. */
                  | SIM_SOPT4_FTM1CH0SRC(SOPT4_FTM1CH0SRC_FTM)

                  /* FTM2 channel 0 input capture source select: FTM2_CH0 signal. */
                  | SIM_SOPT4_FTM2CH0SRC(SOPT4_FTM2CH0SRC_FTM));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
