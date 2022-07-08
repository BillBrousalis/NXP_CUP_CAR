#pragma once

#include "fsl_gpio.h"
#include "pin_mux.h"

#define ls_clk_set()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 1)
#define ls_clk_clr()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 0)

#define ls_si_set()	GPIO_PinWrite(BOARD_INITPINS_LSC2_CSn_GPIO, BOARD_INITPINS_LSC2_CSn_PIN, 1)
#define ls_si_clr()	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, 0)
