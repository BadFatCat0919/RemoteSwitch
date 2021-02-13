/**
 * @file hw_pwm.hpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层HW_PWM类
 * @date 2021-02-13
 */

#ifndef __HW_PWM_HPP__
#define __HW_PWM_HPP__

#include <stdint.h>
#include <esp32-hal-ledc.h>

/**
 * @brief 硬件层的HW_PWM类
 */
class HW_PWM
{
public:
    /**
     * @brief 
     * @param pin 使用的引脚编号
     * @param frequency 基础频率
     * @param countBits 计数位数
     */
    HW_PWM(uint8_t pin, uint8_t channel, double frequency, uint8_t countBits):
        _pin(pin), _frequency(frequency), _countBits(countBits), _channel(channel)
        {
            _min = 0;
            _max = 2 << countBits; 
        }

    /**
     * @brief 销毁一个已创建的HW_PWM对象
     */
    ~HW_PWM()
    {
        off();
    }

    /**
     * @brief 初始化
     * @return 成功为0, 否则为错误码
     */
    int init()
    {
        return !ledcSetup(_channel, _frequency, _countBits);
    }

    /**
     * @brief 打开pwm
     * @return HW_PWM&
     */
    HW_PWM& on()
    {
        ledcAttachPin(_pin, _channel);
        return *this;
    }

    /**
     * @brief 关闭pwm
     * @return HW_PWM&
     */
    HW_PWM& off()
    {
        ledcDetachPin(_pin);
        return *this;
    }

    /**
     * @brief 设置pwm值
     * @param pwmValue 目标pwm值
     * @return HW_PWM& 
     */
    HW_PWM& set(long pwmValue)
    {
        if(pwmValue > _max)
        {
            pwmValue = _max;
        }
        if(pwmValue < _min)
        {
            pwmValue = _min;
        }
        ledcWrite(_channel, pwmValue);
        return *this;
    }

    /**
     * @brief 赋值号重载为设置pwm值
     * @param pwmValue 目标pwm值
     * @return HW_PWM& 
     */
    HW_PWM& operator=(long pwmValue)
    {
        set(pwmValue);
        return *this;
    }
    
private:
    uint8_t _pin, _channel, _countBits;
    uint32_t _min, _max;
    double _frequency;
};

#endif // __HW_PWM_HPP__
