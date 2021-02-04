/**
 * @file base_log.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief log相关接口实现
 * @date 2021-02-04
 */

#include "base.h"
#include "base_log.h"
#include <HardwareSerial.h>
#include <stdio.h>
#include <stdarg.h>

static int log_level = LOG_LEVEL_NONE;

/**
 * @brief 将标准输出重定向到串口
 * @param c 需要输出的字符
 * @param fp 需要输出到的文件
 * @return 输出的字符
 */
int fputc(int c, FILE *fp)
{
    Serial.write(c);
    return c;
}

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
 * @brief 格式化输出log
 * @param level log等级
 * @param file log所在文件
 * @param function log所在函数
 * @param line log所在行数
 * @param format 格式化字符串
 * @param ... 参数列表
 */
void _log_printf(int level, const char *file, int line, const char *function, const char *format, ...)
{
    if(log_level < level) // 只有在系统设置的log等级不小于该条log等级时打印
    {
        return;
    }

    char levelLabel = '\0';
    switch(level)
    {
        case LOG_LEVEL_DEBUG:
            levelLabel = 'D';
            break;
        case LOG_LEVEL_INFORM:
            levelLabel = 'I';
            break;
        case LOG_LEVEL_WARN:
            levelLabel = 'W';
            break;
        case LOG_LEVEL_ERROR:
            levelLabel = 'E';
            break;
        default:
            break;
    }
    printf("[%c][%s:%03d][%s]>> ", levelLabel, file, line, function);

    va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
}
