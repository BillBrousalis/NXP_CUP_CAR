/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT2_RMIISRC_EXTAL 0x00u  /*!<@brief RMII clock source select: EXTAL clock */
#define SOPT4_FTM1CH0SRC_FTM 0x00u /*!<@brief FTM1 channel 0 input capture source select: FTM1_CH0 signal */
#define SOPT4_FTM2CH0SRC_FTM 0x00u /*!<@brief FTM2 channel 0 input capture source select: FTM2_CH0 signal */

/*! @name PORTC5 (number 77), SPI0_SCLK
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SPI0_SCLK_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_SPI0_SCLK_GPIO_PIN_MASK (1U << 5U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_SPI0_SCLK_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_SPI0_SCLK_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_SPI0_SCLK_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
