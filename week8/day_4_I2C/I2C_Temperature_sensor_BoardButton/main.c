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

I2C_HandleTypeDef I2C_handle;            // defining the I2C configuration structure
GPIO_InitTypeDef SCL_SDA_config;           // configure GPIOs for I2C data and clock lines
UART_HandleTypeDef Uart_handle;
GPIO_InitTypeDef board_button;

uint8_t read_temp_reg = 0;
uint8_t read_temp_val;

#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define UART_PUTCHAR int __io_putchar(int ch)

/* 7 bit address of an I2C sensor shifted to left 1 bit, leaving place for W/R bit,
 * which is inserted by the HAL_I2C_Master_Transmit and HAL_I2C_Master_Receive */

void init_board_button(void)
{
		__HAL_RCC_GPIOI_CLK_ENABLE();

		board_button.Pin = GPIO_PIN_11; //board button
		board_button.Pull = GPIO_NOPULL;
		board_button.Speed = GPIO_SPEED_FAST;
		board_button.Mode = GPIO_MODE_IT_RISING;

		HAL_GPIO_Init(GPIOI, &board_button);

		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
void init_SCL_SDA(void)
{
		__HAL_RCC_GPIOB_CLK_ENABLE();       /* enable GPIO clock */

	    SCL_SDA_config.Pin         = GPIO_PIN_8 | GPIO_PIN_9;  /* PB8: SCL, PB9: SDA */
	    SCL_SDA_config.Pull        = GPIO_PULLUP;
	    SCL_SDA_config.Mode        = GPIO_MODE_AF_OD;          /* configure in pen drain mode */
	    SCL_SDA_config.Alternate   = GPIO_AF4_I2C1;

	    HAL_GPIO_Init(GPIOB, &SCL_SDA_config);
}

void init_I2C(void)
{
		__HAL_RCC_I2C1_CLK_ENABLE();        /* enable the clock of the used peripheral */

	    I2C_handle.Instance             = I2C1;
	    I2C_handle.Init.Timing          = 0x40912732;
	    I2C_handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;

	    HAL_I2C_Init(&I2C_handle);
}

void init_UART(void)
{
		__HAL_RCC_USART1_CLK_ENABLE();

		Uart_handle.Instance = USART1;
		Uart_handle.Init.BaudRate = 115200;
		Uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
		Uart_handle.Init.StopBits = UART_STOPBITS_1;
		Uart_handle.Init.Parity = UART_PARITY_NONE;
		Uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		Uart_handle.Init.Mode = UART_MODE_TX_RX;

		BSP_COM_Init(COM1, &Uart_handle);
}

int main(void)
{
    HAL_Init();

    init_SCL_SDA();
    init_I2C();
    init_UART();
    init_board_button();
    BSP_LED_Init(LED_GREEN);
    while (1){
    }
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==board_button.Pin){
		BSP_LED_Toggle(LED_GREEN);
		        HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_reg, sizeof(read_temp_reg), 100);
		        HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_val, sizeof(read_temp_val), 100);

		        printf("Temperature: %d\r\n", read_temp_val);
	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&Uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
