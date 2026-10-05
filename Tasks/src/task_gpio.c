#include "task_gpio.h"

/**
 * @brief 初始化 GPIO（PC13 推挽输出，低电平点亮 LED）
 *
 * 对于 STM32F103 最小系统板，PC13 连接板载 LED，低电平点亮
 */
void Task_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* 使能 GPIOC 时钟 */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* 配置 PC13 为推挽输出 */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* 设置 PC13 为低电平，点亮 LED */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}
