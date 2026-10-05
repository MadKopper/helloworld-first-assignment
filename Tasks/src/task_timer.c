#include "task_timer.h"
#include "task_iwdg.h"
#include "tim.h"  /* CubeMX 生成的 TIM 头文件，包含 htim2 声明 */
#include "iwdg.h" /* CubeMX 生成的 IWDG 头文件，包含 hiwdg 声明 */

/* 全局 tick 变量，每 1ms 自增 1 */
volatile uint32_t tick = 0;

/**
 * @brief 启动定时器中断（TIM2 已由 CubeMX 初始化）
 *
 * 时钟计算：
 * - SYSCLK = 8MHz (HSI)
 * - AHB = 8MHz (分频系数 = 1)
 * - APB1 = 8MHz (分频系数 = 1)
 * - TIM2 挂在 APB1 上，APB1 分频为 1，所以定时器时钟 = APB1 = 8MHz
 *
 * 1ms 中断周期计算：
 * (PSC + 1) * (ARR + 1) / 定时器时钟 = 0.001s
 * (799 + 1) * (9 + 1) / 8000000 = 800 * 10 / 8000000 = 0.001s ✓
 *
 * 注意：需要在 CubeMX 中设置 TIM2 的 ARR = 9
 */
void Task_Timer_Init(void)
{
    /* 配置 NVIC，启用 TIM2 中断 */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    /* 启动定时器中断 */
    HAL_TIM_Base_Start_IT(&htim2);
}

/**
 * @brief 定时器更新中断回调函数
 * @param htim: 定时器句柄
 *
 * 每 1ms 触发一次，tick 自增 1，并喂狗
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick++;
        /*HAL_IWDG_Refresh(&hiwdg);*/  /* 喂狗 */
    }
}
