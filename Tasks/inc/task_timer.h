#ifndef __TASK_TIMER_H
#define __TASK_TIMER_H

#include "stm32f1xx_hal.h"

/**
 * @brief 初始化定时器（1ms 更新中断）
 */
void Task_Timer_Init(void);

/**
 * @brief 全局 tick 变量，每 1ms 自增 1
 */
extern volatile uint32_t tick;

#endif /* __TASK_TIMER_H */
