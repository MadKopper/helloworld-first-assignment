#ifndef __TASK_GPIO_H
#define __TASK_GPIO_H

#include "stm32f1xx_hal.h"

/**
 * @brief 初始化 GPIO（PC13 推挽输出，低电平点亮 LED）
 */
void Task_GPIO_Init(void);

#endif /* __TASK_GPIO_H */
