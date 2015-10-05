################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Case.cpp \
../src/Data.cpp \
../src/Layer.cpp \
../src/Neuron.cpp \
../src/RedMultiCapaPerceptron.cpp \
../src/main.cpp 

OBJS += \
./src/Case.o \
./src/Data.o \
./src/Layer.o \
./src/Neuron.o \
./src/RedMultiCapaPerceptron.o \
./src/main.o 

CPP_DEPS += \
./src/Case.d \
./src/Data.d \
./src/Layer.d \
./src/Neuron.d \
./src/RedMultiCapaPerceptron.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


