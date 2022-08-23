//-----------------------------------------------------------------------------------------------------------------------------------
//!	includes.h
//-----------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "defines.h"
#include "board.h"
#include "fsl_adc16.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "fsl_uart_freertos.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* TODO: insert other include files here. */
#include "drive_tracking.h"
#include "base_drivers/servo.h"
#include "base_drivers/pot.h"
#include "base_drivers/motors.h"
#include "base_drivers/gpio.h"
#include "base_drivers/uart.h"
#include "base_drivers/led.h"
#include "base_drivers/linescan.h"
#include "car_tasks/mytasks.h"
#include "tests/pot_testing.h"
#include "irq_handler.h"
#include "misc.h"
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
