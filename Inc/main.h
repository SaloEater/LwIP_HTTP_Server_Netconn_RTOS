/**
  ******************************************************************************
  * @file    LwIP/LwIP_HTTP_Server_Netconn_RTOS/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32f7xx_nucleo_144.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/ 
#define USE_DHCP       /* enable DHCP, if disabled static address is used*/
 
/*Static IP ADDRESS*/
#define IP_ADDR0   192
#define IP_ADDR1   169
#define IP_ADDR2   2
#define IP_ADDR3   101

#define SERVER_PORT   80
   
/*NETMASK*/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/*Gateway Address*/
#define GW_ADDR0   192
#define GW_ADDR1   169
#define GW_ADDR2   2
#define GW_ADDR3   1 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */  
extern UART_HandleTypeDef huart3;

#ifdef __cplusplus
}
#endif


#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB

#define LD2_Pin GPIO_PIN_7
#define LD2_GPIO_Port GPIOB

#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB

#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC



#define DIR1_Pin GPIO_PIN_10
#define DIR1_GPIO_Port GPIOF

#define DIR2_Pin GPIO_PIN_7
#define DIR2_GPIO_Port GPIOE

#define DIR3_Pin GPIO_PIN_14
#define DIR3_GPIO_Port GPIOD

#define DIR4_Pin GPIO_PIN_15
#define DIR4_GPIO_Port GPIOD

#define DIR5_Pin GPIO_PIN_11
#define DIR5_GPIO_Port GPIOE

#define DIR6_Pin GPIO_PIN_3
#define DIR6_GPIO_Port GPIOF



#define STEP1_Pin GPIO_PIN_13
#define STEP1_GPIO_Port GPIOD

#define STEP2_Pin GPIO_PIN_12
#define STEP2_GPIO_Port GPIOD

#define STEP3_Pin GPIO_PIN_11
#define STEP3_GPIO_Port GPIOD

#define STEP4_Pin GPIO_PIN_10
#define STEP4_GPIO_Port GPIOE

#define STEP5_Pin GPIO_PIN_13
#define STEP5_GPIO_Port GPIOE

#define STEP6_Pin GPIO_PIN_13
#define STEP6_GPIO_Port GPIOF

#define PILLAR_ONOFF_Pin GPIO_PIN_12
#define PILLAR_ONOFF_GPIO_Port GPIOE

#define PILLAR_UPDOWN_Pin GPIO_PIN_14
#define PILLAR_UPDOWN_GPIO_Port GPIOF

#define MAGNET1_ONOFF_Pin GPIO_PIN_14
#define MAGNET1_ONOFF_GPIO_Port GPIOE

#define MAGNET2_ONOFF_Pin GPIO_PIN_9
#define MAGNET2_ONOFF_GPIO_Port GPIOE

/* Definition for CANx clock resources */
#define CANx                            CAN1
#define CANx_CLK_ENABLE()               __HAL_RCC_CAN1_CLK_ENABLE()
#define CANx_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()

#define CANx_FORCE_RESET()              __HAL_RCC_CAN1_FORCE_RESET()
#define CANx_RELEASE_RESET()            __HAL_RCC_CAN1_RELEASE_RESET()

/* Definition for CANx Pins */
#define CANx_TX_PIN                    GPIO_PIN_12
#define CANx_TX_GPIO_PORT              GPIOA
#define CANx_TX_AF                     GPIO_AF9_CAN1
#define CANx_RX_PIN                    GPIO_PIN_11
#define CANx_RX_GPIO_PORT              GPIOA
#define CANx_RX_AF                     GPIO_AF9_CAN1

/* Definition for CAN's NVIC */
#define CANx_RX_IRQn                   CAN1_RX0_IRQn
#define CANx_RX_IRQHandler             CAN1_RX0_IRQHandler

 /*
#define DIR1_Pin GPIO_PIN_10
#define DIR1_GPIO_Port GPIOF

#define DIR2_Pin GPIO_PIN_7
#define DIR2_GPIO_Port GPIOE

#define DIR3_Pin GPIO_PIN_14
#define DIR3_GPIO_Port GPIOD

#define RELAY1_ONOFF_Pin GPIO_PIN_10
#define RELAY1_ONOFF_GPIO_Port GPIOE
#define RELAY1_UPDOWN_Pin GPIO_PIN_15
#define RELAY1_UPDOWN_GPIO_Port GPIOD

#define STEP3_Pin GPIO_PIN_11
#define STEP3_GPIO_Port GPIOD
#define STEP2_Pin GPIO_PIN_12
#define STEP2_GPIO_Port GPIOD
#define STEP1_Pin GPIO_PIN_13
#define STEP1_GPIO_Port GPIOD
*/


#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD

#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG



#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
