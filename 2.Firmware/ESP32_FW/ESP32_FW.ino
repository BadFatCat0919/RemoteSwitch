/**
 * @file ESP32_FW.ino
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 用户代码与Arduino固件的接口
 * @date 2021-01-23
 */

#include "base.h"
#include "hardware.h"
#include "firmware.h"
#include "app.h"

/**
 * @brief 主循环开始执行前仅被调用一次的代码，这里用于初始化
 */
void setup()
{
    LOG_SET_LEVEL(LOG_LEVEL_DEBUG);

    int ret = ERROR_NONE;

    if(ret = base_init())
    {

    }
    if(ret = hardware_init())
    {

    }
    if(ret = firmware_init())
    {

    }
    if(ret = app_init())
    {

    }
}

/**
 * @brief 程序都在Task中执行，主循环置空
 */
void loop()
{
    if(Key_Board.scan())
    { 
        OTA_enter_update_status();
    }
    // LOG_DEBUG("test log debug!\n");
}
