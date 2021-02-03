/**
 * @file os_task.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 操作系统层的各个Task的实现
 * @date 2021-01-23
 */

#include "hw_api.h"

/**
 * @brief 点灯测试任务
 * @param pvParameters 
 */
void TaskBlink(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        LED_Board = KEY_Board.status();
    }
}
