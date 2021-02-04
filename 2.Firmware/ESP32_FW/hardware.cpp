/**
 * @file hardware.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API实现
 * @date 2021-01-23
 */

#include "base.h"
#include "hardware.h"

HW_LED LED_Board(2, true, false);
HW_Key Key_Board(0, false);

/**
 * @brief 硬件层初始化
 * @return 成功为0，否则为错误码
 */
int hardware_init(void)
{
    int ret = ERROR_NONE;
    
    LED_Board.init();
    Key_Board.init();

    return ret;
}
