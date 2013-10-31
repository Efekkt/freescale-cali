################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/TFC/ARM_SysTick.c" \
"../Sources/TFC/CrystalClock.c" \
"../Sources/TFC/TFC.c" \
"../Sources/TFC/TFC_ADC.c" \
"../Sources/TFC/TFC_BoardSupport.c" \
"../Sources/TFC/TFC_I2C.c" \
"../Sources/TFC/TFC_Led_RGB.c" \
"../Sources/TFC/TFC_LineScanCamera.c" \
"../Sources/TFC/TFC_MMA8451.c" \
"../Sources/TFC/TFC_Motor.c" \
"../Sources/TFC/TFC_Potentiometer.c" \
"../Sources/TFC/TFC_Queue.c" \
"../Sources/TFC/TFC_Servo.c" \
"../Sources/TFC/TFC_Terminal.c" \
"../Sources/TFC/TFC_UART.c" \
"../Sources/TFC/TFC_arm_cm0.c" \

C_SRCS += \
../Sources/TFC/ARM_SysTick.c \
../Sources/TFC/CrystalClock.c \
../Sources/TFC/TFC.c \
../Sources/TFC/TFC_ADC.c \
../Sources/TFC/TFC_BoardSupport.c \
../Sources/TFC/TFC_I2C.c \
../Sources/TFC/TFC_Led_RGB.c \
../Sources/TFC/TFC_LineScanCamera.c \
../Sources/TFC/TFC_MMA8451.c \
../Sources/TFC/TFC_Motor.c \
../Sources/TFC/TFC_Potentiometer.c \
../Sources/TFC/TFC_Queue.c \
../Sources/TFC/TFC_Servo.c \
../Sources/TFC/TFC_Terminal.c \
../Sources/TFC/TFC_UART.c \
../Sources/TFC/TFC_arm_cm0.c \

OBJS += \
./Sources/TFC/ARM_SysTick.o \
./Sources/TFC/CrystalClock.o \
./Sources/TFC/TFC.o \
./Sources/TFC/TFC_ADC.o \
./Sources/TFC/TFC_BoardSupport.o \
./Sources/TFC/TFC_I2C.o \
./Sources/TFC/TFC_Led_RGB.o \
./Sources/TFC/TFC_LineScanCamera.o \
./Sources/TFC/TFC_MMA8451.o \
./Sources/TFC/TFC_Motor.o \
./Sources/TFC/TFC_Potentiometer.o \
./Sources/TFC/TFC_Queue.o \
./Sources/TFC/TFC_Servo.o \
./Sources/TFC/TFC_Terminal.o \
./Sources/TFC/TFC_UART.o \
./Sources/TFC/TFC_arm_cm0.o \

C_DEPS += \
./Sources/TFC/ARM_SysTick.d \
./Sources/TFC/CrystalClock.d \
./Sources/TFC/TFC.d \
./Sources/TFC/TFC_ADC.d \
./Sources/TFC/TFC_BoardSupport.d \
./Sources/TFC/TFC_I2C.d \
./Sources/TFC/TFC_Led_RGB.d \
./Sources/TFC/TFC_LineScanCamera.d \
./Sources/TFC/TFC_MMA8451.d \
./Sources/TFC/TFC_Motor.d \
./Sources/TFC/TFC_Potentiometer.d \
./Sources/TFC/TFC_Queue.d \
./Sources/TFC/TFC_Servo.d \
./Sources/TFC/TFC_Terminal.d \
./Sources/TFC/TFC_UART.d \
./Sources/TFC/TFC_arm_cm0.d \

OBJS_QUOTED += \
"./Sources/TFC/ARM_SysTick.o" \
"./Sources/TFC/CrystalClock.o" \
"./Sources/TFC/TFC.o" \
"./Sources/TFC/TFC_ADC.o" \
"./Sources/TFC/TFC_BoardSupport.o" \
"./Sources/TFC/TFC_I2C.o" \
"./Sources/TFC/TFC_Led_RGB.o" \
"./Sources/TFC/TFC_LineScanCamera.o" \
"./Sources/TFC/TFC_MMA8451.o" \
"./Sources/TFC/TFC_Motor.o" \
"./Sources/TFC/TFC_Potentiometer.o" \
"./Sources/TFC/TFC_Queue.o" \
"./Sources/TFC/TFC_Servo.o" \
"./Sources/TFC/TFC_Terminal.o" \
"./Sources/TFC/TFC_UART.o" \
"./Sources/TFC/TFC_arm_cm0.o" \

C_DEPS_QUOTED += \
"./Sources/TFC/ARM_SysTick.d" \
"./Sources/TFC/CrystalClock.d" \
"./Sources/TFC/TFC.d" \
"./Sources/TFC/TFC_ADC.d" \
"./Sources/TFC/TFC_BoardSupport.d" \
"./Sources/TFC/TFC_I2C.d" \
"./Sources/TFC/TFC_Led_RGB.d" \
"./Sources/TFC/TFC_LineScanCamera.d" \
"./Sources/TFC/TFC_MMA8451.d" \
"./Sources/TFC/TFC_Motor.d" \
"./Sources/TFC/TFC_Potentiometer.d" \
"./Sources/TFC/TFC_Queue.d" \
"./Sources/TFC/TFC_Servo.d" \
"./Sources/TFC/TFC_Terminal.d" \
"./Sources/TFC/TFC_UART.d" \
"./Sources/TFC/TFC_arm_cm0.d" \

OBJS_OS_FORMAT += \
./Sources/TFC/ARM_SysTick.o \
./Sources/TFC/CrystalClock.o \
./Sources/TFC/TFC.o \
./Sources/TFC/TFC_ADC.o \
./Sources/TFC/TFC_BoardSupport.o \
./Sources/TFC/TFC_I2C.o \
./Sources/TFC/TFC_Led_RGB.o \
./Sources/TFC/TFC_LineScanCamera.o \
./Sources/TFC/TFC_MMA8451.o \
./Sources/TFC/TFC_Motor.o \
./Sources/TFC/TFC_Potentiometer.o \
./Sources/TFC/TFC_Queue.o \
./Sources/TFC/TFC_Servo.o \
./Sources/TFC/TFC_Terminal.o \
./Sources/TFC/TFC_UART.o \
./Sources/TFC/TFC_arm_cm0.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/TFC/ARM_SysTick.o: ../Sources/TFC/ARM_SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/ARM_SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/ARM_SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/CrystalClock.o: ../Sources/TFC/CrystalClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/CrystalClock.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/CrystalClock.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC.o: ../Sources/TFC/TFC.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_ADC.o: ../Sources/TFC/TFC_ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_BoardSupport.o: ../Sources/TFC/TFC_BoardSupport.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_BoardSupport.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_BoardSupport.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_I2C.o: ../Sources/TFC/TFC_I2C.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_I2C.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_I2C.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Led_RGB.o: ../Sources/TFC/TFC_Led_RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Led_RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Led_RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_LineScanCamera.o: ../Sources/TFC/TFC_LineScanCamera.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_LineScanCamera.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_LineScanCamera.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_MMA8451.o: ../Sources/TFC/TFC_MMA8451.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_MMA8451.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_MMA8451.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Motor.o: ../Sources/TFC/TFC_Motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Motor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Motor.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Potentiometer.o: ../Sources/TFC/TFC_Potentiometer.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Potentiometer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Potentiometer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Queue.o: ../Sources/TFC/TFC_Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Servo.o: ../Sources/TFC/TFC_Servo.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Servo.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Servo.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_Terminal.o: ../Sources/TFC/TFC_Terminal.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_Terminal.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_Terminal.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_UART.o: ../Sources/TFC/TFC_UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_UART.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_UART.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TFC/TFC_arm_cm0.o: ../Sources/TFC/TFC_arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TFC/TFC_arm_cm0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TFC/TFC_arm_cm0.o"
	@echo 'Finished building: $<'
	@echo ' '


