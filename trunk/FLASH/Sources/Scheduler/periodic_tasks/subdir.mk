################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Scheduler/periodic_tasks/periodic_tasks_exec.c" \
"../Sources/Scheduler/periodic_tasks/periodic_tasks_init.c" \

C_SRCS += \
../Sources/Scheduler/periodic_tasks/periodic_tasks_exec.c \
../Sources/Scheduler/periodic_tasks/periodic_tasks_init.c \

OBJS += \
./Sources/Scheduler/periodic_tasks/periodic_tasks_exec.o \
./Sources/Scheduler/periodic_tasks/periodic_tasks_init.o \

C_DEPS += \
./Sources/Scheduler/periodic_tasks/periodic_tasks_exec.d \
./Sources/Scheduler/periodic_tasks/periodic_tasks_init.d \

OBJS_QUOTED += \
"./Sources/Scheduler/periodic_tasks/periodic_tasks_exec.o" \
"./Sources/Scheduler/periodic_tasks/periodic_tasks_init.o" \

C_DEPS_QUOTED += \
"./Sources/Scheduler/periodic_tasks/periodic_tasks_exec.d" \
"./Sources/Scheduler/periodic_tasks/periodic_tasks_init.d" \

OBJS_OS_FORMAT += \
./Sources/Scheduler/periodic_tasks/periodic_tasks_exec.o \
./Sources/Scheduler/periodic_tasks/periodic_tasks_init.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Scheduler/periodic_tasks/periodic_tasks_exec.o: ../Sources/Scheduler/periodic_tasks/periodic_tasks_exec.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/periodic_tasks/periodic_tasks_exec.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/periodic_tasks/periodic_tasks_exec.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/periodic_tasks/periodic_tasks_init.o: ../Sources/Scheduler/periodic_tasks/periodic_tasks_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/periodic_tasks/periodic_tasks_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/periodic_tasks/periodic_tasks_init.o"
	@echo 'Finished building: $<'
	@echo ' '


