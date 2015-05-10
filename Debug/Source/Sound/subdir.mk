################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Sound/Alsa.cpp \
../Source/Sound/Mixer.cpp 

OBJS += \
./Source/Sound/Alsa.o \
./Source/Sound/Mixer.o 

CPP_DEPS += \
./Source/Sound/Alsa.d \
./Source/Sound/Mixer.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Sound/%.o: ../Source/Sound/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/include/libxml2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


