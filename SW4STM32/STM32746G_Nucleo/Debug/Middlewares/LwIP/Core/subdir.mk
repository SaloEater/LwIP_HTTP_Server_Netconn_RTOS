################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/def.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/dns.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/inet_chksum.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/init.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/ip.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/mem.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/memp.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/netif.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/pbuf.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/raw.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/stats.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/sys.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp_in.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp_out.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/timeouts.c \
C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/udp.c 

OBJS += \
./Middlewares/LwIP/Core/def.o \
./Middlewares/LwIP/Core/dns.o \
./Middlewares/LwIP/Core/inet_chksum.o \
./Middlewares/LwIP/Core/init.o \
./Middlewares/LwIP/Core/ip.o \
./Middlewares/LwIP/Core/mem.o \
./Middlewares/LwIP/Core/memp.o \
./Middlewares/LwIP/Core/netif.o \
./Middlewares/LwIP/Core/pbuf.o \
./Middlewares/LwIP/Core/raw.o \
./Middlewares/LwIP/Core/stats.o \
./Middlewares/LwIP/Core/sys.o \
./Middlewares/LwIP/Core/tcp.o \
./Middlewares/LwIP/Core/tcp_in.o \
./Middlewares/LwIP/Core/tcp_out.o \
./Middlewares/LwIP/Core/timeouts.o \
./Middlewares/LwIP/Core/udp.o 

C_DEPS += \
./Middlewares/LwIP/Core/def.d \
./Middlewares/LwIP/Core/dns.d \
./Middlewares/LwIP/Core/inet_chksum.d \
./Middlewares/LwIP/Core/init.d \
./Middlewares/LwIP/Core/ip.d \
./Middlewares/LwIP/Core/mem.d \
./Middlewares/LwIP/Core/memp.d \
./Middlewares/LwIP/Core/netif.d \
./Middlewares/LwIP/Core/pbuf.d \
./Middlewares/LwIP/Core/raw.d \
./Middlewares/LwIP/Core/stats.d \
./Middlewares/LwIP/Core/sys.d \
./Middlewares/LwIP/Core/tcp.d \
./Middlewares/LwIP/Core/tcp_in.d \
./Middlewares/LwIP/Core/tcp_out.d \
./Middlewares/LwIP/Core/timeouts.d \
./Middlewares/LwIP/Core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LwIP/Core/def.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/def.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/def.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/dns.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/dns.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/dns.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/inet_chksum.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/inet_chksum.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/inet_chksum.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/init.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/init.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/init.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/ip.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/ip.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/ip.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/mem.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/mem.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/mem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/memp.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/memp.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/memp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/netif.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/netif.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/netif.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/pbuf.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/pbuf.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/pbuf.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/raw.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/raw.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/raw.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/stats.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/stats.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/stats.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/sys.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/sys.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/sys.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/tcp.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/tcp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/tcp_in.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp_in.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/tcp_in.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/tcp_out.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/tcp_out.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/tcp_out.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/timeouts.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/timeouts.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/timeouts.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Core/udp.o: C:/Users/danil/Documents/Univ/Robot/LwIP_HTTP_Server_Netconn_RTOS/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/core/udp.c Middlewares/LwIP/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32F7XX_NUCLEO_144ADAFRUIT_TFT_JOY_SD_ID802 -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LwIP/Core/udp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

