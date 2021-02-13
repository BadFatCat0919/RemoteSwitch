/**
 * @file hw_touch.hpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层HW_Touch类
 * @date 2021-01-24
 */

#ifndef __HW_TOUCH_HPP__
#define __HW_TOUCH_HPP__

#include <stdint.h>
#include "hw_gpio.hpp"

/**
 * @brief 硬件层的HW_Touch类
 */
class HW_Touch
{
public:
    /**
     * @brief 创建一个新的HW_Touch对象
     * @param pin 使用的gpio引脚
     */
    HW_Touch(uint8_t pin):
        _gpio(pin, INPUT){}

    /**
     * @brief 销毁一个已创建的HW_Touch对象
     */
    ~HW_Touch() = default;

    /**
     * @brief 初始化
     * @return 成功为0, 否则为错误码
     */
    int init()
    {
        return _gpio.init();
    }

    /**
     * @brief 检测按键是否被按下
     * @return true 被按下
     * @return false 没被按下
     */
    bool scan()
    {
        return _gpio.status() == true;
    }

protected:
    HW_GPIO _gpio;
};

#endif // __HW_TOUCH_HPP__
