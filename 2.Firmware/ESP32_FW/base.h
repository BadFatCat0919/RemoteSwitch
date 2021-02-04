/**
 * @file base.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 基础层API声明
 * @date 2021-02-04
 */

#ifndef __BASE_H__
#define __BASE_H__

/* 通用头文件 */
#include <stddef.h>
#include <stdint.h>
#include <Arduino.h>
#include <Esp.h>
#include "base_log.h"

/* 通用错误码 */
#define ERROR_NONE           0   // 没有错误
#define ERROR               -1   // 普通错误
#define ERROR_TIMEOUT       -2   // 超时
#define ERROR_FULL          -3   // 溢出
#define ERROR_EMPTY         -4   // 空
#define ERROR_NOMEM         -5   // 内存不足
#define ERROR_BUSY          -6   // 被占用
#define ERROR_INVAL         -7   // 参数无效
#define ERROR_HARDWARE      -8   // 硬件错误

/* 通用接口函数 */
int base_init(void);

#endif // __BASE_H__
