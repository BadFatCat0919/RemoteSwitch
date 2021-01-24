/**
 * @file hw_api.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 硬件层的API实现
 * @date 2021-01-23
 * 
 * Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 */

#include "hw_includes.h"

HW_LED LED_Board(2, true, false);

/**
 * @brief 硬件层初始化
 */
void HW_Init(void)
{
    LED_Board.init();
}
