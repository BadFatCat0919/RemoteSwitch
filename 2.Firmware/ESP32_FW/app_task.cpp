/**
 * @file app_task.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层的各个Task的实现
 * @date 2021-01-23
 */

#include "base.h"
#include "app_task.h"
#include "hardware.h"
#include "firmware.h"

/**
 * @brief 按键扫描任务
 * @param pvParameters 
 */
void task_keyScan(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
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

        vTaskDelay(50);
    }
}
