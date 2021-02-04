/**
 * @file bs_log.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief log相关函数实现
 * @date 2021-02-04
 */

#include "base.h"
#include "bs_log.h"
#include <HardwareSerial.h>

/**
 * @brief 
 * @return 成功为0，否则为错误码
 */
int log_init(void)
{
    int ret = ERROR_NONE;

    Serial.begin(115200);

    return ret;
}
