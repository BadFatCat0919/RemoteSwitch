/**
 * @file fw_data.h
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层的数据存储相关接口声明
 * @date 2021-02-03
 */

#ifndef __APP_DATA_H__
#define __APP_DATA_H__

int data_init(void);
int data_save(void);
void data_load(void);
bool data_getUpdateFlag(void);
bool data_setUpdateFlag(bool status);

#endif // __APP_DATA_H__
