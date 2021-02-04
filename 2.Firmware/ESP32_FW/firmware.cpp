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
 * @return 成功为0，否则为错误码
 */
int firmware_init(void)
{
    int ret = ERROR_NONE;

    do{
        if(ret = data_init())
        {
            break;
        }

        if(data_getUpdateFlag())
        {
            if(ret = OTA_update_init())
            {
                break;
            }
            OTA_update(); // 函数中含有while(true)
        }
    }while(false);

    return ret;
}