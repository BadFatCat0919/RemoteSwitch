/**
 * @file ESP32_FW.ino
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 用户代码与Arduino的接口
 * @date 2021-01-23
 */

#include "hw_api.h"
#include "os_api.h"
#include "app_api.h"

/**
 * @brief 主循环开始执行前仅被调用一次的代码。这里用于软硬件初始化
 */
void setup()
{
    hw_init();
    app_init();
    os_init();
}

/**
 * @brief 主循环。程序都在Task中执行，这里置空
 */
void loop()
{
  // empty
}
