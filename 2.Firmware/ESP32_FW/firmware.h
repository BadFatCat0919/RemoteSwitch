/**
 * @file firmware.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层的API声明
 * @date 2021-02-03
 */

#ifndef __FIRMWARE_H__
#define __FIRMWARE_H__

#include "fw_data.h"
#include "fw_ota.h"

int firmware_init(void);

#endif // __FIRMWARE_H__
