/**
 * @file hw_api.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API声明
 * @date 2021-01-24
 * 
 * Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 */

#ifndef __HW_API_H__
#define __HW_API_H__

#include "hw_gpio.hpp"
#include "hw_led.hpp"
#include "hw_key.hpp"

extern HW_LED LED_Board;
extern HW_KEY KEY_Board;

/**
 * @brief 硬件层初始化
 * 
 */
void HW_Init(void);

#endif // __HW_API_H__
