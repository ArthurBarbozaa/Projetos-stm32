/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* Definitions for BlinkLedYellow */
osThreadId_t BlinkLedYellowHandle;
const osThreadAttr_t BlinkLedYellow_attributes = {
  .name = "BlinkLedYellow",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BlinkLedGreen */
osThreadId_t BlinkLedGreenHandle;
const osThreadAttr_t BlinkLedGreen_attributes = {
  .name = "BlinkLedGreen",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for BlinkLedRed */
osThreadId_t BlinkLedRedHandle;
const osThreadAttr_t BlinkLedRed_attributes = {
  .name = "BlinkLedRed",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for semTurnsRedLed */
osSemaphoreId_t semTurnsRedLedHandle;
const osSemaphoreAttr_t semTurnsRedLed_attributes = {
  .name = "semTurnsRedLed"
};
/* Definitions for semTurnsGreenLed */
osSemaphoreId_t semTurnsGreenLedHandle;
const osSemaphoreAttr_t semTurnsGreenLed_attributes = {
  .name = "semTurnsGreenLed"
};
/* Definitions for semTurnsYellowLed */
osSemaphoreId_t semTurnsYellowLedHandle;
const osSemaphoreAttr_t semTurnsYellowLed_attributes = {
  .name = "semTurnsYellowLed"
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartBlinkLedYellow(void *argument);
void StartBlinkLedGreen(void *argument);
void StartBlinkLedRed(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of semTurnsRedLed */
  semTurnsRedLedHandle = osSemaphoreNew(1, 0, &semTurnsRedLed_attributes);

  /* creation of semTurnsGreenLed */
  semTurnsGreenLedHandle = osSemaphoreNew(1, 1, &semTurnsGreenLed_attributes);

  /* creation of semTurnsYellowLed */
  semTurnsYellowLedHandle = osSemaphoreNew(1, 0, &semTurnsYellowLed_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of BlinkLedYellow */
  BlinkLedYellowHandle = osThreadNew(StartBlinkLedYellow, NULL, &BlinkLedYellow_attributes);

  /* creation of BlinkLedGreen */
  BlinkLedGreenHandle = osThreadNew(StartBlinkLedGreen, NULL, &BlinkLedGreen_attributes);

  /* creation of BlinkLedRed */
  BlinkLedRedHandle = osThreadNew(StartBlinkLedRed, NULL, &BlinkLedRed_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED_LED_Pin YELLOW_LED_Pin GREEN_LED_Pin */
  GPIO_InitStruct.Pin = RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartBlinkLedYellow */
/**
  * @brief  Function implementing the BlinkLedYellow thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartBlinkLedYellow */
void StartBlinkLedYellow(void *argument)
{
  /* USER CODE BEGIN 5 */

  /* Infinite loop */
  for(;;)
  {
	      osSemaphoreAcquire(semTurnsYellowLedHandle, osWaitForever);
	 	  HAL_GPIO_TogglePin(GPIOB, YELLOW_LED_Pin);
	       osDelay(1500);
	       HAL_GPIO_TogglePin(GPIOB, YELLOW_LED_Pin);
	       osSemaphoreRelease(semTurnsRedLedHandle);
  }

  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartBlinkLedGreen */
/**
* @brief Function implementing the BlinkLedGreen thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBlinkLedGreen */
void StartBlinkLedGreen(void *argument)
{
  /* USER CODE BEGIN StartBlinkLedGreen */
  /* Infinite loop */
  for(;;)
  {
	  osSemaphoreAcquire(semTurnsGreenLedHandle,osWaitForever);
	  HAL_GPIO_TogglePin(GPIOB, GREEN_LED_Pin);
      osDelay(2500);
      HAL_GPIO_TogglePin(GPIOB, GREEN_LED_Pin);
      osSemaphoreRelease(semTurnsYellowLedHandle);

  }
  /* USER CODE END StartBlinkLedGreen */
}

/* USER CODE BEGIN Header_StartBlinkLedRed */
/**
* @brief Function implementing the BlinkLedRed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBlinkLedRed */
void StartBlinkLedRed(void *argument)
{
  /* USER CODE BEGIN StartBlinkLedRed */
  /* Infinite loop */
  for(;;)
  {
	  osSemaphoreAcquire(semTurnsRedLedHandle, osWaitForever);
	  HAL_GPIO_TogglePin(GPIOB, RED_LED_Pin);
	  osDelay(2000);
	  HAL_GPIO_TogglePin(GPIOB, RED_LED_Pin);
	  osSemaphoreRelease(semTurnsGreenLedHandle);

  }
  /* USER CODE END StartBlinkLedRed */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
