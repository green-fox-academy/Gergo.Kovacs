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
			
GPIO_InitTypeDef led;
GPIO_InitTypeDef board_button_handle;
TIM_HandleTypeDef pwm;
TIM_OC_InitTypeDef s_config;

volatile uint32_t button_speed=0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_board_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	board_button_handle.Pin = GPIO_PIN_11; //board button
	board_button_handle.Pull = GPIO_NOPULL;
	board_button_handle.Speed = GPIO_SPEED_FAST;
	board_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &board_button_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
void init_led(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	led.Pin = GPIO_PIN_4;
	led.Pull = GPIO_NOPULL;
	led.Mode = GPIO_MODE_AF_PP;
	led.Speed = GPIO_SPEED_FAST;
	led.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &led);
}

void init_pwm(void)
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	pwm.Instance = TIM3;
	pwm.Init.Prescaler = 108-1;
	pwm.Init.Period = 100-1;
	pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&pwm);

	s_config.Pulse = 0;
	s_config.OCMode = TIM_OCMODE_PWM1;
	s_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	s_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&pwm, &s_config, TIM_CHANNEL_1);

	HAL_TIM_PWM_Start(&pwm,TIM_CHANNEL_1);

}

int main(void)
{
	HAL_Init();

	SystemClock_Config();
	init_led();
	init_board_button();
	init_pwm();

	HAL_TIM_PWM_Start_IT(&pwm, TIM_CHANNEL_1);

	while (1) {
			__HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, button_speed);
		//	if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11) == GPIO_PIN_RESET) {
				if (button_speed >= 3) {
					button_speed -= 3;
				} else {
					button_speed = 0;
				}
				HAL_Delay(500);
			}

}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==board_button_handle.Pin){

		if(button_speed<=50){
			if(button_speed+5<=50){
				button_speed+=5;
			}else{
				button_speed=50;
			}
		}
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
