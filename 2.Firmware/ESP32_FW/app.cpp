/**
 * @file app.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层的API实现
 * @date 2021-01-24
 */

#include "base.h"
#include "hardware.h"
#include "app.h"
#include "app_task.h"
#include <FreeRTOS.h>

/**
 * @brief 操作系统初始化。创建各个任务并启动调度器
 * @return 成功为0, 否则为错误码
 */
int app_init(void)
{
	int ret = ERROR_NONE;

	ret = xTaskCreatePinnedToCore(
		task_key_scan,
		"key scan",
		2048,
		NULL,
		configMAX_PRIORITIES - 1, // 优先级设为最大优先级，使按键扫描尽量不受其他任务影响
		NULL,
		APP_CPU_NUM
	);
	if(ret != ERROR_NONE)
	{
		LOG_E(ERROR, "task_key_scan creat fail! return value = %d!\r\n", ret);
	}

	xTaskCreatePinnedToCore(
		task_servo_control,
		"servo control",
		2048,
		NULL,
		1,
		NULL,
		APP_CPU_NUM
	);
	if(ret != ERROR_NONE)
	{
		LOG_E(ERROR, "task_servo_control creat fail! return value = %d!\r\n", ret);
	}

	return ret;
}
