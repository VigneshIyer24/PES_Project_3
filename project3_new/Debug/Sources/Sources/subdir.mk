################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Sources/adc.c \
../Sources/Sources/applic.c \
../Sources/Sources/dma.c \
../Sources/Sources/main.c \
../Sources/Sources/pit.c \
../Sources/Sources/sa_mtlb.c \
../Sources/Sources/uart.c 

OBJS += \
./Sources/Sources/adc.o \
./Sources/Sources/applic.o \
./Sources/Sources/dma.o \
./Sources/Sources/main.o \
./Sources/Sources/pit.o \
./Sources/Sources/sa_mtlb.o \
./Sources/Sources/uart.o 

C_DEPS += \
./Sources/Sources/adc.d \
./Sources/Sources/applic.d \
./Sources/Sources/dma.d \
./Sources/Sources/main.d \
./Sources/Sources/pit.d \
./Sources/Sources/sa_mtlb.d \
./Sources/Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Sources/%.o: ../Sources/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


