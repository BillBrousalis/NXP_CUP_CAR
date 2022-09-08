#ifndef GPIO_H_
#define GPIO_H_
#include "fsl_gpio.h"
#include "pin_mux.h"

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------
#define ls_clk_set()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 0)
#define ls_clk_clr()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 1)

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------
#define ls_si_set()		GPIO_PinWrite(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, 1)
#define ls_si_clr()		GPIO_PinWrite(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, 0)

//----------------------------------------------------------------------------------------------------------
// Debug pin 	- PTE26 (TP1)
//----------------------------------------------------------------------------------------------------------
#define dbg_set()	GPIO_PinWrite(BOARD_INITPINS_DEBUG_OUT_GPIO, BOARD_INITPINS_DEBUG_OUT_GPIO_PIN_MASK, 1)
#define dbg_clr()	GPIO_PinWrite(BOARD_INITPINS_DEBUG_OUT_GPIO, BOARD_INITPINS_DEBUG_OUT_GPIO_PIN_MASK, 0)

//----------------------------------------------------------------------------------------------------------
// Debug pin 	- PTC6 (J4 pin 3)
//----------------------------------------------------------------------------------------------------------
#define dbg2_set()	GPIO_PinWrite(BOARD_INITPINS_DEBUG_OUT2_GPIO, BOARD_INITPINS_DEBUG_OUT2_PIN, 1)
#define dbg2_clr()	GPIO_PinWrite(BOARD_INITPINS_DEBUG_OUT2_GPIO, BOARD_INITPINS_DEBUG_OUT2_PIN, 0)
#define dbg2_tog()	GPIO_PortToggle(BOARD_INITPINS_DEBUG_OUT2_GPIO, BOARD_INITPINS_DEBUG_OUT2_PIN_MASK)

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------
#define SW1_read() 	GPIO_PinRead(BOARD_INITPINS_DILSW1_GPIO, BOARD_INITPINS_DILSW1_PIN)
#define SW2_read() 	GPIO_PinRead(BOARD_INITPINS_DILSW2_GPIO, BOARD_INITPINS_DILSW2_PIN)
#define SW3_read() 	GPIO_PinRead(BOARD_INITPINS_DILSW3_GPIO, BOARD_INITPINS_DILSW3_PIN)
#define SW4_read() 	GPIO_PinRead(BOARD_INITPINS_DILSW4_GPIO, BOARD_INITPINS_DILSW4_PIN)

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------
#define LED1_ON()	GPIO_PinWrite(BOARD_INITPINS_LED1_GPIO, BOARD_INITPINS_LED1_PIN, 1)
#define LED1_OFF()	GPIO_PinWrite(BOARD_INITPINS_LED1_GPIO, BOARD_INITPINS_LED1_PIN, 0)
#define LED1_TOG()	GPIO_PortToggle(BOARD_INITPINS_LED1_PORT, BOARD_INITPINS_LED1_PIN_MASK)

#define LED2_ON()	GPIO_PinWrite(BOARD_INITPINS_LED2_GPIO, BOARD_INITPINS_LED2_PIN, 1)
#define LED2_OFF()	GPIO_PinWrite(BOARD_INITPINS_LED2_GPIO, BOARD_INITPINS_LED2_PIN, 0)
#define LED2_TOG()	GPIO_PortToggle(BOARD_INITPINS_LED2_PORT, BOARD_INITPINS_LED2_PIN_MASK)

#define LED3_ON()	GPIO_PinWrite(BOARD_INITPINS_LED3_GPIO, BOARD_INITPINS_LED3_PIN, 1)
#define LED3_OFF()	GPIO_PinWrite(BOARD_INITPINS_LED3_GPIO, BOARD_INITPINS_LED3_PIN, 0)
#define LED3_TOG()	GPIO_PortToggle(BOARD_INITPINS_LED3_PORT, BOARD_INITPINS_LED3_PIN_MASK)

#define LED4_ON()	GPIO_PinWrite(BOARD_INITPINS_LED4_GPIO, BOARD_INITPINS_LED4_PIN, 1)
#define LED4_OFF()	GPIO_PinWrite(BOARD_INITPINS_LED4_GPIO, BOARD_INITPINS_LED4_PIN, 0)
#define LED4_TOG()	GPIO_PortToggle(BOARD_INITPINS_LED4_PORT, BOARD_INITPINS_LED4_PIN_MASK)
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------

#endif
