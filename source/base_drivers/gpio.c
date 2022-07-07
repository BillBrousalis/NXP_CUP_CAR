#include "fsl_gpio.h"
#include "pin_mux.h"

#include "gpio.h"

void ls_clk_set(uint32_t output) {
	GPIO_PinWrite(BOARD_INITPINS_SPI0_SCLK_GPIO, BOARD_INITPINS_SPI0_SCLK_PIN, output);
}
