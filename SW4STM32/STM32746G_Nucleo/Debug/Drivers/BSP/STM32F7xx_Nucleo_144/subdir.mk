################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.c 

OBJS += \
./Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.o 

C_DEPS += \
./Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.c Drivers/BSP/STM32F7xx_Nucleo_144/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32F7xx_Nucleo_144/stm32f7xx_nucleo_144.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

