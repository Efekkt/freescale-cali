################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Scheduler/PeriodicTasks/Periodic_Tasks.c" \
"../Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.c" \

C_SRCS += \
../Sources/Scheduler/PeriodicTasks/Periodic_Tasks.c \
../Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.c \

OBJS += \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks.o \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.o \

C_DEPS += \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks.d \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.d \

OBJS_QUOTED += \
"./Sources/Scheduler/PeriodicTasks/Periodic_Tasks.o" \
"./Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.o" \

C_DEPS_QUOTED += \
"./Sources/Scheduler/PeriodicTasks/Periodic_Tasks.d" \
"./Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.d" \

OBJS_OS_FORMAT += \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks.o \
./Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Scheduler/PeriodicTasks/Periodic_Tasks.o: ../Sources/Scheduler/PeriodicTasks/Periodic_Tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/PeriodicTasks/Periodic_Tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/PeriodicTasks/Periodic_Tasks.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.o: ../Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/PeriodicTasks/Periodic_Tasks_Init.o"
	@echo 'Finished building: $<'
	@echo ' '


