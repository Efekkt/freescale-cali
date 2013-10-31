################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/mcl/interrupts.c" \

C_SRCS += \
../Sources/mcl/interrupts.c \

OBJS += \
./Sources/mcl/interrupts.o \

C_DEPS += \
./Sources/mcl/interrupts.d \

OBJS_QUOTED += \
"./Sources/mcl/interrupts.o" \

C_DEPS_QUOTED += \
"./Sources/mcl/interrupts.d" \

OBJS_OS_FORMAT += \
./Sources/mcl/interrupts.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/mcl/interrupts.o: ../Sources/mcl/interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/interrupts.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/interrupts.o"
	@echo 'Finished building: $<'
	@echo ' '


