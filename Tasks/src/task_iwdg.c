#include "task_iwdg.h"

/**
 * @brief IWDG 已由 CubeMX 初始化，此函数留空
 *
 * 配置参数（F103，LSI ≈ 40kHz）：
 * - 分频系数 = 64
 * - 重装载值 = 1249（在 CubeMX 中配置）
 * - 超时时间 = (1249 + 1) × 64 / 40000 = 2 秒
 *
 * 注意：IWDG 一旦启用就不能关闭
 */
void Task_IWDG_Init(void)
{
    /* IWDG 已在 CubeMX 的 MX_IWDG_Init() 中初始化 */
    /* 这里不需要额外操作 */
}
