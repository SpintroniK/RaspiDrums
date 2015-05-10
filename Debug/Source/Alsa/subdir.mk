################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Alsa/Alsa.cpp 

OBJS += \
./Source/Alsa/Alsa.o 

CPP_DEPS += \
./Source/Alsa/Alsa.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Alsa/%.o: ../Source/Alsa/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


