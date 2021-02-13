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
     * @param onValue 开灯状态时的角度值
     * @param releaseValue 释力状态的角度值
     * @param offValue 关灯状态的角度值
     */
    HW_Servo(int pin, int pwmChannel, int onValue = 6, int releaseValue = 19, int offValue = 32):
        _pwm(pin, pwmChannel, 50, 8), _onValue(onValue), _releaseValue(releaseValue), _offValue(offValue){}

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
        return *this;
    }

    /**
     * @brief 赋值号重载为设置pwm值
     * @param pwmValue 目标pwm值
     * @return HW_Servo& 
     */
    HW_Servo& operator=(long pwmValue)
    {
        set(pwmValue);
        return *this;
    }
    
private:
    HW_PWM _pwm;
    int _onValue, _releaseValue, _offValue;
};

#endif // __HW_SERVO_HPP__
