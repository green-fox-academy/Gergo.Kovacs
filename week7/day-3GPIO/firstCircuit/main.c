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



int main(void) {

	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef led_init;
	led_init.Pin = GPIO_PIN_0;
	led_init.Mode = GPIO_MODE_OUTPUT_PP;
	led_init.Pull = GPIO_NOPULL;
	led_init.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &led_init);

	while (1) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		HAL_Delay(500);
	}

}
