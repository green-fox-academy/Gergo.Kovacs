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

GPIO_InitTypeDef rgb_led_red;
GPIO_InitTypeDef rgb_led_green;
GPIO_InitTypeDef rgb_led_blue;
GPIO_InitTypeDef board_button;
TIM_HandleTypeDef pwm_red;
TIM_HandleTypeDef pwm_green;
TIM_HandleTypeDef pwm_blue;
TIM_OC_InitTypeDef s_config;

volatile int counter_of_button_pushing=0;
volatile int pushing_button = 0;

const uint32_t debounce_delay=0;
uint32_t debounce_time=50; //pergés mentesítés

volatile uint32_t pushing;
volatile uint32_t releasing;

volatile uint32_t pulse_changer_red=100;
volatile uint32_t pulse_changer_green=100;
volatile uint32_t pulse_changer_blue=100;

typedef enum {
	RED, GREEN, BLUE
} rgb_color_t;

volatile rgb_color_t color;
volatile int flag=1;

static void Error_Handler(void);
static void SystemClock_Config(void);


void init_board_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	board_button.Pin = GPIO_PIN_11;
	board_button.Pull = GPIO_NOPULL;
	board_button.Speed = GPIO_SPEED_FAST;
	board_button.Mode = GPIO_MODE_IT_RISING_FALLING ;

	HAL_GPIO_Init(GPIOI, &board_button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_rgb_led_red()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	rgb_led_red.Pin = GPIO_PIN_15;
	rgb_led_red.Pull = GPIO_NOPULL;
	rgb_led_red.Speed = GPIO_SPEED_HIGH;
	rgb_led_red.Alternate = GPIO_AF1_TIM2;
	rgb_led_red.Mode = GPIO_MODE_AF_OD;				// OD invertelés
	HAL_GPIO_Init(GPIOA, &rgb_led_red);
}

void init_rgb_led_green()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	rgb_led_green.Pin = GPIO_PIN_4;
	rgb_led_green.Pull = GPIO_NOPULL;
	rgb_led_green.Speed = GPIO_SPEED_HIGH;
	rgb_led_green.Alternate = GPIO_AF2_TIM3;
	rgb_led_green.Mode = GPIO_MODE_AF_OD;
	HAL_GPIO_Init(GPIOB, &rgb_led_green);
}

void init_rgb_led_blue()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	rgb_led_blue.Pin = GPIO_PIN_0;
	rgb_led_blue.Pull = GPIO_NOPULL;
	rgb_led_blue.Speed = GPIO_SPEED_HIGH;
	rgb_led_blue.Alternate = GPIO_AF2_TIM5;
	rgb_led_blue.Mode = GPIO_MODE_AF_OD;
	HAL_GPIO_Init(GPIOI, &rgb_led_blue);

}

void init_pwm_rgb()
{
	__HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_TIM5_CLK_ENABLE();
	__HAL_RCC_TIM3_CLK_ENABLE();

	pwm_red.Instance = TIM2;
	pwm_red.Init.Prescaler = 108 - 1;
	pwm_red.Init.Period = 100 - 1;
	pwm_red.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm_red.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_red);

	pwm_blue.Instance = TIM5;
	pwm_blue.Init.Prescaler = 108 - 1;
	pwm_blue.Init.Period = 100 - 1;
	pwm_blue.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm_blue.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_blue);

	pwm_green.Instance = TIM3;
	pwm_green.Init.Prescaler = 108 - 1;
	pwm_green.Init.Period = 100 - 1;
	pwm_green.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm_green.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_green);

	s_config.Pulse = 50;
	s_config.OCMode = TIM_OCMODE_PWM1;
	s_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	s_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&pwm_red, &s_config, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&pwm_green, &s_config, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&pwm_blue, &s_config, TIM_CHANNEL_4);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_pwm_rgb();
	init_board_button();
	init_rgb_led_red();
	init_rgb_led_green();
	init_rgb_led_blue();


	HAL_TIM_PWM_Start(&pwm_green, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&pwm_blue, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&pwm_red, TIM_CHANNEL_1);

    while (1) {
        __HAL_TIM_SET_COMPARE(&pwm_red, TIM_CHANNEL_1, pulse_changer_red);
        __HAL_TIM_SET_COMPARE(&pwm_blue, TIM_CHANNEL_4, pulse_changer_blue);
        __HAL_TIM_SET_COMPARE(&pwm_green, TIM_CHANNEL_1, pulse_changer_green);
    }

}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
 {
	if (GPIO_Pin == board_button.Pin) {
		uint32_t current_time = HAL_GetTick();
		if (current_time < debounce_time + debounce_delay) {
			return;

		} else if (pushing_button == 0) { //változó értéke nulla és lenyomás fog következni
			pushing_button = 1;
			pushing = HAL_GetTick();
		} else if (pushing_button == 1) {
			pushing_button = 0;
			releasing = HAL_GetTick();
			uint32_t interrupt_time = releasing - pushing;

			if (interrupt_time <= 600) {
				if (counter_of_button_pushing == 0) {
					color = RED;
					counter_of_button_pushing++;
				} else if (counter_of_button_pushing == 1) {
					color = GREEN;
					counter_of_button_pushing++;
				} else if (counter_of_button_pushing == 2) {
					color = BLUE;
					counter_of_button_pushing = 0;
				}
			} else if (interrupt_time > 600) {
				if (color == RED) {
					if (flag) {
						if (pulse_changer_red + 10 < 100) {
							pulse_changer_red += 10;
						} else {
							pulse_changer_red = 100;
							flag = 0;
						}
					} else {
						if (pulse_changer_red - 10 > 0) {
							pulse_changer_red -= 10;
						} else {
							pulse_changer_red = 0;
							flag = 1;
						}
					}
				} else if (color == GREEN) {
					if (flag) {
						if (pulse_changer_green + 10 < 100) {
							pulse_changer_green += 10;
						} else {
							pulse_changer_green = 100;
							flag = 0;
						}
					} else {
						if (pulse_changer_green - 10 > 0) {
							pulse_changer_green -= 10;
						} else {
							pulse_changer_green = 0;
							flag = 1;
						}
					}
				} else if (color == BLUE) {
					if (flag) {
						if (pulse_changer_blue + 10 < 100) {
							pulse_changer_blue += 10;
						} else {
							pulse_changer_blue = 100;
							flag = 0;
						}
					} else {
						if (pulse_changer_blue - 10 > 0) {
							pulse_changer_blue -= 10;
						} else {
							pulse_changer_blue = 0;
							flag = 1;
						}
					}
				}
			}
		}
		debounce_time = current_time;
	}
}

static void Error_Handler(void)
{

}

static void SystemClock_Config(void)
 {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}

}
