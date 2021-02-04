/**
 * @file fw_data.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层的数据存储相关接口实现
 * @date 2021-02-03
 */

#include "base.h"
#include "fw_data.h"
#include <EEPROM.h>

static const size_t DATA_SIZE = 1;
static EEPROMClass dataVessel("eeprom0", DATA_SIZE);
static uint8_t data[DATA_SIZE];
uint8_t &updateFlag = data[0];

/**
 * @brief 数据初始化
 * @return 成功为0，否则为错误码
 */
int data_init(void)
{
    int ret = ERROR_NONE;

    do{
        if(!dataVessel.begin(dataVessel.length()))
        {
            ret = ERROR_HARDWARE;
            break;
        }
        else
        {
            data_load();
        }
    }while(false);

    return ret;
}

/**
 * @brief 将数据写入存储器
 * @return 成功为0，否则为错误码
 */
int data_save(void)
{
    dataVessel.put(0, data);
    if(!dataVessel.commit())
    {
        return ERROR_HARDWARE;
    }
    return 0;
}

/**
 * @brief 将数据从存储器读出
 */
void data_load(void)
{
    dataVessel.get(0, data);
}

/**
 * @brief 获取升级标志位
 * @return true 需要升级
 * @return false 不需要升级
 */
bool data_getUpdateFlag(void)
{
    return updateFlag;
}

/**
 * @brief 设置升级标志位
 * @return true 需要升级
 * @return false 不需要升级
 */
bool data_setUpdateFlag(bool status)
{
    return (updateFlag = status);
}
