################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/IO/HddSensor.cpp \
../Source/IO/Sensor.cpp 

OBJS += \
./Source/IO/HddSensor.o \
./Source/IO/Sensor.o 

CPP_DEPS += \
./Source/IO/HddSensor.d \
./Source/IO/Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Source/IO/%.o: ../Source/IO/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/include/libxml2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


