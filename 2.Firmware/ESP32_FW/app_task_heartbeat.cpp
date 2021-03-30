/**
 * @file app_task_heartbeat.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 系统心跳任务的实现
 * @date 2021-03-22
 */

#include "base.h"
#include "app_task.h"
#include "hardware.h"
#include "firmware.h"

static void heartbeat(void);

/**
 * @brief 按键扫描任务
 * @param pvParameters 
 */
void task_heartbeat(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        heartbeat();
        vTaskDelay(5000);
    }
}

/**
 * @brief 心跳任务，隔一段时间发一个log
 */
static void heartbeat(void)
{
    LOG_D("system running...\r\n");
}
