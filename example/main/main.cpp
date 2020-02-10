/**
This file is part of ESP32RMT esp-idf component
(https://github.com/CalinRadoni/ESP32RMT)
Copyright (C) 2020+ by Calin Radoni

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"

#include "ESP32RMTChannel.h"

#include "sdkconfig.h"

const char* TAG = "Init";

static const uint8_t  cfgOutputPin = 14;    // the GPIO where LEDs are connected
static const uint8_t  cfgChannel   = 0;     // ESP32 RMT's channel [0 ... 7]
static const uint16_t cfgLEDcount  = 64;    // 64 LEDS

ESP32RMTChannel rmtChannel;

extern "C" {

    void delay_ms(uint32_t ms)
    {
        if (ms != 0) {
            vTaskDelay(ms / portTICK_PERIOD_MS);
        }
    }

    void app_main() {
        esp_err_t err = nvs_flash_init();
        if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
            err = nvs_flash_erase();
            if (err != ESP_OK) {
                ESP_LOGE(TAG, "%d nvs_flash_erase", err);
            }
            else {
                err = nvs_flash_init();
                if (err != ESP_OK) {
                    ESP_LOGE(TAG, "%d nvs_flash_init", err);
                }
            }
        }

        if ( rmtChannel.Initialize((rmt_channel_t)cfgChannel, (gpio_num_t)cfgOutputPin, cfgLEDcount * 24) ) {
            if ( rmtChannel.ConfigureForWS2812x() ) {
                ESP_LOGI(TAG, "rmtChannel initialized and configured for WS2812x");
            }
            else {
                ESP_LOGE(TAG, "rmtChannel.ConfigureForWS2812x failed");
            }
        }
        else {
            ESP_LOGE(TAG, "rmtChannel.Initialize failed");
        }

        for(;;){
            delay_ms(20);
        }
    }
}
