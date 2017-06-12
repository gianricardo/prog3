################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/jogopresidente.cpp \
../src/main.cpp \
../src/regrapresidente.cpp 

OBJS += \
./src/jogopresidente.o \
./src/main.o \
./src/regrapresidente.o 

CPP_DEPS += \
./src/jogopresidente.d \
./src/main.d \
./src/regrapresidente.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


