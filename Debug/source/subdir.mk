################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/RaceCar_P2.cpp \
../source/cpp_config.cpp 

C_SRCS += \
../source/drive_tracking.c \
../source/irq_handler.c \
../source/misc.c \
../source/semihost_hardfault.c 

OBJS += \
./source/RaceCar_P2.o \
./source/cpp_config.o \
./source/drive_tracking.o \
./source/irq_handler.o \
./source/misc.o \
./source/semihost_hardfault.o 

CPP_DEPS += \
./source/RaceCar_P2.d \
./source/cpp_config.d 

C_DEPS += \
./source/drive_tracking.d \
./source/irq_handler.d \
./source/misc.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\work\NXP\NXP_CUP_CAR\board" -I"C:\work\NXP\NXP_CUP_CAR\source" -I"C:\work\NXP\NXP_CUP_CAR\source\generated" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\include" -I"C:\work\NXP\NXP_CUP_CAR\component\osa" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\inc" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\work\NXP\NXP_CUP_CAR\drivers" -I"C:\work\NXP\NXP_CUP_CAR\drivers\freertos" -I"C:\work\NXP\NXP_CUP_CAR\utilities" -I"C:\work\NXP\NXP_CUP_CAR\component\serial_manager" -I"C:\work\NXP\NXP_CUP_CAR\component\uart" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source\fsl_sd_disk" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host\class" -I"C:\work\NXP\NXP_CUP_CAR\usb\include" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\osa" -I"C:\work\NXP\NXP_CUP_CAR\component\lists" -I"C:\work\NXP\NXP_CUP_CAR\CMSIS" -I"C:\work\NXP\NXP_CUP_CAR\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\work\NXP\NXP_CUP_CAR\board" -I"C:\work\NXP\NXP_CUP_CAR\source" -I"C:\work\NXP\NXP_CUP_CAR\source\generated" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\include" -I"C:\work\NXP\NXP_CUP_CAR\component\osa" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\inc" -I"C:\work\NXP\NXP_CUP_CAR\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\work\NXP\NXP_CUP_CAR\drivers" -I"C:\work\NXP\NXP_CUP_CAR\drivers\freertos" -I"C:\work\NXP\NXP_CUP_CAR\utilities" -I"C:\work\NXP\NXP_CUP_CAR\component\serial_manager" -I"C:\work\NXP\NXP_CUP_CAR\component\uart" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source" -I"C:\work\NXP\NXP_CUP_CAR\fatfs\source\fsl_sd_disk" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host" -I"C:\work\NXP\NXP_CUP_CAR\usb\host\class" -I"C:\work\NXP\NXP_CUP_CAR\usb\include" -I"C:\work\NXP\NXP_CUP_CAR\sdmmc\osa" -I"C:\work\NXP\NXP_CUP_CAR\component\lists" -I"C:\work\NXP\NXP_CUP_CAR\CMSIS" -I"C:\work\NXP\NXP_CUP_CAR\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


