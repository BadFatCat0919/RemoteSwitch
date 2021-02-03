/**
 * @file fw_ota.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层OTA升级相关接口声明
 * @date 2021-02-03
 */

#ifndef __FW_OTA_H__
#define __FW_OTA_H__

int OTA_update_init(void);
void enter_OTA_status(void);
void OTA_update(void);

#endif // __FW_OTA_H__
