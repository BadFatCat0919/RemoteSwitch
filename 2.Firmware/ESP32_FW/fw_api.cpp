/**
 * @file fw_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层的API实现
 * @date 2021-02-03
 */

#include "fw_api.h"

/**
 * @brief 固件层初始化
 * @return 成功为0，否则为错误码
 */
int fw_init(void)
{
    int ret = 0;

    do{
        if(data_init())
        {
            ret = -1;
            break;
        }

        if(data_getUpdateFlag())
        {
            data_setUpdateFlag(false);
            data_save();
            if(OTA_update_init())
            {
                ret = -1;
                break;
            }
            OTA_update(); // 函数中含有while(true)
        }
    }while(false);

    return ret;
}
