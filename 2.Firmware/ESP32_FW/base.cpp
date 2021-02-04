/**
 * @file base.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 基础层API实现
 * @date 2021-02-04
 */

#include "base.h"
#include "base_log.h"

/**
 * @brief 基础层
 * @return 成功为0，否则为错误码
 */
int base_init(void)
{
    int ret = ERROR_NONE;

    do{
        if(ret = log_init())
        {

        }
    }while(false);

    return ret;
}
