/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"


GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef pwm;

TIM_OC_InitTypeDef s_config; //PWM channel

static void Error_Handler(void);
static void SystemClock_Config(void);


void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button_handle.Pin = GPIO_PIN_11; //board button
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode =GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &user_button_handle);
}

void init_timer_pwm(void)
{
	__HAL_RCC_TIM1_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&pwm);
	__HAL_TIM_SET_COUNTER(&pwm, 0);

	pwm.Instance = TIM2;
	pwm.Init.Prescaler = 10800 - 1; //0,1 ms
	pwm.Init.Period = 5000 - 1; //0.5 s period
	pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAl_TIM_PWM_Init(&pwm);

	s_config.Pulse = 50;
	s_config.OCMode = TIM_OCMODE_PWM1;
	s_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	s_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&pwm, &s_config, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_uart();

	init_timer_pwm();

	HAL_TIM_PWM_Start_IT(&pwm,TIM_CHANNEL_1);

	while (1) {
	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&pwm);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {


	}
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
