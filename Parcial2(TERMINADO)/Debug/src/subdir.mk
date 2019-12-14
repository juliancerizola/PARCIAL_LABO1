################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Entidad.c \
../src/LinkedList.c \
../src/Opciones.c \
../src/Parcial.c \
../src/parser.c 

OBJS += \
./src/Controller.o \
./src/Entidad.o \
./src/LinkedList.o \
./src/Opciones.o \
./src/Parcial.o \
./src/parser.o 

C_DEPS += \
./src/Controller.d \
./src/Entidad.d \
./src/LinkedList.d \
./src/Opciones.d \
./src/Parcial.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


