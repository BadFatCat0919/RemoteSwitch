/**
 * @file base_log.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief log相关接口声明
 * @date 2021-02-04
 */

#ifndef __BASE_LOG_H__
#define __BASE_LOG_H__

/* 需要的头文件 */
#include <string.h>

/* LOG等级定义 */
#define LOG_LEVEL_DEBUG     4
#define LOG_LEVEL_INFORM    3
#define LOG_LEVEL_WARN      2
#define LOG_LEVEL_ERROR     1
#define LOG_LEVEL_NONE      0

/* 中间层(禁止直接从外部调用！！！) */
#define _FILTER_FILE_NAME(x)    (strrchr((x),'\\')?strrchr((x),'\\')+1:(x))
void _log_printf(int level, const char *file, int line, const char *function, const char *format, ...);
void _log_set_level(int level);

/* LOG调用接口 */
int log_init(void);
#define LOG_SET_LEVEL(level)            _log_set_level(level)
#define LOG_PRINTF(level, format, ...)  _log_printf(level, _FILTER_FILE_NAME(__FILE__), __LINE__, __func__, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...)          LOG_PRINTF(LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)
#define LOG_INFORM(format, ...)         LOG_PRINTF(LOG_LEVEL_INFORM, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)           LOG_PRINTF(LOG_LEVEL_WARN, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)          LOG_PRINTF(LOG_LEVEL_ERROR, format, ##__VA_ARGS__)

#endif // __BASE_LOG_H__
