/**
 * @file firmware.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层的API实现
 * @date 2021-02-03
 */

#include "base.h"
#include "firmware.h"

/**
 * @brief 固件层初始化
 * @return 成功为0, 否则为错误码
 */
int firmware_init(void)
{
    int ret = ERROR_NONE;

    do{
        if(ret = data_init())
        {
            LOG_E(ret, "data init failed!\r\n");
            break;
        }

        if(data_getUpdateFlag())
        {
            LOG_D("init OTA update...\r\n");
            if(ret = OTA_update_init())
            {
                LOG_E(ret, "OTA update init failed!\r\n");
                break;
            }
            OTA_update(); // 函数中含有while(true)
        }
    }while(false);

    return ret;
}
