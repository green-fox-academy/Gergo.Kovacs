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
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			BSP_LED_On(LED1);
			HAL_Delay(500);
		}
		if (BSP_PB_GetState(BUTTON_KEY)) {
			BSP_LED_Off(LED1);
			HAL_Delay(500);
		}
	}

}
