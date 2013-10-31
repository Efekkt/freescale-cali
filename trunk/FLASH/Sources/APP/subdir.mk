################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/APP/Coeficientes.c" \
"../Sources/APP/Tasks.c" \

C_SRCS += \
../Sources/APP/Coeficientes.c \
../Sources/APP/Tasks.c \

OBJS += \
./Sources/APP/Coeficientes.o \
./Sources/APP/Tasks.o \

C_DEPS += \
./Sources/APP/Coeficientes.d \
./Sources/APP/Tasks.d \

OBJS_QUOTED += \
"./Sources/APP/Coeficientes.o" \
"./Sources/APP/Tasks.o" \

C_DEPS_QUOTED += \
"./Sources/APP/Coeficientes.d" \
"./Sources/APP/Tasks.d" \

OBJS_OS_FORMAT += \
./Sources/APP/Coeficientes.o \
./Sources/APP/Tasks.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/APP/Coeficientes.o: ../Sources/APP/Coeficientes.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/APP/Coeficientes.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/APP/Coeficientes.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/APP/Tasks.o: ../Sources/APP/Tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/APP/Tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/APP/Tasks.o"
	@echo 'Finished building: $<'
	@echo ' '


