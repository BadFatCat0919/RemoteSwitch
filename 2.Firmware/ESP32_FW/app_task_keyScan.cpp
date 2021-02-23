/**
 * @file app_task_key_scan.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层按键扫描任务的实现
 * @date 2021-02-23
 */

#include "base.h"
#include "app_task.h"
#include "hardware.h"
#include "firmware.h"

static void keyScan(void);

/**
 * @brief 按键扫描任务
 * @param pvParameters 
 */
void task_key_scan(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        keyScan();
        vTaskDelay(50);
    }
}

/**
 * @brief 按键扫描任务，按下按键后重启并进入OTA升级模式
 */
static void keyScan(void)
{
    if(Key_Board.scan())
    {
        LOG_D("Key_Board is pressed.\r\n");
        LED_Board.on();
        while(Key_Board.scan())
        {
            vTaskDelay(50);
        }
        OTA_enter_update_status();
    }
}
