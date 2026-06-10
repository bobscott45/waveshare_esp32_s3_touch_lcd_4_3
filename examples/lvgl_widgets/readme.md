# Waveshare ESP32-S3 Touch LCD 4.3 - LVGL Widgets Example

This example demonstrates how to compile and run the official LVGL Widgets demo on the Waveshare ESP32-S3 Touch LCD 4.3 board.

It showcases the decoupled board drivers (`bsp/board.h`) initializing the display and touch controllers separately and feeding them into the LVGL port wrapper (`bsp/lvgl_port.h`).

---

## References

* **Official Wiki:** [Waveshare ESP32-S3-Touch-LCD-4.3 Wiki](https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-4.3)
* **Original Demo Code:** This example and driver are based on the official demo code found in the [Waveshare ESP32-S3-Touch-LCD-4.3 Demo ZIP](https://files.waveshare.com/wiki/ESP32-S3-Touch-LCD-4.3/ESP32-S3-Touch-LCD-4.3-Demo.zip)

---

## Requirements

* **Target Hardware:** Waveshare ESP32-S3-Touch-LCD-4.3 (A) board.
* **ESP-IDF Version:** v5.3 or higher.
* **LVGL Version:** Works with **LVGL v8 (>=8.3.11)** or **LVGL v9 (>=9.0.0)**.

## Switching Between LVGL v8 and v9

The example dynamically compiles against either version based on the dependency defined in `main/idf_component.yml`.     

To switch between versions:
1. Open `main/idf_component.yml` and adjust the `lvgl` version rule (e.g., `^8.3.11` or `^9.0.0`).
2. Run `idf.py reconfigure` to update components.
3. Clean the configuration and rebuild:
   ```bash
   rm -f sdkconfig
   rm -rf build
   idf.py build
   ```

## Building and Flashing

Because this project uses board-specific RGB display timings and Octal PSRAM configurations, the build target is locked to the `esp32s3`.

1. Set the build target:
   ```bash
   idf.py set-target esp32s3
   ```

2. Build the project:
   ```bash
   idf.py build
   ```

3. Flash the executable and open the serial monitor:
   ```bash
   idf.py flash monitor
   ```
