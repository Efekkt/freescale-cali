################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/SDL/ADC.c" \
"../Sources/SDL/BoardSupport.c" \
"../Sources/SDL/I2C.c" \
"../Sources/SDL/Led_RGB.c" \
"../Sources/SDL/LineScanCamera.c" \
"../Sources/SDL/MMA8451.c" \
"../Sources/SDL/Motor.c" \
"../Sources/SDL/Potentiometer.c" \
"../Sources/SDL/Queue.c" \
"../Sources/SDL/Servo.c" \
"../Sources/SDL/Terminal.c" \
"../Sources/SDL/UART.c" \

C_SRCS += \
../Sources/SDL/ADC.c \
../Sources/SDL/BoardSupport.c \
../Sources/SDL/I2C.c \
../Sources/SDL/Led_RGB.c \
../Sources/SDL/LineScanCamera.c \
../Sources/SDL/MMA8451.c \
../Sources/SDL/Motor.c \
../Sources/SDL/Potentiometer.c \
../Sources/SDL/Queue.c \
../Sources/SDL/Servo.c \
../Sources/SDL/Terminal.c \
../Sources/SDL/UART.c \

OBJS += \
./Sources/SDL/ADC.o \
./Sources/SDL/BoardSupport.o \
./Sources/SDL/I2C.o \
./Sources/SDL/Led_RGB.o \
./Sources/SDL/LineScanCamera.o \
./Sources/SDL/MMA8451.o \
./Sources/SDL/Motor.o \
./Sources/SDL/Potentiometer.o \
./Sources/SDL/Queue.o \
./Sources/SDL/Servo.o \
./Sources/SDL/Terminal.o \
./Sources/SDL/UART.o \

C_DEPS += \
./Sources/SDL/ADC.d \
./Sources/SDL/BoardSupport.d \
./Sources/SDL/I2C.d \
./Sources/SDL/Led_RGB.d \
./Sources/SDL/LineScanCamera.d \
./Sources/SDL/MMA8451.d \
./Sources/SDL/Motor.d \
./Sources/SDL/Potentiometer.d \
./Sources/SDL/Queue.d \
./Sources/SDL/Servo.d \
./Sources/SDL/Terminal.d \
./Sources/SDL/UART.d \

OBJS_QUOTED += \
"./Sources/SDL/ADC.o" \
"./Sources/SDL/BoardSupport.o" \
"./Sources/SDL/I2C.o" \
"./Sources/SDL/Led_RGB.o" \
"./Sources/SDL/LineScanCamera.o" \
"./Sources/SDL/MMA8451.o" \
"./Sources/SDL/Motor.o" \
"./Sources/SDL/Potentiometer.o" \
"./Sources/SDL/Queue.o" \
"./Sources/SDL/Servo.o" \
"./Sources/SDL/Terminal.o" \
"./Sources/SDL/UART.o" \

C_DEPS_QUOTED += \
"./Sources/SDL/ADC.d" \
"./Sources/SDL/BoardSupport.d" \
"./Sources/SDL/I2C.d" \
"./Sources/SDL/Led_RGB.d" \
"./Sources/SDL/LineScanCamera.d" \
"./Sources/SDL/MMA8451.d" \
"./Sources/SDL/Motor.d" \
"./Sources/SDL/Potentiometer.d" \
"./Sources/SDL/Queue.d" \
"./Sources/SDL/Servo.d" \
"./Sources/SDL/Terminal.d" \
"./Sources/SDL/UART.d" \

OBJS_OS_FORMAT += \
./Sources/SDL/ADC.o \
./Sources/SDL/BoardSupport.o \
./Sources/SDL/I2C.o \
./Sources/SDL/Led_RGB.o \
./Sources/SDL/LineScanCamera.o \
./Sources/SDL/MMA8451.o \
./Sources/SDL/Motor.o \
./Sources/SDL/Potentiometer.o \
./Sources/SDL/Queue.o \
./Sources/SDL/Servo.o \
./Sources/SDL/Terminal.o \
./Sources/SDL/UART.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/SDL/ADC.o: ../Sources/SDL/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/BoardSupport.o: ../Sources/SDL/BoardSupport.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/BoardSupport.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/BoardSupport.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/I2C.o: ../Sources/SDL/I2C.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/I2C.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/I2C.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Led_RGB.o: ../Sources/SDL/Led_RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Led_RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Led_RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/LineScanCamera.o: ../Sources/SDL/LineScanCamera.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/LineScanCamera.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/LineScanCamera.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/MMA8451.o: ../Sources/SDL/MMA8451.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/MMA8451.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/MMA8451.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Motor.o: ../Sources/SDL/Motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Motor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Motor.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Potentiometer.o: ../Sources/SDL/Potentiometer.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Potentiometer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Potentiometer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Queue.o: ../Sources/SDL/Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Servo.o: ../Sources/SDL/Servo.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Servo.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Servo.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/Terminal.o: ../Sources/SDL/Terminal.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/Terminal.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/Terminal.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SDL/UART.o: ../Sources/SDL/UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SDL/UART.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SDL/UART.o"
	@echo 'Finished building: $<'
	@echo ' '


