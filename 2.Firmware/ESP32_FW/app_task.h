/**
 * @file app_task.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层的各个Task的声明
 * @date 2021-01-23
 */

#ifndef __APP_TASK_H__
#define __APP_TASK_H__

void task_key_scan(void *pvParameters);
void task_servo_control(void *pvParameters);

#endif // __APP_TASK_H__
