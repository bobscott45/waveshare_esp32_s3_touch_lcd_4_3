#include <stdio.h>
#include "esp_log.h"
#include "esp_timer.h"
#include "waveshare_esp32_s3_touch_lcd_4_3.h"
#include "widgets/lv_demo_widgets.h"



void app_main(void)
{
    waveshare_esp32_s3_rgb_lcd_init();
    waveshare_rgb_lcd_bl_on();

    ESP_LOGI(TAG, "Displaying LVGL widgets demo");

    if (lvgl_port_lock(-1)) {
        lv_demo_widgets();
        lvgl_port_unlock();
    }

    ESP_LOGI(TAG, "UI tasks running via background worker task. Keeping main task alive.");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000)); // Just sleep app_main to keep the CPU happy
    }
}