################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Scheduler/Core/Core.c" \
"../Sources/Scheduler/Core/Core_Config.c" \
"../Sources/Scheduler/Core/Core_Tick_ISR.c" \

C_SRCS += \
../Sources/Scheduler/Core/Core.c \
../Sources/Scheduler/Core/Core_Config.c \
../Sources/Scheduler/Core/Core_Tick_ISR.c \

OBJS += \
./Sources/Scheduler/Core/Core.o \
./Sources/Scheduler/Core/Core_Config.o \
./Sources/Scheduler/Core/Core_Tick_ISR.o \

C_DEPS += \
./Sources/Scheduler/Core/Core.d \
./Sources/Scheduler/Core/Core_Config.d \
./Sources/Scheduler/Core/Core_Tick_ISR.d \

OBJS_QUOTED += \
"./Sources/Scheduler/Core/Core.o" \
"./Sources/Scheduler/Core/Core_Config.o" \
"./Sources/Scheduler/Core/Core_Tick_ISR.o" \

C_DEPS_QUOTED += \
"./Sources/Scheduler/Core/Core.d" \
"./Sources/Scheduler/Core/Core_Config.d" \
"./Sources/Scheduler/Core/Core_Tick_ISR.d" \

OBJS_OS_FORMAT += \
./Sources/Scheduler/Core/Core.o \
./Sources/Scheduler/Core/Core_Config.o \
./Sources/Scheduler/Core/Core_Tick_ISR.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Scheduler/Core/Core.o: ../Sources/Scheduler/Core/Core.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/Core/Core.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/Core/Core.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/Core/Core_Config.o: ../Sources/Scheduler/Core/Core_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/Core/Core_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/Core/Core_Config.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/Core/Core_Tick_ISR.o: ../Sources/Scheduler/Core/Core_Tick_ISR.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/Core/Core_Tick_ISR.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/Core/Core_Tick_ISR.o"
	@echo 'Finished building: $<'
	@echo ' '


