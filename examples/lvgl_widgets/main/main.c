
#include "esp_log.h"
#include "../../../include/bsp/board.h"
#include "widgets/lv_demo_widgets.h"

static const char *TAG = "main";

void app_main(void)
{
    ESP_ERROR_CHECK(waveshare_esp32_s3_rgb_lcd_init());
    ESP_ERROR_CHECK(waveshare_rgb_lcd_bl_on());

    ESP_LOGI(TAG, "Displaying LVGL widgets demo");

    if (lvgl_port_lock(-1)) {
        lv_demo_widgets();
        lvgl_port_unlock();
    } else {
        ESP_LOGE(TAG, "Failed to acquire LVGL lock, widgets demo skipped");
    }

    ESP_LOGI(TAG, "UI tasks running via background worker task. Deleting main task.");

    vTaskDelete(NULL);
}