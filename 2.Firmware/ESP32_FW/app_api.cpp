/**
 * @file app_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 用户层的API实现
 * @date 2021-02-03
 */

#include "app_api.h"
#include "app_data.h"
#include "hw_api.h"

/**
 * @brief 用户层程序初始化
 * @return 成功为0，否则为错误码
 */
int app_init(void)
{
    int ret = 0;

    do{
        if(data_init())
        {
            ret = -1;
            break;
        }
        data_load();
        if(data_getUpdateFlag())
        {
            LED_Board.on();
            Serial.printf("update...");
            data_setUpdateFlag(false);
            data_save();
        }
    }while(false);

    return ret;
}
