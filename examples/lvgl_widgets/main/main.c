#include <stdio.h>
#include "esp_log.h"
#include "esp_timer.h"
#include "waveshare_esp32_s3_touch_lcd_4_3.h"
#include "widgets/lv_demo_widgets.h"

static const char *TAG = "LVGL_WIDGETS";

void app_main(void)
{
    ESP_ERROR_CHECK(waveshare_esp32_s3_rgb_lcd_init());
    ESP_ERROR_CHECK(waveshare_rgb_lcd_bl_on());

    ESP_LOGI(TAG, "Displaying LVGL widgets demo");

    if (lvgl_port_lock(-1)) {
        lv_demo_widgets();
        lvgl_port_unlock();
    }

    ESP_LOGI(TAG, "UI tasks running via background worker task. Deleting main task.");

    vTaskDelete(NULL);
}