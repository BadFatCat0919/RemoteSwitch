/**
 * @file hw_servo.hpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层HW_Servo类
 * @date 2021-02-13
 */

#ifndef __HW_SERVO_HPP__
#define __HW_SERVO_HPP__

#include "hw_pwm.hpp"

/**
 * @brief 硬件层的HW_Servo类
 */
class HW_Servo
{
public:
    /**
     * @brief 创建一个新的HW_Servo对象
     * @param pin 使用的引脚
     * @param pwmChannel 使用的pwm通道
     * @param minValue 最大pwm值
     * @param midValue 中间pwm值
     * @param maxValue 最小pwm值
     */
    HW_Servo(int pin, int pwmChannel, int minValue = 6, int maxValue = 32):
        _pwm(pin, pwmChannel, 50, 8), _minValue(minValue), _midValue((minValue + maxValue)/2), _maxValue(maxValue){}

    /**
     * @brief 销毁一个已创建的HW_Servo对象
     */
    ~HW_Servo()
    {
        _pwm.off();
    }

    /**
     * @brief 初始化
     * @return 成功为0, 否则为错误码
     */
    bool init()
    {
        return _pwm.init();
    }

    /**
     * @brief 打开pwm
     * @return HW_Servo&
     */
    HW_Servo& on()
    {
        _pwm.on();
        return *this;
    }

    /**
     * @brief 关闭pwm
     * @return HW_Servo&
     */
    HW_Servo& off()
    {
        _pwm.off();
        return *this;
    }

    /**
     * @brief 设置pwm值
     * @param pwmValue 目标pwm值
     * @return HW_Servo& 
     */
    HW_Servo& set(long pwmValue)
    {
        _pwm.set(pwmValue);
        _nowValue = pwmValue;
        return *this;
    }

    /**
     * @brief 赋值号重载为设置pwm值
     * @param pwmValue 目标pwm值
     * @return HW_Servo& 
     */
    HW_Servo& operator=(long pwmValue)
    {
        return set(pwmValue);
    }

    /**
     * @brief 获得当前pwm值
     * @return 当前pwm值
     */
    int get_pwm_now()
    {
        return _nowValue;
    }

    /**
     * @brief 获得最大pwm值
     * @return 最大pwm值
     */
    int get_pwm_max()
    {
        return _maxValue;
    }

    /**
     * @brief 获得中间pwm值
     * @return 中间pwm值
     */
    int get_pwm_mid()
    {
        return _midValue;
    }

    /**
     * @brief 获得最小pwm值
     * @return 最小pwm值
     */
    int get_pwm_min()
    {
        return _minValue;
    }
    
private:
    HW_PWM _pwm;
    int _nowValue, _minValue, _midValue, _maxValue;
};

#endif // __HW_SERVO_HPP__
