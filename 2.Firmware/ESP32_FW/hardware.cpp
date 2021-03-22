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
    
    LED_Red.init();
    LED_Green.init();
    LED_Blue.init();
    Key_Left.init();
    Key_OK.init();
    Key_Right.init();
    Servo_Left.init();
    Servo_Right.init();

    return ret;
}
