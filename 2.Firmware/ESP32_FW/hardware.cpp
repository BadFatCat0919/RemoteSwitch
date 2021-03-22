/**
 * @file hardware.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API实现
 * @date 2021-01-23
 */

#include "base.h"
#include "hardware.h"

HW_LED LED_Red(16, false, false), LED_Green(17, false, false), LED_Blue(4, false, false);
HW_Key Key_Left(23, false), Key_OK(22, false), Key_Right(0, false);
HW_Servo Servo_Left(25, 1), Servo_Right(15, 2);

/**
 * @brief 硬件层初始化
 * @return 成功为0, 否则为错误码
 */
int hardware_init(void)
{
    int ret = ERROR_NONE;
    
    do{
        if(ret = LED_Red.init())
        {
            LOG_E(ret, "LED_Red init failed!\r\n");
            break;
        }
        if(ret = LED_Green.init())
        {
            LOG_E(ret, "LED_Green init failed!\r\n");
            break;
        }
        if(ret = LED_Blue.init())
        {
            LOG_E(ret, "LED_Blue init failed!\r\n");
            break;
        }
        if(ret = Key_Left.init())
        {
            LOG_E(ret, "Key_Left init failed!\r\n");
            break;
        }
        if(ret = Key_OK.init())
        {
            LOG_E(ret, "Key_OK init failed!\r\n");
            break;
        }
        if(ret = Key_Right.init())
        {
            LOG_E(ret, "Key_Right init failed!\r\n");
            break;
        }
        if(ret = Servo_Left.init())
        {
            LOG_E(ret, "Servo_Left init failed!\r\n");
            break;
        }
        if(ret = Servo_Right.init())
        {
            LOG_E(ret, "Servo_Right init failed!\r\n");
            break;
        }
        LED_Red.on();
        LED_Green.on();
        LED_Blue.on();
    }while(0);

    return ret;
}
