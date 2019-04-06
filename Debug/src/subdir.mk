################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Particle.cpp \
../src/Screen.cpp \
../src/Swarm.cpp \
../src/sdl_basic.cpp 

OBJS += \
./src/Particle.o \
./src/Screen.o \
./src/Swarm.o \
./src/sdl_basic.o 

CPP_DEPS += \
./src/Particle.d \
./src/Screen.d \
./src/Swarm.d \
./src/sdl_basic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


