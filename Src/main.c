/**
  ******************************************************************************
  * @file    LwIP/LwIP_HTTP_Server_Netconn_RTOS/Src/main.c 
  * @author  MCD Application Team
  * @brief   This sample code implements a http server application based on 
  *          Netconn API of LwIP stack and FreeRTOS. This application uses 
  *          STM32F7xx the ETH HAL API to transmit and receive data. 
  *          The communication is done with a web browser of a remote PC.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "ethernetif.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "app_ethernet.h"
//#include "httpserver-netconn.h"
#include "../SW4STM32/STM32746G_Nucleo/Application/User/tcp_echoserver.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct netif gnetif; /* network interface structure */

UART_HandleTypeDef huart3;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void StartThread(void const * argument);
static void Netif_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void MX_USART3_UART_Init(void);

static void MX_GPIO_Init(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Configure the MPU attributes as Device memory for ETH DMA descriptors */
  MPU_Config();
  
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
  HAL_Init();  
  
  /* Configure the system clock to 216 MHz */
  SystemClock_Config(); 

  MX_GPIO_Init();

  /*configure LED1 and LED3 */
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  /* Init thread */
#if defined(__GNUC__)
  osThreadDef(Start, StartThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 5);
#else
  osThreadDef(Start, StartThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
#endif
  
  osThreadCreate (osThread(Start), NULL);

  /* Start scheduler */
  osKernelStart();
  

  //todo HAL_UART_Transmit(&huart3, "Control_Lost\r\n", 14, 100);


  while (1)
  {
    /* USER CODE END WHILE */

	  if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)){
		  HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
		 /* HAL_GPIO_WritePin(GPIOE, STEP1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE, STEP2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE, STEP3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE, DIR3_Pin, GPIO_PIN_SET);
		//  HAL_GPIO_WritePin(GPIOE, RELAY1_ONOFF_Pin, GPIO_PIN_SET);
		//  HAL_GPIO_WritePin(GPIOE, RELAY1_UPDOWN_Pin, GPIO_PIN_SET);
		  */
		  HAL_Delay(10);
	/*
		  HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
		//  HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
		  //Шаговый движок №1
		  HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_SET);
		  HAL_Delay(10);
		  HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);


		  //Шаговый движок №2
		  HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_RESET);

 		 //Шаговый движок №3
		  HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOD, DIR3_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOD, DIR3_Pin, GPIO_PIN_RESET);

 		 //Колонная
		  HAL_GPIO_WritePin(GPIOE, RELAY1_ONOFF_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOE, RELAY1_ONOFF_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOE, RELAY1_UPDOWN_Pin, GPIO_PIN_SET);
 		  HAL_GPIO_WritePin(GPIOD, RELAY1_UPDOWN_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_SET);
		  HAL_Delay(10);
		  HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);
*/

	  }
	  else {
		  /*  HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_RESET);
*/
/*
		  HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, STEP1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, STEP2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, STEP3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, DIR3_Pin, GPIO_PIN_RESET);
		//  HAL_GPIO_WritePin(GPIOE, RELAY1_ONOFF_Pin, GPIO_PIN_RESET);
		//  HAL_GPIO_WritePin(GPIOE, RELAY1_UPDOWN_Pin, GPIO_PIN_RESET);
		  HAL_Delay(10);
	*/
	  }

  }
  /* We should never get here as control is now taken by the scheduler */

}

/**
  * @brief  Start Thread 
  * @param  argument not used
  * @retval None
  */
static void StartThread(void const * argument)
{ 
	//todo HAL_UART_Transmit(&huart3, "tcpip_init\r\n", 12, 100);
  /* Create tcp_ip stack thread */
  tcpip_init(NULL, NULL);
  
  //todo HAL_UART_Transmit(&huart3, "Netif_Config\r\n", 14, 100);
  /* Initialize the LwIP stack */
  Netif_Config();
  
  /* Initialize webserver demo */
  //http_server_netconn_init();


  //todo
//  MX_USART3_UART_Init();
//  //todo
//  HAL_StatusTypeDef res;
//  for(int i=0; i<100; i++){
//	  res = HAL_UART_Transmit(&huart3, "data\r\n", 6, 100);
//	  BSP_LED_On(LED_GREEN);
//
//	  for(int j=0; j<100000; j++)
//		  for(int k=0; k<100; k++);
//	  BSP_LED_Off(LED_GREEN);
//	  for(int j=0; j<100000; j++)
//	  		  for(int k=0; k<100; k++);
//  }


  //todo HAL_UART_Transmit(&huart3, "tcp_echoserver_init_Before\r\n", 28, 100);
	/* tcp echo server Init */
	tcp_echoserver_init();
	//todo HAL_UART_Transmit(&huart3, "tcp_echoserver_init\r\n", 21, 100);

  
  /* Notify user about the network interface config */
  User_notification(&gnetif);
  
#ifdef USE_DHCP
  /* Start DHCPClient */
  osThreadDef(DHCP, DHCP_thread, osPriorityBelowNormal, 0, configMINIMAL_STACK_SIZE * 2);
  osThreadCreate (osThread(DHCP), &gnetif);
#endif

  for( ;; )
  {
	  //todo HAL_UART_Transmit(&huart3, "osThreadTerminate_Before\r\n", 26, 100);
    /* Delete the Init Thread */ 
    osThreadTerminate(NULL);
    //todo HAL_UART_Transmit(&huart3, "osThreadTerminate_After\r\n", 25, 100);
  }
}

/**
  * @brief  Initializes the lwIP stack
  * @param  None
  * @retval None
  */
static void Netif_Config(void)
{
  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;
 
#ifdef USE_DHCP
  ip_addr_set_zero_ip4(&ipaddr);
  ip_addr_set_zero_ip4(&netmask);
  ip_addr_set_zero_ip4(&gw);
#else
  IP_ADDR4(&ipaddr,IP_ADDR0,IP_ADDR1,IP_ADDR2,IP_ADDR3);
  IP_ADDR4(&netmask,NETMASK_ADDR0,NETMASK_ADDR1,NETMASK_ADDR2,NETMASK_ADDR3);
  IP_ADDR4(&gw,GW_ADDR0,GW_ADDR1,GW_ADDR2,GW_ADDR3);
#endif /* USE_DHCP */
  
  /* add the network interface */    
  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
  
  /*  Registers the default network interface. */
  netif_set_default(&gnetif);
  
  if (netif_is_link_up(&gnetif))
  {
    /* When the netif is fully configured this function must be called.*/
    netif_set_up(&gnetif);
  }
  else
  {
    /* When the netif link is down this function must be called */
    netif_set_down(&gnetif);
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

//todo
//    /* Enable USART1 and GPIOA clock */
//    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
//
//    /* Configure the GPIOs */
//    GPIO_InitTypeDef GPIO_InitStructure;
//
//    /* Configure USART1 Tx (PA.09) as alternate function push-pull */
//    GPIO_InitStructure.Pin = GPIO_PIN_9;
//    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    /* Configure USART1 Rx (PA.10) as input floating */
//    GPIO_InitStructure.Pin = GPIO_PIN_10;
//    GPIO_InitStructure.Mode = GPIO_MODE_IN_FLOATING;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  //todo BSP_LED_On(LED2);
  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes .
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();
  
  /* Configure the MPU as Normal Non Cacheable for Ethernet Buffers in the SRAM2 */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x2004C000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_16KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  
  /* Configure the MPU as Device for Ethernet Descriptors in the SRAM2 */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x2004C000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256B;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  
  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
static void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif



/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOF, PILLAR_UPDOWN_Pin, GPIO_PIN_SET);


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, STEP3_Pin|STEP2_Pin|STEP1_Pin|DIR3_Pin, GPIO_PIN_RESET);


  HAL_GPIO_WritePin(GPIOE, MAGNET1_ONOFF_Pin|MAGNET2_ONOFF_Pin|PILLAR_ONOFF_Pin, GPIO_PIN_SET);


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);


  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


  /*Configure GPIO pin : RELAY1_ONOFF_Pin */


  /*Configure GPIO pin : RELAY1_UPDOWN_Pin */


  /*Configure GPIO pins : STEP3_Pin STEP2_Pin STEP1_Pin DIR3_Pin */
  GPIO_InitStruct.Pin = STEP3_Pin|STEP2_Pin|STEP1_Pin|DIR3_Pin|DIR4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DIR5_Pin|STEP5_Pin|STEP4_Pin|MAGNET1_ONOFF_Pin|MAGNET2_ONOFF_Pin|PILLAR_ONOFF_Pin|DIR2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DIR6_Pin|STEP6_Pin|PILLAR_UPDOWN_Pin|DIR1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);


  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
