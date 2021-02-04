/**
 * @file app_task.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层的各个Task的实现
 * @date 2021-01-23
 */

#include "base.h"
#include "app_task.h"
#include "hardware.h"

/**
 * @brief 任务
 * @param pvParameters 
 */
void task_test1(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        // LOG_INFORM("enter task_test1!\n");
        Serial.printf("test here!\n");
        vTaskDelay(200);
    }
}
