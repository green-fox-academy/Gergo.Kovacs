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
#include <string.h>
#define UART_PUTCHAR int __io_putchar(int ch)
UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef led_init;

int main(void) {

	HAL_Init();

	__HAL_RCC_GPIOF_CLK_ENABLE();

	led_init.Pin = GPIO_PIN_10 | GPIO_PIN_9;
	led_init.Mode = GPIO_MODE_OUTPUT_PP;
	led_init.Pull = GPIO_NOPULL;
	led_init.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led_init);

	__HAL_RCC_USART1_CLK_ENABLE();

	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);

	char buffer[10];

	printf("start\n");
	while (1) {

		while(HAL_UART_Receive(&UartHandle, (uint8_t*) buffer, 10, 1000)!=HAL_TIMEOUT);

		printf("received: '%s'\n", buffer);

		if (strcmp(buffer, "on\r\n") == 0) {
			memset(buffer, '\0', 10);
			printf("on\n");
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		} else if (strcmp(buffer, "off\r\n") == 0) {
			printf("off\r\n");
			memset(buffer, '\0', 10);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		} else if(strcmp(buffer," \r\n")==0){
			printf("error\n");
			memset(buffer, '\0', 10);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_Delay(500);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_Delay(500);
		}
	}
}
UART_PUTCHAR
{
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
