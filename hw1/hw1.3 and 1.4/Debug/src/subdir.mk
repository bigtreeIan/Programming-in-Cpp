################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/hw1.3\ and\ 1.4.cpp 

OBJS += \
./src/hw1.3\ and\ 1.4.o 

CPP_DEPS += \
./src/hw1.3\ and\ 1.4.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw1.3\ and\ 1.4.o: ../src/hw1.3\ and\ 1.4.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/hw1.3 and 1.4.d" -MT"src/hw1.3\ and\ 1.4.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


