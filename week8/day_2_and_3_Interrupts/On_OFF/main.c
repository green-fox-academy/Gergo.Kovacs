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

GPIO_InitTypeDef button_handle;

uint32_t debounce_time=0;
const debounce_delay=150;
volatile int counter=0;

void init_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	button_handle.Pin = GPIO_PIN_4;
	button_handle.Pull = GPIO_NOPULL;
	button_handle.Speed = GPIO_SPEED_FAST;
	button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &button_handle);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED_GREEN);

	init_button();

	while (1) {
	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if(GPIO_Pin==button_handle.Pin){

		uint32_t current_time=HAL_GetTick();

		if(current_time<debounce_time+debounce_delay){
			return;
		}
		counter++;
		if ( counter%10==5){
			BSP_LED_Toggle(LED_GREEN);
		}
		if(counter%10==0){
			BSP_LED_Toggle(LED_GREEN);
		}
		debounce_time=current_time;
	}
}
