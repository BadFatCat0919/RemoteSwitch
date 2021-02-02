/**
 * @file hw_gpio.hpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层 HW_GPIO 类
 * @date 2021-01-24
 */

#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__

#include <stdint.h>
#include "esp32-hal-gpio.h"

/**
 * @brief 硬件层的 HW_GPIO 类
 */
class HW_GPIO
{
public:
    /**
     * @brief 创建一个新的 HW_GPIO 对象
     * @param pin 使用的引脚
     * @param mode 引脚模式
     * @param status 默认电平状态
     */
    HW_GPIO(uint8_t pin, uint8_t mode, bool status = false):
    _pin(pin), _mode(mode), _status(status){}
    
    /**
     * @brief 销毁一个已创建的 HW_GPIO 对象
     */
    ~HW_GPIO() = default;

    /**
     * @brief 初始化
     * @return HW_GPIO& 
     */
    HW_GPIO& init()
    {
        pinMode(_pin, _mode);
        if(_mode == OUTPUT)
        {
            digitalWrite(_pin, _status);
        }
        return *this;
    }
    
    /**
     * @brief 读取当前电平状态
     * @return true 当前电平为高电平
     * @return false 当前电平为低电平
     */
    bool status()
    {
        if(_mode == OUTPUT)
        {
            return _status;
        }
        return digitalRead(_pin);
    }

    /**
     * @brief 设置新电平
     * @param newStatus 
     * @return HW_GPIO& 
     */
    HW_GPIO& status(bool newStatus)
    {
        if(_mode == OUTPUT)
        {
            digitalWrite(_pin, newStatus);
            _status = newStatus;
        }
        return *this;
    }

    /**
     * @brief 翻转电平
     */
    void reverse()
    {
        if(_mode == OUTPUT)
        {
            digitalWrite(_pin, !_status);
            _status = !_status;
        }
    }

protected:
    uint8_t _pin, _mode, _status;
};

#endif // __HW_GPIO_H__
