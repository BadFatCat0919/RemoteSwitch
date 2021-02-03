/**
 * @file hw_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API实现
 * @date 2021-01-23
 */

#include "hw_api.h"

HW_LED LED_Board(2, true, false);
HW_Key Key_Board(0, false);

/**
 * @brief 硬件层初始化
 */
void hw_init(void)
{
    LED_Board.init();
    Key_Board.init();
}
