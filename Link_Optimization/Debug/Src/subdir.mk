################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/PID.c \
../Src/Servo_Move.c \
../Src/adc.c \
../Src/algorithm.c \
../Src/main.c \
../Src/process_console.c \
../Src/scanning_function.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick.c \
../Src/tim.c \
../Src/uart.c \
../Src/uart1.c 

OBJS += \
./Src/PID.o \
./Src/Servo_Move.o \
./Src/adc.o \
./Src/algorithm.o \
./Src/main.o \
./Src/process_console.o \
./Src/scanning_function.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick.o \
./Src/tim.o \
./Src/uart.o \
./Src/uart1.o 

C_DEPS += \
./Src/PID.d \
./Src/Servo_Move.d \
./Src/adc.d \
./Src/algorithm.d \
./Src/main.d \
./Src/process_console.d \
./Src/scanning_function.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick.d \
./Src/tim.d \
./Src/uart.d \
./Src/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"C:/Users/A/OneDrive - California State University San Marcos/Documents/STM32 Bare Metal Workspace/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/A/OneDrive - California State University San Marcos/Documents/STM32 Bare Metal Workspace/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/PID.cyclo ./Src/PID.d ./Src/PID.o ./Src/PID.su ./Src/Servo_Move.cyclo ./Src/Servo_Move.d ./Src/Servo_Move.o ./Src/Servo_Move.su ./Src/adc.cyclo ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/algorithm.cyclo ./Src/algorithm.d ./Src/algorithm.o ./Src/algorithm.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/process_console.cyclo ./Src/process_console.d ./Src/process_console.o ./Src/process_console.su ./Src/scanning_function.cyclo ./Src/scanning_function.d ./Src/scanning_function.o ./Src/scanning_function.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/systick.cyclo ./Src/systick.d ./Src/systick.o ./Src/systick.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su ./Src/uart1.cyclo ./Src/uart1.d ./Src/uart1.o ./Src/uart1.su

.PHONY: clean-Src

