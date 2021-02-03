/**
 * @file ESP32_FW.ino
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 用户代码与Arduino的接口
 * @date 2021-01-23
 */

#include "hw_api.h"
#include "fw_api.h"
#include "os_api.h"

/**
 * @brief 主循环开始执行前仅被调用一次的代码。这里用于软硬件初始化
 */
void setup()
{
    int ret = 0;
    if(ret = hw_init())
    {

    }
    if(ret = fw_init())
    {

    }
    if(ret = os_init())
    {

    }
}

/**
 * @brief 主循环。程序都在Task中执行，这里置空
 */
void loop()
{
    if(Key_Board.status())
    { 
        enter_OTA_status();
    }
}
