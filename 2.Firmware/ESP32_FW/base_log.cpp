/**
 * @file base_log.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief log相关接口实现
 * @date 2021-02-13
 */

#include "base.h"
#include "base_log.h"
#include <HardwareSerial.h>

static int log_level = LOG_LEVEL_NONE;

/**
 * @brief log初始化
 * @return 成功为0，否则为错误码
 */
int log_init(void)
{
    int ret = ERROR_NONE;

    Serial.begin(115200);

    return ret;
}

/**
 * @brief 设置log等级
 * @param level 需要设置的等级
 */
void _log_set_level(int level)
{
    log_level = level;
}

/**
 * @brief 判断在当前设定log等级下，对应log是否应当打印
 * @param level 等待打印的log的等级
 * @return true 设定的log等级不小于等待打印的log的等级
 * @return false 设定的log等级小于等待打印的log的等级
 */
bool _log_compare_level(int level)
{
    return log_level >= level;
}

/**
 * @brief 将log等级转换为字符标签
 * @param level 需要设置的等级
 * @return log等级对应的字符标签
 */
char _log_get_level_label(int level)
{
    switch(level)
    {
        case LOG_LEVEL_DEBUG:
            return 'D';
        case LOG_LEVEL_INFORM:
            return 'I';
        case LOG_LEVEL_WARN:
            return 'W';
        case LOG_LEVEL_ERROR:
            return 'E';
        default:
            return '?';
    }
}
