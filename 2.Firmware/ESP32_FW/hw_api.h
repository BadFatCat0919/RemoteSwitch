/**
 * @file hw_api.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API声明
 * @date 2021-01-24
 */

#ifndef __HW_API_H__
#define __HW_API_H__

#include "hw_gpio.hpp"
#include "hw_led.hpp"
#include "hw_key.hpp"

extern HW_LED LED_Board;
extern HW_Key Key_Board;

int hw_init(void);

#endif // __HW_API_H__
