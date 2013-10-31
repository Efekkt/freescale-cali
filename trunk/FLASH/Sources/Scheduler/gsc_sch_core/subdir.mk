################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Scheduler/gsc_sch_core/gsc_sch_core.c" \
"../Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.c" \
"../Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.c" \

C_SRCS += \
../Sources/Scheduler/gsc_sch_core/gsc_sch_core.c \
../Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.c \
../Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.c \

OBJS += \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core.o \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.o \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.o \

C_DEPS += \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core.d \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.d \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.d \

OBJS_QUOTED += \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core.o" \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.o" \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.o" \

C_DEPS_QUOTED += \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core.d" \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.d" \
"./Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.d" \

OBJS_OS_FORMAT += \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core.o \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.o \
./Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Scheduler/gsc_sch_core/gsc_sch_core.o: ../Sources/Scheduler/gsc_sch_core/gsc_sch_core.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/gsc_sch_core/gsc_sch_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/gsc_sch_core/gsc_sch_core.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.o: ../Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/gsc_sch_core/gsc_sch_core_cfg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.o: ../Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/gsc_sch_core/gsc_sch_core_tick_isr.o"
	@echo 'Finished building: $<'
	@echo ' '


