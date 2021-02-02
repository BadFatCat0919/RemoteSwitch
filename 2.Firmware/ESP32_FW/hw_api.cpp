/**
 * @file hw_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API实现
 * @date 2021-01-23
 */

#include "hw_api.h"

HW_LED LED_Board(2, true, false);
HW_KEY KEY_Board(0, false);

/**
 * @brief 硬件层初始化
 */
void HW_Init(void)
{
    LED_Board.init();
    KEY_Board.init();
}
