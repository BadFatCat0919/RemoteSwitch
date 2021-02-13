/**
 * @file hardware.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API声明
 * @date 2021-01-24
 */

#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include "hw_led.hpp"
#include "hw_key.hpp"
#include "hw_touch.hpp"
#include "hw_servo.hpp"

extern HW_LED LED_Board;
extern HW_Key Key_Board;
extern HW_Touch Touch_P27, Touch_P04;
extern HW_Servo Servo_Left, Servo_Right;

int hardware_init(void);

#endif // __HARDWARE_H__
