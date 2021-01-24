/**
 * @file os_api.c
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 操作系统层的API实现
 * @date 2021-01-24
 * 
 * Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 */

#include "os_includes.h"
#include "hw_api.h"
#include "FreeRTOS.h"

/**
 * @brief 操作系统初始化。创建各个任务并启动调度器
 */
void OS_Init(void)
{
  xTaskCreatePinnedToCore(
    TaskBlink
    ,  "TaskBlink"
    ,  1024
    ,  NULL
    ,  1
    ,  NULL 
    ,  APP_CPU_NUM);
}
