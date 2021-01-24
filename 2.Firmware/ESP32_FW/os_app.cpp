/**
 * @file os_app.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 操作系统层的各个Task的实现
 * @date 2021-01-23
 * 
 * Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 */

#include "hw_api.h"

/**
 * @brief 点灯测试任务
 * 
 * @param pvParameters 
 */
void TaskBlink(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        LED_Board.reverse();
        vTaskDelay(500);
    }
}
