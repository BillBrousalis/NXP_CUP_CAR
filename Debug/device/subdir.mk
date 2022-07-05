################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MK64F12.c 

OBJS += \
./device/system_MK64F12.o 

C_DEPS += \
./device/system_MK64F12.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\work\NxpCup\RaceCar_P2\board" -I"C:\work\NxpCup\RaceCar_P2\source" -I"C:\work\NxpCup\RaceCar_P2\sdmmc\template\sdhc" -I"C:\work\NxpCup\RaceCar_P2\source\generated" -I"C:\work\NxpCup\RaceCar_P2\freertos\freertos_kernel\include" -I"C:\work\NxpCup\RaceCar_P2\component\osa" -I"C:\work\NxpCup\RaceCar_P2\sdmmc\inc" -I"C:\work\NxpCup\RaceCar_P2\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\work\NxpCup\RaceCar_P2\drivers" -I"C:\work\NxpCup\RaceCar_P2\drivers\freertos" -I"C:\work\NxpCup\RaceCar_P2\utilities" -I"C:\work\NxpCup\RaceCar_P2\component\serial_manager" -I"C:\work\NxpCup\RaceCar_P2\component\uart" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source\fsl_mmc_disk" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source\fsl_ram_disk" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source\fsl_sd_disk" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source\fsl_sdspi_disk" -I"C:\work\NxpCup\RaceCar_P2\fatfs\source\fsl_usb_disk" -I"C:\work\NxpCup\RaceCar_P2\sdmmc\host" -I"C:\work\NxpCup\RaceCar_P2\usb\host" -I"C:\work\NxpCup\RaceCar_P2\usb\host\class" -I"C:\work\NxpCup\RaceCar_P2\usb\include" -I"C:\work\NxpCup\RaceCar_P2\sdmmc\osa" -I"C:\work\NxpCup\RaceCar_P2\component\lists" -I"C:\work\NxpCup\RaceCar_P2\CMSIS" -I"C:\work\NxpCup\RaceCar_P2\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


