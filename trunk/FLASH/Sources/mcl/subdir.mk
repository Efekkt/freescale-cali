################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MCL/ARM_SysTick.c" \
"../Sources/MCL/CrystalClock.c" \
"../Sources/MCL/arm_cm0.c" \
"../Sources/MCL/interrupts.c" \

C_SRCS += \
../Sources/MCL/ARM_SysTick.c \
../Sources/MCL/CrystalClock.c \
../Sources/MCL/arm_cm0.c \
../Sources/MCL/interrupts.c \

OBJS += \
./Sources/MCL/ARM_SysTick.o \
./Sources/MCL/CrystalClock.o \
./Sources/MCL/arm_cm0.o \
./Sources/MCL/interrupts.o \

C_DEPS += \
./Sources/MCL/ARM_SysTick.d \
./Sources/MCL/CrystalClock.d \
./Sources/MCL/arm_cm0.d \
./Sources/MCL/interrupts.d \

OBJS_QUOTED += \
"./Sources/MCL/ARM_SysTick.o" \
"./Sources/MCL/CrystalClock.o" \
"./Sources/MCL/arm_cm0.o" \
"./Sources/MCL/interrupts.o" \

C_DEPS_QUOTED += \
"./Sources/MCL/ARM_SysTick.d" \
"./Sources/MCL/CrystalClock.d" \
"./Sources/MCL/arm_cm0.d" \
"./Sources/MCL/interrupts.d" \

OBJS_OS_FORMAT += \
./Sources/MCL/ARM_SysTick.o \
./Sources/MCL/CrystalClock.o \
./Sources/MCL/arm_cm0.o \
./Sources/MCL/interrupts.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/MCL/ARM_SysTick.o: ../Sources/MCL/ARM_SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCL/ARM_SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MCL/ARM_SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCL/CrystalClock.o: ../Sources/MCL/CrystalClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCL/CrystalClock.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MCL/CrystalClock.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCL/arm_cm0.o: ../Sources/MCL/arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCL/arm_cm0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MCL/arm_cm0.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCL/interrupts.o: ../Sources/MCL/interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCL/interrupts.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MCL/interrupts.o"
	@echo 'Finished building: $<'
	@echo ' '


