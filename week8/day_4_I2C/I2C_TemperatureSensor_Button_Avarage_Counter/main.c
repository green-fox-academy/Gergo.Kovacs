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
TIM_HandleTypeDef timer_handle;

volatile uint8_t read_temp_reg = 0;
volatile uint8_t read_temp_val;
volatile uint16_t number_of_temperature=0;
volatile float sum=0;

static void Error_Handler(void);
static void SystemClock_Config(void);

#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define UART_PUTCHAR int __io_putchar(int ch)


void init_board_button(void)
{
		__HAL_RCC_GPIOI_CLK_ENABLE();

		board_button.Pin = GPIO_PIN_11; //board button
		board_button.Pull = GPIO_NOPULL;
		board_button.Speed = GPIO_SPEED_FAST;
		board_button.Mode = GPIO_MODE_IT_RISING;

		HAL_GPIO_Init(GPIOI, &board_button);

		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
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

void init_timer(void)
{

	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&timer_handle);

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1;
	timer_handle.Init.Period = 5000 - 1;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	init_UART();

	init_timer();

	printf("Start\r\n");

	HAL_TIM_Base_Start_IT(&timer_handle);

	init_SCL_SDA();

	init_I2C();

	init_board_button();

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

		printf("Average Temperature: %.2f\r\n", (sum/number_of_temperature));
		sum=0;
		number_of_temperature=0;
	}
}
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim->Instance == timer_handle.Instance) {
		HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS,&read_temp_reg, sizeof(read_temp_reg), 100);
		HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_val,sizeof(read_temp_val), 100);
		number_of_temperature++;
		sum+=read_temp_val;
		printf("Temperature: %d\r\n", read_temp_val);
	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&Uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

static void Error_Handler(void)
{

}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}
