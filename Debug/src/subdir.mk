################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Capa.cpp \
../src/Caso.cpp \
../src/Data.cpp \
../src/Neurona.cpp \
../src/PerceptronMultiCapa.cpp \
../src/RedMultiCapaPerceptron.cpp 

OBJS += \
./src/Capa.o \
./src/Caso.o \
./src/Data.o \
./src/Neurona.o \
./src/PerceptronMultiCapa.o \
./src/RedMultiCapaPerceptron.o 

CPP_DEPS += \
./src/Capa.d \
./src/Caso.d \
./src/Data.d \
./src/Neurona.d \
./src/PerceptronMultiCapa.d \
./src/RedMultiCapaPerceptron.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


