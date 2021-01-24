/**
 * @file hw_led.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层HW_LED类的声明
 * @date 2021-01-23
 * 
 * Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 */

#ifndef __HW_LED_H__
#define __HW_LED_H__

#include <stdint.h>
#include "hw_gpio.h"

/**
 * @brief 硬件层的 HW_LED 类
 * 
 */
class HW_LED
{
public:
    /**
     * @brief 创建一个新的 HW_LED 对象
     * 
     * @param pin 使用的gpio引脚，缺省为板载的LED
     * @param onLevel LED点亮时的电平
     * @param defaultStatus LED初始化后的默认状态
     */
    HW_LED(uint8_t pin = 2, bool onLevel = true, bool defaultStatus = false):
        _gpio(pin, OUTPUT, defaultStatus ? onLevel : !onLevel), _onLevel(onLevel){}

    /**
     * @brief 销毁一个已创建的 HW_LED 对象
     * 
     */
    ~HW_LED() = default;

    /**
     * @brief 初始化
     * 
     * @return HW_LED& 
     */
    HW_LED& init()
    {
        _gpio.init();
        return *this;
    }

    /**
     * @brief 打开LED
     * 
     * @return hw_led& 
     */
    HW_LED& on()
    {
        _gpio.status(_onLevel);
        return *this;
    }

    /**
     * @brief 关闭LED
     * 
     * @return HW_LED& 
     */
    HW_LED& off()
    {
        _gpio.status(!_onLevel);
        return *this;
    }

    /**
     * @brief 翻转LED状态
     * 
     * @return HW_LED& 
     */
    HW_LED& reverse()
    {
        _gpio.reverse();
        return *this;
    }
    
protected:
    HW_GPIO _gpio;
    bool _onLevel;
};


#endif // __HW_LED_H__
