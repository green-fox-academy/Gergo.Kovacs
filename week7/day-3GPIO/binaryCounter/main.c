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
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef led_init;
	led_init.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
	led_init.Mode = GPIO_MODE_OUTPUT_PP;
	led_init.Pull = GPIO_NOPULL;
	led_init.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led_init2;
	led_init2.Pin = GPIO_PIN_0;
	led_init2.Mode = GPIO_MODE_OUTPUT_PP;
	led_init2.Pull = GPIO_NOPULL;
	led_init2.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &led_init2);
	HAL_GPIO_Init(GPIOF, &led_init);

	int counter = 0;

	while (1) {
		if (counter % 2 > 0) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		}
		if (counter % 4 > 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		}
		if (counter % 8 > 3) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		}
		if (counter % 16 > 7) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
		}
		counter++;
	}

}
