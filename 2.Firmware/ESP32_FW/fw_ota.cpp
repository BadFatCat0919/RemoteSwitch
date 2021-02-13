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
 * @return 成功为0, 否则为错误码
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
        LOG_I("WiFi ssid: %s\r\n", ssid);

        ArduinoOTA
        .onStart([]() {
            LOG_D("start OTA update...\r");
            LED_Board.off();
        })
        .onEnd([]() {
            LOG_D("OTA update finish.\r\n");
            LED_Board.on();
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            LOG_D("Progress: %u%%\r", (progress / (total / 100)));
            if(!(progress % 100))
            {
                LED_Board.reverse();
            }
        })
        .onError([](ota_error_t error) {
            LOG_E(ERROR, "update failed!\r\n");
            OTA_enter_update_status();
        });

        ArduinoOTA.begin();
    }while(false);

    return ret;
}

/**
 * @brief 单片机重启并进入OTA状态
 * @note 函数中含有重启命令
 */
void OTA_enter_update_status(void)
{
    data_setUpdateFlag(true);

    int ret = ERROR_NONE;
    do{
        if(ret = data_save())
        {
            LOG_E(ret, "data save error!\r\n");
            vTaskDelay(200);
        }
    }while(ret);

    LOG_D("restart and enter OTA update mode...\r\n");
    ESP.restart();
}

/**
 * @brief 进行OTA升级
 * @note 函数中含有while(true)
 */
void OTA_update(void)
{
    LOG_D("OTA update ready.\r\n");
    while(true)
    {
        LED_Board.on();
        ArduinoOTA.handle();
        
        if(Key_Board.scan())
        {
            LOG_D("Key_Board is pressed.\r\n");
            LED_Board.off();
            while(Key_Board.scan())
            {
                vTaskDelay(50);
            }
            LOG_D("restart and quit OTA update mode...\r\n");
            ESP.restart();
        }
    }
}
