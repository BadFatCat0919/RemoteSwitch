/**
 * @file hw_key.hpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层HW_Key类
 * @date 2021-01-24
 */

#ifndef __HW_KEY_HPP__
#define __HW_KEY_HPP__

#include <stdint.h>
#include "hw_gpio.hpp"

/**
 * @brief 硬件层的HW_Key类
 */
class HW_Key
{
public:
    /**
     * @brief 创建一个新的HW_Key对象
     * @param pin 使用的gpio引脚, 缺省为板载的按键
     * @param pressLevel 按键按下时的电平
     */
    HW_Key(uint8_t pin = 0, bool pressLevel = false):
        _gpio(pin, pressLevel ? INPUT_PULLDOWN : INPUT_PULLUP), _pressLevel(pressLevel){}

    /**
     * @brief 销毁一个已创建的HW_Key对象
     */
    ~HW_Key() = default;

    /**
     * @brief 初始化
     */
    void init()
    {
        _gpio.init();
    }

    /**
     * @brief 检测按键是否被按下
     * @return true 被按下
     * @return false 没被按下
     */
    bool scan()
    {
        return _gpio.status() == _pressLevel;
    }

protected:
    HW_GPIO _gpio;
    bool _pressLevel;
};

#endif // __HW_KEY_HPP__
