################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Signal/Trigger.cpp 

OBJS += \
./Source/Signal/Trigger.o 

CPP_DEPS += \
./Source/Signal/Trigger.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Signal/%.o: ../Source/Signal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/include/libxml2 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


