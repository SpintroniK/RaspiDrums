################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Testing/DrumKitTest.cpp \
../Source/Testing/DrumKit_HddTest.cpp \
../Source/Testing/HddSensorTest.cpp \
../Source/Testing/SensorTest.cpp 

OBJS += \
./Source/Testing/DrumKitTest.o \
./Source/Testing/DrumKit_HddTest.o \
./Source/Testing/HddSensorTest.o \
./Source/Testing/SensorTest.o 

CPP_DEPS += \
./Source/Testing/DrumKitTest.d \
./Source/Testing/DrumKit_HddTest.d \
./Source/Testing/HddSensorTest.d \
./Source/Testing/SensorTest.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Testing/%.o: ../Source/Testing/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/include/libxml2 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


