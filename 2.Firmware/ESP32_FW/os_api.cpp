/**
 * @file os_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 操作系统层的API实现
 * @date 2021-01-24
 */

#include "hw_api.h"
#include "os_api.h"
#include "os_task.h"
#include "FreeRTOS.h"

/**
 * @brief 操作系统初始化。创建各个任务并启动调度器
 * @return 成功为0，否则为错误码
 */
int os_init(void)
{
	int ret = 0;

	xTaskCreatePinnedToCore(
	task_blink
		,  "TaskBlink"
		,  1024
		,  NULL
		,  1
		,  NULL 
		,  APP_CPU_NUM);

	return ret;
}
