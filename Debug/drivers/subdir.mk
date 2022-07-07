################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_crc.c \
../drivers/fsl_dac.c \
../drivers/fsl_dspi.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_rnga.c \
../drivers/fsl_rtc.c \
../drivers/fsl_sdhc.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c \
../drivers/fsl_vref.c 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_crc.o \
./drivers/fsl_dac.o \
./drivers/fsl_dspi.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_rnga.o \
./drivers/fsl_rtc.o \
./drivers/fsl_sdhc.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_vref.o 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_crc.d \
./drivers/fsl_dac.d \
./drivers/fsl_dspi.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_rnga.d \
./drivers/fsl_rtc.d \
./drivers/fsl_sdhc.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d \
./drivers/fsl_vref.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\work\NXP\NXP_CUP_CAR\board" -I"C:\work\NXP\NXP_CUP_CAR\source" -I"C:\work\NXP\NXP_CUP_CAR\source\generated" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\include" -I"C:\work\NXP\NXP_CUP_CAR\component\osa" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\inc" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\work\NXP\NXP_CUP_CAR\drivers" -I"C:\work\NXP\NXP_CUP_CAR\drivers\freertos" -I"C:\work\NXP\NXP_CUP_CAR\utilities" -I"C:\work\NXP\NXP_CUP_CAR\component\serial_manager" -I"C:\work\NXP\NXP_CUP_CAR\component\uart" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source\fsl_sd_disk" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host\class" -I"C:\work\NXP\NXP_CUP_CAR\usb\include" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\osa" -I"C:\work\NXP\NXP_CUP_CAR\component\lists" -I"C:\work\NXP\NXP_CUP_CAR\CMSIS" -I"C:\work\NXP\NXP_CUP_CAR\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


