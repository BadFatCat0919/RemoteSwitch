/**
 * @file app_task_servo_control.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 应用程序层舵机控制任务的实现
 * @date 2021-02-23
 */

#include "base.h"
#include "app_task.h"
#include "hardware.h"
#include "firmware.h"

typedef enum{
    INIT    = 0,
    ATTACH  = 1,
    RELEASE = 2,
    ON      = 3,
    MID     = 4,
    OFF     = 5,
    TEST    = 6,
}ServoState;

static void servo_control_statemachine(ServoState &state, HW_Servo &servo);

/**
 * @brief 舵机控制任务
 * @param pvParameters 
 */
void task_servo_control(void *pvParameters)
{
    (void) pvParameters;

    for (;;)
    {
        // static ServoState leftServoState, rightServoState;
        // servo_control_statemachine(leftServoState, Servo_Left);
        // servo_control_statemachine(rightServoState, Servo_Right);
        vTaskDelay(50);
    }
}

/**
 * @brief 舵机控制状态机
 * @param state 舵机状态变量
 * @param servo 状态机控制的舵机
 */
static void servo_control_statemachine(ServoState &state, HW_Servo &servo)
{
    switch(state)
    {
        case INIT:
            state = MID;
            break;

        case ATTACH:
            servo.on();
            break;

        case RELEASE:
            servo.off();
            break;

        case ON:
            break;

        case MID:
            break;

        case OFF:
            break;

        case TEST:
            break;

        default:
            LOG_E(ERROR_INVAL, "invalid servo state!\r\n");
            state = INIT;
            break;
    }
}
