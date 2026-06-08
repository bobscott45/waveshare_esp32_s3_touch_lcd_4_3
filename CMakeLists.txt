idf_component_register(SRCS "src/waveshare_esp32_s3_touch_lcd_4_3.c"
                            "src/lvgl_port.c"
                    INCLUDE_DIRS "include"
                    REQUIRES  "esp_timer"
                              "esp_lcd" "esp_lcd_touch" "esp_lcd_touch_gt911"
                              "lvgl"
)