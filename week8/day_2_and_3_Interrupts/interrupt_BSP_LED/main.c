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
			
GPIO_InitTypeDef user_button;

void init_user_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button.Pin = GPIO_PIN_11;
	user_button.Pull = GPIO_NOPULL;
	user_button.Speed = GPIO_SPEED_FAST;
	user_button.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &user_button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while(1){
	}

	return 0;
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button.Pin);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == user_button.Pin) {
		BSP_LED_Toggle(LED_GREEN);
	}
}

