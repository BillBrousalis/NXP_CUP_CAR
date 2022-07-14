#pragma once

#include "fsl_gpio.h"
#include "pin_mux.h"

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------

#define ls_clk_set()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 1)
#define ls_clk_clr()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 0)

//----------------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------------
#define ls_si_set()	GPIO_PinWrite(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, 1)
#define ls_si_clr()	GPIO_PinWrite(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, 0)

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
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
