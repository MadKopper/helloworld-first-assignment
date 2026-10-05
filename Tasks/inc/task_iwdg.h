#ifndef __TASK_IWDG_H
#define __TASK_IWDG_H

#include "stm32f1xx_hal.h"

/**
 * @brief IWDG 已由 CubeMX 初始化，此函数用于额外的看门狗相关操作
 */
void Task_IWDG_Init(void);

#endif /* __TASK_IWDG_H */
