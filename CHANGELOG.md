# Changelog

All notable changes to this project will be documented in this file.

## [1.0.4] - 2026-06-13
- Updated sdkconfig.defaults.

## [1.0.3] - 2026-06-12

- Replaced strict `ESP_ERROR_CHECK` on I2C/Touch initialization with graceful `ESP_LOGE` to prevent silent USB disconnects on boot.

## [1.0.2] - 2026-06-12

- Fixed missing namespace in `add-dependency` command in `readme.md`.

## [1.0.1] - 2024-06-12

- Initial release published to the Espressif Component Registry.
- Added full driver support for the Waveshare ESP32-S3 Touch LCD 4.3" with GT911 touch controller and LVGL v8/v9 integration.
- Refactored hardware initialization functions (`waveshare_esp32_s3_touch_reset` and `gpio_init`) to return `esp_err_t`, preventing silent failures.
- Replaced hard aborts with graceful error handling in the example application (`main.c`).
- Simplified LVGL display rotation logic in `lvgl_port.c` to directly use the `LVGL_PORT_ROTATION_DEGREE` macro.
- Expanded the `readme.md` to include required configuration and advanced performance tuning notes.
- Implemented a robust `.gitignore` to exclude build artifacts and dependency locks.
- Added MIT License recognizing original Waveshare copyright alongside port maintainer rights.
