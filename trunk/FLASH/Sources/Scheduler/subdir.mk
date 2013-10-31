################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Scheduler/Coeficientes.c" \
"../Sources/Scheduler/TFC_Tasks.c" \

C_SRCS += \
../Sources/Scheduler/Coeficientes.c \
../Sources/Scheduler/TFC_Tasks.c \

OBJS += \
./Sources/Scheduler/Coeficientes.o \
./Sources/Scheduler/TFC_Tasks.o \

C_DEPS += \
./Sources/Scheduler/Coeficientes.d \
./Sources/Scheduler/TFC_Tasks.d \

OBJS_QUOTED += \
"./Sources/Scheduler/Coeficientes.o" \
"./Sources/Scheduler/TFC_Tasks.o" \

C_DEPS_QUOTED += \
"./Sources/Scheduler/Coeficientes.d" \
"./Sources/Scheduler/TFC_Tasks.d" \

OBJS_OS_FORMAT += \
./Sources/Scheduler/Coeficientes.o \
./Sources/Scheduler/TFC_Tasks.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Scheduler/Coeficientes.o: ../Sources/Scheduler/Coeficientes.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/Coeficientes.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/Coeficientes.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Scheduler/TFC_Tasks.o: ../Sources/Scheduler/TFC_Tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Scheduler/TFC_Tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Scheduler/TFC_Tasks.o"
	@echo 'Finished building: $<'
	@echo ' '


