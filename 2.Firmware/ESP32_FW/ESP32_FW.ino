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
        LOG_E(ret, "base init failed!\r\n");
    }
    if(ret = hardware_init())
    {
        LOG_E(ret, "hardware init failed!\r\n");
    }
    if(ret = firmware_init())
    {
        LOG_E(ret, "firmware init failed!\r\n");
    }
    if(ret = app_init())
    {
        LOG_E(ret, "app init failed!\r\n");
    }
}

/**
 * @brief 程序都在Task中执行，主循环置空
 */
void loop()
{
//                      _ooOoo_	
//                     o8888888o
//                     88" . "88
//                     (| -_- |)
//                     O\  =  /O
//                  ____/`---'\____
//                .'  \\|     |//  `.
//               /  \\|||  :  |||//  \
//              /  _||||| -:- |||||_  \
//              |   | \\\  -  /// |   |
//              | \_|  ''\---/''  |_/ |
//              \  .-\__  `-`  ___/-. /
//        =======|. .'  /--.--\  '. .|=======
//       ===.""'<  '.___\_<|>_/___.'  >'"".===
//      ==| | :  ` - `.;`\ _ /`;.`/ - ` : | |==
//     ===\  \ `-.   \_ __\ /__ _/   .-` /  /===
//    =====`-.____`-.___\_____/___.-`____.-'=====
//   ===================`=---='===================
//  ===============================================
// ================ 佛祖保佑代码无bug ===============
}
