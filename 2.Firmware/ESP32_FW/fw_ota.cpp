/**
 * @file fw_ota.cpp
 * @author BadFatCat0919 (543015378@qq.com)
 * @brief 固件层OTA升级相关接口实现
 * @date 2021-02-03
 */

#include "base.h"
#include "fw_ota.h"
#include "fw_data.h"
#include "hardware.h"
#include <Esp.h>
#include <stdio.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

WiFiServer server(80);

/**
 * @brief OTA升级初始化
 * @return 成功为0，否则为错误码
 */
int OTA_update_init(void)
{
    int ret = ERROR_NONE;

    do{
        data_setUpdateFlag(false);
        if(ret = data_save())
        {
            break;
        }

        char ssid[] = "RemoteSwitch-XXXXXXXXXXXX";
        sprintf(ssid, "RemoteSwitch-%012llX", ESP.getEfuseMac());
        WiFi.softAP(ssid);

        ArduinoOTA
        .onStart([]() {
            LED_Board.off();
        })
        .onEnd([]() {
            LED_Board.on();
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            if(!(progress % 100))
            {
                LED_Board.reverse();
            }
        })
        .onError([](ota_error_t error) {
            
        });

        ArduinoOTA.begin();
    }while(false);

    return ret;
}

/**
 * @brief 单片机进入OTA状态
 * @note 函数中含有重启命令
 */
void OTA_enter_update_status(void)
{
    data_setUpdateFlag(true);
    data_save();
    ESP.restart();
}

/**
 * @brief 进行OTA升级
 * @note 函数中含有while(true)
 */
void OTA_update(void)
{
    while(true)
    {
        LED_Board.on();
        ArduinoOTA.handle();
    }
}
